/*
 * max32662.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 

#ifndef _MAX32662_H_
#define _MAX32662_H_

typedef struct 
{
	// +0x0000
	uint32_t rsvd0;
	
	// +0x0004
	union {
		uint32_t dword;
		struct {
			uint32_t tmr3		: 1;
			uint32_t rsvd1_2	: 2;
			uint32_t rtc		: 1;
			uint32_t rsvd4_31	: 28;
		} bf;
	} rst;
	
	// +0x0008
	union {
		uint32_t dword;
		struct {
			uint32_t rsvd0_15	: 16;
			uint32_t ertco_pd	: 1;
			uint32_t ertco_en	: 1;
			uint32_t rsvd18_31	: 14;
		} bf;
	} clkctrl;
	// +0x000C
	union {
		uint32_t dword;
		struct {
			uint32_t pd0		: 1;
			uint32_t pd1		: 1;
			uint32_t hyst		: 2;
			uint32_t rsvd4_15	: 12;
			uint32_t nsel_comp0	: 2;
			uint32_t rsvd18_19	: 2;
			uint32_t psel_comp0	: 2;
			uint32_t rsvd22_23	: 2;
			uint32_t nsel_comp1	: 2;
			uint32_t rsvd26_27	: 2;
			uint32_t psel_comp1	: 2;
			uint32_t rsvd30_31	: 2;
		} bf;
	} aincomp;
	// +0x0010
	union {
		uint32_t dword;
		struct {
			uint32_t tmr3_in	: 1;
			uint32_t tmr3_out	: 1;
			uint32_t tmr3_out_n	: 1;
			uint32_t rsvd3_31	: 29;
		} bf;
	} lppioctrl;
	// +0x0014 - 0x0020
	uint32_t rsvd0x0014;
	uint32_t rsvd0x0018;
	uint32_t rsvd0x001c;
	uint32_t rsvd0x0020;
	// +0x0024
	union {
		uint32_t dword;
		struct {
			uint32_t tmr3		: 1;
			uint32_t rsvd1_31	: 31;
		} bf;
	} pclkdis;
	// +0x0028 - 0x0030
	uint32_t rsvd0x0028;
	uint32_t rsvd0x002C;
	uint32_t rsvd0x0030;
	// +0x0034
	union {
		uint32_t dword;
		struct {
			uint32_t ptr		: 16;
			uint32_t rsvd16_31	: 16;
		} bf;
	} aeskey;
	// +0x0038
	union {
		uint32_t dword;
		struct {
			uint32_t lp_extclk_en	: 1;
			uint32_t rsvd1		: 1;
			uint32_t ext_ref	: 1;
			uint32_t int_ref	: 1;
			uint32_t rsvd4_31	: 28;
		} bf;
	} adccfg0;
	// +0x003C
	union {
		uint32_t dword;
		struct {
			uint32_t thu_pad_sw_en	: 4;
			uint32_t ain_inp_en	: 4;
			uint32_t thru_en	: 1;
			uint32_t amp_en		: 1;
			uint32_t amp_rri_en	: 1;
			uint32_t div_sel	: 2;
			uint32_t rsvd13_31	: 19;
		} bf;
	} adccfg1;
	// +0x0040
	union {
		uint32_t dword;
		struct {
			uint32_t vrefm		: 7;
			uint32_t rsvd7		: 1;
			uint32_t vrefp		: 7;
			uint32_t rsvd15		: 1;
			uint32_t idrv		: 4;
			uint32_t vcm		: 2;
			uint32_t rsvd22_23	: 2;
			uint32_t d_iboost	: 1;
			uint32_t rsvd24_31	: 7;
		} bf;
	} adccfg2;
} Max32662_mcr;
	

typedef enum
{
	Max32662_adc_no_div = 0,
	Max32662_adc_div_1,
	Max32662_adc_div_2,
	Max32662_adc_div_3,
} Max32662_adc_div;

typedef enum 
{
	Max32662_adc_ref_int = 0,
	Max32662_adc_ref_ext,
} MAX32662_adc_ref;

typedef enum 
{
	Max32662_adc_ref_1_25v = 0,
	Max32662_adc_ref_2_048v,
} MAX32662_adc_vref;


#define MAX32662_MCR		((volatile Max32662_mcr*)0x40106C00)


#endif//_MAX32662_H_

