/*
 * sensor.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef _SENSOR_H_
#define _SENSOR_H_


#include "driver/iam20680ht.h"

// 20bytes
#pragma pack(1)
typedef struct
{
	uint16_t idx;
	int16_t acc[3];
	int16_t ang[3];
	int16_t rpm ;
	int16_t batt_v;
	int16_t batt_i;
} SensorValue;
#pragma pack()

#define SENSOR_ACCELER_TO_mG(a)				(SENSOR_ACCELER_COEFF_mG  * (a))
#define SENSOR_ANGULAR_TO_RAD(a)			(SENSOR_ANGULAR_COEFF_RAD * (a))
#define SENSOR_ANGULAR_TO_DEGREE(a)			(SENSOR_ANGULAR_COEFF_DEG * (a))

extern int sensor_probe(void);
extern int sensor_grab(SensorValue *val);

#endif/*_SENSOR_H_*/
