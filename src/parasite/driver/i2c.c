/*
 * i2c.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"

#include "string.h"

#include "target_syssvc.h"

#include "max32662_i2c.h"

#include "driver/i2c.h"

#define DEFAULT_I2C_DONE		0x00000001
#include "app/console.h"

/// オカルト
/// この2つの関数がないと，割込みハンドラ内で primask が立ってしまう？？？
static uint32_t __read_primask(void){
	uint32_t val;

	Asm("mrs  %0, PRIMASK" : "=r"(val));
	return val;
}

static int ____sense_lock(void)
{
	return(__read_primask() == 0x1u);
}


static volatile int _tmp_ctx = 0;
static volatile int _ret = 0;
static volatile int _dbg = 0;
static volatile int _dbg2 = 0;

void _debug_set(int dbg)
{
	_dbg = dbg;
}

int driver_i2c_init(void)
{
	return max32662_i2c_initialize(max32662_i2c1, 400000, 50000000, 0, 0);
}


static void _default_callback(int status)
{
	do {
	_ret = iset_flg(I2C_FLG, DEFAULT_I2C_DONE);
	}while(_ret == E_CTX);

}

int driver_i2c_transfer_blocking(uint8_t addr, uint8_t *txbuf, size_t txlen, uint8_t *rxbuf, size_t rxlen)
{
//	return max32662_i2c_transfer(max32662_i2c1, addr, txbuf, txlen, rxbuf, rxlen, NULL);
	_dbg2  = 0;
	_dbg = 0;

	FLGPTN flg = 0;
	clr_flg(I2C_FLG, DEFAULT_I2C_DONE);

	_dbg = 1;

	int ret = max32662_i2c_transfer(max32662_i2c1, addr, txbuf, txlen, rxbuf, rxlen, _default_callback);
	if (ret != 0) return ret;

	_dbg = 2;

	ret = wai_flg(I2C_FLG, DEFAULT_I2C_DONE, TWF_ORW, &flg);
	if (ret != 0) return ret;

	_dbg = 3;

	return clr_flg(I2C_FLG, DEFAULT_I2C_DONE);
}

int driver_i2c_transfer(uint8_t addr, uint8_t *txbuf, size_t txlen, uint8_t *rxbuf, size_t rxlen, driver_i2c_transfer_done cb)
{
	return max32662_i2c_transfer(max32662_i2c1, addr, txbuf, txlen, rxbuf, rxlen, cb);
}

void isr_i2c0(intptr_t exinf)
{
	i2c0_handler();
}

void isr_i2c1(intptr_t exinf)
{
	i2c1_handler();
}
