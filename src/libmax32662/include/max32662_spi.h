/*
 * max32662_i2c.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 
#ifndef _MAX32662_SPI_H_
#define _MAX32662_SPI_H_

#include <stdint.h>
#include <stddef.h>


typedef struct 
{
	// +0x0000
	union {
		uint32_t dword;
		uint16_t word;
		uint8_t byte;
	} fifo;

	// +0x0004
	union {
		uint32_t dword;
		struct {
			uint32_t en					: 1;
			uint32_t mst_mode			: 1;
			uint32_t rsvd_2_3			: 2;
			uint32_t ss_io				: 1;
			uint32_t start 				: 1;
			uint32_t rsvd_6_7			: 2;
			uint32_t ss_ctrl			: 1;
			uint32_t rsvd_9_15			: 7;
			uint32_t ss_active			: 4;
			uint32_t rsvd_20_31			: 12;
		} bf;
	} ctrl0;

	// +0x0008
	union {
		uint32_t dword;
		struct {
			uint32_t tx_num_char		: 16;
			uint32_t rx_num_char		: 16;
		} bf;
	} ctrl1;

	// +0x000C
	union {
		uint32_t dword;
		struct {
			uint32_t clkpha				: 1;
			uint32_t clkpol				: 1;
			uint32_t rsvd_2_7			: 6;
			uint32_t numbits			: 4;
			uint32_t data_width			: 2;
			uint32_t rsvd_14			: 1;
			uint32_t three_wire			: 1;
			uint32_t ss_pol				: 4;
			uint32_t rsvd_20_31			: 12;
		} bf;
	} ctrl2;

	// +0x0010
	union {
		uint32_t dword;
		struct {
			uint32_t pre				: 8;
			uint32_t post				: 8;
			uint32_t inact				: 8;
			uint32_t rsvd_24_31			: 8;
		} bf;
	} sstime;

	// +0x0014
	union {
		uint32_t dword;
		struct {
			uint32_t lo					: 8;
			uint32_t hi					: 8;
			uint32_t clkdiv				: 4;
			uint32_t rsvd_20_31			: 12;
		} bf;
	} clkctrl;

	// +0x0018
	uint32_t rsvd_0x18;

	// +0x001C
	union {
		uint32_t dword;
		struct {
			uint32_t tx_thd_val			: 5;
			uint32_t rsvd_5				: 1;
			uint32_t tx_fifo_en			: 1;
			uint32_t tx_flush			: 1;
			uint32_t tx_lvl				: 7;
			uint32_t dma_tx_en			: 1;
			uint32_t rx_thd_val			: 5;
			uint32_t rsvd_21			: 1;
			uint32_t rx_fifo_en			: 1;
			uint32_t rx_flush			: 1;
			uint32_t rx_lvl				: 7;
			uint32_t dma_rx_en			: 1;
		} bf;
	} dma;

	// +0x0020
	union {
		uint32_t dword;
		struct {
			uint32_t tx_thd				: 1;
			uint32_t tx_em				: 1;
			uint32_t rx_thd				: 1;
			uint32_t rx_full			: 1;
			uint32_t ssa				: 1;
			uint32_t ssd				: 1;
			uint32_t rsvd_6_7			: 2;
			uint32_t fault				: 1;
			uint32_t abort				: 1;
			uint32_t rsvd_10			: 1;
			uint32_t mst_done			: 1;
			uint32_t tx_ov				: 1;
			uint32_t tx_un				: 1;
			uint32_t rx_ov				: 1;
			uint32_t rx_un				: 1;
			uint32_t rsvd_16_31			: 16;
		} bf;
	} intfl;

	// +0x0024
	union {
		uint32_t dword;
		struct {
			uint32_t tx_thd				: 1;
			uint32_t tx_em				: 1;
			uint32_t rx_thd				: 1;
			uint32_t rx_full			: 1;
			uint32_t ssa				: 1;
			uint32_t ssd				: 1;
			uint32_t rsvd_6_7			: 2;
			uint32_t fault				: 1;
			uint32_t abort				: 1;
			uint32_t rsvd_10			: 1;
			uint32_t mst_done			: 1;
			uint32_t tx_ov				: 1;
			uint32_t tx_un				: 1;
			uint32_t rx_ov				: 1;
			uint32_t rx_un				: 1;
			uint32_t rsvd_16_31			: 16;
		} bf;
	} inten;

	// +0x0028
	union {
		uint32_t dword;
		struct {
			uint32_t tx_thd				: 1;
			uint32_t tx_em				: 1;
			uint32_t rx_thd				: 1;
			uint32_t rx_full			: 1;
			uint32_t rsvd_4_31			: 28;
		} bf;
	} wkfl;

	// +0x002C
	union {
		uint32_t dword;
		struct {
			uint32_t tx_thd				: 1;
			uint32_t tx_em				: 1;
			uint32_t rx_thd				: 1;
			uint32_t rx_full			: 1;
			uint32_t rsvd_4_31			: 28;
		} bf;
	} wken;

	// +0x0030
	union {
		uint32_t dword;
		struct {
			uint32_t busy				: 1;
			uint32_t rsvd_1_31			: 31;
		} bf;
	} stat;

} Max32662_reg_spi;


typedef enum
{
	max32662_spi0 = 0,
	max32662_spi1 = 1
} max32662_spi_id;

typedef enum
{
	max32662_spi_mode0 = 0,
	max32662_spi_mode1,
	max32662_spi_mode2,
	max32662_spi_mode3
} max32662_spi_mode;



#define MAX32662_SPI0		((volatile Max32662_reg_spi *)0x40046000)
#define MAX32662_SPI1		((volatile Max32662_reg_spi *)0x40047000)


extern int max32662_spi_master_initialize(max32662_spi_id id, max32662_spi_mode mode, uint32_t sck_MHz, uint32_t peripheral_clk_MHz);
extern int max32662_spi_master_transfer(max32662_spi_id id,  uint8_t *txbuf, uint8_t *rxbuf, size_t tx_size, size_t rx_size);

#endif//_MAX32662_SPI_H_
