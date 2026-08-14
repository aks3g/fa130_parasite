/*
 * ad_collector.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#ifndef AD_COLLECTOR_H_
#define AD_COLLECTOR_H_

#define ADC_BUF_LEN		(4096*2)

extern void analog_collector_init(void);
#if 0
extern int analog_collector_get(uint32_t ch, float *buf);
#else
extern int analog_collector_get(uint32_t ch, uint16_t *buf);
#endif

#endif
