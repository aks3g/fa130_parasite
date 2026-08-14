/*
 * env.c
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#include <kernel.h>
#include "kernel_cfg.h"

#include <string.h>

#include "fs/fs.h"

#include "error_code.h"
#include "file_list.h"

#include "app/console.h"

#define ENV_STRING_SIZE			(1024)
static char _env[ENV_STRING_SIZE] = {0xff};
static char *_env_tail = NULL;
static FsFile _envFile;

static char * _env_get_tail_pos(void)
{
	char *p = _env;
	while (*p != 0xff && p != _env_tail) p++;

	return p;
}

static size_t _env_get_free_size(void)
{
	char *tail = _env_get_tail_pos();

	return (size_t)ENV_STRING_SIZE - (size_t)(tail - _env);
}

static char * _env_get_key_pos(const char *key)
{
	char *p = _env;
	while (*(uint8_t *)p != 0xff) {
		if (strncmp(key, p, strlen(key)) == 0 && p[strlen(key)] == '=') {
			return p;
		}
		//J 環境変数レコード+NULL終端
		p += strlen(p) + 1;
	}

	return NULL;
}

static int _env_add_entry_at_tail(const char *key, const char *value)
{
	if (_env_get_free_size() < (strlen(key) + strlen(value) + 2)) return E_ENV_NO_SPACE;

	char *p = _env_get_tail_pos();

	// copy <key>=<value>
	strcpy(p, key); p+= strlen(key);
	*p++ = '=';
	strcpy(p, value);

	return E_OK;
}

int env_init(void)
{
	int ret =fs_open(&_envFile, FILE_INDEX_ENV_FILE);
	if (ret != E_OK) return ret;

	ret = fs_read_page(&_envFile, (uint8_t *)_env, ENV_STRING_SIZE/SFLASH_PAGE_SIZE);
	if (ret != E_OK) return ret;

	_env_tail = &_env[ENV_STRING_SIZE - 1];

	return 0;
}

int env_get_value(const char *key, const char **value)
{
	char *p = _env_get_key_pos(key);
	if (p == NULL) return E_ENV_NOT_FOUND;

	*value = p + (strlen(key)+1);
	return E_OK;
}

int env_set_value(const char *key, const char *value)
{
	const char *val = NULL;

	//J 存在しない環境変数の登録
	if (E_ENV_NOT_FOUND == env_get_value(key, &val)) {
		return _env_add_entry_at_tail(key, value);
	}
	//J 存在する環境変数の更新
	else {
		char *p = _env_get_key_pos(key);
		size_t remove_size = strlen(p) + 1; // 環境変数レコード+NULL終端
		char *follow = p + remove_size;

		// Remove entry and fill
		memcpy (p, follow, _env_tail - follow);
		memset (_env_tail - remove_size + 1, 0xff, remove_size);

		return _env_add_entry_at_tail(key, value);
	}

	return 0;
}

int env_save(void)
{
	int ret = fs_erase(&_envFile);
	if (ret != E_OK) return ret;

	fs_seek(&_envFile, 0);
	ret = fs_write_page(&_envFile, (uint8_t *)_env, ENV_STRING_SIZE/SFLASH_PAGE_SIZE);

	return ret;
}


int env_dump_hex(void)
{
	console_printf("%u %p %p\n", _env_get_free_size(), _env_get_tail_pos(), _env);
	for (size_t i= 0 ;i<ENV_STRING_SIZE ; ++i) {
		console_printf("%02x%c", _env[i], (i%16==15) ? '\n':' ');
	}

	return 0;
}
