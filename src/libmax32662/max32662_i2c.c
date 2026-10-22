/*
 * max32662_i2c.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "cortex_m4.h"
#include "max32662_irq.h"
#include "max32662_i2c.h"

typedef enum {
	I2C_IDLE,
	I2C_WAIT_TX_DONE,
	I2C_WAIT_RESTART,
	I2C_WAIT_RX_DONE,
} Max32662_i2c_intr_state;

typedef struct {
	Max32662_i2c_intr_state state;
	max32662_i2c_transfer_done callback;
	uint8_t *rxbuf;
	size_t  rxsize;
	size_t  cnt;
	uint8_t addr; 
} I2cTransferContext;

I2cTransferContext _ctx[2];


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

static volatile I2cTransferContext * _get_i2c_context(max32662_i2c_id id)
{
	switch (id)
	{
	case max32662_i2c0:
		return &_ctx[0];
	case max32662_i2c1:
		return &_ctx[1];
	default:
		return NULL;
	}
}


int max32662_i2c_initialize(max32662_i2c_id id, uint32_t scl_clk_Hz, uint32_t peripheral_clk_Hz, uint32_t tx_fifo_size, uint32_t rx_fifo_size)
{
	volatile Max32662_reg_i2c *i2c = _get_i2c_regs(id);
	volatile I2cTransferContext *ctx = _get_i2c_context(id);
	if (i2c == NULL) return -1;

	memset((void *)ctx, 0, sizeof(I2cTransferContext));

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

	if (id == max32662_i2c0) {
		__enable_nvic_irq(MAX32662_IRQNUM_I2C);
	}
	else {
		__enable_nvic_irq(MAX32662_IRQNUM_I2C1);
	}


	return 0;
}


int max32662_i2c_transfer(max32662_i2c_id id, uint8_t addr,  uint8_t *txbuf, size_t txsize, uint8_t *rxbuf, size_t rxsize, max32662_i2c_transfer_done cb)
{
	volatile Max32662_reg_i2c   *i2c = _get_i2c_regs(id);
	volatile I2cTransferContext *ctx = _get_i2c_context(id);
	if (i2c == NULL) return -1;

	size_t i = 0;

	while (i2c->mstctrl.bf.start == 1 || i2c->mstctrl.bf.restart == 1 || i2c->mstctrl.bf.stop == 1);
	while (i2c->status.bf.mst_busy == 1 || i2c->status.bf.busy == 1);

	// Blocking Mode
	if (cb == NULL) {
		i2c->rxctrl1.bf.cnt = 0;

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

			//J 終了条件を待つ
			while (i2c->mstctrl.bf.restart == 1 || i2c->mstctrl.bf.stop == 1);
		}

		if (rxsize > 0) {
			i2c->rxctrl1.bf.cnt = rxsize; // setup rx size
			i2c->fifo.dword = (addr << 1) | 1; //read

			i2c->mstctrl.bf.restart = 0;
			i2c->mstctrl.bf.stop  = 1;

			i2c->mstctrl.bf.start = 1; //start receive

			for (i=0 ; i<rxsize ; ++i) {
				while (i2c->rxctrl1.bf.lvl == 0);
				rxbuf[i] = i2c->fifo.dword;
			}

			while (i2c->mstctrl.bf.stop == 1);
		}
	}
	else {
		i2c->rxctrl0.bf.thd_lvl = 5; //J FIFOが8byteなので取りこぼさないように1つ減らしておく
		i2c->rxctrl1.bf.cnt = 0;

		i2c->inten0.bf.done = 1;
		i2c->inten0.bf.addr_nack_err = 1;
		i2c->inten0.bf.rx_thd = 1;

		// save Rx Context
		ctx->callback = cb;
		ctx->state    = rxsize==0 ? I2C_IDLE : I2C_WAIT_TX_DONE;
		ctx->addr     = addr;
		ctx->rxsize   = rxsize;
		ctx->rxbuf    = rxbuf;
		ctx->cnt      = 0;

		if (txsize > 0) {
			i2c->fifo.dword = (addr << 1) | 0; //write

			// TODO Tx fifoのサイズを超えたTxが出来ないと思うので必要に応じて
			// 割込みハンドラ側で積みなおす必要がある
			while (i2c->status.bf.tx_full == 0 && i != txsize) {
				i2c->fifo.dword = txbuf[i++];
			}

			// TODO 積み残しがある間はStop/Restart設定をしない方が良いかも
			if (rxsize > 0) {
				i2c->mstctrl.bf.restart = 1;
				i2c->mstctrl.bf.stop = 0;
			}
			else {
				i2c->mstctrl.bf.restart = 0;
				i2c->mstctrl.bf.stop = 1;
			}
			i2c->mstctrl.bf.start = 1; //start transfer
		}
		else if (rxsize > 0) {
			i2c->rxctrl1.bf.cnt = rxsize; // setup rx size
			i2c->fifo.dword = (addr << 1) | 1; //read

			i2c->mstctrl.bf.restart = 0;
			i2c->mstctrl.bf.stop  = 1;

			i2c->mstctrl.bf.start = 1; //start receive
		}
	}

	return 0;
}


void i2cn_handler(volatile Max32662_reg_i2c *i2c, I2cTransferContext *ctx)
{
	max32662_i2c_intfl0 flg0 = i2c->intfl0;
	
	// rx が残っていれば対応する
	if (flg0.bf.done) {
		i2c->intfl0.bf.done = 1;
		if (ctx->state == I2C_WAIT_TX_DONE) {
			while (i2c->mstctrl.bf.restart == 1 || i2c->mstctrl.bf.stop == 1);

			ctx->state = I2C_WAIT_RX_DONE;

			i2c->rxctrl1.bf.cnt = ctx->rxsize; // setup rx size
			i2c->fifo.dword = (ctx->addr << 1) | 1; //read

			i2c->mstctrl.bf.stop  = 1;
			i2c->mstctrl.bf.start = 1; //start receive

		}
		else if (ctx->state == I2C_WAIT_RX_DONE) {
			while (i2c->mstctrl.bf.restart == 1 || i2c->mstctrl.bf.stop == 1);

			ctx->state = I2C_IDLE;
			i2c->inten0.dword = 0;
			i2c->inten1.dword = 0;

			while (i2c->rxctrl1.bf.lvl != 0 && ctx->cnt < ctx->rxsize) {
				ctx->rxbuf[ctx->cnt++] = i2c->fifo.dword;
			}

			if(ctx->callback) ctx->callback(0);
		}
		else if (ctx->state == I2C_IDLE) {
			while (i2c->mstctrl.bf.restart == 1 || i2c->mstctrl.bf.stop == 1);

			ctx->state = I2C_IDLE;
			i2c->inten0.dword = 0;
			i2c->inten1.dword = 0;

			if(ctx->callback) ctx->callback(0);
		}
	}
	if (flg0.bf.rx_thd) {
		while (i2c->rxctrl1.bf.lvl != 0 && ctx->cnt < ctx->rxsize) {
			ctx->rxbuf[ctx->cnt++] = i2c->fifo.dword;
		}
		i2c->intfl0.bf.rx_thd = 1;
	}
	if (flg0.bf.addr_nack_err) {
		if(ctx->callback) ctx->callback(MAX32662_I2C_ERROR_NAK);
		i2c->intfl0.bf.addr_nack_err = 1;
	}

	return;
}

void i2c0_handler(void)
{
	i2cn_handler(MAX32662_I2C0, &_ctx[0]);
}


void i2c1_handler(void)
{
	i2cn_handler(MAX32662_I2C1, &_ctx[1]);
}

