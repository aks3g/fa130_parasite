/*
 * gpio_portmap.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 
#ifndef _GPIO_PORTMAP_H_
#define _GPIO_PORTMAP_H_

// for Debugger
#define PARASITE_PIN_EXT_COM_DET	Max32662_gpio_14
#define PARASITE_PIN_DBG_UART_TX	Max32662_gpio_2
#define PARASITE_PIN_DBG_UART_RX	Max32662_gpio_3

#define PARASITE_ALT_EXT_COM_DET	(0)
#define PARASITE_ALT_DBG_UART_TX	(2)
#define PARASITE_ALT_DBG_UART_RX	(2)

#define PARASITE_PUD_EXT_COM_DET	(Max32662_gpio_pull_up)
#define PARASITE_PUD_DBG_UART_TX	(Max32662_gpio_hi_impedance)
#define PARASITE_PUD_DBG_UART_RX	(Max32662_gpio_hi_impedance)

#define PARASITE_IO__EXT_COM_DET	(Max32662_gpio_input)
#define PARASITE_IO__DBG_UART_TX	(Max32662_gpio_output)
#define PARASITE_IO__DBG_UART_RX	(Max32662_gpio_input)

#define PARASITE_OUT_EXT_COM_DET	(0)
#define PARASITE_OUT_DBG_UART_TX	(0)
#define PARASITE_OUT_DBG_UART_RX	(0)


#define PARASITE_PIN_DBG_LED		Max32662_gpio_2

#define PARASITE_ALT_DBG_LED		(0)

#define PARASITE_PUD_DBG_LED		(Max32662_gpio_pull_up)

#define PARASITE_IO__DBG_LED		(Max32662_gpio_output)

#define PARASITE_OUT_DBG_LED		(1)


// for Motor driver
#define PARASITE_PIN_MD_CTRL1		Max32662_gpio_4
#define PARASITE_PIN_MD_CTRL2		Max32662_gpio_15
#define PARASITE_PIN_MD_PWM1		Max32662_gpio_16
#define PARASITE_PIN_MD_PWM2		Max32662_gpio_5
#define PARASITE_PIN_MD_FB			Max32662_gpio_20

#define PARASITE_ALT_MD_CTRL1		(0)
#define PARASITE_ALT_MD_CTRL2		(0)
#define PARASITE_ALT_MD_PWM1		(0)
#define PARASITE_ALT_MD_PWM2		(0)
#define PARASITE_ALT_MD_FB			(0)

#define PARASITE_PUD_MD_CTRL1		(Max32662_gpio_hi_impedance)
#define PARASITE_PUD_MD_CTRL2		(Max32662_gpio_hi_impedance)
#define PARASITE_PUD_MD_PWM1		(Max32662_gpio_hi_impedance)
#define PARASITE_PUD_MD_PWM2		(Max32662_gpio_hi_impedance)
#define PARASITE_PUD_MD_FB			(Max32662_gpio_hi_impedance)

#define PARASITE_IO__MD_CTRL1		(Max32662_gpio_output)
#define PARASITE_IO__MD_CTRL2		(Max32662_gpio_output)
#define PARASITE_IO__MD_PWM1		(Max32662_gpio_output)
#define PARASITE_IO__MD_PWM2		(Max32662_gpio_output)
#define PARASITE_IO__MD_FB			(Max32662_gpio_input)

#define PARASITE_OUT_MD_CTRL1		(0)
#define PARASITE_OUT_MD_CTRL2		(0)
#define PARASITE_OUT_MD_PWM1		(0)
#define PARASITE_OUT_MD_PWM2		(0)
#define PARASITE_OUT_MD_FB			(0)


// for IMU
#define PARASITE_PIN_SENS_INT		Max32662_gpio_19
#define PARASITE_PIN_SENS_SCL		Max32662_gpio_6
#define PARASITE_PIN_SENS_SDA		Max32662_gpio_9

#define PARASITE_ALT_SENS_INT		(0)
#define PARASITE_ALT_SENS_SCL		(1)
#define PARASITE_ALT_SENS_SDA		(1)

#define PARASITE_PUD_SENS_INT		(Max32662_gpio_pull_up)
#define PARASITE_PUD_SENS_SCL		(Max32662_gpio_pull_up)
#define PARASITE_PUD_SENS_SDA		(Max32662_gpio_pull_up)

#define PARASITE_IO__SENS_INT		(Max32662_gpio_input)
#define PARASITE_IO__SENS_SCL		(Max32662_gpio_input)
#define PARASITE_IO__SENS_SDA		(Max32662_gpio_input)

#define PARASITE_OUT_SENS_INT		(0)
#define PARASITE_OUT_SENS_SCL		(0)
#define PARASITE_OUT_SENS_SDA		(0)


// for serial flash
#define PARASITE_PIN_MISO			Max32662_gpio_7
#define PARASITE_PIN_MOSI			Max32662_gpio_8
#define PARASITE_PIN_SCK			Max32662_gpio_17
#define PARASITE_PIN_CS				Max32662_gpio_18

#define PARASITE_ALT_MISO			(1)
#define PARASITE_ALT_MOSI			(1)
#define PARASITE_ALT_SCK			(1)
#define PARASITE_ALT_CS				(1)

#define PARASITE_PUD_MISO			(Max32662_gpio_hi_impedance)
#define PARASITE_PUD_MOSI			(Max32662_gpio_hi_impedance)
#define PARASITE_PUD_SCK			(Max32662_gpio_hi_impedance)
#define PARASITE_PUD_CS				(Max32662_gpio_hi_impedance)

#define PARASITE_IO__MISO			(Max32662_gpio_input)
#define PARASITE_IO__MOSI			(Max32662_gpio_output)
#define PARASITE_IO__SCK			(Max32662_gpio_output)
#define PARASITE_IO__CS				(Max32662_gpio_output)

#define PARASITE_OUT_MISO			(0)
#define PARASITE_OUT_MOSI			(0)
#define PARASITE_OUT_SCK			(0)
#define PARASITE_OUT_CS				(0)


// for ADC
#define PARASITE_PIN_B_MON			Max32662_gpio_10
#define PARASITE_PIN_M_M			Max32662_gpio_11
#define PARASITE_PIN_M_P			Max32662_gpio_12
#define PARASITE_PIN_I_MON			Max32662_gpio_13

#define PARASITE_ALT_B_MON			(4)
#define PARASITE_ALT_M_M			(4)
#define PARASITE_ALT_M_P			(4)
#define PARASITE_ALT_I_MON			(4)

#define PARASITE_PUD_B_MON			(Max32662_gpio_hi_impedance)
#define PARASITE_PUD_M_M			(Max32662_gpio_hi_impedance)
#define PARASITE_PUD_M_P			(Max32662_gpio_hi_impedance)
#define PARASITE_PUD_I_MON			(Max32662_gpio_hi_impedance)

#define PARASITE_IO__B_MON			(Max32662_gpio_input)
#define PARASITE_IO__M_M			(Max32662_gpio_input)
#define PARASITE_IO__M_P			(Max32662_gpio_input)
#define PARASITE_IO__I_MON			(Max32662_gpio_input)

#define PARASITE_OUT_B_MON			(0)
#define PARASITE_OUT_M_M			(0)
#define PARASITE_OUT_M_P			(0)
#define PARASITE_OUT_I_MON			(0)

extern void driver_gpio_init(void);
extern uint32_t driver_gpio_get_boot_strap(void);
extern void driver_gpio_setup_led(void);
extern void driver_gpio_led_on(void);
extern void driver_gpio_led_off(void);
extern void driver_gpio_led_toggle(void);

#endif

