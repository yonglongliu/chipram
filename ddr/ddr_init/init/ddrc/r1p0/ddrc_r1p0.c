#include <sci_types.h>
#include <asm/arch/clk_para_config.h>
#include <asm/arch/sprd_reg.h>
#include <asm/arch/sprd_chipram_env.h>

#include "ddrc_r1p0.h"
#include "ddrc_r1p0_phy.h"
#include "ddrc_r1p0_common.h"
extern u32 FREQ_TRAINING_ENABLE[8];

static DRAM_JEDEC_INFO jedec_info_cs0 = {0,			/*cs index*/
					CFG_CS0_BANK_NUM,	/*bank number*/
					CFG_CS0_ROW_NUM,	/*row number*/
					CFG_CS0_COLUMN_NUM,	/*column number*/
					CFG_CS0_DQ_DW,		/*data width*/
					CFG_CS0_SIZE		/*cs0 size*/
};

static DRAM_JEDEC_INFO jedec_info_cs1 = {1,			/*cs index*/
					 CFG_CS1_BANK_NUM,	/*bank number*/
					 CFG_CS1_ROW_NUM,	/*row number*/
					 CFG_CS1_COLUMN_NUM,	/*column number*/
					 CFG_CS1_DQ_DW,		/*data width*/
					 CFG_CS1_SIZE		/*cs1 size*/
};

DRAM_CHIP_INFO ddr_chip_cur = {
	CFG_DRAM_TYPE,
	2,
	&jedec_info_cs0,
	&jedec_info_cs1,
	0
};

dfs_freq_table dfs_table[8]={{0,160},{1,233},{2,311},{3,400},{4,533},{5,622},{6,800},{7,933}};

uint32 find_freq_num(uint32 clk_freq)
{
	uint32 i=0;
	for(i=0; i<8; i++)
	{
		if(clk_freq == dfs_table[i].freq)
		{
			return dfs_table[i].point_num;
		}
	}
	return 8;
}

uint32 find_ddr_freq(uint32 num)
{
	uint32 i=0;
	for(i=0; i<8; i++)
	{
		if(num == dfs_table[i].point_num)
		{
			return dfs_table[i].freq;
		}
	}
	return 8;
}

DRAM_TYPE dmc_get_ddr_type(void)
{
	return ddr_chip_cur.chip_type;
}

int sdram_chip_data_width(void)
{
	return jedec_info_cs0.dw;
}

int sdram_chip_cs_num(void)
{
	return ddr_chip_cur.cs_num;
}

int sdram_chip_whole_size(uint64 *size)
{

	if (ddr_chip_cur.cs_num == 1)
	{
		*size = jedec_info_cs0.cs_size;
	}
	else if (ddr_chip_cur.cs_num == 2)
	{
		*size = jedec_info_cs0.cs_size + jedec_info_cs1.cs_size;
	}
	else
	{
		return -1;
	}
	return 0;

}

int sdram_cs_whole_size(int cs, uint64*size)
{
	if (0 == cs)
	{
		*size = jedec_info_cs0.cs_size;
	}
	else if (1 == cs)
	{
		*size = jedec_info_cs1.cs_size;
	}
	else
	{
		return -1;
	}
	return 0;
}

static void dmc_ddr_size_limit(chipram_env_t *p_env, u32 limit_size)
{
	if (p_env->cs_number == 2)
	{
		if (p_env->dram_size >= limit_size)
		{
			if (p_env->cs0_size >= limit_size)
			{
				p_env->cs0_size = limit_size - BIST_RESERVE_SIZE;
				p_env->cs1_size = 0;
				p_env->cs_number = 1;
			}
			else
			{
				p_env->cs1_size = limit_size - (p_env->cs0_size + BIST_RESERVE_SIZE);
			}
		}
		else
		{
			p_env->cs1_size -= BIST_RESERVE_SIZE;
		}
	}
	else
	{
		if (p_env->dram_size >= limit_size)
			p_env->cs0_size = limit_size - BIST_RESERVE_SIZE;
		else
			p_env->cs0_size -= BIST_RESERVE_SIZE;
	}
}

