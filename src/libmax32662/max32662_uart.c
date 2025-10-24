/*
 * max32662_uart.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 

#include "max32662_uart.h"
#include "max32662_clock.h"


static Max32662_uart_rx_done_func _rx_cb[2];
static Max32662_uart_tx_done_func _tx_cb[2];



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

	return 0;
}


int max32662_uart_enable_intr(Max32662_uart_id id, Max32662_uart_tx_done_func tx_cb, Max32662_uart_rx_done_func rx_cb)
{
	volatile Max32662_uart * reg = _uart_reg(id);

	// Enable Rx FIFO Threshold and Tx FIFO Almost Empty
	reg->inten.bf.rx_thd = 1;
	reg->inten.bf.tx_ae  = 1;

	_rx_cb[id] = rx_cb;
	_tx_cb[id] = tx_cb;

	return 0;
}


int max32662_uart_tx(Max32662_uart_id id, uint8_t c)
{
	volatile Max32662_uart * reg = _uart_reg(id);

	reg->fifo.bf.data = c;

	return 0;
}

