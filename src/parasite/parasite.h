/*
 *  ターゲット依存の定義
 */
#include "target_test.h"

/*
 *  各タスクの優先度の定義
 */

#define MAIN_PRIORITY	5		/* メインタスクの優先度 */

#define HIGH_PRIORITY	9		/* 並行実行されるタスクの優先度 */
#define MID_PRIORITY	10
#define LOW_PRIORITY	11

/*
 *  ターゲットに依存する可能性のある定数の定義
 */

#ifndef TASK_PORTID
#	define	TASK_PORTID		1			/* 文字入力するシリアルポートID */
#endif /* TASK_PORTID */

#ifndef STACK_SIZE
#	define	STACK_SIZE		4096		/* タスクのスタックサイズ */
#endif /* STACK_SIZE */

#ifndef LOOP_REF
#	define LOOP_REF		ULONG_C(1000000)	/* 速度計測用のループ回数 */
#endif /* LOOP_REF */

/*
 *  関数のプロトタイプ宣言
 */
#ifndef TOPPERS_MACRO_ONLY

extern void app_hw_init(intptr_t exinf);

extern void main_task(intptr_t exinf);
extern void fs_task(intptr_t exinf);
extern void sensor_task(intptr_t exinf);
extern void signal_proc_task(intptr_t exinf);
extern void console_task(intptr_t exinf);

#ifdef CPUEXC1
extern void	cpuexc_handler(void *p_excinf);
#endif /* CPUEXC1 */

#endif /* TOPPERS_MACRO_ONLY */
