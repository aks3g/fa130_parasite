/*
 * ad_collector.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#ifndef AD_COLLECTOR_H_
#define AD_COLLECTOR_H_

#define ADC_IDX_BMON			(3)
#define ADC_IDX_MM				(2)
#define ADC_IDX_MP				(1)
#define ADC_IDX_IMON			(0)

extern void analog_collector_init(void);
extern int analog_collector_get(uint32_t ch, uint16_t *buf);

#endif
