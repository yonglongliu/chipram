/*
 * Copyright (C) 2017 Spreadtrum Communications Inc.
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 * updated at 2017-12-14 16:29:53
 *
 */


#ifndef ANLG_PHY_TOP_H
#define ANLG_PHY_TOP_H

#define CTL_BASE_ANLG_PHY_TOP 0x32420000


#define REG_ANLG_PHY_TOP_ANALOG_MPLL0_MPLL0_CTRL0_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x0000 )
#define REG_ANLG_PHY_TOP_ANALOG_MPLL0_REG_SEL_CFG_0                ( CTL_BASE_ANLG_PHY_TOP + 0x0004 )
#define REG_ANLG_PHY_TOP_ANALOG_MPLL1_MPLL1_CTRL0_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x0008 )
#define REG_ANLG_PHY_TOP_ANALOG_MPLL1_REG_SEL_CFG_0                ( CTL_BASE_ANLG_PHY_TOP + 0x000C )
#define REG_ANLG_PHY_TOP_ANALOG_THM2_0_THM2_CTL_TOP                ( CTL_BASE_ANLG_PHY_TOP + 0x0010 )
#define REG_ANLG_PHY_TOP_ANALOG_THM2_0_REG_SEL_CFG_0               ( CTL_BASE_ANLG_PHY_TOP + 0x0014 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ANA_BB_PWR_CTRL_TOP         ( CTL_BASE_ANLG_PHY_TOP + 0x0018 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ANA_BB_RST_CTRL_TOP         ( CTL_BASE_ANLG_PHY_TOP + 0x001C )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ANA_BB_SINE_CTRL_TOP        ( CTL_BASE_ANLG_PHY_TOP + 0x0020 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_CTRL0_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x0024 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_CTRL1_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x0028 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_CTRL2_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x002C )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_BIST_CTRL_TOP          ( CTL_BASE_ANLG_PHY_TOP + 0x0030 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_CTRL0_TOP             ( CTL_BASE_ANLG_PHY_TOP + 0x0034 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_CTRL2_TOP             ( CTL_BASE_ANLG_PHY_TOP + 0x0038 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_CTRL0_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x003C )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_CTRL2_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x0040 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_GPLL_CTRL2_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x0044 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_AAPC_CTRL1_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x0048 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_AAPC_CTRL2_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x004C )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ANA_BB_RSVD_TOP             ( CTL_BASE_ANLG_PHY_TOP + 0x0050 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_RTC4M_CTRL_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x0054 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_CTRL0_TOP            ( CTL_BASE_ANLG_PHY_TOP + 0x0058 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_CTRL3_TOP            ( CTL_BASE_ANLG_PHY_TOP + 0x005C )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_PLL_RESERVED_TOP            ( CTL_BASE_ANLG_PHY_TOP + 0x0060 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_PLL_CLKEN_TOP               ( CTL_BASE_ANLG_PHY_TOP + 0x0064 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_RESERVED_TOP         ( CTL_BASE_ANLG_PHY_TOP + 0x0068 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_REG_SEL_CFG_0               ( CTL_BASE_ANLG_PHY_TOP + 0x006C )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_REG_SEL_CFG_1               ( CTL_BASE_ANLG_PHY_TOP + 0x0070 )
#define REG_ANLG_PHY_TOP_ANALOG_BB_TOP_REG_SEL_CFG_2               ( CTL_BASE_ANLG_PHY_TOP + 0x0074 )
#define REG_ANLG_PHY_TOP_ANALOG_THM2_1_THM2_CTL_TOP                ( CTL_BASE_ANLG_PHY_TOP + 0x0078 )
#define REG_ANLG_PHY_TOP_ANALOG_THM2_1_REG_SEL_CFG_0               ( CTL_BASE_ANLG_PHY_TOP + 0x007C )
#define REG_ANLG_PHY_TOP_ANALOG_EFUSE1_0_EFUSE_PIN_PW_CTL_TOP      ( CTL_BASE_ANLG_PHY_TOP + 0x0080 )
#define REG_ANLG_PHY_TOP_ANALOG_EFUSE1_0_REG_SEL_CFG_0             ( CTL_BASE_ANLG_PHY_TOP + 0x0084 )
#define REG_ANLG_PHY_TOP_ANALOG_EFUSE1_1_EFUSE_PIN_PW_CTL_TOP      ( CTL_BASE_ANLG_PHY_TOP + 0x0088 )
#define REG_ANLG_PHY_TOP_ANALOG_EFUSE1_1_REG_SEL_CFG_0             ( CTL_BASE_ANLG_PHY_TOP + 0x008C )
#define REG_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL2_CTRL0_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x0090 )
#define REG_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL3_CTRL0_TOP              ( CTL_BASE_ANLG_PHY_TOP + 0x0094 )
#define REG_ANLG_PHY_TOP_ANALOG_MPLL2_REG_SEL_CFG_0                ( CTL_BASE_ANLG_PHY_TOP + 0x0098 )
#define REG_ANLG_PHY_TOP_ANALOG_THM1_THM1_CTL_TOP                  ( CTL_BASE_ANLG_PHY_TOP + 0x009C )
#define REG_ANLG_PHY_TOP_ANALOG_THM1_REG_SEL_CFG_0                 ( CTL_BASE_ANLG_PHY_TOP + 0x00A0 )
#define REG_ANLG_PHY_TOP_ANALOG_PHY_PD_ISO_REG_CFG_0               ( CTL_BASE_ANLG_PHY_TOP + 0x00A4 )
#define REG_ANLG_PHY_TOP_ANALOG_USB20_USB20_TEST_PIN               ( CTL_BASE_ANLG_PHY_TOP + 0x00A8 )
#define REG_ANLG_PHY_TOP_ANALOG_USB20_USB20_UTMI_CTL1              ( CTL_BASE_ANLG_PHY_TOP + 0x00AC )
#define REG_ANLG_PHY_TOP_ANALOG_USB20_USB20_BATTER_PLL             ( CTL_BASE_ANLG_PHY_TOP + 0x00B0 )
#define REG_ANLG_PHY_TOP_ANALOG_USB20_USB20_UTMI_CTL2              ( CTL_BASE_ANLG_PHY_TOP + 0x00B4 )
#define REG_ANLG_PHY_TOP_ANALOG_USB20_USB20_PHY_BIST_TEST          ( CTL_BASE_ANLG_PHY_TOP + 0x00B8 )
#define REG_ANLG_PHY_TOP_ANALOG_USB20_REG_SEL_CFG_0                ( CTL_BASE_ANLG_PHY_TOP + 0x00BC )
#define REG_ANLG_PHY_TOP_MPLL_CLK_JITTER_CTRL                      ( CTL_BASE_ANLG_PHY_TOP + 0x00C0 )

