/*
 * console.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <kernel.h>

extern void console_init(void);
extern void console_puts(char *str);
extern int console_printf(const char *str, ...);
extern void console_task(intptr_t exinf);


#endif