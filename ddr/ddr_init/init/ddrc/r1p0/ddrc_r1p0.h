#ifndef __DDRC_SPRD_R1P0_H__
#define __DDRC_SPRD_R1P0_H__

#include "debug.h"

#ifndef BIT
#define BIT(x)				(1 << (x))
#endif

#ifndef MAX
#define MAX(x,y)			(((x) > (y)) ? (x) : (y))
#endif
#ifndef REG32
#define REG32(_x_) (*(volatile u32*)((u64)(_x_)))
#endif

#define GUCPHY_TRAINING_MODE

#define GUCPHY_VREF_CA_RANGE 0x33

#define BIST_RESERVE_SIZE		0x40000
/*0=64B,1=128B,2=256B,3=512B,4=1k,5=2k,6=4k,7=8k*/
#define INTERLEAVE_SIZE 0
#define LP3_PINMUX_CASE0
#define PXP_DEBUG
//#define SHARKL3_BRINGUP
#define ASYNC_MODE

#define MIN_FREQ_SEL    0
#define MAX_FREQ_SEL    8

#define TARGET_FREQ		0

#define DMC_REG_ADDR_BASE_PHY (0x30000000)
#define PUB_AHB_ADDR_BASE_PHY (0x300e0000)
#define PUB_AHB_ADDR_BASE_BIST 0x30080000
#define DMC_GUCPHY0_BASE        (0x30400000)
#define PMU_APB_BASE_ADDR       (0x402b0000)
#define PUB_APB_BASE            (0x300F0000)
#define PUB_AHB_BASE            (0x30200000)

#define DMC_DUMMY_REG1			(PUB_AHB_ADDR_BASE_PHY + 0x00A4)

#define REG_PUB_DFS_SW_CTEL         (PUB_APB_BASE + 0x0008)
#define REG_PUB_DFS_PURE_SW_CTRL        (PUB_APB_BASE + 0x0018)
#define REG_PUB_DFS_SW_CTRL1            (PUB_APB_BASE + 0x0030)
#define REG_PUB_BIST_CTRL1              (PUB_APB_BASE + 0x004c)
#define REG_PUB_DFS_HW_CTRL         (PUB_APB_BASE + 0x0100)
#define REG_PUB_DDR_CHN_SLEEP_CTRL0	(PUB_AHB_BASE + 0x10)
#define REG_DMC_CLK_INIT_SW_START   (PUB_AHB_BASE + 0x0100)
#define REG_DMC_CLK_STATE               (PUB_AHB_BASE + 0x0104)
#define REG_DMC_CLK_INIT_CFG            (PUB_AHB_BASE + 0x0108)
#define REG_DMC_RST_CTL             (PUB_AHB_BASE + 0x0080)
#define PUB_ACC_RDY         (PMU_APB_BASE_ADDR + 0x250)
#define DMC_GUCPHY1_BASE        (DMC_GUCPHY0_BASE+0x10000)
#define DMC_GUCPHY2_BASE        (DMC_GUCPHY0_BASE+0x20000)
#define DMC_GUCPHY3_BASE        (DMC_GUCPHY0_BASE+0x30000)
#define DDR_DRV_CFG 34

#define DMC_MAP                              (0x30000130)
#define RF_HI_URGENT_EN                      (0x30000014)

