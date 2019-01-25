

ifdef O
ifeq ("$(origin O)", "command line")
BUILD_DIR := $(O)
endif
endif

ifneq ($(BUILD_DIR),)
saved-output := $(BUILD_DIR)

# Attempt to create a output directory.
$(shell [ -d ${BUILD_DIR} ] || mkdir -p ${BUILD_DIR})

# Verify if it was successful.
BUILD_DIR := $(shell cd $(BUILD_DIR) && /bin/pwd)
$(if $(BUILD_DIR),,$(error output directory "$(saved-output)" does not exist))
endif # ifneq ($(BUILD_DIR),)

OBJTREE		:= $(if $(BUILD_DIR),$(BUILD_DIR),$(CURDIR))
SRCTREE		:= $(CURDIR)
TOPDIR		:= $(SRCTREE)
export	TOPDIR SRCTREE OBJTREE

MKCONFIG	:= $(SRCTREE)/mkconfig

obj := $(OBJTREE)/
src := $(SRCTREE)/

export obj src

#########################################################################

ifeq ($(obj)include/config.mk,$(wildcard $(obj)include/config.mk))

# load ARCH, BOARD, and CPU configuration
include $(obj)include/config.mk
export	ARCH CPU BOARD VENDOR SOC

ifndef CONFIG_X86
CROSS_COMPILE ?= arm-eabi-
endif

# load other configuration
include $(TOPDIR)/config.mk

include  $(TOPDIR)/nand_fdl/board/$(VENDOR)/$(SOC)/config.mk
#########################################################################


# Add GCC lib
#ifndef CONFIG_X86
PLATFORM_LIBGCC = -L $(shell dirname `$(CC) $(CFLAGS) -print-libgcc-file-name`) -lgcc
#endif
PLATFORM_LIBS += $(PLATFORM_LIBGCC)
export PLATFORM_LIBS

#########################################################################
ALL +=  spl fdl1

all:		$(ALL) $(obj)include/autoconf.mk

sinclude $(obj)include/autoconf.mk.dep
sinclude $(obj)include/autoconf.mk

spl:	SPL_ALL

depend dep:	$(obj)include/autoconf.mk

splobj	:= $(OBJTREE)/nand_spl/
fdlobj	:= $(OBJTREE)/nand_fdl/

export splobj fdlobj

CFLAGS		+= -g -ffunction-sections -fdata-sections

ifeq ($(ARCH),x86)
CFLAGS		+= -m32 -w
AFLAGS		+= -m32 -w
else
CFLAGS		+= -mlittle-endian
AFLAGS		+= -mlittle-endian
endif
#########################################################################

SPL_OBJ := $(splobj)nand_spl/board/$(VENDOR)/$(SOC)/spl_start.o
FDL_OBJ := $(fdlobj)nand_fdl/board/$(VENDOR)/$(SOC)/fdl_start.o

$(SPL_OBJ):
	@:

$(FDL_OBJ):
	@:

SPL_LIBS-y += drivers/
SPL_LIBS-y += secure/
SPL_LIBS-y += common/
SPL_LIBS-y += $(CPUDIR)/$(SOC)/
SPL_LIBS-y += arch/$(ARCH)/lib/
SPL_LIBS-y += nand_spl/
SPL_LIBS-y += nand_spl/board/$(VENDOR)/$(SOC)/
SPL_LIBS-y += ddr/
SPL_LIBS-$(CONFIG_SPRD_DMC_R2P0) += arch/$(ARCH)/cpu/sprd_dmc/r2p0/
SPL_LIBS-$(CONFIG_SPRD_DMC_R3P0) += arch/$(ARCH)/cpu/sprd_dmc/r3p0/

FDL_LIBS-y += drivers/
FDL_LIBS-y += secure/
FDL_LIBS-y += common/
FDL_LIBS-y += $(CPUDIR)/$(SOC)/
FDL_LIBS-y += arch/$(ARCH)/lib/
FDL_LIBS-y += nand_fdl/fdl-1/src/
FDL_LIBS-y += nand_fdl/common/
FDL_LIBS-y += nand_fdl/board/$(VENDOR)/$(SOC)/
FDL_LIBS-y += ddr/
FDL_LIBS-$(CONFIG_SPRD_DMC_R2P0) += arch/$(ARCH)/cpu/sprd_dmc/r2p0/
FDL_LIBS-$(CONFIG_SPRD_DMC_R3P0) += arch/$(ARCH)/cpu/sprd_dmc/r3p0/

SPL_LIBS-y := $(patsubst %/, %/built-in.o, $(SPL_LIBS-y))
FDL_LIBS-y := $(patsubst %/, %/built-in.o, $(FDL_LIBS-y))

SPL_LIBS := $(addprefix $(splobj),$(sort $(SPL_LIBS-y)))
FDL_LIBS := $(addprefix $(fdlobj),$(sort $(FDL_LIBS-y)))

__SPL_LIBS := $(subst $(splobj),,$(SPL_LIBS))
__FDL_LIBS := $(subst $(fdlobj),,$(FDL_LIBS))

build := -f $(TOPDIR)/scripts/Makefile.build -C

