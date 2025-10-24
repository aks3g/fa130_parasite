/*
 * max32662_timer.h
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */ 
#ifndef _MAX32662_TIMER_H_
#define _MAX32662_TIMER_H_

typedef union
{
	uint32_t dword;
	struct {
		uint32_t irq_a     : 1;
		uint32_t rsvd1_7   : 7;
		uint32_t wrdone_a  : 1;
		uint32_t wr_dis_a  : 1;
		uint32_t rsvd10_15 : 6;
		uint32_t irq_b     : 1;
		uint32_t rsvd17_23 : 7;
		uint32_t wrdone_b  : 1;
		uint32_t wr_dis_b  : 1;
		uint32_t rsvd26_31 : 6;
	} bf;
} max32662_timer_tmr_intfl;


typedef struct
{
	uint32_t tmr_cnt;
	uint32_t tmr_cmp;
	uint32_t tmr_pwm;
	max32662_timer_tmr_intfl tmr_intfl;

	union
	{
		uint32_t dword;
		struct {
			uint32_t mode_a    : 4;
			uint32_t clkdiv_a  : 4;
			uint32_t pol_a     : 1;
			uint32_t pwmsync_a : 1;
			uint32_t nolhpol_a : 1;
			uint32_t nollpol_a : 1;
			uint32_t pwmckbd_a : 1;
			uint32_t rst_a     : 1;
			uint32_t clken_a   : 1;
			uint32_t en_a      : 1;
			uint32_t mode_b    : 4;
			uint32_t clkdiv_b  : 4;
			uint32_t rsvd24_28 : 5;
			uint32_t rst_b     : 1;
			uint32_t clken_b   : 1;
			uint32_t en_b      : 1;
		} bf;
	}  tmr_ctrl0;

	union
	{
		uint32_t dword;
		struct {
			uint32_t lo_a : 8;
			uint32_t hi_a : 8;
			uint32_t lo_b : 8;
			uint32_t hi_b : 8;
		} bf;
	}  tmr_nolcmp;

	union
	{
		uint32_t dword;
		struct {
			uint32_t clksel_a       : 2;
			uint32_t clken_a        : 1;
			uint32_t clkrdy_a       : 1;
			uint32_t event_sel_a    : 3;
			uint32_t negtrig_a      : 1;
			uint32_t ie_a           : 1;
			uint32_t capevent_sel_a : 2;
			uint32_t sw_capevent_a  : 1;
			uint32_t we_a           : 1;
			uint32_t outen_a        : 1;
			uint32_t outben_a       : 1;
			uint32_t rsvd15         : 1;
			uint32_t clksel_b       : 2;
			uint32_t clken_b        : 1;
			uint32_t clkrdy_b       : 1;
			uint32_t event_sel_b    : 3;
			uint32_t negtrig_b      : 1;
			uint32_t ie_b           : 1;
			uint32_t capevent_sel_b : 2;
			uint32_t sw_capevent_b  : 1;
			uint32_t we_b           : 1;
			uint32_t rsvd29_30      : 2;
			uint32_t cascade        : 1;
		} bf;
	} tmr_ctrl1;

	union
	{
		uint32_t dword;
		struct {
			uint32_t a         : 1;
			uint32_t rsvd1_15  : 15;
			uint32_t b         : 1;
			uint32_t rsvd17_31 : 15;
		}bf;
	} tmr_wkfl;
} max32662_tmr;


typedef enum
{
	max32662_tmr_ctrl0_clkdiv_1 = 0,
	max32662_tmr_ctrl0_clkdiv_2,
	max32662_tmr_ctrl0_clkdiv_4,
	max32662_tmr_ctrl0_clkdiv_8,
	max32662_tmr_ctrl0_clkdiv_16,
	max32662_tmr_ctrl0_clkdiv_32,
	max32662_tmr_ctrl0_clkdiv_64,
	max32662_tmr_ctrl0_clkdiv_128,
	max32662_tmr_ctrl0_clkdiv_256,
	max32662_tmr_ctrl0_clkdiv_512,
	max32662_tmr_ctrl0_clkdiv_1024,
	max32662_tmr_ctrl0_clkdiv_2048,
	max32662_tmr_ctrl0_clkdiv_4096,
	max32662_tmr_ctrl0_clkdiv_rsvd13,
	max32662_tmr_ctrl0_clkdiv_rsvd14,
	max32662_tmr_ctrl0_clkdiv_rsvd15,
} max32662_tmr_ctrl0_clkdiv;

typedef enum
{
	max32662_tmr_ctrl0_mode_one_shot = 0,
	max32662_tmr_ctrl0_mode_continuous,
	max32662_tmr_ctrl0_mode_counter,
	max32662_tmr_ctrl0_mode_pwm,
	max32662_tmr_ctrl0_mode_capture,
	max32662_tmr_ctrl0_mode_compare,
	max32662_tmr_ctrl0_mode_gated,
	max32662_tmr_ctrl0_mode_capture_compare,
	max32662_tmr_ctrl0_mode_dual_edge_capture,
	max32662_tmr_ctrl0_mode_rsvd9,
	max32662_tmr_ctrl0_mode_rsvd10,
	max32662_tmr_ctrl0_mode_rsvd11,
	max32662_tmr_ctrl0_mode_internally_gated,
	max32662_tmr_ctrl0_mode_rsvd13,
	max32662_tmr_ctrl0_mode_rsvd14,
	max32662_tmr_ctrl0_mode_rsvd15,
} max32662_tmr_ctrl0_mode;

typedef enum
{
	max32662_tmr_ctrl1_clksel_pclk = 0,
	max32662_tmr_ctrl1_clksel_hf_ext_clk,
	max32662_tmr_ctrl1_clksel_ibro,
	max32662_tmr_ctrl1_clksel_erfo,
} max32662_tmr_ctrl1_clksel;


typedef enum
{
	max32662_timer_0 = 0,
	max32662_timer_1,
	max32662_timer_2,
	max32662_timer_max
} max32662_timer_id;


#define MAX32662_TIMER0		((volatile max32662_tmr *)0x40010000)
#define MAX32662_TIMER1		((volatile max32662_tmr *)0x40011000)
#define MAX32662_TIMER2		((volatile max32662_tmr *)0x40012000)

typedef void (*max32662_timer_callback)(int timer_id);

extern int max32662_timer_initialize(max32662_timer_id id, uint32_t peripheral_clk_Hz, uint32_t interval_us, max32662_timer_callback cb);
extern int max32662_timer_enable_interrupt(max32662_timer_id id, int enable);

extern int max32662_timer_initialize_as_pwm(max32662_timer_id id, uint32_t peripheral_clk_Hz, uint32_t pwm_freq_Hz);
extern int max32662_timer_pwm_set_duty(max32662_timer_id id, uint8_t duty);

#endif//_MAX32662_TIMER_H_
