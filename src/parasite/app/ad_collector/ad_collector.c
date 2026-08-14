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

//static float a0[ADC_BUF_LEN];
static uint16_t a0[ADC_BUF_LEN];
//static float a1[ADC_BUF_LEN];
//static float a2[ADC_BUF_LEN];
//static float a3[ADC_BUF_LEN];

static DriverAdcBuf sResult = 
{
	.len = ADC_BUF_LEN,
//	.fbuf = {a0, a1, NULL, NULL},
//	.fbuf = {a0, NULL, NULL, NULL},
	.buf = {a0, NULL, NULL, NULL},
	.wptr = 0,
};


void analog_collector_init(void)
{
	volatile int x = 1000000;
	while(x--);
	
	memset(a0, 0, sizeof(a0));
//	memset(a1, 0, sizeof(a1));
//	memset(a2, 0, sizeof(a2));
//	memset(a3, 0, sizeof(a3));

	sResult.buf[0] = a0;
//	sResult.fbuf[0] = a0;
//	sResult.fbuf[1] = a1;
//	sResult.fbuf[2] = a2;
//	sResult.fbuf[3] = a3;

	driver_adc_init(4000, &sResult);

	return;
}

#if 0
int analog_collector_get(uint32_t ch, float *fbuf)
{
	if (ch >= 4) return -1;

	uint16_t i = sResult.wptr;

	memcpy (&fbuf[0],               &sResult.fbuf[ch][i], sizeof(float)*(ADC_BUF_LEN - i));
	memcpy (&fbuf[ADC_BUF_LEN - i], &sResult.fbuf[ch][0], sizeof(float)*(              i));

	return 0;
}
#else

int analog_collector_get(uint32_t ch, uint16_t *buf)
{
	if (ch >= 4) return -1;

	uint16_t i = sResult.wptr;

	memcpy (&buf[0],               &sResult.buf[ch][i], sizeof(uint16_t)*(ADC_BUF_LEN - i));
	memcpy (&buf[ADC_BUF_LEN - i], &sResult.buf[ch][0], sizeof(uint16_t)*(              i));

	return 0;
}
#endif
