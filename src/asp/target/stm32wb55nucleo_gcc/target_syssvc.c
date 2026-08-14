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
 *  @(#) $Id: target_syssvc.c 698 2020-09-06 11:59:10Z roi $
 */

/*
 * ターゲット依存モジュール（stm32wb55-nucleo用）
 */
#include "target_syssvc.h"

#define sil_modw_mem(addr, mask, val)	sil_wrw_mem((addr), ((sil_rew_mem(addr) & ~(mask)) | (val)))
#define sil_andw_mem(addr, mask)		sil_wrw_mem((addr), (sil_rew_mem(addr) & ~(mask)))
#define sil_orw_mem(addr, val)			sil_wrw_mem((addr), (sil_rew_mem(addr) | (val)))

#ifndef HSEM_CR_COREID_CURRENT
#define HSEM_CR_COREID_CURRENT   HSEM_CR_COREID_CPU1
#endif

#define HSE_TIMEOUT_VALUE          (100*1000)
#define HSI_TIMEOUT_VALUE          (2000U)      /* 2 ms (minimum Tick + 1U) */
#define PLL_TIMEOUT_VALUE          (2000U)      /* 2 ms (minimum Tick + 1U) */
#define MSI_TIMEOUT_VALUE          (2000U)      /* 2 ms (minimum Tick + 1U) */
#define LSI1_TIMEOUT_VALUE         (2000U)		/* 2 ms (minimum Tick + 1)   */
#define LSI2_TIMEOUT_VALUE         (3000U)		/* to be adjusted with DS    */
#define HSI48_TIMEOUT_VALUE        (2000U)		/* 2 ms (minimum Tick + 1)   */
#define RCC_LSE_TIMEOUT_VALUE      (5000000U)	/* 5 s    */
#define RCC_DBP_TIMEOUT_VALUE      (2000U)		/* 2 ms (minimum Tick + 1)  */
#define CLOCKSWITCH_TIMEOUT_VALUE  (5000000U)	/* 5 s    */
#define LATENCY_TIMEOUT_VALUE      (2000U)		/* 2 ms (minimum Tick + 1)   */
#define PRESCALER_TIMEOUT_VALUE    (2000U)		/* 2 ms (minimum Tick + 1)   */

#define PLLSOURCE_NONE             (0)
#define MEGA_HZ                    1000000		/* Division factor to convert Hz in Mhz */


#if !defined(MAX_RANGE)
#define MAX_RANGE                  6
#endif
#if !defined(RTC_CLOCK_SOURCE)
#define RTC_CLOCK_SOURCE           RCC_RTCCLKSOURCE_LSE
#endif

/*
 *  PLLクロック設定
_*/
#define PLL_M                      0		/* RCC_PLLM_DIV1 */
#define PLL_N                      32		/*  */
#define PLL_P                      4		/* RCC_PLLP_DIV5 */
#define PLL_Q                      4
#define PLL_R                      1		/* RCC_PLLR_DIV2 */

/*
 *  RCCレジスタシフト定義
 */
#define CFGR_SWS_SHIFT             2
#define MSITRIM_SHIFT              8
#define HSITRIM_SHIFT              24
#define SHDHPRE_SHIFT              0


/*
 *  FLASH_Latency設定
 */ 
#define FLASH_LATENCY_0            (FLASH_ACR_LATENCY_0WS)	/* FLASH Zero wait state   */
#define FLASH_LATENCY_1            (FLASH_ACR_LATENCY_1WS)	/* FLASH One wait state    */
#define FLASH_LATENCY_2            (FLASH_ACR_LATENCY_2WS)	/* FLASH Two wait states   */
#define FLASH_LATENCY_3            (FLASH_ACR_LATENCY_3WS)	/* FLASH Three wait states */

/*
 *  POWER Voltage scaleの定義
 */
#define PWR_REGULATOR_VOLTAGE_SCALE1 PWR_CR1_VOS_0			/* Regulator voltage output range 1 mode, typical output voltage at 1.2 V, system frequency up to 64 MHz */
#define PWR_REGULATOR_VOLTAGE_SCALE2 PWR_CR1_VOS_1			/* Regulator voltage output range 2 mode, typical output voltage at 1.0 V, system frequency up to 16 MHz */

/*
 *  RCC System Clock Sourceの定義
 */
#define RCC_SYSCLKSOURCE_MSI       0x00000000				/* MSI selection as system clock */
#define RCC_SYSCLKSOURCE_HSI       RCC_CFGR_SW_0			/* HSI selection as system clock */
#define RCC_SYSCLKSOURCE_HSE       RCC_CFGR_SW_1			/* HSE selection as system clock */
#define RCC_SYSCLKSOURCE_PLLCLK    (RCC_CFGR_SW_1 | RCC_CFGR_SW_0)	/* PLL selection as system clock */


/*
 *  RCC HCLK Dividedの定義
 */
#define RCC_HCLK_DIV1              0x00000000			/* HCLK not divided */
#define RCC_HCLK_DIV2              RCC_CFGR_PPRE1_2		/* HCLK divided by 2 */
#define RCC_HCLK_DIV4              (RCC_CFGR_PPRE1_2 | RCC_CFGR_PPRE1_0)	/* HCLK divided by 4 */
#define RCC_HCLK_DIV8              (RCC_CFGR_PPRE1_2 | RCC_CFGR_PPRE1_1)	/* HCLK divided by 8 */
#define RCC_HCLK_DIV16             (RCC_CFGR_PPRE1_2 | RCC_CFGR_PPRE1_1 | RCC_CFGR_PPRE1_0)	/* HCLK divided by 16 */

/*
 *  RCC AHB Clock Sourceの定義
 */
#define RCC_SYSCLK_DIV1            0x00000000			/* SYSCLK not divided */
#define RCC_SYSCLK_DIV2            RCC_CFGR_HPRE_3		/* SYSCLK divided by 2 */
#define RCC_SYSCLK_DIV3            RCC_CFGR_HPRE_0		/* SYSCLK divided by 3 */
#define RCC_SYSCLK_DIV4            (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_0)	/* SYSCLK divided by 4 */
#define RCC_SYSCLK_DIV5            RCC_CFGR_HPRE_1		/* SYSCLK divided by 5 */
#define RCC_SYSCLK_DIV6            (RCC_CFGR_HPRE_2 | RCC_CFGR_HPRE_0)	/* SYSCLK divided by 6 */
#define RCC_SYSCLK_DIV8            (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_1)	/* SYSCLK divided by 8 */
#define RCC_SYSCLK_DIV10           (RCC_CFGR_HPRE_2 | RCC_CFGR_HPRE_1)	/* SYSCLK divided by 10 */
#define RCC_SYSCLK_DIV16           (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_1 | RCC_CFGR_HPRE_0)	/* SYSCLK divided by 16 */
#define RCC_SYSCLK_DIV32           (RCC_CFGR_HPRE_2 | RCC_CFGR_HPRE_1 | RCC_CFGR_HPRE_0)	/* SYSCLK divided by 32 */
#define RCC_SYSCLK_DIV64           (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_2)	/* SYSCLK divided by 64 */
#define RCC_SYSCLK_DIV128          (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_2 | RCC_CFGR_HPRE_0)	/* SYSCLK divided by 128 */
#define RCC_SYSCLK_DIV256          (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_2 | RCC_CFGR_HPRE_1)	/* SYSCLK divided by 256 */
#define RCC_SYSCLK_DIV512          (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_2 | RCC_CFGR_HPRE_1 | RCC_CFGR_HPRE_0)	/* SYSCLK divided by 512 */


/*
 *  PLLクロック出力定義
 */
#define RCC_PLL_SYSCLK             RCC_PLLCFGR_PLLREN	/* PLLCLK selection from main PLL */
#define RCC_PLL_USBCLK             RCC_PLLCFGR_PLLQEN	/* PLLUSBCLK selection from main PLL */
#define RCC_PLL_RNGCLK             RCC_PLLCFGR_PLLQEN	/* PLLRNGCLK selection from main PLL */
#define RCC_PLL_SAI1CLK            RCC_PLLCFGR_PLLPEN	/* PLLSAI1CLK selection from main PLL */
#define RCC_PLL_ADCCLK             RCC_PLLCFGR_PLLPEN	/* PLLADCCLK selection from main PLL */

/*
 *  RTCクロックソース定義
 */
#define RCC_RTCCLKSOURCE_NONE      0x00000000			/* No clock used as RTC clock */
#define RCC_RTCCLKSOURCE_LSE       RCC_BDCR_RTCSEL_0	/* LSE oscillator clock used as RTC clock */
#define RCC_RTCCLKSOURCE_LSI       RCC_BDCR_RTCSEL_1	/* LSI oscillator clock used as RTC clock */
#define RCC_RTCCLKSOURCE_HSE_DIV32 RCC_BDCR_RTCSEL		/* HSE oscillator clock divided by 32 used as RTC clock */

/*
 *  USART1クロックソース定義
 */
#define RCC_USART1CLKSOURCE_PCLK2  0x00000000			/* APB2 clock selected as USART 1 clock*/
#define RCC_USART1CLKSOURCE_SYSCLK RCC_CCIPR_USART1SEL_0	/* SYSCLK clock selected as USART 1 clock*/
#define RCC_USART1CLKSOURCE_HSI    RCC_CCIPR_USART1SEL_1	/* HSI clock selected as USART 1 clock*/
#define RCC_USART1CLKSOURCE_LSE    RCC_CCIPR_USART1SEL	/* LSE clock selected as USART 1 clock*/

/*
 *  LPUART1クロックソース定義
 */
#define RCC_LPUART1CLKSOURCE_PCLK1 0x00000000			/* APB1 clock selected as LPUART 1 clock*/
#define RCC_LPUART1CLKSOURCE_SYSCLK RCC_CCIPR_LPUART1SEL_0	/* SYSCLK clock selected as LPUART 1 clock*/
#define RCC_LPUART1CLKSOURCE_HSI   RCC_CCIPR_LPUART1SEL_1	/* HSI clock selected as LPUART 1 clock*/
#define RCC_LPUART1CLKSOURCE_LSE   RCC_CCIPR_LPUART1SEL	/* LSE clock selected as LPUART 1 clock*/

/*
 *  I2Cクロックソースの定義
 */
#define RCC_I2C1CLKSOURCE_PCLK1    0x00000000			/* APB1 clock selected as I2C1 clock */
#define RCC_I2C1CLKSOURCE_SYSCLK   RCC_CCIPR_I2C1SEL_0	/* SYSCLK clock selected as I2C1 clock */
#define RCC_I2C1CLKSOURCE_HSI      RCC_CCIPR_I2C1SEL_1	/* HSI clock selected as I2C1 clock */
#define RCC_I2C3CLKSOURCE_PCLK1    0x00000000			/* APB1 clock selected as I2C3 clock */
#define RCC_I2C3CLKSOURCE_SYSCLK   RCC_CCIPR_I2C3SEL_0	/* SYSCLK clock selected as I2C3 clock */
#define RCC_I2C3CLKSOURCE_HSI      RCC_CCIPR_I2C3SEL_1	/* HSI clock selected as I2C3 clock */

/*
 *  RFWKPクロックソース定義
 */
#define RCC_RFWKPCLKSOURCE_NONE    0x00000000			/* None clock selected as RF system wakeup clock */
#define RCC_RFWKPCLKSOURCE_LSE     RCC_CSR_RFWKPSEL_0	/* LSE clock selected as RF system wakeup clock */
#define RCC_RFWKPCLKSOURCE_LSI     RCC_CSR_RFWKPSEL_1	/* LSI clock selected as RF system wakeup clock */
#define RCC_RFWKPCLKSOURCE_HSE_DIV1024 RCC_CSR_RFWKPSEL	/* HSE clock divided by 1024 selected as RF system wakeup clock */

/*
 *  SMPSクロックソース定義
 */
#define RCC_SMPSCLKSOURCE_HSI      0x00000000			/* HSI selection as smps clock */
#define RCC_SMPSCLKSOURCE_MSI      RCC_SMPSCR_SMPSSEL_0	/* MSI selection as smps clock */
#define RCC_SMPSCLKSOURCE_HSE      RCC_SMPSCR_SMPSSEL_1	/* HSE selection as smps clock */

/*
 *  SMPS Clock Division Factor
 */
#define RCC_SMPSCLKDIV_RANGE0      0x00000000			/* PLLM division factor = 0 */
#define RCC_SMPSCLKDIV_RANGE1      RCC_SMPSCR_SMPSDIV_0	/* PLLM division factor = 1 */
#define RCC_SMPSCLKDIV_RANGE2      RCC_SMPSCR_SMPSDIV_1	/* PLLM division factor = 2 */
#define RCC_SMPSCLKDIV_RANGE3      (RCC_SMPSCR_SMPSDIV_0|RCC_SMPSCR_SMPSDIV_1)	/* PLLM division factor = 3 */




#define RCC_PLL_MASK               (RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | \
									RCC_PLLCFGR_PLLP   | RCC_PLLCFGR_PLLQ | RCC_PLLCFGR_PLLR)

