/*
 * sflash.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef SFLASH_H_
#define SFLASH_H_

#include <kernel.h>
#include "kernel_cfg.h"

extern int sflash_init(void);
extern int sflash_read_page(uint32_t addr, uint8_t *work);
extern int sflash_write_page(uint32_t addr, const uint8_t *buf);
extern int sflash_erase_sector(uint32_t addr);
extern int sflash_read_ids(uint8_t *manu_id, uint8_t *dev_id, uint16_t *jdid, uint8_t *uid);

#endif

