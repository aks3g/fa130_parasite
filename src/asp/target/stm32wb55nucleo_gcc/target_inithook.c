/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2017-2019 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: target_inithook.c 698 2020-08-08 16:13:53Z roi $
 */

#include "target_syssvc.h"

/*
 *  初期化プログラム（stm32wb55-nucleo用）
 */

#define sil_modw_mem(addr, mask, val)	sil_wrw_mem((addr), ((sil_rew_mem(addr) & ~(mask)) | (val)))
#define sil_andw_mem(addr, mask)		sil_wrw_mem((addr), (sil_rew_mem(addr) & ~(mask)))
#define sil_orw_mem(addr, val)			sil_wrw_mem((addr), (sil_rew_mem(addr) | (val)))

#if !defined(MSI_RANGE)
#define MSI_RANGE                  0
#endif

/*
 *  RCCレジスタシフト定義
 */
#define HSECR_HSETUNE_SHIFT        8
#define IPCC_CHFM_SHIFT            16


/*
 *  USBクロックソース定義
 */
#define RCC_USBCLKSOURCE_HSI48     0x00000000			/* HSI48 clock selected as USB clock */
#define RCC_USBCLKSOURCE_PLLSAI1   RCC_CCIPR_CLK48SEL_0	/* PLLSAI1 "Q" clock selected as USB clock */
#define RCC_USBCLKSOURCE_PLL       RCC_CCIPR_CLK48SEL_1	/* PLL "Q" clock selected as USB clock */
#define RCC_USBCLKSOURCE_MSI       RCC_CCIPR_CLK48SEL	/* MSI clock selected as USB clock */

/*
 *  IPCC_EC Channel定義
 */
#define IPCC_CHANNEL_1             0x00000001			/* IPCC Channel 1 */
#define IPCC_CHANNEL_2             0x00000002			/* IPCC Channel 2 */
#define IPCC_CHANNEL_3             0x00000004			/* IPCC Channel 3 */
#define IPCC_CHANNEL_4             0x00000008			/* IPCC Channel 4 */
#define IPCC_CHANNEL_5             0x00000010			/* IPCC Channel 5 */
#define IPCC_CHANNEL_6             0x00000020			/* IPCC Channel 6 */

/*
 *  CRS SynchroDivider
 */
#define CRS_SYNC_DIV1             0x00000000			/* Synchro Signal not divided (default) */
#define CRS_SYNC_DIV2             CRS_CFGR_SYNCDIV_0	/* Synchro Signal divided by 2 */
#define CRS_SYNC_DIV4             CRS_CFGR_SYNCDIV_1	/* Synchro Signal divided by 4 */
#define CRS_SYNC_DIV8             (CRS_CFGR_SYNCDIV_1 | CRS_CFGR_SYNCDIV_0)	/* Synchro Signal divided by 8 */
#define CRS_SYNC_DIV16            CRS_CFGR_SYNCDIV_2	/* Synchro Signal divided by 16 */
#define CRS_SYNC_DIV32            (CRS_CFGR_SYNCDIV_2 | CRS_CFGR_SYNCDIV_0)	/* Synchro Signal divided by 32 */
#define CRS_SYNC_DIV64            (CRS_CFGR_SYNCDIV_2 | CRS_CFGR_SYNCDIV_1)	/* Synchro Signal divided by 64 */
#define CRS_SYNC_DIV128           CRS_CFGR_SYNCDIV		/* Synchro Signal divided by 128 */

/*
 *  CRS SynchroSource
 */
#define CRS_SYNC_SOURCE_GPIO       0x00000000			/* Synchro Signal source GPIO */
#define CRS_SYNC_SOURCE_LSE        CRS_CFGR_SYNCSRC_0	/* Synchro Signal source LSE */
#define CRS_SYNC_SOURCE_USB        CRS_CFGR_SYNCSRC_1	/* Synchro Signal source USB SOF (default)*/

/*
 *  CRS SynchroPolarity
 */
#define CRS_SYNC_POLARITY_RISING   0x00000000			/* Synchro Active on rising edge (default) */
#define CRS_SYNC_POLARITY_FALLING  CRS_CFGR_SYNCPOL		/* Synchro Active on falling edge */

#define CRS_ERRORLIMIT_DEFAULT     (0x00000022 << 16)	/* CRS Default Frequency error limit */
#define CRS_RELOADVALUE_DEFAULT    0x0000BB7F			/* CRS ReloadValueDefault value */

#define HSI48CALIBRATION_DEFAULT   (0x00000020 << 8)	/* CRS HSI48CalibrationDefault value */


#define HSE_CONTROL_UNLOCK_KEY     0xCAFECAFE


#define RCC_CR_RESET               (RCC_CR_PLLSAI1ON | RCC_CR_PLLON | RCC_CR_CSSON | \
									RCC_CR_HSEON | RCC_CR_HSION | RCC_CR_MSIPLLEN)

#define RCC_PLL_DEFAULT            (RCC_PLLCFGR_PLLN_4 | RCC_PLLCFGR_PLLP_1 | \
									RCC_PLLCFGR_PLLQ_0 | RCC_PLLCFGR_PLLR_0)

#define IPCC_CHANNEL_ALL           (IPCC_CHANNEL_1 | IPCC_CHANNEL_2 | IPCC_CHANNEL_3 | \
									IPCC_CHANNEL_4 | IPCC_CHANNEL_5 | IPCC_CHANNEL_6)

#define CRS_CFGR_DEFAULT           (CRS_SYNC_DIV1 | CRS_SYNC_SOURCE_USB | CRS_SYNC_POLARITY_RISING | \
									CRS_ERRORLIMIT_DEFAULT | CRS_RELOADVALUE_DEFAULT)

