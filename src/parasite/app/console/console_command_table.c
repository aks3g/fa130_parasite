/*
 * console_command_table.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#define TOPPERS_MACRO_ONLY

#include <kernel.h>
#include "kernel_cfg.h"

#include <stdint.h>
#include <stddef.h>

#include "app/console_command.h"

ConsoleCmdItem consoleCmdSet[] =
{
	{
		.func = consoleFuncCapture,
		.help = consoleHelpCapture,
		.name = "capture",
	},
	{
		.func = consoleFuncSignalProc,
		.help = consoleHelpSignalProc,
		.name = "sigproc",
	},
	{
		.func = consoleFuncMotor,
		.help = consoleHelpMotor,
		.name = "md",
	},
	{
		.func = consoleFuncPid,
		.help = consoleHelpPid,
		.name = "pid"
	},
	{
		.func = consoleFuncFs,
		.help = consoleHelpFs,
		.name = "fs"
	},
	{
		.func = consoleFuncEnv,
		.help = consoleHelpEnv,
		.name = "env"
	},
	{
		.func = consoleFuncSaveEnv,
		.help = NULL,
		.name = "save"
	},
	{
		.func = consoleFuncEcho,
		.help = NULL,
		.name = "echo"
	},
	{
		.func = consoleFuncVersion,
		.help = NULL,
		.name = "version"
	},
	{
		.func = consoleFuncHelp,
		.help = consoleHelpHelp,
		.name = "help"
	},
	{
		.func = NULL,
		.help = NULL,
		.name = NULL
	}
};


