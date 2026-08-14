/*
 * iir_lpf.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef IIR_LPF_H_
#define IIR_LPF_H_


typedef struct {
	float b0;
	float b1;
	float b2;
	float a1;
	float a2;
	float x1;
	float x2;
	float y1;
	float y2;
} BiquadFilter;

typedef struct {
	BiquadFilter stage[2];
} Iir4thOrderFilter;


extern float iir4thOrderFilter_Process(Iir4thOrderFilter *f, float x);
extern void biquadFilter_init(BiquadFilter *f, float b0, float b1, float b2, float a1, float a2);
extern void biquadFilter_reset(BiquadFilter *f);

#endif
