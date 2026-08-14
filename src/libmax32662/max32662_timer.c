/*
 * max32662_timer.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */
#include <stddef.h>
#include <stdint.h>

#include "cortex_m4.h"
#include "max32662_irq.h"
#include "max32662_timer.h"


static max32662_timer_callback s_callback_list[max32662_timer_max] = {NULL};

static volatile max32662_tmr * _max32662_timer_select_instance(max32662_timer_id timer_id)
{
	switch (timer_id) {
	case max32662_timer_0:
		return MAX32662_TIMER0;
	case max32662_timer_1:
		return MAX32662_TIMER1;
	case max32662_timer_2:
		return MAX32662_TIMER2;
	default:
		return NULL;
	}
}

int max32662_timer_initalize_freerun(max32662_timer_id id, uint32_t peripheral_clk_Hz, max32662_tmr_ctrl0_clkdiv prescal)
{
	volatile max32662_tmr *tmr = _max32662_timer_select_instance(id);
	if (tmr == NULL) return -1;

	//J Wait for Disable
	tmr->tmr_ctrl0.bf.en_a = 0;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clken_a) != 0);

	//J select clock source
	tmr->tmr_ctrl1.bf.clksel_a = max32662_tmr_ctrl1_clksel_pclk;
	tmr->tmr_ctrl1.bf.cascade  = 1; //32bit mode

	tmr->tmr_ctrl0.bf.clken_a = 1;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clkrdy_a) == 0);

	//J 連続モード
	tmr->tmr_ctrl0.bf.mode_a = max32662_tmr_ctrl0_mode_continuous;

	tmr->tmr_ctrl0.bf.clkdiv_a = prescal;

	//J Wait for Enable
	tmr->tmr_ctrl0.bf.en_a = 1;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clken_a) == 0);

	return 0;
}

uint32_t max32662_timer_gettick(max32662_timer_id id)
{
	volatile max32662_tmr *tmr = _max32662_timer_select_instance(id);
	if (tmr == NULL) return -1;

	return tmr->tmr_cnt;
}


int max32662_timer_initialize(max32662_timer_id id, uint32_t peripheral_clk_Hz, uint32_t interval_us, max32662_timer_callback cb)
{
	uint32_t i = 0;
	volatile max32662_tmr *tmr = _max32662_timer_select_instance(id);
	if (tmr == NULL) return -1;

	//J Wait for Disable
	tmr->tmr_ctrl0.bf.en_a = 0;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clken_a) != 0);

	//J select clock source
	tmr->tmr_ctrl1.bf.clksel_a = max32662_tmr_ctrl1_clksel_pclk;
	tmr->tmr_ctrl1.bf.clksel_b = max32662_tmr_ctrl1_clksel_pclk;

	tmr->tmr_ctrl0.bf.clken_a = 1;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clkrdy_a) == 0);

	//J 連続モード
	tmr->tmr_ctrl0.bf.mode_a = max32662_tmr_ctrl0_mode_continuous;

	//J Prescaler と compare の組み合わせの中で，良いモノを見つける
	for (i=max32662_tmr_ctrl0_clkdiv_1 ; i<=max32662_tmr_ctrl0_clkdiv_4096 ; ++i) {
		volatile uint32_t div = (1 << i);
		volatile uint32_t clk = (peripheral_clk_Hz / 1000000);
		volatile uint64_t cnt = (interval_us * clk) / div;
		if (cnt < 0x000000000000ffff) {
			tmr->tmr_ctrl0.bf.clkdiv_a = i;
			tmr->tmr_cmp = cnt;

			break;
		}
	}
	if (i > max32662_tmr_ctrl0_clkdiv_4096) return -2;

	//J Enable Interrupt
	s_callback_list[id] = cb;
	tmr->tmr_ctrl1.bf.ie_a = 1;

	//J Wait for Enable
	tmr->tmr_ctrl0.bf.en_a = 1;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clken_a) == 0);


	return 0;
}


int max32662_timer_initialize_oneshot(max32662_timer_id id, uint32_t peripheral_clk_Hz, uint32_t time_us, max32662_timer_callback cb)
{
	uint32_t i = 0;
	volatile max32662_tmr *tmr = _max32662_timer_select_instance(id);
	if (tmr == NULL) return -1;

	//J Wait for Disable
	tmr->tmr_ctrl0.bf.en_a = 0;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clken_a) != 0);

	//J select clock source
	tmr->tmr_ctrl1.bf.clksel_a = max32662_tmr_ctrl1_clksel_pclk;
	tmr->tmr_ctrl1.bf.clksel_b = max32662_tmr_ctrl1_clksel_pclk;

	tmr->tmr_ctrl0.bf.clken_a = 1;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clkrdy_a) == 0);

	//J Prescaler と compare の組み合わせの中で，良いモノを見つける
	for (i=max32662_tmr_ctrl0_clkdiv_1 ; i<=max32662_tmr_ctrl0_clkdiv_4096 ; ++i) {
		volatile uint32_t div = (1 << i);
		volatile uint32_t clk = (peripheral_clk_Hz / 1000000);
		volatile uint64_t cnt = (time_us * clk) / div;
		if (cnt < 0x000000000000ffff) {
			tmr->tmr_ctrl0.bf.clkdiv_a = i;
			tmr->tmr_cmp = cnt;

			break;
		}
	}
	if (i > max32662_tmr_ctrl0_clkdiv_4096) return -2;

	//J OneShot
	tmr->tmr_ctrl0.bf.mode_a = max32662_tmr_ctrl0_mode_one_shot;

	//J Enable Interrupt
	s_callback_list[id] = cb;
	tmr->tmr_ctrl1.bf.ie_a = 1;

	return 0;
}

