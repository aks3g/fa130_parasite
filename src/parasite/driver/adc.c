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
static Iir4thOrderFilter filter[4];

#if 1
static Max32662_adc_ch ch_arr[] = {
		Max32662_adc_ch_ain0,
};
#else
static Max32662_adc_ch ch_arr[] = {
		Max32662_adc_ch_ain1,
		Max32662_adc_ch_ain1,
		Max32662_adc_ch_ain1,
		Max32662_adc_ch_ain1,
		Max32662_adc_ch_ain1,
		Max32662_adc_ch_ain1,
		Max32662_adc_ch_ain1,
		Max32662_adc_ch_ain1,
};
#endif

static Max32662_adc_result _result[sizeof(ch_arr)/sizeof(ch_arr[0])];

static void _adc_cb(Max32662_adc_result *result, size_t size)
{
	// Restart Driver
//	driver_md_ctrl_restart();

	if (size != sizeof(ch_arr)/sizeof(ch_arr[0])) while(1);

	// Update Value
//	s_pAdcBuf->fbuf[0][s_pAdcBuf->wptr] = (float)driver_timer_gettick();
//	s_pAdcBuf->fbuf[0][s_pAdcBuf->wptr] = iir4thOrderFilter_Process(&(filter[0]), (float)result[0].bf.data);
//	s_pAdcBuf->fbuf[0][s_pAdcBuf->wptr] = (float)result[0].bf.data;
	s_pAdcBuf->buf[0][s_pAdcBuf->wptr] = (uint16_t)result[0].bf.data;

	s_pAdcBuf->wptr = (s_pAdcBuf->wptr + 1) % s_pAdcBuf->len;

	return;
}



void driver_adc_init(uint16_t conversion_Hz, DriverAdcBuf *buf)
{

	s_pAdcBuf = buf;

	// ADCの起動
	max32661_adc_init(Max32662_adc_amp_disabled, Max32662_adc_no_div, Max32662_adc_ref_2_048v);
//	max32661_adc_init(Max32662_adc_amp_enabled, Max32662_adc_no_div, Max32662_adc_ref_2_048v);

	// Dummy Conversion
	max32662_adc_setup_conversion(ch_arr, sizeof(ch_arr)/sizeof(ch_arr[0]), Max32662_adc_trig_soft, 0);
	max32662_adc_start_conversion(_result, sizeof(ch_arr)/sizeof(ch_arr[0]), _adc_cb);

	dly_tsk(100);

	//Sampling 4000Hz/ cutoff 500Hz
	for (int i=0 ; i<4 ; ++i) {
		biquadFilter_init(&(filter[i].stage[0]), 0.43284664f, 0.86569329f, 0.43284664f, 1.04859958f, 0.29614036f);
		biquadFilter_init(&(filter[i].stage[1]), 1.00000000f, 2.00000000f, 1.00000000f, 1.32091343f, 0.63273879);
	}

	biquadFilter_reset(&filter[0]);
	biquadFilter_reset(&filter[1]);
	biquadFilter_reset(&filter[2]);
	biquadFilter_reset(&filter[3]);

	return;
}

void driver_adc_reset_trig(Max32662_adc_trig trig)
{
	//J Single Conversion, Hardware Trigger
	max32662_adc_setup_conversion(ch_arr, sizeof(ch_arr)/sizeof(ch_arr[0]), trig, 0);
	max32662_adc_start_conversion(_result, sizeof(ch_arr)/sizeof(ch_arr[0]), _adc_cb);
}

void isr_adc(intptr_t exinf)
{
	(void)exinf;
	max32662_adc_handler();
}

