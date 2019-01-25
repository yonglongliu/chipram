#include <asm/arch/sprd_reg.h>
#include "sci_types.h"
#include "ddrc_r1p0.h"
#include "ddrc_r1p0_phy.h"
#include "ddrc_r1p0_phy_cfg_lp3.h"
#include "ddrc_r1p0_phy_cfg_lp4.h"
#include "ddrc_r1p0_common.h"
extern DRAM_CHIP_INFO ddr_chip_cur;

#ifdef GUCPHY_TRAINING_MODE
u32 FREQ_TRAINING_ENABLE[8] = {0,0,0,0,1,1,1,1};
#else
u32 FREQ_TRAINING_ENABLE[8] = {0};
#endif

static TRAIN_STATUS_TABLE ddrc_training_status_table;
static TRAIN_CONDITIONS_TABLE ddrc_training_table;
static unsigned int ddrc_ca_debug;
extern unsigned int phy_cfg_data_lp3[160];
extern unsigned int phy_cfg_data_lp4[160];
extern unsigned int phy_cfg_common_data_lp3[54];
extern unsigned int phy_cfg_common_data_lp4[54];
static void while_loop(void)
{
	while(1);
}
void ddrc_phy_vref_setting(void)
{
	/*bit[22] PHY_VREF_HI_C vref power down,1:pd 0:no-pd
	 * for lpddr3 suggest set to 1'b0
	 * for lpddr4/4x suggest set to 1'b1
	 * */
	/*bit[23] PHY_VREF_FP hi-current mode 1:enable 0:disable*/
	if (ddr_chip_cur.chip_type == DRAM_LPDDR3)
	{
		reg_bits_set(REG_PMU_APB_DDR_SLEEP_CTRL, 22, 2, 0x0);
	}
	else
	{
		reg_bits_set(REG_PMU_APB_DDR_SLEEP_CTRL, 22, 2, 0x2);
	}
	/*bit[31:24] PHY_VREF_AGJ */
	reg_bits_set(REG_PMU_APB_DDR_SLEEP_CTRL, 24, 8, 0x50);

}

void ddrc_phy_iopvt_pre_seq(void)
{
	/*0x02cc*/
	/*bit[01] mlb_train_wdqs_stop_step_cfg_disable*/
	/*bit[02] mlb_train_wdqs_stop_step_cfg_cal_manual_mode_*/
	reg_bits_set((DMC_GUCPHY0_BASE + 0xB3*4), 1, 2, 0);
	reg_bits_set((DMC_GUCPHY1_BASE + 0xB3*4), 1, 2, 0);
	/*0x032c*/
	/*bit[11] mlb_cal_eb_cfg_cal_eb*/
	reg_bits_set((DMC_GUCPHY0_BASE + 0xCB*4), 11, 1, 1);
	reg_bits_set((DMC_GUCPHY1_BASE + 0xCB*4), 11, 1, 1);

}

void ddrc_phy_iopvt_cal_seq(void)
{
	u32 read_data;
	u32 data_tmp;

	/*step 1) check result*/
	data_tmp = __raw_readl(DMC_GUCPHY0_BASE + 0xd6*4);
	if (((data_tmp >> 3) & 0x1))
	{
		dmc_print_str("polling io pvt failed\n");
		while_loop();
	}

	/*step 2) reset the pu/pd base on the iopvt zq resut*/
	/*0xe5*4 PU/PD code of IO PVT calibration result*/
	/*bit[23:16] pdio_cfg_pd_code*/
	/*bit[7:0] pdio_cfg_pu_code*/
	read_data = __raw_readl((DMC_GUCPHY0_BASE + 0xe5*4));
	/*0xb4*4 IO PVT manual mode*/
	/*bit[31:24] cal_default_pd_cfg_default_pd*/
	/*bit[23:16] cal_default_pd_cfg_default_pu*/
	/*bit[11:8]  cal_default_pd_cfg_offset_pd*/
	/*bit[3:0]   cal_default_pd_cfg_offset_pu*/
	reg_bits_set((DMC_GUCPHY0_BASE + 0xb4*4), 16, 8, (read_data & 0xff));//cfg_pu_code data_tmp[23:16] = read_data[7:0]
	reg_bits_set((DMC_GUCPHY0_BASE + 0xb4*4), 24, 8, ((read_data >> 16) & 0xff));//cfg_pd_code;data_tmp[31:24] = read_data[23:16]

	/*step 3) enable cal_manual_mode and disable iopvt zq cali*/
	reg_bits_set((DMC_GUCPHY0_BASE + 0x2cc), 1, 2, 3);//bitp[1]cal_disable,bit[2] cal_manual_mode
	reg_bits_set((DMC_GUCPHY1_BASE + 0x2cc), 1, 2, 3);//bitp[1]cal_disable,bit[2] cal_manual_mode

	/*step 4) disable cal_eb 0xcb*4 MLB gated clock ctrl register*/
	if (ddrc_training_status_table.iopvt_zq_cal_done == 1)
	{
		reg_bits_set((DMC_GUCPHY0_BASE + 0x32c), 11, 1, 0);//reg_mlb_cal_eb_cfg_cal_eb

		reg_bits_set((DMC_GUCPHY1_BASE + 0x32c), 11, 1, 0);//reg_mlb_cal_eb_cfg_cal_eb
	}

	ddrc_training_status_table.iopvt_zq_cal_done = 1;
}
void ddrc_phy_post_setting(u32 phy_base)
{
	reg_bits_set(phy_base + 0xcb*4, 8, 4, 0); //eb
	reg_bits_set(phy_base + 0xcb*4, 0, 4, 0);//ag_en
	reg_bits_set(phy_base + 0xd1*4, 16, 1, 0); //reg_pwrup_cke_rstn_en
	reg_bits_set(phy_base + 0x32c, 11, 1, 0); //reg_mlb_cal_eb_cfg_cal_eb
}
void ddrc_phy_rpull_set_for_gate_train(u32 phy_base, u32 dfs_freq_sel)
{
	u32 tmp_addr = phy_base + (dfs_freq_sel*20*4);

	reg_bits_set(tmp_addr + 0x9*4, 31, 1, 0);//cfg_rpull
	reg_bits_set(tmp_addr + 0x9*4, 24, 1, 1);//cfg_rup
	reg_bits_set(tmp_addr + 0x9*4, 28, 1, 1);//cfg_rdn

	reg_bits_set(tmp_addr + 0x6*4, 8, 1, 1); //cs nen
	reg_bits_set(tmp_addr + 0x8*4, 28, 1, ddrc_training_status_table.gate_edge_mode); //cs nen
}
int ca_reload_rank_reg(u32 phy_base, u32 dfs_freq_sel, u32 rank)
{
	u32 tmp_addr = phy_base + (dfs_freq_sel*20*4);
	u32 data_tmp;
	u32 read_data;
	u32 data_rank0;
	u32 data_rank1;
	u32 data_rank0_bk;
	u32 data_rank1_bk;
	u32 ac_mst_delay;

	ac_mst_delay = reg_bits_get((phy_base + 0xe1*4), 0, 9);

	read_data = __raw_readl(phy_base + 0x398);
	if (((read_data >> 16) & 0xFF) < 10)
	{
		if (rank)
			dmc_print_str("RANK 1 CA Training window size too small!\n");
		else
			dmc_print_str("RANK 0 CA Training window size too small!\n");
		return -1;
	}

	data_tmp = __raw_readl(phy_base + 0xe6*4);
	if ((((data_tmp >> 8) & 0xff) == 0xff) && ((data_tmp & 0x1) == 0x1))
	{
		dmc_print_str("rank CA training failed because have not right boundary!\n");
		return -1;
	}

	if (rank == 0)
	{
		__raw_writel((tmp_addr + 0xc*4), data_tmp);
	}
	else
	{
		data_rank1 = data_tmp;

		data_rank0 = __raw_readl(tmp_addr + 0xc*4);

		//{data_rank1[0], data_rank1[15:8]}
		data_rank1_bk = (((data_rank1 & 0x1) << 9) || (data_rank1 >> 8 & 0xff));
		data_rank0_bk = (((data_rank0 & 0x1) << 9) || (data_rank0 >> 8 & 0xff));

		if (data_rank1_bk  > data_rank0_bk)
		{
			__raw_writel(tmp_addr + 0xc*4, data_rank0);
			//reg_phy_longer_ca_dl_sel <= #'RD reg_wdata[19:16]
			reg_bits_set((phy_base + 0x348), 16, 4, 0x2);
			//reg_phy_fdl_ca_mul_wr <= #'RD reg_wdata[21:16]ca delay difference
			reg_bits_set((phy_base + 0x34c), 16, 6, ((data_rank1_bk - data_rank0_bk)*ac_mst_delay/256/2));
		}
		else //rank0 longer
		{
			__raw_writel(tmp_addr + 0xC*4, data_rank1);
			//reg_phy_longer_ca_dl_sel <= #'RD reg_wdata[19:16]
			reg_bits_set((phy_base + 0x348), 16, 4, 0x1);
			//reg_phy_fdl_ca_mul_wr <= #'RD reg_wdata[21:16]ca delay difference
			reg_bits_set((phy_base + 0x34c), 16, 6, (data_rank0_bk - data_rank1_bk)*ac_mst_delay/256/2);

			ddrc_training_status_table.CA_SHORTER_RANK = 1;
		}
	}
	return 1;
}

void phy_reload_weye_result(u32 phy_base, u32 dfs_freq_sel)
{
	u32 read_data;
	u32 data_tmp;
	u32 tmp_addr = phy_base + dfs_freq_sel*20*4;
	u32 tmp_fdl_mul_wr_pre;
	u32 tmp_fdl_mul_wr;
	u32 db0_mst_delay;
	u32 db1_mst_delay;

	if (ddrc_training_status_table.WR_SHORTER_RANK != ddrc_training_status_table.CA_SHORTER_RANK) //different with ca
	{
		db0_mst_delay = __raw_readl(phy_base + 0xdf*4) & 0x1f;
		db1_mst_delay = __raw_readl(phy_base + 0xe0*4) & 0x1f;

		tmp_fdl_mul_wr_pre = __raw_readl(phy_base + 0x34c);
		tmp_fdl_mul_wr_pre = (tmp_fdl_mul_wr_pre & 0x3f) *2 * 256;

		read_data = __raw_readl(tmp_addr + 0x12*4);

		tmp_fdl_mul_wr = tmp_fdl_mul_wr_pre / db0_mst_delay;
		//{read_data[19:16], read_data[7:0]} = {read_data[19:16], read_data[7:0]} - tmp_fdl_mul_wr;
		data_tmp = (((read_data >> 16) & 0xf) << 8) | (read_data & 0xff);
		data_tmp -= tmp_fdl_mul_wr;
		read_data = u32_bits_set(read_data, 0, 8, (data_tmp & 0xff));
		read_data = u32_bits_set(read_data, 16, 4, ((data_tmp >> 8) & 0xff));

		tmp_fdl_mul_wr = tmp_fdl_mul_wr_pre / db1_mst_delay;
		//{read_data[19:16], read_data[7:0]} = {read_data[19:16], read_data[7:0]} - tmp_fdl_mul_wr;
		data_tmp = (((read_data >> 16) & 0xf) << 8) | (read_data & 0xff);
		data_tmp -= tmp_fdl_mul_wr;
		read_data = u32_bits_set(read_data, 0, 8, (data_tmp & 0xff));
		read_data = u32_bits_set(read_data, 16, 4, ((data_tmp >> 8) & 0xff));

		__raw_writel(tmp_addr + 0x12*4, read_data);

	}
}

