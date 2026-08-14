/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2016-2016 by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
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
 *  @(#) $Id: target_inithook.c 698 2019-12-23 17:53:05Z roi $
 */

#include <sil.h>
#include "stm32g4xx.h"

/*
 *  初期化プログラム（stm32g474-nucleo64用）
 */

#define sil_modw_mem(addr, mask, val)	sil_wrw_mem((addr), ((sil_rew_mem(addr) & ~(mask)) | (val)))
#define sil_andw_mem(addr, mask)		sil_wrw_mem((addr), (sil_rew_mem(addr) & ~(mask)))
#define sil_orw_mem(addr, val)			sil_wrw_mem((addr), (sil_rew_mem(addr) | (val)))


#define HSE_TIMEOUT_VALUE   (100*1000)	/* 100 ms */
#define HSI_TIMEOUT_VALUE   (2*1000)	/* 2 ms (minimum Tick + 1) */
#define LSI_TIMEOUT_VALUE   (2*1000)	/* 2 ms (minimum Tick + 1) */
#define HSI48_TIMEOUT_VALUE (2*1000)	/* 2 ms (minimum Tick + 1) */
#define PLL_TIMEOUT_VALUE   (2*1000)	/* 2 ms (minimum Tick + 1) */

#define CLOCKSWITCH_TIMEOUT_VALUE  (5000*1000) /* 5 s    */


#if !defined  (HSE_VALUE)
  #define HSE_VALUE         8000000		/* Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE         16000000	/* Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

/* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N */
#define PLL_M               4
#define PLL_N               85

/* SYSCLK = PLL_VCO / PLL_P */
#define PLL_P               2

/* USB FS, SDIO and RNG Clock =  PLL_VCO / PLLQ */
#define PLL_Q               2

/* I2SCLK =  PLLVCO / PLLR */
#define PLL_R               2	/* Possible value between 2 and 7 */

#define PLLM_SHIFT          4
#define PLLN_SHIFT          8
#define PLLR_SHIFT          25
#define PPRE1_SHIFT         8
#define PPRE2_SHIFT         11

#define PLL_MASK            (RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | \
                              RCC_PLLCFGR_PLLQ | RCC_PLLCFGR_PLLR | RCC_PLLCFGR_PLLPDIV)
#define PLL_VALUE           ((RCC_PLLSOURCE_HSI) | \
                             ((PLL_M - 1) << PLLM_SHIFT) | \
                             (PLL_N << PLLN_SHIFT) | \
                             (((PLL_Q >> 1) - 1) << 21) | \
                             (((PLL_R >> 1) - 1) << PLLR_SHIFT) | \
                             (PLL_P << 27))


/*
 *  システムクロックソース定義
 */
#define RCC_SYSCLKSOURCE_HSI      RCC_CFGR_SW_HSI		/* HSI selection as system clock */
#define RCC_SYSCLKSOURCE_HSE      RCC_CFGR_SW_HSE		/* HSE selection as system clock */
#define RCC_SYSCLKSOURCE_PLLCLK   RCC_CFGR_SW_PLL		/* PLL selection as system clock */

#define RCC_PLL_SYSCLK            RCC_PLLCFGR_PLLREN	/* PLLCLK selection from main PLL */
#define RCC_HSICALIBRATION_DEFAULT 0x40	/* Default HSI calibration trimming value */

/*
 * FLASH_Latency FLASH Latency
 */ 