/*
 *  OTP領域定義
 */
typedef struct OTP_ID0_s
{
    uint8_t   bd_address[6];
    uint8_t   hse_tuning;
    uint8_t   id;
} OTP_ID0_t;

#ifndef TOPPERS_RAM_EXEC

#if MSI_RANGE == 0
/*
 *  OTP領域読み出し関数
 */
static uint8_t * OTP_Read(uint8_t id)
{
	uint8_t *p_id;

	p_id = (uint8_t*)(OTP_AREA_END_ADDR - 7) ;

	while( ((*(p_id + 7)) != id) && ( p_id != (uint8_t*)OTP_AREA_BASE)){
		p_id -= 8 ;
	}

	if((*(p_id + 7)) != id){
		p_id = 0 ;
	}
	return p_id;
}
#endif

/*
 *  低レベルのターゲット依存の初期化
 *
 *  スタートアップモジュールの中で，メモリの初期化の前に呼び出される．
 */
void hardware_init_hook(void)
{
#if MSI_RANGE == 0
	OTP_ID0_t *p_otp;
	uint32_t csr;
#endif
	uint32_t tmp;

	/* FPU settings */
#if FPU_USED == 1
	sil_orw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CPACR), (3 << (10*2)) | (3 << (11*2)));
#endif

	/*
	 *  RCCの初期化
	 */
	/*  MSION設定 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSION);

	/*  CFGRレジスタ値リセット */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), 0x00070000);

	/*  PLLSAI1ON, PLLON, HSECSSON, HSEON, HSION, MSIPLLONビットリセット */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_RESET);

	/*  LSI1 and LSI2クロッククリア */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR), (RCC_CSR_LSI2ON | RCC_CSR_LSION));

	/*  HSI48ONクロッククリア */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CRRCR), RCC_CRRCR_HSI48ON);

	/*  PLLCFGRレジスタリセット */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), RCC_PLL_DEFAULT);

	/*  PLLSAI1CFGRレジスタリセット */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLSAI1CFGR), RCC_PLL_DEFAULT);

	/*  HSEBYPビットクリア */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEBYP);

	/*  RCC割込み無効化 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CIER), 0x00000000);

#if MSI_RANGE == 0
	/*
	 *  コプロセッサ関係, RFの設定
	 */
	csr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR));

	if(((csr & RCC_CSR_PINRSTF) != 0) && ((csr & RCC_CSR_SFTRSTF) == 0)){
		/*  RTCレジスタアクセス用 */
		sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_DBP);

		/*  APB-AHBブリッジフラッシュ用 */
		sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_DBP);

		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_BDRST);
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_BDRST);
	}

	/*
	 *  IPCCのリセット
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB3ENR), RCC_AHB3ENR_IPCCEN);
	/* Delay after an RCC peripheral clock enabling */
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB3ENR));

	sil_wrw_mem((uint32_t *)(TADR_IPCC_BASE+TOFF_IPCC_C1SCR), IPCC_CHANNEL_ALL);
	sil_wrw_mem((uint32_t *)(TADR_IPCC_BASE+TOFF_IPCC_C2SCR), IPCC_CHANNEL_ALL);
	sil_orw_mem((uint32_t *)(TADR_IPCC_BASE+TOFF_IPCC_C1MR), (IPCC_CHANNEL_ALL << IPCC_CHFM_SHIFT));
	sil_orw_mem((uint32_t *)(TADR_IPCC_BASE+TOFF_IPCC_C2MR), (IPCC_CHANNEL_ALL << IPCC_CHFM_SHIFT));
	sil_orw_mem((uint32_t *)(TADR_IPCC_BASE+TOFF_IPCC_C1MR), IPCC_CHANNEL_ALL);
	sil_orw_mem((uint32_t *)(TADR_IPCC_BASE+TOFF_IPCC_C2MR), IPCC_CHANNEL_ALL);

	if((p_otp = (OTP_ID0_t *)OTP_Read(0)) != NULL){
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_HSECR), HSE_CONTROL_UNLOCK_KEY);
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_HSECR), RCC_HSECR_HSETUNE, p_otp->hse_tuning << HSECR_HSETUNE_SHIFT);
	}
#endif

	if(sysclock_change(MSI_RANGE) != 0){
		while(1){}
	}

#ifdef USE_HSI48_USB
	/*  USBクロック設定(HSI48) */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), RCC_CCIPR_CLK48SEL, RCC_USBCLKSOURCE_HSI48);

	/*  CRSクロック設定 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1), RCC_APB1ENR1_CRSEN);
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1));

	/*
	 *  CRSリセット
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1RSTR1), RCC_APB1RSTR1_CRSRST);
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1RSTR1), RCC_APB1RSTR1_CRSRST);

	/*  CRS CFGレジスタ設定 */
	sil_wrw_mem((uint32_t *)(TADR_CRS_BASE+TOFF_CRS_CFGR), CRS_CFGR_DEFAULT);

	/*  HSI48 oscillator smooth trimming */
	sil_modw_mem((uint32_t *)(TADR_CRS_BASE+TOFF_CRS_CR), CRS_CR_TRIM, HSI48CALIBRATION_DEFAULT);

	/*
	 *  CRS有効化
	 */
	sil_orw_mem((uint32_t *)(TADR_CRS_BASE+TOFF_CRS_CR), (CRS_CR_AUTOTRIMEN | CRS_CR_CEN));
#endif
	(void)(tmp);
}
#endif