void phy_reload_rank_0_reg(u32 wr_bit,u32 phy_base, u32 dfs_freq_sel, u32 rank)
{
	u32 read_data;
	u32 data_tmp;
	u32 tmp_addr = phy_base + dfs_freq_sel*20*4;

	if ((wr_bit >> 8) & 0x1)//GATE
	{
		/*0x039C The gate training coarse and fine delay training result*/
		data_tmp = __raw_readl(phy_base + 0xe7*4);
		/*F0-7 The gate training manual mode coarse and fine delay setting*/
		__raw_writel(tmp_addr + 0xd*4, data_tmp);//db1_dl_gate_fine_cfg_db1_fine

		/*0x03A4 The rddv_sel valude and DRAM vref training reslut*/
		/*bit[29:24] vref_dram_value_manu_cfg*/
		/*bit[3:0]   vref_dram_value_manu_cfg_rddv_sel*/
		read_data = REG32(phy_base + 0xe9*4);
		/*F0-7 rddv sel and offset manual mode setting for set and DRAM
		 * vref manual mode seting*/
		/*bit[30]    mlb_vref_dram_rang_manu_cfg_range*/
		/*bit[29:24] mlb_vref_dram_rang_manu_cfg_value*/
		/*bit[10:8]  mlb_vref_dram_rang_manu_cfg_offset*/
		/*bit[3:0]   mlb_vref_dram_rang_manu_cfg_sel*/
		reg_bits_set(tmp_addr + 0xf*4, 0, 4, (read_data & 0xf));
	}

	if ((wr_bit >> 10) & 0x1)//RDEYE
	{
		/*0x03AC Read dqs rising and flling edge phase shift training*/

		read_data = __raw_readl(phy_base + 0x3B4);
		if ((((read_data & 0xff) <= 10)) ||
		     (((read_data >> 8) & 0xFF) <= 10))
		{
			dmc_print_str("rank 0 Read EYE window size too small!\n");
			while_loop();
		}
		data_tmp = __raw_readl(phy_base + 0xeb*4);
		/*0x44 + F0-7 Rank read dqs rising and falling edge phase shift
		 * manual mode setting*/
		/*bit[31:24] db1_dll_rddeye_dqsn_cfg_db0_dqs_mul*/
		/*bit[23:16] db1_dll_rddeye_dqsn_cfg_db1_dqs_mul*/
		/*bit[15:8]  db1_dll_rddeye_dqsn_cfg_db1_dqs*/
		/*bit[7:0]   db1_dll_rddeye_dqsn_cfg_db0_dqs*/
		__raw_writel(tmp_addr + 0x11*4, data_tmp);

		if ((((data_tmp >> 24) & 0xff) == 0xff) ||
		    (((data_tmp >> 16) & 0xff) == 0xf)||
		    (((data_tmp >> 8) & 0xff) == 0xff)||
		    ((data_tmp & 0xff) == 0xff))
		{
			dmc_print_str("rank 0 Read EYE training failed because have not right boundary!\n");
			while_loop();
		}
	}

	if ((wr_bit >> 11) & 0x1)//RVREF
	{
		/*0x03A8 Read vref training result*/
		/*bit[15:8] vref_phy_agj_result_db1_cfg_db1_result*/
		/*bit[7:0]  vref_phy_agj_result_db1_cfg_db0_result*/
		read_data = __raw_readl(phy_base + 0xea*4);
		/*0x40 + F0-7 Read vref manual mode setting and multiple rank MLB
		 * function disable control*/
		/*bit[15:8] mlb_vref_phy_value_manu_db1_cfg_db1*/
		/*bit[7:0]  mlb_vref_phy_value_manu_db1_cfg_db0*/
		reg_bits_set(tmp_addr + 0x10*4, 0, 16, read_data & 0xffff);
	}

	if ((wr_bit >> 13) & 0x1)//WEYE
	{
		read_data = __raw_readl(phy_base + 0x3B8);
		if ((((read_data & 0xff) <= 10)) ||
		     (((read_data >> 8) & 0xFF) <= 10))
		{
			if (rank)
				dmc_print_str("RANK 1 Write EYE window size too small!\n");
			else
				dmc_print_str("RANK 0 Write EYE window size too small!\n");

			while_loop();
		}

		data_tmp = __raw_readl(phy_base + 0xec*4);
		__raw_writel(tmp_addr + 0x12*4, data_tmp);///db1_bt_wdq_cfg_db1_bt/db0_bt/db1_wrdeye/db0_wrdeye

		if (((((data_tmp >> 8) & 0xff) == 0xff) && (((data_tmp >> 20) & 0xf) == 0xf)) ||
		    ((((data_tmp >>16) & 0xf) == 0xf) && ((data_tmp & 0xff) == 0xff)))
		{
			dmc_print_str("rank 0 Write EYE training failed because have not right boundary!\n");
			while_loop();
		}
		phy_reload_weye_result(phy_base, dfs_freq_sel);
	}

	if ((wr_bit >> 14) & 0x1)//WVREF
	{
		/*0x03A4 The rddv_sel valude and DRAM vref training reslut*/
		/*bit[29:24] vref_dram_value_manu_cfg*/
		/*bit[3:0]   vref_dram_value_manu_cfg_rddv_sel*/
		read_data = __raw_readl(phy_base + 0xe9*4);
		/*rddv sel and offset manual mode setting for set
		 * and DRAM vref manual mode settting for F0-7*/
		/*bit[29:24] mlb_vref_dram_range_manu_cfg_value*/
		reg_bits_set(tmp_addr + 0xf*4, 24, 6, (read_data >>24 & 0x3f));
	}

	if ((wr_bit >> 9) & 0x1)//RPERB dm use dq0
	{
		data_tmp = __raw_readl(phy_base + 0xf6*4);
		__raw_writel(phy_base + 0xbc*4, data_tmp);

		read_data = __raw_readl(phy_base + 0xf5*4);
		__raw_writel(phy_base + 0xbb*4, read_data);

		data_tmp = __raw_readl(phy_base + 0xf4*4);
		data_tmp= u32_bits_set(data_tmp, 24, 8, (read_data & 0xff));//f5[7:0] is reg_ro_rd_db1_dq3_fdl_cfg_db1_dq0
		__raw_writel(phy_base + 0xba*4, data_tmp);//bit[31:24]fdl_db1_dm_rd_cfg_db1_dm_rd
							//bit[23:16]fdl_db1_dm_rd_cfg_db1_dqs_rd
							//bit[15:8]fdl_db1_dm_rd_cfg_db0_dq7_rd
							//bit[7:0]fdl_db1_dm_rd_cfg_db0_dq6_rd

		data_tmp = __raw_readl(phy_base + 0xf3*4);
		__raw_writel(phy_base + 0xb9*4, data_tmp);//bit[31:24]fdl_db0_dq5_rd_cfg_db0_dq5_rd
							//bit[23:16]fdl_db0_dq5_rd_cfg_db0_dq4_rd
							//bit[15:8]fdl_db0_dq5_rd_cfg_db0_dq3_rd
							//bit[7:0]fdl_db0_dq5_rd_cfg_db0_dq2_rd

		data_tmp = __raw_readl(phy_base + 0xf2*4);//data_tmp[15:8]= data_tmp[23:16]if reg ro rd db0 dq1  fdl cfg db0 dq0
		data_tmp= u32_bits_set(data_tmp, 8, 8, ((data_tmp >> 16)& 0xff));
		__raw_writel(phy_base + 0xb8*4, data_tmp);

		data_tmp = __raw_readl(phy_base + 0xe2*4);
		if ((data_tmp & 0xf) != 0xf)
		{
			dmc_print_str("perbit rd training failed\n");
			while_loop();//perbit rd training fail
		}
	}

	if ((wr_bit >> 12) & 0x1)//WPERB dm us dq0
	{
		/*0x03EC PHY write path per bit deskew training result*/
		data_tmp = __raw_readl(phy_base + 0xfb*4);
		/*0x0304 PHY write path per bit deskew manual mode setting*/
		__raw_writel(phy_base + 0xc1*4, data_tmp);

		read_data = __raw_readl(phy_base + 0xfa*4);
		/*0x0300 PHY write path per bit deskew manual mode setting*/
		__raw_writel(phy_base + 0xc0*4, read_data);

		/*0x03E4 PHY write path per bit deskew training result*/
		/*0x3E8 bit[7:0] wr_db1_dq3_fdl_cfg_db1_dq0*/
		/*0x3E4 bit[31:24] wr_db1_dm_fdl_cfg_db1_dm*/
		/* dq0 to dm
		 * data_tmp[31:24] == read_data[7:0]*/
		data_tmp = __raw_readl(phy_base + 0xf9*4);
		data_tmp= u32_bits_set(data_tmp, 24, 8, (read_data & 0xff));
		/*0x0300 PHY write path per bit deskew manual mode setting*/
		__raw_writel(phy_base + 0xbf*4, data_tmp);

		data_tmp = __raw_readl(phy_base + 0xf8*4);
		/*0x0300 PHY write path per bit deskew manual mode setting*/
		__raw_writel(phy_base + 0xbe*4, data_tmp);

		data_tmp = __raw_readl(phy_base + 0xf7*4);//data_tmp[15:8]= data_tmp[23:16]
		data_tmp= u32_bits_set(data_tmp, 8, 8, ((data_tmp >> 16) & 0xff));
		/*0x0300 PHY write path per bit deskew manual mode setting*/
		__raw_writel(phy_base + 0xbd*4, data_tmp);

		data_tmp = __raw_readl(phy_base + 0xe2*4);
		if (((data_tmp >> 4) & 0xf) != 0xf)
		{
			dmc_print_str("perbit wr training failed!\n");
			while_loop();
		}
	}
}

