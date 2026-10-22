/*
 * i2c.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#ifndef I2C_H_
#define I2C_H_

#include "max32662_i2c.h"

#define DRIVER_I2C_ERROR_NAK	(MAX32662_I2C_ERROR_NAK)

typedef void (*driver_i2c_transfer_done)(int);

extern int driver_i2c_init(void);
extern int driver_i2c_transfer_blocking(uint8_t addr, uint8_t *txbuf, size_t txlen, uint8_t *rxbuf, size_t rxlen);
extern int driver_i2c_transfer(uint8_t addr, uint8_t *txbuf, size_t txlen, uint8_t *rxbuf, size_t rxlen, driver_i2c_transfer_done cb);

#endif/*I2C_H_*/