/*
 * down_sample.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#include <stdint.h>
#include <stddef.h>

uint32_t signalProc_down_sampling(uint16_t *input, uint16_t *output, uint32_t input_count, uint32_t step)
{
	uint32_t idx = 0;
	for (uint32_t i=0 ; i<input_count ; i+=step) {
		output[idx++] = input[i];
	}

	return idx;
}

uint32_t signalProc_down_sampling_f(float *input, float *output, uint32_t input_count, uint32_t step)
{
	uint32_t idx = 0;
	for (uint32_t i=0 ; i<input_count ; i+=step) {
		output[idx++] = input[i];
	}

	return idx;
}
