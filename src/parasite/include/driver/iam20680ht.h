/*
 * iam20680ht.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */ 
#include <stdint.h>

#ifndef IAM20680HT_H_
#define IAM20680HT_H_

#pragma pack(1)
typedef union {
	uint16_t arr[7];
	struct {
		int16_t accel[3];
		int16_t temp;
		int16_t gyro[3];
	}bf;
} Iam20680ht_data;
#pragma pack()


typedef void (*Iam20680ht_grab_cb)(Iam20680ht_data *data);

extern int iam20680ht_probe(Iam20680ht_grab_cb cb);
extern int iam20680ht_grab_oneshot(Iam20680ht_data *rxbuf);
extern int iam20680ht_on_int(void);

#endif/*IAM20680HT_H_*/
