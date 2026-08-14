/*
 * fft.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef FFT_H_
#define FFT_H_

#include <stdint.h>

#define FFT_SIZE			(256)
#define FFT_BINS			(FFT_SIZE / 2)

typedef struct 
{
	size_t count;
	float *input;
	float *fft_out;
	float *mag;
} fft_context;


extern void    fft_init(void);
extern void    fft_execute(fft_context *ctx);
extern void    fft_apply_hann_window(fft_context *ctx, size_t size);
extern int32_t fft_find_peak_bin(const fft_context *ctx, uint32_t bin_start, uint32_t bin_end);
extern float   fft_bin_to_freq(uint32_t bin, float fs);

#endif