void phy_reload_rank_1_reg(u32 wr_bit, u32 phy_base, u32 dfs_freq_sel, u32 rank)
{
	u32 data_tmp;
	u32 tmp_addr = phy_base + (dfs_freq_sel * 20 * 4);
	u32 data_rank0;
	u32 data_rank0_bk;
	u32 data_rank1;
	u32 data_rank1_bk;
	u32 db0_mst_delay;
	u32 db1_mst_delay;
	u32 ac_mst_delay;
	u64 fdl_db0_mul_wr_pre;
	u64 fdl_db1_mul_wr_pre;

	data_tmp = __raw_readl(phy_base + 0xdf*4);
	db0_mst_delay = data_tmp & 0x1ff;

	data_tmp = __raw_readl(phy_base + 0xe0*4);
	db1_mst_delay = data_tmp & 0x1ff;

	data_tmp = __raw_readl(phy_base + 0xe1*4);
	ac_mst_delay = data_tmp & 0x1ff;

	if ((wr_bit >> 10) & 0x1)//rdeye
	{
		data_rank1 = __raw_readl(phy_base + 0xeb*4);

		if (((data_rank1 >> 24 & 0xff) == 0xff) || ((data_rank1 >> 16 & 0xff) == 0xff) ||
			((data_rank1 >> 8 & 0xff) == 0xff) || ((data_rank1 & 0xff) == 0xff))
		{
			dmc_print_str("Rank RDEYE CA training failed because have not right boundary!\n");
			while_loop();

		}

		data_rank0 = __raw_readl(tmp_addr + 0x11*4);

		if ((data_rank1 & 0xff) > (data_rank0 & 0xff)) //db0 rank 1 longer
		{
			reg_bits_set(phy_base + 0x348, 0, 4, 2); //reg phy longer rd dl sel db0 <= #'RD reg_wdata[3:0]

			data_rank0 = u32_bits_set(data_rank0, 0, 8, (data_rank0 & 0xff));//not used
			data_rank0 = u32_bits_set(data_rank0, 16, 8, (data_rank1 & 0xff));
			__raw_writel(tmp_addr + 0x11*4, data_rank0);
		}
		else
		{
			reg_bits_set(phy_base + 0x348, 0, 4, 1); //reg phy longer rd dl sel db0 <= #'RD reg_wdata[3:0]

			data_rank0 = u32_bits_set(data_rank0, 0, 8, (data_rank1 & 0xff));
			data_rank0 = u32_bits_set(data_rank0, 16, 8, (data_rank0 & 0xff));
			__raw_writel(tmp_addr + 0x11*4, data_rank0);
		}

		if (((data_rank1 >> 8) & 0xff) > ((data_rank0 >> 8) & 0xff))//db1 rank 1 longer
		{
			reg_bits_set(phy_base + 0x348, 4, 4, 2); //reg phy longer rd dl sel db0 <= #'RD reg_wdata[3:0]
			//data_rank0[15:8] = data_rank0[15:8]
			//data_rank0[31:24] = data_rank1[15:8]
			data_rank0 = u32_bits_set(data_rank0, 8, 8, ((data_rank0 >> 8) & 0xff));
			data_rank0 = u32_bits_set(data_rank0, 24, 8, ((data_rank1 >> 8) & 0xff));
			__raw_writel(tmp_addr + 0x11*4, data_rank0);
		}
		else
		{
			reg_bits_set(phy_base + 0x348, 4, 4, 1); //reg phy longer rd dl sel db0 <= #'RD reg_wdata[3:0]
			//data_rank0[15:8] = data_rank1[15:8]
			//data_rank0[31:24] = data_rank0[15:8]
			data_rank0 = u32_bits_set(data_rank0, 8, 8, ((data_rank1 >> 8) & 0xff));
			data_rank0 = u32_bits_set(data_rank0, 24, 8, ((data_rank0 >> 8) & 0xff));
			__raw_writel(tmp_addr + 0x11*4, data_rank0);
		}
	}

	if ((wr_bit >> 13) & 0x1)//weye
	{
		data_rank1 = __raw_readl(phy_base + 0xec*4);

		if ((((data_rank1 >> 8 & 0xff) == 0xff) && ((data_rank1 >> 20 & 0xf) == 0xf)) ||
			(((data_rank1 >> 16 & 0xf) == 0xf) && ((data_rank1 & 0xff) == 0xff)))
		{
			dmc_print_str("Rank WEYE CA training failed because have not right boundary!\n");
			while_loop();

		}

		data_rank0 = __raw_readl(tmp_addr + 0x12*4);

		//{data_rank1[19:16], data_rank1[7:0]} = {data_rank0[19:16], data_rank0[7:0]}
		data_rank1_bk = (((data_rank1 >> 16) & 0xf) << 8) || (data_rank1 & 0xff);
		data_rank0_bk = (((data_rank0 >> 16) & 0xf) << 8) || (data_rank0 & 0xff);

		//pre calcute the difference of to rank
		if (data_rank1_bk > data_rank0_bk) //rank 1  db0 longer
		{
			fdl_db0_mul_wr_pre = data_rank1_bk - data_rank0_bk;
			ddrc_training_status_table.WR_SHORTER_RANK_DB0 = 0;
		}
		else
		{
			fdl_db0_mul_wr_pre = data_rank0_bk - data_rank1_bk;
			ddrc_training_status_table.WR_SHORTER_RANK_DB0 = 1;
			ddrc_training_status_table.WR_SHORTER_RANK = 1;
		}

		//{data_rank1[23:20], data_rank1[15:8]} = {data_rank0[23:20], data_rank0[15:8]}
		data_rank1_bk = (((data_rank1 >> 20) & 0xf) << 8) || ((data_rank1 >> 8) & 0xff);
		data_rank0_bk = (((data_rank0 >> 20) & 0xf) << 8) || ((data_rank0 >> 8) & 0xff);

		if (data_rank1_bk > data_rank0_bk)
		{
			fdl_db1_mul_wr_pre = data_rank1_bk - data_rank0_bk;
			ddrc_training_status_table.WR_SHORTER_RANK_DB1 = 0;
		}
		else
		{
			fdl_db1_mul_wr_pre = data_rank0_bk - data_rank1_bk;
			ddrc_training_status_table.WR_SHORTER_RANK_DB1 = 1;
		}

		if (ddrc_training_status_table.WR_SHORTER_RANK_DB0  != ddrc_training_status_table.WR_SHORTER_RANK_DB1)
			dmc_print_str("wr_shorter_rank_dbx different\n");

		if (ddrc_training_status_table.WR_SHORTER_RANK_DB0 == 0)
		{
			reg_bits_set(phy_base + 0x348, 8, 4, 2); //reg phy longer wr dl sel db0 <= #'RD reg_wdata[11:8]

			data_tmp = __raw_readl(phy_base + 0x34c);
			data_tmp= u32_bits_set(data_tmp, 0, 6, (fdl_db0_mul_wr_pre*db0_mst_delay)/256/2);
			__raw_writel(phy_base + 0x34c, data_tmp);

			//{data_rank0[19:16], data_rank0[7:0]} = {data_rank0[19:16], data_rank0[7:0]};
			data_rank0 = u32_bits_set(data_rank0, 0, 8, (data_rank0 & 0xff));
			data_rank0 = u32_bits_set(data_rank0, 16, 4, ((data_rank0 >> 16) & 0xf));
			__raw_writel(tmp_addr + 0x12*4, data_rank0);
		}
		else
		{
			reg_bits_set(phy_base + 0x348, 8, 4, 1); //reg phy longer rd dl sel db0 <= #'RD reg_wdata[3:0]

			data_tmp = __raw_readl(phy_base + 0x34c);
			data_tmp= u32_bits_set(data_tmp, 0, 6, fdl_db0_mul_wr_pre*db0_mst_delay/256/2);
			__raw_writel(phy_base + 0x34c, data_tmp);

			//{data_rank0[19:16], data_rank0[7:0]} = {data_rank1[19:16], data_rank1[7:0]};
			data_rank0 = u32_bits_set(data_rank0, 0, 8, (data_rank1 & 0xff));
			data_rank0 = u32_bits_set(data_rank0, 16, 4, ((data_rank1 >> 16)& 0xf));
			__raw_writel(tmp_addr + 0x12*4, data_rank0);
		}

		if (ddrc_training_status_table.WR_SHORTER_RANK_DB1 == 0)
		{
			reg_bits_set(phy_base+ 0x348, 12, 4, 2); //reg phy longer rd dl sel db0 <= #'RD reg_wdata[3:0]

			data_tmp = __raw_readl(phy_base + 0x34c);
			data_tmp= u32_bits_set(data_tmp, 8, 6, fdl_db1_mul_wr_pre*db1_mst_delay/256/2);
			__raw_writel(phy_base + 0x34c, data_tmp);

			//{data_rank0[23:20], data_rank0[15:8]} = {data_rank0[23:20], data_rank0[15:8]};
			data_rank0 = u32_bits_set(data_rank0, 8, 8, ((data_rank0 >> 8)& 0xff));
			data_rank0 = u32_bits_set(data_rank0, 16, 4, ((data_rank0 >> 20)& 0xf));
			__raw_writel(tmp_addr + 0x12*4, data_rank0);
		}
		else
		{
			//data_tmp = __raw_readl(phy_base + 0x348);
			reg_bits_set(phy_base + 0x348, 12, 4, 1); //reg phy longer rd dl sel db0 <= #'RD reg_wdata[3:0]

			data_tmp = __raw_readl(phy_base + 0x34c);
			data_tmp= u32_bits_set(data_tmp, 0, 6, fdl_db1_mul_wr_pre*db1_mst_delay/256/2);
			__raw_writel(phy_base + 0x34c, data_tmp);

			//{data_rank0[23:20], data_rank0[15:8]} = {data_rank1[23:20], data_rank1[15:8]};
			data_rank0 = u32_bits_set(data_rank0, 8, 8, ((data_rank1 >> 8)& 0xff));
			data_rank0 = u32_bits_set(data_rank0, 16, 4, ((data_rank1 >> 20)& 0xf));
			__raw_writel(tmp_addr + 0x12*4, data_rank0);
		}

	}
}
void phy_load_ca_perbit_reg(u32 phy_base, u32 dfs_freq_sel, u32 rank)
{
	u32 data_tmp;
	u32 max_fdl;
	u32 read_data;
	u32 data_tmp1, data_tmp2, data_tmp3;
	u32 data_tmp1_0_7, data_tmp1_8_15, data_tmp1_16_23, data_tmp1_24_31;
	u32 data_tmp2_0_7, data_tmp2_8_15, data_tmp2_16_23, data_tmp2_24_31;
	u32 data_tmp3_0_7, data_tmp3_8_15;//data_tmp3_16_23, data_tmp3_24_31;

	read_data = __raw_readl(phy_base + 0x398);
	if (((read_data >> 16) & 0xFF) < 10)
	{
		dmc_print_str("RANK 0 CA Perbit Training CA window size too small!\n");
		//while_loop();
	}

	//CA per bit deskew training result
	data_tmp1 = __raw_readl(phy_base + 0xef*4);//train_addr3_fdl_cfg_addr[3/2/1/0]_wr
	data_tmp2 = __raw_readl(phy_base + 0xf0*4);//train_addr7_fdl_cfg_addr[7/6/5/4]_wr
	data_tmp3 = __raw_readl(phy_base + 0xf1*4);//train_addr9_fdl_cfg_addr[9/8]_wr

	max_fdl = 0;

	data_tmp1_0_7 = data_tmp1 & 0xff;//addr0_wr
	data_tmp1_8_15 = (data_tmp1 >> 8) & 0xff;//addr1_wr
	data_tmp1_16_23 = (data_tmp1 >>16) & 0xff;//addr2_wr
	data_tmp1_24_31 = (data_tmp1 >> 24) & 0xff;//addr3_wr

	data_tmp2_0_7 = data_tmp2 & 0xff;//addr4_wr
	data_tmp2_8_15 = (data_tmp2 >> 8) & 0xff;//addr5
	data_tmp2_16_23 = (data_tmp2 >>16) & 0xff;//addr6
	data_tmp2_24_31 = (data_tmp2 >> 24) & 0xff;//addr7

	data_tmp3_0_7 = data_tmp3 & 0xff;//addr8
	data_tmp3_8_15 = (data_tmp3 >> 8) & 0xff;//addr9

	if (data_tmp1_0_7 > max_fdl)	max_fdl = data_tmp1_0_7;
	if (data_tmp1_8_15 > max_fdl)	max_fdl = data_tmp1_8_15;
	if (data_tmp1_16_23 > max_fdl)	max_fdl = data_tmp1_16_23;
	if (data_tmp1_24_31 > max_fdl)	max_fdl = data_tmp1_24_31;
	if (data_tmp2_0_7 > max_fdl)	max_fdl = data_tmp2_0_7;
	if (data_tmp2_8_15 > max_fdl)	max_fdl = data_tmp2_8_15;

	if (ddr_chip_cur.chip_type == DRAM_LPDDR3)
	{
		if (data_tmp2_16_23 > max_fdl) max_fdl = data_tmp2_16_23;
		if (data_tmp2_24_31 > max_fdl) max_fdl = data_tmp2_24_31;
		if (data_tmp3_8_15 > max_fdl)   max_fdl = data_tmp3_8_15;
		if (data_tmp3_0_7 > max_fdl)     max_fdl = data_tmp3_0_7;
	}

	//check fdl result
	if ((data_tmp1_0_7 == 0x3f) || (data_tmp1_8_15 == 0x3f)||
		(data_tmp1_16_23 == 0x3f) || (data_tmp1_24_31 == 0x3f) ||
		(data_tmp2_0_7 == 0x3f) || (data_tmp2_8_15 == 0x3f))
	{
		dmc_print_str("Rank Ca perbit training fail because have not right boundary\n");
		while_loop();
	}

	if (ddr_chip_cur.chip_type == DRAM_LPDDR3)
	{
		if ((data_tmp2_16_23 == 0x3f) || (data_tmp2_24_31 == 0x3f) ||
			(data_tmp3_8_15 == 0x3f) || (data_tmp3_0_7 == 0x3f))
		{
			dmc_print_str("Rank Ca perbit training fail because have not right boundary\n");
			while_loop();
		}
	}

	max_fdl = 0x3f - max_fdl;
	data_tmp1 = u32_bits_set(data_tmp1, 0, 8, data_tmp1_0_7 + max_fdl);
	data_tmp1 = u32_bits_set(data_tmp1, 8, 8, data_tmp1_8_15 + max_fdl);
	data_tmp1 = u32_bits_set(data_tmp1, 16, 8, data_tmp1_16_23 + max_fdl);
	data_tmp1 = u32_bits_set(data_tmp1, 24, 8, data_tmp1_24_31 + max_fdl);

	data_tmp2 = u32_bits_set(data_tmp2, 0, 8, data_tmp2_0_7 + max_fdl);
	data_tmp2 = u32_bits_set(data_tmp2, 8, 8, data_tmp2_8_15 + max_fdl);
	if (ddr_chip_cur.chip_type == DRAM_LPDDR3)
	{
		data_tmp2 = u32_bits_set(data_tmp2, 16, 8, data_tmp2_16_23 + max_fdl);
		data_tmp2 = u32_bits_set(data_tmp2, 24, 8, data_tmp2_24_31 + max_fdl);

		data_tmp3 = u32_bits_set(data_tmp3, 8, 8, data_tmp3_8_15+ max_fdl);
		data_tmp3 = u32_bits_set(data_tmp3, 0, 8, data_tmp3_0_7 + max_fdl);
	}
	data_tmp1 = u32_bits_set(data_tmp1, 0, 1, 1);//to create upd pulse, force bit[0] to 0
	__raw_writel((phy_base + 0xb5*4), data_tmp1);//fdl_addr3_wr_cfg_addr[3/2/1/0]
	__raw_writel((phy_base + 0xb6*4), data_tmp2);//fdl_addr7_wr_cfg_addr[7/6/5/4]

	if (ddr_chip_cur.chip_type == DRAM_LPDDR3)
	{
		data_tmp = __raw_readl(phy_base + 0xb7*4);
		data_tmp = u32_bits_set(data_tmp, 0, 16, data_tmp3 & 0xffff);//fdl_base_delay_cfg_addr[9/8]
		__raw_writel((phy_base + 0xb7*4), data_tmp);
	}
}

