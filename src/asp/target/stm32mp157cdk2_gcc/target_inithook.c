/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2016-2016 by 3rd Designing Center
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
 *  @(#) $Id: target_inithook.c 698 2020-08-19 13:14:09Z roi $
 */

#include <sil.h>
#include "target_syssvc.h"

/*
 *  初期化プログラム（stm32mp157c-dk2用）
 */

#define sil_orw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) | (b))
#define sil_andw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) & ~(b))
#define sil_modw_mem(a, b, c)	sil_wrw_mem((a), (sil_rew_mem(a) & (~b)) | (c))

#define HSE_TIMEOUT_VALUE   (HSE_STARTUP_TIMEOUT*1000)
#define HSI_TIMEOUT_VALUE   (100*1000U)  /* 100 ms */
#define DBP_TIMEOUT_VALUE   (100*1000)
#define LSE_TIMEOUT_VALUE   (5000*1000)
#define PLL_TIMEOUT_VALUE   (100*1000U)  /* 100 ms */
#define CLOCKSWITCH_TIMEOUT_VALUE   (1000*1000U) /* 1 s    */

/*
 *  CORTEX PREEMPTION PRIORTY GROUP定義
 */
#define NVIC_PRIORITYGROUP_0    0x00000007	/* 0 bits for pre-emption priority 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1    0x00000006	/* 1 bits for pre-emption priority 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2    0x00000005	/* 2 bits for pre-emption priority 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3    0x00000004	/* 3 bits for pre-emption priority 1 bits for subpriority */
#define NVIC_PRIORITYGROUP_4    0x00000003	/* 4 bits for pre-emption priority 0 bits for subpriority */

/*
 *  PLL設定値
 */
#define PLL12_CLOCKSOURCE   RCC_PLL12SOURCE_HSE
#define PLL_M               3
#define PLL_N               81
#define PLL_P               1
#define PLL_Q               1
#define PLL_R               1
#define PLL_FRACV           0x800

#define PLL2_M              3
#define PLL2_N              66
#define PLL2_P              2
#define PLL2_Q              1
#define PLL2_R              1
#define PLL2_FRACV          0x1400

#define PLL3_CLOCKSOURCE    RCC_PLL3SOURCE_HSE
#define PLL3_M              2
#define PLL3_N              34
#define PLL3_P              2
#define PLL3_Q              17
#define PLL3_R              37
#define PLL3_RGE            RCC_PLL3CFGR1_IFRGE_1
#define PLL3_FRACV          0x1A04

#define PLL4_CLOCKSOURCE    RCC_PLL4SOURCE_HSE
#define PLL4_M              4
#define PLL4_N              99
#define PLL4_P              6
#define PLL4_Q              8
#define PLL4_R              8
#define PLL4_RGE            RCC_PLL4CFGR1_IFRGE_0

/*
 *  クロック設定値
 */
#define MPU_CLOCK           RCC_MPUSOURCE_PLL1
#define AXI_CLOCK           RCC_AXISSOURCE_PLL2
#define AXI_DIV             RCC_AXI_DIV1
#define MCU_CLOCK           RCC_MCUSSOURCE_PLL3
#define MCU_DIV             RCC_MCU_DIV1
#define APB1_DIV            RCC_APB1_DIV2
#define	APB2_DIV            RCC_APB2_DIV2
#define APB3_DIV            RCC_APB3_DIV2
#define APB4_DIV            RCC_APB4_DIV2
#define APB5_DIV            RCC_APB5_DIV4

#define HSICALIBRATIONVAL   16
#define HSI_DIV_VALUE       RCC_HSI_DIV1

#define PLL1_DIVIEREN       (RCC_PLL1CR_DIVPEN | RCC_PLL1CR_DIVQEN | RCC_PLL1CR_DIVREN)
#define PLL2_DIVIEREN       (RCC_PLL2CR_DIVPEN | RCC_PLL2CR_DIVQEN | RCC_PLL2CR_DIVREN)
#define PLL3_DIVIEREN       (RCC_PLL3CR_DIVPEN | RCC_PLL3CR_DIVQEN | RCC_PLL3CR_DIVREN)
#define PLL4_DIVIEREN       (RCC_PLL4CR_DIVPEN | RCC_PLL4CR_DIVQEN | RCC_PLL4CR_DIVREN)

/*
 *  RCC UART78 CLOCK SOURCE定義
 */
#define RCC_UART78CLKSOURCE_PCLK1   RCC_UART78CKSELR_UART78SRC_0
#define RCC_UART78CLKSOURCE_PLL4    RCC_UART78CKSELR_UART78SRC_1
#define RCC_UART78CLKSOURCE_HSI     RCC_UART78CKSELR_UART78SRC_2
#define RCC_UART78CLKSOURCE_CSI     RCC_UART78CKSELR_UART78SRC_3
#define RCC_UART78CLKSOURCE_HSE     RCC_UART78CKSELR_UART78SRC_4

/*
 *  RCC LSEDRIVE CONFIG定義
 */
#define RCC_LSEDRIVE_LOW        RCC_BDCR_LSEDRV_0	/* LSE low drive capability */
#define RCC_LSEDRIVE_MEDIUMLOW  RCC_BDCR_LSEDRV_1	/* LSE medium low drive capability */
#define RCC_LSEDRIVE_MEDIUMHIGH RCC_BDCR_LSEDRV_2	/* LSE medium high drive capability */
#define RCC_LSEDRIVE_HIGH       RCC_BDCR_LSEDRV_3	/* LSE high drive capability */


#ifndef TOPPERS_RAM_EXEC
/*
 *  HSE使用中判定
 */
static int is_hse_in_use(void)
{
	if((getMPUsource() == RCC_MPUSOURCE_HSI) && getMPUsourcerdy())
		return 1;
	else if((getAXISsource() == RCC_AXISSOURCE_HSI) && getAXISsourcerdy())
		return 1;
	else if((getMCUsource() == RCC_MCUSSOURCE_HSI) && getMCUSsourcerdy())
		return 1;
	else if((getPLL12source() == RCC_PLL12SOURCE_HSI) && (getPLL1rdy() || getPLL2rdy()))
		return 1;
	else if((getPLL3source() == RCC_PLL3SOURCE_HSI) && getPLL3rdy())
		return 1;
	else if((getPLL4source() == RCC_PLL4SOURCE_HSI) && getPLL4rdy())
		return 1;
	else
		return 0;
}

/*
 *  HSI使用中判定
 */
static int is_hsi_in_use(void)
{
	if((getMPUsource() == RCC_MPUSOURCE_HSI) && getMPUsourcerdy())
		return 1;
	else if((getAXISsource() == RCC_AXISSOURCE_HSI) && getAXISsourcerdy())
		return 1;
	else if((getMCUsource() == RCC_MCUSSOURCE_HSI) && getMCUSsourcerdy())
		return 1;
	else if((getPLL12source() == RCC_PLL12SOURCE_HSI) && (getPLL1rdy() || getPLL2rdy()))
		return 1;
	else if((getPLL3source() == RCC_PLL3SOURCE_HSI) && getPLL3rdy())
		return 1;
	else if((getPLL4source() == RCC_PLL4SOURCE_HSI) && getPLL4rdy())
		return 1;
	else
		return 0;
}

/*
 *  システムOSCILLATOR設定
 */
int SystemOscConfig(void)
{
	uint32_t tick = 0;

	/*
	 *  HSEクロック設定、設定済ならばスキップ
	 */
	if(is_hse_in_use()){
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCRDYR)) & RCC_OCRDYR_HSERDY) != 0){
			return -1;
		}
	}
	else{

		/*
		 *  HSE停止
		 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCENCLRR), RCC_OCENCLRR_HSEON);

		/*
		 *  HSEクロック停止待ち
		 */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCRDYR)) & RCC_OCRDYR_HSERDY) != 0){
			if ( ++tick > HSE_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}

		/*
		 *  モード設定ビットクリア
		 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCENCLRR), (RCC_OCENCLRR_DIGBYP | RCC_OCENSETR_HSEBYP));

		/*
		 *  HSEをRCC_HSE_BYPASS_DIGモードに設定
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCENSETR), RCC_OCENCLRR_DIGBYP);
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCENSETR), RCC_OCENSETR_HSEBYP);

		/*
		 *  OSCILLATOR有効化
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCENSETR), RCC_OCENSETR_HSEON);

		/*
		 *  HSEクロック開始待ち
		 */
		tick = 0;
		while ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCRDYR)) & RCC_OCRDYR_HSERDY) == 0){
			if ( ++tick > HSE_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}
	}

	/*
	 *  HSIクロック設定、使用中ならばスキップ
	 */
	if(is_hsi_in_use()){
		/*
		 *  HSIキャリブレーション値設定
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_HSICFGR), RCC_HSICFGR_HSITRIM, \
                            (HSICALIBRATIONVAL << HSICFGR_HSITRIM_SHIFT));

		/* It is not allowed to change HSIDIV if HSI is currently used as
		 * reference clock for a PLL
		 */
		if(((getPLL12source() != RCC_PLL12SOURCE_HSI) || ((!getPLL1rdy()) && ((!getPLL2rdy())))) &&
			((getPLL3source() != RCC_PLL3SOURCE_HSI) || (!getPLL3rdy())) &&
			((getPLL4source() != RCC_PLL4SOURCE_HSI) || (!getPLL4rdy()))){

			/*
			 *  HSI Divied値更新
			 */
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_HSICFGR), RCC_HSICFGR_HSIDIV, HSI_DIV_VALUE);

			/*
			 *  HSI Dividerレディ待ち
			 */
			tick = 0;
			while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCRDYR)) & RCC_OCRDYR_HSIDIVRDY) == 0){
				if( ++tick > HSI_TIMEOUT_VALUE){
					return -2;
				}
				sil_dly_nse(1000);
			}
		}
	}
	else{
		/*
		 *  HSI(Internal High Speed oscillator)有効化
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCENSETR), RCC_OCENSETR_HSION);

		/*
		 *  HSIレディ待ち
		 */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCRDYR)) & RCC_OCRDYR_HSIRDY) == 0){
			if(++tick > HSI_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}

		/*
		 *  HSI Divied値更新
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_HSICFGR), RCC_HSICFGR_HSIDIV, HSI_DIV_VALUE);

		/*
		 *  HSI Dividerレディ待ち
		 */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCRDYR)) & RCC_OCRDYR_HSIDIVRDY) == 0){
			if(++tick > HSI_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}

		/*
		 *  HSIキャリブレーション値設定
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_HSICFGR), RCC_HSICFGR_HSITRIM, \
                            (HSICALIBRATIONVAL << HSICFGR_HSITRIM_SHIFT));
    }

	/*
	 *  LSEクロック設定
	 */
	/*
	 *  バックアップドメイン ライトアクセス設定
	 */
	sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_DBP);

	/*
	 *  バックアップ・ドメイン ライトプロテクション無効化待ち
	 */
	tick = 0;
	while ((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_DBP) == 0){
		if ( ++tick > DBP_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  LSEクロック停止
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_LSEON);

	/*
	 *  LSEクロック停止待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR)) & RCC_BDCR_LSERDY) != 0){
		if ( ++tick > LSE_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  BDCR LSEBYP/DIGBYPビットオフ
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), (RCC_BDCR_LSEBYP | RCC_BDCR_DIGBYP));

	/*
	 *  LSE有効化設定
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_LSEON);

	/*
	 *  LSEクロックレディ待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR)) & RCC_BDCR_LSERDY) == 0){
		if( ++tick > LSE_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  PLL1,2,3,4の設定
	 */
	/*
	 *  PLL1設定:PLL1使用チェック、使用中ならばスキップ
	 */
	if(!((getMPUsource() == RCC_MPUSOURCE_PLL1) && getMPUsourcerdy()) || \
		((getMPUsource() == RCC_MPUSOURCE_MPUDIV) && getMPUsourcerdy()) ){

		/*
		 *  DIVIER、PLL1を停止
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1CR), PLL1_DIVIEREN);
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1CR), RCC_PLL1CR_PLLON);

		/*
		 *  PLL1停止待ち
		 */
		tick = 0;
		while ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1CR)) & RCC_PLL1CR_PLL1RDY) != 0){
			if( ++tick > PLL_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}

		/*
		 *  PLL2が使用中かの確認、未使用ならクロックソース設定
		 */
		if(!((getAXISsource() == RCC_AXISSOURCE_PLL2) && getAXISsourcerdy())){
			/*
			 *  PLL1,PLL2クロックソース設定
			 */
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_RCK12SELR), RCC_RCK12SELR_PLL12SRC, PLL12_CLOCKSOURCE);
		}

		/*
		 *  PLL12ソースレディ待ち
		 */
		tick = 0;
		while ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_RCK12SELR)) & RCC_RCK12SELR_PLL12SRCRDY) == 0){
			if( ++tick > PLL_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}

		/*
		 *  PLL1分周ファクター設定
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1CFGR1), (RCC_PLL1CFGR1_DIVN | RCC_PLL1CFGR1_DIVM1), \
			((PLL_N - 1U) | ((PLL_M - 1U) << 16U)));
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1CFGR2), (RCC_PLL1CFGR2_DIVP | RCC_PLL1CFGR2_DIVQ | RCC_PLL1CFGR2_DIVR), \
			((PLL_P - 1U) | ((PLL_Q - 1U) <<8U ) | ((PLL_R - 1U) <<16U)));

		/*
		 *  PLL1 FRACTIONAL DIVIER設定
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1FRACR), RCC_PLL1FRACR_FRACLE);	/* 無効化 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1FRACR), RCC_PLL1FRACR_FRACV, (PLL_FRACV << PLLFRACR_FRACV_SHIFT));
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1FRACR), RCC_PLL1FRACR_FRACLE);	/* 有効化 */

		/*
		 *  PLL1 Spectrum Clock Generator無効化
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1CR), RCC_PLL1CR_SSCG_CTRL);

		/*
		 *  PLL1有効化
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1CR), RCC_PLL1CR_PLLON);

		/*
		 *  PLL1開始待ち
		 */
		tick = 0;
		while ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1CR)) & RCC_PLL1CR_PLL1RDY) == 0){
			if(++tick > PLL_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}

		/*
		 *  PLL1 DIVIER有効化
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1CR), PLL1_DIVIEREN);
	}

	/*
	 *  PLL2設定:PLL2使用チェック、使用中ならばスキップ
	 */
	if(!((getAXISsource() == RCC_AXISSOURCE_PLL2) && getAXISsourcerdy())){

		/*
		 *  DIVIER、PLL2を停止
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CR), PLL2_DIVIEREN);
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CR), RCC_PLL2CR_PLLON);

		/*
		 *  PLL2停止待ち
		 */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CR)) & RCC_PLL2CR_PLL2RDY) != 0){
			if ( ++tick > PLL_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}

		/*
		 *  PLL1が使用中かの確認、未使用ならクロックソース設定
		 */
		if(!((getMPUsource() == RCC_MPUSOURCE_PLL1) && getMPUsourcerdy()) || \
			((getMPUsource() == RCC_MPUSOURCE_MPUDIV) && getMPUsourcerdy()) ){
			/*
			 *  PLL1,PLL2クロックソース設定
			 */
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_RCK12SELR), RCC_RCK12SELR_PLL12SRC, PLL12_CLOCKSOURCE);
		}

		/*
		 *  PLL2分周ファクター設定
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CFGR1), (RCC_PLL2CFGR1_DIVN | RCC_PLL2CFGR1_DIVM2), \
			((PLL2_N - 1U) | ((PLL2_M - 1U) << 16U)));
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CFGR2), (RCC_PLL2CFGR2_DIVP | RCC_PLL2CFGR2_DIVQ | RCC_PLL2CFGR2_DIVR), \
			((PLL2_P - 1U) | ((PLL2_Q - 1U) << 8U) | ((PLL2_R - 1U) << 16U)));

		/*
		 *  PLL2 FRACTIONAL DIVIER設定
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2FRACR), RCC_PLL2FRACR_FRACLE);	/* 無効化 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2FRACR), RCC_PLL2FRACR_FRACV, (PLL2_FRACV << PLLFRACR_FRACV_SHIFT));
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2FRACR), RCC_PLL2FRACR_FRACLE);	/* 有効化 */

		/*
		 *  PLL2 Spread Spectrum Clock Generator無効化
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CR), RCC_PLL2CR_SSCG_CTRL);

		/*
		 *  PLL2有効化
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CR), RCC_PLL2CR_PLLON);

		/*
		 *  PLL2開始待ち
		 */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CR)) & RCC_PLL2CR_PLL2RDY) == 0){
			if ( ++tick > PLL_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}

		/*
		 *  PLL2 DIVIER有効化
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CR), PLL2_DIVIEREN);
	}

	/*
	 *  PLL3設定:PLL3使用チェック、使用中ならばスキップ
	 */
	if(!((getMCUsource() == RCC_MCUSSOURCE_PLL3) && getMCUSsourcerdy())){

		/*
		 *  DIVIER、PLL3を停止
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CR), PLL3_DIVIEREN);
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CR), RCC_PLL3CR_PLLON);

		/*
		 *  PLL3停止待ち
		 */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CR)) & RCC_PLL3CR_PLL3RDY) != 0){
			if ( ++tick > PLL_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}

		/*
		 *  PLL3クロックソース設定
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_RCK3SELR), RCC_RCK3SELR_PLL3SRC, PLL3_CLOCKSOURCE);

		/*
		 *  PLL3クロック開始待ち
		 */
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_RCK3SELR)) & RCC_RCK3SELR_PLL3SRCRDY) == 0){
			if ( ++tick > PLL_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}

		/*
		 *  PLL3入力参照周波数レンジ設定
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CFGR1), RCC_PLL3CFGR1_IFRGE, PLL3_RGE);

		/*
		 *  PLL3分周ファクター設定
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CFGR1), (RCC_PLL3CFGR1_DIVN | RCC_PLL3CFGR1_DIVM3), \
			((PLL3_N - 1U) | ((PLL3_M - 1U) << 16U)));
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CFGR2), (RCC_PLL3CFGR2_DIVP | RCC_PLL3CFGR2_DIVQ | RCC_PLL3CFGR2_DIVR), \
			((PLL3_P - 1U) | ((PLL3_Q - 1U) <<8U) | ( (PLL3_R - 1U) <<16U)));

		/*
		 *  PLL3 FRACTIONAL DIVIER設定
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3FRACR), RCC_PLL3FRACR_FRACLE);	/* 無効化 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3FRACR), RCC_PLL3FRACR_FRACV, (PLL3_FRACV << PLLFRACR_FRACV_SHIFT));
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3FRACR), RCC_PLL3FRACR_FRACLE);	/* 有効化 */

		/*
		 *  PLL3 Spread Spectrum Clock Generator無効化
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CR), RCC_PLL3CR_SSCG_CTRL);

		/*
		 *  PLL3有効化
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CR), RCC_PLL3CR_PLLON);

		/*
		 *  PLL3開始待ち
		 */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CR)) & RCC_PLL3CR_PLL3RDY) == 0){
			if ( ++tick > PLL_TIMEOUT_VALUE){
				return -2;
			}
			sil_dly_nse(1000);
		}

		/*
		 *  PLL3 DIVIER有効化
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CR), PLL3_DIVIEREN);
	}

	/*
	 *  PLL4設定:INTEGERモード
	 */
	/*
	 *  DIVIER、PLL4を停止
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CR), PLL4_DIVIEREN);
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CR), RCC_PLL4CR_PLLON);

	/*
	 *  PLL4停止待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CR)) & RCC_PLL4CR_PLL4RDY) != 0){
		if ( ++tick > PLL_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  PLL4クロックソース設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_RCK4SELR), RCC_RCK4SELR_PLL4SRC, PLL4_CLOCKSOURCE);

	/*
	 *  PLL4クロック開始待ち
	 */
	while ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_RCK4SELR)) & RCC_RCK4SELR_PLL4SRCRDY) == 0){
		if ( ++tick > PLL_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  PLL4入力参照周波数レンジ設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CFGR1), RCC_PLL4CFGR1_IFRGE, PLL4_RGE);

	/*
	 *  PLL4分周ファクター設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CFGR1), (RCC_PLL4CFGR1_DIVN | RCC_PLL4CFGR1_DIVM4), \
		((PLL4_N - 1U) | ( (PLL4_M - 1U) << 16U)));
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CFGR2), (RCC_PLL4CFGR2_DIVP | RCC_PLL4CFGR2_DIVQ | RCC_PLL4CFGR2_DIVR), \
		((PLL4_P - 1U) | ( (PLL4_Q - 1U) <<8U ) | ((PLL4_R - 1U) <<16U)));

	/*
	 *  PLL4 ファンクショナル・デバイダー設定
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4FRACR), RCC_PLL4FRACR_FRACLE);	/* 無効化 */
	/*
	 *  ファンクショナル・デバイダーを使用しないためゼロ設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4FRACR), RCC_PLL4FRACR_FRACV, 0 << PLLFRACR_FRACV_SHIFT);
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4FRACR), RCC_PLL4FRACR_FRACLE);	/* 有効化 */

	/*
	 *  PLL4 Spread Spectrum Clock Generator無効化
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CR), RCC_PLL4CR_SSCG_CTRL);

	/*
	 *  PLL4有効化
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CR), RCC_PLL4CR_PLLON);

	/*
	 *  PLL4開始待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CR)) & RCC_PLL4CR_PLL4RDY) == 0){
		if ( ++tick > PLL_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  PLL4 DIVIER有効化
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CR), PLL4_DIVIEREN);
	return 0;
}

/*
 *  システム・クロック設定
 */
