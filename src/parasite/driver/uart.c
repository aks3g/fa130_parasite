/*
 * uart.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
// #include <stddef.h>
// #include <stdint.h>
// #include <stdio.h>

#include <kernel.h>
#include "kernel_cfg.h"

#include "string.h"

#include "target_syssvc.h"

#include "max32662_uart.h"
#include "include/driver/uart.h"

void isr_uart1(intptr_t exinf)
{
	size_t len = 0;

	max32662_uart_isr(1);

	max32662_uart_rx(1, NULL, 0, &len);
	if (len != 0) iset_flg(UART_FLG, UART_FLG_RX);

}

int driver_uart_init(int baudrate)
{
	max32662_uart_setup(Max32662_uart1, baudrate);

	// Enable Interrupt UART1
	ena_int(IRQ_UART1);

	return E_OK;
}
	
int driver_uart_putc(char c)
{
//	while (max32662_uart_tx_check_buf(Max32662_uart1) <= 1) dly_tsk(1);

	return max32662_uart_tx_b(Max32662_uart1, (uint8_t *)&c, sizeof(c));
}

int driver_uart_puts(char *str)
{
//	while (max32662_uart_tx_check_buf(Max32662_uart1) <= strlen(str)) dly_tsk(1);

	return max32662_uart_tx_b(Max32662_uart1, (uint8_t *)str, strlen(str));
}

int driver_uart_getc(char *c)
{
	size_t len;
	int err = max32662_uart_rx(Max32662_uart1, (uint8_t *)c, sizeof(char), &len);
	if (err != 0) {
		return err;
	}

	if (len != sizeof(char)) {
		return E_NOMEM;
	}

	return E_OK;
}

int driver_uart_wait_rx(void)
{
	FLGPTN  flg = 0;
	ER err = wai_flg(UART_FLG, UART_FLG_RX, TWF_ORW, &flg);
	if (err != E_OK) {
		return err;
	}

	if ((flg & UART_FLG_RX) == 0) {
		return E_SYS;
	}

	return E_OK;
}

