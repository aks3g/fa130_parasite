/*
 * timer.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef TIMER_H_
#define TIMER_H_

#define DRIVER_TIMER_TICK_TO_SEC(tick)			 ((float)((tick * 32.0f) / 50000000.0f))

extern int driver_timer_init(void);
extern uint32_t driver_timer_gettick_us(void);
extern uint32_t driver_timer_gettick(void);

#endif
