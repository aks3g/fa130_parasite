/*
 * sensor.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"
#include "string.h"
#include "target_syssvc.h"

#include "driver/motor_driver.h"
#include "driver/iam20680ht.h"
#include "app/sensor.h"

#define SENSOR__EVT_GRAB			(1 << 0)

static uint16_t _sensor_data_index=0;
static Iam20680ht_data _sensor_data;

static void _sensor_imu_grab(Iam20680ht_data *data)
{
	memcpy(&_sensor_data, data, sizeof(Iam20680ht_data));
	iset_flg(SENSOR_FLG, SENSOR__EVT_GRAB);
	_sensor_data_index++;
}

int sensor_probe(void)
{
	int ret = iam20680ht_probe(_sensor_imu_grab);
	_sensor_data_index = 0;

	return ret;
}

int sensor_flush(void)
{
	return clr_flg(SENSOR_FLG, SENSOR__EVT_GRAB);
}

int sensor_grab(SensorValue *val)
{
	FLGPTN flg = 0;
	int ret = twai_flg(SENSOR_FLG, SENSOR__EVT_GRAB, TWF_ORW, &flg, 100);
	if (ret == E_OK && (flg & SENSOR__EVT_GRAB)) {
		val->idx = _sensor_data_index;
		memcpy(val->acc, _sensor_data.bf.accel, sizeof(int16_t)*3); 
		memcpy(val->ang, _sensor_data.bf.gyro,  sizeof(int16_t)*3); 
		val->rpm = driver_md_get_rpm();
		val->batt_v = 0;
		val->batt_i = 0;
	}
	else {
		memset (val, 0xff, sizeof(SensorValue));
	}

	clr_flg(SENSOR_FLG, SENSOR__EVT_GRAB);

	return ret;
}