void phy_load_rw_perbit_reg(u32 wr_bit, u32 phy_base, u32 dfs_freq_sel, u32 rank)
{
	u32 data_tmp;
	u32 max_fdl;
	u32 data_tmp1, data_tmp2, data_tmp3, data_tmp4, data_tmp5;
	u32 data_tmp1_0_7, data_tmp1_8_15, data_tmp1_16_23, data_tmp1_24_31;
	u32 data_tmp2_0_7, data_tmp2_8_15, data_tmp2_16_23, data_tmp2_24_31;
	u32 data_tmp3_0_7, data_tmp3_8_15;//, data_tmp3_16_23, data_tmp3_24_31;
	u32 data_tmp4_0_7, data_tmp4_8_15, data_tmp4_16_23, data_tmp4_24_31;
	u32 data_tmp5_0_7, data_tmp5_8_15, data_tmp5_16_23, data_tmp5_24_31;

	max_fdl = 0;
	if (((wr_bit >>9) & 0x1)) //RPERB dm use dq0
	{
		data_tmp1 = __raw_readl(phy_base + 0xf6*4);
		data_tmp2 = __raw_readl(phy_base + 0xf5*4);
		data_tmp3 = __raw_readl(phy_base + 0xf4*4);
		data_tmp4 = __raw_readl(phy_base + 0xf3*4);
		data_tmp5 = __raw_readl(phy_base + 0xf2*4);

		data_tmp1_0_7 = data_tmp1 & 0xff;
		data_tmp1_8_15 = (data_tmp1 >> 8) & 0xff;
		data_tmp1_16_23 = (data_tmp1 >>16) & 0xff;
		data_tmp1_24_31 = (data_tmp1 >> 24) & 0xff;

		data_tmp2_0_7 = data_tmp2 & 0xff;
		data_tmp2_8_15 = (data_tmp2 >> 8) & 0xff;
		data_tmp2_16_23 = (data_tmp2 >>16) & 0xff;
		data_tmp2_24_31 = (data_tmp2 >> 24) & 0xff;

		//check fdl result
		if ((data_tmp1_24_31 == 0) || (data_tmp1_16_23 ==0) ||
		(data_tmp1_8_15 == 0) || (data_tmp1_0_7 == 0) ||
		(data_tmp2_24_31 == 0) || (data_tmp2_16_23 == 0) ||
		(data_tmp2_8_15 == 0) || (data_tmp2_0_7 == 0))
		{
			dmc_print_str("Read perbit traininig  rank failed because have not right boundary\n");
			while_loop();
		}

		//set dm to dq0
		//data_tmp3[31:24] = data_tmp2[7:0]
		data_tmp3 = u32_bits_set(data_tmp3, 24, 8, (data_tmp2 & 0xff));//f5[7:0] is reg ro rd db1 dq3 fdl cfg db1 dq0

		data_tmp3_0_7 = data_tmp3 & 0xff;
		data_tmp3_8_15 = (data_tmp3 >> 8) & 0xff;

		data_tmp4_0_7 = data_tmp4 & 0xff;
		data_tmp4_8_15 = (data_tmp4 >> 8) & 0xff;
		data_tmp4_16_23 = (data_tmp4 >>16) & 0xff;
		data_tmp4_24_31 = (data_tmp4 >> 24) & 0xff;

		data_tmp5_16_23 = (data_tmp5 >>16) & 0xff;
		data_tmp5_24_31 = (data_tmp5 >> 24) & 0xff;

		if ((data_tmp3_8_15 == 0) || (data_tmp3_0_7 == 0) ||
		(data_tmp4_24_31 == 0) || (data_tmp4_16_23 == 0) ||
		(data_tmp4_8_15 == 0) || (data_tmp4_0_7 == 0) ||
		(data_tmp5_24_31 == 0) || (data_tmp5_16_23 == 0))
		{
			dmc_print_str("Read perbit traininig rank failed because have not right boundary\n");
			while_loop();
		}

		//set dm to dq0
		//data_tmp5[15:8] = data_tmp5[23:16]
		data_tmp5 = u32_bits_set(data_tmp5, 8, 8,((data_tmp5 >> 16) & 0xff));//[23:16] is reg ro rd db0 dq1 fdl cfg db0 dq0
		//PHY read path per bit deskew manual mode setting
		/*0x02Ff0; 0x02EC; 0x02E8; 0x02E4; 0x02E0*/
		__raw_writel(phy_base + 0xbc*4, data_tmp1);
		__raw_writel(phy_base + 0xbb*4, data_tmp2);
		__raw_writel(phy_base + 0xba*4, data_tmp3);
		__raw_writel(phy_base + 0xb9*4, data_tmp4);
		__raw_writel(phy_base + 0xb8*4, data_tmp5);

		/*0x0388 MLB training search read out register*/
		/*
		bit[3:0] wdqs_search_result_cfg_rdqs_sucess
		*/
		data_tmp = __raw_readl(phy_base + 0xe2*4);
		if ((data_tmp & 0xf) != 0xf)
		{
			dmc_print_str("perbit read rank training failed\n");
			while_loop();
		}
	}

	if ((wr_bit >> 12) & 0x1) //WPERB dm use dq0
	{
		//load WPERB
		data_tmp1 = __raw_readl(phy_base + 0xf7*4);
		data_tmp2 = __raw_readl(phy_base + 0xf8*4);
		data_tmp3 = __raw_readl(phy_base + 0xf9*4);
		data_tmp4 = __raw_readl(phy_base + 0xfa*4);
		data_tmp5 = __raw_readl(phy_base + 0xfb*4);

		//db1
		max_fdl = 0;
		data_tmp1_0_7 = data_tmp1 & 0xff;
		data_tmp1_8_15 = (data_tmp1 >> 8) & 0xff;
		data_tmp1_16_23 = (data_tmp1 >>16) & 0xff;
		data_tmp1_24_31 = (data_tmp1 >> 24) & 0xff;

		data_tmp2_0_7 = data_tmp2 & 0xff;
		data_tmp2_8_15 = (data_tmp2 >> 8) & 0xff;
		data_tmp2_16_23 = (data_tmp2 >>16) & 0xff;
		data_tmp2_24_31 = (data_tmp2 >> 24) & 0xff;

		data_tmp3_0_7 = data_tmp3 & 0xff;
		data_tmp3_8_15 = (data_tmp3 >> 8) & 0xff;
		//data_tmp3_16_23 = (data_tmp3 >>16) & 0xff;
		//data_tmp3_24_31 = (data_tmp3 >> 24) & 0xff;

		if (data_tmp1_24_31 > max_fdl) max_fdl = data_tmp1_24_31;
		if (data_tmp1_16_23 > max_fdl) max_fdl = data_tmp1_16_23;
		if (data_tmp2_24_31 > max_fdl) max_fdl = data_tmp2_24_31;
		if (data_tmp2_16_23 > max_fdl) max_fdl = data_tmp2_16_23;
		if (data_tmp2_8_15 > max_fdl) max_fdl = data_tmp2_8_15;
		if (data_tmp2_0_7 > max_fdl) max_fdl = data_tmp2_0_7;
		if (data_tmp3_8_15 > max_fdl) max_fdl = data_tmp3_8_15;
		if (data_tmp3_0_7 > max_fdl) max_fdl = data_tmp3_0_7;

		//check fdl result
		if ((data_tmp1_24_31 == 0x3f) || (data_tmp1_16_23 == 0x3f) ||
		(data_tmp2_24_31 == 0x3f) || (data_tmp2_16_23 == 0x3f) ||
		(data_tmp2_8_15 == 0x3f) || (data_tmp2_0_7 == 0x3f)||
		(data_tmp3_8_15 == 0x3f) || (data_tmp3_0_7 == 0x3f))
		{
			dmc_print_str("Write perbit rank traininig failed because 3dc,3e0,3e4 have not right boundary;\n");
			while_loop();
		}

		max_fdl = 0x3f - max_fdl;
		data_tmp1 = u32_bits_set(data_tmp1, 24, 8, data_tmp1_24_31 + max_fdl);
		data_tmp1 = u32_bits_set(data_tmp1, 16, 8, data_tmp1_16_23 + max_fdl);

		data_tmp2 = u32_bits_set(data_tmp2, 24, 8, data_tmp2_24_31 + max_fdl);
		data_tmp2 = u32_bits_set(data_tmp2, 16, 8, data_tmp2_16_23 + max_fdl);
		data_tmp2 = u32_bits_set(data_tmp2, 8, 8, data_tmp2_8_15 + max_fdl);
		data_tmp2 = u32_bits_set(data_tmp2, 0, 8, data_tmp2_0_7 + max_fdl);
		data_tmp3 = u32_bits_set(data_tmp3, 8, 8, data_tmp3_8_15 + max_fdl);
		data_tmp3 = u32_bits_set(data_tmp3, 0, 8, data_tmp3_0_7 + max_fdl);

		//set dm and dqs
		/*
		[23:16] wr_db0_dq1_fdl_cfg_db0_dq0
		[15:08] wr_db0_dq1_fdl+cfg_db0_dm
		*/
		//data_tmp1[15:8] = data_tmp1[23:16]
		data_tmp1 = u32_bits_set(data_tmp1, 8, 8, ((data_tmp1 >> 16) & 0xff ) );

		//db0
		max_fdl = 0;
		data_tmp4_0_7 = data_tmp4 & 0xff;
		data_tmp4_8_15 = (data_tmp4 >> 8) & 0xff;
		data_tmp4_16_23 = (data_tmp4 >>16) & 0xff;
		data_tmp4_24_31 = (data_tmp4 >> 24) & 0xff;

		data_tmp5_0_7 = data_tmp5 & 0xff;
		data_tmp5_8_15 = (data_tmp5 >> 8) & 0xff;
		data_tmp5_16_23 = (data_tmp5 >>16) & 0xff;
		data_tmp5_24_31 = (data_tmp5 >> 24) & 0xff;

		if (data_tmp4_24_31 > max_fdl) max_fdl = data_tmp4_24_31;
		if (data_tmp4_16_23 > max_fdl) max_fdl = data_tmp4_16_23;
		if (data_tmp4_8_15 > max_fdl) max_fdl = data_tmp4_8_15;
		if (data_tmp4_0_7 > max_fdl) max_fdl = data_tmp4_0_7;

		if (data_tmp5_24_31 > max_fdl) max_fdl = data_tmp5_24_31;
		if (data_tmp5_16_23 > max_fdl) max_fdl = data_tmp5_16_23;
		if (data_tmp5_8_15 > max_fdl) max_fdl = data_tmp5_8_15;
		if (data_tmp5_0_7 > max_fdl) max_fdl = data_tmp5_0_7;

		//check fdl result
		if ((data_tmp4_24_31 == 0x3f) || (data_tmp4_16_23 ==0x3f) ||
		(data_tmp4_8_15   == 0x3f) || (data_tmp4_0_7    == 0x3f) ||
		(data_tmp5_24_31 == 0x3f) || (data_tmp5_16_23 == 0x3f)||
		(data_tmp5_8_15   == 0x3f) || (data_tmp5_0_7    == 0x3f))
		{
			dmc_print_str("Write perbit rank traininig failed because 3E8,3EC,have not right boundary;\n");
			while_loop();
		}
		max_fdl = 0x3f -max_fdl;
		data_tmp4 = u32_bits_set(data_tmp4, 24, 8, data_tmp4_24_31 + max_fdl);
		data_tmp4 = u32_bits_set(data_tmp4, 16, 8, data_tmp4_16_23 + max_fdl);
		data_tmp4 = u32_bits_set(data_tmp4, 8, 8, data_tmp4_8_15 + max_fdl);
		data_tmp4 = u32_bits_set(data_tmp4, 0, 8, data_tmp4_0_7 + max_fdl);

		data_tmp5 = u32_bits_set(data_tmp5, 8, 8, data_tmp5_24_31 + max_fdl);
		data_tmp5 = u32_bits_set(data_tmp5, 0, 8, data_tmp5_16_23 + max_fdl);
		data_tmp5 = u32_bits_set(data_tmp5, 8, 8, data_tmp5_8_15 + max_fdl);
		data_tmp5 = u32_bits_set(data_tmp5, 0, 8, data_tmp5_0_7 + max_fdl);

		//set dm and dqs
		/*0x03E4 [31:24]= 0x03E8 [7:0] */
		/*
		0x03E4
		bit[31:24] wr_db1_dm_fdl_cfg_db1_dm
		*/
		/*
		0x03E8
		bit[7:0] wr_db1_dq3_fdl_cfg_db1_dq0
		*/
		//data_tmp3[31:24] = data_tmp4[7:0]
		data_tmp3 = u32_bits_set(data_tmp3, 24, 8, (data_tmp4 & 0xff ) );
		data_tmp1 = u32_bits_set(data_tmp1, 16, 1, 0x1);

		/*PHY write path per bit deskew manual mode setting*/
		/*0x02F4; 0x02F8; 0x02FC; 0x0300; 0x0304*/
		__raw_writel(phy_base + 0xbd*4, data_tmp1);
		__raw_writel(phy_base + 0xbe*4, data_tmp2);
		__raw_writel(phy_base + 0xbf*4, data_tmp3);
		__raw_writel(phy_base + 0xc0*4, data_tmp4);
		__raw_writel(phy_base + 0xc1*4, data_tmp5);

		/*
		    0x0388 MLB training search read out register
		    bit[7:4] wdqs_search_result_cfg_wrdq_sucess
		*/
		data_tmp = __raw_readl(phy_base + 0xe2*4);
		if (((data_tmp >> 4) & 0xf) != 0xf)
		{
			dmc_print_str("Perbit write rank training failed\n");
			while_loop();
		}
	}
}

void odt_set_for_ca_train(u32 phy_base, u32 dfs_freq_sel, u32  odt_on)
{
	u32 data_tmp;
	u32 tmp_addr = phy_base + dfs_freq_sel *20*4;

	if (odt_on)
	{
		/*F0-7 phy otd and ocd setting*/
		/*bit[22:20] rpull_cfg_ca_drvp*/
		/*bit[18:16] rpull_cfg_ca_drvp*/
		/*bit[14:12] rpull_cfg_data_drvp*/
		/*bit[10:8] rpull_cfg_data_drvn*/
		/*bit[6:4] rpull_cfg_odtp*/
		/*bit[2:0] rpull_cfg_odtn*/
		/*but*/
		data_tmp = __raw_readl(tmp_addr + 0x9*4);
		data_tmp= u32_bits_set(data_tmp, 0, 3, 0x1);
		data_tmp= u32_bits_set(data_tmp, 4, 3, 0x0);
		__raw_writel(tmp_addr + 0x9*4, data_tmp);
	}
	else
	{
		data_tmp = __raw_readl(tmp_addr + 0x9*4);//0x0024
		data_tmp= u32_bits_set(data_tmp, 0, 3, 0x0);//rpull_cfg_odtn
		data_tmp= u32_bits_set(data_tmp, 4, 3, 0x0);//rpull_cfg_odtp
		__raw_writel(tmp_addr + 0x9*4, data_tmp);

	}
	/*F0-7 PHY read odt and write odt control*/
	/*bit[31] mlb_wrodt_alwayson_cfg_wrodt_alwaysoff*/
	/*bit[26:24] mlb_wrodt_alwayson_cfg_wrodt_en_dly*/
	/*bit[21:16] mlb_wrodt_alwayson_cfg_wrodt_cnt_intg*/
	/*bit[15] mlb_wrodt_alwayson_cfg_rdodt_alwayson*/
	/*bit[10:8] mlb_wrodt_alwayson_cfg_rdodt_en_dly*/
	/*bit[5:0] mlb_wrodt_alwayson_cfg_rdodt_cnt_intg*/
	reg_bits_set((tmp_addr + 0xa*4), 15, 1, odt_on);

}

