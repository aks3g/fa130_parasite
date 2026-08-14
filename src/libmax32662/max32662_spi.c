/*
 * max32662_spi.c
 *
 * Copyright 2025 Kiyotaka Akasaka. All rights reserved.
 */
#include <stddef.h>
#include <stdint.h>

#include "cortex_m4.h"
#include "max32662_irq.h"
#include "max32662_spi.h"
#include "max32662_dmac.h"

typedef struct {
	uint32_t cpol;
	uint32_t cpha;
} SpiMode;

static SpiMode _modes[4] = 
{
	{
		.cpol = 0,
		.cpha = 0
	},
	{
		.cpol = 0,
		.cpha = 1
	},
	{
		.cpol = 1,
		.cpha = 0
	},
	{
		.cpol = 1,
		.cpha = 1
	}
};

static Max32662_spi_callback _cb[2] = {NULL, NULL};

static uint32_t _dma_flags[2] = {0,0};


static volatile Max32662_reg_spi *_selectSpi(max32662_spi_id id)
{
	if      (id == max32662_spi0) return MAX32662_SPI0;
	else if (id == max32662_spi1) return MAX32662_SPI1;
	else                          return NULL;
}

static void _set_flag_and_callback(max32662_spi_id id, uint32_t flag)
{
	_dma_flags[id] |= flag;
	if (_dma_flags[id] == ((1<<2) | (1<<1) | (1<<0)) ) {
		_cb[id](0);

		_cb[id] = NULL;
		_dma_flags[id] = 0;

		// Disable DMA
		volatile Max32662_reg_spi *spi = _selectSpi(id);
		spi->dma.bf.dma_rx_en = 0;
		spi->dma.bf.dma_tx_en = 0;
	}
}


static void _spi02mem_cb(int status)
{
	_set_flag_and_callback(max32662_spi0, (1<<0));
}

static void _mem2spi0_cb(int status)
{
	_set_flag_and_callback(max32662_spi0, (1<<1));
}

static void _spi12mem_cb(int status)
{
	_set_flag_and_callback(max32662_spi1, (1<<0));
}

static void _mem2spi1_cb(int status)
{
	_set_flag_and_callback(max32662_spi1, (1<<1));
}


static void _spi_handler(max32662_spi_id id, volatile Max32662_reg_spi *spi, Max32662_spi_callback cb)
{
	uint32_t flg = spi->intfl.dword;

	if (spi->dma.bf.dma_rx_en || spi->dma.bf.dma_tx_en) {
		if (spi->intfl.bf.mst_done) {
			_set_flag_and_callback(id, (1<<2));
		}
	}
	else {
		if (spi->intfl.bf.mst_done && cb) {
			cb(0);
		}
	}

	spi->intfl.dword = flg;


	return;
}

void spi0_handler(void)
{
	_spi_handler(max32662_spi0, MAX32662_SPI0, _cb[0]);
}

void spi1_handler(void)
{
	_spi_handler(max32662_spi1, MAX32662_SPI1, _cb[1]);
}



int max32662_spi_master_initialize(max32662_spi_id id, max32662_spi_mode mode, uint32_t sck_MHz, uint32_t peripheral_clk_MHz)
{
	volatile Max32662_reg_spi *spi = _selectSpi(id);
	if (spi == NULL) {
		return -1;
	}

	if (id == max32662_spi0) {
		__enable_nvic_irq(MAX32662_IRQNUM_SPI0);
	}
	else {
		__enable_nvic_irq(MAX32662_IRQNUM_SPI1);
	}

	spi->ctrl0.dword = 0; // Disable SPIx

	// setup spi char configuration 
	spi->ctrl2.bf.clkpol = _modes[mode].cpol;
	spi->ctrl2.bf.clkpha = _modes[mode].cpha;
	spi->ctrl2.bf.three_wire = 0;             // 4wire mode.
	spi->ctrl2.bf.numbits = 8;                // 8bits

	uint32_t clk_cnt =  sck_MHz / peripheral_clk_MHz;
	if (clk_cnt < 2) return -1;

	// setup ss timing
	spi->sstime.bf.pre   = clk_cnt;
	spi->sstime.bf.post  = clk_cnt;
	spi->sstime.bf.inact = clk_cnt;

	// clock setting
	spi->clkctrl.bf.clkdiv = 0;
	spi->clkctrl.bf.lo = clk_cnt / 2;
	spi->clkctrl.bf.hi = clk_cnt - spi->clkctrl.bf.lo;

	spi->ctrl0.bf.ss_io = 0;
	spi->ctrl0.bf.ss_active = 1; // Use SS target 0.
	spi->ctrl0.bf.mst_mode = 1;

	return 0;
}