int SystemClockConfig(void)
{
	uint32_t tick = 0;

	/*
	 *  MPUクロックソース設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MPCKSELR), RCC_MPCKSELR_MPUSRC , MPU_CLOCK);

	/*
	 *  MPUクロックソース設定レディ待ち
	 */
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MPCKSELR)) & RCC_MPCKSELR_MPUSRCRDY) == 0){
		if (++tick > CLOCKSWITCH_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  AXISSブロッククロックソース設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ASSCKSELR), RCC_ASSCKSELR_AXISSRC, AXI_CLOCK);

	/*
	 *  AXISSブロッククロックソース設定レディ待ち
	 */
	tick = 0;
	while ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ASSCKSELR)) & RCC_ASSCKSELR_AXISSRCRDY) == 0){
		if ( ++tick > CLOCKSWITCH_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  AXISSブロックデバイダー設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AXIDIVR), RCC_AXIDIVR_AXIDIV, AXI_DIV);

	/*
	 *  AXISSブロックデバイダー設定レディ待ち
	 */
	tick = 0;
	while ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AXIDIVR)) & RCC_AXIDIVR_AXIDIVRDY) == 0){
		if ( ++tick > CLOCKSWITCH_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  MCUブロッククロックソース設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MSSCKSELR), RCC_MSSCKSELR_MCUSSRC, MCU_CLOCK);

	/*
	 *  MCUブロッククロックソース設定レディ待ち
	 */
	tick = 0;
	while ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MSSCKSELR)) & RCC_MSSCKSELR_MCUSSRCRDY) == 0){
		if ( ++tick > CLOCKSWITCH_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  MCUデバイダーを更新
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MCUDIVR), RCC_MCUDIVR_MCUDIV , MCU_DIV);

	/*
	 *  MCUデバイダーレディ待ち
	 */
	tick = 0;
	while ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MCUDIVR)) & RCC_MCUDIVR_MCUDIVRDY) == 0){
		if ( ++tick > CLOCKSWITCH_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  APB4デバイダー更新
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB4DIVR), RCC_APB4DIVR_APB4DIV, APB4_DIV);

	/*
	 *  APB4デバイダーレディ待ち
	 */
    tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB4DIVR)) & RCC_APB4DIVR_APB4DIVRDY) == 0){
		if ( ++tick > CLOCKSWITCH_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  APB5デバイダー更新
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB5DIVR), RCC_APB5DIVR_APB5DIV , APB5_DIV);

	/*
	 *  APB5デバイダーレディ待ち
	 */
    tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB5DIVR)) & RCC_APB5DIVR_APB5DIVRDY) == 0){
		if ( ++tick > CLOCKSWITCH_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  APB1デバイダー更新
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1DIVR), RCC_APB1DIVR_APB1DIV, APB1_DIV);

	/*
	 *  APB1デバイダーレディ待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1DIVR)) & RCC_APB1DIVR_APB1DIVRDY) == 0){
		if ( ++tick > CLOCKSWITCH_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  APB2デバイダー更新
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB2DIVR), RCC_APB2DIVR_APB2DIV, APB2_DIV);

	/*
	 *  APB2デバイダーレディ待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB2DIVR)) & RCC_APB2DIVR_APB2DIVRDY) == 0){
		if ( ++tick > CLOCKSWITCH_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}

	/*
	 *  APB3デバイダー更新
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB3DIVR), RCC_APB3DIVR_APB3DIV , APB3_DIV);

	/*
	 *  APB3デバイダーレディ待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB3DIVR)) & RCC_APB3DIVR_APB3DIVRDY) == 0){
		if ( ++tick > CLOCKSWITCH_TIMEOUT_VALUE){
			return -2;
		}
		sil_dly_nse(1000);
	}
	return 0;
}
#endif


/*
 *  低レベルのターゲット依存の初期化
 *
 *  スタートアップモジュールの中で，メモリの初期化の前に呼び出される．
 */
