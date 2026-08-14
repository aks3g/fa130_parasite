/*
 * console_command_version.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "kernel_cfg.h"
#include "app/console.h"

#define MAJOR	0
#define MINOR	1
#define REV		2
#define HASH	0xdeadbeef



void consoleFuncVersion(char **argv, int argc)
{
	console_printf("Parasite AI mini4wd. %d.%d.%d %08x %s %s\n", MAJOR, MINOR, REV, HASH, __DATE__, __TIME__);
}
