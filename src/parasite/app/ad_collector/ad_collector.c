/*
 * console.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"

#include <string.h>

#include "parasite.h"
#include "adc.h"

#include "app/ad_collector.h"

#define _ADC_BUF_LEN			(8)

static uint16_t a0[_ADC_BUF_LEN];
static uint16_t a1[_ADC_BUF_LEN];
static uint16_t a2[_ADC_BUF_LEN];
static uint16_t a3[_ADC_BUF_LEN];

static DriverAdcBuf sResult = 
{
	.len = _ADC_BUF_LEN,
	.buf = {a0, a1, a2, a3},
	.wptr = 0,
};


void analog_collector_init(void)
{
	volatile int x = 1000000;
	while(x--);

	driver_adc_init(100, &sResult);

	return;
}

int analog_collector_get(uint32_t ch, uint16_t *buf)
{
	if (ch >= 4) return -1;

	uint16_t i = (sResult.wptr - 1) & (_ADC_BUF_LEN - 1);

	*buf = sResult.buf[ch][i];

	return 0;
}