typedef struct __DDRC_R1P0_REG_INFO {
    volatile unsigned int dmc_cfg0;                     /*addr:0x0*/
    volatile unsigned int dmc_cfg1;                     /*addr:0x4*/
    volatile unsigned int dmc_cfg2;                     /*addr:0x8*/
    volatile unsigned int dmc_cfg3;                     /*addr:0xc*/
    volatile unsigned int dmc_cfg4;                     /*addr:0x10*/
    volatile unsigned int dmc_cfg5;                     /*addr:0x14*/
    volatile unsigned int dmc_cfg6;                     /*addr:0x18*/
    volatile unsigned int dmc_cfg7;                     /*addr:0x1c*/

    volatile unsigned int dmc_cfg0_ach0;                /*addr:0x20*/
    volatile unsigned int dmc_cfg1_ach0;                /*addr:0x24*/
    volatile unsigned int dmc_cfg0_ach1;                /*addr:0x28*/
    volatile unsigned int dmc_cfg1_ach1;                /*addr:0x2c*/
    volatile unsigned int dmc_cfg0_ach2;                /*addr:0x30*/
    volatile unsigned int dmc_cfg1_ach2;                /*addr:0x34*/
    volatile unsigned int dmc_cfg0_ach3;                /*addr:0x38*/
    volatile unsigned int dmc_cfg1_ach3;                /*addr:0x3c*/
    volatile unsigned int dmc_cfg0_ach4;                /*addr:0x40*/
    volatile unsigned int dmc_cfg1_ach4;                /*addr:0x44*/
    volatile unsigned int dmc_cfg0_ach5;                /*addr:0x48*/
    volatile unsigned int dmc_cfg1_ach5;                /*addr:0x4c*/
    volatile unsigned int dmc_cfg0_ach6;                /*addr:0x50*/
    volatile unsigned int dmc_cfg1_ach6;                /*addr:0x54*/
    volatile unsigned int dmc_cfg0_ach7;                /*addr:0x58*/
    volatile unsigned int dmc_cfg1_ach7;                /*addr:0x5c*/

    volatile unsigned int pad1[15];                     /*addr:0x60~0x98*/
    volatile unsigned int dmc_lock_cfg;                 /*addr:0x9c*/
    volatile unsigned int dmc_sts0;                     /*addr:0xa0*/
    volatile unsigned int dmc_sts1;                     /*addr:0xa4*/
    volatile unsigned int dmc_sts2;                     /*addr:0xa8*/
    volatile unsigned int dmc_sts3;                     /*addr:0xac*/
    volatile unsigned int dmc_sts4;                     /*addr:0xb0*/
    volatile unsigned int dmc_sts5;                     /*addr:0xb4*/
    volatile unsigned int dmc_sts6;                     /*addr:0xb8*/
    volatile unsigned int dmc_sts7;                     /*addr:0xbc*/

    volatile unsigned int dmc_axi_chx_sts[8];               /*addr:0xc0~0xdc*/
    volatile unsigned int pad2[8];                      /*addr:0xe0~0xfc*/

    volatile unsigned int dmc_dcfg0;                    /*addr:0x100*/
    volatile unsigned int dmc_dcfg1;                    /*addr:0x104*/
    volatile unsigned int dmc_dcfg2;                    /*addr:0x108*/
    volatile unsigned int dmc_dcfg3;                    /*addr:0x10c*/
    volatile unsigned int dmc_dcfg4;                    /*addr:0x110*/
    volatile unsigned int dmc_dcfg5;                    /*addr:0x114*/
    volatile unsigned int dmc_dcfg6;                    /*addr:0x118*/
    volatile unsigned int dmc_dcfg7;                    /*addr:0x11c*/
    volatile unsigned int dmc_dcfg8;                    /*addr:0x120*/
    volatile unsigned int dmc_dcfg9;                    /*addr:0x124*/
    volatile unsigned int dmc_dcfg10;               /*addr:0x128*/
    volatile unsigned int dmc_dcfg11;               /*addr:0x12c*/
    volatile unsigned int dmc_dcfg12;               /*addr:0x130*/
    volatile unsigned int dmc_dcfg13;               /*addr:0x134*/
    volatile unsigned int dmc_dcfg14;               /*addr:0x138*/
    volatile unsigned int dmc_dcfg15;               /*addr:0x13c*/
    volatile unsigned int dmc_dcfg16;               /*addr:0x140*/
    volatile unsigned int dmc_dcfg17;               /*addr:0x144*/
    volatile unsigned int dmc_dcfg18;               /*addr:0x148*/
    volatile unsigned int dmc_dcfg19;               /*addr:0x14c*/
    volatile unsigned int dmc_dcfg20;               /*addr:0x150*/

    volatile unsigned int pad3[11];                     /*addr:0x154~0x17c*/
    volatile unsigned int dmc_dtmg_f[8][20+4]; /*addr:0x180~0x1cc*/
}DDRC_R1P0_REG_INFO, *DDRC_R1P0_REG_INFO_PTR;

