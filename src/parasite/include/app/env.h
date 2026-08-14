/*
 * env.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */

#ifndef ENV_H_
#define ENV_H_

extern int env_init(void);
extern int env_get_value(const char *key, const char **value);
extern int env_set_value(const char *key, const char *value);
extern int env_dump_hex(void);
extern int env_save(void);

#endif