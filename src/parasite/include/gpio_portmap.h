/*
 * gpio_portmap.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 

#ifndef _GPIO_PORTMAP_H_
#define _GPIO_PORTMAP_H_

#include "max32662_gpio.h"

// for Debugger
#define PARASITE_PIN_EXT_COM_DET	Max32662_gpio_14
#define PARASITE_PIN_DBG_UART_TX	Max32662_gpio_2
#define PARASITE_PIN_DBG_UART_RX	Max32662_gpio_3

#define PARASITE_ALT_EXT_COM_DET	()
#define PARASITE_ALT_DBG_UART_TX	()
#define PARASITE_ALT_DBG_UART_RX	()

#define PARASITE_PUD_EXT_COM_DET	()
#define PARASITE_PUD_DBG_UART_TX	()
#define PARASITE_PUD_DBG_UART_RX	()

#define PARASITE_IO__EXT_COM_DET	()
#define PARASITE_IO__DBG_UART_TX	()
#define PARASITE_IO__DBG_UART_RX	()

// for Motor driver
#define PARASITE_PIN_MD_CTRL1		Max32662_gpio_4
#define PARASITE_PIN_MD_CTRL2		Max32662_gpio_15
#define PARASITE_PIN_MD_PWM1		Max32662_gpio_16
#define PARASITE_PIN_MD_PWM2		Max32662_gpio_5

// for IMU
#define PARASITE_PIN_SENS_INT		Max32662_gpio_19
#define PARASITE_PIN_SCL			Max32662_gpio_6
#define PARASITE_PIN_SDA			Max32662_gpio_9

// for serial flash
#define PARASITE_PIN_MISO			Max32662_gpio_7
#define PARASITE_PIN_MOSI			Max32662_gpio_8
#define PARASITE_PIN_SCK			Max32662_gpio_17
#define PARASITE_PIN_CS				Max32662_gpio_18

// for ADC
#define PARASITE_PIN_B_MON			Max32662_gpio_10
#define PARASITE_PIN_M_M			Max32662_gpio_11
#define PARASITE_PIN_M_P			Max32662_gpio_12
#define PARASITE_PIN_I_MON			Max32662_gpio_13


#endif