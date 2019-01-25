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


#ifndef MEM_FW_AON_H
#define MEM_FW_AON_H

#define CTL_BASE_MEM_FW_AON 0x32801000


#define REG_MEM_FW_AON_PORT0_DEFAULT_R_ADDR_0  ( CTL_BASE_MEM_FW_AON + 0x0000 )
#define REG_MEM_FW_AON_PORT0_DEFAULT_W_ADDR_0  ( CTL_BASE_MEM_FW_AON + 0x0004 )
#define REG_MEM_FW_AON_CLK_GATE_BYPASS         ( CTL_BASE_MEM_FW_AON + 0x0100 )
#define REG_MEM_FW_AON_PORT_INT_W_EN           ( CTL_BASE_MEM_FW_AON + 0x0200 )
#define REG_MEM_FW_AON_PORT_INT_W_CLR          ( CTL_BASE_MEM_FW_AON + 0x0204 )
#define REG_MEM_FW_AON_PORT_INT_W_RAW          ( CTL_BASE_MEM_FW_AON + 0x0208 )
#define REG_MEM_FW_AON_PORT_INT_W_FIN          ( CTL_BASE_MEM_FW_AON + 0x020C )
#define REG_MEM_FW_AON_PORT_INT_R_EN           ( CTL_BASE_MEM_FW_AON + 0x0210 )
#define REG_MEM_FW_AON_PORT_INT_R_CLR          ( CTL_BASE_MEM_FW_AON + 0x0214 )
#define REG_MEM_FW_AON_PORT_INT_R_RAW          ( CTL_BASE_MEM_FW_AON + 0x0218 )
#define REG_MEM_FW_AON_PORT_INT_R_FIN          ( CTL_BASE_MEM_FW_AON + 0x021C )
#define REG_MEM_FW_AON_PORT_0_W_DEBUG_ADDR     ( CTL_BASE_MEM_FW_AON + 0x0400 )
#define REG_MEM_FW_AON_PORT_0_W_DEBUG_ID       ( CTL_BASE_MEM_FW_AON + 0x0404 )
#define REG_MEM_FW_AON_PORT_0_R_DEBUG_ADDR     ( CTL_BASE_MEM_FW_AON + 0x0408 )
#define REG_MEM_FW_AON_PORT_0_R_DEBUG_ID       ( CTL_BASE_MEM_FW_AON + 0x040C )
#define REG_MEM_FW_AON_SEG_DEFAULT_FIRST_ADDR  ( CTL_BASE_MEM_FW_AON + 0x0800 )
#define REG_MEM_FW_AON_SEG_DEFAULT_LAST_ADDR   ( CTL_BASE_MEM_FW_AON + 0x0804 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID0   ( CTL_BASE_MEM_FW_AON + 0x0808 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID1   ( CTL_BASE_MEM_FW_AON + 0x080C )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID2   ( CTL_BASE_MEM_FW_AON + 0x0810 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID3   ( CTL_BASE_MEM_FW_AON + 0x0814 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID4   ( CTL_BASE_MEM_FW_AON + 0x0818 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID5   ( CTL_BASE_MEM_FW_AON + 0x081C )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID6   ( CTL_BASE_MEM_FW_AON + 0x0820 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID7   ( CTL_BASE_MEM_FW_AON + 0x0824 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID0   ( CTL_BASE_MEM_FW_AON + 0x0828 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID1   ( CTL_BASE_MEM_FW_AON + 0x082C )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID2   ( CTL_BASE_MEM_FW_AON + 0x0830 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID3   ( CTL_BASE_MEM_FW_AON + 0x0834 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID4   ( CTL_BASE_MEM_FW_AON + 0x0838 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID5   ( CTL_BASE_MEM_FW_AON + 0x083C )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID6   ( CTL_BASE_MEM_FW_AON + 0x0840 )
#define REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID7   ( CTL_BASE_MEM_FW_AON + 0x0844 )
#define REG_MEM_FW_AON_SEG_0_FIRST_ADDR        ( CTL_BASE_MEM_FW_AON + 0x1000 )
#define REG_MEM_FW_AON_SEG_0_LAST_ADDR         ( CTL_BASE_MEM_FW_AON + 0x1004 )
#define REG_MEM_FW_AON_SEG_0_MST_R_ID0         ( CTL_BASE_MEM_FW_AON + 0x1008 )
#define REG_MEM_FW_AON_SEG_0_MST_R_ID1         ( CTL_BASE_MEM_FW_AON + 0x100C )
#define REG_MEM_FW_AON_SEG_0_MST_R_ID2         ( CTL_BASE_MEM_FW_AON + 0x1010 )
#define REG_MEM_FW_AON_SEG_0_MST_R_ID3         ( CTL_BASE_MEM_FW_AON + 0x1014 )
#define REG_MEM_FW_AON_SEG_0_MST_R_ID4         ( CTL_BASE_MEM_FW_AON + 0x1018 )
#define REG_MEM_FW_AON_SEG_0_MST_R_ID5         ( CTL_BASE_MEM_FW_AON + 0x101C )
#define REG_MEM_FW_AON_SEG_0_MST_R_ID6         ( CTL_BASE_MEM_FW_AON + 0x1020 )
#define REG_MEM_FW_AON_SEG_0_MST_R_ID7         ( CTL_BASE_MEM_FW_AON + 0x1024 )
#define REG_MEM_FW_AON_SEG_0_MST_W_ID0         ( CTL_BASE_MEM_FW_AON + 0x1028 )
#define REG_MEM_FW_AON_SEG_0_MST_W_ID1         ( CTL_BASE_MEM_FW_AON + 0x102C )
#define REG_MEM_FW_AON_SEG_0_MST_W_ID2         ( CTL_BASE_MEM_FW_AON + 0x1030 )
#define REG_MEM_FW_AON_SEG_0_MST_W_ID3         ( CTL_BASE_MEM_FW_AON + 0x1034 )
#define REG_MEM_FW_AON_SEG_0_MST_W_ID4         ( CTL_BASE_MEM_FW_AON + 0x1038 )
#define REG_MEM_FW_AON_SEG_0_MST_W_ID5         ( CTL_BASE_MEM_FW_AON + 0x103C )
#define REG_MEM_FW_AON_SEG_0_MST_W_ID6         ( CTL_BASE_MEM_FW_AON + 0x1040 )
#define REG_MEM_FW_AON_SEG_0_MST_W_ID7         ( CTL_BASE_MEM_FW_AON + 0x1044 )
#define REG_MEM_FW_AON_SEG_1_FIRST_ADDR        ( CTL_BASE_MEM_FW_AON + 0x1080 )
#define REG_MEM_FW_AON_SEG_1_LAST_ADDR         ( CTL_BASE_MEM_FW_AON + 0x1084 )
#define REG_MEM_FW_AON_SEG_1_MST_R_ID0         ( CTL_BASE_MEM_FW_AON + 0x1088 )
#define REG_MEM_FW_AON_SEG_1_MST_R_ID1         ( CTL_BASE_MEM_FW_AON + 0x108C )
#define REG_MEM_FW_AON_SEG_1_MST_R_ID2         ( CTL_BASE_MEM_FW_AON + 0x1090 )
#define REG_MEM_FW_AON_SEG_1_MST_R_ID3         ( CTL_BASE_MEM_FW_AON + 0x1094 )
#define REG_MEM_FW_AON_SEG_1_MST_R_ID4         ( CTL_BASE_MEM_FW_AON + 0x1098 )
#define REG_MEM_FW_AON_SEG_1_MST_R_ID5         ( CTL_BASE_MEM_FW_AON + 0x109C )
#define REG_MEM_FW_AON_SEG_1_MST_R_ID6         ( CTL_BASE_MEM_FW_AON + 0x10A0 )
#define REG_MEM_FW_AON_SEG_1_MST_R_ID7         ( CTL_BASE_MEM_FW_AON + 0x10A4 )
#define REG_MEM_FW_AON_SEG_1_MST_W_ID0         ( CTL_BASE_MEM_FW_AON + 0x10A8 )
#define REG_MEM_FW_AON_SEG_1_MST_W_ID1         ( CTL_BASE_MEM_FW_AON + 0x10AC )
#define REG_MEM_FW_AON_SEG_1_MST_W_ID2         ( CTL_BASE_MEM_FW_AON + 0x10B0 )
#define REG_MEM_FW_AON_SEG_1_MST_W_ID3         ( CTL_BASE_MEM_FW_AON + 0x10B4 )
#define REG_MEM_FW_AON_SEG_1_MST_W_ID4         ( CTL_BASE_MEM_FW_AON + 0x10B8 )
#define REG_MEM_FW_AON_SEG_1_MST_W_ID5         ( CTL_BASE_MEM_FW_AON + 0x10BC )
#define REG_MEM_FW_AON_SEG_1_MST_W_ID6         ( CTL_BASE_MEM_FW_AON + 0x10C0 )
#define REG_MEM_FW_AON_SEG_1_MST_W_ID7         ( CTL_BASE_MEM_FW_AON + 0x10C4 )
#define REG_MEM_FW_AON_SEG_2_FIRST_ADDR        ( CTL_BASE_MEM_FW_AON + 0x1100 )
#define REG_MEM_FW_AON_SEG_2_LAST_ADDR         ( CTL_BASE_MEM_FW_AON + 0x1104 )
#define REG_MEM_FW_AON_SEG_2_MST_R_ID0         ( CTL_BASE_MEM_FW_AON + 0x1108 )
#define REG_MEM_FW_AON_SEG_2_MST_R_ID1         ( CTL_BASE_MEM_FW_AON + 0x110C )
#define REG_MEM_FW_AON_SEG_2_MST_R_ID2         ( CTL_BASE_MEM_FW_AON + 0x1110 )
#define REG_MEM_FW_AON_SEG_2_MST_R_ID3         ( CTL_BASE_MEM_FW_AON + 0x1114 )
#define REG_MEM_FW_AON_SEG_2_MST_R_ID4         ( CTL_BASE_MEM_FW_AON + 0x1118 )
#define REG_MEM_FW_AON_SEG_2_MST_R_ID5         ( CTL_BASE_MEM_FW_AON + 0x111C )
#define REG_MEM_FW_AON_SEG_2_MST_R_ID6         ( CTL_BASE_MEM_FW_AON + 0x1120 )
#define REG_MEM_FW_AON_SEG_2_MST_R_ID7         ( CTL_BASE_MEM_FW_AON + 0x1124 )
#define REG_MEM_FW_AON_SEG_2_MST_W_ID0         ( CTL_BASE_MEM_FW_AON + 0x1128 )
#define REG_MEM_FW_AON_SEG_2_MST_W_ID1         ( CTL_BASE_MEM_FW_AON + 0x112C )
#define REG_MEM_FW_AON_SEG_2_MST_W_ID2         ( CTL_BASE_MEM_FW_AON + 0x1130 )
#define REG_MEM_FW_AON_SEG_2_MST_W_ID3         ( CTL_BASE_MEM_FW_AON + 0x1134 )
#define REG_MEM_FW_AON_SEG_2_MST_W_ID4         ( CTL_BASE_MEM_FW_AON + 0x1138 )
#define REG_MEM_FW_AON_SEG_2_MST_W_ID5         ( CTL_BASE_MEM_FW_AON + 0x113C )
#define REG_MEM_FW_AON_SEG_2_MST_W_ID6         ( CTL_BASE_MEM_FW_AON + 0x1140 )
#define REG_MEM_FW_AON_SEG_2_MST_W_ID7         ( CTL_BASE_MEM_FW_AON + 0x1144 )
#define REG_MEM_FW_AON_SEG_3_FIRST_ADDR        ( CTL_BASE_MEM_FW_AON + 0x1180 )
#define REG_MEM_FW_AON_SEG_3_LAST_ADDR         ( CTL_BASE_MEM_FW_AON + 0x1184 )
#define REG_MEM_FW_AON_SEG_3_MST_R_ID0         ( CTL_BASE_MEM_FW_AON + 0x1188 )
#define REG_MEM_FW_AON_SEG_3_MST_R_ID1         ( CTL_BASE_MEM_FW_AON + 0x118C )
#define REG_MEM_FW_AON_SEG_3_MST_R_ID2         ( CTL_BASE_MEM_FW_AON + 0x1190 )
#define REG_MEM_FW_AON_SEG_3_MST_R_ID3         ( CTL_BASE_MEM_FW_AON + 0x1194 )
#define REG_MEM_FW_AON_SEG_3_MST_R_ID4         ( CTL_BASE_MEM_FW_AON + 0x1198 )
#define REG_MEM_FW_AON_SEG_3_MST_R_ID5         ( CTL_BASE_MEM_FW_AON + 0x119C )
#define REG_MEM_FW_AON_SEG_3_MST_R_ID6         ( CTL_BASE_MEM_FW_AON + 0x11A0 )
#define REG_MEM_FW_AON_SEG_3_MST_R_ID7         ( CTL_BASE_MEM_FW_AON + 0x11A4 )
#define REG_MEM_FW_AON_SEG_3_MST_W_ID0         ( CTL_BASE_MEM_FW_AON + 0x11A8 )
#define REG_MEM_FW_AON_SEG_3_MST_W_ID1         ( CTL_BASE_MEM_FW_AON + 0x11AC )
#define REG_MEM_FW_AON_SEG_3_MST_W_ID2         ( CTL_BASE_MEM_FW_AON + 0x11B0 )
#define REG_MEM_FW_AON_SEG_3_MST_W_ID3         ( CTL_BASE_MEM_FW_AON + 0x11B4 )
#define REG_MEM_FW_AON_SEG_3_MST_W_ID4         ( CTL_BASE_MEM_FW_AON + 0x11B8 )
#define REG_MEM_FW_AON_SEG_3_MST_W_ID5         ( CTL_BASE_MEM_FW_AON + 0x11BC )
#define REG_MEM_FW_AON_SEG_3_MST_W_ID6         ( CTL_BASE_MEM_FW_AON + 0x11C0 )
#define REG_MEM_FW_AON_SEG_3_MST_W_ID7         ( CTL_BASE_MEM_FW_AON + 0x11C4 )