#define RCC_PLL_MSI                ((PLL_M<<PLLM_SHIFT) | (PLL_N<<PLLN_SHIFT) | (PLL_P<<PLLP_SHIFT) | \
									(PLL_Q<<PLLQ_SHIFT) | (PLL_R<<PLLR_SHIFT))

#define RCC_MSICALIB_DEFAULT       (0 << MSITRIM_SHIFT)
#define RCC_HSICALIB_DEFAULT       (64 << HSITRIM_SHIFT)


static const uint32_t AHBPrescTable[16] = {1, 3, 5, 1, 1, 6, 10, 32, 2, 4, 8, 16, 64, 128, 256, 512};

static const uint32_t MSIRangeTable[16] = {100000UL, 200000UL, 400000UL, 800000UL, 1000000UL, 2000000UL, \
                                   4000000UL, 8000000UL, 16000000UL, 24000000UL, 32000000UL, 48000000UL, 0UL, 0UL, 0UL, 0UL}; /* 0UL values are incorrect cases */

  /* Flash Clock source (HCLK4) range in MHz with a VCORE is range1 */
static const uint32_t FLASH_CLK_SRC_RANGE_VOS1[] = {18UL, 36UL, 54UL, 64UL};
  /* Flash Clock source (HCLK4) range in MHz with a VCORE is range2 */