int max32662_spi_master_transfer(max32662_spi_id id,  uint8_t *txbuf, uint8_t *rxbuf, size_t tx_size, size_t rx_size, Max32662_spi_callback cb)
{
	volatile Max32662_reg_spi *spi = _selectSpi(id);
	if (spi == NULL) {
		return -1;
	}

	if (cb) {
		// setup interrupt
		spi->inten.bf.mst_done = 1;
		_cb[id] = cb;
	}
	else {
		spi->inten.bf.mst_done = 0;
		_cb[id] = NULL;
	}

	size_t total = tx_size + rx_size;
	size_t p_tx = 0;
	size_t p_rx = 0;
	size_t skip_rx = tx_size;

	spi->ctrl0.bf.en = 0;

	// Disable FIFO
	spi->dma.bf.tx_fifo_en = 0;
	spi->dma.bf.rx_fifo_en = 0;

	// Enable fifo & Setup Transaction size
	spi->ctrl1.bf.rx_num_char = total;
	spi->dma.bf.rx_fifo_en = 1;

	spi->ctrl1.bf.tx_num_char = total;
	spi->dma.bf.tx_fifo_en = 1;

	spi->dma.bf.tx_thd_val = 1;
	spi->dma.bf.rx_thd_val = 1;

	spi->dma.bf.tx_flush = 1;
	spi->dma.bf.rx_flush = 1;

	spi->ctrl0.bf.en = 1;

	// Setup tx data
	size_t init_len = tx_size > 32 ? 32 : tx_size;
	for (size_t i=0 ; i<init_len ; ++i) {
		spi->fifo.byte = txbuf[p_tx++];
	}

	// Start transaction
	spi->intfl.dword = 0xffffffff;
	spi->ctrl0.bf.start = 1;

	// Tx/Rx がTotal Byteを超えるまで動かす
	while (p_tx < total) {
		while ((p_tx < total) && (spi->dma.bf.tx_lvl < 31)) {
			spi->fifo.byte = (p_tx < tx_size) ? txbuf[p_tx] : 0xff;
			p_tx++;
		}

		while ((p_rx < rx_size) && (spi->dma.bf.rx_lvl != 0)) {
			if (skip_rx) {
				skip_rx--;
				volatile uint8_t dispose = spi->fifo.byte;
				(void)dispose;
			}
			else {
				rxbuf[p_rx++] = spi->fifo.byte;
			}
		}
	}

	if (!cb) {
		while (spi->intfl.bf.mst_done == 0);
	}

	return 0;
}

int max32662_spi_master_transferDMA(max32662_spi_id id,  uint8_t *txbuf, uint8_t *rxbuf, size_t size, Max32662_spi_callback cb)
{
	int ret = 0;

	volatile Max32662_reg_spi *spi = _selectSpi(id);
	if (spi == NULL) {
		return -1;
	}

	// Setup SPI FIFO
	spi->ctrl0.bf.en = 0;

	// Disable FIFO
	spi->dma.bf.tx_fifo_en = 0;
	spi->dma.bf.rx_fifo_en = 0;

	// Enable fifo & Setup Transaction size
	spi->ctrl1.bf.rx_num_char = size;
	spi->dma.bf.rx_fifo_en = 1;

	spi->ctrl1.bf.tx_num_char = size;
	spi->dma.bf.tx_fifo_en = 1;

	spi->dma.bf.tx_thd_val = 1;
	spi->dma.bf.rx_thd_val = 1;

	spi->dma.bf.tx_flush = 1;
	spi->dma.bf.rx_flush = 1;

	spi->ctrl0.bf.en = 1;

	// PUSH to TX fifo.
	for (size_t i=0 ; i< (size>32 ? 32 : size) ; ++i) {
		spi->fifo.byte = txbuf[i];
	}

	// Setup DMAC
	Max32662_dmac_cfg_src_to_dma_fifo spi2mem_src;
	{
		spi2mem_src.src        = (void *)&(spi->fifo.byte);
		spi2mem_src.burst_size = 1;
		spi2mem_src.srcwd      = sizeof(uint8_t);
		spi2mem_src.cnt        = size;
		spi2mem_src.srcinc     = 0;
	}
	Max32662_dmac_cfg_dst_from_dma_fifo spi2mem_dst;
	{
		spi2mem_dst.dst        = rxbuf;
		spi2mem_dst.burst_size = 1;
		spi2mem_dst.dstwd      = sizeof(uint8_t);
		spi2mem_dst.dstinc     = 1;
	}
	// 先頭の32ByteはFIFOに積んでる
	Max32662_dmac_cfg_src_to_dma_fifo mem2spi_src;
	{
		mem2spi_src.src        = size>32 ? &(txbuf[32]) : txbuf;
		mem2spi_src.burst_size = 1;
		mem2spi_src.srcwd      = sizeof(uint8_t);
		mem2spi_src.cnt        = size>32 ? (size - 32) : 0;
		mem2spi_src.srcinc     = 1;
	}
	Max32662_dmac_cfg_dst_from_dma_fifo mem2spi_dst;
	{
		mem2spi_dst.dst        = (void *)&(spi->fifo.byte);
		mem2spi_dst.burst_size = 1;
		mem2spi_dst.dstwd      = sizeof(uint8_t);
		mem2spi_dst.dstinc     = 0;
	}

	Max32662_dmac_request ch0_req = (id == max32662_spi0) ? Max32662_dmac_req_spi0_to_mem : Max32662_dmac_req_spi1_to_mem;
	Max32662_dmac_request ch1_req = (id == max32662_spi0) ? Max32662_dmac_req_mem_to_spi0 : Max32662_dmac_req_mem_to_spi1;

	// Setup DMA
	ret = max32662_dmac_setup(Max32662_dmac_ch0, ch0_req, &spi2mem_src, &spi2mem_dst);
	if (ret != 0) return ret;
	ret = max32662_dmac_setup(Max32662_dmac_ch1, ch1_req, &mem2spi_src, &mem2spi_dst);
	if (ret != 0) return ret;

	ret = max32662_dmac_start_transfer(Max32662_dmac_ch0, id == max32662_spi0 ? _spi02mem_cb : _spi12mem_cb);
	if (ret != 0) return ret;
	ret = max32662_dmac_start_transfer(Max32662_dmac_ch1, id == max32662_spi0 ? _mem2spi0_cb : _mem2spi1_cb);
	if (ret != 0) return ret;

	// Enable DMA.
	spi->dma.bf.dma_rx_en = 1;
	spi->dma.bf.dma_tx_en = 1;

	// setup interrupt
	spi->inten.bf.mst_done = 1;
	_cb[id] = cb;

	// Start SPI transaction
	spi->ctrl0.bf.start = 1;

	return 0;
}