$(SPL_LIBS):
	@echo "spl built: $@ libs: $(SPL_LIBS)!!!"
	$(MAKE) MAKE_SPL_TARGET=y $(build) $(dir $(subst $(splobj),,$@))

$(FDL_LIBS):
	@echo "fdl built: $@ libs: $(FDL_LIBS)!!!"
	$(MAKE) $(build) $(dir $(subst $(fdlobj),,$@))

#########################################################################
SPL_LDSCRIPT	= $(TOPDIR)/nand_spl/board/$(VENDOR)/$(SOC)/spl.lds

SPL_LDFLAGS	= -Bstatic -T $(SPL_LDS) $(PLATFORM_LDFLAGS) --gc-sections

SPL_LNDIR		:= $(splobj)

FILE_SIZE_CHECK := $(SRCTREE)/nand_spl/board/$(VENDOR)/$(SOC)/file_size_check.sh

SPL_ALL :$(splobj)u-boot-spl $(splobj)u-boot-spl.bin $(splobj)u-boot-spl-16k.bin file_size_check $(SPL_LNDIR)/spl.lds

STARTDIR := $(splobj)nand_spl/board/$(VENDOR)/$(SOC)

SPL_LDPPFLAGS += -DSTARTDIR=$(STARTDIR)

SPL_LDS := $(SPL_LNDIR)spl.lds
$(SPL_LDS): $(SPL_LDSCRIPT) depend
		$(CPP) $(CPPFLAGS) $(SPL_LDPPFLAGS) -ansi -D__ASSEMBLY__ -P - <$< >$@

file_size_check: $(splobj)u-boot-spl-16k.bin
	$(FILE_SIZE_CHECK) $(CONFIG_BIN_SIZE) $< $(splobj)u-boot-spl.bin $(splobj)u-boot-spl


$(splobj)u-boot-spl-16k.bin: $(splobj)u-boot-spl.bin
	cat $(splobj)u-boot-spl.bin > $@


$(splobj)u-boot-spl.bin:	$(splobj)u-boot-spl
	$(OBJCOPY) ${OBJCFLAGS} --pad-to "$(CONFIG_PAD_TO)" -O binary $< $@

$(splobj)u-boot-spl:	$(SPL_LDS) $(SPL_LIBS) $(SPL_OBJ)
	cd $(SPL_LNDIR) && $(LD) $(SPL_LDFLAGS) $(PLATFORM_LIBS) $(SPL_LIBS) $(SPL_OBJ)\
		-Map $(splobj)u-boot-spl.map \
		-o $@

#########################################################################

FDL1_PATH     = $(TOPDIR)/nand_fdl/fdl-1

FDL1_LNDIR   := $(fdlobj)

fdl1:	$(fdlobj)fdl1.bin

FDL1_LDSCRIPT      = $(TOPDIR)/nand_fdl/board/$(VENDOR)/$(SOC)/fdl1.lds

FDL1_LDFLAGS  = -Bstatic -T $(FDL_LDS) $(PLATFORM_LDFLAGS) --gc-sections

FDL_STARTDIR := $(fdlobj)nand_fdl/board/$(VENDOR)/$(SOC)

FDL_LDPPFLAGS += -DFDL_STARTDIR=$(FDL_STARTDIR)

FDL_LDS := $(FDL1_LNDIR)fdl1.lds
$(FDL_LDS): $(FDL1_LDSCRIPT) depend
		$(CPP) $(CPPFLAGS) $(FDL_LDPPFLAGS) -ansi -D__ASSEMBLY__ -P - <$< >$@

$(fdlobj)fdl1.bin : $(fdlobj)fdl1.axf
	$(OBJCOPY) ${OBJCFLAGS} -O binary $< $@

$(fdlobj)fdl1.axf: $(FDL_LIBS) $(FDL_LDS) $(FDL_OBJ)
	cd $(FDL1_LNDIR) && $(LD) $(FDL1_LDFLAGS)\
		$(FDL_LIBS) $(FDL_OBJ)\
		-Map $(fdlobj)fdl1.map \
		-o $@ $(PLATFORM_LIBS)

#########################################################################
endif	# config.mk

preconfig:
	@rm -f $(obj)include/config.h $(obj)include/config.mk
	@mkdir -p $(obj)include
	@mkdir -p $(obj)nand_fdl
	@mkdir -p $(obj)nand_spl

$(obj)include/autoconf.mk: $(obj)include/config.h
	$(CPP) $(CFLAGS) -DDO_DEPS_ONLY -dM $(obj)include/config.h > $@.tmp && \
		sed -n -f scripts/define2mk.sed $@.tmp > $@; \
	rm $@.tmp

#========================================================================
# SPRD board define
#========================================================================

include $(TOPDIR)/board.def

#########################################################################

clean:
	@rm -f $(obj)nand_spl/{u-boot-spl,u-boot-spl.map}
	@find $(OBJTREE) -type f \
		\( -name 'core' -o -name '.depend' -o -name '*.bak' -o -name '*~' \
		-o -name '*.o'	-o -name '*.a' -o -name '*.exe'	\) -print \
		| xargs rm -f


distclean:
	rm -rf $(obj)*

#########################################################################
