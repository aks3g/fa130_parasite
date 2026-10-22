/*
 * adc.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"

#include "string.h"

#include "target_syssvc.h"

#include "max32662_gpio.h"
#include "max32662_adc.h"
#include "max32662_timer.h"

#include "driver/adc.h"
#include "driver/timer.h"
#include "driver/gpio.h"

#include "signal_proc/iir_lpf.h"

static DriverAdcBuf *s_pAdcBuf = NULL;

static Max32662_adc_ch ch_arr[] = {
		Max32662_adc_ch_ain0,
		Max32662_adc_ch_ain1,
		Max32662_adc_ch_ain2,
		Max32662_adc_ch_ain3,
};

static Max32662_adc_result _result[sizeof(ch_arr)/sizeof(ch_arr[0])];

static void _adc_cb(Max32662_adc_result *result, size_t size)
{
	if (size != sizeof(ch_arr)/sizeof(ch_arr[0])) while(1);
	if (s_pAdcBuf == NULL) return;

	// Update Value
	s_pAdcBuf->buf[0][s_pAdcBuf->wptr] = (uint16_t)result[0].bf.data;
	s_pAdcBuf->buf[1][s_pAdcBuf->wptr] = (uint16_t)result[1].bf.data;
	s_pAdcBuf->buf[2][s_pAdcBuf->wptr] = (uint16_t)result[2].bf.data;
	s_pAdcBuf->buf[3][s_pAdcBuf->wptr] = (uint16_t)result[3].bf.data;

	s_pAdcBuf->wptr = (s_pAdcBuf->wptr + 1) % s_pAdcBuf->len;

	return;
}

void driver_adc_init(uint16_t conversion_Hz, DriverAdcBuf *buf)
{
	s_pAdcBuf = buf;

	// ADCの起動
	max32661_adc_init(Max32662_adc_amp_enabled, Max32662_adc_div_2, Max32662_adc_ref_2_048v);

	// Dummy Conversion
	max32662_adc_setup_conversion(ch_arr, sizeof(ch_arr)/sizeof(ch_arr[0]), Max32662_adc_trig_soft, 1);
	max32662_adc_start_continuous(_result, sizeof(ch_arr)/sizeof(ch_arr[0]), 100, _adc_cb);

	return;
}

void isr_adc(intptr_t exinf)
{
	(void)exinf;
	max32662_adc_handler();
}
