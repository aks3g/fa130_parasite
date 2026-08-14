/*
 * console.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#include <kernel.h>
#include "kernel_cfg.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "parasite.h"

#include "uart.h"
#include "gpio.h"

#include "app/console_command.h"

#define CONSOLE_CMD_SIZE		(32)

typedef struct{
	char   buf[CONSOLE_CMD_SIZE];
	size_t len;
} ConsoleCmd;

static ConsoleCmd sConsoleCmd;




void console_init(void)
{
	driver_uart_init(115200);

	return;
}

void console_puts(char *str)
{
	wai_sem(CONSOLE_SEM);

	driver_uart_puts(str);

	sig_sem(CONSOLE_SEM);

}

static char _print_buf[128];
int console_printf(const char *str, ...)
{
	wai_sem(CONSOLE_SEM);

	int len = 0;
    va_list ap;

    va_start( ap, str );
    len = vsnprintf(_print_buf, sizeof(_print_buf), str, ap );
    va_end( ap );

	driver_uart_puts(_print_buf);

	sig_sem(CONSOLE_SEM);

	return len;
}


static void _push_console_in(char c)
{
	if (c == '\n') {
		// Echo Back
		driver_uart_putc(c);

		sConsoleCmd.buf[sConsoleCmd.len] = '\0';
		if (strlen(sConsoleCmd.buf) != 0) consoleCmdExec(sConsoleCmd.buf);

		memset(sConsoleCmd.buf, 0, sizeof(sConsoleCmd.buf));
		sConsoleCmd.len = 0;
	}
	else if (c == '\b'){
		if (sConsoleCmd.len > 0) {
			driver_uart_putc('\b');
			driver_uart_putc(' ');
			driver_uart_putc('\b');
			sConsoleCmd.buf[sConsoleCmd.len--] = '\0';
		}
	}
	else {
		driver_uart_putc(c);
		if (sConsoleCmd.len < (CONSOLE_CMD_SIZE-1)) {
			sConsoleCmd.buf[sConsoleCmd.len++] = c;
		}
	}

	return;
}

void console_task(intptr_t exinf)
{
	int ret = 0;
	char c = ' ';

	memset (&sConsoleCmd, 0, sizeof(sConsoleCmd));

//	console_puts("Activated: console task\n");

	while(1) {
		ret = driver_uart_wait_rx();
		if (ret != 0) continue;

		do {
			ret = driver_uart_getc(&c);
			if (ret == 0) {
				_push_console_in(c);
			}
		} 
		while (ret == 0);
	}
}
