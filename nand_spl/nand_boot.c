#include <config.h>
#include <common.h>
#include <nand.h>
#include <asm/io.h>
#include <asm/arch/sprd_chipram_env.h>
#include <linux/types.h>
#include <asm/arch/secure_boot.h>
#include <malloc.h>
#include <security/sprd_ce_ctrl.h>

#define SECURE_HEADER_OFF 512

#define CONFIG_SYS_NAND_READ_DELAY \
	{ volatile int dummy; int i; for (i=0; i<10000; i++) dummy = i; }

#define CONFIG_SYS_NAND_BAD_BLOCK_POS	0
#define CONFIG_SYS_NAND_5_ADDR_CYCLE	1

static int pageinblock = 0;
static uchar s_oob_data[NAND_MAX_OOBSIZE];
static int nand_is_bad_block(struct mtd_info *mtd, int block)
{
	struct nand_chip *this = mtd->priv;
	int page_addr = CONFIG_SYS_NAND_BAD_BLOCK_POS + block * pageinblock;

	this->ecc.read_oob(mtd, this, page_addr, 1);
	/*
	 * compare one bytes
	 */
	if (this->oob_poi[0] != 0xff)
		return 1;

	return 0;
}

static int nand_read_page(struct mtd_info *mtd, int block, int page, uchar *dst)
{
	struct nand_chip *this = mtd->priv;
	int page_addr = page + block * pageinblock;
	int stat;

	this->cmdfunc(mtd, NAND_CMD_READ0, 0x00, page_addr);
	stat = this->ecc.read_page(mtd, this, dst,page_addr);
	return 0;
}

int nand_load(struct mtd_info *mtd, unsigned int offs,
		     unsigned int uboot_size, uchar *dst)
{
	unsigned int block, lastblock;
	unsigned int page;
	unsigned int lastpage;

/*
	 * offs has to be aligned to a page address!
*/
	block = offs / mtd->erasesize;
	lastblock = (offs + uboot_size - 1) / mtd->erasesize;
	page = (offs % mtd->erasesize) / mtd->writesize;
	lastpage = uboot_size / mtd->writesize;

	while (lastpage > pageinblock) {
		lastpage = lastpage - pageinblock;
	}

	while (block <= lastblock) {
		if (!nand_is_bad_block(mtd, block)) {
			/*
			 * Skip bad blocks
			 */
			while (page < lastpage) {
				nand_read_page(mtd, block, page, dst);
				dst += mtd->writesize;
				page++;
			}
			page = 0;
		} else {
			lastblock++;
		}

		block++;
	}

	return 0;
}

/*
 * The main entry for NAND booting. It's necessary that SDRAM is already
 * configured and available since this code loads the main U-Boot image
 * from NAND into SDRAM and starts it from there.
 */
void nand_boot(void)
{
	struct nand_chip nand_chip;
	nand_info_t nand_info;
	int ret;
	__attribute__((noreturn)) void (*uboot)(void);

	/*
	 * Init board specific nand support
	 */
#ifdef SPRD_EVM_TAG_ON
	SPRD_EVM_TAG(1);
#endif

#ifdef CONFIG_FIREWALL
	sprd_firewall_config_pre();
#endif
	nand_info.priv = &nand_chip;
	nand_chip.dev_ready = NULL;	/* preset to NULL */
	board_nand_init(&nand_chip);
	if (nand_chip.select_chip)
		nand_chip.select_chip(&nand_info, 0);
	nand_chip.oob_poi=s_oob_data; //init the oob data buffer
	/*
	 * Load U-Boot image from NAND into RAM
	 */
	pageinblock = nand_info.erasesize / nand_info.writesize;
#ifdef SPRD_EVM_TAG_ON
	SPRD_EVM_TAG(2);
#endif

#ifdef CONFIG_LOAD_TOS_ALONE
	ret = nand_load(&nand_info, CONFIG_SYS_NAND_U_TOS_OFFS,TOS_LOAD_MAX_SIZE,
			(uchar *)CONFIG_TOS_LDADDR_START - SECURE_HEADER_OFF);
#endif

#ifdef CONFIG_LOAD_ATF
	ret = nand_load(&nand_info, CONFIG_SYS_NAND_U_SML_OFFS,SML_LOAD_MAX_SIZE,
			(uchar *)CONFIG_SML_LDADDR_START - SECURE_HEADER_OFF);
#endif

	ret = nand_load(&nand_info, CONFIG_SYS_NAND_U_BOOT_OFFS, CONFIG_SYS_NAND_U_BOOT_SIZE,
			(uchar *)CONFIG_SYS_NAND_U_BOOT_DST - SECURE_HEADER_OFF);
	/*
	 * Jump to U-Boot image
	 */
#ifdef SPRD_EVM_TAG_ON
	SPRD_EVM_TAG(3);
#endif

#if CONFIG_SMLBOOT || CONFIG_LOAD_ATF
	uboot = (void *)CONFIG_SML_LDADDR_START;
#else
	uboot = (void *)CONFIG_SYS_NAND_U_BOOT_START;
#endif

	disable_ahb_ce_eb();
	disable_ahb_ce_efs_eb();

#ifdef CONFIG_FIREWALL
	sprd_firewall_config();
#endif

	chipram_env_set(BOOTLOADER_MODE_LOAD);

#ifdef  CONFIG_SCX35L64
        extern void switch64_and_set_pc(u32 addr);
        switch64_and_set_pc(CONFIG_SYS_NAND_U_BOOT_START);
#else
#if (CONFIG_LOAD_TOS_ALONE == 1) && !defined (CONFIG_ATF_BOOT_TOS)
	secure_sp_entry(CONFIG_TOS_LDADDR_START,CONFIG_SYS_NAND_U_BOOT_START);
#else
	(*uboot) ();
#endif
#endif
}