static const uint32_t FLASH_CLK_SRC_RANGE_VOS2[] = {6UL, 12UL, 16UL};

#define NUM_RANGE_VOS1             (sizeof(FLASH_CLK_SRC_RANGE_VOS1)/sizeof(uint32_t))
#define NUM_RANGE_VOS2             (sizeof(FLASH_CLK_SRC_RANGE_VOS2)/sizeof(uint32_t))

uint32_t SystemFrequency;
uint8_t  current_range;


/*
 *  FLASH Latencyを設定する
 */
static int
RCC_SetFlashLatency(uint32_t latency)
{
	uint32_t tick = 0;

	/*
	 *  Latencyの設定
	 */
	sil_modw_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR), FLASH_ACR_LATENCY, latency);

    /*
	 *  Latencyの確定待ち
	 */
	while((sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY) != latency){
		if(tick > LATENCY_TIMEOUT_VALUE)
			return -1;
		tick++;
		sil_dly_nse(1000);
	}
	return 0;
}

/*
 *  MSI用のFLASH Latencyを設定する
 */
static int
RCC_SetFlashLatencyMSI(uint32_t Flash_ClkSrcFreq, uint32_t VCORE_Voltage)
{
	const uint32_t FLASH_LATENCY_RANGE[] = {FLASH_LATENCY_0, FLASH_LATENCY_1, FLASH_LATENCY_2, FLASH_LATENCY_3};
	uint32_t latency = FLASH_LATENCY_0;	/* デフォルト 0WS */
	uint32_t index;

	if(VCORE_Voltage == PWR_REGULATOR_VOLTAGE_SCALE1){
		for(index = 0 ; index < NUM_RANGE_VOS1 ; index++){
			if(Flash_ClkSrcFreq <= FLASH_CLK_SRC_RANGE_VOS1[index]){
				latency = FLASH_LATENCY_RANGE[index];
				break;
			}
		}
	}
	else{		/* PWR_REGULATOR_VOLTAGE_SCALE2 */
		for(index = 0 ; index < NUM_RANGE_VOS2 ; index++){
			if(Flash_ClkSrcFreq <= FLASH_CLK_SRC_RANGE_VOS2[index]){
				latency = FLASH_LATENCY_RANGE[index];
				break;
			}
		}
	}
	return RCC_SetFlashLatency(latency);
}


