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
 *  @(#) $Id: target_syssvc.c 698 2020-08-19 13:19:30Z roi $
 */

/*
 * ターゲット依存モジュール（stm32mp15xx用）
 */
#include <sil.h>
#include "stm32mp157xx.h"
#include "target_syssvc.h"
#include "chip_serial.h"

/*
 *  ペリフェラルアドレスからHSEN番号変換マクロ
 */
#define get_hsem_no(taddr)   (((taddr) == (TADR_GPIOA_BASE))? 0U :\
                              ((taddr) == (TADR_GPIOB_BASE))? 0U :\
                              ((taddr) == (TADR_GPIOC_BASE))? 0U :\
                              ((taddr) == (TADR_GPIOD_BASE))? 0U :\
                              ((taddr) == (TADR_GPIOE_BASE))? 0U :\
                              ((taddr) == (TADR_GPIOF_BASE))? 0U :\
                              ((taddr) == (TADR_GPIOG_BASE))? 0U :\
                              ((taddr) == (TADR_GPIOH_BASE))? 0U :\
                              ((taddr) == (TADR_GPIOI_BASE))? 0U :\
                              ((taddr) == (TADR_GPIOJ_BASE))? 0U :\
                              ((taddr) == (TADR_GPIOK_BASE))? 0U :\
                              ((taddr) == (TADR_GPIOZ_BASE))? 0U :\
                              ((taddr) == (TADR_EXTI_BASE))?  1U : HSEM_SEMID_MAX + 1U)


uint32_t SystemFrequency;
uint32_t SysFrePCLK1, SysFrePCLK2, SysFrePCLK5;

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


/*
 *  ターゲットペリフェラルハードウェアセマフォロック
 */
ER
target_periph_lock(uint32_t periph, uint32_t timeout)
{
	uint32_t tick = 0;
	uint32_t semno = get_hsem_no(periph);

	if(semno > HSEM_SEMID_MAX)
		return E_PAR;

	/*
	 *  セマフォ取得待ち
	 */
	while(hsem_1steplock(semno) != 0){
		if((timeout == 0U) || ( ++tick > timeout)){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
	}
	return E_OK;
}

/*
 *  ターゲットペリフェラルハードウェアセマフォアンロック
 */
void
target_periph_unlock(uint32_t periph)
{
	uint32_t semno = get_hsem_no(periph);

	if(semno > HSEM_SEMID_MAX)
		return;

	/*
	 *  ハードウェアセマフォ開放
	 */
	hsem_releaselock(semno, 0);
}

/*
 *  BOOTモード取得
 */
uint32_t
target_get_bootmode(void)
{
	return (sil_rew_mem((uint32_t *)(TADR_SYSCFG_BASE+TOFF_SYSCFG_BOOTR)) & (SYSCFG_BOOTR_BOOT2|SYSCFG_BOOTR_BOOT1|SYSCFG_BOOTR_BOOT0));
}


/*
 *  システム・クロック取得
 */
uint32_t
GetSystemFrequency(void)
{
	RCC_PLLClocksTypeDef pll3_clocks;
	uint32_t mcudiv = 0;
	uint32_t mcussfreq = 0;

	/*
	 *  MCUクロック周波数算出
	 */
	mcudiv = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MCUDIVR)) & RCC_MCUDIVR_MCUDIV;
	if (mcudiv > RCC_MCU_DIV512)
		mcudiv = RCC_MCU_DIV512;

	switch (getMCUsource()){
	case RCC_MCUSSOURCE_PLL3:	/* PLL3-Pクロックソース */
		GetPLL3ClockFreq(&pll3_clocks);
		mcussfreq = pll3_clocks.PLL_P_Frequency;
		break;

	case RCC_MCUSSOURCE_HSI:	/* HSIクロックソース */
		mcussfreq = (HSI_VALUE >> (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_HSICFGR)) & RCC_HSICFGR_HSIDIV));
		break;

	case RCC_MCUSSOURCE_HSE:	/* HSEクロックソース */
		mcussfreq = HSE_VALUE;
		break;

	case RCC_MCUSSOURCE_CSI:	/* CSIクロックソース */
		mcussfreq = CSI_VALUE;
		break;
	}
	return mcussfreq >> mcudiv;
}

/*
 *  ACLK取得
 */
