/*
 * max32662_dmac.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 
#ifndef _MAX32662_DMAC_H_
#define _MAX32662_DMAC_H_

#include <stdint.h>
#include <stddef.h>

typedef struct 
{
	// +0x0000
	union {
		uint32_t dword;
		struct {
			uint32_t en						: 1;
			uint32_t rlden					: 1;
			uint32_t pri					: 2;
			uint32_t request				: 6;
			uint32_t to_wait				: 1;
			uint32_t to_per					: 3;
			uint32_t to_clkdiv				: 2;
			uint32_t srcwd					: 2;
			uint32_t srcinc					: 1;
			uint32_t rsvd19					: 1;
			uint32_t dstwd					: 2;
			uint32_t dstinc					: 1;
			uint32_t rsvd23					: 1;
			uint32_t burst_size				: 5;
			uint32_t rsvd29					: 1;
			uint32_t dis_ie					: 1;
			uint32_t ctz_ie					: 1;
		} bf;
	} ctrl;
	
	// +0x0004
	union {
		uint32_t dword;
		struct {
			uint32_t status					: 1;
			uint32_t ipend					: 1;
			uint32_t ctz_if					: 1;
			uint32_t rld_if					: 1;
			uint32_t bus_err				: 1;
			uint32_t rsvd5					: 1;
			uint32_t to_if					: 1;
			uint32_t rsvd7_31				: 25;
		} bf;
	} status;
	
	// +0x0008
	uint32_t src;

	// +0x000C
	uint32_t dst;
	
	// +0x0010
	union {
		uint32_t dword;
		struct {
			uint32_t cnt					: 24;
			uint32_t rsvd24_31				: 8;
		} bf;
	} cnt;

	// +0x0014
	union {
		uint32_t dword;
		struct {
			uint32_t addr					: 31;
			uint32_t rsvd31					: 1;
		} bf;
	} srcrld;

	// +0x0018
	union {
		uint32_t dword;
		struct {
			uint32_t addr					: 31;
			uint32_t rsvd31					: 1;
		} bf;
	} dstrld;

	// +0x001C
	union {
		uint32_t dword;
		struct {
			uint32_t cnt					: 24;
			uint32_t rsvd24_30				: 7;
			uint32_t ren					: 1;
		} bf;
	} cntrld;
} Max32662_reg_dmac_channel;

typedef struct 
{
	// +0x0000
	union {
		uint32_t dword;
		struct {
			uint32_t ch0				: 1;
			uint32_t ch1				: 1;
			uint32_t ch2				: 1;
			uint32_t ch3				: 1;
			uint32_t rsvd4_31			: 28;
		} bf;
	} inten;

	// +0x0004
	union {
		uint32_t dword;
		struct {
			uint32_t ch0				: 1;
			uint32_t ch1				: 1;
			uint32_t ch2				: 1;
			uint32_t ch3				: 1;
			uint32_t rsvd4_31			: 28;
		} bf;
	} intfl;


	uint8_t reserved_0x0008_0x00FF[256 - 2*sizeof(uint32_t)];

	Max32662_reg_dmac_channel ch[4];
} Max32662_reg_dmac;


#define MAX32662_DMAC		((volatile Max32662_reg_dmac *)0x40028000)

typedef enum 
{
	Max32662_dmac_ch0 = 0,
	Max32662_dmac_ch1,
	Max32662_dmac_ch2,
	Max32662_dmac_ch3,
	Max32662_dmac_ch_MAX,
} Max32662_dmac_ch;

typedef enum
{
	Max32662_dmac_req_mem_to_mem		= 0x00,
	Max32662_dmac_req_spi0_to_mem		= 0x01,
	Max32662_dmac_req_spi1_to_mem		= 0x02,
	Max32662_dmac_req_uart0_to_mem		= 0x04,
	Max32662_dmac_req_uart1_to_mem		= 0x05,
	Max32662_dmac_req_can_to_mem		= 0x06,
	Max32662_dmac_req_i2c0_to_mem		= 0x07,
	Max32662_dmac_req_i2c1_to_mem		= 0x08,
	Max32662_dmac_req_adc_to_mem		= 0x09,
	Max32662_dmac_req_i2c2_to_mem		= 0x0A,
	Max32662_dmac_req_i2s_to_mem		= 0x1E,
	Max32662_dmac_req_mem_to_spi0		= 0x21,
	Max32662_dmac_req_mem_to_spi1		= 0x22,
	Max32662_dmac_req_mem_to_uart0		= 0x24,
	Max32662_dmac_req_mem_to_uart1		= 0x25,
	Max32662_dmac_req_mem_to_can		= 0x26,
	Max32662_dmac_req_mem_to_i2c0		= 0x27,
	Max32662_dmac_req_mem_to_i2c1		= 0x28,
	Max32662_dmac_req_mem_to_i2s		= 0x3E,
} Max32662_dmac_request;

typedef struct 
{
	void     *src;
	uint32_t burst_size;
	uint32_t srcwd;
	uint32_t srcinc;
	uint32_t cnt;
} Max32662_dmac_cfg_src_to_dma_fifo;

typedef struct 
{
	void     *dst;
	uint32_t burst_size;
	uint32_t dstwd;
	uint32_t dstinc;
} Max32662_dmac_cfg_dst_from_dma_fifo;


#define MAX32662_DMAC_CODE_CTZ				(0) // Counter is Zero
#define MAX32662_DMAC_CODE_DIS				(1) // Channel Disable
#define MAX32662_DMAC_CODE_RLD				(2) // Reload
#define MAX32662_DMAC_CODE_BUS_ERR			(3) // Bus Error
#define MAX32662_DMAC_CODE_TO				(4) // Time out
#define MAX32662_DMAC_CODE_UNKNWON			(5)

typedef void (*Max32662_dmac_transfer_done_callback)(int);

extern int max32662_dmac_initialize(void);
extern int max32662_dmac_setup(Max32662_dmac_ch ch, Max32662_dmac_request req, Max32662_dmac_cfg_src_to_dma_fifo *src, Max32662_dmac_cfg_dst_from_dma_fifo *dst);
extern int max32662_dmac_start_transfer(Max32662_dmac_ch ch, Max32662_dmac_transfer_done_callback cb);

#endif//_MAX32662_DMAC_H_