/*
 * motor_driver.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_

extern int driver_md_set_gain(float kp, float ki, float kd);
extern int driver_md_set_rps(float rps);
extern int driver_md_set_slottle(int slottle);
extern int driver_md_init(void);
extern int driver_md_start_pulse(void);
extern int16_t driver_md_get_rpm(void);
extern float driver_md_get_rps(void);
extern float driver_md_get_delta_sec(void);
extern uint32_t driver_md_get_tick(void);

#endif