/* REG_MEM_FW_AON_PORT0_DEFAULT_R_ADDR_0 */

#define BIT_MEM_FW_AON_PORT0_DEFAULT_R_ADDR_0_PORT0_DEFAULT_R_ADDR_0(x)  (((x) & 0x3F))

/* REG_MEM_FW_AON_PORT0_DEFAULT_W_ADDR_0 */

#define BIT_MEM_FW_AON_PORT0_DEFAULT_W_ADDR_0_PORT0_DEFAULT_W_ADDR_0(x)  (((x) & 0x3F))

/* REG_MEM_FW_AON_CLK_GATE_BYPASS */

#define BIT_MEM_FW_AON_CLK_GATE_BYPASS_CLK_GATE_BYPASS                   BIT(0)

/* REG_MEM_FW_AON_PORT_INT_W_EN */

#define BIT_MEM_FW_AON_PORT_INT_W_EN_PORT_0_W_EN                         BIT(0)

/* REG_MEM_FW_AON_PORT_INT_W_CLR */

#define BIT_MEM_FW_AON_PORT_INT_W_CLR_PORT_0_W_CLR                       BIT(0)

/* REG_MEM_FW_AON_PORT_INT_W_RAW */

#define BIT_MEM_FW_AON_PORT_INT_W_RAW_PORT_0_W_RAW                       BIT(0)

