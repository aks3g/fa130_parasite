/*
 * cortex_m4.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef _CORTEX_M4_H_
#define _CORTEX_M4_H_

#include <stdint.h>

typedef struct {
	uint32_t reserved0[1];
	uint32_t ictr;
	uint32_t actrl;
} cm4_scs;

typedef struct 
{
	union {
		uint32_t dword;
		struct {
			uint32_t enable        : 1;
			uint32_t tickint       : 1;
			uint32_t clksource     : 1;
			uint32_t reserved3_15  : 13;
			uint32_t countflag     : 1;
			uint32_t reserved31_17 : 15;
		}bf;
	} control_and_status;

	uint32_t reload_value;
	uint32_t current_value;
	uint32_t calibration_value;
} cm4_systick;

typedef struct {
	uint32_t iser[8];			// +0x0000_0000
	uint32_t reserved0[24];
	uint32_t icer[8];			// +0x0000_0080
	uint32_t reserved1[24];
	uint32_t ispr[8];			// +0x0000_0100
	uint32_t reserved2[24];
	uint32_t icpr[8];			// +0x0000_0180
	uint32_t reserved3[24];
	uint32_t iabr[8];			// +0x0000_0200
	uint32_t reserved4[56];
	uint8_t  ip[240];			// +0x0000_0280
	uint32_t reserved5[644];
	uint32_t STIR;
} cm4_nvic;

typedef struct {
	uint32_t cpuid;
	uint32_t icsr;
	uint32_t vtor;
	uint32_t aircr;
	uint32_t scr;
	uint32_t ccr;
	uint8_t  shp[12];
	uint32_t shcsr;
	uint32_t cfsr;
	uint32_t hfsr;
	uint32_t dfsr;
	uint32_t mmfar;
	uint32_t bfar;
	uint32_t afsr;
	uint32_t pfr[2];
	uint32_t dfr;
	uint32_t adr;
	uint32_t mmfr[4];
	uint32_t isar[5];
	uint32_t reserved[5];
	uint32_t cpacr;
} cm4_scb;

/* System Control Space */
#define CM4_SCS_BASE			(0xE000E000UL) 

#define CM4_SYS_TICK_BASE		(CM4_SCS_BASE + 0x0010UL)
#define CM4_NVIC_BASE			(CM4_SCS_BASE + 0x0100UL)
#define CM4_SCB_BASE			(CM4_SCS_BASE + 0x0D00UL)

#define CM4_SCS					((cm4_scs *)    CM4_SCS_BASE)
#define CM4_SYS_TICK			((cm4_systick *)CM4_SYS_TICK_BASE)
#define CM4_NVIC				((cm4_nvic *)   CM4_NVIC_BASE)
#define CM4_SCB					((cm4_scb *)    CM4_SCB_BASE)


#define CM4_SCB_VTOR_TBLOFF_MASK   (0x1FFFFFFUL << 7)


__attribute__((always_inline)) static inline void __isb(void)
{
    __asm volatile("isb");
}

__attribute__((always_inline)) static inline void __dsb(void)
{
    __asm volatile("dsb");
}

__attribute__((always_inline)) static inline void __dmb(void)
{
    __asm volatile("dmb");
}

__attribute__((always_inline)) static inline void __enable_irq(void)
{
    __asm volatile("cpsie i" : : : "memory");
}

__attribute__((always_inline)) static inline void __disable_irq(void)
{
    __asm volatile("cpsid i" : : : "memory");
}

__attribute__((always_inline)) static inline void __enable_nvic_irq(int irqnum)
{
    CM4_NVIC->iser[irqnum>>5] = (1<<(irqnum&0x1F));
}

__attribute__((always_inline)) static inline void __disable_nvic_irq(int irqnum)
{
    CM4_NVIC->icer[irqnum>>5] = (1<<(irqnum&0x1F));
}



//J ここにあるべきなのか悩む
extern void systick_init(uint32_t period_ms, uint32_t core_clk_Hz);
extern void systick_delay(uint32_t delay_ms);

#endif//_CORTEX_M4_H_