/*
 *  HSEシステムクロック設定
 *  設定値は以下の通り
 *      System Clock source            = PLL (HSE)
 *      SYSCLK(Hz)                     = 32000000
 *      HCLK(Hz)                       = 32000000
 *      AHB Prescaler                  = 1
 *      AHB2 Prescaler                 = 1
 *      AHB4 Prescaler                 = 1
 *      APB1 Prescaler                 = 1
 *      APB2 Prescaler                 = 1
 *      HSI Frequency(Hz)              = 32000000
 *      PLL                            = NONE
 *      Flash Latency(WS)              = 1
 *  return  正常終了なら0を返す
 */
static int
SystemClock_Config(void)
{
	uint32_t tick, rtcclocksource, tmp;
	int status  = 0;

	/*
     *  POWER Voltage scaleを1に設定
	 */
	sil_modw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_VOS, PWR_REGULATOR_VOLTAGE_SCALE1);
	tmp = sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1));

	/*
	 *  HSEクロック設定
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEON);

	/*  HSEクロック開始待ち */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSERDY) == 0){
		if(tick > HSE_TIMEOUT_VALUE)
			return -1;
		tick++;
		sil_dly_nse(1000);
	}
	/*
	 *  HSIクロック設定
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSION);

	/*  HSI開始待ち */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSIRDY) == 0){
		if(tick > HSI_TIMEOUT_VALUE)
			return -2;
		tick++;
		sil_dly_nse(1000);
	}

	/*  HSI calibration default設定 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ICSCR), RCC_ICSCR_HSITRIM, RCC_HSICALIB_DEFAULT);

	/*
	 *  LSEクロック設定
	 */
    if((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_DBP) == 0){
		/*  Backup domainに書込み有効化設定 */
		sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_DBP);

		/*  Backup domain 書込み有効化待ち */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_DBP) == 0){
			if(tick > RCC_DBP_TIMEOUT_VALUE)
				return -4;
			tick++;
			sil_dly_nse(1000);
		}
	}

	/*  LSEクロック設定 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_LSEON);

	/*  LSE READY待ち */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR)) & RCC_BDCR_LSERDY) == 0){
		if(tick > RCC_LSE_TIMEOUT_VALUE)
			return -5;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  LSI2クロック停止
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR), RCC_CSR_LSI2ON);

	/*  LSI2停止待ち */
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR)) & RCC_CSR_LSI2RDY) != 0){
		if(tick > LSI2_TIMEOUT_VALUE)
			return -5;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  LSI1クロック設定
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR), RCC_CSR_LSI1ON);

	/*  LSI1開始待ち */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR)) & RCC_CSR_LSI1RDY) == 0){
		if(tick > LSI1_TIMEOUT_VALUE)
			return -6;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  HSI48設定
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CRRCR), RCC_CRRCR_HSI48ON);
	tick = 0;

	/*  HSI48開始待ち */
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CRRCR)) & RCC_CRRCR_HSI48RDY) == 0){
		if(tick > HSI48_TIMEOUT_VALUE)
			return -7;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  FLASH Latencyが1未満の場合、1に設定
	 */
	if(FLASH_LATENCY_1 > (sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY)){
		if(RCC_SetFlashLatency(FLASH_LATENCY_1) != 0)
			return -8;
	}

	/*
	 *  HCLK1設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_HPRE, RCC_SYSCLK_DIV1);

	/*  HCLK1 Prescalerフラグのセットを待つ */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_HPREF) == 0){
		if(tick > PRESCALER_TIMEOUT_VALUE)
			return -9;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  HCLK2設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_EXTCFGR), RCC_EXTCFGR_C2HPRE, RCC_SYSCLK_DIV1);

    /*  HCLK2 Prescalerフラグのセットを待つ */
    tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_EXTCFGR)) & RCC_EXTCFGR_C2HPREF) == 0){
		if(tick > PRESCALER_TIMEOUT_VALUE)
			return -10;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  HCLK4設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_EXTCFGR), RCC_EXTCFGR_SHDHPRE, RCC_SYSCLK_DIV1 >> 4);

    /*  AHB Prescalerフラグのセットを待つ */
    tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_EXTCFGR)) & RCC_EXTCFGR_SHDHPREF) == 0){
		if(tick > PRESCALER_TIMEOUT_VALUE)
			return -11;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  PCLK1設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE1, RCC_HCLK_DIV1);

	/*  APB1 Prescalerフラグのセットを待つ */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_PPRE1F) == 0){
		if(tick > PRESCALER_TIMEOUT_VALUE)
			return -12;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  PCLK2設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE2, RCC_HCLK_DIV1 << 3);

	/*  APB2 Prescalerフラグのセットを待つ */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_PPRE2F) == 0){
		if(tick > PRESCALER_TIMEOUT_VALUE)
			return -13;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  SYSCLK設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_SW, RCC_SYSCLKSOURCE_HSE);

	/*  System Clock sourceの設定を待つ */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) != (RCC_SYSCLKSOURCE_HSE << CFGR_SWS_SHIFT)){
		if(tick > CLOCKSWITCH_TIMEOUT_VALUE)
			return -14;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  FLASH Latencyが1より大きい場合、1に設定
	 */
	if(FLASH_LATENCY_1 < (sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY)){
		if(RCC_SetFlashLatency(FLASH_LATENCY_1) != 0)
			return -15;
	}

	/*
	 *  設定クロックをSystemFrequencyにセット
	 */
	SystemFrequency = sysclock_init_value();

	/*
	 *  PLLクロック停止
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);

	/*  PLL出力停止 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLLSRC, PLLSOURCE_NONE);
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), (RCC_PLL_SYSCLK | RCC_PLL_USBCLK | RCC_PLL_SAI1CLK));

	/*  PLLクロック停止待ち */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) != 0){
		if(tick > PLL_TIMEOUT_VALUE)
			return -16;
		tick++;
		sil_dly_nse(1000);
	}


	/*  RTCクロック設定 */
	rtcclocksource = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR)) & RCC_BDCR_RTCSEL;
    if(rtcclocksource != RTC_CLOCK_SOURCE){
		/*  Backup domainにアクセスできるようDBPをセット */
		sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_DBP);
		if(rtcclocksource == RCC_RTCCLKSOURCE_NONE)
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_RTCSEL, RTC_CLOCK_SOURCE);
		else{
			/*
			 *  RTCのソース設定がされていなければ、Backup Domainをリセット
			 */
			uint32_t bdcr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR));
			sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_BDRST);
			sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_BDRST);
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_RTCSEL, RTC_CLOCK_SOURCE);
			sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), bdcr);
		}
	}

	/*  USART1クロック設定 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), RCC_CCIPR_USART1SEL, RCC_USART1CLKSOURCE_PCLK2);

	/*  LPUART1クロック設定 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), RCC_CCIPR_LPUART1SEL, RCC_LPUART1CLKSOURCE_PCLK1);

	/*  I2C1クロック設定(SYSCLK) */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), RCC_CCIPR_I2C1SEL, RCC_I2C1CLKSOURCE_SYSCLK);

	/*  I2C3クロック設定(HSI) */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), RCC_CCIPR_I2C3SEL, RCC_I2C3CLKSOURCE_HSI);

	/*  RFWKPクロック設定 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR), RCC_CSR_RFWKPSEL, RCC_RFWKPCLKSOURCE_LSI);

	/*  SMPSクロック設定 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_SMPSCR), RCC_SMPSCR_SMPSDIV, RCC_SMPSCLKDIV_RANGE1);
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_SMPSCR), RCC_SMPSCR_SMPSSEL, RCC_SMPSCLKSOURCE_HSE);

	(void)(tmp);
	return status;
}

/*
 *  最大システムクロック設定(rangは6)
 *  設定値は以下の通り
 *      System Clock source            = PLL (MSI)
 *      SYSCLK(Hz)                     = 64000000
 *      HCLK(Hz)                       = 64000000
 *      AHB Prescaler                  = 1
 *      AHB2 Prescaler                 = 2
 *      AHB4 Prescaler                 = 1
 *      APB1 Prescaler                 = 1
 *      APB2 Prescaler                 = 1
 *      HSI Frequency(Hz)              = 64000000
 *      PLLM                           = 0 RCC_PLLM_DIV1
 *      PLLN                           = 32
 *      PLLP                           = 4 RCC_PLLP_DIV5
 *      PLLR                           = 1 RCC_PLLR_DIV2
 *      PLLQ                           = 4
 *      Flash Latency(WS)              = 3
 *  return  正常終了なら0を返す
 */
