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



static volatile Max32662_reg_spi *_selectSpi(max32662_spi_id id)
{
	if      (id == max32662_spi0) return MAX32662_SPI0;
	else if (id == max32662_spi1) return MAX32662_SPI1;
	else                          return NULL;
}


int max32662_spi_master_initialize(max32662_spi_id id, max32662_spi_mode mode, uint32_t sck_MHz, uint32_t peripheral_clk_MHz)
{
	volatile Max32662_reg_spi *spi = _selectSpi(id);
	if (spi == NULL) {
		return -1;
	}

	spi->ctrl0.dword = 0; // Disable SPIx

	// setup spi char configuration 
	spi->ctrl2.bf.clkpol = _modes[mode].cpol;
	spi->ctrl2.bf.clkpha = _modes[mode].cpha;
	spi->ctrl2.bf.three_wire = 0;             // 4wire mode.
	spi->ctrl2.bf.numbits = 8;                // 8bits

	uint32_t clk_cnt = peripheral_clk_MHz / sck_MHz;
	if (clk_cnt < 2) return -1;

	// setup ss timing
	spi->sstime.bf.pre   = clk_cnt;
	spi->sstime.bf.post  = clk_cnt;
	spi->sstime.bf.inact = clk_cnt;

	spi->sstime.bf.pre   = 1;
	spi->sstime.bf.post  = 1;
	spi->sstime.bf.inact = 1;

	// clock setting
	spi->clkctrl.bf.clkdiv = 4;
//	spi->clkctrl.bf.lo = clk_cnt / 2;
//	spi->clkctrl.bf.hi = clk_cnt - spi->clkctrl.bf.lo;
	spi->clkctrl.bf.lo = 15;
	spi->clkctrl.bf.hi = 15;

	spi->ctrl0.bf.ss_io = 0;
	spi->ctrl0.bf.ss_active = 1; // Use SS target 0.
	spi->ctrl0.bf.mst_mode = 1;

	return 0;
}

int max32662_spi_master_transfer(max32662_spi_id id,  uint8_t *txbuf, uint8_t *rxbuf, size_t tx_size, size_t rx_size)
{
	volatile Max32662_reg_spi *spi = _selectSpi(id);
	if (spi == NULL) {
		return -1;
	}

	size_t total = tx_size + rx_size;
	size_t p_tx = 0;
	size_t p_rx = 0;

	spi->ctrl0.bf.en = 0;

	// Enable fifo & Setup Transaction size
	spi->ctrl1.bf.rx_num_char = total;
	spi->dma.bf.rx_fifo_en = 1;

	spi->ctrl1.bf.tx_num_char = total;
	spi->dma.bf.tx_fifo_en = 1;

	spi->dma.bf.tx_flush = 1;
	spi->dma.bf.rx_flush = 1;

	spi->dma.bf.tx_thd_val = 1;
	spi->dma.bf.rx_thd_val = 1;

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
	while ((p_rx < total) || (p_tx < total)) {
		while ((p_tx < total) && (spi->dma.bf.tx_lvl < 31)) {
			spi->fifo.byte = (p_tx < tx_size) ? txbuf[p_tx] : 0xff;
			p_tx++;
		}

		while ((p_rx < total) && (spi->dma.bf.rx_lvl != 0)) {
			rxbuf[p_rx++] = spi->fifo.byte;
		}
	}

	while (spi->intfl.bf.mst_done == 0);

	// Disable fifo
	spi->dma.bf.tx_fifo_en = 0;
	spi->dma.bf.rx_fifo_en = 0;


	return 0;
}

int max32662_spi_master_transferDMA(max32662_spi_id id,  uint8_t *txbuf, uint8_t *rxbuf, size_t size)
{
	return 0;
}
