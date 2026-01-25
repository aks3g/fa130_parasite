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

void _switch_cb(Max32662_gpio_pin pin)
{
	return;
}

static Max32662_adc_result _result[4];

void _adc_cb(Max32662_adc_result *result, size_t size)
{
	max32662_gpio_outout_toggle(Max32662_gpio_14);

	if (idx >= (sizeof(arr_ai0)/sizeof(arr_ai0[0])) ) {
		return;
	}

	arr_ai0[idx] = result[0].dword;
	if (size > 1) arr_ai1[idx] = result[1].dword;
	if (size > 2) arr_ai2[idx] = result[2].dword;
	if (size > 3) arr_ai3[idx] = result[3].dword;

	idx++;

	return;
}


void _timer0_cb(int id)
{
//	max32662_gpio_outout_toggle(Max32662_gpio_14);
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

static volatile int _spi_transaction_done = 0;
static void _spi_cb(int status)
{
	_spi_transaction_done = 1;

	return;
}

static volatile int dma_done = 0;
static void _dmac_cb(int status)
{
	dma_done = 1;
}

#define SPI_FLASH_STATUS_REG_WIP			(1<<0)
#define SPI_FLASH_STATUS_REG_WEL			(1<<1)
#define SPI_FLASH_STATUS_REG_BP0			(1<<2)
#define SPI_FLASH_STATUS_REG_BP1			(1<<3)
#define SPI_FLASH_STATUS_REG_BP2			(1<<4)
#define SPI_FLASH_STATUS_REG_BP3			(1<<5)
#define SPI_FLASH_STATUS_REG_QE				(1<<6)
#define SPI_FLASH_STATUS_REG_SRWD			(1<<7)


static uint8_t tx[512] = {0x9F};
static uint8_t rx[512] = {0};

static uint32_t src_buf[32] = {0xaa};
static uint32_t dst_buf[32] = {0x00};

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

	__enable_irq();

	max32662_gpio_altfunc(Max32662_gpio_7,  1, 1);
	max32662_gpio_altfunc(Max32662_gpio_8,  1, 1);
	max32662_gpio_altfunc(Max32662_gpio_17, 1, 1);
	max32662_gpio_altfunc(Max32662_gpio_18, 1, 1);

	max32662_gpio_setup_inout(Max32662_gpio_7,  Max32662_gpio_input);
	max32662_gpio_setup_inout(Max32662_gpio_8,  Max32662_gpio_output);
	max32662_gpio_setup_inout(Max32662_gpio_17, Max32662_gpio_output);
	max32662_gpio_setup_inout(Max32662_gpio_18, Max32662_gpio_output);

	max32662_gpio_altfunc(Max32662_gpio_7,  1, 0);
	max32662_gpio_altfunc(Max32662_gpio_8,  1, 0);
	max32662_gpio_altfunc(Max32662_gpio_17, 1, 0);
	max32662_gpio_altfunc(Max32662_gpio_18, 1, 0);

	// Check Chipid
	max32662_clock_reset(Max32662_reset_spi1);
	max32662_spi_master_initialize(max32662_spi1, max32662_spi_mode0, 25, 50);

	// Check Chipid
	tx[0] = 0x9f;
	max32662_spi_master_transfer(max32662_spi1, tx, rx, 1, 4, NULL);

	// Write Enable
	tx[0] = 0x06;
	max32662_spi_master_transfer(max32662_spi1, tx, rx, 1, 0, NULL);

	// poll status register
//	tx[0] = 0x05;
//	max32662_spi_master_transfer(max32662_spi1, tx, rx, 1, 1, NULL);

//	if (0 == (rx[1] & SPI_FLASH_STATUS_REG_WEL)) while (1);

	// Page Program
	tx[0] = 0x02;
	tx[1] = 0x00;
	tx[2] = 0x00;
	tx[3] = 0x00;

	for (size_t i=0 ; i<256 ; ++i) {
		tx[4+i] = i;
	}
//	max32662_spi_master_transfer(max32662_spi1, tx, rx, 256+4, 0, NULL);
	_spi_transaction_done = 0;
	max32662_spi_master_transferDMA(max32662_spi1, tx, rx, 256+4, _spi_cb);

	while(!_spi_transaction_done);

	tx[0] = 0x05;
	do {
		max32662_spi_master_transfer(max32662_spi1, tx, rx, 1, 1, NULL);
	}
	while (rx[1] & SPI_FLASH_STATUS_REG_WIP);

	tx[0] = 0x03;
	tx[1] = 0x00;
	tx[2] = 0x00;
	tx[3] = 0x00;
	memset (rx, 0xaa, sizeof(rx));
	max32662_spi_master_transfer(max32662_spi1, tx, rx, 4, 256, NULL);

	while(1);

	max32662_dmac_initialize();

	Max32662_dmac_cfg_src_to_dma_fifo src;
	Max32662_dmac_cfg_dst_from_dma_fifo dst;
	{
		src.src = src_buf;
		src.burst_size = 1;
		src.srcwd = sizeof(uint32_t);;
		src.cnt = sizeof(src_buf) / sizeof(uint32_t);
		src.srcinc = 1;

		dst.dst = dst_buf;
		dst.burst_size = 1;
		dst.dstwd = sizeof(uint32_t);
		dst.dstinc = 1;

		max32662_dmac_setup(Max32662_dmac_ch0, Max32662_dmac_req_mem_to_mem, &src, &dst);
		max32662_dmac_start_transfer(Max32662_dmac_ch0, _dmac_cb);
	}

	while(1);

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
	max32662_adc_setup_conversion(ch_arr, sizeof(ch_arr)/sizeof(ch_arr[0]), 1);
	max32662_adc_start_continuous(_result, 4, 4000, _adc_cb);

	// UART
/*
	max32662_gpio_altfunc(Max32662_gpio_10, 1, 0);
	max32662_gpio_altfunc(Max32662_gpio_11, 1, 0);
	max32662_uart_setup(Max32662_uart0, 115200);
*/
	// Test Tiemr & PWM
//	max32662_timer_initialize(max32662_timer_0, 50000000, 1000000/2048, _timer0_cb);
//	max32662_timer_initialize(max32662_timer_0, 50000000, 1000000/(4096*2), _timer0_cb);
//	max32662_timer_enable_interrupt(max32662_timer_0, 1);

	max32662_timer_initialize_as_pwm(max32662_timer_1, 50000000, 2000);
	max32662_timer_initialize_as_pwm(max32662_timer_2, 50000000, 2000);
	max32662_timer_pwm_set_duty(max32662_timer_1, 0);
	max32662_timer_pwm_set_duty(max32662_timer_2, 0);

	__enable_irq();

	systick_delay(99);

	while(1) {
		_set_slottle(80);

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