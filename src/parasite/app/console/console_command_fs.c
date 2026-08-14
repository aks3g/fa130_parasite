/*
 * console_command_md.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"
#include "app/console.h"

#include <string.h>
#include <stdlib.h>

#include "fs/fs.h"
#include "sflash.h"

static FsFile test_file;
static uint8_t test_buf[512];

static void _dump_hex(uint8_t *arr, size_t size)
{
	for (size_t i=0 ; i<size; ++i) {
		console_printf("%02x%c", arr[i], (i%16==15) ? '\n' : ' ');
	}
}

void consoleHelpFs(void)
{
	console_printf("fs <sub command>\n");
	console_printf(" - fs info\n");
	console_printf(" - fs format\n");
	console_printf(" - fs read <file index> <sector index>\n");
	console_printf(" - fs fill <file index> <sector index> <value>\n");
}

void consoleFuncFs(char **argv, int argc)
{
	if (argc < 2) {
		consoleHelpFs();
		return;
	}

	if (strcmp(argv[1], "info") == 0) {
		uint8_t manu_id, dev_id, uid;
		uint16_t jdid;
		sflash_read_ids(&manu_id, &dev_id, &jdid, &uid);

		console_printf("MDID = %02x %02x, JDID = %04x, UID = %02x\n", manu_id, dev_id, jdid, uid);
	}
	else if (strcmp(argv[1], "format") == 0) {
		fs_format();
		console_printf("format was done\n");
	}
	else if (strcmp(argv[1], "read") == 0) {
		if (argc != 4) {
			consoleHelpFs();
			return;
		}

		uint32_t idx = 0;
		uint32_t start_page = 0;

		idx        = strtoul(argv[2], NULL, 10);
		start_page = strtoul(argv[3], NULL, 10);

		console_printf("Read file %d, start_page = %d\n", idx, start_page);

		fs_open(&test_file, idx);
		fs_seek(&test_file, start_page * SFLASH_PAGE_SIZE);
		fs_read_page(&test_file, test_buf, 1);

		_dump_hex(test_buf, SFLASH_PAGE_SIZE);
	}
	else if (strcmp(argv[1], "fill") == 0) {
		if (argc != 5) {
			consoleHelpFs();
			return;
		}

		uint32_t idx = 0;
		uint32_t start_page = 0;
		uint8_t  val = 0;

		idx        = strtoul(argv[2], NULL, 10);
		start_page = strtoul(argv[3], NULL, 10);
		val        = strtoul(argv[4], NULL, 16);

		console_printf("Fill file %d, page = %d, value = %02x\n", idx, start_page, val);

		memset(test_buf, val, sizeof(test_buf));

		fs_open(&test_file, idx);
		fs_seek(&test_file, start_page * SFLASH_PAGE_SIZE);
		fs_write_page(&test_file, test_buf, 1);
	}
	else if (strcmp(argv[1], "rm") == 0) {
		if (argc != 3) {
			consoleHelpFs();
			return;
		}

		uint32_t idx = strtoul(argv[2], NULL, 10);

		console_printf("Remove file %d\n", idx);

		fs_open(&test_file, idx);
		fs_erase(&test_file);
	}
	else {
		consoleHelpFs();
	}


	return;
}

