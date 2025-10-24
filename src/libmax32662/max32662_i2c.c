/*
 * max32662_i2c.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */
#include <stddef.h>
#include <stdint.h>

#include "cortex_m4.h"
#include "max32662_irq.h"
#include "max32662_i2c.h"

static volatile Max32662_reg_i2c * _get_i2c_regs(max32662_i2c_id id)
{
	switch (id)
	{
	case max32662_i2c0:
		return MAX32662_I2C0;
	case max32662_i2c1:
		return MAX32662_I2C1;
	default:
		return NULL;
	}
}


int max32662_i2c_initialize(max32662_i2c_id id, uint32_t scl_clk_Hz, uint32_t peripheral_clk_Hz, uint32_t tx_fifo_size, uint32_t rx_fifo_size)
{
	volatile Max32662_reg_i2c *i2c = _get_i2c_regs(id);
	if (i2c == NULL) return -1;

	i2c->ctrl.bf.en = 1;
	{
		i2c->ctrl.bf.mst_mode = MAX32662_I2C_CTRL_MST_MODE_CONTROLLER_MODE;

		i2c->rxctrl1.bf.cnt = 1;
		i2c->mstctrl.bf.ex_addr_en = 0; // 7bit address mode

		// Setup scl hi/lo count
		uint32_t clk_cnt = ((peripheral_clk_Hz/scl_clk_Hz) / 2)  - 1;
		i2c->clklo.bf.lo = clk_cnt;
		i2c->clkhi.bf.hi = clk_cnt;
	}

	return 0;
}


int max32662_i2c_transfer(max32662_i2c_id id, uint8_t addr,  uint8_t *txbuf, size_t txsize, uint8_t *rxbuf, size_t rxsize)
{
	volatile Max32662_reg_i2c *i2c = _get_i2c_regs(id);
	if (i2c == NULL) return -1;

	i2c->mstctrl.bf.start = 1; //start sending
	i2c->fifo.dword = (addr << 1) | 0; //write

	return 0;
}


void i2cn_handler(volatile Max32662_reg_i2c *i2c)
{
}

void i2c0_handler(void)
{
	i2cn_handler(MAX32662_I2C0);
}


void i2c1_handler(void)
{
	i2cn_handler(MAX32662_I2C1);
}

