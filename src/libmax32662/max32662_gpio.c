/*
 * max32662_goio.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */
#include <stddef.h>
#include <stdint.h>

#include "cortex_m4.h"
#include "max32662_irq.h"
#include "max32662_gpio.h"


static Max32662_gpio_intr_callback sGpioInterruptCb[Max32662_gpio_pin_max] = {NULL};

int max32662_gpio_altfunc(Max32662_gpio_pin pin, uint32_t alt, int transition)
{
	if(alt > 5) return -1;

	MAX32662_GPIO->gpion_inen     |= (1<<(int)pin);

	switch (alt)
	{
	case 0://GPIO
		MAX32662_GPIO->gpion_en0_set = (1<<pin);
		MAX32662_GPIO->gpion_en1_clr = (1<<pin);
		MAX32662_GPIO->gpion_en2_clr = (1<<pin);
		MAX32662_GPIO->gpion_en3_clr = (1<<pin);
		break;
	case 1:
		if (transition) MAX32662_GPIO->gpion_en0_set = (1<<pin);
		else            MAX32662_GPIO->gpion_en0_clr = (1<<pin);
		MAX32662_GPIO->gpion_en1_clr = (1<<pin);
		MAX32662_GPIO->gpion_en2_clr = (1<<pin);
		MAX32662_GPIO->gpion_en3_clr = (1<<pin);
		break;
	case 2:
		if (transition) MAX32662_GPIO->gpion_en0_set = (1<<pin);
		else            MAX32662_GPIO->gpion_en0_clr = (1<<pin);
		MAX32662_GPIO->gpion_en1_set = (1<<pin);
		MAX32662_GPIO->gpion_en2_clr = (1<<pin);
		MAX32662_GPIO->gpion_en3_clr = (1<<pin);
		break;
	case 3:
		if (transition) MAX32662_GPIO->gpion_en0_set = (1<<pin);
		else            MAX32662_GPIO->gpion_en0_clr = (1<<pin);
		MAX32662_GPIO->gpion_en1_clr = (1<<pin);
		MAX32662_GPIO->gpion_en2_set = (1<<pin);
		MAX32662_GPIO->gpion_en3_clr = (1<<pin);
		break;
	case 4:
		if (transition) MAX32662_GPIO->gpion_en0_set = (1<<pin);
		else            MAX32662_GPIO->gpion_en0_clr = (1<<pin);
		MAX32662_GPIO->gpion_en1_set = (1<<pin);
		MAX32662_GPIO->gpion_en2_set = (1<<pin);
		MAX32662_GPIO->gpion_en3_clr = (1<<pin);
		break;
	case 5:
		if (transition) MAX32662_GPIO->gpion_en0_set = (1<<pin);
		else            MAX32662_GPIO->gpion_en0_clr = (1<<pin);
		MAX32662_GPIO->gpion_en1_clr = (1<<pin);
		MAX32662_GPIO->gpion_en2_clr = (1<<pin);
		MAX32662_GPIO->gpion_en3_set = (1<<pin);
		break;
	case 6:
		MAX32662_GPIO->gpion_en0_clr = (1<<pin);
		MAX32662_GPIO->gpion_en1_clr = (1<<pin);
		MAX32662_GPIO->gpion_en2_clr = (1<<pin);
		MAX32662_GPIO->gpion_en3_clr = (1<<pin);
		break;
	default:
		break;
	}
	
	return 0;
}

int max32662_gpio_setup_pullmode(Max32662_gpio_pin pin, Max32662_gpio_pullmode pullmode)
{
	if (pullmode == Max32662_gpio_hi_impedance) {
		MAX32662_GPIO->gpion_padctrl0 &= ~(1<<(int)pin);
	}
	else if (pullmode == Max32662_gpio_pull_up) {
		MAX32662_GPIO->gpion_padctrl0 |=  (1<<(int)pin);
		MAX32662_GPIO->gpion_ps       |=  (1<<(int)pin);

	}
	else if (pullmode == Max32662_gpio_pull_down) {
		MAX32662_GPIO->gpion_padctrl0 |=  (1<<(int)pin);
		MAX32662_GPIO->gpion_ps       &= ~(1<<(int)pin);
	}
	else {
		return -1;
	}

	return 0;
}

