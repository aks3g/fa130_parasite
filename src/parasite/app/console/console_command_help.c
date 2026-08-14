/*
 * console_command_version.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"
#include "app/console.h"

#include <string.h>

#include "app/console_command.h"
#include "console_command_table.h"

void consoleFuncHelp(char **argv, size_t argc)
{
	ConsoleCmdItem *p = consoleCmdSet;

	if (argc == 1) {
		console_printf("List of commands:\n");
		while (p->name != NULL) {
			console_printf("%s\n", p->name);
			p++;
		}
	}
	else {
		char *cmd = argv[1];
		while (p->name != NULL) {
			if (0 == strcmp(cmd, p->name)) {
				if (p->help != NULL) p->help();
				return;
			}
			p++;
		}

		console_printf("%s not found\n", cmd);
	}

	return;
}

void consoleHelpHelp(void)
{
	console_printf("Print help message\n");
}
