#include "max32662_cfg.h"

void isr_power_fault(intptr_t exinf)
{
	(void)exinf;
}

void isr_window_watchdog_tiemr0(intptr_t exinf)
{
	(void)exinf;
}

void isr_rtc(intptr_t exinf)
{
	(void)exinf;
}

void isr_trng(intptr_t exinf)
{
	(void)exinf;
}

void isr_tmr0(intptr_t exinf)
{
	(void)exinf;
}


void isr_tmr1(intptr_t exinf)
{
	(void)exinf;
}

void isr_tmr2(intptr_t exinf)
{
	(void)exinf;
}

void isr_tmr3(intptr_t exinf)
{
	(void)exinf;
}

void isr_i2c0(intptr_t exinf)
{
	(void)exinf;
}

void isr_uart0(intptr_t exinf)
{
	(void)exinf;
}

#if 0
void isr_uart1(intptr_t exinf)
{
	size_t len = 0;

	max32662_uart_isr(1);

	max32662_uart_rx(1, NULL, 0, &len);
	if (len != 0) set_flg(UART_FLG, UART_FLG_RX);

}
#endif

#if 0
void isr_spi0(intptr_t exinf)
{
	(void)exinf;
}

void isr_spi1(intptr_t exinf)
{
	(void)exinf;
}
#endif

#if 0
void isr_adc(intptr_t exinf)
{
	(void)exinf;
}
#endif

void isr_flash_controller0(intptr_t exinf)
{
	(void)exinf;
}

#if 0
void isr_gpio(intptr_t exinf)
{
	(void)exinf;
}

void isr_dac0(intptr_t exinf)
{
	(void)exinf;
	dmac0_handler();
}

void isr_dac1(intptr_t exinf)
{
	(void)exinf;
	dmac1_handler();
}

void isr_dac2(intptr_t exinf)
{
	(void)exinf;
	dmac2_handler();
}

void isr_dac3(intptr_t exinf)
{
	(void)exinf;
	dmac3_handler();
}
#endif

void isr_i2c1(intptr_t exinf)
{
	(void)exinf;
}

void isr_gpiowake(intptr_t exinf)
{
	(void)exinf;
}

void isr_pulse_train(intptr_t exinf)
{
	(void)exinf;
}

void isr_ecc(intptr_t exinf)
{
	(void)exinf;
}

void isr_aes(intptr_t exinf)
{
	(void)exinf;
}

void isr_i2s(intptr_t exinf)
{
	(void)exinf;
}

void isr_can(intptr_t exinf)
{
	(void)exinf;
}
