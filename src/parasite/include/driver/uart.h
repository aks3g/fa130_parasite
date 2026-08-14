/*
 * uart.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#ifndef _UART_H_
#define _UART_H_

#define UART_FLG_RX					(0x00000001)

extern int driver_uart_init(int baudrate);
extern int driver_uart_putc(char c);
extern int driver_uart_puts(char *str);
extern int driver_uart_getc(char *c);
extern int driver_uart_wait_rx(void);

#endif