/* REG_ANLG_PHY_TOP_ANALOG_MPLL0_MPLL0_CTRL0_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_MPLL0_MPLL0_PD                         BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL0_MPLL0_RST                        BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL0_MPLL0_CLKOUT_EN                  BIT(2)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL0_MPLL0_DIV32_EN                   BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL0_MPLL0_LOCK_DONE                  BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_MPLL0_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL0_MPLL0_PD                 BIT(3)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL0_MPLL0_RST                BIT(2)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL0_MPLL0_CLKOUT_EN          BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL0_MPLL0_DIV32_EN           BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_MPLL1_MPLL1_CTRL0_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_MPLL1_MPLL1_PD                         BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL1_MPLL1_RST                        BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL1_MPLL1_CLKOUT_EN                  BIT(2)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL1_MPLL1_DIV32_EN                   BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL1_MPLL1_LOCK_DONE                  BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_MPLL1_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL1_MPLL1_PD                 BIT(3)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL1_MPLL1_RST                BIT(2)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL1_MPLL1_CLKOUT_EN          BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL1_MPLL1_DIV32_EN           BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_THM2_0_THM2_CTL_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_THM2_0_THM_RSTN                        BIT(13)
#define BIT_ANLG_PHY_TOP_ANALOG_THM2_0_THM_RUN                         BIT(12)
#define BIT_ANLG_PHY_TOP_ANALOG_THM2_0_THM_PD                          BIT(11)
#define BIT_ANLG_PHY_TOP_ANALOG_THM2_0_THM_VALID                       BIT(10)
#define BIT_ANLG_PHY_TOP_ANALOG_THM2_0_THM_DATA(x)                     (((x) & 0x3FF))

/* REG_ANLG_PHY_TOP_ANALOG_THM2_0_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_THM2_0_THM_RSTN                BIT(2)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_THM2_0_THM_RUN                 BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_THM2_0_THM_PD                  BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ANA_BB_PWR_CTRL_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_REC_26MHZ_0_BUF_PD              BIT(6)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_PD                         BIT(5)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_PD                        BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_PD                         BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_GPLL_PD                         BIT(2)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_S_AAPC_PD                       BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_M_AAPC_PD                       BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ANA_BB_RST_CTRL_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_RST                        BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_RST                       BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_RST                        BIT(2)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_GPLL_RST                        BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RTC100M_RSTB                    BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ANA_BB_SINE_CTRL_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_SINDRV_ENA                      BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_SINDRV_ENA_SQUARE               BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_CTRL0_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_N(x)                       (((x) & 0x7FF) << 12)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_IBIAS(x)                   (((x) & 0x3) << 10)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_LPF(x)                     (((x) & 0x7) << 7)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_SDM_EN                     BIT(6)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_MOD_EN                     BIT(5)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_DIV_S                      BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_REF_SEL(x)                 (((x) & 0x3) << 2)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_CLK26MHZ_AUD_EN                 BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_DIV_EN                     BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_CTRL1_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_NINT(x)                    (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_KINT(x)                    (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_CTRL2_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_DIV1_EN                    BIT(8)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_BIST_EN                    BIT(7)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_26M_DIV(x)                 (((x) & 0x3F) << 1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_LOCK_DONE                  BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_BIST_CTRL_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_BIST_CTRL(x)               (((x) & 0xFF) << 16)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RPLL_BIST_CNT(x)                (((x) & 0xFFFF))

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_CTRL0_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_REF_SEL(x)                (((x) & 0x3))

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_CTRL2_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_CLKOUT_EN                 BIT(6)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_DIV1_EN                   BIT(5)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_DIV2_EN                   BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_DIV3_EN                   BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_DIV5_EN                   BIT(2)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_DIV7_EN                   BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_TWPLL_LOCK_DONE                 BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_CTRL0_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_REF_SEL(x)                 (((x) & 0x3))

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_CTRL2_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_CLKOUT_EN                  BIT(5)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_DIV1_EN                    BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_DIV2_EN                    BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_DIV3_EN                    BIT(2)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_DIV5_EN                    BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_LPLL_LOCK_DONE                  BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_GPLL_CTRL2_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_GPLL_CLKOUT_EN                  BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_GPLL_LOCK_DONE                  BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_AAPC_CTRL1_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_AAPC_G0(x)                      (((x) & 0x3) << 24)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_AAPC_G1(x)                      (((x) & 0x3) << 22)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_AAPC_G2(x)                      (((x) & 0x3) << 20)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_S_AAPC_LOW_V_CON                BIT(19)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_S_AAPC_D(x)                     (((x) & 0x3FFF) << 5)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_S_AAPC_BPRES                    BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_S_APCOUT_SEL(x)                 (((x) & 0x3) << 2)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_S_AAPC_RESERVED(x)              (((x) & 0x3))

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_AAPC_CTRL2_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_M_AAPC_D(x)                     (((x) & 0x3FFF) << 6)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_M_AAPC_LOW_V_CON                BIT(5)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_M_AAPC_BPRES                    BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_M_APCOUT_SEL(x)                 (((x) & 0x3) << 2)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_M_AAPC_RESERVED(x)              (((x) & 0x3))

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ANA_BB_RSVD_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_TO_LVDS_SEL(x)                  (((x) & 0x3))

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_RTC4M_CTRL_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RTC100M_EN                      BIT(7)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_RTC100M_RC_C(x)                 (((x) & 0x7F))

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_CTRL0_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_BB_BG_RBIAS_MODE                BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_CLKIN                    BIT(2)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_PD                       BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_RST                      BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_CTRL3_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_LOCK_DONE                BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_CLKOUT                   BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_PLL_RESERVED_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_ANALOG_PLL_RESERVED(x)          (((x) & 0x3FFFFFFF))

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_PLL_CLKEN_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_GPIO_BB_CLKIN                   BIT(10)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_GPIO_RPLL_CLKIN_EN              BIT(9)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_SINEO_RPLL_CLKOUT_EN            BIT(8)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_GPIO_TWPLL_CLKIN_EN             BIT(7)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_SINEO_TWPLL_CLKOUT_EN           BIT(6)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_GPIO_LPLL_CLKIN_EN              BIT(5)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_SINEO_LPLL_CLKOUT_EN            BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_GPIO_GPLL_CLKIN_EN              BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_SINEO_GPLL_CLKOUT_EN            BIT(2)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_GPIO_ISPPLL_CLKIN_EN            BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_SINEO_ISPPLL_CLKOUT_EN          BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_RESERVED_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_DIV2_EN                  BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_DIV3_EN                  BIT(2)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_DIV2_CLKOUT              BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_BB_TOP_ISPPLL_DIV3_CLKOUT              BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_REC_26MHZ_0_BUF_PD      BIT(31)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_PD                 BIT(30)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_TWPLL_PD                BIT(29)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_LPLL_PD                 BIT(28)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_GPLL_PD                 BIT(27)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_S_AAPC_PD               BIT(26)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_M_AAPC_PD               BIT(25)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_RST                BIT(24)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_TWPLL_RST               BIT(23)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_LPLL_RST                BIT(22)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_GPLL_RST                BIT(21)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RTC100M_RSTB            BIT(20)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_N                  BIT(19)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_IBIAS              BIT(18)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_LPF                BIT(17)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_SDM_EN             BIT(16)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_MOD_EN             BIT(15)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_DIV_S              BIT(14)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_REF_SEL            BIT(13)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_CLK26MHZ_AUD_EN         BIT(12)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_DIV_EN             BIT(11)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_NINT               BIT(10)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_KINT               BIT(9)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_DIV1_EN            BIT(8)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_BIST_EN            BIT(7)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_26M_DIV            BIT(6)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RPLL_BIST_CTRL          BIT(5)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_TWPLL_REF_SEL           BIT(4)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_TWPLL_DIV1_EN           BIT(3)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_TWPLL_DIV2_EN           BIT(2)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_TWPLL_DIV3_EN           BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_TWPLL_DIV5_EN           BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_REG_SEL_CFG_1 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_TWPLL_DIV7_EN           BIT(31)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_LPLL_REF_SEL            BIT(30)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_LPLL_DIV1_EN            BIT(29)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_LPLL_DIV2_EN            BIT(28)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_LPLL_DIV3_EN            BIT(27)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_LPLL_DIV5_EN            BIT(26)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_GPLL_CLKOUT_EN          BIT(25)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_AAPC_G0                 BIT(24)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_AAPC_G1                 BIT(23)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_AAPC_G2                 BIT(22)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_S_AAPC_LOW_V_CON        BIT(21)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_S_AAPC_D                BIT(20)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_S_AAPC_BPRES            BIT(19)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_S_APCOUT_SEL            BIT(18)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_S_AAPC_RESERVED         BIT(17)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_M_AAPC_D                BIT(16)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_M_AAPC_LOW_V_CON        BIT(15)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_M_AAPC_BPRES            BIT(14)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_M_APCOUT_SEL            BIT(13)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_M_AAPC_RESERVED         BIT(12)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_TO_LVDS_SEL             BIT(11)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RTC100M_EN              BIT(10)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_RTC100M_RC_C            BIT(9)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_BB_BG_RBIAS_MODE        BIT(8)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_ISPPLL_CLKIN            BIT(7)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_ISPPLL_PD               BIT(6)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_ISPPLL_RST              BIT(5)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_ANALOG_PLL_RESERVED     BIT(4)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_GPIO_BB_CLKIN           BIT(3)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_GPIO_RPLL_CLKIN_EN      BIT(2)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_SINEO_RPLL_CLKOUT_EN    BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_GPIO_TWPLL_CLKIN_EN     BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_BB_TOP_REG_SEL_CFG_2 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_SINEO_TWPLL_CLKOUT_EN   BIT(8)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_GPIO_LPLL_CLKIN_EN      BIT(7)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_SINEO_LPLL_CLKOUT_EN    BIT(6)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_GPIO_GPLL_CLKIN_EN      BIT(5)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_SINEO_GPLL_CLKOUT_EN    BIT(4)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_GPIO_ISPPLL_CLKIN_EN    BIT(3)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_SINEO_ISPPLL_CLKOUT_EN  BIT(2)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_ISPPLL_DIV2_EN          BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_BB_TOP_ISPPLL_DIV3_EN          BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_THM2_1_THM2_CTL_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_THM2_1_THM_RSTN                        BIT(13)
#define BIT_ANLG_PHY_TOP_ANALOG_THM2_1_THM_RUN                         BIT(12)
#define BIT_ANLG_PHY_TOP_ANALOG_THM2_1_THM_PD                          BIT(11)
#define BIT_ANLG_PHY_TOP_ANALOG_THM2_1_THM_VALID                       BIT(10)
#define BIT_ANLG_PHY_TOP_ANALOG_THM2_1_THM_DATA(x)                     (((x) & 0x3FF))

/* REG_ANLG_PHY_TOP_ANALOG_THM2_1_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_THM2_1_THM_RSTN                BIT(2)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_THM2_1_THM_RUN                 BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_THM2_1_THM_PD                  BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_EFUSE1_0_EFUSE_PIN_PW_CTL_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_EFUSE1_0_EFS1_ENK1                     BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_EFUSE1_0_EFS1_ENK2                     BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_EFUSE1_0_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_EFUSE1_0_EFS1_ENK1             BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_EFUSE1_0_EFS1_ENK2             BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_EFUSE1_1_EFUSE_PIN_PW_CTL_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_EFUSE1_1_EFS1_ENK1                     BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_EFUSE1_1_EFS1_ENK2                     BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_EFUSE1_1_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_EFUSE1_1_EFS1_ENK1             BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_EFUSE1_1_EFS1_ENK2             BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL2_CTRL0_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL2_PD                         BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL2_RST                        BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL2_CLKOUT_EN                  BIT(2)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL2_DIV32_EN                   BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL2_LOCK_DONE                  BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL3_CTRL0_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL3_PD                         BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL3_RST                        BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL3_CLKOUT_EN                  BIT(2)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL3_DIV32_EN                   BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_MPLL2_MPLL3_LOCK_DONE                  BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_MPLL2_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL2_MPLL2_PD                 BIT(7)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL2_MPLL2_RST                BIT(6)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL2_MPLL2_CLKOUT_EN          BIT(5)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL2_MPLL2_DIV32_EN           BIT(4)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL2_MPLL3_PD                 BIT(3)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL2_MPLL3_RST                BIT(2)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL2_MPLL3_CLKOUT_EN          BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MPLL2_MPLL3_DIV32_EN           BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_THM1_THM1_CTL_TOP */

