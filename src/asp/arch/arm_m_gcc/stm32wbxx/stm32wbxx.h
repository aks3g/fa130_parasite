/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2017-2022 by TOPPERS PROJECT Educational Working Group.
 *
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
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
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: stm32wbxx.h,v 1.4 2022/01/14 15:15:30 roi Exp $
 */

#ifndef _STM32WBXX_H_
#define _STM32WBXX_H_

#include <sil.h>
#include "cmsis_m4.h"

/*
 *  割込み番号の最大値
 */
#define TMAX_INTNO          (16 + 63)

/*
 *  割込み優先度のビット幅
 */
#define TBITW_IPRI          4

/*
 *  INTERRUPT NUMBER
 */
#define IRQ_VECTOR_WWDG             (16 + 0)	/* Window WatchDog Interrupt */
#define IRQ_PVD_PVM                 (16 + 1)	/* PVD and PVM detector Interrupts */
#define IRQ_TAMP_STAMP_LSECSS       (16 + 2)	/* Tamper and TimeStamp interrupts and LSECSS Interrupts */
#define IRQ_VECTOR_RTC_WKUP         (16 + 3)	/* RTC Wakeup interrupt */
#define IRQ_VECTOR_FLASH            (16 + 4)	/* FLASH (CFI) global Interrupt */
#define IRQ_VECTOR_RCC              (16 + 5)	/* RCC Interrupt */
#define IRQ_VECTOR_EXTI0            (16 + 6)	/* EXTI Line0 Interrupt */
#define IRQ_VECTOR_EXTI1            (16 + 7)	/* EXTI Line1 Interrupt */
#define IRQ_VECTOR_EXTI2            (16 + 8)	/* EXTI Line2 Interrupt */
#define IRQ_VECTOR_EXTI3            (16 + 9)	/* EXTI Line3 Interrupt */
#define IRQ_VECTOR_EXTI4            (16 + 10)	/* EXTI Line4 Interrupt */
#define IRQ_VECTOR_DMA1_CH1         (16 + 11)	/* DMA1 Channel 1 global Interrupt */
#define IRQ_VECTOR_DMA1_CH2         (16 + 12)	/* DMA1 Channel 2 global Interrupt */
#define IRQ_VECTOR_DMA1_CH3         (16 + 13)	/* DMA1 Channel 3 global Interrupt */
#define IRQ_VECTOR_DMA1_CH4         (16 + 14)	/* DMA1 Channel 4 global Interrupt */
#define IRQ_VECTOR_DMA1_CH5         (16 + 15)	/* DMA1 Channel 5 global Interrupt */
#define IRQ_VECTOR_DMA1_CH6         (16 + 16)	/* DMA1 Channel 6 global Interrupt */
#define IRQ_VECTOR_DMA1_CH7         (16 + 17)	/* DMA1 Channel 7 global Interrupt */
#define IRQ_VECTOR_ADC1             (16 + 18)	/* ADC1 Interrupts */
#define IRQ_VECTOR_USB_HP           (16 + 19)	/* USB High Priority Interrupt */
#define IRQ_VECTOR_USB_LP           (16 + 20)	/* USB Low Priority Interrupt (including USB wakeup) */
#define IRQ_VECTOR_C2SEV_PWR_C2H    (16 + 21)	/* CPU2 SEV Interrupt */
#define IRQ_VECTOR_COMP             (16 + 22)	/* COMP1 and COMP2 Interrupts */
#define IRQ_VECTOR_EXTI9_5          (16 + 23)	/* External Line[9:5] Interrupts */
#define IRQ_VECTOR_TIM1_BRK         (16 + 24)	/* TIM1 Break Interrupt */
#define IRQ_VECTOR_TIM1_UP_TIM16    (16 + 25)	/* TIM1 Update and TIM16 global Interrupts */
#define IRQ_VECTOR_TIM1_TRG_COM_TIM17 (16+26)	/* TIM1 Trigger and Communication and TIM17 global Interrupts */
#define IRQ_VECTOR_TIM1_CC          (16 + 27)	/* TIM1 Capture Compare Interrupt */
#define IRQ_VECTOR_TIM2             (16 + 28)	/* TIM2 global Interrupt */
#define IRQ_VECTOR_PKA              (16 + 29)	/* PKA Interrupt */
#define IRQ_VECTOR_I2C1_EV          (16 + 30)	/* I2C1 Event Interrupt */
#define IRQ_VECTOR_I2C1_ER          (16 + 31)	/* I2C1 Error Interrupt */
#define IRQ_VECTOR_I2C3_EV          (16 + 32)	/* I2C3 Event Interrupt */
#define IRQ_VECTOR_I2C3_ER          (16 + 33)	/* I2C3 Error Interrupt */
#define IRQ_VECTOR_SPI1             (16 + 34)	/* SPI1 global Interrupt */
#define IRQ_VECTOR_SPI2             (16 + 35)	/* SPI2 global Interrupt */
#define IRQ_VECTOR_USART1           (16 + 36)	/* USART1 global Interrupt */
#define IRQ_VECTOR_LPUART1          (16 + 37)	/* LPUART1 Interrupt */
#define IRQ_VECTOR_SAI1             (16 + 38)	/* SAI1 A and B global interrupt */
#define IRQ_VECTOR_TSC              (16 + 39)	/* TSC Interrupt */
#define IRQ_VECTOR_EXTI15_10        (16 + 40)	/* External Line[15:10] Interrupts */
#define IRQ_VECTOR_RTC_ALARM        (16 + 41)	/* RTC Alarm (A and B) through EXTI Line Interrupt */
#define IRQ_VECTOR_CRS              (16 + 42)	/* CRS interrupt */
#define IRQ_VECTOR_PWR_SOTF_BLEACT_802ACT_RFPHASE (16+43)
												/* PWR switching on the fly interrupt */
												/* PWR end of BLE activity interrupt */
												/* PWR end of 802.15.4 (Zigbee) activity interrupt */
												/* PWR end of critical radio phase interrupt */
#define IRQ_VECTOR_IPCC_C1_RX       (16 + 44)	/* IPCC RX Occupied Interrupt */
#define IRQ_VECTOR_IPCC_C1_TX       (16 + 45)	/* IPCC TX Free Interrupt */
#define IRQ_VECTOR_HSEM             (16 + 46)	/* HSEM Interrupt */
#define IRQ_VECTOR_LPTIM1           (16 + 47)	/* LPTIM1 Interrupt */
#define IRQ_VECTOR_LPTIM2           (16 + 48)	/* LPTIM2 Interrupt */
#define IRQ_VECTOR_LCD              (16 + 49)	/* LCD Interrupt */
#define IRQ_VECTOR_QUADSPI          (16 + 50)	/* QUADSPI Interrupt */
#define IRQ_VECTOR_AES1             (16 + 51)	/* AES1 Interrupt */
#define IRQ_VECTOR_AES2             (16 + 52)	/* AES2 Interrupt */
#define IRQ_VECTOR_RNG              (16 + 53)	/* RNG Interrupt */
#define IRQ_VECTOR_FPU              (16 + 54)	/* FPU Interrupt */
#define IRQ_VECTOR_DMA2_CH1         (16 + 55)	/* DMA2 Channel 1 global Interrupt */
#define IRQ_VECTOR_DMA2_CH2         (16 + 56)	/* DMA2 Channel 2 global Interrupt */
#define IRQ_VECTOR_DMA2_CH3         (16 + 57)	/* DMA2 Channel 3 global Interrupt */
#define IRQ_VECTOR_DMA2_CH4         (16 + 58)	/* DMA2 Channel 4 global Interrupt */
#define IRQ_VECTOR_DMA2_CH5         (16 + 59)	/* DMA2 Channel 5 global Interrupt */
#define IRQ_VECTOR_DMA2_CH6         (16 + 60)	/* DMA2 Channel 6 global Interrupt */
#define IRQ_VECTOR_DMA2_CH7         (16 + 61)	/* DMA2 Channel 7 global Interrupt */
#define IRQ_VECTOR_DMAMUX1_OVR      (16 + 62)	/* DMAMUX1 overrun Interrupt */

/*
 *  PERIPHERAL MEMORY MAP
 */
#define FLASH_BASE          0x08000000	/* FLASH base address in the alias region */
#define SRAM_BASE           0x20000000	/* SRAM base address in the alias region */
#define PERIPH_BASE         0x40000000	/* Peripheral base address in the alias region */

#define SYSTEM_MEMORY_BASE  0x1FFF0000	/* System Memory : 28Kb (0x1FFF0000 ・0x1FFF6FFF) */
#define OTP_AREA_BASE       0x1FFF7000	/* OTP area : 1kB (0x1FFF7000 ・0x1FFF73FF)       */
#define OPTION_BYTE_BASE    0x1FFF8000	/* Option Bytes : 4kB (0x1FFF8000 ・0x1FFF8FFF)   */
#define ENGI_BYTE_BASE      0x1FFF7400	/* Engi Bytes : 3kB (0x1FFF7400 ・0x1FFF7FFF)     */

#define SRAM1_BASE          SRAM_BASE					/* SRAM1(up to 192 KB) base address */
#define SRAM2A_BASE         (SRAM_BASE + 0x00030000)	/* SRAM2A(32 KB) base address       */
#define SRAM2B_BASE         (SRAM_BASE + 0x00038000)	/* SRAM2B(32 KB) base address       */

#define SYSTEM_MEMORY_END_ADDR 0x1FFF6FFF	/* System Memory : 28KB (0x1FFF0000 ・0x1FFF6FFF)  */
#define OTP_AREA_END_ADDR      0x1FFF73FF	/* OTP area : 1KB (0x1FFF7000 ・0x1FFF73FF)        */
#define OPTION_BYTE_END_ADDR   0x1FFF8FFF	/* Option Bytes : 4KB (0x1FFF8000 ・0x1FFF8FFF)    */
#define ENGI_BYTE_END_ADDR     0x1FFF7FFF	/* Engi Bytes : 3kB (0x1FFF7400 ・0x1FFF7FFF)      */

/* Peripheral memory map */
#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE     (PERIPH_BASE + 0x08000000)
#define AHB4PERIPH_BASE     (PERIPH_BASE + 0x18000000)
#define APB3PERIPH_BASE     (PERIPH_BASE + 0x20000000)
#define AHB3PERIPH_BASE     (PERIPH_BASE + 0x50000000)

/* Debug MCU registers base address */
#define DBGMCU_BASE         0xE0042000

/* AHB3 peripherals */
#define QUADSPI_BASE        (AHB3PERIPH_BASE + 0x00000000)	/* QUADSPI memories accessible over AHB base address */

/* Device Electronic Signature */
#define PACKAGE_BASE        0x1FFF7500	/* Package data register base address     */
#define UID64_BASE          0x1FFF7580	/* 64-bit Unique device Identification    */
#define UID_BASE            0x1FFF7590	/* Unique device ID register base address */
#define FLASHSIZE_BASE      0x1FFF75E0	/* Flash size data register base address  */


/*
 *  TIMER
 */
#define TADR_TIM1_BASE      (APB2PERIPH_BASE + 0x2C00)
#define TADR_TIM2_BASE      (APB1PERIPH_BASE + 0x0000)
#define TADR_TIM16_BASE     (APB2PERIPH_BASE + 0x4400)
#define TADR_TIM17_BASE     (APB2PERIPH_BASE + 0x4800)

#define TOFF_TIM_CR1        0x0000		/* (RW) TIM control register 1 */
  #define TIM_CR1_CEN        0x00000001	/* Counter enable */
  #define TIM_CR1_UDIS       0x00000002	/* Update disable */
  #define TIM_CR1_URS        0x00000004	/* Update request source */
  #define TIM_CR1_OPM        0x00000008	/* One pulse mode */
  #define TIM_CR1_DIR        0x00000010	/* Direction */
  #define TIM_CR1_CMS        0x00000060	/* CMS[1:0] bits (Center-aligned mode selection) */
  #define TIM_CR1_CMS_0      0x00000020	/* CMS[1:0] bit 0 */
  #define TIM_CR1_CMS_1      0x00000040	/* CMS[1:0] bit 1 */
  #define TIM_CR1_ARPE       0x00000080	/* Auto-reload preload enable */
  #define TIM_CR1_CKD        0x00000300	/* CKD[1:0] bits (clock division) */
  #define TIM_CR1_CKD_0      0x00000100	/* CKD[1:0] bit 0 */
  #define TIM_CR1_CKD_1      0x00000200	/* CKD[1:0] bit 1 */
  #define TIM_CR1_UIFREMAP   0x00000800	/* Update interrupt flag remap */
#define TOFF_TIM_CR2        0x0004		/* (RW) TIM control register 2 */
  #define TIM_CR2_CCPC       0x00000001	/* Capture/Compare Preloaded Control */
  #define TIM_CR2_CCUS       0x00000004	/* Capture/Compare Control Update Selection */
  #define TIM_CR2_CCDS       0x00000008	/* Capture/Compare DMA Selection */
  #define TIM_CR2_MMS        0x00000070	/* MMS[2:0] bits (Master Mode Selection) */
  #define TIM_CR2_MMS_0      0x00000010
  #define TIM_CR2_MMS_1      0x00000020
  #define TIM_CR2_MMS_2      0x00000040
  #define TIM_CR2_TI1S       0x00000080	/* TI1 Selection */
  #define TIM_CR2_OIS1       0x00000100	/* Output Idle state 1 (OC1 output) */
  #define TIM_CR2_OIS1N      0x00000200	/* Output Idle state 1 (OC1N output) */
  #define TIM_CR2_OIS2       0x00000400	/* Output Idle state 2 (OC2 output) */
  #define TIM_CR2_OIS2N      0x00000800	/* Output Idle state 2 (OC2N output) */
  #define TIM_CR2_OIS3       0x00001000	/* Output Idle state 3 (OC3 output) */
  #define TIM_CR2_OIS3N      0x00002000	/* Output Idle state 3 (OC3N output) */
  #define TIM_CR2_OIS4       0x00004000	/* Output Idle state 4 (OC4 output) */
  #define TIM_CR2_OIS5       0x00010000	/* Output Idle state 5 (OC5 output) */
  #define TIM_CR2_OIS6       0x00040000	/* Output Idle state 6 (OC6 output) */
  #define TIM_CR2_MMS2       0x00F00000	/* MMS[2:0] bits (Master Mode Selection) */
  #define TIM_CR2_MMS2_0     0x00100000
  #define TIM_CR2_MMS2_1     0x00200000
  #define TIM_CR2_MMS2_2     0x00400000
  #define TIM_CR2_MMS2_3     0x00800000
#define TOFF_TIM_SMCR       0x0008		/* (RW) TIM slave mode control register */
  #define TIM_SMCR_SMS       0x00010007	/* SMS[2:0] bits (Slave mode selection) */
  #define TIM_SMCR_SMS_0     0x00000001
  #define TIM_SMCR_SMS_1     0x00000002
  #define TIM_SMCR_SMS_2     0x00000004
  #define TIM_SMCR_SMS_3     0x00010000
  #define TIM_SMCR_OCCS      0x00000008	/* OCREF clear selection */
  #define TIM_SMCR_TS        0x00300070	/* TS[2:0] bits (Trigger selection) */
  #define TIM_SMCR_TS_0      0x00000010
  #define TIM_SMCR_TS_1      0x00000020
  #define TIM_SMCR_TS_2      0x00000040
  #define TIM_SMCR_TS_3      0x00100000
  #define TIM_SMCR_TS_4      0x00200000
  #define TIM_SMCR_MSM       0x00000080	/* Master/slave mode */
  #define TIM_SMCR_ETF       0x00000F00	/* ETF[3:0] bits (External trigger filter) */
  #define TIM_SMCR_ETF_0     0x00000100
  #define TIM_SMCR_ETF_1     0x00000200
  #define TIM_SMCR_ETF_2     0x00000400
  #define TIM_SMCR_ETF_3     0x00000800
  #define TIM_SMCR_ETPS      0x00003000	/* ETPS[1:0] bits (External trigger prescaler) */
  #define TIM_SMCR_ETPS_0    0x00001000
  #define TIM_SMCR_ETPS_1    0x00002000
  #define TIM_SMCR_ECE       0x00004000	/* External clock enable */
  #define TIM_SMCR_ETP       0x00008000	/* External trigger polarity */
#define TOFF_TIM_DIER       0x000C		/* (RW) TIM DMA/interrupt enable register */
  #define TIM_DIER_UIE       0x00000001	/* Update interrupt enable */
  #define TIM_DIER_CC1IE     0x00000002	/* Capture/Compare 1 interrupt enable */
  #define TIM_DIER_CC2IE     0x00000004	/* Capture/Compare 2 interrupt enable */
  #define TIM_DIER_CC3IE     0x00000008	/* Capture/Compare 3 interrupt enable */
  #define TIM_DIER_CC4IE     0x00000010	/* Capture/Compare 4 interrupt enable */
  #define TIM_DIER_COMIE     0x00000020	/* COM interrupt enable */
  #define TIM_DIER_TIE       0x00000040	/* Trigger interrupt enable */
  #define TIM_DIER_BIE       0x00000080	/* Break interrupt enable */
  #define TIM_DIER_UDE       0x00000100	/* Update DMA request enable */
  #define TIM_DIER_CC1DE     0x00000200	/* Capture/Compare 1 DMA request enable */
  #define TIM_DIER_CC2DE     0x00000400	/* Capture/Compare 2 DMA request enable */
  #define TIM_DIER_CC3DE     0x00000800	/* Capture/Compare 3 DMA request enable */
  #define TIM_DIER_CC4DE     0x00001000	/* Capture/Compare 4 DMA request enable */
  #define TIM_DIER_COMDE     0x00002000	/* COM DMA request enable */
  #define TIM_DIER_TDE       0x00004000	/* Trigger DMA request enable */
#define TOFF_TIM_SR         0x0010		/* (RW) TIM status register */
  #define TIM_SR_UIF         0x00000001	/* Update interrupt Flag */
  #define TIM_SR_CC1IF       0x00000002	/* Capture/Compare 1 interrupt Flag */
  #define TIM_SR_CC2IF       0x00000004	/* Capture/Compare 2 interrupt Flag */
  #define TIM_SR_CC3IF       0x00000008	/* Capture/Compare 3 interrupt Flag */
  #define TIM_SR_CC4IF       0x00000010	/* Capture/Compare 4 interrupt Flag */
  #define TIM_SR_COMIF       0x00000020	/* COM interrupt Flag */
  #define TIM_SR_TIF         0x00000040	/* Trigger interrupt Flag */
  #define TIM_SR_BIF         0x00000080	/* Break interrupt Flag */
  #define TIM_SR_B2IF        0x00000100	/* Break 2 interrupt Flag */
  #define TIM_SR_CC1OF       0x00000200	/* Capture/Compare 1 Overcapture Flag */
  #define TIM_SR_CC2OF       0x00000400	/* Capture/Compare 2 Overcapture Flag */
  #define TIM_SR_CC3OF       0x00000800	/* Capture/Compare 3 Overcapture Flag */
  #define TIM_SR_CC4OF       0x00001000	/* Capture/Compare 4 Overcapture Flag */
  #define TIM_SR_SBIF        0x00002000	/* System Break interrupt Flag */
  #define TIM_SR_CC5IF       0x00010000	/* Capture/Compare 5 interrupt Flag */
  #define TIM_SR_CC6IF       0x00020000	/* Capture/Compare 6 interrupt Flag */
#define TOFF_TIM_EGR        0x0014		/* (RW) TIM event generation register */
  #define TIM_EGR_UG         0x00000001	/* Update Generation */
  #define TIM_EGR_CC1G       0x00000002	/* Capture/Compare 1 Generation */
  #define TIM_EGR_CC2G       0x00000004	/* Capture/Compare 2 Generation */
  #define TIM_EGR_CC3G       0x00000008	/* Capture/Compare 3 Generation */
  #define TIM_EGR_CC4G       0x00000010	/* Capture/Compare 4 Generation */
  #define TIM_EGR_COMG       0x00000020	/* Capture/Compare Control Update Generation */
  #define TIM_EGR_TG         0x00000040	/* Trigger Generation */
  #define TIM_EGR_BG         0x00000080	/* Break Generation */
  #define TIM_EGR_B2G        0x00000100	/* Break 2 Generation */
#define TOFF_TIM_CCMR1      0x0018		/* (RW) TIM capture/compare mode register 1 */
  #define TIM_CCMR1_CC1S     0x00000003	/* CC1S[1:0] bits (Capture/Compare 1 Selection) */
  #define TIM_CCMR1_CC1S_0   0x00000001
  #define TIM_CCMR1_CC1S_1   0x00000002
  #define TIM_CCMR1_OC1FE    0x00000004	/* Output Compare 1 Fast enable */
  #define TIM_CCMR1_OC1PE    0x00000008	/* Output Compare 1 Preload enable */
  #define TIM_CCMR1_OC1M     0x00010070	/* OC1M[2:0] bits (Output Compare 1 Mode) */
  #define TIM_CCMR1_OC1M_0   0x00000010
  #define TIM_CCMR1_OC1M_1   0x00000020
  #define TIM_CCMR1_OC1M_2   0x00000040
  #define TIM_CCMR1_OC1M_3   0x00010000
  #define TIM_CCMR1_OC1CE    0x00000080	/* Output Compare 1 Clear Enable */
  #define TIM_CCMR1_CC2S     0x00000300	/* CC2S[1:0] bits (Capture/Compare 2 Selection) */
  #define TIM_CCMR1_CC2S_0   0x00000100
  #define TIM_CCMR1_CC2S_1   0x00000200
  #define TIM_CCMR1_OC2FE    0x00000400	/* Output Compare 2 Fast enable */
  #define TIM_CCMR1_OC2PE    0x00000800	/* Output Compare 2 Preload enable */
  #define TIM_CCMR1_OC2M     0x01007000	/* OC2M[2:0] bits (Output Compare 2 Mode) */
  #define TIM_CCMR1_OC2M_0   0x00001000
  #define TIM_CCMR1_OC2M_1   0x00002000
  #define TIM_CCMR1_OC2M_2   0x00004000
  #define TIM_CCMR1_OC2M_3   0x01000000
  #define TIM_CCMR1_OC2CE    0x00008000	/* Output Compare 2 Clear Enable */

  #define TIM_CCMR1_IC1PSC   0x0000000C	/* IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
  #define TIM_CCMR1_IC1PSC_0 0x00000004
  #define TIM_CCMR1_IC1PSC_1 0x00000008
  #define TIM_CCMR1_IC1F     0x000000F0	/* IC1F[3:0] bits (Input Capture 1 Filter) */
  #define TIM_CCMR1_IC1F_0   0x00000010
  #define TIM_CCMR1_IC1F_1   0x00000020
  #define TIM_CCMR1_IC1F_2   0x00000040
  #define TIM_CCMR1_IC1F_3   0x00000080
  #define TIM_CCMR1_IC2PSC   0x00000C00	/* IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
  #define TIM_CCMR1_IC2PSC_0 0x00000400
  #define TIM_CCMR1_IC2PSC_1 0x00000800
  #define TIM_CCMR1_IC2F     0x0000F000	/* IC2F[3:0] bits (Input Capture 2 Filter) */
  #define TIM_CCMR1_IC2F_0   0x00001000
  #define TIM_CCMR1_IC2F_1   0x00002000
  #define TIM_CCMR1_IC2F_2   0x00004000
  #define TIM_CCMR1_IC2F_3   0x00008000
#define TOFF_TIM_CCMR2      0x001C		/* (RW) TIM capture/compare mode register 2 */
  #define TIM_CCMR2_CC3S     0x00000003	/* CC3S[1:0] bits (Capture/Compare 3 Selection) */
  #define TIM_CCMR2_CC3S_0   0x00000001
  #define TIM_CCMR2_CC3S_1   0x00000002
  #define TIM_CCMR2_OC3FE    0x00000004	/* Output Compare 3 Fast enable */
  #define TIM_CCMR2_OC3PE    0x00000008	/* Output Compare 3 Preload enable */
  #define TIM_CCMR2_OC3M     0x00010070	/* OC3M[2:0] bits (Output Compare 3 Mode) */
  #define TIM_CCMR2_OC3M_0   0x00000010
  #define TIM_CCMR2_OC3M_1   0x00000020
  #define TIM_CCMR2_OC3M_2   0x00000040
  #define TIM_CCMR2_OC3M_3   0x00010000
  #define TIM_CCMR2_OC3CE    0x00000080	/* Output Compare 3 Clear Enable */
  #define TIM_CCMR2_CC4S     0x00000300	/* CC4S[1:0] bits (Capture/Compare 4 Selection) */
  #define TIM_CCMR2_CC4S_0   0x00000100
  #define TIM_CCMR2_CC4S_1   0x00000200
  #define TIM_CCMR2_OC4FE    0x00000400	/* Output Compare 4 Fast enable */
  #define TIM_CCMR2_OC4PE    0x00000800	/* Output Compare 4 Preload enable */
  #define TIM_CCMR2_OC4M     0x01007000	/* OC4M[2:0] bits (Output Compare 4 Mode) */
  #define TIM_CCMR2_OC4M_0   0x00001000
  #define TIM_CCMR2_OC4M_1   0x00002000
  #define TIM_CCMR2_OC4M_2   0x00004000
  #define TIM_CCMR2_OC4M_3   0x01000000
  #define TIM_CCMR2_OC4CE    0x00008000	/* Output Compare 4 Clear Enable */

  #define TIM_CCMR2_IC3PSC   0x0000000C	/* IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
  #define TIM_CCMR2_IC3PSC_0 0x00000004
  #define TIM_CCMR2_IC3PSC_1 0x00000008
  #define TIM_CCMR2_IC3F     0x000000F0	/* IC3F[3:0] bits (Input Capture 3 Filter) */
  #define TIM_CCMR2_IC3F_0   0x00000010
  #define TIM_CCMR2_IC3F_1   0x00000020
  #define TIM_CCMR2_IC3F_2   0x00000040
  #define TIM_CCMR2_IC3F_3   0x00000080
  #define TIM_CCMR2_IC4PSC   0x00000C00	/* IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
  #define TIM_CCMR2_IC4PSC_0 0x00000400
  #define TIM_CCMR2_IC4PSC_1 0x00000800
  #define TIM_CCMR2_IC4F     0x0000F000	/* IC4F[3:0] bits (Input Capture 4 Filter) */
  #define TIM_CCMR2_IC4F_0   0x00001000
  #define TIM_CCMR2_IC4F_1   0x00002000
  #define TIM_CCMR2_IC4F_2   0x00004000
  #define TIM_CCMR2_IC4F_3   0x00008000
#define TOFF_TIM_CCER       0x0020		/* (RW) TIM capture/compare enable register */
  #define TIM_CCER_CC1E      0x00000001	/* Capture/Compare 1 output enable */
  #define TIM_CCER_CC1P      0x00000002	/* Capture/Compare 1 output Polarity */
  #define TIM_CCER_CC1NE     0x00000004	/* Capture/Compare 1 Complementary output enable */
  #define TIM_CCER_CC1NP     0x00000008	/* Capture/Compare 1 Complementary output Polarity */
  #define TIM_CCER_CC2E      0x00000010	/* Capture/Compare 2 output enable */
  #define TIM_CCER_CC2P      0x00000020	/* Capture/Compare 2 output Polarity */
  #define TIM_CCER_CC2NE     0x00000040	/* Capture/Compare 2 Complementary output enable */
  #define TIM_CCER_CC2NP     0x00000080	/* Capture/Compare 2 Complementary output Polarity */
  #define TIM_CCER_CC3E      0x00000100	/* Capture/Compare 3 output enable */
  #define TIM_CCER_CC3P      0x00000200	/* Capture/Compare 3 output Polarity */
  #define TIM_CCER_CC3NE     0x00000400	/* Capture/Compare 3 Complementary output enable */
  #define TIM_CCER_CC3NP     0x00000800	/* Capture/Compare 3 Complementary output Polarity */
  #define TIM_CCER_CC4E      0x00001000	/* Capture/Compare 4 output enable */
  #define TIM_CCER_CC4P      0x00002000	/* Capture/Compare 4 output Polarity */
  #define TIM_CCER_CC4NP     0x00008000	/* Capture/Compare 4 Complementary output Polarity */
  #define TIM_CCER_CC5E      0x00010000	/* Capture/Compare 5 output enable */
  #define TIM_CCER_CC5P      0x00020000	/* Capture/Compare 5 output Polarity */
  #define TIM_CCER_CC6E      0x00100000	/* Capture/Compare 6 output enable */
  #define TIM_CCER_CC6P      0x00200000	/* Capture/Compare 6 output Polarity */
#define TOFF_TIM_CNT        0x0024		/* (RW) TIM counter register */
  #define TIM_CNT_CNT        0xFFFFFFFF	/* Counter Value */
  #define TIM_CNT_UIFCPY     0x80000000	/* Update interrupt flag copy (if UIFREMAP=1) */
#define TOFF_TIM_PSC        0x0028		/* (RW) TIM prescaler */
  #define TIM_PSC_PSC        0x0000FFFF	/* Prescaler Value */
#define TOFF_TIM_ARR        0x002C		/* (RW) TIM auto-reload register */
#define TOFF_TIM_RCR        0x0030		/* (RW) TIM repetition counter register */
  #define TIM_RCR_REP        0x0000FFFF	/* Repetition Counter Value */
#define TOFF_TIM_CCR1       0x0034		/* (RW) TIM capture/compare register 1 */
  #define TIM_CCR1_CCR1      0x0000FFFF	/* Capture/Compare 1 Value */
#define TOFF_TIM_CCR2       0x0038		/* (RW) TIM capture/compare register 2 */
  #define TIM_CCR2_CCR2      0x0000FFFF	/* Capture/Compare 2 Value */
#define TOFF_TIM_CCR3       0x003C		/* (RW) TIM capture/compare register 3 */
  #define TIM_CCR3_CCR3      0x0000FFFF	/* Capture/Compare 3 Value */
#define TOFF_TIM_CCR4       0x0040		/* (RW) TIM capture/compare register 4 */
  #define TIM_CCR4_CCR4      0x0000FFFF	/* Capture/Compare 4 Value */
#define TOFF_TIM_BDTR       0x0044		/* (RW) TIM break and dead-time register */
  #define TIM_BDTR_DTG       0x000000FF	/* DTG[0:7] bits (Dead-Time Generator set-up) */
  #define TIM_BDTR_DTG_0     0x00000001
  #define TIM_BDTR_DTG_1     0x00000002
  #define TIM_BDTR_DTG_2     0x00000004
  #define TIM_BDTR_DTG_3     0x00000008
  #define TIM_BDTR_DTG_4     0x00000010
  #define TIM_BDTR_DTG_5     0x00000020
  #define TIM_BDTR_DTG_6     0x00000040
  #define TIM_BDTR_DTG_7     0x00000080
  #define TIM_BDTR_LOCK      0x00000300	/* LOCK[1:0] bits (Lock Configuration) */
  #define TIM_BDTR_LOCK_0    0x00000100
  #define TIM_BDTR_LOCK_1    0x00000200
  #define TIM_BDTR_OSSI      0x00000400	/* Off-State Selection for Idle mode */
  #define TIM_BDTR_OSSR      0x00000800	/* Off-State Selection for Run mode */
  #define TIM_BDTR_BKE       0x00001000	/* Break enable for Break 1 */
  #define TIM_BDTR_BKP       0x00002000	/* Break Polarity for Break 1 */
  #define TIM_BDTR_AOE       0x00004000	/* Automatic Output enable */
  #define TIM_BDTR_MOE       0x00008000	/* Main Output enable */
  #define TIM_BDTR_BKF       0x000F0000	/* Break Filter for Break 1 */
  #define TIM_BDTR_BK2F      0x00F00000	/* Break Filter for Break 2 */
  #define TIM_BDTR_BK2E      0x01000000	/* Break enable for Break 2 */
  #define TIM_BDTR_BK2P      0x02000000	/* Break Polarity for Break 2 */
  #define TIM_BDTR_BKDSRM    0x04000000	/* Break disarming/re-arming */
  #define TIM_BDTR_BK2DSRM   0x08000000	/* Break2 disarming/re-arming */
  #define TIM_BDTR_BKBID     0x10000000	/* Break BIDirectional */
  #define TIM_BDTR_BK2BID    0x20000000	/* Break2 BIDirectional */
#define TOFF_TIM_DCR        0x0048		/* (RW) TIM DMA control register */
  #define TIM_DCR_DBA        0x0000001F	/* DBA[4:0] bits (DMA Base Address) */
  #define TIM_DCR_DBA_0      0x00000001
  #define TIM_DCR_DBA_1      0x00000002
  #define TIM_DCR_DBA_2      0x00000004
  #define TIM_DCR_DBA_3      0x00000008
  #define TIM_DCR_DBA_4      0x00000010
  #define TIM_DCR_DBL        0x00001F00	/* DBL[4:0] bits (DMA Burst Length) */
  #define TIM_DCR_DBL_0      0x00000100
  #define TIM_DCR_DBL_1      0x00000200
  #define TIM_DCR_DBL_2      0x00000400
  #define TIM_DCR_DBL_3      0x00000800
  #define TIM_DCR_DBL_4      0x00001000
#define TOFF_TIM_DMAR       0x004C		/* (RW) TIM DMA address for full transfer */
  #define TIM_DMAR_DMAB      0x0000FFFF	/* DMA register for burst accesses */
#define TOFF_TIM_OR         0x0050		/* (RW) TIM option register */
#define TOFF_TIM_CCMR3      0x0054		/* (RW) TIM capture/compare mode register 3 */
  #define TIM_CCMR3_OC5FE    0x00000004	/* Output Compare 5 Fast enable */
  #define TIM_CCMR3_OC5PE    0x00000008	/* Output Compare 5 Preload enable */
  #define TIM_CCMR3_OC5M     0x00010070	/* OC5M[3:0] bits (Output Compare 5 Mode) */
  #define TIM_CCMR3_OC5M_0   0x00000010
  #define TIM_CCMR3_OC5M_1   0x00000020
  #define TIM_CCMR3_OC5M_2   0x00000040
  #define TIM_CCMR3_OC5M_3   0x00010000
  #define TIM_CCMR3_OC5CE    0x00000080	/* Output Compare 5 Clear Enable */
  #define TIM_CCMR3_OC6FE    0x00000400	/* Output Compare 6 Fast enable */
  #define TIM_CCMR3_OC6PE    0x00000800	/* Output Compare 6 Preload enable */
  #define TIM_CCMR3_OC6M     0x01007000	/* OC6M[3:0] bits (Output Compare 6 Mode) */
  #define TIM_CCMR3_OC6M_0   0x00001000
  #define TIM_CCMR3_OC6M_1   0x00002000
  #define TIM_CCMR3_OC6M_2   0x00004000
  #define TIM_CCMR3_OC6M_3   0x01000000
  #define TIM_CCMR3_OC6CE    0x00008000	/* Output Compare 6 Clear Enable */
#define TOFF_TIM_CCR5       0x0058		/* (RW) TIM capture/compare register5 */
  #define TIM_CCR5_CCR5      0xFFFFFFFF	/* Capture/Compare 5 Value */
  #define TIM_CCR5_GC5C1     0x20000000	/* Group Channel 5 and Channel 1 */
  #define TIM_CCR5_GC5C2     0x40000000	/* Group Channel 5 and Channel 2 */
  #define TIM_CCR5_GC5C3     0x80000000	/* Group Channel 5 and Channel 3 */
#define TOFF_TIM_CCR6		0x005C		/* (RW) TIM capture/compare register6 */
  #define TIM_CCR6_CCR6      0x0000FFFF	/* Capture/Compare 6 Value */
#define TOFF_TIM_AF1        0x0060		/* (RW) TIM Alternate function option register 1 */
#define TOFF_TIM_AF2        0x0064		/* (RW) TIM Alternate function option register 2 */

/*
 *  LCD
 */
#define TADR_LCD_BASE       (APB1PERIPH_BASE + 0x2400)
#define TOFF_LCD_CR         0x0000		/* (RW) LCD control register */
  #define LCD_CR_LCDEN       0x00000001	/* LCD Enable Bit */
  #define LCD_CR_VSEL        0x00000002	/* Voltage source selector Bit */
  #define LCD_CR_DUTY        0x0000001C	/* DUTY[2:0] bits (Duty selector) */
  #define LCD_CR_DUTY_0      0x00000004
  #define LCD_CR_DUTY_1      0x00000008
  #define LCD_CR_DUTY_2      0x00000010
  #define LCD_CR_BIAS        0x00000060	/* BIAS[1:0] bits (Bias selector) */
  #define LCD_CR_BIAS_0      0x00000020
  #define LCD_CR_BIAS_1      0x00000040
  #define LCD_CR_MUX_SEG     0x00000080	/* Mux Segment Enable Bit */
  #define LCD_CR_BUFEN       0x00000100	/* Voltage output buffer enable Bit */
#define TOFF_LCD_FCR        0x0004		/* (RW) LCD frame control register */
  #define LCD_FCR_HD         0x00000001	/* High Drive Enable Bit */
  #define LCD_FCR_SOFIE      0x00000002	/* Start of Frame Interrupt Enable Bit */
  #define LCD_FCR_UDDIE      0x00000008	/* Update Display Done Interrupt Enable Bit */
  #define LCD_FCR_PON        0x00000070	/* PON[2:0] bits (Puls ON Duration) */
  #define LCD_FCR_PON_0      0x00000010
  #define LCD_FCR_PON_1      0x00000020
  #define LCD_FCR_PON_2      0x00000040
  #define LCD_FCR_DEAD       0x00000380	/* DEAD[2:0] bits (DEAD Time) */
  #define LCD_FCR_DEAD_0     0x00000080
  #define LCD_FCR_DEAD_1     0x00000100
  #define LCD_FCR_DEAD_2     0x00000200
  #define LCD_FCR_CC         0x00001C00	/* CC[2:0] bits (Contrast Control) */
  #define LCD_FCR_CC_0       0x00000400
  #define LCD_FCR_CC_1       0x00000800
  #define LCD_FCR_CC_2       0x00001000
  #define LCD_FCR_BLINKF     0x0000E000	/* BLINKF[2:0] bits (Blink Frequency) */
  #define LCD_FCR_BLINKF_0   0x00002000
  #define LCD_FCR_BLINKF_1   0x00004000
  #define LCD_FCR_BLINKF_2   0x00008000
  #define LCD_FCR_BLINK      0x00030000	/* BLINK[1:0] bits (Blink Enable) */
  #define LCD_FCR_BLINK_0    0x00010000
  #define LCD_FCR_BLINK_1    0x00020000
  #define LCD_FCR_DIV        0x003C0000	/* DIV[3:0] bits (Divider) */
  #define LCD_FCR_PS         0x03C00000	/* PS[3:0] bits (Prescaler) */
#define TOFF_LCD_SR         0x0008		/* (RW) LCD status register */
  #define LCD_SR_ENS         0x00000001	/* LCD Enabled Bit */
  #define LCD_SR_SOF         0x00000002	/* Start Of Frame Flag Bit */
  #define LCD_SR_UDR         0x00000004	/* Update Display Request Bit */
  #define LCD_SR_UDD         0x00000008	/* Update Display Done Flag Bit */
  #define LCD_SR_RDY         0x00000010	/* Ready Flag Bit */
  #define LCD_SR_FCRSR       0x00000020	/* LCD FCR Register Synchronization Flag Bit */
#define TOFF_LCD_CLR        0x000C		/* (RW) LCD clear register */
  #define LCD_CLR_SOFC       0x00000002	/* Start Of Frame Flag Clear Bit */
  #define LCD_CLR_UDDC       0x00000008	/* Update Display Done Flag Clear Bit */
#define TOFF_LCD_RAM        0x0014		/* (RW) LCD display memory  0x14-0x50 */

/*
 *  REAL-TIME CLOCK
 */
#define TADR_RTC_BASE       (APB1PERIPH_BASE + 0x2800)
#define TOFF_RTC_TR         0x0000		/* (RW) RTC time register */
  #define RTC_TR_SU                0x0000000F	/* Second units in BCD format */
  #define RTC_TR_SU_0              0x00000001
  #define RTC_TR_SU_1              0x00000002
  #define RTC_TR_SU_2              0x00000004
  #define RTC_TR_SU_3              0x00000008
  #define RTC_TR_ST                0x00000070	/* Second tens in BCD format */
  #define RTC_TR_ST_0              0x00000010
  #define RTC_TR_ST_1              0x00000020
  #define RTC_TR_ST_2              0x00000040
  #define RTC_TR_MNU               0x00000F00	/* Minute unit in BCD format */
  #define RTC_TR_MNU_0             0x00000100
  #define RTC_TR_MNU_1             0x00000200
  #define RTC_TR_MNU_2             0x00000400
  #define RTC_TR_MNU_3             0x00000800
  #define RTC_TR_MNT               0x00007000	/* Minute tens in BCD format */
  #define RTC_TR_MNT_0             0x00001000
  #define RTC_TR_MNT_1             0x00002000
  #define RTC_TR_MNT_2             0x00004000
  #define RTC_TR_HU                0x000F0000	/* Hour units in BCD format */
  #define RTC_TR_HU_0              0x00010000
  #define RTC_TR_HU_1              0x00020000
  #define RTC_TR_HU_2              0x00040000
  #define RTC_TR_HU_3              0x00080000
  #define RTC_TR_HT                0x00300000	/* Hour tens in BCD format */
  #define RTC_TR_HT_0              0x00100000
  #define RTC_TR_HT_1              0x00200000
  #define RTC_TR_PM                0x00400000	/* AM/PM notation */
#define TOFF_RTC_DR         0x0004		/* (RW) RTC date register */
  #define RTC_DR_DU                0x0000000F	/* Date units in BCD format */
  #define RTC_DR_DU_0              0x00000001
  #define RTC_DR_DU_1              0x00000002
  #define RTC_DR_DU_2              0x00000004
  #define RTC_DR_DU_3              0x00000008
  #define RTC_DR_DT                0x00000030	/* Date tens in BCD format */
  #define RTC_DR_DT_0              0x00000010
  #define RTC_DR_DT_1              0x00000020
  #define RTC_DR_MU                0x00000F00	/* Month units in BCD format */
  #define RTC_DR_MU_0              0x00000100
  #define RTC_DR_MU_1              0x00000200
  #define RTC_DR_MU_2              0x00000400
  #define RTC_DR_MU_3              0x00000800
  #define RTC_DR_MT                0x00001000	/* Month tens in BCD format */
  #define RTC_DR_WDU               0x0000E000	/* Week day units */
  #define RTC_DR_WDU_0             0x00002000
  #define RTC_DR_WDU_1             0x00004000
  #define RTC_DR_WDU_2             0x00008000
  #define RTC_DR_YU                0x000F0000	/* Years units in BCD format */
  #define RTC_DR_YU_0              0x00010000
  #define RTC_DR_YU_1              0x00020000
  #define RTC_DR_YU_2              0x00040000
  #define RTC_DR_YU_3              0x00080000
  #define RTC_DR_YT                0x00F00000	/* Year tens in BCD format */
  #define RTC_DR_YT_0              0x00100000
  #define RTC_DR_YT_1              0x00200000
  #define RTC_DR_YT_2              0x00400000
  #define RTC_DR_YT_3              0x00800000
#define TOFF_RTC_CR         0x0008		/* (RW) RTC control register */
  #define RTC_CR_WUCKSEL           0x00000007	/* Wakekup clock selection */
  #define RTC_CR_WUCKSEL_0         0x00000001
  #define RTC_CR_WUCKSEL_1         0x00000002
  #define RTC_CR_WUCKSEL_2         0x00000004
  #define RTC_CR_TSEDGE            0x00000008	/* Timestamp event active edge */
  #define RTC_CR_REFCKON           0x00000010	/* RTC_REFIN reference clock detection enable (50 or 60 Hz) */
  #define RTC_CR_BYPSHAD           0x00000020	/* Bypass the shadow registers */
  #define RTC_CR_FMT               0x00000040	/* Hour AM/PM or 24H format */
  #define RTC_CR_ALRAE             0x00000100	/* Alarm A enable */
  #define RTC_CR_ALRBE             0x00000200	/* Alarm B enable */
  #define RTC_CR_WUTE              0x00000400	/* Wakeup timer enable */
  #define RTC_CR_TSE               0x00000800	/* Timestamp on RTC TS input edge enable */
  #define RTC_CR_ALRAIE            0x00001000	/* Alarm A interrupt enable */
  #define RTC_CR_ALRBIE            0x00002000	/* Alarm B interrupt enable */
  #define RTC_CR_WUTIE             0x00004000	/* Wakeup timer interrupt enable */
  #define RTC_CR_TSIE              0x00008000	/* Time-stamp interrupt enable */
  #define RTC_CR_ADD1H             0x00010000	/* Add 1 hour (summer time change) */
  #define RTC_CR_SUB1H             0x00020000	/* Subtract 1 hour (winter time change) */
  #define RTC_CR_BKP               0x00040000	/* Backup */
  #define RTC_CR_COSEL             0x00080000	/* Calibration ouput selection */
  #define RTC_CR_POL               0x00100000	/* Ouput polarity */
  #define RTC_CR_OSEL              0x00600000	/* Output selection */
  #define RTC_CR_OSEL_0            0x00200000
  #define RTC_CR_OSEL_1            0x00400000
  #define RTC_CR_COE               0x00800000	/* Calibration output enable */
  #define RTC_CR_ITSE              0x01000000	/* Timestamp on internal event enable */
#define TOFF_RTC_ISR        0x000C		/* (RW) RTC initialization and status register */
  #define RTC_ISR_ALRAWF           0x00000001	/* Alarm A write flag */
  #define RTC_ISR_ALRBWF           0x00000002	/* Alarm B write flag */
  #define RTC_ISR_WUTWF            0x00000004	/* Wakeup timer write flag */
  #define RTC_ISR_SHPF             0x00000008	/* Shift operation pending */
  #define RTC_ISR_INITS            0x00000010	/* Initialization status flag */
  #define RTC_ISR_RSF              0x00000020	/* Registers synchronization flag */
  #define RTC_ISR_INITF            0x00000040	/* Initialization flag */
  #define RTC_ISR_INIT             0x00000080	/* Initialization mode */
  #define RTC_ISR_ALRAF            0x00000100	/* Alarm A flag */
  #define RTC_ISR_ALRBF            0x00000200	/* Alarm B flag */
  #define RTC_ISR_WUTF             0x00000400	/* Wakeup timer flag */
  #define RTC_ISR_TSF              0x00000800	/* Timestamp flag */
  #define RTC_ISR_TSOVF            0x00001000	/* Timestamp overflow flag */
  #define RTC_ISR_TAMP1F           0x00002000	/* RTC_TAMP1 detection flag */
  #define RTC_ISR_TAMP2F           0x00004000	/* RTC_TAMP2 detection flag */
  #define RTC_ISR_TAMP3F           0x00008000	/* RTC_TAMP3 detection flag */
  #define RTC_ISR_RECALPF          0x00010000	/* Recalibration pending flag */
  #define RTC_ISR_ITSF             0x00020000	/* Internal timestamp flag */
#define TOFF_RTC_PRER       0x0010		/* (RW) RTC prescaler register */
#define TOFF_RTC_WUTR       0x0014		/* (RW) RTC wakeup timer register */
#define TOFF_RTC_ALRMAR     0x001C		/* (RW) RTC alarm A register */
  #define RTC_ALRMAR_SU            0x0000000F	/* Alarm A second units in BCD format */
  #define RTC_ALRMAR_SU_0          0x00000001
  #define RTC_ALRMAR_SU_1          0x00000002
  #define RTC_ALRMAR_SU_2          0x00000004
  #define RTC_ALRMAR_SU_3          0x00000008
  #define RTC_ALRMAR_ST            0x00000070	/* Alarm A second tens in BCD format */
  #define RTC_ALRMAR_ST_0          0x00000010
  #define RTC_ALRMAR_ST_1          0x00000020
  #define RTC_ALRMAR_ST_2          0x00000040
  #define RTC_ALRMAR_MSK1          0x00000080	/* Alarm A seconds mask */
  #define RTC_ALRMAR_MNU           0x00000F00	/* Alarm A minute units in BCD format */
  #define RTC_ALRMAR_MNU_0         0x00000100
  #define RTC_ALRMAR_MNU_1         0x00000200
  #define RTC_ALRMAR_MNU_2         0x00000400
  #define RTC_ALRMAR_MNU_3         0x00000800
  #define RTC_ALRMAR_MNT           0x00007000	/* Alarm A minute tens in BCD format */
  #define RTC_ALRMAR_MNT_0         0x00001000
  #define RTC_ALRMAR_MNT_1         0x00002000
  #define RTC_ALRMAR_MNT_2         0x00004000
  #define RTC_ALRMAR_MSK2          0x00008000	/* Alarm A minutes mask */
  #define RTC_ALRMAR_HU            0x000F0000	/* Alarm A hour units in BCD format */
  #define RTC_ALRMAR_HU_0          0x00010000
  #define RTC_ALRMAR_HU_1          0x00020000
  #define RTC_ALRMAR_HU_2          0x00040000
  #define RTC_ALRMAR_HU_3          0x00080000
  #define RTC_ALRMAR_HT            0x00300000	/* Alarm A hour tens in BCD format */
  #define RTC_ALRMAR_HT_0          0x00100000
  #define RTC_ALRMAR_HT_1          0x00200000
  #define RTC_ALRMAR_PM            0x00400000	/* Alarm A AM/PM or 24H format */
  #define RTC_ALRMAR_MSK3          0x00800000	/* Alarm A hours mask */
  #define RTC_ALRMAR_DU            0x0F000000	/* Alarm A date units in BCD format */
  #define RTC_ALRMAR_DU_0          0x01000000
  #define RTC_ALRMAR_DU_1          0x02000000
  #define RTC_ALRMAR_DU_2          0x04000000
  #define RTC_ALRMAR_DU_3          0x08000000
  #define RTC_ALRMAR_DT            0x30000000	/* Alarm A date tens in BCD format */
  #define RTC_ALRMAR_DT_0          0x10000000
  #define RTC_ALRMAR_DT_1          0x20000000
  #define RTC_ALRMAR_WDSEL         0x40000000	/* Alarm A week day selection */
  #define RTC_ALRMAR_MSK4          0x80000000	/* Alarm A date mask */
#define TOFF_RTC_ALRMBR     0x0020		/* (RW) RTC alarm B register */
  #define RTC_ALRMBR_SU            0x0000000F	/* Alarm B second units in BCD format */
  #define RTC_ALRMBR_SU_0          0x00000001
  #define RTC_ALRMBR_SU_1          0x00000002
  #define RTC_ALRMBR_SU_2          0x00000004
  #define RTC_ALRMBR_SU_3          0x00000008
  #define RTC_ALRMBR_ST            0x00000070	/* Alarm B second tens in BCD format */
  #define RTC_ALRMBR_ST_0          0x00000010
  #define RTC_ALRMBR_ST_1          0x00000020
  #define RTC_ALRMBR_ST_2          0x00000040
  #define RTC_ALRMBR_MSK1          0x00000080	/* Alarm B seconds mask */
  #define RTC_ALRMBR_MNU           0x00000F00	/* Alarm B minute units in BCD format */
  #define RTC_ALRMBR_MNU_0         0x00000100
  #define RTC_ALRMBR_MNU_1         0x00000200
  #define RTC_ALRMBR_MNU_2         0x00000400
  #define RTC_ALRMBR_MNU_3         0x00000800
  #define RTC_ALRMBR_MNT           0x00007000	/* Alarm B minute tens in BCD format */
  #define RTC_ALRMBR_MNT_0         0x00001000
  #define RTC_ALRMBR_MNT_1         0x00002000
  #define RTC_ALRMBR_MNT_2         0x00004000
  #define RTC_ALRMBR_MSK2          0x00008000	/* Alarm B minutes mask */
  #define RTC_ALRMBR_HU            0x000F0000	/* Alarm B hour units in BCD format */
  #define RTC_ALRMBR_HU_0          0x00010000
  #define RTC_ALRMBR_HU_1          0x00020000
  #define RTC_ALRMBR_HU_2          0x00040000
  #define RTC_ALRMBR_HU_3          0x00080000
  #define RTC_ALRMBR_HT            0x00300000	/* Alarm B hour tens in BCD format */
  #define RTC_ALRMBR_HT_0          0x00100000
  #define RTC_ALRMBR_HT_1          0x00200000
  #define RTC_ALRMBR_PM            0x00400000	/* Alarm B AM/PM or 24H format */
  #define RTC_ALRMBR_MSK3          0x00800000	/* Alarm B hour mask */
  #define RTC_ALRMBR_DU            0x0F000000	/* Alarm B data units or day in BCD format */
  #define RTC_ALRMBR_DU_0          0x01000000
  #define RTC_ALRMBR_DU_1          0x02000000
  #define RTC_ALRMBR_DU_2          0x04000000
  #define RTC_ALRMBR_DU_3          0x08000000
  #define RTC_ALRMBR_DT            0x30000000	/* Alarm B data tens in BCD format */
  #define RTC_ALRMBR_DT_0          0x10000000
  #define RTC_ALRMBR_DT_1          0x20000000
  #define RTC_ALRMBR_WDSEL         0x40000000	/* Alarm B week day selection */
  #define RTC_ALRMBR_MSK4          0x80000000	/* Alarm B date mask */
#define TOFF_RTC_WPR        0x0024		/* (RW) RTC write protection register */
  #define RTC_WPR_KEY              0x000000FF	/* Write protection key */
#define TOFF_RTC_SSR        0x0028		/* (RW) RTC sub second register */
#define TOFF_RTC_SHIFTR     0x002C		/* (RW) RTC shift control register */
#define TOFF_RTC_TSTR       0x0030		/* (RW) RTC time stamp time register */
  #define RTC_TSTR_SU              0x0000000F	/* Timestamp second units in BCD format */
  #define RTC_TSTR_SU_0            0x00000001
  #define RTC_TSTR_SU_1            0x00000002
  #define RTC_TSTR_SU_2            0x00000004
  #define RTC_TSTR_SU_3            0x00000008
  #define RTC_TSTR_ST              0x00000070	/* Timestamp second tens in BCD format */
  #define RTC_TSTR_ST_0            0x00000010
  #define RTC_TSTR_ST_1            0x00000020
  #define RTC_TSTR_ST_2            0x00000040
  #define RTC_TSTR_MNU             0x00000F00	/* Timestamp minute units in BCD format */
  #define RTC_TSTR_MNU_0           0x00000100
  #define RTC_TSTR_MNU_1           0x00000200
  #define RTC_TSTR_MNU_2           0x00000400
  #define RTC_TSTR_MNU_3           0x00000800
  #define RTC_TSTR_MNT             0x00007000	/* Timestamp minute tens in BCD format */
  #define RTC_TSTR_MNT_0           0x00001000
  #define RTC_TSTR_MNT_1           0x00002000
  #define RTC_TSTR_MNT_2           0x00004000
  #define RTC_TSTR_HU              0x000F0000	/* Timestamp hour units in BCD format */
  #define RTC_TSTR_HU_0            0x00010000
  #define RTC_TSTR_HU_1            0x00020000
  #define RTC_TSTR_HU_2            0x00040000
  #define RTC_TSTR_HU_3            0x00080000
  #define RTC_TSTR_HT              0x00300000	/* Timestamp hour tens in BCD format */
  #define RTC_TSTR_HT_0            0x00100000
  #define RTC_TSTR_HT_1            0x00200000
  #define RTC_TSTR_PM              0x00400000	/* Timestamp AM/PM or 24H format */
#define TOFF_RTC_TSDR       0x0034		/* (RW) RTC time stamp date register */
  #define RTC_TSDR_DU              0x0000000F	/* Timestamp date units in BCD format */
  #define RTC_TSDR_DU_0            0x00000001
  #define RTC_TSDR_DU_1            0x00000002
  #define RTC_TSDR_DU_2            0x00000004
  #define RTC_TSDR_DU_3            0x00000008
  #define RTC_TSDR_DT              0x00000030	/* Timestamp date tens in BCD format */
  #define RTC_TSDR_DT_0            0x00000010
  #define RTC_TSDR_DT_1            0x00000020
  #define RTC_TSDR_MU              0x00000F00	/* Timestamp month units in BCD format */
  #define RTC_TSDR_MU_0            0x00000100
  #define RTC_TSDR_MU_1            0x00000200
  #define RTC_TSDR_MU_2            0x00000400
  #define RTC_TSDR_MU_3            0x00000800
  #define RTC_TSDR_MT              0x00001000	/* Timestamp month tens in BCD format */
  #define RTC_TSDR_WDU             0x0000E000	/* Timestamp week day units */
  #define RTC_TSDR_WDU_0           0x00002000
  #define RTC_TSDR_WDU_1           0x00004000
  #define RTC_TSDR_WDU_2           0x00008000
#define TOFF_RTC_TSSSR      0x0038		/* (RW) RTC time-stamp sub second register */
#define TOFF_RTC_CALR       0x003C		/* (RW) RTC calibration register */
  #define RTC_CALR_CALM            0x000001FF	/* Calibration minus */
  #define RTC_CALR_CALM_0          0x00000001
  #define RTC_CALR_CALM_1          0x00000002
  #define RTC_CALR_CALM_2          0x00000004
  #define RTC_CALR_CALM_3          0x00000008
  #define RTC_CALR_CALM_4          0x00000010
  #define RTC_CALR_CALM_5          0x00000020
  #define RTC_CALR_CALM_6          0x00000040
  #define RTC_CALR_CALM_7          0x00000080
  #define RTC_CALR_CALM_8          0x00000100
  #define RTC_CALR_CALW16          0x00002000	/* Use a 16-second calibration cycle period */
  #define RTC_CALR_CALW8           0x00004000	/* Use a 8-second calibration cycle period */
  #define RTC_CALR_CALP            0x00008000	/* Increase frequency of RTC 488.5 ppm */
#define TOFF_RTC_TAMPCR     0x0040		/* (RW) RTC tamper configuration register */
  #define RTC_TAMPCR_TAMP1E        0x00000001	/* RTC_TAMP1 detection enable */
  #define RTC_TAMPCR_TAMP1TRG      0x00000002	/* Active level for RTC_TAMP1 input */
  #define RTC_TAMPCR_TAMPIE        0x00000004	/* Tampers interrupt enable */
  #define RTC_TAMPCR_TAMP2E        0x00000008	/* RTC_TAMP2 detection enable */
  #define RTC_TAMPCR_TAMP2TRG      0x00000010	/* Active level for RTC_TAMP2 input */
  #define RTC_TAMPCR_TAMP3E        0x00000020	/* RTC_TAMP3 detection enable */
  #define RTC_TAMPCR_TAMP3TRG      0x00000040	/* Active level for RTC_TAMP3 input */
  #define RTC_TAMPCR_TAMPTS        0x00000080	/* Activate timestamp on tamper detection event */
  #define RTC_TAMPCR_TAMPFREQ      0x00000700	/* Tamper sampling frequency */
  #define RTC_TAMPCR_TAMPFREQ_0    0x00000100
  #define RTC_TAMPCR_TAMPFREQ_1    0x00000200
  #define RTC_TAMPCR_TAMPFREQ_2    0x00000400
  #define RTC_TAMPCR_TAMPFLT       0x00001800	/* RTC_TAMPx filter count */
  #define RTC_TAMPCR_TAMPFLT_0     0x00000800
  #define RTC_TAMPCR_TAMPFLT_1     0x00001000
  #define RTC_TAMPCR_TAMPPRCH      0x00006000	/* RTC_TAMPx precharge duration */
  #define RTC_TAMPCR_TAMPPRCH_0    0x00002000
  #define RTC_TAMPCR_TAMPPRCH_1    0x00004000
  #define RTC_TAMPCR_TAMPPUDIS     0x00008000	/* RTC_TAMPx pull-up disable */
  #define RTC_TAMPCR_TAMP1IE       0x00010000	/* Tamper 1 interrupt enable */
  #define RTC_TAMPCR_TAMP1NOERASE  0x00020000	/* Tamper 1 no erase backup registers */
  #define RTC_TAMPCR_TAMP1MF       0x00040000	/* Tamper 1 generates a trigger event */
  #define RTC_TAMPCR_TAMP2IE       0x00080000	/* Tamper 2 interrupt enable */
  #define RTC_TAMPCR_TAMP2NOERASE  0x00100000	/* Tamper 2 no erase backup registers */
  #define RTC_TAMPCR_TAMP2MF       0x00200000	/* Tamper 2 generates a trigger event */
  #define RTC_TAMPCR_TAMP3IE       0x00400000	/* Tamper 3 interrupt enable */
  #define RTC_TAMPCR_TAMP3NOERASE  0x00800000	/* Tamper 3 no erase backup registers */
  #define RTC_TAMPCR_TAMP3MF       0x01000000	/* Tamper 3 generates a trigger event */
#define TOFF_RTC_ALRMASSR   0x0044		/* (RW) RTC alarm A sub second register */
  #define RTC_ALRMASSR_SS          0x00007FFF	/* Alarm A sub seconds value */
  #define RTC_ALRMASSR_MASKSS      0x0F000000	/* Alarm A mask the most-significant bits starting at this bit */
  #define RTC_ALRMASSR_MASKSS_0    0x01000000
  #define RTC_ALRMASSR_MASKSS_1    0x02000000
  #define RTC_ALRMASSR_MASKSS_2    0x04000000
  #define RTC_ALRMASSR_MASKSS_3    0x08000000
#define TOFF_RTC_ALRMBSSR   0x0048		/* (RW) RTC alarm B sub second register */
  #define RTC_ALRMBSSR_SS          0x00007FFF	/* Alarm B sub seconds value */
  #define RTC_ALRMBSSR_MASKSS      0x0F000000	/* Alarm B mask the most-significant bits starting at this bit */
  #define RTC_ALRMBSSR_MASKSS_0    0x01000000
  #define RTC_ALRMBSSR_MASKSS_1    0x02000000
  #define RTC_ALRMBSSR_MASKSS_2    0x04000000
  #define RTC_ALRMBSSR_MASKSS_3    0x08000000
#define TOFF_RTC_OR         0x004C		/* (RW) RTC option register */
  #define RTC_OR_ALARMOUTTYPE      0x00000001	/* RTC_ALARM on PC13 output type */
  #define RTC_OR_OUT_RMP           0x00000002	/* RTC_OUT remap */
#define TOFF_RTC_BKP0R      0x0050		/* (RW) RTC backup register 0 */
#define TOFF_RTC_BKP1R      0x0054		/* (RW) RTC backup register 1 */
#define TOFF_RTC_BKP2R      0x0058		/* (RW) RTC backup register 2 */
#define TOFF_RTC_BKP3R      0x005C		/* (RW) RTC backup register 3 */
#define TOFF_RTC_BKP4R      0x0060		/* (RW) RTC backup register 4 */
#define TOFF_RTC_BKP5R      0x0064		/* (RW) RTC backup register 5 */
#define TOFF_RTC_BKP6R      0x0068		/* (RW) RTC backup register 6 */
#define TOFF_RTC_BKP7R      0x006C		/* (RW) RTC backup register 7 */
#define TOFF_RTC_BKP8R      0x0070		/* (RW) RTC backup register 8 */
#define TOFF_RTC_BKP9R      0x0074		/* (RW) RTC backup register 9 */
#define TOFF_RTC_BKP10R     0x0078		/* (RW) RTC backup register 10 */
#define TOFF_RTC_BKP11R     0x007C		/* (RW) RTC backup register 11 */
#define TOFF_RTC_BKP12R     0x0080		/* (RW) RTC backup register 12 */
#define TOFF_RTC_BKP13R     0x0084		/* (RW) RTC backup register 13 */
#define TOFF_RTC_BKP14R     0x0088		/* (RW) RTC backup register 14 */
#define TOFF_RTC_BKP15R     0x008C		/* (RW) RTC backup register 15 */
#define TOFF_RTC_BKP16R     0x0090		/* (RW) RTC backup register 16 */
#define TOFF_RTC_BKP17R     0x0094		/* (RW) RTC backup register 17 */
#define TOFF_RTC_BKP18R     0x0098		/* (RW) RTC backup register 18 */
#define TOFF_RTC_BKP19R     0x009C		/* (RW) RTC backup register 19 */

/*
 *  WINDOW WATCHDOG
 */
#define TADR_WWDG_BASE      (APB1PERIPH_BASE + 0x2C00)
#define TOFF_WWDG_CR        0x0000		/* (RW) WWDG Control register */
  #define WWDG_CR_T           0x0000007F	/* T[6:0] bits (7-Bit counter (MSB to LSB)) */
  #define WWDG_CR_T_0         0x00000001
  #define WWDG_CR_T_1         0x00000002
  #define WWDG_CR_T_2         0x00000004
  #define WWDG_CR_T_3         0x00000008
  #define WWDG_CR_T_4         0x00000010
  #define WWDG_CR_T_5         0x00000020
  #define WWDG_CR_T_6         0x00000040
  #define WWDG_CR_T0          WWDG_CR_T_0
  #define WWDG_CR_T1          WWDG_CR_T_1
  #define WWDG_CR_T2          WWDG_CR_T_2
  #define WWDG_CR_T3          WWDG_CR_T_3
  #define WWDG_CR_T4          WWDG_CR_T_4
  #define WWDG_CR_T5          WWDG_CR_T_5
  #define WWDG_CR_T6          WWDG_CR_T_6
  #define WWDG_CR_WDGA        0x00000080	/* Activation bit */
#define TOFF_WWDG_CFR       0x0004		/* (RW) WWDG Configuration register */
  #define WWDG_CFR_W          0x0000007F	/* W[6:0] bits (7-bit window value) */
  #define WWDG_CFR_W_0        0x00000001
  #define WWDG_CFR_W_1        0x00000002
  #define WWDG_CFR_W_2        0x00000004
  #define WWDG_CFR_W_3        0x00000008
  #define WWDG_CFR_W_4        0x00000010
  #define WWDG_CFR_W_5        0x00000020
  #define WWDG_CFR_W_6        0x00000040
  #define WWDG_CFR_W0         WWDG_CFR_W_0
  #define WWDG_CFR_W1         WWDG_CFR_W_1
  #define WWDG_CFR_W2         WWDG_CFR_W_2
  #define WWDG_CFR_W3         WWDG_CFR_W_3
  #define WWDG_CFR_W4         WWDG_CFR_W_4
  #define WWDG_CFR_W5         WWDG_CFR_W_5
  #define WWDG_CFR_W6         WWDG_CFR_W_6
  #define WWDG_CFR_WDGTB      0x00003800	/* WDGTB[2:0] bits (Timer Base) */
  #define WWDG_CFR_WDGTB_0    0x00000800
  #define WWDG_CFR_WDGTB_1    0x00001000
  #define WWDG_CFR_WDGTB_2    0x00002000
  #define WWDG_CFR_WDGTB0     WWDG_CFR_WDGTB_0
  #define WWDG_CFR_WDGTB1     WWDG_CFR_WDGTB_1
  #define WWDG_CFR_WDGTB2     WWDG_CFR_WDGTB_2
  #define WWDG_CFR_EWI        0x00000200	/* Early Wakeup Interrupt */
#define TOFF_WWDG_SR        0x0008		/* (R)  WWDG Status register */
  #define WWDG_SR_EWIF        0x00000001	/* Early Wakeup Interrupt Flag */

/*
 *  INDEPENDENT WATCHDOG
 */
#define TADR_IWDG_BASE      (APB1PERIPH_BASE + 0x3000)
#define TOFF_IWDG_KR        0x0000		/* (RW) IWDG Key register */
#define TOFF_IWDG_PR        0x0004		/* (RW) IWDG Prescaler register */
  #define IWDG_PR_PR          0x00000007	/* PR[2:0] (Prescaler divider) */
  #define IWDG_PR_PR_0        0x00000001
  #define IWDG_PR_PR_1        0x00000002
  #define IWDG_PR_PR_2        0x00000004
#define TOFF_IWDG_RLR       0x0008		/* (RW) IWDG Reload register */
#define TOFF_IWDG_SR        0x000C		/* (RW) IWDG Status register */
  #define IWDG_SR_PVU         0x00000001	/* Watchdog prescaler value update */
  #define IWDG_SR_RVU         0x00000002	/* Watchdog counter reload value update */
  #define IWDG_SR_WVU         0x00000004	/* Watchdog counter window value update */
#define TOFF_IWDG_WINR      0x0010		/* (RW) IWDG Window register */

/*
 *  SERIAL PERIPHERAL IINTERFACE
 */
#define TADR_SPI2_BASE      (APB1PERIPH_BASE + 0x3800)
#define TADR_SPI1_BASE      (APB2PERIPH_BASE + 0x3000)
#define TOFF_SPI_CR1        0x0000		/* (RW) SPI control register 1 (not used in I2S mode) */
  #define SPI_CR1_CPHA             0x00000001	/* Clock Phase */
  #define SPI_CR1_CPOL             0x00000002	/* Clock Polarity */
  #define SPI_CR1_MSTR             0x00000004	/* Master Selection */
  #define SPI_CR1_BR               0x00000038	/* Baud Rate Control */
  #define SPI_CR1_BR_0             0x00000008	/* Bit 0 */
  #define SPI_CR1_BR_1             0x00000010	/* Bit 1 */
  #define SPI_CR1_BR_2             0x00000020	/* Bit 2 */
  #define SPI_CR1_SPE              0x00000040	/* SPI Enable */
  #define SPI_CR1_LSBFIRST         0x00000080	/* Frame Format */
  #define SPI_CR1_SSI              0x00000100	/* Internal slave select */
  #define SPI_CR1_SSM              0x00000200	/* Software slave management */
  #define SPI_CR1_RXONLY           0x00000400	/* Receive only */
  #define SPI_CR1_CRCL             0x00000800	/* CRC Length */
  #define SPI_CR1_CRCNEXT          0x00001000	/* Transmit CRC next */
  #define SPI_CR1_CRCEN            0x00002000	/* Hardware CRC calculation enable */
  #define SPI_CR1_BIDIOE           0x00004000	/* Output enable in bidirectional mode */
  #define SPI_CR1_BIDIMODE         0x00008000	/* Bidirectional data mode enable */
#define TOFF_SPI_CR2        0x0004		/* (RW) SPI control register 2 */
  #define SPI_CR2_RXDMAEN          0x00000001	/* Rx Buffer DMA Enable */
  #define SPI_CR2_TXDMAEN          0x00000002	/* Tx Buffer DMA Enable */
  #define SPI_CR2_SSOE             0x00000004	/* SS Output Enable */
  #define SPI_CR2_NSSP             0x00000008	/* NSS pulse management Enable */
  #define SPI_CR2_FRF              0x00000010	/* Frame Format */
  #define SPI_CR2_ERRIE            0x00000020	/* Error Interrupt Enable */
  #define SPI_CR2_RXNEIE           0x00000040	/* RX buffer Not Empty Interrupt Enable */
  #define SPI_CR2_TXEIE            0x00000080	/* Tx buffer Empty Interrupt Enable */
  #define SPI_CR2_DS               0x00000F00	/* DS[3:0] Data Size */
  #define SPI_CR2_DS_0             0x00000100
  #define SPI_CR2_DS_1             0x00000200
  #define SPI_CR2_DS_2             0x00000400
  #define SPI_CR2_DS_3             0x00000800
  #define SPI_CR2_FRXTH            0x00001000	/* FIFO reception Threshold */
  #define SPI_CR2_LDMARX           0x00002000	/* Last DMA transfer for reception */
  #define SPI_CR2_LDMATX           0x00004000	/* Last DMA transfer for transmission */
#define TOFF_SPI_SR         0x0008		/* (RW) SPI status register */
  #define SPI_SR_RXNE              0x00000001	/* Receive buffer Not Empty */
  #define SPI_SR_TXE               0x00000002	/* Transmit buffer Empty */
  #define SPI_SR_CRCERR            0x00000010	/* CRC Error flag */
  #define SPI_SR_MODF              0x00000020	/* Mode fault */
  #define SPI_SR_OVR               0x00000040	/* Overrun flag */
  #define SPI_SR_BSY               0x00000080	/* Busy flag */
  #define SPI_SR_FRE               0x00000100	/* Frame format error flag */
  #define SPI_SR_FRLVL             0x00000600	/* FIFO Reception Level */
  #define SPI_SR_FRLVL_0           0x00000200
  #define SPI_SR_FRLVL_1           0x00000400
  #define SPI_SR_FTLVL             0x00001800	/* FIFO Transmission Level */
  #define SPI_SR_FTLVL_0           0x00000800
  #define SPI_SR_FTLVL_1           0x00001000
#define TOFF_SPI_DR         0x000C		/* (RW) SPI data register */
#define TOFF_SPI_CRCPR      0x0010		/* (RW) SPI CRC polynomial register (not used in I2S mode) */
#define TOFF_SPI_RXCRCR     0x0014		/* (RW) SPI RX CRC register (not used in I2S mode) */
#define TOFF_SPI_TXCRCR     0x0018		/* (RW) SPI TX CRC register (not used in I2S mode) */

/*
 *  INTER-INTERATED CIRCUIT IINTERFACE
 */
#define TADR_I2C1_BASE      (APB1PERIPH_BASE + 0x5400)
#define TADR_I2C3_BASE      (APB1PERIPH_BASE + 0x5C00)
#define TOFF_I2C_CR1        0x0000		/* (RW) I2C Control register 1 */
  #define I2C_CR1_PE         0x00000001	/* Peripheral Enable */
  #define I2C_CR1_TXIE       0x00000002	/* TX interrupt enable */
  #define I2C_CR1_RXIE       0x00000004	/* RX interrupt enable */
  #define I2C_CR1_ADDRIE     0x00000008	/* Address match interrupt enable */
  #define I2C_CR1_NACKIE     0x00000010	/* NACK received interrupt enable */
  #define I2C_CR1_STOPIE     0x00000020	/* STOP detection interrupt enable */
  #define I2C_CR1_TCIE       0x00000040	/* Transfer complete interrupt enable */
  #define I2C_CR1_ERRIE      0x00000080	/* Errors interrupt enable */
  #define I2C_CR1_DNF        0x00000F00	/* Digital noise filter */
  #define I2C_CR1_ANFOFF     0x00001000	/* Analog noise filter OFF */
  #define I2C_CR1_SWRST      0x00002000	/* Software reset */
  #define I2C_CR1_TXDMAEN    0x00004000	/* DMA transmission requests enable */
  #define I2C_CR1_RXDMAEN    0x00008000	/* DMA reception requests enable */
  #define I2C_CR1_SBC        0x00010000	/* Slave byte control */
  #define I2C_CR1_NOSTRETCH  0x00020000	/* Clock stretching disable */
  #define I2C_CR1_WUPEN      0x00040000	/* Wakeup from STOP enable */
  #define I2C_CR1_GCEN       0x00080000	/* General call enable */
  #define I2C_CR1_SMBHEN     0x00100000	/* SMBus host address enable */
  #define I2C_CR1_SMBDEN     0x00200000	/* SMBus device default address enable */
  #define I2C_CR1_ALERTEN    0x00400000	/* SMBus alert enable */
  #define I2C_CR1_PECEN      0x00800000	/* PEC enable */
#define TOFF_I2C_CR2        0x0004		/* (RW) I2C Control register 2 */
  #define I2C_CR2_SADD       0x000003FF	/* Slave address (master mode) */
  #define I2C_CR2_RD_WRN     0x00000400	/* Transfer direction (master mode) */
  #define I2C_CR2_ADD10      0x00000800	/* 10-bit addressing mode (master mode) */
  #define I2C_CR2_HEAD10R    0x00001000	/* 10-bit address header only read direction (master mode) */
  #define I2C_CR2_START      0x00002000	/* START generation */
  #define I2C_CR2_STOP       0x00004000	/* STOP generation (master mode) */
  #define I2C_CR2_NACK       0x00008000	/* NACK generation (slave mode) */
  #define I2C_CR2_NBYTES     0x00FF0000	/* Number of bytes */
  #define I2C_CR2_RELOAD     0x01000000	/* NBYTES reload mode */
  #define I2C_CR2_AUTOEND    0x02000000	/* Automatic end mode (master mode) */
  #define I2C_CR2_PECBYTE    0x04000000	/* Packet error checking byte */
#define TOFF_I2C_OAR1       0x0008		/* (RW) I2C Own address register 1 */
  #define I2C_OAR1_OA1      0x000003FF	/* Interface own address 1 */
  #define I2C_OAR1_OA1MODE  0x00000400	/* Own address 1 10-bit mode */
  #define I2C_OAR1_OA1EN    0x00008000	/* Own address 1 enable */
#define TOFF_I2C_OAR2       0x000C		/* (RW) I2C Own address register 2 */
  #define I2C_OAR2_OA2       0x000000FE	/* Interface own address 2 */
  #define I2C_OAR2_OA2MSK    0x00000700	/* Own address 2 masks */
  #define I2C_OAR2_OA2NOMASK 0x00000000	/* No mask */
  #define I2C_OAR2_OA2MASK01 0x00000100	/* OA2[1] is masked, Only OA2[7:2] are compared */
  #define I2C_OAR2_OA2MASK02 0x00000200	/* OA2[2:1] is masked, Only OA2[7:3] are compared */
  #define I2C_OAR2_OA2MASK03 0x00000300	/* OA2[3:1] is masked, Only OA2[7:4] are compared */
  #define I2C_OAR2_OA2MASK04 0x00000400	/* OA2[4:1] is masked, Only OA2[7:5] are compared */
  #define I2C_OAR2_OA2MASK05 0x00000500	/* OA2[5:1] is masked, Only OA2[7:6] are compared */
  #define I2C_OAR2_OA2MASK06 0x00000600	/* OA2[6:1] is masked, Only OA2[7] are compared */
  #define I2C_OAR2_OA2MASK07 0x00000700	/* OA2[7:1] is masked, No comparison is done */
  #define I2C_OAR2_OA2EN     0x00008000	/* Own address 2 enable */
#define TOFF_I2C_TIMINGR    0x0010		/* (RW) I2C Timing register */
  #define I2C_TIMINGR_SCLL   0x000000FF	/* SCL low period (master mode) */
  #define I2C_TIMINGR_SCLH   0x0000FF00	/* SCL high period (master mode) */
  #define I2C_TIMINGR_SDADEL 0x000F0000	/* Data hold time */
  #define I2C_TIMINGR_SCLDEL 0x00F00000	/* Data setup time */
  #define I2C_TIMINGR_PRESC  0xF0000000	/* Timings prescaler */
#define TOFF_I2C_TIMEOUTR   0x0014		/* (RW) I2C Timeout register */
  #define I2C_TIMEOUTR_TIMEOUTA 0x00000FFF	/* Bus timeout A */
  #define I2C_TIMEOUTR_TIDLE    0x00001000	/* Idle clock timeout detection */
  #define I2C_TIMEOUTR_TIMOUTEN 0x00008000	/* Clock timeout enable */
  #define I2C_TIMEOUTR_TIMEOUTB 0x0FFF0000	/* Bus timeout B*/
  #define I2C_TIMEOUTR_TEXTEN   0x80000000	/* Extended clock timeout enable */
#define TOFF_I2C_ISR        0x0018		/* (RW) I2C Interrupt and status register */
  #define I2C_ISR_TXE        0x00000001	/* Transmit data register empty */
  #define I2C_ISR_TXIS       0x00000002	/* Transmit interrupt status */
  #define I2C_ISR_RXNE       0x00000004	/* Receive data register not empty */
  #define I2C_ISR_ADDR       0x00000008	/* Address matched (slave mode)*/
  #define I2C_ISR_NACKF      0x00000010	/* NACK received flag */
  #define I2C_ISR_STOPF      0x00000020	/* STOP detection flag */
  #define I2C_ISR_TC         0x00000040	/* Transfer complete (master mode) */
  #define I2C_ISR_TCR        0x00000080	/* Transfer complete reload */
  #define I2C_ISR_BERR       0x00000100	/* Bus error */
  #define I2C_ISR_ARLO       0x00000200	/* Arbitration lost */
  #define I2C_ISR_OVR        0x00000400	/* Overrun/Underrun */
  #define I2C_ISR_PECERR     0x00000800	/* PEC error in reception */
  #define I2C_ISR_TIMEOUT    0x00001000	/* Timeout or Tlow detection flag */
  #define I2C_ISR_ALERT      0x00002000	/* SMBus alert */
  #define I2C_ISR_BUSY       0x00008000	/* Bus busy */
  #define I2C_ISR_DIR        0x00010000	/* Transfer direction (slave mode) */
  #define I2C_ISR_ADDCODE    0x00FE0000	/* Address match code (slave mode) */
#define TOFF_I2C_ICR        0x001C		/* (RW) I2C Interrupt clear register */
  #define I2C_ICR_ADDRCF     0x00000008	/* Address matched clear flag */
  #define I2C_ICR_NACKCF     0x00000010	/* NACK clear flag */
  #define I2C_ICR_STOPCF     0x00000020	/* STOP detection clear flag */
  #define I2C_ICR_BERRCF     0x00000100	/* Bus error clear flag */
  #define I2C_ICR_ARLOCF     0x00000200	/* Arbitration lost clear flag */
  #define I2C_ICR_OVRCF      0x00000400	/* Overrun/Underrun clear flag */
  #define I2C_ICR_PECCF      0x00000800	/* PAC error clear flag */
  #define I2C_ICR_TIMOUTCF   0x00001000	/* Timeout clear flag */
  #define I2C_ICR_ALERTCF    0x00002000	/* Alert clear flag */
#define TOFF_I2C_PECR       0x0020		/* (RW) I2C PEC register */
  #define I2C_PECR_PEC       0x000000FF	/* PEC register */
#define TOFF_I2C_RXDR       0x0024		/* (RW) I2C Receive data register */
  #define I2C_RXDR_RXDATA    0x000000FF	/* 8-bit receive data */
#define TOFF_I2C_TXDR       0x0028		/* (RW) I2C Transmit data register */
  #define I2C_TXDR_TXDATA    0x000000FF	/* 8-bit transmit data */


/*
 *  CLOCK RECOVERY SYSTEM
 */
#define TADR_CRS_BASE       (APB1PERIPH_BASE + 0x6000)
#define TOFF_CRS_CR         0x0000		/* (RW) CRS ccontrol register */
  #define CRS_CR_SYNCOKIE    0x00000001	/* SYNC event OK interrupt enable */
  #define CRS_CR_SYNCWARNIE  0x00000002	/* SYNC warning interrupt enable */
  #define CRS_CR_ERRIE       0x00000004	/* SYNC error or trimming error interrupt enable */
  #define CRS_CR_ESYNCIE     0x00000008	/* Expected SYNC interrupt enable */
  #define CRS_CR_CEN         0x00000020	/* Frequency error counter enable */
  #define CRS_CR_AUTOTRIMEN  0x00000040	/* Automatic trimming enable */
  #define CRS_CR_SWSYNC      0x00000080	/* Generate software SYNC event */
  #define CRS_CR_TRIM        0x00003F00	/* HSI48 oscillator smooth trimming */
#define TOFF_CRS_CFGR       0x0004		/* (RW) CRS configuration register */
  #define CRS_CFGR_RELOAD    0x0000FFFF	/* Counter reload value */
  #define CRS_CFGR_FELIM     0x00FF0000	/* Frequency error limit */
  #define CRS_CFGR_SYNCDIV   0x07000000	/* SYNC divider */
  #define CRS_CFGR_SYNCDIV_0 0x01000000
  #define CRS_CFGR_SYNCDIV_1 0x02000000
  #define CRS_CFGR_SYNCDIV_2 0x04000000
  #define CRS_CFGR_SYNCSRC   0x30000000	/* SYNC signal source selection */
  #define CRS_CFGR_SYNCSRC_0 0x10000000
  #define CRS_CFGR_SYNCSRC_1 0x20000000
  #define CRS_CFGR_SYNCPOL   0x80000000	/* SYNC polarity selection */
#define TOFF_CRS_ISR        0x0008		/* (RW) CRS interrupt and status register */
  #define CRS_ISR_SYNCOKF    0x00000001	/* SYNC event OK flag */
  #define CRS_ISR_SYNCWARNF  0x00000002	/* SYNC warning flag */
  #define CRS_ISR_ERRF       0x00000004	/* Error flag */
  #define CRS_ISR_ESYNCF     0x00000008	/* Expected SYNC flag */
  #define CRS_ISR_SYNCERR    0x00000100	/* SYNC error */
  #define CRS_ISR_SYNCMISS   0x00000200	/* SYNC missed */
  #define CRS_ISR_TRIMOVF    0x00000400	/* Trimming overflow or underflow */
  #define CRS_ISR_FEDIR      0x00008000	/* Frequency error direction */
  #define CRS_ISR_FECAP      0xFFFF0000	/* Frequency error capture */
#define TOFF_CRS_ICR        0x000C		/* (RW) CRS interrupt flag clear register */
  #define CRS_ICR_SYNCOKC    0x00000001	/* SYNC event OK clear flag */
  #define CRS_ICR_SYNCWARNC  0x00000002	/* SYNC warning clear flag */
  #define CRS_ICR_ERRC       0x00000004	/* Error clear flag */
  #define CRS_ICR_ESYNCC     0x00000008	/* Expected SYNC clear flag */


/*
 *  UNIVERSAL SERIAL BUS FULL SPEED DEVICE
 */
#define TADR_USB1_BASE      (APB1PERIPH_BASE + 0x6800)
#define TADR_USB1_PMAADDR   (APB1PERIPH_BASE + 0x6C00)
#define TOFF_USB_EP0R       0x0000		/* (RW-16) USB Endpoint 0 register  */
  #define USB_EPADDR_FIELD   0x000F		/* EndPoint ADDRess FIELD */
  #define USB_EPTX_STAT      0x0030		/* EndPoint TX STATus bit field */
    #define USB_EP_TX_DIS    0x0000		/*  EndPoint TX DISabled */
    #define USB_EP_TX_STALL  0x0010		/*  EndPoint TX STALLed */
    #define USB_EP_TX_NAK    0x0020		/*  EndPoint TX NAKed */
    #define USB_EP_TX_VALID  0x0030		/*  EndPoint TX VALID */
    #define USB_EPTX_DTOG1   0x0010		/*  EndPoint TX Data TOGgle bit1 */
    #define USB_EPTX_DTOG2   0x0020		/*  EndPoint TX Data TOGgle bit2 */
    #define USB_EPTX_DTOGMASK  (USB_EPTX_STAT|USB_EPREG_MASK)
  #define USB_EP_DTOG_TX     0x0040		/* EndPoint Data TOGGLE TX */
  #define USB_EP_CTR_TX      0x0080		/* EndPoint Correct TRansfer TX */
  #define USB_EP_KIND        0x0100		/* EndPoint KIND */
  #define USB_EP_T_FIELD     0x0600		/* EndPoint TYPE */
    #define USB_EP_TYPE_MASK 0x0600		/*  EndPoint TYPE Mask */
    #define USB_EP_BULK      0x0000		/*  EndPoint BULK */
    #define USB_EP_CONTROL   0x0200		/*  EndPoint CONTROL */
    #define USB_EP_ISOCHRONOUS 0x0400	/*  EndPoint ISOCHRONOUS */
    #define USB_EP_INTERRUPT 0x0600		/*  EndPoint INTERRUPT */
  #define USB_EP_SETUP       0x0800		/* EndPoint SETUP */
  #define USB_EPRX_STAT      0x3000		/* EndPoint RX STATus bit field */
    #define USB_EP_RX_DIS    0x0000		/*  EndPoint RX DISabled */
    #define USB_EP_RX_STALL  0x1000		/*  EndPoint RX STALLed */
    #define USB_EP_RX_NAK    0x2000		/*  EndPoint RX NAKed */
    #define USB_EP_RX_VALID  0x3000		/*  EndPoint RX VALID */
    #define USB_EPRX_DTOG1   0x1000		/*  EndPoint RX Data TOGgle bit1 */
    #define USB_EPRX_DTOG2   0x2000		/*  EndPoint RX Data TOGgle bit1 */
    #define USB_EPRX_DTOGMASK  (USB_EPRX_STAT|USB_EPREG_MASK)
  #define USB_EP_DTOG_RX     0x4000		/* EndPoint Data TOGGLE RX */
  #define USB_EP_CTR_RX      0x8000		/* EndPoint Correct TRansfer RX */
  #define USB_EPREG_MASK     (USB_EP_CTR_RX|USB_EP_SETUP|USB_EP_T_FIELD|USB_EP_KIND|USB_EP_CTR_TX|USB_EPADDR_FIELD)
#define TOFF_USB_EP1R       0x0004		/* (RW-16) endpoint 1 register address */
#define TOFF_USB_EP2R       0x0008		/* (RW-16) endpoint 2 register address */
#define TOFF_USB_EP3R       0x000C		/* (RW-16) endpoint 3 register address */
#define TOFF_USB_EP4R       0x0010		/* (RW-16) endpoint 4 register address */
#define TOFF_USB_EP5R       0x0014		/* (RW-16) endpoint 5 register address */
#define TOFF_USB_EP6R       0x0018		/* (RW-16) endpoint 6 register address */
#define TOFF_USB_EP7R       0x001C		/* (RW-16) endpoint 7 register address */
#define TOFF_USB_CNTR       0x0040		/* (RW-16) Control register */
  #define USB_CNTR_FRES      0x0001		/* Force USB RESet */
  #define USB_CNTR_PDWN      0x0002		/* Power DoWN */
  #define USB_CNTR_LPMODE    0x0004		/* Low-power MODE */
  #define USB_CNTR_FSUSP     0x0008		/* Force SUSPend */
  #define USB_CNTR_RESUME    0x0010		/* RESUME request */
  #define USB_CNTR_L1RESUME  0x0020		/* LPM L1 Resume request */
  #define USB_CNTR_L1REQM    0x0080		/* LPM L1 state request interrupt mask */
  #define USB_CNTR_ESOFM     0x0100		/* Expected Start Of Frame Mask */
  #define USB_CNTR_SOFM      0x0200		/* Start Of Frame Mask */
  #define USB_CNTR_RESETM    0x0400		/* RESET Mask   */
  #define USB_CNTR_SUSPM     0x0800		/* SUSPend Mask */
  #define USB_CNTR_WKUPM     0x1000		/* WaKe UP Mask */
  #define USB_CNTR_ERRM      0x2000		/* ERRor Mask */
  #define USB_CNTR_PMAOVRM   0x4000		/* DMA OVeR/underrun Mask */
  #define USB_CNTR_CTRM      0x8000		/* Correct TRansfer Mask */
#define TOFF_USB_ISTR       0x0044		/* (RW-16) Interrupt status register */
  #define USB_ISTR_EP_ID     0x000F		/* EndPoint IDentifier (read-only bit)  */
  #define USB_ISTR_DIR       0x0010		/* DIRection of transaction (read-only bit)  */
  #define USB_ISTR_L1REQ     0x0080		/* LPM L1 state request  */
  #define USB_ISTR_ESOF      0x0100		/* Expected Start Of Frame (clear-only bit) */
  #define USB_ISTR_SOF       0x0200		/* Start Of Frame (clear-only bit) */
  #define USB_ISTR_RESET     0x0400		/* RESET (clear-only bit) */
  #define USB_ISTR_SUSP      0x0800		/* SUSPend (clear-only bit) */
  #define USB_ISTR_WKUP      0x1000		/* WaKe UP (clear-only bit) */
  #define USB_ISTR_ERR       0x2000		/* ERRor (clear-only bit) */
  #define USB_ISTR_PMAOVR    0x4000		/* DMA OVeR/underrun (clear-only bit) */
  #define USB_ISTR_CTR       0x8000		/* Correct TRansfer (clear-only bit) */
  #define USB_CLR_L1REQ      (~USB_ISTR_L1REQ)	/* clear LPM L1  bit */
  #define USB_CLR_ESOF       (~USB_ISTR_ESOF)	/* clear Expected Start Of Frame bit */
  #define USB_CLR_SOF        (~USB_ISTR_SOF)	/* clear Start Of Frame bit */
  #define USB_CLR_RESET      (~USB_ISTR_RESET)	/* clear RESET bit */
  #define USB_CLR_SUSP       (~USB_ISTR_SUSP)	/* clear SUSPend bit */
  #define USB_CLR_WKUP       (~USB_ISTR_WKUP)	/* clear WaKe UP bit */
  #define USB_CLR_ERR        (~USB_ISTR_ERR)	/* clear ERRor bit */
  #define USB_CLR_PMAOVR     (~USB_ISTR_PMAOVR)	/* clear DMA OVeR/underrun bit*/
  #define USB_CLR_CTR        (~USB_ISTR_CTR)	/* clear Correct TRansfer bit */
#define TOFF_USB_FNR        0x0048		/* (RW-16) Frame number register */
  #define USB_FNR_FN         0x07FF		/* Frame Number */
  #define USB_FNR_LSOF       0x1800		/* Lost SOF */
  #define USB_FNR_LCK        0x2000		/* LoCKed */
  #define USB_FNR_RXDM       0x4000		/* status of D- data line */
  #define USB_FNR_RXDP       0x8000		/* status of D+ data line */
#define TOFF_USB_DADDR      0x004C		/* (RW-16) Device address register */
  #define USB_DADDR_ADD      0x007F		/* USB device address */
  #define USB_DADDR_EF       0x0080		/* USB device address Enable Function */
#define TOFF_USB_BTABLE     0x0050		/* (RW-16) Buffer Table address register */
#define TOFF_USB_LPMCSR     0x0054		/* (RW-16) LPM Control and Status register */
  #define USB_LPMCSR_LMPEN  0x0001		/* LPM support enable  */
  #define USB_LPMCSR_LPMACK 0x0002		/* LPM Token acknowledge enable*/
  #define USB_LPMCSR_REMWAKE 0x0008		/* bRemoteWake value received with last ACKed LPM Token */
  #define USB_LPMCSR_BESL   0x00F0		/* BESL value received with last ACKed LPM Token  */ 
#define TOFF_USB_BCDR       0x0058		/* (RW-16) Battery Charging detector register */
  #define USB_BCDR_BCDEN     0x0001		/* Battery charging detector (BCD) enable */
  #define USB_BCDR_DCDEN     0x0002		/* Data contact detection (DCD) mode enable */
  #define USB_BCDR_PDEN      0x0004		/* Primary detection (PD) mode enable */
  #define USB_BCDR_SDEN      0x0008		/* Secondary detection (SD) mode enable */
  #define USB_BCDR_DCDET     0x0010		/* Data contact detection (DCD) status */
  #define USB_BCDR_PDET      0x0020		/* Primary detection (PD) status */
  #define USB_BCDR_SDET      0x0040		/* Secondary detection (SD) status */
  #define USB_BCDR_PS2DET    0x0080		/* PS2 port or proprietary charger detected */
  #define USB_BCDR_DPPU      0x8000		/* DP Pull-up Enable */


/*
 *  LOW POWER TIMIMER
 */
#define TADR_LPTIM1_BASE    (APB1PERIPH_BASE + 0x7C00)
#define TADR_LPTIM2_BASE    (APB1PERIPH_BASE + 0x9400)
#define TOFF_LPTIM_ISR      0x0000		/* (RW) LPTIM Interrupt and Status register */
  #define LPTIM_ISR_CMPM        0x00000001	/* Compare match */
  #define LPTIM_ISR_ARRM        0x00000002	/* Autoreload match */
  #define LPTIM_ISR_EXTTRIG     0x00000004	/* External trigger edge event */
  #define LPTIM_ISR_CMPOK       0x00000008	/* Compare register update OK */
  #define LPTIM_ISR_ARROK       0x00000010	/* Autoreload register update OK */
  #define LPTIM_ISR_UP          0x00000020	/* Counter direction change down to up */
  #define LPTIM_ISR_DOWN        0x00000040	/* Counter direction change up to down */
#define TOFF_LPTIM_ICR      0x0004		/* (RW) LPTIM Interrupt Clear register */
  #define LPTIM_ICR_CMPMCF      0x00000001	/* Compare match Clear Flag */
  #define LPTIM_ICR_ARRMCF      0x00000002	/* Autoreload match Clear Flag */
  #define LPTIM_ICR_EXTTRIGCF   0x00000004	/* External trigger edge event Clear Flag */
  #define LPTIM_ICR_CMPOKCF     0x00000008	/* Compare register update OK Clear Flag */
  #define LPTIM_ICR_ARROKCF     0x00000010	/* Autoreload register update OK Clear Flag */
  #define LPTIM_ICR_UPCF        0x00000020	/* Counter direction change down to up Clear Flag */
  #define LPTIM_ICR_DOWNCF      0x00000040	/* Counter direction change up to down Clear Flag */
#define TOFF_LPTIM_IER      0x0008		/* (RW) LPTIM Interrupt Enable register */
  #define LPTIM_IER_CMPMIE      0x00000001	/* Compare match Interrupt Enable */
  #define LPTIM_IER_ARRMIE      0x00000002	/* Autoreload match Interrupt Enable */
  #define LPTIM_IER_EXTTRIGIE   0x00000004	/* External trigger edge event Interrupt Enable */
  #define LPTIM_IER_CMPOKIE     0x00000008	/* Compare register update OK Interrupt Enable */
  #define LPTIM_IER_ARROKIE     0x00000010	/* Autoreload register update OK Interrupt Enable */
  #define LPTIM_IER_UPIE        0x00000020	/* Counter direction change down to up Interrupt Enable */
  #define LPTIM_IER_DOWNIE      0x00000040	/* Counter direction change up to down Interrupt Enable */
#define TOFF_LPTIM_CFGR     0x000C		/* (RW) LPTIM Configuration register */
  #define LPTIM_CFGR_CKSEL      0x00000001	/* Clock selector */
  #define LPTIM_CFGR_CKPOL      0x00000006	/* CKPOL[1:0] bits (Clock polarity) */
  #define LPTIM_CFGR_CKPOL_0    0x00000002
  #define LPTIM_CFGR_CKPOL_1    0x00000004
  #define LPTIM_CFGR_CKFLT      0x00000018	/* CKFLT[1:0] bits (Configurable digital filter for external clock) */
  #define LPTIM_CFGR_CKFLT_0    0x00000008
  #define LPTIM_CFGR_CKFLT_1    0x00000010
  #define LPTIM_CFGR_TRGFLT     0x000000C0	/* TRGFLT[1:0] bits (Configurable digital filter for trigger) */
  #define LPTIM_CFGR_TRGFLT_0   0x00000040
  #define LPTIM_CFGR_TRGFLT_1   0x00000080
  #define LPTIM_CFGR_PRESC      0x00000E00	/* PRESC[2:0] bits (Clock prescaler) */
  #define LPTIM_CFGR_PRESC_0    0x00000200
  #define LPTIM_CFGR_PRESC_1    0x00000400
  #define LPTIM_CFGR_PRESC_2    0x00000800
  #define LPTIM_CFGR_TRIGSEL    0x0000E000	/* TRIGSEL[2:0]] bits (Trigger selector) */
  #define LPTIM_CFGR_TRIGSEL_0  0x00002000
  #define LPTIM_CFGR_TRIGSEL_1  0x00004000
  #define LPTIM_CFGR_TRIGSEL_2  0x00008000
  #define LPTIM_CFGR_TRIGEN     0x00060000	/* TRIGEN[1:0] bits (Trigger enable and polarity) */
  #define LPTIM_CFGR_TRIGEN_0   0x00020000
  #define LPTIM_CFGR_TRIGEN_1   0x00040000
  #define LPTIM_CFGR_TIMOUT     0x00080000	/* Timeout enable */
  #define LPTIM_CFGR_WAVE       0x00100000	/* Waveform shape */
  #define LPTIM_CFGR_WAVPOL     0x00200000	/* Waveform shape polarity */
  #define LPTIM_CFGR_PRELOAD    0x00400000	/* Reg update mode */
  #define LPTIM_CFGR_COUNTMODE  0x00800000	/* Counter mode enable */
  #define LPTIM_CFGR_ENC        0x01000000	/* Encoder mode enable */
#define TOFF_LPTIM_CR       0x0010		/* (RW) LPTIM Control register */
  #define LPTIM_CR_ENABLE       0x00000001	/* LPTIMer enable */
  #define LPTIM_CR_SNGSTRT      0x00000002	/* Timer start in single mode */
  #define LPTIM_CR_CNTSTRT      0x00000004	/* Timer start in continuous mode */
  #define LPTIM_CR_COUNTRST     0x00000008	/* Counter reset */
  #define LPTIM_CR_RSTARE       0x00000010	/* Reset after read enable */
#define TOFF_LPTIM_CMP      0x0014		/* (RW) LPTIM Compare register */
#define TOFF_LPTIM_ARR      0x0018		/* (RW) LPTIM Autoreload register */
#define TOFF_LPTIM_CNT      0x001C		/* (RW) LPTIM Counter register */
#define TOFF_LPTIM_OR       0x0020		/* (RW) LPTIM Option register */
  #define LPTIM_OR_OR           0x00000003	/* OR[1:0] bits (Remap selection) */
  #define LPTIM_OR_OR_0         0x00000001
  #define LPTIM_OR_OR_1         0x00000002


/*
 *  UNIVERSAL SYNCHRONOUS ASYNCHORONOUS RECEIVER TRANSMITTER
 */
#define TADR_LPUART1_BASE   (APB1PERIPH_BASE + 0x8000)
#define TADR_USART1_BASE    (APB2PERIPH_BASE + 0x3800)
#define TOFF_USART_CR1      0x0000		/* (RW-32) USART Control register 1 */
  #define USART_CR1_UE       0x00000001	/* USART Enable */
  #define USART_CR1_UESM     0x00000002	/* USART Enable in STOP Mode */
  #define USART_CR1_RE       0x00000004	/* Receiver Enable */
  #define USART_CR1_TE       0x00000008	/* Transmitter Enable */
  #define USART_CR1_IDLEIE   0x00000010	/* IDLE Interrupt Enable */
  #define USART_CR1_RXNEIE   0x00000020	/* RXNE Interrupt Enable */
  #define USART_CR1_TCIE     0x00000040	/* Transmission Complete Interrupt Enable */
  #define USART_CR1_TXEIE    0x00000080	/* PE Interrupt Enable */
  #define USART_CR1_PEIE     0x00000100	/* PE Interrupt Enable */
  #define USART_CR1_PS       0x00000200	/* Parity Selection */
  #define USART_CR1_PCE      0x00000400	/* Parity Control Enable */
  #define USART_CR1_WAKE     0x00000800	/* Wakeup method */
  #define USART_CR1_M0       0x00001000	/* Word length bit 0 */
  #define USART_CR1_MME      0x00002000	/* Mute Mode Enable */
  #define USART_CR1_CMIE     0x00004000	/* Character match interrupt enable */
  #define USART_CR1_OVER8    0x00008000	/* Oversampling by 8-bit or 16-bit mode */
  #define USART_CR1_DEDT     0x001F0000	/* DEDT[4:0] bits (Driver Enable Deassertion Time) */
  #define USART_CR1_DEDT_0   0x00010000
  #define USART_CR1_DEDT_1   0x00020000
  #define USART_CR1_DEDT_2   0x00040000
  #define USART_CR1_DEDT_3   0x00080000
  #define USART_CR1_DEDT_4   0x00100000
  #define USART_CR1_DEAT     0x03E00000	/* DEAT[4:0] bits (Driver Enable Assertion Time) */
  #define USART_CR1_DEAT_0   0x00200000
  #define USART_CR1_DEAT_1   0x00400000
  #define USART_CR1_DEAT_2   0x00800000
  #define USART_CR1_DEAT_3   0x01000000
  #define USART_CR1_DEAT_4   0x02000000
  #define USART_CR1_RTOIE    0x04000000	/* Receive Time Out interrupt enable */
  #define USART_CR1_EOBIE    0x08000000	/* End of Block interrupt enable */
  #define USART_CR1_M1       0x10000000	/* Word length bit 1 */
  #define USART_CR1_M        0x10001000	/* [M1:M0] Word length */
  #define USART_CR1_FIFOEN   0x20000000	/* FIFO mode enable */
  #define USART_CR1_TXFEIE   0x40000000	/* TX FIFO Empty Interrupt Enable */
  #define USART_CR1_RXFFIE   0x80000000	/* RX FIFO Full Interrupt Enable */
#define TOFF_USART_CR2      0x0004		/* (RW-32) USART Control register 2 */
  #define USART_CR2_SLVEN    0x00000001	/* Synchronous Slave mode enable */
  #define USART_CR2_DIS_NSS  0x00000008	/* Slave Select (NSS) pin management */
  #define USART_CR2_ADDM7    0x00000010	/* 7-bit or 4-bit Address Detection */
  #define USART_CR2_LBDL     0x00000020	/* LIN Break Detection Length */
  #define USART_CR2_LBDIE    0x00000040	/* LIN Break Detection Interrupt Enable */
  #define USART_CR2_LBCL     0x00000100	/* Last Bit Clock pulse */
  #define USART_CR2_CPHA     0x00000200	/* Clock Phase */
  #define USART_CR2_CPOL     0x00000400	/* Clock Polarity */
  #define USART_CR2_CLKEN    0x00000800	/* Clock Enable */
  #define USART_CR2_STOP     0x00003000	/* STOP[1:0] bits (STOP bits) */
  #define USART_CR2_STOP_0   0x00001000	/* Bit 0 */
  #define USART_CR2_STOP_1   0x00002000	/* Bit 1 */
  #define USART_CR2_LINEN    0x00004000	/* LIN mode enable */
  #define USART_CR2_SWAP     0x00008000	/* SWAP TX/RX pins */
  #define USART_CR2_RXINV    0x00010000	/* RX pin active level inversion */
  #define USART_CR2_TXINV    0x00020000	/* TX pin active level inversion */
  #define USART_CR2_DATAINV  0x00040000	/* Binary data inversion */
  #define USART_CR2_MSBFIRST 0x00080000	/* Most Significant Bit First */
  #define USART_CR2_ABREN    0x00100000	/* Auto Baud-Rate Enable*/
  #define USART_CR2_ABRMODE  0x00600000	/* ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
  #define USART_CR2_ABRMODE_0 0x00200000
  #define USART_CR2_ABRMODE_1 0x00400000
  #define USART_CR2_RTOEN    0x00800000	/* Receiver Time-Out enable */
  #define USART_CR2_ADD      0xFF000000	/* Address of the USART node */
#define TOFF_USART_CR3      0x0008		/* (RW-32) USART Control register 3 */
  #define USART_CR3_EIE      0x00000001	/* Error Interrupt Enable */
  #define USART_CR3_IREN     0x00000002	/* IrDA mode Enable */
  #define USART_CR3_IRLP     0x00000004	/* IrDA Low-Power */
  #define USART_CR3_HDSEL    0x00000008	/* Half-Duplex Selection */
  #define USART_CR3_NACK     0x00000010	/* Smartcard NACK enable */
  #define USART_CR3_SCEN     0x00000020	/* Smartcard mode enable */
  #define USART_CR3_DMAR     0x00000040	/* DMA Enable Receiver */
  #define USART_CR3_DMAT     0x00000080	/* DMA Enable Transmitter */
  #define USART_CR3_RTSE     0x00000100	/* RTS Enable */
  #define USART_CR3_CTSE     0x00000200	/* CTS Enable */
  #define USART_CR3_CTSIE    0x00000400	/* CTS Interrupt Enable */
  #define USART_CR3_ONEBIT   0x00000800	/* USART One bit method enable */
  #define USART_CR3_OVRDIS   0x00001000	/* Overrun Disable */
  #define USART_CR3_DDRE     0x00002000	/* DMA Disable on Reception Error */
  #define USART_CR3_DEM      0x00004000	/* Driver Enable Mode */
  #define USART_CR3_DEP      0x00008000	/* Driver Enable Polarity Selection */
  #define USART_CR3_SCARCNT  0x000E0000	/* SCARCNT[2:0] bits (SmartCard Auto-Retry Count) */
  #define USART_CR3_SCARCNT_0 0x00020000
  #define USART_CR3_SCARCNT_1 0x00040000
  #define USART_CR3_SCARCNT_2 0x00080000
  #define USART_CR3_WUS      0x00300000	/* WUS[1:0] bits (Wake UP Interrupt Flag Selection) */
  #define USART_CR3_WUS_0    0x00100000
  #define USART_CR3_WUS_1    0x00200000
  #define USART_CR3_WUFIE    0x00400000	/* Wake Up Interrupt Enable */
  #define USART_CR3_TXFTIE   0x00800000	/* TX FIFO Threshold Interrupt Enable */
  #define USART_CR3_TCBGTIE  0x01000000	/* Transmission Complete Before Guard Time Interrupt Enable */
  #define USART_CR3_RXFTCFG  0x0E000000	/* RX FIFO Threshold Configuration */
  #define USART_CR3_RXFTCFG_0 0x02000000
  #define USART_CR3_RXFTCFG_1 0x04000000
  #define USART_CR3_RXFTCFG_2 0x08000000
  #define USART_CR3_RXFTIE   0x10000000	/* RX FIFO Threshold Interrupt Enable */
  #define USART_CR3_TXFTCFG  0xE0000000	/* TX FIFO Threshold configuration */
  #define USART_CR3_TXFTCFG_0 0x20000000
  #define USART_CR3_TXFTCFG_1 0x40000000/
  #define USART_CR3_TXFTCFG_2 0x80000000
#define TOFF_USART_BRR      0x000C		/* (RW-32) USART Baud rate register */
#define TOFF_USART_GTPR     0x0010		/* (RW-32) USART Guard time and prescaler register */
  #define USART_GTPR_PSC     0x000000FF	/* PSC[7:0] bits (Prescaler value) */
  #define USART_GTPR_PSC_0   0x00000001	/* Bit 0 */
  #define USART_GTPR_PSC_1   0x00000002	/* Bit 1 */
  #define USART_GTPR_PSC_2   0x00000004	/* Bit 2 */
  #define USART_GTPR_PSC_3   0x00000008	/* Bit 3 */
  #define USART_GTPR_PSC_4   0x00000010	/* Bit 4 */
  #define USART_GTPR_PSC_5   0x00000020	/* Bit 5 */
  #define USART_GTPR_PSC_6   0x00000040	/* Bit 6 */
  #define USART_GTPR_PSC_7   0x00000080	/* Bit 7 */
  #define USART_GTPR_GT      0x0000FF00	/* Guard time value */
#define TOFF_USART_RTOR     0x0014		/* (RW) USART Receiver Time Out register */
  #define USART_RTOR_RTO     0x00FFFFFF	/* Receiver Time Out Value */
  #define USART_RTOR_BLEN    0xFF000000	/* Block Length */
#define TOFF_USART_RQR      0x0018		/* (RW) USART Request register */
  #define USART_RQR_ABRRQ    0x00000001	/* Auto-Baud Rate Request */
  #define USART_RQR_SBKRQ    0x00000002	/* Send Break Request */
  #define USART_RQR_MMRQ     0x00000004	/* Mute Mode Request */
  #define USART_RQR_RXFRQ    0x00000008	/* Receive Data flush Request */
  #define USART_RQR_TXFRQ    0x00000010	/* Transmit data flush Request */
#define TOFF_USART_ISR      0x001C		/* (RW) USART Interrupt and status register */
  #define USART_ISR_PE       0x00000001	/* Parity Error */
  #define USART_ISR_FE       0x00000002	/* Framing Error */
  #define USART_ISR_NE       0x00000004	/* Noise detected Flag */
  #define USART_ISR_ORE      0x00000008	/* OverRun Error */
  #define USART_ISR_IDLE     0x00000010	/* IDLE line detected */
  #define USART_ISR_RXNE     0x00000020	/* Read Data Register Not Empty */
  #define USART_ISR_RXNE_RXFNE USART_ISR_RXNE	/* Read Data Register or RX FIFO Not Empty */
  #define USART_ISR_TC       0x00000040	/* Transmission Complete */
  #define USART_ISR_TXE      0x00000080	/* Transmit Data Register Empty */
  #define USART_ISR_TXE_TXFNF  USART_ISR_TXE	/* Transmit Data Register Empty or TX FIFO Not Full Flag */
  #define USART_ISR_LBDF     0x00000100	/* LIN Break Detection Flag */
  #define USART_ISR_CTSIF    0x00000200	/* CTS interrupt flag */
  #define USART_ISR_CTS      0x00000400	/* CTS flag */
  #define USART_ISR_RTOF     0x00000800	/* Receiver Time Out */
  #define USART_ISR_EOBF     0x00001000	/* End Of Block Flag */
  #define USART_ISR_UDR      0x00002000	/* SPI Slave Underrun error Flag */
  #define USART_ISR_ABRE     0x00004000	/* Auto-Baud Rate Error */
  #define USART_ISR_ABRF     0x00008000	/* Auto-Baud Rate Flag */
  #define USART_ISR_BUSY     0x00010000	/* Busy Flag */
  #define USART_ISR_CMF      0x00020000	/* Character Match Flag */
  #define USART_ISR_SBKF     0x00040000	/* Send Break Flag */
  #define USART_ISR_RWU      0x00080000	/* Receive Wake Up from mute mode Flag */
  #define USART_ISR_WUF      0x00100000	/* Wake Up from stop mode Flag */
  #define USART_ISR_TEACK    0x00200000	/* Transmit Enable Acknowledge Flag */
  #define USART_ISR_REACK    0x00400000	/* Receive Enable Acknowledge Flag */
  #define USART_ISR_TXFE     0x00800000	/* TX FIFO Empty Flag */
  #define USART_ISR_RXFF     0x01000000	/* RX FIFO Full Flag */
  #define USART_ISR_TCBGT    0x02000000	/* Transmission Complete Before Guard Time completion */
  #define USART_ISR_RXFT     0x04000000	/* RX FIFO Threshold Flag */
  #define USART_ISR_TXFT     0x08000000	/* TX FIFO Threshold Flag */
#define TOFF_USART_ICR      0x0020		/* (RW) USART Interrupt flag Clear register */
  #define USART_ICR_PECF     0x00000001	/* Parity Error Clear Flag */
  #define USART_ICR_FECF     0x00000002	/* Framing Error Clear Flag */
  #define USART_ICR_NCF      0x00000004	/* Noise detected Clear Flag */
  #define USART_ICR_ORECF    0x00000008	/* OverRun Error Clear Flag */
  #define USART_ICR_IDLECF   0x00000010	/* IDLE line detected Clear Flag */
  #define USART_ICR_TXFECF   0x00000020	/* TX FIFO Empty Clear Flag */
  #define USART_ICR_TCCF     0x00000040	/* Transmission Complete Clear Flag */
  #define USART_ICR_TCBGTCF  0x00000080	/* Transmission Complete Before Guard Time Clear Flag */
  #define USART_ICR_LBDCF    0x00000100	/* LIN Break Detection Clear Flag */
  #define USART_ICR_CTSCF    0x00000200	/* CTS Interrupt Clear Flag */
  #define USART_ICR_RTOCF    0x00000800	/* Receiver Time Out Clear Flag */
  #define USART_ICR_EOBCF    0x00001000	/* End Of Block Clear Flag */
  #define USART_ICR_UDRCF    0x00002000	/* SPI Slave Underrun Clear Flag */
  #define USART_ICR_CMCF     0x00020000	/* Character Match Clear Flag */
  #define USART_ICR_WUCF     0x00100000	/* Wake Up from stop mode Clear Flag */
#define TOFF_USART_RDR      0x0024		/* (RW-16) USART Receive Data register */
  #define USART_RDR_RDR      0x01FF		/* RDR[8:0] bits (Receive Data value) */
#define TOFF_USART_TDR      0x0028		/* (RW-16) USART Transmit Data register */
  #define USART_TDR_TDR      0x01FF		/* TDR[8:0] bits (Transmit Data value) */
#define TOFF_USART_PRESC    0x002C		/* Prescaler register */
  #define USART_PRESC_PRESCALER   0x0000000F	/* PRESCALER[3:0] bits (Clock prescaler) */
  #define USART_PRESC_PRESCALER_0 0x00000001
  #define USART_PRESC_PRESCALER_1 0x00000002
  #define USART_PRESC_PRESCALER_2 0x00000004
  #define USART_PRESC_PRESCALER_3 0x00000008


/*
 *  SYSTEM CONFIGURATION CONTROLLER
 */
#define TADR_SYSCFG_BASE    (APB2PERIPH_BASE + 0x0000)
#define TOFF_SYSCFG_MEMRMP  0x0000		/* (RW) SYSCFG memory remap register */
  #define SYSCFG_MEMRMP_MEM_MODE 0x00000007	/* SYSCFG_Memory Remap Config */
  #define SYSCFG_MEMRMP_MEM_MODE_0 0x00000001
  #define SYSCFG_MEMRMP_MEM_MODE_1 0x00000002
  #define SYSCFG_MEMRMP_MEM_MODE_2 0x00000004
#define TOFF_SYSCFG_CFGR1   0x0004		/* (RW) SYSCFG configuration register 1 */
  #define SYSCFG_CFGR1_BOOSTEN  0x00000100	/* I/O analog switch voltage booster enable */
  #define SYSCFG_CFGR1_ANASWVDD 0x00000200	/* I/O analog switch voltage selection */
  #define SYSCFG_CFGR1_I2C_PB6_FMP 0x00010000	/* I2C PB6 Fast mode plus */
  #define SYSCFG_CFGR1_I2C_PB7_FMP 0x00020000	/* I2C PB7 Fast mode plus */
  #define SYSCFG_CFGR1_I2C_PB8_FMP 0x00040000	/* I2C PB8 Fast mode plus */
  #define SYSCFG_CFGR1_I2C_PB9_FMP 0x00080000	/* I2C PB9 Fast mode plus */
  #define SYSCFG_CFGR1_I2C1_FMP 0x00100000	/* I2C1 Fast mode plus */
  #define SYSCFG_CFGR1_I2C3_FMP 0x00400000	/* I2C3 Fast mode plus */
  #define SYSCFG_CFGR1_FPU_IE_0 0x04000000	/* Invalid operation Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_1 0x08000000	/* Divide-by-zero Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_2 0x10000000	/* Underflow Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_3 0x20000000	/* Overflow Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_4 0x40000000	/* Input denormal Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_5 0x80000000	/* Inexact Interrupt enable (interrupt disabled at reset) */
#define TOFF_SYSCFG_EXTICR  0x0008		/* (RW) SYSCFG external interrupt configuration registers */
#define TOFF_SYSCFG_EXTICR1 0x0008		/* (RW) SYSCFG external interrupt configuration registers 1 */
  #define SYSCFG_EXTICR1_EXTI0  0x00000007	/* EXTI 0 configuration */
  #define SYSCFG_EXTICR1_EXTI1  0x00000070	/* EXTI 1 configuration */
  #define SYSCFG_EXTICR1_EXTI2  0x00000700	/* EXTI 2 configuration */
  #define SYSCFG_EXTICR1_EXTI3  0x00007000	/* EXTI 3 configuration */
  #define SYSCFG_EXTICR1_EXTI0_PA   0x00000000	/* PA[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PB   0x00000001	/* PB[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PC   0x00000002	/* PC[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PD   0x00000003	/* PD[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PE   0x00000004	/* PE[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PH   0x00000007	/* PH[0] pin */
  #define SYSCFG_EXTICR1_EXTI1_PA   0x00000000	/* PA[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PB   0x00000010	/* PB[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PC   0x00000020	/* PC[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PD   0x00000030	/* PD[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PE   0x00000040	/* PE[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PH   0x00000070	/* PH[1] pin */
  #define SYSCFG_EXTICR1_EXTI2_PA   0x00000000	/* PA[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PB   0x00000100	/* PB[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PC   0x00000200	/* PC[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PD   0x00000300	/* PD[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PE   0x00000400	/* PE[2] pin */
  #define SYSCFG_EXTICR1_EXTI3_PA   0x00000000	/* PA[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PB   0x00001000	/* PB[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PC   0x00002000	/* PC[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PD   0x00003000	/* PD[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PE   0x00004000	/* PE[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PH   0x00007000	/* PH[3] pin */
#define TOFF_SYSCFG_EXTICR2 0x000C		/* (RW) SYSCFG external interrupt configuration registers 2 */
  #define SYSCFG_EXTICR2_EXTI4  0x00000007	/* EXTI 4 configuration */
  #define SYSCFG_EXTICR2_EXTI5  0x00000070	/* EXTI 5 configuration */
  #define SYSCFG_EXTICR2_EXTI6  0x00000700	/* EXTI 6 configuration */
  #define SYSCFG_EXTICR2_EXTI7  0x00007000	/* EXTI 7 configuration */
  #define SYSCFG_EXTICR2_EXTI4_PA   0x00000000	/* PA[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PB   0x00000001	/* PB[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PC   0x00000002	/* PC[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PD   0x00000003	/* PD[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PE   0x00000004	/* PE[4] pin */
  #define SYSCFG_EXTICR2_EXTI5_PA   0x00000000	/* PA[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PB   0x00000010	/* PB[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PC   0x00000020	/* PC[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PD   0x00000030	/* PD[5] pin */
  #define SYSCFG_EXTICR2_EXTI6_PA   0x00000000	/* PA[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PB   0x00000100	/* PB[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PC   0x00000200	/* PC[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PD   0x00000300	/* PD[6] pin */
  #define SYSCFG_EXTICR2_EXTI7_PA   0x00000000	/* PA[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PB   0x00001000	/* PB[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PC   0x00002000	/* PC[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PD   0x00003000	/* PD[7] pin */
#define TOFF_SYSCFG_EXTICR3 0x0010		/* (RW) SYSCFG external interrupt configuration registers 3 */
  #define SYSCFG_EXTICR3_EXTI8  0x00000007	/* EXTI 8 configuration */
  #define SYSCFG_EXTICR3_EXTI9  0x00000070	/* EXTI 9 configuration */
  #define SYSCFG_EXTICR3_EXTI10 0x00000700	/* EXTI 10 configuration */
  #define SYSCFG_EXTICR3_EXTI11 0x0000F000	/* EXTI 11 configuration */
  #define SYSCFG_EXTICR3_EXTI8_PA   0x00000000	/* PA[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PB   0x00000001	/* PB[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PC   0x00000002	/* PC[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PD   0x00000003	/* PD[8] pin */
  #define SYSCFG_EXTICR3_EXTI9_PA   0x00000000	/* PA[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PB   0x00000010	/* PB[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PC   0x00000020	/* PC[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PD   0x00000030	/* PD[9] pin */
  #define SYSCFG_EXTICR3_EXTI10_PA  0x00000000	/* PA[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PB  0x00000100	/* PB[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PC  0x00000200	/* PC[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PD  0x00000300	/* PD[10] pin */
  #define SYSCFG_EXTICR3_EXTI11_PA  0x00000000	/* PA[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PB  0x00001000	/* PB[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PC  0x00002000	/* PC[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PD  0x00003000	/* PD[11] pin */
#define TOFF_SYSCFG_EXTICR4 0x0018		/* (RW) SYSCFG external interrupt configuration registers 4 */
  #define SYSCFG_EXTICR4_EXTI12 0x00000007	/* EXTI 12 configuration */
  #define SYSCFG_EXTICR4_EXTI13 0x00000070	/* EXTI 13 configuration */
  #define SYSCFG_EXTICR4_EXTI14 0x00000700	/* EXTI 14 configuration */
  #define SYSCFG_EXTICR4_EXTI15 0x00007000	/* EXTI 15 configuration */
  #define SYSCFG_EXTICR4_EXTI12_PA  0x00000000	/* PA[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PB  0x00000001	/* PB[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PC  0x00000002	/* PC[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PD  0x00000003	/* PD[12] pin */
  #define SYSCFG_EXTICR4_EXTI13_PA  0x00000000	/* PA[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PB  0x00000010	/* PB[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PC  0x00000020	/* PC[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PD  0x00000030	/* PD[13] pin */
  #define SYSCFG_EXTICR4_EXTI14_PA  0x00000000	/* PA[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PB  0x00000100	/* PB[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PC  0x00000200	/* PC[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PD  0x00000300	/* PD[14] pin */
  #define SYSCFG_EXTICR4_EXTI15_PA  0x00000000	/* PA[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PB  0x00001000	/* PB[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PC  0x00002000	/* PC[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PD  0x00003000	/* PD[15] pin */
#define TOFF_SYSCFG_SCSR    0x0018		/* (RW) SYSCFG SRAM2 control and status register */
  #define SYSCFG_SCSR_SRAM2ER   0x00000001	/* SRAM2 Erase Request */
  #define SYSCFG_SCSR_SRAM2BSY  0x00000002	/* SRAM2 Erase Ongoing */
  #define SYSCFG_SCSR_C2RFD     0x80000000	/* CPU2 SRAM fetch (execution) disable */
#define TOFF_SYSCFG_CFGR2   0x001C		/* (RW) SYSCFG configuration register 2 */
  #define SYSCFG_CFGR2_CLL   0x00000001	/* Core Lockup Lock */
  #define SYSCFG_CFGR2_SPL   0x00000002	/* SRAM Parity Lock*/
  #define SYSCFG_CFGR2_PVDL  0x00000004	/* PVD Lock */
  #define SYSCFG_CFGR2_ECCL  0x00000008	/* ECC Lock*/
  #define SYSCFG_CFGR2_SPF   0x00000100	/* SRAM Parity Flag */
#define TOFF_SYSCFG_SWPR1   0x0020		/* (RW) SYSCFG SRAM2 write protection register */
  #define SYSCFG_SWPR1_PAGE0  0x00000001	/* SRAM2 Write protection page 0 */
  #define SYSCFG_SWPR1_PAGE1  0x00000002	/* SRAM2 Write protection page 1 */
  #define SYSCFG_SWPR1_PAGE2  0x00000004	/* SRAM2 Write protection page 2 */
  #define SYSCFG_SWPR1_PAGE3  0x00000008	/* SRAM2 Write protection page 3 */
  #define SYSCFG_SWPR1_PAGE4  0x00000010	/* SRAM2 Write protection page 4 */
  #define SYSCFG_SWPR1_PAGE5  0x00000020	/* SRAM2 Write protection page 5 */
  #define SYSCFG_SWPR1_PAGE6  0x00000040	/* SRAM2 Write protection page 6 */
  #define SYSCFG_SWPR1_PAGE7  0x00000080	/* SRAM2 Write protection page 7 */
  #define SYSCFG_SWPR1_PAGE8  0x00000100	/* SRAM2 Write protection page 8 */
  #define SYSCFG_SWPR1_PAGE9  0x00000200	/* SRAM2 Write protection page 9 */
  #define SYSCFG_SWPR1_PAGE10 0x00000400	/* SRAM2 Write protection page 10*/
  #define SYSCFG_SWPR1_PAGE11 0x00000800	/* SRAM2 Write protection page 11*/
  #define SYSCFG_SWPR1_PAGE12 0x00001000	/* SRAM2 Write protection page 12*/
  #define SYSCFG_SWPR1_PAGE13 0x00002000	/* SRAM2 Write protection page 13*/
  #define SYSCFG_SWPR1_PAGE14 0x00004000	/* SRAM2 Write protection page 14*/
  #define SYSCFG_SWPR1_PAGE15 0x00008000	/* SRAM2 Write protection page 15*/
  #define SYSCFG_SWPR1_PAGE16 0x00010000	/* SRAM2 Write protection page 16*/
  #define SYSCFG_SWPR1_PAGE17 0x00020000	/* SRAM2 Write protection page 17*/
  #define SYSCFG_SWPR1_PAGE18 0x00040000	/* SRAM2 Write protection page 18*/
  #define SYSCFG_SWPR1_PAGE19 0x00080000	/* SRAM2 Write protection page 19*/
  #define SYSCFG_SWPR1_PAGE20 0x00100000	/* SRAM2 Write protection page 20*/
  #define SYSCFG_SWPR1_PAGE21 0x00200000	/* SRAM2 Write protection page 21*/
  #define SYSCFG_SWPR1_PAGE22 0x00400000	/* SRAM2 Write protection page 22*/
  #define SYSCFG_SWPR1_PAGE23 0x00800000	/* SRAM2 Write protection page 23*/
  #define SYSCFG_SWPR1_PAGE24 0x01000000	/* SRAM2 Write protection page 24*/
  #define SYSCFG_SWPR1_PAGE25 0x02000000	/* SRAM2 Write protection page 25*/
  #define SYSCFG_SWPR1_PAGE26 0x04000000	/* SRAM2 Write protection page 26*/
  #define SYSCFG_SWPR1_PAGE27 0x08000000	/* SRAM2 Write protection page 27*/
  #define SYSCFG_SWPR1_PAGE28 0x10000000	/* SRAM2 Write protection page 28*/
  #define SYSCFG_SWPR1_PAGE29 0x20000000	/* SRAM2 Write protection page 29*/
  #define SYSCFG_SWPR1_PAGE30 0x40000000	/* SRAM2 Write protection page 30*/
  #define SYSCFG_SWPR1_PAGE31 0x80000000	/* SRAM2 Write protection page 31*/
#define TOFF_SYSCFG_SKR     0x0024		/* (RW) SYSCFG SRAM2 key register */
  #define SYSCFG_SKR_KEY     0x000000FF	/* SRAM2 write protection key for software erase  */
#define TOFF_SYSCFG_SWPR2   0x0028		/* (RW) SYSCFG write protection register part 2 */
  #define SYSCFG_SWPR2_PAGE32 0x00000001	/* SRAM2B Write protection page 0 (0x20038000 ・0x200383FF)   */
  #define SYSCFG_SWPR2_PAGE33 0x00000002	/* SRAM2B Write protection page 1 (0x20038400 ・0x200387FF)   */
  #define SYSCFG_SWPR2_PAGE34 0x00000004	/* SRAM2B Write protection page 2 (0x20038800 ・0x20038bFF)   */
  #define SYSCFG_SWPR2_PAGE35 0x00000008	/* SRAM2B Write protection page 3 (0x20038C00 ・0x20038FFF)   */
  #define SYSCFG_SWPR2_PAGE36 0x00000010	/* SRAM2B Write protection page 4 (0x20039000 ・0x200393FF)   */
  #define SYSCFG_SWPR2_PAGE37 0x00000020	/* SRAM2B Write protection page 5 (0x20039400 ・0x200397FF)   */
  #define SYSCFG_SWPR2_PAGE38 0x00000040	/* SRAM2B Write protection page 6 (0x20039800 ・0x20039BFF)   */
  #define SYSCFG_SWPR2_PAGE39 0x00000080	/* SRAM2B Write protection page 7 (0x20039C00 ・0x20039FFF)   */
  #define SYSCFG_SWPR2_PAGE40 0x00000100	/* SRAM2B Write protection page 8 (0x2003A000 ・0x2003A3FF)   */
  #define SYSCFG_SWPR2_PAGE41 0x00000200	/* SRAM2B Write protection page 9 (0x2003A400 ・0x2003A7FF)   */
  #define SYSCFG_SWPR2_PAGE42 0x00000400	/* SRAM2B Write protection page 10 (0x2003A800 ・0x2003ABFF)  */
  #define SYSCFG_SWPR2_PAGE43 0x00000800	/* SRAM2B Write protection page 11 (0x2003AC00 ・0x2003AFFF)  */
  #define SYSCFG_SWPR2_PAGE44 0x00001000	/* SRAM2B Write protection page 12 (0x2003B000 ・0x2003B3FF)  */
  #define SYSCFG_SWPR2_PAGE45 0x00002000	/* SRAM2B Write protection page 13 (0x2003B400 ・0x2003B7FF)  */
  #define SYSCFG_SWPR2_PAGE46 0x00004000	/* SRAM2B Write protection page 14 (0x2003B800 ・0x2003BBFF)  */
  #define SYSCFG_SWPR2_PAGE47 0x00008000	/* SRAM2B Write protection page 15 (0x2003BC00 ・0x2003BFFF)  */
  #define SYSCFG_SWPR2_PAGE48 0x00010000	/* SRAM2B Write protection page 16 (0x2003C000 ・0x2003C3FF)  */
  #define SYSCFG_SWPR2_PAGE49 0x00020000	/* SRAM2B Write protection page 17 (0x2003C400 ・0x2003C7FF)  */
  #define SYSCFG_SWPR2_PAGE50 0x00040000	/* SRAM2B Write protection page 18 (0x2003C800 ・0x2003CBFF)  */
  #define SYSCFG_SWPR2_PAGE51 0x00080000	/* SRAM2B Write protection page 19 (0x2003CC00 ・0x2003CFFF)  */
  #define SYSCFG_SWPR2_PAGE52 0x00100000	/* SRAM2B Write protection page 20 (0x2003D000 ・0x2003D3FF)  */
  #define SYSCFG_SWPR2_PAGE53 0x00200000	/* SRAM2B Write protection page 21 (0x2003D400 ・0x2003D7FF)  */
  #define SYSCFG_SWPR2_PAGE54 0x00400000	/* SRAM2B Write protection page 22 (0x2003D800 ・0x2003DBFF)  */
  #define SYSCFG_SWPR2_PAGE55 0x00800000	/* SRAM2B Write protection page 23 (0x2003DC00 ・0x2003DFFF)  */
  #define SYSCFG_SWPR2_PAGE56 0x01000000	/* SRAM2B Write protection page 24 (0x2003E000 ・0x2003E3FF)  */
  #define SYSCFG_SWPR2_PAGE57 0x02000000	/* SRAM2B Write protection page 25 (0x2003E400 ・0x2003E7FF)  */
  #define SYSCFG_SWPR2_PAGE58 0x04000000	/* SRAM2B Write protection page 26 (0x2003E800 ・0x2003EBFF)  */
  #define SYSCFG_SWPR2_PAGE59 0x08000000	/* SRAM2B Write protection page 27 (0x2003EC00 ・0x2003EFFF)  */
  #define SYSCFG_SWPR2_PAGE60 0x10000000	/* SRAM2B Write protection page 28 (0x2003F000 ・0x2003F3FF)  */
  #define SYSCFG_SWPR2_PAGE61 0x20000000	/* SRAM2B Write protection page 29 (0x2003F400 ・0x2003F7FF)  */
  #define SYSCFG_SWPR2_PAGE62 0x40000000	/* SRAM2B Write protection page 30 (0x2003F800 ・0x2003FBFF)  */
  #define SYSCFG_SWPR2_PAGE63 0x80000000	/* SRAM2B Write protection page 31 (0x2003FC00 ・0x2003FFFF)  */
#define TOFF_SYSCFG_IMR1    0x0100		/* (RW) SYSCFG CPU1 (CORTEX M4) interrupt masks control-status register part 1 */
  #define SYSCFG_IMR1_TIM1IM  0x00002000	/* Enabling of interrupt from Timer 1 to CPU1 */
  #define SYSCFG_IMR1_TIM16IM 0x00004000	/* Enabling of interrupt from Timer 16 to CPU1 */
  #define SYSCFG_IMR1_TIM17IM 0x00008000	/* Enabling of interrupt from Timer 17 to CPU1 */
  #define SYSCFG_IMR1_EXTI5IM 0x00200000	/* Enabling of interrupt from External Interrupt Line 5 to CPU1 */
  #define SYSCFG_IMR1_EXTI6IM 0x00400000	/* Enabling of interrupt from External Interrupt Line 6 to CPU1 */
  #define SYSCFG_IMR1_EXTI7IM 0x00800000	/* Enabling of interrupt from External Interrupt Line 7 to CPU1 */
  #define SYSCFG_IMR1_EXTI8IM 0x01000000	/* Enabling of interrupt from External Interrupt Line 8 to CPU1 */
  #define SYSCFG_IMR1_EXTI9IM 0x02000000	/* Enabling of interrupt from External Interrupt Line 9 to CPU1 */
  #define SYSCFG_IMR1_EXTI10IM 0x04000000	/* Enabling of interrupt from External Interrupt Line 10 to CPU1 */
  #define SYSCFG_IMR1_EXTI11IM 0x08000000	/* Enabling of interrupt from External Interrupt Line 11 to CPU1 */
  #define SYSCFG_IMR1_EXTI12IM 0x10000000	/* Enabling of interrupt from External Interrupt Line 12 to CPU1 */
  #define SYSCFG_IMR1_EXTI13IM 0x20000000	/* Enabling of interrupt from External Interrupt Line 13 to CPU1 */
  #define SYSCFG_IMR1_EXTI14IM 0x40000000	/* Enabling of interrupt from External Interrupt Line 14 to CPU1 */
  #define SYSCFG_IMR1_EXTI15IM 0x80000000	/* Enabling of interrupt from External Interrupt Line 15 to CPU1 */
#define TOFF_SYSCFG_IMR2    0x0104		/* (RW) SYSCFG CPU1 (CORTEX M4) interrupt masks control-status register part 2 */
  #define SYSCFG_IMR2_PVM1IM  0x00010000	/* Enabling of interrupt from Power Voltage Monitoring 1 to CPU1 */
  #define SYSCFG_IMR2_PVM3IM  0x00040000	/* Enabling of interrupt from Power Voltage Monitoring 3 to CPU1 */
  #define SYSCFG_IMR2_PVDIM   0x00100000	/* Enabling of interrupt from Power Voltage Detector to CPU1 */
#define TOFF_SYSCFG_C2IMR1  0x0108		/* (RW) SYSCFG CPU2 (CORTEX M0) interrupt masks control-status register part 1 */
  #define SYSCFG_C2IMR1_RTCSTAMPTAMPLSECSSIM 0x00000001	/* Enabling of interrupt from RTC TimeStamp, RTC Tampers and LSE Clock Security System to CPU2 */
  #define SYSCFG_C2IMR1_RTCWKUPIM  0x00000008	/* Enabling of interrupt from RTC Wakeup to CPU2 */
  #define SYSCFG_C2IMR1_RTCALARMIM 0x00000010	/* Enabling of interrupt from RTC Alarms to CPU2 */
  #define SYSCFG_C2IMR1_RCCIM      0x00000020	/* Enabling of interrupt from RCC to CPU2 */
  #define SYSCFG_C2IMR1_FLASHIM    0x00000040	/* Enabling of interrupt from FLASH to CPU2 */
  #define SYSCFG_C2IMR1_PKAIM      0x00000100	/* Enabling of interrupt from Public Key Accelerator to CPU2 */
  #define SYSCFG_C2IMR1_RNGIM      0x00000200	/* Enabling of interrupt from Random Number Generator to CPU2 */
  #define SYSCFG_C2IMR1_AES1IM     0x00000400	/* Enabling of interrupt from Advanced Encryption Standard 1 to CPU2 */
  #define SYSCFG_C2IMR1_COMPIM     0x00000800	/* Enabling of interrupt from Comparator to CPU2 */
  #define SYSCFG_C2IMR1_ADCIM      0x00001000	/* Enabling of interrupt from Analog Digital Converter to CPU2 */
  #define SYSCFG_C2IMR1_EXTI0IM    0x00010000	/* Enabling of interrupt from External Interrupt Line 0 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI1IM    0x00020000	/* Enabling of interrupt from External Interrupt Line 1 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI2IM    0x00040000	/* Enabling of interrupt from External Interrupt Line 2 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI3IM    0x00080000	/* Enabling of interrupt from External Interrupt Line 3 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI4IM    0x00100000	/* Enabling of interrupt from External Interrupt Line 4 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI5IM    0x00200000	/* Enabling of interrupt from External Interrupt Line 5 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI6IM    0x00400000	/* Enabling of interrupt from External Interrupt Line 6 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI7IM    0x00800000	/* Enabling of interrupt from External Interrupt Line 7 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI8IM    0x01000000	/* Enabling of interrupt from External Interrupt Line 8 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI9IM    0x02000000	/* Enabling of interrupt from External Interrupt Line 9 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI10IM   0x04000000	/* Enabling of interrupt from External Interrupt Line 10 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI11IM   0x08000000	/* Enabling of interrupt from External Interrupt Line 11 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI12IM   0x10000000	/* Enabling of interrupt from External Interrupt Line 12 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI13IM   0x20000000	/* Enabling of interrupt from External Interrupt Line 13 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI14IM   0x40000000	/* Enabling of interrupt from External Interrupt Line 14 to CPU2 */
  #define SYSCFG_C2IMR1_EXTI15IM   0x80000000	/* Enabling of interrupt from External Interrupt Line 15 to CPU2 */
#define TOFF_SYSCFG_C2IMR2  0x010C		/* (RW) SYSCFG CPU2 (CORTEX M0) interrupt masks control-status register part 2 */
  #define SYSCFG_C2IMR2_DMA1CH1IM  0x00000001	/* Enabling of interrupt from DMA1 Channel 1 to CPU2 */
  #define SYSCFG_C2IMR2_DMA1CH2IM  0x00000002	/* Enabling of interrupt from DMA1 Channel 2 to CPU2 */
  #define SYSCFG_C2IMR2_DMA1CH3IM  0x00000004	/* Enabling of interrupt from DMA1 Channel 3 to CPU2 */
  #define SYSCFG_C2IMR2_DMA1CH4IM  0x00000008	/* Enabling of interrupt from DMA1 Channel 4 to CPU2 */
  #define SYSCFG_C2IMR2_DMA1CH5IM  0x00000010	/* Enabling of interrupt from DMA1 Channel 5 to CPU2 */
  #define SYSCFG_C2IMR2_DMA1CH6IM  0x00000020	/* Enabling of interrupt from DMA1 Channel 6 to CPU2 */
  #define SYSCFG_C2IMR2_DMA1CH7IM  0x00000040	/* Enabling of interrupt from DMA1 Channel 7 to CPU2 */
  #define SYSCFG_C2IMR2_DMA2CH1IM  0x00000100	/* Enabling of interrupt from DMA2 Channel 1 to CPU2 */
  #define SYSCFG_C2IMR2_DMA2CH2IM  0x00000200	/* Enabling of interrupt from DMA2 Channel 2 to CPU2 */
  #define SYSCFG_C2IMR2_DMA2CH3IM  0x00000400	/* Enabling of interrupt from DMA2 Channel 3 to CPU2 */
  #define SYSCFG_C2IMR2_DMA2CH4IM  0x00000800	/* Enabling of interrupt from DMA2 Channel 4 to CPU2 */
  #define SYSCFG_C2IMR2_DMA2CH5IM  0x00001000	/* Enabling of interrupt from DMA2 Channel 5 to CPU2 */
  #define SYSCFG_C2IMR2_DMA2CH6IM  0x00002000	/* Enabling of interrupt from DMA2 Channel 6 to CPU2 */
  #define SYSCFG_C2IMR2_DMA2CH7IM  0x00004000	/* Enabling of interrupt from DMA2 Channel 7 to CPU2 */
  #define SYSCFG_C2IMR2_DMAMUX1IM  0x00008000	/* Enabling of interrupt from DMAMUX1 to CPU2 */
  #define SYSCFG_C2IMR2_PVM1IM     0x00010000	/* Enabling of interrupt from Power Voltage Monitoring 1 to CPU2 */
  #define SYSCFG_C2IMR2_PVM3IM     0x00040000	/* Enabling of interrupt from Power Voltage Monitoring 3 to CPU2 */
  #define SYSCFG_C2IMR2_PVDIM      0x00100000	/* Enabling of interrupt from Power Voltage Detector to CPU2 */
  #define SYSCFG_C2IMR2_TSCIM      0x00200000	/* Enabling of interrupt from Touch Sensing Controller to CPU2 */
  #define SYSCFG_C2IMR2_LCDIM      0x00400000	/* Enabling of interrupt from Liquid Crystal Display to CPU2 */
#define TOFF_SYSCFG_SIPCR   0x0110		/* (RW) SYSCFG secure IP control register */
  #define SYSCFG_SIPCR_SAES1       0x00000001	/* Enabling the security access of Advanced Encryption Standard 1 KEY[7:0] */
  #define SYSCFG_SIPCR_SAES2       0x00000002	/* Enabling the security access of Advanced Encryption Standard 2 */
  #define SYSCFG_SIPCR_SPKA        0x00000004	/* Enabling the security access of Public Key Accelerator */
  #define SYSCFG_SIPCR_SRNG        0x00000008	/* Enabling the security access of Random Number Generator */


/*
 *  VREFBUF
 */
#define TADR_VREFBUF_BASE   (APB2PERIPH_BASE + 0x0030)
#define TOFF_VREFBUF_CSR    0x0000		/* (RW) VREFBUF control and status register */
  #define VREFBUF_CSR_ENVR   0x00000001	/* Voltage reference buffer enable */
  #define VREFBUF_CSR_HIZ    0x00000002	/* High impedance mode */
  #define VREFBUF_CSR_VRS    0x00000004	/* Voltage reference scale */
  #define VREFBUF_CSR_VRR    0x00000008	/* Voltage reference buffer ready  */
#define TOFF_VREFBUF_CCR    0x0004		/* (RW) VREFBUF calibration and control register */
  #define VREFBUF_CCR_TRIM   0x0000003F	/* TRIM[5:0] bits (Trimming code)  */


/*
 *  COMPARATOR
 */
#define TADR_COMP1_BASE     (APB2PERIPH_BASE + 0x0200)
#define TADR_COMP2_BASE     (APB2PERIPH_BASE + 0x0204)
#define TADR_COMP12_COMMON_BASE (TADR_COMP2_BASE)
#define TOFF_COMP_CSR       0x0000		/* (RW) COMP control and status register */
  #define COMP_CSR_EN        0x00000001	/* Comparator enable */
  #define COMP_CSR_PWRMODE   0x0000000C	/* Comparator power mode */
  #define COMP_CSR_PWRMODE_0 0x00000004
  #define COMP_CSR_PWRMODE_1 0x00000008
  #define COMP_CSR_INMSEL    0x00000070	/* Comparator input minus selection */
  #define COMP_CSR_INMSEL_0  0x00000010
  #define COMP_CSR_INMSEL_1  0x00000020
  #define COMP_CSR_INMSEL_2  0x00000040
  #define COMP_CSR_INPSEL    0x00000180	/* Comparator input plus selection */
  #define COMP_CSR_INPSEL_0  0x00000080
  #define COMP_CSR_INPSEL_1  0x00000100
  #define COMP_CSR_WINMODE   0x00000200	/* Pair of comparators window mode. Bit intended to be used with COMP common instance (COMP_Common_TypeDef)  */
  #define COMP_CSR_POLARITY  0x00008000	/* Comparator output polarity */
  #define COMP_CSR_HYST      0x00030000	/* Comparator hysteresis */
  #define COMP_CSR_HYST_0    0x00010000
  #define COMP_CSR_HYST_1    0x00020000
  #define COMP_CSR_BLANKING  0x001C0000	/* Comparator blanking source */
  #define COMP_CSR_BLANKING_0 0x00040000
  #define COMP_CSR_BLANKING_1 0x00080000
  #define COMP_CSR_BLANKING_2 0x00100000
  #define COMP_CSR_BRGEN     0x00400000	/* Comparator voltage scaler enable */
  #define COMP_CSR_SCALEN    0x00800000	/* Comparator scaler bridge enable */
  #define COMP_CSR_INMESEL   0x06000000	/* Comparator input minus extended selection */
  #define COMP_CSR_INMESEL_0 0x02000000
  #define COMP_CSR_INMESEL_1 0x04000000
  #define COMP_CSR_VALUE     0x40000000	/* Comparator output level */
  #define COMP_CSR_LOCK      0x80000000	/* Comparator lock */


/*
 *  SERIAL AUDIO INTERFACE
 */
#define TADR_SAI1_BASE      (APB2PERIPH_BASE + 0x5400)
#define TOFF_SAI_GCR        0x0000		/* (RW) SAI global configuration register */
  #define SAI_GCR_SYNCIN      0x00000003	/* SYNCIN[1:0] bits (Synchronization Inputs)   */
  #define SAI_GCR_SYNCIN_0    0x00000001	/* Bit 0 */
  #define SAI_GCR_SYNCIN_1    0x00000002	/* Bit 1 */
  #define SAI_GCR_SYNCOUT     0x00000030	/* SYNCOUT[1:0] bits (Synchronization Outputs) */
  #define SAI_GCR_SYNCOUT_0   0x00000010	/* Bit 0 */
  #define SAI_GCR_SYNCOUT_1   0x00000020	/* Bit 1 */
#define TOFF_SAI_PDMCR      0x0044		/* (RW) SAI PDM control register */
  #define SAI_PDMCR_PDMEN     0x00000001	/* PDM enable */
  #define SAI_PDMCR_MICNBR    0x00000030	/* MICNBR[1:0] (Number of microphones) */
  #define SAI_PDMCR_MICNBR_0  0x00000010
  #define SAI_PDMCR_MICNBR_1  0x00000020
  #define SAI_PDMCR_CKEN1     0x00000100	/* Clock 1 enable */
  #define SAI_PDMCR_CKEN2     0x00000200	/* Clock 2 enable */
  #define SAI_PDMCR_CKEN3     0x00000400	/* Clock 3 enable */
  #define SAI_PDMCR_CKEN4     0x00000800	/* Clock 4 enable */
#define TOFF_SAI_PDMDLY     0x0048		/* (RW) SAI PDM delay register */
  #define SAI_PDMDLY_DLYM1L   0x00000007	/* DLYM1L[2:0] (Delay line adjust for left microphone of pair 1) */
  #define SAI_PDMDLY_DLYM1L_0 0x00000001
  #define SAI_PDMDLY_DLYM1L_1 0x00000002
  #define SAI_PDMDLY_DLYM1L_2 0x00000004
  #define SAI_PDMDLY_DLYM1R   0x00000070	/* DLYM1R[2:0] (Delay line adjust for right microphone of pair 1) */
  #define SAI_PDMDLY_DLYM1R_0 0x00000010
  #define SAI_PDMDLY_DLYM1R_1 0x00000020
  #define SAI_PDMDLY_DLYM1R_2 0x00000040
  #define SAI_PDMDLY_DLYM2L   0x00000700	/* DLYM2L[2:0] (Delay line adjust for left microphone of pair 2) */
  #define SAI_PDMDLY_DLYM2L_0 0x00000100
  #define SAI_PDMDLY_DLYM2L_1 0x00000200
  #define SAI_PDMDLY_DLYM2L_2 0x00000400
  #define SAI_PDMDLY_DLYM2R   0x00007000	/* DLYM2R[2:0] (Delay line adjust for right microphone of pair 2) */
  #define SAI_PDMDLY_DLYM2R_0 0x00001000
  #define SAI_PDMDLY_DLYM2R_1 0x00002000
  #define SAI_PDMDLY_DLYM2R_2 0x00004000
  #define SAI_PDMDLY_DLYM3L   0x00070000	/* DLYM3L[2:0] (Delay line adjust for left microphone of pair 3) */
  #define SAI_PDMDLY_DLYM3L_0 0x00010000
  #define SAI_PDMDLY_DLYM3L_1 0x00020000
  #define SAI_PDMDLY_DLYM3L_2 0x00040000
  #define SAI_PDMDLY_DLYM3R   0x00700000	/* DLYM3R[2:0] (Delay line adjust for right microphone of pair 3) */
  #define SAI_PDMDLY_DLYM3R_0 0x00100000
  #define SAI_PDMDLY_DLYM3R_1 0x00200000
  #define SAI_PDMDLY_DLYM3R_2 0x00400000
  #define SAI_PDMDLY_DLYM4L   0x07000000	/* DLYM4L[2:0] (Delay line adjust for left microphone of pair 4) */
  #define SAI_PDMDLY_DLYM4L_0 0x01000000
  #define SAI_PDMDLY_DLYM4L_1 0x02000000
  #define SAI_PDMDLY_DLYM4L_2 0x04000000
  #define SAI_PDMDLY_DLYM4R   0x70000000	/* DLYM4R[2:0] (Delay line adjust for right microphone of pair 4) */
  #define SAI_PDMDLY_DLYM4R_0 0x10000000
  #define SAI_PDMDLY_DLYM4R_1 0x20000000
  #define SAI_PDMDLY_DLYM4R_2 0x40000000

#define SAI_WINDOW_SIZE     0x0020
#define TOFF_SAI_CR1        0x0000		/* (RW) SAI block x configuration register 1 */
  #define SAI_xCR1_MODE       0x00000003	/* MODE[1:0] bits (Audio Block Mode) */
  #define SAI_xCR1_MODE_0     0x00000001	/* Bit 0 */
  #define SAI_xCR1_MODE_1     0x00000002	/* Bit 1 */
  #define SAI_xCR1_PRTCFG     0x0000000C	/* PRTCFG[1:0] bits (Protocol Configuration)   */
  #define SAI_xCR1_PRTCFG_0   0x00000004	/* Bit 0 */
  #define SAI_xCR1_PRTCFG_1   0x00000008	/* Bit 1 */
  #define SAI_xCR1_DS         0x000000E0	/* DS[1:0] bits (Data Size) */
  #define SAI_xCR1_DS_0       0x00000020	/* Bit 0 */
  #define SAI_xCR1_DS_1       0x00000040	/* Bit 1 */
  #define SAI_xCR1_DS_2       0x00000080	/* Bit 2 */
  #define SAI_xCR1_LSBFIRST   0x00000100	/* LSB First Configuration  */
  #define SAI_xCR1_CKSTR      0x00000200	/* ClocK STRobing edge      */
  #define SAI_xCR1_SYNCEN     0x00000C00	/* SYNCEN[1:0](SYNChronization ENable) */
  #define SAI_xCR1_SYNCEN_0   0x00000400	/* Bit 0 */
  #define SAI_xCR1_SYNCEN_1   0x00000800	/* Bit 1 */
  #define SAI_xCR1_MONO       0x00001000	/* Mono mode */
  #define SAI_xCR1_OUTDRIV    0x00002000	/* Output Drive */
  #define SAI_xCR1_SAIEN      0x00010000	/* Audio Block enable */
  #define SAI_xCR1_DMAEN      0x00020000	/* DMA enable */
  #define SAI_xCR1_NODIV      0x00080000	/* No Divider Configuration */
  #define SAI_xCR1_MCKDIV     0x03F00000	/* MCKDIV[5:0] (Master ClocK Divider)  */
  #define SAI_xCR1_MCKDIV_0   0x00100000	/* Bit 0  */
  #define SAI_xCR1_MCKDIV_1   0x00200000	/* Bit 1  */
  #define SAI_xCR1_MCKDIV_2   0x00400000	/* Bit 2  */
  #define SAI_xCR1_MCKDIV_3   0x00800000	/* Bit 3  */
  #define SAI_xCR1_MCKDIV_4   0x01000000	/* Bit 4  */
  #define SAI_xCR1_MCKDIV_5   0x02000000	/* Bit 5  */
  #define SAI_xCR1_OSR        0x04000000	/* Oversampling ratio for master clock */
  #define SAI_xCR1_MCKEN      0x08000000	/* Master clock generation enable */
#define TOFF_SAI_CR2        0x0004		/* (RW) SAI block x configuration register 2 */
  #define SAI_xCR2_FTH        0x00000007	/* FTH[2:0](Fifo THreshold)  */
  #define SAI_xCR2_FTH_0      0x00000001	/* Bit 0 */
  #define SAI_xCR2_FTH_1      0x00000002	/* Bit 1 */
  #define SAI_xCR2_FTH_2      0x00000004	/* Bit 2 */
  #define SAI_xCR2_FFLUSH     0x00000008	/* Fifo FLUSH */
  #define SAI_xCR2_TRIS       0x00000010	/* TRIState Management on data line */
  #define SAI_xCR2_MUTE       0x00000020	/* Mute mode */
  #define SAI_xCR2_MUTEVAL    0x00000040	/* Mute value */
  #define SAI_xCR2_MUTECNT    0x00001F80	/* MUTECNT[5:0] (MUTE counter) */
  #define SAI_xCR2_MUTECNT_0  0x00000080	/* Bit 0 */
  #define SAI_xCR2_MUTECNT_1  0x00000100	/* Bit 1 */
  #define SAI_xCR2_MUTECNT_2  0x00000200	/* Bit 2 */
  #define SAI_xCR2_MUTECNT_3  0x00000400	/* Bit 3 */
  #define SAI_xCR2_MUTECNT_4  0x00000800	/* Bit 4 */
  #define SAI_xCR2_MUTECNT_5  0x00001000	/* Bit 5 */
  #define SAI_xCR2_CPL        0x00080000	/* Complement Bit */
  #define SAI_xCR2_COMP       0x0000C000	/* COMP[1:0] (Companding mode) */
  #define SAI_xCR2_COMP_0     0x00004000	/* Bit 0 */
  #define SAI_xCR2_COMP_1     0x00008000	/* Bit 1 */
#define TOFF_SAI_FRCR       0x0008		/* (RW) SAI block x frame configuration register */
  #define SAI_xFRCR_FRL       0x000000FF	/* FRL[1:0](Frame length)  */
  #define SAI_xFRCR_FRL_0     0x00000001	/* Bit 0 */
  #define SAI_xFRCR_FRL_1     0x00000002	/* Bit 1 */
  #define SAI_xFRCR_FRL_2     0x00000004	/* Bit 2 */
  #define SAI_xFRCR_FRL_3     0x00000008	/* Bit 3 */
  #define SAI_xFRCR_FRL_4     0x00000010	/* Bit 4 */
  #define SAI_xFRCR_FRL_5     0x00000020	/* Bit 5 */
  #define SAI_xFRCR_FRL_6     0x00000040	/* Bit 6 */
  #define SAI_xFRCR_FRL_7     0x00000080	/* Bit 7 */
  #define SAI_xFRCR_FSALL     0x00007F00	/* FRL[1:0] (Frame synchronization active level length)  */
  #define SAI_xFRCR_FSALL_0   0x00000100	/* Bit 0 */
  #define SAI_xFRCR_FSALL_1   0x00000200	/* Bit 1 */
  #define SAI_xFRCR_FSALL_2   0x00000400	/* Bit 2 */
  #define SAI_xFRCR_FSALL_3   0x00000800	/* Bit 3 */
  #define SAI_xFRCR_FSALL_4   0x00001000	/* Bit 4 */
  #define SAI_xFRCR_FSALL_5   0x00002000	/* Bit 5 */
  #define SAI_xFRCR_FSALL_6   0x00004000	/* Bit 6 */
  #define SAI_xFRCR_FSDEF     0x00010000	/* Frame Synchronization Definition */
  #define SAI_xFRCR_FSPO      0x00020000	/* Frame Synchronization POLarity */
  #define SAI_xFRCR_FSOFF     0x00040000	/* Frame Synchronization OFFset*/
#define TOFF_SAI_SLOTR      0x000C		/* (RW) SAI block x slot register */
  #define SAI_xSLOTR_FBOFF    0x0000001F	/* FRL[4:0](First Bit Offset)  */
  #define SAI_xSLOTR_FBOFF_0  0x00000001	/* Bit 0 */
  #define SAI_xSLOTR_FBOFF_1  0x00000002	/* Bit 1 */
  #define SAI_xSLOTR_FBOFF_2  0x00000004	/* Bit 2 */
  #define SAI_xSLOTR_FBOFF_3  0x00000008	/* Bit 3 */
  #define SAI_xSLOTR_FBOFF_4  0x00000010	/* Bit 4 */
  #define SAI_xSLOTR_SLOTSZ   0x000000C0	/* SLOTSZ[1:0] (Slot size)  */
  #define SAI_xSLOTR_SLOTSZ_0 0x00000040	/* Bit 0 */
  #define SAI_xSLOTR_SLOTSZ_1 0x00000080	/* Bit 1 */
  #define SAI_xSLOTR_NBSLOT   0x00000F00	/* NBSLOT[3:0] (Number of Slot in audio Frame)  */
  #define SAI_xSLOTR_NBSLOT_0 0x00000100	/* Bit 0 */
  #define SAI_xSLOTR_NBSLOT_1 0x00000200	/* Bit 1 */
  #define SAI_xSLOTR_NBSLOT_2 0x00000400	/* Bit 2 */
  #define SAI_xSLOTR_NBSLOT_3 0x00000800	/* Bit 3 */
  #define SAI_xSLOTR_SLOTEN   0xFFFF0000	/* SLOTEN[15:0] (Slot Enable)  */
#define TOFF_SAI_IMR        0x0010		/* (RW) SAI block x interrupt mask register */
  #define SAI_xIMR_OVRUDRIE   0x00000001	/* Overrun underrun interrupt enable                              */
  #define SAI_xIMR_MUTEDETIE  0x00000002	/* Mute detection interrupt enable                                */
  #define SAI_xIMR_WCKCFGIE   0x00000004	/* Wrong Clock Configuration interrupt enable                     */
  #define SAI_xIMR_FREQIE     0x00000008	/* FIFO request interrupt enable                                  */
  #define SAI_xIMR_CNRDYIE    0x00000010	/* Codec not ready interrupt enable                               */
  #define SAI_xIMR_AFSDETIE   0x00000020	/* Anticipated frame synchronization detection interrupt enable   */
  #define SAI_xIMR_LFSDETIE   0x00000040	/* Late frame synchronization detection interrupt enable          */
#define TOFF_SAI_SR         0x0014		/* (RW) SAI block x status register */
  #define SAI_xSR_OVRUDR      0x00000001	/* Overrun underrun */
  #define SAI_xSR_MUTEDET     0x00000002	/* Mute detection */
  #define SAI_xSR_WCKCFG      0x00000004	/* Wrong Clock Configuration */
  #define SAI_xSR_FREQ        0x00000008	/* FIFO request */
  #define SAI_xSR_CNRDY       0x00000010	/* Codec not ready */
  #define SAI_xSR_AFSDET      0x00000020	/* Anticipated frame synchronization detection */
  #define SAI_xSR_LFSDET      0x00000040	/* Late frame synchronization detection */
  #define SAI_xSR_FLVL        0x00070000	/* FLVL[2:0] (FIFO Level Threshold) */
  #define SAI_xSR_FLVL_0      0x00010000	/* Bit 0 */
  #define SAI_xSR_FLVL_1      0x00020000	/* Bit 1 */
  #define SAI_xSR_FLVL_2      0x00040000	/* Bit 2 */
#define TOFF_SAI_CLRFR      0x0018		/* (RW) SAI block x clear flag register */
  #define SAI_xCLRFR_COVRUDR  0x00000001	/* Clear Overrun underrun */
  #define SAI_xCLRFR_CMUTEDET 0x00000002	/* Clear Mute detection */
  #define SAI_xCLRFR_CWCKCFG  0x00000004	/* Clear Wrong Clock Configuration */
  #define SAI_xCLRFR_CFREQ    0x00000008	/* Clear FIFO request */
  #define SAI_xCLRFR_CCNRDY   0x00000010	/* Clear Codec not ready */
  #define SAI_xCLRFR_CAFSDET  0x00000020	/* Clear Anticipated frame synchronization detection */
  #define SAI_xCLRFR_CLFSDET  0x00000040	/* Clear Late frame synchronization detection */
#define TOFF_SAI_DR         0x001C		/* (RW) SAI block x data register */


/* 
 *  DMA CONTROLLER
 */
#define TADR_DMA1_BASE      (AHB1PERIPH_BASE + 0x0000)
#define TADR_DMA2_BASE      (AHB1PERIPH_BASE + 0x0400)
#define TOFF_DMA_ISR        0x0000		/* (RW) DMA interrupt status register */
  #define DMA_ISR_GIF        0x1		/* Channel Global interrupt flag */
  #define DMA_ISR_TCIF       0x2		/* Channel Transfer Complete flag */
  #define DMA_ISR_HTIF       0x4		/* Channel Half Transfer flag */
  #define DMA_ISR_TEIF       0x8		/* Channel Transfer Error flag */
#define TOFF_DMA_IFCR       0x0004		/* (RW) DMA interrupt flag clear register */
  #define DMA_IFCR_CGIF      0x1		/* Channel Global interrupt clear    */
  #define DMA_IFCR_CTCIF     0x2		/* Channel Transfer Complete clear   */
  #define DMA_IFCR_CHTIF     0x4		/* Channel Half Transfer clear       */
  #define DMA_IFCR_CTEIF     0x8		/* Channel Transfer Error clear      */
#define TADR_DMA1_CH1_BASE  (TADR_DMA1_BASE + 0x0008)
#define TADR_DMA1_CH2_BASE  (TADR_DMA1_BASE + 0x001C)
#define TADR_DMA1_CH3_BASE  (TADR_DMA1_BASE + 0x0030)
#define TADR_DMA1_CH4_BASE  (TADR_DMA1_BASE + 0x0044)
#define TADR_DMA1_CH5_BASE  (TADR_DMA1_BASE + 0x0058)
#define TADR_DMA1_CH6_BASE  (TADR_DMA1_BASE + 0x006C)
#define TADR_DMA1_CH7_BASE  (TADR_DMA1_BASE + 0x0080)
#define TADR_DMA2_CH1_BASE  (TADR_DMA2_BASE + 0x0008)
#define TADR_DMA2_CH2_BASE  (TADR_DMA2_BASE + 0x001C)
#define TADR_DMA2_CH3_BASE  (TADR_DMA2_BASE + 0x0030)
#define TADR_DMA2_CH4_BASE  (TADR_DMA2_BASE + 0x0044)
#define TADR_DMA2_CH5_BASE  (TADR_DMA2_BASE + 0x0058)
#define TADR_DMA2_CH6_BASE  (TADR_DMA2_BASE + 0x006C)
#define TADR_DMA2_CH7_BASE  (TADR_DMA2_BASE + 0x0080)
#define TOFF_DMACH_CCR      0x0000		/* (RW) DMA channel x configuration register */
  #define DMA_CCR_EN         0x00000001	/* Channel enable */
  #define DMA_CCR_TCIE       0x00000002	/* Transfer complete interrupt enable */
  #define DMA_CCR_HTIE       0x00000004	/* Half Transfer interrupt enable */
  #define DMA_CCR_TEIE       0x00000008	/* Transfer error interrupt enable */
  #define DMA_CCR_DIR        0x00000010	/* Data transfer direction */
  #define DMA_CCR_CIRC       0x00000020	/* Circular mode */
  #define DMA_CCR_PINC       0x00000040	/* Peripheral increment mode */
  #define DMA_CCR_MINC       0x00000080	/* Memory increment mode */
  #define DMA_CCR_PSIZE      0x00000300	/* PSIZE[1:0] bits (Peripheral size) */
  #define DMA_CCR_PSIZE_0    0x00000100
  #define DMA_CCR_PSIZE_1    0x00000200
  #define DMA_CCR_MSIZE      0x00000C00	/* MSIZE[1:0] bits (Memory size) */
  #define DMA_CCR_MSIZE_0    0x00000400
  #define DMA_CCR_MSIZE_1    0x00000800
  #define DMA_CCR_PL         0x00003000	/* PL[1:0] bits(Channel Priority level) */
  #define DMA_CCR_PL_0       0x00001000
  #define DMA_CCR_PL_1       0x00002000
  #define DMA_CCR_MEM2MEM    0x00004000	/* Memory to memory mode */
#define TOFF_DMACH_CNDTR    0x0004		/* (RW) DMA channel x number of data register */
  #define DMA_CNDTR_NDT      0x0000FFFF	/* Number of data to Transfer */
#define TOFF_DMACH_CPAR     0x0008		/* (RW) DMA channel x peripheral address register   */
#define TOFF_DMACH_CMAR     0x000C		/* (RW) DMA channel x memory address register */


/*
 *  DMAMUTEX
 */
#define TADR_DMAMUX1_BASE   (AHB1PERIPH_BASE + 0x0800)
#define TOFF_DMAMUX_CHANNEL_CR      0x0000
  #define DMAMUX_CxCR_DMAREQ_ID     0x000000FF
  #define DMAMUX_CxCR_DMAREQ_ID_0   0x00000001
  #define DMAMUX_CxCR_DMAREQ_ID_1   0x00000002
  #define DMAMUX_CxCR_DMAREQ_ID_2   0x00000004
  #define DMAMUX_CxCR_DMAREQ_ID_3   0x00000008
  #define DMAMUX_CxCR_DMAREQ_ID_4   0x00000010
  #define DMAMUX_CxCR_DMAREQ_ID_5   0x00000020
  #define DMAMUX_CxCR_DMAREQ_ID_6   0x00000040
  #define DMAMUX_CxCR_DMAREQ_ID_7   0x00000080
  #define DMAMUX_CxCR_SOIE          0x00000100
  #define DMAMUX_CxCR_EGE           0x00000200
  #define DMAMUX_CxCR_SE            0x00010000
  #define DMAMUX_CxCR_SPOL          0x00060000
  #define DMAMUX_CxCR_SPOL_0        0x00020000
  #define DMAMUX_CxCR_SPOL_1        0x00040000
  #define DMAMUX_CxCR_NBREQ         0x00F80000
  #define DMAMUX_CxCR_NBREQ_0       0x00080000
  #define DMAMUX_CxCR_NBREQ_1       0x00100000
  #define DMAMUX_CxCR_NBREQ_2       0x00200000
  #define DMAMUX_CxCR_NBREQ_3       0x00400000
  #define DMAMUX_CxCR_NBREQ_4       0x00800000
  #define DMAMUX_CxCR_SYNC_ID       0x1F000000
  #define DMAMUX_CxCR_SYNC_ID_0     0x01000000
  #define DMAMUX_CxCR_SYNC_ID_1     0x02000000
  #define DMAMUX_CxCR_SYNC_ID_2     0x04000000
  #define DMAMUX_CxCR_SYNC_ID_3     0x08000000
  #define DMAMUX_CxCR_SYNC_ID_4     0x10000000
#define TOFF_DMAMUX_REQUEST_GEN     0x0100
  #define DMAMUX_RGxCR_SIG_ID       0x0000001F
  #define DMAMUX_RGxCR_SIG_ID_0     0x00000001
  #define DMAMUX_RGxCR_SIG_ID_1     0x00000002
  #define DMAMUX_RGxCR_SIG_ID_2     0x00000004
  #define DMAMUX_RGxCR_SIG_ID_3     0x00000008
  #define DMAMUX_RGxCR_SIG_ID_4     0x00000010
  #define DMAMUX_RGxCR_OIE          0x00000100
  #define DMAMUX_RGxCR_GE           0x00010000
  #define DMAMUX_RGxCR_GPOL         0x00060000
  #define DMAMUX_RGxCR_GPOL_0       0x00020000
  #define DMAMUX_RGxCR_GPOL_1       0x00040000
  #define DMAMUX_RGxCR_GNBREQ       0x00F80000
  #define DMAMUX_RGxCR_GNBREQ_0     0x00080000
  #define DMAMUX_RGxCR_GNBREQ_1     0x00100000
  #define DMAMUX_RGxCR_GNBREQ_2     0x00200000
  #define DMAMUX_RGxCR_GNBREQ_3     0x00400000
  #define DMAMUX_RGxCR_GNBREQ_4     0x00800000
#define TOFF_DMAMUX_CHANNEL_STS     0x0080
#define TOFF_DMAMUX_CHANNEL_STS_CSR TOFF_DMAMUX_CHANNEL_STS
#define TOFF_DMAMUX_CHANNEL_STS_CFR (TOFF_DMAMUX_CHANNEL_STS+4)
#define TOFF_DMAMUX_REQUEST_GENSTS  0x0140
#define TOFF_DMAMUX_REQUEST_GENSTS_RGSR  TOFF_DMAMUX_REQUEST_GENSTS
#define TOFF_DMAMUX_REQUEST_GENSTS_RGCFR (TOFF_DMAMUX_REQUEST_GENSTS+4)


/*
 *  CRC CALCULATION UNIT
 */
#define TADR_CRC_BASE       (AHB1PERIPH_BASE + 0x3000)
#define TOFF_CRC_DR         0x0000		/* (RW) CRC Data register */
#define TOFF_CRC_IDR        0x0004		/* (RW-8) CRC Independent data register */
#define TOFF_CRC_CR         0x0008		/* (RW) CRC Control register */
  #define CRC_CR_RESET       0x00000001	/* RESET the CRC computation unit bit */
  #define CRC_CR_POLYSIZE    0x00000018	/* Polynomial size bits */
  #define CRC_CR_POLYSIZE_0  0x00000008
  #define CRC_CR_POLYSIZE_1  0x00000010
  #define CRC_CR_REV_IN      0x00000060	/* REV_IN Reverse Input Data bits */
  #define CRC_CR_REV_IN_0    0x00000020
  #define CRC_CR_REV_IN_1    0x00000040
  #define CRC_CR_REV_OUT     0x00000080	/* REV_OUT Reverse Output Data bits */
#define TOFF_CRC_INIT       0x0010		/* (RW) Initial CRC value register */
#define TOFF_CRC_POL        0x0014		/* (RW) CRC polynomial register */


/*
 *  TOUCH SENSING CONTROLLER
 */
#define TADR_TSC_BASE       (AHB1PERIPH_BASE + 0x4000)
#define TOFF_TSC_CR         0x0000		/* (RW) TSC control register */
  #define TSC_CR_TSCE        0x00000001	/* Touch sensing controller enable */
  #define TSC_CR_START       0x00000002	/* Start acquisition */
  #define TSC_CR_AM          0x00000004	/* Acquisition mode */
  #define TSC_CR_SYNCPOL     0x00000008	/* Synchronization pin polarity */
  #define TSC_CR_IODEF       0x00000010	/* IO default mode */
  #define TSC_CR_MCV         0x000000E0	/* MCV[2:0] bits (Max Count Value) */
  #define TSC_CR_MCV_0       0x00000020
  #define TSC_CR_MCV_1       0x00000040
  #define TSC_CR_MCV_2       0x00000080
  #define TSC_CR_PGPSC       0x00007000	/* PGPSC[2:0] bits (Pulse Generator Prescaler) */
  #define TSC_CR_PGPSC_0     0x00001000
  #define TSC_CR_PGPSC_1     0x00002000
  #define TSC_CR_PGPSC_2     0x00004000
  #define TSC_CR_SSPSC       0x00008000	/* Spread Spectrum Prescaler */
  #define TSC_CR_SSE         0x00010000	/* Spread Spectrum Enable */
  #define TSC_CR_SSD         0x00FE0000	/* SSD[6:0] bits (Spread Spectrum Deviation) */
  #define TSC_CR_SSD_0       0x00020000
  #define TSC_CR_SSD_1       0x00040000
  #define TSC_CR_SSD_2       0x00080000
  #define TSC_CR_SSD_3       0x00100000
  #define TSC_CR_SSD_4       0x00200000
  #define TSC_CR_SSD_5       0x00400000
  #define TSC_CR_SSD_6       0x00800000
  #define TSC_CR_CTPL        0x0F000000	/* CTPL[3:0] bits (Charge Transfer pulse low) */
  #define TSC_CR_CTPL_0      0x01000000
  #define TSC_CR_CTPL_1      0x02000000
  #define TSC_CR_CTPL_2      0x04000000
  #define TSC_CR_CTPL_3      0x08000000
  #define TSC_CR_CTPH        0xF0000000	/* CTPH[3:0] bits (Charge Transfer pulse high) */
  #define TSC_CR_CTPH_0      0x10000000
  #define TSC_CR_CTPH_1      0x20000000
  #define TSC_CR_CTPH_2      0x40000000
  #define TSC_CR_CTPH_3      0x80000000
#define TOFF_TSC_IER        0x0004		/* (RW) TSC interrupt enable register */
  #define TSC_IER_EOAIE      0x00000001	/* End of acquisition interrupt enable */
  #define TSC_IER_MCEIE      0x00000002	/* Max count error interrupt enable */
#define TOFF_TSC_ICR        0x0008		/* (RW) TSC interrupt clear register */
  #define TSC_ICR_EOAIC      0x00000001	/* End of acquisition interrupt clear */
  #define TSC_ICR_MCEIC      0x00000002	/* Max count error interrupt clear */
#define TOFF_TSC_ISR        0x000C		/* (RW) TSC interrupt status register */
  #define TSC_ISR_EOAF       0x00000001	/* End of acquisition flag */
  #define TSC_ISR_MCEF       0x00000002	/* Max count error flag */
#define TOFF_TSC_IOHCR      0x0010		/* (RW) TSC I/O hysteresis control register */
  #define TSC_IOHCR_G1_IO1   0x00000001	/* GROUP1_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G1_IO2   0x00000002	/* GROUP1_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G1_IO3   0x00000004	/* GROUP1_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G1_IO4   0x00000008	/* GROUP1_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G2_IO1   0x00000010	/* GROUP2_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G2_IO2   0x00000020	/* GROUP2_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G2_IO3   0x00000040	/* GROUP2_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G2_IO4   0x00000080	/* GROUP2_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G3_IO1   0x00000100	/* GROUP3_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G3_IO2   0x00000200	/* GROUP3_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G3_IO3   0x00000400	/* GROUP3_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G3_IO4   0x00000800	/* GROUP3_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G4_IO1   0x00001000	/* GROUP4_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G4_IO2   0x00002000	/* GROUP4_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G4_IO3   0x00004000	/* GROUP4_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G4_IO4   0x00008000	/* GROUP4_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G5_IO1   0x00010000	/* GROUP5_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G5_IO2   0x00020000	/* GROUP5_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G5_IO3   0x00040000	/* GROUP5_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G5_IO4   0x00080000	/* GROUP5_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G6_IO1   0x00100000	/* GROUP6_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G6_IO2   0x00200000	/* GROUP6_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G6_IO3   0x00400000	/* GROUP6_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G6_IO4   0x00800000	/* GROUP6_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G7_IO1   0x01000000	/* GROUP7_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G7_IO2   0x02000000	/* GROUP7_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G7_IO3   0x04000000	/* GROUP7_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G7_IO4   0x08000000	/* GROUP7_IO4 schmitt trigger hysteresis mode */
#define TOFF_TSC_IOASCR     0x0018		/* (RW) TSC I/O analog switch control register */
  #define TSC_IOASCR_G1_IO1  0x00000001	/*GROUP1_IO1 analog switch enable */
  #define TSC_IOASCR_G1_IO2  0x00000002	/* GROUP1_IO2 analog switch enable */
  #define TSC_IOASCR_G1_IO3  0x00000004	/* GROUP1_IO3 analog switch enable */
  #define TSC_IOASCR_G1_IO4  0x00000008	/* GROUP1_IO4 analog switch enable */
  #define TSC_IOASCR_G2_IO1  0x00000010	/* GROUP2_IO1 analog switch enable */
  #define TSC_IOASCR_G2_IO2  0x00000020	/* GROUP2_IO2 analog switch enable */
  #define TSC_IOASCR_G2_IO3  0x00000040	/* GROUP2_IO3 analog switch enable */
  #define TSC_IOASCR_G2_IO4  0x00000080	/* GROUP2_IO4 analog switch enable */
  #define TSC_IOASCR_G3_IO1  0x00000100	/* GROUP3_IO1 analog switch enable */
  #define TSC_IOASCR_G3_IO2  0x00000200	/* GROUP3_IO2 analog switch enable */
  #define TSC_IOASCR_G3_IO3  0x00000400	/* GROUP3_IO3 analog switch enable */
  #define TSC_IOASCR_G3_IO4  0x00000800	/* GROUP3_IO4 analog switch enable */
  #define TSC_IOASCR_G4_IO1  0x00001000	/* GROUP4_IO1 analog switch enable */
  #define TSC_IOASCR_G4_IO2  0x00002000	/* GROUP4_IO2 analog switch enable */
  #define TSC_IOASCR_G4_IO3  0x00004000	/* GROUP4_IO3 analog switch enable */
  #define TSC_IOASCR_G4_IO4  0x00008000	/* GROUP4_IO4 analog switch enable */
  #define TSC_IOASCR_G5_IO1  0x00010000	/* GROUP5_IO1 analog switch enable */
  #define TSC_IOASCR_G5_IO2  0x00020000	/* GROUP5_IO2 analog switch enable */
  #define TSC_IOASCR_G5_IO3  0x00040000	/* GROUP5_IO3 analog switch enable */
  #define TSC_IOASCR_G5_IO4  0x00080000	/* GROUP5_IO4 analog switch enable */
  #define TSC_IOASCR_G6_IO1  0x00100000	/* GROUP6_IO1 analog switch enable */
  #define TSC_IOASCR_G6_IO2  0x00200000	/* GROUP6_IO2 analog switch enable */
  #define TSC_IOASCR_G6_IO3  0x00400000	/* GROUP6_IO3 analog switch enable */
  #define TSC_IOASCR_G6_IO4  0x00800000	/* GROUP6_IO4 analog switch enable */
  #define TSC_IOASCR_G7_IO1  0x01000000	/* GROUP7_IO1 analog switch enable */
  #define TSC_IOASCR_G7_IO2  0x02000000	/* GROUP7_IO2 analog switch enable */
  #define TSC_IOASCR_G7_IO3  0x04000000	/* GROUP7_IO3 analog switch enable */
  #define TSC_IOASCR_G7_IO4  0x08000000	/* GROUP7_IO4 analog switch enable */
#define TOFF_TSC_IOSCR      0x0020		/* (RW) TSC I/O sampling control register */
  #define TSC_IOSCR_G1_IO1   0x00000001	/* GROUP1_IO1 sampling mode */
  #define TSC_IOSCR_G1_IO2   0x00000002	/* GROUP1_IO2 sampling mode */
  #define TSC_IOSCR_G1_IO3   0x00000004	/* GROUP1_IO3 sampling mode */
  #define TSC_IOSCR_G1_IO4   0x00000008	/* GROUP1_IO4 sampling mode */
  #define TSC_IOSCR_G2_IO1   0x00000010	/* GROUP2_IO1 sampling mode */
  #define TSC_IOSCR_G2_IO2   0x00000020	/* GROUP2_IO2 sampling mode */
  #define TSC_IOSCR_G2_IO3   0x00000040	/* GROUP2_IO3 sampling mode */
  #define TSC_IOSCR_G2_IO4   0x00000080	/* GROUP2_IO4 sampling mode */
  #define TSC_IOSCR_G3_IO1   0x00000100	/* GROUP3_IO1 sampling mode */
  #define TSC_IOSCR_G3_IO2   0x00000200	/* GROUP3_IO2 sampling mode */
  #define TSC_IOSCR_G3_IO3   0x00000400	/* GROUP3_IO3 sampling mode */
  #define TSC_IOSCR_G3_IO4   0x00000800	/* GROUP3_IO4 sampling mode */
  #define TSC_IOSCR_G4_IO1   0x00001000	/* GROUP4_IO1 sampling mode */
  #define TSC_IOSCR_G4_IO2   0x00002000	/* GROUP4_IO2 sampling mode */
  #define TSC_IOSCR_G4_IO3   0x00004000	/* GROUP4_IO3 sampling mode */
  #define TSC_IOSCR_G4_IO4   0x00008000	/* GROUP4_IO4 sampling mode */
  #define TSC_IOSCR_G5_IO1   0x00010000	/* GROUP5_IO1 sampling mode */
  #define TSC_IOSCR_G5_IO2   0x00020000	/* GROUP5_IO2 sampling mode */
  #define TSC_IOSCR_G5_IO3   0x00040000	/* GROUP5_IO3 sampling mode */
  #define TSC_IOSCR_G5_IO4   0x00080000	/* GROUP5_IO4 sampling mode */
  #define TSC_IOSCR_G6_IO1   0x00100000	/* GROUP6_IO1 sampling mode */
  #define TSC_IOSCR_G6_IO2   0x00200000	/* GROUP6_IO2 sampling mode */
  #define TSC_IOSCR_G6_IO3   0x00400000	/* GROUP6_IO3 sampling mode */
  #define TSC_IOSCR_G6_IO4   0x00800000	/* GROUP6_IO4 sampling mode */
  #define TSC_IOSCR_G7_IO1   0x01000000	/* GROUP7_IO1 sampling mode */
  #define TSC_IOSCR_G7_IO2   0x02000000	/* GROUP7_IO2 sampling mode */
  #define TSC_IOSCR_G7_IO3   0x04000000	/* GROUP7_IO3 sampling mode */
  #define TSC_IOSCR_G7_IO4   0x08000000	/* GROUP7_IO4 sampling mode */
#define TOFF_TSC_IOCCR      0x0028		/* (RW) TSC I/O channel control register */
  #define TSC_IOCCR_G1_IO1   0x00000001	/* GROUP1_IO1 channel mode */
  #define TSC_IOCCR_G1_IO2   0x00000002	/* GROUP1_IO2 channel mode */
  #define TSC_IOCCR_G1_IO3   0x00000004	/* GROUP1_IO3 channel mode */
  #define TSC_IOCCR_G1_IO4   0x00000008	/* GROUP1_IO4 channel mode */
  #define TSC_IOCCR_G2_IO1   0x00000010	/* GROUP2_IO1 channel mode */
  #define TSC_IOCCR_G2_IO2   0x00000020	/* GROUP2_IO2 channel mode */
  #define TSC_IOCCR_G2_IO3   0x00000040	/* GROUP2_IO3 channel mode */
  #define TSC_IOCCR_G2_IO4   0x00000080	/* GROUP2_IO4 channel mode */
  #define TSC_IOCCR_G3_IO1   0x00000100	/* GROUP3_IO1 channel mode */
  #define TSC_IOCCR_G3_IO2   0x00000200	/* GROUP3_IO2 channel mode */
  #define TSC_IOCCR_G3_IO3   0x00000400	/* GROUP3_IO3 channel mode */
  #define TSC_IOCCR_G3_IO4   0x00000800	/* GROUP3_IO4 channel mode */
  #define TSC_IOCCR_G4_IO1   0x00001000	/* GROUP4_IO1 channel mode */
  #define TSC_IOCCR_G4_IO2   0x00002000	/* GROUP4_IO2 channel mode */
  #define TSC_IOCCR_G4_IO3   0x00004000	/* GROUP4_IO3 channel mode */
  #define TSC_IOCCR_G4_IO4   0x00008000	/* GROUP4_IO4 channel mode */
  #define TSC_IOCCR_G5_IO1   0x00010000	/* GROUP5_IO1 channel mode */
  #define TSC_IOCCR_G5_IO2   0x00020000	/* GROUP5_IO2 channel mode */
  #define TSC_IOCCR_G5_IO3   0x00040000	/* GROUP5_IO3 channel mode */
  #define TSC_IOCCR_G5_IO4   0x00080000	/* GROUP5_IO4 channel mode */
  #define TSC_IOCCR_G6_IO1   0x00100000	/* GROUP6_IO1 channel mode */
  #define TSC_IOCCR_G6_IO2   0x00200000	/* GROUP6_IO2 channel mode */
  #define TSC_IOCCR_G6_IO3   0x00400000	/* GROUP6_IO3 channel mode */
  #define TSC_IOCCR_G6_IO4   0x00800000	/* GROUP6_IO4 channel mode */
  #define TSC_IOCCR_G7_IO1   0x01000000	/* GROUP7_IO1 channel mode */
  #define TSC_IOCCR_G7_IO2   0x02000000	/* GROUP7_IO2 channel mode */
  #define TSC_IOCCR_G7_IO3   0x04000000	/* GROUP7_IO3 channel mode */
  #define TSC_IOCCR_G7_IO4   0x08000000	/* GROUP7_IO4 channel mode */
#define TOFF_TSC_IOGCSR     0x0030		/* (RW) TSC I/O group control status register */
  #define TSC_IOGCSR_G1E     0x00000001	/* Analog IO GROUP1 enable */
  #define TSC_IOGCSR_G2E     0x00000002	/* Analog IO GROUP2 enable */
  #define TSC_IOGCSR_G3E     0x00000004	/* Analog IO GROUP3 enable */
  #define TSC_IOGCSR_G4E     0x00000008	/* Analog IO GROUP4 enable */
  #define TSC_IOGCSR_G5E     0x00000010	/* Analog IO GROUP5 enable */
  #define TSC_IOGCSR_G6E     0x00000020	/* Analog IO GROUP6 enable */
  #define TSC_IOGCSR_G7E     0x00000040	/* Analog IO GROUP7 enable */
  #define TSC_IOGCSR_G8E     0x00000080	/* Analog IO GROUP8 enable */
  #define TSC_IOGCSR_G1S     0x00010000	/* Analog IO GROUP1 status */
  #define TSC_IOGCSR_G2S     0x00020000	/* Analog IO GROUP2 status */
  #define TSC_IOGCSR_G3S     0x00040000	/* Analog IO GROUP3 status */
  #define TSC_IOGCSR_G4S     0x00080000	/* Analog IO GROUP4 status */
  #define TSC_IOGCSR_G5S     0x00100000	/* Analog IO GROUP5 status */
  #define TSC_IOGCSR_G6S     0x00200000	/* Analog IO GROUP6 status */
  #define TSC_IOGCSR_G7S     0x00400000	/* Analog IO GROUP7 status */
#define TOFF_TSC_IOGXCR     0x0034		/* (RW) TSC I/O group x counter register 0x34-50 */
  #define TSC_IOGXCR_CNT     0x00003FFF	/* CNT[13:0] bits (Counter value) */


/*
 *  GENERAL PURPOSE I/O
 */
#define TADR_GPIOA_BASE     (AHB2PERIPH_BASE + 0x0000)
#define TADR_GPIOB_BASE     (AHB2PERIPH_BASE + 0x0400)
#define TADR_GPIOC_BASE     (AHB2PERIPH_BASE + 0x0800)
#define TADR_GPIOD_BASE     (AHB2PERIPH_BASE + 0x0C00)
#define TADR_GPIOE_BASE     (AHB2PERIPH_BASE + 0x1000)
#define TADR_GPIOH_BASE     (AHB2PERIPH_BASE + 0x1C00)
#define TOFF_GPIO_MODER     0x0000		/* (RW) GPIO port mode register */
  #define GPIO_MODER_MODER0  0x1
  #define GPIO_MODER_MODER1  0x2
  #define GPIO_MODER_MODER2  0x3
#define TOFF_GPIO_OTYPER    0x0004		/* (RW) GPIO port output type register */
  #define GPIO_OTYPER_OT     0x1
#define TOFF_GPIO_OSPEEDR   0x0008		/* (RW) GPIO port output speed register */
  #define GPIO_OSPEEDER_OSPEEDR0 0x1
  #define GPIO_OSPEEDER_OSPEEDR1 0x2
  #define GPIO_OSPEEDER_OSPEEDR2 0x3
#define TOFF_GPIO_PUPDR     0x000C		/* (RW) GPIO port pull-up/pull-down register */
  #define GPIO_PUPDR_PUPDR0  0x1
  #define GPIO_PUPDR_PUPDR1  0x2
  #define GPIO_PUPDR_PUPDR2  0x3
#define TOFF_GPIO_IDR       0x0010		/* (R)  GPIO port input data register */
#define TOFF_GPIO_ODR       0x0014		/* (RW) GPIO port output data register */
#define TOFF_GPIO_BSRR      0x0018		/* (RW) GPIO port bit set/reset low register */
#define TOFF_GPIO_LCKR      0x001C		/* (RW) GPIO port configuration lock register */
#define TOFF_GPIO_AFR0      0x0020		/* (RW) GPIO alternate function registers */
#define TOFF_GPIO_AFR1      0x0024		/* (RW) GPIO alternate function registers */
#define TOFF_GPIO_BRR       0x0028		/* (RW) GPIO Bit Reset register */


/*
 *  ANALOG TO DIGITAL CONVERTER
 */
#define TADR_ADC1_BASE      (AHB2PERIPH_BASE + 0x08040000)
#define TOFF_ADC_ISR        0x0000		/* (RW) ADC interrupt and status register */
  #define ADC_ISR_ADRDY      0x00000001	/* ADC ready flag */
  #define ADC_ISR_EOSMP      0x00000002	/* ADC group regular end of sampling flag */
  #define ADC_ISR_EOC        0x00000004	/* ADC group regular end of unitary conversion flag */
  #define ADC_ISR_EOS        0x00000008	/* ADC End of Sequence flag */
  #define ADC_ISR_OVR        0x00000010	/* ADC group regular overrun flag */
  #define ADC_ISR_JEOC       0x00000020	/* ADC group injected end of unitary conversion flag */
  #define ADC_ISR_JEOS       0x00000040	/* ADC group injected end of sequence conversions flag */
  #define ADC_ISR_AWD1       0x00000080	/* ADC analog watchdog 1 flag */
  #define ADC_ISR_AWD2       0x00000100	/* ADC analog watchdog 2 flag */
  #define ADC_ISR_AWD3       0x00000200	/* ADC analog watchdog 3 flag */
  #define ADC_ISR_JQOVF      0x00000400	/* ADC group injected contexts queue overflow flag */
#define TOFF_ADC_IER        0x0004		/* (RW) ADC interrupt enable register */
  #define ADC_IER_ADRDYIE    0x00000001	/* ADC ready interrupt */
  #define ADC_IER_EOSMPIE    0x00000002	/* ADC group regular end of sampling interrupt */
  #define ADC_IER_EOCIE      0x00000004	/* ADC group regular end of unitary conversion interrupt */
  #define ADC_IER_EOSIE      0x00000008	/* ADC End of Sequence of conversion interrupt enable */
  #define ADC_IER_OVRIE      0x00000010	/* ADC group regular overrun interrupt */
  #define ADC_IER_JEOCIE     0x00000020	/* ADC group injected end of unitary conversion interrupt */
  #define ADC_IER_JEOSIE     0x00000040	/* ADC group injected end of sequence conversions interrupt */
  #define ADC_IER_AWD1IE     0x00000080	/* ADC analog watchdog 1 interrupt */
  #define ADC_IER_AWD2IE     0x00000100	/* ADC analog watchdog 2 interrupt */
  #define ADC_IER_AWD3IE     0x00000200	/* ADC analog watchdog 3 interrupt */
  #define ADC_IER_JQOVFIE    0x00000400	/* ADC group injected contexts queue overflow interrupt */
#define TOFF_ADC_CR         0x0008		/* (RW) ADC control register */
  #define ADC_CR_ADEN        0x00000001	/* ADC enable */
  #define ADC_CR_ADDIS       0x00000002	/* ADC disable */
  #define ADC_CR_ADSTART     0x00000004	/* ADC group regular conversion start */
  #define ADC_CR_JADSTART    0x00000008	/* ADC group injected conversion start */
  #define ADC_CR_ADSTP       0x00000010	/* ADC group regular conversion stop */
  #define ADC_CR_JADSTP      0x00000020	/* ADC group injected conversion stop */
  #define ADC_CR_ADVREGEN    0x10000000	/* ADC Voltage Regulator Enable */
  #define ADC_CR_DEEPPWD     0x20000000	/* ADC deep power down enable */
  #define ADC_CR_ADCALDIF    0x40000000	/* ADC differential mode for calibration */
  #define ADC_CR_ADCAL       0x80000000	/* ADC calibration */
#define TOFF_ADC_CFGR       0x000C		/* (RW) ADC configuration register 1 */
  #define ADC_CFGR_DMAEN     0x00000001	/* ADC DMA transfer enable */
  #define ADC_CFGR_DMACFG    0x00000002	/* ADC DMA transfer configuration */
  #define ADC_CFGR_SCANDIR   0x00000004	/* ADC group regular sequencer scan direction */
  #define ADC_CFGR_RES       0x00000018	/* ADC data resolution */
  #define ADC_CFGR_RES_0     0x00000008
  #define ADC_CFGR_RES_1     0x00000010
  #define ADC_CFGR_ALIGN     0x00000020	/* ADC data alignement */
  #define ADC_CFGR_EXTSEL    0x000003C0	/* ADC group regular external trigger source */
  #define ADC_CFGR_EXTSEL_0  0x00000040
  #define ADC_CFGR_EXTSEL_1  0x00000080
  #define ADC_CFGR_EXTSEL_2  0x00000100
  #define ADC_CFGR_EXTSEL_3  0x00000200
  #define ADC_CFGR_EXTEN     0x00000C00	/* ADC group regular external trigger polarity */
  #define ADC_CFGR_EXTEN_0   0x00000400
  #define ADC_CFGR_EXTEN_1   0x00000800
  #define ADC_CFGR_OVRMOD    0x00001000	/* ADC group regular overrun configuration */
  #define ADC_CFGR_CONT      0x00002000	/* ADC group regular continuous conversion mode */
  #define ADC_CFGR_AUTDLY    0x00004000	/* ADC low power auto wait */
  #define ADC_CFGR_DISCEN    0x00010000	/* ADC group regular sequencer discontinuous mode */
  #define ADC_CFGR_DISCNUM   0x000E0000	/* ADC group regular sequencer discontinuous number of ranks */
  #define ADC_CFGR_DISCNUM_0 0x00020000
  #define ADC_CFGR_DISCNUM_1 0x00040000
  #define ADC_CFGR_DISCNUM_2 0x00080000
  #define ADC_CFGR_JDISCEN   0x00100000	/* ADC group injected sequencer discontinuous mode */
  #define ADC_CFGR_JQM       0x00200000	/* ADC group injected contexts queue mode */
  #define ADC_CFGR_AWD1SGL   0x00400000	/* ADC analog watchdog 1 monitoring a single channel or all channels */
  #define ADC_CFGR_AWD1EN    0x00800000	/* ADC analog watchdog 1 enable on scope ADC group regular */
  #define ADC_CFGR_JAWD1EN   0x01000000	/* ADC analog watchdog 1 enable on scope ADC group injected */
  #define ADC_CFGR_JAUTO     0x02000000
  #define ADC_CFGR_AWD1CH    0x7C000000	/* ADC analog watchdog 1 monitored channel selection */
  #define ADC_CFGR_AWD1CH_0  0x04000000
  #define ADC_CFGR_AWD1CH_1  0x08000000
  #define ADC_CFGR_AWD1CH_2  0x10000000
  #define ADC_CFGR_AWD1CH_3  0x20000000
  #define ADC_CFGR_AWD1CH_4  0x40000000
  #define ADC_CFGR_JQDIS     0x80000000	/* ADC group injected contexts queue disable */
#define TOFF_ADC_CFGR2      0x0010	/* (RW) ADC configuration register 2 */
  #define ADC_CFGR2_ROVSE    0x00000001	/* ADC oversampler enable on scope ADC group regular */
  #define ADC_CFGR2_JOVSE    0x00000002	/* ADC oversampler enable on scope ADC group injected */
  #define ADC_CFGR2_OVSR     0x0000001C	/* ADC oversampling ratio */
  #define ADC_CFGR2_OVSR_0   0x00000004
  #define ADC_CFGR2_OVSR_1   0x00000008
  #define ADC_CFGR2_OVSR_2   0x00000010
  #define ADC_CFGR2_OVSS     0x000001E0	/* ADC oversampling shift */
  #define ADC_CFGR2_OVSS_0   0x00000020
  #define ADC_CFGR2_OVSS_1   0x00000040
  #define ADC_CFGR2_OVSS_2   0x00000080
  #define ADC_CFGR2_OVSS_3   0x00000100
  #define ADC_CFGR2_TROVS    0x00000200	/* ADC oversampling discontinuous mode (triggered mode) for ADC group regular */
  #define ADC_CFGR2_ROVSM    0x00000400	/* ADC oversampling mode managing interlaced conversions of ADC group regular and group injected */
#define TOFF_ADC_SMPR1      0x0014	/* (RW) ADC sampling time register 1 */
  #define ADC_SMPR1_SMP0     0x00000007	/* ADC channel 0 sampling time selection  */
  #define ADC_SMPR1_SMP0_0   0x00000001
  #define ADC_SMPR1_SMP0_1   0x00000002
  #define ADC_SMPR1_SMP0_2   0x00000004
  #define ADC_SMPR1_SMP1     0x00000038	/* ADC channel 1 sampling time selection  */
  #define ADC_SMPR1_SMP1_0   0x00000008
  #define ADC_SMPR1_SMP1_1   0x00000010
  #define ADC_SMPR1_SMP1_2   0x00000020
  #define ADC_SMPR1_SMP2     0x000001C0	/* ADC channel 2 sampling time selection  */
  #define ADC_SMPR1_SMP2_0   0x00000040
  #define ADC_SMPR1_SMP2_1   0x00000080
  #define ADC_SMPR1_SMP2_2   0x00000100
  #define ADC_SMPR1_SMP3     0x00000E00	/* ADC channel 3 sampling time selection  */
  #define ADC_SMPR1_SMP3_0   0x00000200
  #define ADC_SMPR1_SMP3_1   0x00000400
  #define ADC_SMPR1_SMP3_2   0x00000800
  #define ADC_SMPR1_SMP4     0x00007000	/* ADC channel 4 sampling time selection  */
  #define ADC_SMPR1_SMP4_0   0x00001000
  #define ADC_SMPR1_SMP4_1   0x00002000
  #define ADC_SMPR1_SMP4_2   0x00004000
  #define ADC_SMPR1_SMP5     0x00038000	/* ADC channel 5 sampling time selection  */
  #define ADC_SMPR1_SMP5_0   0x00008000
  #define ADC_SMPR1_SMP5_1   0x00010000
  #define ADC_SMPR1_SMP5_2   0x00020000
  #define ADC_SMPR1_SMP6     0x001C0000	/* ADC channel 6 sampling time selection  */
  #define ADC_SMPR1_SMP6_0   0x00040000
  #define ADC_SMPR1_SMP6_1   0x00080000
  #define ADC_SMPR1_SMP6_2   0x00100000
  #define ADC_SMPR1_SMP7     0x00E00000	/* ADC channel 7 sampling time selection  */
  #define ADC_SMPR1_SMP7_0   0x00200000
  #define ADC_SMPR1_SMP7_1   0x00400000
  #define ADC_SMPR1_SMP7_2   0x00800000
  #define ADC_SMPR1_SMP8     0x07000000	/* ADC channel 8 sampling time selection  */
  #define ADC_SMPR1_SMP8_0   0x01000000
  #define ADC_SMPR1_SMP8_1   0x02000000
  #define ADC_SMPR1_SMP8_2   0x04000000
  #define ADC_SMPR1_SMP9     0x38000000	/* ADC channel 9 sampling time selection  */
  #define ADC_SMPR1_SMP9_0   0x08000000
  #define ADC_SMPR1_SMP9_1   0x10000000
  #define ADC_SMPR1_SMP9_2   0x20000000
#define TOFF_ADC_SMPR2      0x0018	/* (RW) ADC sampling time register 2 */
  #define ADC_SMPR2_SMP10    0x00000007	/* ADC channel 10 sampling time selection  */
  #define ADC_SMPR2_SMP10_0  0x00000001
  #define ADC_SMPR2_SMP10_1  0x00000002
  #define ADC_SMPR2_SMP10_2  0x00000004
  #define ADC_SMPR2_SMP11    0x00000038	/* ADC channel 11 sampling time selection  */
  #define ADC_SMPR2_SMP11_0  0x00000008
  #define ADC_SMPR2_SMP11_1  0x00000010
  #define ADC_SMPR2_SMP11_2  0x00000020
  #define ADC_SMPR2_SMP12    0x000001C0	/* ADC channel 12 sampling time selection  */
  #define ADC_SMPR2_SMP12_0  0x00000040
  #define ADC_SMPR2_SMP12_1  0x00000080
  #define ADC_SMPR2_SMP12_2  0x00000100
  #define ADC_SMPR2_SMP13    0x00000E00	/* ADC channel 13 sampling time selection  */
  #define ADC_SMPR2_SMP13_0  0x00000200
  #define ADC_SMPR2_SMP13_1  0x00000400
  #define ADC_SMPR2_SMP13_2  0x00000800
  #define ADC_SMPR2_SMP14    0x00007000	/* ADC channel 14 sampling time selection  */
  #define ADC_SMPR2_SMP14_0  0x00001000
  #define ADC_SMPR2_SMP14_1  0x00002000
  #define ADC_SMPR2_SMP14_2  0x00004000
  #define ADC_SMPR2_SMP15    0x00038000	/* ADC channel 15 sampling time selection  */
  #define ADC_SMPR2_SMP15_0  0x00008000
  #define ADC_SMPR2_SMP15_1  0x00010000
  #define ADC_SMPR2_SMP15_2  0x00020000
  #define ADC_SMPR2_SMP16    0x001C0000	/* ADC channel 16 sampling time selection  */
  #define ADC_SMPR2_SMP16_0  0x00040000
  #define ADC_SMPR2_SMP16_1  0x00080000
  #define ADC_SMPR2_SMP16_2  0x00100000
  #define ADC_SMPR2_SMP17    0x00E00000	/* ADC channel 17 sampling time selection  */
  #define ADC_SMPR2_SMP17_0  0x00200000
  #define ADC_SMPR2_SMP17_1  0x00400000
  #define ADC_SMPR2_SMP17_2  0x00800000
  #define ADC_SMPR2_SMP18s   0x07000000	/* ADC channel 18 sampling time selection  */
  #define ADC_SMPR2_SMP18_0  0x01000000
  #define ADC_SMPR2_SMP18_1  0x02000000
  #define ADC_SMPR2_SMP18_2  0x04000000
#define TOFF_ADC_TR1        0x0020	/* (RW) ADC analog watchdog 1 threshold register */
  #define ADC_TR1_LT1        0x00000FFF	/* ADC analog watchdog 1 threshold low */
  #define ADC_TR1_LT1_0      0x00000001
  #define ADC_TR1_LT1_1      0x00000002
  #define ADC_TR1_LT1_2      0x00000004
  #define ADC_TR1_LT1_3      0x00000008
  #define ADC_TR1_LT1_4      0x00000010
  #define ADC_TR1_LT1_5      0x00000020
  #define ADC_TR1_LT1_6      0x00000040
  #define ADC_TR1_LT1_7      0x00000080
  #define ADC_TR1_LT1_8      0x00000100
  #define ADC_TR1_LT1_9      0x00000200
  #define ADC_TR1_LT1_10     0x00000400
  #define ADC_TR1_LT1_11     0x00000800
  #define ADC_TR1_HT1        0x0FFF0000	/* ADC Analog watchdog 1 threshold high */
  #define ADC_TR1_HT1_0      0x00010000
  #define ADC_TR1_HT1_1      0x00020000
  #define ADC_TR1_HT1_2      0x00040000
  #define ADC_TR1_HT1_3      0x00080000
  #define ADC_TR1_HT1_4      0x00100000
  #define ADC_TR1_HT1_5      0x00200000
  #define ADC_TR1_HT1_6      0x00400000
  #define ADC_TR1_HT1_7      0x00800000
  #define ADC_TR1_HT1_8      0x01000000
  #define ADC_TR1_HT1_9      0x02000000
  #define ADC_TR1_HT1_10     0x04000000
  #define ADC_TR1_HT1_11     0x08000000
#define TOFF_ADC_TR2        0x0024	/* (RW) ADC analog watchdog 2 threshold register */
  #define ADC_TR2_LT2        0x000000FF	/* ADC analog watchdog 2 threshold low */
  #define ADC_TR2_LT2_0      0x00000001
  #define ADC_TR2_LT2_1      0x00000002
  #define ADC_TR2_LT2_2      0x00000004
  #define ADC_TR2_LT2_3      0x00000008
  #define ADC_TR2_LT2_4      0x00000010
  #define ADC_TR2_LT2_5      0x00000020
  #define ADC_TR2_LT2_6      0x00000040
  #define ADC_TR2_LT2_7      0x00000080
  #define ADC_TR2_HT2        0x00FF0000	/* ADC analog watchdog 2 threshold high */
  #define ADC_TR2_HT2_0      0x00010000
  #define ADC_TR2_HT2_1      0x00020000
  #define ADC_TR2_HT2_2      0x00040000
  #define ADC_TR2_HT2_3      0x00080000
  #define ADC_TR2_HT2_4      0x00100000
  #define ADC_TR2_HT2_5      0x00200000
  #define ADC_TR2_HT2_6      0x00400000
  #define ADC_TR2_HT2_7      0x00800000
#define TOFF_ADC_TR3        0x0028	/* (RW) ADC analog watchdog 3 threshold register */
  #define ADC_TR3_LT3        0x000000FF	/* ADC analog watchdog 3 threshold low */
  #define ADC_TR3_LT3_0      0x00000001
  #define ADC_TR3_LT3_1      0x00000002
  #define ADC_TR3_LT3_2      0x00000004
  #define ADC_TR3_LT3_3      0x00000008
  #define ADC_TR3_LT3_4      0x00000010
  #define ADC_TR3_LT3_5      0x00000020
  #define ADC_TR3_LT3_6      0x00000040
  #define ADC_TR3_LT3_7      0x00000080
  #define ADC_TR3_HT3        0x00FF0000	/* ADC analog watchdog 3 threshold high */
  #define ADC_TR3_HT3_0      0x00010000
  #define ADC_TR3_HT3_1      0x00020000
  #define ADC_TR3_HT3_2      0x00040000
  #define ADC_TR3_HT3_3      0x00080000
  #define ADC_TR3_HT3_4      0x00100000
  #define ADC_TR3_HT3_5      0x00200000
  #define ADC_TR3_HT3_6      0x00400000
  #define ADC_TR3_HT3_7      0x00800000
#define TOFF_ADC_SQR1       0x0030	/* (RW) ADC group regular sequencer register 1 */
  #define ADC_SQR1_L         0x0000000F	/* ADC group regular sequencer scan length */
  #define ADC_SQR1_L_0       0x00000001
  #define ADC_SQR1_L_1       0x00000002
  #define ADC_SQR1_L_2       0x00000004
  #define ADC_SQR1_L_3       0x00000008
  #define ADC_SQR1_SQ1       0x000007C0	/* ADC group regular sequencer rank 1 */
  #define ADC_SQR1_SQ1_0     0x00000040
  #define ADC_SQR1_SQ1_1     0x00000080
  #define ADC_SQR1_SQ1_2     0x00000100
  #define ADC_SQR1_SQ1_3     0x00000200
  #define ADC_SQR1_SQ1_4     0x00000400
  #define ADC_SQR1_SQ2       0x0001F000	/* ADC group regular sequencer rank 2 */
  #define ADC_SQR1_SQ2_0     0x00001000
  #define ADC_SQR1_SQ2_1     0x00002000
  #define ADC_SQR1_SQ2_2     0x00004000
  #define ADC_SQR1_SQ2_3     0x00008000
  #define ADC_SQR1_SQ2_4     0x00010000
  #define ADC_SQR1_SQ3       0x007C0000	/* ADC group regular sequencer rank 3 */
  #define ADC_SQR1_SQ3_0     0x00040000
  #define ADC_SQR1_SQ3_1     0x00080000
  #define ADC_SQR1_SQ3_2     0x00100000
  #define ADC_SQR1_SQ3_3     0x00200000
  #define ADC_SQR1_SQ3_4     0x00400000
  #define ADC_SQR1_SQ4       0x1F000000	/* ADC group regular sequencer rank 4 */
  #define ADC_SQR1_SQ4_0     0x01000000
  #define ADC_SQR1_SQ4_1     0x02000000
  #define ADC_SQR1_SQ4_2     0x04000000
  #define ADC_SQR1_SQ4_3     0x08000000
  #define ADC_SQR1_SQ4_4     0x10000000
#define TOFF_ADC_SQR2       0x0034	/* (RW) ADC group regular sequencer register 2 */
  #define ADC_SQR2_SQ5       0x0000001F	/* ADC group regular sequencer rank 5 */
  #define ADC_SQR2_SQ5_0     0x00000001
  #define ADC_SQR2_SQ5_1     0x00000002
  #define ADC_SQR2_SQ5_2     0x00000004
  #define ADC_SQR2_SQ5_3     0x00000008
  #define ADC_SQR2_SQ5_4     0x00000010
  #define ADC_SQR2_SQ6       0x000007C0	/* ADC group regular sequencer rank 6 */
  #define ADC_SQR2_SQ6_0     0x00000040
  #define ADC_SQR2_SQ6_1     0x00000080
  #define ADC_SQR2_SQ6_2     0x00000100
  #define ADC_SQR2_SQ6_3     0x00000200
  #define ADC_SQR2_SQ6_4     0x00000400
  #define ADC_SQR2_SQ7       0x0001F000	/* ADC group regular sequencer rank 7 */
  #define ADC_SQR2_SQ7_0     0x00001000
  #define ADC_SQR2_SQ7_1     0x00002000
  #define ADC_SQR2_SQ7_2     0x00004000
  #define ADC_SQR2_SQ7_3     0x00008000
  #define ADC_SQR2_SQ7_4     0x00010000
  #define ADC_SQR2_SQ8       0x007C0000	/* ADC group regular sequencer rank 8 */
  #define ADC_SQR2_SQ8_0     0x00040000
  #define ADC_SQR2_SQ8_1     0x00080000
  #define ADC_SQR2_SQ8_2     0x00100000
  #define ADC_SQR2_SQ8_3     0x00200000
  #define ADC_SQR2_SQ8_4     0x00400000
  #define ADC_SQR2_SQ9       0x1F000000	/* ADC group regular sequencer rank 9 */
  #define ADC_SQR2_SQ9_0     0x01000000
  #define ADC_SQR2_SQ9_1     0x02000000
  #define ADC_SQR2_SQ9_2     0x04000000
  #define ADC_SQR2_SQ9_3     0x08000000
  #define ADC_SQR2_SQ9_4     0x10000000
#define TOFF_ADC_SQR3       0x0038	/* (RW) ADC group regular sequencer register 3 */
  #define ADC_SQR3_SQ10      0x0000001F	/* ADC group regular sequencer rank 10 */
  #define ADC_SQR3_SQ10_0    0x00000001
  #define ADC_SQR3_SQ10_1    0x00000002
  #define ADC_SQR3_SQ10_2    0x00000004
  #define ADC_SQR3_SQ10_3    0x00000008
  #define ADC_SQR3_SQ10_4    0x00000010
  #define ADC_SQR3_SQ11      0x000007C0	/* ADC group regular sequencer rank 11 */
  #define ADC_SQR3_SQ11_0    0x00000040
  #define ADC_SQR3_SQ11_1    0x00000080
  #define ADC_SQR3_SQ11_2    0x00000100
  #define ADC_SQR3_SQ11_3    0x00000200
  #define ADC_SQR3_SQ11_4    0x00000400
  #define ADC_SQR3_SQ12      0x0001F000	/* ADC group regular sequencer rank 12 */
  #define ADC_SQR3_SQ12_0    0x00001000
  #define ADC_SQR3_SQ12_1    0x00002000
  #define ADC_SQR3_SQ12_2    0x00004000
  #define ADC_SQR3_SQ12_3    0x00008000
  #define ADC_SQR3_SQ12_4    0x00010000
  #define ADC_SQR3_SQ13      0x007C0000	/* ADC group regular sequencer rank 13 */
  #define ADC_SQR3_SQ13_0    0x00040000
  #define ADC_SQR3_SQ13_1    0x00080000
  #define ADC_SQR3_SQ13_2    0x00100000
  #define ADC_SQR3_SQ13_3    0x00200000
  #define ADC_SQR3_SQ13_4    0x00400000
  #define ADC_SQR3_SQ14      0x1F000000	/* ADC group regular sequencer rank 14 */
  #define ADC_SQR3_SQ14_0    0x01000000
  #define ADC_SQR3_SQ14_1    0x02000000
  #define ADC_SQR3_SQ14_2    0x04000000
  #define ADC_SQR3_SQ14_3    0x08000000
  #define ADC_SQR3_SQ14_4    0x10000000
#define TOFF_ADC_SQR4       0x003C	/* (RW) ADC group regular sequencer register 4 */
  #define ADC_SQR4_SQ15      0x0000001F	/* ADC group regular sequencer rank 15 */
  #define ADC_SQR4_SQ15_0    0x00000001
  #define ADC_SQR4_SQ15_1    0x00000002
  #define ADC_SQR4_SQ15_2    0x00000004
  #define ADC_SQR4_SQ15_3    0x00000008
  #define ADC_SQR4_SQ15_4    0x00000010
  #define ADC_SQR4_SQ16      0x000007C0	/* ADC group regular sequencer rank 16 */
  #define ADC_SQR4_SQ16_0    0x00000040
  #define ADC_SQR4_SQ16_1    0x00000080
  #define ADC_SQR4_SQ16_2    0x00000100
  #define ADC_SQR4_SQ16_3    0x00000200
  #define ADC_SQR4_SQ16_4    0x00000400
#define TOFF_ADC_DR         0x0040		/* (RW) ADC group regular data register */
  #define ADC_DR_DATA        0x0000FFFF	/* ADC group regular conversion data */
#define TOFF_ADC_JSQR       0x004C	/* (RW) ADC group injected sequencer register */
  #define ADC_JSQR_JL        0x00000003	/* ADC group injected sequencer scan length */
  #define ADC_JSQR_JL_0      0x00000001
  #define ADC_JSQR_JL_1      0x00000002
  #define ADC_JSQR_JEXTSEL   0x0000003C	/* ADC group injected external trigger source */
  #define ADC_JSQR_JEXTSEL_0 0x00000004
  #define ADC_JSQR_JEXTSEL_1 0x00000008
  #define ADC_JSQR_JEXTSEL_2 0x00000010
  #define ADC_JSQR_JEXTSEL_3 0x00000020
  #define ADC_JSQR_JEXTEN    0x000000C0	/* ADC group injected external trigger polarity */
  #define ADC_JSQR_JEXTEN_0  0x00000040
  #define ADC_JSQR_JEXTEN_1  0x00000080
  #define ADC_JSQR_JSQ1      0x00001F00	/* ADC group injected sequencer rank 1 */
  #define ADC_JSQR_JSQ1_0    0x00000100
  #define ADC_JSQR_JSQ1_1    0x00000200
  #define ADC_JSQR_JSQ1_2    0x00000400
  #define ADC_JSQR_JSQ1_3    0x00000800
  #define ADC_JSQR_JSQ1_4    0x00001000
  #define ADC_JSQR_JSQ2      0x0007C000	/* ADC group injected sequencer rank 2 */
  #define ADC_JSQR_JSQ2_0    0x00004000
  #define ADC_JSQR_JSQ2_1    0x00008000
  #define ADC_JSQR_JSQ2_2    0x00010000
  #define ADC_JSQR_JSQ2_3    0x00020000
  #define ADC_JSQR_JSQ2_4    0x00040000
  #define ADC_JSQR_JSQ3      0x01F00000	/* ADC group injected sequencer rank 3 */
  #define ADC_JSQR_JSQ3_0    0x00100000
  #define ADC_JSQR_JSQ3_1    0x00200000
  #define ADC_JSQR_JSQ3_2    0x00400000
  #define ADC_JSQR_JSQ3_3    0x00800000
  #define ADC_JSQR_JSQ3_4    0x01000000
  #define ADC_JSQR_JSQ4      0x7C000000	/* ADC group injected sequencer rank 4 */
  #define ADC_JSQR_JSQ4_0    0x04000000
  #define ADC_JSQR_JSQ4_1    0x08000000
  #define ADC_JSQR_JSQ4_2    0x10000000
  #define ADC_JSQR_JSQ4_3    0x20000000
  #define ADC_JSQR_JSQ4_4    0x40000000
#define TOFF_ADC_OFR1       0x0060	/* (RW) ADC offset register 1 */
  #define ADC_OFR1_OFFSET1    0x00000FFF	/* ADC offset number 1 offset level */
  #define ADC_OFR1_OFFSET1_CH 0x7C000000	/* ADC offset number 1 channel selection */
  #define ADC_OFR1_OFFSET1_EN 0x80000000	/* ADC offset number 1 enable */
#define TOFF_ADC_OFR2       0x0064	/* (RW) ADC offset register 2 */
  #define ADC_OFR2_OFFSET2    0x00000FFF	/* ADC offset number 2 offset level */
  #define ADC_OFR2_OFFSET2_CH 0x7C000000	/* ADC offset number 2 channel selection */
  #define ADC_OFR2_OFFSET2_EN 0x80000000	/* ADC offset number 2 enable */
#define TOFF_ADC_OFR3       0x0068	/* (RW) ADC offset register 3 */
  #define ADC_OFR3_OFFSET3    0x00000FFF	/* ADC offset number 3 offset level */
  #define ADC_OFR3_OFFSET3_CH 0x7C000000	/* ADC offset number 3 channel selection */
  #define ADC_OFR3_OFFSET3_EN 0x80000000	/* ADC offset number 3 enable */
#define TOFF_ADC_OFR4       0x006C	/* (RW) ADC offset register 4 */
  #define ADC_OFR4_OFFSET4    0x00000FFF	/* ADC offset number 4 offset level */
  #define ADC_OFR4_OFFSET4_CH 0x7C000000	/* ADC offset number 4 channel selection */
  #define ADC_OFR4_OFFSET4_EN 0x80000000	/* ADC offset number 4 enable */
#define TOFF_ADC_JDR1       0x0080	/* (RW) ADC group injected rank 1 data register */
  #define ADC_JDR1_JDATA     0x0000FFFF	/* ADC group injected sequencer rank 1 conversion data */
#define TOFF_ADC_JDR2       0x0084	/* (RW) ADC group injected rank 2 data register */
  #define ADC_JDR2_JDATA     0x0000FFFF	/* ADC group injected sequencer rank 2 conversion data */
#define TOFF_ADC_JDR3       0x0088	/* (RW) ADC group injected rank 3 data register */
  #define ADC_JDR3_JDATA     0x0000FFFF	/* ADC group injected sequencer rank 3 conversion data */
#define TOFF_ADC_JDR4       0x008C	/* (RW) ADC group injected rank 4 data register */
  #define ADC_JDR4_JDATA     0x0000FFFF	/* ADC group injected sequencer rank 4 conversion data */
#define TOFF_ADC_AWD2CR     0x00A0	/* (RW) ADC analog watchdog 1 configuration register */
  #define ADC_AWD2CR_AWD2CH  0x0007FFFF	/* ADC analog watchdog 2 monitored channel selection */
#define TOFF_ADC_AWD3CR     0x00A4	/* (RW) ADC analog watchdog 3 Configuration Register */
  #define ADC_AWD3CR_AWD3CH  0x0007FFFF	/* ADC analog watchdog 3 monitored channel selection */
#define TOFF_ADC_DIFSEL     0x00B0	/* (RW) ADC differential mode selection register */
  #define ADC_DIFSEL_DIFSEL  0x0007FFFF	/* ADC channel differential or single-ended mode */
#define TOFF_ADC_CALFACT    0x00B4		/* ADC data register */
  #define ADC_CALFACT_CALFACT_S 0x0000007F	/* Calibration factor */
  #define ADC_CALFACT_CALFACT_D 0x007F0000	/* Calibration factor */

#define TADR_ADC_BASE       (AHB2PERIPH_BASE + 0x08040300)
#define TOFF_ADC_CCR        0x0008		/* (RW) ADC common configuration register */
  #define ADC_CCR_DUAL       0x0000001F	/* ADC multimode mode selection */
  #define ADC_CCR_DUAL_0     0x00000001
  #define ADC_CCR_DUAL_1     0x00000002
  #define ADC_CCR_DUAL_2     0x00000004
  #define ADC_CCR_DUAL_3     0x00000008
  #define ADC_CCR_DUAL_4     0x00000010
  #define ADC_CCR_DELAY      0x00000F00	/* ADC multimode delay between 2 sampling phases */
  #define ADC_CCR_DELAY_0    0x00000100
  #define ADC_CCR_DELAY_1    0x00000200
  #define ADC_CCR_DELAY_2    0x00000400
  #define ADC_CCR_DELAY_3    0x00000800
  #define ADC_CCR_DMACFG     0x00002000	/* ADC multimode DMA transfer configuration */
  #define ADC_CCR_MDMA       0x0000C000	/* ADC multimode DMA transfer enable */
  #define ADC_CCR_MDMA_0     0x00004000
  #define ADC_CCR_MDMA_1     0x00008000
  #define ADC_CCR_CKMODE     0x00030000	/* ADC common clock source and prescaler (prescaler only for clock source synchronous) */
  #define ADC_CCR_CKMODE_0   0x00010000
  #define ADC_CCR_CKMODE_1   0x00020000
  #define ADC_CCR_PRESC      0x003C0000	/* ADC common clock prescaler, only for clock source asynchronous */
  #define ADC_CCR_PRESC_0    0x00040000
  #define ADC_CCR_PRESC_1    0x00080000
  #define ADC_CCR_PRESC_2    0x00100000
  #define ADC_CCR_PRESC_3    0x00200000
  #define ADC_CCR_VREFEN     0x00400000	/* ADC internal path to VrefInt enable */
  #define ADC_CCR_TSEN       0x00800000	/* ADC internal path to temperature sensor enable */
  #define ADC_CCR_VBATEN     0x01000000	/* ADC internal path to battery voltage enable */


/*
 *  AES HARDWARE ACCLELERATOR
 */
#define TADR_AES1_BASE      (AHB2PERIPH_BASE + 0x08060000)
#define TADR_AES2_BASE      (AHB4PERIPH_BASE + 0x00001800)
#define TOFF_AES_CR         0x0000		/* (RW) AES control register */
  #define AES_CR_EN          0x00000001	/* AES Enable */
  #define AES_CR_DATATYPE    0x00000006	/* Data type selection */
  #define AES_CR_DATATYPE_0  0x00000002
  #define AES_CR_DATATYPE_1  0x00000004
  #define AES_CR_MODE        0x00000018	/* AES Mode Of Operation */
  #define AES_CR_MODE_0      0x00000008
  #define AES_CR_MODE_1      0x00000010
  #define AES_CR_CHMOD       0x00010060	/* AES Chaining Mode */
  #define AES_CR_CHMOD_0     0x00000020
  #define AES_CR_CHMOD_1     0x00000040
  #define AES_CR_CHMOD_2     0x00010000
  #define AES_CR_CCFC        0x00000080	/* Computation Complete Flag Clear */
  #define AES_CR_ERRC        0x00000100	/* Error Clear */
  #define AES_CR_CCFIE       0x00000200	/* Computation Complete Flag Interrupt Enable */
  #define AES_CR_ERRIE       0x00000400	/* Error Interrupt Enable */
  #define AES_CR_DMAINEN     0x00000800	/* Enable data input phase DMA management */
  #define AES_CR_DMAOUTEN    0x00001000	/* Enable data output phase DMA management */
  #define AES_CR_GCMPH       0x00006000	/* GCM Phase */
  #define AES_CR_GCMPH_0     0x00002000
  #define AES_CR_GCMPH_1     0x00004000
  #define AES_CR_KEYSIZE     0x00040000	/* Key size selection */
  #define AES_CR_NPBLB       0x00F00000	/* Number of padding bytes in last payload block */
  #define AES_CR_NPBLB_0     0x00100000
  #define AES_CR_NPBLB_1     0x00200000
  #define AES_CR_NPBLB_2     0x00400000
  #define AES_CR_NPBLB_3     0x00800000
#define TOFF_AES_SR         0x0004		/* (RW) AES status register */
  #define AES_SR_CCF         0x00000001	/* Computation Complete Flag */
  #define AES_SR_RDERR       0x00000002	/* Read Error Flag */
  #define AES_SR_WRERR       0x00000004	/* Write Error Flag */
  #define AES_SR_BUSY        0x00000008	/* Busy Flag */
#define TOFF_AES_DINR       0x0008		/* (RW) AES data input register */
#define TOFF_AES_DOUTR      0x000C		/* (RW) AES data output register */
#define TOFF_AES_KEYR0      0x0010		/* (RW) AES key register 0 */
#define TOFF_AES_KEYR1      0x0014		/* (RW) AES key register 1 */
#define TOFF_AES_KEYR2      0x0018		/* (RW) AES key register 2 */
#define TOFF_AES_KEYR3      0x001C		/* (RW) AES key register 3 */
#define TOFF_AES_IVR0       0x0020		/* (RW) AES initialization vector register 0 */
#define TOFF_AES_IVR1       0x0024		/* (RW) AES initialization vector register 1 */
#define TOFF_AES_IVR2       0x0028		/* (RW) AES initialization vector register 2 */
#define TOFF_AES_IVR3       0x002C		/* (RW) AES initialization vector register 3 */
#define TOFF_AES_KEYR4      0x0030		/* (RW) AES key register 4 */
#define TOFF_AES_KEYR5      0x0034		/* (RW) AES key register 5 */
#define TOFF_AES_KEYR6      0x0038		/* (RW) AES key register 6 */
#define TOFF_AES_KEYR7      0x003C		/* (RW) AES key register 7 */
#define TOFF_AES_SUSP0R     0x0040		/* (RW) AES Suspend register 0 */
#define TOFF_AES_SUSP1R     0x0044		/* (RW) AES Suspend register 1 */
#define TOFF_AES_SUSP2R     0x0048		/* (RW) AES Suspend register 2 */
#define TOFF_AES_SUSP3R     0x004C		/* (RW) AES Suspend register 3 */
#define TOFF_AES_SUSP4R     0x0050		/* (RW) AES Suspend register 4 */
#define TOFF_AES_SUSP5R     0x0054		/* (RW) AES Suspend register 5 */
#define TOFF_AES_SUSP6R     0x0058		/* (RW) AES Suspend register 6 */
#define TOFF_AES_SUSP7R     0x005C		/* (RW) AES Suspend register 7 */


/*
 *  RESET AND CLOCK CONTROL
 */
#define TADR_RCC_BASE       (AHB4PERIPH_BASE + 0x0000)
#define TOFF_RCC_CR         0x0000		/* (RW) RCC clock control register */
  #define RCC_CR_MSION          0x00000001	/* Internal Multi Speed oscillator (MSI) clock enable */
  #define RCC_CR_MSIRDY         0x00000002	/* Internal Multi Speed oscillator (MSI) clock ready flag */
  #define RCC_CR_MSIPLLEN       0x00000004	/* Internal Multi Speed oscillator (MSI) PLL enable */
  #define RCC_CR_MSIRGSEL       0x00000008	/* Internal Multi Speed oscillator (MSI) range selection */
  #define RCC_CR_MSIRANGE       0x000000F0	/* Internal Multi Speed oscillator (MSI) clock Range */
  #define RCC_CR_MSIRANGE_0     0x00000000
  #define RCC_CR_MSIRANGE_1     0x00000010
  #define RCC_CR_MSIRANGE_2     0x00000020
  #define RCC_CR_MSIRANGE_3     0x00000030
  #define RCC_CR_MSIRANGE_4     0x00000040
  #define RCC_CR_MSIRANGE_5     0x00000050
  #define RCC_CR_MSIRANGE_6     0x00000060
  #define RCC_CR_MSIRANGE_7     0x00000070
  #define RCC_CR_MSIRANGE_8     0x00000080
  #define RCC_CR_MSIRANGE_9     0x00000090
  #define RCC_CR_MSIRANGE_10    0x000000A0
  #define RCC_CR_MSIRANGE_11    0x000000B0
  #define RCC_CR_HSION          0x00000100	/* Internal High Speed oscillator (HSI16) clock enable */
  #define RCC_CR_HSIKERON       0x00000200	/* Internal High Speed oscillator (HSI16) clock enable for some IPs Kernel */
  #define RCC_CR_HSIRDY         0x00000400	/* Internal High Speed oscillator (HSI16) clock ready flag */
  #define RCC_CR_HSIASFS        0x00000800	/* HSI16 Automatic Start from Stop */
  #define RCC_CR_HSIKERDY       0x00001000	/* Internal High Speed oscillator (HSI16) clock enable for some IPs Kernel ready flag*/
  #define RCC_CR_HSEON          0x00010000	/* External High Speed oscillator (HSE) clock enable */
  #define RCC_CR_HSERDY         0x00020000	/* External High Speed oscillator (HSE) clock ready */
  #define RCC_CR_HSEBYP         0x00040000	/* External High Speed oscillator (HSE) clock bypass */
  #define RCC_CR_CSSON          0x00080000	/* HSE Clock Security System enable */
  #define RCC_CR_HSEPRE         0x00100000	/* HSE sysclk prescaler */
  #define RCC_CR_PLLON          0x01000000	/* System PLL clock enable */
  #define RCC_CR_PLLRDY         0x02000000	/* System PLL clock ready */
  #define RCC_CR_PLLSAI1ON      0x04000000	/* SAI1 PLL enable */
  #define RCC_CR_PLLSAI1RDY     0x08000000	/* SAI1 PLL ready */
#define TOFF_RCC_ICSCR      0x0004		/* (RW) RCC Internal clock sources calibration register */
  #define RCC_ICSCR_MSICAL      0x000000FF	/* MSICAL[7:0] bits */
  #define RCC_ICSCR_MSICAL_0    0x00000001
  #define RCC_ICSCR_MSICAL_1    0x00000002
  #define RCC_ICSCR_MSICAL_2    0x00000004
  #define RCC_ICSCR_MSICAL_3    0x00000008
  #define RCC_ICSCR_MSICAL_4    0x00000010
  #define RCC_ICSCR_MSICAL_5    0x00000020
  #define RCC_ICSCR_MSICAL_6    0x00000040
  #define RCC_ICSCR_MSICAL_7    0x00000080
  #define RCC_ICSCR_MSITRIM     0x0000FF00	/* MSITRIM[7:0] bits */
  #define RCC_ICSCR_MSITRIM_0   0x00000100
  #define RCC_ICSCR_MSITRIM_1   0x00000200
  #define RCC_ICSCR_MSITRIM_2   0x00000400
  #define RCC_ICSCR_MSITRIM_3   0x00000800
  #define RCC_ICSCR_MSITRIM_4   0x00001000
  #define RCC_ICSCR_MSITRIM_5   0x00002000
  #define RCC_ICSCR_MSITRIM_6   0x00004000
  #define RCC_ICSCR_MSITRIM_7   0x00008000
  #define RCC_ICSCR_HSICAL      0x00FF0000	/* HSICAL[7:0] bits */
  #define RCC_ICSCR_HSICAL_0    0x00010000
  #define RCC_ICSCR_HSICAL_1    0x00020000
  #define RCC_ICSCR_HSICAL_2    0x00040000
  #define RCC_ICSCR_HSICAL_3    0x00080000
  #define RCC_ICSCR_HSICAL_4    0x00100000
  #define RCC_ICSCR_HSICAL_5    0x00200000
  #define RCC_ICSCR_HSICAL_6    0x00400000
  #define RCC_ICSCR_HSICAL_7    0x00800000
  #define RCC_ICSCR_HSITRIM     0x7F000000	/* HSITRIM[6:0] bits */
  #define RCC_ICSCR_HSITRIM_0   0x01000000
  #define RCC_ICSCR_HSITRIM_1   0x02000000
  #define RCC_ICSCR_HSITRIM_2   0x04000000
  #define RCC_ICSCR_HSITRIM_3   0x08000000
  #define RCC_ICSCR_HSITRIM_4   0x10000000
  #define RCC_ICSCR_HSITRIM_5   0x20000000
  #define RCC_ICSCR_HSITRIM_6   0x40000000
#define TOFF_RCC_CFGR       0x0008		/* (RW) RCC clock configuration register */
  #define RCC_CFGR_SW           0x00000003	/* SW[1:0] bits (System clock Switch) */
  #define RCC_CFGR_SW_0         0x00000001
  #define RCC_CFGR_SW_1         0x00000002
  #define RCC_CFGR_SW_MSI       0x00000000	/* MSI oscillator selection as system clock */
  #define RCC_CFGR_SW_HSI       0x00000001	/* HSI16 oscillator selection as system clock */
  #define RCC_CFGR_SW_HSE       0x00000002	/* HSE oscillator selection as system clock */
  #define RCC_CFGR_SW_PLL       0x00000003	/* PLL selection as system clock */
  #define RCC_CFGR_SWS          0x0000000C	/* SWS[1:0] bits (System Clock Switch Status) */
  #define RCC_CFGR_SWS_0        0x00000004
  #define RCC_CFGR_SWS_1        0x00000008
  #define RCC_CFGR_SWS_MSI      0x00000000	/* MSI oscillator used as system clock */
  #define RCC_CFGR_SWS_HSI      0x00000004	/* HSI16 oscillator used as system clock */
  #define RCC_CFGR_SWS_HSE      0x00000008	/* HSE oscillator used as system clock */
  #define RCC_CFGR_SWS_PLL      0x0000000C	/* PLL used as system clock */
  #define RCC_CFGR_HPRE         0x000000F0	/* HPRE[3:0] bits (AHB prescaler) */
  #define RCC_CFGR_HPRE_0       0x00000010
  #define RCC_CFGR_HPRE_1       0x00000020
  #define RCC_CFGR_HPRE_2       0x00000040
  #define RCC_CFGR_HPRE_3       0x00000080
  #define RCC_CFGR_HPRE_DIV1    0x00000000	/* SYSCLK not divided */
  #define RCC_CFGR_HPRE_DIV2    0x00000080	/* SYSCLK divided by 2 */
  #define RCC_CFGR_HPRE_DIV4    0x00000090	/* SYSCLK divided by 4 */
  #define RCC_CFGR_HPRE_DIV8    0x000000A0	/* SYSCLK divided by 8 */
  #define RCC_CFGR_HPRE_DIV16   0x000000B0	/* SYSCLK divided by 16 */
  #define RCC_CFGR_HPRE_DIV64   0x000000C0	/* SYSCLK divided by 64 */
  #define RCC_CFGR_HPRE_DIV128  0x000000D0	/* SYSCLK divided by 128 */
  #define RCC_CFGR_HPRE_DIV256  0x000000E0	/* SYSCLK divided by 256 */
  #define RCC_CFGR_HPRE_DIV512  0x000000F0	/* SYSCLK divided by 512 */
  #define RCC_CFGR_PPRE1        0x00000700	/* PRE1[2:0] bits (APB2 prescaler) */
  #define RCC_CFGR_PPRE1_0      0x00000100
  #define RCC_CFGR_PPRE1_1      0x00000200
  #define RCC_CFGR_PPRE1_2      0x00000400
  #define RCC_CFGR_PPRE1_DIV1   0x00000000	/* HCLK not divided */
  #define RCC_CFGR_PPRE1_DIV2   0x00000400	/* HCLK divided by 2 */
  #define RCC_CFGR_PPRE1_DIV4   0x00000500	/* HCLK divided by 4 */
  #define RCC_CFGR_PPRE1_DIV8   0x00000600	/* HCLK divided by 8 */
  #define RCC_CFGR_PPRE1_DIV16  0x00000700	/* HCLK divided by 16 */
  #define RCC_CFGR_PPRE2        0x00003800	/* PRE2[2:0] bits (APB2 prescaler) */
  #define RCC_CFGR_PPRE2_0      0x00000800
  #define RCC_CFGR_PPRE2_1      0x00001000
  #define RCC_CFGR_PPRE2_2      0x00002000
  #define RCC_CFGR_PPRE2_DIV1   0x00000000	/* HCLK not divided */
  #define RCC_CFGR_PPRE2_DIV2   0x00002000	/* HCLK divided by 2 */
  #define RCC_CFGR_PPRE2_DIV4   0x00002800	/* HCLK divided by 4 */
  #define RCC_CFGR_PPRE2_DIV8   0x00003000	/* HCLK divided by 8 */
  #define RCC_CFGR_PPRE2_DIV16  0x00003800	/* HCLK divided by 16 */
  #define RCC_CFGR_STOPWUCK     0x00008000	/* Wake Up from stop and CSS backup clock selection */
  #define RCC_CFGR_HPREF        0x00010000	/* AHB prescaler flag */
  #define RCC_CFGR_PPRE1F       0x00020000	/* CPU1 APB1 prescaler flag */
  #define RCC_CFGR_PPRE2F       0x00040000	/* APB2 prescaler flag */
  #define RCC_CFGR_MCOSEL       0x0F000000	/* MCOSEL [2:0] bits (Clock output selection) */
  #define RCC_CFGR_MCOSEL_0     0x01000000
  #define RCC_CFGR_MCOSEL_1     0x02000000
  #define RCC_CFGR_MCOSEL_2     0x04000000
  #define RCC_CFGR_MCOSEL_3     0x08000000
  #define RCC_CFGR_MCOPRE       0x70000000	/* MCO prescaler */
  #define RCC_CFGR_MCOPRE_0     0x10000000
  #define RCC_CFGR_MCOPRE_1     0x20000000
  #define RCC_CFGR_MCOPRE_2     0x40000000
  #define RCC_CFGR_MCOPRE_DIV1  0x00000000	/* MCO is divided by 1 */
  #define RCC_CFGR_MCOPRE_DIV2  0x10000000	/* MCO is divided by 2 */
  #define RCC_CFGR_MCOPRE_DIV4  0x20000000	/* MCO is divided by 4 */
  #define RCC_CFGR_MCOPRE_DIV8  0x30000000	/* MCO is divided by 8 */
  #define RCC_CFGR_MCOPRE_DIV16 0x40000000	/* MCO is divided by 16 */
  #define RCC_CFGR_MCO_PRE      RCC_CFGR_MCOPRE
  #define RCC_CFGR_MCO_PRE_1    RCC_CFGR_MCOPRE_DIV1
  #define RCC_CFGR_MCO_PRE_2    RCC_CFGR_MCOPRE_DIV2
  #define RCC_CFGR_MCO_PRE_4    RCC_CFGR_MCOPRE_DIV4
  #define RCC_CFGR_MCO_PRE_8    RCC_CFGR_MCOPRE_DIV8
  #define RCC_CFGR_MCO_PRE_16   RCC_CFGR_MCOPRE_DIV16
#define TOFF_RCC_PLLCFGR    0x000C		/* (RW) RCC system PLL configuration register */
  #define RCC_PLLCFGR_PLLSRC    0x00000003
  #define RCC_PLLCFGR_PLLSRC_MSI 0x00000001	/* MSI oscillator source clock selected */
  #define RCC_PLLCFGR_PLLSRC_HSI 0x00000002	/* HSI16 oscillator source clock selected */
  #define RCC_PLLCFGR_PLLSRC_HSE 0x00000003	/* HSE oscillator source clock selected */
  #define RCC_PLLCFGR_PLLM      0x00000070
  #define RCC_PLLCFGR_PLLM_0    0x00000010
  #define RCC_PLLCFGR_PLLM_1    0x00000020
  #define RCC_PLLCFGR_PLLM_2    0x00000040
  #define RCC_PLLCFGR_PLLN      0x00007F00
  #define RCC_PLLCFGR_PLLN_0    0x00000100
  #define RCC_PLLCFGR_PLLN_1    0x00000200
  #define RCC_PLLCFGR_PLLN_2    0x00000400
  #define RCC_PLLCFGR_PLLN_3    0x00000800
  #define RCC_PLLCFGR_PLLN_4    0x00001000
  #define RCC_PLLCFGR_PLLN_5    0x00002000
  #define RCC_PLLCFGR_PLLN_6    0x00004000
  #define RCC_PLLCFGR_PLLPEN    0x00010000
  #define RCC_PLLCFGR_PLLP      0x003E0000
  #define RCC_PLLCFGR_PLLP_0    0x00020000
  #define RCC_PLLCFGR_PLLP_1    0x00040000
  #define RCC_PLLCFGR_PLLP_2    0x00080000
  #define RCC_PLLCFGR_PLLP_3    0x00100000
  #define RCC_PLLCFGR_PLLP_4    0x00200000
  #define RCC_PLLCFGR_PLLQEN    0x01000000
  #define RCC_PLLCFGR_PLLQ      0x0E000000
  #define RCC_PLLCFGR_PLLQ_0    0x02000000
  #define RCC_PLLCFGR_PLLQ_1    0x04000000
  #define RCC_PLLCFGR_PLLQ_2    0x08000000
  #define RCC_PLLCFGR_PLLREN    0x10000000
  #define RCC_PLLCFGR_PLLR      0xE0000000
  #define RCC_PLLCFGR_PLLR_0    0x20000000
  #define RCC_PLLCFGR_PLLR_1    0x40000000
  #define RCC_PLLCFGR_PLLR_2    0x80000000
#define TOFF_RCC_PLLSAI1CFGR 0x0010		/* (RW) RCC PLL SAI1 configuration register */
  #define RCC_PLLSAI1CFGR_PLLN    0x00007F00
  #define RCC_PLLSAI1CFGR_PLLN_0  0x00000100
  #define RCC_PLLSAI1CFGR_PLLN_1  0x00000200
  #define RCC_PLLSAI1CFGR_PLLN_2  0x00000400
  #define RCC_PLLSAI1CFGR_PLLN_3  0x00000800
  #define RCC_PLLSAI1CFGR_PLLN_4  0x00001000
  #define RCC_PLLSAI1CFGR_PLLN_5  0x00002000
  #define RCC_PLLSAI1CFGR_PLLN_6  0x00004000
  #define RCC_PLLSAI1CFGR_PLLPEN  0x00010000
  #define RCC_PLLSAI1CFGR_PLLP    0x003E0000
  #define RCC_PLLSAI1CFGR_PLLP_0  0x00020000
  #define RCC_PLLSAI1CFGR_PLLP_1  0x00040000
  #define RCC_PLLSAI1CFGR_PLLP_2  0x00080000
  #define RCC_PLLSAI1CFGR_PLLP_3  0x00100000
  #define RCC_PLLSAI1CFGR_PLLP_4  0x00200000
  #define RCC_PLLSAI1CFGR_PLLQEN  0x01000000
  #define RCC_PLLSAI1CFGR_PLLQ    0x0E000000
  #define RCC_PLLSAI1CFGR_PLLQ_0  0x02000000
  #define RCC_PLLSAI1CFGR_PLLQ_1  0x04000000
  #define RCC_PLLSAI1CFGR_PLLQ_2  0x08000000
  #define RCC_PLLSAI1CFGR_PLLREN  0x10000000
  #define RCC_PLLSAI1CFGR_PLLR    0xE0000000
  #define RCC_PLLSAI1CFGR_PLLR_0  0x20000000
  #define RCC_PLLSAI1CFGR_PLLR_1  0x40000000
  #define RCC_PLLSAI1CFGR_PLLR_2  0x80000000
#define TOFF_RCC_CIER       0x0018		/* (RW) RCC clock interrupt enable register */
  #define RCC_CIER_LSIRDYIE     0x00000001
  #define RCC_CIER_LSI1RDYIE    RCC_CIER_LSIRDYIE
  #define RCC_CIER_LSERDYIE     0x00000002
  #define RCC_CIER_MSIRDYIE     0x00000004
  #define RCC_CIER_HSIRDYIE     0x00000008
  #define RCC_CIER_HSERDYIE     0x00000010
  #define RCC_CIER_PLLRDYIE     0x00000020
  #define RCC_CIER_PLLSAI1RDYIE 0x00000040
  #define RCC_CIER_LSECSSIE     0x00000200
  #define RCC_CIER_HSI48RDYIE   0x00000400
  #define RCC_CIER_LSI2RDYIE    0x00000800
#define TOFF_RCC_CIFR       0x001C		/* (RW) RCC clock interrupt flag register */
  #define RCC_CIFR_LSIRDYF      0x00000001
  #define RCC_CIFR_LSI1RDYF     RCC_CIFR_LSIRDYF
  #define RCC_CIFR_LSERDYF      0x00000002
  #define RCC_CIFR_MSIRDYF      0x00000004
  #define RCC_CIFR_HSIRDYF      0x00000008
  #define RCC_CIFR_HSERDYF      0x00000010
  #define RCC_CIFR_PLLRDYF      0x00000020
  #define RCC_CIFR_PLLSAI1RDYF  0x00000040
  #define RCC_CIFR_PLLSAI2RDYF  0x00000080
  #define RCC_CIFR_CSSF         0x00000100
  #define RCC_CIFR_LSECSSF      0x00000200
  #define RCC_CIFR_HSI48RDYF    0x00000400
  #define RCC_CIFR_LSI2RDYF     0x00000800
#define TOFF_RCC_CICR       0x0020		/* (RW) RCC clock interrupt clear register */
  #define RCC_CICR_LSIRDYC      0x00000001
  #define RCC_CICR_LSI1RDYC     RCC_CICR_LSIRDYC
  #define RCC_CICR_LSERDYC      0x00000002
  #define RCC_CICR_MSIRDYC      0x00000004
  #define RCC_CICR_HSIRDYC      0x00000008
  #define RCC_CICR_HSERDYC      0x00000010
  #define RCC_CICR_PLLRDYC      0x00000020
  #define RCC_CICR_PLLSAI1RDYC  0x00000040
  #define RCC_CICR_PLLSAI2RDYC  0x00000080
  #define RCC_CICR_CSSC         0x00000100
  #define RCC_CICR_LSECSSC      0x00000200
  #define RCC_CICR_HSI48RDYC    0x00000400
  #define RCC_CICR_LSI2RDYC     0x00000800
#define TOFF_RCC_SMPSCR     0x0024		/* (RW) RCC Clock Interrupt Clear Register */
  #define RCC_SMPSCR_SMPSSEL    0x00000003
  #define RCC_SMPSCR_SMPSSEL_0  0x00000001
  #define RCC_SMPSCR_SMPSSEL_1  0x00000002
  #define RCC_SMPSCR_SMPSDIV    0x00000030
  #define RCC_SMPSCR_SMPSDIV_0  0x00000010
  #define RCC_SMPSCR_SMPSDIV_1  0x00000020
  #define RCC_SMPSCR_SMPSSWS    0x00000300
  #define RCC_SMPSCR_SMPSSWS_0  0x00000100
  #define RCC_SMPSCR_SMPSSWS_1  0x00000200
#define TOFF_RCC_AHB1RSTR   0x0028		/* (RW) RCC AHB1 peripheral reset register */
  #define RCC_AHB1RSTR_DMA1RST  0x00000001	/* DMA1 reset */
  #define RCC_AHB1RSTR_DMA2RST  0x00000002	/* DMA2 reset */
  #define RCC_AHB1RSTR_DMAMUX1RST 0x00000004		/* DMAMUX1 reset */
  #define RCC_AHB1RSTR_CRCRST   0x00001000	/* CRC reset */
  #define RCC_AHB1RSTR_TSCRST   0x00010000	/* TSC reset */
#define TOFF_RCC_AHB2RSTR   0x002C		/* (RW) RCC AHB2 peripheral reset register */
  #define RCC_AHB2RSTR_GPIOARST 0x00000001	/* GPIOA reset */
  #define RCC_AHB2RSTR_GPIOBRST 0x00000002	/* GPIOB reset */
  #define RCC_AHB2RSTR_GPIOCRST 0x00000004	/* GPIOC reset */
  #define RCC_AHB2RSTR_GPIODRST 0x00000008	/* GPIOD reset */
  #define RCC_AHB2RSTR_GPIOERST 0x00000010	/* GPIOE reset */
  #define RCC_AHB2RSTR_GPIOHRST 0x00000080	/* GPIOH reset */
  #define RCC_AHB2RSTR_OTGFSRST 0x00001000	/* USB_OTG FS reset */
  #define RCC_AHB2RSTR_ADCRST   0x00002000	/* ADC reset */
  #define RCC_AHB2RSTR_AES1RST  0x00010000	/* AES1 reset */
#define TOFF_RCC_AHB3RSTR   0x0030		/* (RW) RCC AHB3 peripheral reset register */
  #define RCC_AHB3RSTR_QUADSPIRST 0x00000100	/* QAUDSPI reset */
  #define RCC_AHB3RSTR_PKARST   0x00010000	/* PKA reset */
  #define RCC_AHB3RSTR_AES2RST  0x00020000	/* AES2 reset */
  #define RCC_AHB3RSTR_RNGRST   0x00040000	/* RNG reset */
  #define RCC_AHB3RSTR_HSEMRST  0x00080000	/* HSEM reset */
  #define RCC_AHB3RSTR_IPCCRST  0x00100000	/* IPCC reset */
  #define RCC_AHB3RSTR_FLASHRST 0x02000000	/* FLASH reset */
#define TOFF_RCC_APB1RSTR1  0x0038		/* (RW) RCC APB1 peripheral reset register 1 */
  #define RCC_APB1RSTR1_TIM2RST   0x00000001	/* TIMER2 reset */
  #define RCC_APB1RSTR1_LCDRST    0x00000200	/* LCD reset */
  #define RCC_APB1RSTR1_SPI2RST   0x00004000	/* SPI2 reset */
  #define RCC_APB1RSTR1_I2C1RST   0x00200000	/* I2C1 reset */
  #define RCC_APB1RSTR1_I2C3RST   0x00800000	/* I2C3 reset */
  #define RCC_APB1RSTR1_CRSRST    0x01000000	/* CRS reset */
  #define RCC_APB1RSTR1_USBRST    0x04000000	/* USB reset */
  #define RCC_APB1RSTR1_LPTIM1RST 0x80000000	/* LPTIM1 reset */
#define TOFF_RCC_APB1RSTR2  0x003C		/* (RW) RCC APB1 peripheral reset register 2 */
  #define RCC_APB1RSTR2_LPUART1RST 0x00000001	/* LPUART1 reset */
  #define RCC_APB1RSTR2_LPTIM2RST  0x00000020	/* LPTIMER2 reset */
#define TOFF_RCC_APB2RSTR   0x0040		/* (RW) RCC APB2 peripheral reset register */
  #define RCC_APB2RSTR_TIM1RST    0x00000800	/* TIMER1 reset */
  #define RCC_APB2RSTR_SPI1RST    0x00001000	/* SPI1 reset */
  #define RCC_APB2RSTR_USART1RST  0x00004000	/* USART1 reset */
  #define RCC_APB2RSTR_TIM16RST   0x00020000	/* TIMER16 reset */
  #define RCC_APB2RSTR_TIM17RST   0x00040000	/* TIMER17 reset */
  #define RCC_APB2RSTR_SAI1RST    0x00200000	/* SAI1 reset */
#define TOFF_RCC_APB3RSTR   0x0044		/* (RW) RCC APB3 peripheral reset register */
  #define RCC_APB3RSTR_RFRST      0x00000001	/* RF reset */
#define TOFF_RCC_AHB1ENR    0x0048		/* (RW) RCC AHB1 peripheral clocks enable register */
  #define RCC_AHB1ENR_DMA1EN    0x00000001	/* DMA1 clock clock enable */
  #define RCC_AHB1ENR_DMA2EN    0x00000002	/* DMA2 clock enable */
  #define RCC_AHB1ENR_DMAMUX1EN 0x00000004	/* DMAMUX clock enable */
  #define RCC_AHB1ENR_CRCEN     0x00001000	/* CRC clock enable */
  #define RCC_AHB1ENR_TSCEN     0x00010000	/* TSC clock enable */
#define TOFF_RCC_AHB2ENR    0x004C		/* (RW) RCC AHB2 peripheral clocks clock enable register */
  #define RCC_AHB2ENR_GPIOAEN   0x00000001	/* GPIOA clock enable */
  #define RCC_AHB2ENR_GPIOBEN   0x00000002	/* GPIOB clock enable */
  #define RCC_AHB2ENR_GPIOCEN   0x00000004	/* GPIOC clock enable */
  #define RCC_AHB2ENR_GPIODEN   0x00000008	/* GPIOD clock enable */
  #define RCC_AHB2ENR_GPIOEEN   0x00000010	/* GPIOE clock enable */
  #define RCC_AHB2ENR_GPIOHEN   0x00000080	/* GPIOH clock enable */
  #define RCC_AHB2ENR_ADCEN     0x00002000	/* ADC clock enable */
  #define RCC_AHB2ENR_AES1EN    0x00010000	/* AES1 clock enable */
#define TOFF_RCC_AHB3ENR    0x0050		/* (RW) RCC AHB3 peripheral clocks clock enable register */
  #define RCC_AHB3ENR_QUADSPIEN 0x00000100	/* QUADSPI clock enable */
  #define RCC_AHB3ENR_PKAEN     0x00010000	/* PKA clock enable */
  #define RCC_AHB3ENR_AES2EN    0x00020000	/* AES2 clock enable */
  #define RCC_AHB3ENR_RNGEN     0x00040000	/* RNG clock enable */
  #define RCC_AHB3ENR_HSEMEN    0x00080000	/* HSEM clock enable */
  #define RCC_AHB3ENR_IPCCEN    0x00100000	/* IPCC clock enable */
  #define RCC_AHB3ENR_FLASHEN   0x02000000	/* FLASH clock enable */
#define TOFF_RCC_APB1ENR1   0x0058		/* (RW) RCC APB1 peripheral clocks clock enable register 1 */
  #define RCC_APB1ENR1_TIM2EN   0x00000001	/* TIMER2 clock enable */
  #define RCC_APB1ENR1_LCDEN    0x00000200	/* LCD clock enable */
  #define RCC_APB1ENR1_RTCAPBEN 0x00000400	/* RTCAPB clock enable */
  #define RCC_APB1ENR1_WWDGEN   0x00000800	/* WWDG clock enable */
  #define RCC_APB1ENR1_SPI2EN   0x00004000	/* SPI2 clock enable */
  #define RCC_APB1ENR1_I2C1EN   0x00200000	/* I2C1 clock enable */
  #define RCC_APB1ENR1_I2C3EN   0x00800000	/* I2C3 clock enable */
  #define RCC_APB1ENR1_CRSEN    0x01000000	/* CRS clock enable */
  #define RCC_APB1ENR1_USBEN    0x04000000	/* USB clock enable */
  #define RCC_APB1ENR1_LPTIM1EN 0x80000000	/* LPTIMER1 clock enable */
#define TOFF_RCC_APB1ENR2   0x005C		/* (RW) RCC APB1 peripheral clocks enable register 2 */
  #define RCC_APB1ENR2_LPUART1EN 0x00000001	/* LPUART1 clock enable */
  #define RCC_APB1ENR2_LPTIM2EN 0x00000020	/* LPTIMER2 clock enable */
#define TOFF_RCC_APB2ENR    0x0060		/* (RW) RCC APB2 peripheral clocks enable register */
  #define RCC_APB2ENR_TIM1EN    0x00000800	/* TIMER1 clock enable */
  #define RCC_APB2ENR_SPI1EN    0x00001000	/* SPI1 clock enable */
  #define RCC_APB2ENR_USART1EN  0x00004000	/* USART1 clock enable */
  #define RCC_APB2ENR_TIM16EN   0x00020000	/* TIMER16 clock enable */
  #define RCC_APB2ENR_TIM17EN   0x00040000	/* TIMER17 clock enable */
  #define RCC_APB2ENR_SAI1EN    0x00200000	/* SAI1 clock enable */
#define TOFF_RCC_AHB1SMENR  0x0068		/* (RW) RCC AHB1 peripheral clocks enable in sleep and stop modes register */
  #define RCC_AHB1SMENR_DMA1SMEN  0x00000001	/* DMA1 clock enabled in sleep mode */
  #define RCC_AHB1SMENR_DMA2SMEN  0x00000002	/* DMA2 clock enabled in sleep mode */
  #define RCC_AHB1SMENR_DMAMUX1SMEN  0x00000004	/* DMAMUX1S clock enabled in sleep mode */
  #define RCC_AHB1SMENR_SRAM1SMEN 0x00000200	/* SRAM1 clock enabled in sleep mode */
  #define RCC_AHB1SMENR_CRCSMEN   0x00001000	/* CRC clock enabled in sleep mode */
  #define RCC_AHB1SMENR_TSCSMEN   0x00010000	/* TSC clock enabled in sleep mode */
#define TOFF_RCC_AHB2SMENR  0x006C		/* (RW) RCC AHB2 peripheral clocks enable in sleep and stop modes register */
  #define RCC_AHB2SMENR_GPIOASMEN 0x00000001	/* GPIOA clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOBSMEN 0x00000002	/* GPIOB clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOCSMEN 0x00000004	/* GPIOC clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIODSMEN 0x00000008	/* GPIOD clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOESMEN 0x00000010	/* GPIOE clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOHSMEN 0x00000080	/* GPIOH clock enabled in sleep mode */
  #define RCC_AHB2SMENR_SRAM2SMEN 0x00000200	/* SRAM2 clock enabled in sleep mode */
  #define RCC_AHB2SMENR_ADCSMEN   0x00002000	/* ADCS clock enabled in sleep mode */
  #define RCC_AHB2SMENR_AES1SMEN  0x00010000	/* AES1 clock enabled in sleep mode */
#define TOFF_RCC_AHB3SMENR  0x0070		/* (RW) RCC AHB3 peripheral clocks enable in sleep and stop modes register */
  #define RCC_AHB3SMENR_QUADSPISMEN 0x00000100	/* QUADSPI clock enabled in sleep mode */
  #define RCC_AHB3SMENR_PKASMEN   0x00010000	/* PKA clock enabled in sleep mode */
  #define RCC_AHB3SMENR_AES2SMEN  0x00020000	/* AES2 clock enabled in sleep mode */
  #define RCC_AHB3SMENR_RNGSMEN   0x00040000	/* RNG clock enabled in sleep mode */
  #define RCC_AHB3SMENR_SRAM2SMEN 0x01000000	/* SRAM2S clock enabled in sleep mode */
  #define RCC_AHB3SMENR_FLASHSMEN 0x02000000	/* FLASH clock enabled in sleep mode */
#define TOFF_RCC_APB1SMENR1 0x0078		/* (RW) RCC APB1 peripheral clocks enable in sleep mode and stop modes register 1 */
  #define RCC_APB1SMENR1_TIM2SMEN 0x00000001	/* TIM2 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_LCDSMEN  0x00000200	/* LCD clock enabled in sleep mode */
  #define RCC_APB1SMENR1_RTCAPBSMEN 0x00000400	/* RTCAPB clock enabled in sleep mode */
  #define RCC_APB1SMENR1_WWDGSMEN 0x00000800	/* WWDG clock enabled in sleep mode */
  #define RCC_APB1SMENR1_SPI2SMEN 0x00004000	/* SPI2 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_I2C1SMEN 0x00200000	/* I2C1 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_I2C3SMEN 0x00800000	/* I2C3 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_CRSSMEN  0x01000000	/* CRS clock enabled in sleep mode */
  #define RCC_APB1SMENR1_USBSMEN  0x04000000	/* USB clock enabled in sleep mode */
  #define RCC_APB1SMENR1_LPTIM1SMEN 0x80000000	/* LPTIM1 clock enabled in sleep mode */
#define TOFF_RCC_APB1SMENR2 0x007C		/* (RW) RCC APB1 peripheral clocks enable in sleep mode and stop modes register 2 */
  #define RCC_APB1SMENR2_LPUART1SMEN 0x00000001	/* LPUART1 clock enabled in sleep mode */
  #define RCC_APB1SMENR2_LPTIM2SMEN 0x00000020	/* LPTIM2 clock enabled in sleep mode */
#define TOFF_RCC_APB2SMENR  0x0080		/* (RW) RCC APB2 peripheral clocks enable in sleep mode and stop modes register */
  #define RCC_APB2SMENR_TIM1SMEN    0x00000800	/* TIM1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_SPI1SMEN    0x00001000	/* SPI1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_USART1SMEN  0x00004000	/* USART1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM16SMEN   0x00020000	/* TIM16 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM17SMEN   0x00040000	/* TIM17 clock enabled in sleep mode */
  #define RCC_APB2SMENR_SAI1SMEN    0x00200000	/* SAI1 clock enabled in sleep mode */
#define TOFF_RCC_CCIPR      0x0088		/* (RW) RCC peripherals independent clock configuration register */
  #define RCC_CCIPR_USART1SEL   0x00000003	/* USART1SEL[1:0] bits */
  #define RCC_CCIPR_USART1SEL_0 0x00000001
  #define RCC_CCIPR_USART1SEL_1 0x00000002
  #define RCC_CCIPR_LPUART1SEL  0x00000C00	/* LPUART1SEL[1:0] bits */
  #define RCC_CCIPR_LPUART1SEL_0 0x00000400
  #define RCC_CCIPR_LPUART1SEL_1 0x00000800
  #define RCC_CCIPR_I2C1SEL     0x00003000	/* I2C1SEL[1:0] bits */
  #define RCC_CCIPR_I2C1SEL_0   0x00001000
  #define RCC_CCIPR_I2C1SEL_1   0x00002000
  #define RCC_CCIPR_I2C3SEL     0x00030000	/* I2C3SEL[1:0] bits */
  #define RCC_CCIPR_I2C3SEL_0   0x00010000
  #define RCC_CCIPR_I2C3SEL_1   0x00020000
  #define RCC_CCIPR_LPTIM1SEL   0x000C0000	/* LPTIM1SEL[1:0] bits */
  #define RCC_CCIPR_LPTIM1SEL_0 0x00040000
  #define RCC_CCIPR_LPTIM1SEL_1 0x00080000
  #define RCC_CCIPR_LPTIM2SEL   0x00300000	/* LPTIM2SEL[1:0] bits */
  #define RCC_CCIPR_LPTIM2SEL_0 0x00100000
  #define RCC_CCIPR_LPTIM2SEL_1 0x00200000
  #define RCC_CCIPR_SAI1SEL     0x00C00000	/* SAI1SEL[1:0] bits */
  #define RCC_CCIPR_SAI1SEL_0   0x00400000
  #define RCC_CCIPR_SAI1SEL_1   0x00800000
  #define RCC_CCIPR_CLK48SEL    0x0C000000	/* CLK48SEL[1:0] bits */
  #define RCC_CCIPR_CLK48SEL_0  0x04000000
  #define RCC_CCIPR_CLK48SEL_1  0x08000000
  #define RCC_CCIPR_ADCSEL      0x30000000	/* ADCSEL[1:0] bits */
  #define RCC_CCIPR_ADCSEL_0    0x10000000
  #define RCC_CCIPR_ADCSEL_1    0x20000000
  #define RCC_CCIPR_RNGSEL      0xC0000000	/* RNG[1:0] bits */
  #define RCC_CCIPR_RNGSEL_0    0x40000000
  #define RCC_CCIPR_RNGSEL_1    0x80000000
#define TOFF_RCC_BDCR       0x0090		/* (RW) RCC backup domain control register */
  #define RCC_BDCR_LSEON        0x00000001
  #define RCC_BDCR_LSERDY       0x00000002
  #define RCC_BDCR_LSEBYP       0x00000004
  #define RCC_BDCR_LSEDRV       0x00000018
  #define RCC_BDCR_LSEDRV_0     0x00000008
  #define RCC_BDCR_LSEDRV_1     0x00000010
  #define RCC_BDCR_LSECSSON     0x00000020
  #define RCC_BDCR_LSECSSD      0x00000040
  #define RCC_BDCR_RTCSEL       0x00000300
  #define RCC_BDCR_RTCSEL_0     0x00000100
  #define RCC_BDCR_RTCSEL_1     0x00000200
  #define RCC_BDCR_RTCEN        0x00008000
  #define RCC_BDCR_BDRST        0x00010000
  #define RCC_BDCR_LSCOEN       0x01000000
  #define RCC_BDCR_LSCOSEL      0x02000000
#define TOFF_RCC_CSR        0x0094		/* (RW) RCC clock control & status register */
  #define RCC_CSR_LSION         0x00000001	/* Internal Low Speed oscillator enable */
  #define RCC_CSR_LSI1ON        RCC_CSR_LSION
  #define RCC_CSR_LSIRDY        0x00000002	/* Internal Low Speed oscillator Ready */
  #define RCC_CSR_LSI1RDY       RCC_CSR_LSIRDY
  #define RCC_CSR_LSI2ON        0x00000004	/* Internal Low Speed oscillator2 enable */
  #define RCC_CSR_LSI2RDY       0x00000008	/* Internal Low Speed oscillator2 Ready */
  #define RCC_CSR_LSI2TRIM      0x00000F00
  #define RCC_CSR_LSI2TRIM_0    0x00000100
  #define RCC_CSR_LSI2TRIM_1    0x00000200
  #define RCC_CSR_LSI2TRIM_2    0x00000400
  #define RCC_CSR_LSI2TRIM_3    0x00000800
  #define RCC_CSR_RFWKPSEL      0x0000C000
  #define RCC_CSR_RFWKPSEL_0    0x00004000
  #define RCC_CSR_RFWKPSEL_1    0x00008000
  #define RCC_CSR_RFRSTS        0x00010000
  #define RCC_CSR_RMVF          0x00800000	/* Remove reset flag */
  #define RCC_CSR_OBLRSTF       0x02000000	/* OBL reset flag */
  #define RCC_CSR_PINRSTF       0x04000000	/* PIN reset flag */
  #define RCC_CSR_BORRSTF       0x08000000
  #define RCC_CSR_SFTRSTF       0x10000000	/* Software Reset flag */
  #define RCC_CSR_IWDGRSTF      0x20000000	/* Independent Watchdog reset flag */
  #define RCC_CSR_WWDGRSTF      0x40000000	/* Window watchdog reset flag */
  #define RCC_CSR_LPWRRSTF      0x80000000	/* Low-Power reset flag */
#define TOFF_RCC_CRRCR      0x0098		/* (RW) RCC clock recovery RC register */
  #define RCC_CRRCR_HSI48ON     0x00000001
  #define RCC_CRRCR_HSI48RDY    0x00000002
  #define RCC_CRRCR_HSI48CAL    0x0000FF80
  #define RCC_CRRCR_HSI48CAL_0  0x00000080
  #define RCC_CRRCR_HSI48CAL_1  0x00000100
  #define RCC_CRRCR_HSI48CAL_2  0x00000200
  #define RCC_CRRCR_HSI48CAL_3  0x00000400
  #define RCC_CRRCR_HSI48CAL_4  0x00000800
  #define RCC_CRRCR_HSI48CAL_5  0x00001000
  #define RCC_CRRCR_HSI48CAL_6  0x00002000
  #define RCC_CRRCR_HSI48CAL_7  0x00004000
  #define RCC_CRRCR_HSI48CAL_8  0x00008000
#define TOFF_RCC_HSECR      0x009C		/* (RW) RCC HSE Clock Register */
  #define RCC_HSECR_UNLOCKED    0x00000001
  #define RCC_HSECR_HSES        0x00000008
  #define RCC_HSECR_HSEGMC      0x00000070
  #define RCC_HSECR_HSEGMC0     0x00000010
  #define RCC_HSECR_HSEGMC1     0x00000020
  #define RCC_HSECR_HSEGMC2     0x00000040
  #define RCC_HSECR_HSETUNE     0x00003F00
  #define RCC_HSECR_HSETUNE0    0x00000100
  #define RCC_HSECR_HSETUNE1    0x00000200
  #define RCC_HSECR_HSETUNE2    0x00000400
  #define RCC_HSECR_HSETUNE3    0x00000800
  #define RCC_HSECR_HSETUNE4    0x00001000
  #define RCC_HSECR_HSETUNE5    0x00002000
#define TOFF_RCC_EXTCFGR    0x0108		/* (RW) RCC Extended Clock Recovery Register */
  #define RCC_EXTCFGR_SHDHPRE   0x0000000F
  #define RCC_EXTCFGR_SHDHPRE_0 0x00000001
  #define RCC_EXTCFGR_SHDHPRE_1 0x00000002
  #define RCC_EXTCFGR_SHDHPRE_2 0x00000004
  #define RCC_EXTCFGR_SHDHPRE_3 0x00000008
  #define RCC_EXTCFGR_C2HPRE    0x000000F0
  #define RCC_EXTCFGR_C2HPRE_0  0x00000010
  #define RCC_EXTCFGR_C2HPRE_1  0x00000020
  #define RCC_EXTCFGR_C2HPRE_2  0x00000040
  #define RCC_EXTCFGR_C2HPRE_3  0x00000080
  #define RCC_EXTCFGR_SHDHPREF  0x00010000
  #define RCC_EXTCFGR_C2HPREF   0x00020000
  #define RCC_EXTCFGR_RFCSS     0x00100000
#define TOFF_RCC_C2AHB1ENR  0x0148		/* (RW) RRCC AHB1 peripheral CPU2 clocks enable register */
  #define RCC_C2AHB1ENR_DMA1EN          RCC_AHB1ENR_DMA1EN
  #define RCC_C2AHB1ENR_DMA2EN          RCC_AHB1ENR_DMA2EN
  #define RCC_C2AHB1ENR_DMAMUX1EN       RCC_AHB1ENR_DMAMUX1EN
  #define RCC_C2AHB1ENR_SRAM1EN         0x00000200
  #define RCC_C2AHB1ENR_CRCEN           RCC_AHB1ENR_CRCEN
  #define RCC_C2AHB1ENR_TSCEN           RCC_AHB1ENR_TSCEN
#define TOFF_RCC_C2AHB2ENR  0x014C		/* (RW) RCC AHB2 peripheral CPU2 clocks enable register */
  #define RCC_C2AHB2ENR_GPIOAEN         RCC_AHB2ENR_GPIOAEN
  #define RCC_C2AHB2ENR_GPIOBEN         RCC_AHB2ENR_GPIOBEN
  #define RCC_C2AHB2ENR_GPIOCEN         RCC_AHB2ENR_GPIOCEN
  #define RCC_C2AHB2ENR_GPIODEN         RCC_AHB2ENR_GPIODEN
  #define RCC_C2AHB2ENR_GPIOEEN         RCC_AHB2ENR_GPIOEEN
  #define RCC_C2AHB2ENR_GPIOHEN         RCC_AHB2ENR_GPIOHEN
  #define RCC_C2AHB2ENR_ADCEN           RCC_AHB2ENR_ADCEN
  #define RCC_C2AHB2ENR_AES1EN          RCC_AHB2ENR_AES1EN
#define TOFF_RCC_C2AHB3ENR  0x0150		/* (RW) RCC AHB3 & AHB4 peripheral CPU2 clocks enable register */
  #define RCC_C2AHB3ENR_PKAEN           RCC_AHB3ENR_PKAEN
  #define RCC_C2AHB3ENR_AES2EN          RCC_AHB3ENR_AES2EN
  #define RCC_C2AHB3ENR_RNGEN           RCC_AHB3ENR_RNGEN
  #define RCC_C2AHB3ENR_HSEMEN          RCC_AHB3ENR_HSEMEN
  #define RCC_C2AHB3ENR_IPCCEN          RCC_AHB3ENR_IPCCEN
  #define RCC_C2AHB3ENR_FLASHEN         RCC_AHB3ENR_FLASHEN
#define TOFF_RCC_C2APB1ENR1 0x0158		/* (RW) RCC APB1 peripheral CPU2 clocks enable register 1 */
  #define RCC_C2APB1ENR1_TIM2EN         RCC_APB1ENR1_TIM2EN
  #define RCC_C2APB1ENR1_LCDEN          RCC_APB1ENR1_LCDEN
  #define RCC_C2APB1ENR1_RTCAPBEN       RCC_APB1ENR1_RTCAPBEN
  #define RCC_C2APB1ENR1_SPI2EN         RCC_APB1ENR1_SPI2EN
  #define RCC_C2APB1ENR1_I2C1EN         RCC_APB1ENR1_I2C1EN
  #define RCC_C2APB1ENR1_I2C3EN         RCC_APB1ENR1_I2C3EN
  #define RCC_C2APB1ENR1_CRSEN          RCC_APB1ENR1_CRSEN
  #define RCC_C2APB1ENR1_USBEN          RCC_APB1ENR1_USBEN
  #define RCC_C2APB1ENR1_LPTIM1EN       RCC_APB1ENR1_LPTIM1EN
#define TOFF_RCC_C2APB1ENR2 0x015C		/* (RW) RCC APB1 peripheral CPU2 clocks enable register 2 */
  #define RCC_C2APB1ENR2_LPUART1EN      RCC_APB1ENR2_LPUART1EN
  #define RCC_C2APB1ENR2_LPTIM2EN       RCC_APB1ENR2_LPTIM2EN
#define TOFF_RCC_C2APB2ENR  0x0160		/* (RW) RCC APB2 peripheral CPU2 clocks enable register 1 */
  #define RCC_C2APB2ENR_TIM1EN          RCC_APB2ENR_TIM1EN
  #define RCC_C2APB2ENR_SPI1EN          RCC_APB2ENR_SPI1EN
  #define RCC_C2APB2ENR_USART1EN        RCC_APB2ENR_USART1EN
  #define RCC_C2APB2ENR_TIM16EN         RCC_APB2ENR_TIM16EN
  #define RCC_C2APB2ENR_TIM17EN         RCC_APB2ENR_TIM17EN
  #define RCC_C2APB2ENR_SAI1EN          RCC_APB2ENR_SAI1EN
#define TOFF_RCC_C2APB3ENR  0x0164		/* (RW) RCC APB3 peripheral CPU2 clocks enable register 1 */
  #define RCC_C2APB3ENR_BLEEN           0x00000001
  #define RCC_C2APB3ENR_802EN           0x00000002
#define TOFF_RCC_C2AHB1SMENR  0x0168	/* (RW) RCC AHB1 peripheral CPU2 clocks enable in sleep and stop modes register */
  #define RCC_C2AHB1SMENR_DMA1SMEN      RCC_AHB1SMENR_DMA1SMEN
  #define RCC_C2AHB1SMENR_DMA2SMEN      RCC_AHB1SMENR_DMA2SMEN
  #define RCC_C2AHB1SMENR_DMAMUX1SMEN   RCC_AHB1SMENR_DMAMUX1SMEN
  #define RCC_C2AHB1SMENR_SRAM1SMEN     RCC_AHB1SMENR_SRAM1SMEN
  #define RCC_C2AHB1SMENR_CRCSMEN       RCC_AHB1SMENR_CRCSMEN
  #define RCC_C2AHB1SMENR_TSCSMEN       RCC_AHB1SMENR_TSCSMEN
#define TOFF_RCC_C2AHB2SMENR  0x016C	/* (RW) RCC AHB2 peripheral CPU2 clocks enable in sleep and stop modes registe */
  #define RCC_C2AHB2SMENR_GPIOASMEN     RCC_AHB2SMENR_GPIOASMEN
  #define RCC_C2AHB2SMENR_GPIOBSMEN     RCC_AHB2SMENR_GPIOBSMEN
  #define RCC_C2AHB2SMENR_GPIOCSMEN     RCC_AHB2SMENR_GPIOCSMEN
  #define RCC_C2AHB2SMENR_GPIODSMEN     RCC_AHB2SMENR_GPIODSMEN
  #define RCC_C2AHB2SMENR_GPIOESMEN     RCC_AHB2SMENR_GPIOESMEN
  #define RCC_C2AHB2SMENR_GPIOHSMEN     RCC_AHB2SMENR_GPIOHSMEN
  #define RCC_C2AHB2SMENR_ADCSMEN       RCC_AHB2SMENR_ADCSMEN
  #define RCC_C2AHB2SMENR_AES1SMEN      RCC_AHB2SMENR_AES1SMEN
#define TOFF_RCC_C2AHB3SMENR  0x0170	/* (RW) RCC AHB3 & AHB4 peripheral CPU2 clocks enable in sleep and stop modes register */
  #define RCC_C2AHB3SMENR_PKASMEN       RCC_AHB3SMENR_PKASMEN
  #define RCC_C2AHB3SMENR_AES2SMEN      RCC_AHB3SMENR_AES2SMEN
  #define RCC_C2AHB3SMENR_RNGSMEN       RCC_AHB3SMENR_RNGSMEN
  #define RCC_C2AHB3SMENR_SRAM2SMEN     RCC_AHB3SMENR_SRAM2SMEN
  #define RCC_C2AHB3SMENR_FLASHSMEN     RCC_AHB3SMENR_FLASHSMEN
#define TOFF_RCC_C2APB1SMENR1 0x0178	/* (RW) RCC APB1 peripheral CPU2 clocks enable in sleep mode and stop modes register 1 */
  #define RCC_C2APB1SMENR1_TIM2SMEN     RCC_APB1SMENR1_TIM2SMEN
  #define RCC_C2APB1SMENR1_LCDSMEN      RCC_APB1SMENR1_LCDSMEN
  #define RCC_C2APB1SMENR1_RTCAPBSMEN   RCC_APB1SMENR1_RTCAPBSMEN
  #define RCC_C2APB1SMENR1_SPI2SMEN     RCC_APB1SMENR1_SPI2SMEN
  #define RCC_C2APB1SMENR1_I2C1SMEN     RCC_APB1SMENR1_I2C1SMEN
  #define RCC_C2APB1SMENR1_I2C3SMEN     RCC_APB1SMENR1_I2C3SMEN
  #define RCC_C2APB1SMENR1_CRSSMEN      RCC_APB1SMENR1_CRSSMEN
  #define RCC_C2APB1SMENR1_USBSMEN      RCC_APB1SMENR1_USBSMEN
  #define RCC_C2APB1SMENR1_LPTIM1SMEN   RCC_APB1SMENR1_LPTIM1SMEN
#define TOFF_RCC_C2APB1SMENR2 0x017C	/* (RW) RCC APB1 peripheral CPU2 clocks enable in sleep mode and stop modes register 2 */
  #define RCC_C2APB1SMENR2_LPUART1SMEN  RCC_APB1SMENR2_LPUART1SMEN
  #define RCC_C2APB1SMENR2_LPTIM2SMEN   RCC_APB1SMENR2_LPTIM2SMEN
#define TOFF_RCC_C2APB2SMENR  0x0180	/* (RW) RCC APB2 peripheral CPU2 clocks enable in sleep mode and stop modes register */
  #define RCC_C2APB2SMENR_TIM1SMEN      RCC_APB2SMENR_TIM1SMEN
  #define RCC_C2APB2SMENR_SPI1SMEN      RCC_APB2SMENR_SPI1SMEN
  #define RCC_C2APB2SMENR_USART1SMEN    RCC_APB2SMENR_USART1SMEN
  #define RCC_C2APB2SMENR_TIM16SMEN     RCC_APB2SMENR_TIM16SMEN
  #define RCC_C2APB2SMENR_TIM17SMEN     RCC_APB2SMENR_TIM17SMEN
  #define RCC_C2APB2SMENR_SAI1SMEN      RCC_APB2SMENR_SAI1SMEN
#define TOFF_RCC_C2APB3SMENR  0x0184	/* (RW) RCC APB3 peripheral CPU2 clocks enable in sleep mode and stop modes register */
  #define RCC_C2APB3SMENR_BLESMEN       0x00000001
  #define RCC_C2APB3SMENR_802SMEN       0x00000002


/*
 *  POWER CONTROL
 */
#define TADR_PWR_BASE       (AHB4PERIPH_BASE + 0x0400)

#define TOFF_PWR_CR1        0x0000	/* (RW) PWR power control register 1 */
  #define PWR_CR1_LPMS          0x00000007	/* Low-power mode selection field */
  #define PWR_CR1_LPMS_0        0x00000001
  #define PWR_CR1_LPMS_1        0x00000002
  #define PWR_CR1_LPMS_2        0x00000004
  #define PWR_CR1_FPDR          0x00000010	/* Flash power down mode during LPrun for CPU1 */
  #define PWR_CR1_FPDS          0x00000020	/* Flash power down mode during LPsleep for CPU1 */
  #define PWR_CR1_DBP           0x00000100	/* Disable Back-up domain Protection */
  #define PWR_CR1_VOS           0x00000600	/* VOS[1:0] bits (Regulator voltage scaling output selection) */
  #define PWR_CR1_VOS_0         0x00000200
  #define PWR_CR1_VOS_1         0x00000400
  #define PWR_CR1_LPR           0x00004000	/* Regulator low-power mode */
#define TOFF_PWR_CR2        0x0004	/* (RW) PWR power control register 2 */
  #define PWR_CR2_PVDE          0x00000001	/* Power Voltage Detector Enable */
  #define PWR_CR2_PLS           0x0000000E	/* PVD level selection */
  #define PWR_CR2_PLS_0         0x00000002
  #define PWR_CR2_PLS_1         0x00000004
  #define PWR_CR2_PLS_2         0x00000008
  #define PWR_CR2_PVME          0x00000050	/* PVM bits field */
  #define PWR_CR2_PVME3         0x00000040	/* PVM 3 Enable */
  #define PWR_CR2_PVME1         0x00000010	/* PVM 1 Enable */
  #define PWR_CR2_USV           0x00000400	/* VDD USB Supply Valid */
#define TOFF_PWR_CR3        0x0008	/* (RW) PWR power control register 3 */
  #define PWR_CR3_EWUP          0x0000001F	/* Enable Wake-Up Pins  */
  #define PWR_CR3_EWUP1         0x00000001	/* Enable Wake-Up Pin 1 */
  #define PWR_CR3_EWUP2         0x00000002	/* Enable Wake-Up Pin 2 */
  #define PWR_CR3_EWUP3         0x00000004	/* Enable Wake-Up Pin 3 */
  #define PWR_CR3_EWUP4         0x00000008	/* Enable Wake-Up Pin 4 */
  #define PWR_CR3_EWUP5         0x00000010	/* Enable Wake-Up Pin 5 */
  #define PWR_CR3_EBORHSMPSFB   0x00000100	/* BORH and SMPS Step Down converter forced in Bypass interrupts for CPU1 */
  #define PWR_CR3_RRS           0x00000200	/* SRAM2 retention in STANDBY mode */
  #define PWR_CR3_APC           0x00000400	/* Apply pull-up and pull-down configuration for CPU1 */
  #define PWR_CR3_ECRPE         0x00000800	/* Critical radio phase end of activity interrupt for CPU1 */
  #define PWR_CR3_EBLEA         0x00010000	/* BLE end of activity interrupt for CPU1 */
  #define PWR_CR3_E802A         0x00020000	/* 802.15.4 end of activity interrupt for CPU1 */
  #define PWR_CR3_EC2H          0x00040000	/* CPU2 Hold interrupt for CPU1 */
  #define PWR_CR3_EIWUL         0x00080000	/* Internal Wake-Up line interrupt for CPU1 */
#define TOFF_PWR_CR4        0x000C	/* (RW) PWR power control register 4 */
  #define PWR_CR4_WP1           0x00000001	/* Wake-Up Pin 1 polarity */
  #define PWR_CR4_WP2           0x00000002	/* Wake-Up Pin 2 polarity */
  #define PWR_CR4_WP3           0x00000004	/* Wake-Up Pin 3 polarity */
  #define PWR_CR4_WP4           0x00000008	/* Wake-Up Pin 4 polarity */
  #define PWR_CR4_WP5           0x00000010	/* Wake-Up Pin 5 polarity */
  #define PWR_CR4_VBE           0x00000100	/* VBAT Battery charging Enable  */
  #define PWR_CR4_VBRS          0x00000200	/* VBAT Battery charging Resistor Selection */
  #define PWR_CR4_C2BOOT        0x00008000	/* Boot CPU2 after reset or wakeup from Stop or Standby modes */
#define TOFF_PWR_SR1        0x0010	/* (RW) PWR power status register 1 */
  #define PWR_SR1_WUF           0x0000001F	/* Wake-up Flags */
  #define PWR_SR1_WUF1          0x00000001	/* Wake-up Flag 1 */
  #define PWR_SR1_WUF2          0x00000002	/* Wake-up Flag 2 */
  #define PWR_SR1_WUF3          0x00000004	/* Wake-up Flag 3 */
  #define PWR_SR1_WUF4          0x00000008	/* Wake-up Flag 4 */
  #define PWR_SR1_WUF5          0x00000010	/* Wake-up Flag 5 */
  #define PWR_SR1_SMPSFBF       0x00000080	/* SMPS Step Down converter forced in bypass mode interrupt flag */
  #define PWR_SR1_BORHF         0x00000100	/* BORH interrupt flag */
  #define PWR_SR1_BLEWUF        0x00000200	/* BLE wakeup interrupt flag */
  #define PWR_SR1_802WUF        0x00000400	/* 802.15.4 wakeup interrupt flag */
  #define PWR_SR1_CRPEF         0x00000800	/* Critical radio phase end of activity interrupt flag */
  #define PWR_SR1_BLEAF         0x00001000	/* BLE end of activity interrupt flag */
  #define PWR_SR1_802AF         0x00002000	/* 802.15.4 end of activity interrupt flag */
  #define PWR_SR1_C2HF          0x00004000	/* CPU2 Hold interrupt flag */
  #define PWR_SR1_WUFI          0x00008000	/* Internal wakeup interrupt flag */
#define TOFF_PWR_SR2        0x0014	/* (RW) PWR power status register 2 */
  #define PWR_SR2_SMPSBF        0x00000001	/* SMPS step down converter in operating mode bypass flag */
  #define PWR_SR2_SMPSF         0x00000002	/* SMPS step down converter in operating mode step down flag */
  #define PWR_SR2_REGLPS        0x00000100	/* Low-power Regulator Started */
  #define PWR_SR2_REGLPF        0x00000200	/* Low-power Regulator Flag */
  #define PWR_SR2_VOSF          0x00000400	/* Voltage Scaling Flag */
  #define PWR_SR2_PVDO          0x00000800	/* Power Voltage Detector Output */
  #define PWR_SR2_PVMO          0x00005000	/* Peripheral voltage monitor output for all power domains */
  #define PWR_SR2_PVMO1         0x00001000	/* Peripheral Voltage Monitoring Output 1 */
  #define PWR_SR2_PVMO3         0x00004000	/* Peripheral Voltage Monitoring Output 3 */
#define TOFF_PWR_SCR        0x0018	/* (RW) PWR power status reset register */
  #define PWR_SCR_CWUF          0x0000001F	/* Clear Wake-up Flags  */
  #define PWR_SCR_CWUF1         0x00000001	/* Clear Wake-up Flag 1 */
  #define PWR_SCR_CWUF2         0x00000002	/* Clear Wake-up Flag 2 */
  #define PWR_SCR_CWUF3         0x00000004	/* Clear Wake-up Flag 3 */
  #define PWR_SCR_CWUF4         0x00000008	/* Clear Wake-up Flag 4 */
  #define PWR_SCR_CWUF5         0x00000010	/* Clear Wake-up Flag 5 */
  #define PWR_SCR_CSMPSFBF      0x00000080	/* Clear SMPS Step Down converter forced in bypass mode interrupt flag  */
  #define PWR_SCR_CBORHF        0x00000100	/* Clear BORH interrupt flag  */
  #define PWR_SCR_CBLEWUF       0x00000200	/* Clear BLE wakeup interrupt flag */
  #define PWR_SCR_C802WUF       0x00000400	/* Clear 802.15.4 wakeup interrupt flag */
  #define PWR_SCR_CCRPEF        0x00000800	/* Clear Critical radio phase end of activity interrupt flag */
  #define PWR_SCR_CBLEAF        0x00001000	/* Clear BLE end of activity interrupt flag */
  #define PWR_SCR_C802AF        0x00002000	/* Clear 802.15.4 end of activity interrupt flag */
  #define PWR_SCR_CC2HF         0x00004000	/* Clear CPU2 Hold interrupt flag */
#define TOFF_PWR_CR5        0x001C	/* (RW) PWR power control register 5 */
  #define PWR_CR5_SMPSVOS       0x0000000F	/* SMPS step down converter voltage output scaling voltage level */
  #define PWR_CR5_SMPSVOS_0     0x00000001
  #define PWR_CR5_SMPSVOS_1     0x00000002
  #define PWR_CR5_SMPSVOS_2     0x00000004
  #define PWR_CR5_SMPSVOS_3     0x00000008
  #define PWR_CR5_SMPSSC        0x00000070	/* SMPS step down converter supply startup current selection */
  #define PWR_CR5_SMPSSC_0      0x00000010
  #define PWR_CR5_SMPSSC_1      0x00000020
  #define PWR_CR5_SMPSSC_2      0x00000040
  #define PWR_CR5_BORHC         0x00000100	/* BORH configuration selection */
  #define PWR_CR5_SMPSEN        0x00008000	/* Enable SMPS Step Down converter SMPS mode enable */
#define TOFF_PWR_PUCRA      0x0020	/* (RW) Pull_up control register of portA */
#define TOFF_PWR_PDCRA      0x0024	/* (RW) Pull_Down control register of portA */
#define TOFF_PWR_PUCRB      0x0028	/* (RW) Pull_up control register of portB */
#define TOFF_PWR_PDCRB      0x002C	/* (RW) Pull_Down control register of portB */
#define TOFF_PWR_PUCRC      0x0030	/* (RW) Pull_up control register of portC */
#define TOFF_PWR_PDCRC      0x0034	/* (RW) Pull_Down control register of portC */
#define TOFF_PWR_PUCRD      0x0038	/* (RW) Pull_up control register of portD */
#define TOFF_PWR_PDCRD      0x003C	/* (RW) Pull_Down control register of portD */
#define TOFF_PWR_PUCRE      0x0040	/* (RW) Pull_up control register of portE */
#define TOFF_PWR_PDCRE      0x0044	/* (RW) Pull_Down control register of portE */
#define TOFF_PWR_PUCRH      0x0058	/* (RW) Pull_up control register of portH */
#define TOFF_PWR_PDCRH      0x005C	/* (RW) Pull_Down control register of portH */
#define TOFF_PWR_C2CR1      0x0080	/* (RW) PWR Power Control Register 1 for CPU2 */
  #define PWR_C2CR1_LPMS        0x00000007	/* Low Power Mode Selection for CPU2 */
  #define PWR_C2CR1_LPMS_0      0x00000001
  #define PWR_C2CR1_LPMS_1      0x00000002
  #define PWR_C2CR1_LPMS_2      0x00000004
  #define PWR_C2CR1_FPDR        0x00000010	/* Flash power down mode during LPrun for CPU2 */
  #define PWR_C2CR1_FPDS        0x00000020	/* Flash power down mode during LPsleep for CPU2 */
  #define PWR_C2CR1_BLEEWKUP    0x00004000	/* Radio BLE external wakeup signal */
  #define PWR_C2CR1_802EWKUP    0x00008000	/* Radio 802.15.4 external wakeup signal */
#define TOFF_PWR_C2CR3      0x0084	/* (RW) PWR Power Control Register 3 for CPU2 */
  #define PWR_C2CR3_EWUP        0x0000001F	/* Enable all external Wake-Up lines for CPU2 */
  #define PWR_C2CR3_EWUP1       0x00000001	/* Enable external WKUP Pin 1 [line 0] for CPU2 */
  #define PWR_C2CR3_EWUP2       0x00000002	/* Enable external WKUP Pin 2 [line 1] for CPU2 */
  #define PWR_C2CR3_EWUP3       0x00000004	/* Enable external WKUP Pin 3 [line 2] for CPU2 */
  #define PWR_C2CR3_EWUP4       0x00000008	/* Enable external WKUP Pin 4 [line 3] for CPU2 */
  #define PWR_C2CR3_EWUP5       0x00000010	/* Enable external WKUP Pin 5 [line 4] for CPU2 */
  #define PWR_C2CR3_EBLEWUP     0x00000200	/* Enable BLE host wakeup interrupt for CPU2 */
  #define PWR_C2CR3_E802WUP     0x00000400	/* Enable BLE host wakeup interrupt for CPU2 */
  #define PWR_C2CR3_APC         0x00001000	/* Apply pull-up and pull-down configuration for CPU2 */
  #define PWR_C2CR3_EIWUL       0x00008000	/* Internal Wake-Up line interrupt for CPU2 */
#define TOFF_PWR_EXTSCR     0x0088	/* (RW) PWR Power Status Reset Register for CPU2 */
  #define PWR_EXTSCR_C1CSSF     0x00000001	/* Clear standby and stop flags for CPU1 */
  #define PWR_EXTSCR_C2CSSF     0x00000002	/* Clear standby and stop flags for CPU2 */
  #define PWR_EXTSCR_CCRPF      0x00000004	/* Clear critical radio system phase flag */
  #define PWR_EXTSCR_C1SBF      0x00000100	/* System standby flag for CPU1 */
  #define PWR_EXTSCR_C1STOPF    0x00000200	/* System stop flag for CPU1 */
  #define PWR_EXTSCR_C2SBF      0x00000400	/* System standby flag for CPU2 */
  #define PWR_EXTSCR_C2STOPF    0x00000800	/* System stop flag for CPU2 */
  #define PWR_EXTSCR_CRPF       0x00002000	/* Critical radio system phase flag */
  #define PWR_EXTSCR_C1DS       0x00004000	/* CPU1 deepsleep mode flag */
  #define PWR_EXTSCR_C2DS       0x00008000	/* CPU2 deepsleep mode flag */


/*
 *  EXTERNAL INTERRUPT/EVENT CONTROLLER
 */
#define TADR_EXTI_BASE      (AHB4PERIPH_BASE + 0x0800)
#define TOFF_EXTI_RTSR1     0x0000	/* (RW) EXTI rising trigger selection register [31:0] */
  #define EXTI_RTSR1_RT      0x803FFFFF	/* Rising trigger event configuration bit */
  #define EXTI_RTSR1_RT0     0x00000001	/* Rising trigger event configuration bit of line 0 */
  #define EXTI_RTSR1_RT1     0x00000002	/* Rising trigger event configuration bit of line 1 */
  #define EXTI_RTSR1_RT2     0x00000004	/* Rising trigger event configuration bit of line 2 */
  #define EXTI_RTSR1_RT3     0x00000008	/* Rising trigger event configuration bit of line 3 */
  #define EXTI_RTSR1_RT4     0x00000010	/* Rising trigger event configuration bit of line 4 */
  #define EXTI_RTSR1_RT5     0x00000020	/* Rising trigger event configuration bit of line 5 */
  #define EXTI_RTSR1_RT6     0x00000040	/* Rising trigger event configuration bit of line 6 */
  #define EXTI_RTSR1_RT7     0x00000080	/* Rising trigger event configuration bit of line 7 */
  #define EXTI_RTSR1_RT8     0x00000100	/* Rising trigger event configuration bit of line 8 */
  #define EXTI_RTSR1_RT9     0x00000200	/* Rising trigger event configuration bit of line 9 */
  #define EXTI_RTSR1_RT10    0x00000400	/* Rising trigger event configuration bit of line 10 */
  #define EXTI_RTSR1_RT11    0x00000800	/* Rising trigger event configuration bit of line 11 */
  #define EXTI_RTSR1_RT12    0x00001000	/* Rising trigger event configuration bit of line 12 */
  #define EXTI_RTSR1_RT13    0x00002000	/* Rising trigger event configuration bit of line 13 */
  #define EXTI_RTSR1_RT14    0x00004000	/* Rising trigger event configuration bit of line 14 */
  #define EXTI_RTSR1_RT15    0x00008000	/* Rising trigger event configuration bit of line 15 */
  #define EXTI_RTSR1_RT16    0x00010000	/* Rising trigger event configuration bit of line 16 */
  #define EXTI_RTSR1_RT17    0x00020000	/* Rising trigger event configuration bit of line 17 */
  #define EXTI_RTSR1_RT18    0x00040000	/* Rising trigger event configuration bit of line 18 */
  #define EXTI_RTSR1_RT19    0x00080000	/* Rising trigger event configuration bit of line 19 */
  #define EXTI_RTSR1_RT20    0x00100000	/* Rising trigger event configuration bit of line 20 */
  #define EXTI_RTSR1_RT21    0x00200000	/* Rising trigger event configuration bit of line 21 */
  #define EXTI_RTSR1_RT31    0x80000000	/* Rising trigger event configuration bit of line 31 */
#define TOFF_EXTI_FTSR1     0x0004	/* (RW) EXTI falling trigger selection register [31:0] */
  #define EXTI_FTSR1_FT      0x803FFFFF	/* Falling trigger event configuration bit */
  #define EXTI_FTSR1_FT0     0x00000001	/* Falling trigger event configuration bit of line 0 */
  #define EXTI_FTSR1_FT1     0x00000002	/* Falling trigger event configuration bit of line 1 */
  #define EXTI_FTSR1_FT2     0x00000004	/* Falling trigger event configuration bit of line 2 */
  #define EXTI_FTSR1_FT3     0x00000008	/* Falling trigger event configuration bit of line 3 */
  #define EXTI_FTSR1_FT4     0x00000010	/* Falling trigger event configuration bit of line 4 */
  #define EXTI_FTSR1_FT5     0x00000020	/* Falling trigger event configuration bit of line 5 */
  #define EXTI_FTSR1_FT6     0x00000040	/* Falling trigger event configuration bit of line 6 */
  #define EXTI_FTSR1_FT7     0x00000080	/* Falling trigger event configuration bit of line 7 */
  #define EXTI_FTSR1_FT8     0x00000100	/* Falling trigger event configuration bit of line 8 */
  #define EXTI_FTSR1_FT9     0x00000200	/* Falling trigger event configuration bit of line 9 */
  #define EXTI_FTSR1_FT10    0x00000400	/* Falling trigger event configuration bit of line 10 */
  #define EXTI_FTSR1_FT11    0x00000800	/* Falling trigger event configuration bit of line 11 */
  #define EXTI_FTSR1_FT12    0x00001000	/* Falling trigger event configuration bit of line 12 */
  #define EXTI_FTSR1_FT13    0x00002000	/* Falling trigger event configuration bit of line 13 */
  #define EXTI_FTSR1_FT14    0x00004000	/* Falling trigger event configuration bit of line 14 */
  #define EXTI_FTSR1_FT15    0x00008000	/* Falling trigger event configuration bit of line 15 */
  #define EXTI_FTSR1_FT16    0x00010000	/* Falling trigger event configuration bit of line 16 */
  #define EXTI_FTSR1_FT17    0x00020000	/* Falling trigger event configuration bit of line 17 */
  #define EXTI_FTSR1_FT18    0x00040000	/* Falling trigger event configuration bit of line 18 */
  #define EXTI_FTSR1_FT19    0x00080000	/* Falling trigger event configuration bit of line 19 */
  #define EXTI_FTSR1_FT20    0x00100000	/* Falling trigger event configuration bit of line 20 */
  #define EXTI_FTSR1_FT21    0x00200000	/* Falling trigger event configuration bit of line 21 */
  #define EXTI_FTSR1_FT31    0x80000000	/* Falling trigger event configuration bit of line 31 */
#define TOFF_EXTI_SWIER1    0x0008	/* (RW) EXTI software interrupt event register [31:0] */
  #define EXTI_SWIER1_SWI    0x803FFFFF	/* Software interrupt */
  #define EXTI_SWIER1_SWI0   0x00000001	/* Software Interrupt on line 0 */
  #define EXTI_SWIER1_SWI1   0x00000002	/* Software Interrupt on line 1 */
  #define EXTI_SWIER1_SWI2   0x00000004	/* Software Interrupt on line 2 */
  #define EXTI_SWIER1_SWI3   0x00000008	/* Software Interrupt on line 3 */
  #define EXTI_SWIER1_SWI4   0x00000010	/* Software Interrupt on line 4 */
  #define EXTI_SWIER1_SWI5   0x00000020	/* Software Interrupt on line 5 */
  #define EXTI_SWIER1_SWI6   0x00000040	/* Software Interrupt on line 6 */
  #define EXTI_SWIER1_SWI7   0x00000080	/* Software Interrupt on line 7 */
  #define EXTI_SWIER1_SWI8   0x00000100	/* Software Interrupt on line 8 */
  #define EXTI_SWIER1_SWI9   0x00000200	/* Software Interrupt on line 9 */
  #define EXTI_SWIER1_SWI10  0x00000400	/* Software Interrupt on line 10 */
  #define EXTI_SWIER1_SWI11  0x00000800	/* Software Interrupt on line 11 */
  #define EXTI_SWIER1_SWI12  0x00001000	/* Software Interrupt on line 12 */
  #define EXTI_SWIER1_SWI13  0x00002000	/* Software Interrupt on line 13 */
  #define EXTI_SWIER1_SWI14  0x00004000	/* Software Interrupt on line 14 */
  #define EXTI_SWIER1_SWI15  0x00008000	/* Software Interrupt on line 15 */
  #define EXTI_SWIER1_SWI16  0x00010000	/* Software Interrupt on line 16 */
  #define EXTI_SWIER1_SWI17  0x00020000	/* Software Interrupt on line 17 */
  #define EXTI_SWIER1_SWI18  0x00040000	/* Software Interrupt on line 18 */
  #define EXTI_SWIER1_SWI19  0x00080000	/* Software Interrupt on line 19 */
  #define EXTI_SWIER1_SWI20  0x00100000	/* Software Interrupt on line 20 */
  #define EXTI_SWIER1_SWI21  0x00200000	/* Software Interrupt on line 21 */
  #define EXTI_SWIER1_SWI31  0x80000000	/* Software Interrupt on line 31 */
#define TOFF_EXTI_PR1       0x000C	/* (RW) EXTI pending register [31:0] */
  #define EXTI_PR1_PIF       0x803FFFFF	/* Pending bit */
  #define EXTI_PR1_PIF0      0x00000001	/* Pending bit for line 0 */
  #define EXTI_PR1_PIF1      0x00000002	/* Pending bit for line 1 */
  #define EXTI_PR1_PIF2      0x00000004	/* Pending bit for line 2 */
  #define EXTI_PR1_PIF3      0x00000008	/* Pending bit for line 3 */
  #define EXTI_PR1_PIF4      0x00000010	/* Pending bit for line 4 */
  #define EXTI_PR1_PIF5      0x00000020	/* Pending bit for line 5 */
  #define EXTI_PR1_PIF6      0x00000040	/* Pending bit for line 6 */
  #define EXTI_PR1_PIF7      0x00000080	/* Pending bit for line 7 */
  #define EXTI_PR1_PIF8      0x00000100	/* Pending bit for line 8 */
  #define EXTI_PR1_PIF9      0x00000200	/* Pending bit for line 9 */
  #define EXTI_PR1_PIF10     0x00000400	/* Pending bit for line 10 */
  #define EXTI_PR1_PIF11     0x00000800	/* Pending bit for line 11 */
  #define EXTI_PR1_PIF12     0x00001000	/* Pending bit for line 12 */
  #define EXTI_PR1_PIF13     0x00002000	/* Pending bit for line 13 */
  #define EXTI_PR1_PIF14     0x00004000	/* Pending bit for line 14 */
  #define EXTI_PR1_PIF15     0x00008000	/* Pending bit for line 15 */
  #define EXTI_PR1_PIF16     0x00010000	/* Pending bit for line 16 */
  #define EXTI_PR1_PIF17     0x00020000	/* Pending bit for line 17 */
  #define EXTI_PR1_PIF18     0x00040000	/* Pending bit for line 18 */
  #define EXTI_PR1_PIF19     0x00080000	/* Pending bit for line 19 */
  #define EXTI_PR1_PIF20     0x00100000	/* Pending bit for line 20 */
  #define EXTI_PR1_PIF21     0x00200000	/* Pending bit for line 21 */
  #define EXTI_PR1_PIF31     0x80000000	/* Pending bit for line 31 */
#define TOFF_EXTI_RTSR2     0x0020	/* (RW) EXTI rising trigger selection register [31:0] */
  #define EXTI_RTSR2_RT      0x00000302	/* Rising trigger event configuration bit */
  #define EXTI_RTSR2_RT33    0x00000002	/* Rising trigger event configuration bit of line 33 */
  #define EXTI_RTSR2_RT40    0x00000100	/* Rising trigger event configuration bit of line 40 */
  #define EXTI_RTSR2_RT41    0x00000200	/* Rising trigger event configuration bit of line 41 */
#define TOFF_EXTI_FTSR2     0x0024	/* (RW) EXTI falling trigger selection register [31:0] */
  #define EXTI_FTSR2_FT      0x00000302	/* Falling trigger event configuration bit */
  #define EXTI_FTSR2_FT33    0x00000002	/* Falling trigger event configuration bit of line 33 */
  #define EXTI_FTSR2_FT40    0x00000100	/* Falling trigger event configuration bit of line 40 */
  #define EXTI_FTSR2_FT41    0x00000200	/* Falling trigger event configuration bit of line 41 */
#define TOFF_EXTI_SWIER2    0x0028	/* (RW) EXTI software interrupt event register [31:0] */
  #define EXTI_SWIER2_SWI    0x00000302	/* Falling trigger event configuration bit */
  #define EXTI_SWIER2_SWI33  0x00000002	/* Software Interrupt on line 33 */
  #define EXTI_SWIER2_SWI40  0x00000100	/* Software Interrupt on line 40 */
  #define EXTI_SWIER2_SWI41  0x00000200	/* Software Interrupt on line 41 */
#define TOFF_EXTI_PR2       0x002C	/* (RW) EXTI pending register [31:0] 0x2C */
  #define EXTI_PR2_PIF       0x00000302	/* Pending bit */
  #define EXTI_PR2_PIF33     0x00000002	/* Pending bit for line 33 */
  #define EXTI_PR2_PIF40     0x00000100	/* Pending bit for line 40 */
  #define EXTI_PR2_PIF41     0x00000200	/* Pending bit for line 41 */
#define TOFF_EXTI_IMR1      0x0080	/* (RW) EXTI wakeup with interrupt mask register for cpu1 [31:0] */
  #define EXTI_IMR1_IM       0xFFFFFFFF	/* CPU1 wakeup with interrupt Mask on Event */
  #define EXTI_IMR1_IM0      0x00000001	/* CPU1 Interrupt Mask on line 0 */
  #define EXTI_IMR1_IM1      0x00000002	/* CPU1 Interrupt Mask on line 1 */
  #define EXTI_IMR1_IM2      0x00000004	/* CPU1 Interrupt Mask on line 2 */
  #define EXTI_IMR1_IM3      0x00000008	/* CPU1 Interrupt Mask on line 3 */
  #define EXTI_IMR1_IM4      0x00000010	/* CPU1 Interrupt Mask on line 4 */
  #define EXTI_IMR1_IM5      0x00000020	/* CPU1 Interrupt Mask on line 5 */
  #define EXTI_IMR1_IM6      0x00000040	/* CPU1 Interrupt Mask on line 6 */
  #define EXTI_IMR1_IM7      0x00000080	/* CPU1 Interrupt Mask on line 7 */
  #define EXTI_IMR1_IM8      0x00000100	/* CPU1 Interrupt Mask on line 8 */
  #define EXTI_IMR1_IM9      0x00000200	/* CPU1 Interrupt Mask on line 9 */
  #define EXTI_IMR1_IM10     0x00000400	/* CPU1 Interrupt Mask on line 10 */
  #define EXTI_IMR1_IM11     0x00000800	/* CPU1 Interrupt Mask on line 11 */
  #define EXTI_IMR1_IM12     0x00001000	/* CPU1 Interrupt Mask on line 12 */
  #define EXTI_IMR1_IM13     0x00002000	/* CPU1 Interrupt Mask on line 13 */
  #define EXTI_IMR1_IM14     0x00004000	/* CPU1 Interrupt Mask on line 14 */
  #define EXTI_IMR1_IM15     0x00008000	/* CPU1 Interrupt Mask on line 15 */
  #define EXTI_IMR1_IM16     0x00010000	/* CPU1 Interrupt Mask on line 16 */
  #define EXTI_IMR1_IM17     0x00020000	/* CPU1 Interrupt Mask on line 17 */
  #define EXTI_IMR1_IM18     0x00040000	/* CPU1 Interrupt Mask on line 18 */
  #define EXTI_IMR1_IM19     0x00080000	/* CPU1 Interrupt Mask on line 19 */
  #define EXTI_IMR1_IM20     0x00100000	/* CPU1 Interrupt Mask on line 20 */
  #define EXTI_IMR1_IM21     0x00200000	/* CPU1 Interrupt Mask on line 21 */
  #define EXTI_IMR1_IM22     0x00400000	/* CPU1 Interrupt Mask on line 22 */
  #define EXTI_IMR1_IM23     0x00800000	/* CPU1 Interrupt Mask on line 23 */
  #define EXTI_IMR1_IM24     0x01000000	/* CPU1 Interrupt Mask on line 24 */
  #define EXTI_IMR1_IM25     0x02000000	/* CPU1 Interrupt Mask on line 25 */
  #define EXTI_IMR1_IM26     0x04000000	/* CPU1 Interrupt Mask on line 26 */
  #define EXTI_IMR1_IM27     0x08000000	/* CPU1 Interrupt Mask on line 27 */
  #define EXTI_IMR1_IM28     0x10000000	/* CPU1 Interrupt Mask on line 28 */
  #define EXTI_IMR1_IM29     0x20000000	/* CPU1 Interrupt Mask on line 29 */
  #define EXTI_IMR1_IM30     0x40000000	/* CPU1 Interrupt Mask on line 30 */
  #define EXTI_IMR1_IM31     0x80000000	/* CPU1 Interrupt Mask on line 31 */
#define TOFF_EXTI_EMR1      0x0084	/* (RW) EXTI wakeup with event mask register for cpu1 [31:0] */
  #define EXTI_EMR1_EM       0x003EFFFF	/* CPU1 Event Mask */
  #define EXTI_EMR1_EM0      0x00000001	/* CPU1 Event Mask on line 0 */
  #define EXTI_EMR1_EM1      0x00000002	/* CPU1 Event Mask on line 1 */
  #define EXTI_EMR1_EM2      0x00000004	/* CPU1 Event Mask on line 2 */
  #define EXTI_EMR1_EM3      0x00000008	/* CPU1 Event Mask on line 3 */
  #define EXTI_EMR1_EM4      0x00000010	/* CPU1 Event Mask on line 4 */
  #define EXTI_EMR1_EM5      0x00000020	/* CPU1 Event Mask on line 5 */
  #define EXTI_EMR1_EM6      0x00000040	/* CPU1 Event Mask on line 6 */
  #define EXTI_EMR1_EM7      0x00000080	/* CPU1 Event Mask on line 7 */
  #define EXTI_EMR1_EM8      0x00000100	/* CPU1 Event Mask on line 8 */
  #define EXTI_EMR1_EM9      0x00000200	/* CPU1 Event Mask on line 9 */
  #define EXTI_EMR1_EM10     0x00000400	/* CPU1 Event Mask on line 10 */
  #define EXTI_EMR1_EM11     0x00000800	/* CPU1 Event Mask on line 11 */
  #define EXTI_EMR1_EM12     0x00001000	/* CPU1 Event Mask on line 12 */
  #define EXTI_EMR1_EM13     0x00002000	/* CPU1 Event Mask on line 13 */
  #define EXTI_EMR1_EM14     0x00004000	/* CPU1 Event Mask on line 14 */
  #define EXTI_EMR1_EM15     0x00008000	/* CPU1 Event Mask on line 15 */
  #define EXTI_EMR1_EM16     0x00010000	/* CPU1 Event Mask on line 16 */
  #define EXTI_EMR1_EM17     0x00020000	/* CPU1 Event Mask on line 17 */
  #define EXTI_EMR1_EM18     0x00040000	/* CPU1 Event Mask on line 18 */
  #define EXTI_EMR1_EM19     0x00080000	/* CPU1 Event Mask on line 19 */
  #define EXTI_EMR1_EM20     0x00100000	/* CPU1 Event Mask on line 20 */
  #define EXTI_EMR1_EM21     0x00200000	/* CPU1 Event Mask on line 21 */
#define TOFF_EXTI_IMR2      0x0090	/* (RW) EXTI wakeup with interrupt mask register for cpu1 [31:0] */
  #define EXTI_IMR2_IM       0x0001FFFF	/* CPU1 Interrupt Mask  */
  #define EXTI_IMR2_IM32     0x00000001	/* CPU1 Interrupt Mask on line 32 */
  #define EXTI_IMR2_IM33     0x00000002	/* CPU1 Interrupt Mask on line 33 */
  #define EXTI_IMR2_IM34     0x00000004	/* CPU1 Interrupt Mask on line 34 */
  #define EXTI_IMR2_IM35     0x00000008	/* CPU1 Interrupt Mask on line 35 */
  #define EXTI_IMR2_IM36     0x00000010	/* CPU1 Interrupt Mask on line 36 */
  #define EXTI_IMR2_IM37     0x00000020	/* CPU1 Interrupt Mask on line 37 */
  #define EXTI_IMR2_IM38     0x00000040	/* CPU1 Interrupt Mask on line 38 */
  #define EXTI_IMR2_IM39     0x00000080	/* CPU1 Interrupt Mask on line 39 */
  #define EXTI_IMR2_IM40     0x00000100	/* CPU1 Interrupt Mask on line 40 */
  #define EXTI_IMR2_IM41     0x00000200	/* CPU1 Interrupt Mask on line 41 */
  #define EXTI_IMR2_IM42     0x00000400	/* CPU1 Interrupt Mask on line 42 */
  #define EXTI_IMR2_IM43     0x00000800	/* CPU1 Interrupt Mask on line 43 */
  #define EXTI_IMR2_IM44     0x00001000	/* CPU1 Interrupt Mask on line 44 */
  #define EXTI_IMR2_IM45     0x00002000	/* CPU1 Interrupt Mask on line 45 */
  #define EXTI_IMR2_IM46     0x00004000	/* CPU1 Interrupt Mask on line 46 */
  #define EXTI_IMR2_IM47     0x00008000	/* CPU1 Interrupt Mask on line 47 */
  #define EXTI_IMR2_IM48     0x00010000	/* CPU1 Interrupt Mask on line 48 */
#define TOFF_EXTI_EMR2      0x0094	/* (RW) EXTI wakeup with event mask register for cpu1 [31:0] */
  #define EXTI_EMR2_EM       0x00000300	/* CPU1 Interrupt Mask  */
  #define EXTI_EMR2_EM40     0x00000100	/* CPU1 Event Mask on line 40 */
  #define EXTI_EMR2_EM41     0x00000200	/* CPU1 Event Mask on line 41 */
#define TOFF_EXTI_C2IMR1    0x00C0	/* (RW) EXTI wakeup with interrupt mask register for cpu2 [31:0] */
  #define EXTI_C2IMR1_IM     0xFFFFFFFF	/* CPU2 wakeup with interrupt Mask on Event */
  #define EXTI_C2IMR1_IM0    0x00000001	/* CPU2 Interrupt Mask on line 0 */
  #define EXTI_C2IMR1_IM1    0x00000002	/* CPU2 Interrupt Mask on line 1 */
  #define EXTI_C2IMR1_IM2    0x00000004	/* CPU2 Interrupt Mask on line 2 */
  #define EXTI_C2IMR1_IM3    0x00000008	/* CPU2 Interrupt Mask on line 3 */
  #define EXTI_C2IMR1_IM4    0x00000010	/* CPU2 Interrupt Mask on line 4 */
  #define EXTI_C2IMR1_IM5    0x00000020	/* CPU2 Interrupt Mask on line 5 */
  #define EXTI_C2IMR1_IM6    0x00000040	/* CPU2 Interrupt Mask on line 6 */
  #define EXTI_C2IMR1_IM7    0x00000080	/* CPU2 Interrupt Mask on line 7 */
  #define EXTI_C2IMR1_IM8    0x00000100	/* CPU2 Interrupt Mask on line 8 */
  #define EXTI_C2IMR1_IM9    0x00000200	/* CPU2 Interrupt Mask on line 9 */
  #define EXTI_C2IMR1_IM10   0x00000400	/* CPU2 Interrupt Mask on line 10 */
  #define EXTI_C2IMR1_IM11   0x00000800	/* CPU2 Interrupt Mask on line 11 */
  #define EXTI_C2IMR1_IM12   0x00001000	/* CPU2 Interrupt Mask on line 12 */
  #define EXTI_C2IMR1_IM13   0x00002000	/* CPU2 Interrupt Mask on line 13 */
  #define EXTI_C2IMR1_IM14   0x00004000	/* CPU2 Interrupt Mask on line 14 */
  #define EXTI_C2IMR1_IM15   0x00008000	/* CPU2 Interrupt Mask on line 15 */
  #define EXTI_C2IMR1_IM16   0x00010000	/* CPU2 Interrupt Mask on line 16 */
  #define EXTI_C2IMR1_IM17   0x00020000	/* CPU2 Interrupt Mask on line 17 */
  #define EXTI_C2IMR1_IM18   0x00040000	/* CPU2 Interrupt Mask on line 18 */
  #define EXTI_C2IMR1_IM19   0x00080000	/* CPU2 Interrupt Mask on line 19 */
  #define EXTI_C2IMR1_IM20   0x00100000	/* CPU2 Interrupt Mask on line 20 */
  #define EXTI_C2IMR1_IM21   0x00200000	/* CPU2 Interrupt Mask on line 21 */
  #define EXTI_C2IMR1_IM22   0x00400000	/* CPU2 Interrupt Mask on line 22 */
  #define EXTI_C2IMR1_IM23   0x00800000	/* CPU2 Interrupt Mask on line 23 */
  #define EXTI_C2IMR1_IM24   0x01000000	/* CPU2 Interrupt Mask on line 24 */
  #define EXTI_C2IMR1_IM25   0x02000000	/* CPU2 Interrupt Mask on line 25 */
  #define EXTI_C2IMR1_IM26   0x04000000	/* CPU2 Interrupt Mask on line 26 */
  #define EXTI_C2IMR1_IM27   0x08000000	/* CPU2 Interrupt Mask on line 27 */
  #define EXTI_C2IMR1_IM28   0x10000000	/* CPU2 Interrupt Mask on line 28 */
  #define EXTI_C2IMR1_IM29   0x20000000	/* CPU2 Interrupt Mask on line 29 */
  #define EXTI_C2IMR1_IM30   0x40000000	/* CPU2 Interrupt Mask on line 30 */
  #define EXTI_C2IMR1_IM31   0x80000000	/* CPU2 Interrupt Mask on line 31 */
#define TOFF_EXTI_C2EMR1    0x00C4	/* (RW) EXTI wakeup with event mask register for cpu2 [31:0] */
  #define EXTI_C2EMR1_EM     0x003EFFFF	/* CPU2 Event Mask */
  #define EXTI_C2EMR1_EM0    0x00000001	/* CPU2 Event Mask on line 0 */
  #define EXTI_C2EMR1_EM1    0x00000002	/* CPU2 Event Mask on line 1 */
  #define EXTI_C2EMR1_EM2    0x00000004	/* CPU2 Event Mask on line 2 */
  #define EXTI_C2EMR1_EM3    0x00000008	/* CPU2 Event Mask on line 3 */
  #define EXTI_C2EMR1_EM4    0x00000010	/* CPU2 Event Mask on line 4 */
  #define EXTI_C2EMR1_EM5    0x00000020	/* CPU2 Event Mask on line 5 */
  #define EXTI_C2EMR1_EM6    0x00000040	/* CPU2 Event Mask on line 6 */
  #define EXTI_C2EMR1_EM7    0x00000080	/* CPU2 Event Mask on line 7 */
  #define EXTI_C2EMR1_EM8    0x00000100	/* CPU2 Event Mask on line 8 */
  #define EXTI_C2EMR1_EM9    0x00000200	/* CPU2 Event Mask on line 9 */
  #define EXTI_C2EMR1_EM10   0x00000400	/* CPU2 Event Mask on line 10 */
  #define EXTI_C2EMR1_EM11   0x00000800	/* CPU2 Event Mask on line 11 */
  #define EXTI_C2EMR1_EM12   0x00001000	/* CPU2 Event Mask on line 12 */
  #define EXTI_C2EMR1_EM13   0x00002000	/* CPU2 Event Mask on line 13 */
  #define EXTI_C2EMR1_EM14   0x00004000	/* CPU2 Event Mask on line 14 */
  #define EXTI_C2EMR1_EM15   0x00008000	/* CPU2 Event Mask on line 15 */
  #define EXTI_C2EMR1_EM16   0x00010000	/* CPU2 Event Mask on line 16 */
  #define EXTI_C2EMR1_EM17   0x00020000	/* CPU2 Event Mask on line 17 */
  #define EXTI_C2EMR1_EM18   0x00040000	/* CPU2 Event Mask on line 18 */
  #define EXTI_C2EMR1_EM19   0x00080000	/* CPU2 Event Mask on line 19 */
  #define EXTI_C2EMR1_EM20   0x00100000	/* CPU2 Event Mask on line 20 */
  #define EXTI_C2EMR1_EM21   0x00200000	/* CPU2 Event Mask on line 21 */
#define TOFF_EXTI_C2IMR2    0x00D0	/* (RW) EXTI wakeup with interrupt mask register for cpu2 [31:0] */
  #define EXTI_C2IMR2_IM     0x0001FFFF	/* CPU2 Interrupt Mask  */
  #define EXTI_C2IMR2_IM32   0x00000001	/* CPU2 Interrupt Mask on line 32 */
  #define EXTI_C2IMR2_IM33   0x00000002	/* CPU2 Interrupt Mask on line 33 */
  #define EXTI_C2IMR2_IM34   0x00000004	/* CPU2 Interrupt Mask on line 34 */
  #define EXTI_C2IMR2_IM35   0x00000008	/* CPU2 Interrupt Mask on line 35 */
  #define EXTI_C2IMR2_IM36   0x00000010	/* CPU2 Interrupt Mask on line 36 */
  #define EXTI_C2IMR2_IM37   0x00000020	/* CPU2 Interrupt Mask on line 37 */
  #define EXTI_C2IMR2_IM38   0x00000040	/* CPU2 Interrupt Mask on line 38 */
  #define EXTI_C2IMR2_IM39   0x00000080	/* CPU2 Interrupt Mask on line 39 */
  #define EXTI_C2IMR2_IM40   0x00000100	/* CPU2 Interrupt Mask on line 40 */
  #define EXTI_C2IMR2_IM41   0x00000200	/* CPU2 Interrupt Mask on line 41 */
  #define EXTI_C2IMR2_IM42   0x00000400	/* CPU2 Interrupt Mask on line 42 */
  #define EXTI_C2IMR2_IM43   0x00000800	/* CPU2 Interrupt Mask on line 43 */
  #define EXTI_C2IMR2_IM44   0x00001000	/* CPU2 Interrupt Mask on line 44 */
  #define EXTI_C2IMR2_IM45   0x00002000	/* CPU2 Interrupt Mask on line 45 */
  #define EXTI_C2IMR2_IM46   0x00004000	/* CPU2 Interrupt Mask on line 46 */
  #define EXTI_C2IMR2_IM47   0x00008000	/* CPU2 Interrupt Mask on line 47 */
  #define EXTI_C2IMR2_IM48   0x00010000	/* CPU2 Interrupt Mask on line 48 */
#define TOFF_EXTI_C2EMR2    0x00D4	/* (RW) EXTI wakeup with event mask register for cpu2 [31:0] */ 
  #define EXTI_C2EMR2_EM     0x00000300	/* CPU2 Interrupt Mask  */
  #define EXTI_C2EMR2_EM40   0x00000100	/* CPU2 Event Mask on line 40 */
  #define EXTI_C2EMR2_EM41   0x00000200	/* CPU2 Event Mask on line 41 */


/*
 *  HW SEMAPHORE (HSEM)
 */
#define TADR_HSEM_BASE      (AHB4PERIPH_BASE + 0x1400)
#define TOFF_HSEM_R         0x0000	/* (RW) HSEM 2-step write lock and read back registers, 0-31 */
  #define HSEM_R_PROCID      0x000000FF	/* Semaphore ProcessID */
  #define HSEM_R_COREID      0x00000F00	/* Semaphore CoreID. */
  #define HSEM_R_LOCK        0x80000000	/* Lock indication. */
#define TOFF_HSEM_RLR       0x0080	/* (RW) HSEM 1-step read lock registers 0-31 */
  #define HSEM_RLR_PROCID    0x000000FF	/* Semaphore ProcessID */
  #define HSEM_RLR_COREID    0x00000F00	/* Semaphore CoreID. */
  #define HSEM_RLR_LOCK      0x80000000	/* Lock indication. */
#define TOFF_HSEM_C1IER     0x0100	/* (RW) HSEM CPU1 interrupt enable register */
#define TOFF_HSEM_C1ICR     0x0104	/* (RW) HSEM CPU1 interrupt clear register */
#define TOFF_HSEM_C1ISR     0x0108	/* (RW) HSEM CPU1 interrupt status register */
#define TOFF_HSEM_C1MISR    0x010C	/* (RW) HSEM CPU1 masked interrupt status register */
#define TOFF_HSEM_C2IER     0x0110	/* (RW) HSEM CPU2 interrupt enable register */
#define TOFF_HSEM_C2ICR     0x0114	/* (RW) HSEM CPU2 interrupt clear register */
#define TOFF_HSEM_C2ISR     0x0118	/* (RW) HSEM CPU2 interrupt status register */
#define TOFF_HSEM_C2MISR    0x011C	/* (RW) HSEM CPU2 masked interrupt status register */
#define TOFF_HSEM_CR        0x0140	/* (RW) HSEM Semaphore clear register */
  #define HSEM_CR_COREID     0x00000F00	/* CoreID of semaphores to be cleared. */
  #define HSEM_CR_COREID_CPU1    0x00000400
  #define HSEM_CR_COREID_CPU2    0x00000800
  #define HSEM_CR_COREID_CURRENT HSEM_CR_COREID_CPU1
  #define HSEM_CR_KEY        0xFFFF0000	/* semaphores clear key. */
#define TOFF_HSEM_KEYR      0x0144	/* (RW) HSEM Semaphore clear key register */
  #define HSEM_KEYR_KEY      0xFFFF0000	/* semaphores clear key. */

#define TADR_HSEM_COMMON_BASE  (TADR_HSEM_BASE + TOFF_HSEM_C1IER)
#define TOFF_HSEMC_IER      0x0000	/* (RW) HSEM interrupt enable register */
  #define HSEM_CIER_ISE0     0x00000001	/* semaphore 0 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE1     0x00000002	/* semaphore 1 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE2     0x00000004	/* semaphore 2 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE3     0x00000008	/* semaphore 3 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE4     0x00000010	/* semaphore 4 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE5     0x00000020	/* semaphore 5 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE6     0x00000040	/* semaphore 6 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE7     0x00000080	/* semaphore 7 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE8     0x00000100	/* semaphore 8 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE9     0x00000200	/* semaphore 9 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE10    0x00000400	/* semaphore 10 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE11    0x00000800	/* semaphore 11 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE12    0x00001000	/* semaphore 12 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE13    0x00002000	/* semaphore 13 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE14    0x00004000	/* semaphore 14 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE15    0x00008000	/* semaphore 15 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE16    0x00010000	/* semaphore 16 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE17    0x00020000	/* semaphore 17 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE18    0x00040000	/* semaphore 18 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE19    0x00080000	/* semaphore 19 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE20    0x00100000	/* semaphore 20 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE21    0x00200000	/* semaphore 21 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE22    0x00400000	/* semaphore 22 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE23    0x00800000	/* semaphore 23 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE24    0x01000000	/* semaphore 24 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE25    0x02000000	/* semaphore 25 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE26    0x04000000	/* semaphore 26 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE27    0x08000000	/* semaphore 27 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE28    0x10000000	/* semaphore 28 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE29    0x20000000	/* semaphore 29 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE30    0x40000000	/* semaphore 30 CPUn interrupt enable bit.  */
  #define HSEM_CIER_ISE31    0x80000000	/* semaphore 31 CPUn interrupt enable bit.  */
#define TOFF_HSEMC_ICR      0x0004	/* (RW) HSEM interrupt clear register */
  #define HSEM_CICR_ISC0     0x00000001	/* semaphore 0 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC1     0x00000002	/* semaphore 1 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC2     0x00000004	/* semaphore 2 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC3     0x00000008	/* semaphore 3 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC4     0x00000010	/* semaphore 4 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC5     0x00000020	/* semaphore 5 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC6     0x00000040	/* semaphore 6 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC7     0x00000080	/* semaphore 7 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC8     0x00000100	/* semaphore 8 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC9     0x00000200	/* semaphore 9 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC10    0x00000400	/* semaphore 10 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC11    0x00000800	/* semaphore 11 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC12    0x00001000	/* semaphore 12 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC13    0x00002000	/* semaphore 13 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC14    0x00004000	/* semaphore 14 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC15    0x00008000	/* semaphore 15 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC16    0x00010000	/* semaphore 16 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC17    0x00020000	/* semaphore 17 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC18    0x00040000	/* semaphore 18 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC19    0x00080000	/* semaphore 19 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC20    0x00100000	/* semaphore 20 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC21    0x00200000	/* semaphore 21 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC22    0x00400000	/* semaphore 22 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC23    0x00800000	/* semaphore 23 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC24    0x01000000	/* semaphore 24 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC25    0x02000000	/* semaphore 25 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC26    0x04000000	/* semaphore 26 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC27    0x08000000	/* semaphore 27 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC28    0x10000000	/* semaphore 28 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC29    0x20000000	/* semaphore 29 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC30    0x40000000	/* semaphore 30 CPUn interrupt clear bit.  */
  #define HSEM_CICR_ISC31    0x80000000	/* semaphore 31 CPUn interrupt clear bit.  */
#define TOFF_HSEMC_ISR      0x0008	/* (RW) HSEM interrupt status register */
  #define HSEM_CISR_ISF0     0x00000001	/* semaphore 0 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF1     0x00000002	/* semaphore 1 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF2     0x00000004	/* semaphore 2 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF3     0x00000008	/* semaphore 3 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF4     0x00000010	/* semaphore 4 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF5     0x00000020	/* semaphore 5 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF6     0x00000040	/* semaphore 6 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF7     0x00000080	/* semaphore 7 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF8     0x00000100	/* semaphore 8 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF9     0x00000200	/* semaphore 9 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF10    0x00000400	/* semaphore 10 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF11    0x00000800	/* semaphore 11 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF12    0x00001000	/* semaphore 12 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF13    0x00002000	/* semaphore 13 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF14    0x00004000	/* semaphore 14 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF15    0x00008000	/* semaphore 15 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF16    0x00010000	/* semaphore 16 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF17    0x00020000	/* semaphore 17 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF18    0x00040000	/* semaphore 18 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF19    0x00080000	/* semaphore 19 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF20    0x00100000	/* semaphore 20 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF21    0x00200000	/* semaphore 21 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF22    0x00400000	/* semaphore 22 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF23    0x00800000	/* semaphore 23 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF24    0x01000000	/* semaphore 24 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF25    0x02000000	/* semaphore 25 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF26    0x04000000	/* semaphore 26 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF27    0x08000000	/* semaphore 27 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF28    0x10000000	/* semaphore 28 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF29    0x20000000	/* semaphore 29 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF30    0x40000000	/* semaphore 30 CPUn interrupt status bit.  */
  #define HSEM_CISR_ISF31    0x80000000	/* semaphore 31 CPUn interrupt status bit.  */
#define TOFF_HSEMC_MISR     0x000C	/* (RW) HSEM masked interrupt status register */
  #define HSEM_CMISR_MISF0   0x00000001	/* semaphore 0 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF1   0x00000002	/* semaphore 1 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF2   0x00000004	/* semaphore 2 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF3   0x00000008	/* semaphore 3 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF4   0x00000010	/* semaphore 4 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF5   0x00000020	/* semaphore 5 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF6   0x00000040	/* semaphore 6 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF7   0x00000080	/* semaphore 7 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF8   0x00000100	/* semaphore 8 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF9   0x00000200	/* semaphore 9 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF10  0x00000400	/* semaphore 10 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF11  0x00000800	/* semaphore 11 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF12  0x00001000	/* semaphore 12 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF13  0x00002000	/* semaphore 13 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF14  0x00004000	/* semaphore 14 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF15  0x00008000	/* semaphore 15 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF16  0x00010000	/* semaphore 16 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF17  0x00020000	/* semaphore 17 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF18  0x00040000	/* semaphore 18 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF19  0x00080000	/* semaphore 19 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF20  0x00100000	/* semaphore 20 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF21  0x00200000	/* semaphore 21 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF22  0x00400000	/* semaphore 22 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF23  0x00800000	/* semaphore 23 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF24  0x01000000	/* semaphore 24 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF25  0x02000000	/* semaphore 25 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF26  0x04000000	/* semaphore 26 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF27  0x08000000	/* semaphore 27 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF28  0x10000000	/* semaphore 28 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF29  0x20000000	/* semaphore 29 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF30  0x40000000	/* semaphore 30 CPUn interrupt masked status bit.  */
  #define HSEM_CMISR_MISF31  0x80000000	/* semaphore 31 CPUn interrupt masked status bit.  */


/*
 *  INTER-PROCESSOR COMMUNICATION (IPCC)
 */
#define TADR_IPCC_BASE      (AHB4PERIPH_BASE + 0x0C00)
#define TOFF_IPCC1          0x0000
#define TOFF_IPCC_C1CR      TOFF_IPCC1	/* (RW) Inter-Processor Communication: C1 control register */
  #define IPCC_C1CR_RXOIE    0x00000001	/* Processor M4 Receive channel occupied interrupt enable */
  #define IPCC_C1CR_TXFIE    0x00010000	/* Processor M4 Transmit channel free interrupt enable */
#define TOFF_IPCC_C1MR      0x0004		/* (RW) Inter-Processor Communication: C1 mask register */
#define TOFF_IPCC_C1SCR     0x0008		/* (RW) Inter-Processor Communication: C1 status set clear register */
#define TOFF_IPCC_C1TOC2SR  0x000C		/* (RW) Inter-Processor Communication: C1 to processor M4  status register */
#define TOFF_IPCC2          0x0010
#define TOFF_IPCC_C2CR      TOFF_IPCC2	/* (RW) Inter-Processor Communication: C2 control register */
#define TOFF_IPCC_C2MR      0x0014		/* (RW) Inter-Processor Communication: C2 mask register */
#define TOFF_IPCC_C2SCR     0x0018		/* (RW) Inter-Processor Communication: C2 status set clear register */
#define TOFF_IPCC_C2TOC1SR  0x001C		/* (RW) Inter-Processor Communication: C2 to processor M4 status register */

#define TOFF_IPCC_CR        0x0000		/* (RW) Control register */
  #define IPCC_CR_RXOIE      0x00000001	/* Processor M4 Receive channel occupied interrupt enable */
  #define IPCC_CR_TXFIE      0x00010000	/* Processor M4 Transmit channel free interrupt enable */
#define TOFF_IPCC_MR        0x0004		/* (RW) Mask register */
  #define IPCC_MR_CH1OM      0x00000001	/* Channel1 occupied interrupt mask */
  #define IPCC_MR_CH2OM      0x00000002	/* Channel2 occupied interrupt mask */
  #define IPCC_MR_CH3OM      0x00000004	/* Channel3 occupied interrupt mask */
  #define IPCC_MR_CH4OM      0x00000008	/* Channel4 occupied interrupt mask */
  #define IPCC_MR_CH5OM      0x00000010	/* Channel5 occupied interrupt mask */
  #define IPCC_MR_CH6OM      0x00000020	/* Channel6 occupied interrupt mask */
  #define IPCC_MR_CH1FM      0x00010000	/* Transmit Channel1 free interrupt mask */
  #define IPCC_MR_CH2FM      0x00020000	/* Transmit Channel2 free interrupt mask */
  #define IPCC_MR_CH3FM      0x00040000	/* Transmit Channel3 free interrupt mask */
  #define IPCC_MR_CH4FM      0x00080000	/* Transmit Channel4 free interrupt mask */
  #define IPCC_MR_CH5FM      0x00100000	/* Transmit Channel5 free interrupt mask */
  #define IPCC_MR_CH6FM      0x00200000	/* Transmit Channel6 free interrupt mask */
#define TOFF_IPCC_SCR       0x0008		/* (RW) Status set clear register */
  #define IPCC_SCR_CH1C      0x00000001	/* receive Channel1 status clear */
  #define IPCC_SCR_CH2C      0x00000002	/* receive Channel2 status clear */
  #define IPCC_SCR_CH3C      0x00000004	/* receive Channel3 status clear */
  #define IPCC_SCR_CH4C      0x00000008	/* receive Channel4 status clear */
  #define IPCC_SCR_CH5C      0x00000010	/* receive Channel5 status clear */
  #define IPCC_SCR_CH6C      0x00000020	/* receive Channel6 status clear */
  #define IPCC_SCR_CH1S      0x00010000	/* transmit Channel1 status set */
  #define IPCC_SCR_CH2S      0x00020000	/* transmit Channel2 status set */
  #define IPCC_SCR_CH3S      0x00040000	/* transmit Channel3 status set */
  #define IPCC_SCR_CH4S      0x00080000	/* transmit Channel4 status set */
  #define IPCC_SCR_CH5S      0x00100000	/* transmit Channel5 status set */
  #define IPCC_SCR_CH6S      0x00200000	/* transmit Channel6 status set  */
#define TOFF_IPCC_SR        0x000C		/* (RW) Status register */
  #define IPCC_SR_CH1F       0x00000001	/* transmit to receive Channel1 status flag before masking */
  #define IPCC_SR_CH2F       0x00000002	/* transmit to receive Channel2 status flag before masking */
  #define IPCC_SR_CH3F       0x00000004	/* transmit to receive Channel3 status flag before masking */
  #define IPCC_SR_CH4F       0x00000008	/* transmit to receive Channel4 status flag before masking */
  #define IPCC_SR_CH5F       0x00000010	/* transmit to receive Channel5 status flag before masking */
  #define IPCC_SR_CH6F       0x00000020	/* transmit to receive Channel6 status flag before masking */

/*
 *  PUBLIC KEY ACCELERATER (PKA)
 */
#define TADR_PKA_BASE       (AHB4PERIPH_BASE + 0x4000)
#define TOFF_PKA_CR         0x0000		/* (RW) PKA control register */
  #define PKA_CR_EN          0x00000001	/* PKA enable */
  #define PKA_CR_START       0x00000002	/* Start operation */
  #define PKA_CR_MODE        0x00003F00	/* MODE[5:0] PKA operation code */
  #define PKA_CR_MODE_0      0x00000100
  #define PKA_CR_MODE_1      0x00000200
  #define PKA_CR_MODE_2      0x00000400
  #define PKA_CR_MODE_3      0x00000800
  #define PKA_CR_MODE_4      0x00001000
  #define PKA_CR_MODE_5      0x00002000
  #define PKA_CR_PROCENDIE   0x00020000	/* End of operation interrupt enable */
  #define PKA_CR_RAMERRIE    0x00080000	/* RAM error interrupt enable */
  #define PKA_CR_ADDRERRIE   0x00100000	/* RAM error interrupt enable */
#define TOFF_PKA_SR         0x0004		/* (RW) PKA status register */
  #define PKA_SR_BUSY        0x00010000	/* PKA operation is in progress */
  #define PKA_SR_PROCENDF    0x00020000	/* PKA end of operation flag */
  #define PKA_SR_RAMERRF     0x00080000	/* PKA RAM error flag */
  #define PKA_SR_ADDRERRF    0x00100000	/* Address error flag */
#define TOFF_PKA_CLRFR      0x0008		/* (RW) PKA clear flag register */
  #define PKA_CLRFR_PROCENDFC 0x00020000	/* Clear PKA end of operation flag */
  #define PKA_CLRFR_RAMERRFC  0x00080000	/* Clear PKA RAM error flag */
  #define PKA_CLRFR_ADDRERRFC 0x00100000	/* Clear address error flag */
#define TOFF_PKA_RAM        0x0400		/* (RW) PKA RAM 0x0400-0x11F4 */


/*
 *  FLASH REGISTERS
 */
#define TADR_FLASH_R_BASE   (AHB4PERIPH_BASE + 0x4000)
#define TOFF_FLASH_ACR      0x0000		/* (RW) FLASH access control register */
  #define FLASH_ACR_LATENCY  0x00000007
  #define FLASH_ACR_LATENCY_0WS  0x00000000
  #define FLASH_ACR_LATENCY_1WS  0x00000001
  #define FLASH_ACR_LATENCY_2WS  0x00000002
  #define FLASH_ACR_LATENCY_3WS  0x00000003
  #define FLASH_ACR_LATENCY_4WS  0x00000004
  #define FLASH_ACR_PRFTEN   0x00000100
  #define FLASH_ACR_ICEN     0x00000200
  #define FLASH_ACR_DCEN     0x00000400
  #define FLASH_ACR_ICRST    0x00000800
  #define FLASH_ACR_DCRST    0x00001000
  #define FLASH_ACR_PES      0x00008000	/* Program/erase suspend request */
  #define FLASH_ACR_EMPTY    0x00010000	/* Flash use area empty */
#define TOFF_FLASH_PDKEYR   0x0004		/* (RW) Power down key register */
#define TOFF_FLASH_KEYR     0x0008		/* (RW) FLASH key register */
#define TOFF_FLASH_OPTKEYR  0x000C		/* (RW) Option byte key register */
#define TOFF_FLASH_SR       0x0010		/* (RW) Status register */
  #define FLASH_SR_EOP       0x00000001	/* End Of Programming*/
  #define FLASH_SR_OPERR     0x00000002	/* Operation error */
  #define FLASH_SR_PROGERR   0x00000008	/* Programming error */
  #define FLASH_SR_WRPERR    0x00000010	/* Write protection error */
  #define FLASH_SR_PGAERR    0x00000020	/* Programming Alignment Error */
  #define FLASH_SR_SIZERR    0x00000040	/* Size error */
  #define FLASH_SR_PGSERR    0x00000080	/* Programming sequence error */
  #define FLASH_SR_MISERR    0x00000100	/* Fast programming data miss error */
  #define FLASH_SR_FASTERR   0x00000200	/* Fast programming error */
  #define FLASH_SR_OPTNV     0x00002000	/* User option OPTVAL indication */
  #define FLASH_SR_RDERR     0x00004000	/* PCROP read error */
  #define FLASH_SR_OPTVERR   0x00008000	/* Option Valid error */
  #define FLASH_SR_BSY       0x00010000	/* Busy */
  #define FLASH_SR_CFGBSY    0x00040000	/* Programming or erase configuration busy */
  #define FLASH_SR_PESD      0x00080000	/* Programming/erase operation suspended */
#define TOFF_FLASH_CR       0x0014		/* (RW) FLASH control register */
  #define FLASH_CR_PG        0x00000001	/* Flash programming */
  #define FLASH_CR_PER       0x00000002	/* Page erase */
  #define FLASH_CR_MER       0x00000004	/* Mass erase */
  #define FLASH_CR_PNB       0x000007F8	/* Page number selection mask */
  #define FLASH_CR_STRT      0x00010000	/* Start an erase operation */
  #define FLASH_CR_OPTSTRT   0x00020000	/* Options modification start */
  #define FLASH_CR_FSTPG     0x00040000	/* Fast programming */
  #define FLASH_CR_EOPIE     0x01000000	/* End of operation interrupt enable */
  #define FLASH_CR_ERRIE     0x02000000	/* Error interrupt enable */
  #define FLASH_CR_RDERRIE   0x04000000	/* PCROP read error interrupt enable */
  #define FLASH_CR_OBL_LAUNCH 0x08000000	/* Force the option bute loading */
  #define FLASH_CR_OPTLOCK   0x40000000	/* Options lock */
  #define FLASH_CR_LOCK      0x80000000	/* Flash control register lock */
#define TOFF_FLASH_ECCR     0x0018		/* (RW) FLASH ECC register */
  #define FLASH_ECCR_ADDR_ECC 0x0001FFFF	/* double-word address ECC fail */
  #define FLASH_ECCR_SYSF_ECC 0x00100000	/* System flash ECC fail */
  #define FLASH_ECCR_ECCIE    0x01000000	/* ECC correction interrupt enable */
  #define FLASH_ECCR_CPUID    0x1C000000	/* CPU identification */
  #define FLASH_ECCR_ECCC     0x40000000	/* ECC correction */
  #define FLASH_ECCR_ECCD     0x80000000	/* ECC detection */
#define TOFF_FLASH_OPTR     0x0020		/* (RW) Option byte register */
  #define FLASH_OPTR_RDP        0x000000FF	/* Read protection level */
  #define FLASH_OPTR_ESE        0x00000100	/* Security enable */
  #define FLASH_OPTR_BOR_LEV    0x00000E00	/* BOR reset level mask */
  #define FLASH_OPTR_BOR_LEV_0  0x00000200
  #define FLASH_OPTR_BOR_LEV_1  0x00000400
  #define FLASH_OPTR_BOR_LEV_2  0x00000800
  #define FLASH_OPTR_nRST_STOP  0x00001000	/* Reset option in Stop mode */
  #define FLASH_OPTR_nRST_STDBY 0x00002000	/* Reset option in Standby mode */
  #define FLASH_OPTR_nRST_SHDW  0x00004000	/* Reset option in Shutdown mode */
  #define FLASH_OPTR_IWDG_SW    0x00010000	/* Independent watchdog selection */
  #define FLASH_OPTR_IWDG_STOP  0x00020000	/* Independent watchdog counter option in Stop mode */
  #define FLASH_OPTR_IWDG_STDBY 0x00040000	/* Independent watchdog counter option in Standby mode */
  #define FLASH_OPTR_WWDG_SW    0x00080000	/* Window watchdog selection */
  #define FLASH_OPTR_nBOOT1     0x00800000	/* Boot Configuration */
  #define FLASH_OPTR_SRAM2_PE   0x01000000	/* SRAM2 parity check enable */
  #define FLASH_OPTR_SRAM2_RST  0x02000000	/* SRAM2 erase option when system reset */
  #define FLASH_OPTR_nSWBOOT0   0x04000000	/* Software BOOT0 */
  #define FLASH_OPTR_nBOOT0     0x08000000	/* BOOT0 option bit */
  #define FLASH_OPTR_AGC_TRIM   0xE0000000	/* Automatic Gain Control trimming mask */
  #define FLASH_OPTR_AGC_TRIM_0 0x20000000
  #define FLASH_OPTR_AGC_TRIM_1 0x40000000
  #define FLASH_OPTR_AGC_TRIM_2 0x80000000
#define TOFF_FLASH_PCROP1ASR 0x0024		/* (RW) FLASH Bank 1 PCROP area A Start address register */
  #define FLASH_PCROP1ASR_PCROP1A_STRT 0x000001FF	/* PCROP area A start offset */
#define TOFF_FLASH_PCROP1AER 0x0028		/* (RW) FLASH Bank 1 PCROP area A End address register */
  #define FLASH_PCROP1AER_PCROP1A_END  0x000001FF	/* PCROP area A end offset */
  #define FLASH_PCROP1AER_PCROP_RDP    0x80000000	/* PCROP area   preserved when RDP level decreased */
#define TOFF_FLASH_WRP1AR   0x002C		/* (RW) FLASH bank1 WRP area A address register */
  #define FLASH_WRP1AR_WRP1A_STRT      0x000000FF
  #define FLASH_WRP1AR_WRP1A_END       0x00FF0000
#define TOFF_FLASH_WRP1BR   0x0030		/* (RW) FLASH bank1 WRP area B address register */
  #define FLASH_WRP1BR_WRP1B_STRT      0x000000FF
  #define FLASH_WRP1BR_WRP1B_END       0x00FF0000
#define TOFF_FLASH_PCROP1BSR 0x0034		/* (RW) FLASH Bank 1 PCROP area B Start address register */
  #define FLASH_PCROP1BSR_PCROP1B_STRT 0x000001FF	/* PCROP area B start offset */
#define TOFF_FLASH_PCROP1BER 0x0038		/* (RW) FLASH Bank 1 PCROP area B End address register */
  #define FLASH_PCROP1BER_PCROP1B_END  0x000001FF	/* PCROP area B end offset */
#define TOFF_FLASH_IPCCBR   0x003C		/* (RW) FLASH IPCC data buffer address */
  #define FLASH_IPCCBR_IPCCDBA         0x00003FFF	/* IPCC data buffer base address */
#define TOFF_FLASH_C2ACR    0x005C		/* (RW) FLASH Core MO+ Access Control Register */
  #define FLASH_C2ACR_PRFTEN    0x00000100	/* CPU2 Prefetch enable */
  #define FLASH_C2ACR_ICEN      0x00000200	/* CPU2 Instruction cache enable */
  #define FLASH_C2ACR_ICRST     0x00000800	/* CPU2 Instruction cache reset */
  #define FLASH_C2ACR_PES       0x00008000	/* CPU2 Program/erase suspend request */
#define TOFF_FLASH_C2SR     0x0060		/* (RW) FLASH Core MO+ Status Register */
  #define FLASH_C2SR_EOP        0x00000001	/* CPU2 End of operation */
  #define FLASH_C2SR_OPERR      0x00000002	/* CPU2 Operation error */
  #define FLASH_C2SR_PROGERR    0x00000008	/* CPU2 Programming error */
  #define FLASH_C2SR_WRPERR     0x00000010	/* CPU2 Write protection error */
  #define FLASH_C2SR_PGAERR     0x00000020	/* CPU2 Programming alignment error */
  #define FLASH_C2SR_SIZERR     0x00000040	/* CPU2 Size error */
  #define FLASH_C2SR_PGSERR     0x00000080	/* CPU2 Programming sequence error */
  #define FLASH_C2SR_MISERR     0x00000100	/* CPU2 Fast programming data miss error */
  #define FLASH_C2SR_FASTERR    0x00000200	/* CPU2 Fast programming error */
  #define FLASH_C2SR_RDERR      0x00004000	/* CPU2 PCROP read error */
  #define FLASH_C2SR_BSY        0x00010000	/* CPU2 Flash busy */
  #define FLASH_C2SR_CFGBSY     0x00040000	/* CPU2 Programming or erase configuration busy */
  #define FLASH_C2SR_PESD       0x00080000	/* CPU2 Programming/erase operation suspended */
#define TOFF_FLASH_C2CR     0x0064		/* (RW) FLASH Core MO+ Control register */
  #define FLASH_C2CR_PG         0x00000001	/* CPU2 Flash programming */
  #define FLASH_C2CR_PER        0x00000002	/* CPU2 Page erase */
  #define FLASH_C2CR_MER        0x00000004	/* CPU2 Mass erase */
  #define FLASH_C2CR_PNB        0x000007F8	/* CPU2 Page number selection mask */
  #define FLASH_C2CR_STRT       0x00010000	/* CPU2 Start an erase operation */
  #define FLASH_C2CR_FSTPG      0x00040000	/* CPU2 Fast programming */
  #define FLASH_C2CR_EOPIE      0x01000000	/* CPU2 End of operation interrupt enable */
  #define FLASH_C2CR_ERRIE      0x02000000	/* CPU2 Error interrupt enable */
  #define FLASH_C2CR_RDERRIE    0x04000000	/* CPU2 PCROP read error interrupt enable */
#define TOFF_FLASH_SFR      0x0080		/* (RW) FLASH secure start address */
  #define FLASH_SFR_SFSA        0x000000FF	/* Secure flash start address */
  #define FLASH_SFR_FSD         0x00000100	/* Flash mode secure */
  #define FLASH_SFR_DDS         0x00001000	/* Enabling and disabling CPU2 Debug access */
#define TOFF_FLASH_SRRVR    0x0084		/* (RW) FlASH secure SRAM2 start addr and CPU2 reset vector Address */
  #define FLASH_SRRVR_SBRV      0x0003FFFF	/* SCPU2 boot reset vector memory offset */
  #define FLASH_SRRVR_SBRSA     0x007C0000	/* Secure backup SRAM2a start address */
  #define FLASH_SRRVR_BRSD      0x00800000	/* Backup SRAM2A secure mode */
  #define FLASH_SRRVR_SNBRSA    0x3E000000	/* Secure non-backup SRAM2b start address */
  #define FLASH_SRRVR_NBRSD     0x40000000	/* Non-backup SRAM2B secure mode */
  #define FLASH_SRRVR_C2OPT     0x80000000	/* SCPU2 boot reset vector memory selection */


/*
 *  RANDOM NUMBER GENERATOR
 */
#define TADR_RNG_BASE       (AHB4PERIPH_BASE + 0x1000)
#define TOFF_RNG_CR         0x0000		/* (RW) RNG control register */
  #define RNG_CR_RNGEN       0x00000004
  #define RNG_CR_IE          0x00000008
  #define RNG_CR_CED         0x00000020
#define TOFF_RNG_SR         0x0004		/* (RW) RNG status register */
  #define RNG_SR_DRDY        0x00000001
  #define RNG_SR_CECS        0x00000002
  #define RNG_SR_SECS        0x00000004
  #define RNG_SR_CEIS        0x00000020
  #define RNG_SR_SEIS        0x00000040
#define TOFF_RNG_DR         0x0008		/* (RW) RNG data register */


/*
 * QUAD SERIAL PERIPHERAL INTERFACE
 */
#define TADR_QSPI_R_BASE    (AHB3PERIPH_BASE + 0x10001000)
#define TOFF_QUADSPI_CR     0x0000		/* (RW) QUADSPI Control register */
  #define QUADSPI_CR_EN         0x00000001	/* Enable */
  #define QUADSPI_CR_ABORT      0x00000002	/* Abort request */
  #define QUADSPI_CR_DMAEN      0x00000004	/* DMA Enable */
  #define QUADSPI_CR_TCEN       0x00000008	/* Timeout Counter Enable */
  #define QUADSPI_CR_SSHIFT     0x00000010	/* Sample Shift */
  #define QUADSPI_CR_FTHRES     0x00000F00	/* FTHRES[3:0] FIFO Level */
  #define QUADSPI_CR_TEIE       0x00010000	/* Transfer Error Interrupt Enable */
  #define QUADSPI_CR_TCIE       0x00020000	/* Transfer Complete Interrupt Enable */
  #define QUADSPI_CR_FTIE       0x00040000	/* FIFO Threshold Interrupt Enable */
  #define QUADSPI_CR_SMIE       0x00080000	/* Status Match Interrupt Enable */
  #define QUADSPI_CR_TOIE       0x00100000	/* TimeOut Interrupt Enable */
  #define QUADSPI_CR_APMS       0x00400000	/* Automatic Polling Mode Stop */
  #define QUADSPI_CR_PMM        0x00800000	/* Polling Match Mode */
  #define QUADSPI_CR_PRESCALER  0xFF000000	/* PRESCALER[7:0] Clock prescaler */
#define TOFF_QUADSPI_DCR    0x0004		/* (RW) QUADSPI Device Configuration register */
  #define QUADSPI_DCR_CKMODE    0x00000001	/* Mode 0 / Mode 3 */
  #define QUADSPI_DCR_CSHT      0x00000700	/* CSHT[2:0]: ChipSelect High Time */
  #define QUADSPI_DCR_CSHT_0    0x00000100
  #define QUADSPI_DCR_CSHT_1    0x00000200
  #define QUADSPI_DCR_CSHT_2    0x00000400
  #define QUADSPI_DCR_FSIZE     0x001F0000	/* FSIZE[4:0]: Flash Size */
#define TOFF_QUADSPI_SR     0x0008		/* (RW) QUADSPI Status register */
  #define QUADSPI_SR_TEF        0x00000001	/* Transfer Error Flag */
  #define QUADSPI_SR_TCF        0x00000002	/* Transfer Complete Flag */
  #define QUADSPI_SR_FTF        0x00000004	/* FIFO Threshlod Flag */
  #define QUADSPI_SR_SMF        0x00000008	/* Status Match Flag */
  #define QUADSPI_SR_TOF        0x00000010	/* Timeout Flag */
  #define QUADSPI_SR_BUSY       0x00000020	/* Busy */
  #define QUADSPI_SR_FLEVEL     0x00001F00	/* FIFO Threshlod Flag */
#define TOFF_QUADSPI_FCR    0x000C		/* (W)  QUADSPI Flag Clear register */
  #define QUADSPI_FCR_CTEF      0x00000001	/* Clear Transfer Error Flag */
  #define QUADSPI_FCR_CTCF      0x00000002	/* Clear Transfer Complete Flag */
  #define QUADSPI_FCR_CSMF      0x00000008	/* Clear Status Match Flag */
  #define QUADSPI_FCR_CTOF      0x00000010	/* Clear Timeout Flag */
#define TOFF_QUADSPI_DLR    0x0010		/* (RW) QUADSPI Data Length register */
#define TOFF_QUADSPI_CCR    0x0014		/* (RW) QUADSPI Communication Configuration register */
  #define QUADSPI_CCR_INSTRUCTION 0x000000FF	/* INSTRUCTION[7:0]: Instruction */
  #define QUADSPI_CCR_IMODE     0x00000300	/* IMODE[1:0]: Instruction Mode */
  #define QUADSPI_CCR_IMODE_0   0x00000100
  #define QUADSPI_CCR_IMODE_1   0x00000200
  #define QUADSPI_CCR_ADMODE    0x00000C00	/* ADMODE[1:0]: Address Mode */
  #define QUADSPI_CCR_ADMODE_0  0x00000400
  #define QUADSPI_CCR_ADMODE_1  0x00000800
  #define QUADSPI_CCR_ADSIZE    0x00003000	/* ADSIZE[1:0]: Address Size */
  #define QUADSPI_CCR_ADSIZE_0  0x00001000
  #define QUADSPI_CCR_ADSIZE_1  0x00002000
  #define QUADSPI_CCR_ABMODE    0x0000C000	/* ABMODE[1:0]: Alternate Bytes Mode */
  #define QUADSPI_CCR_ABMODE_0  0x00004000
  #define QUADSPI_CCR_ABMODE_1  0x00008000
  #define QUADSPI_CCR_ABSIZE    0x00030000	/* ABSIZE[1:0]: Instruction Mode */
  #define QUADSPI_CCR_ABSIZE_0  0x00010000
  #define QUADSPI_CCR_ABSIZE_1  0x00020000
  #define QUADSPI_CCR_DCYC      0x007C0000	/* DCYC[4:0]: Dummy Cycles */
  #define QUADSPI_CCR_DMODE     0x03000000	/* DMODE[1:0]: Data Mode */
  #define QUADSPI_CCR_DMODE_0   0x01000000
  #define QUADSPI_CCR_DMODE_1   0x02000000
  #define QUADSPI_CCR_FMODE     0x0C000000	/* FMODE[1:0]: Functional Mode */
  #define QUADSPI_CCR_FMODE_0   0x04000000
  #define QUADSPI_CCR_FMODE_1   0x08000000
  #define QUADSPI_CCR_SIOO      0x10000000	/* SIOO: Send Instruction Only Once Mode */
  #define QUADSPI_CCR_DDRM      0x80000000	/* DDRM: Double Data Rate Mode */
#define TOFF_QUADSPI_AR     0x0018		/* (RW) QUADSPI Address register */
#define TOFF_QUADSPI_ABR    0x001C		/* (RW) QUADSPI Alternate Bytes register */
#define TOFF_QUADSPI_DR     0x0020		/* (RW) QUADSPI Data register */
#define TOFF_QUADSPI_PSMKR  0x0024		/* (RW) QUADSPI Polling Status Mask register */
#define TOFF_QUADSPI_PSMAR  0x0028		/* (RW) QUADSPI Polling Status Match register */
#define TOFF_QUADSPI_PIR    0x002C		/* (RW) QUADSPI Polling Interval register */
  #define QUADSPI_PIR_INTERVAL  0x0000FFFF	/* INTERVAL[15:0]: Polling Interval */
#define TOFF_QUADSPI_LPTR   0x0030		/* (RW) QUADSPI Low Power Timeout register */
  #define QUADSPI_LPTR_TIMEOUT  0x0000FFFF	/* TIMEOUT[15:0]: Timeout period */


/*
 *  DEBUG MCU
 */
#define TADR_DBGMCU_BASE    (DBGMCU_BASE)
#define TOFF_DBGMCU_IDCODE  0x0000		/* (RW) MCU device ID code */
#define TOFF_DBGMCU_CR      0x0004		/* (RW) Debug MCU configuration register */
  #define DBGMCU_CR_DBG_SLEEP    0x00000001
  #define DBGMCU_CR_DBG_STOP     0x00000002
  #define DBGMCU_CR_DBG_STANDBY  0x00000004
  #define DBGMCU_CR_TRACE_IOEN   0x00000020
  #define DBGMCU_CR_TRGOEN       0x10000000
#define TOFF_DBGMCU_APB1FZR1   0x003C	/* (RW) Debug MCU CPU1 APB1 freeze register */
#define TOFF_DBGMCU_C2APB1FZR1 0x0040	/* (RW) Debug MCU CPU2 APB1 freeze register */
#define TOFF_DBGMCU_APB1FZR2   0x0044	/* (RW) Debug MCU CPU1 APB1 freeze register */
#define TOFF_DBGMCU_C2APB1FZR2 0x0048	/* (RW) Debug MCU CPU2 APB1 freeze register */
#define TOFF_DBGMCU_APB2FZR    0x004C	/* (RW) Debug MCU CPU1 APB2 freeze register */
#define TOFF_DBGMCU_C2APB2FZR  0x0050	/* (RW) Debug MCU CPU2 APB2 freeze register */


#endif  /* _STM32WBXX_H_ */