void trigger_training_done(u32 wr_bit, u32 rd_bit)
{
	u32 src_rank = 0;
	u32 data_tmp;
	u32 read_data;
	/*step 0) add for modify rank*/
	if (ddrc_training_status_table.rank1_training_done)
	{
		data_tmp = __raw_readl(DMC_GUCPHY0_BASE + 0x2b0);
		src_rank = (data_tmp >> 12) & 0x3;//dat_tmp[13:12] mlb_multi_rank_cfg_multi_rank

		reg_bits_set((DMC_GUCPHY0_BASE + 0x2b0), 12, 2, ddrc_training_status_table.CA_SHORTER_RANK);//cfg_multi_rank
		reg_bits_set((DMC_GUCPHY1_BASE + 0x2b0), 12, 2, ddrc_training_status_table.CA_SHORTER_RANK);//cfg_multi_rank
	}

	/*step 1) training start traininig*/
	/*0x02cc training enable control
	[31:24] mlb_train_wdqs_stop_step_cfg_wdqs_stop_step
	[22:20] mlb_train_wdqs_stop_step_cfg_wdqs_top_intg
	[18:16] mlb_train_wdqs_stop_step_cfg_data_training_mode
	[15:15] mlb_train_wdqs_stop_step_cfg_gate_fast_mode
	[14:14] mlb_train_wdqs_stop_step_cfg_wrvref_disable
	[13:13] mlb_train_wdqs_stop_step_cfg_wreye_enable
	[12:12] mlb_train_wdqs_stop_step_cfg_wr_perbit_disable
	[11:11] mlb_train_wdqs_stop_step_cfg_rdvref_disable
	[10:10] mlb_train_wdqs_stop_step_cfg_rdeye_enable
	[9]	mlb_train_wdqs_stop_step_cfg_rd_perbit_disable
	[8]	mlb_train_wdqs_stop_step_cfg_train_gate_enable
	[6]	mlb_train_wdqs_stop_step_cfg_train_ca_enable
	[5]	mlb_train_wdqs_stop_step_cfg_ca_perbit_disable
	[4]	mlb_train_wdqs_stop_step_cfg_cal_ncomp_first
	[3]	mlb_train_wdqs_stop_step_cfg_cal_manual_pwrdn
	[2]	mlb_train_wdqs_stop_step_cfg_cal_manual_mode
	[1]	mlb_train_wdqs_stop_step_cfg_disable
	[0]	mlb_train_wdqs_stop_step_cfg_train_start
	*/
	data_tmp = __raw_readl(DMC_GUCPHY0_BASE + 0x2cc);//mlb_train_wdqs_stop_step_cfg_XX
	__raw_writel(DMC_GUCPHY0_BASE + 0x2cc, data_tmp^wr_bit);

	data_tmp = __raw_readl(DMC_GUCPHY1_BASE + 0x2cc);//mlb_train_wdqs_stop_step_cfg_XX
	__raw_writel(DMC_GUCPHY1_BASE + 0x2cc, data_tmp^wr_bit);

	/*step 2) polling training done*/
	/*0x00358 DDR PHY status read out register*/
	/*
	[27] ro_phy_stat_cfg_train_done
	[26] ro_phy_stat_cfg_train_start
	[25] ro_phy_stat_cfg_vref_done
	[24] ro_phy_stat_cfg_vref_start
	[23] ro_phy_stat_cfg_wteye_done
	[22] ro_phy_stat_cfg_wteye_start
	[21] ro_phy_stat_cfg_wt_perbit_done
	[20] ro_phy_stat_cfg_wt_perbit_start
	[19] ro_phy_stat_cfg_rdeye_done
	[18] ro_phy_stat_cfg_rdeye_start
	[17] ro_phy_stat_cfg_rd_perbit_done
	[16] ro_phy_stat_cfg_rd_perbit_start
	[15] ro_phy_stat_cfg_gate_done
	[14] ro_phy_stat_cfg_gate_start
	[13] ro_phy_stat_cfg_wlvl_done
	[12] ro_phy_stat_cfg_wlvl_start
	[11] ro_phy_stat_cfg_ca_done
	[10] ro_phy_stat_cfg_ca_start
	[9]  ro_phy_stat_cfg_ca_perbit_done
	[8]  ro_phy_stat_cfg_ca_perbit_start
	[7]  ro_phy_stat_cfg_automrs_done
	[6]  ro_phy_stat_cfg_automrs_start
	[5]  ro_phy_stat_cfg_runtime_fail
	[4]  ro_phy_stat_cfg_runtime_done
	[3]  ro_phy_stat_cfg_cal_fail
	[2]  ro_phy_stat_cfg_iopvt_done
	[1]  ro_phy_stat_cfg_dfi_done
	[0]  ro_phy_stat_cfg_pll_lock
	*/
	while(1)
	{
		read_data = __raw_readl(DMC_GUCPHY0_BASE + 0xd6*4);
		data_tmp = read_data & rd_bit;
		if (data_tmp > 0)
			break;
	}

	while(1)
	{
		read_data = __raw_readl(DMC_GUCPHY1_BASE + 0xd6*4);
		data_tmp = read_data & rd_bit;
		if (data_tmp > 0)
			break;
	}

	/*step 3) add for modify rank*/
	if (ddrc_training_status_table.rank1_training_done)
	{
		reg_bits_set(DMC_GUCPHY0_BASE + 0x2b0, 12, 2, src_rank);//cfg_multi_rank
		reg_bits_set(DMC_GUCPHY1_BASE + 0x2b0, 12, 2, src_rank);//cfg_multi_rank
	}
}
void disable_this_training(u32 wr_bit)
{
	u32 data_tmp;
	dmc_dosoft_cmd_setting(0x80200000);//dsoft_auto_ref

	data_tmp = __raw_readl(DMC_GUCPHY0_BASE + 0x2cc);
	__raw_writel(DMC_GUCPHY0_BASE + 0x2cc, data_tmp^wr_bit);

	data_tmp = __raw_readl(DMC_GUCPHY1_BASE + 0x2cc);
	__raw_writel(DMC_GUCPHY1_BASE + 0x2cc, data_tmp^wr_bit);
}
void ddrc_ctrl_mode_setting(u32 wr_bit)
{
	//DDRC_R1P0_REG_INFO_PTR pdmc = (DDRC_R1P0_REG_INFO_PTR)DMC_REG_ADDR_BASE_PHY;
	u32 data_tmp;
	if (((wr_bit >> 14) & 1) == 1)
	{
		data_tmp = reg_bits_get((DMC_GUCPHY0_BASE + 0xe9*4), 24, 6);
		/*
		pdmc->dmc_dcfg2 = data_tmp;
		pdmc->dmc_dcfg1 = 0x810000E;//mr14 write vref(dq)
		while(((pdmc->dmc_dcfg1 >> 19) & 0x1ff) != 0);
		*/
		lpddr_dmc_mrw(CMD_CS_BOTH, 0xE, data_tmp);
		dmc_sprd_delay(200);//vrcg
	}
}
void rw_eye_training_flow(u32 wr_bit, u32 rd_bit, u32 dfs_freq_sel, u32 rank)
{
	trigger_training_done(wr_bit, rd_bit);

	//step 1) read training result and write to manual mode register
	if (rank == 0)
	{
		phy_reload_rank_0_reg(wr_bit, DMC_GUCPHY0_BASE, dfs_freq_sel, rank);
		phy_reload_rank_0_reg(wr_bit, DMC_GUCPHY1_BASE, dfs_freq_sel, rank);
	}
	else
	{
		phy_reload_rank_1_reg(wr_bit, DMC_GUCPHY0_BASE, dfs_freq_sel, rank);
		phy_reload_rank_1_reg(wr_bit, DMC_GUCPHY1_BASE, dfs_freq_sel, rank);
	}

	//step 2) soft send precharge all and auto refres
	dmc_dosoft_cmd_setting(0x80100000);//dsoft_pre_all

	if (ddr_chip_cur.chip_type == DRAM_LPDDR4)
	{
		ddrc_ctrl_mode_setting(wr_bit);
	}
	//step 5) disable this training
	disable_this_training(wr_bit);
}
void phy_gate_seq(u32 dfs_freq_sel)
{
	//u32 wr_bit = BIT08_GATE;
	//u32 rd_bit = BIT15_GATE_DONE;

	ddrc_phy_rpull_set_for_gate_train(DMC_GUCPHY0_BASE, dfs_freq_sel);
	ddrc_phy_rpull_set_for_gate_train(DMC_GUCPHY0_BASE, dfs_freq_sel);
}
void phy_rwvref_seq(u32 dfs_freq_sel, u32 rw_sel, u32 rank)
{
	u32 wr_bit = BIT14_WVREF;
	u32 rd_bit = BIT23_WREYE_DONE;
	if (rw_sel == 0)
	{
		wr_bit = BIT11_RVREF;
		rd_bit = BIT19_RDEYE_DONE;
	}

	rw_eye_training_flow(wr_bit, rd_bit, dfs_freq_sel, rank);
}

void phy_rweye_seq(u32 dfs_freq_sel, u32 rw_sel, u32 rank)
{
	u32 wr_bit = BIT13_WREYE;
	u32 rd_bit = BIT23_WREYE_DONE;
	if (rw_sel == 0)
	{
		wr_bit = BIT10_RDEYE;
		rd_bit = BIT19_RDEYE_DONE;
	}

	rw_eye_training_flow(wr_bit, rd_bit, dfs_freq_sel, rank);
}

void phy_rwpbit_seq(u32 dfs_freq_sel, u32 rw_sel)
{
	u32 wr_bit = BIT12_WPERB;
	u32 rd_bit = BIT23_WREYE_DONE;

	if (rw_sel == 0)
	{
		wr_bit = BIT09_RPERB;
		rd_bit = BIT19_RDEYE_DONE;
		ddrc_training_status_table.RDPERBIT_DONE =1 ;
	}
	else
	{
		ddrc_training_status_table.WRPERBIT_DONE = 1;
	}

	trigger_training_done(wr_bit, rd_bit);

	/*step 3) read traininig result and write to manual mode register*/
	phy_load_rw_perbit_reg(wr_bit, DMC_GUCPHY0_BASE, dfs_freq_sel, 0);
	phy_load_rw_perbit_reg(wr_bit, DMC_GUCPHY1_BASE, dfs_freq_sel, 0);
	//db0
	reg_bits_set(DMC_GUCPHY0_BASE + 0xbd*4, 16, 1, 0);//to create upd pulse toggle[0]
	reg_bits_set(DMC_GUCPHY1_BASE + 0xbd*4, 16, 1, 0);//to create upd pulse toggle[0]
	reg_bits_set(DMC_GUCPHY0_BASE + 0xbd*4, 16, 1, 1);//to create upd pulse toggle[0]
	reg_bits_set(DMC_GUCPHY1_BASE + 0xbd*4, 16, 1, 1);//to create upd pulse toggle[0]
	reg_bits_set(DMC_GUCPHY0_BASE + 0xbd*4, 16, 1, 0);//to create upd pulse toggle[0]
	reg_bits_set(DMC_GUCPHY1_BASE + 0xbd*4, 16, 1, 0);//to create upd pulse toggle[0]
	//db1
	reg_bits_set(DMC_GUCPHY0_BASE + 0xc0*4, 0, 1, 0);//to create upd pulse toggle[0]
	reg_bits_set(DMC_GUCPHY1_BASE + 0xc0*4, 0, 1, 0);//to create upd pulse toggle[0]
	reg_bits_set(DMC_GUCPHY0_BASE + 0xc0*4, 0, 1, 1);//to create upd pulse toggle[0]
	reg_bits_set(DMC_GUCPHY1_BASE + 0xc0*4, 0, 1, 1);//to create upd pulse toggle[0]
	reg_bits_set(DMC_GUCPHY0_BASE + 0xc0*4, 0, 1, 0);//to create upd pulse toggle[0]
	reg_bits_set(DMC_GUCPHY1_BASE + 0xc0*4, 0, 1, 0);//to create upd pulse toggle[0]
	dmc_sprd_delay(200);

	/*step 4) soft send precharge all and auto refresh*/
	dmc_dosoft_cmd_setting(0x80100000);

	if (ddr_chip_cur.chip_type == DRAM_LPDDR4)
	{
		ddrc_ctrl_mode_setting(wr_bit);
	}

	/*step 5) disable this training*/
	disable_this_training(wr_bit);
}
int phy_caeye_seq(u32 dfs_freq_sel, u32 rank)
{
	u32 wr_bit = BIT06_CA;
	u32 rd_bit  = BIT11_CA_DONE;
	u32 data_tmp;
	int regval1,regval2;

	//printf("CA Training Start !\n");
	/*step 1) special set for CA*/
	odt_set_for_ca_train(DMC_GUCPHY0_BASE, dfs_freq_sel, 1);
	odt_set_for_ca_train(DMC_GUCPHY1_BASE, dfs_freq_sel, 1);

	/*step 2) selfrefresh for LP4 ca training*/
	if (ddr_chip_cur.chip_type == DRAM_LPDDR4)
	{
		data_tmp = reg_bits_get((DMC_REG_ADDR_BASE_PHY + 0x0124), 24, 2);
		if (data_tmp != 0x3  )//ch0_rfdmem_cmd_chip_sleep
		{
			dmc_dosoft_cmd_setting(0x80100000);//bit[20] dosoft_precharge_all
			dmc_dosoft_cmd_setting(0x80200000);//bit[21] dosoft_auto_ref
			dmc_dosoft_cmd_setting(0x80400000);//bit[22] dosoft_self_ref
		}
	}

	/*step 3) special set for lpddr3 perbit training*/
	if (ddr_chip_cur.chip_type == DRAM_LPDDR3)
	{
		//if (((wr_bit >> 5) & 0x1))//CA_PERBIT
		{
			reg_bits_set(DMC_GUCPHY0_BASE + 0x2b0, 3, 1, 1);//mlb_multi_rank_cfg-bit[3]ca end bt
			reg_bits_set(DMC_GUCPHY1_BASE + 0x2b0, 3, 1, 1);//mlb_multi_rank_cfg-bit[3]ca end bt
		}
	}

	/*step 4) cfg_vref_ca_disable 0x02b0*/
	reg_bits_set(DMC_GUCPHY0_BASE + 0xac*4, 1, 1, 1);//mlb_multi_rank_cfg_vref_ca_disable
	reg_bits_set(DMC_GUCPHY1_BASE + 0xac*4, 1, 1, 1);//mlb_multi_rank_cfg_vref_ca_disable

	trigger_training_done(wr_bit, rd_bit);

	/*step 6) read training result and write to manual mode register*/
	regval1 = ca_reload_rank_reg(DMC_GUCPHY0_BASE, dfs_freq_sel, rank);
	regval2 = ca_reload_rank_reg(DMC_GUCPHY1_BASE, dfs_freq_sel, rank);

	/*step 7) soft send precharge all and auto refresh*/
	data_tmp = reg_bits_get((DMC_REG_ADDR_BASE_PHY + 0x124), 24, 2);
	if (data_tmp == 0x3)
	{
		dmc_dosoft_cmd_setting(0x80800000);//dsoft_resume
	}
	dmc_dosoft_cmd_setting(0x80100000);//dsoft_precharge_all

	/*step 8) disable this training*/
	disable_this_training(wr_bit);

	/*step9) special set for ca traininig*/
	odt_set_for_ca_train(DMC_GUCPHY0_BASE, dfs_freq_sel, 0);
	odt_set_for_ca_train(DMC_GUCPHY1_BASE, dfs_freq_sel, 0);

	/*step 10) check training result*/
	/*0x0398 CA training coarse and fine delay training*/
	/*
	[31:31] vref_dram_ca_train_cfg_fail
	[29:24] vref_dram_ca_result_cfg_vref_dram
	[23:16] vref_dram_ca_pass_window
	[15:08] vref_dram_ca_result_cfg_fine
	[07:00] vref_dram_ca_result_cfg_coarse
	*/
	if ((regval1 < 0) || (regval2 < 0))
		return -1;

	data_tmp = reg_bits_get((DMC_GUCPHY0_BASE + 0xe6*4), 31, 1);
	if (data_tmp)
	{
		dmc_print_str("PHY 0  rank CA traininig  failed\n");
		return -2;
	}

	data_tmp = reg_bits_get((DMC_GUCPHY1_BASE + 0xe6*4), 31, 1);
	if ((data_tmp >> 31) & 0x1)
	{
		dmc_print_str("PHY 1 rank CA traininig failed\n");
		return -2;
	}
	return 1;

}

