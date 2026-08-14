/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2016 by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *  Copyright (C) 2017-2020 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: target_config.c 698 2020-08-03 22:27:49Z roi $
 */

/*
 * ターゲット依存モジュール（stm32mp15xx用）
 */
#include "kernel_impl.h"

#include <sil.h>
#include "target_syssvc.h"


/*
 *  ターゲット依存の初期化
 */
void
target_initialize(void){

	uint32_t div = 0;

	/*
	 *  システムクロックを更新
	 */
	SystemFrequency = GetSystemFrequency();

	/*
	 *  PCLK1クロック周波数算出
	 */
	div = (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1DIVR)) & RCC_APB1DIVR_APB1DIV);
	if(div > RCC_APB1_DIV16)
		div = RCC_APB1_DIV16;
	SysFrePCLK1 = SystemFrequency >> div;

	/*
	 *  PCLK2クロック周波数算出
	 */
	div = (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB2DIVR)) & RCC_APB2DIVR_APB2DIV);
	if(div > RCC_APB2_DIV16)
		div = RCC_APB2_DIV16;
	SysFrePCLK2 = SystemFrequency >> div;

	/*
	 *  PCLK5クロック周波数算出
	 */
	div = (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB5DIVR)) & RCC_APB5DIVR_APB5DIV);
	if(div > RCC_APB5_DIV16)
		div = RCC_APB5_DIV16;
	SysFrePCLK5 = GetACLKFreq() >> div;

	/*
	 * チップ依存の初期化
	 */
	chip_initialize();
}

/*
 *  ターゲット依存の終了処理
 */
void
target_exit(void)
{
	/*
	 *  コア依存の終了処理
	 */
	core_terminate();

	/*
	 *  開発環境依存の終了処理
	 */
	while(1);
}

