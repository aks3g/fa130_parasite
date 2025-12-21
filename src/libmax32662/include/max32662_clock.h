/*
 * max32662_clock.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 

#ifndef _MAX32662_CLOCK_H_
#define _MAX32662_CLOCK_H_

#include <stdint.h>

#pragma pack(1)
typedef struct 
{
	volatile uint32_t gcr_sysctrl;
	volatile uint32_t gcr_rst0;
	union {
		volatile uint32_t dword;
		struct{
			volatile uint32_t reserved0_5   : 6;
			volatile uint32_t sysclk_div    : 3;
			volatile uint32_t sysclk_sel    : 3;
			volatile uint32_t reserved12    : 1;
			volatile uint32_t sysclk_rdy    : 1;
			volatile uint32_t ipo_div       : 2;
			volatile uint32_t erfo_en       : 1;
			volatile uint32_t do_not_mod    : 2;
			volatile uint32_t ipo_en        : 1;
			volatile uint32_t ibro_en       : 1;
			volatile uint32_t ibro_vs       : 1;
			volatile uint32_t reserved22_23 : 2;
			volatile uint32_t efo_rdy       : 1;
			volatile uint32_t erto_rdy      : 1;
			volatile uint32_t reserved26    : 1;
			volatile uint32_t ipo_rdy       : 1;
			volatile uint32_t ibro_rdy      : 1;
			volatile uint32_t inro_rdy      : 1;
			volatile uint32_t reserved30    : 1;
			volatile uint32_t extclk_rdy    : 1;
		} bf;
	} gcr_clkctrl;
	volatile uint32_t gcr_pm;
	volatile uint32_t reserved_0x10_0x17[2];
	volatile uint32_t gcr_pclkdiv;
	volatile uint32_t reserved_0x1c_0x23[2];
	volatile uint32_t gcr_pclkdis0;
	volatile uint32_t gcr_memctrl;
	volatile uint32_t gcr_memz;
	volatile uint32_t reserved_0x30_0x3f[4];
	volatile uint32_t gcr_sysst;
	volatile uint32_t gcr_rst1;
	volatile uint32_t gcr_pclkdis1;
	volatile uint32_t gcr_eventen;
	volatile uint32_t gcr_revision;
	volatile uint32_t gcr_sysie;
} Max32662_gcr;
#pragma pack()

#define MAX32662_GCR		((volatile Max32662_gcr *)0x40000000)


typedef enum
{
	Max32662_gcr_ipo_div_1 = 0,
	Max32662_gcr_ipo_div_2 = 1,
	Max32662_gcr_ipo_div_4 = 2,
	Max32662_gcr_ipo_div_8 = 3,
} Max32662_gcr_ipo_div;


typedef enum
{
	Max32662_gcr_sysclk_erfo    = 2,
	Max32662_gcr_sysclk_inro    = 3,
	Max32662_gcr_sysclk_ipo     = 4,
	Max32662_gcr_sysclk_ibro    = 5,
	Max32662_gcr_sysclk_ertco   = 6,
	Max32662_gcr_sysclk_ext_clk = 7,
} Max32662_gcr_sysclk_sel;

typedef enum
{
	Max32662_gcr_sysclk_div_1   = 0,
	Max32662_gcr_sysclk_div_2   = 1,
	Max32662_gcr_sysclk_div_4   = 2,
	Max32662_gcr_sysclk_div_8   = 3,
	Max32662_gcr_sysclk_div_16  = 4,
	Max32662_gcr_sysclk_div_32  = 5,
	Max32662_gcr_sysclk_div_64  = 6,
	Max32662_gcr_sysclk_div_128 = 7,
} Max32662_gcr_sysclk_div;

typedef enum
{
	Max32662_peripheral_gpio0   = (1 << 0),
	Max32662_peripheral_dma     = (1 << 5),
	Max32662_peripheral_spi0    = (1 << 6),
	Max32662_peripheral_spi1    = (1 << 7),
	Max32662_peripheral_uart0   = (1 << 9),
	Max32662_peripheral_uart1   = (1 << 10),
	Max32662_peripheral_i2c0    = (1 << 13),
	Max32662_peripheral_tmr0    = (1 << 15),
	Max32662_peripheral_tmr1    = (1 << 16),
	Max32662_peripheral_tmr2    = (1 << 17),
	Max32662_peripheral_adc     = (1 << 23),
	Max32662_peripheral_i2c1    = (1 << 28),
	Max32662_peripheral_pt      = (1 << 29),
} Max32662_gcr_peripheral;

typedef enum
{
	Max32662_reset_dma          = (1 << 0),
	Max32662_reset_wdt          = (1 << 1),
	Max32662_reset_gpio0        = (1 << 2),
	Max32662_reset_tmr0         = (1 << 4),
	Max32662_reset_tmr1         = (1 << 6),
	Max32662_reset_tmr2         = (1 << 7),
	Max32662_reset_uart0        = (1 << 11),
	Max32662_reset_uart1        = (1 << 12),
	Max32662_reset_spi0         = (1 << 13),
	Max32662_reset_spi1         = (1 << 14),
	Max32662_reset_i2c0         = (1 << 16),
	Max32662_reset_can          = (1 << 19),
	Max32662_reset_trng         = (1 << 24),
	Max32662_reset_adc          = (1 << 26),
	Max32662_reset_soft         = (1 << 29),
	Max32662_reset_perih        = (1 << 20),
	Max32662_reset_sys          = (1 << 31),
} Max32662_gcr_reset;


#define MAX32662_IBRO_CLK_HZ 7372800

extern int max32662_clock_setup_internal_ibro(void);
extern int max32662_clock_setup_internal_primary_osc(Max32662_gcr_ipo_div prescale);
extern int max32662_clock_setup_sysclock(Max32662_gcr_sysclk_sel sel, Max32662_gcr_sysclk_div prescale);
extern int max32662_clock_enter_sleep(void);
extern int max32662_clock_exit_sleep(void);
extern int max32662_clock_peripheral(Max32662_gcr_peripheral peri, uint32_t enable);
extern int max32662_clock_reset(Max32662_gcr_reset peri);


#endif