typedef enum PLL_SOURCE{
	DPLL0=0,
	DPLL1,
	TWPLL
}DMC_PLL_SOURCE;


typedef enum CLK_TYPE{
	PUB_CLK_156M=156,
	PUB_CLK_160M=160,
	PUB_CLK_233M=233,
	PUB_CLK_311M=311,
	PUB_CLK_384M=384,
	PUB_CLK_400M=400,
	PUB_CLK_512M=512,
	PUB_CLK_533M=533,
	PUB_CLK_622M=622,
	PUB_CLK_768M=768,
	PUB_CLK_800M=800,
	PUB_CLK_933M=933,
	PUB_CLK_1536M=1536,
	PUB_CLK_1600M=1600
}DMC_CLK_TYPE;

typedef enum DESKEWPLL_STATUS
{
	DESKEW_BYAPSS=0,
	DESKEW_ON,
	DESKEW_OFF
}DMC_DESKEWPLL_STATUS;

typedef struct CLK_DFS_CFG{
uint32 pll_sel;
uint32 pll_div_sel;
uint32 deskew_mode;
uint32 x1_sel;
uint32 d2_sel;
uint32 half_freq_mode;
}DMC_CLK_CFG;

typedef struct PUB_CLK_CFG{
uint32 freq_num;
DMC_CLK_TYPE ddr_clk;
DMC_PLL_SOURCE pll_source;
DMC_CLK_CFG  clk_cfg;
}DMC_PUB_CLK_CFG;

typedef struct dmc_local_timing_cfg {
    unsigned int clk;
    unsigned int dtmg[24];
}DDRC_R1P0_TIMING_CFG;

typedef struct dfs_freq_tab
{
    uint32 point_num;   //0:F0/1:F1/2:F2/3:F3
    uint32 freq;        //MHz
}dfs_freq_table;

typedef struct __LPDDR3_MR_INFO {
    int bl;         /*burst length*/
    int bt;         /*burst type*/
    int wc;         /*wrap*/
    int nwr;        /*nwr*/
    int rl;         /*read latency*/
    int wl;         /*write latency*/
    int ds;         /*driver strength*/
}LPDDR3_MR_INFO;

typedef struct __LPDDR4_MR_INFO {
    int bl;         /*burst length*/
    int bt;         /*burst type*/
    int wc;         /*wrap*/
    int nwr;        /*nwr*/
    int rl;         /*read latency*/
    int wl;         /*write latency*/
    int ds;         /*driver strength*/
    int dbi;
}LPDDR4_MR_INFO;

typedef enum __dmc_cmd_cs_index {
    CMD_CS_0,
    CMD_CS_1,
    CMD_CS_BOTH
}DMC_CMD_CS_INDEX;

typedef enum __DRAM_TYPE {
    DRAM_LPDDR1=0x100,
    DRAM_LPDDR2,
    DRAM_LPDDR3,
    DRAM_LPDDR4,
}DRAM_TYPE;

#define CFG_DRAM_TYPE DRAM_LPDDR3

typedef struct __DRAM_JEDEC_INFO {
    int cs_index;
    int bank;
    int row;
    int column;
    int dw;
    u32 cs_size;
}DRAM_JEDEC_INFO;

