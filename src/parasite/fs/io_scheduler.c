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
typedf struct {
	uint32_t req;
	FsFile   *fil;
	void     *buf;
	size_t   len;
} IoRequest;
#pragma pack()

#define IO_SCHEDULER_DONE_FLG			(0x1 << 0)

int io_scheduler_task(void)
{
	IoRequest io_req;
	
	while (1) {
		int ret = rcv_mbf(FS_MBF, &io_req);
		if (ret != E_OK) continue;

		switch (io_req.req){
		case IO_SCHEDULER_WRIET:
			
			break;
		case IO_SCHEDULER_READ_BLOCKING:
			fs_read_page()
			set_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG);
			break;
		case IO_SCHEDULER_WRIET_BLOCKING:
			set_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG);
			break;
		default:
		}
	}
}


static FsFile _file[2] = 
{
	{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, {0}},
	{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, {0}},
}

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

int io_scheduler_write_req(FsFile *f, const uint8_t *buf, size_t length)
{
	IoRequest io_req;
	io_req.req = IO_SCHEDULER_WRITE;
	io_req.buf = (void *)buf;
	io_req.fil = f;
	io_req.len = length;

	int ret = snd_mbf(FS_MBF, &io_req, sizeof(io_req));
	if (ret != E_OK) return ret;

	return E_OK;
}


int io_scheduler_read_blocking(FsFile *f, uint8_t *buf, size_t length)
{
	IoRequest io_req;
	io_req.req = IO_SCHEDULER_READ;
	io_req.buf = (void *)buf;
	io_req.len = length;

	int ret = snd_mbf(FS_MBF, &io_req, sizeof(io_req));
	if (ret != E_OK) return ret;

	FLG_PTN flag;
	return twai_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG, TWF_ORW, &flg, 100);
}

int io_scheduler_write_blocking(FsFile *f, const uint8_t *buf, size_t length)
{
	IoRequest io_req;
	io_req.req = IO_SCHEDULER_WRITE;
	io_req.buf = (void *)buf;
	io_req.fil = f;
	io_req.len = length;

	int ret = snd_mbf(FS_MBF, &io_req, sizeof(io_req));
	if (ret != E_OK) return ret;

	FLG_PTN flag;
	return twai_flg(IO_SCHEDULER_FLG, IO_SCHEDULER_DONE_FLG, TWF_ORW, &flg, 100);
}