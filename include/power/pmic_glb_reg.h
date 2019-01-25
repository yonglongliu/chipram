/*
 * Copyright (C) 2014-2015 Spreadtrum Communications Inc.
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 */

#ifndef _PMIC_GLB_REG_H_
#define _PMIC_GLB_REG_H_



#if defined(CONFIG_ADIE_SC2723) || defined(CONFIG_ADIE_SC2723S)
#include "sc2723_reg_base.h"
#include "__regs_sc2723_glb.h"
#elif defined(CONFIG_ADIE_SC2731)
#include "sc2731_reg_base.h"
#include "__regs_sc2731_glb.h"
#elif defined(CONFIG_ADIE_SC2721)
#include "sc2721_reg_base.h"
#include "__regs_sc2721_glb.h"
#elif defined(CONFIG_ADIE_SC2711)
#include "sc2711_reg_base.h"
#include "__regs_sc2711_glb.h"
#elif defined(CONFIG_ADIE_SC2713) || defined(CONFIG_ADIE_SC2713S)
#include "sc2713_reg_base.h"
#include "__regs_sc2713_glb.h"
#elif defined(CONFIG_ADIE_SC2720)
#include "sc2720_reg_base.h"
#include "__regs_sc2720_glb.h"
#else
#warning "PMIC .h is not defined!"
#endif

#endif