void phy_caperbit_seq(u32 dfs_freq_sel, u32 rank)
{
	u32 wr_bit = BIT05_CA_PERB;
	u32 rd_bit  = BIT11_CA_DONE;
	u32 data_tmp;
	ddrc_training_status_table.CAPERBIT_DONE = 1;

	/*step 1) special set for CA*/
	odt_set_for_ca_train(DMC_GUCPHY0_BASE, dfs_freq_sel, 1);
	odt_set_for_ca_train(DMC_GUCPHY1_BASE, dfs_freq_sel, 1);

	/*step 2) selfrefresh for LP4 ca training*/
	if (ddr_chip_cur.chip_type == DRAM_LPDDR4)
	{
		data_tmp = reg_bits_get((DMC_REG_ADDR_BASE_PHY + 0x124), 24, 2);
		if (data_tmp != 0x3)//ch0_rfdmem_cmd_chip_sleep
		{
			dmc_dosoft_cmd_setting(0x80100000);//bit[20] dosoft_pre_all
			dmc_dosoft_cmd_setting(0x80200000);//bit[21] dosoft_auto_ref
			dmc_dosoft_cmd_setting(0x80400000);//bit[22] dosoft_self_ref
		}
	}
	else //for lpddr3
	{
		/*step 0.2) special set for lpddr3 perbit training*/
		/*0x02B0 MLB training setting*/
		/*bit[3] mlb_multi_rank_cfg_ca_end_bt*/
		if ((wr_bit >> 5) & 0x1) //CA PERB
		{
			reg_bits_set((DMC_GUCPHY0_BASE + 0x2b0), 3, 1, 1);
			reg_bits_set((DMC_GUCPHY1_BASE + 0x2b0), 3, 1, 1);
		}
	}

	/*step 3) cfg_vref_ca_disable */
	//0x02B0 bit[1] mbl_multi_rank_cfg_vref_ca_disable
	reg_bits_set((DMC_GUCPHY0_BASE + 0xac*4), 1, 1, 1);//mlb_multi_rank_cfg_vref_ca_disable
	reg_bits_set((DMC_GUCPHY1_BASE + 0xac*4), 1, 1, 1);//mlb_multi_rank_cfg_vref_ca_disable

	/*step 4) polling training done*/
	trigger_training_done(wr_bit, rd_bit);


	/*step 5) read training result and write to manual mode register*/
	phy_load_ca_perbit_reg(DMC_GUCPHY0_BASE, dfs_freq_sel, rank);
	phy_load_ca_perbit_reg(DMC_GUCPHY1_BASE, dfs_freq_sel, rank);

	reg_bits_set((DMC_GUCPHY0_BASE + 0xb5*4), 0, 1, 0);//to create upd pulse toggle[0]
	reg_bits_set((DMC_GUCPHY1_BASE + 0xb5*4), 0, 1, 0);//to create upd pulse toggle[0]
	reg_bits_set((DMC_GUCPHY0_BASE + 0xb5*4), 0, 1, 1);//to create upd pulse toggle[0]
	reg_bits_set((DMC_GUCPHY1_BASE + 0xb5*4), 0, 1, 1);//to create upd pulse toggle[0]
	reg_bits_set((DMC_GUCPHY0_BASE + 0xb5*4), 0, 1, 0);//to create upd pulse toggle[0]
	reg_bits_set((DMC_GUCPHY1_BASE + 0xb5*4), 0, 1, 0);//to create upd pulse toggle[0]
	dmc_sprd_delay(200);

	/*step 6) soft send precharge all and auto refresh*/
	data_tmp = reg_bits_get((DMC_REG_ADDR_BASE_PHY + 0x124), 24, 2);
	if (data_tmp == 0x3  )
	{
		dmc_dosoft_cmd_setting(0x80800000);//dsoft_resume
	}
	dmc_dosoft_cmd_setting(0x80100000);//dsoft_pre_all


	/*step 7) disable this training*/
	disable_this_training(wr_bit);

	/*step 7) special set for ca traininig*/
	odt_set_for_ca_train(DMC_GUCPHY0_BASE, dfs_freq_sel, 0);
	odt_set_for_ca_train(DMC_GUCPHY1_BASE, dfs_freq_sel, 0);

	/*step 8) check training result*/
	data_tmp = reg_bits_get((DMC_GUCPHY0_BASE + 0xe6*4), 31, 1);//0x0398
	if (data_tmp)
	{
		dmc_print_str("phy 0 ca perbit traininig failed\n");
		while_loop();
	}

	data_tmp = reg_bits_get((DMC_GUCPHY1_BASE + 0xe6*4), 31, 1);
	if (data_tmp)
	{
		dmc_print_str("phy 1 ca perbit traininig failed\n");
		while_loop();
	}
}

void training_process_ctrl_pre(u32 phy_base, u32 dfs_freq_sel, u32 rank)
{
    u32 tmp_addr = phy_base + (dfs_freq_sel*20*4);

    //step 1) cfg multi rank
    reg_bits_set(phy_base + 0x2b0, 12, 2, rank);

    //step 2) disable dcc clock gate and setting manual mode
    //bit[8]dcc_ag_en_cfg_dcc_ag_en
    //reg_bits_set(tmp_addr + 0xb*4, 8, 1, 0);

    //step 3) rpull cfg
    reg_bits_set(tmp_addr + 0x9*4, 31, 1, 1); //cfg_rpull
    reg_bits_set(tmp_addr + 0x9*4, 24, 1, 0);//cfg_rup
    reg_bits_set(tmp_addr + 0x9*4, 28, 1, 0);//cfg_rdn

    //step 4)mode setting
    if (ddrc_training_status_table.weye_enable) //wreye_manual_mode
        reg_bits_set(phy_base + 0x2c8, 3, 1, 0);

    if (ddrc_training_status_table.reye_enable)//rdeye_manual_mode
        reg_bits_set(phy_base + 0x2c8, 2, 1, 0);

    if (ddrc_training_status_table.gate_enable)//gate_manual_mode
        reg_bits_set(phy_base + 0x2c8, 1, 1, 0);

    if (ddrc_training_status_table.cabt_enable)//ca_manual_mode
        reg_bits_set(phy_base + 0x2c8, 0, 1, 0);

    dmc_sprd_delay(400);
}

void training_process_ctrl_post(u32 phy_base, u32 dfs_freq_sel)
{
    //u32 tmp_addr = phy_base + (dfs_freq_sel* 20*4);

    //step 1) enable manual mode
    reg_bits_set(phy_base + 0x2c8, 0, 4, 0xf);

    //step 2) enable dcc_ag_en
    //reg_bits_set(tmp_addr + 0xb*4, 8, 1, 1);

    //step 3) cfg multi rank
    reg_bits_set(phy_base + 0x2b0, 12, 2, 0);
}
void ddrc_phy_training_conditions(u32 this_freq)
{
	ddrc_training_status_table.ca_perb_enable = 0;
	ddrc_training_status_table.pbrd_enable = 0;
	ddrc_training_status_table.pbwr_enable = 0;
	ddrc_training_status_table.gate_enable = 0;

	//if (ddrc_training_status_table.ca_perb_enable)
		ddrc_training_status_table.cabt_enable = 1;

	//if (ddrc_training_status_table.pbwr_enable)
		ddrc_training_status_table.weye_enable = 1;

	//if (ddrc_training_status_table.pbrd_enable)
		ddrc_training_status_table.reye_enable =1;

	if (ddr_chip_cur.chip_type == DRAM_LPDDR3)
	{
		ddrc_training_status_table.rdvref_train_enable = 1;
		ddrc_training_status_table.wrvref_train_enable = 0;
	}
	ddrc_training_status_table.ca_vref_enable = 0;

	if (this_freq > 622)
	{
		if (ddrc_training_status_table.ca_perb_enable && (ddrc_training_status_table.CAPERBIT_DONE == 0))
			ddrc_training_status_table.ca_perbit_enable =1;
		else
			ddrc_training_status_table.ca_perbit_enable =0;

		if (ddrc_training_status_table.pbrd_enable && (ddrc_training_status_table.RDPERBIT_DONE == 0))
			ddrc_training_status_table.perbitrd_enable = 1;
		else
			ddrc_training_status_table.perbitrd_enable = 0;

		if (ddrc_training_status_table.pbwr_enable && (ddrc_training_status_table.WRPERBIT_DONE == 0))
			ddrc_training_status_table.perbitwr_enable = 1;
		else
			ddrc_training_status_table.perbitwr_enable = 0;
	}

	if (ddrc_training_status_table.ca_perbit_enable)
		ddrc_training_status_table.cabt_enable =1;

	if (ddrc_training_status_table.perbitrd_enable | ddrc_training_status_table.rdvref_train_enable)
		ddrc_training_status_table.reye_enable =1;

	if (ddrc_training_status_table.perbitwr_enable | ddrc_training_status_table.wrvref_train_enable)
		ddrc_training_status_table.weye_enable =1;
}

int ddrc_phy_training_seq(u32 this_freq, u32 dfs_freq_sel, TRAIN_CONDITIONS_TABLE *phy_train)
{
	u32 regval;
	int ca_result = 0;
	//step 0) check the conditions for training
	if ((FREQ_TRAINING_ENABLE[dfs_freq_sel] != 1) || (this_freq < 311))
	{
		FREQ_TRAINING_ENABLE[dfs_freq_sel] = 0;
		return -1;
	}

	ddrc_phy_training_conditions(this_freq);

	//step 1) exit selfrefresh status
	regval = reg_bits_get((DMC_REG_ADDR_BASE_PHY + 0x124), 24, 2);
	if (regval == 0x3)//bit[25:24]ch0_rfdmem_cmd_chip_sleep
	{
		dmc_dosoft_cmd_setting(0x80800000);//dsoft_resume
		dmc_dosoft_cmd_setting(0x80200000);//dsoft_auto_ref
	}

	//step 2) dram init and send mrws command
	if (phy_train->mrw_en)
		dram_powerup_seq(find_ddr_freq(dfs_freq_sel));

	//step 3) setting some phy register for training mode this will change global argument
	training_process_ctrl_pre(DMC_GUCPHY0_BASE, dfs_freq_sel, phy_train->rank);
	training_process_ctrl_pre(DMC_GUCPHY1_BASE, dfs_freq_sel, phy_train->rank);

    //step 4) trigger mlb training
    if (phy_train->rank == 0)
    {
        if (ddrc_training_status_table.ca_perbit_enable)
		phy_caperbit_seq(dfs_freq_sel, phy_train->rank);

        if (ddrc_training_status_table.cabt_enable)
	{
		regval = 0;
		while(1)
		{
			//reg_bits_set((DMC_GUCPHY0_BASE + ((dfs_freq_sel)*20*4) + 0xC*4), 8, 8, regval);
			//reg_bits_set((DMC_GUCPHY1_BASE + ((dfs_freq_sel)*20*4) + 0xC*4), 8, 8, regval);
			ca_result = phy_caeye_seq(dfs_freq_sel, phy_train->rank);
			if (ca_result == 1 && regval < 10)
			{
				break;
			}
			regval ++;
			if (regval >= 10)
			{
				ddrc_ca_debug = regval;
				while_loop();
			}
		}
	}

        if ((ddrc_training_status_table.gate_enable == 1) && (this_freq > 933))
		phy_gate_seq(dfs_freq_sel);

        //read perbit training
        if (ddrc_training_status_table.perbitrd_enable)
		phy_rwpbit_seq(dfs_freq_sel, 0);

        if (ddrc_training_status_table.rdvref_train_enable)
		phy_rwvref_seq(dfs_freq_sel, 0, phy_train->rank);

        if (ddrc_training_status_table.reye_enable)
		phy_rweye_seq(dfs_freq_sel, 0, phy_train->rank);

        //werit perbit training
        if (ddrc_training_status_table.perbitwr_enable)
		phy_rwpbit_seq(dfs_freq_sel, 1);

        if (ddrc_training_status_table.wrvref_train_enable)
		phy_rwvref_seq(dfs_freq_sel, 1, phy_train->rank);

	if (ddrc_training_status_table.weye_enable)
		phy_rweye_seq(dfs_freq_sel, 1, phy_train->rank);
    }
    else
    {
        if (ddrc_training_status_table.cabt_enable)
            phy_caeye_seq(dfs_freq_sel, phy_train->rank);

        if (ddrc_training_status_table.weye_enable)
            phy_rweye_seq(dfs_freq_sel, 1, phy_train->rank);
         ddrc_training_status_table.rank1_training_done = 1;
    }

    //step 5) this frequency end need go into selfrefresh mode
    regval = reg_bits_get((DMC_REG_ADDR_BASE_PHY + 0x124), 24, 2);
    if (regval != 0x3 )
    {
	for (regval = 0; regval < 6; regval ++)
		dmc_dosoft_cmd_setting(0x80200000);//dsoft_auto_ref
	dmc_dosoft_cmd_setting(0x80400000);//dsoft_self_ref
    }

    //step 6) training post setting
    training_process_ctrl_post(DMC_GUCPHY0_BASE, dfs_freq_sel);
    training_process_ctrl_post(DMC_GUCPHY1_BASE, dfs_freq_sel);
    return 0;
}