#define BIT_ANLG_PHY_TOP_ANALOG_THM1_THM_RSTN                          BIT(13)
#define BIT_ANLG_PHY_TOP_ANALOG_THM1_THM_RUN                           BIT(12)
#define BIT_ANLG_PHY_TOP_ANALOG_THM1_THM_PD                            BIT(11)
#define BIT_ANLG_PHY_TOP_ANALOG_THM1_THM_VALID                         BIT(10)
#define BIT_ANLG_PHY_TOP_ANALOG_THM1_THM_DATA(x)                       (((x) & 0x3FF))

/* REG_ANLG_PHY_TOP_ANALOG_THM1_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_THM1_THM_RSTN                  BIT(2)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_THM1_THM_RUN                   BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_THM1_THM_PD                    BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_PHY_PD_ISO_REG_CFG_0 */

#define BIT_ANLG_PHY_TOP_R2G_SEL_DSI_4LANE_ISO_SW_EN                   BIT(28)
#define BIT_ANLG_PHY_TOP_R2G_SEL_CSI_4LANE_0_ISO_SW_EN                 BIT(27)
#define BIT_ANLG_PHY_TOP_R2G_SEL_CSI_2LANE_ISO_SW_EN                   BIT(26)
#define BIT_ANLG_PHY_TOP_R2G_SEL_CSI_2P2LANE_ISO_SW_EN                 BIT(25)
#define BIT_ANLG_PHY_TOP_R2G_USB20_ISO_SW_EN                           BIT(24)
#define BIT_ANLG_PHY_TOP_R2G_DSI_4LANE_ISO_SW_EN                       BIT(23)
#define BIT_ANLG_PHY_TOP_R2G_CSI_4LANE_0_ISO_SW_EN                     BIT(22)
#define BIT_ANLG_PHY_TOP_R2G_CSI_2LANE_ISO_SW_EN                       BIT(21)
#define BIT_ANLG_PHY_TOP_R2G_CSI_2P2LANE_ISO_SW_EN                     BIT(20)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MIPI_CSI_4LANE_DSI_PS_PD_S     BIT(19)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MIPI_CSI_4LANE_DSI_PS_PD_L     BIT(18)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MIPI_CSI_4LANE_0_CSI_PS_PD_S   BIT(17)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MIPI_CSI_4LANE_0_CSI_PS_PD_L   BIT(16)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MIPI_CSI_2LANE_CSI_PS_PD_S     BIT(15)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MIPI_CSI_2LANE_CSI_PS_PD_L     BIT(14)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MIPI_CSI_2P2LANE_CSI_PS_PD_S   BIT(13)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_MIPI_CSI_2P2LANE_CSI_PS_PD_L   BIT(12)
#define BIT_ANLG_PHY_TOP_R2G_ANALOG_MIPI_CSI_4LANE_DSI_PS_PD_S         BIT(11)
#define BIT_ANLG_PHY_TOP_R2G_ANALOG_MIPI_CSI_4LANE_DSI_PS_PD_L         BIT(10)
#define BIT_ANLG_PHY_TOP_R2G_ANALOG_MIPI_CSI_4LANE_0_CSI_PS_PD_S       BIT(9)
#define BIT_ANLG_PHY_TOP_R2G_ANALOG_MIPI_CSI_4LANE_0_CSI_PS_PD_L       BIT(8)
#define BIT_ANLG_PHY_TOP_R2G_ANALOG_MIPI_CSI_2LANE_CSI_PS_PD_S         BIT(7)
#define BIT_ANLG_PHY_TOP_R2G_ANALOG_MIPI_CSI_2LANE_CSI_PS_PD_L         BIT(6)
#define BIT_ANLG_PHY_TOP_R2G_ANALOG_MIPI_CSI_2P2LANE_CSI_PS_PD_S       BIT(5)
#define BIT_ANLG_PHY_TOP_R2G_ANALOG_MIPI_CSI_2P2LANE_CSI_PS_PD_L       BIT(4)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_USB20_USB20_PS_PD_S            BIT(3)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_USB20_USB20_PS_PD_L            BIT(2)
#define BIT_ANLG_PHY_TOP_R2G_ANALOG_USB20_USB20_PS_PD_S                BIT(1)
#define BIT_ANLG_PHY_TOP_R2G_ANALOG_USB20_USB20_PS_PD_L                BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_USB20_USB20_TEST_PIN */

