/*
 * console_command_version.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"

#include "driver/adc.h"
#include "app/console.h"
#include "app/ad_collector.h"

#include "signal_proc/signal_proc_utils.h"

#include <stdlib.h>

void consoleHelpCapture(void)
{
	console_puts("capture <ch>");

	return;
}


void consoleFuncCapture(char **argv, int argc)
{
	if (argc != 2) {
		consoleHelpCapture();
		return;
	}

	uint16_t *tmp_buf;
	size_t count;
	signalProc_getWorkBuf(&tmp_buf, &count);

	int ch = strtol(argv[1], NULL, 10);

	analog_collector_get(0, tmp_buf);

	for (size_t i=0 ; i<count ; ++i) {
		console_printf("%u\n", tmp_buf[i]);
//		console_printf("%f\n", tmp_buf[i]);
	}

	return;
}