/* REG_MEM_FW_AON_PORT_INT_W_FIN */

#define BIT_MEM_FW_AON_PORT_INT_W_FIN_PORT_0_W_FIN                       BIT(0)

/* REG_MEM_FW_AON_PORT_INT_R_EN */

#define BIT_MEM_FW_AON_PORT_INT_R_EN_PORT_0_R_EN                         BIT(0)

/* REG_MEM_FW_AON_PORT_INT_R_CLR */

#define BIT_MEM_FW_AON_PORT_INT_R_CLR_PORT_0_R_CLR                       BIT(0)

/* REG_MEM_FW_AON_PORT_INT_R_RAW */

#define BIT_MEM_FW_AON_PORT_INT_R_RAW_PORT_0_R_RAW                       BIT(0)

/* REG_MEM_FW_AON_PORT_INT_R_FIN */

#define BIT_MEM_FW_AON_PORT_INT_R_FIN_PORT_0_R_FIN                       BIT(0)

/* REG_MEM_FW_AON_PORT_0_W_DEBUG_ADDR */

#define BIT_MEM_FW_AON_PORT_0_W_DEBUG_ADDR_W_ADDR_0(x)                   (((x) & 0x3F))

/* REG_MEM_FW_AON_PORT_0_W_DEBUG_ID */

