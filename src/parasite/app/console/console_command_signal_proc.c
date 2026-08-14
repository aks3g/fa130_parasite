/*
 * console_command_version.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#include <string.h>
#include <stdlib.h>

#include <kernel.h>
#include "kernel_cfg.h"
#include "app/console.h"

#include "max32662_gpio.h"


#include "driver/timer.h"
#include "driver/motor_driver.h"
#include "signal_proc/iir_lpf.h"
#include "signal_proc/fft.h"
#include "signal_proc/down_sample.h"
#include "signal_proc/signal_proc_utils.h"

void consoleHelpSignalProc(void)
{
	console_printf("signal proc\n");
	console_printf("  sigproc average\n");
	console_printf("  sigproc resampling\n");
	console_printf("  sigproc iir_lpf\n");
	console_printf("  sigproc fft\n");
}

static Iir4thOrderFilter filter;

static fft_context fftCtx = {
	.count   = 0,
	.input   = NULL, 
	.fft_out = NULL, 
	.mag     = NULL,
};

static float output_f[FFT_SIZE];
static float mag_f   [FFT_SIZE];

#define _FFT_DEBUG_

void consoleFuncSignalProc(char **argv, int argc)
{
	if (argc == 1) {
		consoleHelpSignalProc();
	}
	else if (strcmp(argv[1], "run") == 0) {

		for (uint8_t duty = 50 ; duty <= 100 ; duty += 10) {
			driver_md_set_slottle(duty);
			for (uint32_t i=0 ; i<200 ; ++i) {
				float interval = driver_md_get_delta_sec();
				float velocity_kmph = (1.0f/interval) * (26.0f*3.1415f/1000000.0f) * 3600;
				console_printf("%d %f\n", duty, velocity_kmph);
				dly_tsk(10);
			}
		}

		driver_md_set_slottle(0);
	}
	else if(strcmp(argv[1], "time") == 0) {
		uint32_t cur = 0;
		ER err = get_tim(&cur);

		console_printf("%d %d\n", err, cur);
	}
	else {
		consoleHelpSignalProc();
	}

	return;
}


