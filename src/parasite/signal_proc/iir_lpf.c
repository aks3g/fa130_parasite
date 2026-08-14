/*
 * iir_lpf.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#include <string.h>
#include <stdlib.h>

#include "signal_proc/iir_lpf.h"

static float biquadFilter_process(BiquadFilter *f, float x)
{
	float y;

	y = (f->b0 * x)
		+ (f->b1 * f->x1)
		+ (f->b2 * f->x2)
		- (f->a1 * f->y1)
		- (f->a2 * f->y2);

	f->x2 = f->x1;
	f->x1 = x;
	f->y2 = f->y1;
	f->y1 = y;

    return y;
}

float iir4thOrderFilter_Process(Iir4thOrderFilter *f, float x)
{
	float y1;
	float y2;

	y1 = biquadFilter_process(&f->stage[0], x);
	y2 = biquadFilter_process(&f->stage[1], y1);

	return y2;
}

void biquadFilter_init(BiquadFilter *f, float b0, float b1, float b2, float a1, float a2)
{
	f->b0 = b0;
	f->b1 = b1;
	f->b2 = b2;
	f->a1 = a1;
	f->a2 = a2;

	f->x1 = 0.0f;
	f->x2 = 0.0f;
	f->y1 = 0.0f;
	f->y2 = 0.0f;
}

void biquadFilter_reset(BiquadFilter *f)
{
	f->x1 = 0.0f;
	f->x2 = 0.0f;
	f->y1 = 0.0f;
	f->y2 = 0.0f;
}

