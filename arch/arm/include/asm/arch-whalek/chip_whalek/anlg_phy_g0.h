/*
 * Copyright (C) 2017 Spreadtrum Communications Inc.
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 * updated at 2017-12-14 16:29:52
 *
 */


#ifndef ANLG_PHY_G0_H
#define ANLG_PHY_G0_H

#define CTL_BASE_ANLG_PHY_G0 0x32390000


#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_ANA_DPLL_DUMY      ( CTL_BASE_ANLG_PHY_G0 + 0x0000 )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL0         ( CTL_BASE_ANLG_PHY_G0 + 0x0004 )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL1         ( CTL_BASE_ANLG_PHY_G0 + 0x0008 )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL2         ( CTL_BASE_ANLG_PHY_G0 + 0x000C )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL3         ( CTL_BASE_ANLG_PHY_G0 + 0x0010 )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL4         ( CTL_BASE_ANLG_PHY_G0 + 0x0014 )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL5         ( CTL_BASE_ANLG_PHY_G0 + 0x0018 )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL13        ( CTL_BASE_ANLG_PHY_G0 + 0x001C )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL6         ( CTL_BASE_ANLG_PHY_G0 + 0x0020 )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL7         ( CTL_BASE_ANLG_PHY_G0 + 0x0024 )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL8         ( CTL_BASE_ANLG_PHY_G0 + 0x0028 )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL9         ( CTL_BASE_ANLG_PHY_G0 + 0x002C )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL14        ( CTL_BASE_ANLG_PHY_G0 + 0x0030 )
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_REG_SEL_CFG_0      ( CTL_BASE_ANLG_PHY_G0 + 0x0034 )

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_ANA_DPLL_DUMY */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_ANALOG_DPLL_DUMY_IN(x)    (((x) & 0xFFFF) << 16)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_ANALOG_DPLL_DUMY_OUT(x)   (((x) & 0xFFFF))

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL0 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_PD                  BIT(19)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_RST                 BIT(18)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CLKOUT_EN           BIT(17)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_DIV_SEL(x)          (((x) & 0xF) << 13)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_DIV32_EN            BIT(12)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_PD                  BIT(11)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_RST                 BIT(10)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CLKOUT_EN           BIT(9)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_DIV_SEL(x)          (((x) & 0xF) << 5)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_DIV32_EN            BIT(4)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_LOCK_DONE           BIT(3)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_LOCK_DONE           BIT(2)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CALI_MODE(x)        (((x) & 0x3))

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL1 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CALI_INI(x)         (((x) & 0x1F) << 26)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CALI_TRIG           BIT(25)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_FREQ_DIFF_EN        BIT(24)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CALI_WAITCNT(x)     (((x) & 0x3) << 22)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CALI_POLARITY       BIT(21)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_VCTRLH_SEL(x)       (((x) & 0x7) << 18)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_VCTRLL_SEL(x)       (((x) & 0x7) << 15)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_VCO_BANK_SEL(x)     (((x) & 0x1F) << 10)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_FREQ_DOUBLE_EN      BIT(9)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_RG_CLOSELOOP_EN     BIT(8)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CALI_DONE           BIT(7)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_VCTRL_HIGH          BIT(6)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_VCTRL_LOW           BIT(5)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CALI_OUT(x)         (((x) & 0x1F))

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL2 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CALI_CPPD           BIT(24)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CP_OFFSET(x)        (((x) & 0x3) << 22)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CP_EN               BIT(21)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_LDO_TRIM(x)         (((x) & 0xF) << 17)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_R2_SEL(x)           (((x) & 0x3) << 15)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_R3_SEL(x)           (((x) & 0x3) << 13)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_C1_SEL(x)           (((x) & 0x3) << 11)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_C2_SEL(x)           (((x) & 0x3) << 9)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_KVCO_SEL(x)         (((x) & 0x3) << 7)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_VCO_TEST_EN         BIT(6)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_VCO_TEST_INT        BIT(5)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_VCO_TEST_INTSEL(x)  (((x) & 0x7) << 2)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_FBDIV_EN            BIT(1)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_VCOBUF_EN           BIT(0)

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL3 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_N(x)                (((x) & 0x7FF) << 3)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_ICP(x)              (((x) & 0x7))

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL4 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_NINT(x)             (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_KINT(x)             (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL5 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_SDM_EN              BIT(19)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CCS_CTRL(x)         (((x) & 0xFF) << 11)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_MOD_EN              BIT(10)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_DIV_S               BIT(9)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_RESERVED(x)         (((x) & 0xFF) << 1)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_BIST_EN             BIT(0)

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL13 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_IL_DIV              BIT(25)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_BIST_CNT(x)         (((x) & 0xFFFF) << 9)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CALI_MODE(x)        (((x) & 0x3) << 7)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CALI_INI(x)         (((x) & 0x1F) << 2)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CALI_TRIG           BIT(1)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_FREQ_DIFF_EN        BIT(0)

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL6 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CALI_WAITCNT(x)     (((x) & 0x3) << 30)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CALI_POLARITY       BIT(29)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_VCTRLH_SEL(x)       (((x) & 0x7) << 26)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_VCTRLL_SEL(x)       (((x) & 0x7) << 23)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_VCO_BANK_SEL(x)     (((x) & 0x1F) << 18)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_FREQ_DOUBLE_EN      BIT(17)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_RG_CLOSELOOP_EN     BIT(16)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CALI_DONE           BIT(15)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_VCTRL_HIGH          BIT(14)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_VCTRL_LOW           BIT(13)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CALI_OUT(x)         (((x) & 0x1F) << 8)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CALI_CPPD           BIT(7)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CP_OFFSET(x)        (((x) & 0x3) << 5)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CP_EN               BIT(4)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_LDO_TRIM(x)         (((x) & 0xF))

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL7 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_R2_SEL(x)           (((x) & 0x3) << 29)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_R3_SEL(x)           (((x) & 0x3) << 27)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_C1_SEL(x)           (((x) & 0x3) << 25)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_C2_SEL(x)           (((x) & 0x3) << 23)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_KVCO_SEL(x)         (((x) & 0x3) << 21)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_VCO_TEST_EN         BIT(20)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_VCO_TEST_INT        BIT(19)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_VCO_TEST_INTSEL(x)  (((x) & 0x7) << 16)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_FBDIV_EN            BIT(15)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_VCOBUF_EN           BIT(14)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_N(x)                (((x) & 0x7FF) << 3)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_ICP(x)              (((x) & 0x7))

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL8 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_NINT(x)             (((x) & 0x7F) << 23)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_KINT(x)             (((x) & 0x7FFFFF))

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL9 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_SDM_EN              BIT(18)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_CCS_CTRL(x)         (((x) & 0xFF) << 10)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_MOD_EN              BIT(9)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_DIV_S               BIT(8)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_RESERVED(x)         (((x) & 0xFF))

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL14 */

#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_BIST_EN             BIT(17)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_IL_DIV              BIT(16)
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL1_BIST_CNT(x)         (((x) & 0xFFFF))

/* REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_REG_SEL_CFG_0 */

#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL0_PD          BIT(8)
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL0_RST         BIT(7)
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL0_CLKOUT_EN   BIT(6)
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL0_DIV_SEL     BIT(5)
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL0_DIV32_EN    BIT(4)
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL1_PD          BIT(3)
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL1_RST         BIT(2)
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL1_CLKOUT_EN   BIT(1)
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL1_DIV32_EN    BIT(0)


#endif /* ANLG_PHY_G0_H */

