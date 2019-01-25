
ifneq ($(CONFIG_SOC_IWHALE2)$(CONFIG_SOC_ISHARKL2)$(CONFIG_WHALE2)$(CONFIG_SPRD_DDRC_R1P0),)

ifndef CONFIG_SPRD_DDRC_R1P0
obj-y = ddr_common/
endif

obj-$(CONFIG_WHALE) += ddr_init/init/v0_0/
obj-$(CONFIG_WHALE) += ddr_init/qos/v0_0/
obj-$(CONFIG_WHALE) += ddr_init/timing/v0_0/

obj-$(CONFIG_WHALE2) += ddr_init/init/v0_1/
obj-$(CONFIG_WHALE2) += ddr_init/qos/v0_1/
obj-$(CONFIG_WHALE2) += ddr_init/timing/v0_1/

obj-$(CONFIG_SOC_IWHALE2) += ddr_init/init/v0_2/
obj-$(CONFIG_SOC_IWHALE2) += ddr_init/qos/v0_2/
obj-$(CONFIG_SOC_IWHALE2) += ddr_init/timing/v0_2/

obj-$(CONFIG_SOC_ISHARKL2) += ddr_init/init/v0_3/
obj-$(CONFIG_SPRD_DDRC_R1P0) += ddr_init/init/ddrc/r1p0/

obj-$(CONFIG_DDR_IP_CONFIG_FILE) += ddr_init/ip_cfg/v0_2/

endif