#define BIT_MEM_FW_AON_PORT_0_W_DEBUG_ID_W_ID_0(x)                       (((x) & 0xFF))

/* REG_MEM_FW_AON_PORT_0_R_DEBUG_ADDR */

#define BIT_MEM_FW_AON_PORT_0_R_DEBUG_ADDR_R_ADDR_0(x)                   (((x) & 0x3F))

/* REG_MEM_FW_AON_PORT_0_R_DEBUG_ID */

#define BIT_MEM_FW_AON_PORT_0_R_DEBUG_ID_R_ID_0(x)                       (((x) & 0xFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_FIRST_ADDR */

#define BIT_MEM_FW_AON_SEG_DEFAULT_FIRST_ADDR_FIRST_ADDR(x)              (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_LAST_ADDR */

#define BIT_MEM_FW_AON_SEG_DEFAULT_LAST_ADDR_LAST_ADDR(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID0 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_R_ID0_MST_R_ID0(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID1 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_R_ID1_MST_R_ID1(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID2 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_R_ID2_MST_R_ID2(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID3 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_R_ID3_MST_R_ID3(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID4 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_R_ID4_MST_R_ID4(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID5 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_R_ID5_MST_R_ID5(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID6 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_R_ID6_MST_R_ID6(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_R_ID7 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_R_ID7_MST_R_ID7(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID0 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_W_ID0_MST_W_ID0(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID1 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_W_ID1_MST_W_ID1(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID2 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_W_ID2_MST_W_ID2(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID3 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_W_ID3_MST_W_ID3(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID4 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_W_ID4_MST_W_ID4(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID5 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_W_ID5_MST_W_ID5(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID6 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_W_ID6_MST_W_ID6(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_DEFAULT_MST_W_ID7 */