#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_TESTDATAOUT(x)             (((x) & 0xF) << 7)
#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_T2RCOMP                    BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_LPBK_END                   BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_USB20_USB20_UTMI_CTL1 */

#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_SUSPENDM                   BIT(27)
#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_PORN                       BIT(26)
#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_RESET                      BIT(25)
#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_RXERROR                    BIT(24)
#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_BYPASS_FS                  BIT(22)
#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_BYPASS_IN_DM               BIT(21)
#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_BYPASS_OUT_DP              BIT(20)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_USB20_USB20_BYPASS_FS          BIT(19)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_USB20_USB20_BYPASS_IN_DM       BIT(18)

/* REG_ANLG_PHY_TOP_ANALOG_USB20_USB20_BATTER_PLL */

#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_SAMPLER_SEL                BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_USB20_USB20_UTMI_CTL2 */

#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_DPPULLDOWN                 BIT(4)
#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_DMPULLDOWN                 BIT(3)
#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_SLEEPM                     BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_USB20_USB20_PHY_BIST_TEST */

#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_BISTRAM_EN                 BIT(1)
#define BIT_ANLG_PHY_TOP_ANALOG_USB20_USB20_BIST_MODE_EN               BIT(0)

/* REG_ANLG_PHY_TOP_ANALOG_USB20_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_USB20_USB20_SUSPENDM           BIT(6)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_USB20_USB20_PORN               BIT(5)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_USB20_USB20_RESET              BIT(4)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_USB20_USB20_SAMPLER_SEL        BIT(3)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_USB20_USB20_DPPULLDOWN         BIT(2)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_USB20_USB20_DMPULLDOWN         BIT(1)
#define BIT_ANLG_PHY_TOP_DBG_SEL_ANALOG_USB20_USB20_SLEEPM             BIT(0)

/* REG_ANLG_PHY_TOP_MPLL_CLK_JITTER_CTRL */

#define BIT_ANLG_PHY_TOP_MPLL_CLK_JITTER_MON_SEL(x)                    (((x) & 0x3) << 1)
#define BIT_ANLG_PHY_TOP_MPLL_CLK_JITTER_MON_EN                        BIT(0)


#endif /* ANLG_PHY_TOP_H */


