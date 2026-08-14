#ifndef _MAX32662_CFG_H_
#define _MAX32662_CFG_H_

#include "max32662_sil.h"

#define INTPRI_POWER_FAULT				(-6)
#define INTPRI_WINDOW_WATCHDOG_TIMER0	(-6)
#define INTPRI_RTC						(-6)
#define INTPRI_TRNG						(-6)
#define INTPRI_TMR0						(-6)
#define INTPRI_TMR1						(-6)
#define INTPRI_TMR2						(-6)
#define INTPRI_TMR3						(-6)
#define INTPRI_I2C						(-6)
#define INTPRI_UART0					(-6)
#define INTPRI_UART1					(-6)
#define INTPRI_SPI0						(-6)
#define INTPRI_SPI1						(-6)
#define INTPRI_ADC						(-6)
#define INTPRI_FLASH_CONTROLLER0		(-6)
#define INTPRI_GPIO						(-6)
#define INTPRI_DAC0						(-6)
#define INTPRI_DAC1						(-6)
#define INTPRI_DAC2						(-6)
#define INTPRI_DAC3						(-6)
#define INTPRI_I2C1						(-6)
#define INTPRI_GPIOWAKE					(-6)
#define INTPRI_PULSE_TRAIN				(-6)
#define INTPRI_ECC						(-6)
#define INTPRI_AES						(-6)
#define INTPRI_I2S						(-6)
#define INTPRI_CAN						(-6)



#define INTATR_POWER_FAULT				(0)
#define INTATR_WINDOW_WATCHDOG_TIMER0	(0)
#define INTATR_RTC						(0)
#define INTATR_TRNG						(0)
#define INTATR_TMR0						(0)
#define INTATR_TMR1						(0)
#define INTATR_TMR2						(0)
#define INTATR_TMR3						(0)
#define INTATR_I2C						(0)
#define INTATR_UART0					(0)
#define INTATR_UART1					(0)
#define INTATR_SPI0						(0)
#define INTATR_SPI1						(0)
#define INTATR_ADC						(0)
#define INTATR_FLASH_CONTROLLER0		(0)
#define INTATR_GPIO						(0)
#define INTATR_DAC0						(0)
#define INTATR_DAC1						(0)
#define INTATR_DAC2						(0)
#define INTATR_DAC3						(0)
#define INTATR_I2C1						(0)
#define INTATR_GPIOWAKE					(0)
#define INTATR_PULSE_TRAIN				(0)
#define INTATR_ECC						(0)
#define INTATR_AES						(0)
#define INTATR_I2S						(0)
#define INTATR_CAN						(0)


extern void isr_power_fault(intptr_t exinf);
extern void isr_window_watchdog_tiemr0(intptr_t exinf);
extern void isr_rtc(intptr_t exinf);
extern void isr_trng(intptr_t exinf);
extern void isr_tmr0(intptr_t exinf);
extern void isr_tmr1(intptr_t exinf);
extern void isr_tmr2(intptr_t exinf);
extern void isr_tmr3(intptr_t exinf);
extern void isr_i2c0(intptr_t exinf);
extern void isr_uart0(intptr_t exinf);
extern void isr_uart1(intptr_t exinf);
extern void isr_spi0(intptr_t exinf);
extern void isr_spi1(intptr_t exinf);
extern void isr_adc(intptr_t exinf);
extern void isr_flash_controller0(intptr_t exinf);
extern void isr_gpio(intptr_t exinf);
extern void isr_dac0(intptr_t exinf);
extern void isr_dac1(intptr_t exinf);
extern void isr_dac2(intptr_t exinf);
extern void isr_dac3(intptr_t exinf);
extern void isr_i2c1(intptr_t exinf);
extern void isr_gpiowake(intptr_t exinf);
extern void isr_pulse_train(intptr_t exinf);
extern void isr_ecc(intptr_t exinf);
extern void isr_aes(intptr_t exinf);
extern void isr_i2s(intptr_t exinf);
extern void isr_can(intptr_t exinf);

#endif/*_MAX32662_CFG_H_*/