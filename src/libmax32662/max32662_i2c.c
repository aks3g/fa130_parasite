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


int max32662_i2c_transfer(max32662_i2c_id id, uint8_t addr,  uint8_t *txbuf, size_t txsize, uint8_t *rxbuf, size_t rxsize, max32662_i2c_transfer_done cb)
{
	volatile Max32662_reg_i2c *i2c = _get_i2c_regs(id);
	if (i2c == NULL) return -1;

	size_t i = 0;

	// Blocking Mode
	if (cb == NULL) {
		if (txsize > 0) {
			i2c->fifo.dword = (addr << 1) | 0; //write
			while (i2c->status.bf.tx_full == 0 && i != txsize) {// tx fifo is not fill
				i2c->fifo.dword = txbuf[i++];
			}

			if (rxsize > 0) {
				i2c->mstctrl.bf.restart = 1;
				i2c->mstctrl.bf.stop = 0;
			}
			else {
				i2c->mstctrl.bf.restart = 0;
				i2c->mstctrl.bf.stop = 1;
			}
			i2c->mstctrl.bf.start = 1; //start transfer

			while (i != txsize){ // transmitted size is not reach to txsize
				while(i2c->status.bf.tx_full == 1); // wait for fifo

				i2c->fifo.dword = txbuf[i++];
			}

			while (i2c->intfl0.bf.done == 0 && i2c->intfl0.bf.addr_nack_err == 0); // wait for done.
			if (i2c->intfl0.bf.addr_nack_err != 0) {
				i2c->txctrl0.bf.flush = 1;

				return MAX32662_I2C_ERROR_NAK;
			}

			if (rxsize > 0) {
				while (i2c->mstctrl.bf.restart == 1);
			}
			else {
				while (i2c->mstctrl.bf.stop == 1);
			}
		}

		if (rxsize > 0) {
			i2c->rxctrl1.bf.cnt = rxsize; // setup rx size
			i2c->fifo.dword = (addr << 1) | 1; //read

			i2c->mstctrl.bf.restart = 0;
			i2c->mstctrl.bf.stop  = 1;

			i2c->mstctrl.bf.start = 1; //start transmit

			while (i2c->intfl0.bf.done == 0); // wait for done.
			if (i2c->intfl0.bf.addr_nack_err != 0) {
				i2c->txctrl0.bf.flush = 1;

				return MAX32662_I2C_ERROR_NAK;
			}

			for (i=0 ; i<rxsize ; ++i) {
				rxbuf[i] = i2c->fifo.dword;
			}

			while (i2c->mstctrl.bf.stop == 1);
		}
	}
	else {

	}

	return 0;
}


void i2cn_handler(volatile Max32662_reg_i2c *i2c)
{
	
	return;
}

void i2c0_handler(void)
{
	i2cn_handler(MAX32662_I2C0);
}


void i2c1_handler(void)
{
	i2cn_handler(MAX32662_I2C1);
}