#define FLASH_LATENCY_0           FLASH_ACR_LATENCY_0WS		/* FLASH Zero wait state */
#define FLASH_LATENCY_1           FLASH_ACR_LATENCY_1WS		/* FLASH One wait state */
#define FLASH_LATENCY_2           FLASH_ACR_LATENCY_2WS		/* FLASH Two wait states */
#define FLASH_LATENCY_3           FLASH_ACR_LATENCY_3WS		/* FLASH Three wait states */
#define FLASH_LATENCY_4           FLASH_ACR_LATENCY_4WS		/* FLASH Four wait states */
#define FLASH_LATENCY_5           FLASH_ACR_LATENCY_5WS		/* FLASH Five wait state */
#define FLASH_LATENCY_6           FLASH_ACR_LATENCY_6WS		/* FLASH Six wait state */
#define FLASH_LATENCY_7           FLASH_ACR_LATENCY_7WS		/* FLASH Seven wait states */
#define FLASH_LATENCY_8           FLASH_ACR_LATENCY_8WS		/* FLASH Eight wait states */
#define FLASH_LATENCY_9           FLASH_ACR_LATENCY_9WS		/* FLASH Nine wait states */
#define FLASH_LATENCY_10          FLASH_ACR_LATENCY_10WS	/* FLASH Ten wait state */
#define FLASH_LATENCY_11          FLASH_ACR_LATENCY_11WS	/* FLASH Eleven wait state */
#define FLASH_LATENCY_12          FLASH_ACR_LATENCY_12WS	/* FLASH Twelve wait states */
#define FLASH_LATENCY_13          FLASH_ACR_LATENCY_13WS	/* FLASH Thirteen wait states */
#define FLASH_LATENCY_14          FLASH_ACR_LATENCY_14WS	/* FLASH Fourteen wait states */
#define FLASH_LATENCY_15          FLASH_ACR_LATENCY_15WS	/* FLASH Fifteen wait states */

#define TARGET_FLASH_LATENCY      FLASH_LATENCY_8
#define TARGET_HCLK_DIV           RCC_CFGR_HPRE_DIV1

/*
 *  PLLソース定義
 */
#define RCC_PLLSOURCE_NONE        0x00000000				/* No clock selected as PLL entry clock source  */
#define RCC_PLLSOURCE_HSI         RCC_PLLCFGR_PLLSRC_HSI	/* HSI clock selected as PLL entry clock source */
#define RCC_PLLSOURCE_HSE         RCC_PLLCFGR_PLLSRC_HSE	/* HSE clock selected as PLL entry clock source */

#define PWR_FLAG_SETTING_DELAY_US 50UL	/* Time out value for REGLPF and VOSF flags setting */


#define PWR_REGULATOR_VOLTAGE_SCALE1   PWR_CR1_VOS_0	/* Voltage scaling range 1 normal mode */
#define PWR_REGULATOR_VOLTAGE_SCALE2   PWR_CR1_VOS_1	/* Voltage scaling range 2             */

#define RCC_LPUART1CLKSOURCE_PCLK1     0x00000000U
#define RCC_LPUART1CLKSOURCE_SYSCLK    RCC_CCIPR_LPUART1SEL_0
#define RCC_LPUART1CLKSOURCE_HSI       RCC_CCIPR_LPUART1SEL_1
#define RCC_LPUART1CLKSOURCE_LSE       (RCC_CCIPR_LPUART1SEL_0 | RCC_CCIPR_LPUART1SEL_1)

#define DEFAULT_CLOCK                  170000000UL


/*
 *  CRS ErrorLimitDefault定義
 */
#define RCC_CRS_ERRORLIMIT_DEFAULT     0x00000022			/* Default Frequency error limit */

/*
 *  CRS HSI48キャリブレーション値定義
 */
#define RCC_CRS_HSI48CALIB_DEFAULT     0x00000020			/* Default Calibration HSI48 value */

/*
 *  CRSソース定義
 */
#define RCC_CRS_SYNC_SOURCE_GPIO  0x00000000				/* Synchro Signal source GPIO */
#define RCC_CRS_SYNC_SOURCE_LSE   CRS_CFGR_SYNCSRC_0		/* Synchro Signal source LSE */
#define RCC_CRS_SYNC_SOURCE_USB   CRS_CFGR_SYNCSRC_1		/* Synchro Signal source USB SOF (default)*/