static void dmc_update_param_for_uboot(void)
{
	chipram_env_t * p_env = CHIPRAM_ENV_ADDR;
	p_env->cs_number = ddr_chip_cur.cs_num;
	p_env->cs0_size = jedec_info_cs0.cs_size;
	p_env->cs1_size = jedec_info_cs1.cs_size;
        u32 val;
	if (ddr_chip_cur.cs_num == 1)
	{
		p_env->cs1_size = jedec_info_cs1.cs_size = 0;
		p_env->dram_size = p_env->cs0_size;
	}
	else if (ddr_chip_cur.cs_num == 2)
		p_env->dram_size = (u64)p_env->cs0_size + (u64)p_env->cs1_size;

	if (ddr_chip_cur.cs_num == 2)
	{
#if defined(CONFIG_CHIPRAM_DDR_CUSTOMIZE)
		dmc_ddr_size_limit(p_env, CONFIG_CHIPRAM_DDR_CUSTOMIZE);
#else
		p_env->cs1_size -= BIST_RESERVE_SIZE;
#endif
	}
	else if (ddr_chip_cur.cs_num == 1)
	{
#if defined(CONFIG_CHIPRAM_DDR_CUSTOMIZE)
		dmc_ddr_size_limit(p_env, CONFIG_CHIPRAM_DDR_CUSTOMIZE);
#else
		p_env->cs0_size -= BIST_RESERVE_SIZE;
#endif
	}
}

static void dmc_ddr_debug_mode(void)
{
#if defined(DDR_MODE)
	u32 ddr_mode = mcu_clk_para.ddr_debug_mode.value;
#else
	u32 ddr_mode = 0x0;
#endif
	u32 regval;
	/* ddr_mode
	 * bit[0] 1'b1 dfs disable; 1'b0 dfs_enable
	 * bit[1] 1'b1 retention disable; 1'b0 retention enable
	 *
	*/
	if ((ddr_mode & 0x1))
	{
		regval = REG32(DMC_DUMMY_REG1);
		regval = u32_bits_set(regval, 4, 4,0xf);
		REG32(DMC_DUMMY_REG1) = regval;
	}

	if ((ddr_mode & 0x2))
	{
		regval = REG32(DMC_DUMMY_REG1);
		regval = u32_bits_set(regval, 8, 4,0xf);
		REG32(DMC_DUMMY_REG1) = regval;
	}
}
#if defined(CONFIG_SOC_SHARKL3)
void dmc_exit_self_refresh(u32 repeat)
{
	DDRC_R1P0_REG_INFO_PTR pdmc = (DDRC_R1P0_REG_INFO_PTR)DMC_REG_ADDR_BASE_PHY;
	u32 regval, i;
	/*step 6) exit selfrefresh and initial DRAM if not send current frequency MRWs*/
	/*ch0_rfdmem_cmd_chip_sleep*/
	regval = (pdmc->dmc_dcfg9 >> 24) & 0x3;
	if (regval == 0x3)
	{
		pdmc->dmc_dcfg1 = 0x80800000;//dsoft_resume
		while(((pdmc->dmc_dcfg1 >> 19) & 0x1ff) != 0);
	}

	for (i = 0; i < repeat; i++)
	{
		pdmc->dmc_dcfg1 = 0x80200000;//dsoft_auto_ref
		while(((pdmc->dmc_dcfg1 >> 19) & 0x1ff) != 0);
	}
}

static void pub_soft_reset(void)
{
	REG32(REG_PMU_APB_CP_SOFT_RST) |= 1<<6;
	dmc_sprd_delay(100);
	REG32(REG_PMU_APB_CP_SOFT_RST) &= ~(1<<6);
}
static void ddr_umctrl_soft_reset(void)
{
	REG32(REG_PMU_APB_DDR_PHY_RET_CFG) |= 1<<16;
	dmc_sprd_delay(100);
	REG32(REG_PMU_APB_DDR_PHY_RET_CFG) &= ~(1<<16);
}

