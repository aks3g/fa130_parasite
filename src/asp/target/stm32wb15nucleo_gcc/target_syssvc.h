/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2017-2021 by TOPPERS PROJECT Educational Working Group.
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: target_syssvc.h 698 2021-01-11 16:30:27Z roi $
 */

/*
 *  システムサービスのターゲット依存部（stm32wb15-nucleo用）
 *
 *  システムサービスのターゲット依存部のインクルードファイル．このファ
 *  イルの内容は，コンポーネント記述ファイルに記述され，このファイルは
 *  無くなる見込み．
 */

#ifndef TOPPERS_TARGET_SYSSVC_H
#define TOPPERS_TARGET_SYSSVC_H

/*
 *  ターゲットシステムのハードウェア資源の定義
 */
#include "stm32wbxx.h"


/*
 *  システムクロックの定義
 */
#if !defined(HSE_VALUE)
#define HSE_VALUE           32000000		/* Value of the External oscillator in Hz */
#endif /* HSE_VALUE */
#if !defined(HSI_VALUE)
#define HSI_VALUE           16000000		/* Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */
#if !defined(LSE_VALUE)
#define LSE_VALUE           32768			/* Value of the External low oscillator in Hz*/
#endif

/*
 *  RCC System Clock Source Statusの定義
 */
#define RCC_SYSCLKSOURCE_STATUS_MSI    0x00000000			/* MSI used as system clock */
#define RCC_SYSCLKSOURCE_STATUS_HSI    RCC_CFGR_SWS_0		/* HSI used as system clock */
#define RCC_SYSCLKSOURCE_STATUS_HSE    RCC_CFGR_SWS_1		/* HSE used as system clock */
#define RCC_SYSCLKSOURCE_STATUS_PLLCLK (RCC_CFGR_SWS_1 | RCC_CFGR_SWS_0)   /* PLL used as system clock */

/*
 *  PLLクロックソースの定義
 */
#define RCC_PLLSOURCE_NONE  0x00000000				/* No clock selected as PLL entry clock source  */
#define RCC_PLLSOURCE_MSI   RCC_PLLCFGR_PLLSRC_MSI	/* MSI clock selected as PLL entry clock source */
#define RCC_PLLSOURCE_HSI   RCC_PLLCFGR_PLLSRC_HSI	/* HSI clock selected as PLL entry clock source */
#define RCC_PLLSOURCE_HSE   RCC_PLLCFGR_PLLSRC_HSE	/* HSE clock selected as PLL entry clock source */


#ifndef TOPPERS_MACRO_ONLY

extern  uint32_t SystemFrequency;
#define SysFreHCLK          SystemFrequency	/* HCLK = MasterClock / 1 */
#define SysFrePCLK1         SystemFrequency	/* PCLK1 = HCLK / 1 */
#define SysFrePCLK2         SystemFrequency	/* PCLK2 = HCLK / 1 */

#define SYS_CLOCK		    (SystemFrequency)

extern uint8_t current_range;

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  RCCレジスタシフト定義
 */
#define PLLM_SHIFT          4
#define PLLN_SHIFT          8
#define PLLP_SHIFT          17
#define PLLQ_SHIFT          25
#define PLLR_SHIFT          29
#define CFGR_HPRE_SHIFT     4
#define MSIRANG_SHIFT       4

/*
 *  SRAM2領域定義
 */
#define SRAM2ABASE          0x20030000	/* SRAM2A base address in the alias region */
#define SRAM2A_SIZE         (32*1024)	/* SRAM2A size */
#define SRAM2BBASE          0x20038000	/* SRAM2B base address in the alias region */
#define SRAM2B_SIZE         (4*1024)	/* SRAM2B size */

/*
 *  トレースログに関する設定
 */
#ifdef TOPPERS_ENABLE_TRACE
#include "logtrace/trace_config.h"
#endif /* TOPPERS_ENABLE_TRACE */

/*
 *  起動メッセージのターゲットシステム名
 */
#define TARGET_NAME    "stm32wb15-nucleo(Cortex-M4)"

/*
 *  起動メッセージの著作権表示
 */
#define TARGET_COPYRIGHT \
"Copyright (C) 2016-2021 by Education Working Group TOPPERS PROJECT\n" \

#ifndef TOPPERS_MACRO_ONLY

/*
 *  起動システムクロックの取得
 */
extern uint32_t sysclock_init_value(void);

/*
 *  システムクロックコンフィギュレーション
 */
extern ER sysclock_config(int mode);

/*
 *  システムクロックの変更
 */
extern ER sysclock_change(uint8_t range);


/*
 *  Hardware Semaphore初期化
 */
extern void hsem_init(intptr_t exinf);

/*
 *  ターゲット１ステップロック
 */
extern uint32_t hsem_1steplock(uint8_t sem);

/*
 *  ターゲットリリースロック
 */
extern void hsem_releaselock(uint8_t sem, uint8_t process);

/*
 *  システムログの低レベル出力のための文字出力
 *
 *  ターゲット依存の方法で，文字cを表示/出力/保存する．
 */
extern void	target_fput_log(int8_t c);

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  サポートするシリアルポートの数
 */
#define TNUM_PORT        TNUM_SIOP

/*
 *  ログタスクが使用するポートID
 */
#define LOGTASK_PORTID   SIO_PORTID

/*
 *  ボーレート
 */
#define BPS_SETTING		(115200)

/*
 *  システムログタスク関連の定数の定義
 *
 *  デフォルト値の通り．
 */

#endif /* TOPPERS_TARGET_SYSSVC_H */