int max32662_gpio_setup_inout(Max32662_gpio_pin pin, Max32662_gpio_inout inout)
{
	MAX32662_GPIO->gpion_en0_set = (1<<(int)pin);
	MAX32662_GPIO->gpion_en1_clr = (1<<(int)pin);
	MAX32662_GPIO->gpion_en2_clr = (1<<(int)pin);

	if (inout == Max32662_gpio_output) {
		MAX32662_GPIO->gpion_outen_set = (1<<(int)pin);
		MAX32662_GPIO->gpion_inen     &=~(1<<(int)pin);
	}
	else if (inout == Max32662_gpio_input) {
		MAX32662_GPIO->gpion_outen_clr = (1<<(int)pin);
		MAX32662_GPIO->gpion_inen     |= (1<<(int)pin);
	}
	else {
		MAX32662_GPIO->gpion_outen_clr = (1<<(int)pin);
		MAX32662_GPIO->gpion_inen     &=~(1<<(int)pin);
	}

	return 0;
}

int max32662_gpio_input(Max32662_gpio_pin pin, uint32_t *input)
{
	*input = ((MAX32662_GPIO->gpion_in &  (1<<(int)pin)) == 0) ? 0 : 1;

	return 0;
}

int  max32662_gpio_outout(Max32662_gpio_pin pin, uint32_t output)
{
	if (output) {
		MAX32662_GPIO->gpion_out_set = (1<<(int)pin);
	}
	else {
		MAX32662_GPIO->gpion_out_clr = (1<<(int)pin);
	}

	return 0;
}

int max32662_gpio_outout_toggle(Max32662_gpio_pin pin)
{
	if (MAX32662_GPIO->gpion_out & (1<<(int)pin)) {
		MAX32662_GPIO->gpion_out_clr = (1<<(int)pin);
	}
	else {
		MAX32662_GPIO->gpion_out_set = (1<<(int)pin);
	}

	return 0;
}

int max32662_gpio_setup_interrupt(Max32662_gpio_pin pin, Max32662_gpio_intr_mode mode, Max32662_gpio_intr_callback cb)
{
	MAX32662_GPIO->gpion_inten_clr = (1<<(int)pin);
	{
		MAX32662_GPIO->gpion_intfl_clr = (1<<(int)pin);
		if (mode == Max32662_gpio_intr_level_low) {
			MAX32662_GPIO->gpion_intmode  &= ~(1<<(int)pin);
			MAX32662_GPIO->gpion_intpol   &= ~(1<<(int)pin);
		}
		else if (mode == Max32662_gpio_intr_level_high) {
			MAX32662_GPIO->gpion_intmode  &= ~(1<<(int)pin);
			MAX32662_GPIO->gpion_intpol   |=  (1<<(int)pin);
		}
		else if (mode == Max32662_gpio_intr_edge_falling) {
			MAX32662_GPIO->gpion_intmode  |= (1<<(int)pin);
			MAX32662_GPIO->gpion_intpol   |=  (1<<(int)pin);
		}
		else if (mode == Max32662_gpio_intr_edge_rising) {
			MAX32662_GPIO->gpion_intmode  |= (1<<(int)pin);
			MAX32662_GPIO->gpion_intpol   &= ~(1<<(int)pin);
		}
		else if (mode == Max32662_gpio_intr_edge_both) {
			MAX32662_GPIO->gpion_intmode  |= (1<<(int)pin);
			MAX32662_GPIO->gpion_dualedge |= (1<<(int)pin);
		}

		sGpioInterruptCb[(int)pin] = cb;

	}
	MAX32662_GPIO->gpion_inten_set = (1<<(int)pin);

	return 0;
}

int max32662_gpio_enable_interrupt(int enable)
{
	if(enable) {
		__enable_nvic_irq(MAX32662_IRQNUM_GPIO);
	}
	else {
		__disable_nvic_irq(MAX32662_IRQNUM_GPIO);
	}

	return 0;
}


// Interrupt handler
void gpio0_handler(void)
{
	uint32_t i=0;
	uint32_t flg = MAX32662_GPIO->gpion_intfl;
	MAX32662_GPIO->gpion_intfl_clr = flg;

	for (i=0 ; i<Max32662_gpio_pin_max ; ++i) {
		if ( ( ((1<<i) & flg) != 0) && (sGpioInterruptCb[i] != NULL) ) {
			sGpioInterruptCb[i]((Max32662_gpio_pin)(1<<i));
		}
	}

}