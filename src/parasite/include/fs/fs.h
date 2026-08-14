/*
 * fs.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#ifndef FS_H_
#define FS_H_

#define SFLASH_SIZE					(1024*1024)
#define SFLASH_PAGE_SIZE			(256)
#define SFLASH_SECTOR_SIZE			(4096)

#define FS_FILE_SIZE_SMALL			(  8 * 1024)
#define FS_FILE_SIZE_LARGE			(320 * 1024)

#define FS_FILE_PAGES_SMALL			(FS_FILE_SIZE_SMALL / SFLASH_PAGE_SIZE)
#define FS_FILE_PAGES_LARGE			(FS_FILE_SIZE_LARGE / SFLASH_PAGE_SIZE)

typedef enum {
	fs_file_s_0 = 0,
	fs_file_s_1,
	fs_file_s_2,
	fs_file_s_3,
	fs_file_s_4,
	fs_file_s_5,
	fs_file_s_6,
	fs_file_s_7,

	fs_file_l_0,
	fs_file_l_1,
	fs_file_l_2,
} fs_file_idx;


typedef struct 
{
	uint32_t ptr;
	uint32_t size;
	uint32_t begin_page;
	uint8_t work[SFLASH_PAGE_SIZE + 5];
} FsFile;


extern int fs_init(void);
extern int fs_erase(FsFile *f);
extern int fs_open(FsFile *f, const fs_file_idx index);
extern int fs_close(FsFile *f);
extern int fs_read(FsFile *f, uint8_t *buf, const size_t size);
extern int fs_read_page(FsFile *f, uint8_t *buf, const size_t npage);
extern int fs_write(FsFile *f, const uint8_t *buf, const size_t size);
extern int fs_write_page(FsFile *f, const uint8_t *buf, const size_t npage);
extern int fs_seek(FsFile *fs, uint32_t pos);
extern int fs_format(void);

#endif