static void ddrc_axi_lowpower_setting(void)
{
	/*bit[16] 1'b1 ddr_chn0_axi_lp_en*/
	/*bit[17] 1'b1 ddr_chn1_axi_lp_en*/
	/*bit[18] 1'b1 ddr_chn2_axi_lp_en*/
	/*bit[19] 1'b0 ddr_chn3_axi_lp_en*/
	/*bit[20] 1'b1 ddr_chn4_axi_lp_en*/
	/*bit[21] 1'b1 ddr_chn5_axi_lp_en*/
	/*bit[22] 1'b1 ddr_chn6_axi_lp_en*/
	/*bit[23] 1'b1 ddr_chn7_axi_lp_en*/
	reg_bits_set(REG_PUB_TOP_AHB_DDR_CHN_SLEEP_CTRL0, 16, 8, 0xF7);//ddr channelx axi lower power en

	/*pub_top_pub_top_AHB_RF_DDR_CHN_SLEEP_CTRL*/
	/*bit[0] 1'b0 ddr_chn0_axi_top_sel*/
	/*bit[1] 1'b0 ddr_chn1_axi_top_sel*/
	/*bit[2] 1'b0 ddr_chn2_axi_top_sel*/
	/*bit[3] 1'b0 ddr_chn3_axi_top_sel*/
	/*bit[4] 1'b0 ddr_chn4_axi_top_sel*/
	/*bit[5] 1'b0 ddr_chn5_axi_top_sel*/
	/*bit[6] 1'b0 ddr_chn6_axi_top_sel*/
	/*bit[7] 1'b0 ddr_chn7_axi_top_sel*/
	reg_bits_set(REG_PUB_TOP_AHB_DDR_CHN_SLEEP_CTRL1, 0, 8, 0x0);//ddr channelx axi top sel

	/*PUB_TOP_AHB_WRAP_RF_FENCING_CTRL*/
	reg_bits_set(REG_PUB_AHB_WRAP_FENCING_CTRL, 30, 1, 0x1);//ddr fencing enable
	reg_bits_set(REG_PUB_AHB_WRAP_FENCING_CTRL, 0, 30, 0x257);//ddr fencing channel idle cnt(1us)
}
static void ddrc_apb_lowpower_setting(void)
{
	/*AON_CLK_LP_RF_CLK_SW_MODE_SEL*/
	reg_bits_set(REG_AON_CLK_LP_CLK_SW_MODE_SEL, 4, 1, 0x0);//clk emc ref mode sel
	reg_bits_set(REG_AON_CLK_LP_BUSCLK_MODE_SEL, 4, 1, 0x1);//clk_aonmatrix2pub_mode_sel
	/*bit[6] 1'b1 pub_cfg_auto_en*/
	/*bit[7] 1'b0 pub_cfg_slow_en*/
	reg_bits_set(REG_AON_CLK_LP_CLK_AUTO_GATE_EN_CTRL3, 6, 2, 0x1);
	reg_bits_set(REG_PMU_APB_PMU_DUMMY_REG1, 14, 2, 0x1);//debug
}
static void ddrc_pub_lowpoer_setting(void)
{
	/*enable pubsys clock auto gating fuctions*/
	/*PUB_TOP_PUB_TOP_AHB_RG_DMC_DDR_CTRL_CLK_CTRLi 0x30200000*/
	/*bit[31] 1'b1 pub_clk_dfs_sleep_auto_gate_en*/
	/*bit[30] 1'b1 clk_apb_auto_gate_en*/
	/*bit[29] 1'b1 clk_emc_ref_auto_gate_en*/
	/*bit[28] 1'b1 pub_clk_dfs_auto_gate_en*/
	/*bit[27] 1'b1 dmc_dfi_mon_auto_gate_en*/
	/*bit[26] 1'b1 dmc_sref_auto_gate_en*/
	/*bit[25] 1'b1 ddr_phy_auto_gate_en*/
	/*bit[24] 1'b1 ddr_umctrl_auto_gate_en*/
	/*bit[22] 1'b0 pub_clk_emc_ref_en*/
	/*bit[20] 1'b0 pub_clk_apb_en*/
	/*bit[11] 1'b0 pub_clk_dmc_x1_eb*/
	/*bit[23] 1'b1 pub_top_mon_en*/
	/*bit[15] 1'b1 pub_clk_dfs_en*/
	reg_bits_set(REG_PUB_TOP_AHB_DMC_DDR_CLK_CTRL, 24, 8, 0xF);
	reg_bits_set(REG_PUB_TOP_AHB_DMC_DDR_CLK_CTRL, 20, 1, 0x0);
	reg_bits_set(REG_PUB_TOP_AHB_DMC_DDR_CLK_CTRL, 22, 1, 0x0);
	reg_bits_set(REG_PUB_TOP_AHB_DMC_DDR_CLK_CTRL, 11, 1, 0x0);
	reg_bits_set(REG_PUB_TOP_AHB_DMC_DDR_CLK_CTRL, 23, 1, 0x1);
	reg_bits_set(REG_PUB_TOP_AHB_DMC_DDR_CLK_CTRL, 15, 1, 0x1);

	/*enable qos controller clock auto gating functions 0x30210008*/
	/*bit[0] 1'b1 qosc_port_clkc_auto_gate_en*/
	/*but[1] 1'b1 qosc_bw_limit_auto_gate_en*/
	/*bit[8] 1'b0 qosc_cfg_clk_en*/
	/*bit[9] 1'b1 qosc_cfg_clk_auto_gate_en*/
	reg_bits_set(REG_PUB_QOSC_AHB_QOSC_CLK_CTRL, 0, 2, 0x3);
	reg_bits_set(REG_PUB_QOSC_AHB_QOSC_CLK_CTRL, 8, 2, 0x2);

	/*PUB_TOP_PUB_QOSC_AHB_RF_QOSC_M1_CLK_CTRL 0x30210408*/
	/*bit[0] 1'b1 qosc_port_clk_auto_gate_en (M1)*/
	/*bit[1] 1'b1 qosc_bw_limit_auto_gate_en (M1)*/
	/*bit[8] 1'b0 qosc_cfg_clk_en(M1)*/
	reg_bits_set(REG_PUB_QOSC_AHB_M1_QOSC_CLK_CTRL, 0, 2, 0x3);
	reg_bits_set(REG_PUB_QOSC_AHB_M1_QOSC_CLK_CTRL, 8, 1, 0x0);

	/*PUB_TOP_PUB_QOSC_AHB_RF_QOSC_M2_CLK_CTRL 0x30210608*/
	/*bit[0] 1'b1 qosc_port_clk_auto_gate_en (M2)*/
	/*bit[1] 1'b1 qosc_bw_limit_auto_gate_en (M2)*/
	/*bit[8] 1'b0 qosc_cfg_clk_en(M2)*/
	reg_bits_set(REG_PUB_QOSC_AHB_M2_QOSC_CLK_CTRL, 0, 2, 0x3);
	reg_bits_set(REG_PUB_QOSC_AHB_M2_QOSC_CLK_CTRL, 8, 1, 0x0);

	/*REG_PUB_TOP_AHB_DMC_CLK_INIT_CFG 0x30200108*/
	/*bit[8] dmc sleep_force_finish_mode*/
	reg_bits_set(REG_PUB_TOP_AHB_DMC_CLK_INIT_CFG, 8, 1, 0x0);

	/*REG_PUB_TOP_AHB_HSEL_IDLE_CNT 0x30200088*/
	/*bit[7:0] hsel_idle_cnt*/
	reg_bits_set(REG_PUB_TOP_AHB_HSEL_IDLE_CNT, 0, 8, 0x10);

	/*disable bus ot detect clk*/
	/*REG_PUB_AHB_WRAP_PUB_PERI_CLK_EN*/
	/*bit[1] ot_clk_en OT mode clock enable*/
	reg_bits_set(REG_PUB_AHB_WRAP_PUB_PERI_CLK_EN, 1, 1, 0x0);

	/*for pll pd default*/
	/*0x30200108*/
	/*bit[4] deskew_pll_pd_default_sel*/
	/*bit[5] deskew_pll_pd_default_sw*/
	reg_bits_set(REG_PUB_TOP_AHB_DMC_CLK_INIT_CFG, 4, 2, 0x3);
	//reg_bits_set(0x30400284, 24, 1 ,0x0);
	//reg_bits_set(0x30410284, 24, 1 ,0x0);
}

