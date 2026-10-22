/*
 * io_scheduler.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#ifndef IO_SCHADULER_H_
#define IO_SCHADULER_H_

extern int     io_scheduler_task(void);
extern FsFile *io_scheduler_open(fs_file_idx index);
extern int     io_scheduler_read_req (FsFile *f, uint8_t *buf, size_t length);
extern int     io_scheduler_write_req(FsFile *f, const uint8_t *buf, size_t length);

#endif


