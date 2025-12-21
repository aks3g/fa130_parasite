/*
 * max32662_clock.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */
#include <stdint.h>

#include "max32662_clock.h"


int max32662_clock_setup_internal_ibro(void)
{
	MAX32662_GCR->gcr_clkctrl.bf.ibro_en= 1;
	while (MAX32662_GCR->gcr_clkctrl.bf.ibro_rdy == 0);

	return 0;
}


int max32662_clock_setup_internal_primary_osc(Max32662_gcr_ipo_div prescale)
{
	MAX32662_GCR->gcr_clkctrl.bf.ipo_div = prescale;
	while (MAX32662_GCR->gcr_clkctrl.bf.ipo_rdy == 0);

	return 0;
}

int max32662_clock_setup_sysclock(Max32662_gcr_sysclk_sel sel, Max32662_gcr_sysclk_div prescale)
{
	MAX32662_GCR->gcr_clkctrl.bf.sysclk_div = (uint32_t)prescale;
	MAX32662_GCR->gcr_clkctrl.bf.sysclk_sel = (uint32_t)sel;

	while (MAX32662_GCR->gcr_clkctrl.bf.sysclk_rdy == 0);

	return 0;
}

int max32662_clock_enter_sleep(void)
{
	return 0;
}

int max32662_clock_exit_sleep(void)
{
	return 0;
}

int max32662_clock_peripheral(Max32662_gcr_peripheral peri, uint32_t enable)
{
	if (enable) {
		MAX32662_GCR->gcr_pclkdis0 &= ~(uint32_t)peri;
	}
	else {
		MAX32662_GCR->gcr_pclkdis0 |= (uint32_t)peri;
	}

	return 0;
}

int max32662_clock_reset(Max32662_gcr_reset peri)
{
	MAX32662_GCR->gcr_rst0 = (uint32_t)peri;
	return 0;
}