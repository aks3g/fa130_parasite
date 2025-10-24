#include <stdint.h>

#include "cortex_m4.h"

#include "max32662_clock.h"
#include "max32662_gpio.h"
#include "max32662_timer.h"
#include "max32662_adc.h"
#include "max32662_i2c.h"
#include "max32662_uart.h"

volatile uint32_t work = 0;
volatile uint32_t idx = 0;
uint32_t arr_ai0[2048] = {0};
uint32_t arr_ai1[2048] = {0};
uint32_t arr_ai2[2048] = {0};
uint32_t arr_ai3[2048] = {0};

uint32_t _state = 0;
uint8_t  _duty = 0;
void _switch_cb(Max32662_gpio_pin pin)
{
	return;
}

static Max32662_adc_result _result[4];

void _adc_cb(Max32662_adc_result *result, size_t size)
{
	if (idx >= (sizeof(arr_ai0)/sizeof(arr_ai0[0])) ) {
		return;
	}

	arr_ai0[idx] = result[0].dword;
	if (size > 1) arr_ai1[idx] = result[1].dword;
	if (size > 2) arr_ai2[idx] = result[2].dword;
	if (size > 3) arr_ai3[idx] = result[3].dword;

	idx++;
	work = 0;

	return;
}


void _timer0_cb(int id)
{
	if (idx >= (sizeof(arr_ai0)/sizeof(arr_ai0[0])) ) {
		return;
	}

	if (work) return;
	work = 1;
	max32662_gpio_outout(Max32662_gpio_14, 0);
	max32662_adc_start_conversion(_result, sizeof(_result)/sizeof(_result[0]), _adc_cb);
}

#define AI_MINI4WD_PIN_CTRL1		Max32662_gpio_4
#define AI_MINI4WD_PIN_CTRL2		Max32662_gpio_15
#define AI_MINI4WD_PIN_PWM1			Max32662_gpio_16
#define AI_MINI4WD_PIN_PWM2			Max32662_gpio_5

#define AI_MINI4WD_PWM_CH1			max32662_timer_2
#define AI_MINI4WD_PWM_CH2			max32662_timer_1

static void _set_slottle(int slottle)
{
	if (slottle > 100 || -100 > slottle) {
		return;
	}
	
	if (slottle == 0) {
		max32662_gpio_outout(AI_MINI4WD_PIN_CTRL1, 0);
		max32662_gpio_outout(AI_MINI4WD_PIN_CTRL2, 0);

		max32662_gpio_altfunc(AI_MINI4WD_PIN_PWM1,  0, 0);
		max32662_gpio_altfunc(AI_MINI4WD_PIN_PWM2,  0, 0);
		max32662_gpio_outout(AI_MINI4WD_PIN_PWM1, 0);
		max32662_gpio_outout(AI_MINI4WD_PIN_PWM2, 0);
	}
	else if (slottle > 0) {
		max32662_gpio_outout(AI_MINI4WD_PIN_CTRL1, 1);
		max32662_gpio_outout(AI_MINI4WD_PIN_CTRL2, 0);

		max32662_gpio_altfunc(AI_MINI4WD_PIN_PWM1,  3, 1);
		max32662_gpio_altfunc(AI_MINI4WD_PIN_PWM1,  3, 0);
		max32662_timer_pwm_set_duty(AI_MINI4WD_PWM_CH1, slottle);

		max32662_gpio_altfunc(AI_MINI4WD_PIN_PWM2,  0, 0);
		max32662_gpio_outout(AI_MINI4WD_PIN_PWM2, 0);
	} 
	else {//if(slottle < 0)
		max32662_gpio_outout(AI_MINI4WD_PIN_CTRL1, 0);
		max32662_gpio_outout(AI_MINI4WD_PIN_CTRL2, 1);

		max32662_gpio_altfunc(AI_MINI4WD_PIN_PWM1,  0, 0);
		max32662_gpio_outout(AI_MINI4WD_PIN_PWM1, 0);

		max32662_gpio_altfunc(AI_MINI4WD_PIN_PWM2,  3, 1);
		max32662_gpio_altfunc(AI_MINI4WD_PIN_PWM2,  3, 0);
		max32662_timer_pwm_set_duty(AI_MINI4WD_PWM_CH2, -slottle);
	}
}