/*
 *  CRS DIVIDERソース定義
 */
#define RCC_CRS_SYNC_DIV1         0x00000000				/* Synchro Signal not divided (default) */
#define RCC_CRS_SYNC_DIV2         CRS_CFGR_SYNCDIV_0		/* Synchro Signal divided by 2 */
#define RCC_CRS_SYNC_DIV4         CRS_CFGR_SYNCDIV_1		/* Synchro Signal divided by 4 */
#define RCC_CRS_SYNC_DIV8         (CRS_CFGR_SYNCDIV_1 | CRS_CFGR_SYNCDIV_0)	/* Synchro Signal divided by 8 */
#define RCC_CRS_SYNC_DIV16        CRS_CFGR_SYNCDIV_2		/* Synchro Signal divided by 16 */
#define RCC_CRS_SYNC_DIV32        (CRS_CFGR_SYNCDIV_2 | CRS_CFGR_SYNCDIV_0)	/* Synchro Signal divided by 32 */
#define RCC_CRS_SYNC_DIV64        (CRS_CFGR_SYNCDIV_2 | CRS_CFGR_SYNCDIV_1)	/* Synchro Signal divided by 64 */
#define RCC_CRS_SYNC_DIV128       CRS_CFGR_SYNCDIV			/* Synchro Signal divided by 128 */

#define get_sysclk_source()            (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS)
#define get_pll_source()               (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR)) & RCC_PLLCFGR_PLLSRC)
#define set_hsi_calibration_adjust(a)  (sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ICSCR), RCC_ICSCR_HSITRIM, (a) << 24))
#define get_flash_latency()            (sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY)
#define set_flash_latency(v)           (sil_modw_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR), FLASH_ACR_LATENCY, (v)))

/*
 *  MSIRANGE対応クロックテーブル
 */




/*
 *  最大システムクロック設定
 *  設定値は以下の通り
 *      System Clock source            = PLL (HSI)
 *            SYSCLK(Hz)               = 170000000
 *            HCLK(Hz)                 = 170000000
 *            AHB Prescaler            = 1
 *            APB1 Prescaler           = 1
 *            APB2 Prescaler           = 1
 *            HSI Frequency(Hz)        = 16000000
 *            PLL_M                    = 4
 *            PLL_N                    = 85
 *            PLL_P                    = 2
 *            PLL_Q                    = 2
 *            PLL_R                    = 2
 *            Flash Latency(WS)        = 8
 *  return  正常終了なら0を返す
 */
ER
SystemClock_Config(void)
{
	uint32_t tick = 0;
	uint32_t pllvco, pllsource, pllr, pllm;
	uint32_t pllfreq, pllcfgr, tmp;
	uint32_t wait_loop_index;

	/*
	 *  パワーレギュレータをBOOSTモードに設定
	*/
	if((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_VOS) == PWR_REGULATOR_VOLTAGE_SCALE2){
		/*
		 *  現在のVOLTAGE SCALE RANGが2の場合、RANG1-BOOSTを有効化
		 */
		sil_andw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR5), PWR_CR5_R1MODE);

		/*
		 *  VOLTAGE SCALE RANG1に設定
		 */
		sil_modw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_VOS, PWR_REGULATOR_VOLTAGE_SCALE1);

		/*
		 *  VOSFのクリア待ち
		 */
		wait_loop_index = ((PWR_FLAG_SETTING_DELAY_US * DEFAULT_CLOCK) / 1000000U) + 1U;
		while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_SR2)) & PWR_SR2_VOSF) != 0 && (wait_loop_index != 0U)){
			wait_loop_index--;
		}
		if((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_SR2)) & PWR_SR2_VOSF) != 0){
			return E_TMOUT;
		}
	}
	else{
		/*
		 *  現在のVOLTAGE SCALE RANGが1の場合、RANG1-BOOSTを有効化のみを行う
		 */
		sil_andw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR5), PWR_CR5_R1MODE);
    }

	/*
	 *  HSIクロックの起動
	 */
    tmp = get_sysclk_source();
    pllsource = get_pll_source();
    if((tmp == RCC_CFGR_SWS_PLL && pllsource == RCC_PLLSOURCE_HSI) || tmp == RCC_CFGR_SWS_HSI){
		/*
		 *  HSIクロックが動作中の場合
		 */
        set_hsi_calibration_adjust(RCC_HSICALIBRATION_DEFAULT);

	}
	else{
		/*
		 *  HSIクロックが未起動の場合
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSION);

		/*
		 *  HSIクロックのレディ待ち
		 */
        tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSIRDY) == 0){
			if(++tick > HSI_TIMEOUT_VALUE)
				return E_TMOUT;
			 sil_dly_nse(1000);
		}

		/*
		 *  HSIキャリブレーション設定
		 */
        set_hsi_calibration_adjust(RCC_HSICALIBRATION_DEFAULT);
    }