void
hardware_init_hook(void)
{
	uint32_t tmp;

	/*
	 *  EXTI割込み、イベントのクリア
	 */
	sil_wrw_mem((uint32_t *)(TADR_EXTI_C2_BASE+TOFF_EXTI_C_IMR1), 0);
	sil_wrw_mem((uint32_t *)(TADR_EXTI_C2_BASE+TOFF_EXTI_C_IMR2), 0);
	sil_wrw_mem((uint32_t *)(TADR_EXTI_C2_BASE+TOFF_EXTI_C_IMR3), 0);
	sil_wrw_mem((uint32_t *)(TADR_EXTI_C2_BASE+TOFF_EXTI_C_EMR1), 0);
	sil_wrw_mem((uint32_t *)(TADR_EXTI_C2_BASE+TOFF_EXTI_C_EMR2), 0);
	sil_wrw_mem((uint32_t *)(TADR_EXTI_C2_BASE+TOFF_EXTI_C_EMR3), 0);

	/*
	 *  グループ4割込み優先度設定
	 */
	tmp  = sil_rew_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_AIRCR));
	tmp &= ~((uint32_t)(SCB_AIRCR_VECTKEY_Msk | SCB_AIRCR_PRIGROUP_Msk)); /* clear bits to change               */
	tmp |=  ((uint32_t)0x5FAUL << SCB_AIRCR_VECTKEY_Pos) |
            (NVIC_PRIORITYGROUP_4 << SCB_AIRCR_PRIGROUP_Pos);  /* Insert write key and priority group */
	sil_wrw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_AIRCR), tmp);

