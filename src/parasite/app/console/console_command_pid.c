/*
 * console_command_md.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"
#include "app/console.h"

#include "driver/motor_driver.h"

void consoleHelpPid(void)
{
	console_printf("pid <velocity km/h>\n");
}

void consoleFuncPid(char **argv, int argc)
{
	if (argc != 2) {
		consoleHelpMotor();
		return;
	}

	uint32_t velocity_kmph = strtol(argv[1], NULL, 10);
	float rps = (float)velocity_kmph * 1000000.0f / (3600.0f * 26.0f * 3.1415f);

	console_printf("target rps = %f\n", rps);
	driver_md_set_slottle(50);

	driver_md_set_gain(0.4f, 1.0f, 0.0f);
	driver_md_set_rps(rps);

	for (uint32_t i=0 ; i<100 ; ++i) {
		dly_tsk(10);
	}


	return;
}

