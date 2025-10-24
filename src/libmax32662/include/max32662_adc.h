/*
 * max32662_goio.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 
#ifndef _MAX32662_ADC_H_
#define _MAX32662_ADC_H_

#include <stdint.h>
#include <stddef.h>

#include "max32662.h"

typedef struct
{
	// +0x0000
	union {
		uint32_t dword;
		struct
		{
			uint32_t adc_en		: 1;
			uint32_t bias_en	: 1;
			uint32_t skip_cal	: 1;
			uint32_t chop_force	: 1;
			uint32_t resetb		: 1;
			uint32_t rsvd5_31	: 27;
		} bf;
	} ctrl0;

	// +0x0004
	union {
		uint32_t dword;
		struct {
			uint32_t start		: 1;
			uint32_t trig_mode	: 1;
			uint32_t cnv_mode	: 1;
			uint32_t samp_cK_off	: 1;
			uint32_t trig_sel	: 3;
			uint32_t rsvd7		: 1;
			uint32_t avg		: 3;
			uint32_t rsvd11_15	: 5;
			uint32_t num_slots	: 5;
			uint32_t rsvd21_31	: 11;
		} bf;
	} ctrl1;

	// +0x0008
	union {
		uint32_t dword;
		struct {
			uint32_t clksel		: 2;
			uint32_t rsvd2_3	: 2;
			uint32_t clkdiv		: 3;
			uint32_t rsvd7_31	: 25;
		} bf;
	} clkctrl;

	// +0x000C
	union {
		uint32_t dword;
		struct {
			uint32_t track_cnt	: 10;
			uint32_t rsvd10_15	: 6;
			uint32_t idle_cnt	: 16;
		} bf;
	} sampclkctrl;

	// +0x0010
	union {
		uint32_t dword;
		struct {
			uint32_t slot0_id	: 5;
			uint32_t rsvd5_7	: 3;
			uint32_t slot1_id	: 5;
			uint32_t rsvd13_15	: 3;
			uint32_t slot2_id	: 5;
			uint32_t rsvd21_23	: 3;
			uint32_t slot3_id	: 5;
			uint32_t rsvd29_31	: 3;
		} bf;
	} chsel0;

	// +0x0014
	union {
		uint32_t dword;
		struct {
			uint32_t slot4_id	: 5;
			uint32_t rsvd5_7	: 3;
			uint32_t slot5_id	: 5;
			uint32_t rsvd13_15	: 3;
			uint32_t slot6_id	: 5;
			uint32_t rsvd21_23	: 3;
			uint32_t slot7_id	: 5;
			uint32_t rsvd29_31	: 3;
		} bf;
	} chsel1;

	// +0x0018 - 0x0028
	uint32_t rsvd_0x0018;
	uint32_t rsvd_0x001C;
	uint32_t rsvd_0x0020;
	uint32_t rsvd_0x0024;
	uint32_t rsvd_0x0028;

	// +0x002C
	union {
		uint32_t dword;
		struct {
			uint32_t cnt		: 16;
			uint32_t rsvd16_31	: 16;
		} bf;
	} restart;

	// +0x0030 - 0x0038
	uint32_t rsvd_0x0030;
	uint32_t rsvd_0x0034;
	uint32_t rsvd_0x0038;

	// +0x003C
	uint32_t datafmt;

	// +0x0040
	union {
		uint32_t dword;
		struct {
			uint32_t dma_en		: 1;
			uint32_t flush		: 1;
			uint32_t data_format	: 2;
			uint32_t rsvd4_7	: 4;
			uint32_t thresh		: 8;
			uint32_t rsvd16_31	: 16;
		} bf;
	} fifodmactrl;

	// +0x004
	union {
		uint32_t dword;
		struct {
			uint32_t data		: 16;
			uint32_t chan		: 5;
			uint32_t rsvd21_23	: 3;
			uint32_t invalid	: 1;
			uint32_t rsvd25_30	: 6;
			uint32_t clipped	: 1;
		} bf;
	} data;

	// +0x0048
	union {
		uint32_t dword;
		struct {
			uint32_t ready		: 1;
			uint32_t empty		: 1;
			uint32_t full		: 1;
			uint32_t rsvd3_7	: 5;
			uint32_t fifo_level	: 8;
			uint32_t rsvd16_31	:16;
		} bf;
	} status;

	// +0x004c
	union
	{
		uint32_t dword;
		struct {
			uint32_t clipped	: 16;
			uint32_t rsvd16_31	: 16;
		} bf;
	} chstatus;


	// +0x0050
	union {
		uint32_t dword;
		struct {
			uint32_t ready		: 1;
			uint32_t rsvd1		: 1;
			uint32_t abort		: 1;
			uint32_t start_det	: 1;
			uint32_t seq_started	: 1;
			uint32_t seq_done	: 1;
			uint32_t conv_done	: 1;
			uint32_t clipped	: 1;
			uint32_t fifo_lvl	: 1;
			uint32_t fifo_full	: 1;
			uint32_t fifo_ofl	: 1;
			uint32_t rsvd11_31	: 21;
		} bf;
	} inten;

	// +0x0054
	union {
		uint32_t dword;
		struct {
			uint32_t ready		: 1;
			uint32_t rsvd1		: 1;
			uint32_t abort		: 1;
			uint32_t start_det	: 1;
			uint32_t seq_started	: 1;
			uint32_t seq_done	: 1;
			uint32_t conv_done	: 1;
			uint32_t clipped	: 1;
			uint32_t fifo_lvl	: 1;
			uint32_t fifo_full	: 1;
			uint32_t fifo_ofl	: 1;
			uint32_t rsvd11_31	: 21;
		} bf;
	} intfl;

	// +0x0058-0x005C
	uint32_t rsvd0x0058;
	uint32_t rsvd0x005C;

	// +0x0060
	union{
		uint32_t dword;
		struct {
			uint32_t offset		: 16;
			uint32_t rsvd16_31	: 16;
		} bf;
	} sfraddroffset;

	// +0x0064
	union{
		uint32_t dword;
		struct {
			uint32_t addr		: 16;
			uint32_t rsvd16_31	: 16;
		} bf;
	} sfraddr;

	// +0x0068
	union{
		uint32_t dword;
		struct {
			uint32_t data		: 16;
			uint32_t rsvd16_31	: 16;
		} bf;
	} sfrwrdata;

	// +0x006C
	union{
		uint32_t dword;
		struct {
			uint32_t data		: 16;
			uint32_t rsvd16_31	: 16;
		} bf;
	} sfrrddata;

	// +0x0070
	union{
		uint32_t dword;
		struct {
			uint32_t nack		: 1;
			uint32_t rsvd1_31	: 31;
		} bf;
	} sfrstatus;

} Max32662_adc;

typedef union
{
	uint32_t dword;
	struct {
		uint32_t data		: 12;
		uint32_t rsvd12_15	: 4;
		uint32_t chan		: 5;
		uint32_t rsvd21_23	: 3;
		uint32_t invalid	: 1;
		uint32_t rsvd25_30	: 6;
		uint32_t clipped	: 1;
	} bf;
} Max32662_adc_result;


typedef enum
{
	Max32662_adc_ch_ain0 = 0,
	Max32662_adc_ch_ain1,
	Max32662_adc_ch_ain2,
	Max32662_adc_ch_ain3,
	Max32662_adc_ch_rsvd4,
	Max32662_adc_ch_rsvd5,
	Max32662_adc_ch_rsvd6,
	Max32662_adc_ch_rsvd7,
	Max32662_adc_ch_rsvd8,
	Max32662_adc_ch_rsvd9,
	Max32662_adc_ch_rsvd10,
	Max32662_adc_ch_rsvd11,
	Max32662_adc_ch_vdda_2,
	Max32662_adc_ch_rsvd13,
	Max32662_adc_ch_vcore,
	Max32662_adc_ch_vssa,
	Max32662_adc_ch_rsvd16,
	Max32662_adc_ch_rsvd17,
	Max32662_adc_ch_vddio_4,
} Max32662_adc_ch;

typedef enum
{
	Max32662_adc_clksel_sys_osc = 0,
	Max32662_adc_clksel_hf_ext_clk,
	Max32662_adc_clksel_ibro,
	Max32662_adc_clksel_erfo,
} Max32662_adc_clksel;

typedef enum
{
	Max32662_adc_clkdiv_by_2 = 0,
	Max32662_adc_clkdiv_by_4,
	Max32662_adc_clkdiv_by_8,
	Max32662_adc_clkdiv_by_16,
	Max32662_adc_clkdiv_by_1,
} Max32662_adc_clkdiv;

typedef enum
{
	Max32662_adc_amp_disabled = 0,
	Max32662_adc_amp_enabled  = 1,
} Max32662_adc_amp;


typedef void (*Max32662_adc_conv_done_callback)(Max32662_adc_result *result, size_t size);


#define MAX32662_ADC			((volatile Max32662_adc *)0x40034000)

int max32661_adc_init(Max32662_adc_amp amp, Max32662_adc_div div, MAX32662_adc_vref vref);
int max32662_adc_setup_conversion(Max32662_adc_ch *ch_arr, size_t arr_size);
int max32662_adc_start_conversion(Max32662_adc_result *result, size_t size, Max32662_adc_conv_done_callback cb);


#endif//_MAX32662_ADC_H_