#ifndef TOPPERS_RAM_EXEC
	if(target_get_bootmode() == SYSCFG_BOOTR_BOOT2){
		/*
		 *  LSEドライブキャパシティ設定
		 */
		sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_DBP);
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_LSEDRV, RCC_LSEDRIVE_MEDIUMHIGH);

		/*
		 *  システムOSCILLATOR設定
		 */
		if(SystemOscConfig() != 0){
			for(;;){}
		}

		/*
		 *  システムクロック設定
		 */
		if (SystemClockConfig() != 0){
			for(;;){}
		}

		/*
		 *  HSEからRTCクロック生成用のデバイドファクター設定
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_RTCDIVR), RCC_RTCDIVR_RTCDIV, (24-1));
	}
#endif

	/*
	 *  ハードウェアセマフォクロック設定
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MC_AHB3ENSETR), RCC_MC_AHB3ENSETR_HSEMEN);

	/*
	 *  GPIOクロック設定
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MP_AHB4ENSETR), RCC_MC_AHB4ENSETR_GPIOHEN);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MP_AHB4ENSETR), RCC_MC_AHB4ENSETR_GPIODEN);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MP_AHB4ENSETR), RCC_MC_AHB4ENSETR_GPIOGEN);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MP_AHB4ENSETR), RCC_MC_AHB4ENSETR_GPIOBEN);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MP_AHB4ENSETR), RCC_MC_AHB4ENSETR_GPIOFEN);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MP_AHB4ENSETR), RCC_MC_AHB4ENSETR_GPIOCEN);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MP_AHB4ENSETR), RCC_MC_AHB4ENSETR_GPIOEEN);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MP_AHB4ENSETR), RCC_MC_AHB4ENSETR_GPIOAEN);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MP_AHB4ENSETR), RCC_MC_AHB4ENSETR_GPIOIEN);

#ifndef TOPPERS_RAM_EXEC
	/*
	 * UART7クロックソース設定
	 */
	if(target_get_bootmode() == SYSCFG_BOOTR_BOOT2){
		/*
		 *  UART78クロック設定
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_UART78CKSELR), RCC_UART78CKSELR_UART78SRC, RCC_UART78CLKSOURCE_HSI);
	}
#endif
}

