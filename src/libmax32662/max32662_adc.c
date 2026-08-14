/*
 * max32662_adc.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */
#include <stddef.h>
#include <stdint.h>

#include "cortex_m4.h"
#include "max32662.h"
#include "max32662_irq.h"
#include "max32662_adc.h"

// for interrupt
static Max32662_adc_conv_done_callback s_cb_func;
static Max32662_adc_result * s_result;
static size_t s_size;


int max32661_adc_init(Max32662_adc_amp amp, Max32662_adc_div div, MAX32662_adc_vref vref)
{
	MAX32662_ADC->ctrl0.bf.resetb  = 0;
	MAX32662_ADC->ctrl0.bf.adc_en  = 0;

	MAX32662_ADC->ctrl0.bf.skip_cal = 0;

	// Setup Clock
	MAX32662_ADC->clkctrl.bf.clksel = Max32662_adc_clksel_sys_osc;	// 100MHz


	//J 変換時間を25kHzに設定
#if 0
	MAX32662_ADC->clkctrl.bf.clkdiv = Max32662_adc_clkdiv_by_4;		// SAR_CLK = 25MHz
	MAX32662_ADC->sampclkctrl.bf.track_cnt =  10;  // min=4
	MAX32662_ADC->sampclkctrl.bf.idle_cnt  = 958;  // 25ksps
else
	MAX32662_ADC->clkctrl.bf.clkdiv = Max32662_adc_clkdiv_by_16;	// SAR_CLK = 6.25MHz
	MAX32662_ADC->sampclkctrl.bf.track_cnt = 60;
	MAX32662_ADC->sampclkctrl.bf.idle_cnt  = 0;
#endif

	MAX32662_ADC->intfl.dword = 0xffffffff;
	
	// Refernce and divider
	MAX32662_MCR->adccfg0.bf.ext_ref = Max32662_adc_ref_int;
	MAX32662_MCR->adccfg0.bf.int_ref = vref;

	// 10.3 Analog Input Buffer Path
	// Enable all analog input
//	MAX32662_MCR->adccfg1.bf.ain_inp_en    = 0xf;
	MAX32662_MCR->adccfg1.bf.ain_inp_en    = 0x2;
	MAX32662_MCR->adccfg1.bf.div_sel       = div;

	if (amp == Max32662_adc_amp_enabled) {
		MAX32662_MCR->adccfg1.bf.thu_pad_sw_en = 0xf;
		MAX32662_MCR->adccfg1.bf.thru_en     = 0x1;
		MAX32662_MCR->adccfg1.bf.amp_en      = 0x1; // Amp enable
		MAX32662_MCR->adccfg1.bf.amp_rri_en  = 0x1; // Rail to Rail Amp
	}
	else {
		MAX32662_MCR->adccfg1.bf.thu_pad_sw_en = 0;
		MAX32662_MCR->adccfg1.bf.thru_en     = 0;
		MAX32662_MCR->adccfg1.bf.amp_en      = 0; // Amp disable
		MAX32662_MCR->adccfg1.bf.amp_rri_en  = 0;
	}

	// Enable and wait for ready
	MAX32662_ADC->ctrl0.bf.resetb  = 1;
	MAX32662_ADC->ctrl0.bf.bias_en = 1;
	MAX32662_ADC->ctrl0.bf.adc_en  = 1;
	while (MAX32662_ADC->intfl.bf.ready == 0);

	return 0;
}

