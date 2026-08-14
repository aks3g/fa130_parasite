/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2016-2020 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: target_config.h 698 2020-09-06 10:44:50Z roi $
 */

/*
 *  チップ依存モジュール（stm32wbxx用）
 *
 *  カーネルのターゲット依存部のインクルードファイル．kernel_impl.hのター
 *  ゲット依存部の位置付けとなる．
 */

#ifndef TOPPERS_CHIP_CONFIG_H
#define TOPPERS_CHIP_CONFIG_H

/*
 *  ターゲット依存部のハードウェア資源の定義
 */
#include "stm32wbxx.h"

/*
 *  RAM実行する場合やQEMU実行時ROMデバッグ時はMSPを初期化する
 *  必要があるため,スタートアップルーチンでMSPを初期化する． 
 */
#define INIT_MSP

/*
 *  デフォルトの非タスクコンテキスト用のスタック領域の定義
 */
#define DEFAULT_ISTKSZ      (0x1000U)   /* 4KByte */

/*
 *  使用するシリアルポートID
 */
#ifndef SIO_PORTID
#define SIO_PORTID		(1)
#endif /* SIO_PORTID */

/*
 *  core_support待ち処理(wfiを使用しない)
 */
#define TOPPERS_CUSTOM_IDLE
#define toppers_asm_custom_idle                           \
    ldr   r0, =0xE000ED00; /* SCBベースアドレス */        \
    ldr   r2, [r0, #TOFF_SCB_SCR]; /* SCR取り出し */      \
    bic.w r2, #SCB_SCR_SLEEPDEEP_Msk;                     \
    str   r2, [r0, #TOFF_SCB_SCR];/* SLEEPDEEPをセット */ \
    cpsid i;             /* PRIMASK をセット */           \
    msr   basepri, r4;   /* 全割込み許可 */               \
	wfi;                                                  \
    cpsie i; /* PRIMASK をクリア（割込みを受け付ける） */ \
    msr   basepri, r5;   /* CPUロック状態へ */ 


#ifndef TOPPERS_MACRO_ONLY

/*
 *  ターゲットシステム依存の初期化
 */
extern void	chip_initialize(void);

/*
 *  ターゲットシステムの終了
 *
 *  システムを終了する時に使う．
 */
extern void	chip_exit(void) NoReturn;

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  コア依存モジュール（ARM-M用）
 */
#include "core_config.h"

#endif /* TOPPERS_CHIP_CONFIG_H */
