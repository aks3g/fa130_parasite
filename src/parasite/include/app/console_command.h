/*
 * console_command.h
 *
 * Copyright 2026 Kiyotaka Akasaka. All rights reserved.
 */
#ifndef CONSOLE_COMMAND_TABLE_H_
#define CONSOLE_COMMAND_TABLE_H_

#include <stdint.h>
#include <stddef.h>

typedef  void (*CommandFunc)(char **argv, size_t argc);
typedef  void (*CommandHelp)(void);

typedef struct {
	CommandFunc func;
	CommandHelp help;
	char *name;
} ConsoleCmdItem;

extern ConsoleCmdItem consoleCmdSet[];


extern void consoleFuncEcho(char **argv, size_t argc);
extern void consoleFuncVersion(char **argv, size_t argc);
extern void consoleFuncHelp(char **argv, size_t argc);
extern void consoleFuncCapture(char **argv, size_t argc);
extern void consoleFuncMotor(char **argv, size_t argc);
extern void consoleFuncPid(char **argv, size_t argc);
extern void consoleFuncSignalProc(char **argv, size_t argc);
extern void consoleFuncFs(char **argv, size_t argc);
extern void consoleFuncEnv(char **argv, size_t argc);
extern void consoleFuncSaveEnv(char **argv, size_t argc);
extern void consoleFuncSensor(char **argv, int argc);

extern void consoleHelpHelp(void);
extern void consoleHelpCapture(void);
extern void consoleHelpMotor(void);
extern void consoleHelpPid(void);
extern void consoleHelpSignalProc(void);
extern void consoleHelpFs(void);
extern void consoleHelpEnv(void);
extern void consoleHelpSensor(void);


extern void consoleCmdExec(char *line);


#endif