static int
SystemClock_Config2(uint8_t range)
{
	uint32_t tick, rtcclocksource;
	int status  = 0;

	/*
	 *  MSIクロック設定
	 */
	range <<= 4;
	if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_MSIRDY) != 0){
		uint32_t flash_clksrcfreq;
		uint32_t msifreq   = MSIRangeTable[(range & RCC_CR_MSIRANGE) >> MSIRANG_SHIFT];
		uint32_t prescaler = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_EXTCFGR)) & RCC_EXTCFGR_SHDHPRE;
		uint32_t volrange  = sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_VOS;
		flash_clksrcfreq = msifreq / AHBPrescTable[prescaler >>  SHDHPRE_SHIFT];

		if(range > (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_MSIRANGE)){
	        /*
			 *  MSI Rangeが上がる場合, FLASH Latencyを上げて設定変更
			 */
			if(RCC_SetFlashLatencyMSI((flash_clksrcfreq / MEGA_HZ), volrange) != 0)
				return -1;

			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRANGE, range);
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ICSCR), RCC_ICSCR_MSITRIM, RCC_MSICALIB_DEFAULT);
		}
		else{
	        /*
			 *  MSI Rangeが下がる場合, FLASH Latencyを下げて設定変更
			 */
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRANGE, range);
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ICSCR), RCC_ICSCR_MSITRIM, RCC_MSICALIB_DEFAULT);

			if(RCC_SetFlashLatencyMSI((flash_clksrcfreq / MEGA_HZ), volrange) != 0)
				return -1;
		}
	}
	else{
		/*
		 *  MSIを有効化
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIPLLEN);

		/*  MSIが有効となるまで待つ */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_MSIRDY) == 0){
			if(tick > MSI_TIMEOUT_VALUE)
				return -1;
			tick++;
			sil_dly_nse(1000);
		}

        /*
		 *  MSIのRange設定を行い、Calibrationをデフォルト設定する
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRANGE, range);
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ICSCR), RCC_ICSCR_MSITRIM, RCC_MSICALIB_DEFAULT);
    }

	/*
	 *  HSIクロック停止
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSION);

	/*  HSIが停止するまで待つ */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSIRDY) != 0){
		if(tick > HSI_TIMEOUT_VALUE)
			return -2;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  LSI1クロック停止
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR), RCC_CSR_LSI1ON);

	/*  LSI1停止待ち */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR)) & RCC_CSR_LSI1RDY) != 0){
		if(tick > LSI1_TIMEOUT_VALUE)
			return -3;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  LSEクロック設定
	 */
    if((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_DBP) == 0){
		/*  Backup domainに書込み有効化設定 */
		sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_DBP);

		/*  Backup domain 書込み有効化待ち */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_DBP) == 0){
			if(tick > RCC_DBP_TIMEOUT_VALUE)
				return -4;
			tick++;
			sil_dly_nse(1000);
		}
	}

	/*  LSEクロック設定 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_LSEON);

	/*  LSE READY待ち */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR)) & RCC_BDCR_LSERDY) == 0){
		if(tick > RCC_LSE_TIMEOUT_VALUE)
			return -5;
		tick++;
		sil_dly_nse(1000);
	}


