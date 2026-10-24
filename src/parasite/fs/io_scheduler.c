/*
 * io_scheduler.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"
#include "string.h"
#include "target_syssvc.h"

#include "app/console.h"

#include "fs/fs.h"
#include "fs/io_scheduler.h"

#pragma pack(1)
typedef struct {
	uint32_t req;
	FsFile   *fil;
	void     *buf;
	size_t   len;
} IoRequest;
#pragma pack()

#define IO_SCHEDULER_DONE_FLG					(0x1 << 0)
#define IO_SCHEDULER_ALIGNE_ERROR_FLG			(0x1 << 1)
#define IO_SCHEDULER_IO_ERROR_FLG				(0x1 << 2)

typedef enum {
	IO_SCHEDULER_WRITE_REQ,
	IO_SCHEDULER_BLOCK_WRITE_REQ,
	IO_SCHEDULER_READ,
	IO_SCHEDULER_BLOCK_READ,
	IO_SCHEDULER_WRITE,
	IO_SCHEDULER_BLOCK_WRITE,
} IoSchedulerRequest;

int io_scheduler_task(void)
{
	IoRequest *io_req;
	
	while (1) {
		int ret = rcv_dtq(FS_IO_DTQ, (intptr_t *)&io_req);
		if (ret != E_OK) continue;

		switch (io_req->req){
		case IO_SCHEDULER_WRITE_REQ:
			(void)fs_write(io_req->fil, io_req->buf, io_req->len);
			break;
		case IO_SCHEDULER_BLOCK_WRITE_REQ:
			if( (io_req->len % SFLASH_PAGE_SIZE) != 0 ) break;
			(void)fs_write_page(io_req->fil, io_req->buf, (io_req->len/SFLASH_PAGE_SIZE));
			break;

		case IO_SCHEDULER_READ:
			fs_read(io_req->fil, io_req->buf, io_req->len);
			set_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG);
			break;
		case IO_SCHEDULER_BLOCK_READ:
			if( (io_req->len % SFLASH_PAGE_SIZE) != 0 ) {
				set_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_ALIGNE_ERROR_FLG);
			}
			else {
				int ret = fs_read_page(io_req->fil, io_req->buf, io_req->len);
				if (ret == E_OK) set_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG);
				else             set_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_IO_ERROR_FLG);
			}
			break;

		case IO_SCHEDULER_WRITE:
			fs_write(io_req->fil, io_req->buf, io_req->len);
			set_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG);
			break;
		case IO_SCHEDULER_BLOCK_WRITE:
			if( (io_req->len % SFLASH_PAGE_SIZE) != 0 ) {
				set_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_ALIGNE_ERROR_FLG);
			}
			else {
				int ret = fs_write_page(io_req->fil, io_req->buf, io_req->len);
				if (ret == E_OK) set_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG);
				else             set_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_IO_ERROR_FLG);
			}
			break;

		default:
			break;
		}
	}
}

static FsFile _file[2] = 
{
	{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, {0}},
	{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, {0}},
};

FsFile *io_scheduler_open(fs_file_idx index)
{
	// search free file context
	FsFile *f = NULL;
	for (uint32_t i= 0; i< sizeof(_file)/sizeof(_file[0]) ; ++i) {
		if (_file[i].ptr == 0xffffffff) {
			f = &_file[i];
			break;
		}
	}

	if (f == NULL) {
		return NULL;
	}

	// Open file.
	int ret =fs_open(f, index);
	if (ret != E_OK) return NULL;

	return f;
}

// 本当はLock取るべき．将来的にMulti Thread safeにしないとダメ
int io_scheduler_write_req(FsFile *f, const uint8_t *buf, size_t length)
{
	static IoRequest io_req;
	io_req.req = IO_SCHEDULER_WRITE_REQ;
	io_req.buf = (void *)buf;
	io_req.fil = f;
	io_req.len = length;

	int ret = snd_dtq(FS_IO_DTQ, (intptr_t)&io_req);
	if (ret != E_OK) return ret;

	return E_OK;
}

// 本当はLock取るべき
int io_scheduler_block_write_req(FsFile *f, const uint8_t *buf, size_t length)
{
	static IoRequest io_req;
	io_req.req = IO_SCHEDULER_BLOCK_WRITE_REQ;
	io_req.buf = (void *)buf;
	io_req.fil = f;
	io_req.len = length;

	int ret = snd_dtq(FS_IO_DTQ, (intptr_t)&io_req);
	if (ret != E_OK) return ret;

	return E_OK;
}

int io_scheduler_read(FsFile *f, uint8_t *buf, size_t length)
{
	IoRequest io_req;
	io_req.req = IO_SCHEDULER_READ;
	io_req.buf = (void *)buf;
	io_req.len = length;

	int ret = snd_dtq(FS_IO_DTQ, (intptr_t)&io_req);
	if (ret != E_OK) return ret;

	FLGPTN flag;
	ret = twai_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG, TWF_ORW, &flag, 100);
	if (ret != E_OK) return ret;
	if (flag & IO_SCHEDULER_ALIGNE_ERROR_FLG) {
		return E_ALIGN;
	}
	else if (flag & IO_SCHEDULER_IO_ERROR_FLG) {
		return E_IO;
	}
	return E_OK;
}

int io_scheduler_block_read(FsFile *f, uint8_t *buf, size_t length)
{
	IoRequest io_req;
	io_req.req = IO_SCHEDULER_BLOCK_READ;
	io_req.buf = (void *)buf;
	io_req.len = length;

	int ret = snd_dtq(FS_IO_DTQ, (intptr_t)&io_req);
	if (ret != E_OK) return ret;

	FLGPTN flag;
	ret = twai_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG, TWF_ORW, &flag, 100);
	if (ret != E_OK) return ret;
	if (flag & IO_SCHEDULER_ALIGNE_ERROR_FLG) {
		return E_ALIGN;
	}
	else if (flag & IO_SCHEDULER_IO_ERROR_FLG) {
		return E_IO;
	}
	return E_OK;
}

int io_scheduler_write(FsFile *f, const uint8_t *buf, size_t length)
{
	IoRequest io_req;
	io_req.req = IO_SCHEDULER_WRITE;
	io_req.buf = (void *)buf;
	io_req.fil = f;
	io_req.len = length;

	int ret = snd_dtq(FS_IO_DTQ, (intptr_t)&io_req);
	if (ret != E_OK) return ret;

	FLGPTN flag;
	ret = twai_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG, TWF_ORW, &flag, 100);
	if (ret != E_OK) return ret;
	if (flag & IO_SCHEDULER_ALIGNE_ERROR_FLG) {
		return E_ALIGN;
	}
	else if (flag & IO_SCHEDULER_IO_ERROR_FLG) {
		return E_IO;
	}
	return E_OK;
}

int io_scheduler_block_write(FsFile *f, const uint8_t *buf, size_t length)
{
	IoRequest io_req;
	io_req.req = IO_SCHEDULER_BLOCK_WRITE;
	io_req.buf = (void *)buf;
	io_req.fil = f;
	io_req.len = length;

	int ret = snd_dtq(FS_IO_DTQ, (intptr_t)&io_req);
	if (ret != E_OK) return ret;

	FLGPTN flag;
	ret = twai_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG, TWF_ORW, &flag, 100);
	if (ret != E_OK) return ret;
	if (flag & IO_SCHEDULER_ALIGNE_ERROR_FLG) {
		return E_ALIGN;
	}
	else if (flag & IO_SCHEDULER_IO_ERROR_FLG) {
		return E_IO;
	}
	return E_OK;
}