#define BIT_MEM_FW_AON_SEG_DEFAULT_MST_W_ID7_MST_W_ID7(x)                (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_FIRST_ADDR */

#define BIT_MEM_FW_AON_SEG_0_FIRST_ADDR_FIRST_ADDR(x)                    (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_LAST_ADDR */

#define BIT_MEM_FW_AON_SEG_0_LAST_ADDR_LAST_ADDR(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_R_ID0 */

#define BIT_MEM_FW_AON_SEG_0_MST_R_ID0_MST_R_ID0(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_R_ID1 */

#define BIT_MEM_FW_AON_SEG_0_MST_R_ID1_MST_R_ID1(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_R_ID2 */

#define BIT_MEM_FW_AON_SEG_0_MST_R_ID2_MST_R_ID2(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_R_ID3 */

#define BIT_MEM_FW_AON_SEG_0_MST_R_ID3_MST_R_ID3(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_R_ID4 */

#define BIT_MEM_FW_AON_SEG_0_MST_R_ID4_MST_R_ID4(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_R_ID5 */

#define BIT_MEM_FW_AON_SEG_0_MST_R_ID5_MST_R_ID5(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_R_ID6 */

#define BIT_MEM_FW_AON_SEG_0_MST_R_ID6_MST_R_ID6(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_R_ID7 */

#define BIT_MEM_FW_AON_SEG_0_MST_R_ID7_MST_R_ID7(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_W_ID0 */