#ifdef USE_HSI48_USB
	/*
	 *  HSI48設定
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CRRCR), RCC_CRRCR_HSI48ON);
	tick = 0;

	/*  HSI48開始待ち */
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CRRCR)) & RCC_CRRCR_HSI48RDY) == 0){
		if(tick > HSI48_TIMEOUT_VALUE)
			return -6;
		tick++;
		sil_dly_nse(1000);
	}
#endif

	/*
	 *  PLLクロック設定
	 */
	if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) != RCC_SYSCLKSOURCE_STATUS_PLLCLK){
		/*
		 *  PLLクロック停止
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);

		/*  Ready中は待ち */
		tick = 0;
		while ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) != 0){
			if(tick > PLL_TIMEOUT_VALUE)
				return -7;
			tick++;
			sil_dly_nse(1000);
		}

        /*
		 *  PLL各クロック設定
		 */
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), RCC_PLL_MASK, (RCC_PLL_MSI | RCC_PLLSOURCE_MSI));

        /*  PLLを有効化 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);

        /*  システムクロックアウトプット設定 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), RCC_PLL_SYSCLK);

		/*  Readyになるまで待ち */
        tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) == 0){
			if(tick > PLL_TIMEOUT_VALUE)
				return -8;
			tick++;
			sil_dly_nse(1000);
		}
	}
	else{
		/*
		 *  システムクロックで使用中ならば、PLLの設定変更があればエラー
		 */
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR)) & RCC_PLL_MASK)
				!= (RCC_PLL_MSI | RCC_PLLSOURCE_MSI))
			return -9;
    }

	/*
	 *  FLASH Latencyが3未満の場合、3に設定
	 */
	if(FLASH_LATENCY_3 > (sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY)){
		if(RCC_SetFlashLatency(FLASH_LATENCY_3) != 0)
			return -10;
	}

	/*
	 *  HCLK1設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_HPRE, RCC_SYSCLK_DIV1);

	/*  HCLK1 Prescalerフラグのセットを待つ */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_HPREF) == 0){
		if(tick > PRESCALER_TIMEOUT_VALUE)
			return -11;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  HCLK2設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_EXTCFGR), RCC_EXTCFGR_C2HPRE, RCC_SYSCLK_DIV2);

    /*  HCLK2 Prescalerフラグのセットを待つ */
    tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_EXTCFGR)) & RCC_EXTCFGR_C2HPREF) == 0){
		if(tick > PRESCALER_TIMEOUT_VALUE)
			return -12;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  HCLK4設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_EXTCFGR), RCC_EXTCFGR_SHDHPRE, RCC_SYSCLK_DIV1 >> 4);

    /*  AHB Prescalerフラグのセットを待つ */
    tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_EXTCFGR)) & RCC_EXTCFGR_SHDHPREF) == 0){
		if(tick > PRESCALER_TIMEOUT_VALUE)
			return -13;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  PCLK1設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE1, RCC_HCLK_DIV1);

	/*  APB1 Prescalerフラグのセットを待つ */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_PPRE1F) == 0){
		if(tick > PRESCALER_TIMEOUT_VALUE)
			return -14;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  PCLK2設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE2, RCC_HCLK_DIV1 << 3);

	/*  APB2 Prescalerフラグのセットを待つ */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_PPRE2F) == 0){
		if(tick > PRESCALER_TIMEOUT_VALUE)
			return -15;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  SYSCLK設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_SW, RCC_SYSCLKSOURCE_PLLCLK);

	/*  System Clock source statusの一致を待つ */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) != (RCC_SYSCLKSOURCE_PLLCLK << CFGR_SWS_SHIFT)){
		if(tick > CLOCKSWITCH_TIMEOUT_VALUE)
			return -16;
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  FLASH Latencyが3より大きい場合、3に設定
	 */
	if(FLASH_LATENCY_3 < (sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY)){
		if(RCC_SetFlashLatency(FLASH_LATENCY_3) != 0)
			return -1;
	}

	/*
	 *  設定クロックをSystemFrequencyにセット
	 */
	SystemFrequency = sysclock_init_value();


	/*
	 *  HSEクロック停止
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEON);
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEBYP);

	/*  HSEの停止を待つ */
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSERDY) != 0){
		if(tick > HSE_TIMEOUT_VALUE)
			return -17;
		tick++;
		sil_dly_nse(1000);
	}

	/*  RTCクロック設定 */
	rtcclocksource = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR)) & RCC_BDCR_RTCSEL;
    if(rtcclocksource != RCC_RTCCLKSOURCE_LSE){
		/*  Backup domainにアクセスできるようDBPをセット */
		sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_DBP);

		/*
		 *  RTCのソース設定がされていなければ、Backup Domainをリセット
		 */
		if(rtcclocksource == RCC_RTCCLKSOURCE_NONE)
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_RTCSEL, RCC_RTCCLKSOURCE_LSE);
		else{
			/*
			 *  RTCのソース設定がされていなければ、Backup Domainをリセット
			 */
			uint32_t bdcr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR));
			sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_BDRST);
			sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_BDRST);
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_RTCSEL, RCC_RTCCLKSOURCE_LSE);
			sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), bdcr);
		}
	}

	/*  USART1クロック設定 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), RCC_CCIPR_USART1SEL, RCC_USART1CLKSOURCE_PCLK2);

	/*  LPUART1クロック設定 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), RCC_CCIPR_LPUART1SEL, RCC_LPUART1CLKSOURCE_PCLK1);

	/*  I2C1クロック設定(SYSCLK) */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), RCC_CCIPR_I2C1SEL, RCC_I2C1CLKSOURCE_SYSCLK);

	/*  I2C3クロック設定(HSI) */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), RCC_CCIPR_I2C3SEL, RCC_I2C3CLKSOURCE_HSI);
	return status;
}


