/*
 * console_command.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */ 
#include <kernel.h>
#include "kernel_cfg.h"

#include "app/console.h"

#include "app/console_command.h"
#include "console_command_table.h"

#include <string.h>

static char * argv[10];
void consoleCmdExec(char *line)
{
	// Parse line
	int argc = 0;
	char *cmd = line;

	memset(argv, 0, sizeof(argv));

	argv[argc++] = line;

	while (*line != '\0') {
		if (*line == ' ') {
			*line = '\0';
			line++;
			if(*line != '\0') argv[argc++] = line;
		}
		else {
			line++;
		}
	}

	// Search and exec command
	for (ConsoleCmdItem *pCmd = consoleCmdSet ; pCmd->func != NULL ; pCmd++) {
		if (0 == strcmp(cmd, pCmd->name)) {
			pCmd->func(argv, argc);

			return;
		}
	}

	// Reach here if command not found.
	console_printf("Command %s is not found\n", cmd);

	return;
}

