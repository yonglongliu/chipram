/*
 * Copyright (C) 2017 Spreadtrum Communications Inc.
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 * updated at 2017-12-27 15:24:15
 *
 */


#ifndef ANLG_PHY_G2_H
#define ANLG_PHY_G2_H

#define CTL_BASE_ANLG_PHY_G2 0x40353000


#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPIO_CLK_CTRL            ( CTL_BASE_ANLG_PHY_G2 + 0x0000 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL0              ( CTL_BASE_ANLG_PHY_G2 + 0x0004 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL1              ( CTL_BASE_ANLG_PHY_G2 + 0x0008 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL2              ( CTL_BASE_ANLG_PHY_G2 + 0x000C )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL3              ( CTL_BASE_ANLG_PHY_G2 + 0x0010 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL4              ( CTL_BASE_ANLG_PHY_G2 + 0x0014 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL5              ( CTL_BASE_ANLG_PHY_G2 + 0x0018 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL6              ( CTL_BASE_ANLG_PHY_G2 + 0x001C )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL0               ( CTL_BASE_ANLG_PHY_G2 + 0x0020 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL1               ( CTL_BASE_ANLG_PHY_G2 + 0x0024 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL2               ( CTL_BASE_ANLG_PHY_G2 + 0x0028 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL3               ( CTL_BASE_ANLG_PHY_G2 + 0x002C )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL4               ( CTL_BASE_ANLG_PHY_G2 + 0x0030 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL0               ( CTL_BASE_ANLG_PHY_G2 + 0x0038 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL1               ( CTL_BASE_ANLG_PHY_G2 + 0x003C )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL2               ( CTL_BASE_ANLG_PHY_G2 + 0x0040 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL3               ( CTL_BASE_ANLG_PHY_G2 + 0x0044 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL4               ( CTL_BASE_ANLG_PHY_G2 + 0x0048 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL0              ( CTL_BASE_ANLG_PHY_G2 + 0x0050 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL1              ( CTL_BASE_ANLG_PHY_G2 + 0x0054 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL2              ( CTL_BASE_ANLG_PHY_G2 + 0x0058 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL3              ( CTL_BASE_ANLG_PHY_G2 + 0x005C )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL4              ( CTL_BASE_ANLG_PHY_G2 + 0x0060 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_ANA_PLL_RSVD             ( CTL_BASE_ANLG_PHY_G2 + 0x0068 )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_PLL_TO_CSI_CLK_CRTL      ( CTL_BASE_ANLG_PHY_G2 + 0x007C )
#define REG_ANLG_PHY_G2_ANALOG_PLL_TOP_REG_SEL_CFG_0            ( CTL_BASE_ANLG_PHY_G2 + 0x0080 )

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPIO_CLK_CTRL */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPIO_CLK_IN_CTRL          BIT(3)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPIO_CLK_OUT_CTRL(x)      (((x) & 0x7))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL0 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_MACRO_TYPE(x)       (((x) & 0xFF) << 24)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_REG_VERSION(x)      (((x) & 0xF) << 20)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_N(x)                (((x) & 0x7FF) << 8)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_ICP(x)              (((x) & 0x7) << 3)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_SDM_EN              BIT(2)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_MOD_EN              BIT(1)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV_S               BIT(0)

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL1 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_NINT(x)             (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_KINT(x)             (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL2 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_LOCK_DONE           BIT(31)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_FREQ_DOUBLE_EN      BIT(27)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_RST                 BIT(25)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_PD                  BIT(24)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_REF_SEL(x)          (((x) & 0x3) << 20)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV7_EN             BIT(7)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV5_EN             BIT(5)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV3_EN             BIT(3)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV2_EN             BIT(2)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_DIV1_EN             BIT(1)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CLKOUT_EN           BIT(0)

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL3 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_RESERVED(x)         (((x) & 0xFF) << 16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_SSC_CTRL(x)         (((x) & 0xFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL4 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_BIST_EN             BIT(16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_BIST_CNT(x)         (((x) & 0xFFFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL5 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_R2_SEL(x)           (((x) & 0x3) << 30)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_R3_SEL(x)           (((x) & 0x3) << 28)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_C1_SEL(x)           (((x) & 0x3) << 26)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_C2_SEL(x)           (((x) & 0x3) << 24)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_LDO_TRIM(x)         (((x) & 0xF) << 20)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_KVCO_SEL(x)         (((x) & 0x3) << 18)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CP_OFFSET(x)        (((x) & 0x3) << 16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCO_BANK_SEL(x)     (((x) & 0x1F) << 10)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_MODE(x)        (((x) & 0x3) << 8)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCO_TEST_EN         BIT(7)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCO_TEST_INT        BIT(6)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCO_TEST_INTSEL(x)  (((x) & 0x7) << 3)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CP_EN               BIT(2)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_FBDIV_EN            BIT(1)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCOBUF_EN           BIT(0)

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CTRL6 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCTRLH_SEL(x)       (((x) & 0x7) << 24)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCTRLL_SEL(x)       (((x) & 0x7) << 21)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_INI(x)         (((x) & 0x1F) << 16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCTRL_HIGH          BIT(14)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_VCTRL_LOW           BIT(13)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_OUT(x)         (((x) & 0x1F) << 8)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_WAITCNT(x)     (((x) & 0x3) << 6)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_FREQ_DIFF_EN        BIT(5)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_RG_CLOSELOOP_EN     BIT(4)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_POLARITY       BIT(3)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_CPPD           BIT(2)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_DONE           BIT(1)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_TWPLL_CALI_TRIG           BIT(0)

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL0 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_MACRO_TYPE(x)        (((x) & 0xFF) << 24)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_REG_VERSION(x)       (((x) & 0xF) << 20)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_N(x)                 (((x) & 0x7FF) << 8)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_IBIAS(x)             (((x) & 0x3) << 6)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_LPF(x)               (((x) & 0x7) << 3)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_SDM_EN               BIT(2)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_MOD_EN               BIT(1)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_DIV_S                BIT(0)

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL1 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_NINT(x)              (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_KINT(x)              (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL2 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_LOCK_DONE            BIT(31)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_RST                  BIT(25)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_PD                   BIT(24)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_REF_SEL(x)           (((x) & 0x3) << 20)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_DIV5_EN              BIT(5)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_DIV3_EN              BIT(3)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_DIV2_EN              BIT(2)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_DIV1_EN              BIT(1)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CLKOUT_EN            BIT(0)

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL3 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_RESERVED(x)          (((x) & 0xFF) << 16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_SSC_CTRL(x)          (((x) & 0xFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_CTRL4 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_BIST_EN              BIT(16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_LPLL_BIST_CNT(x)          (((x) & 0xFFFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL0 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_MACRO_TYPE(x)        (((x) & 0xFF) << 24)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_REG_VERSION(x)       (((x) & 0xF) << 20)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_N(x)                 (((x) & 0x7FF) << 8)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_IBIAS(x)             (((x) & 0x3) << 6)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_LPF(x)               (((x) & 0x7) << 3)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_SDM_EN               BIT(2)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_MOD_EN               BIT(1)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_DIV_S                BIT(0)

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL1 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_NINT(x)              (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_KINT(x)              (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL2 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_LOCK_DONE            BIT(31)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_RST                  BIT(25)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_PD                   BIT(24)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_REF_SEL              BIT(20)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_POSTDIV              BIT(16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CLKOUT_EN            BIT(0)

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL3 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_RESERVED(x)          (((x) & 0xFF) << 16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_SSC_CTRL(x)          (((x) & 0xFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_CTRL4 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_BIST_EN              BIT(16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_GPLL_BIST_CNT(x)          (((x) & 0xFFFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL0 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_MACRO_TYPE(x)        (((x) & 0xFF) << 24)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_REG_VERSION(x)       (((x) & 0xF) << 20)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_N(x)                 (((x) & 0x7FF) << 8)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_IBIAS(x)             (((x) & 0x3) << 6)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_LPF(x)               (((x) & 0x7) << 3)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_SDM_EN               BIT(2)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_MOD_EN               BIT(1)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_DIV_S                BIT(0)

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL1 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_NINT(x)              (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_KINT(x)              (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL2 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_LOCK_DONE            BIT(31)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_RST                  BIT(25)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_PD                   BIT(24)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_REF_SEL              BIT(20)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_POSTDIV              BIT(16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_DIV3_EN              BIT(3)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_DIV2_EN              BIT(2)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_DIV1_EN              BIT(1)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_CLKOUT_EN            BIT(0)

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL3 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_RESERVED(x)          (((x) & 0xFF) << 16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_SSC_CTRL(x)          (((x) & 0xFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_IPPLL_CTRL4 */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_BIST_EN              BIT(16)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_BIST_CNT(x)          (((x) & 0xFFFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_ANA_PLL_RSVD */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_ANALOG_PLL_RESERVED(x)    (((x) & 0xFF))

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_PLL_TO_CSI_CLK_CRTL */

#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_CSI_TXBITCLK_SEL(x)       (((x) & 0x3) << 1)
#define BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_PLL_CK2CSI_EN             BIT(0)

/* REG_ANLG_PHY_G2_ANALOG_PLL_TOP_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_PD          BIT(25)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_RST         BIT(24)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_REF_SEL     BIT(23)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV7_EN     BIT(22)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV5_EN     BIT(21)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV3_EN     BIT(20)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV2_EN     BIT(19)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_DIV1_EN     BIT(18)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_TWPLL_CLKOUT_EN   BIT(17)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_PD           BIT(16)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_RST          BIT(15)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_REF_SEL      BIT(14)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV5_EN      BIT(13)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV3_EN      BIT(12)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV2_EN      BIT(11)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_DIV1_EN      BIT(10)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_LPLL_CLKOUT_EN    BIT(9)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_GPLL_PD           BIT(8)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_GPLL_RST          BIT(7)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_GPLL_CLKOUT_EN    BIT(6)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_PD           BIT(5)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_RST          BIT(4)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_DIV3_EN      BIT(3)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_DIV2_EN      BIT(2)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_DIV1_EN      BIT(1)
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_PLL_TOP_IPLL_CLKOUT_EN    BIT(0)


#endif /* ANLG_PHY_G2_H */


