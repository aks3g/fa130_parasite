/*
 * max32662_i2c.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 
#ifndef _MAX32662_I2C_H_
#define _MAX32662_I2C_H_

#include <stdint.h>
#include <stddef.h>


typedef struct 
{
	// +0x0000
	union {
		uint32_t dword;
		struct {
			uint32_t en					: 1;
			uint32_t mst_mode			: 1;
			uint32_t gc_addr_en			: 1;
			uint32_t irxm_en			: 1;
			uint32_t irxm_ack			: 1;
			uint32_t rsvd5				: 1;
			uint32_t scl_out			: 1;
			uint32_t sda_out			: 1;
			uint32_t scl				: 1;
			uint32_t sda				: 1;
			uint32_t bb_mode			: 1;
			uint32_t read				: 1;
			uint32_t clkstr_dis 		: 1;
			uint32_t rsvd13				: 1;
			uint32_t rsvd14				: 1;
			uint32_t hs_en				: 1;
			uint32_t rsvd16_31			: 16;
		} bf;
	} ctrl;

	// +0x0004
	union {
		uint32_t dword;
		struct {
			uint32_t busy				: 1;
			uint32_t rx_em				: 1;
			uint32_t rx_full			: 1;
			uint32_t tx_em				: 1;
			uint32_t tx_full			: 1;
			uint32_t mst_busy			: 1;
			uint32_t rsvd6_31			: 26;
		}bf;
	} status;

	// +0x0008
	union {
		uint32_t dword;
		struct {
			uint32_t done				: 1;
			uint32_t irxm				: 1;
			uint32_t gc_addr_match		: 1;
			uint32_t addr_match			: 1;
			uint32_t rx_thd				: 1;
			uint32_t tx_thd				: 1;
			uint32_t stop				: 1;
			uint32_t addr_ack			: 1;
			uint32_t arb_err			: 1;
			uint32_t to_err				: 1;
			uint32_t addr_nack_err		: 1;
			uint32_t data_err			: 1;
			uint32_t dnr_err			: 1;
			uint32_t start_err			: 1;
			uint32_t stop_err			: 1;
			uint32_t tx_lockout			: 1;
			uint32_t mami				: 4;
			uint32_t rsvd20_21			: 2;
			uint32_t rd_addr_match		: 1;
			uint32_t wr_addr_match		: 1;
			uint32_t rsvd24_31			: 8;
		} bf;
	} intfl0;

	// +0x000C
	union {
		uint32_t dword;
		struct {
			uint32_t done				: 1;
			uint32_t irxm				: 1;
			uint32_t gc_addr_match		: 1;
			uint32_t addr_match			: 1;
			uint32_t rx_thd				: 1;
			uint32_t tx_thd				: 1;
			uint32_t stop				: 1;
			uint32_t addr_ack			: 1;
			uint32_t arb_err			: 1;
			uint32_t to_err				: 1;
			uint32_t addr_nack_err		: 1;
			uint32_t data_err			: 1;
			uint32_t dnr_err			: 1;
			uint32_t start_err			: 1;
			uint32_t stop_err			: 1;
			uint32_t tx_lockout			: 1;
			uint32_t mami				: 4;
			uint32_t rsvd20_21			: 2;
			uint32_t rd_addr_match		: 1;
			uint32_t wr_addr_match		: 1;
			uint32_t rsvd24_31			: 8;
		} bf;
	} inten0;

	// +0x0010
	union {
		uint32_t dword;
		struct {
			uint32_t rx_ov				: 1;
			uint32_t tx_un				: 1;
			uint32_t start				: 1;
			uint32_t rsvd3_31			:29;
		} bf;
	} intfl1;

	// +0x0014
	union {
		uint32_t dword;
		struct {
			uint32_t rx_ov				: 1;
			uint32_t tx_un				: 1;
			uint32_t start				: 1;
			uint32_t rsvd3_31			:29;
		} bf;
	} inten1;

	// +0x0018
	union {
		uint32_t dword;
		struct {
			uint32_t rx_depth			: 8;
			uint32_t tx_depth			: 8;
			uint32_t rsvd16_31			:16;
		} bf;
	} fifolen;

	// +0x001C
	union {
		uint32_t dword;
		struct {
			uint32_t dnr				: 1;
			uint32_t rsvd1_6			: 6;
			uint32_t flush				: 1;
			uint32_t thd_lvl			: 4;
			uint32_t rsvd12_31			: 20;
		} bf;
	} rxctrl0;

	// +0x0020
	union {
		uint32_t dword;
		struct {
			uint32_t cnt				: 8;
			uint32_t lvl				: 4;
			uint32_t rsvd12_31			: 20;
		} bf;
	} rxctrl1;

	// +0x0024
	union {
		uint32_t dword;
		struct {
			uint32_t preload_mode		: 1;
			uint32_t tx_ready_mode		: 1;
			uint32_t gc_addr_flush_dis	: 1;
			uint32_t wr_addr_flush_dis	: 1;
			uint32_t rd_addr_flush_dis	: 1;
			uint32_t nack_flush_dis		: 1;
			uint32_t rsvd6				: 1;
			uint32_t flush				: 1;
			uint32_t thd_lvl			: 4;
			uint32_t rsvd12_31			: 20;
		} bf;
	} txctrl0;

	// +0x0028
	union {
		uint32_t dword;
		struct {
			uint32_t preload_rdy		: 1;
			uint32_t rsvd1_7			: 7;
			uint32_t lvl				: 4;
			uint32_t rsvd12_31			: 20;
		} bf;
	} txctrl1;

	// +0x002C
	union {
		uint32_t dword;
		struct {
			uint32_t data				: 8;
			uint32_t rsvd8_31			: 24;
		} bf;
	} fifo;

	// +0x0030
	union {
		uint32_t dword;
		struct {
			uint32_t start				: 1;
			uint32_t restart			: 1;
			uint32_t stop				: 1;
			uint32_t rsvd3_6			: 4;
			uint32_t ex_addr_en			: 1;
			uint32_t rsvd8_10			: 3;
			uint32_t rsvd11_31			: 21;
		} bf;
	} mstctrl;

	// +0x0034
	union {
		uint32_t dword;
		struct {
			uint32_t lo					: 9;
			uint32_t rsvd9_31			: 23;
		} bf;
	} clklo;

	// +0x0038
	union {
		uint32_t dword;
		struct {
			uint32_t hi					: 9;
			uint32_t rsvd9_31			: 23;
		} bf;
	} clkhi;

	// +0x003C
	union {
		uint32_t dword;
		struct {
			uint32_t lo					: 8;
			uint32_t hi					: 8;
			uint32_t rsvd9_31			: 16;
		} bf;
	} hsclk;

	// +0x0040
	union {
		uint32_t dword;
		struct {
			uint32_t scl_to_val			: 16;
			uint32_t rsvd9_31			: 16;
		} bf;
	} timeout;

	// +0x0044
	uint32_t rsvd_0x0044;

	// +0x0048
	union {
		uint32_t dword;
		struct {
			uint32_t tx_en				: 1;
			uint32_t rx_en				: 1;
			uint32_t rsvd2_31			: 30;
		} bf;
	} dma;

	// +0x004C
	union {
		uint32_t dword;
		struct {
			uint32_t addr				: 10;
			uint32_t dis				: 1;
			uint32_t rsvd11_14			: 4;
			uint32_t ext_addr_en		: 1;
			uint32_t rsvd2_31			: 16;
		} bf;
	} slave0;

	// +0x0050
	union {
		uint32_t dword;
		struct {
			uint32_t addr				: 10;
			uint32_t dis				: 1;
			uint32_t rsvd11_14			: 4;
			uint32_t ext_addr_en		: 1;
			uint32_t rsvd2_31			: 16;
		} bf;
	} slave1;

	// +0x0054
	union {
		uint32_t dword;
		struct {
			uint32_t addr				: 10;
			uint32_t dis				: 1;
			uint32_t rsvd11_14			: 4;
			uint32_t ext_addr_en		: 1;
			uint32_t rsvd2_31			: 16;
		} bf;
	} slave2;

	// +0x0058
	union {
		uint32_t dword;
		struct {
			uint32_t addr				: 10;
			uint32_t dis				: 1;
			uint32_t rsvd11_14			: 4;
			uint32_t ext_addr_en		: 1;
			uint32_t rsvd2_31			: 16;
		} bf;
	} slave3;

} Max32662_reg_i2c;


typedef enum
{
	max32662_i2c0 = 0,
	max32662_i2c1 = 1
} max32662_i2c_id;

#define MAX32662_I2C_CTRL_MST_MODE_TARGET_MODE			(0)
#define MAX32662_I2C_CTRL_MST_MODE_CONTROLLER_MODE		(1)


#define MAX32662_I2C0		((volatile Max32662_reg_i2c *)0x4001D000)
#define MAX32662_I2C1		((volatile Max32662_reg_i2c *)0x4001E000)


extern int max32662_i2c_initialize(max32662_i2c_id id, uint32_t scl_clk_Hz, uint32_t peripheral_clk_Hz, uint32_t tx_fifo_size, uint32_t rx_fifo_size);
extern int max32662_i2c_transfer(max32662_i2c_id id, uint8_t addr,  uint8_t *txbuf, size_t txsize, uint8_t *rxbuf, size_t rxsize);

#endif//_MAX32662_I2C_H_