int max32662_adc_setup_conversion(Max32662_adc_ch *ch_arr, size_t arr_size, Max32662_adc_trig trig, int continuous)
{
	size_t i = 0;
	// 10.12.2.1
	if (trig == Max32662_adc_trig_soft) {
		MAX32662_ADC->ctrl1.bf.trig_mode = 0;
	}
	else {
		MAX32662_ADC->ctrl1.bf.trig_mode = 1;
		MAX32662_ADC->ctrl1.bf.trig_sel  = (trig & 0x7);
	}
	MAX32662_ADC->ctrl1.bf.cnv_mode  = continuous;

	// Slot setup
	MAX32662_ADC->ctrl1.bf.num_slots = arr_size-1;
	MAX32662_ADC->chsel0.bf.slot0_id = ch_arr[i++];
	if (arr_size >= 2) {
		MAX32662_ADC->chsel0.bf.slot1_id = ch_arr[i++];
	}
	if (arr_size >= 3) {
		MAX32662_ADC->chsel0.bf.slot2_id = ch_arr[i++];
	}
	if (arr_size >= 4) {
		MAX32662_ADC->chsel0.bf.slot3_id = ch_arr[i++];
	}
	if (arr_size >= 5) {
		MAX32662_ADC->chsel1.bf.slot4_id = ch_arr[i++];
	}
	if (arr_size >= 6) {
		MAX32662_ADC->chsel1.bf.slot5_id = ch_arr[i++];
	}
	if (arr_size >= 7) {
		MAX32662_ADC->chsel1.bf.slot6_id = ch_arr[i++];
	}
	if (arr_size >= 8) {
		MAX32662_ADC->chsel1.bf.slot7_id = ch_arr[i++];
	}

	// No Average
	MAX32662_ADC->ctrl1.bf.avg  = 0;

	// Format enabled
	MAX32662_ADC->fifodmactrl.bf.data_format = 1;

	// Clear Interrupt flags
	MAX32662_ADC->intfl.dword = 0xffffffff;

	MAX32662_ADC->inten.dword = 0;

	__enable_nvic_irq(MAX32662_IRQNUM_ADC);

	return 0;
}


int max32662_adc_start_conversion(Max32662_adc_result *result, size_t n_ch, Max32662_adc_conv_done_callback cb)
{
	s_result  = result;
	s_size    = n_ch;
	s_cb_func = cb;

	MAX32662_ADC->intfl.dword = 0xffffffff;
	MAX32662_ADC->inten.bf.seq_done = 1;
	MAX32662_ADC->inten.bf.conv_done = 1;

	MAX32662_ADC->ctrl1.bf.start  = 1;

	return 0;
}

int max32662_adc_start_continuous(Max32662_adc_result *result, size_t n_ch, uint32_t conv_hz, Max32662_adc_conv_done_callback cb)
{
	s_result  = result;
	s_size    = n_ch;
	s_cb_func = cb;

	//J Sequence間の間隔を調整する
	//J interval を micro-secで表現
	uint32_t interval_us = 1000000 / conv_hz; 

	//J 25ksps に設定しているので，channel数を使って1sequenceにかかる時間[us]を計算する
	uint32_t seq_time_us = n_ch * (1000000 / 25000);

	//J 100/4 MHzで考えたときの待ち時間を変換時間単位でをRestart Delay Counterに入れる
	volatile uint32_t delay_us = interval_us - seq_time_us;
	MAX32662_ADC->restart.dword = (delay_us * 25 / 1000); //@25KHz

	MAX32662_ADC->intfl.dword = 0xffffffff;
	MAX32662_ADC->inten.bf.seq_done = 1;

	MAX32662_ADC->ctrl1.bf.start  = 1;

	return 0;
}


void max32662_adc_handler(void)
{
	max32662_adc_intflg flg = MAX32662_ADC->intfl;

	// Read from fifo
	if (flg.bf.seq_done) {
		for (size_t i=0 ; i<s_size ; ++i) {
			s_result[i].dword = MAX32662_ADC->data.dword;
		}
		if (s_cb_func != NULL) {
			s_cb_func(s_result, s_size);
		}
	}

	MAX32662_ADC->intfl.dword = flg.dword;

	if (flg.bf.conv_done) {
		//J Clear start bit if single conversion mode
		if (MAX32662_ADC->ctrl1.bf.cnv_mode == 0) {
			MAX32662_ADC->ctrl1.bf.start = 0;
		}

		// Re-arm next trigger
		if (MAX32662_ADC->ctrl1.bf.trig_mode == 1) {
			MAX32662_ADC->ctrl1.bf.start = 1;
		}
	}
}

