/*
 * down_sample.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef _DOWN_SAMPLE_H_
#define _DOWN_SAMPLE_H_

extern uint32_t signalProc_down_sampling(uint16_t *input, uint16_t *output, uint32_t input_cnt, uint32_t step);
extern uint32_t signalProc_down_sampling_f(float *input, float *output, uint32_t input_count, uint32_t step);

#endif
