/*
 * signal_proc_utils.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#include <stdint.h>
#include <stddef.h>

#include "driver/adc.h"

#include "app/console.h"
#include "app/ad_collector.h"

void signalProc_dump(uint16_t *buf, size_t count)
{
	for (size_t i=0 ; i<count ; ++i) {
		console_printf("%d\n",buf[i]);
	}
}

void signalProc_dump_f(float *buf, size_t count)
{
	for (size_t i=0 ; i<count ; ++i) {
		console_printf("%f\n",buf[i]);
	}
}

#if 0
static float work_buf[ADC_BUF_LEN];
void signalProc_getWorkBuf(float **buf, size_t *count)
{
	*buf = work_buf;
	*count = ADC_BUF_LEN;
}
#else
static uint16_t work_buf[ADC_BUF_LEN];
void signalProc_getWorkBuf(uint16_t **buf, size_t *count)
{
	*buf = work_buf;
	*count = ADC_BUF_LEN;
}


#endif