int max32662_timer_enable_oneshot(max32662_timer_id id)
{
	volatile max32662_tmr *tmr = _max32662_timer_select_instance(id);
	if (tmr == NULL) return -1;

	tmr->tmr_cnt = 0x00000001;
	tmr->tmr_intfl = tmr->tmr_intfl;

	tmr->tmr_ctrl0.bf.en_a = 1;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clken_a) == 0);

	return 0;
}



int max32662_timer_enable_interrupt(max32662_timer_id id, int enable)
{
	if (id == max32662_timer_0) {
		if(enable) {
			__enable_nvic_irq(MAX32662_IRQNUM_TMR0);
		}
		else {
			__disable_nvic_irq(MAX32662_IRQNUM_TMR0);
		}
	}
	else if (id == max32662_timer_1) {
		if(enable) {
			__enable_nvic_irq(MAX32662_IRQNUM_TMR1);
		}
		else {
			__disable_nvic_irq(MAX32662_IRQNUM_TMR1);
		}
	}
	else if (id == max32662_timer_2) {
		if(enable) {
			__enable_nvic_irq(MAX32662_IRQNUM_TMR2);
		}
		else {
			__disable_nvic_irq(MAX32662_IRQNUM_TMR2);
		}
	}
	else {
		return -1;
	}

	return 0;
}


int max32662_timer_initialize_as_pwm(max32662_timer_id id, uint32_t peripheral_clk_Hz, uint32_t pwm_freq_Hz, max32662_timer_callback cb)
{
	uint32_t i = 0;
	volatile max32662_tmr *tmr = _max32662_timer_select_instance(id);
	if (tmr == NULL) return -1;

	//J Wait for Disable
	tmr->tmr_ctrl0.bf.en_a = 0;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clken_a) != 0);

	//J select clock source
	tmr->tmr_ctrl1.bf.clksel_a = max32662_tmr_ctrl1_clksel_pclk;
	tmr->tmr_ctrl1.bf.clksel_b = max32662_tmr_ctrl1_clksel_pclk;

	tmr->tmr_ctrl0.bf.clken_a = 1;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clkrdy_a) == 0);

	//J PWMモード
	tmr->tmr_ctrl0.bf.mode_a = max32662_tmr_ctrl0_mode_pwm;
	tmr->tmr_ctrl0.bf.pol_a = 1;

	//J Prescaler と compare の組み合わせの中で，良いモノを見つける
	//J cnt が100 - 0xffffの間になるような組み合わせを見つける
	for (i=max32662_tmr_ctrl0_clkdiv_1 ; i<=max32662_tmr_ctrl0_clkdiv_4096 ; ++i) {
		volatile uint32_t div = (1 << i);
		volatile uint64_t cnt = (peripheral_clk_Hz / div) / pwm_freq_Hz;
		if (cnt < 0x000000000000ffff && cnt > 100) {
			tmr->tmr_ctrl0.bf.clkdiv_a = i;
			tmr->tmr_cmp = cnt;
			//J 初期状態ではPWMを止める
			tmr->tmr_pwm = 0;

			break;
		}
	}
	if (i > max32662_tmr_ctrl0_clkdiv_4096) return -2;

	if (cb != NULL) {
		//J Enable Interrupt
		s_callback_list[id] = cb;
		tmr->tmr_ctrl1.bf.ie_a = 1;
	}

	//J Wait for Enable
	tmr->tmr_ctrl0.bf.en_a = 1;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clken_a) == 0);
	
	return 0;
}

int max32662_timer_pwm_set_pol(max32662_timer_id id, uint8_t pol)
{
	volatile max32662_tmr *tmr = _max32662_timer_select_instance(id);
	if (tmr == NULL) return -1;

	tmr->tmr_ctrl0.bf.pol_a = (pol) ? 1 : 0;

	return 0;
}

int max32662_timer_pwm_set_duty(max32662_timer_id id, uint8_t duty)
{
	volatile max32662_tmr *tmr = _max32662_timer_select_instance(id);
	if (tmr == NULL) return -1;
	if (duty > 100)  return -2;

	uint16_t next = ((uint32_t)tmr->tmr_cmp * duty) / 100;

	tmr->tmr_ctrl0.bf.en_a = 0;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clken_a) != 0);

	tmr->tmr_pwm = next;

	tmr->tmr_ctrl0.bf.en_a = 1;
	while (((volatile uint32_t)tmr->tmr_ctrl1.bf.clken_a) == 0);

	return 0;
}


void tmr0_handler(void)
{
	max32662_timer_tmr_intfl flg;
	flg.dword = MAX32662_TIMER0->tmr_intfl.dword;
	MAX32662_TIMER0->tmr_intfl.dword = flg.dword;

	if (flg.bf.irq_a && s_callback_list[0] != NULL) {
		s_callback_list[0](max32662_timer_0);
	}

}

void tmr1_handler(void)
{
	max32662_timer_tmr_intfl flg;
	flg.dword = MAX32662_TIMER1->tmr_intfl.dword;
	MAX32662_TIMER1->tmr_intfl.dword = flg.dword;

	if (flg.bf.irq_a && s_callback_list[1] != NULL) {
		s_callback_list[1](max32662_timer_1);
	}
}

void tmr2_handler(void)
{
	max32662_timer_tmr_intfl flg;
	flg.dword = MAX32662_TIMER2->tmr_intfl.dword;
	MAX32662_TIMER2->tmr_intfl.dword = flg.dword;

	if (flg.bf.irq_a && s_callback_list[2] != NULL) {
		s_callback_list[2](max32662_timer_2);
	}
}