uint32_t
GetACLKFreq(void)
{
	uint32_t axidiv = 0;
	uint32_t axissfreq = 0;
	RCC_PLLClocksTypeDef pll2_clocks;

	/*
	 *  ACLKクロック周波数算出
	 */
	axidiv = (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_AXIDIVR)) & RCC_AXIDIVR_AXIDIV);
	if(axidiv > RCC_AXI_DIV4)
		axidiv = RCC_AXI_DIV4;
	axidiv++;

	switch (getAXISsource()){
	case RCC_AXISSOURCE_PLL2:	/* PLL2-Pクロックソース */
		GetPLL2ClockFreq(&pll2_clocks);
		axissfreq = pll2_clocks.PLL_P_Frequency;
		break;

	case RCC_AXISSOURCE_HSI:	/* HSIクロックソース */
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCRDYR)) & RCC_OCRDYR_HSIDIVRDY) != 0)
			axissfreq = (HSI_VALUE >> (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_HSICFGR)) & RCC_HSICFGR_HSIDIV));
		else
			axissfreq = HSI_VALUE;
		break;

	case RCC_AXISSOURCE_HSE:	/* HSEクロックソース */
		axissfreq = HSE_VALUE;
		break;

	case RCC_AXISSOURCE_OFF:
	default:
		axissfreq = 0; /* ck_axiss is gated */
		break;
	}
	return axissfreq / axidiv;
}

/*
 *  PLL2クロック取得
  */
void
GetPLL2ClockFreq(RCC_PLLClocksTypeDef *PLL2_Clocks)
{
	uint32_t pll2m = 1U, pll2fracen = 0U, hsivalue = 0U;
	uint32_t pll2cfgr1, pll2cfgr2, pll2fracr;
	float fracn1, pll2vco = 0;

	pll2cfgr1 = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CFGR1));
	pll2fracr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2FRACR));
	pll2m = ((pll2cfgr1 & RCC_PLL2CFGR1_DIVM2) >> PLLCFGR1_DIVM2_SHIFT) + 1U;
	pll2fracen = (pll2fracr & RCC_PLL2FRACR_FRACLE) >> PLLFRACR_FRACLE_SHIFT;
	fracn1 = (float)(pll2fracen * ((pll2fracr & RCC_PLL2FRACR_FRACV) >> PLLFRACR_FRACV_SHIFT));
	pll2vco = (float)((float)((pll2cfgr1 & RCC_PLL2CFGR1_DIVN) + 1U) + (fracn1 / (float)0x1FFF));  //Intermediary value
	switch(getPLL12source()){
	case RCC_PLL12SOURCE_HSI:  /* HSIベース PLL クロックソース */
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCRDYR)) & RCC_OCRDYR_HSIDIVRDY) != 0){
			hsivalue = (HSI_VALUE >> (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_HSICFGR)) & RCC_HSICFGR_HSIDIV));
			pll2vco *= (float)(hsivalue / pll2m);
		}
		else{
			pll2vco *= (float)(HSI_VALUE / pll2m);
		}
		break;
	case RCC_PLL12SOURCE_HSE:  /* HSEベース PLL クロックソース */
		pll2vco *= (float)(HSE_VALUE / pll2m);
		break;
	case RCC_PLL12SOURCE_OFF:  /* PLLクロックソースなし */
	default:
		pll2vco = 0;
		break;
	}
	pll2cfgr2 = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CFGR2));
	PLL2_Clocks->PLL_P_Frequency = (uint32_t)(pll2vco / ((float)(((pll2cfgr2 & RCC_PLL2CFGR2_DIVP) >> PLLCFGR2_DIVP_SHIFT) + 1U)));
	PLL2_Clocks->PLL_Q_Frequency = (uint32_t)(pll2vco / ((float)(((pll2cfgr2 & RCC_PLL2CFGR2_DIVQ) >> PLLCFGR2_DIVQ_SHIFT) + 1U)));
	PLL2_Clocks->PLL_R_Frequency = (uint32_t)(pll2vco / ((float)(((pll2cfgr2 & RCC_PLL2CFGR2_DIVR) >> PLLCFGR2_DIVR_SHIFT) + 1U)));
}

/*
 *  PLL3クロック取得
 */