int main(void)
{
	systick_init(1, 100000000);
	__disable_irq();

	max32662_clock_setup_internal_ibro();
	max32662_clock_setup_internal_primary_osc(Max32662_gcr_ipo_div_1);
	max32662_clock_setup_sysclock(Max32662_gcr_sysclk_ipo, Max32662_gcr_sysclk_div_1);

	max32662_clock_peripheral(Max32662_peripheral_uart0, 1);
	max32662_clock_peripheral(Max32662_peripheral_uart1, 1);
	max32662_clock_peripheral(Max32662_peripheral_gpio0, 1);
	max32662_clock_peripheral(Max32662_peripheral_tmr0, 1);
	max32662_clock_peripheral(Max32662_peripheral_tmr1, 1);
	max32662_clock_peripheral(Max32662_peripheral_tmr2, 1);
	max32662_clock_peripheral(Max32662_peripheral_adc,  1);
	max32662_clock_peripheral(Max32662_peripheral_i2c1, 1);

	// Test LED Output.
	max32662_gpio_setup_inout(Max32662_gpio_2, Max32662_gpio_output);
	max32662_gpio_outout(Max32662_gpio_2, 1);
//	max32662_gpio_setup_inout(Max32662_gpio_14, Max32662_gpio_output);
//	max32662_gpio_outout(Max32662_gpio_14, 1);

	// Motor Control
	max32662_gpio_setup_inout(Max32662_gpio_4, Max32662_gpio_output);
	max32662_gpio_outout(Max32662_gpio_4, 0);
	max32662_gpio_setup_inout(Max32662_gpio_15, Max32662_gpio_output);
	max32662_gpio_outout(Max32662_gpio_15, 0);
	max32662_gpio_setup_inout(Max32662_gpio_5, Max32662_gpio_output);
	max32662_gpio_outout(Max32662_gpio_5, 0);
	max32662_gpio_setup_inout(Max32662_gpio_16, Max32662_gpio_output);
	max32662_gpio_outout(Max32662_gpio_16, 0);

	// Switch on EVKIT
//	max32662_gpio_setup_inout(Max32662_gpio_6, Max32662_gpio_input);
//	max32662_gpio_setup_pullmode(Max32662_gpio_6, Max32662_gpio_pull_up);
//	max32662_gpio_setup_interrupt(Max32662_gpio_6, Max32662_gpio_intr_edge_falling, _switch_cb);
	
//	max32662_gpio_enable_interrupt(1);

//	max32662_timer_initialize_as_pwm(max32662_timer_1, 50000000, 5000);
//	max32662_gpio_altfunc(Max32662_gpio_5, 3, 1);
//	max32662_gpio_altfunc(Max32662_gpio_5, 3, 0);

	// Test I2C
#if 0
	max32662_gpio_altfunc(Max32662_gpio_6, 1, 1);
	max32662_gpio_setup_inout(Max32662_gpio_6, Max32662_gpio_input);
	max32662_gpio_setup_pullmode(Max32662_gpio_6, Max32662_gpio_pull_up);
	max32662_gpio_altfunc(Max32662_gpio_6, 1, 0);

	max32662_gpio_altfunc(Max32662_gpio_9, 1, 1);
	max32662_gpio_setup_inout(Max32662_gpio_9, Max32662_gpio_input);
	max32662_gpio_setup_pullmode(Max32662_gpio_9, Max32662_gpio_pull_up);
	max32662_gpio_altfunc(Max32662_gpio_9, 1, 0);

	max32662_i2c_initialize(max32662_i2c1, 100000, 50000000, 0, 0);
#endif

	// Test ADC
	Max32662_adc_ch ch_arr[] = {
		Max32662_adc_ch_ain0,
		Max32662_adc_ch_ain1,
		Max32662_adc_ch_ain2,
		Max32662_adc_ch_ain3,
	};
	max32662_gpio_altfunc(Max32662_gpio_10, 4, 1);
	max32662_gpio_altfunc(Max32662_gpio_10, 4, 0);

	max32662_gpio_altfunc(Max32662_gpio_11, 4, 1);
	max32662_gpio_altfunc(Max32662_gpio_11, 4, 0);

	max32662_gpio_altfunc(Max32662_gpio_12, 4, 1);
	max32662_gpio_altfunc(Max32662_gpio_12, 4, 0);

	max32662_gpio_altfunc(Max32662_gpio_13, 4, 1);
	max32662_gpio_altfunc(Max32662_gpio_13, 4, 0);

	max32661_adc_init(Max32662_adc_amp_enabled, Max32662_adc_div_3, Max32662_adc_ref_2_048v);
	max32662_adc_setup_conversion(ch_arr, 4);

	// UART
/*
	max32662_gpio_altfunc(Max32662_gpio_10, 1, 0);
	max32662_gpio_altfunc(Max32662_gpio_11, 1, 0);
	max32662_uart_setup(Max32662_uart0, 115200);
*/
	// Test Tiemr & PWM
	max32662_timer_initialize(max32662_timer_0, 50000000, 1000000/2048, _timer0_cb);
	max32662_timer_enable_interrupt(max32662_timer_0, 1);

	max32662_timer_initialize_as_pwm(max32662_timer_1, 50000000, 2048);
	max32662_timer_initialize_as_pwm(max32662_timer_2, 50000000, 2048);
	max32662_timer_pwm_set_duty(max32662_timer_1, 0);
	max32662_timer_pwm_set_duty(max32662_timer_2, 0);

	__enable_irq();

	while(1) {
		_set_slottle(100);


		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);

		idx = 0;

		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 1);
		systick_delay(100);
		max32662_gpio_outout(Max32662_gpio_2, 0);
		systick_delay(100);
		_set_slottle(0);

		while(1);

//		max32662_uart_tx(Max32662_uart0, (uint8_t)'/');
	}

	return 0;
}