static void ddrc_phy_reset(u32 on)
{
	reg_bits_set(REG_DMC_RST_CTL, 0, 1, on);
	dmc_sprd_delay(50);
}

void training_set_pre(u32 phy_base, u32 dfs_freq_sel)
{
    uint32 this_freq = find_ddr_freq(dfs_freq_sel);
    u32 tmp_addr = phy_base + dfs_freq_sel*20*4;
    switch (this_freq)
    {
        case 933:
		REG32(phy_base + 0x294) = DMC_GUCPHY_LP3_933_294_DATA;
		REG32(phy_base + 0x298) = DMC_GUCPHY_LP3_933_298_DATA;
		REG32(phy_base + 0x29C) = DMC_GUCPHY_LP3_933_29C_DATA;
		REG32(phy_base + 0x2A0) = DMC_GUCPHY_LP3_933_2A0_DATA;
		REG32(phy_base + 0x2A4) = DMC_GUCPHY_LP3_933_2A4_DATA;
		REG32(phy_base + 0x2BC) = DMC_GUCPHY_LP3_933_2BC_DATA;
		break;
        case 800:
		REG32(phy_base + 0x294) = DMC_GUCPHY_LP3_800_294_DATA;
		REG32(phy_base + 0x298) = DMC_GUCPHY_LP3_800_298_DATA;
		REG32(phy_base + 0x29C) = DMC_GUCPHY_LP3_800_29C_DATA;
		REG32(phy_base + 0x2A0) = DMC_GUCPHY_LP3_800_2A0_DATA;
		REG32(phy_base + 0x2A4) = DMC_GUCPHY_LP3_800_2A4_DATA;
		REG32(phy_base + 0x2BC) = DMC_GUCPHY_LP3_800_2BC_DATA;
		break;
	case 622:
		REG32(phy_base + 0x294) = DMC_GUCPHY_LP3_622_294_DATA;
		REG32(phy_base + 0x298) = DMC_GUCPHY_LP3_622_298_DATA;
		REG32(phy_base + 0x29C) = DMC_GUCPHY_LP3_622_29C_DATA;
		REG32(phy_base + 0x2A0) = DMC_GUCPHY_LP3_622_2A0_DATA;
		REG32(phy_base + 0x2A4) = DMC_GUCPHY_LP3_622_2A4_DATA;
		REG32(phy_base + 0x2BC) = DMC_GUCPHY_LP3_622_2BC_DATA;
		break;
	case 533:
		REG32(phy_base + 0x294) = DMC_GUCPHY_LP3_533_294_DATA;
		REG32(phy_base + 0x298) = DMC_GUCPHY_LP3_533_298_DATA;
		REG32(phy_base + 0x29C) = DMC_GUCPHY_LP3_533_29C_DATA;
		REG32(phy_base + 0x2A0) = DMC_GUCPHY_LP3_533_2A0_DATA;
		REG32(phy_base + 0x2A4) = DMC_GUCPHY_LP3_533_2A4_DATA;
		REG32(phy_base + 0x2BC) = DMC_GUCPHY_LP3_533_2BC_DATA;
		break;
	case 400:
		REG32(phy_base + 0x294) = DMC_GUCPHY_LP3_400_294_DATA;
		REG32(phy_base + 0x298) = DMC_GUCPHY_LP3_400_298_DATA;
		REG32(phy_base + 0x29C) = DMC_GUCPHY_LP3_400_29C_DATA;
		REG32(phy_base + 0x2A0) = DMC_GUCPHY_LP3_400_2A0_DATA;
		REG32(phy_base + 0x2A4) = DMC_GUCPHY_LP3_400_2A4_DATA;
		REG32(phy_base + 0x2BC) = DMC_GUCPHY_LP3_400_2BC_DATA;
		break;
	case 311:
		REG32(phy_base + 0x294) = DMC_GUCPHY_LP3_311_294_DATA;
		REG32(phy_base + 0x298) = DMC_GUCPHY_LP3_311_298_DATA;
		REG32(phy_base + 0x29C) = DMC_GUCPHY_LP3_311_29C_DATA;
		REG32(phy_base + 0x2A0) = DMC_GUCPHY_LP3_311_2A0_DATA;
		REG32(phy_base + 0x2A4) = DMC_GUCPHY_LP3_311_2A4_DATA;
		REG32(phy_base + 0x2BC) = DMC_GUCPHY_LP3_311_2BC_DATA;
		break;
	case 233:
		REG32(phy_base + 0x294) = DMC_GUCPHY_LP3_233_294_DATA;
		REG32(phy_base + 0x298) = DMC_GUCPHY_LP3_233_298_DATA;
		REG32(phy_base + 0x29C) = DMC_GUCPHY_LP3_233_29C_DATA;
		REG32(phy_base + 0x2A0) = DMC_GUCPHY_LP3_233_2A0_DATA;
		REG32(phy_base + 0x2A4) = DMC_GUCPHY_LP3_233_2A4_DATA;
		REG32(phy_base + 0x2BC) = DMC_GUCPHY_LP3_233_2BC_DATA;
		break;
	case 160:
		REG32(phy_base + 0x294) = DMC_GUCPHY_LP3_160_294_DATA;
		REG32(phy_base + 0x298) = DMC_GUCPHY_LP3_160_298_DATA;
		REG32(phy_base + 0x29C) = DMC_GUCPHY_LP3_160_29C_DATA;
		REG32(phy_base + 0x2A0) = DMC_GUCPHY_LP3_160_2A0_DATA;
		REG32(phy_base + 0x2A4) = DMC_GUCPHY_LP3_160_2A4_DATA;
		REG32(phy_base + 0x2BC) = DMC_GUCPHY_LP3_160_2BC_DATA;
		break;

    }
    //set CA manual vref

    reg_bits_set(tmp_addr + 0xC * 4, 24, 6, GUCPHY_VREF_CA_RANGE);

    if (ddrc_training_status_table.CAPERBIT_DONE && this_freq > 622)
    {
	if (ddr_chip_cur.chip_type == DRAM_LPDDR3)
	{
		reg_bits_set((tmp_addr + 0xc*4), 0, 1, 0);//ca_rang_manu_delay_bt
		reg_bits_set((tmp_addr + 0xc*4), 8, 8, 0x80);//ca_rang_manu_cfg_delay
	}
	else
	{
		reg_bits_set((tmp_addr + 0xc*4), 0, 1, 1);//ca_rang_manu_delay_bt
		reg_bits_set((tmp_addr + 0xc*4), 8, 8, 0);//ca_rang_manu_cfg_delay
	}
    }

    if (ddrc_training_status_table.WRPERBIT_DONE && (this_freq > 622))
    {
	if (ddr_chip_cur.chip_type == DRAM_LPDDR3)
	{
		reg_bits_set((tmp_addr + 0x12*4), 0, 8, 0x80);//reg_f0_db1_bt_wdq_cfg_db0_wrdeye
		reg_bits_set((tmp_addr + 0x12*4), 8, 8, 0x80);//reg_f0_db1_bt_wdq_cfg_db1_wrdeye
		reg_bits_set((tmp_addr + 0x12*4), 16, 4, 0x0);//reg_f0_db1_bt_wdq_cfg_db0_bt
		reg_bits_set((tmp_addr + 0x12*4), 20, 4, 0x0);//reg_f0_db1_bt_wdq_cfg_db1_bt
	}
    }
}

/*setting second dll mode*/
void write_back_deskew_dll(u32 phy_base, u32 dfs_freq_sel)
{
	u32 read_data;
	u32 wrbk_data;
	u32 data_tmp;
	u32 tmp_addr;
	u32 rd_coarse;
	u32 regval;
	u32 cur_freq = find_ddr_freq(dfs_freq_sel);

	tmp_addr = phy_base + dfs_freq_sel*20*4;
	//step 1) read out coarse tuning resluts and write back to WR register
	//0xd8*4 bit[7:6] deskew_dll_status_reg01_cfg_clk_pos
	read_data = reg_bits_get((phy_base + 0xd8*4), 6, 2);
	reg_bits_set((tmp_addr + 0x4*4), 18, 2, read_data); //cfg_dll_clk_pos

	/*step 2) read out coarse tuning result and write back*/
	rd_coarse = __raw_readl(phy_base + 0xd7*4);
	/*0x035c
	 *bit[31] deskew_dll_status_reg00_cfg_dll_lock
	 *bit[30] deskew_dll_status_reg00_cfg_first_pass
	 *bit[29] deskew_dll_status_reg00_cfg_fail_flag
	 *bit[28] deskew_dll_status_reg00_cfg_agj_saturat
	 *bit[27:18] deskew_dll_status_reg00_cfg_fine_dly
	 *bit[17:14] deskew_dll_status_reg00_cfg_cnt_unlock
	 *bit[13:08] deskew_dll_status_reg00_cfg_cnt_lock
	 *bit[07:00] deskew_dll_status_reg00_cfg_cnt_continus
	 * */
	if (cur_freq > 400)
	{
		regval = (rd_coarse >> 18) & 0x1FF;
		regval = (regval >= 10) ? (regval - 10) : 0;
		rd_coarse = u32_bits_set(rd_coarse, 18, 9, regval);
	}
	regval = (rd_coarse >> 18) & 0xFF;
	/*F0-7 Deskew dll reg 1 setting*/
	/*bit[31] dll_1_cfg_dll_mode_en*/
	/*bit[30:26] dll_1_cfg_cyc_rst*/
	/*bit[25:21] dll_1_cfg_cyc_check*/
	/*bit[20:16] dll_1_cfg_cyc_found*/
	/*bit[15:08] dll_1_cfg_adj_ini_lo*/
	/*bit[07:00] dll_1_cfg_adj_coarse_lo*/
	wrbk_data = __raw_readl(tmp_addr + 0x3*4);
	wrbk_data = u32_bits_set(wrbk_data, 0, 8, regval);
	wrbk_data = u32_bits_set(wrbk_data, 8, 8, regval);
	__raw_writel(tmp_addr + 0x3*4,  wrbk_data);
	/*F0-7 Deskew dll reg 2 setting*/
	/*bit[31:29] dll_2_cfg_adjs0_cyc*/
	/*bit[28:26] dll_2_cfg_adjs1_cyc*/
	/*bit[25:23] dll_2_cfg_adjs2_cyc*/
	/*bit[22]    dll_2_cfg_adj_v_coafse*/
	/*bit[21:20] dll_2_cfg_coarse_tune_mode*/
	/*bit[19;18] dll_2_cfg_dll_clk_pos_i*/
	/*bit[16]    dll_2_cfg_adj_ini_hi*/
	/*bit[14]    dll_2_cfg_agj_coarse_hi*/
	/*bit[9]     dll_2_cfg_det_en1*/
	/*bit[8]     dll_2_cfg_det_start1*/
	/*bit[7:5]   dll_2_cfg_det_period1*/
	/*bit[4]     dll_2_cfg_det_en0*/
	/*bit[3]     dll_2_cfg_det_start0*/
	/*bit[2:0]   dll_2_cfg_det_period0*/
	wrbk_data = __raw_readl(tmp_addr + 0x4*4);
	regval = (rd_coarse >> 26) & 0x1;
	wrbk_data = u32_bits_set(wrbk_data, 14, 1, regval);
	wrbk_data = u32_bits_set(wrbk_data, 16, 1, regval);
	wrbk_data = u32_bits_set(wrbk_data, 20, 3, 0x0);//bit[21:20] coarse_tune_mode (3:bypass tuning by appling 1st training coarse tune)
						   //bit[20]==0 adj_v_coarse
	__raw_writel(tmp_addr + 0x4*4, wrbk_data);

	/*step 3) set fine tune bypass*/
	/*F0-7 Deskew dll reg 0 setting*/
	/*bit[1] dll_0_cfg_fine_tune_bypass*/
	read_data = __raw_readl(tmp_addr + 0x2*4);
	regval = cur_freq < 311 ? 1 : 0;
	read_data = u32_bits_set(read_data, 1, 1, regval);
	REG32(tmp_addr + 0x2*4) = read_data;

	/*step 4) write back acc init delay*/
	/*F0--7 DLL max and min value*/
	/*bit[24:16] min_delay_value*/
	/*bit[08:00] max_delay_value*/
	//read_data = __raw_read(phy_base + 0xdf*4);
	//bit[8:0]phy_db0_dll_cfg_1st
	//regval = (read_data & 0x1ff);

	read_data = REG32(phy_base + (0x104 + dfs_freq_sel) * 4);
	regval = ((read_data >> 16) & 0x1ff);

	if (cur_freq > 233 && phy_base == DMC_GUCPHY0_BASE)
	{
		if ((regval == 0x1FF) || ((read_data & 0x1FF) == 0x1FF))
		{
			dmc_print_str("ACC min/max delay value error!\n");
			while_loop();
		}
	}
	if (cur_freq > 1066)
	{
		if (regval >= 30)
			regval -= 30;
		else
			regval = 0;
	}
	else if (cur_freq > 384)
	{
		if (regval >= 40)
			regval -= 40;
		else
			regval = 0;
	}
	else
	{
		if (regval >= 10)
			regval -= 10;
		else
			regval = 0;
	}
	read_data = u32_bits_set(read_data, 16, 9, regval);
	data_tmp = __raw_readl(tmp_addr + 0x7*4);
	//acc init delay;data_tmp[21:16] = read_data[24:19]
	/*bit[21:16] master delay line initial deyal, start value setting*/
	data_tmp = u32_bits_set(data_tmp, 16, 6, ((read_data >> 19) & 0x3f));
	__raw_writel(tmp_addr + 0x7*4, data_tmp);
}

