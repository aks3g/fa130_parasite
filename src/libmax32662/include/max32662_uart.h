/*
 * max32662_uart.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 
#ifndef _MAX32662_UART_H_
#define _MAX32662_UART_H_

#include <stdint.h>
#include <stddef.h>

typedef struct {
	// +0x0000
	union {
		uint32_t dword;
		struct {
			uint32_t rx_thd_val : 4;
			uint32_t par_en     : 1;
			uint32_t par_eo     : 1;
			uint32_t par_md     : 1;
			uint32_t cts_dis    : 1;
			uint32_t tx_flush   : 1;
			uint32_t rx_flush   : 1;
			uint32_t char_size  : 2;
			uint32_t stopbits   : 1;
			uint32_t hfc_en     : 1;
			uint32_t rtsdc      : 1;
			uint32_t bclken     : 1;
			uint32_t bclksrc    : 2;
			uint32_t dpfe_en    : 1;
			uint32_t bclkrdy    : 1;
			uint32_t ucagm      : 1;
			uint32_t fdm        : 1;
			uint32_t desm       : 1;
			uint32_t rsvd23_31  : 9;
		} bf;
	} ctrl;

	// +0x0004
	union {
		uint32_t dword;
		struct {
			uint32_t tx_busy    : 1;
			uint32_t rx_busy    : 1;
			uint32_t rsvd2_3    : 2;
			uint32_t rx_em      : 1;
			uint32_t rx_full    : 1;
			uint32_t tx_em      : 1;
			uint32_t tx_full    : 1;
			uint32_t rx_lvl     : 4;
			uint32_t tx_lvl     : 4;
			uint32_t rsvd16_31  : 16;
		} bf;
	} status;

	// +0x0008
	union {
		uint32_t dword;
		struct {
			uint32_t rx_ferr    : 1;
			uint32_t rx_par     : 1;
			uint32_t cts_ev     : 1;
			uint32_t rx_ov      : 1;
			uint32_t rx_thd     : 1;
			uint32_t tx_ae      : 1;
			uint32_t tx_he      : 1;
			uint32_t rsvd7_31   : 25;
		} bf;
	} inten;

	// +0x000C
	union {
		uint32_t dword;
		struct {
			uint32_t rx_ferr    : 1;
			uint32_t rx_par     : 1;
			uint32_t cts_ev     : 1;
			uint32_t rx_ov      : 1;
			uint32_t rx_thd     : 1;
			uint32_t tx_ae      : 1;
			uint32_t tx_he      : 1;
			uint32_t rsvd7_31   : 25;
		} bf;
	} intfl;

	// +0x0010
	union {
		uint32_t dword;
		struct {
			uint32_t clkdiv     : 20;
			uint32_t rsvd20_31  : 12;
		} bf;
	} clkdiv;

	// +0x0014
	union {
		uint32_t dword;
		struct {
			uint32_t osr        : 3;
			uint32_t rsvd3_31   : 29;
		} bf;
	} osr;

	// +0x0018
	union {
		uint32_t dword;
		struct {
			uint32_t data       : 8;
			uint32_t rsvd8_31   : 24;
		} bf;
	} txpeek;

	// +0x001C
	union {
		uint32_t dword;
		struct {
			uint32_t cts        : 1;
			uint32_t rts        : 2;
			uint32_t rsvd2_31   : 30;
		} bf;
	} pnr;

	// +0x0020
	union {
		uint32_t dword;
		struct {
			uint32_t data       : 8;
			uint32_t rx_par     : 1;
			uint32_t rsvd9_31   : 23;
		} bf;
	} fifo;

	// +0x0024 - 0x002C
	uint32_t rsvd0x0024;
	uint32_t rsvd0x0028;
	uint32_t rsvd0x002C;

	// +0x0030
	union {
		uint32_t dword;
		struct {
			uint32_t tx_thd_val : 4;
			uint32_t tx_en      : 1;
			uint32_t rx_thd_val : 4;
			uint32_t rx_en      : 1;
			uint32_t rsvd10_31  : 30;
		} bf;
	} dma;

	// +0x0034
	union {
		uint32_t dword;
		struct {
			uint32_t rx_ne      : 1;
			uint32_t tx_full    : 1;
			uint32_t rx_thd     : 1;
			uint32_t rsvd3_31   : 29;
		} bf;
	} wken;

	// +0x0038
	union {
		uint32_t dword;
		struct {
			uint32_t rx_ne      : 1;
			uint32_t tx_full    : 1;
			uint32_t rx_thd     : 1;
			uint32_t rsvd3_31   : 29;
		} bf;
	} wkfl;
} Max32662_uart;


#define MAX32662_UART0		((volatile Max32662_uart*) 0x40042000)
#define MAX32662_UART1		((volatile Max32662_uart*) 0x40043000)

typedef enum
{
	Max32662_uart0 = 0,
	Max32662_uart1,
} Max32662_uart_id;

typedef enum
{
	Max32662_uart_clk_pclk = 0,
	Max32662_uart_clk_hf_ext,
	Max32662_uart_clk_ibro,
	Max32662_uart_clk_erfo,
} Max32662_uart_clk_src;

typedef enum
{
	Max32662_uart_over_samplingx128 = 0,
	Max32662_uart_over_samplingx64,
	Max32662_uart_over_samplingx32,
	Max32662_uart_over_samplingx16,
	Max32662_uart_over_samplingx8,
	Max32662_uart_over_samplingx4,
} Max32662_uart_over_sampling;


typedef void (*Max32662_uart_tx_done_func)(void);
typedef void (*Max32662_uart_rx_done_func)(uint8_t c);

int max32662_uart_setup(Max32662_uart_id id, uint32_t baudrate);
int max32662_uart_enable_intr(Max32662_uart_id id, Max32662_uart_tx_done_func tx_cb, Max32662_uart_rx_done_func rx_cb);
int max32662_uart_tx(Max32662_uart_id id, uint8_t c);

#endif//_MAX32662_UART_H_
