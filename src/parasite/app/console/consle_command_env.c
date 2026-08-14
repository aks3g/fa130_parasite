/*
 * console_command_md.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"
#include "app/console.h"

#include <string.h>
#include <stdlib.h>

#include "fs/fs.h"
#include "app/env.h"

void consoleHelpEnv(void)
{
	console_printf("env <sub command>\n");
	console_printf(" - env <key> <value>\n");
	console_printf(" - env <key>\n");
}

void consoleFuncEnv(char **argv, int argc)
{
	if (argc == 1) {
		env_dump_hex();
	}
	else if (argc == 2) {
		const char *value = NULL;
		int ret = env_get_value(argv[1], &value);
		if (ret != E_OK) {
			console_printf("Env %s is not found. %08x\n", argv[1], ret);
			return;
		}

		console_printf("%s = %s\n", argv[1], value);
	}
	else if (argc == 3) {
		int ret = env_set_value(argv[1], argv[2]);
		if (ret != E_OK) {
			console_printf("Failed to set/update env variable %s=%s. %08x\n", argv[1], argv[2], ret);
			return;
		}

	}
	else {
		consoleHelpEnv();
	}


	return;
}

void consoleFuncSaveEnv(char **argv, int argc)
{
	env_save();
	return;
}