#ifdef USE_USB
	/*
	 *  HSI48有効化
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CRRCR), RCC_CRRCR_HSI48ON);

	/*
	 *  HSI48レディ待ち
	 */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CRRCR)) & RCC_CRRCR_HSI48RDY) == 0){
		if(++tick > HSI48_TIMEOUT_VALUE)
			return -1;
		sil_dly_nse(1000);
	}

	/*
	 *  CRSコンフィギュレーション
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1), RCC_APB1ENR1_CRSEN);
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1));
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1RSTR1), RCC_APB1RSTR1_CRSRST);
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1RSTR1), RCC_APB1RSTR1_CRSRST);

	/*
	 *  HSI48用CRS設定
	 */
	tmp = (RCC_CRS_SYNC_DIV1 | RCC_CRS_SYNC_SOURCE_USB);
	tmp |= (48000000 / 1000) - 1;
	tmp |= (RCC_CRS_ERRORLIMIT_DEFAULT << 16);
	sil_wrw_mem((uint32_t *)(TADR_CRS_BASE+TOFF_CRS_CFGR), tmp);

	/*
	 *  リキャブレートタイミング設定
	 */
	sil_modw_mem((uint32_t *)(TADR_CRS_BASE+TOFF_CRS_CR), CRS_CR_TRIM, (RCC_CRS_HSI48CALIB_DEFAULT << 8));

	/*
	 *  CRS有効化
	 */
	sil_orw_mem((uint32_t *)(TADR_CRS_BASE+TOFF_CRS_CR), (CRS_CR_AUTOTRIMEN | CRS_CR_CEN));