/*
 *  システムクロックコンフィギュレーション
 */
ER
sysclock_config(int mode)
{
	if(current_range == 0 || current_range > MAX_RANGE)
		return SystemClock_Config();
	else
		return SystemClock_Config2(current_range);
}

/*
 *  起動クロックの取り出し
 */
uint32_t
sysclock_init_value(void)
{
	uint32_t pllsource;
	uint32_t sysclockfreq, pllinputfreq, msirange;
	uint32_t pllm, plln, pllr;
	const uint32_t cstatus = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS;
	uint32_t pllcfgr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR));
	msirange = MSIRangeTable[(sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_MSIRANGE) >> MSIRANG_SHIFT];

	if(cstatus == RCC_SYSCLKSOURCE_STATUS_MSI){
		/* MSI クロック System Clock設定 */
		sysclockfreq = msirange;
	}
	else if(cstatus == RCC_SYSCLKSOURCE_STATUS_HSI){
		/* HSI クロック System Clock設定 */
		sysclockfreq = HSI_VALUE;
	}
	else if(cstatus == RCC_SYSCLKSOURCE_STATUS_HSE){
		/* HSE クロック System Clock設定 */
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSEPRE) != 0)
			sysclockfreq = HSE_VALUE / 2;
		else
			sysclockfreq = HSE_VALUE;
	}
	else{
		/* PLL クロック System Clock設定 */
		pllsource = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR)) & RCC_PLLCFGR_PLLSRC;
		switch (pllsource){
		case RCC_PLLSOURCE_HSI:  /* HSI PLLクロックソース */
			pllinputfreq = HSI_VALUE;
			break;
		case RCC_PLLSOURCE_HSE:  /* HSE PLLクロックソース */
			if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSEPRE) != 0)
				pllinputfreq = HSE_VALUE / 2;
			else
				pllinputfreq = HSE_VALUE;
			break;
		case RCC_PLLSOURCE_MSI:  /* MSI PLLクロックソース */
		default:
			pllinputfreq = msirange;
			break;
		}
		pllm = (pllcfgr & RCC_PLLCFGR_PLLM) >> PLLM_SHIFT;
		plln = (pllcfgr & RCC_PLLCFGR_PLLN) >> PLLN_SHIFT;
		pllr = (pllcfgr & RCC_PLLCFGR_PLLR) >> PLLR_SHIFT;
		sysclockfreq = pllinputfreq * plln / ((pllm + 1)) / (pllr + 1);
	}
	return sysclockfreq / AHBPrescTable[((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_HPRE) >> CFGR_HPRE_SHIFT)];
}

