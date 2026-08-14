/*
 * adc.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef ADC_H_
#define ADC_H_

#if 0
typedef struct {
	uint16_t len;
	float    *fbuf[4];
	uint16_t wptr;
} DriverAdcBuf;
#else
typedef struct {
	uint16_t len;
	uint16_t *buf[4];
	uint16_t wptr;
} DriverAdcBuf;
#endif
extern void driver_adc_init(uint16_t conversion_Hz, DriverAdcBuf *buf);

#endif
