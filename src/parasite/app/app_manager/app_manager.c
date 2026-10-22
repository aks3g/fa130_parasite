/*
 * sensor.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"
#include "string.h"
#include "target_syssvc.h"

#include "app/console.h"
#include "app/env.h"

#include "fs/fs.h"
#include "fs/io_scheduler.h"

#include "driver/motor_driver.h"
#include "driver/iam20680ht.h"
#include "app/sensor.h"
#include "app/app_manager.h"

void _default_app(void);
void _mapping_app(void);
void _learning_app(void);
void _race_app(void);

typedef struct
{
	App app;
	const char * name;
} AppItem;


static AppItem sAppList[] = 
{
	{_default_app,    "default"},
	{_mapping_app,    "mapping"},
	{_learning_app,   "learning"},
	{_race_app,       "race"},
	{NULL, NULL},
};

static App sSelected_app = _default_app;

int appManager_init(void)
{
	AppItem *itr = sAppList;
	const char *app_name = NULL;
	int ret = env_get_value("app", &app_name);
	if (ret != E_OK) {
		goto ENSURE;
	}

	while (itr->app != NULL) {
		if (0 == strcmp(itr->name, app_name)) {
			sSelected_app = itr->app;
			break;
		}
	}

ENSURE:
	console_printf("Selected : %s\n", itr->name);

	return E_OK;
}

App appManagerGetCurrentApp(void)
{
	return sSelected_app;
}

//-----------------------------------------------------------------------------
static uint8_t sFsBuf[3][256];

void _default_app(void)
{
	int ret = 0;
	int wptr = 0;
	int i = 0;
	SensorValue val;

	memset(sFsBuf, 0xFF, sizeof(sFsBuf));

	while (1) {
		(void)sensor_grab(&val);

		// 32 byte単位で書き込み
		memcpy(&(sFsBuf[i][wptr]), &val, sizeof(SensorValue));
		wptr += 32;
		if (wptr == SFLASH_PAGE_SIZE) {
			ret = io_scheduler_write_req(sFsBuf[i]);
			if (ret != E_OK) {
			}

			wptr = 0;
			i = 1-i;
		}
	}
}

void _mapping_app(void)
{
	SensorValue val;
	while (1) {
		(void)sensor_grab(&val);
	}
}

void _learning_app(void)
{
	SensorValue val;
	while (1) {
		(void)sensor_grab(&val);
	}
}

void _race_app(void)
{
	SensorValue val;
	while (1) {
		(void)sensor_grab(&val);
	}
}