#endif

	/*
	 *  PLL設定(システムソースがPLLでない場合)
	 */
	if(get_sysclk_source() != RCC_CFGR_SWS_PLL){
		/*
		 *  PLL停止
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);

        /*
		 *  PLL停止待ち
		 */
        tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) != 0){
			if(++tick > PLL_TIMEOUT_VALUE)
				return E_TMOUT;
			sil_dly_nse(1000);
		}

        /*
		 *  PLLコンフュギュレーション設定
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), PLL_MASK, PLL_VALUE);

		/*
		 *  PLL起動と出力設定
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), RCC_PLL_SYSCLK);

        /*
		 *  PLLレディ待ち
		 */
        tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) == 0){
			if(++tick > PLL_TIMEOUT_VALUE)
				return E_TMOUT;
			sil_dly_nse(1000);
		}
	}
	else{
		/*
		 *  設定付加なので、設定値を確認する
		 */
		pllcfgr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR));
		if((pllcfgr & PLL_MASK) != PLL_VALUE)
			return E_TMOUT;
    }

	/*
	 *  現在のFLASHレイテンシィがターゲットより、小さい場合はターゲットに設定する
	 */
	if(TARGET_FLASH_LATENCY > get_flash_latency()){
		set_flash_latency(TARGET_FLASH_LATENCY);

		/*
		 *  ターゲットに変更されたかを再チェックする
		 */
		if(get_flash_latency() != TARGET_FLASH_LATENCY)
			return E_TMOUT;
	}

	/*
	 *  SYSCLKをPLLに設定
	 *  PLL_VCO = (HSE_VALUE or HSI_VALUE/ PLLM) * PLLN
	 *  SYSCLK = PLL_VCO / PLLR
	 */
	pllsource = get_pll_source();
	pllcfgr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR));
	pllm = ((pllcfgr & RCC_PLLCFGR_PLLM) >> PLLM_SHIFT) + 1;

	switch(pllsource){
	case RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source */
		pllvco = (HSE_VALUE / pllm) * ((pllcfgr & RCC_PLLCFGR_PLLN) >> PLLN_SHIFT);
		break;
	case RCC_PLLSOURCE_HSI:  /* HSI used as PLL clock source */
	default:
		pllvco = (HSI_VALUE / pllm) * ((pllcfgr & RCC_PLLCFGR_PLLN) >> PLLN_SHIFT);
		break;
	}
	pllr = (((pllcfgr & RCC_PLLCFGR_PLLR) >> PLLR_SHIFT) + 1) * 2;
	pllfreq = pllvco/pllr;

	/*
	 *  PLLクロックが80MHzより大きい場合は、DIV2をとりあえず設定
	 */
	if(pllfreq > 80000000U){
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_HPRE, RCC_CFGR_HPRE_DIV2);
	}

	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_SW, RCC_SYSCLKSOURCE_PLLCLK);

	tick = 0;
	while (get_sysclk_source() != (RCC_SYSCLKSOURCE_PLLCLK << 2)){
		if(++tick > CLOCKSWITCH_TIMEOUT_VALUE)
			return E_TMOUT;
		sil_dly_nse(1000);
	}

	/*
	 *  HCLK設定
	 */
	/*  PLLの設定を最低に落とす */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE1, RCC_CFGR_PPRE1_DIV16);
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE2, RCC_CFGR_PPRE2_DIV16);

    /*
	 *  HCLKのデバイダー設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_HPRE, TARGET_HCLK_DIV);

	/*
	 *  現在のFLASHレイテンシィがターゲットより、大きい場合はターゲットに設定する
	 */
	if (TARGET_FLASH_LATENCY < get_flash_latency()){
		set_flash_latency(TARGET_FLASH_LATENCY);

		/*
		 *  ターゲットに変更されたかを再チェックする
		 */
		tick = 0;
		while(get_flash_latency() != TARGET_FLASH_LATENCY){
			if(++tick > CLOCKSWITCH_TIMEOUT_VALUE)
				return E_TMOUT;
			sil_dly_nse(1000);
		}
	}

	/*
	 *  PCLK1,2設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE1, RCC_CFGR_PPRE1_DIV1);
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE2, RCC_CFGR_PPRE2_DIV1);
	return E_OK;
}

/*
 *  システムクロックコンフィギュレーション
 */
ER
sysclock_config(int mode)
{
	return SystemClock_Config();
}


#ifndef TOPPERS_RAM_EXEC
/*
 *  低レベルのターゲット依存の初期化
 *
 *  スタートアップモジュールの中で，メモリの初期化の前に呼び出される．
 */
void hardware_init_hook(void)
{
	/*
	 *  FPUの設定
	 */
	sil_orw_mem((uint32_t *)(TADR_SCB_BASE+TOFF_SCB_CPACR), ((3UL << 10*2)|(3UL << 11*2)));	/* set CP10 and CP11 Full Access */

	/*
	 *  PLL,システムクロックの設定
	 */
	if(SystemClock_Config() != E_OK){
		while(1){}
	}

	/*
	 *  LPUART1クロックソース設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), RCC_CCIPR_LPUART1SEL, RCC_LPUART1CLKSOURCE_PCLK1);
}
#endif

