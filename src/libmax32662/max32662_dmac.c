/*
 * max32662_spi.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */
#include <stddef.h>
#include <stdint.h>

#include "cortex_m4.h"
#include "max32662_irq.h"
#include "max32662_dmac.h"

static Max32662_dmac_transfer_done_callback s_callbacks[Max32662_dmac_ch_MAX] = {NULL};

static int _to_errcode(uint32_t flg)
{
//	if ((flg & (1<<1)) == 0) return MAX32662_DMAC_CODE_UNKNWON;

	if (flg & (1<<2))		return MAX32662_DMAC_CODE_CTZ;
	else if (flg & (1<<3))	return MAX32662_DMAC_CODE_RLD;
	else if (flg & (1<<4))	return MAX32662_DMAC_CODE_BUS_ERR;
	else if (flg & (1<<6))	return MAX32662_DMAC_CODE_TO;

	return MAX32662_DMAC_CODE_UNKNWON;
}

static void _dmacx_handler(Max32662_dmac_ch ch)
{
	uint32_t flg = MAX32662_DMAC->ch[ch].status.dword;
	MAX32662_DMAC->ch[ch].status.dword = flg; // Clear W1C bit

	if (s_callbacks[ch] != NULL) s_callbacks[ch](_to_errcode(flg));

}

void dmac0_handler(void)
{
	_dmacx_handler(Max32662_dmac_ch0);
}

void dmac1_handler(void)
{
	_dmacx_handler(Max32662_dmac_ch1);
}

void dmac2_handler(void)
{
	_dmacx_handler(Max32662_dmac_ch2);
}

void dmac3_handler(void)
{
	_dmacx_handler(Max32662_dmac_ch3);
}


static int _dst_is_memory(Max32662_dmac_request req)
{
	switch (req)
	{
	case Max32662_dmac_req_mem_to_mem	:
	case Max32662_dmac_req_spi0_to_mem	:
	case Max32662_dmac_req_spi1_to_mem	:
	case Max32662_dmac_req_uart0_to_mem	:
	case Max32662_dmac_req_uart1_to_mem	:
	case Max32662_dmac_req_can_to_mem	:
	case Max32662_dmac_req_i2c0_to_mem	:
	case Max32662_dmac_req_i2c1_to_mem	:
	case Max32662_dmac_req_adc_to_mem	:
	case Max32662_dmac_req_i2c2_to_mem	:
	case Max32662_dmac_req_i2s_to_mem	:
		return 1;

	case Max32662_dmac_req_mem_to_spi0	:
	case Max32662_dmac_req_mem_to_spi1	:
	case Max32662_dmac_req_mem_to_uart0	:
	case Max32662_dmac_req_mem_to_uart1	:
	case Max32662_dmac_req_mem_to_can	:
	case Max32662_dmac_req_mem_to_i2c0	:
	case Max32662_dmac_req_mem_to_i2c1	:
	case Max32662_dmac_req_mem_to_i2s	:
	default:
		return 0;
	}
}

static int _src_is_memory(Max32662_dmac_request req)
{
	switch (req)
	{
	case Max32662_dmac_req_spi0_to_mem	:
	case Max32662_dmac_req_spi1_to_mem	:
	case Max32662_dmac_req_uart0_to_mem	:
	case Max32662_dmac_req_uart1_to_mem	:
	case Max32662_dmac_req_can_to_mem	:
	case Max32662_dmac_req_i2c0_to_mem	:
	case Max32662_dmac_req_i2c1_to_mem	:
	case Max32662_dmac_req_adc_to_mem	:
	case Max32662_dmac_req_i2c2_to_mem	:
	case Max32662_dmac_req_i2s_to_mem	:
		return 0;

	case Max32662_dmac_req_mem_to_mem	:
	case Max32662_dmac_req_mem_to_spi0	:
	case Max32662_dmac_req_mem_to_spi1	:
	case Max32662_dmac_req_mem_to_uart0	:
	case Max32662_dmac_req_mem_to_uart1	:
	case Max32662_dmac_req_mem_to_can	:
	case Max32662_dmac_req_mem_to_i2c0	:
	case Max32662_dmac_req_mem_to_i2c1	:
	case Max32662_dmac_req_mem_to_i2s	:
	default:
		return 1;
	}
}


int max32662_dmac_initialize(void)
{
	return 0;
}

int max32662_dmac_setup(Max32662_dmac_ch ch, Max32662_dmac_request req, Max32662_dmac_cfg_src_to_dma_fifo *src, Max32662_dmac_cfg_dst_from_dma_fifo *dst)
{
	volatile Max32662_reg_dmac_channel *dmac = &(MAX32662_DMAC->ch[ch]);

	// Step 1. Ensure DMA_CHn_CTRL.en, DMA_CHn_CTRL.rlden = 0, and DMA_CHn_STATUS.ctz_if = 0.
	dmac->ctrl.bf.en    = 0;
	dmac->ctrl.bf.rlden = 0;
	dmac->status.bf.ctz_if = 0;

	// Step 2. Configure DMA DST address
	if (_dst_is_memory(req)) {
		dmac->dst = (uint32_t)((int)dst->dst);
	}

	// Step 3. Configure DMA SRC address
	if (_src_is_memory(req)) {
		dmac->src = (uint32_t)((int)src->src);
	}

	// Step 4.
	dmac->cnt.bf.cnt = src->cnt;

	// Step 5
	dmac->ctrl.bf.request = req;
	dmac->ctrl.bf.burst_size = dst->burst_size;
	dmac->ctrl.bf.pri = 0; // TODO
	dmac->ctrl.bf.dstwd  = dst->dstwd;
	dmac->ctrl.bf.dstinc = dst->dstinc;
	dmac->ctrl.bf.srcwd  = src->srcwd;
	dmac->ctrl.bf.srcinc = src->srcinc;

	dmac->ctrl.bf.dis_ie = 1;
	dmac->ctrl.bf.ctz_ie = 1;

	dmac->ctrl.bf.to_clkdiv = 0;

	// Step 6
	dmac->ctrl.bf.rlden = 0;

	return 0;
}

int max32662_dmac_start_transfer(Max32662_dmac_ch ch, Max32662_dmac_transfer_done_callback cb)
{
	// Register Callback
	if (cb != NULL) {
		s_callbacks[ch] = cb;

		__enable_nvic_irq(MAX32662_IRQNUM_DAC0 + ch);
		MAX32662_DMAC->inten.dword |= (1<<ch);
	}
	else {
		__disable_nvic_irq(MAX32662_IRQNUM_DAC0 + ch);
		MAX32662_DMAC->inten.dword &=~(1<<ch);
	}

	// Step 7
	MAX32662_DMAC->ch[ch].ctrl.bf.en = 1;

	return 0;
}

