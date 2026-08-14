#include <stdint.h>
#include <string.h>

#include "cortex_m4.h"

#include "max32662_clock.h"
#include "max32662_gpio.h"
#include "max32662_timer.h"
#include "max32662_adc.h"
#include "max32662_i2c.h"
#include "max32662_uart.h"
#include "max32662_spi.h"
#include "max32662_dmac.h"

volatile uint32_t idx = 0;
uint32_t arr_ai0[4096] = {0};
uint32_t arr_ai1[4096] = {0};
uint32_t arr_ai2[4096] = {0};
uint32_t arr_ai3[4096] = {0};

#define SPI_FLASH_STATUS_REG_WIP			(1<<0)
#define SPI_FLASH_STATUS_REG_WEL			(1<<1)
#define SPI_FLASH_STATUS_REG_BP0			(1<<2)
#define SPI_FLASH_STATUS_REG_BP1			(1<<3)
#define SPI_FLASH_STATUS_REG_BP2			(1<<4)
#define SPI_FLASH_STATUS_REG_BP3			(1<<5)
#define SPI_FLASH_STATUS_REG_QE				(1<<6)
#define SPI_FLASH_STATUS_REG_SRWD			(1<<7)

#define PARASITE_MD_PWM_CH1			max32662_timer_2
#define PARASITE_MD_PWM_CH2			max32662_timer_1

#define PARASITE_PIN_MD_PWM1		Max32662_gpio_16
#define PARASITE_PIN_MD_PWM2		Max32662_gpio_5

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
	max32662_clock_peripheral(Max32662_peripheral_spi0, 1);
	max32662_clock_peripheral(Max32662_peripheral_spi1, 1);
	max32662_clock_peripheral(Max32662_peripheral_dma, 1);

	// Test LED Output.
	max32662_gpio_setup_inout(Max32662_gpio_2, Max32662_gpio_output);
	max32662_gpio_outout(Max32662_gpio_2, 1);
	max32662_gpio_setup_inout(Max32662_gpio_14, Max32662_gpio_output);
	max32662_gpio_outout(Max32662_gpio_14, 1);

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


	__enable_irq();

	max32662_timer_initialize_as_pwm(PARASITE_MD_PWM_CH1, 50000000, 1000);
	max32662_timer_initialize_as_pwm(PARASITE_MD_PWM_CH2, 50000000, 1000);

	max32662_timer_pwm_set_duty(PARASITE_MD_PWM_CH1, 0);
	max32662_timer_pwm_set_duty(PARASITE_MD_PWM_CH2, 0);


	max32662_gpio_altfunc(PARASITE_PIN_MD_PWM1,  3, 1);
	max32662_gpio_altfunc(PARASITE_PIN_MD_PWM1,  3, 0);

	max32662_gpio_altfunc(PARASITE_PIN_MD_PWM2,  3, 1);
	max32662_gpio_altfunc(PARASITE_PIN_MD_PWM2,  3, 0);

	max32662_timer_pwm_set_duty(PARASITE_MD_PWM_CH2, 50);

	while(1);

	return 0;
}