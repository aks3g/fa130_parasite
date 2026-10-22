/*
 * motor_driver.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#include <kernel.h>
#include "kernel_cfg.h"

#include <stdlib.h>
#include <string.h>

#include "max32662_gpio.h"
#include "max32662_timer.h"
#include "max32662_adc.h"

#include "driver/timer.h"
#include "driver/gpio.h"
#include "driver/motor_driver.h"

#define PARASITE_MD_PWM_CH1			max32662_timer_2
#define PARASITE_MD_PWM_CH2			max32662_timer_1

typedef struct
{
	float Kp;
	float Ki;
	float Kd;

	float target;
	float prev_error;
	float duty;

	uint32_t enabled;
} MdParam;

#define MEDIAN_SIZE			4
#define MEDIAN_SIZE_MASK	3
#define MEDIAN_MID_POS		2
typedef struct 
{
	uint32_t wptr;
	uint32_t mask;
	uint32_t arr[MEDIAN_SIZE];
	uint32_t tmp[MEDIAN_SIZE];
} DeltaBuf;

static DeltaBuf delta_buf = {0, MEDIAN_SIZE_MASK, {0}};
static int compare_uint32(const void *a, const void *b)
{
    uint32_t aa = *(const uint32_t *)a;
    uint32_t bb = *(const uint32_t *)b;

	return (aa > bb) - (aa < bb);
}


static MdParam _mdParam;
static int _slottle = 0;

static uint32_t delta = 1;
static uint32_t prv = 0;
static void _tachometer_cb(Max32662_gpio_pin pin)
{
	uint32_t cur = driver_timer_gettick();

	delta_buf.arr[delta_buf.wptr] = cur - prv;
	delta_buf.wptr = (delta_buf.wptr + 1) & delta_buf.mask;

	memcpy(delta_buf.tmp, delta_buf.arr, sizeof(delta_buf.tmp));
	qsort(delta_buf.tmp, MEDIAN_SIZE, sizeof(uint32_t), compare_uint32);
	delta = (delta_buf.tmp[MEDIAN_MID_POS]);


	if (_mdParam.enabled == 0 || delta == 0) {
	}
	else {
		float error         = _mdParam.target - driver_md_get_rps();
		float dt            = driver_md_get_delta_sec();

		float delta_p = _mdParam.Kp *        (error - _mdParam.prev_error);
		float delta_i = _mdParam.Ki * 0.5f * (error + _mdParam.prev_error) * dt;

		_mdParam.duty = _mdParam.duty + delta_p + delta_i;

//		console_printf("%f %f\n", _mdParam.duty, delta_p);

		     if (_mdParam.duty >  100) _mdParam.duty =  100;
		else if (_mdParam.duty < -100) _mdParam.duty = -100;

		driver_md_set_slottle((int)_mdParam.duty);

		_mdParam.prev_error = error;
	}

	prv = cur;

	return;
}

uint32_t driver_md_get_tick(void)
{
	return prv;
}

int16_t driver_md_get_rpm(void)
{
	return (int16_t)(60.0f * 1.0f / DRIVER_TIMER_TICK_TO_SEC(delta));
}


float driver_md_get_rps(void)
{
	return 1.0f / DRIVER_TIMER_TICK_TO_SEC(delta);
}

float driver_md_get_delta_sec(void)
{
	return DRIVER_TIMER_TICK_TO_SEC(delta);
}


int driver_md_set_gain(float kp, float ki, float kd)
{
	_mdParam.enabled = 1;

	_mdParam.Kp = kp;
	_mdParam.Ki = ki;
	_mdParam.Kd = kd;

	_mdParam.target = 0.0f;

	return 0;
}

int driver_md_set_rps(float rps)
{
	_mdParam.target     = rps;
	_mdParam.prev_error = 0.0f;
	_mdParam.duty       = _slottle;

	return 0;
}


int driver_md_set_slottle(int slottle)
{
	if (-100 > slottle || slottle > 100) {
		return -1;
	}

	//J 同じDutyであればこれ以上のUpdateはしない
	if (_slottle == slottle) return 0;

	if (slottle == 0) {
		// set dir
		if (!(_slottle == 0)) {
			max32662_gpio_outout(PARASITE_PIN_MD_CTRL1, 0);
			max32662_gpio_outout(PARASITE_PIN_MD_CTRL2, 0);

			max32662_gpio_altfunc(PARASITE_PIN_MD_PWM1, 0, 0);
			max32662_gpio_outout (PARASITE_PIN_MD_PWM1, 0);

			max32662_gpio_altfunc(PARASITE_PIN_MD_PWM2, 0, 0);
			max32662_gpio_outout (PARASITE_PIN_MD_PWM2, 0);
		}
	}
	else if (slottle > 0) {
		// set dir
		if (!(_slottle > 0)) {
			max32662_gpio_outout(PARASITE_PIN_MD_CTRL1, 1);
			max32662_gpio_outout(PARASITE_PIN_MD_CTRL2, 0);

			max32662_gpio_altfunc(PARASITE_PIN_MD_PWM2, 0, 0);
			max32662_gpio_outout (PARASITE_PIN_MD_PWM2, 0);

			max32662_gpio_altfunc(PARASITE_PIN_MD_PWM1,  3, 1);
			max32662_gpio_altfunc(PARASITE_PIN_MD_PWM1,  3, 0);
		}

		max32662_timer_pwm_set_duty(PARASITE_MD_PWM_CH1, slottle);
	} 
	else {//if(slottle < 0)
		// set dir
		if (!(_slottle < 0)) {
			max32662_gpio_outout(PARASITE_PIN_MD_CTRL1, 0);
			max32662_gpio_outout(PARASITE_PIN_MD_CTRL2, 1);

			max32662_gpio_altfunc(PARASITE_PIN_MD_PWM1, 0, 0);
			max32662_gpio_outout (PARASITE_PIN_MD_PWM1, 0);

			max32662_gpio_altfunc(PARASITE_PIN_MD_PWM2,  3, 1);
			max32662_gpio_altfunc(PARASITE_PIN_MD_PWM2,  3, 0);
		}

		max32662_timer_pwm_set_duty(PARASITE_MD_PWM_CH2, -slottle);
	}

	_slottle = slottle;

	return 0;
}

int driver_md_init(void)
{
	// Setup PWM
	max32662_timer_initialize_as_pwm(PARASITE_MD_PWM_CH1, 50000000, 800, NULL);
	max32662_timer_initialize_as_pwm(PARASITE_MD_PWM_CH2, 50000000, 800, NULL);

	max32662_timer_pwm_set_duty(PARASITE_MD_PWM_CH1, 0);
	max32662_timer_pwm_set_duty(PARASITE_MD_PWM_CH2, 0);

	driver_md_set_slottle(0);

	// Setup Tachometer
	max32662_gpio_setup_interrupt(PARASITE_PIN_SENS_INT, Max32662_gpio_intr_edge_falling, _tachometer_cb);

	return 0;
}
