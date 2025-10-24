
#include <stdint.h>

#include "cortex_m4.h"

extern uint32_t _svectors;
extern uint32_t _szero;
extern uint32_t _ezero;
extern uint32_t _sstack;
extern uint32_t _etext;
extern uint32_t _srelocate;
extern uint32_t _erelocate;
extern const char *_estack[];

int main(void);

void dummy_handler(void);

/* Cortex-M4 core handlers */
void Reset_Handler(void);

/* Peripherals handlers */

/* Exception Table */
typedef void (*fp)(void);

__attribute__((weak)) void nmi_handler(void){while(1);}
__attribute__((weak)) void hard_fault_handler(void){while(1);}
__attribute__((weak)) void memory_management_fault_handler(void){while(1);}
__attribute__((weak)) void bus_fauult_handler(void){while(1);}
__attribute__((weak)) void usage_fault_handler(void){while(1);}
__attribute__((weak)) void svcall_handler(void){while(1);}
__attribute__((weak)) void pendsv_handler(void){while(1);}
__attribute__((weak)) void sys_tick_handler(void){while(1);}
 
__attribute__((weak)) void power_fail_handler(void){while(1);}
__attribute__((weak)) void windowd_watchdog_timer0_handler(void){while(1);}
__attribute__((weak)) void rtc_handler(void){while(1);}
__attribute__((weak)) void trng_handler(void){while(1);}
__attribute__((weak)) void tmr0_handler(void){while(1);}
__attribute__((weak)) void tmr1_handler(void){while(1);}
__attribute__((weak)) void tmr2_handler(void){while(1);}
__attribute__((weak)) void tmr3_handler(void){while(1);}
__attribute__((weak)) void i2c0_handler(void){while(1);}
__attribute__((weak)) void uart0_handler(void){while(1);}
__attribute__((weak)) void uart1_handler(void){while(1);}
__attribute__((weak)) void spi0_handler(void){while(1);}
__attribute__((weak)) void spi1_handler(void){while(1);}
__attribute__((weak)) void adc_handler(void){while(1);}
__attribute__((weak)) void flash_controller0_handler(void){while(1);}
__attribute__((weak)) void gpio0_handler(void){while(1);}
__attribute__((weak)) void dmac0_handler(void){while(1);}
__attribute__((weak)) void dmac1_handler(void){while(1);}
__attribute__((weak)) void dmac2_handler(void){while(1);}
__attribute__((weak)) void dmac3_handler(void){while(1);}
__attribute__((weak)) void i2c1_handler(void){while(1);}
__attribute__((weak)) void gpiowake_handler(void){while(1);}
__attribute__((weak)) void pulse_train_handler(void){while(1);}
__attribute__((weak)) void ecc_handler(void){while(1);}
__attribute__((weak)) void aes_handler(void){while(1);}
__attribute__((weak)) void i2s_handler(void){while(1);}
__attribute__((weak)) void can_handler(void){while(1);}


