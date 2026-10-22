/*
 * console_command_sensor.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"
#include "app/console.h"

#include <string.h>
#include <stdlib.h>

#include "iam20680ht.h"

void consoleHelpSensor(void)
{
	console_printf("sensor <sub command>\n");

}

void consoleFuncSensor(char **argv, int argc)
{
	Iam20680ht_data dat;
	iam20680ht_grab_oneshot(&dat);

	console_printf("%d %d %d %d %d %d %d\n", dat.bf.accel[0], dat.bf.accel[1], dat.bf.accel[2], dat.bf.temp, dat.bf.gyro[0], dat.bf.gyro[1], dat.bf.gyro[2]);
	console_printf("%04x %04x %04x %04x %04x %04x %04x\n", dat.bf.accel[0], dat.bf.accel[1], dat.bf.accel[2], dat.bf.temp, dat.bf.gyro[0], dat.bf.gyro[1], dat.bf.gyro[2]);

	return;
}