/*
 *  システムクロック変更
 */
ER
sysclock_change(uint8_t range)
{
	current_range = range;
	return sysclock_config(0);
}


/*
 *  Hardware Semaphore初期化
 */
void
hsem_init(intptr_t exinf)
{
	uint32_t tmp;

	/*
	 *  Hardware Semaphoreクロック有効化
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB3ENR), RCC_AHB3ENR_HSEMEN);
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AHB3ENR));
	(void)(tmp);
}

/*
 *  Hardware Semaphore 1-step lock
 *  parameter1  sem: semphore番号(0-31)
 *  return 1 ロック失敗, 0 ロック成功、または、すでにロック状態
 */
uint32_t
hsem_1steplock(uint8_t sem)
{
	uint32_t sembase = TADR_HSEM_BASE + TOFF_HSEM_RLR + sem * 4;
	if(sem > 31)
		return 0;
	if(sil_rew_mem((uint32_t *)(sembase)) != (HSEM_RLR_LOCK | HSEM_CR_COREID_CURRENT))
		return 1;
	else
		return 0;
}

/*
 *  Hardware Semaphore relese the lock
 *  parameter1  sem: semaphore番号(0-31)
 *  parameter2  process: プロセス番号(0-255)
 */
void
hsem_releaselock(uint8_t sem, uint8_t process)
{
	uint32_t sembase = TADR_HSEM_BASE + TOFF_HSEM_R + sem * 4;
	if(sem > 31)
		return;
	sil_wrw_mem((uint32_t *)(sembase), (HSEM_CR_COREID_CURRENT | process));
}