void
GetPLL3ClockFreq(RCC_PLLClocksTypeDef *PLL3_Clocks)
{
	uint32_t pll3m = 1, pll3fracen = 0, hsivalue = 0;
	uint32_t pll3cfgr1, pll3cfgr2, pll3fracr;
	float fracn1, pll3vco = 0;

	pll3cfgr1 = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CFGR1));
	pll3fracr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3FRACR));
	pll3m = ((pll3cfgr1 & RCC_PLL3CFGR1_DIVM3) >> PLLCFGR1_DIVM2_SHIFT) + 1U;
	pll3fracen = (pll3fracr & RCC_PLL3FRACR_FRACLE) >> PLLFRACR_FRACLE_SHIFT;
	fracn1 = (float)(pll3fracen * ((pll3fracr & RCC_PLL3FRACR_FRACV) >> PLLFRACR_FRACV_SHIFT));
	pll3vco = (float)((float)((pll3cfgr1 & RCC_PLL3CFGR1_DIVN) + 1U) + (fracn1 / (float) 0x1FFF));  //Intermediary value
	switch(getPLL3source()){
	case RCC_PLL3SOURCE_HSI:  /* HSIベース PLL クロックソース */
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCRDYR)) & RCC_OCRDYR_HSIDIVRDY) != 0){
			hsivalue = (HSI_VALUE >> (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_HSICFGR)) & RCC_HSICFGR_HSIDIV));
			pll3vco *= (float)(hsivalue / pll3m);
		}
		else{
			pll3vco *= (float)(HSI_VALUE / pll3m);
		}
		break;
	case RCC_PLL3SOURCE_HSE:  /* HSEベース PLL クロックソース */
		pll3vco *= (float)(HSE_VALUE / pll3m);
		break;
	case RCC_PLL3SOURCE_CSI:  /* CSIベース PLL クロックソース */
		pll3vco *= (float)(CSI_VALUE / pll3m);
		break;
	case RCC_PLL3SOURCE_OFF:  /* PLLクロックソースなし */
		pll3vco = 0;
		break;
	}
	pll3cfgr2 = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CFGR2));
	PLL3_Clocks->PLL_P_Frequency = (uint32_t)(pll3vco / ((float)(((pll3cfgr2 & RCC_PLL3CFGR2_DIVP) >> PLLCFGR2_DIVP_SHIFT) + 1U)));
	PLL3_Clocks->PLL_Q_Frequency = (uint32_t)(pll3vco / ((float)(((pll3cfgr2 & RCC_PLL3CFGR2_DIVQ) >> PLLCFGR2_DIVQ_SHIFT) + 1U)));
	PLL3_Clocks->PLL_R_Frequency = (uint32_t)(pll3vco / ((float)(((pll3cfgr2 & RCC_PLL3CFGR2_DIVR) >> PLLCFGR2_DIVR_SHIFT) + 1U)));
}

/*
 *  PLL4クロック取得
 */
void
GetPLL4ClockFreq(RCC_PLLClocksTypeDef *PLL4_Clocks)
{
	uint32_t pll4m = 1U, pll4fracen = 0U, hsivalue = 0U;
	uint32_t pll4cfgr1, pll4cfgr2, pll4fracr;
	float fracn1, pll4vco = 0;

	pll4cfgr1 = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CFGR1));
	pll4fracr = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4FRACR));
	pll4m = ((pll4cfgr1 & RCC_PLL4CFGR1_DIVM4) >> PLLCFGR1_DIVM2_SHIFT) + 1U;
	pll4fracen = (pll4fracr & RCC_PLL4FRACR_FRACLE) >> PLLFRACR_FRACLE_SHIFT;
	fracn1 = (float)(pll4fracen * ((pll4fracr & RCC_PLL4FRACR_FRACV) >> PLLFRACR_FRACV_SHIFT));
	pll4vco = (float)((float)((pll4cfgr1 & RCC_PLL4CFGR1_DIVN) + 1U) + (fracn1 / (float) 0x1FFF));  //Intermediary value
	switch(getPLL4source()){
	case RCC_PLL4SOURCE_HSI:  /* HSIベース PLL クロックソース */
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_OCRDYR)) & RCC_OCRDYR_HSIDIVRDY) != 0){
			hsivalue = (HSI_VALUE >> (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_HSICFGR)) & RCC_HSICFGR_HSIDIV));
			pll4vco *= (float)(hsivalue / pll4m);
		}
		else{
			pll4vco *= (float)(HSI_VALUE / pll4m);
		}
		break;
	case RCC_PLL4SOURCE_HSE:  /* HSEベース PLL クロックソース */
		pll4vco *= (float)(HSE_VALUE / pll4m);
		break;
	case RCC_PLL4SOURCE_CSI:  /* CSIベース PLL クロックソース */
		pll4vco *= (float)(CSI_VALUE / pll4m);
		break;
	case RCC_PLL4SOURCE_I2S_CKIN:  /* Signal I2S_CKIN PLL クロックソース */
		pll4vco *= (float)(EXTERNAL_CLOCK_VALUE / pll4m);
		break;
	}
	pll4cfgr2 = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CFGR2));
	PLL4_Clocks->PLL_P_Frequency = (uint32_t)(pll4vco / ((float)(((pll4cfgr2 & RCC_PLL4CFGR2_DIVP) >> PLLCFGR2_DIVP_SHIFT) + 1U)));
	PLL4_Clocks->PLL_Q_Frequency = (uint32_t)(pll4vco / ((float)(((pll4cfgr2 & RCC_PLL4CFGR2_DIVQ) >> PLLCFGR2_DIVQ_SHIFT) + 1U)));
	PLL4_Clocks->PLL_R_Frequency = (uint32_t)(pll4vco / ((float)(((pll4cfgr2 & RCC_PLL4CFGR2_DIVR) >> PLLCFGR2_DIVR_SHIFT) + 1U)));
}

