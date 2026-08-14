/*
 * gpio_portmap.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 
#include <kernel.h>

#include "max32662_gpio.h" 

#include "driver/gpio.h"

#pragma pack(1)
typedef struct
{
	Max32662_gpio_pin      pin;
	uint8_t                alt;
	Max32662_gpio_pullmode pul;
	Max32662_gpio_inout    io;
	uint8_t                out;
} GpioSetting;
#pragma pack()

static GpioSetting _gpioSettings[]
=
{
	// Pin No                  Alternative Function      Pull-mode                 Input/Output              Initial Output Value
	{PARASITE_PIN_EXT_COM_DET, PARASITE_ALT_EXT_COM_DET, PARASITE_PUD_EXT_COM_DET, PARASITE_IO__EXT_COM_DET, PARASITE_OUT_EXT_COM_DET},
	{PARASITE_PIN_DBG_UART_TX, PARASITE_ALT_DBG_UART_TX, PARASITE_PUD_DBG_UART_TX, PARASITE_IO__DBG_UART_TX, PARASITE_OUT_DBG_UART_TX},
	{PARASITE_PIN_DBG_UART_RX, PARASITE_ALT_DBG_UART_RX, PARASITE_PUD_DBG_UART_RX, PARASITE_IO__DBG_UART_RX, PARASITE_OUT_DBG_UART_RX},
	{PARASITE_PIN_MD_CTRL1,    PARASITE_ALT_MD_CTRL1,    PARASITE_PUD_MD_CTRL1,    PARASITE_IO__MD_CTRL1,    PARASITE_OUT_MD_CTRL1   },
	{PARASITE_PIN_MD_CTRL2,    PARASITE_ALT_MD_CTRL2,    PARASITE_PUD_MD_CTRL2,    PARASITE_IO__MD_CTRL2,    PARASITE_OUT_MD_CTRL2   },
	{PARASITE_PIN_MD_PWM1,     PARASITE_ALT_MD_PWM1,     PARASITE_PUD_MD_PWM1,     PARASITE_IO__MD_PWM1,     PARASITE_OUT_MD_PWM1    },
	{PARASITE_PIN_MD_PWM2,     PARASITE_ALT_MD_PWM2,     PARASITE_PUD_MD_PWM2,     PARASITE_IO__MD_PWM2,     PARASITE_OUT_MD_PWM2    },
	{PARASITE_PIN_MD_FB,       PARASITE_ALT_MD_FB,       PARASITE_PUD_MD_FB,       PARASITE_IO__MD_FB,       PARASITE_OUT_MD_FB      },
	{PARASITE_PIN_SENS_INT,    PARASITE_ALT_SENS_INT,    PARASITE_PUD_SENS_INT,    PARASITE_IO__SENS_INT,    PARASITE_OUT_SENS_INT   },
	{PARASITE_PIN_SENS_SCL,    PARASITE_ALT_SENS_SCL,    PARASITE_PUD_SENS_SCL,    PARASITE_IO__SENS_SCL,    PARASITE_OUT_SENS_SCL   },
	{PARASITE_PIN_SENS_SDA,    PARASITE_ALT_SENS_SDA,    PARASITE_PUD_SENS_SDA,    PARASITE_IO__SENS_SDA,    PARASITE_OUT_SENS_SDA   },
	{PARASITE_PIN_MISO,        PARASITE_ALT_MISO,        PARASITE_PUD_MISO,        PARASITE_IO__MISO,        PARASITE_OUT_MISO,      },
	{PARASITE_PIN_MOSI,        PARASITE_ALT_MOSI,        PARASITE_PUD_MOSI,        PARASITE_IO__MOSI,        PARASITE_OUT_MOSI,      },
	{PARASITE_PIN_SCK,         PARASITE_ALT_SCK,         PARASITE_PUD_SCK,         PARASITE_IO__SCK,         PARASITE_OUT_SCK,       },
	{PARASITE_PIN_CS,          PARASITE_ALT_CS,          PARASITE_PUD_CS,          PARASITE_IO__CS,          PARASITE_OUT_CS,        },
	{PARASITE_PIN_B_MON,       PARASITE_ALT_B_MON,       PARASITE_PUD_B_MON,       PARASITE_IO__B_MON,       PARASITE_OUT_B_MON,     },
	{PARASITE_PIN_M_M,         PARASITE_ALT_M_M,         PARASITE_PUD_M_M,         PARASITE_IO__M_M,         PARASITE_OUT_M_M,       },
	{PARASITE_PIN_M_P,         PARASITE_ALT_M_P,         PARASITE_PUD_M_P,         PARASITE_IO__M_P,         PARASITE_OUT_M_P,       },
	{PARASITE_PIN_I_MON,       PARASITE_ALT_I_MON,       PARASITE_PUD_I_MON,       PARASITE_IO__I_MON,       PARASITE_OUT_I_MON,     },
};



void driver_gpio_init(void)
{
	for (size_t i=0 ; i<sizeof(_gpioSettings)/sizeof(_gpioSettings[0]) ; ++i) {
		max32662_gpio_altfunc(_gpioSettings[i].pin, _gpioSettings[i].alt, 1);

		max32662_gpio_setup_inout   (_gpioSettings[i].pin, _gpioSettings[i].io); 
		max32662_gpio_setup_pullmode(_gpioSettings[i].pin, _gpioSettings[i].pul);
		max32662_gpio_outout        (_gpioSettings[i].pin, _gpioSettings[i].out);

		max32662_gpio_altfunc(_gpioSettings[i].pin, _gpioSettings[i].alt, 0);
	}

	// Enable GPIO
	max32662_gpio_enable_interrupt(1);

	return;
}

uint32_t driver_gpio_get_boot_strap(void)
{
	uint32_t boot_strap = 0;
	max32662_gpio_input(PARASITE_PIN_EXT_COM_DET, &boot_strap);

	return boot_strap;
}

void driver_gpio_setup_led(void)
{
	max32662_gpio_altfunc(PARASITE_PIN_DBG_LED, PARASITE_ALT_DBG_LED, 1);

	max32662_gpio_setup_inout   (PARASITE_PIN_DBG_LED, PARASITE_IO__DBG_LED); 
	max32662_gpio_setup_pullmode(PARASITE_PIN_DBG_LED, PARASITE_PUD_DBG_LED);
	max32662_gpio_outout        (PARASITE_PIN_DBG_LED, PARASITE_OUT_DBG_LED);

	max32662_gpio_altfunc(PARASITE_PIN_DBG_LED, PARASITE_ALT_DBG_LED, 0);

}

void driver_gpio_led_on(void)
{
	max32662_gpio_outout(PARASITE_PIN_DBG_LED, 0);
	return;
}

void driver_gpio_led_off(void)
{
	max32662_gpio_outout(PARASITE_PIN_DBG_LED, 1);
	return;
}

void driver_gpio_led_toggle(void)
{
	max32662_gpio_outout_toggle(PARASITE_PIN_DBG_LED);
	return;
}

void isr_gpio(intptr_t exinf)
{
	(void)exinf;
	gpio0_handler();
}
