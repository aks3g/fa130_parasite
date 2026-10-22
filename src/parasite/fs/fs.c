/*
 * fs.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"

#include <string.h>

#include "max32662_spi.h"
#include "max32662_clock.h"

#include "error_code.h"
#include "sflash.h"
#include "fs/fs.h"

#include "app/console.h"

int fs_init(void)
{
	int ret = sflash_init();

	return ret;
}

int fs_open(FsFile *f, const fs_file_idx index)
{
	if (f == NULL) return E_FS_NULL;

	switch (index)
	{
	case fs_file_s_0:
	case fs_file_s_1:
	case fs_file_s_2:
	case fs_file_s_3:
	case fs_file_s_4:
	case fs_file_s_5:
	case fs_file_s_6:
	case fs_file_s_7:
		f->ptr = 0;
		f->size = FS_FILE_SIZE_SMALL;
		f->begin_page = (int)index * FS_FILE_PAGES_SMALL;
		break;
	case fs_file_l_0:
	case fs_file_l_1:
	case fs_file_l_2:
		f->ptr = 0;
		f->size = FS_FILE_SIZE_LARGE;
		f->begin_page = ((int)fs_file_s_7+1) * FS_FILE_PAGES_SMALL + ((int)index - (int)fs_file_l_0) * FS_FILE_PAGES_LARGE;
		break;

	default:
		return E_FS_NOT_FOUND;
	}


	return 0;
}

int fs_close(FsFile *f)
{
	memset ((void *)f, 0xff, sizeof(FsFile));

	return 0;
}


int fs_erase(FsFile *f)
{
	if (f == NULL) return E_FS_NULL;

	wai_sem(FS_SEM);

	uint32_t start_sector = (f->begin_page * SFLASH_PAGE_SIZE) / SFLASH_SECTOR_SIZE;
	for (size_t i = 0 ; i < (f->size / SFLASH_SECTOR_SIZE) ; ++i) {
		sflash_erase_sector((start_sector+i) * SFLASH_SECTOR_SIZE);
	}

	sig_sem(FS_SEM);

	return 0;
}


int fs_read(FsFile *f, uint8_t *buf, const size_t size)
{
	int ret = 0;
	if (f == NULL) return E_FS_NULL;

	size_t remaining = size;

	wai_sem(FS_SEM);

	//J 今の作業領域に乗っている部分はコピーしてしまう
	if ( ((size_t)f->ptr & (SFLASH_PAGE_SIZE - 1)) != 0) {
		size_t fragment = SFLASH_PAGE_SIZE - (size_t)f->ptr & (SFLASH_PAGE_SIZE - 1);
		size_t copy_size = framgnet > remaining ? remaining : fragment;
		if (copy_size) {
			memcpy(buf, &f->work[4+(size_t)f->ptr & (SFLASH_PAGE_SIZE - 1)], copy_size);
			remaining -= copy_size;
			f->ptr += copy_size;
			buf += copy_size;
		}
	}
	if (remaining == 0) goto FINALLY;

	uint32_t addr = (f->begin_page + (f->ptr / SFLASH_PAGE_SIZE)) * SFLASH_PAGE_SIZE;
	while (remaining) {
		ret=sflash_read_page(addr, f->work);
		if (ret != 0) goto FINALLY;

		uint32_t copy_size = remaining > SFLASH_PAGE_SIZE ? SFLASH_PAGE_SIZE : remaining;
		memcpy(buf, &f->work[4], copy_size);

		addr += SFLASH_PAGE_SIZE;
		remaining -= copy_size;
		f->ptr += copy_size;
		buf += copy_size;
	}


FINALLY:
	sig_sem(FS_SEM);

	return ret;
}

int fs_read_page(FsFile *f, uint8_t *buf, const size_t npage)
{
	int ret = 0;
	if (f == NULL) return E_FS_NULL;

	wai_sem(FS_SEM);

	uint32_t begin_address = (f->begin_page + (f->ptr / SFLASH_PAGE_SIZE)) * SFLASH_PAGE_SIZE;
	for (size_t i=0 ; i<npage ; ++i) {
		ret=sflash_read_page(begin_address + (i*SFLASH_PAGE_SIZE), f->work);
		if (ret != 0) goto ENSURE;

		memcpy(buf + i*SFLASH_PAGE_SIZE, &(f->work[4]), SFLASH_PAGE_SIZE);

		f->ptr += SFLASH_PAGE_SIZE;
	}
ENSURE:
	sig_sem(FS_SEM);

	return ret;
}


int fs_write(FsFile *f, const uint8_t *buf, const size_t size)
{
	if (f == NULL) return E_FS_NULL;
	wai_sem(FS_SEM);

	sig_sem(FS_SEM);

	return 0;
}

int fs_write_page(FsFile *f, const uint8_t *buf, const size_t npage)
{
	if (f == NULL) return E_FS_NULL;

	wai_sem(FS_SEM);

	uint32_t begin_address = (f->begin_page + (f->ptr / SFLASH_PAGE_SIZE)) * SFLASH_PAGE_SIZE;
	for (size_t i=0 ; i<npage ; ++i) {
		memcpy(f->work, buf + i*SFLASH_PAGE_SIZE, SFLASH_PAGE_SIZE);
		int ret =sflash_write_page(begin_address + (i*SFLASH_PAGE_SIZE), f->work);
		if (ret != 0) return ret;

		f->ptr += SFLASH_PAGE_SIZE;
	}

	sig_sem(FS_SEM);


	return 0;
}

int fs_seek(FsFile *f, uint32_t pos)
{
	if (f == NULL) return E_FS_NULL;

	f->ptr = pos;

	return 0;
}


int fs_format(void)
{
	wai_sem(FS_SEM);

	for (size_t i=0 ; i<SFLASH_SIZE / SFLASH_SECTOR_SIZE ; ++i) {
		console_printf(".");
		sflash_erase_sector(i * SFLASH_SECTOR_SIZE);
	}
	console_printf("\n");

	sig_sem(FS_SEM);

	return 0;
}
