/*
 * timer.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#include <kernel.h>
#include "kernel_cfg.h"

#include "string.h"

#include "target_syssvc.h"

#include "max32662_timer.h"
#include "include/driver/timer.h"

int driver_timer_init(void)
{
	return max32662_timer_initalize_freerun(max32662_timer_0, 50000000, max32662_tmr_ctrl0_clkdiv_32);
}

uint32_t driver_timer_gettick(void)
{
	return max32662_timer_gettick(max32662_timer_0);
}

uint32_t driver_timer_gettick_us(void)
{
	uint32_t tick = max32662_timer_gettick(max32662_timer_0);

	//return (tick * 1000000) * (32/50000000);
	return (tick * 32) / 50;
}