typedef struct __DRAM_CHIP_INFO {
    DRAM_TYPE chip_type;
    int cs_num;
    DRAM_JEDEC_INFO *cs0_jedec_info;
    DRAM_JEDEC_INFO *cs1_jedec_info;
    int unsymmetry;
}DRAM_CHIP_INFO;

#define CFG_CS0_BANK_NUM	8
#define CFG_CS0_ROW_NUM		15
#define CFG_CS0_COLUMN_NUM	10
#define CFG_CS0_DQ_DW		32
#define CFG_CS0_AP_PIN_POS	10
#define CFG_CS0_SIZE	0x40000000

#define CFG_CS1_BANK_NUM	8
#define CFG_CS1_ROW_NUM		15
#define CFG_CS1_COLUMN_NUM	10
#define CFG_CS1_DQ_DW		32
#define CFG_CS1_AP_PIN_POS	10
#define CFG_CS1_SIZE	0x40000000
struct interleave_cfg
{
	u32 liner_base_ch0;
	u32 liner_base_ch1;
	u32 liner_base_ch2;
	u32 liner_base_ch3;
	u32 interleave_base;
	u32 interleave_offset;
};

void reset_dmc_fifo(void);
uint32 find_freq_num(uint32 clk_freq);
uint32 find_ddr_freq(uint32 num);
int ctrl_pre_set_seq(dfs_freq_table dfs_frequency[8]);
void axi_ch_cfg_seq(void);
int ctrl_post_set_seq(void);
void ddrc_phy_pre_set_seq(void);
void ddrc_phy_post_set_seq(void);
void dram_powerup_seq(u32 clock);
void ddrc_phy_init_post_seq(void);
void ddrc_phy_init_seq(void);

/*default burst length*/
#define DEFAULT_LPDDR2_BL   4
#define DEFAULT_LPDDR3_BL   8
#define DEFAULT_LPDDR4_BL   16

#define MRR_BYTE_SWITCH_INDEX 0

#define RF_LINER_BASE_CH0_16G			0
#define RF_LINER_BASE_CH1_16G     0
#define RF_LINER_BASE_CH2_16G     0
#define RF_LINER_BASE_CH3_16G     0
#define RF_INTERLEAVE_BASE_16G    0
#define RF_INTERLEAVE_OFFSET_16G  0
#define RF_LINER_BASE_CH0_8G      0
#define RF_LINER_BASE_CH1_8G      0
#define RF_LINER_BASE_CH2_8G      0
#define RF_LINER_BASE_CH3_8G      0
#define RF_INTERLEAVE_BASE_8G     0
#define RF_INTERLEAVE_OFFSET_8G   0
#define RF_LINER_BASE_CH0_4G      0
#define RF_LINER_BASE_CH1_4G      0
#define RF_LINER_BASE_CH2_4G      0
#define RF_LINER_BASE_CH3_4G      0
#define RF_INTERLEAVE_BASE_4G     0
#define RF_INTERLEAVE_OFFSET_4G   0
#define RF_LINER_BASE_CH0_2G      0
#define RF_LINER_BASE_CH1_2G      0
#define RF_LINER_BASE_CH2_2G      0
#define RF_LINER_BASE_CH3_2G      0
#define RF_INTERLEAVE_BASE_2G     0
#define RF_INTERLEAVE_OFFSET_2G   0
#define RF_LINER_BASE_CH0_1G      0
#define RF_LINER_BASE_CH1_1G      0
#define RF_LINER_BASE_CH2_1G      0
#define RF_LINER_BASE_CH3_1G      0
#define RF_INTERLEAVE_BASE_1G     0
#define RF_INTERLEAVE_OFFSET_1G   0
#define RF_LINER_BASE_CH0_512M    0
#define RF_LINER_BASE_CH1_512M    0
#define RF_LINER_BASE_CH2_512M    0
#define RF_LINER_BASE_CH3_512M    0
#define RF_INTERLEAVE_BASE_512M   0
#define RF_INTERLEAVE_OFFSET_512M 0

#endif
