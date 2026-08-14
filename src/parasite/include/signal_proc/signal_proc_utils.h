/*
 * signal_proc_utils.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef _SIGNAL_PROC_UTILS_H_
#define _SIGNAL_PROC_UTILS_H_

extern void signalProc_dump(uint16_t *buf, size_t count);
extern void signalProc_dump_f(float *buf, size_t count);

extern void signalProc_getWorkBuf(float **buf, size_t *count);

#endif