const fp exception_table[] __attribute__ ((used)) __attribute__ ((section(".vectors")))= {
	(fp)_estack,

	// Cortex M4
	(fp) Reset_Handler,
	(fp) nmi_handler,
	(fp) hard_fault_handler,
	(fp) memory_management_fault_handler,
	(fp) bus_fauult_handler,
	(fp) usage_fault_handler,
	(fp) (0UL), /* Reserved */
	(fp) (0UL), /* Reserved */
	(fp) (0UL), /* Reserved */
	(fp) (0UL), /* Reserved */
	(fp) svcall_handler,
	(fp) dummy_handler,
	(fp) (0UL), /* Reserved */
	(fp) pendsv_handler,
	(fp) sys_tick_handler,

	// max32662
	(fp) power_fail_handler,				// 16
	(fp) windowd_watchdog_timer0_handler,	// 17
	(fp) dummy_handler,						// 18
	(fp) rtc_handler,						// 19
	(fp) trng_handler,						// 20
	(fp) tmr0_handler,						// 21
	(fp) tmr1_handler,						// 22
	(fp) tmr2_handler,						// 23
	(fp) tmr3_handler,						// 24
	(fp) dummy_handler,						// 25
	(fp) dummy_handler,						// 26
	(fp) dummy_handler,						// 27
	(fp) dummy_handler,						// 28
	(fp) i2c0_handler,						// 29
	(fp) uart0_handler,						// 30
	(fp) uart1_handler,						// 31
	(fp) spi0_handler,						// 32
	(fp) spi1_handler,						// 33
	(fp) dummy_handler,						// 34
	(fp) dummy_handler,						// 35
	(fp) adc_handler,						// 36
	(fp) dummy_handler,						// 37
	(fp) dummy_handler,						// 38
	(fp) flash_controller0_handler,			// 39
	(fp) gpio0_handler,						// 40
	(fp) dummy_handler,						// 41
	(fp) dummy_handler,						// 42
	(fp) dummy_handler,						// 43
	(fp) dmac0_handler,						// 44
	(fp) dmac1_handler,						// 45
	(fp) dmac2_handler,						// 46
	(fp) dmac3_handler,						// 47
	(fp) dummy_handler,						// 48
	(fp) dummy_handler,						// 49
	(fp) dummy_handler,						// 50
	(fp) dummy_handler,						// 51
	(fp) i2c1_handler,						// 52
	(fp) dummy_handler,						// 53
	(fp) dummy_handler,						// 54
	(fp) dummy_handler,						// 55
	(fp) dummy_handler,						// 56
	(fp) dummy_handler,						// 57
	(fp) dummy_handler,						// 58
	(fp) dummy_handler,						// 59
	(fp) dummy_handler,						// 60
	(fp) dummy_handler,						// 61
	(fp) dummy_handler,						// 62
	(fp) dummy_handler,						// 63
	(fp) dummy_handler,						// 64
	(fp) dummy_handler,						// 65
	(fp) dummy_handler,						// 66
	(fp) dummy_handler,						// 67
	(fp) dummy_handler,						// 68
	(fp) dummy_handler,						// 69
	(fp) gpiowake_handler,					// 70
	(fp) dummy_handler,						// 71
	(fp) dummy_handler,						// 72
	(fp) dummy_handler,						// 73
	(fp) dummy_handler,						// 74
	(fp) pulse_train_handler,				// 75
	(fp) dummy_handler,						// 76
	(fp) dummy_handler,						// 77
	(fp) dummy_handler,						// 78
	(fp) dummy_handler,						// 79
	(fp) dummy_handler,						// 80
	(fp) dummy_handler,						// 81
	(fp) dummy_handler,						// 82
	(fp) dummy_handler,						// 83
	(fp) dummy_handler,						// 84
	(fp) dummy_handler,						// 85
	(fp) dummy_handler,						// 86
	(fp) dummy_handler,						// 87
	(fp) dummy_handler,						// 88
	(fp) dummy_handler,						// 89
	(fp) dummy_handler,						// 90
	(fp) dummy_handler,						// 91
	(fp) dummy_handler,						// 92
	(fp) dummy_handler,						// 93
	(fp) dummy_handler,						// 94
	(fp) dummy_handler,						// 95
	(fp) dummy_handler,						// 96
	(fp) dummy_handler,						// 97
	(fp) ecc_handler,						// 98
	(fp) dummy_handler,						// 99
	(fp) dummy_handler,						// 100
	(fp) dummy_handler,						// 101
	(fp) dummy_handler,						// 102
	(fp) dummy_handler,						// 103
	(fp) dummy_handler,						// 104
	(fp) dummy_handler,						// 105
	(fp) dummy_handler,						// 106
	(fp) dummy_handler,						// 107
	(fp) dummy_handler,						// 108
	(fp) dummy_handler,						// 109
	(fp) dummy_handler,						// 110
	(fp) dummy_handler,						// 111
	(fp) dummy_handler,						// 112
	(fp) aes_handler,						// 113
	(fp) dummy_handler,						// 114
	(fp) i2s_handler,						// 115
	(fp) dummy_handler,						// 116
	(fp) dummy_handler,						// 117
	(fp) dummy_handler,						// 118
	(fp) dummy_handler,						// 119
	(fp) dummy_handler,						// 120
	(fp) dummy_handler,						// 121
	(fp) dummy_handler,						// 122
	(fp) can_handler,						// 123
	(fp) dummy_handler,						// 124
	(fp) dummy_handler,						// 125
	(fp) dummy_handler,						// 126
	(fp) dummy_handler,						// 127
};


void Reset_Handler(void)
{
	uint32_t *p_src, *p_dst;

	__asm volatile("ldr r0, =_estack");
	__asm volatile("mov sp, r0");

	p_src = &_etext;
	p_dst = &_srelocate;

	if (p_src != p_dst) {
		for (; p_dst < &_erelocate;) {
			*p_dst++ = *p_src++;
		}
	}

	// Fill zero to BSS
	for (p_dst = &_szero; p_dst < &_ezero;) {
		*p_dst++ = 0;
	}

	// Set Vector Table offset
	p_src = (uint32_t *) & _svectors;
	CM4_SCB->vtor = ((uint32_t) p_src & CM4_SCB_VTOR_TBLOFF_MASK);

	// Enable FPU(CP10/CP11) full access
	CM4_SCB->cpacr |= (0x0000000F << 20);
	__dsb();
	__isb();

	main();

	while(1);
}

/**
 * \brief Default interrupt handler for unused IRQs.
 */
void dummy_handler(void)
{
	while (1);
}
