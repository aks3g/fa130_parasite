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
 *  @(#) $Id: target_syssvc.h 698 2020-08-19 13:12:05Z roi $
 */

/*
 *  システムサービスのターゲット依存部（stm32mp157c-dk2用）
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
#include "stm32mp157xx.h"

/*
 *  システムクロックの定義
 */
#define HSI_VALUE               64000000	/* Value of the Internal oscillator in Hz*/
#define HSE_VALUE               24000000	/* Value of the External oscillator in Hz */
#define CSI_VALUE               4000000		/* Value of the Internal oscillator in Hz*/
#define EXTERNAL_CLOCK_VALUE    12288000	/* Value of the External clock in Hz*/

/*
 *  HSEスタートアップタイムアウト値(ms)
 */
#define HSE_STARTUP_TIMEOUT  100		/* Time out for HSE start up */

/*
 *  ターゲットペリフェラルロックタイムアウト値(us)
 */
#define LOCK_RESOURCE_TIMEOUT   (1000*1000U)

/*
 *  レジスタシフト値定義
 */
#define HSICFGR_HSITRIM_SHIFT   (8U)
#define PLLCFGR1_DIVM2_SHIFT    (16U)
#define PLLCFGR2_DIVP_SHIFT     (0U)
#define PLLCFGR2_DIVQ_SHIFT     (8U)
#define PLLCFGR2_DIVR_SHIFT     (16U)
#define PLLFRACR_FRACLE_SHIFT   (16U)
#define PLLFRACR_FRACV_SHIFT    (3U)
#define PLLFRACR_FRACV_SHIFT    (3U)

/*
 *  RCC MCU CLOCK SOURCE定義
 */
#define RCC_MCUSSOURCE_HSI  RCC_MSSCKSELR_MCUSSRC_0
#define RCC_MCUSSOURCE_HSE  RCC_MSSCKSELR_MCUSSRC_1
#define RCC_MCUSSOURCE_CSI  RCC_MSSCKSELR_MCUSSRC_2
#define RCC_MCUSSOURCE_PLL3 RCC_MSSCKSELR_MCUSSRC_3

/*
 *  RCC MPU CLOCK SOURCE定義
 */
#define RCC_MPUSOURCE_HSI   RCC_MPCKSELR_MPUSRC_0
#define RCC_MPUSOURCE_HSE   RCC_MPCKSELR_MPUSRC_1
#define RCC_MPUSOURCE_PLL1  RCC_MPCKSELR_MPUSRC_2
#define RCC_MPUSOURCE_MPUDIV RCC_MPCKSELR_MPUSRC_3

/*
 *  RCC AXISS CLOCK SOURCE定義
 */
#define RCC_AXISSOURCE_HSI  RCC_ASSCKSELR_AXISSRC_0
#define RCC_AXISSOURCE_HSE  RCC_ASSCKSELR_AXISSRC_1
#define RCC_AXISSOURCE_PLL2 RCC_ASSCKSELR_AXISSRC_2
#define RCC_AXISSOURCE_OFF  RCC_ASSCKSELR_AXISSRC_3

/*
 *  RCC PLL12 CLOCK SOURCE定義
 */
#define RCC_PLL12SOURCE_HSI RCC_RCK12SELR_PLL12SRC_0
#define RCC_PLL12SOURCE_HSE RCC_RCK12SELR_PLL12SRC_1
#define RCC_PLL12SOURCE_OFF RCC_RCK12SELR_PLL12SRC_2

/*
 *  RCC PLL3 CLOCK SOURCE定義
 */
#define RCC_PLL3SOURCE_HSI  RCC_RCK3SELR_PLL3SRC_0
#define RCC_PLL3SOURCE_HSE  RCC_RCK3SELR_PLL3SRC_1
#define RCC_PLL3SOURCE_CSI  RCC_RCK3SELR_PLL3SRC_2
#define RCC_PLL3SOURCE_OFF  RCC_RCK3SELR_PLL3SRC_3

/*
 *  RCC PLL4 CLOCK SOURCE定義
 */
#define RCC_PLL4SOURCE_HSI  RCC_RCK4SELR_PLL4SRC_0
#define RCC_PLL4SOURCE_HSE  RCC_RCK4SELR_PLL4SRC_1
#define RCC_PLL4SOURCE_CSI  RCC_RCK4SELR_PLL4SRC_2
#define RCC_PLL4SOURCE_I2S_CKIN RCC_RCK4SELR_PLL4SRC_3

/*
 *  RCC MCU CLOCK DIVIER定義
 */
#define RCC_MCU_DIV1        RCC_MCUDIVR_MCUDIV_0
#define RCC_MCU_DIV2        RCC_MCUDIVR_MCUDIV_1
#define RCC_MCU_DIV4        RCC_MCUDIVR_MCUDIV_2
#define RCC_MCU_DIV8        RCC_MCUDIVR_MCUDIV_3
#define RCC_MCU_DIV16       RCC_MCUDIVR_MCUDIV_4
#define RCC_MCU_DIV32       RCC_MCUDIVR_MCUDIV_5
#define RCC_MCU_DIV64       RCC_MCUDIVR_MCUDIV_6
#define RCC_MCU_DIV128      RCC_MCUDIVR_MCUDIV_7
#define RCC_MCU_DIV256      RCC_MCUDIVR_MCUDIV_8
#define RCC_MCU_DIV512      RCC_MCUDIVR_MCUDIV_9

/*
 *  RCC HSI CLOCK PRESCALER定義
 */
#define RCC_HSI_DIV1        RCC_HSICFGR_HSIDIV_0	/* Division by 1, ck_hsi(_ker) = 64 MHz (default after reset)*/
#define RCC_HSI_DIV2        RCC_HSICFGR_HSIDIV_1	/* Division by 2, ck_hsi(_ker) = 32 MHz*/
#define RCC_HSI_DIV4        RCC_HSICFGR_HSIDIV_2	/* Division by 4, ck_hsi(_ker) = 16 MHz*/
#define RCC_HSI_DIV8        RCC_HSICFGR_HSIDIV_3	/* Division by 8, ck_hsi(_ker) =  8 MHz*/

/*
 *  RCC AXI CLOCK SOURCE定義
 */
#define RCC_AXI_DIV1        RCC_AXIDIVR_AXIDIV_0
#define RCC_AXI_DIV2        RCC_AXIDIVR_AXIDIV_1
#define RCC_AXI_DIV3        RCC_AXIDIVR_AXIDIV_2
#define RCC_AXI_DIV4        RCC_AXIDIVR_AXIDIV_3

/*
 *  RCC APB1 CLOCK DIVIER定義
 */
#define RCC_APB1_DIV1       RCC_APB1DIVR_APB1DIV_0
#define RCC_APB1_DIV2       RCC_APB1DIVR_APB1DIV_1
#define RCC_APB1_DIV4       RCC_APB1DIVR_APB1DIV_2
#define RCC_APB1_DIV8       RCC_APB1DIVR_APB1DIV_3
#define RCC_APB1_DIV16      RCC_APB1DIVR_APB1DIV_4

/*
 *  RCC APB2 CLOCK DIVIER定義
 */
#define RCC_APB2_DIV1       RCC_APB2DIVR_APB2DIV_0
#define RCC_APB2_DIV2       RCC_APB2DIVR_APB2DIV_1
#define RCC_APB2_DIV4       RCC_APB2DIVR_APB2DIV_2
#define RCC_APB2_DIV8       RCC_APB2DIVR_APB2DIV_3
#define RCC_APB2_DIV16      RCC_APB2DIVR_APB2DIV_4

/*
 *  RCC APB3 CLOCK DIVIER定義
 */
#define RCC_APB3_DIV1       RCC_APB3DIVR_APB3DIV_0
#define RCC_APB3_DIV2       RCC_APB3DIVR_APB3DIV_1
#define RCC_APB3_DIV4       RCC_APB3DIVR_APB3DIV_2
#define RCC_APB3_DIV8       RCC_APB3DIVR_APB3DIV_3
#define RCC_APB3_DIV16      RCC_APB3DIVR_APB3DIV_4

/*
 *  RCC APB4 CLOCK DIVIER定義
 */
#define RCC_APB4_DIV1       RCC_APB4DIVR_APB4DIV_0
#define RCC_APB4_DIV2       RCC_APB4DIVR_APB4DIV_1
#define RCC_APB4_DIV4       RCC_APB4DIVR_APB4DIV_2
#define RCC_APB4_DIV8       RCC_APB4DIVR_APB4DIV_3
#define RCC_APB4_DIV16      RCC_APB4DIVR_APB4DIV_4

/*
 *  RCC APB5 CLOCK DIVIER定義
 */
#define RCC_APB5_DIV1       RCC_APB5DIVR_APB5DIV_0
#define RCC_APB5_DIV2       RCC_APB5DIVR_APB5DIV_1
#define RCC_APB5_DIV4       RCC_APB5DIVR_APB5DIV_2
#define RCC_APB5_DIV8       RCC_APB5DIVR_APB5DIV_3
#define RCC_APB5_DIV16      RCC_APB5DIVR_APB5DIV_4


#ifndef TOPPERS_MACRO_ONLY

/*
 *  クロックソース取得マクロ
 */
#define getPLL12source()    ((uint32_t)(sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_RCK12SELR)) & RCC_RCK12SELR_PLL12SRC))
#define getPLL3source()     ((uint32_t)(sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_RCK3SELR)) & RCC_RCK3SELR_PLL3SRC))
#define getPLL4source()     ((uint32_t)(sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_RCK4SELR)) & RCC_RCK4SELR_PLL4SRC))
#define getMPUsource()      ((uint32_t)(sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MPCKSELR)) & RCC_MPCKSELR_MPUSRC))
#define getAXISsource()     ((uint32_t)(sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ASSCKSELR)) & RCC_ASSCKSELR_AXISSRC))
#define getMCUsource()      ((uint32_t)(sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MSSCKSELR)) & RCC_MSSCKSELR_MCUSSRC))


/*
 *  クロックレディ取得マクロ
 */
#define getMPUsourcerdy()   ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MPCKSELR)) & RCC_MPCKSELR_MPUSRCRDY) == RCC_MPCKSELR_MPUSRCRDY)
#define getAXISsourcerdy()  ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ASSCKSELR)) & RCC_ASSCKSELR_AXISSRCRDY) == RCC_ASSCKSELR_AXISSRCRDY)
#define getMCUSsourcerdy()  ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_MSSCKSELR)) & RCC_MSSCKSELR_MCUSSRCRDY) == RCC_MSSCKSELR_MCUSSRCRDY)
#define getPLL1rdy()        ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL1CR)) & RCC_PLL1CR_PLL1RDY) == RCC_PLL1CR_PLL1RDY)
#define getPLL2rdy()        ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL2CR)) & RCC_PLL2CR_PLL2RDY) == RCC_PLL2CR_PLL2RDY)
#define getPLL3rdy()        ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL3CR)) & RCC_PLL3CR_PLL3RDY) == RCC_PLL3CR_PLL3RDY)
#define getPLL4rdy()        ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLL4CR)) & RCC_PLL4CR_PLL4RDY) == RCC_PLL4CR_PLL4RDY)

extern uint32_t SystemFrequency;
extern uint32_t SysFrePCLK1;		/* PCLK1 */
extern uint32_t SysFrePCLK2;		/* PCLK2 */
extern uint32_t SysFrePCLK5;		/* PCLK5 */
#define SysFreHCLK          SystemFrequency	/* HCLK = MasterClock / 1 */

#define SYS_CLOCK		    (SystemFrequency)

/*
 *  PCLK取り出し構造体
 */
typedef struct {
	uint32_t PLL_P_Frequency;	/*  PLL P clock frequency expressed in Hz */
	uint32_t PLL_Q_Frequency;	/*  PLL Q clock frequency expressed in Hz */
	uint32_t PLL_R_Frequency;	/*  PLL R clock frequency expressed in Hz */
} RCC_PLLClocksTypeDef;

/*
 *  システム・クロック取得
 */
extern uint32_t GetSystemFrequency(void);

/*
 *  ACLK取得
 */
extern uint32_t GetACLKFreq(void);

/*
 *  PCLK2,3,4取り出し関数
 */
extern void GetPLL2ClockFreq(RCC_PLLClocksTypeDef *PLL2_Clocks);
extern void GetPLL3ClockFreq(RCC_PLLClocksTypeDef *PLL3_Clocks);
extern void GetPLL4ClockFreq(RCC_PLLClocksTypeDef *PLL4_Clocks);

/*
 *  ターゲット１ステップロック
 */
extern uint32_t hsem_1steplock(uint8_t sem);

/*
 *  ターゲットリリースロック
 */
extern void hsem_releaselock(uint8_t sem, uint8_t process);

/*
 *  ターゲットペリフェラルハードウェアセマフォロック
 */
extern ER target_periph_lock(uint32_t periph, uint32_t timeout);

/*
 *  ターゲットペリフェラルハードウェアセマフォアンロック
 */
extern void target_periph_unlock(uint32_t periph);

/*
 *  BOOTモード取得
 */
extern uint32_t target_get_bootmode(void);

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  トレースログに関する設定
 */
#ifdef TOPPERS_ENABLE_TRACE
#include "logtrace/trace_config.h"
#endif /* TOPPERS_ENABLE_TRACE */

/*
 *  起動メッセージのターゲットシステム名
 */
#define TARGET_NAME    "stm32mp157c-dk2(Cortex-M4)"

/*
 *  起動メッセージの著作権表示
 */
#define TARGET_COPYRIGHT \
"Copyright (C) 2016-2020 by Education Working Group TOPPERS PROJECT\n" \

/*
 *  システムログの低レベル出力のための文字出力
 *
 *  ターゲット依存の方法で，文字cを表示/出力/保存する．
 */
extern void	target_fput_log(int8_t c);

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
