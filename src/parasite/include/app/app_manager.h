/*
 * app_manager.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef _APP_MANAGER_H_
#define _APP_MANAGER_H_


#include "driver/iam20680ht.h"

typedef void (*App)(void);

extern int appManager_init(void);
extern App appManagerGetCurrentApp(void);

#endif/*_APP_MANAGER_H_*/
