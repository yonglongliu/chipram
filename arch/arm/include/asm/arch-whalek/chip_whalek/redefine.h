/*
 * Copyright (C) 2017 Spreadtrum Communications Inc.
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 */


#ifndef _REDEFINE_H
#define _REDEFINE_H

/* macro definition for compatible */

/* referenced by mmc_v40.c */
#define AON_CLK_FREQ_26M                        (0x1)
#define AON_CLK_FREQ_384M       0X02
#define BIT_AON_APB_EFUSE_NORMAL_EB		BIT_AON_APB_EFUSE_EB
/* bit redefinition for compatible */

/* referenced by efuse.c */
#define BIT_EFUSE_SOFT_RST                      BIT_AON_APB_EFUSE_SOFT_RST
#define BIT_EFUSE_EB                            BIT_AON_APB_EFUSE_NORMAL_EB

/* referenced by adi.c */
#define BIT_ADI_SOFT_RST                        BIT_AON_APB_ADI_SOFT_RST
#define BIT_ADI_EB                              BIT_AON_APB_ADI_EB

/* referenced by mmc_v40.c */
#define BIT_AP_AHB_EMMC_EB			BIT_AP_APB_EMMC_EB
#define BIT_AP_AHB_EMMC_SOFT_RST		BIT_AP_APB_EMMC_SOFT_RST
#define BIT_AP_AHB_SDIO0_EB			BIT_AP_APB_SDIO0_EB
#define BIT_AP_AHB_SDIO0_SOFT_RST		BIT_AP_APB_SDIO0_SOFT_RST

/* referenced by timer.c */
#define BIT_AON_TMR_26M_EB			BIT_AON_APB_CGM_TMR_EN

/* referenced by aon_apb.h */
#define REG_AON_APB_APB_RTC_EB			REG_AON_APB_APB_RTC_EB0

/* register redefiniton for compatible */

/* referenced by mmc_v40.c */
#define AON_SDIO0_CLK_2X_CFG                    0x80
#define AON_EMMC_CLK_2X_CFG                     0x90

/* referemced by timer.c */
#define REG_AON_TMR_CLK_EN			REG_AON_APB_APB_EB1
#define REG_AON_TMR_CLK_RTC_EN			REG_AON_APB_APB_RTC_EB0
#define REG_AON_TMR_26M_EN			REG_AON_APB_CGM_REG1
#endif
