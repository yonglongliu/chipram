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


#ifndef MASTER_CTRL_AON_H
#define MASTER_CTRL_AON_H

#define CTL_BASE_MASTER_CTRL_AON 0x32803000


#define REG_MASTER_CTRL_AON_RD_SEC_0  ( CTL_BASE_MASTER_CTRL_AON + 0x0000 )
#define REG_MASTER_CTRL_AON_WR_SEC_0  ( CTL_BASE_MASTER_CTRL_AON + 0x0004 )

/* REG_MASTER_CTRL_AON_RD_SEC_0 */

#define BIT_MASTER_CTRL_AON_RD_SEC_0_CM4_RD_SEC           BIT(22)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_USBOTG_RD_SEC        BIT(21)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_PUBCP_AON_RD_SEC     BIT(20)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_WTLCP_AON_RD_SEC     BIT(19)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_AUDCP_AON_RD_SEC     BIT(18)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_PUBCP_DDR_RD_SEC(x)  (((x) & 0x3) << 16)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_WTLCP_DDR_RD_SEC(x)  (((x) & 0x3) << 14)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_AUDCP_DDR_RD_SEC(x)  (((x) & 0x3) << 12)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_DCAM_MM_RD_SEC(x)    (((x) & 0x3) << 10)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_ISP_MM_RD_SEC(x)     (((x) & 0x3) << 8)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_JPG_MM_RD_SEC(x)     (((x) & 0x3) << 6)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_CPP_MM_RD_SEC(x)     (((x) & 0x3) << 4)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_GPU_RD_SEC(x)        (((x) & 0x3) << 2)
#define BIT_MASTER_CTRL_AON_RD_SEC_0_ETR_RD_SEC(x)        (((x) & 0x3))

/* REG_MASTER_CTRL_AON_WR_SEC_0 */

#define BIT_MASTER_CTRL_AON_WR_SEC_0_CM4_WR_SEC           BIT(22)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_USBOTG_WR_SEC        BIT(21)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_PUBCP_AON_WR_SEC     BIT(20)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_WTLCP_AON_WR_SEC     BIT(19)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_AUDCP_AON_WR_SEC     BIT(18)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_PUBCP_DDR_WR_SEC(x)  (((x) & 0x3) << 16)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_WTLCP_DDR_WR_SEC(x)  (((x) & 0x3) << 14)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_AUDCP_DDR_WR_SEC(x)  (((x) & 0x3) << 12)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_DCAM_MM_WR_SEC(x)    (((x) & 0x3) << 10)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_ISP_MM_WR_SEC(x)     (((x) & 0x3) << 8)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_JPG_MM_WR_SEC(x)     (((x) & 0x3) << 6)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_CPP_MM_WR_SEC(x)     (((x) & 0x3) << 4)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_GPU_WR_SEC(x)        (((x) & 0x3) << 2)
#define BIT_MASTER_CTRL_AON_WR_SEC_0_ETR_WR_SEC(x)        (((x) & 0x3))


#endif /* MASTER_CTRL_AON_H */


