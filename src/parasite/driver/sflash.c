/*
 * sflash.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"

#include <string.h>

#include "max32662_spi.h"
#include "max32662_clock.h"

#include "error_code.h"
#include "fs/fs.h"

// SPI Flash Commands
#define SFLASH_CMD_WRITE_ENABLE				(0x06)
#define SFLASH_CMD_WRITE_DISABLE			(0x04)
#define SFLASH_CMD_READ_STATUS_REG			(0x05)
#define SFLASH_CMD_WRITE_STATUS_REG			(0x01)
#define SFLASH_CMD_READ_DATA				(0x03)
#define SFLASH_CMD_FAST_READ				(0x0B)
#define SFLASH_CMD_PAGE_PROGRAM				(0x02)
#define SFLASH_CMD_SECTOR_ERASE				(0x20)
#define SFLASH_CMD_CHIP_ERASE				(0x60)
#define SFLASH_CMD_MANU_DEV_ID				(0x90)
#define SFLASH_CMD_READ_IDENTIFICATION		(0x9F)
#define SFLASH_CMD_READ_UNIQ_ID				(0x4B)
#define SFLASH_CMD_RELEASE_FROM_DPD			(0xAB)

// SPI Flash Status
#define SPI_FLASH_STATUS_REG_WIP			(1<<0)
#define SPI_FLASH_STATUS_REG_WEL			(1<<1)
#define SPI_FLASH_STATUS_REG_BP0			(1<<2)
#define SPI_FLASH_STATUS_REG_BP1			(1<<3)
#define SPI_FLASH_STATUS_REG_BP2			(1<<4)
#define SPI_FLASH_STATUS_REG_BP3			(1<<5)
#define SPI_FLASH_STATUS_REG_QE				(1<<6)
#define SPI_FLASH_STATUS_REG_SRWD			(1<<7)

// Event Flag
#define FS_EVT_DONE							(1 << 0)
#define FS_EVT_ERROR						(1 << 1)

typedef struct {
	uint8_t work[SFLASH_PAGE_SIZE + 4];
} SflashDevice;

static SflashDevice dev;

static void _spi_dma_transer_done(int status)
{
	if (status == 0) {
		iset_flg(FS_FLG, FS_EVT_DONE);
	}
	else {
		iset_flg(FS_FLG, FS_EVT_ERROR);
	}

	return;
}

static uint8_t _sflash_read_status(void)
{
	uint8_t txb[1] = {SFLASH_CMD_READ_STATUS_REG};
	uint8_t rxb[1] = {0xFF};
	max32662_spi_master_transfer(max32662_spi1, txb, rxb, sizeof(txb), 1, NULL);

	return rxb[0];
}

static void _sflash_write_status(uint8_t status)
{
	uint8_t txb[2] = {SFLASH_CMD_WRITE_STATUS_REG};
	txb[1] = status;

	max32662_spi_master_transfer(max32662_spi1, txb, NULL, sizeof(txb), 0, NULL);

	return;
}

static void _sflash_write_enable(void)
{
	uint8_t txb[1] = {SFLASH_CMD_WRITE_ENABLE};

	max32662_spi_master_transfer(max32662_spi1, txb, NULL, sizeof(txb), 0, NULL);

	return;
}


static void _sflash_wait_busy(void)
{
	uint8_t status = 0;
	// check write in progress
	do {
		status = _sflash_read_status();
	} while ((status & SPI_FLASH_STATUS_REG_WIP) != 0);

	return;
}

#if 0
static void _sflash_wait_write_enable(void)
{
	uint8_t status = 0;
	// check write in progress
	do {
		status = _sflash_read_status();
	} while ((status & SPI_FLASH_STATUS_REG_WEL) == 0);

	return;
}
#endif


int sflash_init(void)
{
	max32662_clock_reset(Max32662_reset_spi1);
	int ret = max32662_spi_master_initialize(max32662_spi1, max32662_spi_mode3, 50000000, 25000000);
	if (ret != 0) {
		return ret;
	}

	_sflash_write_status(0);

	return 0;
}

int sflash_read_page(uint32_t addr, uint8_t *work)
{
	FLGPTN flag = 0;

	_sflash_wait_busy();

	dev.work[0] = SFLASH_CMD_READ_DATA;
	dev.work[1] = (uint8_t)(addr >> 16);
	dev.work[2] = (uint8_t)(addr >>  8);
	dev.work[3] = (uint8_t)(addr >>  0);

	int ret = max32662_spi_master_transferDMA(max32662_spi1, dev.work, work, 4+SFLASH_PAGE_SIZE, _spi_dma_transer_done);
	if (ret != 0) return ret;

	return wai_flg(FS_FLG, FS_EVT_DONE | FS_EVT_ERROR, TWF_ORW, &flag);
}

int sflash_write_page(uint32_t addr, const uint8_t *buf)
{
	FLGPTN flag = 0;

	dev.work[0] = SFLASH_CMD_PAGE_PROGRAM;
	dev.work[1] = (uint8_t)(addr >> 16);
	dev.work[2] = (uint8_t)(addr >>  8);
	dev.work[3] = (uint8_t)(addr >>  0);

	// copy from buf
	memcpy(&(dev.work[4]), buf, SFLASH_PAGE_SIZE);

	_sflash_wait_busy();
	_sflash_write_enable();

	int ret = max32662_spi_master_transferDMA(max32662_spi1, dev.work, (uint8_t *)buf, 4+SFLASH_PAGE_SIZE, _spi_dma_transer_done);
	if (ret != 0) return ret;

	return wai_flg(FS_FLG, FS_EVT_DONE | FS_EVT_ERROR, TWF_ORW, &flag);
}

int sflash_erase_sector(uint32_t addr)
{
	_sflash_wait_busy();
	_sflash_write_enable();

	uint8_t txb[4] = {SFLASH_CMD_SECTOR_ERASE, 0,0,0};
	txb[1] = (uint8_t)(addr >> 16);
	txb[2] = (uint8_t)(addr >>  8);
	txb[3] = (uint8_t)(addr >>  0);

	max32662_spi_master_transfer(max32662_spi1, txb, NULL, sizeof(txb), 0, NULL);

	_sflash_wait_busy();

	return 0;
}

int sflash_read_ids(uint8_t *manu_id, uint8_t *dev_id, uint16_t *jdid, uint8_t *uid)
{
	FLGPTN flag = 0;
	uint8_t rxb[6];

	// manufactuer id, device id
	memset(rxb, 0, sizeof(rxb));
	dev.work[0] = SFLASH_CMD_MANU_DEV_ID;
	max32662_spi_master_transferDMA(max32662_spi1, dev.work, rxb, 6, _spi_dma_transer_done);
	wai_flg(FS_FLG, FS_EVT_DONE | FS_EVT_ERROR, TWF_ORW, &flag);

	*manu_id = rxb[4];
	*dev_id  = rxb[5];

	// JDID
	memset(rxb, 0, sizeof(rxb));
	dev.work[0] = SFLASH_CMD_READ_IDENTIFICATION;
	max32662_spi_master_transferDMA(max32662_spi1, dev.work, rxb, 4, _spi_dma_transer_done);
	wai_flg(FS_FLG, FS_EVT_DONE | FS_EVT_ERROR, TWF_ORW, &flag);

	*jdid = (uint16_t)rxb[2] << 8 | rxb[3];

	// Uniq ID
	memset(rxb, 0, sizeof(rxb));
	dev.work[0] = SFLASH_CMD_READ_UNIQ_ID;
	max32662_spi_master_transferDMA(max32662_spi1, dev.work, rxb, 6, _spi_dma_transer_done);
	wai_flg(FS_FLG, FS_EVT_DONE | FS_EVT_ERROR, TWF_ORW, &flag);

	*uid  = rxb[5];

	return 0;
}




extern void dmac0_handler(void);
extern void dmac1_handler(void);
extern void dmac2_handler(void);
extern void dmac3_handler(void);
extern void spi0_handler(void);
extern void spi1_handler(void);

void isr_dac0(intptr_t exinf)
{
	(void)exinf;
	dmac0_handler();
}

void isr_dac1(intptr_t exinf)
{
	(void)exinf;
	dmac1_handler();
}

void isr_dac2(intptr_t exinf)
{
	(void)exinf;
	dmac2_handler();
}

void isr_dac3(intptr_t exinf)
{
	(void)exinf;
	dmac3_handler();
}


void isr_spi0(intptr_t exinf)
{
	(void)exinf;
	spi0_handler();
}

void isr_spi1(intptr_t exinf)
{
	(void)exinf;
	spi1_handler();
}