#define BIT_MEM_FW_AON_SEG_0_MST_W_ID0_MST_W_ID0(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_W_ID1 */

#define BIT_MEM_FW_AON_SEG_0_MST_W_ID1_MST_W_ID1(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_W_ID2 */

#define BIT_MEM_FW_AON_SEG_0_MST_W_ID2_MST_W_ID2(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_W_ID3 */

#define BIT_MEM_FW_AON_SEG_0_MST_W_ID3_MST_W_ID3(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_W_ID4 */

#define BIT_MEM_FW_AON_SEG_0_MST_W_ID4_MST_W_ID4(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_W_ID5 */

#define BIT_MEM_FW_AON_SEG_0_MST_W_ID5_MST_W_ID5(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_W_ID6 */

#define BIT_MEM_FW_AON_SEG_0_MST_W_ID6_MST_W_ID6(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_0_MST_W_ID7 */

#define BIT_MEM_FW_AON_SEG_0_MST_W_ID7_MST_W_ID7(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_FIRST_ADDR */

#define BIT_MEM_FW_AON_SEG_1_FIRST_ADDR_FIRST_ADDR(x)                    (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_LAST_ADDR */

#define BIT_MEM_FW_AON_SEG_1_LAST_ADDR_LAST_ADDR(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_R_ID0 */

#define BIT_MEM_FW_AON_SEG_1_MST_R_ID0_MST_R_ID0(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_R_ID1 */

#define BIT_MEM_FW_AON_SEG_1_MST_R_ID1_MST_R_ID1(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_R_ID2 */

#define BIT_MEM_FW_AON_SEG_1_MST_R_ID2_MST_R_ID2(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_R_ID3 */

#define BIT_MEM_FW_AON_SEG_1_MST_R_ID3_MST_R_ID3(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_R_ID4 */

#define BIT_MEM_FW_AON_SEG_1_MST_R_ID4_MST_R_ID4(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_R_ID5 */

#define BIT_MEM_FW_AON_SEG_1_MST_R_ID5_MST_R_ID5(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_R_ID6 */

#define BIT_MEM_FW_AON_SEG_1_MST_R_ID6_MST_R_ID6(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_R_ID7 */

#define BIT_MEM_FW_AON_SEG_1_MST_R_ID7_MST_R_ID7(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_W_ID0 */

#define BIT_MEM_FW_AON_SEG_1_MST_W_ID0_MST_W_ID0(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_W_ID1 */

#define BIT_MEM_FW_AON_SEG_1_MST_W_ID1_MST_W_ID1(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_W_ID2 */

#define BIT_MEM_FW_AON_SEG_1_MST_W_ID2_MST_W_ID2(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_W_ID3 */

#define BIT_MEM_FW_AON_SEG_1_MST_W_ID3_MST_W_ID3(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_W_ID4 */

#define BIT_MEM_FW_AON_SEG_1_MST_W_ID4_MST_W_ID4(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_W_ID5 */

#define BIT_MEM_FW_AON_SEG_1_MST_W_ID5_MST_W_ID5(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_W_ID6 */

#define BIT_MEM_FW_AON_SEG_1_MST_W_ID6_MST_W_ID6(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_1_MST_W_ID7 */

#define BIT_MEM_FW_AON_SEG_1_MST_W_ID7_MST_W_ID7(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_FIRST_ADDR */

#define BIT_MEM_FW_AON_SEG_2_FIRST_ADDR_FIRST_ADDR(x)                    (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_LAST_ADDR */

#define BIT_MEM_FW_AON_SEG_2_LAST_ADDR_LAST_ADDR(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_R_ID0 */

#define BIT_MEM_FW_AON_SEG_2_MST_R_ID0_MST_R_ID0(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_R_ID1 */

#define BIT_MEM_FW_AON_SEG_2_MST_R_ID1_MST_R_ID1(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_R_ID2 */

#define BIT_MEM_FW_AON_SEG_2_MST_R_ID2_MST_R_ID2(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_R_ID3 */

#define BIT_MEM_FW_AON_SEG_2_MST_R_ID3_MST_R_ID3(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_R_ID4 */

