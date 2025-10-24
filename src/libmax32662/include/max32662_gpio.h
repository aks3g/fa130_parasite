/*
 * max32662_goio.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 
#ifndef _MAX32662_GPIO_H_
#define _MAX32662_GPIO_H_

#include <stdint.h>

#pragma pack(1)
typedef struct 
{
	// 0x40008000
	uint32_t gpion_en0;
	uint32_t gpion_en0_set;
	uint32_t gpion_en0_clr;
	uint32_t gpion_outen;
	// 0x40008010
	uint32_t gpion_outen_set;
	uint32_t gpion_outen_clr;
	uint32_t gpion_out;
	uint32_t gpion_out_set;
	// 0x40008020
	uint32_t gpion_out_clr;
	uint32_t gpion_in;
	uint32_t gpion_intmode;
	uint32_t gpion_intpol;
	// 0x40008030
	uint32_t gpion_inen;
	uint32_t gpion_inten;
	uint32_t gpion_inten_set;
	uint32_t gpion_inten_clr;
	// 0x40008040
	uint32_t gpion_intfl;
	uint32_t reserved_0x44;
	uint32_t gpion_intfl_clr;
	uint32_t gpion_wken;
	// 0x40008050
	uint32_t gpion_wken_set;
	uint32_t gpion_wken_clr;
	uint32_t reserved_0x58;
	uint32_t gpion_dualedge;
	// 0x40008060
	uint32_t gpion_padctrl0;
	uint32_t gpion_padctrl1;
	uint32_t gpion_en1;
	uint32_t gpion_en1_set;
	// 0x40008070
	uint32_t gpion_en1_clr;
	uint32_t gpion_en2;
	uint32_t gpion_en2_set;
	uint32_t gpion_en2_clr;
	// 0x40008080
	uint32_t gpion_en3;
	uint32_t gpion_en3_set;
	uint32_t gpion_en3_clr;
	uint32_t reserved_0x8c_0xa7[7];
	// 0x40008090
	uint32_t gpion_hysen;
	uint32_t gpion_srsel;
	uint32_t gpion_ds0;
	uint32_t gpion_ds1;
	
	uint32_t gpion_ps;
	uint32_t reserved_0xbc;
	uint32_t gpion_vssel;
} Max32662_reg_gpio;
#pragma pack()

#define MAX32662_GPIO			((Max32662_reg_gpio *)0x40008000)

typedef enum
{
	Max32662_gpio_0,
	Max32662_gpio_1,
	Max32662_gpio_2,
	Max32662_gpio_3,
	Max32662_gpio_4,
	Max32662_gpio_5,
	Max32662_gpio_6,
	Max32662_gpio_7,
	Max32662_gpio_8,
	Max32662_gpio_9,
	Max32662_gpio_10,
	Max32662_gpio_11,
	Max32662_gpio_12,
	Max32662_gpio_13,
	Max32662_gpio_14,
	Max32662_gpio_15,
	Max32662_gpio_16,
	Max32662_gpio_17,
	Max32662_gpio_18,
	Max32662_gpio_19,
	Max32662_gpio_20,
	Max32662_gpio_21,
	Max32662_gpio_pin_max,
} Max32662_gpio_pin;

typedef enum
{
	Max32662_gpio_hi_impedance,
	Max32662_gpio_pull_up,
	Max32662_gpio_pull_down
} Max32662_gpio_pullmode;


typedef enum
{
	Max32662_gpio_input,
	Max32662_gpio_output,
} Max32662_gpio_inout;

typedef enum
{
	Max32662_gpio_intr_level_low,
	Max32662_gpio_intr_level_high,
	Max32662_gpio_intr_edge_low,
	Max32662_gpio_intr_edge_falling,
	Max32662_gpio_intr_edge_rising,
	Max32662_gpio_intr_edge_both,
} Max32662_gpio_intr_mode;

typedef void (*Max32662_gpio_intr_callback)(Max32662_gpio_pin pin);



extern int max32662_gpio_altfunc(Max32662_gpio_pin pin, uint32_t alt, int transition);
extern int max32662_gpio_setup_pullmode(Max32662_gpio_pin pin, Max32662_gpio_pullmode pullmode);
extern int max32662_gpio_setup_inout(Max32662_gpio_pin pin, Max32662_gpio_inout inout);
extern int max32662_gpio_input(Max32662_gpio_pin pin, uint32_t *input);
extern int max32662_gpio_outout(Max32662_gpio_pin pin, uint32_t output);
extern int max32662_gpio_setup_interrupt(Max32662_gpio_pin pin, Max32662_gpio_intr_mode mode, Max32662_gpio_intr_callback cb);
extern int max32662_gpio_enable_interrupt(int enable);
#endif//_MAX32662_GPIO_H_
