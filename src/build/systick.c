/*
 * systick.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */
#include "cortex_m4.h"

volatile uint32_t gtick = 0;
volatile uint32_t g_count_down = 0;
void sys_tick_handler(void)
{
	if (g_count_down != 0) g_count_down--;
	gtick++;
}

void systick_init(uint32_t period_ms, uint32_t core_clk_Hz)
{
	uint32_t reload = (core_clk_Hz * period_ms) / 1000;

	CM4_SYS_TICK->reload_value = reload;
	CM4_SYS_TICK->control_and_status.bf.clksource = 1;
	CM4_SYS_TICK->control_and_status.bf.tickint = 1;
	CM4_SYS_TICK->control_and_status.bf.enable = 1;

	return;
}

void systick_delay(uint32_t delay_ms)
{
	g_count_down = delay_ms+1;
	while (g_count_down);

	return;
}