#define BIT_MEM_FW_AON_SEG_2_MST_R_ID4_MST_R_ID4(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_R_ID5 */

#define BIT_MEM_FW_AON_SEG_2_MST_R_ID5_MST_R_ID5(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_R_ID6 */

#define BIT_MEM_FW_AON_SEG_2_MST_R_ID6_MST_R_ID6(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_R_ID7 */

#define BIT_MEM_FW_AON_SEG_2_MST_R_ID7_MST_R_ID7(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_W_ID0 */

#define BIT_MEM_FW_AON_SEG_2_MST_W_ID0_MST_W_ID0(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_W_ID1 */

#define BIT_MEM_FW_AON_SEG_2_MST_W_ID1_MST_W_ID1(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_W_ID2 */

#define BIT_MEM_FW_AON_SEG_2_MST_W_ID2_MST_W_ID2(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_W_ID3 */

#define BIT_MEM_FW_AON_SEG_2_MST_W_ID3_MST_W_ID3(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_W_ID4 */

#define BIT_MEM_FW_AON_SEG_2_MST_W_ID4_MST_W_ID4(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_W_ID5 */

#define BIT_MEM_FW_AON_SEG_2_MST_W_ID5_MST_W_ID5(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_W_ID6 */

#define BIT_MEM_FW_AON_SEG_2_MST_W_ID6_MST_W_ID6(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_2_MST_W_ID7 */

#define BIT_MEM_FW_AON_SEG_2_MST_W_ID7_MST_W_ID7(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_FIRST_ADDR */

#define BIT_MEM_FW_AON_SEG_3_FIRST_ADDR_FIRST_ADDR(x)                    (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_LAST_ADDR */

#define BIT_MEM_FW_AON_SEG_3_LAST_ADDR_LAST_ADDR(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_R_ID0 */

#define BIT_MEM_FW_AON_SEG_3_MST_R_ID0_MST_R_ID0(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_R_ID1 */

#define BIT_MEM_FW_AON_SEG_3_MST_R_ID1_MST_R_ID1(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_R_ID2 */

#define BIT_MEM_FW_AON_SEG_3_MST_R_ID2_MST_R_ID2(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_R_ID3 */

#define BIT_MEM_FW_AON_SEG_3_MST_R_ID3_MST_R_ID3(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_R_ID4 */

#define BIT_MEM_FW_AON_SEG_3_MST_R_ID4_MST_R_ID4(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_R_ID5 */

#define BIT_MEM_FW_AON_SEG_3_MST_R_ID5_MST_R_ID5(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_R_ID6 */

#define BIT_MEM_FW_AON_SEG_3_MST_R_ID6_MST_R_ID6(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_R_ID7 */

#define BIT_MEM_FW_AON_SEG_3_MST_R_ID7_MST_R_ID7(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_W_ID0 */

#define BIT_MEM_FW_AON_SEG_3_MST_W_ID0_MST_W_ID0(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_W_ID1 */

#define BIT_MEM_FW_AON_SEG_3_MST_W_ID1_MST_W_ID1(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_W_ID2 */

#define BIT_MEM_FW_AON_SEG_3_MST_W_ID2_MST_W_ID2(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_W_ID3 */

#define BIT_MEM_FW_AON_SEG_3_MST_W_ID3_MST_W_ID3(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_W_ID4 */

#define BIT_MEM_FW_AON_SEG_3_MST_W_ID4_MST_W_ID4(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_W_ID5 */

#define BIT_MEM_FW_AON_SEG_3_MST_W_ID5_MST_W_ID5(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_W_ID6 */

#define BIT_MEM_FW_AON_SEG_3_MST_W_ID6_MST_W_ID6(x)                      (((x) & 0xFFFFFFFF))

/* REG_MEM_FW_AON_SEG_3_MST_W_ID7 */

#define BIT_MEM_FW_AON_SEG_3_MST_W_ID7_MST_W_ID7(x)                      (((x) & 0xFFFFFFFF))


#endif /* MEM_FW_AON_H */


