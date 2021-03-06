
#ifndef _SC9630_REG_DEF_H_
#define _SC9630_REG_DEF_H_

#ifndef BIT
#define BIT(x) (1<<x)
#endif

#include <config.h>
#include "hardware.h"
#include <power/pmic_glb_reg.h>
#if defined CONFIG_SPX15
#include "chip_x15/__regs_ap_apb.h"
#include "chip_x15/__regs_ap_ahb.h"
#include "chip_x15/__regs_ap_clk.h"
#include "chip_x15/__regs_mm_ahb_rf.h"
#include "chip_x15/__regs_mm_clk.h"
#include "chip_x15/__regs_gpu_apb.h"
#include "chip_x15/__regs_gpu_clk.h"
#include "chip_x15/__regs_aon_apb.h"
#include "chip_x15/__regs_aon_ckg.h"
#include "chip_x15/__regs_aon_clk.h"
#include "chip_x15/__regs_pmu_apb.h"
#include "chip_x15/__regs_pub_apb.h"
#elif defined(CONFIG_ARCH_SCX35LT8)
#include "chip_x35lt8/__regs_ap_apb.h"
#include "chip_x35lt8/__regs_ap_ahb_rf.h"
#include "chip_x35lt8/__regs_ap_clk.h"
#include "chip_x35lt8/__regs_mm_ahb_rf.h"
#include "chip_x35lt8/__regs_mm_clk.h"
#include "chip_x35lt8/__regs_gpu_apb_rf.h"
#include "chip_x35lt8/__regs_gpu_clk.h"
#include "chip_x35lt8/__regs_aon_apb_rf.h"
#include "chip_x35lt8/__regs_aon_ckg.h"
#include "chip_x35lt8/__regs_aon_clk.h"
#include "chip_x35lt8/__regs_pmu_apb_rf.h"
#include "chip_x35lt8/__regs_pub_apb.h"
#include "chip_x35lt8/sprd_reg_base.h"
#elif defined(CONFIG_ARCH_SCX35L64)
#include "chip_x35l64/__regs_ap_apb.h"
#include "chip_x35l64/__regs_ap_ahb_rf.h"
#include "chip_x35l64/__regs_ap_clk.h"
#include "chip_x35l64/__regs_mm_ahb_rf.h"
#include "chip_x35l64/__regs_mm_clk.h"
#include "chip_x35l64/__regs_gpu_apb_rf.h"
#include "chip_x35l64/__regs_gpu_clk.h"
#include "chip_x35l64/__regs_aon_apb_rf.h"
#include "chip_x35l64/__regs_aon_ckg.h"
#include "chip_x35l64/__regs_aon_clk.h"
#include "chip_x35l64/__regs_pmu_apb_rf.h"
#include "chip_x35l64/__regs_pub_apb.h"
#include "chip_x35l64/sprd_reg_base.h"
#elif defined(CONFIG_SOC_PIKE2)
		#include "chip_pike2/aon_apb.h"
		#include "chip_pike2/aon_sec_apb.h"
		#include "chip_pike2/ap_ahb.h"
		#include "chip_pike2/ap_apb.h"
		#include "chip_pike2/pmu_apb.h"
		#include "chip_pike2/serdes_apb.h"
		#include "chip_pike2/sp_ahb.h"
		#include "chip_pike2/aon_clk_core.h"
		#include "chip_pike2/ap_clk_core.h"
		#include "chip_pike2/ca7_clk_core.h"
#elif defined(CONFIG_ARCH_SCX35L)
	#if defined(CONFIG_ARCH_SCX20L)
		#include "chip_x20l/__regs_ap_apb.h"
		#include "chip_x20l/__regs_ap_ahb_rf.h"
		#include "chip_x20l/__regs_ap_clk.h"
		#include "chip_x20l/__regs_mm_ahb_rf.h"
		#include "chip_x20l/__regs_mm_clk.h"
		#include "chip_x20l/__regs_gpu_apb_rf.h"
		#include "chip_x20l/__regs_gpu_clk.h"
		#include "chip_x20l/__regs_aon_apb_rf.h"
		#include "chip_x20l/__regs_aon_ckg.h"
		#include "chip_x20l/__regs_aon_clk.h"
		#include "chip_x20l/__regs_pmu_apb_rf.h"
		#include "chip_x20l/__regs_pub_apb.h"
		#include "chip_x20l/sprd_reg_base.h"
	#elif (defined CONFIG_ARCH_SCX35L2)
		#include "chip_x35l2/__regs_anlg_phy_g1.h"
		#include "chip_x35l2/__regs_anlg_phy_g2.h"
		#include "chip_x35l2/__regs_anlg_phy_g3.h"
		#include "chip_x35l2/__regs_anlg_phy_g5.h"
		#include "chip_x35l2/__regs_aon_apb.h"
		#include "chip_x35l2/__regs_aon_clk.h"
		#include "chip_x35l2/__regs_aon_sec_apb.h"
		#include "chip_x35l2/__regs_ap_ahb.h"
		#include "chip_x35l2/__regs_ap_apb.h"
		#include "chip_x35l2/__regs_ap_clk.h"
		#include "chip_x35l2/__regs_arm7_ahb.h"
		#include "chip_x35l2/__regs_gpu_apb.h"
		#include "chip_x35l2/__regs_mm_ahb_rf.h"
		#include "chip_x35l2/__regs_mm_clk.h"
		#include "chip_x35l2/__regs_pmu_apb.h"
		#include "chip_x35l2/__regs_pub_ahb.h"
		#include "chip_x35l2/__regs_serdes_apb.h"
		#include "chip_x35l2/redefine.h"
	#else
		#include "chip_x35l/__regs_ap_apb.h"
		#include "chip_x35l/__regs_ap_ahb_rf.h"
		#include "chip_x35l/__regs_ap_clk.h"
		#include "chip_x35l/__regs_mm_ahb_rf.h"
		#include "chip_x35l/__regs_mm_clk.h"
		#include "chip_x35l/__regs_gpu_apb_rf.h"
		#include "chip_x35l/__regs_gpu_clk.h"
		#include "chip_x35l/__regs_aon_apb_rf.h"
		#include "chip_x35l/__regs_aon_ckg.h"
		#include "chip_x35l/__regs_aon_clk.h"
		#include "chip_x35l/__regs_pmu_apb_rf.h"
		#include "chip_x35l/__regs_pub_apb.h"
		#include "chip_x35l/sprd_reg_base.h"
	#endif

#else
#include "chip_x35/sprd_reg_ap_apb.h"
#include "chip_x35/sprd_reg_ap_ahb.h"
#include "chip_x35/sprd_reg_ap_clk.h"
#include "chip_x35/sprd_reg_mm_ahb.h"
#include "chip_x35/sprd_reg_mm_clk.h"
#include "chip_x35/sprd_reg_gpu_apb.h"
#include "chip_x35/sprd_reg_gpu_clk.h"
#include "chip_x35/sprd_reg_aon_apb.h"
#include "chip_x35/sprd_reg_aon_ckg.h"
#include "chip_x35/sprd_reg_aon_clk.h"
#include "chip_x35/sprd_reg_pmu_apb.h"
#include "chip_x35/sprd_reg_pub_apb.h"
#include "chip_x35/sprd_reg_base.h"
#endif

#endif /*_SC9630_REG_DEF_H_*/

