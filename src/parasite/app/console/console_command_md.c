/*
 * console_command_md.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"
#include "app/console.h"

#include "driver/motor_driver.h"

void consoleHelpMotor(void)
{
	console_printf("md <slottle>\n");
	console_printf("slottle: -100 ... 100\n");
}

void consoleFuncMotor(char **argv, int argc)
{
	if (argc != 2) {
		consoleHelpMotor();
		return;
	}

	int slottle = strtol(argv[1], NULL, 10);
	if (slottle > 100 || slottle < -100) {
		consoleHelpMotor();
		return;
	}

	driver_md_set_slottle(slottle);

	return;
}

