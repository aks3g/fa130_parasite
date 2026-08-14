/*
 * fft.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#include "arm_math.h"

#include "signal_proc/fft.h"

static arm_rfft_fast_instance_f32 _fft_instance;

void fft_init(void)
{
	(void)arm_rfft_fast_init_f32(&_fft_instance, FFT_SIZE);
}

void fft_execute(fft_context *ctx)
{
	uint32_t i;
	float real_part;
	float imag_part;

	if (ctx == 0) {
		return;
	}

	/*
	 * Real FFT
	 * input   : proc->input[FFT_SIZE]
	 * output  : proc->fft_out[FFT_SIZE]
	 */
	arm_rfft_fast_f32(&_fft_instance, ctx->input, ctx->fft_out, 0U);

	/*
	 * arm_rfft_fast_f32 output format:
	 * fft_out[0] = DC
	 * fft_out[1] = Nyquist
	 * fft_out[2*k]   = Re[k]
	 * fft_out[2*k+1] = Im[k]
	 *
	 * Here, mag[0] = |DC|
	 * Then bins 1 .. FFT_SIZE/2-1 are calculated normally.
	 */
	ctx->mag[0] = fabsf(ctx->fft_out[0]) / (float)FFT_SIZE;

	for (i = 1U; i < FFT_BINS; i++) {
		real_part = ctx->fft_out[2U * i];
		imag_part = ctx->fft_out[2U * i + 1U];
		ctx->mag[i] = sqrtf((real_part * real_part) + (imag_part * imag_part)) / (float)FFT_SIZE;
	}

	return;
}

void fft_apply_hann_window(fft_context *ctx, size_t size)
{
	uint32_t i;
	float w;

	for (i=0 ; i<size; i++) {
		w = 0.5f - 0.5f * arm_cos_f32((2.0f * PI * (float)i) / (float)(size - 1U));
		ctx->input[i] *= w;
	}

	return;
}

int32_t fft_find_peak_bin(const fft_context *ctx, uint32_t bin_start, uint32_t bin_end)
{
	uint32_t i;
	uint32_t peak_bin;
	float peak_val;

	if (bin_end <= bin_start) {
		return -1;
	}

	peak_bin = bin_start;
	peak_val = ctx->mag[bin_start];

	for (i = bin_start + 1U; i <= bin_end; i++) {
		if (ctx->mag[i] > peak_val) {
			peak_val = ctx->mag[i];
			peak_bin = i;
		}
	}

	return (int32_t)peak_bin;
}

float fft_bin_to_freq(uint32_t bin, float fs)
{
	return ((float)bin * fs) / (float)FFT_SIZE;
}