static void ddrc_lowpower_setting(void)
{
	ddrc_axi_lowpower_setting();
	ddrc_apb_lowpower_setting();
	ddrc_pub_lowpoer_setting();
}
#endif
static void sdram_init_fpga(void)
{
}
void ddrc_qos_setting(void)
{
        //set DMC_MAP
                REG32(DMC_MAP)=0x80804040;
		reg_bits_set(RF_HI_URGENT_EN,8,1,1);//rf_hi_urgent_en
        //QOS
		REG32(REG_PUB_QOSC_AHB_QOSC_CLK_CTRL)   =0x00000213;//QOSC_CLK_CTRL
		REG32(REG_PUB_QOSC_AHB_M1_QOSC_CLK_CTRL)=0x00000213;//M1_QOSC_CLK_CTRL
		REG32(REG_PUB_QOSC_AHB_M2_QOSC_CLK_CTRL)=0x00000213;//M2_QOSC_CLK_CTRL
		REG32(REG_PUB_QOSC_AHB_QOSC_CFG)        =0x10330040;//QOSC_CFG
		REG32(REG_PUB_QOSC_AHB_M1_QOSC_CFG)     =0x10330000;//M1_QOSC_CFG
		REG32(REG_PUB_QOSC_AHB_M2_QOSC_CFG)     =0x10330000;//M2_QOSC_CFG

		REG32(REG_PUB_QOSC_AHB_QOSC_PORT_ENABLE)   =0x000000ff;//QOSC_PORT_ENABLE
		REG32(REG_PUB_QOSC_AHB_QOSC_AXURGENT_EN)   =0x00000000;//QOSC_AXURENT_EN
		REG32(REG_PUB_QOSC_AHB_M1_QOSC_PORT_ENABLE)=0x00000003;//M1_QOSC_PORT_ENABLE
		REG32(REG_PUB_QOSC_AHB_M1_QOSC_AXURGENT_EN)=0x00000000;//M1_QOSC_AXURGENT_EN
		REG32(REG_PUB_QOSC_AHB_M2_QOSC_PORT_ENABLE)=0x00000007;//M2_QOSC_PORT_ENABLE
		REG32(REG_PUB_QOSC_AHB_M2_QOSC_AXURGENT_EN)=0x00000000;//M2_QOSC_AXURGENT_EN
		REG32(REG_PUB_QOSC_AHB_QOSC_QOS_VALUE_CH0)=0xEE884A00;//QOSC_QOS_VALUE_CH0
		REG32(REG_PUB_QOSC_AHB_QOSC_QOS_VALUE_CH2)=0xEE88A800;//QOSC_QOS_VALUE_CH2
		REG32(REG_PUB_QOSC_AHB_QOSC_QOS_VALUE_CH5)=0xEE88EC00;//QOSC_QOS_VALUE_CH5
		REG32(REG_PUB_QOSC_AHB_M2_QOSC_QOS_VALUE_CH1)=0xEE888800;//QOSC_QOSC_QOS_VALUE_CH1

		REG32(REG_PUB_QOSC_AHB_QOS_CTRL_EB)=0x00000001;//QOS_CTR_EB
		REG32(REG_PUB_QOSC_AHB_M1_QOS_CTRL_EB)=0x00000001;//M1_QOS_CTRL_EB
		REG32(REG_PUB_QOSC_AHB_M2_QOS_CTRL_EB)=0x00000001;//M2_QOS_CTRL_EB
}
int sdram_init(void)
{
#if defined(CONFIG_CLK_PARA)
	u32 ddr_clk = (mcu_clk_para.ddr_freq.value)/1000000;
#else
	u32 ddr_clk = DDR_CLK;
#endif
	unsigned int regval;
#if defined(CONFIG_FPGA) || defined(CONFIG_SOC_WHALEK)
	sdram_init_fpga();
#else
	dmc_print_str("ddr init start\n");
	if (find_freq_num(ddr_clk) > 7)
	{
		dmc_print_str("error: invalid ddr clock\n");
		while(1);
	}
	ddrc_phy_vref_setting();
	/*step 1). pub soft rst*/
	pub_soft_reset();

	/*step 1). ddr phy ret en clear sw*/
	reg_bits_set(REG_PMU_APB_DDR_OP_MODE_CFG, 30, 1, 1);

	/*step 1). release dmc ctrl rst*/
	ddr_umctrl_soft_reset();

	/*step 2). ddrc ctrl init pre setting*/
	ctrl_pre_set_seq(dfs_table);

	/*step 3). ddrc phy init pre setting*/
	ddrc_phy_pre_set_seq();

	/*step 4). initial frequency point*/
	ddrc_phy_init_seq();

	/*step 5). ddrc phy setting after phy initial*/
	ddrc_phy_post_set_seq();

	/*step 6). exit selfrefresh and initial DRAM if not send current frequency MRWs*/
	/*ch0_rfdmem_cmd_chip_sleep*/
	dmc_exit_self_refresh(8);

	/*step 7). ddrc powerup init setting*/
	/*this setting for one freq boot*/
#if !defined(GUCPHY_TRAINING_MODE) || !defined(CONFIG_NAND_SPL)
	dram_powerup_seq(ddr_clk);
#endif

	/*step 8). phy or ctrl setting after dram inital*/
	ctrl_post_set_seq();

	/*step 9). dmc initial setting post*/
	ddrc_phy_init_post_seq();

	/*bist test*/
	dmc_ddr_test(0);

	/*pub axi low power setting*/
	//ddrc_lowpower_setting();

	REG32(0x3000009c) = 0xdeadbeef;
	REG32(REG_PMU_APB_PUB_ACC_RDY) = 0x1;
	dmc_update_param_for_uboot();
	dmc_ddr_debug_mode();
	ddrc_qos_setting();
#endif
	dmc_print_str("ddr init pass\n");
#ifdef DDR_REINIT_TEST
	DMC_ReInit();
#endif
	return 0;
}


