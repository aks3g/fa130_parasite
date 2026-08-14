/*
 * max32662_uart.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 

#include <stdint.h>
#include <stddef.h>

#include "cortex_m4.h"
#include "max32662_irq.h"
#include "max32662_clock.h"

#include "max32662_uart.h"

#define UART_FIFO_SIZE 256

typedef struct {
	uint8_t buf[UART_FIFO_SIZE];
	uint32_t wptr;
	uint32_t rptr;
} uart_fifo;

typedef struct {
	uart_fifo tx;
	uart_fifo rx;
	Max32662_uart_rx_done_func rx_cb;
} uart_context;

static uart_context ctx[2] = {0};

static volatile Max32662_uart * _uart_reg(Max32662_uart_id id)
{
	if (id == Max32662_uart0) {
		return MAX32662_UART0;
	}
	else if(id == Max32662_uart1) {
		return MAX32662_UART1;
	}
	else {
		return NULL;
	}
}

#define _FIFO_LEN(fifo)		((UART_FIFO_SIZE + (fifo)->wptr - (fifo)->rptr) & (UART_FIFO_SIZE-1))
#define _FIFO_FULL(fifo)	(_FIFO_LEN(fifo) == (UART_FIFO_SIZE-1))

static int _fifo_push(uart_fifo *fifo, uint8_t b)
{
	if (_FIFO_FULL(fifo)) return -1;

	fifo->buf[fifo->wptr] = b;
	fifo->wptr = (fifo->wptr + 1) & (UART_FIFO_SIZE-1);

	return 0;
}

static int _fifo_pop(uart_fifo *fifo, uint8_t *b)
{
	if (_FIFO_LEN(fifo)==0) return -1;

	*b =fifo->buf[fifo->rptr];
	fifo->rptr = (fifo->rptr+1) & (UART_FIFO_SIZE-1);

	return 0;
}


int  max32662_uart_isr(Max32662_uart_id id)
{
	volatile Max32662_uart * reg = _uart_reg(id);
	max32662_uart_intfl intfl = reg->intfl;
	reg->intfl.dword = intfl.dword;

	if (reg->status.bf.tx_em || intfl.bf.tx_ae || intfl.bf.tx_he) {
		uint8_t c=0;
		while ((reg->status.bf.tx_full == 0) && (_FIFO_LEN(&(ctx[id].tx)) > 0)) {
			(void)_fifo_pop(&(ctx[id].tx), &c);
			reg->fifo.dword = c;
		}

		if (_FIFO_LEN(&(ctx[id].tx)) == 0) {
			reg->inten.bf.tx_ae  = 0;
			reg->inten.bf.tx_he  = 0;
		}
	}

	if (reg->status.bf.rx_lvl > 0) {
		uint8_t b = reg->fifo.dword;
		_fifo_push(&(ctx[id].rx), b);

		if (ctx[id].rx_cb != NULL)  ctx[id].rx_cb(b);
	}

	return 0;
}


void uart0_handler(void)
{
	max32662_uart_isr(Max32662_uart0);
}

void uart1_handler(void)
{
	max32662_uart_isr(Max32662_uart1);
}


int max32662_uart_setup(Max32662_uart_id id, uint32_t baudrate)
{
	volatile Max32662_uart * reg = _uart_reg(id);

	reg->ctrl.bf.bclken  = 0;

	// Setup baudrate
	reg->ctrl.bf.bclksrc = Max32662_uart_clk_ibro;
	reg->clkdiv.bf.clkdiv = MAX32662_IBRO_CLK_HZ / baudrate;

	reg->osr.bf.osr = Max32662_uart_over_samplingx16;

	// FIFO flush
	reg->ctrl.bf.rx_flush = 1;
	reg->ctrl.bf.tx_flush = 1;

	// Setup format
	reg->ctrl.bf.char_size = 3; // 8bits
	reg->ctrl.bf.stopbits  = 0; // 1 stop bit
	reg->ctrl.bf.par_en    = 0; // No parity
	reg->ctrl.bf.cts_dis   = 1; // Disable CTS

	// Enable baudrate
//	reg->ctrl.bf.bclken  = 1;
	reg->ctrl.dword |= (1<<15);
	while (reg->ctrl.bf.bclkrdy == 0);

	// setup interrupt
	reg->ctrl.bf.rx_thd_val = 1; // FIFO threshold is  1byte
	reg->inten.bf.rx_thd = 1;
//	reg->inten.bf.tx_ae  = 1;

	if (id == Max32662_uart0) {
		__enable_nvic_irq(MAX32662_IRQNUM_UART0);
	}
	else {
		__enable_nvic_irq(MAX32662_IRQNUM_UART1);
	}

	return 0;
}


int max32662_uart_register_cb(Max32662_uart_id id, Max32662_uart_rx_done_func rx_cb)
{
	// Register 
	ctx[id].rx_cb = rx_cb;

	return 0;
}


int max32662_uart_tx(Max32662_uart_id id, uint8_t *buf, size_t len)
{
	volatile Max32662_uart * reg = _uart_reg(id);

	//J 一旦すべてFIFOに積む
	while (len-- != 0) {
		_fifo_push(&(ctx[id].tx), *buf++);
	}

	//J FW FIFOに積めるだけ積む
	if (reg->status.bf.tx_em != 0) {
		uint8_t ch=0;
		while ((reg->status.bf.tx_full == 0) && (_FIFO_LEN(&(ctx[id].tx)) > 0)) {
			(void)_fifo_pop(&(ctx[id].tx), &ch);
			reg->fifo.bf.data = ch;
		}
	}

	//J FIFOに積んだら割込有効にする
	reg->inten.bf.tx_ae  = 1;
	reg->inten.bf.tx_he  = 1;

	return 0;
}

int max32662_uart_tx_b(Max32662_uart_id id, uint8_t *buf, size_t len)
{
	volatile Max32662_uart * reg = _uart_reg(id);

	//J 一旦すべてFIFOに積む
	while (len-- != 0) {
		while (reg->status.bf.tx_full == 1);
		reg->fifo.bf.data = *buf++;
	}

	return 0;
}


int max32662_uart_rx(Max32662_uart_id id, uint8_t *buf, size_t len, size_t *rxlen)
{
	//J BufがNULLだった場合には，サイズだけ返す
	if (buf == NULL) {
		*rxlen = _FIFO_LEN((&ctx[id].rx));
		return 0;
	}

	size_t tmp_len = _FIFO_LEN((&ctx[id].rx));
	*rxlen = (tmp_len <= len) ? len : tmp_len;
	if (tmp_len == 0) {
		return -1;
	}

	for (size_t i=0 ; i<*rxlen ; ++i) {
		_fifo_pop(&ctx[id].rx, &buf[i]);
	}

	return 0;
}

size_t max32662_uart_tx_check_buf(Max32662_uart_id id)
{
	return (UART_FIFO_SIZE - 1)- _FIFO_LEN((&ctx[id].tx));
}