void master_dll_lock_seq(uint32 cur_freq)
{
	unsigned int regval;
	uint32 freq_select;
	DDRC_R1P0_REG_INFO_PTR pdmc = (DDRC_R1P0_REG_INFO_PTR)DMC_REG_ADDR_BASE_PHY;

	/*step 1. setting rf phy init start ahb to high*/
	pdmc->dmc_cfg3 = 0xf;

	/*step 2. polling rf phy dfi init complete*/
	do {
		regval = pdmc->dmc_cfg3;
		regval &= 0xf0000;
	}while (regval != 0xf0000);

	/*step 3. disable dfi init start*/
	pdmc->dmc_cfg3 = 0;
	/*step 4. write back deskew dll setting*/
	freq_select = (pdmc->dmc_dcfg11 >> 4) & 0x7;
	if (cur_freq)
	{
		write_back_deskew_dll(DMC_GUCPHY0_BASE, freq_select);
		write_back_deskew_dll(DMC_GUCPHY1_BASE, freq_select);
	}
}

void ddrc_phy_init_flow(u32 this_freq, u32 dfs_freq_sel, TRAIN_CONDITIONS_TABLE *phy_train)
{
	u32 this_freq_first = 0;

	//step 0) < 622Mhz do not need execulte for rank 1
	if ((phy_train->rank == 1) && (this_freq <= 400))
		return;

	if ((phy_train->rank == 1) && (ddrc_training_status_table.rank1_training_done == 1))
		return;

	if ((phy_train->flow_type == 1) && (phy_train->rank == 0))
		this_freq_first = 1;

	if ((phy_train->flow_type == 0) && (phy_train->wr_dsk_dll))
		this_freq_first = 1;

	/*step 1) phy soft_rst*/
	ddrc_phy_reset(1);

	/*step 2) setting dmc clock(gating clock and toggle adj_valid and phy_soft_rst_n=0)*/
	if (this_freq_first)
	{
		change_clk_freq_seq(dfs_freq_sel);
		change_clk_freq_seq(dfs_freq_sel);
	}

	/*step 3) soc rst phy*/
	ddrc_phy_reset(0);

	/*step 4) set iopv before initial start*/
	if (ddrc_training_status_table.iopvt_zq_cal_done == 0)
		ddrc_phy_iopvt_pre_seq();

	/*step 5) dll lock(dfi_init_start and dcc_rstn)*/
	master_dll_lock_seq(this_freq_first);

	/*step 6) iopvt zq calibration just need one time*/
	if (ddrc_training_status_table.iopvt_zq_cal_done == 0)
		ddrc_phy_iopvt_cal_seq();

	/*step 7) training really process*/
#ifdef GUCPHY_TRAINING_MODE
	phy_train ->mrw_en = this_freq_first;
	ddrc_phy_training_seq(this_freq, dfs_freq_sel, phy_train);
#endif
}

void ddrc_phy_reg_set(unsigned int *phy_base_addr)
{
	int i;
	unsigned int *pPhyBase = phy_base_addr;

	if (ddr_chip_cur.chip_type == DRAM_LPDDR3)
	{
		for(i=0; i<sizeof(phy_cfg_data_lp3)/sizeof(phy_cfg_data_lp3[0]); i++)
		{
			*(pPhyBase++) = phy_cfg_data_lp3[i];
		}


		pPhyBase = phy_base_addr+0x280/4;
		for(i=0; i<sizeof(phy_cfg_common_data_lp3)/sizeof(phy_cfg_common_data_lp3[0]); i++)
		{
			*(pPhyBase++) = phy_cfg_common_data_lp3[i];
		}
	}
	else
	{
		for(i=0; i<sizeof(phy_cfg_data_lp4)/sizeof(phy_cfg_data_lp4[0]); i++)
		{
			*(pPhyBase++) = phy_cfg_data_lp4[i];
		}

		pPhyBase = phy_base_addr+0x280/4;
		for(i=0; i<sizeof(phy_cfg_common_data_lp4)/sizeof(phy_cfg_common_data_lp4[0]); i++)
		{
			*(pPhyBase++) = phy_cfg_common_data_lp4[i];
		}
	}
}

void ddrc_phy_pin_mux_setting(void)
{
	if (ddr_chip_cur.chip_type == DRAM_LPDDR3)
	{
#if defined(LP3_PINMUX_CASE0)
		reg_bits_set(DMC_GUCPHY1_BASE+0xcb*4, 24, 8, 0x21);
		__raw_writel(DMC_GUCPHY1_BASE + 0xcc*4, 0x83140726);
		__raw_writel(DMC_GUCPHY1_BASE + 0xcd*4, 0x42618735);
		__raw_writel(DMC_GUCPHY1_BASE + 0xce*4, 0x1ac68805);
		__raw_writel(DMC_GUCPHY1_BASE + 0xd4*4, 0x20846153);
		__raw_writel(DMC_GUCPHY1_BASE + 0xd5*4, 0x47605387);
#elif defined(LP3_PINMUX_CASE1)
		reg_bits_set(DMC_GUCPHY1_BASE+0xcb*4, 24, 8, 0x21);
		__raw_writel(DMC_GUCPHY1_BASE + 0xcc*4, 0x82041536);
		__raw_writel(DMC_GUCPHY1_BASE + 0xcd*4, 0x32408757);
		__raw_writel(DMC_GUCPHY1_BASE + 0xce*4, 0x1ac68816);
		__raw_writel(DMC_GUCPHY1_BASE + 0xd4*4, 0x80241635);
		__raw_writel(DMC_GUCPHY1_BASE + 0xd5*4, 0x70465837);
#else
		//no pin mux
#endif
	}
	else
	{
#if defined(LP4_PINMUX_CASE0)
		reg_bits_set(DMC_GUCPHY1_BASE+0xcb*4, 24, 8, 0x47);
		__raw_writel(DMC_GUCPHY1_BASE + 0xcc*4, 0x86325140);
		__raw_writel(DMC_GUCPHY1_BASE + 0xcd*4, 0x64821537);
		__raw_writel(DMC_GUCPHY1_BASE + 0xce*4, 0x1ac68107);
		__raw_writel(DMC_GUCPHY1_BASE + 0xcf*4, 0x02400050);
		reg_bits_set(DMC_GUCPHY1_BASE + 0xd0*4, 0, 9, 0x13);//reg_mlb_ca_bit_pattern_hi bit[7:0] = 0x13,reg_mlb_byte_pattern bit[8]=0
		__raw_writel(DMC_GUCPHY1_BASE + 0xd4*4, 0x86315420);
		__raw_writel(DMC_GUCPHY1_BASE + 0xd5*4, 0x61503287);
#elif defined(LP4_PINMUX_CASE1)
		reg_bits_set(DMC_GUCPHY1_BASE+0xcb*4, 24, 8, 0x47);

		__raw_writel(DMC_GUCPHY1_BASE + 0xcc*4, 0x86325140);
		__raw_writel(DMC_GUCPHY1_BASE + 0xcd*4, 0x64821537);
		__raw_writel(DMC_GUCPHY1_BASE + 0xce*4, 0x1ac88107);
		__raw_writel(DMC_GUCPHY1_BASE + 0xcf*4, 0x02400050);

		reg_bits_set(DMC_GUCPHY1_BASE + 0xd0*4, 0, 9, 0x13);//reg_mlb_ca_bit_pattern_hi bit[7:0] = 0x13,reg_mlb_byte_pattern bit[8]=0

		__raw_writel(DMC_GUCPHY1_BASE + 0xd4*4, 0x86315420);
		__raw_writel(DMC_GUCPHY1_BASE + 0xd5*4, 0x61503287);

#else
		__raw_writel(DMC_GUCPHY1_BASE + 0xcf*4, 0x02400050);//reg mlb_ca_bit_pattern_lo
		reg_bits_set(DMC_GUCPHY1_BASE + 0xd0*4, 0, 8, 0x13);
#endif
	}
}

void ddrc_phy_pre_set_seq(void)
{
	/*Step1. SW setting the PHY register according to the lpx_register_table_x16_v001 for PHY0 */
	ddrc_phy_reg_set((unsigned int *)DMC_GUCPHY0_BASE);

	/*Step2. SW setting the PHY register according to the lpx_register_table_x16_v001 for PHY1*/
	ddrc_phy_reg_set((unsigned int *)DMC_GUCPHY1_BASE);

	/*step 3. setting pin mux*/
	ddrc_phy_pin_mux_setting();
}

void ddrc_phy_post_set_seq(void)
{
	ddrc_phy_post_setting(DMC_GUCPHY0_BASE);
	ddrc_phy_post_setting(DMC_GUCPHY1_BASE);
}

void ddrc_phy_post_setting_rpull(u32 phy_base)
{
	u32 tmp_addr;
	u32 data_tmp;
	int i;
	/*PHY odt and oct setting for set fx*/
	//set rpull base on gate edge mode
	for (i = MIN_FREQ_SEL; i < MAX_FREQ_SEL; i++)
	{
		tmp_addr = phy_base + (i *20 *4);
		data_tmp = REG32(tmp_addr + (0x9 * 4));
		data_tmp= u32_bits_set(data_tmp, 31, 1, 1);//phy_pad_rpull
		data_tmp= u32_bits_set(data_tmp, 24, 1, 0);//phy_pad_rpu edge mode without odt lp3
		data_tmp= u32_bits_set(data_tmp, 28, 1, 0);//phy_pad_rpd edge mode without odt lp4
		REG32(tmp_addr + (0x9 * 4)) = data_tmp;
	}
}

void ddrc_phy_init_post_seq(void)
{
	/*step 1) set rpull for normal mode*/
	ddrc_phy_post_setting_rpull(DMC_GUCPHY0_BASE);
	ddrc_phy_post_setting_rpull(DMC_GUCPHY1_BASE);
}

void one_freq_point_init_flow(u32 dfs_freq_sel)
{
	u32 this_freq = find_ddr_freq(dfs_freq_sel);
	/*pre-setting gucphy*/
	/*perbit training only execulte one times*/

#ifdef GUCPHY_TRAINING_MODE
	training_set_pre(DMC_GUCPHY0_BASE, dfs_freq_sel);
	training_set_pre(DMC_GUCPHY1_BASE, dfs_freq_sel);
#endif
	ddrc_training_table.flow_type = 1;
	ddrc_training_table.rank =0;
	ddrc_training_table.wr_dsk_dll = 0;
	ddrc_training_table.cur_odt_en = 0;
	ddrc_training_table.mrw_en = 0;

	ddrc_phy_init_flow(this_freq, dfs_freq_sel, &ddrc_training_table);//rank 0

#if 0//def GUCPHY_TRAINING_MODE
	ddrc_training_table.rank = 1;
	ddrc_phy_init_flow(this_freq, dfs_freq_sel, &ddrc_training_table);//rank 1
#endif
}

void ddrc_phy_init_seq(void)
{
	int i ;

#if !defined(GUCPHY_TRAINING_MODE) || !defined(CONFIG_NAND_SPL)
	one_freq_point_init_flow(find_freq_num(CLK_DDR_FREQ/1000000));
#else
	for (i = MIN_FREQ_SEL; i < MAX_FREQ_SEL; i++)
	{
		one_freq_point_init_flow(i);
		if (i > 4)
		{
			reg_bits_set((DMC_GUCPHY0_BASE + ((i)*20*4) + 0xA*4), 8, 4, i);
			reg_bits_set((DMC_GUCPHY1_BASE + ((i)*20*4) + 0xA*4), 8, 4, i);
		}
	}
#endif
}

