/*
 * console_command_echo.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#include <kernel.h>

#include "kernel_cfg.h"
#include "app/console.h"

#define MAJOR	0
#define MINOR	1
#define REV		2
#define HASH	0xdeadbeef



void consoleFuncEcho(char **argv, int argc)
{
	for (int i=0 ; i<argc ; ++i) {
		console_printf("%s ", argv[i]);
	}
}
