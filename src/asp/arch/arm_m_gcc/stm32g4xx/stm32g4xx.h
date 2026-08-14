/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2015-2016 by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *  Copyright (C) 2017-2019 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: stm32g4xx.h,v 1.1 2019/12/18 17:43:59 roi Exp $
 */

#ifndef _STM32G4XX_H_
#define _STM32G4XX_H_

#include <sil.h>
#include "cmsis_m4.h"

/*
 *  割込み番号の最大値
 */
#define TMAX_INTNO          (16 + 102)

/*
 *  割込み優先度のビット幅
 */
#define TBITW_IPRI          4

/*
 *  INTERRUPT NUMBER
 */
#define IRQ_VECTOR_WWDG             (16 + 0)	/* Window WatchDog Interrupt */
#define IRQ_VECTOR_PVD_PVM          (16 + 1)	/* PVD/PVM1/PVM2/PVM3/PVM4 through EXTI Line detection Interrupts */
#define IRQ_VECTOR_RTC_TAMP_LSECSS  (16 + 2)	/* Tamper and TimeStamp interrupts through the EXTI line */
#define IRQ_VECTOR_RTC_WKUP         (16 + 3)	/* RTC Wakeup interrupt through the EXTI line */
#define IRQ_VECTOR_FLASH            (16 + 4)	/* FLASH global Interrupt */
#define IRQ_VECTOR_RCC              (16 + 5)	/* RCC global Interrupt */
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
#define IRQ_VECTOR_ADC1_2           (16 + 18)	/* ADC1, ADC2 SAR global Interrupts */
#define IRQ_VECTOR_USB_HP           (16 + 19)	/* USB HP Interrupt */
#define IRQ_VECTOR_USB_LP           (16 + 20)	/* USB LP Interrupt */
#define IRQ_VECTOR_FDCAN1_IT0       (16 + 21)	/* FDCAN1 IT0 Interrupt */
#define IRQ_VECTOR_FDCAN1_IT1       (16 + 22)	/* FDCAN1 IT1 Interrupt */
#define IRQ_VECTOR_EXTI9_5          (16 + 23)	/* External Line[9:5] Interrupts */
#define IRQ_VECTOR_TIM1_BRK_TIM9    (16 + 24)	/* TIM1 Break interrupt and TIM9 global interrupt */
#define IRQ_VECTOR_TIM1_UP_TIM10    (16 + 25)	/* TIM1 Update Interrupt and TIM10 global interrupt */
#define IRQ_VECTOR_TIM1_TRG_COM_TIM11 (16+26)	/* TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
#define IRQ_VECTOR_TIM1_CC          (16 + 27)	/* TIM1 Capture Compare Interrupt */
#define IRQ_VECTOR_TIM2             (16 + 28)	/* TIM2 global Interrupt */
#define IRQ_VECTOR_TIM3             (16 + 29)	/* TIM3 global Interrupt */
#define IRQ_VECTOR_TIM4             (16 + 30)	/* TIM4 global Interrupt */
#define IRQ_VECTOR_I2C1_EV          (16 + 31)	/* I2C1 Event Interrupt */
#define IRQ_VECTOR_I2C1_ER          (16 + 32)	/* I2C1 Error Interrupt */
#define IRQ_VECTOR_I2C2_EV          (16 + 33)	/* I2C2 Event Interrupt */
#define IRQ_VECTOR_I2C2_ER          (16 + 34)	/* I2C2 Error Interrupt */
#define IRQ_VECTOR_SPI1             (16 + 35)	/* SPI1 global Interrupt */
#define IRQ_VECTOR_SPI2             (16 + 36)	/* SPI2 global Interrupt */
#define IRQ_VECTOR_USART1           (16 + 37)	/* USART1 global Interrupt */
#define IRQ_VECTOR_USART2           (16 + 38)	/* USART2 global Interrupt */
#define IRQ_VECTOR_USART3           (16 + 39)	/* USART3 global Interrupt */
#define IRQ_VECTOR_EXTI15_10        (16 + 40)	/* External Line[15:10] Interrupts */
#define IRQ_VECTOR_RTC_ALARM        (16 + 41)	/* RTC Alarm (A and B) through EXTI Line Interrupt */
#define IRQ_VECTOR_USB_WAKEUP       (16 + 42)	/* USB Wakeup through EXTI line Interrupt */
#define IRQ_VECTOR_TIM8_BRK         (16 + 43)	/* TIM8 Break Interrupt */
#define IRQ_VECTOR_TIM8_UP          (16 + 44)	/* TIM8 Update Interrupt */
#define IRQ_VECTOR_TIM8_TRG_COM     (16 + 45)	/* TIM8 Trigger and Commutation Interrupt */
#define IRQ_VECTOR_TIM8_CC          (16 + 46)	/* TIM8 Capture Compare Interrupt */
#define IRQ_VECTOR_ADC3             (16 + 47)	/* ADC3 global Interrupt */
#define IRQ_VECTOR_FMC              (16 + 48)	/* FMC global Interrupt */
#define IRQ_VECTOR_LPTIM1           (16 + 49)	/* LP TIM1 Interrupt */
#define IRQ_VECTOR_TIM5             (16 + 50)	/* TIM5 global Interrupt */
#define IRQ_VECTOR_SPI3             (16 + 51)	/* SPI3 global Interrupt */
#define IRQ_VECTOR_UART4            (16 + 52)	/* UART4 global Interrupt */
#define IRQ_VECTOR_UART5            (16 + 53)	/* UART5 global Interrupt */
#define IRQ_VECTOR_TIM6_DAC         (16 + 54)	/* TIM6 global and DAC1&2 underrun error interrupts */
#define IRQ_VECTOR_TIM7_DAC         (16 + 55)	/* TIM7 global and DAC1&2 underrun error interrupts */
#define IRQ_VECTOR_DMA2_CH1         (16 + 56)	/* DMA2 Channel 1 global Interrupt */
#define IRQ_VECTOR_DMA2_CH2         (16 + 57)	/* DMA2 Channel 2 global Interrupt */
#define IRQ_VECTOR_DMA2_CH3         (16 + 58)	/* DMA2 Channel 3 global Interrupt */
#define IRQ_VECTOR_DMA2_CH4         (16 + 59)	/* DMA2 Channel 4 global Interrupt */
#define IRQ_VECTOR_DMA2_CH5         (16 + 60)	/* DMA2 Channel 5 global Interrupt */
#define IRQ_VECTOR_ADC4             (16 + 61)	/* ADC4 global Interrupt */
#define IRQ_VECTOR_ADC5             (16 + 62)	/* ADC5 global Interrupt */
#define IRQ_VECTOR_UCPD1            (16 + 63)	/* UCPD global Interrupt */
#define IRQ_VECTOR_COMP1_2_3        (16 + 64)	/* COMP1, COMP2 and COMP3 Interrupts */
#define IRQ_VECTOR_COMP4_5_6        (16 + 65)	/* COMP4, COMP5 and COMP6 Interrupts */
#define IRQ_VECTOR_COMP7            (16 + 66)	/* COMP7 Interrupt */
#define IRQ_VECTOR_HRTIM1_MASTER    (16 + 67)	/* HRTIM Master Timer global Interrupt */
#define IRQ_VECTOR_HRTIM1_TIMA      (16 + 68)	/* HRTIM Timer A global Interrupt */
#define IRQ_VECTOR_HRTIM1_TIMB      (16 + 69)	/* HRTIM Timer B global Interrupt */
#define IRQ_VECTOR_HRTIM1_TIMC      (16 + 70)	/* HRTIM Timer C global Interrupt */
#define IRQ_VECTOR_HRTIM1_TIMD      (16 + 71)	/* HRTIM Timer D global Interrupt */
#define IRQ_VECTOR_HRTIM1_TIME      (16 + 72)	/* HRTIM Timer E global Interrupt */
#define IRQ_VECTOR_HRTIM1_FLT       (16 + 73)	/* HRTIM Fault global Interrupt */
#define IRQ_VECTOR_HRTIM1_TIMF      (16 + 74)	/* HRTIM Timer F global Interrupt */
#define IRQ_VECTOR_CRS              (16 + 75)	/* CRS global interrupt */
#define IRQ_VECTOR_SAI1             (16 + 76)	/* Serial Audio Interface global interrupt */
#define IRQ_VECTOR_TIM20_BRK        (16 + 77)	/* TIM20 Break, Transition error and Index error Interrupt */
#define IRQ_VECTOR_TIM20_UP         (16 + 78)	/* TIM20 Update interrupt */
#define IRQ_VECTOR_TIM20_TRG_COM    (16 + 79)	/* TIM20 Trigger, Commutation, Direction change and Index Interrupt */
#define IRQ_VECTOR_TIM20_CC         (16 + 80)	/* TIM20 Capture Compare interrupt */
#define IRQ_VECTOR_FPU              (16 + 81)	/* FPU global interrupt */
#define IRQ_VECTOR_I2C4_EV          (16 + 82)	/* I2C4 Event interrupt */
#define IRQ_VECTOR_I2C4_ER          (16 + 83)	/* I2C4 Error interrupt */
#define IRQ_VECTOR_SPI4             (16 + 84)	/* SPI4 Event interrupt */
#define IRQ_VECTOR_FDCAN2_IT0       (16 + 86)	/* FDCAN2 interrupt line 0 interrupt */
#define IRQ_VECTOR_FDCAN2_IT1       (16 + 87)	/* FDCAN2 interrupt line 1 interrupt */
#define IRQ_VECTOR_FDCAN3_IT0       (16 + 88)	/* FDCAN3 interrupt line 0 interrupt */
#define IRQ_VECTOR_FDCAN3_IT1       (16 + 89)	/* FDCAN3 interrupt line 1 interrupt */
#define IRQ_VECTOR_RNG              (16 + 90)	/* RNG global interrupt */
#define IRQ_VECTOR_LPUART1          (16 + 91)	/* LP UART 1 Interrupt */
#define IRQ_VECTOR_I2C3_EV          (16 + 92)	/* I2C3 Event Interrupt */
#define IRQ_VECTOR_I2C3_ER          (16 + 93)	/* I2C3 Error interrupt */
#define IRQ_VECTOR_DMAMUX_OVR       (16 + 94)	/* DMAMUX overrun global interrupt */
#define IRQ_VECTOR_QUADSPI          (16 + 95)	/* QUADSPI interrupt */
#define IRQ_VECTOR_DMA1_CH8         (16 + 96)	/* DMA1 Channel 8 interrupt */
#define IRQ_VECTOR_DMA2_CH6         (16 + 97)	/* DMA2 Channel 6 interrupt */
#define IRQ_VECTOR_DMA2_CH7         (16 + 98)	/* DMA2 Channel 7 interrupt */
#define IRQ_VECTOR_DMA2_CH8         (16 + 99)	/* DMA2 Channel 8 interrupt */
#define IRQ_VECTOR_CORDIC           (16 + 100)	/* CORDIC global Interrupt  */
#define IRQ_VECTOR_FMAC             (16 + 101)	/* FMAC global Interrupt */

/*
 *  PERIPHERAL MEMORY MAP
 */
#define FLASH_BASE          0x08000000	/* FLASH base address in the alias region */
#define SRAM_BASE           0x20000000	/* SRAM base address in the alias region */
#define PERIPH_BASE         0x40000000	/* Peripheral base address in the alias region */
#define FMC_BASE            0x60000000	/* FMC base address */
#define QSPI_BASE           0x90000000	/* QUADSPI memories accessible over AHB base address */


#define FMC_R_BASE          0xA0000000	/* FMC  control registers base address */
#define QSPI_R_BASE         0xA0001000	/* QUADSPI control registers base address */
#define PERIPH_BB_BASE      0x42000000	/* Peripheral base address in the bit-band region */

/* Peripheral memory map */
#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE     (PERIPH_BASE + 0x08000000)

/* Debug MCU registers base address */
#define DBGMCU_BASE         0xE0042000

/*
 *  TIMER
 */
#define TADR_TIM2_BASE      (APB1PERIPH_BASE + 0x0000)
#define TADR_TIM3_BASE      (APB1PERIPH_BASE + 0x0400)
#define TADR_TIM4_BASE      (APB1PERIPH_BASE + 0x0800)
#define TADR_TIM5_BASE      (APB1PERIPH_BASE + 0x0C00)
#define TADR_TIM6_BASE      (APB1PERIPH_BASE + 0x1000)
#define TADR_TIM7_BASE      (APB1PERIPH_BASE + 0x1400)
#define TADR_TIM1_BASE      (APB2PERIPH_BASE + 0x2C00)
#define TADR_TIM8_BASE      (APB2PERIPH_BASE + 0x3400)
#define TADR_TIM15_BASE     (APB2PERIPH_BASE + 0x4000)
#define TADR_TIM16_BASE     (APB2PERIPH_BASE + 0x4400)
#define TADR_TIM17_BASE     (APB2PERIPH_BASE + 0x4800)
#define TADR_TIM20_BASE     (APB2PERIPH_BASE + 0x5000)

#define TOFF_TIM_CR1        0x0000		/* (RW) TIM control register 1 */
  #define TIM_CR1_CEN        0x00000001	/* Counter enable */
  #define TIM_CR1_UDIS       0x00000002	/* Update disable */
  #define TIM_CR1_URS        0x00000004	/* Update request source */
  #define TIM_CR1_OPM        0x00000008	/* One pulse mode */
  #define TIM_CR1_DIR        0x00000010	/* Direction */
  #define TIM_CR1_CMS_0      0x00000020	/* CMS[1:0] bit 0 */
  #define TIM_CR1_CMS_1      0x00000040	/* CMS[1:0] bit 1 */
  #define TIM_CR1_ARPE       0x00000080	/* Auto-reload preload enable */
  #define TIM_CR1_CKD_0      0x00000100	/* CKD[1:0] bit 0 */
  #define TIM_CR1_CKD_1      0x00000200	/* CKD[1:0] bit 1 */
  #define TIM_CR1_UIFREMAP   0x00000800	/* Update interrupt flag remap */
  #define TIM_CR1_DITHEN     0x00001000	/* Dithering enable */
#define TOFF_TIM_CR2        0x0004		/* (RW) TIM control register 2 */
  #define TIM_CR2_CCPC       0x00000001	/* Capture/Compare Preloaded Control */
  #define TIM_CR2_CCUS       0x00000004	/* Capture/Compare Control Update Selection */
  #define TIM_CR2_CCDS       0x00000008	/* Capture/Compare DMA Selection */
  #define TIM_CR2_MMS        0x02000070	/* MMS[2:0] bits (Master Mode Selection) */
  #define TIM_CR2_MMS_0      0x00000010
  #define TIM_CR2_MMS_1      0x00000020
  #define TIM_CR2_MMS_2      0x00000040
  #define TIM_CR2_MMS_3      0x02000000
  #define TIM_CR2_TI1S       0x00000080	/* TI1 Selection */
  #define TIM_CR2_OIS1       0x00000100	/* Output Idle state 1 (OC1 output) */
  #define TIM_CR2_OIS1N      0x00000200	/* Output Idle state 1 (OC1N output) */
  #define TIM_CR2_OIS2       0x00000400	/* Output Idle state 2 (OC2 output) */
  #define TIM_CR2_OIS2N      0x00000800	/* Output Idle state 2 (OC2N output) */
  #define TIM_CR2_OIS3       0x00001000	/* Output Idle state 3 (OC3 output) */
  #define TIM_CR2_OIS3N      0x00002000	/* Output Idle state 3 (OC3N output) */
  #define TIM_CR2_OIS4       0x00004000	/* Output Idle state 4 (OC4 output) */
  #define TIM_CR2_OIS4N      0x00008000	/* Output Idle state 4 (OC4N output) */
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
  #define TIM_SMCR_SMSPE     0x02000000	/* SMS preload enable */
  #define TIM_SMCR_SMSPS     0x04000000	/* SMS preload source */
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
  #define TIM_DIER_IDXIE     0x00100000	/* Encoder index interrupt enable */
  #define TIM_DIER_DIRIE     0x00200000	/* Encoder direction change interrupt enable */
  #define TIM_DIER_IERRIE    0x00400000	/* Encoder index error enable */
  #define TIM_DIER_TERRIE    0x00800000	/* Encoder transition error enable */
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
  #define TIM_SR_IDXF        0x00100000	/* Encoder index interrupt flag */
  #define TIM_SR_DIRF        0x00200000	/* Encoder direction change interrupt flag */
  #define TIM_SR_IERRF       0x00400000	/* Encoder index error flag */
  #define TIM_SR_TERRF       0x00800000	/* Encoder transition error flag */
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
  #define TIM_CCER_CC4NE     0x00004000	/* Capture/Compare 4 Complementary output enable */
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
#define TOFF_TIM_CCR5       0x0048		/* (RW) TIM capture/compare register 5 */
  #define TIM_CCR5_CCR5      0xFFFFFFFF	/* Capture/Compare 5 Value */
  #define TIM_CCR5_GC5C1     0x20000000	/* Group Channel 5 and Channel 1 */
  #define TIM_CCR5_GC5C2     0x40000000	/* Group Channel 5 and Channel 2 */
  #define TIM_CCR5_GC5C3     0x80000000	/* Group Channel 5 and Channel 3 */
#define TOFF_TIM_CCR6       0x004C		/* (RW) TIM capture/compare register 6 */
  #define TIM_CCR6_CCR6      0x0000FFFF	/* Capture/Compare 6 Value */
#define TOFF_TIM_CCMR3      0x0050		/* (RW) TIM capture/compare mode register 3 */
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
#define TOFF_TIM_DTR2       0x0054		/* (RW) TIM deadtime register 2 */
  #define TIM_DTR2_DTGF      0x0000000F	/* DTGF[7:0] bits (Deadtime falling edge generator setup)*/
  #define TIM_DTR2_DTGF_0    0x00000001
  #define TIM_DTR2_DTGF_1    0x00000002
  #define TIM_DTR2_DTGF_2    0x00000004
  #define TIM_DTR2_DTGF_3    0x00000008
  #define TIM_DTR2_DTGF_4    0x00000010
  #define TIM_DTR2_DTGF_5    0x00000020
  #define TIM_DTR2_DTGF_6    0x00000040
  #define TIM_DTR2_DTGF_7    0x00000080
  #define TIM_DTR2_DTAE      0x00004000	/* Deadtime asymmetric enable */
  #define TIM_DTR2_DTPE      0x00008000	/* Deadtime prelaod enable */
#define TOFF_TIM_ECR        0x0058		/* (RW) TIM encoder control register */
  #define TIM_ECR_IE         0x00000001	/* Index enable */
  #define TIM_ECR_IDIR       0x00000006	/* IDIR[1:0] bits (Index direction)*/
  #define TIM_ECR_IDIR_0     0x00000001
  #define TIM_ECR_IDIR_1     0x00000002
  #define TIM_ECR_FIDX       0x00000020	/* First index enable */
  #define TIM_ECR_IPOS       0x000000C0	/* IPOS[1:0] bits (Index positioning)*/
  #define TIM_ECR_IPOS_0     0x00000040
  #define TIM_ECR_IPOS_1     0x00000080
  #define TIM_ECR            0x00FF0000	/* PW[7:0] bits (Pulse width)*/
  #define TIM_ECR_PW_0       0x00010000
  #define TIM_ECR_PW_1       0x00020000
  #define TIM_ECR_PW_2       0x00040000
  #define TIM_ECR_PW_3       0x00080000
  #define TIM_ECR_PW_4       0x00100000
  #define TIM_ECR_PW_5       0x00200000
  #define TIM_ECR_PW_6       0x00400000
  #define TIM_ECR_PW_7       0x00800000
  #define TIM_ECR_PWPRSC     0x07000000	/* PWPRSC[2:0] bits (Pulse width prescaler)*/
  #define TIM_ECR_PWPRSC_0   0x01000000
  #define TIM_ECR_PWPRSC_1   0x02000000
  #define TIM_ECR_PWPRSC_2   0x04000000
#define TOFF_TIM_TISEL      0x005C		/* (RW) TIM Input Selection register */
  #define TIM_TISEL_TI1SEL   0x0000000F	/* TI1SEL[3:0] bits (TIM1 TI1 SEL)*/
  #define TIM_TISEL_TI1SEL_0 0x00000001
  #define TIM_TISEL_TI1SEL_1 0x00000002
  #define TIM_TISEL_TI1SEL_2 0x00000004
  #define TIM_TISEL_TI1SEL_3 0x00000008
  #define TIM_TISEL_TI2SEL   0x00000F00	/* TI2SEL[3:0] bits (TIM1 TI2 SEL)*/
  #define TIM_TISEL_TI2SEL_0 0x00000100
  #define TIM_TISEL_TI2SEL_1 0x00000200
  #define TIM_TISEL_TI2SEL_2 0x00000400
  #define TIM_TISEL_TI2SEL_3 0x00000800
  #define TIM_TISEL_TI3SEL   0x000F0000	/* TI3SEL[3:0] bits (TIM1 TI3 SEL)*/
  #define TIM_TISEL_TI3SEL_0 0x00010000
  #define TIM_TISEL_TI3SEL_1 0x00020000
  #define TIM_TISEL_TI3SEL_2 0x00040000
  #define TIM_TISEL_TI3SEL_3 0x00080000
  #define TIM_TISEL_TI4SEL   0x0F000000	/* TI4SEL[3:0] bits (TIM1 TI4 SEL)*/
  #define TIM_TISEL_TI4SEL_0 0x01000000
  #define TIM_TISEL_TI4SEL_1 0x02000000
  #define TIM_TISEL_TI4SEL_2 0x04000000
  #define TIM_TISEL_TI4SEL_3 0x08000000
#define TOFF_TIM_AF1        0x0060		/* (RW) TIM alternate function option register 1 */
  #define TIM1_AF1_BKINE     0x00000001	/* BRK BKIN input enable */
  #define TIM1_AF1_BKCMP1E   0x00000002	/* BRK COMP1 enable */
  #define TIM1_AF1_BKCMP2E   0x00000004	/* BRK COMP2 enable */
  #define TIM1_AF1_BKCMP3E   0x00000008	/* BRK COMP3 enable */
  #define TIM1_AF1_BKCMP4E   0x00000010	/* BRK COMP4 enable */
  #define TIM1_AF1_BKCMP5E   0x00000020	/* BRK COMP5 enable */
  #define TIM1_AF1_BKCMP6E   0x00000040	/* BRK COMP6 enable */
  #define TIM1_AF1_BKCMP7E   0x00000080	/* BRK COMP7 enable */
  #define TIM1_AF1_BKINP     0x00000200	/* BRK BKIN input polarity */
  #define TIM1_AF1_BKCMP1P   0x00000400	/* BRK COMP1 input polarity */
  #define TIM1_AF1_BKCMP2P   0x00000800	/* BRK COMP2 input polarity */
  #define TIM1_AF1_BKCMP3P   0x00001000	/* BRK COMP3 input polarity */
  #define TIM1_AF1_BKCMP4P   0x00002000	/* BRK COMP4 input polarity */
  #define TIM1_AF1_ETRSEL    0x0003C000	/* ETRSEL[3:0] bits (TIM1 ETR source selection) */
  #define TIM1_AF1_ETRSEL_0  0x00004000
  #define TIM1_AF1_ETRSEL_1  0x00008000
  #define TIM1_AF1_ETRSEL_2  0x00010000
  #define TIM1_AF1_ETRSEL_3  0x00020000
#define TOFF_TIM_AF2        0x0064		/* (RW) TIM alternate function option register 2 */
  #define TIM1_AF2_BK2INE    0x00000001	/* BRK2 BKIN input enable */
  #define TIM1_AF2_BK2CMP1E  0x00000002	/* BRK2 COMP1 enable */
  #define TIM1_AF2_BK2CMP2E  0x00000004	/* BRK2 COMP2 enable */
  #define TIM1_AF2_BK2CMP3E  0x00000008	/* BRK2 COMP3 enable */
  #define TIM1_AF2_BK2CMP4E  0x00000010	/* BRK2 COMP4 enable */
  #define TIM1_AF2_BK2CMP5E  0x00000020	/* BRK2 COMP5 enable */
  #define TIM1_AF2_BK2CMP6E  0x00000040	/* BRK2 COMP6 enable */
  #define TIM1_AF2_BK2CMP7E  0x00000080	/* BRK2 COMP7 enable */
  #define TIM1_AF2_BK2INP    0x00000200	/* BRK2 BKIN input polarity */
  #define TIM1_AF2_BK2CMP1P  0x00000400	/* BRK2 COMP1 input polarity */
  #define TIM1_AF2_BK2CMP2P  0x00000800	/* BRK2 COMP2 input polarity */
  #define TIM1_AF2_BK2CMP3P  0x00000400	/* BRK2 COMP3 input polarity */
  #define TIM1_AF2_BK2CMP4P  0x00000800	/* BRK2 COMP4 input polarity */
  #define TIM1_AF2_OCRSEL    0x00070000	/* BRK2 COMP2 input polarity */
  #define TIM1_AF2_OCRSEL_0  0x00010000
  #define TIM1_AF2_OCRSEL_1  0x00020000
  #define TIM1_AF2_OCRSEL_2  0x00040000
#define TOFF_TIM_OR         0x0068		/* (RW) TIM option register */
  #define TIM_OR_HSE32EN     0x00000001	/* HSE/32 clock enable */
#define TOFF_TIM_DCR        0x03DC		/* (RW) TIM DMA control register */
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
#define TOFF_TIM_DMAR       0x03E0		/* (RW) TIM DMA address for full transfer */


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
 *  TAMPER AND BACKUP REGISTERS
 */
#define TADR_TAMP_BASE      (APB1PERIPH_BASE + 0x2400)
#define TOFF_TAMP_CR1       0x0000		/* (RW) TAMP configuration register 1 */
  #define TAMP_CR1_TAMP1E       0x00000001
  #define TAMP_CR1_TAMP2E       0x00000002
  #define TAMP_CR1_TAMP3E       0x00000004
  #define TAMP_CR1_ITAMP3E      0x00040000
  #define TAMP_CR1_ITAMP4E      0x00080000
  #define TAMP_CR1_ITAMP5E      0x00100000
  #define TAMP_CR1_ITAMP6E      0x00200000
#define TOFF_TAMP_CR2       0x0004		/* (RW) TAMP configuration register 2 */
  #define TAMP_CR2_TAMP1NOERASE 0x00000001
  #define TAMP_CR2_TAMP2NOERASE 0x00000002
  #define TAMP_CR2_TAMP3NOERASE 0x00000004
  #define TAMP_CR2_TAMP1MF      0x00010000
  #define TAMP_CR2_TAMP2MF      0x00020000
  #define TAMP_CR2_TAMP3MF      0x00040000
  #define TAMP_CR2_TAMP1TRG     0x01000000
  #define TAMP_CR2_TAMP2TRG     0x02000000
  #define TAMP_CR2_TAMP3TRG     0x04000000
#define TOFF_TAMP_FLTCR     0x000C		/* (RW) TAMP filter control register */
  #define TAMP_FLTCR_TAMPFREQ   0x00000007
  #define TAMP_FLTCR_TAMPFREQ_0 0x00000001
  #define TAMP_FLTCR_TAMPFREQ_1 0x00000002
  #define TAMP_FLTCR_TAMPFREQ_2 0x00000004
  #define TAMP_FLTCR_TAMPFLT    0x00000018
  #define TAMP_FLTCR_TAMPFLT_0  0x00000008
  #define TAMP_FLTCR_TAMPFLT_1  0x00000010
  #define TAMP_FLTCR_TAMPPRCH   0x00000060
  #define TAMP_FLTCR_TAMPPRCH_0 0x00000020
  #define TAMP_FLTCR_TAMPPRCH_1 0x00000040
  #define TAMP_FLTCR_TAMPPUDIS  0x00000080
#define TOFF_TAMP_IER       0x002C		/* (RW) TAMP Interrupt enable register */
  #define TAMP_IER_TAMP1IE      0x00000001
  #define TAMP_IER_TAMP2IE      0x00000002
  #define TAMP_IER_TAMP3IE      0x00000004
  #define TAMP_IER_ITAMP3IE     0x00040000
  #define TAMP_IER_ITAMP4IE     0x00080000
  #define TAMP_IER_ITAMP5IE     0x00100000
  #define TAMP_IER_ITAMP6IE     0x00200000
#define TOFF_TAMP_SR        0x0030		/* (RW) TAMP Status register */
  #define TAMP_SR_TAMP1F        0x00000001
  #define TAMP_SR_TAMP2F        0x00000002
  #define TAMP_SR_TAMP3F        0x00000004
  #define TAMP_SR_ITAMP3F       0x00040000
  #define TAMP_SR_ITAMP4F       0x00080000
  #define TAMP_SR_ITAMP5F       0x00100000
  #define TAMP_SR_ITAMP6F       0x00200000
#define TOFF_TAMP_MISR      0x0034		/* (RW) TAMP Masked Interrupt Status register */
  #define TAMP_MISR_TAMP1MF     0x00000001
  #define TAMP_MISR_TAMP2MF     0x00000002
  #define TAMP_MISR_TAMP3MF     0x00000004
  #define TAMP_MISR_ITAMP3MF    0x00040000
  #define TAMP_MISR_ITAMP4MF    0x00080000
  #define TAMP_MISR_ITAMP5MF    0x00100000
  #define TAMP_MISR_ITAMP6MF    0x00200000
#define TOFF_TAMP_SCR       0x003C		/* (RW) TAMP Status clear register */
  #define TAMP_SCR_CTAMP1F      0x00000001
  #define TAMP_SCR_CTAMP2F      0x00000002
  #define TAMP_SCR_CTAMP3F      0x00000004
  #define TAMP_SCR_CITAMP3F     0x00040000
  #define TAMP_SCR_CITAMP4F     0x00080000
  #define TAMP_SCR_CITAMP5F     0x00100000
  #define TAMP_SCR_CITAMP6F     0x00200000
#define TOFF_TAMP_BKP0R     0x0100		/* (RW) TAMP backup register 0 */
#define TOFF_TAMP_BKP1R     0x0104		/* (RW) TAMP backup register 1 */
#define TOFF_TAMP_BKP2R     0x0108		/* (RW) TAMP backup register 2 */
#define TOFF_TAMP_BKP3R     0x010C		/* (RW) TAMP backup register 3 */
#define TOFF_TAMP_BKP4R     0x0110		/* (RW) TAMP backup register 4 */
#define TOFF_TAMP_BKP5R     0x0114		/* (RW) TAMP backup register 5 */
#define TOFF_TAMP_BKP6R     0x0118		/* (RW) TAMP backup register 6 */
#define TOFF_TAMP_BKP7R     0x011C		/* (RW) TAMP backup register 7 */
#define TOFF_TAMP_BKP8R     0x0120		/* (RW) TAMP backup register 8 */
#define TOFF_TAMP_BKP9R     0x0124		/* (RW) TAMP backup register 9 */
#define TOFF_TAMP_BKP10R    0x0128		/* (RW) TAMP backup register 10 */
#define TOFF_TAMP_BKP11R    0x012C		/* (RW) TAMP backup register 11 */
#define TOFF_TAMP_BKP12R    0x0130		/* (RW) TAMP backup register 12 */
#define TOFF_TAMP_BKP13R    0x0134		/* (RW) TAMP backup register 13 */
#define TOFF_TAMP_BKP14R    0x0138		/* (RW) TAMP backup register 14 */
#define TOFF_TAMP_BKP15R    0x013C		/* (RW) TAMP backup register 15 */
#define TOFF_TAMP_BKP16R    0x0140		/* (RW) TAMP backup register 16 */
#define TOFF_TAMP_BKP17R    0x0144		/* (RW) TAMP backup register 17 */
#define TOFF_TAMP_BKP18R    0x0148		/* (RW) TAMP backup register 18 */
#define TOFF_TAMP_BKP19R    0x014C		/* (RW) TAMP backup register 19 */
#define TOFF_TAMP_BKP20R    0x0150		/* (RW) TAMP backup register 20 */
#define TOFF_TAMP_BKP21R    0x0154		/* (RW) TAMP backup register 21 */
#define TOFF_TAMP_BKP22R    0x0158		/* (RW) TAMP backup register 22 */
#define TOFF_TAMP_BKP23R    0x015C		/* (RW) TAMP backup register 23 */
#define TOFF_TAMP_BKP24R    0x0160		/* (RW) TAMP backup register 24 */
#define TOFF_TAMP_BKP25R    0x0164		/* (RW) TAMP backup register 25 */
#define TOFF_TAMP_BKP26R    0x0168		/* (RW) TAMP backup register 26 */
#define TOFF_TAMP_BKP27R    0x016C		/* (RW) TAMP backup register 27 */
#define TOFF_TAMP_BKP28R    0x0170		/* (RW) TAMP backup register 28 */
#define TOFF_TAMP_BKP29R    0x0174		/* (RW) TAMP backup register 29 */
#define TOFF_TAMP_BKP30R    0x0178		/* (RW) TAMP backup register 30 */
#define TOFF_TAMP_BKP31R    0x017C		/* (RW) TAMP backup register 31 */

/*
 *  REAL-TIME CLOCK
 */
#define TADR_RTC_BASE       (APB1PERIPH_BASE + 0x2800)
#define TOFF_RTC_TR         0x0000		/* (RW) RTC time register */
  #define RTC_TR_SU                0x0000000F
  #define RTC_TR_SU_0              0x00000001
  #define RTC_TR_SU_1              0x00000002
  #define RTC_TR_SU_2              0x00000004
  #define RTC_TR_SU_3              0x00000008
  #define RTC_TR_ST                0x00000070
  #define RTC_TR_ST_0              0x00000010
  #define RTC_TR_ST_1              0x00000020
  #define RTC_TR_ST_2              0x00000040
  #define RTC_TR_MNU               0x00000F00
  #define RTC_TR_MNU_0             0x00000100
  #define RTC_TR_MNU_1             0x00000200
  #define RTC_TR_MNU_2             0x00000400
  #define RTC_TR_MNU_3             0x00000800
  #define RTC_TR_MNT               0x00007000
  #define RTC_TR_MNT_0             0x00001000
  #define RTC_TR_MNT_1             0x00002000
  #define RTC_TR_MNT_2             0x00004000
  #define RTC_TR_HU                0x000F0000
  #define RTC_TR_HU_0              0x00010000
  #define RTC_TR_HU_1              0x00020000
  #define RTC_TR_HU_2              0x00040000
  #define RTC_TR_HU_3              0x00080000
  #define RTC_TR_HT                0x00300000
  #define RTC_TR_HT_0              0x00100000
  #define RTC_TR_HT_1              0x00200000
  #define RTC_TR_PM                0x00400000
#define TOFF_RTC_DR         0x0004		/* (RW) RTC date register */
  #define RTC_DR_DU                0x0000000F
  #define RTC_DR_DU_0              0x00000001
  #define RTC_DR_DU_1              0x00000002
  #define RTC_DR_DU_2              0x00000004
  #define RTC_DR_DU_3              0x00000008
  #define RTC_DR_DT                0x00000030
  #define RTC_DR_DT_0              0x00000010
  #define RTC_DR_DT_1              0x00000020
  #define RTC_DR_MU                0x00000F00
  #define RTC_DR_MU_0              0x00000100
  #define RTC_DR_MU_1              0x00000200
  #define RTC_DR_MU_2              0x00000400
  #define RTC_DR_MU_3              0x00000800
  #define RTC_DR_WDU               0x0000E000
  #define RTC_DR_WDU_0             0x00002000
  #define RTC_DR_WDU_1             0x00004000
  #define RTC_DR_WDU_2             0x00008000
  #define RTC_DR_MT                0x00001000
  #define RTC_DR_YU                0x000F0000
  #define RTC_DR_YU_0              0x00010000
  #define RTC_DR_YU_1              0x00020000
  #define RTC_DR_YU_2              0x00040000
  #define RTC_DR_YU_3              0x00080000
  #define RTC_DR_YT                0x00F00000
  #define RTC_DR_YT_0              0x00100000
  #define RTC_DR_YT_1              0x00200000
  #define RTC_DR_YT_2              0x00400000
  #define RTC_DR_YT_3              0x00800000
#define TOFF_RTC_SSR        0x0008		/* (RW) RTC sub second register */
#define TOFF_RTC_ICSR       0x000C		/* (RW) RTC initialization control and status register */
  #define RTC_ICSR_ALRAWF          0x00000001
  #define RTC_ICSR_ALRBWF          0x00000002
  #define RTC_ICSR_WUTWF           0x00000004
  #define RTC_ICSR_SHPF            0x00000008
  #define RTC_ICSR_INITS           0x00000010
  #define RTC_ICSR_RSF             0x00000020
  #define RTC_ICSR_INITF           0x00000040
  #define RTC_ICSR_INIT            0x00000080
  #define RTC_ICSR_RECALPF         0x00010000
#define TOFF_RTC_PRER       0x0010		/* (RW) RTC prescaler register */
  #define RTC_PRER_PREDIV_S        0x00007FFF
  #define RTC_PRER_PREDIV_A        0x007F0000
#define TOFF_RTC_WUTR       0x0014		/* (RW) RTC wakeup timer register */
#define TOFF_RTC_CR         0x0018		/* (RW) RTC control register */
  #define RTC_CR_WUCKSEL           0x00000007
  #define RTC_CR_WUCKSEL_0         0x00000001
  #define RTC_CR_WUCKSEL_1         0x00000002
  #define RTC_CR_WUCKSEL_2         0x00000004
  #define RTC_CR_TSEDGE            0x00000008
  #define RTC_CR_REFCKON           0x00000010
  #define RTC_CR_BYPSHAD           0x00000020
  #define RTC_CR_FMT               0x00000040
  #define RTC_CR_ALRAE             0x00000100
  #define RTC_CR_ALRBE             0x00000200
  #define RTC_CR_WUTE              0x00000400
  #define RTC_CR_TSE               0x00000800
  #define RTC_CR_ALRAIE            0x00001000
  #define RTC_CR_ALRBIE            0x00002000
  #define RTC_CR_WUTIE             0x00004000
  #define RTC_CR_TSIE              0x00008000
  #define RTC_CR_ADD1H             0x00010000
  #define RTC_CR_SUB1H             0x00020000
  #define RTC_CR_BKP               0x00040000
  #define RTC_CR_COSEL             0x00080000
  #define RTC_CR_POL               0x00100000
  #define RTC_CR_OSEL              0x00600000
  #define RTC_CR_OSEL_0            0x00200000
  #define RTC_CR_OSEL_1            0x00400000
  #define RTC_CR_COE               0x00800000
  #define RTC_CR_ITSE              0x01000000
  #define RTC_CR_TAMPTS            0x02000000	/* Activate timestamp on tamper detection event  */
  #define RTC_CR_TAMPOE            0x04000000	/* Tamper detection output enable on TAMPALARM  */
  #define RTC_CR_TAMPALRM_PU       0x20000000	/* TAMPALARM output pull-up config */
  #define RTC_CR_TAMPALRM_TYPE     0x40000000	/* TAMPALARM output type  */
  #define RTC_CR_OUT2EN            0x80000000	/* RTC_OUT2 output enable */
#define TOFF_RTC_WPR        0x0024		/* (RW) RTC write protection register */
  #define RTC_WPR_KEY              0x000000FF
#define TOFF_RTC_CALR       0x0028		/* (RW) RTC calibration register */
  #define RTC_CALR_CALM            0x000001FF
  #define RTC_CALR_CALM_0          0x00000001
  #define RTC_CALR_CALM_1          0x00000002
  #define RTC_CALR_CALM_2          0x00000004
  #define RTC_CALR_CALM_3          0x00000008
  #define RTC_CALR_CALM_4          0x00000010
  #define RTC_CALR_CALM_5          0x00000020
  #define RTC_CALR_CALM_6          0x00000040
  #define RTC_CALR_CALM_7          0x00000080
  #define RTC_CALR_CALM_8          0x00000100
  #define RTC_CALR_CALW16          0x00002000
  #define RTC_CALR_CALW8           0x00004000
  #define RTC_CALR_CALP            0x00008000
#define TOFF_RTC_SHIFTR     0x002C		/* (RW) RTC shift control register */
  #define RTC_SHIFTR_SUBFS         0x00007FFF
  #define RTC_SHIFTR_ADD1S         0x80000000
#define TOFF_RTC_TSTR       0x0030		/* (RW) RTC time stamp time register */
  #define RTC_TSTR_SU              0x0000000F
  #define RTC_TSTR_SU_0            0x00000001
  #define RTC_TSTR_SU_1            0x00000002
  #define RTC_TSTR_SU_2            0x00000004
  #define RTC_TSTR_SU_3            0x00000008
  #define RTC_TSTR_ST              0x00000070
  #define RTC_TSTR_ST_0            0x00000010
  #define RTC_TSTR_ST_1            0x00000020
  #define RTC_TSTR_ST_2            0x00000040
  #define RTC_TSTR_MNU             0x00000F00
  #define RTC_TSTR_MNU_0           0x00000100
  #define RTC_TSTR_MNU_1           0x00000200
  #define RTC_TSTR_MNU_2           0x00000400
  #define RTC_TSTR_MNU_3           0x00000800
  #define RTC_TSTR_MNT             0x00007000
  #define RTC_TSTR_MNT_0           0x00001000
  #define RTC_TSTR_MNT_1           0x00002000
  #define RTC_TSTR_MNT_2           0x00004000
  #define RTC_TSTR_HU              0x000F0000
  #define RTC_TSTR_HU_0            0x00010000
  #define RTC_TSTR_HU_1            0x00020000
  #define RTC_TSTR_HU_2            0x00040000
  #define RTC_TSTR_HU_3            0x00080000
  #define RTC_TSTR_HT              0x00300000
  #define RTC_TSTR_HT_0            0x00100000
  #define RTC_TSTR_HT_1            0x00200000
  #define RTC_TSTR_PM              0x00400000
#define TOFF_RTC_TSDR       0x0034		/* (RW) RTC time stamp date register */
  #define RTC_TSDR_DU              0x0000000F
  #define RTC_TSDR_DU_0            0x00000001
  #define RTC_TSDR_DU_1            0x00000002
  #define RTC_TSDR_DU_2            0x00000004
  #define RTC_TSDR_DU_3            0x00000008
  #define RTC_TSDR_DT              0x00000030
  #define RTC_TSDR_DT_0            0x00000010
  #define RTC_TSDR_DT_1            0x00000020
  #define RTC_TSDR_MU              0x00000F00
  #define RTC_TSDR_MU_0            0x00000100
  #define RTC_TSDR_MU_1            0x00000200
  #define RTC_TSDR_MU_2            0x00000400
  #define RTC_TSDR_MU_3            0x00000800
  #define RTC_TSDR_MT              0x00001000
  #define RTC_TSDR_WDU             0x0000E000
  #define RTC_TSDR_WDU_0           0x00002000
  #define RTC_TSDR_WDU_1           0x00004000
  #define RTC_TSDR_WDU_2           0x00008000
#define TOFF_RTC_TSSSR      0x0038		/* (RW) RTC time-stamp sub second register */
#define TOFF_RTC_ALRMAR     0x0040		/* (RW) RTC alarm A register */
  #define RTC_ALRMAR_SU            0x0000000F
  #define RTC_ALRMAR_SU_0          0x00000001
  #define RTC_ALRMAR_SU_1          0x00000002
  #define RTC_ALRMAR_SU_2          0x00000004
  #define RTC_ALRMAR_SU_3          0x00000008
  #define RTC_ALRMAR_ST            0x00000070
  #define RTC_ALRMAR_ST_0          0x00000010
  #define RTC_ALRMAR_ST_1          0x00000020
  #define RTC_ALRMAR_ST_2          0x00000040
  #define RTC_ALRMAR_MSK1          0x00000080
  #define RTC_ALRMAR_MNU           0x00000F00
  #define RTC_ALRMAR_MNU_0         0x00000100
  #define RTC_ALRMAR_MNU_1         0x00000200
  #define RTC_ALRMAR_MNU_2         0x00000400
  #define RTC_ALRMAR_MNU_3         0x00000800
  #define RTC_ALRMAR_MNT           0x00007000
  #define RTC_ALRMAR_MNT_0         0x00001000
  #define RTC_ALRMAR_MNT_1         0x00002000
  #define RTC_ALRMAR_MNT_2         0x00004000
  #define RTC_ALRMAR_MSK2          0x00008000
  #define RTC_ALRMAR_HU            0x000F0000
  #define RTC_ALRMAR_HU_0          0x00010000
  #define RTC_ALRMAR_HU_1          0x00020000
  #define RTC_ALRMAR_HU_2          0x00040000
  #define RTC_ALRMAR_HU_3          0x00080000
  #define RTC_ALRMAR_HT            0x00300000
  #define RTC_ALRMAR_HT_0          0x00100000
  #define RTC_ALRMAR_HT_1          0x00200000
  #define RTC_ALRMAR_PM            0x00400000
  #define RTC_ALRMAR_MSK3          0x00800000
  #define RTC_ALRMAR_DU            0x0F000000
  #define RTC_ALRMAR_DU_0          0x01000000
  #define RTC_ALRMAR_DU_1          0x02000000
  #define RTC_ALRMAR_DU_2          0x04000000
  #define RTC_ALRMAR_DU_3          0x08000000
  #define RTC_ALRMAR_DT            0x30000000
  #define RTC_ALRMAR_DT_0          0x10000000
  #define RTC_ALRMAR_DT_1          0x20000000
  #define RTC_ALRMAR_WDSEL         0x40000000
  #define RTC_ALRMAR_MSK4          0x80000000
#define TOFF_RTC_ALRMASSR   0x0044		/* (RW) RTC alarm A sub second register */
  #define RTC_ALRMASSR_SS          0x00007FFF
  #define RTC_ALRMASSR_MASKSS      0x0F000000
  #define RTC_ALRMASSR_MASKSS_0    0x01000000
  #define RTC_ALRMASSR_MASKSS_1    0x02000000
  #define RTC_ALRMASSR_MASKSS_2    0x04000000
  #define RTC_ALRMASSR_MASKSS_3    0x08000000
#define TOFF_RTC_ALRMBR     0x0048		/* (RW) RTC alarm B register */
  #define RTC_ALRMBR_SU            0x0000000F
  #define RTC_ALRMBR_SU_0          0x00000001
  #define RTC_ALRMBR_SU_1          0x00000002
  #define RTC_ALRMBR_SU_2          0x00000004
  #define RTC_ALRMBR_SU_3          0x00000008
  #define RTC_ALRMBR_ST            0x00000070
  #define RTC_ALRMBR_ST_0          0x00000010
  #define RTC_ALRMBR_ST_1          0x00000020
  #define RTC_ALRMBR_ST_2          0x00000040
  #define RTC_ALRMBR_MSK1          0x00000080
  #define RTC_ALRMBR_MNU           0x00000F00
  #define RTC_ALRMBR_MNU_0         0x00000100
  #define RTC_ALRMBR_MNU_1         0x00000200
  #define RTC_ALRMBR_MNU_2         0x00000400
  #define RTC_ALRMBR_MNU_3         0x00000800
  #define RTC_ALRMBR_MNT           0x00007000
  #define RTC_ALRMBR_MNT_0         0x00001000
  #define RTC_ALRMBR_MNT_1         0x00002000
  #define RTC_ALRMBR_MNT_2         0x00004000
  #define RTC_ALRMBR_MSK2          0x00008000
  #define RTC_ALRMBR_HU            0x000F0000
  #define RTC_ALRMBR_HU_0          0x00010000
  #define RTC_ALRMBR_HU_1          0x00020000
  #define RTC_ALRMBR_HU_2          0x00040000
  #define RTC_ALRMBR_HU_3          0x00080000
  #define RTC_ALRMBR_HT            0x00300000
  #define RTC_ALRMBR_HT_0          0x00100000
  #define RTC_ALRMBR_HT_1          0x00200000
  #define RTC_ALRMBR_PM            0x00400000
  #define RTC_ALRMBR_MSK3          0x00800000
  #define RTC_ALRMBR_DU            0x0F000000
  #define RTC_ALRMBR_DU_0          0x01000000
  #define RTC_ALRMBR_DU_1          0x02000000
  #define RTC_ALRMBR_DU_2          0x04000000
  #define RTC_ALRMBR_DU_3          0x08000000
  #define RTC_ALRMBR_DT            0x30000000
  #define RTC_ALRMBR_DT_0          0x10000000
  #define RTC_ALRMBR_DT_1          0x20000000
  #define RTC_ALRMBR_WDSEL         0x40000000
  #define RTC_ALRMBR_MSK4          0x80000000
#define TOFF_RTC_ALRMBSSR   0x004C		/* (RW) RTC alarm B sub second register */
  #define RTC_ALRMBSSR_SS          0x00007FFF
  #define RTC_ALRMBSSR_MASKSS      0x0F000000
  #define RTC_ALRMBSSR_MASKSS_0    0x01000000
  #define RTC_ALRMBSSR_MASKSS_1    0x02000000
  #define RTC_ALRMBSSR_MASKSS_2    0x04000000
  #define RTC_ALRMBSSR_MASKSS_3    0x08000000
#define TOFF_RTC_SR         0x0050		/* (RW) RTC Status register */
  #define RTC_SR_ALRAF             0x00000001
  #define RTC_SR_ALRBF             0x00000002
  #define RTC_SR_WUTF              0x00000004
  #define RTC_SR_TSF               0x00000008
  #define RTC_SR_TSOVF             0x00000010
  #define RTC_SR_ITSF              0x00000020
#define TOFF_RTC_MISR       0x0054		/* (RW) RTC Masked Interrupt Status register */
  #define RTC_MISR_ALRAMF          0x00000001
  #define RTC_MISR_ALRBMF          0x00000002
  #define RTC_MISR_WUTMF           0x00000004
  #define RTC_MISR_TSMF            0x00000008
  #define RTC_MISR_TSOVMF          0x00000010
  #define RTC_MISR_ITSMF           0x00000020
#define TOFF_RTC_SCR        0x005C		/* (RW) RTC Status Clear register */
  #define RTC_SCR_CALRAF           0x00000001
  #define RTC_SCR_CALRBF           0x00000002
  #define RTC_SCR_CWUTF            0x00000004
  #define RTC_SCR_CTSF             0x00000008
  #define RTC_SCR_CTSOVF           0x00000010
  #define RTC_SCR_CITSF            0x00000020


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
  #define WWDG_CFR_EWI        0x00000200	/* Early Wakeup Interrupt */
  #define WWDG_CFR_WDGTB      0x00003800	/* WDGTB[2:0] bits (Timer Base) */
  #define WWDG_CFR_WDGTB_0    0x00000800
  #define WWDG_CFR_WDGTB_1    0x00001000
  #define WWDG_CFR_WDGTB_2    0x00002000
  #define WWDG_CFR_WDGTB0     WWDG_CFR_WDGTB_0
  #define WWDG_CFR_WDGTB1     WWDG_CFR_WDGTB_1
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
  #define IWDG_RLR_RL         0x00000FFF	/* Watchdog counter reload value */
#define TOFF_IWDG_SR        0x000C		/* (RW) IWDG Status register */
  #define IWDG_SR_PVU         0x00000001	/* Watchdog prescaler value update */
  #define IWDG_SR_RVU         0x00000002	/* Watchdog counter reload value update */
  #define IWDG_SR_WVU         0x00000004	/* Watchdog counter window value update */
#define TOFF_IWDG_WINR      0x0010		/* (RW) IWDG Window register */
  #define IWDG_WINR_WIN       0x00000FFF	/* Watchdog counter window value */


/*
 *  SERIAL PERIPHERAL IINTERFACE
 */
#define TADR_SPI2_BASE      (APB1PERIPH_BASE + 0x3800)
#define TADR_SPI3_BASE      (APB1PERIPH_BASE + 0x3C00)
#define TADR_SPI1_BASE      (APB2PERIPH_BASE + 0x3000)
#define TADR_SPI4_BASE      (APB2PERIPH_BASE + 0x3C00)
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
  #define SPI_SR_CHSIDE            0x00000004	/* Channel side */
  #define SPI_SR_UDR               0x00000008	/* Underrun flag */
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
#define TOFF_SPI_I2SCFGR    0x001C		/* (RW) SPI_I2S configuration register */
  #define SPI_I2SCFGR_CHLEN        0x00000001	/* Channel length (number of bits per audio channel) */
  #define SPI_I2SCFGR_DATLEN       0x00000006	/* DATLEN[1:0] bits (Data length to be transferred) */
  #define SPI_I2SCFGR_DATLEN_0     0x00000002
  #define SPI_I2SCFGR_DATLEN_1     0x00000004
  #define SPI_I2SCFGR_CKPOL        0x00000008	/* steady state clock polarity */
  #define SPI_I2SCFGR_I2SSTD       0x00000030	/* I2SSTD[1:0] bits (I2S standard selection) */
  #define SPI_I2SCFGR_I2SSTD_0     0x00000010
  #define SPI_I2SCFGR_I2SSTD_1     0x00000020
  #define SPI_I2SCFGR_PCMSYNC      0x00000080	/* PCM frame synchronization */
  #define SPI_I2SCFGR_I2SCFG       0x00000300	/* I2SCFG[1:0] bits (I2S configuration mode) */
  #define SPI_I2SCFGR_I2SCFG_0     0x00000100
  #define SPI_I2SCFGR_I2SCFG_1     0x00000200
  #define SPI_I2SCFGR_I2SE         0x00000400	/* I2S Enable */
  #define SPI_I2SCFGR_I2SMOD       0x00000800	/* I2S mode selection */
  #define SPI_I2SCFGR_ASTRTEN      0x00001000	/* Asynchronous start enable */
#define TOFF_SPI_I2SPR      0x0020		/* (RW) SPI_I2S prescaler register */
  #define SPI_I2SPR_I2SDIV         0x000000FF	/* I2S Linear prescaler */
  #define SPI_I2SPR_ODD            0x00000100	/* Odd factor for the prescaler */
  #define SPI_I2SPR_MCKOE          0x00000200	/* Master Clock Output Enable */


/*
 *  UNIVERSAL SYNCHRONOUS ASYNCHORONOUS RECEIVER TRANSMITTER
 */
#define TADR_USART2_BASE    (APB1PERIPH_BASE + 0x4400)
#define TADR_USART3_BASE    (APB1PERIPH_BASE + 0x4800)
#define TADR_UART4_BASE     (APB1PERIPH_BASE + 0x4C00)
#define TADR_UART5_BASE     (APB1PERIPH_BASE + 0x5000)
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
  #define USART_CR1_TXFEIE   0x40000000	/* TXFIFO empty interrupt enable */
  #define USART_CR1_RXFFIE   0x80000000	/* RXFIFO Full interrupt enable */
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
  #define USART_CR3_TXFTIE   0x00800000	/* TXFIFO threshold interrupt enable */
  #define USART_CR3_TCBGTIE  0x01000000	/* Transmission Complete Before Guard Time Interrupt Enable */
  #define USART_CR3_RXFTCFG  0x0E000000	/* RXFIFO FIFO threshold configuration */
  #define USART_CR3_RXFTCFG_0 0x02000000
  #define USART_CR3_RXFTCFG_1 0x04000000
  #define USART_CR3_RXFTCFG_2 0x08000000
  #define USART_CR3_RXFTIE   0x10000000	/* RXFIFO threshold interrupt enable */
  #define USART_CR3_TXFTCFG  0xE0000000	/* TXFIFO threshold configuration */
  #define USART_CR3_TXFTCFG_0 0x20000000
  #define USART_CR3_TXFTCFG_1 0x40000000
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
  #define USART_ISR_TC       0x00000040	/* Transmission Complete */
  #define USART_ISR_TXE      0x00000080	/* Transmit Data Register Empty */
  #define USART_ISR_LBDF     0x00000100	/* LIN Break Detection Flag */
  #define USART_ISR_CTSIF    0x00000200	/* CTS interrupt flag */
  #define USART_ISR_CTS      0x00000400	/* CTS flag */
  #define USART_ISR_RTOF     0x00000800	/* Receiver Time Out */
  #define USART_ISR_EOBF     0x00001000	/* End Of Block Flag */
  #define USART_ISR_ABRE     0x00004000	/* Auto-Baud Rate Error */
  #define USART_ISR_ABRF     0x00008000	/* Auto-Baud Rate Flag */
  #define USART_ISR_BUSY     0x00010000	/* Busy Flag */
  #define USART_ISR_CMF      0x00020000	/* Character Match Flag */
  #define USART_ISR_SBKF     0x00040000	/* Send Break Flag */
  #define USART_ISR_RWU      0x00080000	/* Receive Wake Up from mute mode Flag */
  #define USART_ISR_WUF      0x00100000	/* Wake Up from stop mode Flag */
  #define USART_ISR_TEACK    0x00200000	/* Transmit Enable Acknowledge Flag */
  #define USART_ISR_REACK    0x00400000	/* Receive Enable Acknowledge Flag */
  #define USART_ISR_TXFE     0x00800000	/* TXFIFO Empty */
  #define USART_ISR_RXFF     0x01000000	/* RXFIFO Full */
  #define USART_ISR_TCBGT    0x02000000	/* Transmission Complete Before Guard Time completion */
  #define USART_ISR_RXFT     0x04000000	/* RXFIFO threshold flag */
  #define USART_ISR_TXFT     0x08000000	/* TXFIFO threshold flag */
#define TOFF_USART_ICR      0x0020		/* (RW) USART Interrupt flag Clear register */
  #define USART_ICR_PECF     0x00000001	/* Parity Error Clear Flag */
  #define USART_ICR_FECF     0x00000002	/* Framing Error Clear Flag */
  #define USART_ICR_NECF     0x00000004	/* Noise detected Clear Flag */
  #define USART_ICR_ORECF    0x00000008	/* OverRun Error Clear Flag */
  #define USART_ICR_IDLECF   0x00000010	/* IDLE line detected Clear Flag */
  #define USART_ICR_TXFECF   0x00000020	/* TXFIFO empty Clear flag */
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
 *  INTER-INTERATED CIRCUIT IINTERFACE
 */
#define TADR_I2C1_BASE      (APB1PERIPH_BASE + 0x5400)
#define TADR_I2C2_BASE      (APB1PERIPH_BASE + 0x5800)
#define TADR_I2C3_BASE      (APB1PERIPH_BASE + 0x7800)
#define TADR_I2C4_BASE      (APB1PERIPH_BASE + 0x8400)
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
 *  UNIVERSAL SERIAL BUS FULL SPEED DEVICE
 */
#define TADR_USB_BASE       (APB1PERIPH_BASE + 0x5C00)	/* USB_IP Peripheral Registers base address */
#define TADR_USB_PMAADDR    (APB1PERIPH_BASE + 0x6000)	/* USB_IP Packet Memory Area base address */
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
 *  FD CONTROLLER AREA NETWORK
 */
#define TADR_FDCAN_CONFIG_BASE  (APB1PERIPH_BASE + 0x6500)  /* FDCAN configuration registers base address */
#define TOFF_FDCAN_CONDIG_CKDIV 0x0000	/* FDCAN clock divider register */
  #define FDCAN_CKDIV_PDIV        0x0000000F	/* Input Clock Divider */

#define TADR_FDCAN1_BASE    (APB1PERIPH_BASE + 0x6400)
#define TADR_FDCAN2_BASE    (APB1PERIPH_BASE + 0x6800)
#define TADR_FDCAN3_BASE    (APB1PERIPH_BASE + 0x6C00)
#define TOFF_FDCAN_CREL     0x0000		/* (RW) FDCAN Core Release register */
  #define FDCAN_CREL_DAY      0x000000FF	/* Timestamp Day */
  #define FDCAN_CREL_MON      0x0000FF00	/* Timestamp Month */
  #define FDCAN_CREL_YEAR     0x000F0000	/* Timestamp Year */
  #define FDCAN_CREL_SUBSTEP  0x00F00000	/* Sub-step of Core release */
  #define FDCAN_CREL_STEP     0x0F000000	/* Step of Core release */
  #define FDCAN_CREL_REL      0xF0000000	/* Core release */
#define TOFF_FDCAN_ENDN     0x0004		/* (RW) FDCAN Endian register */
#define TOFF_FDCAN_DBTP     0x000C		/* (RW) FDCAN Data Bit Timing & Prescaler register */
  #define FDCAN_DBTP_DSJW     0x0000000F	/* Synchronization Jump Width */
  #define FDCAN_DBTP_DTSEG2   0x000000F0	/* Data time segment after sample point */
  #define FDCAN_DBTP_DTSEG1   0x00001F00	/* Data time segment before sample point   */
  #define FDCAN_DBTP_DBRP     0x001F0000	/* Data BIt Rate Prescaler */
  #define FDCAN_DBTP_TDC      0x00800000	/* Transceiver Delay Compensation */
#define TOFF_FDCAN_TEST     0x0010		/* (RW) FDCAN Test register */
  #define FDCAN_TEST_LBCK     0x00000010	/* Loop Back mode */
  #define FDCAN_TEST_TX       0x00000060	/* Control of Transmit Pin */
  #define FDCAN_TEST_RX       0x00000080	/* Receive Pin */
#define TOFF_FDCAN_RWD      0x0014		/* (RW) FDCAN RAM Watchdog register */
  #define FDCAN_RWD_WDC       0x000000FF	/* Watchdog configuration */
  #define FDCAN_RWD_WDV       0x0000FF00	/* Watchdog value */
#define TOFF_FDCAN_CCCR     0x0018		/* (RW) FDCAN CC Control register */
  #define FDCAN_CCCR_INIT     0x00000001	/* Initialization */
  #define FDCAN_CCCR_CCE      0x00000002	/* Configuration Change Enable */
  #define FDCAN_CCCR_ASM      0x00000004	/* ASM Restricted Operation Mode */
  #define FDCAN_CCCR_CSA      0x00000008	/* Clock Stop Acknowledge */
  #define FDCAN_CCCR_CSR      0x00000010	/* Clock Stop Request */
  #define FDCAN_CCCR_MON      0x00000020	/* Bus Monitoring Mode */
  #define FDCAN_CCCR_DAR      0x00000040	/* Disable Automatic Retransmission */
  #define FDCAN_CCCR_TEST     0x00000080	/* Test Mode Enable */
  #define FDCAN_CCCR_FDOE     0x00000100	/* FD Operation Enable */
  #define FDCAN_CCCR_BRSE     0x00000200	/* FDCAN Bit Rate Switching */
  #define FDCAN_CCCR_PXHD     0x00001000	/* Protocol Exception Handling Disable */
  #define FDCAN_CCCR_EFBI     0x00002000	/* Edge Filtering during Bus Integration */
  #define FDCAN_CCCR_TXP      0x00004000	/* Two CAN bit times Pause */
  #define FDCAN_CCCR_NISO     0x00008000	/* Non ISO Operation */
#define TOFF_FDCAN_NBTP     0x001C		/* (RW) FDCAN Nominal Bit Timing & Prescaler register */
  #define FDCAN_NBTP_NTSEG2   0x0000007F	/* Nominal Time segment after sample point  */
  #define FDCAN_NBTP_NTSEG1   0x0000FF00	/* Nominal Time segment before sample point */
  #define FDCAN_NBTP_NBRP     0x01FF0000	/* Bit Rate Prescaler */
  #define FDCAN_NBTP_NSJW     0xFE000000	/* Nominal (Re)Synchronization Jump Width */
#define TOFF_FDCAN_TSCC     0x0020		/* (RW) FDCAN Timestamp Counter Configuration register */
  #define FDCAN_TSCC_TSS      0x00000003	/* Timestamp Select */
  #define FDCAN_TSCC_TCP      0x000F0000	/* Timestamp Counter Prescaler */
#define TOFF_FDCAN_TSCV     0x0024		/* (RW) FDCAN Timestamp Counter Value register */
  #define FDCAN_TSCV_TSC      0x0000FFFF	/* Timestamp Counter */
#define TOFF_FDCAN_TOCC     0x0028		/* (RW) FDCAN Timeout Counter Configuration register */
  #define FDCAN_TOCC_ETOC     0x00000001	/* Enable Timeout Counter */
  #define FDCAN_TOCC_TOS      0x00000006	/* Timeout Select */
  #define FDCAN_TOCC_TOP      0xFFFF0000	/* Timeout Period */
#define TOFF_FDCAN_TOCV     0x002C		/* (RW) FDCAN Timeout Counter Value register */
  #define FDCAN_TOCV_TOC      0x0000FFFF	/* Timeout Counter */
#define TOFF_FDCAN_ECR      0x0040		/* (RW) FDCAN Error Counter register */
  #define FDCAN_ECR_TEC       0x000000FF	/* Transmit Error Counter */
  #define FDCAN_ECR_REC       0x00007F00	/* Receive Error Counter */
  #define FDCAN_ECR_RP        0x00008000	/* Receive Error Passive */
  #define FDCAN_ECR_CEL       0x00FF0000	/* CAN Error Logging */
#define TOFF_FDCAN_PSR      0x0044		/* (RW) FDCAN Protocol Status register */
  #define FDCAN_PSR_LEC       0x00000007	/* Last Error Code */
  #define FDCAN_PSR_ACT       0x00000018	/* Activity */
  #define FDCAN_PSR_EP        0x00000020	/* Error Passive */
  #define FDCAN_PSR_EW        0x00000040	/* Warning Status */
  #define FDCAN_PSR_BO        0x00000080	/* Bus_Off Status */
  #define FDCAN_PSR_DLEC      0x00000700	/* Data Last Error Code */
  #define FDCAN_PSR_RESI      0x00000800	/* ESI flag of last received FDCAN Message */
  #define FDCAN_PSR_RBRS      0x00001000	/* BRS flag of last received FDCAN Message */
  #define FDCAN_PSR_REDL      0x00002000	/* Received FDCAN Message */
  #define FDCAN_PSR_PXE       0x00004000	/* Protocol Exception Event */
  #define FDCAN_PSR_TDCV      0x007F0000	/* Transmitter Delay Compensation Value */
#define TOFF_FDCAN_TDCR     0x0048		/* (RW) FDCAN Transmitter Delay Compensation register */
  #define FDCAN_TDCR_TDCF     0x0000007F	/* Transmitter Delay Compensation Filter */
  #define FDCAN_TDCR_TDCO     0x00007F00	/* Transmitter Delay Compensation Offset */
#define TOFF_FDCAN_IR       0x0050		/* (RW) FDCAN Interrupt register */
  #define FDCAN_IR_RF0N       0x00000001	/* Rx FIFO 0 New Message */
  #define FDCAN_IR_RF0F       0x00000002	/* Rx FIFO 0 Full */
  #define FDCAN_IR_RF0L       0x00000004	/* Rx FIFO 0 Message Lost */
  #define FDCAN_IR_RF1N       0x00000008	/* Rx FIFO 1 New Message */
  #define FDCAN_IR_RF1F       0x00000010	/* Rx FIFO 1 Full */
  #define FDCAN_IR_RF1L       0x00000020	/* Rx FIFO 1 Message Lost */
  #define FDCAN_IR_HPM        0x00000040	/* High Priority Message */
  #define FDCAN_IR_TC         0x00000080	/* Transmission Completed */
  #define FDCAN_IR_TCF        0x00000100	/* Transmission Cancellation Finished */
  #define FDCAN_IR_TFE        0x00000200	/* Tx FIFO Empty */
  #define FDCAN_IR_TEFN       0x00000400	/* Tx Event FIFO New Entry */
  #define FDCAN_IR_TEFF       0x00000800	/* Tx Event FIFO Full */
  #define FDCAN_IR_TEFL       0x00001000	/* Tx Event FIFO Element Lost */
  #define FDCAN_IR_TSW        0x00002000	/* Timestamp Wraparound */
  #define FDCAN_IR_MRAF       0x00004000	/* Message RAM Access Failure */
  #define FDCAN_IR_TOO        0x00008000	/* Timeout Occurred */
  #define FDCAN_IR_ELO        0x00010000	/* Error Logging Overflow */
  #define FDCAN_IR_EP         0x00020000	/* Error Passive */
  #define FDCAN_IR_EW         0x00040000	/* Warning Status */
  #define FDCAN_IR_BO         0x00080000	/* Bus_Off Status */
  #define FDCAN_IR_WDI        0x00100000	/* Watchdog Interrupt */
  #define FDCAN_IR_PEA        0x00200000	/* Protocol Error in Arbitration Phase */
  #define FDCAN_IR_PED        0x00400000	/* Protocol Error in Data Phase */
  #define FDCAN_IR_ARA        0x00800000	/* Access to Reserved Address */
#define TOFF_FDCAN_IE       0x0054		/* (RW) FDCAN Interrupt Enable register */
  #define FDCAN_IE_RF0NE      0x00000001	/* Rx FIFO 0 New Message Enable */
  #define FDCAN_IE_RF0FE      0x00000002	/* Rx FIFO 0 Full Enable */
  #define FDCAN_IE_RF0LE      0x00000004	/* Rx FIFO 0 Message Lost Enable */
  #define FDCAN_IE_RF1NE      0x00000008	/* Rx FIFO 1 New Message Enable */
  #define FDCAN_IE_RF1FE      0x00000010	/* Rx FIFO 1 Full Enable */
  #define FDCAN_IE_RF1LE      0x00000020	/* Rx FIFO 1 Message Lost Enable */
  #define FDCAN_IE_HPME       0x00000040	/* High Priority Message Enable */
  #define FDCAN_IE_TCE        0x00000080	/* Transmission Completed Enable */
  #define FDCAN_IE_TCFE       0x00000100	/* Transmission Cancellation Finished Enable */
  #define FDCAN_IE_TFEE       0x00000200	/* Tx FIFO Empty Enable */
  #define FDCAN_IE_TEFNE      0x00000400	/* Tx Event FIFO New Entry Enable */
  #define FDCAN_IE_TEFFE      0x00000800	/* Tx Event FIFO Full Enable */
  #define FDCAN_IE_TEFLE      0x00001000	/* Tx Event FIFO Element Lost Enable */
  #define FDCAN_IE_TSWE       0x00002000	/* Timestamp Wraparound Enable */
  #define FDCAN_IE_MRAFE      0x00004000	/* Message RAM Access Failure Enable */
  #define FDCAN_IE_TOOE       0x00008000	/* Timeout Occurred Enable */
  #define FDCAN_IE_ELOE       0x00010000	/* Error Logging Overflow Enable */
  #define FDCAN_IE_EPE        0x00020000	/* Error Passive Enable */
  #define FDCAN_IE_EWE        0x00040000	/* Warning Status Enable */
  #define FDCAN_IE_BOE        0x00080000	/* Bus_Off Status Enable */
  #define FDCAN_IE_WDIE       0x00100000	/* Watchdog Interrupt Enable */
  #define FDCAN_IE_PEAE       0x00200000	/* Protocol Error in Arbitration Phase Enable*/
  #define FDCAN_IE_PEDE       0x00400000	/* Protocol Error in Data Phase Enable */
  #define FDCAN_IE_ARAE       0x00800000	/* Access to Reserved Address Enable */
#define TOFF_FDCAN_ILS      0x0058		/* (RW) FDCAN Interrupt Line Select register */
  #define FDCAN_ILS_RXFIFO0   0x00000001	/* Rx FIFO 0 Message Lost/Rx FIFO 0 is Full/Rx FIFO 0 Has New Message */
  #define FDCAN_ILS_RXFIFO1   0x00000002	/* Rx FIFO 1 Message Lost/Rx FIFO 1 is Full/Rx FIFO 1 Has New Message */
  #define FDCAN_ILS_SMSG      0x00000004	/* Transmission Cancellation Finished/Transmission Completed/High Priority Message */
  #define FDCAN_ILS_TFERR     0x00000008	/* Tx Event FIFO Element Lost/Tx Event FIFO Full/Tx Event FIFO New Entry/Tx FIFO Empty Interrupt Line */
  #define FDCAN_ILS_MISC      0x00000010	/* Timeout Occurred/Message RAM Access Failure/Timestamp Wraparound */
  #define FDCAN_ILS_BERR      0x00000020	/* Error Passive/Error Logging Overflow */
  #define FDCAN_ILS_PERR      0x00000040	/* Access to Reserved Address Line/Protocol Error in Data Phase Line/Protocol Error in Arbitration Phase Line */
											/* Watchdog Interrupt Line/Bus_Off Status/Warning Status */
#define TOFF_FDCAN_ILE      0x005C		/* (RW) FDCAN Interrupt Line Enable register */
  #define FDCAN_ILE_EINT0     0x00000001	/* Enable Interrupt Line 0 */
  #define FDCAN_ILE_EINT1     0x00000002	/* Enable Interrupt Line 1 */
#define TOFF_FDCAN_RXGFC    0x0080		/* (RW) FDCAN Global Filter Configuration register */
  #define FDCAN_RXGFC_RRFE    0x00000001	/* Reject Remote Frames Extended */
  #define FDCAN_RXGFC_RRFS    0x00000002	/* Reject Remote Frames Standard */
  #define FDCAN_RXGFC_ANFE    0x0000000C	/* Accept Non-matching Frames Extended */
  #define FDCAN_RXGFC_ANFS    0x00000030	/* Accept Non-matching Frames Standard */
  #define FDCAN_RXGFC_F1OM    0x00000100	/* FIFO 1 operation mode */
  #define FDCAN_RXGFC_F0OM    0x00000200	/* FIFO 0 operation mode */
  #define FDCAN_RXGFC_LSS     0x001F0000	/* List Size Standard */
  #define FDCAN_RXGFC_LSE     0x0F000000	/* List Size Extended */
#define TOFF_FDCAN_XIDAM    0x0084		/* (RW) FDCAN Extended ID AND Mask register */
  #define FDCAN_XIDAM_EIDM    0x1FFFFFFF	/* Extended ID Mask */
#define TOFF_FDCAN_HPMS     0x0088		/* (RW) FDCAN High Priority Message Status register */
  #define FDCAN_HPMS_BIDX     0x00000007	/* Buffer Index */
  #define FDCAN_HPMS_MSI      0x000000C0	/* Message Storage Indicator */
  #define FDCAN_HPMS_FIDX     0x00001F00	/* Filter Index */
  #define FDCAN_HPMS_FLST     0x00008000	/* Filter List */
#define TOFF_FDCAN_RXF0S    0x0090		/* (RW) FDCAN Rx FIFO 0 Status register */
  #define FDCAN_RXF0S_F0FL    0x0000000F	/* Rx FIFO 0 Fill Level */
  #define FDCAN_RXF0S_F0GI    0x00000300	/* Rx FIFO 0 Get Index */
  #define FDCAN_RXF0S_F0PI    0x00030000	/* Rx FIFO 0 Put Index */
  #define FDCAN_RXF0S_F0F     0x01000000	/* Rx FIFO 0 Full */
  #define FDCAN_RXF0S_RF0L    0x02000000	/* Rx FIFO 0 Message Lost */
#define TOFF_FDCAN_RXF0A    0x0094		/* (RW) FDCAN Rx FIFO 0 Acknowledge register */
  #define FDCAN_RXF0A_F0AI    0x00000007	/* Rx FIFO 0 Acknowledge Index */
#define TOFF_FDCAN_RXF1S    0x0098		/* (RW) FDCAN Rx FIFO 1 Status register */
  #define FDCAN_RXF1S_F1FL    0x0000000F	/* Rx FIFO 1 Fill Level */
  #define FDCAN_RXF1S_F1GI    0x00000300	/* Rx FIFO 1 Get Index */
  #define FDCAN_RXF1S_F1PI    0x00030000	/* Rx FIFO 1 Put Index */
  #define FDCAN_RXF1S_F1F     0x01000000	/* Rx FIFO 1 Full */
  #define FDCAN_RXF1S_RF1L    0x02000000	/* Rx FIFO 1 Message Lost */
#define TOFF_FDCAN_RXF1A    0x009C		/* (RW) FDCAN Rx FIFO 1 Acknowledge register */
  #define FDCAN_RXF1A_F1AI    0x00000007	/* Rx FIFO 1 Acknowledge Index */
#define TOFF_FDCAN_TXBC     0x00C0		/* (RW) FDCAN Tx Buffer Configuration register */
  #define FDCAN_TXBC_TFQM     0x01000000	/* Tx FIFO/Queue Mode */
#define TOFF_FDCAN_TXFQS    0x00C4		/* (RW) FDCAN Tx FIFO/Queue Status register */
  #define FDCAN_TXFQS_TFFL    0x00000007	/* Tx FIFO Free Level */
  #define FDCAN_TXFQS_TFGI    0x00000300	/* Tx FIFO Get Index */
  #define FDCAN_TXFQS_TFQPI   0x00030000	/* Tx FIFO/Queue Put Index */
  #define FDCAN_TXFQS_TFQF    0x00200000	/* Tx FIFO/Queue Full */
#define TOFF_FDCAN_TXBRP    0x00C8		/* (RW) FDCAN Tx Buffer Request Pending register */
  #define FDCAN_TXBRP_TRP     0x00000007	/* Transmission Request Pending */
#define TOFF_FDCAN_TXBAR    0x00CC		/* (RW) FDCAN Tx Buffer Add Request register */
  #define FDCAN_TXBAR_AR      0x00000007	/* Add Request */
#define TOFF_FDCAN_TXBCR    0x00D0		/* (RW) FDCAN Tx Buffer Cancellation Request register */
  #define FDCAN_TXBCR_CR      0x00000007	/* Cancellation Request */
#define TOFF_FDCAN_TXBTO    0x00D4		/* (RW) FDCAN Tx Buffer Transmission Occurred register */
  #define FDCAN_TXBTO_TO      0x00000007	/* Transmission Occurred */
#define TOFF_FDCAN_TXBCF    0x00D8		/* (RW) FDCAN Tx Buffer Cancellation Finished register */
  #define FDCAN_TXBCF_CF      0x00000007	/* Cancellation Finished */
#define TOFF_FDCAN_TXBTIE   0x00DC		/* (RW) FDCAN Tx Buffer Transmission Interrupt Enable register */
  #define FDCAN_TXBTIE_TIE    0x00000007	/* Transmission Interrupt Enable */
#define TOFF_FDCAN_TXBCIE   0x00E0		/* (RW) FDCAN Tx Buffer Cancellation Finished Interrupt Enable register */
  #define FDCAN_TXBCIE_CFIE   0x00000007	/* Cancellation Finished Interrupt Enable */
#define TOFF_FDCAN_TXEFS    0x00E4		/* (RW) FDCAN Tx Event FIFO Status register */
  #define FDCAN_TXEFS_EFFL    0x00000007	/* Event FIFO Fill Level */
  #define FDCAN_TXEFS_EFGI    0x00000300	/* Event FIFO Get Index */
  #define FDCAN_TXEFS_EFPI    0x00030000	/* Event FIFO Put Index */
  #define FDCAN_TXEFS_EFF     0x01000000	/* Event FIFO Full */
  #define FDCAN_TXEFS_TEFL    0x02000000	/* Tx Event FIFO Element Lost */
#define TOFF_FDCAN_TXEFA    0x00E8		/* (RW) FDCAN Tx Event FIFO Acknowledge register */
  #define FDCAN_TXEFA_EFAI    0x00000003	/* Event FIFO Acknowledge Index */


/*
 *  POWER CONTROL
 */
#define TADR_PWR_BASE       (APB1PERIPH_BASE + 0x7000)

#define TOFF_PWR_CR1        0x0000	/* (RW) PWR power control register 1 */
  #define PWR_CR1_LPMS          0x00000007	/* Low-power mode selection field */
  #define PWR_CR1_LPMS_STOP0    0x00000000	/* Stop 0 mode */
  #define PWR_CR1_LPMS_STOP1    0x00000001	/* Stop 1 mode */
  #define PWR_CR1_LPMS_STANDBY  0x00000003	/* Stand-by mode */
  #define PWR_CR1_LPMS_SHUTDOWN 0x00000004	/* Shut-down mode */
  #define PWR_CR1_DBP           0x00000100	/* Disable Back-up domain Protection */
  #define PWR_CR1_VOS           0x00000600	/* VOS[1:0] bits (Regulator voltage scaling output selection) */
  #define PWR_CR1_VOS_0         0x00000200
  #define PWR_CR1_VOS_1         0x00000400
  #define PWR_CR1_LPR           0x00004000	/* Regulator low-power mode */
#define TOFF_PWR_CR2        0x0004	/* (RW) PWR power control register 2 */
  #define PWR_CR2_PVDE          0x00000001	/* Power Voltage Detector Enable */
  #define PWR_CR2_PLS           0x0000000E	/* PVD level selection */
  #define PWR_CR2_PLS_LEV0      0x00000000	/* PVD level 0 */
  #define PWR_CR2_PLS_LEV1      0x00000002	/* PVD level 1 */
  #define PWR_CR2_PLS_LEV2      0x00000004	/* PVD level 2 */
  #define PWR_CR2_PLS_LEV3      0x00000006	/* PVD level 3 */
  #define PWR_CR2_PLS_LEV4      0x00000008	/* PVD level 4 */
  #define PWR_CR2_PLS_LEV5      0x0000000A	/* PVD level 5 */
  #define PWR_CR2_PLS_LEV6      0x0000000C	/* PVD level 6 */
  #define PWR_CR2_PLS_LEV7      0x0000000E	/* PVD level 7 */
  #define PWR_CR2_PVME          0x000000F0	/* PVM bits field */
  #define PWR_CR2_PVME1         0x00000010	/* PVM 1 Enable */
  #define PWR_CR2_PVME2         0x00000020	/* PVM 2 Enable */
  #define PWR_CR2_PVME3         0x00000040	/* PVM 3 Enable */
  #define PWR_CR2_PVME4         0x00000080	/* PVM 4 Enable */
#define TOFF_PWR_CR3        0x0008	/* (RW) PWR power control register 3 */
  #define PWR_CR3_EWUP          0x0000001F	/* Enable Wake-Up Pins  */
  #define PWR_CR3_EWUP1         0x00000001	/* Enable Wake-Up Pin 1 */
  #define PWR_CR3_EWUP2         0x00000002	/* Enable Wake-Up Pin 2 */
  #define PWR_CR3_EWUP3         0x00000004	/* Enable Wake-Up Pin 3 */
  #define PWR_CR3_EWUP4         0x00000008	/* Enable Wake-Up Pin 4 */
  #define PWR_CR3_EWUP5         0x00000010	/* Enable Wake-Up Pin 5 */
  #define PWR_CR3_RRS           0x00000100	/* SRAM2 Retention in Stand-by mode */
  #define PWR_CR3_APC           0x00000400	/* Apply pull-up and pull-down configuration */
  #define PWR_CR3_UCPD_STDBY    0x00002000	/* USB Type-C and Power Delivery standby mode. */
  #define PWR_CR3_UCPD_DBDIS    0x00004000	/* USB Type-C and Power Delivery Dead Battery disable. */
  #define PWR_CR3_EIWF          0x00008000	/* Enable Internal Wake-up line */
#define TOFF_PWR_CR4        0x000C	/* (RW) PWR power control register 4 */
  #define PWR_CR4_WP1           0x00000001	/* Wake-Up Pin 1 polarity */
  #define PWR_CR4_WP2           0x00000002	/* Wake-Up Pin 2 polarity */
  #define PWR_CR4_WP3           0x00000004	/* Wake-Up Pin 3 polarity */
  #define PWR_CR4_WP4           0x00000008	/* Wake-Up Pin 4 polarity */
  #define PWR_CR4_WP5           0x00000010	/* Wake-Up Pin 5 polarity */
  #define PWR_CR4_VBE           0x00000100	/* VBAT Battery charging Enable  */
  #define PWR_CR4_VBRS          0x00000200	/* VBAT Battery charging Resistor Selection */
#define TOFF_PWR_SR1        0x0010	/* (RW) PWR power status register 1 */
  #define PWR_SR1_WUF           0x0000001F	/* Wake-up Flags */
  #define PWR_SR1_WUF1          0x00000001	/* Wake-up Flag 1 */
  #define PWR_SR1_WUF2          0x00000002	/* Wake-up Flag 2 */
  #define PWR_SR1_WUF3          0x00000004	/* Wake-up Flag 3 */
  #define PWR_SR1_WUF4          0x00000008	/* Wake-up Flag 4 */
  #define PWR_SR1_WUF5          0x00000010	/* Wake-up Flag 5 */
  #define PWR_SR1_SBF           0x00000100	/* Stand-By Flag */
  #define PWR_SR1_WUFI          0x00008000	/* Wake-Up Flag Internal */
#define TOFF_PWR_SR2        0x0014	/* (RW) PWR power status register 2 */
  #define PWR_SR2_REGLPS        0x00000100	/* Low-power Regulator Started */
  #define PWR_SR2_REGLPF        0x00000200	/* Low-power Regulator Flag */
  #define PWR_SR2_VOSF          0x00000400	/* Voltage Scaling Flag */
  #define PWR_SR2_PVDO          0x00000800	/* Power Voltage Detector Output */
  #define PWR_SR2_PVMO1         0x00001000	/* Peripheral Voltage Monitoring Output 1 */
  #define PWR_SR2_PVMO2         0x00002000	/* Peripheral Voltage Monitoring Output 2 */
  #define PWR_SR2_PVMO3         0x00004000	/* Peripheral Voltage Monitoring Output 3 */
  #define PWR_SR2_PVMO4         0x00008000	/* Peripheral Voltage Monitoring Output 4 */
#define TOFF_PWR_SCR        0x0018	/* (RW) PWR power status reset register */
  #define PWR_SCR_CWUF          0x0000001F	/* Clear Wake-up Flags  */
  #define PWR_SCR_CWUF1         0x00000001	/* Clear Wake-up Flag 1 */
  #define PWR_SCR_CWUF2         0x00000002	/* Clear Wake-up Flag 2 */
  #define PWR_SCR_CWUF3         0x00000004	/* Clear Wake-up Flag 3 */
  #define PWR_SCR_CWUF4         0x00000008	/* Clear Wake-up Flag 4 */
  #define PWR_SCR_CWUF5         0x00000010	/* Clear Wake-up Flag 5 */
  #define PWR_SCR_CSBF          0x00000100	/* Clear Stand-By Flag */
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
#define TOFF_PWR_PUCRF      0x0048	/* (RW) Pull_up control register of portF */
#define TOFF_PWR_PDCRF      0x004C	/* (RW) Pull_Down control register of portF */
#define TOFF_PWR_PUCRG      0x0050	/* (RW) Pull_up control register of portG */
#define TOFF_PWR_PDCRG      0x0054	/* (RW) Pull_Down control register of portG */
#define TOFF_PWR_PUCRH      0x0058	/* (RW) Pull_up control register of portH */
#define TOFF_PWR_PDCRH      0x005C	/* (RW) Pull_Down control register of portH */
#define TOFF_PWR_CR5        0x0080	/* (RW) PWR power control register 5 */
  #define PWR_CR5_R1MODE        0x00000100	/* Range 1 normal mode */


/*
 *  LOW POWER TIMIMER
 */
#define TADR_LPTIM1_BASE    (APB1PERIPH_BASE + 0x7C00)
#define TOFF_LPTIM_ISR      0x0000		/* (RW) LPTIM Interrupt and Status register */
#define TOFF_LPTIM_ICR      0x0004		/* (RW) LPTIM Interrupt Clear register */
#define TOFF_LPTIM_IER      0x0008		/* (RW) LPTIM Interrupt Enable register */
#define TOFF_LPTIM_CFGR     0x000C		/* (RW) LPTIM Configuration register */
#define TOFF_LPTIM_CR       0x0010		/* (RW) LPTIM Control register */
#define TOFF_LPTIM_CMP      0x0014		/* (RW) LPTIM Compare register */
#define TOFF_LPTIM_ARR      0x0018		/* (RW) LPTIM Autoreload register */
#define TOFF_LPTIM_CNT      0x001C		/* (RW) LPTIM Counter register */
#define TOFF_LPTIM_OR       0x0020		/* (RW) LPTIM Option register */


/*
 *  UCPD
 */
#define TADR_UCPD1_BASE     (APB1PERIPH_BASE + 0xA000)
#define TOFF_UCPD_CFG1      0x0000		/* (RW) UCPD configuration register 1 */
  #define UCPD_CFG1_HBITCLKDIV    0x0000003F	/* Number of cycles (minus 1) for a half bit clock */
  #define UCPD_CFG1_HBITCLKDIV_0  0x00000001
  #define UCPD_CFG1_HBITCLKDIV_1  0x00000002
  #define UCPD_CFG1_HBITCLKDIV_2  0x00000004
  #define UCPD_CFG1_HBITCLKDIV_3  0x00000008
  #define UCPD_CFG1_HBITCLKDIV_4  0x00000010
  #define UCPD_CFG1_HBITCLKDIV_5  0x00000020
  #define UCPD_CFG1_IFRGAP        0x000007C0	/* Clock divider value to generates Interframe gap */
  #define UCPD_CFG1_IFRGAP_0      0x00000040
  #define UCPD_CFG1_IFRGAP_1      0x00000080
  #define UCPD_CFG1_IFRGAP_2      0x00000100
  #define UCPD_CFG1_IFRGAP_3      0x00000200
  #define UCPD_CFG1_IFRGAP_4      0x00000400
  #define UCPD_CFG1_TRANSWIN      0x0000F800	/* Number of cycles (minus 1) of the half bit clock */
  #define UCPD_CFG1_TRANSWIN_0    0x00000800
  #define UCPD_CFG1_TRANSWIN_1    0x00001000
  #define UCPD_CFG1_TRANSWIN_2    0x00002000
  #define UCPD_CFG1_TRANSWIN_3    0x00004000
  #define UCPD_CFG1_TRANSWIN_4    0x00008000
  #define UCPD_CFG1_PSC_UCPDCLK   0x000E0000	/* Prescaler for UCPDCLK */
  #define UCPD_CFG1_PSC_UCPDCLK_0 0x00020000
  #define UCPD_CFG1_PSC_UCPDCLK_1 0x00040000
  #define UCPD_CFG1_PSC_UCPDCLK_2 0x00080000
  #define UCPD_CFG1_RXORDSETEN    0x1FF00000	/* Receiver ordered set detection enable */
  #define UCPD_CFG1_RXORDSETEN_0  0x00100000
  #define UCPD_CFG1_RXORDSETEN_1  0x00200000
  #define UCPD_CFG1_RXORDSETEN_2  0x00400000
  #define UCPD_CFG1_RXORDSETEN_3  0x00800000
  #define UCPD_CFG1_RXORDSETEN_4  0x01000000
  #define UCPD_CFG1_RXORDSETEN_5  0x02000000
  #define UCPD_CFG1_RXORDSETEN_6  0x04000000
  #define UCPD_CFG1_RXORDSETEN_7  0x08000000
  #define UCPD_CFG1_RXORDSETEN_8  0x10000000
  #define UCPD_CFG1_TXDMAEN       0x20000000	/* DMA transmission requests enable */
  #define UCPD_CFG1_RXDMAEN       0x40000000	/* DMA reception requests enable   */
  #define UCPD_CFG1_UCPDEN        0x80000000	/* USB Power Delivery Block Enable */
#define TOFF_UCPD_CFG2      0x0004		/* (RW) UCPD configuration register 2 */
  #define UCPD_CFG2_RXFILTDIS     0x00000001	/* Enables an Rx pre-filter for the BMC decoder */
  #define UCPD_CFG2_RXFILT2N3     0x00000002	/* Controls the sampling method for an Rx pre-filter for the BMC decode */
  #define UCPD_CFG2_FORCECLK      0x00000004	/* Controls forcing of the clock request UCPDCLK_REQ */
  #define UCPD_CFG2_WUPEN         0x00000008	/* Wakeup from STOP enable */
#define TOFF_UCPD_CR        0x000C		/* (RW) UCPD control register */
  #define UCPD_CR_TXMODE          0x00000003	/* Type of Tx packet  */
  #define UCPD_CR_TXMODE_0        0x00000001
  #define UCPD_CR_TXMODE_1        0x00000002
  #define UCPD_CR_TXSEND          0x00000004	/* Type of Tx packet  */
  #define UCPD_CR_TXHRST          0x00000008	/* Command to send a Tx Hard Reset  */
  #define UCPD_CR_RXMODE          0x00000010	/* Receiver mode  */
  #define UCPD_CR_PHYRXEN         0x00000020	/* Controls enable of USB Power Delivery receiver  */
  #define UCPD_CR_PHYCCSEL        0x00000040
  #define UCPD_CR_ANASUBMODE      0x00000180	/* Analog PHY sub-mode   */
  #define UCPD_CR_ANASUBMODE_0    0x00000080
  #define UCPD_CR_ANASUBMODE_1    0x00000100
  #define UCPD_CR_ANAMODE         0x00000200	/* Analog PHY working mode   */
  #define UCPD_CR_CCENABLE        0x00000C00
  #define UCPD_CR_CCENABLE_0      0x00000400
  #define UCPD_CR_CCENABLE_1      0x00000800
  #define UCPD_CR_FRSRXEN         0x00010000	/* Enable FRS request detection function */
  #define UCPD_CR_FRSTX           0x00020000	/* Signal Fast Role Swap request */
  #define UCPD_CR_RDCH            0x00040000
  #define UCPD_CR_CC1TCDIS        0x00100000	/* The bit allows the Type-C detector for CC0 to be disabled. */
  #define UCPD_CR_CC2TCDIS        0x00200000	/* The bit allows the Type-C detector for CC2 to be disabled. */
#define TOFF_UCPD_IMR       0x0010		/* (RW) UCPD interrupt mask register */
  #define UCPD_IMR_TXISIE         0x00000001	/* Enable TXIS interrupt  */
  #define UCPD_IMR_TXMSGDISCIE    0x00000002	/* Enable TXMSGDISC interrupt  */
  #define UCPD_IMR_TXMSGSENTIE    0x00000004	/* Enable TXMSGSENT interrupt  */
  #define UCPD_IMR_TXMSGABTIE     0x00000008	/* Enable TXMSGABT interrupt  */
  #define UCPD_IMR_HRSTDISCIE     0x00000010	/* Enable HRSTDISC interrupt  */
  #define UCPD_IMR_HRSTSENTIE     0x00000020	/* Enable HRSTSENT interrupt  */
  #define UCPD_IMR_TXUNDIE        0x00000040	/* Enable TXUND interrupt  */
  #define UCPD_IMR_RXNEIE         0x00000100	/* Enable RXNE interrupt  */
  #define UCPD_IMR_RXORDDETIE     0x00000200	/* Enable RXORDDET interrupt  */
  #define UCPD_IMR_RXHRSTDETIE    0x00000400	/* Enable RXHRSTDET interrupt  */
  #define UCPD_IMR_RXOVRIE        0x00000800	/* Enable RXOVR interrupt  */
  #define UCPD_IMR_RXMSGENDIE     0x00001000	/* Enable RXMSGEND interrupt  */
  #define UCPD_IMR_TYPECEVT1IE    0x00004000	/* Enable TYPECEVT1IE interrupt  */
  #define UCPD_IMR_TYPECEVT2IE    0x00008000	/* Enable TYPECEVT2IE interrupt  */
  #define UCPD_IMR_FRSEVTIE       0x00100000	/* Fast Role Swap interrupt  */
#define TOFF_UCPD_SR        0x0014		/* (RW) UCPD status register */
  #define UCPD_SR_TXIS            0x00000001	/* Transmit interrupt status  */
  #define UCPD_SR_TXMSGDISC       0x00000002	/* Transmit message discarded interrupt  */
  #define UCPD_SR_TXMSGSENT       0x00000004	/* Transmit message sent interrupt  */
  #define UCPD_SR_TXMSGABT        0x00000008	/* Transmit message abort interrupt  */
  #define UCPD_SR_HRSTDISC        0x00000010	/* HRST discarded interrupt  */
  #define UCPD_SR_HRSTSENT        0x00000020	/* HRST sent interrupt  */
  #define UCPD_SR_TXUND           0x00000040	/* Tx data underrun condition interrupt  */
  #define UCPD_SR_RXNE            0x00000100	/* Receive data register not empty interrupt  */
  #define UCPD_SR_RXORDDET        0x00000200	/* Rx ordered set (4 K-codes) detected interrupt  */
  #define UCPD_SR_RXHRSTDET       0x00000400	/* Rx Hard Reset detect interrupt  */
  #define UCPD_SR_RXOVR           0x00000800	/* Rx data overflow interrupt  */
  #define UCPD_SR_RXMSGEND        0x00001000	/* Rx message received  */
  #define UCPD_SR_RXERR           0x00002000	/* RX Error */
  #define UCPD_SR_TYPECEVT1       0x00004000	/* Type C voltage level event on CC1  */
  #define UCPD_SR_TYPECEVT2       0x00008000	/* Type C voltage level event on CC2  */
  #define UCPD_SR_TYPEC_VSTATE_CC1   0x00030000	/* Status of DC level on CC1 pin  */
  #define UCPD_SR_TYPEC_VSTATE_CC1_0 0x00010000
  #define UCPD_SR_TYPEC_VSTATE_CC1_1 0x00020000
  #define UCPD_SR_TYPEC_VSTATE_CC2   0x000C0000	/* Status of DC level on CC2 pin  */
  #define UCPD_SR_TYPEC_VSTATE_CC2_0 0x00040000
  #define UCPD_SR_TYPEC_VSTATE_CC2_1 0x00080000
  #define UCPD_SR_FRSEVT          0x00100000	/* Fast Role Swap detection event  */
#define TOFF_UCPD_ICR       0x0018		/* (RW) UCPD interrupt flag clear register */
  #define UCPD_ICR_TXMSGDISCCF    0x00000002	/* Tx message discarded flag (TXMSGDISC) clear  */
  #define UCPD_ICR_TXMSGSENTCF    0x00000004	/* Tx message sent flag (TXMSGSENT) clear  */
  #define UCPD_ICR_TXMSGABTCF     0x00000008	/* Tx message abort flag (TXMSGABT) clear  */
  #define UCPD_ICR_HRSTDISCCF     0x00000010	/* Hard reset discarded flag (HRSTDISC) clear  */
  #define UCPD_ICR_HRSTSENTCF     0x00000020	/* Hard reset sent flag (HRSTSENT) clear  */
  #define UCPD_ICR_TXUNDCF        0x00000040	/* Tx underflow flag (TXUND) clear  */
  #define UCPD_ICR_RXORDDETCF     0x00000200	/* Rx ordered set detect flag (RXORDDET) clear  */
  #define UCPD_ICR_RXHRSTDETCF    0x00000400	/* Rx Hard Reset detected flag (RXHRSTDET) clear  */
  #define UCPD_ICR_RXOVRCF        0x00000800	/* Rx overflow flag (RXOVR) clear  */
  #define UCPD_ICR_RXMSGENDCF     0x00001000	/* Rx message received flag (RXMSGEND) clear  */
  #define UCPD_ICR_TYPECEVT1CF    0x00004000	/* TypeC event (CC1) flag (TYPECEVT1) clear  */
  #define UCPD_ICR_TYPECEVT2CF    0x00008000	/* TypeC event (CC2) flag (TYPECEVT2) clear  */
  #define UCPD_ICR_FRSEVTCF       0x00100000	/* Fast Role Swap event flag clear  */
#define TOFF_UCPD_TX_ORDSET 0x001C		/* (RW) UCPD Tx ordered set type register */
#define TOFF_UCPD_TX_PAYSZ  0x0020		/* (RW) UCPD Tx payload size register */
#define TOFF_UCPD_TXDR      0x0024		/* (RW) UCPD Tx data register */
#define TOFF_UCPD_RX_ORDSET 0x0028		/* (RW) UCPD Rx ordered set type register */
  #define UCPD_RX_ORDSET_RXORDSET       0x00000007	/* Rx Ordered Set Code detected  */
  #define UCPD_RX_ORDSET_RXORDSET_0     0x00000001
  #define UCPD_RX_ORDSET_RXORDSET_1     0x00000002
  #define UCPD_RX_ORDSET_RXORDSET_2     0x00000004
  #define UCPD_RX_ORDSET_RXSOP3OF4      0x00000008	/* Rx Ordered Set Debug indication */
  #define UCPD_RX_ORDSET_RXSOPKINVALID  0x00000070	/* Rx Ordered Set corrupted K-Codes (Debug) */
#define TOFF_UCPD_RX_PAYSZ  0x002C		/* (RW) UCPD Rx payload size register */
#define TOFF_UCPD_RXDR      0x0030		/* (RW) UCPD Rx data register */
#define TOFF_UCPD_RX_ORDEXT1 0x0034		/* (RW) UCPD Rx ordered set extension 1 register */
#define TOFF_UCPD_RX_ORDEXT2 0x0038		/* (RW) UCPD Rx ordered set extension 2 register */


/*
 *  SYSTEM CONFIGURATION CONTROLLER
 */
#define TADR_SYSCFG_BASE    (APB2PERIPH_BASE + 0x0000)
#define TOFF_SYSCFG_MEMRMP  0x0000		/* (RW) SYSCFG memory remap register */
  #define SYSCFG_MEMRMP_MEM_MODE 0x00000007	/* SYSCFG_Memory Remap Config */
  #define SYSCFG_MEMRMP_MEM_MODE_0 0x00000001
  #define SYSCFG_MEMRMP_MEM_MODE_1 0x00000002
  #define SYSCFG_MEMRMP_MEM_MODE_2 0x00000004
  #define SYSCFG_MEMRMP_FB_MODE 0x00000100	/* Flash Bank mode selection */
#define TOFF_SYSCFG_CFGR1   0x0004		/* (RW) SYSCFG configuration register 1 */
  #define SYSCFG_CFGR1_BOOSTEN  0x00000100	/* I/O analog switch voltage booster enable */
  #define SYSCFG_CFGR1_ANASWVDD 0x00000200	/* GPIO analog switch control voltage selection */
  #define SYSCFG_CFGR1_I2C_PB6_FMP 0x00010000	/* I2C PB6 Fast mode plus */
  #define SYSCFG_CFGR1_I2C_PB7_FMP 0x00020000	/* I2C PB7 Fast mode plus */
  #define SYSCFG_CFGR1_I2C_PB8_FMP 0x00040000	/* I2C PB8 Fast mode plus */
  #define SYSCFG_CFGR1_I2C_PB9_FMP 0x00080000	/* I2C PB9 Fast mode plus */
  #define SYSCFG_CFGR1_I2C1_FMP 0x00100000	/* I2C1 Fast mode plus */
  #define SYSCFG_CFGR1_I2C2_FMP 0x00200000	/* I2C2 Fast mode plus */
  #define SYSCFG_CFGR1_I2C3_FMP 0x00400000	/* I2C3 Fast mode plus */
  #define SYSCFG_CFGR1_I2C4_FMP 0x00800000	/* I2C4 Fast mode plus */
  #define SYSCFG_CFGR1_FPU_IE_0 0x04000000	/* Invalid operation Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_1 0x08000000	/* Divide-by-zero Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_2 0x10000000	/* Underflow Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_3 0x20000000	/* Overflow Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_4 0x40000000	/* Input denormal Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_5 0x80000000	/* Inexact Interrupt enable (interrupt disabled at reset) */
#define TOFF_SYSCFG_EXTICR  0x0008		/* (RW) SYSCFG external interrupt configuration registers */
#define TOFF_SYSCFG_EXTICR1 0x0008		/* (RW) SYSCFG external interrupt configuration registers 1 */
  #define SYSCFG_EXTICR1_EXTI0  0x0000000F	/* EXTI 0 configuration */
  #define SYSCFG_EXTICR1_EXTI1  0x000000F0	/* EXTI 1 configuration */
  #define SYSCFG_EXTICR1_EXTI2  0x00000F00	/* EXTI 2 configuration */
  #define SYSCFG_EXTICR1_EXTI3  0x0000F000	/* EXTI 3 configuration */
  #define SYSCFG_EXTICR1_EXTI0_PA   0x00000000	/* PA[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PB   0x00000001	/* PB[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PC   0x00000002	/* PC[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PD   0x00000003	/* PD[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PE   0x00000004	/* PE[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PF   0x00000005	/* PF[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PG   0x00000006	/* PG[0] pin */
  #define SYSCFG_EXTICR1_EXTI1_PA   0x00000000	/* PA[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PB   0x00000010	/* PB[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PC   0x00000020	/* PC[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PD   0x00000030	/* PD[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PE   0x00000040	/* PE[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PF   0x00000050	/* PF[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PG   0x00000060	/* PG[1] pin */
  #define SYSCFG_EXTICR1_EXTI2_PA   0x00000000	/* PA[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PB   0x00000100	/* PB[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PC   0x00000200	/* PC[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PD   0x00000300	/* PD[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PE   0x00000400	/* PE[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PF   0x00000500	/* PF[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PG   0x00000600	/* PG[2] pin */
  #define SYSCFG_EXTICR1_EXTI3_PA   0x00000000	/* PA[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PB   0x00001000	/* PB[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PC   0x00002000	/* PC[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PD   0x00003000	/* PD[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PE   0x00004000	/* PE[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PF   0x00005000	/* PF[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PG   0x00006000	/* PG[3] pin */
#define TOFF_SYSCFG_EXTICR2 0x000C		/* (RW) SYSCFG external interrupt configuration registers 2 */
  #define SYSCFG_EXTICR2_EXTI4  0x0000000F	/* EXTI 4 configuration */
  #define SYSCFG_EXTICR2_EXTI5  0x000000F0	/* EXTI 5 configuration */
  #define SYSCFG_EXTICR2_EXTI6  0x00000F00	/* EXTI 6 configuration */
  #define SYSCFG_EXTICR2_EXTI7  0x0000F000	/* EXTI 7 configuration */
  #define SYSCFG_EXTICR2_EXTI4_PA   0x00000000	/* PA[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PB   0x00000001	/* PB[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PC   0x00000002	/* PC[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PD   0x00000003	/* PD[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PE   0x00000004	/* PE[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PF   0x00000005	/* PF[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PG   0x00000006	/* PG[4] pin */
  #define SYSCFG_EXTICR2_EXTI5_PA   0x00000000	/* PA[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PB   0x00000010	/* PB[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PC   0x00000020	/* PC[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PD   0x00000030	/* PD[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PE   0x00000040	/* PE[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PF   0x00000050	/* PF[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PG   0x00000060	/* PG[5] pin */
  #define SYSCFG_EXTICR2_EXTI6_PA   0x00000000	/* PA[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PB   0x00000100	/* PB[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PC   0x00000200	/* PC[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PD   0x00000300	/* PD[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PE   0x00000400	/* PE[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PF   0x00000500	/* PF[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PG   0x00000600	/* PG[6] pin */
  #define SYSCFG_EXTICR2_EXTI7_PA   0x00000000	/* PA[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PB   0x00001000	/* PB[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PC   0x00002000	/* PC[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PD   0x00003000	/* PD[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PE   0x00004000	/* PE[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PF   0x00005000	/* PF[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PG   0x00006000	/* PG[7] pin */
#define TOFF_SYSCFG_EXTICR3 0x0010		/* (RW) SYSCFG external interrupt configuration registers 3 */
  #define SYSCFG_EXTICR3_EXTI8  0x0000000F	/* EXTI 8 configuration */
  #define SYSCFG_EXTICR3_EXTI9  0x000000F0	/* EXTI 9 configuration */
  #define SYSCFG_EXTICR3_EXTI10 0x00000F00	/* EXTI 10 configuration */
  #define SYSCFG_EXTICR3_EXTI11 0x0000F000	/* EXTI 11 configuration */
  #define SYSCFG_EXTICR3_EXTI8_PA   0x00000000	/* PA[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PB   0x00000001	/* PB[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PC   0x00000002	/* PC[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PD   0x00000003	/* PD[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PE   0x00000004	/* PE[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PF   0x00000005	/* PF[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PG   0x00000006	/* PG[8] pin */
  #define SYSCFG_EXTICR3_EXTI9_PA   0x00000000	/* PA[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PB   0x00000010	/* PB[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PC   0x00000020	/* PC[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PD   0x00000030	/* PD[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PE   0x00000040	/* PE[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PF   0x00000050	/* PF[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PG   0x00000060	/* PG[9] pin */
  #define SYSCFG_EXTICR3_EXTI10_PA  0x00000000	/* PA[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PB  0x00000100	/* PB[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PC  0x00000200	/* PC[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PD  0x00000300	/* PD[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PE  0x00000400	/* PE[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PF  0x00000500	/* PF[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PG  0x00000600	/* PG[10] pin */
  #define SYSCFG_EXTICR3_EXTI11_PA  0x00000000	/* PA[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PB  0x00001000	/* PB[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PC  0x00002000	/* PC[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PD  0x00003000	/* PD[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PE  0x00004000	/* PE[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PF  0x00005000	/* PF[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PG  0x00006000	/* PG[11] pin */
#define TOFF_SYSCFG_EXTICR4 0x0018		/* (RW) SYSCFG external interrupt configuration registers 4 */
  #define SYSCFG_EXTICR4_EXTI12 0x00000007	/* EXTI 12 configuration */
  #define SYSCFG_EXTICR4_EXTI13 0x00000070	/* EXTI 13 configuration */
  #define SYSCFG_EXTICR4_EXTI14 0x00000700	/* EXTI 14 configuration */
  #define SYSCFG_EXTICR4_EXTI15 0x00007000	/* EXTI 15 configuration */
  #define SYSCFG_EXTICR4_EXTI12_PA  0x00000000	/* PA[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PB  0x00000001	/* PB[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PC  0x00000002	/* PC[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PD  0x00000003	/* PD[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PE  0x00000004	/* PE[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PF  0x00000005	/* PF[12] pin */
  #define SYSCFG_EXTICR4_EXTI13_PA  0x00000000	/* PA[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PB  0x00000010	/* PB[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PC  0x00000020	/* PC[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PD  0x00000030	/* PD[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PE  0x00000040	/* PE[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PF  0x00000050	/* PF[13] pin */
  #define SYSCFG_EXTICR4_EXTI14_PA  0x00000000	/* PA[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PB  0x00000100	/* PB[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PC  0x00000200	/* PC[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PD  0x00000300	/* PD[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PE  0x00000400	/* PE[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PF  0x00000500	/* PF[14] pin */
  #define SYSCFG_EXTICR4_EXTI15_PA  0x00000000	/* PA[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PB  0x00001000	/* PB[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PC  0x00002000	/* PC[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PD  0x00003000	/* PD[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PE  0x00004000	/* PE[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PF  0x00005000	/* PF[15] pin */
#define TOFF_SYSCFG_SCSR    0x0018		/* (RW) SYSCFG SRAM2 control and status register */
  #define SYSCFG_SCSR_SRAM2ER   0x00000001	/* SRAM2 Erase Request */
  #define SYSCFG_SCSR_SRAM2BSY  0x00000002	/* SRAM2 Erase Ongoing */
#define TOFF_SYSCFG_CFGR2   0x001C		/* (RW) SYSCFG configuration register 2 */
  #define SYSCFG_CFGR2_CLL   0x00000001	/* Core Lockup Lock */
  #define SYSCFG_CFGR2_SPL   0x00000002	/* SRAM Parity Lock*/
  #define SYSCFG_CFGR2_PVDL  0x00000004	/* PVD Lock */
  #define SYSCFG_CFGR2_ECCL  0x00000008	/* ECC Lock*/
  #define SYSCFG_CFGR2_SPF   0x00000100	/* SRAM Parity Flag */
#define TOFF_SYSCFG_SWPR    0x0020		/* (RW) SYSCFG SRAM2 write protection register */
  #define SYSCFG_SWPR_PAGE0  0x00000001	/* SRAM2 Write protection page 0 */
  #define SYSCFG_SWPR_PAGE1  0x00000002	/* SRAM2 Write protection page 1 */
  #define SYSCFG_SWPR_PAGE2  0x00000004	/* SRAM2 Write protection page 2 */
  #define SYSCFG_SWPR_PAGE3  0x00000008	/* SRAM2 Write protection page 3 */
  #define SYSCFG_SWPR_PAGE4  0x00000010	/* SRAM2 Write protection page 4 */
  #define SYSCFG_SWPR_PAGE5  0x00000020	/* SRAM2 Write protection page 5 */
  #define SYSCFG_SWPR_PAGE6  0x00000040	/* SRAM2 Write protection page 6 */
  #define SYSCFG_SWPR_PAGE7  0x00000080	/* SRAM2 Write protection page 7 */
  #define SYSCFG_SWPR_PAGE8  0x00000100	/* SRAM2 Write protection page 8 */
  #define SYSCFG_SWPR_PAGE9  0x00000200	/* SRAM2 Write protection page 9 */
  #define SYSCFG_SWPR_PAGE10 0x00000400	/* SRAM2 Write protection page 10*/
  #define SYSCFG_SWPR_PAGE11 0x00000800	/* SRAM2 Write protection page 11*/
  #define SYSCFG_SWPR_PAGE12 0x00001000	/* SRAM2 Write protection page 12*/
  #define SYSCFG_SWPR_PAGE13 0x00002000	/* SRAM2 Write protection page 13*/
  #define SYSCFG_SWPR_PAGE14 0x00004000	/* SRAM2 Write protection page 14*/
  #define SYSCFG_SWPR_PAGE15 0x00008000	/* SRAM2 Write protection page 15*/
  #define SYSCFG_SWPR_PAGE16 0x00010000	/* SRAM2 Write protection page 16*/
  #define SYSCFG_SWPR_PAGE17 0x00020000	/* SRAM2 Write protection page 17*/
  #define SYSCFG_SWPR_PAGE18 0x00040000	/* SRAM2 Write protection page 18*/
  #define SYSCFG_SWPR_PAGE19 0x00080000	/* SRAM2 Write protection page 19*/
  #define SYSCFG_SWPR_PAGE20 0x00100000	/* SRAM2 Write protection page 20*/
  #define SYSCFG_SWPR_PAGE21 0x00200000	/* SRAM2 Write protection page 21*/
  #define SYSCFG_SWPR_PAGE22 0x00400000	/* SRAM2 Write protection page 22*/
  #define SYSCFG_SWPR_PAGE23 0x00800000	/* SRAM2 Write protection page 23*/
  #define SYSCFG_SWPR_PAGE24 0x01000000	/* SRAM2 Write protection page 24*/
  #define SYSCFG_SWPR_PAGE25 0x02000000	/* SRAM2 Write protection page 25*/
  #define SYSCFG_SWPR_PAGE26 0x04000000	/* SRAM2 Write protection page 26*/
  #define SYSCFG_SWPR_PAGE27 0x08000000	/* SRAM2 Write protection page 27*/
  #define SYSCFG_SWPR_PAGE28 0x10000000	/* SRAM2 Write protection page 28*/
  #define SYSCFG_SWPR_PAGE29 0x20000000	/* SRAM2 Write protection page 29*/
  #define SYSCFG_SWPR_PAGE30 0x40000000	/* SRAM2 Write protection page 30*/
  #define SYSCFG_SWPR_PAGE31 0x80000000	/* SRAM2 Write protection page 31*/
#define TOFF_SYSCFG_SKR     0x0024		/* (RW) SYSCFG SRAM2 key register */
  #define SYSCFG_SKR_KEY     0x000000FF	/* SRAM2 write protection key for software erase  */


/*
 *  VREFBUF
 */
#define TADR_VREFBUF_BASE   (APB2PERIPH_BASE + 0x0030)
#define TOFF_VREFBUF_CSR    0x0000		/* (RW) VREFBUF control and status register */
  #define VREFBUF_CSR_ENVR   0x00000001	/* Voltage reference buffer enable */
  #define VREFBUF_CSR_HIZ    0x00000002	/* High impedance mode */
  #define VREFBUF_CSR_VRR    0x00000008	/* Voltage reference buffer ready  */
  #define VREFBUF_CSR_VRS    0x00000030	/* VRS[5:0] bits (Voltage reference scale) */
  #define VREFBUF_CSR_VRS_0  0x00000010
  #define VREFBUF_CSR_VRS_1  0x00000020
#define TOFF_VREFBUF_CCR    0x0004		/* (RW) VREFBUF calibration and control register */
  #define VREFBUF_CCR_TRIM   0x0000003F	/* TRIM[5:0] bits (Trimming code)  */


/*
 *  COMPARATOR
 */
#define TADR_COMP1_BASE     (APB2PERIPH_BASE + 0x0200)
#define TADR_COMP2_BASE     (APB2PERIPH_BASE + 0x0204)
#define TADR_COMP3_BASE     (APB2PERIPH_BASE + 0x0208)
#define TADR_COMP4_BASE     (APB2PERIPH_BASE + 0x020C)
#define TADR_COMP5_BASE     (APB2PERIPH_BASE + 0x0210)
#define TADR_COMP6_BASE     (APB2PERIPH_BASE + 0x0214)
#define TADR_COMP7_BASE     (APB2PERIPH_BASE + 0x0218)
#define TADR_COMP12_COMMON_BASE (TADR_COMP2_BASE)
#define TOFF_COMP_CSR       0x0000		/* (RW) COMP control and status register */
  #define COMP_CSR_EN        0x00000001	/* Comparator enable */
  #define COMP_CSR_INMSEL    0x00000070	/* Comparator input minus selection */
  #define COMP_CSR_INMSEL_0  0x00000010
  #define COMP_CSR_INMSEL_1  0x00000020
  #define COMP_CSR_INMSEL_2  0x00000040
  #define COMP_CSR_INMSEL_3  0x00000080
  #define COMP_CSR_INPSEL    0x00000100	/* Comparator input plus selection */
  #define COMP_CSR_POLARITY  0x00008000	/* Comparator output polarity */
  #define COMP_CSR_HYST      0x00070000	/* Comparator hysteresis */
  #define COMP_CSR_HYST_0    0x00010000
  #define COMP_CSR_HYST_1    0x00020000
  #define COMP_CSR_HYST_2    0x00040000
  #define COMP_CSR_BLANKING  0x00380000	/* Comparator blanking source */
  #define COMP_CSR_BLANKING_0 0x00080000
  #define COMP_CSR_BLANKING_1 0x00100000
  #define COMP_CSR_BLANKING_2 0x00200000
  #define COMP_CSR_BRGEN     0x00400000	/* Comparator voltage scaler enable */
  #define COMP_CSR_SCALEN    0x00800000	/* Comparator scaler bridge enable */
  #define COMP_CSR_VALUE     0x40000000	/* Comparator output level */
  #define COMP_CSR_LOCK      0x80000000	/* Comparator lock */


/*
 *  OPERATIONAL AMPLIFIER(OPAMP)
 */
#define TADR_OPAMP_BASE     (APB2PERIPH_BASE + 0x0300)
#define TADR_OPAMP1_BASE    (APB2PERIPH_BASE + 0x0300)
#define TADR_OPAMP2_BASE    (APB2PERIPH_BASE + 0x0304)
#define TADR_OPAMP3_BASE    (APB2PERIPH_BASE + 0x0308)
#define TADR_OPAMP4_BASE    (APB2PERIPH_BASE + 0x030C)
#define TADR_OPAMP5_BASE    (APB2PERIPH_BASE + 0x0310)
#define TADR_OPAMP6_BASE    (APB2PERIPH_BASE + 0x0314)
#define TOFF_OPAMP_CSR      0x0000		/* (RW) OPAMP control/status register */
  #define OPAMP_CSR_OPAMPxEN    0x00000001	/* OPAMP enable */
  #define OPAMP_CSR_FORCEVP     0x00000002	/* Connect the internal references to the plus input of the OPAMPX */
  #define OPAMP_CSR_VPSEL       0x0000000C	/* Non inverting input selection */
  #define OPAMP_CSR_VPSEL_0     0x00000004
  #define OPAMP_CSR_VPSEL_1     0x00000008
  #define OPAMP_CSR_USERTRIM    0x00000010	/* User trimming enable */
  #define OPAMP_CSR_VMSEL       0x00000060	/* Inverting input selection */
  #define OPAMP_CSR_VMSEL_0     0x00000020
  #define OPAMP_CSR_VMSEL_1     0x00000040
  #define OPAMP_CSR_HIGHSPEEDEN 0x00000080	/* High speed mode enable */
  #define OPAMP_CSR_OPAMPINTEN  0x00000100	/* Internal output enable */
  #define OPAMP_CSR_CALON       0x00000800	/* Calibration mode enable */
  #define OPAMP_CSR_CALSEL      0x00003000	/* Calibration selection */
  #define OPAMP_CSR_CALSEL_0    0x00001000
  #define OPAMP_CSR_CALSEL_1    0x00002000
  #define OPAMP_CSR_PGGAIN      0x0007C000	/* Gain in PGA mode */
  #define OPAMP_CSR_PGGAIN_0    0x00004000
  #define OPAMP_CSR_PGGAIN_1    0x00008000
  #define OPAMP_CSR_PGGAIN_2    0x00010000
  #define OPAMP_CSR_PGGAIN_3    0x00020000
  #define OPAMP_CSR_PGGAIN_4    0x00040000
  #define OPAMP_CSR_TRIMOFFSETP 0x00F80000	/* Offset trimming value (PMOS) */
  #define OPAMP_CSR_TRIMOFFSETN 0x1F000000	/* Offset trimming value (NMOS) */
  #define OPAMP_CSR_OUTCAL      0x40000000	/* OPAMP ouput status flag */
  #define OPAMP_CSR_LOCK        0x80000000	/* OPAMP control/status register lock */
#define TOFF_OPAMP_TCMR     0x0018		/* (RW) OPAMP timer controlled mux mode register */
  #define OPAMP_TCMR_VMSSEL     0x00000001	/* Secondary inverting input selection */
  #define OPAMP_TCMR_VPSSEL     0x00000006	/* Secondary non inverting input selection */
  #define OPAMP_TCMR_VPSSEL_0   0x00000002
  #define OPAMP_TCMR_VPSSEL_1   0x00000004
  #define OPAMP_TCMR_T1CMEN     0x00000008	/* Timer 1 controlled mux mode enable */
  #define OPAMP_TCMR_T8CMEN     0x00000010	/* Timer 8 controlled mux mode enable */
  #define OPAMP_TCMR_T20CMEN    0x00000020	/* Timer 20 controlled mux mode enable */
  #define OPAMP_TCMR_LOCK       0x80000000	/* OPAMP SW control register lock */


/*
 *  EXTERNAL INTERRUPT/EVENT CONTROLLER
 */
#define TADR_EXTI_BASE      (APB2PERIPH_BASE + 0x0400)
#define TOFF_EXTI_IMR1      0x0000		/* (RW) EXTI Interrupt mask register */
  #define EXTI_IMR1_IM       0xFFFFFFFF	/* Interrupt Mask All */
#define TOFF_EXTI_IMR       TOFF_EXTI_IMR1
  #define EXTI_IMR_IM0       0x00000001	/* Interrupt Mask on line 0 */
  #define EXTI_IMR_IM1       0x00000002	/* Interrupt Mask on line 1 */
  #define EXTI_IMR_IM2       0x00000004	/* Interrupt Mask on line 2 */
  #define EXTI_IMR_IM3       0x00000008	/* Interrupt Mask on line 3 */
  #define EXTI_IMR_IM4       0x00000010	/* Interrupt Mask on line 4 */
  #define EXTI_IMR_IM5       0x00000020	/* Interrupt Mask on line 5 */
  #define EXTI_IMR_IM6       0x00000040	/* Interrupt Mask on line 6 */
  #define EXTI_IMR_IM7       0x00000080	/* Interrupt Mask on line 7 */
  #define EXTI_IMR_IM8       0x00000100	/* Interrupt Mask on line 8 */
  #define EXTI_IMR_IM9       0x00000200	/* Interrupt Mask on line 9 */
  #define EXTI_IMR_IM10      0x00000400	/* Interrupt Mask on line 10 */
  #define EXTI_IMR_IM11      0x00000800	/* Interrupt Mask on line 11 */
  #define EXTI_IMR_IM12      0x00001000	/* Interrupt Mask on line 12 */
  #define EXTI_IMR_IM13      0x00002000	/* Interrupt Mask on line 13 */
  #define EXTI_IMR_IM14      0x00004000	/* Interrupt Mask on line 14 */
  #define EXTI_IMR_IM15      0x00008000	/* Interrupt Mask on line 15 */
  #define EXTI_IMR_IM16      0x00010000	/* Interrupt Mask on line 16 */
  #define EXTI_IMR_IM17      0x00020000	/* Interrupt Mask on line 17 */
  #define EXTI_IMR_IM18      0x00040000	/* Interrupt Mask on line 18 */
  #define EXTI_IMR_IM19      0x00080000	/* Interrupt Mask on line 19 */
  #define EXTI_IMR_IM20      0x00100000	/* Interrupt Mask on line 20 */
  #define EXTI_IMR_IM21      0x00200000	/* Interrupt Mask on line 21 */
  #define EXTI_IMR_IM22      0x00400000	/* Interrupt Mask on line 22 */
  #define EXTI_IMR_IM23      0x00800000	/* Interrupt Mask on line 23 */
  #define EXTI_IMR_IM24      0x01000000	/* Interrupt Mask on line 24 */
  #define EXTI_IMR_IM25      0x02000000	/* Interrupt Mask on line 25 */
  #define EXTI_IMR_IM26      0x04000000	/* Interrupt Mask on line 26 */
  #define EXTI_IMR_IM27      0x08000000	/* Interrupt Mask on line 27 */
  #define EXTI_IMR_IM28      0x10000000	/* Interrupt Mask on line 28 */
  #define EXTI_IMR_IM29      0x20000000	/* Interrupt Mask on line 29 */
  #define EXTI_IMR_IM30      0x40000000	/* Interrupt Mask on line 30 */
  #define EXTI_IMR_IM31      0x80000000	/* Interrupt Mask on line 31 */
#define TOFF_EXTI_EMR1      0x0004		/* (RW) EXTI Event mask register */
  #define EXTI_EMR_EM0       0x00000001	/* Event Mask on line 0  */
  #define EXTI_EMR_EM1       0x00000002	/* Event Mask on line 1  */
  #define EXTI_EMR_EM2       0x00000004	/* Event Mask on line 2  */
  #define EXTI_EMR_EM3       0x00000008	/* Event Mask on line 3  */
  #define EXTI_EMR_EM4       0x00000010	/* Event Mask on line 4  */
  #define EXTI_EMR_EM5       0x00000020	/* Event Mask on line 5  */
  #define EXTI_EMR_EM6       0x00000040	/* Event Mask on line 6  */
  #define EXTI_EMR_EM7       0x00000080	/* Event Mask on line 7  */
  #define EXTI_EMR_EM8       0x00000100	/* Event Mask on line 8  */
  #define EXTI_EMR_EM9       0x00000200	/* Event Mask on line 9  */
  #define EXTI_EMR_EM10      0x00000400	/* Event Mask on line 10 */
  #define EXTI_EMR_EM11      0x00000800	/* Event Mask on line 11 */
  #define EXTI_EMR_EM12      0x00001000	/* Event Mask on line 12 */
  #define EXTI_EMR_EM13      0x00002000	/* Event Mask on line 13 */
  #define EXTI_EMR_EM14      0x00004000	/* Event Mask on line 14 */
  #define EXTI_EMR_EM15      0x00008000	/* Event Mask on line 15 */
  #define EXTI_EMR_EM16      0x00010000	/* Event Mask on line 16 */
  #define EXTI_EMR_EM17      0x00020000	/* Event Mask on line 17 */
  #define EXTI_EMR_EM18      0x00040000	/* Event Mask on line 18 */
  #define EXTI_EMR_EM19      0x00080000	/* Event Mask on line 19 */
  #define EXTI_EMR_EM20      0x00100000	/* Event Mask on line 20 */
  #define EXTI_EMR_EM21      0x00200000	/* Event Mask on line 21 */
  #define EXTI_EMR_EM22      0x00400000	/* Event Mask on line 22 */
  #define EXTI_EMR_EM23      0x00800000	/* Event Mask on line 23 */
  #define EXTI_EMR_EM25      0x02000000	/* Event Mask on line 25 */
  #define EXTI_EMR_EM26      0x04000000	/* Event Mask on line 26 */
  #define EXTI_EMR_EM27      0x08000000	/* Event Mask on line 27 */
  #define EXTI_EMR_EM28      0x10000000	/* Event Mask on line 28 */
  #define EXTI_EMR_EM31      0x80000000	/* Event Mask on line 31 */
#define TOFF_EXTI_RTSR1     0x0008		/* (RW) EXTI Rising trigger selection register */
#define TOFF_EXTI_RTSR      TOFF_EXTI_RTSR1
  #define EXTI_RTSR_RT0      0x00000001	/* Rising trigger event configuration bit of line 0 */
  #define EXTI_RTSR_RT1      0x00000002	/* Rising trigger event configuration bit of line 1 */
  #define EXTI_RTSR_RT2      0x00000004	/* Rising trigger event configuration bit of line 2 */
  #define EXTI_RTSR_RT3      0x00000008	/* Rising trigger event configuration bit of line 3 */
  #define EXTI_RTSR_RT4      0x00000010	/* Rising trigger event configuration bit of line 4 */
  #define EXTI_RTSR_RT5      0x00000020	/* Rising trigger event configuration bit of line 5 */
  #define EXTI_RTSR_RT6      0x00000040	/* Rising trigger event configuration bit of line 6 */
  #define EXTI_RTSR_RT7      0x00000080	/* Rising trigger event configuration bit of line 7 */
  #define EXTI_RTSR_RT8      0x00000100	/* Rising trigger event configuration bit of line 8 */
  #define EXTI_RTSR_RT9      0x00000200	/* Rising trigger event configuration bit of line 9 */
  #define EXTI_RTSR_RT10     0x00000400	/* Rising trigger event configuration bit of line 10 */
  #define EXTI_RTSR_RT11     0x00000800	/* Rising trigger event configuration bit of line 11 */
  #define EXTI_RTSR_RT12     0x00001000	/* Rising trigger event configuration bit of line 12 */
  #define EXTI_RTSR_RT13     0x00002000	/* Rising trigger event configuration bit of line 13 */
  #define EXTI_RTSR_RT14     0x00004000	/* Rising trigger event configuration bit of line 14 */
  #define EXTI_RTSR_RT15     0x00008000	/* Rising trigger event configuration bit of line 15 */
  #define EXTI_RTSR_RT16     0x00010000	/* Rising trigger event configuration bit of line 16 */
  #define EXTI_RTSR_RT17     0x00020000	/* Rising trigger event configuration bit of line 17 */
  #define EXTI_RTSR_RT18     0x00040000	/* Rising trigger event configuration bit of line 18 */
  #define EXTI_RTSR_RT19     0x00080000	/* Rising trigger event configuration bit of line 19 */
  #define EXTI_RTSR_RT20     0x00100000	/* Rising trigger event configuration bit of line 20 */
  #define EXTI_RTSR_RT21     0x00200000	/* Rising trigger event configuration bit of line 21 */
  #define EXTI_RTSR_RT22     0x00400000	/* Rising trigger event configuration bit of line 22 */
  #define EXTI_RTSR_RT31     0x80000000	/* Rising trigger event configuration bit of line 31 */
#define TOFF_EXTI_FTSR1     0x000C		/* (RW) EXTI Falling trigger selection register */
#define TOFF_EXTI_FTSR      TOFF_EXTI_FTSR1
  #define EXTI_FTSR_FT0      0x00000001	/* Falling trigger event configuration bit of line 0 */
  #define EXTI_FTSR_FT1      0x00000002	/* Falling trigger event configuration bit of line 1 */
  #define EXTI_FTSR_FT2      0x00000004	/* Falling trigger event configuration bit of line 2 */
  #define EXTI_FTSR_FT3      0x00000008	/* Falling trigger event configuration bit of line 3 */
  #define EXTI_FTSR_FT4      0x00000010	/* Falling trigger event configuration bit of line 4 */
  #define EXTI_FTSR_FT5      0x00000020	/* Falling trigger event configuration bit of line 5 */
  #define EXTI_FTSR_FT6      0x00000040	/* Falling trigger event configuration bit of line 6 */
  #define EXTI_FTSR_FT7      0x00000080	/* Falling trigger event configuration bit of line 7 */
  #define EXTI_FTSR_FT8      0x00000100	/* Falling trigger event configuration bit of line 8 */
  #define EXTI_FTSR_FT9      0x00000200	/* Falling trigger event configuration bit of line 9 */
  #define EXTI_FTSR_FT10     0x00000400	/* Falling trigger event configuration bit of line 10 */
  #define EXTI_FTSR_FT11     0x00000800	/* Falling trigger event configuration bit of line 11 */
  #define EXTI_FTSR_FT12     0x00001000	/* Falling trigger event configuration bit of line 12 */
  #define EXTI_FTSR_FT13     0x00002000	/* Falling trigger event configuration bit of line 13 */
  #define EXTI_FTSR_FT14     0x00004000	/* Falling trigger event configuration bit of line 14 */
  #define EXTI_FTSR_FT15     0x00008000	/* Falling trigger event configuration bit of line 15 */
  #define EXTI_FTSR_FT16     0x00010000	/* Falling trigger event configuration bit of line 16 */
  #define EXTI_FTSR_FT17     0x00020000	/* Falling trigger event configuration bit of line 17 */
  #define EXTI_FTSR_FT18     0x00040000	/* Falling trigger event configuration bit of line 18 */
  #define EXTI_FTSR_FT19     0x00080000	/* Falling trigger event configuration bit of line 19 */
  #define EXTI_FTSR_FT20     0x00100000	/* Falling trigger event configuration bit of line 20 */
  #define EXTI_FTSR_FT21     0x00200000	/* Falling trigger event configuration bit of line 21 */
  #define EXTI_FTSR_FT22     0x00400000	/* Falling trigger event configuration bit of line 22 */
  #define EXTI_FTSR_FT31     0x80000000	/* Falling trigger event configuration bit of line 31 */
#define TOFF_EXTI_SWIER1    0x0010		/* (RW) EXTI Software interrupt event register */
  #define EXTI_SWIER_SW0     0x00000000	/* Software Interrupt on line 0  */
  #define EXTI_SWIER_SW1     0x00000002	/* Software Interrupt on line 1  */
  #define EXTI_SWIER_SW2     0x00000004	/* Software Interrupt on line 2  */
  #define EXTI_SWIER_SW3     0x00000008	/* Software Interrupt on line 3  */
  #define EXTI_SWIER_SW4     0x00000010	/* Software Interrupt on line 4  */
  #define EXTI_SWIER_SW5     0x00000020	/* Software Interrupt on line 5  */
  #define EXTI_SWIER_SW6     0x00000040	/* Software Interrupt on line 6  */
  #define EXTI_SWIER_SW7     0x00000080	/* Software Interrupt on line 7  */
  #define EXTI_SWIER_SW8     0x00000100	/* Software Interrupt on line 8  */
  #define EXTI_SWIER_SW9     0x00000200	/* Software Interrupt on line 9  */
  #define EXTI_SWIER_SW10    0x00000400	/* Software Interrupt on line 10 */
  #define EXTI_SWIER_SW11    0x00000800	/* Software Interrupt on line 11 */
  #define EXTI_SWIER_SW12    0x00001000	/* Software Interrupt on line 12 */
  #define EXTI_SWIER_SW13    0x00002000	/* Software Interrupt on line 13 */
  #define EXTI_SWIER_SW14    0x00004000	/* Software Interrupt on line 14 */
  #define EXTI_SWIER_SW15    0x00008000	/* Software Interrupt on line 15 */
  #define EXTI_SWIER_SW16    0x00010000	/* Software Interrupt on line 16 */
  #define EXTI_SWIER_SW17    0x00020000	/* Software Interrupt on line 17 */
  #define EXTI_SWIER_SW19    0x00080000	/* Software Interrupt on line 19 */
  #define EXTI_SWIER_SW20    0x00100000	/* Software Interrupt on line 20 */
  #define EXTI_SWIER_SW21    0x00200000	/* Software Interrupt on line 21 */
  #define EXTI_SWIER_SW22    0x00400000	/* Software Interrupt on line 22 */
  #define EXTI_SWIER_SW31    0x80000000	/* Software Interrupt on line 31 */
#define TOFF_EXTI_PR1       0x0014		/* (RW) EXTI Pending register */
#define TOFF_EXTI_PR        TOFF_EXTI_PR1
  #define EXTI_PR_PIF0       0x00000001	/* Pending bit for line 0 */
  #define EXTI_PR_PIF1       0x00000002	/* Pending bit for line 1 */
  #define EXTI_PR_PIF2       0x00000004	/* Pending bit for line 2 */
  #define EXTI_PR_PIF3       0x00000008	/* Pending bit for line 3 */
  #define EXTI_PR_PIF4       0x00000010	/* Pending bit for line 4 */
  #define EXTI_PR_PIF5       0x00000020	/* Pending bit for line 5 */
  #define EXTI_PR_PIF6       0x00000040	/* Pending bit for line 6 */
  #define EXTI_PR_PIF7       0x00000080	/* Pending bit for line 7 */
  #define EXTI_PR_PIF8       0x00000100	/* Pending bit for line 8 */
  #define EXTI_PR_PIF9       0x00000200	/* Pending bit for line 9 */
  #define EXTI_PR_PIF10      0x00000400	/* Pending bit for line 10 */
  #define EXTI_PR_PIF11      0x00000800	/* Pending bit for line 11 */
  #define EXTI_PR_PIF12      0x00001000	/* Pending bit for line 12 */
  #define EXTI_PR_PIF13      0x00002000	/* Pending bit for line 13 */
  #define EXTI_PR_PIF14      0x00004000	/* Pending bit for line 14 */
  #define EXTI_PR_PIF15      0x00008000	/* Pending bit for line 15 */
  #define EXTI_PR_PIF16      0x00010000	/* Pending bit for line 16 */
  #define EXTI_PR_PIF17      0x00020000	/* Pending bit for line 17 */
  #define EXTI_PR_PIF18      0x00040000	/* Pending bit for line 18 */
  #define EXTI_PR_PIF19      0x00080000	/* Pending bit for line 19 */
  #define EXTI_PR_PIF20      0x00100000	/* Pending bit for line 20 */
  #define EXTI_PR_PIF21      0x00200000	/* Pending bit for line 21 */
  #define EXTI_PR_PIF22      0x00400000	/* Pending bit for line 22 */
  #define EXTI_PR_PIF31      0x80000000	/* Pending bit for line 31 */
#define TOFF_EXTI_IMR2      0x0020		/* (RW) EXTI Interrupt mask register 2 */
  #define EXTI_IMR2_IM       0x000007FF	/* Interrupt Mask all */
#define TOFF_EXTI_EMR2      0x0024		/* (RW) EXTI Event mask register 2 */
  #define EXTI_EMR2_EM       0x000007FF	/* Interrupt Mask all */
#define TOFF_EXTI_RTSR2     0x0028		/* (RW) EXTI Rising trigger selection register 2 */
#define TOFF_EXTI_FTSR2     0x002C		/* (RW) EXTI Falling trigger selection register 2 */
#define TOFF_EXTI_SWIER2    0x0030		/* (RW) EXTI Software interrupt event register 2 */
#define TOFF_EXTI_PR2       0x0034		/* (RW) EXTI Pending register 2 */


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
  #define SAI_xFRCR_FSPOL     0x00020000	/* Frame Synchronization POLarity */
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
 *  HIGH RESOLUTION TIMER (HRTIM)
  */
#define TADR_HRTIM1_BASE    (APB2PERIPH_BASE + 0x6800)
#define TOFF_HRTIM_MCR      0x0000		/* (RW) HRTIM Master Timer control register */
  #define HRTIM_MCR_CK_PSC      0x00000007	/* Prescaler mask */
  #define HRTIM_MCR_CK_PSC_0    0x00000001
  #define HRTIM_MCR_CK_PSC_1    0x00000002
  #define HRTIM_MCR_CK_PSC_2    0x00000004
  #define HRTIM_MCR_CONT        0x00000008	/* Continuous mode */
  #define HRTIM_MCR_RETRIG      0x00000010	/* Rettrigreable mode */
  #define HRTIM_MCR_HALF        0x00000020	/* Half mode */
  #define HRTIM_MCR_INTLVD      0x000000C0	/* Interleaved mode */
  #define HRTIM_MCR_INTLVD_0    0x00000040
  #define HRTIM_MCR_INTLVD_1    0x00000080
  #define HRTIM_MCR_SYNC_IN     0x00000300	/* Synchronization input master */
  #define HRTIM_MCR_SYNC_IN_0   0x00000100
  #define HRTIM_MCR_SYNC_IN_1   0x00000200
  #define HRTIM_MCR_SYNCRSTM    0x00000400	/* Synchronization reset master */
  #define HRTIM_MCR_SYNCSTRTM   0x00000800	/* Synchronization start master */
  #define HRTIM_MCR_SYNC_OUT    0x00003000	/* Synchronization output master */
  #define HRTIM_MCR_SYNC_OUT_0  0x00001000
  #define HRTIM_MCR_SYNC_OUT_1  0x00002000
  #define HRTIM_MCR_SYNC_SRC    0x0000C000	/* Synchronization source */
  #define HRTIM_MCR_SYNC_SRC_0  0x00004000
  #define HRTIM_MCR_SYNC_SRC_1  0x00008000
  #define HRTIM_MCR_MCEN        0x00010000	/* Master counter enable */
  #define HRTIM_MCR_TACEN       0x00020000	/* Timer A counter enable */
  #define HRTIM_MCR_TBCEN       0x00040000	/* Timer B counter enable */
  #define HRTIM_MCR_TCCEN       0x00080000	/* Timer C counter enable */
  #define HRTIM_MCR_TDCEN       0x00100000	/* Timer D counter enable */
  #define HRTIM_MCR_TECEN       0x00200000	/* Timer E counter enable */
  #define HRTIM_MCR_TFCEN       0x00400000	/* Timer F counter enable */
  #define HRTIM_MCR_DACSYNC     0x06000000	/* DAC sychronization mask */
  #define HRTIM_MCR_DACSYNC_0   0x02000000
  #define HRTIM_MCR_DACSYNC_1   0x04000000
  #define HRTIM_MCR_PREEN       0x08000000	/* Master preload enable */
  #define HRTIM_MCR_MREPU       0x20000000	/* Master repetition update */
  #define HRTIM_MCR_BRSTDMA     0xC0000000	/* Burst DMA update */
  #define HRTIM_MCR_BRSTDMA_0   0x40000000
  #define HRTIM_MCR_BRSTDMA_1   0x80000000
#define TOFF_HRTIM_MISR     0x0004		/* (RW) HRTIM Master Timer interrupt status register */
  #define HRTIM_MISR_MCMP1      0x00000001	/* Master compare 1 interrupt flag */
  #define HRTIM_MISR_MCMP2      0x00000002	/* Master compare 2 interrupt flag */
  #define HRTIM_MISR_MCMP3      0x00000004	/* Master compare 3 interrupt flag */
  #define HRTIM_MISR_MCMP4      0x00000008	/* Master compare 4 interrupt flag */
  #define HRTIM_MISR_MREP       0x00000010	/* Master Repetition interrupt flag */
  #define HRTIM_MISR_SYNC       0x00000020	/* Synchronization input interrupt flag */
  #define HRTIM_MISR_MUPD       0x00000040	/* Master update interrupt flag */
#define TOFF_HRTIM_MICR     0x0008		/* (RW) HRTIM Master Timer interupt clear register */
  #define HRTIM_MICR_MCMP1      0x00000001	/* Master compare 1 interrupt flag clear */
  #define HRTIM_MICR_MCMP2      0x00000002	/* Master compare 2 interrupt flag clear */
  #define HRTIM_MICR_MCMP3      0x00000004	/* Master compare 3 interrupt flag clear */
  #define HRTIM_MICR_MCMP4      0x00000008	/* Master compare 4 interrupt flag clear */
  #define HRTIM_MICR_MREP       0x00000010	/* Master Repetition interrupt flag clear */
  #define HRTIM_MICR_SYNC       0x00000020	/* Synchronization input interrupt flag clear */
  #define HRTIM_MICR_MUPD       0x00000040	/* Master update interrupt flag clear */
#define TOFF_HRTIM_MDIER    0x000C		/* (RW) HRTIM Master Timer DMA/interrupt enable register*/
  #define HRTIM_MDIER_MCMP1IE   0x00000001	/* Master compare 1 interrupt enable */
  #define HRTIM_MDIER_MCMP2IE   0x00000002	/* Master compare 2 interrupt enable */
  #define HRTIM_MDIER_MCMP3IE   0x00000004	/* Master compare 3 interrupt enable */
  #define HRTIM_MDIER_MCMP4IE   0x00000008	/* Master compare 4 interrupt enable */
  #define HRTIM_MDIER_MREPIE    0x00000010	/* Master Repetition interrupt enable */
  #define HRTIM_MDIER_SYNCIE    0x00000020	/* Synchronization input interrupt enable */
  #define HRTIM_MDIER_MUPDIE    0x00000040	/* Master update interrupt enable */
  #define HRTIM_MDIER_MCMP1DE   0x00010000	/* Master compare 1 DMA enable */
  #define HRTIM_MDIER_MCMP2DE   0x00020000	/* Master compare 2 DMA enable */
  #define HRTIM_MDIER_MCMP3DE   0x00040000	/* Master compare 3 DMA enable */
  #define HRTIM_MDIER_MCMP4DE   0x00080000	/* Master compare 4 DMA enable */
  #define HRTIM_MDIER_MREPDE    0x00100000	/* Master Repetition DMA enable */
  #define HRTIM_MDIER_SYNCDE    0x00200000	/* Synchronization input DMA enable */
  #define HRTIM_MDIER_MUPDDE    0x00400000	/* Master update DMA enable */
#define TOFF_HRTIM_MCNTR    0x0010		/* (RW) HRTIM Master Timer counter register */
#define TOFF_HRTIM_MPER     0x0014		/* (RW) HRTIM Master Timer period register */
#define TOFF_HRTIM_MREP     0x0018		/* (RW) HRTIM Master Timer repetition register */
#define TOFF_HRTIM_MCMP1R   0x001C		/* (RW) HRTIM Master Timer compare 1 register */
#define TOFF_HRTIM_MCMP2R   0x0024		/* (RW) HRTIM Master Timer compare 2 register */
#define TOFF_HRTIM_MCMP3R   0x0028		/* (RW) HRTIM Master Timer compare 3 register */
#define TOFF_HRTIM_MCMP4R   0x002C		/* (RW) HRTIM Master Timer compare 4 register */
#define TOFF_HRTIM_TIMER    0x0080		/* Timer A-F offset */

#define TOFF_HRTIM_CR1      0x0380		/* (RW) HRTIM control register1 */
  #define HRTIM_CR1_MUDIS       0x00000001	/* Master update disable*/
  #define HRTIM_CR1_TAUDIS      0x00000002	/* Timer A update disable*/
  #define HRTIM_CR1_TBUDIS      0x00000004	/* Timer B update disable*/
  #define HRTIM_CR1_TCUDIS      0x00000008	/* Timer C update disable*/
  #define HRTIM_CR1_TDUDIS      0x00000010	/* Timer D update disable*/
  #define HRTIM_CR1_TEUDIS      0x00000020	/* Timer E update disable*/
  #define HRTIM_CR1_TFUDIS      0x00000040	/* Timer F update disable*/
  #define HRTIM_CR1_ADC1USRC    0x00070000	/* ADC Trigger 1 update source */
  #define HRTIM_CR1_ADC1USRC_0  0x00010000
  #define HRTIM_CR1_ADC1USRC_1  0x00020000
  #define HRTIM_CR1_ADC1USRC_2  0x00040000
  #define HRTIM_CR1_ADC2USRC    0x00380000	/* ADC Trigger 2 update source */
  #define HRTIM_CR1_ADC2USRC_0  0x00080000
  #define HRTIM_CR1_ADC2USRC_1  0x00100000
  #define HRTIM_CR1_ADC2USRC_2  0x00200000
  #define HRTIM_CR1_ADC3USRC    0x01C00000	/* ADC Trigger 3 update source */
  #define HRTIM_CR1_ADC3USRC_0  0x00400000
  #define HRTIM_CR1_ADC3USRC_1  0x00800000
  #define HRTIM_CR1_ADC3USRC_2  0x01000000
  #define HRTIM_CR1_ADC4USRC    0x0E000000	/* ADC Trigger 4 update source */
  #define HRTIM_CR1_ADC4USRC_0  0x02000000
  #define HRTIM_CR1_ADC4USRC_1  0x04000000
  #define HRTIM_CR1_ADC4USRC_2  0x08000000
#define TOFF_HRTIM_CR2      0x0384		/* (RW) HRTIM control register2 */
  #define HRTIM_CR2_MSWU        0x00000001	/* Master software update */
  #define HRTIM_CR2_TASWU       0x00000002	/* Timer A software update */
  #define HRTIM_CR2_TBSWU       0x00000004	/* Timer B software update */
  #define HRTIM_CR2_TCSWU       0x00000008	/* Timer C software update */
  #define HRTIM_CR2_TDSWU       0x00000010	/* Timer D software update */
  #define HRTIM_CR2_TESWU       0x00000020	/* Timer E software update */
  #define HRTIM_CR2_TFSWU       0x00000040	/* Timer F software update */
  #define HRTIM_CR2_MRST        0x00000100	/* Master count software reset */
  #define HRTIM_CR2_TARST       0x00000200	/* Timer A count software reset */
  #define HRTIM_CR2_TBRST       0x00000400	/* Timer B count software reset */
  #define HRTIM_CR2_TCRST       0x00000800	/* Timer C count software reset */
  #define HRTIM_CR2_TDRST       0x00001000	/* Timer D count software reset */
  #define HRTIM_CR2_TERST       0x00002000	/* Timer E count software reset */
  #define HRTIM_CR2_TFRST       0x00004000	/* Timer F count software reset */
  #define HRTIM_CR2_SWPA        0x00010000	/* Timer A swap outputs */
  #define HRTIM_CR2_SWPB        0x00020000	/* Timer B swap outputs */
  #define HRTIM_CR2_SWPC        0x00040000	/* Timer C swap outputs */
  #define HRTIM_CR2_SWPD        0x00080000	/* Timer D swap outputs */
  #define HRTIM_CR2_SWPE        0x00100000	/* Timer E swap outputs */
  #define HRTIM_CR2_SWPF        0x00200000	/* Timer F swap outputs */
#define TOFF_HRTIM_ISR      0x0388		/* (RW) HRTIM interrupt status register */
  #define HRTIM_ISR_FLT1        0x00000001	/* Fault 1 interrupt flag */
  #define HRTIM_ISR_FLT2        0x00000002	/* Fault 2 interrupt flag */
  #define HRTIM_ISR_FLT3        0x00000004	/* Fault 3 interrupt flag */
  #define HRTIM_ISR_FLT4        0x00000008	/* Fault 4 interrupt flag */
  #define HRTIM_ISR_FLT5        0x00000010	/* Fault 5 interrupt flag */
  #define HRTIM_ISR_SYSFLT      0x00000020	/* System Fault interrupt flag */
  #define HRTIM_ISR_FLT6        0x00000040	/* Fault 6 interrupt flag */
  #define HRTIM_ISR_DLLRDY      0x00010000	/* DLL ready interrupt flag */
  #define HRTIM_ISR_BMPER       0x00020000	/* Burst mode period interrupt flag */
#define TOFF_HRTIM_ICR      0x038C		/* (RW) HRTIM interrupt clear register */
  #define HRTIM_ICR_FLT1C       0x00000001	/* Fault 1 interrupt flag clear */
  #define HRTIM_ICR_FLT2C       0x00000002	/* Fault 2 interrupt flag clear */
  #define HRTIM_ICR_FLT3C       0x00000004	/* Fault 3 interrupt flag clear */
  #define HRTIM_ICR_FLT4C       0x00000008	/* Fault 4 interrupt flag clear */
  #define HRTIM_ICR_FLT5C       0x00000010	/* Fault 5 interrupt flag clear */
  #define HRTIM_ICR_SYSFLTC     0x00000020	/* System Fault interrupt flag clear */
  #define HRTIM_ICR_FLT6C       0x00000040	/* Fault 6 interrupt flag clear */
  #define HRTIM_ICR_DLLRDYC     0x00010000	/* DLL ready interrupt flag clear */
  #define HRTIM_ICR_BMPERC      0x00020000	/*  Burst mode period interrupt flag clear */
#define TOFF_HRTIM_IER      0x0390		/* (RW) HRTIM interrupt enable register */
  #define HRTIM_IER_FLT1        0x00000001	/* Fault 1 interrupt enable */
  #define HRTIM_IER_FLT2        0x00000002	/* Fault 2 interrupt enable */
  #define HRTIM_IER_FLT3        0x00000004	/* Fault 3 interrupt enable */
  #define HRTIM_IER_FLT4        0x00000008	/* Fault 4 interrupt enable */
  #define HRTIM_IER_FLT5        0x00000010	/* Fault 5 interrupt enable */
  #define HRTIM_IER_SYSFLT      0x00000020	/* System Fault interrupt enable */
  #define HRTIM_IER_FLT6        0x00000040	/* Fault 6 interrupt enable */
  #define HRTIM_IER_DLLRDY      0x00010000	/* DLL ready interrupt enable */
  #define HRTIM_IER_BMPER       0x00020000	/*  Burst mode period interrupt enable */
#define TOFF_HRTIM_OENR     0x0394		/* (RW) HRTIM Output enable register */
  #define HRTIM_OENR_TA1OEN     0x00000001	/* Timer A Output 1 enable */
  #define HRTIM_OENR_TA2OEN     0x00000002	/* Timer A Output 2 enable */
  #define HRTIM_OENR_TB1OEN     0x00000004	/* Timer B Output 1 enable */
  #define HRTIM_OENR_TB2OEN     0x00000008	/* Timer B Output 2 enable */
  #define HRTIM_OENR_TC1OEN     0x00000010	/* Timer C Output 1 enable */
  #define HRTIM_OENR_TC2OEN     0x00000020	/* Timer C Output 2 enable */
  #define HRTIM_OENR_TD1OEN     0x00000040	/* Timer D Output 1 enable */
  #define HRTIM_OENR_TD2OEN     0x00000080	/* Timer D Output 2 enable */
  #define HRTIM_OENR_TE1OEN     0x00000100	/* Timer E Output 1 enable */
  #define HRTIM_OENR_TE2OEN     0x00000200	/* Timer E Output 2 enable */
  #define HRTIM_OENR_TF1OEN     0x00000400	/* Timer F Output 1 enable */
  #define HRTIM_OENR_TF2OEN     0x00000800	/* Timer F Output 2 enable */
#define TOFF_HRTIM_ODISR    0x0398		/* (RW) HRTIM Output disable register */
  #define HRTIM_ODISR_TA1ODIS   0x00000001	/* Timer A Output 1 disable */
  #define HRTIM_ODISR_TA2ODIS   0x00000002	/* Timer A Output 2 disable */
  #define HRTIM_ODISR_TB1ODIS   0x00000004	/* Timer B Output 1 disable */
  #define HRTIM_ODISR_TB2ODIS   0x00000008	/* Timer B Output 2 disable */
  #define HRTIM_ODISR_TC1ODIS   0x00000010	/* Timer C Output 1 disable */
  #define HRTIM_ODISR_TC2ODIS   0x00000020	/* Timer C Output 2 disable */
  #define HRTIM_ODISR_TD1ODIS   0x00000040	/* Timer D Output 1 disable */
  #define HRTIM_ODISR_TD2ODIS   0x00000080	/* Timer D Output 2 disable */
  #define HRTIM_ODISR_TE1ODIS   0x00000100	/* Timer E Output 1 disable */
  #define HRTIM_ODISR_TE2ODIS   0x00000200	/* Timer E Output 2 disable */
  #define HRTIM_ODISR_TF1ODIS   0x00000400	/* Timer F Output 1 disable */
  #define HRTIM_ODISR_TF2ODIS   0x00000800	/* Timer F Output 2 disable */
#define TOFF_HRTIM_ODSR     0x039C		/* (RW) HRTIM Output disable status register */
  #define HRTIM_ODSR_TA1ODS     0x00000001	/* Timer A Output 1 disable status */
  #define HRTIM_ODSR_TA2ODS     0x00000002	/* Timer A Output 2 disable status */
  #define HRTIM_ODSR_TB1ODS     0x00000004	/* Timer B Output 1 disable status */
  #define HRTIM_ODSR_TB2ODS     0x00000008	/* Timer B Output 2 disable status */
  #define HRTIM_ODSR_TC1ODS     0x00000010	/* Timer C Output 1 disable status */
  #define HRTIM_ODSR_TC2ODS     0x00000020	/* Timer C Output 2 disable status */
  #define HRTIM_ODSR_TD1ODS     0x00000040	/* Timer D Output 1 disable status */
  #define HRTIM_ODSR_TD2ODS     0x00000080	/* Timer D Output 2 disable status */
  #define HRTIM_ODSR_TE1ODS     0x00000100	/* Timer E Output 1 disable status */
  #define HRTIM_ODSR_TE2ODS     0x00000200	/* Timer E Output 2 disable status */
  #define HRTIM_ODSR_TF1ODS     0x00000400	/* Timer F Output 1 disable status */
  #define HRTIM_ODSR_TF2ODS     0x00000800	/* Timer F Output 2 disable status */
#define TOFF_HRTIM_BMCR     0x03A0		/* (RW) HRTIM Burst mode control register */
  #define HRTIM_BMCR_BME        0x00000001	/* Burst mode enbale */
  #define HRTIM_BMCR_BMOM       0x00000002	/* Burst mode operating mode */
  #define HRTIM_BMCR_BMCLK      0x0000003C	/* Burst mode clock source */
  #define HRTIM_BMCR_BMCLK_0    0x00000004
  #define HRTIM_BMCR_BMCLK_1    0x00000008
  #define HRTIM_BMCR_BMCLK_2    0x00000010
  #define HRTIM_BMCR_BMCLK_3    0x00000020
  #define HRTIM_BMCR_BMPRSC     0x000003C0	/* Burst mode prescaler */
  #define HRTIM_BMCR_BMPRSC_0   0x00000040
  #define HRTIM_BMCR_BMPRSC_1   0x00000080
  #define HRTIM_BMCR_BMPRSC_2   0x00000100
  #define HRTIM_BMCR_BMPRSC_3   0x00000200
  #define HRTIM_BMCR_BMPREN     0x00000400	/* Burst mode Preload bit */
  #define HRTIM_BMCR_MTBM       0x00010000	/* Master Timer Burst mode */
  #define HRTIM_BMCR_TABM       0x00020000	/* Timer A Burst mode */
  #define HRTIM_BMCR_TBBM       0x00040000	/* Timer B Burst mode */
  #define HRTIM_BMCR_TCBM       0x00080000	/* Timer C Burst mode */
  #define HRTIM_BMCR_TDBM       0x00100000	/* Timer D Burst mode */
  #define HRTIM_BMCR_TEBM       0x00200000	/* Timer E Burst mode */
  #define HRTIM_BMCR_TFBM       0x00400000	/* Timer F Burst mode */
  #define HRTIM_BMCR_BMSTAT     0x80000000	/* Burst mode status */
#define TOFF_HRTIM_BMTRGR   0x03A4		/* (RW) HRTIM Busrt mode trigger register */
  #define HRTIM_BMTRGR_SW       0x00000001	/* Software start */
  #define HRTIM_BMTRGR_MSTRST   0x00000002	/* Master reset */
  #define HRTIM_BMTRGR_MSTREP   0x00000004	/* Master repetition */
  #define HRTIM_BMTRGR_MSTCMP1  0x00000008	/* Master compare 1 */
  #define HRTIM_BMTRGR_MSTCMP2  0x00000010	/* Master compare 2  */
  #define HRTIM_BMTRGR_MSTCMP3  0x00000020	/* Master compare 3 */
  #define HRTIM_BMTRGR_MSTCMP4  0x00000040	/* Master compare 4 */
  #define HRTIM_BMTRGR_TARST    0x00000080	/* Timer A reset  */
  #define HRTIM_BMTRGR_TAREP    0x00000100	/* Timer A repetition  */
  #define HRTIM_BMTRGR_TACMP1   0x00000200	/* Timer A compare 1  */
  #define HRTIM_BMTRGR_TACMP2   0x00000400	/* Timer A compare 2  */
  #define HRTIM_BMTRGR_TBRST    0x00000800	/* Timer B reset  */
  #define HRTIM_BMTRGR_TBREP    0x00001000	/* Timer B repetition  */
  #define HRTIM_BMTRGR_TBCMP1   0x00002000	/* Timer B compare 1 */
  #define HRTIM_BMTRGR_TBCMP2   0x00004000	/* Timer B compare 2 */
  #define HRTIM_BMTRGR_TCRST    0x00008000	/* Timer C reset  */
  #define HRTIM_BMTRGR_TCREP    0x00010000	/* Timer C repetition */
  #define HRTIM_BMTRGR_TCCMP1   0x00020000	/* Timer C compare 1 */
  #define HRTIM_BMTRGR_TFRST    0x00040000	/* Timer F reset */
  #define HRTIM_BMTRGR_TCCMP2   0x00040000	/* Timer C compare 2 */
  #define HRTIM_BMTRGR_TDRST    0x00080000	/* Timer D reset  */
  #define HRTIM_BMTRGR_TDREP    0x00100000	/* Timer D repetition  */
  #define HRTIM_BMTRGR_TFREP    0x00200000	/* Timer F repetition*/
  #define HRTIM_BMTRGR_TDCMP1   0x00200000	/* Timer D compare 1 */
  #define HRTIM_BMTRGR_TDCMP2   0x00400000	/* Timer D compare 2 */
  #define HRTIM_BMTRGR_TFCMP1   0x00800000	/* Timer F compare 1 */
  #define HRTIM_BMTRGR_TERST    0x00800000	/* Timer E reset  */
  #define HRTIM_BMTRGR_TEREP    0x01000000	/* Timer E repetition  */
  #define HRTIM_BMTRGR_TECMP1   0x02000000	/* Timer E compare 1 */
  #define HRTIM_BMTRGR_TECMP2   0x04000000	/* Timer E compare 2 */
  #define HRTIM_BMTRGR_TAEEV7   0x08000000	/* Timer A period following External Event7  */
  #define HRTIM_BMTRGR_TDEEV8   0x10000000	/* Timer D period following External Event8  */
  #define HRTIM_BMTRGR_EEV7     0x20000000	/* External Event 7 */
  #define HRTIM_BMTRGR_EEV8     0x40000000	/* External Event 8 */
  #define HRTIM_BMTRGR_OCHPEV   0x80000000	/* on-chip Event */
#define TOFF_HRTIM_BMCMPR   0x03A8		/* (RW) HRTIM Burst mode compare register */
#define TOFF_HRTIM_BMPER    0x03AC		/* (RW) HRTIM Burst mode period register */
#define TOFF_HRTIM_EECR1    0x03B0		/* (RW) HRTIM Timer external event control register */
  #define HRTIM_EECR1_EE1SRC    0x00000003	/* External event 1 source */
  #define HRTIM_EECR1_EE1SRC_0  0x00000001
  #define HRTIM_EECR1_EE1SRC_1  0x00000002
  #define HRTIM_EECR1_EE1POL    0x00000004	/* External event 1 Polarity */
  #define HRTIM_EECR1_EE1SNS    0x00000018	/* External event 1 sensitivity */
  #define HRTIM_EECR1_EE1SNS_0  0x00000008
  #define HRTIM_EECR1_EE1SNS_1  0x00000010
  #define HRTIM_EECR1_EE1FAST   0x00000020	/* External event 1 Fast mode */
  #define HRTIM_EECR1_EE2SRC    0x000000C0	/* External event 2 source */
  #define HRTIM_EECR1_EE2SRC_0  0x00000040
  #define HRTIM_EECR1_EE2SRC_1  0x00000080
  #define HRTIM_EECR1_EE2POL    0x00000100	/* External event 2 Polarity */
  #define HRTIM_EECR1_EE2SNS    0x00000600	/* External event 2 sensitivity */
  #define HRTIM_EECR1_EE2SNS_0  0x00000200
  #define HRTIM_EECR1_EE2SNS_1  0x00000400
  #define HRTIM_EECR1_EE2FAST   0x00000800	/* External event 2 Fast mode */
  #define HRTIM_EECR1_EE3SRC    0x00003000	/* External event 3 source */
  #define HRTIM_EECR1_EE3SRC_0  0x00001000
  #define HRTIM_EECR1_EE3SRC_1  0x00002000
  #define HRTIM_EECR1_EE3POL    0x00004000	/* External event 3 Polarity */
  #define HRTIM_EECR1_EE3SNS    0x00018000	/* External event 3 sensitivity */
  #define HRTIM_EECR1_EE3SNS_0  0x00008000
  #define HRTIM_EECR1_EE3SNS_1  0x00010000
  #define HRTIM_EECR1_EE3FAST   0x00020000	/* External event 3 Fast mode */
  #define HRTIM_EECR1_EE4SRC    0x000C0000	/* External event 4 source */
  #define HRTIM_EECR1_EE4SRC_0  0x00040000
  #define HRTIM_EECR1_EE4SRC_1  0x00080000
  #define HRTIM_EECR1_EE4POL    0x00100000	/* External event 4 Polarity */
  #define HRTIM_EECR1_EE4SNS    0x00600000	/* External event 4 sensitivity */
  #define HRTIM_EECR1_EE4SNS_0  0x00200000
  #define HRTIM_EECR1_EE4SNS_1  0x00400000
  #define HRTIM_EECR1_EE4FAST   0x00800000	/* External event 4 Fast mode */
  #define HRTIM_EECR1_EE5SRC    0x03000000	/* External event 5 source */
  #define HRTIM_EECR1_EE5SRC_0  0x01000000
  #define HRTIM_EECR1_EE5SRC_1  0x02000000
  #define HRTIM_EECR1_EE5POL    0x04000000	/* External event 5 Polarity */
  #define HRTIM_EECR1_EE5SNS    0x18000000	/* External event 5 sensitivity */
  #define HRTIM_EECR1_EE5SNS_0  0x08000000
  #define HRTIM_EECR1_EE5SNS_1  0x10000000
  #define HRTIM_EECR1_EE5FAST   0x20000000	/* External event 5 Fast mode */
#define TOFF_HRTIM_EECR2    0x03B4		/* (RW) HRTIM Timer external event control register */
  #define HRTIM_EECR2_EE6SRC    0x00000003	/* External event 6 source */
  #define HRTIM_EECR2_EE6SRC_0  0x00000001
  #define HRTIM_EECR2_EE6SRC_1  0x00000002
  #define HRTIM_EECR2_EE6POL    0x00000004	/* External event 6 Polarity */
  #define HRTIM_EECR2_EE6SNS    0x00000018	/* External event 6 sensitivity */
  #define HRTIM_EECR2_EE6SNS_0  0x00000008
  #define HRTIM_EECR2_EE6SNS_1  0x00000010
  #define HRTIM_EECR2_EE7SRC    0x000000C0	/* External event 7 source */
  #define HRTIM_EECR2_EE7SRC_0  0x00000040
  #define HRTIM_EECR2_EE7SRC_1  0x00000080
  #define HRTIM_EECR2_EE7POL    0x00000100	/* External event 7 Polarity */
  #define HRTIM_EECR2_EE7SNS    0x00000600	/* External event 7 sensitivity */
  #define HRTIM_EECR2_EE7SNS_0  0x00000200
  #define HRTIM_EECR2_EE7SNS_1  0x00000400
  #define HRTIM_EECR2_EE8SRC    0x00003000	/* External event 8 source */
  #define HRTIM_EECR2_EE8SRC_0  0x00001000
  #define HRTIM_EECR2_EE8SRC_1  0x00002000
  #define HRTIM_EECR2_EE8POL    0x00004000	/* External event 8 Polarity */
  #define HRTIM_EECR2_EE8SNS    0x00018000	/* External event 8 sensitivity */
  #define HRTIM_EECR2_EE8SNS_0  0x00008000
  #define HRTIM_EECR2_EE8SNS_1  0x00010000
  #define HRTIM_EECR2_EE9SRC    0x000C0000	/* External event 9 source */
  #define HRTIM_EECR2_EE9SRC_0  0x00040000
  #define HRTIM_EECR2_EE9SRC_1  0x00080000
  #define HRTIM_EECR2_EE9POL    0x00100000	/* External event 9 Polarity */
  #define HRTIM_EECR2_EE9SNS    0x00600000	/* External event 9 sensitivity */
  #define HRTIM_EECR2_EE9SNS_0  0x00200000
  #define HRTIM_EECR2_EE9SNS_1  0x00400000
  #define HRTIM_EECR2_EE10SRC   0x03000000	/* External event 10 source */
  #define HRTIM_EECR2_EE10SRC_0 0x01000000
  #define HRTIM_EECR2_EE10SRC_1 0x02000000
  #define HRTIM_EECR2_EE10POL   0x04000000	/* External event 10 Polarity */
  #define HRTIM_EECR2_EE10SNS   0x18000000	/* External event 10 sensitivity */
  #define HRTIM_EECR2_EE10SNS_0 0x08000000
  #define HRTIM_EECR2_EE10SNS_1 0x10000000
#define TOFF_HRTIM_EECR3    0x03B8		/* (RW) HRTIM Timer external event control register */
  #define HRTIM_EECR3_EE6F      0x0000000F	/* External event 6 filter */
  #define HRTIM_EECR3_EE6F_0    0x00000001
  #define HRTIM_EECR3_EE6F_1    0x00000002
  #define HRTIM_EECR3_EE6F_2    0x00000004
  #define HRTIM_EECR3_EE6F_3    0x00000008
  #define HRTIM_EECR3_EE7F      0x000003C0	/* External event 7 filter */
  #define HRTIM_EECR3_EE7F_0    0x00000040
  #define HRTIM_EECR3_EE7F_1    0x00000080
  #define HRTIM_EECR3_EE7F_2    0x00000100
  #define HRTIM_EECR3_EE7F_3    0x00000200
  #define HRTIM_EECR3_EE8F      0x0000F000	/* External event 8 filter */
  #define HRTIM_EECR3_EE8F_0    0x00001000
  #define HRTIM_EECR3_EE8F_1    0x00002000
  #define HRTIM_EECR3_EE8F_2    0x00004000
  #define HRTIM_EECR3_EE8F_3    0x00008000
  #define HRTIM_EECR3_EE9F      0x003C0000	/* External event 9 filter */
  #define HRTIM_EECR3_EE9F_0    0x00040000
  #define HRTIM_EECR3_EE9F_1    0x00080000
  #define HRTIM_EECR3_EE9F_2    0x00100000
  #define HRTIM_EECR3_EE9F_3    0x00200000
  #define HRTIM_EECR3_EE10F     0x0F000000	/* External event 10 filter */
  #define HRTIM_EECR3_EE10F_0   0x01000000
  #define HRTIM_EECR3_EE10F_1   0x02000000
  #define HRTIM_EECR3_EE10F_2   0x04000000
  #define HRTIM_EECR3_EE10F_3   0x08000000
  #define HRTIM_EECR3_EEVSD     0xC0000000	/* External event sampling clock division */
  #define HRTIM_EECR3_EEVSD_0   0x40000000
  #define HRTIM_EECR3_EEVSD_1   0x80000000
#define TOFF_HRTIM_ADC1R    0x03BC		/* (RW) HRTIM ADC Trigger 1 register */
  #define HRTIM_ADC1R_AD1MC1    0x00000001	/* ADC Trigger 1 on master compare 1 */
  #define HRTIM_ADC1R_AD1MC2    0x00000002	/* ADC Trigger 1 on master compare 2 */
  #define HRTIM_ADC1R_AD1MC3    0x00000004	/* ADC Trigger 1 on master compare 3 */
  #define HRTIM_ADC1R_AD1MC4    0x00000008	/* ADC Trigger 1 on master compare 4 */
  #define HRTIM_ADC1R_AD1MPER   0x00000010	/* ADC Trigger 1 on master period */
  #define HRTIM_ADC1R_AD1EEV1   0x00000020	/* ADC Trigger 1 on external event 1 */
  #define HRTIM_ADC1R_AD1EEV2   0x00000040	/* ADC Trigger 1 on external event 2 */
  #define HRTIM_ADC1R_AD1EEV3   0x00000080	/* ADC Trigger 1 on external event 3 */
  #define HRTIM_ADC1R_AD1EEV4   0x00000100	/* ADC Trigger 1 on external event 4 */
  #define HRTIM_ADC1R_AD1EEV5   0x00000200	/* ADC Trigger 1 on external event 5 */
  #define HRTIM_ADC1R_AD1TFC2   0x00000400	/* ADC Trigger 1 on Timer F compare 2 */
  #define HRTIM_ADC1R_AD1TAC3   0x00000800	/* ADC Trigger 1 on Timer A compare 3 */
  #define HRTIM_ADC1R_AD1TAC4   0x00001000	/* ADC Trigger 1 on Timer A compare 4 */
  #define HRTIM_ADC1R_AD1TAPER  0x00002000	/* ADC Trigger 1 on Timer A period */
  #define HRTIM_ADC1R_AD1TARST  0x00004000	/* ADC Trigger 1 on Timer A reset */
  #define HRTIM_ADC1R_AD1TFC3   0x00008000	/* ADC Trigger 1 on Timer F compare 3 */
  #define HRTIM_ADC1R_AD1TBC3   0x00010000	/* ADC Trigger 1 on Timer B compare 3 */
  #define HRTIM_ADC1R_AD1TBC4   0x00020000	/* ADC Trigger 1 on Timer B compare 4 */
  #define HRTIM_ADC1R_AD1TBPER  0x00040000	/* ADC Trigger 1 on Timer B period */
  #define HRTIM_ADC1R_AD1TBRST  0x00080000	/* ADC Trigger 1 on Timer B reset */
  #define HRTIM_ADC1R_AD1TFC4   0x00100000	/* ADC Trigger 1 on Timer F compare 4 */
  #define HRTIM_ADC1R_AD1TCC3   0x00200000	/* ADC Trigger 1 on Timer C compare 3 */
  #define HRTIM_ADC1R_AD1TCC4   0x00400000	/* ADC Trigger 1 on Timer C compare 4 */
  #define HRTIM_ADC1R_AD1TCPER  0x00800000	/* ADC Trigger 1 on Timer C period */
  #define HRTIM_ADC1R_AD1TFPER  0x01000000	/* ADC Trigger 1 on Timer F period */
  #define HRTIM_ADC1R_AD1TDC3   0x02000000	/* ADC Trigger 1 on Timer D compare 3 */
  #define HRTIM_ADC1R_AD1TDC4   0x04000000	/* ADC Trigger 1 on Timer D compare 4 */
  #define HRTIM_ADC1R_AD1TDPER  0x08000000	/* ADC Trigger 1 on Timer D period */
  #define HRTIM_ADC1R_AD1TFRST  0x10000000	/* ADC Trigger 1 on Timer F reset */
  #define HRTIM_ADC1R_AD1TEC3   0x20000000	/* ADC Trigger 1 on Timer E compare 3 */
  #define HRTIM_ADC1R_AD1TEC4   0x40000000	/* ADC Trigger 1 on Timer E compare 4 */
  #define HRTIM_ADC1R_AD1TEPER  0x80000000	/* ADC Trigger 1 on Timer E compare period */
#define TOFF_HRTIM_ADC2R    0x03C0		/* (RW) HRTIM ADC Trigger 2 register */
  #define HRTIM_ADC2R_AD2MC1    0x00000001	/* ADC Trigger 2 on master compare 1 */
  #define HRTIM_ADC2R_AD2MC2    0x00000002	/* ADC Trigger 2 on master compare 2 */
  #define HRTIM_ADC2R_AD2MC3    0x00000004	/* ADC Trigger 2 on master compare 3 */
  #define HRTIM_ADC2R_AD2MC4    0x00000008	/* ADC Trigger 2 on master compare 4 */
  #define HRTIM_ADC2R_AD2MPER   0x00000010	/* ADC Trigger 2 on master period */
  #define HRTIM_ADC2R_AD2EEV6   0x00000020	/* ADC Trigger 2 on external event 6 */
  #define HRTIM_ADC2R_AD2EEV7   0x00000040	/* ADC Trigger 2 on external event 7 */
  #define HRTIM_ADC2R_AD2EEV8   0x00000080	/* ADC Trigger 2 on external event 8 */
  #define HRTIM_ADC2R_AD2EEV9   0x00000100	/* ADC Trigger 2 on external event 9 */
  #define HRTIM_ADC2R_AD2EEV10  0x00000200	/* ADC Trigger 2 on external event 10 */
  #define HRTIM_ADC2R_AD2TAC2   0x00000400	/* ADC Trigger 2 on Timer A compare 2 */
  #define HRTIM_ADC2R_AD2TFC2   0x00000800	/* ADC Trigger 2 on Timer F compare 2 */
  #define HRTIM_ADC2R_AD2TAC4   0x00001000	/* ADC Trigger 2 on Timer A compare 4*/
  #define HRTIM_ADC2R_AD2TAPER  0x00002000	/* ADC Trigger 2 on Timer A period */
  #define HRTIM_ADC2R_AD2TBC2   0x00004000	/* ADC Trigger 2 on Timer B compare 2 */
  #define HRTIM_ADC2R_AD2TFC3   0x00008000	/* ADC Trigger 2 on Timer F compare 3 */
  #define HRTIM_ADC2R_AD2TBC4   0x00010000	/* ADC Trigger 2 on Timer B compare 4 */
  #define HRTIM_ADC2R_AD2TBPER  0x00020000	/* ADC Trigger 2 on Timer B period */
  #define HRTIM_ADC2R_AD2TCC2   0x00040000	/* ADC Trigger 2 on Timer C compare 2 */
  #define HRTIM_ADC2R_AD2TFC4   0x00080000	/* ADC Trigger 2 on Timer F compare 4 */
  #define HRTIM_ADC2R_AD2TCC4   0x00100000	/* ADC Trigger 2 on Timer C compare 4 */
  #define HRTIM_ADC2R_AD2TCPER  0x00200000	/* ADC Trigger 2 on Timer C period */
  #define HRTIM_ADC2R_AD2TCRST  0x00400000	/* ADC Trigger 2 on Timer C reset */
  #define HRTIM_ADC2R_AD2TDC2   0x00800000	/* ADC Trigger 2 on Timer D compare 2 */
  #define HRTIM_ADC2R_AD2TFPER  0x01000000	/* ADC Trigger 2 on Timer F period */
  #define HRTIM_ADC2R_AD2TDC4   0x02000000	/* ADC Trigger 2 on Timer D compare 4*/
  #define HRTIM_ADC2R_AD2TDPER  0x04000000	/* ADC Trigger 2 on Timer D period */
  #define HRTIM_ADC2R_AD2TDRST  0x08000000	/* ADC Trigger 2 on Timer D reset */
  #define HRTIM_ADC2R_AD2TEC2   0x10000000	/* ADC Trigger 2 on Timer E compare 2 */
  #define HRTIM_ADC2R_AD2TEC3   0x20000000	/* ADC Trigger 2 on Timer E compare 3 */
  #define HRTIM_ADC2R_AD2TEC4   0x40000000	/* ADC Trigger 2 on Timer E compare 4 */
  #define HRTIM_ADC2R_AD2TERST  0x80000000	/* ADC Trigger 2 on Timer E reset */
#define TOFF_HRTIM_ADC3R    0x03C4		/* (RW) HRTIM ADC Trigger 3 register */
  #define HRTIM_ADC3R_AD3MC1    0x00000001	/* ADC Trigger 3 on master compare 1 */
  #define HRTIM_ADC3R_AD3MC2    0x00000002	/* ADC Trigger 3 on master compare 2 */
  #define HRTIM_ADC3R_AD3MC3    0x00000004	/* ADC Trigger 3 on master compare 3 */
  #define HRTIM_ADC3R_AD3MC4    0x00000008	/* ADC Trigger 3 on master compare 4 */
  #define HRTIM_ADC3R_AD3MPER   0x00000010	/* ADC Trigger 3 on master period */
  #define HRTIM_ADC3R_AD3EEV1   0x00000020	/* ADC Trigger 3 on external event 1 */
  #define HRTIM_ADC3R_AD3EEV2   0x00000040	/* ADC Trigger 3 on external event 2 */
  #define HRTIM_ADC3R_AD3EEV3   0x00000080	/* ADC Trigger 3 on external event 3 */
  #define HRTIM_ADC3R_AD3EEV4   0x00000100	/* ADC Trigger 3 on external event 4 */
  #define HRTIM_ADC3R_AD3EEV5   0x00000200	/* ADC Trigger 3 on external event 5 */
  #define HRTIM_ADC3R_AD3TFC2   0x00000400	/* ADC Trigger 3 on Timer F compare 2 */
  #define HRTIM_ADC3R_AD3TAC3   0x00000800	/* ADC Trigger 3 on Timer A compare 3 */
  #define HRTIM_ADC3R_AD3TAC4   0x00001000	/* ADC Trigger 3 on Timer A compare 4 */
  #define HRTIM_ADC3R_AD3TAPER  0x00002000	/* ADC Trigger 3 on Timer A period */
  #define HRTIM_ADC3R_AD3TARST  0x00004000	/* ADC Trigger 3 on Timer A reset */
  #define HRTIM_ADC3R_AD3TFC3   0x00008000	/* ADC Trigger 3 on Timer F compare 3 */
  #define HRTIM_ADC3R_AD3TBC3   0x00010000	/* ADC Trigger 3 on Timer B compare 3 */
  #define HRTIM_ADC3R_AD3TBC4   0x00020000	/* ADC Trigger 3 on Timer B compare 4 */
  #define HRTIM_ADC3R_AD3TBPER  0x00040000	/* ADC Trigger 3 on Timer B period */
  #define HRTIM_ADC3R_AD3TBRST  0x00080000	/* ADC Trigger 3 on Timer B reset */
  #define HRTIM_ADC3R_AD3TFC4   0x00100000	/* ADC Trigger 3 on Timer F compare 4 */
  #define HRTIM_ADC3R_AD3TCC3   0x00200000	/* ADC Trigger 3 on Timer C compare 3 */
  #define HRTIM_ADC3R_AD3TCC4   0x00400000	/* ADC Trigger 3 on Timer C compare 4 */
  #define HRTIM_ADC3R_AD3TCPER  0x00800000	/* ADC Trigger 3 on Timer C period */
  #define HRTIM_ADC3R_AD3TFPER  0x01000000	/* ADC Trigger 3 on Timer F period */
  #define HRTIM_ADC3R_AD3TDC3   0x02000000	/* ADC Trigger 3 on Timer D compare 3 */
  #define HRTIM_ADC3R_AD3TDC4   0x04000000	/* ADC Trigger 3 on Timer D compare 4 */
  #define HRTIM_ADC3R_AD3TDPER  0x08000000	/* ADC Trigger 3 on Timer D period */
  #define HRTIM_ADC3R_AD3TFRST  0x10000000	/* ADC Trigger 3 on Timer F reset */
  #define HRTIM_ADC3R_AD3TEC3   0x20000000	/* ADC Trigger 3 on Timer E compare 3 */
  #define HRTIM_ADC3R_AD3TEC4   0x40000000	/* ADC Trigger 3 on Timer E compare 4 */
  #define HRTIM_ADC3R_AD3TEPER  0x80000000	/* ADC Trigger 3 on Timer E period */
#define TOFF_HRTIM_ADC4R    0x03C8		/* (RW) HRTIM ADC Trigger 4 register */
  #define HRTIM_ADC4R_AD4MC1    0x00000001	/* ADC Trigger 4 on master compare 1 */
  #define HRTIM_ADC4R_AD4MC2    0x00000002	/* ADC Trigger 4 on master compare 2 */
  #define HRTIM_ADC4R_AD4MC3    0x00000004	/* ADC Trigger 4 on master compare 3 */
  #define HRTIM_ADC4R_AD4MC4    0x00000008	/* ADC Trigger 4 on master compare 4 */
  #define HRTIM_ADC4R_AD4MPER   0x00000010	/* ADC Trigger 4 on master period */
  #define HRTIM_ADC4R_AD4EEV6   0x00000020	/* ADC Trigger 4 on external event 6 */
  #define HRTIM_ADC4R_AD4EEV7   0x00000040	/* ADC Trigger 4 on external event 7 */
  #define HRTIM_ADC4R_AD4EEV8   0x00000080	/* ADC Trigger 4 on external event 8 */
  #define HRTIM_ADC4R_AD4EEV9   0x00000100	/* ADC Trigger 4 on external event 9 */
  #define HRTIM_ADC4R_AD4EEV10  0x00000200	/* ADC Trigger 4 on external event 10 */
  #define HRTIM_ADC4R_AD4TAC2   0x00000400	/* ADC Trigger 4 on Timer A compare 2 */
  #define HRTIM_ADC4R_AD4TFC2   0x00000800	/* ADC Trigger 4 on Timer F compare 2 */
  #define HRTIM_ADC4R_AD4TAC4   0x00001000	/* ADC Trigger 4 on Timer A compare 4*/
  #define HRTIM_ADC4R_AD4TAPER  0x00002000	/* ADC Trigger 4 on Timer A period */
  #define HRTIM_ADC4R_AD4TBC2   0x00004000	/* ADC Trigger 4 on Timer B compare 2 */
  #define HRTIM_ADC4R_AD4TFC3   0x00008000	/* ADC Trigger 4 on Timer F compare 3 */
  #define HRTIM_ADC4R_AD4TBC4   0x00010000	/* ADC Trigger 4 on Timer B compare 4 */
  #define HRTIM_ADC4R_AD4TBPER  0x00020000	/* ADC Trigger 4 on Timer B period */
  #define HRTIM_ADC4R_AD4TCC2   0x00040000	/* ADC Trigger 4 on Timer C compare 2 */
  #define HRTIM_ADC4R_AD4TFC4   0x00080000	/* ADC Trigger 4 on Timer F compare 4 */
  #define HRTIM_ADC4R_AD4TCC4   0x00100000	/* ADC Trigger 4 on Timer C compare 4 */
  #define HRTIM_ADC4R_AD4TCPER  0x00200000	/* ADC Trigger 4 on Timer C period */
  #define HRTIM_ADC4R_AD4TCRST  0x00400000	/* ADC Trigger 4 on Timer C reset */
  #define HRTIM_ADC4R_AD4TDC2   0x00800000	/* ADC Trigger 4 on Timer D compare 2 */
  #define HRTIM_ADC4R_AD4TFPER  0x01000000	/* ADC Trigger 4 on Timer F period */
  #define HRTIM_ADC4R_AD4TDC4   0x02000000	/* ADC Trigger 4 on Timer D compare 4 */
  #define HRTIM_ADC4R_AD4TDPER  0x04000000	/* ADC Trigger 4 on Timer D period */
  #define HRTIM_ADC4R_AD4TDRST  0x08000000	/* ADC Trigger 4 on Timer D reset */
  #define HRTIM_ADC4R_AD4TEC2   0x10000000	/* ADC Trigger 4 on Timer E compare 2 */
  #define HRTIM_ADC4R_AD4TEC3   0x20000000	/* ADC Trigger 4 on Timer E compare 3 */
  #define HRTIM_ADC4R_AD4TEC4   0x40000000	/* ADC Trigger 4 on Timer E compare 4 */
  #define HRTIM_ADC4R_AD4TERST  0x80000000	/* ADC Trigger 4 on Timer E reset */
#define TOFF_HRTIM_DLLCR    0x03CC		/* (RW) HRTIM DLL control register */
  #define HRTIM_DLLCR_CAL       0x00000001	/* DLL calibration start */
  #define HRTIM_DLLCR_CALEN     0x00000002	/* DLL calibration enable */
  #define HRTIM_DLLCR_CALRTE    0x0000000C	/* DLL calibration rate */
  #define HRTIM_DLLCR_CALRTE_0  0x00000004
  #define HRTIM_DLLCR_CALRTE_1  0x00000008
#define TOFF_HRTIM_FLTINR1  0x03D0		/* (RW) HRTIM Fault input register1 */
  #define HRTIM_FLTINR1_FLT1E     0x00000001	/* Fault 1 enable */
  #define HRTIM_FLTINR1_FLT1P     0x00000002	/* Fault 1 polarity */
  #define HRTIM_FLTINR1_FLT1SRC_0 0x00000004	/* Fault 1 source bit 0 */
  #define HRTIM_FLTINR1_FLT1F     0x00000078	/* Fault 1 filter */
  #define HRTIM_FLTINR1_FLT1F_0   0x00000008
  #define HRTIM_FLTINR1_FLT1F_1   0x00000010
  #define HRTIM_FLTINR1_FLT1F_2   0x00000020
  #define HRTIM_FLTINR1_FLT1F_3   0x00000040
  #define HRTIM_FLTINR1_FLT1LCK   0x00000080	/* Fault 1 lock */
  #define HRTIM_FLTINR1_FLT2E     0x00000100	/* Fault 2 enable */
  #define HRTIM_FLTINR1_FLT2P     0x00000200	/* Fault 2 polarity */
  #define HRTIM_FLTINR1_FLT2SRC_0 0x00000400	/* Fault 2 source bit 0 */
  #define HRTIM_FLTINR1_FLT2F     0x00007800	/* Fault 2 filter */
  #define HRTIM_FLTINR1_FLT2F_0   0x00000800
  #define HRTIM_FLTINR1_FLT2F_1   0x00001000
  #define HRTIM_FLTINR1_FLT2F_2   0x00002000
  #define HRTIM_FLTINR1_FLT2F_3   0x00004000
  #define HRTIM_FLTINR1_FLT2LCK   0x00008000	/* Fault 2 lock */
  #define HRTIM_FLTINR1_FLT3E     0x00010000	/* Fault 3 enable */
  #define HRTIM_FLTINR1_FLT3P     0x00020000	/* Fault 3 polarity */
  #define HRTIM_FLTINR1_FLT3SRC_0 0x00040000	/* Fault 3 source bit 0 */
  #define HRTIM_FLTINR1_FLT3F     0x00780000	/* Fault 3 filter */
  #define HRTIM_FLTINR1_FLT3F_0   0x00080000
  #define HRTIM_FLTINR1_FLT3F_1   0x00100000
  #define HRTIM_FLTINR1_FLT3F_2   0x00200000
  #define HRTIM_FLTINR1_FLT3F_3   0x00400000
  #define HRTIM_FLTINR1_FLT3LCK   0x00800000	/* Fault 3 lock */
  #define HRTIM_FLTINR1_FLT4E     0x01000000	/* Fault 4 enable */
  #define HRTIM_FLTINR1_FLT4P     0x02000000	/* Fault 4 polarity */
  #define HRTIM_FLTINR1_FLT4SRC_0 0x04000000	/* Fault 4 source bit 0 */
  #define HRTIM_FLTINR1_FLT4F     0x78000000	/* Fault 4 filter */
  #define HRTIM_FLTINR1_FLT4F_0   0x08000000
  #define HRTIM_FLTINR1_FLT4F_1   0x10000000
  #define HRTIM_FLTINR1_FLT4F_2   0x20000000
  #define HRTIM_FLTINR1_FLT4F_3   0x40000000
  #define HRTIM_FLTINR1_FLT4LCK   0x80000000	/* Fault 4 lock */
#define TOFF_HRTIM_FLTINR2  0x03D4		/* (RW) HRTIM Fault input register2 */
  #define HRTIM_FLTINR2_FLT5E     0x00000001	/* Fault 5 enable */
  #define HRTIM_FLTINR2_FLT5P     0x00000002	/* Fault 5 polarity */
  #define HRTIM_FLTINR2_FLT5SRC_0 0x00000004	/* Fault 5 source bit 0 */
  #define HRTIM_FLTINR2_FLT5F     0x00000078	/* Fault 5 filter */
  #define HRTIM_FLTINR2_FLT5F_0   0x00000008
  #define HRTIM_FLTINR2_FLT5F_1   0x00000010
  #define HRTIM_FLTINR2_FLT5F_2   0x00000020
  #define HRTIM_FLTINR2_FLT5F_3   0x00000040
  #define HRTIM_FLTINR2_FLT5LCK   0x00000080	/* Fault 5 lock */
  #define HRTIM_FLTINR2_FLT6E     0x00000100	/* Fault 6 enable */
  #define HRTIM_FLTINR2_FLT6P     0x00000200	/* Fault 6 polarity */
  #define HRTIM_FLTINR2_FLT6SRC_0 0x00000400	/* Fault 6 source bit 0 */
  #define HRTIM_FLTINR2_FLT6F     0x00007800	/* Fault 6 filter */
  #define HRTIM_FLTINR2_FLT6F_0   0x00000800
  #define HRTIM_FLTINR2_FLT6F_1   0x00001000
  #define HRTIM_FLTINR2_FLT6F_2   0x00002000
  #define HRTIM_FLTINR2_FLT6F_3   0x00004000
  #define HRTIM_FLTINR2_FLT6LCK   0x00008000	/* Fault 6 lock */
  #define HRTIM_FLTINR2_FLT1SRC_1 0x00010000	/* Fault 1 source bit 1 */
  #define HRTIM_FLTINR2_FLT2SRC_1 0x00020000	/* Fault 2 source bit1 */
  #define HRTIM_FLTINR2_FLT3SRC_1 0x00040000	/* Fault 3 source bit 1 */
  #define HRTIM_FLTINR2_FLT4SRC_1 0x00080000	/* Fault 4 source bit 1 */
  #define HRTIM_FLTINR2_FLT5SRC_1 0x00100000	/* Fault 5 source bit 1 */
  #define HRTIM_FLTINR2_FLT6SRC_1 0x00200000	/* Fault 6 source bit 1 */
  #define HRTIM_FLTINR2_FLTSD     0x03000000	/* Fault sampling clock division */
  #define HRTIM_FLTINR2_FLTSD_0   0x01000000
  #define HRTIM_FLTINR2_FLTSD_1   0x02000000
#define TOFF_HRTIM_BDMUPR   0x03D8		/* (RW) HRTIM Burst DMA Master Timer update register */
  #define HRTIM_BDMUPR_MCR      0x00000001	/* MCR register update enable */
  #define HRTIM_BDMUPR_MICR     0x00000002	/* MICR register update enable */
  #define HRTIM_BDMUPR_MDIER    0x00000004	/* MDIER register update enable */
  #define HRTIM_BDMUPR_MCNT     0x00000008	/* MCNT register update enable */
  #define HRTIM_BDMUPR_MPER     0x00000010	/* MPER register update enable */
  #define HRTIM_BDMUPR_MREP     0x00000020	/* MREP register update enable */
  #define HRTIM_BDMUPR_MCMP1    0x00000040	/* MCMP1 register update enable */
  #define HRTIM_BDMUPR_MCMP2    0x00000080	/* MCMP2 register update enable */
  #define HRTIM_BDMUPR_MCMP3    0x00000100	/* MCMP3 register update enable */
  #define HRTIM_BDMUPR_MCMP4    0x00000200	/* MPCMP4 register update enable */
#define TOFF_HRTIM_BDTAUPR  0x03DC		/* (RW) HRTIM Burst DMA Timerx update register */
#define TOFF_HRTIM_BDTBUPR  0x03E0		/* (RW) HRTIM Burst DMA Timerx update register */
#define TOFF_HRTIM_BDTCUPR  0x03E4		/* (RW) HRTIM Burst DMA Timerx update register */
#define TOFF_HRTIM_BDTDUPR  0x03E8		/* (RW) HRTIM Burst DMA Timerx update register */
  #define HRTIM_BDTUPR_TIMCR    0x00000001	/* TIMCR register update enable */
  #define HRTIM_BDTUPR_TIMICR   0x00000002	/* TIMICR register update enable */
  #define HRTIM_BDTUPR_TIMDIER  0x00000004	/* TIMDIER register update enable */
  #define HRTIM_BDTUPR_TIMCNT   0x00000008	/* TIMCNT register update enable */
  #define HRTIM_BDTUPR_TIMPER   0x00000010	/* TIMPER register update enable */
  #define HRTIM_BDTUPR_TIMREP   0x00000020	/* TIMREP register update enable */
  #define HRTIM_BDTUPR_TIMCMP1  0x00000040	/* TIMCMP1 register update enable */
  #define HRTIM_BDTUPR_TIMCMP2  0x00000080	/* TIMCMP2 register update enable */
  #define HRTIM_BDTUPR_TIMCMP3  0x00000100	/* TIMCMP3 register update enable */
  #define HRTIM_BDTUPR_TIMCMP4  0x00000200	/* TIMCMP4 register update enable */
  #define HRTIM_BDTUPR_TIMDTR   0x00000400	/* TIMDTR register update enable */
  #define HRTIM_BDTUPR_TIMSET1R 0x00000800	/* TIMSET1R register update enable */
  #define HRTIM_BDTUPR_TIMRST1R 0x00001000	/* TIMRST1R register update enable */
  #define HRTIM_BDTUPR_TIMSET2R 0x00002000	/* TIMSET2R register update enable */
  #define HRTIM_BDTUPR_TIMRST2R 0x00004000	/* TIMRST2R register update enable */
  #define HRTIM_BDTUPR_TIMEEFR1 0x00008000	/* TIMEEFR1 register update enable */
  #define HRTIM_BDTUPR_TIMEEFR2 0x00010000	/* TIMEEFR2 register update enable */
  #define HRTIM_BDTUPR_TIMRSTR  0x00020000	/* TIMRSTR register update enable */
  #define HRTIM_BDTUPR_TIMCHPR  0x00040000	/* TIMCHPR register update enable */
  #define HRTIM_BDTUPR_TIMOUTR  0x00080000	/* TIMOUTR register update enable */
  #define HRTIM_BDTUPR_TIMFLTR  0x00100000	/* TIMFLTR register update enable */
  #define HRTIM_BDTUPR_TIMCR2   0x00200000	/* TIMCR2 register update enable */
  #define HRTIM_BDTUPR_TIMEEFR3 0x00400000	/* TIMEEFR3 register update enable */
#define TOFF_HRTIM_BDTEUPR  0x03EC		/* (RW) HRTIM Burst DMA Timerx update register */
#define TOFF_HRTIM_BDMADR   0x03F0		/* (RW) HRTIM Burst DMA Master Data register */
#define TOFF_HRTIM_BDTFUPR  0x03F4		/* (RW) HRTIM Burst DMA Timerx update register */
#define TOFF_HRTIM_ADCER    0x03F8		/* (RW) HRTIM ADC Extended Trigger register */
  #define HRTIM_ADCER_AD5TRG    0x0000001F	/* ADC5 trigger */
  #define HRTIM_ADCER_AD6TRG    0x000003E0	/* ADC6 trigger */
  #define HRTIM_ADCER_AD7TRG    0x00007C00	/* ADC7 trigger */
  #define HRTIM_ADCER_AD8TRG    0x001F0000	/* ADC8 trigger */
  #define HRTIM_ADCER_AD9TRG    0x03E00000	/* ADC9 trigger */
  #define HRTIM_ADCER_AD10TRG   0x7C000000	/* ADC10 trigger */
#define TOFF_HRTIM_ADCUR    0x03FC		/* (RW) HRTIM ADC Trigger Update register */
  #define HRTIM_ADCUR_AD5USRC   0x00000007	/* ADC5 trigger Update Source */
  #define HRTIM_ADCUR_AD6USRC   0x00000070	/* ADC6 trigger Update Source */
  #define HRTIM_ADCUR_AD7USRC   0x00000700	/* ADC7 trigger Update Source */
  #define HRTIM_ADCUR_AD8USRC   0x00007000	/* ADC8 trigger Update Source */
  #define HRTIM_ADCUR_AD9USRC   0x00070000	/* ADC9 trigger Update Source */
  #define HRTIM_ADCUR_AD10USRC  0x00700000	/* ADC10 trigger Update Source */
#define TOFF_HRTIM_ADCPS1   0x0400		/* (RW) HRTIM ADC Post Scaler Register 1 */
  #define HRTIM_ADCPS1_AD1PSC   0x0000001F	/* ADC1 post scaler */
  #define HRTIM_ADCPS1_AD2PSC   0x000007C0	/* ADC2 post scaler */
  #define HRTIM_ADCPS1_AD3PSC   0x0001F000	/* ADC3 post scaler */
  #define HRTIM_ADCPS1_AD4PSC   0x007C0000	/* ADC4 post scaler */
  #define HRTIM_ADCPS1_AD5PSC   0x1F000000	/* ADC5 post scaler */
#define TOFF_HRTIM_ADCPS2   0x0404		/* (RW) HRTIM ADC Post Scaler Register 2 */
  #define HRTIM_ADCPS2_AD6PSC   0x0000001F	/* ADC6 post scaler */
  #define HRTIM_ADCPS2_AD7PSC   0x000007C0	/* ADC7 post scaler */
  #define HRTIM_ADCPS2_AD8PSC   0x0001F000	/* ADC8 post scaler */
  #define HRTIM_ADCPS2_AD9PSC   0x007C0000	/* ADC9 post scaler */
  #define HRTIM_ADCPS2_AD10PSC  0x1F000000	/* ADC10 post scaler */
#define TOFF_HRTIM_FLTINR3  0x0408		/* (RW) HRTIM Fault input register3 */
  #define HRTIM_FLTINR3_FLT1BLKE  0x00000001	/* Fault 1 Blanking Enable */
  #define HRTIM_FLTINR3_FLT1BLKS  0x00000002	/* Fault 1 Blanking Source */
  #define HRTIM_FLTINR3_FLT1CNT   0x0000003C	/* Fault 1 Counter */
  #define HRTIM_FLTINR3_FLT1CNT_0 0x00000004
  #define HRTIM_FLTINR3_FLT1CNT_1 0x00000008
  #define HRTIM_FLTINR3_FLT1CNT_2 0x00000010
  #define HRTIM_FLTINR3_FLT1CNT_3 0x00000020
  #define HRTIM_FLTINR3_FLT1CRES  0x00000040	/* Fault 1 Counter Reset  */
  #define HRTIM_FLTINR3_FLT1RSTM  0x00000080	/* Fault 1 Counter Reset Mode */
  #define HRTIM_FLTINR3_FLT2BLKE  0x00000100	/* Fault 2 Blanking Enable */
  #define HRTIM_FLTINR3_FLT2BLKS  0x00000200	/* Fault 2 Blanking Source */
  #define HRTIM_FLTINR3_FLT2CNT   0x00003C00	/* Fault 2 Counter */
  #define HRTIM_FLTINR3_FLT2CNT_0 0x00000400
  #define HRTIM_FLTINR3_FLT2CNT_1 0x00000800
  #define HRTIM_FLTINR3_FLT2CNT_2 0x00001000
  #define HRTIM_FLTINR3_FLT2CNT_3 0x00002000
  #define HRTIM_FLTINR3_FLT2CRES  0x00004000	/* Fault 2 Counter Reset  */
  #define HRTIM_FLTINR3_FLT2RSTM  0x00008000	/* Fault 2 Counter Reset Mode */
  #define HRTIM_FLTINR3_FLT3BLKE  0x00010000	/* Fault 3 Blanking Enable */
  #define HRTIM_FLTINR3_FLT3BLKS  0x00020000	/* Fault 3 Blanking Source */
  #define HRTIM_FLTINR3_FLT3CNT   0x003C0000	/* Fault 3 Counter */
  #define HRTIM_FLTINR3_FLT3CNT_0 0x00040000
  #define HRTIM_FLTINR3_FLT3CNT_1 0x00080000
  #define HRTIM_FLTINR3_FLT3CNT_2 0x00100000
  #define HRTIM_FLTINR3_FLT3CNT_3 0x00200000
  #define HRTIM_FLTINR3_FLT3CRES  0x00400000	/* Fault 3 Counter Reset  */
  #define HRTIM_FLTINR3_FLT3RSTM  0x00800000	/* Fault 3 Counter Reset Mode */
  #define HRTIM_FLTINR3_FLT4BLKE  0x01000000	/* Fault 4 Blanking Enable */
  #define HRTIM_FLTINR3_FLT4BLKS  0x02000000	/* Fault 4 Blanking Source */
  #define HRTIM_FLTINR3_FLT4CNT   0x3C000000	/* Fault 4 Counter */
  #define HRTIM_FLTINR3_FLT4CNT_0 0x04000000
  #define HRTIM_FLTINR3_FLT4CNT_1 0x08000000
  #define HRTIM_FLTINR3_FLT4CNT_2 0x10000000
  #define HRTIM_FLTINR3_FLT4CNT_3 0x20000000
  #define HRTIM_FLTINR3_FLT4CRES  0x40000000	/* Fault 4 Counter Reset  */
  #define HRTIM_FLTINR3_FLT4RSTM  0x80000000	/* Fault 4 Counter Reset Mode */
#define TOFF_HRTIM_FLTINR4  0x040C		/* (RW) HRTIM Fault input register4 */
  #define HRTIM_FLTINR4_FLT5BLKE  0x00000001	/* Fault 5 Blanking Enable */
  #define HRTIM_FLTINR4_FLT5BLKS  0x00000002	/* Fault 5 Blanking Source */
  #define HRTIM_FLTINR4_FLT5CNT   0x0000003C	/* Fault 5 Counter */
  #define HRTIM_FLTINR4_FLT5CNT_0 0x00000004
  #define HRTIM_FLTINR4_FLT5CNT_1 0x00000008
  #define HRTIM_FLTINR4_FLT5CNT_2 0x00000010
  #define HRTIM_FLTINR4_FLT5CNT_3 0x00000020
  #define HRTIM_FLTINR4_FLT5CRES  0x00000040	/* Fault 5 Counter Reset  */
  #define HRTIM_FLTINR4_FLT5RSTM  0x00000080	/* Fault 5 Counter Reset Mode */
  #define HRTIM_FLTINR4_FLT6BLKE  0x00000100	/* Fault 6 Blanking Enable */
  #define HRTIM_FLTINR4_FLT6BLKS  0x00000200	/* Fault 6 Blanking Source */
  #define HRTIM_FLTINR4_FLT6CNT   0x00003C00	/* Fault 6 Counter */
  #define HRTIM_FLTINR4_FLT6CNT_0 0x00000400
  #define HRTIM_FLTINR4_FLT6CNT_1 0x00000800
  #define HRTIM_FLTINR4_FLT6CNT_2 0x00001000
  #define HRTIM_FLTINR4_FLT6CNT_3 0x00002000
  #define HRTIM_FLTINR4_FLT6CRES  0x00004000	/* Fault 6 Counter Reset  */
  #define HRTIM_FLTINR4_FLT6RSTM  0x00008000	/* Fault 6 Counter Reset Mode */

/*
 *  HRTIM TINER A to F REGISTERS
 */
#define HRTIM_WINDOW_SIZE   0x0080
#define TOFF_HRTIM_TIMxCR   0x0000		/* (RW) HRTIM Timerx control register */
  #define HRTIM_TIMCR_CK_PSC    0x00000007	/* Slave prescaler mask*/
  #define HRTIM_TIMCR_CK_PSC_0  0x00000001
  #define HRTIM_TIMCR_CK_PSC_1  0x00000002
  #define HRTIM_TIMCR_CK_PSC_2  0x00000004
  #define HRTIM_TIMCR_CONT      0x00000008	/* Slave continuous mode */
  #define HRTIM_TIMCR_RETRIG    0x00000010	/* Slave Retrigreable mode */
  #define HRTIM_TIMCR_HALF      0x00000020	/* Slave Half mode */
  #define HRTIM_TIMCR_PSHPLL    0x00000040	/* Slave push-pull mode */
  #define HRTIM_TIMCR_INTLVD    0x00000180	/* Interleaved mode */
  #define HRTIM_TIMCR_INTLVD_0  0x00000080
  #define HRTIM_TIMCR_INTLVD_1  0x00000100
  #define HRTIM_TIMCR_RSYNCU    0x00000200	/* Resynchronization update */
  #define HRTIM_TIMCR_SYNCRST   0x00000400	/* Slave synchronization resets */
  #define HRTIM_TIMCR_SYNCSTRT  0x00000800	/* Slave synchronization starts */
  #define HRTIM_TIMCR_DELCMP2   0x00003000	/* Slave delayed compartor 2 mode mask */
  #define HRTIM_TIMCR_DELCMP2_0 0x00001000
  #define HRTIM_TIMCR_DELCMP2_1 0x00002000
  #define HRTIM_TIMCR_DELCMP4   0x0000C000	/* Slave delayed compartor 4 mode mask */
  #define HRTIM_TIMCR_DELCMP4_0 0x00004000
  #define HRTIM_TIMCR_DELCMP4_1 0x00008000
  #define HRTIM_TIMCR_TFU       0x00010000	/* Slave Timer F update reserved for TIM F */
  #define HRTIM_TIMCR_TREPU     0x00020000	/* Slave repetition update */
  #define HRTIM_TIMCR_TRSTU     0x00040000	/* Slave reset update */
  #define HRTIM_TIMCR_TAU       0x00080000	/* Slave Timer A update reserved for TIM A */
  #define HRTIM_TIMCR_TBU       0x00100000	/* Slave Timer B update reserved for TIM B */
  #define HRTIM_TIMCR_TCU       0x00200000	/* Slave Timer C update reserved for TIM C */
  #define HRTIM_TIMCR_TDU       0x00400000	/* Slave Timer D update reserved for TIM D */
  #define HRTIM_TIMCR_TEU       0x00800000	/* Slave Timer E update reserved for TIM E */
  #define HRTIM_TIMCR_MSTU      0x02000000	/* Master Update */
  #define HRTIM_TIMCR_DACSYNC   0x06000000	/* DAC sychronization mask */
  #define HRTIM_TIMCR_DACSYNC_0 0x02000000
  #define HRTIM_TIMCR_DACSYNC_1 0x04000000
  #define HRTIM_TIMCR_PREEN     0x08000000	/* Slave preload enable */
  #define HRTIM_TIMCR_UPDGAT    0xF0000000	/* Slave update gating mask */
  #define HRTIM_TIMCR_UPDGAT_0  0x10000000
  #define HRTIM_TIMCR_UPDGAT_1  0x20000000
  #define HRTIM_TIMCR_UPDGAT_2  0x40000000
  #define HRTIM_TIMCR_UPDGAT_3  0x80000000
#define TOFF_HRTIM_TIMxISR  0x0004		/* (RW) HRTIM Timerx interrupt status register */
  #define HRTIM_TIMISR_CMP1     0x00000001	/* Slave compare 1 interrupt flag */
  #define HRTIM_TIMISR_CMP2     0x00000002	/* Slave compare 2 interrupt flag */
  #define HRTIM_TIMISR_CMP3     0x00000004	/* Slave compare 3 interrupt flag */
  #define HRTIM_TIMISR_CMP4     0x00000008	/* Slave compare 4 interrupt flag */
  #define HRTIM_TIMISR_REP      0x00000010	/* Slave repetition interrupt flag */
  #define HRTIM_TIMISR_UPD      0x00000040	/* Slave update interrupt flag */
  #define HRTIM_TIMISR_CPT1     0x00000080	/* Slave capture 1 interrupt flag */
  #define HRTIM_TIMISR_CPT2     0x00000100	/* Slave capture 2 interrupt flag */
  #define HRTIM_TIMISR_SET1     0x00000200	/* Slave output 1 set interrupt flag */
  #define HRTIM_TIMISR_RST1     0x00000400	/* Slave output 1 reset interrupt flag */
  #define HRTIM_TIMISR_SET2     0x00000800	/* Slave output 2 set interrupt flag */
  #define HRTIM_TIMISR_RST2     0x00001000	/* Slave output 2 reset interrupt flag */
  #define HRTIM_TIMISR_RST      0x00002000	/* Slave reset interrupt flag */
  #define HRTIM_TIMISR_DLYPRT   0x00004000	/* Slave output 1 delay protection interrupt flag */
  #define HRTIM_TIMISR_CPPSTAT  0x00010000	/* Slave current push-pull flag */
  #define HRTIM_TIMISR_IPPSTAT  0x00020000	/* Slave idle push-pull flag */
  #define HRTIM_TIMISR_O1STAT   0x00040000	/* Slave output 1 state flag */
  #define HRTIM_TIMISR_O2STAT   0x00080000	/* Slave output 2 state flag */
  #define HRTIM_TIMISR_O1CPY    0x00100000	/* Slave output 1 copy flag */
  #define HRTIM_TIMISR_O2CPY    0x00200000	/* Slave output 2 copy flag */
#define TOFF_HRTIM_TIMxICR  0x0008		/* (RW) HRTIM Timerx interrupt clear register */
  #define HRTIM_TIMICR_CMP1C    0x00000001	/* Slave compare 1 clear flag */
  #define HRTIM_TIMICR_CMP2C    0x00000002	/* Slave compare 2 clear flag */
  #define HRTIM_TIMICR_CMP3C    0x00000004	/* Slave compare 3 clear flag */
  #define HRTIM_TIMICR_CMP4C    0x00000008	/* Slave compare 4 clear flag */
  #define HRTIM_TIMICR_REPC     0x00000010	/* Slave repetition clear flag */
  #define HRTIM_TIMICR_UPDC     0x00000040	/* Slave update clear flag */
  #define HRTIM_TIMICR_CPT1C    0x00000080	/* Slave capture 1 clear flag */
  #define HRTIM_TIMICR_CPT2C    0x00000100	/* Slave capture 2 clear flag */
  #define HRTIM_TIMICR_SET1C    0x00000200	/* Slave output 1 set clear flag */
  #define HRTIM_TIMICR_RST1C    0x00000400	/* Slave output 1 reset clear flag */
  #define HRTIM_TIMICR_SET2C    0x00000800	/* Slave output 2 set clear flag */
  #define HRTIM_TIMICR_RST2C    0x00001000	/* Slave output 2 reset clear flag */
  #define HRTIM_TIMICR_RSTC     0x00002000	/* Slave reset clear flag */
  #define HRTIM_TIMICR_DLYPRTC  0x00004000	/* Slave output delay protection clear flag */
#define TOFF_HRTIM_TIMxDIER 0x000C		/* (RW) HRTIM Timerx DMA/interrupt enable register */
  #define HRTIM_TIMDIER_CMP1IE  0x00000001	/* Slave compare 1 interrupt enable */
  #define HRTIM_TIMDIER_CMP2IE  0x00000002	/* Slave compare 2 interrupt enable */
  #define HRTIM_TIMDIER_CMP3IE  0x00000004	/* Slave compare 3 interrupt enable */
  #define HRTIM_TIMDIER_CMP4IE  0x00000008	/* Slave compare 4 interrupt enable */
  #define HRTIM_TIMDIER_REPIE   0x00000010	/* Slave repetition interrupt enable */
  #define HRTIM_TIMDIER_UPDIE   0x00000040	/* Slave update interrupt enable */
  #define HRTIM_TIMDIER_CPT1IE  0x00000080	/* Slave capture 1 interrupt enable */
  #define HRTIM_TIMDIER_CPT2IE  0x00000100	/* Slave capture 2 interrupt enable */
  #define HRTIM_TIMDIER_SET1IE  0x00000200	/* Slave output 1 set interrupt enable */
  #define HRTIM_TIMDIER_RST1IE  0x00000400	/* Slave output 1 reset interrupt enable */
  #define HRTIM_TIMDIER_SET2IE  0x00000800	/* Slave output 2 set interrupt enable */
  #define HRTIM_TIMDIER_RST2IE  0x00001000	/* Slave output 2 reset interrupt enable */
  #define HRTIM_TIMDIER_RSTIE   0x00002000	/* Slave reset interrupt enable */
  #define HRTIM_TIMDIER_DLYPRTIE 0x00004000	/* Slave delay protection interrupt enable */
  #define HRTIM_TIMDIER_CMP1DE  0x00010000	/* Slave compare 1 request enable */
  #define HRTIM_TIMDIER_CMP2DE  0x00020000	/* Slave compare 2 request enable */
  #define HRTIM_TIMDIER_CMP3DE  0x00040000	/* Slave compare 3 request enable */
  #define HRTIM_TIMDIER_CMP4DE  0x00080000	/* Slave compare 4 request enable */
  #define HRTIM_TIMDIER_REPDE   0x00100000	/* Slave repetition request enable */
  #define HRTIM_TIMDIER_UPDDE   0x00400000	/* Slave update request enable */
  #define HRTIM_TIMDIER_CPT1DE  0x00800000	/* Slave capture 1 request enable */
  #define HRTIM_TIMDIER_CPT2DE  0x01000000	/* Slave capture 2 request enable */
  #define HRTIM_TIMDIER_SET1DE  0x02000000	/* Slave output 1 set request enable */
  #define HRTIM_TIMDIER_RST1DE  0x04000000	/* Slave output 1 reset request enable */
  #define HRTIM_TIMDIER_SET2DE  0x08000000	/* Slave output 2 set request enable */
  #define HRTIM_TIMDIER_RST2DE  0x10000000	/* Slave output 2 reset request enable */
  #define HRTIM_TIMDIER_RSTDE   0x20000000	/* Slave reset request enable */
  #define HRTIM_TIMDIER_DLYPRTDE 0x40000000	/* Slavedelay protection request enable */
#define TOFF_HRTIM_CNTxR    0x0010		/* (RW) HRTIM Timerx counter register */
#define TOFF_HRTIM_PERxR    0x0014		/* (RW) HRTIM Timerx period register */
#define TOFF_HRTIM_REPxR    0x0018		/* (RW) HRTIM Timerx repetition register */
#define TOFF_HRTIM_CMP1xR   0x001C		/* (RW) HRTIM Timerx compare 1 register */
#define TOFF_HRTIM_CMP1CxR  0x0020		/* (RW) HRTIM Timerx compare 1 compound register */
#define TOFF_HRTIM_CMP2xR   0x0024		/* (RW) HRTIM Timerx compare 2 register */
#define TOFF_HRTIM_CMP3xR   0x0028		/* (RW) HRTIM Timerx compare 3 register */
#define TOFF_HRTIM_CMP4xR   0x002C		/* (RW) HRTIM Timerx compare 4 register */
#define TOFF_HRTIM_CPT1xR   0x0030		/* (RW) HRTIM Timerx capture 1 register */
#define TOFF_HRTIM_CPT2xR   0x0034		/* (RW) HRTIM Timerx capture 2 register */
#define TOFF_HRTIM_DTxR     0x0038		/* (RW) HRTIM Timerx dead time register */
  #define HRTIM_DTR_DTR         0x000001FF	/* Dead time rising value */
  #define HRTIM_DTR_DTR_0       0x00000001
  #define HRTIM_DTR_DTR_1       0x00000002
  #define HRTIM_DTR_DTR_2       0x00000004
  #define HRTIM_DTR_DTR_3       0x00000008
  #define HRTIM_DTR_DTR_4       0x00000010
  #define HRTIM_DTR_DTR_5       0x00000020
  #define HRTIM_DTR_DTR_6       0x00000040
  #define HRTIM_DTR_DTR_7       0x00000080
  #define HRTIM_DTR_DTR_8       0x00000100
  #define HRTIM_DTR_SDTR        0x00000200	/* Sign dead time rising value */
  #define HRTIM_DTR_DTPRSC      0x00001C00	/* Dead time prescaler */
  #define HRTIM_DTR_DTPRSC_0    0x00000400
  #define HRTIM_DTR_DTPRSC_1    0x00000800
  #define HRTIM_DTR_DTPRSC_2    0x00001000
  #define HRTIM_DTR_DTRSLK      0x00004000	/* Dead time rising sign lock */
  #define HRTIM_DTR_DTRLK       0x00008000	/* Dead time rising lock */
  #define HRTIM_DTR_DTF         0x01FF0000	/* Dead time falling value */
  #define HRTIM_DTR_DTF_0       0x00010000
  #define HRTIM_DTR_DTF_1       0x00020000
  #define HRTIM_DTR_DTF_2       0x00040000
  #define HRTIM_DTR_DTF_3       0x00080000
  #define HRTIM_DTR_DTF_4       0x00100000
  #define HRTIM_DTR_DTF_5       0x00200000
  #define HRTIM_DTR_DTF_6       0x00400000
  #define HRTIM_DTR_DTF_7       0x00800000
  #define HRTIM_DTR_DTF_8       0x01000000
  #define HRTIM_DTR_SDTF        0x02000000	/* Sign dead time falling value */
  #define HRTIM_DTR_DTFSLK      0x40000000	/* Dead time falling sign lock */
  #define HRTIM_DTR_DTFLK       0x80000000	/* Dead time falling lock */
#define TOFF_HRTIM_SETx1R   0x003C		/* (RW) HRTIM Timerx output 1 set register */
  #define HRTIM_SET1R_SST       0x00000001	/* software set trigger */
  #define HRTIM_SET1R_RESYNC    0x00000002	/* Timer A resynchronization */
  #define HRTIM_SET1R_PER       0x00000004	/* Timer A period */
  #define HRTIM_SET1R_CMP1      0x00000008	/* Timer A compare 1 */
  #define HRTIM_SET1R_CMP2      0x00000010	/* Timer A compare 2 */
  #define HRTIM_SET1R_CMP3      0x00000020	/* Timer A compare 3 */
  #define HRTIM_SET1R_CMP4      0x00000040	/* Timer A compare 4 */
  #define HRTIM_SET1R_MSTPER    0x00000080	/* Master period */
  #define HRTIM_SET1R_MSTCMP1   0x00000100	/* Master compare 1 */
  #define HRTIM_SET1R_MSTCMP2   0x00000200	/* Master compare 2 */
  #define HRTIM_SET1R_MSTCMP3   0x00000400	/* Master compare 3 */
  #define HRTIM_SET1R_MSTCMP4   0x00000800	/* Master compare 4 */
  #define HRTIM_SET1R_TIMEVNT1  0x00001000	/* Timer event 1 */
  #define HRTIM_SET1R_TIMEVNT2  0x00002000	/* Timer event 2 */
  #define HRTIM_SET1R_TIMEVNT3  0x00004000	/* Timer event 3 */
  #define HRTIM_SET1R_TIMEVNT4  0x00008000	/* Timer event 4 */
  #define HRTIM_SET1R_TIMEVNT5  0x00010000	/* Timer event 5 */
  #define HRTIM_SET1R_TIMEVNT6  0x00020000	/* Timer event 6 */
  #define HRTIM_SET1R_TIMEVNT7  0x00040000	/* Timer event 7 */
  #define HRTIM_SET1R_TIMEVNT8  0x00080000	/* Timer event 8 */
  #define HRTIM_SET1R_TIMEVNT9  0x00100000	/* Timer event 9 */
  #define HRTIM_SET1R_EXTVNT1   0x00200000	/* External event 1 */
  #define HRTIM_SET1R_EXTVNT2   0x00400000	/* External event 2 */
  #define HRTIM_SET1R_EXTVNT3   0x00800000	/* External event 3 */
  #define HRTIM_SET1R_EXTVNT4   0x01000000	/* External event 4 */
  #define HRTIM_SET1R_EXTVNT5   0x02000000	/* External event 5 */
  #define HRTIM_SET1R_EXTVNT6   0x04000000	/* External event 6 */
  #define HRTIM_SET1R_EXTVNT7   0x08000000	/* External event 7 */
  #define HRTIM_SET1R_EXTVNT8   0x10000000	/* External event 8 */
  #define HRTIM_SET1R_EXTVNT9   0x20000000	/* External event 9 */
  #define HRTIM_SET1R_EXTVNT10  0x40000000	/* External event 10 */
  #define HRTIM_SET1R_UPDATE    0x80000000	/* Register update (transfer preload to active) */
#define TOFF_HRTIM_RSTx1R   0x0040		/* (RW) HRTIM Timerx output 1 reset register */
  #define HRTIM_RST1R_SRT       0x00000001	/* software reset trigger */
  #define HRTIM_RST1R_RESYNC    0x00000002	/* Timer A resynchronization */
  #define HRTIM_RST1R_PER       0x00000004	/* Timer A period */
  #define HRTIM_RST1R_CMP1      0x00000008	/* Timer A compare 1 */
  #define HRTIM_RST1R_CMP2      0x00000010	/* Timer A compare 2 */
  #define HRTIM_RST1R_CMP3      0x00000020	/* Timer A compare 3 */
  #define HRTIM_RST1R_CMP4      0x00000040	/* Timer A compare 4 */
  #define HRTIM_RST1R_MSTPER    0x00000080	/* Master period */
  #define HRTIM_RST1R_MSTCMP1   0x00000100	/* Master compare 1 */
  #define HRTIM_RST1R_MSTCMP2   0x00000200	/* Master compare 2 */
  #define HRTIM_RST1R_MSTCMP3   0x00000400	/* Master compare 3 */
  #define HRTIM_RST1R_MSTCMP4   0x00000800	/* Master compare 4 */
  #define HRTIM_RST1R_TIMEVNT1  0x00001000	/* Timer event 1 */
  #define HRTIM_RST1R_TIMEVNT2  0x00002000	/* Timer event 2 */
  #define HRTIM_RST1R_TIMEVNT3  0x00004000	/* Timer event 3 */
  #define HRTIM_RST1R_TIMEVNT4  0x00008000	/* Timer event 4 */
  #define HRTIM_RST1R_TIMEVNT5  0x00010000	/* Timer event 5 */
  #define HRTIM_RST1R_TIMEVNT6  0x00020000	/* Timer event 6 */
  #define HRTIM_RST1R_TIMEVNT7  0x00040000	/* Timer event 7 */
  #define HRTIM_RST1R_TIMEVNT8  0x00080000	/* Timer event 8 */
  #define HRTIM_RST1R_TIMEVNT9  0x00100000	/* Timer event 9 */
  #define HRTIM_RST1R_EXTVNT1   0x00200000	/* External event 1 */
  #define HRTIM_RST1R_EXTVNT2   0x00400000	/* External event 2 */
  #define HRTIM_RST1R_EXTVNT3   0x00800000	/* External event 3 */
  #define HRTIM_RST1R_EXTVNT4   0x01000000	/* External event 4 */
  #define HRTIM_RST1R_EXTVNT5   0x02000000	/* External event 5 */
  #define HRTIM_RST1R_EXTVNT6   0x04000000	/* External event 6 */
  #define HRTIM_RST1R_EXTVNT7   0x08000000	/* External event 7 */
  #define HRTIM_RST1R_EXTVNT8   0x10000000	/* External event 8 */
  #define HRTIM_RST1R_EXTVNT9   0x20000000	/* External event 9 */
  #define HRTIM_RST1R_EXTVNT10  0x40000000	/* External event 10 */
  #define HRTIM_RST1R_UPDATE    0x80000000	/* Register update (transfer preload to active) */
#define TOFF_HRTIM_SETx2R   0x0044		/* (RW) HRTIM Timerx output 2 set register */
  #define HRTIM_SET2R_SST       0x00000001	/* software set trigger */
  #define HRTIM_SET2R_RESYNC    0x00000002	/* Timer A resynchronization */
  #define HRTIM_SET2R_PER       0x00000004	/* Timer A period */
  #define HRTIM_SET2R_CMP1      0x00000008	/* Timer A compare 1 */
  #define HRTIM_SET2R_CMP2      0x00000010	/* Timer A compare 2 */
  #define HRTIM_SET2R_CMP3      0x00000020	/* Timer A compare 3 */
  #define HRTIM_SET2R_CMP4      0x00000040	/* Timer A compare 4 */
  #define HRTIM_SET2R_MSTPER    0x00000080	/* Master period */
  #define HRTIM_SET2R_MSTCMP1   0x00000100	/* Master compare 1 */
  #define HRTIM_SET2R_MSTCMP2   0x00000200	/* Master compare 2 */
  #define HRTIM_SET2R_MSTCMP3   0x00000400	/* Master compare 3 */
  #define HRTIM_SET2R_MSTCMP4   0x00000800	/* Master compare 4 */
  #define HRTIM_SET2R_TIMEVNT1  0x00001000	/* Timer event 1 */
  #define HRTIM_SET2R_TIMEVNT2  0x00002000	/* Timer event 2 */
  #define HRTIM_SET2R_TIMEVNT3  0x00004000	/* Timer event 3 */
  #define HRTIM_SET2R_TIMEVNT4  0x00008000	/* Timer event 4 */
  #define HRTIM_SET2R_TIMEVNT5  0x00010000	/* Timer event 5 */
  #define HRTIM_SET2R_TIMEVNT6  0x00020000	/* Timer event 6 */
  #define HRTIM_SET2R_TIMEVNT7  0x00040000	/* Timer event 7 */
  #define HRTIM_SET2R_TIMEVNT8  0x00080000	/* Timer event 8 */
  #define HRTIM_SET2R_TIMEVNT9  0x00100000	/* Timer event 9 */
  #define HRTIM_SET2R_EXTVNT1   0x00200000	/* External event 1 */
  #define HRTIM_SET2R_EXTVNT2   0x00400000	/* External event 2 */
  #define HRTIM_SET2R_EXTVNT3   0x00800000	/* External event 3 */
  #define HRTIM_SET2R_EXTVNT4   0x01000000	/* External event 4 */
  #define HRTIM_SET2R_EXTVNT5   0x02000000	/* External event 5 */
  #define HRTIM_SET2R_EXTVNT6   0x04000000	/* External event 6 */
  #define HRTIM_SET2R_EXTVNT7   0x08000000	/* External event 7 */
  #define HRTIM_SET2R_EXTVNT8   0x10000000	/* External event 8 */
  #define HRTIM_SET2R_EXTVNT9   0x20000000	/* External event 9 */
  #define HRTIM_SET2R_EXTVNT10  0x40000000	/* External event 10 */
  #define HRTIM_SET2R_UPDATE    0x80000000	/* Register update (transfer preload to active) */
#define TOFF_HRTIM_RSTx2R   0x0048		/* (RW) HRTIM Timerx output 2 reset register */
  #define HRTIM_RST2R_SRT       0x00000001	/* software reset trigger */
  #define HRTIM_RST2R_RESYNC    0x00000002	/* Timer A resynchronization */
  #define HRTIM_RST2R_PER       0x00000004	/* Timer A period */
  #define HRTIM_RST2R_CMP1      0x00000008	/* Timer A compare 1 */
  #define HRTIM_RST2R_CMP2      0x00000010	/* Timer A compare 2 */
  #define HRTIM_RST2R_CMP3      0x00000020	/* Timer A compare 3 */
  #define HRTIM_RST2R_CMP4      0x00000040	/* Timer A compare 4 */
  #define HRTIM_RST2R_MSTPER    0x00000080	/* Master period */
  #define HRTIM_RST2R_MSTCMP1   0x00000100	/* Master compare 1 */
  #define HRTIM_RST2R_MSTCMP2   0x00000200	/* Master compare 2 */
  #define HRTIM_RST2R_MSTCMP3   0x00000400	/* Master compare 3 */
  #define HRTIM_RST2R_MSTCMP4   0x00000800	/* Master compare 4 */
  #define HRTIM_RST2R_TIMEVNT1  0x00001000	/* Timer event 1 */
  #define HRTIM_RST2R_TIMEVNT2  0x00002000	/* Timer event 2 */
  #define HRTIM_RST2R_TIMEVNT3  0x00004000	/* Timer event 3 */
  #define HRTIM_RST2R_TIMEVNT4  0x00008000	/* Timer event 4 */
  #define HRTIM_RST2R_TIMEVNT5  0x00010000	/* Timer event 5 */
  #define HRTIM_RST2R_TIMEVNT6  0x00020000	/* Timer event 6 */
  #define HRTIM_RST2R_TIMEVNT7  0x00040000	/* Timer event 7 */
  #define HRTIM_RST2R_TIMEVNT8  0x00080000	/* Timer event 8 */
  #define HRTIM_RST2R_TIMEVNT9  0x00100000	/* Timer event 9 */
  #define HRTIM_RST2R_EXTVNT1   0x00200000	/* External event 1 */
  #define HRTIM_RST2R_EXTVNT2   0x00400000	/* External event 2 */
  #define HRTIM_RST2R_EXTVNT3   0x00800000	/* External event 3 */
  #define HRTIM_RST2R_EXTVNT4   0x01000000	/* External event 4 */
  #define HRTIM_RST2R_EXTVNT5   0x02000000	/* External event 5 */
  #define HRTIM_RST2R_EXTVNT6   0x04000000	/* External event 6 */
  #define HRTIM_RST2R_EXTVNT7   0x08000000	/* External event 7 */
  #define HRTIM_RST2R_EXTVNT8   0x10000000	/* External event 8 */
  #define HRTIM_RST2R_EXTVNT9   0x20000000	/* External event 9 */
  #define HRTIM_RST2R_EXTVNT10  0x40000000	/* External event 10 */
  #define HRTIM_RST2R_UPDATE    0x80000000	/* Register update (transfer preload to active) */
#define TOFF_HRTIM_EEFxR1   0x004C		/* (RW) HRTIM Timerx external event filtering 1 register */
  #define HRTIM_EEFR1_EE1LTCH   0x00000001	/* External Event 1 latch */
  #define HRTIM_EEFR1_EE1FLTR   0x0000001E	/* External Event 1 filter mask */
  #define HRTIM_EEFR1_EE1FLTR_0 0x00000002
  #define HRTIM_EEFR1_EE1FLTR_1 0x00000004
  #define HRTIM_EEFR1_EE1FLTR_2 0x00000008
  #define HRTIM_EEFR1_EE1FLTR_3 0x00000010
  #define HRTIM_EEFR1_EE2LTCH   0x00000040	/* External Event 2 latch */
  #define HRTIM_EEFR1_EE2FLTR   0x00000780	/* External Event 2 filter mask */
  #define HRTIM_EEFR1_EE2FLTR_0 0x00000080
  #define HRTIM_EEFR1_EE2FLTR_1 0x00000100
  #define HRTIM_EEFR1_EE2FLTR_2 0x00000200
  #define HRTIM_EEFR1_EE2FLTR_3 0x00000400
  #define HRTIM_EEFR1_EE3LTCH   0x00001000	/* External Event 3 latch */
  #define HRTIM_EEFR1_EE3FLTR   0x0001E000	/* External Event 3 filter mask */
  #define HRTIM_EEFR1_EE3FLTR_0 0x00002000
  #define HRTIM_EEFR1_EE3FLTR_1 0x00004000
  #define HRTIM_EEFR1_EE3FLTR_2 0x00008000
  #define HRTIM_EEFR1_EE3FLTR_3 0x00010000
  #define HRTIM_EEFR1_EE4LTCH   0x00040000	/* External Event 4 latch */
  #define HRTIM_EEFR1_EE4FLTR   0x00780000	/* External Event 4 filter mask */
  #define HRTIM_EEFR1_EE4FLTR_0 0x00080000
  #define HRTIM_EEFR1_EE4FLTR_1 0x00100000
  #define HRTIM_EEFR1_EE4FLTR_2 0x00200000
  #define HRTIM_EEFR1_EE4FLTR_3 0x00400000
  #define HRTIM_EEFR1_EE5LTCH   0x01000000	/* External Event 5 latch */
  #define HRTIM_EEFR1_EE5FLTR   0x1E000000	/* External Event 5 filter mask */
  #define HRTIM_EEFR1_EE5FLTR_0 0x02000000
  #define HRTIM_EEFR1_EE5FLTR_1 0x04000000
  #define HRTIM_EEFR1_EE5FLTR_2 0x08000000
  #define HRTIM_EEFR1_EE5FLTR_3 0x10000000
#define TOFF_HRTIM_EEFxR2   0x0050		/* (RW) HRTIM Timerx external event filtering 2 register */
  #define HRTIM_EEFR2_EE6LTCH   0x00000001	/* External Event 6 latch */
  #define HRTIM_EEFR2_EE6FLTR   0x0000001E	/* External Event 6 filter mask */
  #define HRTIM_EEFR2_EE6FLTR_0 0x00000002
  #define HRTIM_EEFR2_EE6FLTR_1 0x00000004
  #define HRTIM_EEFR2_EE6FLTR_2 0x00000008
  #define HRTIM_EEFR2_EE6FLTR_3 0x00000010
  #define HRTIM_EEFR2_EE7LTCH   0x00000040	/* External Event 7 latch */
  #define HRTIM_EEFR2_EE7FLTR   0x00000780	/* External Event 7 filter mask */
  #define HRTIM_EEFR2_EE7FLTR_0 0x00000080
  #define HRTIM_EEFR2_EE7FLTR_1 0x00000100
  #define HRTIM_EEFR2_EE7FLTR_2 0x00000200
  #define HRTIM_EEFR2_EE7FLTR_3 0x00000400
  #define HRTIM_EEFR2_EE8LTCH   0x00001000	/* External Event 8 latch */
  #define HRTIM_EEFR2_EE8FLTR   0x0001E000	/* External Event 8 filter mask */
  #define HRTIM_EEFR2_EE8FLTR_0 0x00002000
  #define HRTIM_EEFR2_EE8FLTR_1 0x00004000
  #define HRTIM_EEFR2_EE8FLTR_2 0x00008000
  #define HRTIM_EEFR2_EE8FLTR_3 0x00010000
  #define HRTIM_EEFR2_EE9LTCH   0x00040000	/* External Event 9 latch */
  #define HRTIM_EEFR2_EE9FLTR   0x00780000	/* External Event 9 filter mask */
  #define HRTIM_EEFR2_EE9FLTR_0 0x00080000
  #define HRTIM_EEFR2_EE9FLTR_1 0x00100000
  #define HRTIM_EEFR2_EE9FLTR_2 0x00200000
  #define HRTIM_EEFR2_EE9FLTR_3 0x00400000
  #define HRTIM_EEFR2_EE10LTCH  0x01000000	/* External Event 10 latch */
  #define HRTIM_EEFR2_EE10FLTR  0x1E000000	/* External Event 10 filter mask */
  #define HRTIM_EEFR2_EE10FLTR_0 0x02000000
  #define HRTIM_EEFR2_EE10FLTR_1 0x04000000
  #define HRTIM_EEFR2_EE10FLTR_2 0x08000000
  #define HRTIM_EEFR2_EE10FLTR_3 0x10000000
#define TOFF_HRTIM_RSTxR    0x0054		/* (RW) HRTIM Timerx Reset register */
  #define HRTIM_RSTR_TIMFCMP1   0x00000001	/* Timer F compare 1 */
  #define HRTIM_RSTR_UPDATE     0x00000002	/* Timer update */
  #define HRTIM_RSTR_CMP2       0x00000004	/* Timer compare2 */
  #define HRTIM_RSTR_CMP4       0x00000008	/* Timer compare4 */
  #define HRTIM_RSTR_MSTPER     0x00000010	/* Master period */
  #define HRTIM_RSTR_MSTCMP1    0x00000020	/* Master compare1 */
  #define HRTIM_RSTR_MSTCMP2    0x00000040	/* Master compare2 */
  #define HRTIM_RSTR_MSTCMP3    0x00000080	/* Master compare3 */
  #define HRTIM_RSTR_MSTCMP4    0x00000100	/* Master compare4 */
  #define HRTIM_RSTR_EXTEVNT1   0x00000200	/* External event 1 */
  #define HRTIM_RSTR_EXTEVNT2   0x00000400	/* External event 2 */
  #define HRTIM_RSTR_EXTEVNT3   0x00000800	/* External event 3 */
  #define HRTIM_RSTR_EXTEVNT4   0x00001000	/* External event 4 */
  #define HRTIM_RSTR_EXTEVNT5   0x00002000	/* External event 5 */
  #define HRTIM_RSTR_EXTEVNT6   0x00004000	/* External event 6 */
  #define HRTIM_RSTR_EXTEVNT7   0x00008000	/* External event 7 */
  #define HRTIM_RSTR_EXTEVNT8   0x00010000	/* External event 8 */
  #define HRTIM_RSTR_EXTEVNT9   0x00020000	/* External event 9 */
  #define HRTIM_RSTR_EXTEVNT10  0x00040000	/* External event 10 */
  #define HRTIM_RSTR_TIMBCMP1   0x00080000	/* Timer B compare 1 */
  #define HRTIM_RSTR_TIMBCMP2   0x00100000	/* Timer B compare 2 */
  #define HRTIM_RSTR_TIMBCMP4   0x00200000	/* Timer B compare 4 */
  #define HRTIM_RSTR_TIMCCMP1   0x00400000	/* Timer C compare 1 */
  #define HRTIM_RSTR_TIMCCMP2   0x00800000	/* Timer C compare 2 */
  #define HRTIM_RSTR_TIMCCMP4   0x01000000	/* Timer C compare 4 */
  #define HRTIM_RSTR_TIMDCMP1   0x02000000	/* Timer D compare 1 */
  #define HRTIM_RSTR_TIMDCMP2   0x04000000	/* Timer D compare 2 */
  #define HRTIM_RSTR_TIMDCMP4   0x08000000	/* Timer D compare 4 */
  #define HRTIM_RSTR_TIMECMP1   0x10000000	/* Timer E compare 1 */
  #define HRTIM_RSTR_TIMECMP2   0x20000000	/* Timer E compare 2 */
  #define HRTIM_RSTR_TIMECMP4   0x40000000	/* Timer E compare 4 */
  #define HRTIM_RSTR_TIMFCMP2   0x80000000	/* Timer F compare 2 */
#define TOFF_HRTIM_CHPxR    0x0058		/* (RW) HRTIM Timerx Chopper register */
  #define HRTIM_CHPR_CARFRQ     0x0000000F	/* Timer carrier frequency value */
  #define HRTIM_CHPR_CARFRQ_0   0x00000001
  #define HRTIM_CHPR_CARFRQ_1   0x00000002
  #define HRTIM_CHPR_CARFRQ_2   0x00000004
  #define HRTIM_CHPR_CARFRQ_3   0x00000008
  #define HRTIM_CHPR_CARDTY     0x00000070	/* Timer chopper duty cycle value */
  #define HRTIM_CHPR_CARDTY_0   0x00000010
  #define HRTIM_CHPR_CARDTY_1   0x00000020
  #define HRTIM_CHPR_CARDTY_2   0x00000040
  #define HRTIM_CHPR_STRPW      0x00000780	/* Timer start pulse width value */
  #define HRTIM_CHPR_STRPW_0    0x00000080
  #define HRTIM_CHPR_STRPW_1    0x00000100
  #define HRTIM_CHPR_STRPW_2    0x00000200
  #define HRTIM_CHPR_STRPW_3    0x00000400
#define TOFF_HRTIM_CPT1xCR  0x005C		/* (RW) HRTIM Timerx Capture 1 register */
  #define HRTIM_CPT1CR_SWCPT    0x00000001	/* Software capture */
  #define HRTIM_CPT1CR_UPDCPT   0x00000002	/* Update capture */
  #define HRTIM_CPT1CR_EXEV1CPT 0x00000004	/* External event 1 capture */
  #define HRTIM_CPT1CR_EXEV2CPT 0x00000008	/* External event 2 capture */
  #define HRTIM_CPT1CR_EXEV3CPT 0x00000010	/* External event 3 capture */
  #define HRTIM_CPT1CR_EXEV4CPT 0x00000020	/* External event 4 capture */
  #define HRTIM_CPT1CR_EXEV5CPT 0x00000040	/* External event 5 capture */
  #define HRTIM_CPT1CR_EXEV6CPT 0x00000080	/* External event 6 capture */
  #define HRTIM_CPT1CR_EXEV7CPT 0x00000100	/* External event 7 capture */
  #define HRTIM_CPT1CR_EXEV8CPT 0x00000200	/* External event 8 capture */
  #define HRTIM_CPT1CR_EXEV9CPT 0x00000400	/* External event 9 capture */
  #define HRTIM_CPT1CR_EXEV10CPT 0x00000800	/* External event 10 capture */
  #define HRTIM_CPT1CR_TF1SET   0x00000001	/* Timer F output 1 set */
  #define HRTIM_CPT1CR_TF1RST   0x00000002	/* Timer F output 1 reset */
  #define HRTIM_CPT1CR_TIMFCMP1 0x00000004	/* Timer F compare 1 */
  #define HRTIM_CPT1CR_TIMFCMP2 0x00000008	/* Timer F compare 2 */
  #define HRTIM_CPT1CR_TA1SET   0x00001000	/* Timer A output 1 set */
  #define HRTIM_CPT1CR_TA1RST   0x00002000	/* Timer A output 1 reset */
  #define HRTIM_CPT1CR_TIMACMP1 0x00004000	/* Timer A compare 1 */
  #define HRTIM_CPT1CR_TIMACMP2 0x00008000	/* Timer A compare 2 */
  #define HRTIM_CPT1CR_TB1SET   0x00010000	/* Timer B output 1 set */
  #define HRTIM_CPT1CR_TB1RST   0x00020000	/* Timer B output 1 reset */
  #define HRTIM_CPT1CR_TIMBCMP1 0x00040000	/* Timer B compare 1 */
  #define HRTIM_CPT1CR_TIMBCMP2 0x00080000	/* Timer B compare 2 */
  #define HRTIM_CPT1CR_TC1SET   0x00100000	/* Timer C output 1 set */
  #define HRTIM_CPT1CR_TC1RST   0x00200000	/* Timer C output 1 reset */
  #define HRTIM_CPT1CR_TIMCCMP1 0x00400000	/* Timer C compare 1 */
  #define HRTIM_CPT1CR_TIMCCMP2 0x00800000	/* Timer C compare 2 */
  #define HRTIM_CPT1CR_TD1SET   0x01000000	/* Timer D output 1 set */
  #define HRTIM_CPT1CR_TD1RST   0x02000000	/* Timer D output 1 reset */
  #define HRTIM_CPT1CR_TIMDCMP1 0x04000000	/* Timer D compare 1 */
  #define HRTIM_CPT1CR_TIMDCMP2 0x08000000	/* Timer D compare 2 */
  #define HRTIM_CPT1CR_TE1SET   0x10000000	/* Timer E output 1 set */
  #define HRTIM_CPT1CR_TE1RST   0x20000000	/* Timer E output 1 reset */
  #define HRTIM_CPT1CR_TIMECMP1 0x40000000	/* Timer E compare 1 */
  #define HRTIM_CPT1CR_TIMECMP2 0x80000000	/* Timer E compare 2 */
#define TOFF_HRTIM_CPT2xCR  0x0060		/* (RW) HRTIM Timerx Capture 2 register */
  #define HRTIM_CPT2CR_SWCPT    0x00000001	/* Software capture */
  #define HRTIM_CPT2CR_UPDCPT   0x00000002	/* Update capture */
  #define HRTIM_CPT2CR_EXEV1CPT 0x00000004	/* External event 1 capture */
  #define HRTIM_CPT2CR_EXEV2CPT 0x00000008	/* External event 2 capture */
  #define HRTIM_CPT2CR_EXEV3CPT 0x00000010	/* External event 3 capture */
  #define HRTIM_CPT2CR_EXEV4CPT 0x00000020	/* External event 4 capture */
  #define HRTIM_CPT2CR_EXEV5CPT 0x00000040	/* External event 5 capture */
  #define HRTIM_CPT2CR_EXEV6CPT 0x00000080	/* External event 6 capture */
  #define HRTIM_CPT2CR_EXEV7CPT 0x00000100	/* External event 7 capture */
  #define HRTIM_CPT2CR_EXEV8CPT 0x00000200	/* External event 8 capture */
  #define HRTIM_CPT2CR_EXEV9CPT 0x00000400	/* External event 9 capture */
  #define HRTIM_CPT2CR_EXEV10CPT 0x00000800	/* External event 10 capture */
  #define HRTIM_CPT2CR_TF1SET   0x00000001	/* Timer F output 1 set */
  #define HRTIM_CPT2CR_TF1RST   0x00000002	/* Timer F output 1 reset */
  #define HRTIM_CPT2CR_TIMFCMP1 0x00000004	/* Timer F compare 1 */
  #define HRTIM_CPT2CR_TIMFCMP2 0x00000008	/* Timer F compare 2 */
  #define HRTIM_CPT2CR_TA1SET   0x00001000	/* Timer A output 1 set */
  #define HRTIM_CPT2CR_TA1RST   0x00002000	/* Timer A output 1 reset */
  #define HRTIM_CPT2CR_TIMACMP1 0x00004000	/* Timer A compare 1 */
  #define HRTIM_CPT2CR_TIMACMP2 0x00008000	/* Timer A compare 2 */
  #define HRTIM_CPT2CR_TB1SET   0x00010000	/* Timer B output 1 set */
  #define HRTIM_CPT2CR_TB1RST   0x00020000	/* Timer B output 1 reset */
  #define HRTIM_CPT2CR_TIMBCMP1 0x00040000	/* Timer B compare 1 */
  #define HRTIM_CPT2CR_TIMBCMP2 0x00080000	/* Timer B compare 2 */
  #define HRTIM_CPT2CR_TC1SET   0x00100000	/* Timer C output 1 set */
  #define HRTIM_CPT2CR_TC1RST   0x00200000	/* Timer C output 1 reset */
  #define HRTIM_CPT2CR_TIMCCMP1 0x00400000	/* Timer C compare 1 */
  #define HRTIM_CPT2CR_TIMCCMP2 0x00800000	/* Timer C compare 2 */
  #define HRTIM_CPT2CR_TD1SET   0x01000000	/* Timer D output 1 set */
  #define HRTIM_CPT2CR_TD1RST   0x02000000	/* Timer D output 1 reset */
  #define HRTIM_CPT2CR_TIMDCMP1 0x04000000	/* Timer D compare 1 */
  #define HRTIM_CPT2CR_TIMDCMP2 0x08000000	/* Timer D compare 2 */
  #define HRTIM_CPT2CR_TE1SET   0x10000000	/* Timer E output 1 set */
  #define HRTIM_CPT2CR_TE1RST   0x20000000	/* Timer E output 1 reset */
  #define HRTIM_CPT2CR_TIMECMP1 0x40000000	/* Timer E compare 1 */
  #define HRTIM_CPT2CR_TIMECMP2 0x80000000	/* Timer E compare 2 */
#define TOFF_HRTIM_OUTxR    0x0064		/* (RW) HRTIM Timerx Output register */
  #define HRTIM_OUTR_POL1       0x00000002	/* Slave output 1 polarity */
  #define HRTIM_OUTR_IDLM1      0x00000004	/* Slave output 1 idle mode */
  #define HRTIM_OUTR_IDLES1     0x00000008	/* Slave output 1 idle state */
  #define HRTIM_OUTR_FAULT1     0x00000030	/* Slave output 1 fault state */
  #define HRTIM_OUTR_FAULT1_0   0x00000010
  #define HRTIM_OUTR_FAULT1_1   0x00000020
  #define HRTIM_OUTR_CHP1       0x00000040	/* Slave output 1 chopper enable */
  #define HRTIM_OUTR_DIDL1      0x00000080	/* Slave output 1 dead time idle */
  #define HRTIM_OUTR_DTEN       0x00000100	/* Slave output deadtime enable */
  #define HRTIM_OUTR_DLYPRTEN   0x00000200	/* Slave output delay protection enable */
  #define HRTIM_OUTR_DLYPRT     0x00001C00	/* Slave output delay protection */
  #define HRTIM_OUTR_DLYPRT_0   0x00000400
  #define HRTIM_OUTR_DLYPRT_1   0x00000800
  #define HRTIM_OUTR_DLYPRT_2   0x00001000
  #define HRTIM_OUTR_BIAR       0x00004000	/* Slave output Balanced Idle Automatic resume */
  #define HRTIM_OUTR_POL2       0x00020000	/* Slave output 2 polarity */
  #define HRTIM_OUTR_IDLM2      0x00040000	/* Slave output 2 idle mode */
  #define HRTIM_OUTR_IDLES2     0x00080000	/* Slave output 2 idle state */
  #define HRTIM_OUTR_FAULT2     0x00300000	/* Slave output 2 fault state */
  #define HRTIM_OUTR_FAULT2_0   0x00100000
  #define HRTIM_OUTR_FAULT2_1   0x00200000
  #define HRTIM_OUTR_CHP2       0x00400000	/* Slave output 2 chopper enable */
  #define HRTIM_OUTR_DIDL2      0x00800000	/* Slave output 2 dead time idle */
#define TOFF_HRTIM_FLTxR    0x0068		/* (RW) HRTIM Timerx Fault register */
  #define HRTIM_FLTR_FLT1EN     0x00000001	/* Fault 1 enable */
  #define HRTIM_FLTR_FLT2EN     0x00000002	/* Fault 2 enable */
  #define HRTIM_FLTR_FLT3EN     0x00000004	/* Fault 3 enable */
  #define HRTIM_FLTR_FLT4EN     0x00000008	/* Fault 4 enable */
  #define HRTIM_FLTR_FLT5EN     0x00000010	/* Fault 5 enable */
  #define HRTIM_FLTR_FLT6EN     0x00000020	/* Fault 6 enable */
  #define HRTIM_FLTR_FLTLCK     0x80000000	/* Fault sources lock */
#define TOFF_HRTIM_TIMxCR2  0x006C		/* (RW) HRTIM Timerx Control register 2 */
  #define HRTIM_TIMCR2_DCDE     0x00000001	/* Dual Channel DAC trigger enable */
  #define HRTIM_TIMCR2_DCDS     0x00000002	/* Dual Channel DAC step trigger */
  #define HRTIM_TIMCR2_DCDR     0x00000004	/* Dual Channel DAC reset trigger */
  #define HRTIM_TIMCR2_UDM      0x00000010	/* Up-Down Mode*/
  #define HRTIM_TIMCR2_ROM      0x000000C0	/* Roll-over Mode */
  #define HRTIM_TIMCR2_ROM_0    0x00000040
  #define HRTIM_TIMCR2_ROM_1    0x00000080
  #define HRTIM_TIMCR2_OUTROM   0x00000300	/* Output Roll-Over Mode */
  #define HRTIM_TIMCR2_OUTROM_0 0x00000100
  #define HRTIM_TIMCR2_OUTROM_1 0x00000200
  #define HRTIM_TIMCR2_ADROM    0x00000C00	/* ADC Roll-Over Mode */
  #define HRTIM_TIMCR2_ADROM_0  0x00000400
  #define HRTIM_TIMCR2_ADROM_1  0x00000800
  #define HRTIM_TIMCR2_BMROM    0x00003000	/* Burst Mode Rollover Mode */
  #define HRTIM_TIMCR2_BMROM_0  0x00001000
  #define HRTIM_TIMCR2_BMROM_1  0x00002000
  #define HRTIM_TIMCR2_FEROM    0x0000C000	/* Fault and Event Rollover Mode */
  #define HRTIM_TIMCR2_FEROM_0  0x00004000
  #define HRTIM_TIMCR2_FEROM_1  0x00008000
  #define HRTIM_TIMCR2_GTCMP1   0x00010000	/* Greater than Compare 1 PWM mode */
  #define HRTIM_TIMCR2_GTCMP3   0x00020000	/* Greater than Compare 3 PWM mode */
  #define HRTIM_TIMCR2_TRGHLF   0x00100000	/* Triggered-Half mode */
#define TOFF_HRTIM_EEFxR3   0x0070		/* (RW) HRTIM Timerx external event filtering 3 register */
  #define HRTIM_EEFR3_EEVACE    0x00000001	/* External Event A Counter Enable */
  #define HRTIM_EEFR3_EEVACRES  0x00000002	/* External Event A Counter Reset */
  #define HRTIM_EEFR3_EEVARSTM  0x00000004	/* External Event A Counter Reset Mode */
  #define HRTIM_EEFR3_EEVASEL   0x000000F0	/* External Event A Selection */
  #define HRTIM_EEFR3_EEVASEL_0 0x00000010
  #define HRTIM_EEFR3_EEVASEL_1 0x00000020
  #define HRTIM_EEFR3_EEVASEL_2 0x00000040
  #define HRTIM_EEFR3_EEVASEL_3 0x00000080
  #define HRTIM_EEFR3_EEVACNT   0x00003F00	/* External Event A Selection */
  #define HRTIM_EEFR3_EEVACNT_0 0x00000100
  #define HRTIM_EEFR3_EEVACNT_1 0x00000200
  #define HRTIM_EEFR3_EEVACNT_2 0x00000400
  #define HRTIM_EEFR3_EEVACNT_3 0x00000800
  #define HRTIM_EEFR3_EEVACNT_4 0x00001000
  #define HRTIM_EEFR3_EEVACNT_5 0x00002000
  #define HRTIM_EEFR3_EEVBCE    0x00010000	/* External Event B Counter Enable */
  #define HRTIM_EEFR3_EEVBCRES  0x00020000	/* External Event B Counter Reset */
  #define HRTIM_EEFR3_EEVBRSTM  0x00040000	/* External Event B Counter Reset Mode */
  #define HRTIM_EEFR3_EEVBSEL   0x00F00000	/* External Event B Selection */
  #define HRTIM_EEFR3_EEVBSEL_0 0x00100000
  #define HRTIM_EEFR3_EEVBSEL_1 0x00200000
  #define HRTIM_EEFR3_EEVBSEL_2 0x00400000
  #define HRTIM_EEFR3_EEVBSEL_3 0x00800000
  #define HRTIM_EEFR3_EEVBCNT   0x3F000000	/* External Event B Counter */
  #define HRTIM_EEFR3_EEVBCNT_0 0x01000000
  #define HRTIM_EEFR3_EEVBCNT_1 0x02000000
  #define HRTIM_EEFR3_EEVBCNT_2 0x04000000
  #define HRTIM_EEFR3_EEVBCNT_3 0x08000000
  #define HRTIM_EEFR3_EEVBCNT_4 0x10000000
  #define HRTIM_EEFR3_EEVBCNT_5 0x20000000


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

#define TADR_DMA1_CH1_BASE  (TADR_DMA1_BASE + 0x008)
#define TADR_DMA1_CH2_BASE  (TADR_DMA1_BASE + 0x01C)
#define TADR_DMA1_CH3_BASE  (TADR_DMA1_BASE + 0x030)
#define TADR_DMA1_CH4_BASE  (TADR_DMA1_BASE + 0x044)
#define TADR_DMA1_CH5_BASE  (TADR_DMA1_BASE + 0x058)
#define TADR_DMA1_CH6_BASE  (TADR_DMA1_BASE + 0x06C)
#define TADR_DMA1_CH7_BASE  (TADR_DMA1_BASE + 0x080)
#define TADR_DMA1_CH8_BASE  (TADR_DMA1_BASE + 0x094)
#define TADR_DMA2_CH1_BASE  (TADR_DMA2_BASE + 0x0008)
#define TADR_DMA2_CH2_BASE  (TADR_DMA2_BASE + 0x001C)
#define TADR_DMA2_CH3_BASE  (TADR_DMA2_BASE + 0x0030)
#define TADR_DMA2_CH4_BASE  (TADR_DMA2_BASE + 0x0044)
#define TADR_DMA2_CH5_BASE  (TADR_DMA2_BASE + 0x0058)
#define TADR_DMA2_CH6_BASE  (TADR_DMA2_BASE + 0x006C)
#define TADR_DMA2_CH7_BASE  (TADR_DMA2_BASE + 0x0080)
#define TADR_DMA2_CH8_BASE  (TADR_DMA2_BASE + 0x0094)
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
 *  CORDIC
 */
#define TADR_CORDIC_BASE    (AHB1PERIPH_BASE + 0x0C00)
#define TOFF_CORDIC_CSR     0x0000		/* (RW) CORDIC control and status register */
  #define CORDIC_CSR_FUNC       0x0000000F	/* Function */
  #define CORDIC_CSR_FUNC_0     0x00000001
  #define CORDIC_CSR_FUNC_1     0x00000002
  #define CORDIC_CSR_FUNC_2     0x00000004
  #define CORDIC_CSR_FUNC_3     0x00000008
  #define CORDIC_CSR_PRECISION  0x000000F0	/* Precision */
  #define CORDIC_CSR_PRECISION_0 0x00000010
  #define CORDIC_CSR_PRECISION_1 0x00000020
  #define CORDIC_CSR_PRECISION_2 0x00000040
  #define CORDIC_CSR_PRECISION_3 0x00000080
  #define CORDIC_CSR_SCALE      0x00000700	/* Scaling factor */
  #define CORDIC_CSR_SCALE_0    0x00000100
  #define CORDIC_CSR_SCALE_1    0x00000200
  #define CORDIC_CSR_SCALE_2    0x00000400
  #define CORDIC_CSR_IEN        0x00010000	/* Interrupt Enable */
  #define CORDIC_CSR_DMAREN     0x00020000	/* DMA Read channel Enable */
  #define CORDIC_CSR_DMAWEN     0x00040000	/* DMA Write channel Enable */
  #define CORDIC_CSR_NRES       0x00080000	/* Number of results in WDATA register */
  #define CORDIC_CSR_NARGS      0x00100000	/* Number of arguments in RDATA register */
  #define CORDIC_CSR_RESSIZE    0x00200000	/* Width of output data */
  #define CORDIC_CSR_ARGSIZE    0x00400000	/* Width of input data */
  #define CORDIC_CSR_RRDY       0x80000000	/* Result Ready Flag */
#define TOFF_CORDIC_WDATA   0x0004		/* (RW) CORDIC argument register */
#define TOFF_CORDIC_RDATA   0x0008		/* (RW) CORDIC result register */


/*
 *  RESET AND CLOCK CONTROL
 */
#define TADR_RCC_BASE       (AHB1PERIPH_BASE + 0x1000)
#define TOFF_RCC_CR         0x0000		/* (RW) RCC clock control register */
  #define RCC_CR_HSION          0x00000100	/* Internal High Speed oscillator (HSI16) clock enable */
  #define RCC_CR_HSIKERON       0x00000200	/* Internal High Speed oscillator (HSI16) clock enable for some IPs Kernel */
  #define RCC_CR_HSIRDY         0x00000400	/* Internal High Speed oscillator (HSI16) clock ready flag */
  #define RCC_CR_HSIASFS        0x00000800	/* HSI16 Automatic Start from Stop */
  #define RCC_CR_HSEON          0x00010000	/* External High Speed oscillator (HSE) clock enable */
  #define RCC_CR_HSERDY         0x00020000	/* External High Speed oscillator (HSE) clock ready */
  #define RCC_CR_HSEBYP         0x00040000	/* External High Speed oscillator (HSE) clock bypass */
  #define RCC_CR_CSSON          0x00080000	/* HSE Clock Security System enable */
  #define RCC_CR_PLLON          0x01000000	/* System PLL clock enable */
  #define RCC_CR_PLLRDY         0x02000000	/* System PLL clock ready */
#define TOFF_RCC_ICSCR      0x0004		/* (RW) RCC Internal clock sources calibration register */
  #define RCC_ICSCR_HSICAL      0x00FF0000	/* HSICAL[7:0] bits */
  #define RCC_ICSCR_HSICAL_0    0x00010000
  #define RCC_ICSCR_HSICAL_1    0x00020000
  #define RCC_ICSCR_HSICAL_2    0x00040000
  #define RCC_ICSCR_HSICAL_3    0x00080000
  #define RCC_ICSCR_HSICAL_4    0x00100000
  #define RCC_ICSCR_HSICAL_5    0x00200000
  #define RCC_ICSCR_HSICAL_6    0x00400000
  #define RCC_ICSCR_HSICAL_7    0x00800000
  #define RCC_ICSCR_HSITRIM     0x1F000000	/* HSITRIM[4:0] bits */
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
  #define RCC_CFGR_SW_HSI       0x00000001	/* HSI16 oscillator selection as system clock */
  #define RCC_CFGR_SW_HSE       0x00000002	/* HSE oscillator selection as system clock */
  #define RCC_CFGR_SW_PLL       0x00000003	/* PLL selection as system clock */
  #define RCC_CFGR_SWS          0x0000000C	/* SWS[1:0] bits (System Clock Switch Status) */
  #define RCC_CFGR_SWS_0        0x00000004
  #define RCC_CFGR_SWS_1        0x00000008
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
  #define RCC_CFGR_MCOSEL       0x0F000000	/* MCOSEL [3:0] bits (Clock output selection) */
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
  #define RCC_PLLCFGR_PLLSRC_0  0x00000001
  #define RCC_PLLCFGR_PLLSRC_1  0x00000002
  #define RCC_PLLCFGR_PLLSRC_HSI 0x00000002	/* HSI16 oscillator source clock selected */
  #define RCC_PLLCFGR_PLLSRC_HSE 0x00000003	/* HSE oscillator source clock selected */
  #define RCC_PLLCFGR_PLLM      0x000000F0
  #define RCC_PLLCFGR_PLLM_0    0x00000010
  #define RCC_PLLCFGR_PLLM_1    0x00000020
  #define RCC_PLLCFGR_PLLM_2    0x00000040
  #define RCC_PLLCFGR_PLLM_3    0x00000080
  #define RCC_PLLCFGR_PLLN      0x00007F00
  #define RCC_PLLCFGR_PLLN_0    0x00000100
  #define RCC_PLLCFGR_PLLN_1    0x00000200
  #define RCC_PLLCFGR_PLLN_2    0x00000400
  #define RCC_PLLCFGR_PLLN_3    0x00000800
  #define RCC_PLLCFGR_PLLN_4    0x00001000
  #define RCC_PLLCFGR_PLLN_5    0x00002000
  #define RCC_PLLCFGR_PLLN_6    0x00004000
  #define RCC_PLLCFGR_PLLPEN    0x00010000
  #define RCC_PLLCFGR_PLLP      0x00020000
  #define RCC_PLLCFGR_PLLQEN    0x00100000
  #define RCC_PLLCFGR_PLLQ      0x00600000
  #define RCC_PLLCFGR_PLLQ_0    0x00200000
  #define RCC_PLLCFGR_PLLQ_1    0x00400000
  #define RCC_PLLCFGR_PLLREN    0x01000000
  #define RCC_PLLCFGR_PLLR      0x06000000
  #define RCC_PLLCFGR_PLLR_0    0x02000000
  #define RCC_PLLCFGR_PLLR_1    0x04000000
  #define RCC_PLLCFGR_PLLPDIV   0xF8000000
  #define RCC_PLLCFGR_PLLPDIV_0 0x08000000
  #define RCC_PLLCFGR_PLLPDIV_1 0x10000000
  #define RCC_PLLCFGR_PLLPDIV_2 0x20000000
  #define RCC_PLLCFGR_PLLPDIV_3 0x40000000
  #define RCC_PLLCFGR_PLLPDIV_4 0x80000000
#define TOFF_RCC_CIER       0x0018		/* (RW) RCC clock interrupt enable register */
  #define RCC_CIER_LSIRDYIE     0x00000001
  #define RCC_CIER_LSERDYIE     0x00000002
  #define RCC_CIER_MSIRDYIE     0x00000004
  #define RCC_CIER_HSIRDYIE     0x00000008
  #define RCC_CIER_HSERDYIE     0x00000010
  #define RCC_CIER_PLLRDYIE     0x00000020
  #define RCC_CIER_LSECSSIE     0x00000200
  #define RCC_CIER_HSI48RDYIE   0x00000400
#define TOFF_RCC_CIFR       0x001C		/* (RW) RCC clock interrupt flag register */
  #define RCC_CIFR_LSIRDYF      0x00000001
  #define RCC_CIFR_LSERDYF      0x00000002
  #define RCC_CIFR_HSIRDYF      0x00000008
  #define RCC_CIFR_HSERDYF      0x00000010
  #define RCC_CIFR_PLLRDYF      0x00000020
  #define RCC_CIFR_CSSF         0x00000100
  #define RCC_CIFR_LSECSSF      0x00000200
  #define RCC_CIFR_HSI48RDYF    0x00000400
#define TOFF_RCC_CICR       0x0020		/* (RW) RCC clock interrupt clear register */
  #define RCC_CICR_LSIRDYC      0x00000001
  #define RCC_CICR_LSERDYC      0x00000002
  #define RCC_CICR_HSIRDYC      0x00000008
  #define RCC_CICR_HSERDYC      0x00000010
  #define RCC_CICR_PLLRDYC      0x00000020
  #define RCC_CICR_CSSC         0x00000100
  #define RCC_CICR_LSECSSC      0x00000200
  #define RCC_CICR_HSI48RDYC    0x00000400
#define TOFF_RCC_AHB1RSTR   0x0028		/* (RW) RCC AHB1 peripheral reset register */
  #define RCC_AHB1RSTR_DMA1RST  0x00000001	/* DMA1 reset */
  #define RCC_AHB1RSTR_DMA2RST  0x00000002	/* DMA2 reset */
  #define RCC_AHB1RSTR_DMAMUX1RST 0x00000004
  #define RCC_AHB1RSTR_CORDICRST  0x00000008
  #define RCC_AHB1RSTR_FMACRST  0x00000010
  #define RCC_AHB1RSTR_FLASHRST 0x00000100	/* FLASH reset */
  #define RCC_AHB1RSTR_CRCRST   0x00001000	/* CRC reset */
#define TOFF_RCC_AHB2RSTR   0x002C		/* (RW) RCC AHB2 peripheral reset register */
  #define RCC_AHB2RSTR_GPIOARST 0x00000001	/* GPIOA reset */
  #define RCC_AHB2RSTR_GPIOBRST 0x00000002	/* GPIOB reset */
  #define RCC_AHB2RSTR_GPIOCRST 0x00000004	/* GPIOC reset */
  #define RCC_AHB2RSTR_GPIODRST 0x00000008	/* GPIOD reset */
  #define RCC_AHB2RSTR_GPIOERST 0x00000010	/* GPIOE reset */
  #define RCC_AHB2RSTR_GPIOFRST 0x00000020	/* GPIOF reset */
  #define RCC_AHB2RSTR_GPIOGRST 0x00000040	/* GPIOG reset */
  #define RCC_AHB2RSTR_ADC12RST 0x00002000	/* ADC12 reset */
  #define RCC_AHB2RSTR_ADC345RST 0x00004000	/* ADC345 reset */
  #define RCC_AHB2RSTR_DAC1RST  0x00010000	/* DAC1 reset */
  #define RCC_AHB2RSTR_DAC2RST  0x00020000	/* DAC2 reset */
  #define RCC_AHB2RSTR_DAC3RST  0x00040000	/* DAC3 reset */
  #define RCC_AHB2RSTR_DAC4RST  0x00080000	/* DAC4 reset */
  #define RCC_AHB2RSTR_RNGRST   0x04000000	/* RNG reset */
#define TOFF_RCC_AHB3RSTR   0x0030		/* (RW) RCC AHB3 peripheral reset register */
  #define RCC_AHB3RSTR_FMCRST   0x00000001	/* FMC reset */
  #define RCC_AHB3RSTR_QSPIRST  0x00000100	/* QSPI reset */
#define TOFF_RCC_APB1RSTR1  0x0038		/* (RW) RCC APB1 peripheral reset register 1 */
  #define RCC_APB1RSTR1_TIM2RST   0x00000001	/* TIMER2 reset */
  #define RCC_APB1RSTR1_TIM3RST   0x00000002	/* TIMER3 reset */
  #define RCC_APB1RSTR1_TIM4RST   0x00000004	/* TIMER4 reset */
  #define RCC_APB1RSTR1_TIM5RST   0x00000008	/* TIMER5 reset */
  #define RCC_APB1RSTR1_TIM6RST   0x00000010	/* TIMER6 reset */
  #define RCC_APB1RSTR1_TIM7RST   0x00000020	/* TIMER7 reset */
  #define RCC_APB1RSTR1_CRSRST    0x00000100	/* CRS reset */
  #define RCC_APB1RSTR1_SPI2RST   0x00004000	/* SPI2 reset */
  #define RCC_APB1RSTR1_SPI3RST   0x00008000	/* SPI3 reset */
  #define RCC_APB1RSTR1_USART2RST 0x00020000	/* USART2 reset */
  #define RCC_APB1RSTR1_USART3RST 0x00040000	/* USART3 reset */
  #define RCC_APB1RSTR1_UART4RST  0x00080000	/* UART4 reset */
  #define RCC_APB1RSTR1_UART5RST  0x00100000	/* UART5 reset */
  #define RCC_APB1RSTR1_I2C1RST   0x00200000	/* I2C1 reset */
  #define RCC_APB1RSTR1_I2C2RST   0x00400000	/* I2C2 reset */
  #define RCC_APB1RSTR1_USBRST    0x00800000	/* USB reset */
  #define RCC_APB1RSTR1_FDCANRST  0x02000000	/* FDCAN reset */
  #define RCC_APB1RSTR1_PWRRST    0x10000000	/* PWR reset */
  #define RCC_APB1RSTR1_I2C3RST   0x40000000	/* I2C3 reset */
  #define RCC_APB1RSTR1_LPTIM1RST 0x80000000	/* LPTIM1 reset */
#define TOFF_RCC_APB1RSTR2  0x003C		/* (RW) RCC APB1 peripheral reset register 2 */
  #define RCC_APB1RSTR2_LPUART1RST 0x00000001	/* LPUART1 reset */
  #define RCC_APB1RSTR2_I2C4RST   0x00000002	/* I2C4 reset */
  #define RCC_APB1RSTR2_UCPD1RST  0x00000100	/* UCPD reset */
#define TOFF_RCC_APB2RSTR   0x0040		/* (RW) RCC APB2 peripheral reset register */
  #define RCC_APB2RSTR_SYSCFGRST  0x00000001	/* SYSCFG reset */
  #define RCC_APB2RSTR_TIM1RST    0x00000800	/* TIMER1 reset */
  #define RCC_APB2RSTR_SPI1RST    0x00001000	/* SPI1 reset */
  #define RCC_APB2RSTR_TIM8RST    0x00002000	/* TIMER8 reset */
  #define RCC_APB2RSTR_USART1RST  0x00004000	/* USART1 reset */
  #define RCC_APB2RSTR_SPI4RST    0x00008000	/* SPI4 reset */
  #define RCC_APB2RSTR_TIM15RST   0x00010000	/* TIMER15 reset */
  #define RCC_APB2RSTR_TIM16RST   0x00020000	/* TIMER16 reset */
  #define RCC_APB2RSTR_TIM17RST   0x00040000	/* TIMER17 reset */
  #define RCC_APB2RSTR_TIM20RST   0x00100000	/* TIMER20 reset */
  #define RCC_APB2RSTR_SAI1RST    0x00200000	/* SAI1 reset */
  #define RCC_APB2RSTR_HRTIM1RST  0x04000000	/* HRTIM1 reset */
#define TOFF_RCC_AHB1ENR    0x0048		/* (RW) RCC AHB1 peripheral clocks enable register */
  #define RCC_AHB1ENR_DMA1EN    0x00000001	/* DMA1 clock clock enable */
  #define RCC_AHB1ENR_DMA2EN    0x00000002	/* DMA2 clock enable */
  #define RCC_AHB1ENR_DMAMUX1EN 0x00000004	/* DMAMUX clock enable */
  #define RCC_AHB1ENR_CORDICEN  0x00000008	/* CORDIC clock enable */
  #define RCC_AHB1ENR_FMACEN    0x00000010	/* FMAC clock enable */
  #define RCC_AHB1ENR_FLASHEN   0x00000100	/* FLASH clock enable */
  #define RCC_AHB1ENR_CRCEN     0x00001000	/* CRC clock enable */
#define TOFF_RCC_AHB2ENR    0x004C		/* (RW) RCC AHB2 peripheral clocks clock enable register */
  #define RCC_AHB2ENR_GPIOAEN   0x00000001	/* GPIOA clock enable */
  #define RCC_AHB2ENR_GPIOBEN   0x00000002	/* GPIOB clock enable */
  #define RCC_AHB2ENR_GPIOCEN   0x00000004	/* GPIOC clock enable */
  #define RCC_AHB2ENR_GPIODEN   0x00000008	/* GPIOD clock enable */
  #define RCC_AHB2ENR_GPIOEEN   0x00000010	/* GPIOE clock enable */
  #define RCC_AHB2ENR_GPIOFEN   0x00000020	/* GPIOF clock enable */
  #define RCC_AHB2ENR_GPIOGEN   0x00000040	/* GPIOG clock enable */
  #define RCC_AHB2ENR_ADC12EN   0x00002000	/* ADC12 clock enable */
  #define RCC_AHB2ENR_ADC345EN  0x00004000	/* ADC345 clock enable */
  #define RCC_AHB2ENR_DAC1EN    0x00010000	/* DAC1 clock enable */
  #define RCC_AHB2ENR_DAC2EN    0x00020000	/* DAC2 clock enable */
  #define RCC_AHB2ENR_DAC3EN    0x00040000	/* DAC3 clock enable */
  #define RCC_AHB2ENR_DAC4EN    0x00080000	/* DAC4 clock enable */
  #define RCC_AHB2ENR_RNGEN     0x00040000	/* RNG clock enable */
#define TOFF_RCC_AHB3ENR    0x0050		/* (RW) RCC AHB3 peripheral clocks clock enable register */
  #define RCC_AHB3ENR_FMCEN     0x00000001	/* FMC clock enable */
  #define RCC_AHB3ENR_QSPIEN    0x00000100	/* QUADSPI clock enable */
#define TOFF_RCC_APB1ENR1   0x0058		/* (RW) RCC APB1 peripheral clocks clock enable register 1 */
  #define RCC_APB1ENR1_TIM2EN   0x00000001	/* TIMER2 clock enable */
  #define RCC_APB1ENR1_TIM3EN   0x00000002	/* TIMER3 clock enable */
  #define RCC_APB1ENR1_TIM4EN   0x00000004	/* TIMER4 clock enable */
  #define RCC_APB1ENR1_TIM5EN   0x00000008	/* TIMER5 clock enable */
  #define RCC_APB1ENR1_TIM6EN   0x00000010	/* TIMER6 clock enable */
  #define RCC_APB1ENR1_TIM7EN   0x00000020	/* TIMER7 clock enable */
  #define RCC_APB1ENR1_CRSEN    0x00000100	/* CRS clock enable */
  #define RCC_APB1ENR1_RTCAPBEN 0x00000400	/* RTCAPB clock enable */
  #define RCC_APB1ENR1_WWDGEN   0x00000800	/* WWDG clock enable */
  #define RCC_APB1ENR1_SPI2EN   0x00004000	/* SPI2 clock enable */
  #define RCC_APB1ENR1_SPI3EN   0x00008000	/* SPI3 clock enable */
  #define RCC_APB1ENR1_USART2EN 0x00020000	/* USART2 clock enable */
  #define RCC_APB1ENR1_USART3EN 0x00040000	/* USART3 clock enable */
  #define RCC_APB1ENR1_UART4EN  0x00080000	/* UART4 clock enable */
  #define RCC_APB1ENR1_UART5EN  0x00100000	/* UART5 clock enable */
  #define RCC_APB1ENR1_I2C1EN   0x00200000	/* I2C1 clock enable */
  #define RCC_APB1ENR1_I2C2EN   0x00400000	/* I2C2 clock enable */
  #define RCC_APB1ENR1_USBEN    0x00800000	/* USB clock enable */
  #define RCC_APB1ENR1_FDCANEN  0x02000000	/* FDCAN clock enable */
  #define RCC_APB1ENR1_PWREN    0x10000000	/* PWR clock enable */
  #define RCC_APB1ENR1_I2C3EN   0x40000000	/* I2C3 clock enable */
  #define RCC_APB1ENR1_LPTIM1EN 0x80000000	/* LPTIMER1 clock enable */
#define TOFF_RCC_APB1ENR2   0x005C		/* (RW) RCC APB1 peripheral clocks enable register 2 */
  #define RCC_APB1ENR2_LPUART1EN 0x00000001	/* LPUART1 clock enable */
  #define RCC_APB1ENR2_I2C4EN   0x00000002	/* I2C4 clock enable */
  #define RCC_APB1ENR2_SWPMI1EN 0x00000004	/* SWPMI clock enable */
  #define RCC_APB1ENR2_UCPD1EN  0x00000100	/* UCPD1 clock enable */
#define TOFF_RCC_APB2ENR    0x0060		/* (RW) RCC APB2 peripheral clocks enable register */
  #define RCC_APB2ENR_SYSCFGEN  0x00000001	/* SYSCFG clock enable */
  #define RCC_APB2ENR_TIM1EN    0x00000800	/* TIMER1 clock enable */
  #define RCC_APB2ENR_SPI1EN    0x00001000	/* SPI1 clock enable */
  #define RCC_APB2ENR_TIM8EN    0x00002000	/* TIMER8 clock enable */
  #define RCC_APB2ENR_USART1EN  0x00004000	/* USART1 clock enable */
  #define RCC_APB2ENR_SPI4EN    0x00008000	/* SPI4 clock enable */
  #define RCC_APB2ENR_TIM15EN   0x00010000	/* TIMER15 clock enable */
  #define RCC_APB2ENR_TIM16EN   0x00020000	/* TIMER16 clock enable */
  #define RCC_APB2ENR_TIM17EN   0x00040000	/* TIMER17 clock enable */
  #define RCC_APB2ENR_TIM20EN   0x00100000	/* TIMER20 clock enable */
  #define RCC_APB2ENR_SAI1EN    0x00200000	/* SAI1 clock enable */
  #define RCC_APB2ENR_HRTIM1EN  0x04000000	/* HRTIM1 clock enable */
#define TOFF_RCC_AHB1SMENR  0x0068		/* (RW) RCC AHB1 peripheral clocks enable in sleep and stop modes register */
  #define RCC_AHB1SMENR_DMA1SMEN  0x00000001	/* DMA1 clock enabled in sleep mode */
  #define RCC_AHB1SMENR_DMA2SMEN  0x00000002	/* DMA2 clock enabled in sleep mode */
  #define RCC_AHB1SMENR_DMAMUX1SMEN 0x00000004	/* DMAMUX1 clock enabled in sleep mode */
  #define RCC_AHB1SMENR_CORDICSMEN  0x00000008	/* CODIC clock enabled in sleep mode */
  #define RCC_AHB1SMENR_FMACSMEN  0x00000010	/* FMAC clock enabled in sleep mode */
  #define RCC_AHB1SMENR_FLASHSMEN 0x00000100	/* FLASH clock enabled in sleep mode */
  #define RCC_AHB1SMENR_SRAM1SMEN 0x00000200	/* SRAM1 clock enabled in sleep mode */
  #define RCC_AHB1SMENR_CRCSMEN   0x00001000	/* CRC clock enabled in sleep mode */
#define TOFF_RCC_AHB2SMENR  0x006C		/* (RW) RCC AHB2 peripheral clocks enable in sleep and stop modes register */
  #define RCC_AHB2SMENR_GPIOASMEN 0x00000001	/* GPIOA clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOBSMEN 0x00000002	/* GPIOB clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOCSMEN 0x00000004	/* GPIOC clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIODSMEN 0x00000008	/* GPIOD clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOESMEN 0x00000010	/* GPIOE clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOFSMEN 0x00000020	/* GPIOF clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOGSMEN 0x00000040	/* GPIOG clock enabled in sleep mode */
  #define RCC_AHB2SMENR_CCMSRAMSMEN 0x00000200	/* CCMSRAM clock enabled in sleep mode */
  #define RCC_AHB2SMENR_SRAM2SMEN 0x00000400	/* SRAM2 clock enabled in sleep mode */
  #define RCC_AHB2SMENR_ADC12SMEN 0x00002000	/* ADC12 clock enabled in sleep mode  */
  #define RCC_AHB2SMENR_ADC345SMEN 0x00004000	/* ADC345 clock enabled in sleep mode */
  #define RCC_AHB2SMENR_DAC1SMEN  0x00010000	/* DAC1 clock enabled in sleep mode */
  #define RCC_AHB2SMENR_DAC2SMEN  0x00020000	/* DAC2 clock enabled in sleep mode */
  #define RCC_AHB2SMENR_DAC3SMEN  0x00040000	/* DAC3 clock enabled in sleep mode */
  #define RCC_AHB2SMENR_DAC4SMEN  0x00080000	/* DAC4 clock enabled in sleep mode */
  #define RCC_AHB2SMENR_RNGSMEN   0x04000000	/* RNG clock enabled in sleep mode */
#define TOFF_RCC_AHB3SMENR  0x0070		/* (RW) RCC AHB3 peripheral clocks enable in sleep and stop modes register */
  #define RCC_AHB3SMENR_FMCSMEN   0x00000001	/* FMC clock enabled in sleep mode */
  #define RCC_AHB3SMENR_QSPISMEN  0x00000100	/* QUADSPI clock enabled in sleep mode */
#define TOFF_RCC_APB1SMENR1 0x0078		/* (RW) RCC APB1 peripheral clocks enable in sleep mode and stop modes register 1 */
  #define RCC_APB1SMENR1_TIM2SMEN 0x00000001	/* TIM2 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_TIM3SMEN 0x00000002	/* TIM3 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_TIM4SMEN 0x00000004	/* TIM4 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_TIM5SMEN 0x00000008	/* TIM5 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_TIM6SMEN 0x00000010	/* TIM6 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_TIM7SMEN 0x00000020	/* TIM7 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_CRSSMEN  0x00000100	/* CRS clock enabled in sleep mode */
  #define RCC_APB1SMENR1_RTCAPBSMEN 0x00000400	/* RTCAPB clock enabled in sleep mode */
  #define RCC_APB1SMENR1_WWDGSMEN 0x00000800	/* WWDG clock enabled in sleep mode */
  #define RCC_APB1SMENR1_SPI2SMEN 0x00004000	/* SPI2 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_SPI3SMEN 0x00008000	/* SPI3 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_USART2SMEN 0x00020000	/* USART2 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_USART3SMEN 0x00040000	/* USART3 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_UART4SMEN  0x00080000	/* UART4 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_UART5SMEN  0x00100000	/* UART5 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_I2C1SMEN 0x00200000	/* I2C1 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_I2C2SMEN 0x00400000	/* I2C2 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_USBSMEN  0x00800000	/* USB clock enabled in sleep mode */
  #define RCC_APB1SMENR1_FCCAN1SMEN 0x02000000	/* FDCAN1 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_PWRSMEN  0x10000000	/* PWR clock enabled in sleep mode */
  #define RCC_APB1SMENR1_I2C3SMEN 0x40000000	/* I2C3 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_LPTIM1SMEN 0x80000000	/* LPTIM1 clock enabled in sleep mode */
#define TOFF_RCC_APB1SMENR2 0x007C		/* (RW) RCC APB1 peripheral clocks enable in sleep mode and stop modes register 2 */
  #define RCC_APB1SMENR2_LPUART1SMEN 0x00000001	/* LPUART1 clock enabled in sleep mode */
  #define RCC_APB1SMENR2_I2C4SMEN  0x00000002	/* I2C4 clock enabled in sleep mode */
  #define RCC_APB1SMENR2_UCPD1SMEN 0x00000100	/* UCPD1 clock enabled in sleep mode */
#define TOFF_RCC_APB2SMENR  0x0080		/* (RW) RCC APB2 peripheral clocks enable in sleep mode and stop modes register */
  #define RCC_APB2SMENR_SYSCFGSMEN 0x00000001	/* SYSCFG clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM1SMEN   0x00000800	/* TIM1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_SPI1SMEN   0x00001000	/* SPI1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM8SMEN   0x00002000	/* TIM8 clock enabled in sleep mode */
  #define RCC_APB2SMENR_USART1SMEN 0x00004000	/* USART1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_SPI4SMEN   0x00008000	/* SPI4 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM15SMEN  0x00010000	/* TIM15 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM16SMEN  0x00020000	/* TIM16 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM17SMEN  0x00040000	/* TIM17 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM20SMEN  0x00100000	/* TIM20 clock enabled in sleep mode */
  #define RCC_APB2SMENR_SAI1SMEN   0x00200000	/* SAI1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_HRTIM1SMEN 0x04000000	/* HRTIM1SMEN clock enabled in sleep mode */
#define TOFF_RCC_CCIPR      0x0088		/* (RW) RCC peripherals independent clock configuration register */
  #define RCC_CCIPR_USART1SEL   0x00000003	/* USART1SEL[1:0] bits */
  #define RCC_CCIPR_USART1SEL_0 0x00000001
  #define RCC_CCIPR_USART1SEL_1 0x00000002
  #define RCC_CCIPR_USART2SEL   0x0000000C	/* USART2SEL[1:0] bits */
  #define RCC_CCIPR_USART2SEL_0 0x00000004
  #define RCC_CCIPR_USART2SEL_1 0x00000008
  #define RCC_CCIPR_USART3SEL   0x00000030	/* USART3SEL[1:0] bits */
  #define RCC_CCIPR_USART3SEL_0 0x00000010
  #define RCC_CCIPR_USART3SEL_1 0x00000020
  #define RCC_CCIPR_UART4SEL    0x000000C0	/* UART4SEL[1:0] bits */
  #define RCC_CCIPR_UART4SEL_0  0x00000040
  #define RCC_CCIPR_UART4SEL_1  0x00000080
  #define RCC_CCIPR_UART5SEL    0x00000300	/* UART5SEL[1:0] bits */
  #define RCC_CCIPR_UART5SEL_0  0x00000100
  #define RCC_CCIPR_UART5SEL_1  0x00000200
  #define RCC_CCIPR_LPUART1SEL  0x00000C00	/* LPUART1SEL[1:0] bits */
  #define RCC_CCIPR_LPUART1SEL_0 0x00000400
  #define RCC_CCIPR_LPUART1SEL_1 0x00000800
  #define RCC_CCIPR_I2C1SEL     0x00003000	/* I2C1SEL[1:0] bits */
  #define RCC_CCIPR_I2C1SEL_0   0x00001000
  #define RCC_CCIPR_I2C1SEL_1   0x00002000
  #define RCC_CCIPR_I2C2SEL     0x0000C000	/* I2C2SEL[1:0] bits */
  #define RCC_CCIPR_I2C2SEL_0   0x00004000
  #define RCC_CCIPR_I2C2SEL_1   0x00008000
  #define RCC_CCIPR_I2C3SEL     0x00030000	/* I2C3SEL[1:0] bits */
  #define RCC_CCIPR_I2C3SEL_0   0x00010000
  #define RCC_CCIPR_I2C3SEL_1   0x00020000
  #define RCC_CCIPR_LPTIM1SEL   0x000C0000	/* LPTIM1SEL[1:0] bits */
  #define RCC_CCIPR_LPTIM1SEL_0 0x00040000
  #define RCC_CCIPR_LPTIM1SEL_1 0x00080000
  #define RCC_CCIPR_SAI1SEL     0x00300000	/* SAI1SEL[1:0] bits */
  #define RCC_CCIPR_SAI1SEL_0   0x00100000
  #define RCC_CCIPR_SAI1SEL_1   0x00200000
  #define RCC_CCIPR_I2S23SEL    0x00C00000
  #define RCC_CCIPR_I2S23SEL_0  0x00400000
  #define RCC_CCIPR_I2S23SEL_1  0x00800000
  #define RCC_CCIPR_FDCANSEL    0x03000000	/* FDCANSEL[1:0] bit */
  #define RCC_CCIPR_FDCANSEL_0  0x01000000
  #define RCC_CCIPR_FDCANSEL_1  0x02000000
  #define RCC_CCIPR_CLK48SEL    0x0C000000	/* CLK48SEL[1:0] bits */
  #define RCC_CCIPR_CLK48SEL_0  0x04000000
  #define RCC_CCIPR_CLK48SEL_1  0x08000000
  #define RCC_CCIPR_ADC12SEL    0x30000000	/* ADC12SEL[1:0] bits */
  #define RCC_CCIPR_ADC12SEL_0  0x10000000
  #define RCC_CCIPR_ADC12SEL_1  0x20000000
  #define RCC_CCIPR_ADC345SEL   0xC0000000	/* ADC345SEL[1:0] bits */
  #define RCC_CCIPR_ADC345SEL_0 0x40000000
  #define RCC_CCIPR_ADC345SEL_1 0x80000000
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
  #define RCC_CSR_LSIRDY        0x00000002	/* Internal Low Speed oscillator Ready */
  #define RCC_CSR_RMVF          0x00800000	/* Remove reset flag */
  #define RCC_CSR_FWRSTF        0x01000000	/* Mifare Firewall reset flag */
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
#define TOFF_RCC_CCIPR2     0x009C		/* (RW) RCC peripherals independent clock configuration register 2 */
  #define RCC_CCIPR2_I2C4SEL    0x00000003
  #define RCC_CCIPR2_I2C4SEL_0  0x00000001
  #define RCC_CCIPR2_I2C4SEL_1  0x00000002
  #define RCC_CCIPR2_QSPISEL    0x00300000
  #define RCC_CCIPR2_QSPISEL_0  0x00100000
  #define RCC_CCIPR2_QSPISEL_1  0x00200000


/*
 *  FMAC
 */
#define TADR_FMAC_BASE      (AHB1PERIPH_BASE + 0x1400)
#define TOFF_FMAC_X1BUFCFG  0x0000		/* (RW) FMAC X1 Buffer Configuration register */
  #define FMAC_X1BUFCFG_X1_BASE     0x000000FF	/* Base address of X1 buffer */
  #define FMAC_X1BUFCFG_X1_BUF_SIZE 0x0000FF00	/* Allocated size of X1 buffer in 16-bit words */
  #define FMAC_X1BUFCFG_FULL_WM     0x03000000	/* Watermark for buffer full flag */
#define TOFF_FMAC_X2BUFCFG  0x0004		/* (RW) FMAC X2 Buffer Configuration register */
  #define FMAC_X2BUFCFG_X2_BASE     0x000000FF	/* Base address of X2 buffer */
  #define FMAC_X2BUFCFG_X2_BUF_SIZE 0x0000FF00	/* Size of X2 buffer in 16-bit words */
#define TOFF_FMAC_YBUFCFG   0x0008		/* (RW) FMAC Y Buffer Configuration register */
  #define FMAC_YBUFCFG_Y_BASE       0x000000FF	/* Base address of Y buffer */
  #define FMAC_YBUFCFG_Y_BUF_SIZE   0x0000FF00	/* Size of Y buffer in 16-bit words */
  #define FMAC_YBUFCFG_EMPTY_WM     0x03000000	/* Watermark for buffer empty flag */
#define TOFF_FMAC_PARAM     0x000C		/* (RW) FMAC Parameter register */
  #define FMAC_PARAM_P              0x000000FF	/* Input parameter P */
  #define FMAC_PARAM_Q              0x0000FF00	/* Input parameter Q */
  #define FMAC_PARAM_R              0x00FF0000	/* Input parameter R */
  #define FMAC_PARAM_FUNC           0x7F000000	/* Function */
  #define FMAC_PARAM_FUNC_0         0x01000000
  #define FMAC_PARAM_FUNC_1         0x02000000
  #define FMAC_PARAM_FUNC_2         0x04000000
  #define FMAC_PARAM_FUNC_3         0x08000000
  #define FMAC_PARAM_FUNC_4         0x10000000
  #define FMAC_PARAM_FUNC_5         0x20000000
  #define FMAC_PARAM_FUNC_6         0x40000000
  #define FMAC_PARAM_START          0x80000000	/* Enable execution */
#define TOFF_FMAC_CR        0x0010		/* (RW) FMAC Control register */
  #define FMAC_CR_RIEN              0x00000001	/* Enable read interrupt */
  #define FMAC_CR_WIEN              0x00000002	/* Enable write interrupt */
  #define FMAC_CR_OVFLIEN           0x00000004	/* Enable overflow error interrupts */
  #define FMAC_CR_UNFLIEN           0x00000008	/* Enable underflow error interrupts */
  #define FMAC_CR_SATIEN            0x00000010	/* Enable saturation error interrupts */
  #define FMAC_CR_DMAREN            0x00000100	/* Enable DMA read channel requests */
  #define FMAC_CR_DMAWEN            0x00000200	/* Enable DMA write channel requests */
  #define FMAC_CR_CLIPEN            0x00008000	/* Enable clipping */
  #define FMAC_CR_RESET             0x00010000	/* Reset filter mathematical accelerator unit */
#define TOFF_FMAC_SR        0x0014		/* (RW) FMAC Status register */
  #define FMAC_SR_YEMPTY            0x00000001	/* Y buffer empty flag */
  #define FMAC_SR_X1FULL            0x00000002	/* X1 buffer full flag */
  #define FMAC_SR_OVFL              0x00000100	/* Overflow error flag */
  #define FMAC_SR_UNFL              0x00000200	/* Underflow error flag */
  #define FMAC_SR_SAT               0x00000400	/* Saturation error flag */
#define TOFF_FMAC_WDATA     0x0018		/* (RW) FMAC Write Data register */
#define TOFF_FMAC_RDATA     0x001C		/* (RW) FMAC Read Data register */


/*
 *  FLASH REGISTERS
 */
#define TADR_FLASH_R_BASE   (AHB1PERIPH_BASE + 0x2000)
#define TOFF_FLASH_ACR      0x0000		/* (RW) FLASH access control register */
  #define FLASH_ACR_LATENCY  0x0000000F
  #define FLASH_ACR_LATENCY_0WS  0x00000000
  #define FLASH_ACR_LATENCY_1WS  0x00000001
  #define FLASH_ACR_LATENCY_2WS  0x00000002
  #define FLASH_ACR_LATENCY_3WS  0x00000003
  #define FLASH_ACR_LATENCY_4WS  0x00000004
  #define FLASH_ACR_LATENCY_5WS  0x00000005
  #define FLASH_ACR_LATENCY_6WS  0x00000006
  #define FLASH_ACR_LATENCY_7WS  0x00000007
  #define FLASH_ACR_LATENCY_8WS  0x00000008
  #define FLASH_ACR_LATENCY_9WS  0x00000009
  #define FLASH_ACR_LATENCY_10WS 0x0000000A
  #define FLASH_ACR_LATENCY_11WS 0x0000000B
  #define FLASH_ACR_LATENCY_12WS 0x0000000C
  #define FLASH_ACR_LATENCY_13WS 0x0000000D
  #define FLASH_ACR_LATENCY_14WS 0x0000000E
  #define FLASH_ACR_LATENCY_15WS 0x0000000F
  #define FLASH_ACR_PRFTEN   0x00000100
  #define FLASH_ACR_ICEN     0x00000200
  #define FLASH_ACR_DCEN     0x00000400
  #define FLASH_ACR_ICRST    0x00000800
  #define FLASH_ACR_DCRST    0x00001000
  #define FLASH_ACR_RUN_PD   0x00002000	/* Flash power down mode during run */
  #define FLASH_ACR_SLEEP_PD 0x00004000	/* Flash power down mode during sleep */
  #define FLASH_ACR_DBG_SWEN 0x00040000	/* Software disable for debugger */
#define TOFF_FLASH_PDKEYR   0x0004		/* (RW) Power down key register */
#define TOFF_FLASH_KEYR     0x0008		/* (RW) FLASH key register */
#define TOFF_FLASH_OPTKEYR  0x000C		/* (RW) Option byte key register */
#define TOFF_FLASH_SR       0x0010		/* (RW) Status register */
  #define FLASH_SR_EOP       0x00000001	/* End Of Programming*/
  #define FLASH_SR_OPERR     0x00000002
  #define FLASH_SR_PROGERR   0x00000008
  #define FLASH_SR_WRPERR    0x00000010	/* Write protection error */
  #define FLASH_SR_PGAERR    0x00000020	/* Programming Alignment Error */
  #define FLASH_SR_SIZERR    0x00000040	/* Size error */
  #define FLASH_SR_PGSERR    0x00000080
  #define FLASH_SR_MISERR    0x00000100
  #define FLASH_SR_FASTERR   0x00000200
  #define FLASH_SR_RDERR     0x00004000
  #define FLASH_SR_OPTVERR   0x00008000	/* Option Valid error */
  #define FLASH_SR_BSY       0x00010000	/* Busy */
#define TOFF_FLASH_CR       0x0014		/* (RW) FLASH control register */
  #define FLASH_CR_PG        0x00000001
  #define FLASH_CR_PER       0x00000002
  #define FLASH_CR_MER1      0x00000004
  #define FLASH_CR_PNB       0x000003F8
  #define FLASH_CR_BKER      0x00000800
  #define FLASH_CR_MER2      0x00008000
  #define FLASH_CR_STRT      0x00010000
  #define FLASH_CR_OPTSTRT   0x00020000
  #define FLASH_CR_FSTPG     0x00040000
  #define FLASH_CR_EOPIE     0x01000000
  #define FLASH_CR_ERRIE     0x02000000
  #define FLASH_CR_RDERRIE   0x04000000
  #define FLASH_CR_OBL_LAUNCH 0x08000000
  #define FLASH_CR_SEC_PROT1 0x10000000
  #define FLASH_CR_SEC_PROT2 0x20000000
  #define FLASH_CR_OPTLOCK   0x40000000
  #define FLASH_CR_LOCK      0x80000000
#define TOFF_FLASH_ECCR     0x0018		/* (RW) FLASH ECC register */
  #define FLASH_ECCR_ADDR_ECC 0x0007FFFF
  #define FLASH_ECCR_BK_ECC   0x00200000
  #define FLASH_ECCR_SYSF_ECC 0x00400000
  #define FLASH_ECCR_ECCIE    0x01000000
  #define FLASH_ECCR_ECCC2    0x10000000
  #define FLASH_ECCR_ECCD2    0x20000000
  #define FLASH_ECCR_ECCC     0x40000000
  #define FLASH_ECCR_ECCD     0x80000000
#define TOFF_FLASH_OPTR     0x0020		/* (RW) Option byte register */
  #define FLASH_OPTR_RDP        0x000000FF
  #define FLASH_OPTR_BOR_LEV    0x00000700	/* BOR_LEV[2:0] Brown Out Reset Threshold Level*/
  #define FLASH_OPTR_BOR_LEV_0  0x00000000
  #define FLASH_OPTR_BOR_LEV_1  0x00000100
  #define FLASH_OPTR_BOR_LEV_2  0x00000200
  #define FLASH_OPTR_BOR_LEV_3  0x00000300
  #define FLASH_OPTR_BOR_LEV_4  0x00000400
  #define FLASH_OPTR_nRST_STOP  0x00001000	/* nRST_STOP */
  #define FLASH_OPTR_nRST_STDBY 0x00002000	/* nRST_STDBY */
  #define FLASH_OPTR_nRST_SHDW  0x00004000	/* nRST_SHDW */
  #define FLASH_OPTR_IWDG_SW    0x00010000	/* IWDG_SW */
  #define FLASH_OPTR_IWDG_STOP  0x00020000	/* IWDG_STOP */
  #define FLASH_OPTR_IWDG_STDBY 0x00040000	/* IWDG_STDBY */
  #define FLASH_OPTR_WWDG_SW    0x00080000
  #define FLASH_OPTR_BFB2       0x00100000
  #define FLASH_OPTR_DBANK      0x00400000
  #define FLASH_OPTR_nBOOT1     0x00800000
  #define FLASH_OPTR_SRAM_PE    0x01000000
  #define FLASH_OPTR_CCMSRAM_RST 0x02000000
  #define FLASH_OPTR_nSWBOOT0   0x04000000
  #define FLASH_OPTR_nBOOT0     0x08000000
  #define FLASH_OPTR_NRST_MODE  0x30000000
  #define FLASH_OPTR_NRST_MODE_0 0x10000000
  #define FLASH_OPTR_NRST_MODE_1 0x20000000
  #define FLASH_OPTR_IRHEN      0x40000000
#define TOFF_FLASH_PCROP1SR 0x0024		/* (RW) FLASH bank1 PCROP start address register */
  #define FLASH_PCROP1SR_PCROP1 0x00007FFF
#define TOFF_FLASH_PCROP1ER 0x0028		/* (RW) FLASH bank1 PCROP end address register */
  #define FLASH_PCROP1ER_PCROP1_END 0x00007FFF
  #define FLASH_PCROP1ER_PCROP_RDP  0x80000000
#define TOFF_FLASH_WRP1AR   0x002C		/* (RW) FLASH bank1 WRP area A address register */
  #define FLASH_WRP1AR_WRP1A_STRT   0x0000007F
  #define FLASH_WRP1AR_WRP1A_END    0x007F0000
#define TOFF_FLASH_WRP1BR   0x0030		/* (RW) FLASH bank1 WRP area B address register */
  #define FLASH_WRP1BR_WRP1B_STRT   0x0000007F
  #define FLASH_WRP1BR_WRP1B_END    0x007F0000
#define TOFF_FLASH_PCROP2SR 0x0044		/* (RW) FLASH bank2 PCROP start address register */
  #define FLASH_PCROP2SR_PCROP2_STRT 0x00007FFF
#define TOFF_FLASH_PCROP2ER 0x0048		/* (RW) FLASH bank2 PCROP end address register */
  #define FLASH_PCROP2ER_PCROP2_END 0x00007FFF
#define TOFF_FLASH_WRP2AR   0x004C		/* (RW) FLASH bank2 WRP area A address register */
  #define FLASH_WRP2AR_WRP2A_STRT   0x000000FF
  #define FLASH_WRP2AR_WRP2A_END    0x00FF0000
#define TOFF_FLASH_WRP2BR   0x0050		/* (RW) FLASH bank2 WRP area B address register */
  #define FLASH_WRP2BR_WRP2B_STRT   0x0000007F
  #define FLASH_WRP2BR_WRP2B_END    0x007F0000
#define TOFF_FLASH_SEC1R    0x0070		/* (RW) FLASH Securable memory register bank1 */
  #define FLASH_SEC1R_SEC_SIZE1     0x000000FF
  #define FLASH_SEC1R_BOOT_LOCK     0x00010000
#define TOFF_FLASH_SEC2R    0x0074		/* (RW) FLASH Securable memory register bank2 */
  #define FLASH_SEC2R_SEC_SIZE2     0x000000FF


/*
 *  CRC CALCULATION UNIT
 */
#define TADR_CRC_BASE       (AHB1PERIPH_BASE + 0x3000)
#define TOFF_CRC_DR         0x0000		/* (RW) CRC Data register */
#define TOFF_CRC_IDR        0x0004		/* (RW) CRC Independent data register */
#define TOFF_CRC_CR         0x0008		/* (RW) CRC Control register */
  #define CRC_CR_RESET        0x00000001	/* RESET the CRC computation unit bit */
  #define CRC_CR_POLYSIZE     0x00000018	/* Polynomial size bits */
  #define CRC_CR_POLYSIZE_0   0x00000008
  #define CRC_CR_POLYSIZE_1   0x00000010
  #define CRC_CR_REV_IN       0x00000060	/* REV_IN Reverse Input Data bits */
  #define CRC_CR_REV_IN_0     0x00000020
  #define CRC_CR_REV_IN_1     0x00000040
  #define CRC_CR_REV_OUT      0x00000080	/* REV_OUT Reverse Output Data bits */
#define TOFF_CRC_INIT       0x0010		/* (RW) Initial CRC value register */
#define TOFF_CRC_POL        0x0014		/* (RW) CRC polynomial register */


/*
 *  GENERAL PURPOSE I/O
 */
#define TADR_GPIOA_BASE     (AHB2PERIPH_BASE + 0x0000)
#define TADR_GPIOB_BASE     (AHB2PERIPH_BASE + 0x0400)
#define TADR_GPIOC_BASE     (AHB2PERIPH_BASE + 0x0800)
#define TADR_GPIOD_BASE     (AHB2PERIPH_BASE + 0x0C00)
#define TADR_GPIOE_BASE     (AHB2PERIPH_BASE + 0x1000)
#define TADR_GPIOF_BASE     (AHB2PERIPH_BASE + 0x1400)
#define TADR_GPIOG_BASE     (AHB2PERIPH_BASE + 0x1800)
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
#define TADR_ADC1_BASE      (AHB2PERIPH_BASE + 0x08000000)
#define TADR_ADC2_BASE      (AHB2PERIPH_BASE + 0x08000100)
#define TADR_ADC3_BASE      (AHB2PERIPH_BASE + 0x08000400)
#define TADR_ADC4_BASE      (AHB2PERIPH_BASE + 0x08000500)
#define TADR_ADC5_BASE      (AHB2PERIPH_BASE + 0x08000600)
#define TOFF_ADC_ISR        0x0000		/* (RW) ADC interrupt and status register */
  #define ADC_ISR_ADRDY         0x00000001	/* ADC ready flag */
  #define ADC_ISR_EOSMP         0x00000002	/* ADC group regular end of sampling flag */
  #define ADC_ISR_EOC           0x00000004	/* ADC group regular end of unitary conversion flag */
  #define ADC_ISR_EOS           0x00000008	/* ADC End of Sequence flag */
  #define ADC_ISR_OVR           0x00000010	/* ADC group regular overrun flag */
  #define ADC_ISR_JEOC          0x00000020	/* ADC group injected end of unitary conversion flag */
  #define ADC_ISR_JEOS          0x00000040	/* ADC group injected end of sequence conversions flag */
  #define ADC_ISR_AWD1          0x00000080	/* ADC analog watchdog 1 flag */
  #define ADC_ISR_AWD2          0x00000100	/* ADC analog watchdog 2 flag */
  #define ADC_ISR_AWD3          0x00000200	/* ADC analog watchdog 3 flag */
  #define ADC_ISR_JQOVF         0x00000400	/* ADC group injected contexts queue overflow flag */
#define TOFF_ADC_IER        0x0004		/* (RW) ADC interrupt enable register */
  #define ADC_IER_ADRDYIE       0x00000001	/* ADC ready interrupt */
  #define ADC_IER_EOSMPIE       0x00000002	/* ADC group regular end of sampling interrupt */
  #define ADC_IER_EOCIE         0x00000004	/* ADC group regular end of unitary conversion interrupt */
  #define ADC_IER_EOSIE         0x00000008	/* ADC End of Sequence of conversion interrupt enable */
  #define ADC_IER_OVRIE         0x00000010	/* ADC group regular overrun interrupt */
  #define ADC_IER_JEOCIE        0x00000020	/* ADC group injected end of unitary conversion interrupt */
  #define ADC_IER_JEOSIE        0x00000040	/* ADC group injected end of sequence conversions interrupt */
  #define ADC_IER_AWD1IE        0x00000080	/* ADC analog watchdog 1 interrupt */
  #define ADC_IER_AWD2IE        0x00000100	/* ADC analog watchdog 2 interrupt */
  #define ADC_IER_AWD3IE        0x00000200	/* ADC analog watchdog 3 interrupt */
  #define ADC_IER_JQOVFIE       0x00000400	/* ADC group injected contexts queue overflow interrupt */
#define TOFF_ADC_CR         0x0008		/* (RW) ADC control register */
  #define ADC_CR_ADEN           0x00000001	/* ADC enable */
  #define ADC_CR_ADDIS          0x00000002	/* ADC disable */
  #define ADC_CR_ADSTART        0x00000004	/* ADC group regular conversion start */
  #define ADC_CR_JADSTART       0x00000008	/* ADC group injected conversion start */
  #define ADC_CR_ADSTP          0x00000010	/* ADC group regular conversion stop */
  #define ADC_CR_JADSTP         0x00000020	/* ADC group injected conversion stop */
  #define ADC_CR_ADVREGEN       0x10000000	/* ADC Voltage Regulator Enable */
  #define ADC_CR_DEEPPWD        0x20000000	/* ADC deep power down enable */
  #define ADC_CR_ADCALDIF       0x40000000	/* ADC differential mode for calibration */
  #define ADC_CR_ADCAL          0x80000000	/* ADC calibration */
#define TOFF_ADC_CFGR       0x000C		/* (RW) ADC configuration register 1 */
  #define ADC_CFGR_DMAEN        0x00000001	/* ADC DMA transfer enable */
  #define ADC_CFGR_DMACFG       0x00000002	/* ADC DMA transfer configuration */
  #define ADC_CFGR_SCANDIR      0x00000004	/* ADC group regular sequencer scan direction */
  #define ADC_CFGR_RES          0x00000018	/* ADC data resolution */
  #define ADC_CFGR_RES_0        0x00000008
  #define ADC_CFGR_RES_1        0x00000010
  #define ADC_CFGR_ALIGN        0x00000020	/* ADC data alignement */
  #define ADC_CFGR_EXTSEL       0x000003E0	/* ADC group regular external trigger source */
  #define ADC_CFGR_EXTSEL_0     0x00000020
  #define ADC_CFGR_EXTSEL_1     0x00000040
  #define ADC_CFGR_EXTSEL_2     0x00000080
  #define ADC_CFGR_EXTSEL_3     0x00000100
  #define ADC_CFGR_EXTSEL_4     0x00000200
  #define ADC_CFGR_EXTEN        0x00000C00	/* ADC group regular external trigger polarity */
  #define ADC_CFGR_EXTEN_0      0x00000400
  #define ADC_CFGR_EXTEN_1      0x00000800
  #define ADC_CFGR_OVRMOD       0x00001000	/* ADC group regular overrun configuration */
  #define ADC_CFGR_CONT         0x00002000	/* ADC group regular continuous conversion mode */
  #define ADC_CFGR_AUTDLY       0x00004000	/* ADC low power auto wait */
  #define ADC_CFGR_DISCEN       0x00010000	/* ADC group regular sequencer discontinuous mode */
  #define ADC_CFGR_DISCNUM      0x000E0000	/* ADC group regular sequencer discontinuous number of ranks */
  #define ADC_CFGR_DISCNUM_0    0x00020000
  #define ADC_CFGR_DISCNUM_1    0x00040000
  #define ADC_CFGR_DISCNUM_2    0x00080000
  #define ADC_CFGR_JDISCEN      0x00100000	/* ADC group injected sequencer discontinuous mode */
  #define ADC_CFGR_JQM          0x00200000	/* ADC group injected contexts queue mode */
  #define ADC_CFGR_AWD1SGL      0x00400000	/* ADC analog watchdog 1 monitoring a single channel or all channels */
  #define ADC_CFGR_AWD1EN       0x00800000	/* ADC analog watchdog 1 enable on scope ADC group regular */
  #define ADC_CFGR_JAWD1EN      0x01000000	/* ADC analog watchdog 1 enable on scope ADC group injected */
  #define ADC_CFGR_JAUTO        0x02000000
  #define ADC_CFGR_AWD1CH       0x7C000000	/* ADC analog watchdog 1 monitored channel selection */
  #define ADC_CFGR_AWD1CH_0     0x04000000
  #define ADC_CFGR_AWD1CH_1     0x08000000
  #define ADC_CFGR_AWD1CH_2     0x10000000
  #define ADC_CFGR_AWD1CH_3     0x20000000
  #define ADC_CFGR_AWD1CH_4     0x40000000
  #define ADC_CFGR_JQDIS        0x80000000	/* ADC group injected contexts queue disable */
#define TOFF_ADC_CFGR2      0x0010	/* (RW) ADC configuration register 2 */
  #define ADC_CFGR2_ROVSE       0x00000001	/* ADC oversampler enable on scope ADC group regular */
  #define ADC_CFGR2_JOVSE       0x00000002	/* ADC oversampler enable on scope ADC group injected */
  #define ADC_CFGR2_OVSR        0x0000001C	/* ADC oversampling ratio */
  #define ADC_CFGR2_OVSR_0      0x00000004
  #define ADC_CFGR2_OVSR_1      0x00000008
  #define ADC_CFGR2_OVSR_2      0x00000010
  #define ADC_CFGR2_OVSS        0x000001E0	/* ADC oversampling shift */
  #define ADC_CFGR2_OVSS_0      0x00000020
  #define ADC_CFGR2_OVSS_1      0x00000040
  #define ADC_CFGR2_OVSS_2      0x00000080
  #define ADC_CFGR2_OVSS_3      0x00000100
  #define ADC_CFGR2_TROVS       0x00000200	/* ADC oversampling discontinuous mode (triggered mode) for ADC group regular */
  #define ADC_CFGR2_ROVSM       0x00000400	/* ADC oversampling mode managing interlaced conversions of ADC group regular and group injected */
  #define ADC_CFGR2_GCOMP       0x00010000	/* ADC Gain Compensation mode */
  #define ADC_CFGR2_SWTRIG      0x02000000	/* ADC Software Trigger Bit for Sample time control trigger mode */
  #define ADC_CFGR2_BULB        0x04000000	/* ADC Bulb sampling mode */
  #define ADC_CFGR2_SMPTRIG     0x08000000	/* ADC Sample Time Control Trigger mode */
  #define ADC_CFGR2_LFTRIG      0x20000000	/* ADC Low Frequency Trigger */
#define TOFF_ADC_SMPR1      0x0014	/* (RW) ADC sampling time register 1 */
  #define ADC_SMPR1_SMP0        0x00000007	/* ADC channel 0 sampling time selection  */
  #define ADC_SMPR1_SMP0_0      0x00000001
  #define ADC_SMPR1_SMP0_1      0x00000002
  #define ADC_SMPR1_SMP0_2      0x00000004
  #define ADC_SMPR1_SMP1        0x00000038	/* ADC channel 1 sampling time selection  */
  #define ADC_SMPR1_SMP1_0      0x00000008
  #define ADC_SMPR1_SMP1_1      0x00000010
  #define ADC_SMPR1_SMP1_2      0x00000020
  #define ADC_SMPR1_SMP2        0x000001C0	/* ADC channel 2 sampling time selection  */
  #define ADC_SMPR1_SMP2_0      0x00000040
  #define ADC_SMPR1_SMP2_1      0x00000080
  #define ADC_SMPR1_SMP2_2      0x00000100
  #define ADC_SMPR1_SMP3        0x00000E00	/* ADC channel 3 sampling time selection  */
  #define ADC_SMPR1_SMP3_0      0x00000200
  #define ADC_SMPR1_SMP3_1      0x00000400
  #define ADC_SMPR1_SMP3_2      0x00000800
  #define ADC_SMPR1_SMP4        0x00007000	/* ADC channel 4 sampling time selection  */
  #define ADC_SMPR1_SMP4_0      0x00001000
  #define ADC_SMPR1_SMP4_1      0x00002000
  #define ADC_SMPR1_SMP4_2      0x00004000
  #define ADC_SMPR1_SMP5        0x00038000	/* ADC channel 5 sampling time selection  */
  #define ADC_SMPR1_SMP5_0      0x00008000
  #define ADC_SMPR1_SMP5_1      0x00010000
  #define ADC_SMPR1_SMP5_2      0x00020000
  #define ADC_SMPR1_SMP6        0x001C0000	/* ADC channel 6 sampling time selection  */
  #define ADC_SMPR1_SMP6_0      0x00040000
  #define ADC_SMPR1_SMP6_1      0x00080000
  #define ADC_SMPR1_SMP6_2      0x00100000
  #define ADC_SMPR1_SMP7        0x00E00000	/* ADC channel 7 sampling time selection  */
  #define ADC_SMPR1_SMP7_0      0x00200000
  #define ADC_SMPR1_SMP7_1      0x00400000
  #define ADC_SMPR1_SMP7_2      0x00800000
  #define ADC_SMPR1_SMP8        0x07000000	/* ADC channel 8 sampling time selection  */
  #define ADC_SMPR1_SMP8_0      0x01000000
  #define ADC_SMPR1_SMP8_1      0x02000000
  #define ADC_SMPR1_SMP8_2      0x04000000
  #define ADC_SMPR1_SMP9        0x38000000	/* ADC channel 9 sampling time selection  */
  #define ADC_SMPR1_SMP9_0      0x08000000
  #define ADC_SMPR1_SMP9_1      0x10000000
  #define ADC_SMPR1_SMP9_2      0x20000000
  #define ADC_SMPR1_SMPPLUS     0x80000000	/* ADC channels sampling time additional setting */
#define TOFF_ADC_SMPR2      0x0018	/* (RW) ADC sampling time register 2 */
  #define ADC_SMPR2_SMP10       0x00000007	/* ADC channel 10 sampling time selection  */
  #define ADC_SMPR2_SMP10_0     0x00000001
  #define ADC_SMPR2_SMP10_1     0x00000002
  #define ADC_SMPR2_SMP10_2     0x00000004
  #define ADC_SMPR2_SMP11       0x00000038	/* ADC channel 11 sampling time selection  */
  #define ADC_SMPR2_SMP11_0     0x00000008
  #define ADC_SMPR2_SMP11_1     0x00000010
  #define ADC_SMPR2_SMP11_2     0x00000020
  #define ADC_SMPR2_SMP12       0x000001C0	/* ADC channel 12 sampling time selection  */
  #define ADC_SMPR2_SMP12_0     0x00000040
  #define ADC_SMPR2_SMP12_1     0x00000080
  #define ADC_SMPR2_SMP12_2     0x00000100
  #define ADC_SMPR2_SMP13       0x00000E00	/* ADC channel 13 sampling time selection  */
  #define ADC_SMPR2_SMP13_0     0x00000200
  #define ADC_SMPR2_SMP13_1     0x00000400
  #define ADC_SMPR2_SMP13_2     0x00000800
  #define ADC_SMPR2_SMP14       0x00007000	/* ADC channel 14 sampling time selection  */
  #define ADC_SMPR2_SMP14_0     0x00001000
  #define ADC_SMPR2_SMP14_1     0x00002000
  #define ADC_SMPR2_SMP14_2     0x00004000
  #define ADC_SMPR2_SMP15       0x00038000	/* ADC channel 15 sampling time selection  */
  #define ADC_SMPR2_SMP15_0     0x00008000
  #define ADC_SMPR2_SMP15_1     0x00010000
  #define ADC_SMPR2_SMP15_2     0x00020000
  #define ADC_SMPR2_SMP16       0x001C0000	/* ADC channel 16 sampling time selection  */
  #define ADC_SMPR2_SMP16_0     0x00040000
  #define ADC_SMPR2_SMP16_1     0x00080000
  #define ADC_SMPR2_SMP16_2     0x00100000
  #define ADC_SMPR2_SMP17       0x00E00000	/* ADC channel 17 sampling time selection  */
  #define ADC_SMPR2_SMP17_0     0x00200000
  #define ADC_SMPR2_SMP17_1     0x00400000
  #define ADC_SMPR2_SMP17_2     0x00800000
  #define ADC_SMPR2_SMP18       0x07000000	/* ADC channel 18 sampling time selection  */
  #define ADC_SMPR2_SMP18_0     0x01000000
  #define ADC_SMPR2_SMP18_1     0x02000000
  #define ADC_SMPR2_SMP18_2     0x04000000
#define TOFF_ADC_TR1        0x0020	/* (RW) ADC analog watchdog 1 threshold register */
  #define ADC_TR1_LT1           0x00000FFF	/* ADC analog watchdog 1 threshold low */
  #define ADC_TR1_AWDFILT       0x00007000	/* ADC analog watchdog filtering parameter  */
  #define ADC_TR1_AWDFILT_0     0x00001000
  #define ADC_TR1_AWDFILT_1     0x00002000
  #define ADC_TR1_AWDFILT_2     0x00004000
  #define ADC_TR1_HT1           0x0FFF0000	/* ADC Analog watchdog 1 threshold high */
#define TOFF_ADC_TR2        0x0024	/* (RW) ADC analog watchdog 2 threshold register */
  #define ADC_TR2_LT2           0x000000FF	/* ADC analog watchdog 2 threshold low */
  #define ADC_TR2_HT2           0x00FF0000	/* ADC analog watchdog 2 threshold high */
#define TOFF_ADC_TR3        0x0028	/* (RW) ADC analog watchdog 3 threshold register */
  #define ADC_TR3_LT3           0x000000FF	/* ADC analog watchdog 3 threshold low */
  #define ADC_TR3_LT3_0         0x00000001
  #define ADC_TR3_LT3_1         0x00000002
  #define ADC_TR3_LT3_2         0x00000004
  #define ADC_TR3_LT3_3         0x00000008
  #define ADC_TR3_LT3_4         0x00000010
  #define ADC_TR3_LT3_5         0x00000020
  #define ADC_TR3_LT3_6         0x00000040
  #define ADC_TR3_LT3_7         0x00000080
  #define ADC_TR3_HT3           0x00FF0000	/* ADC analog watchdog 3 threshold high */
  #define ADC_TR3_HT3_0         0x00010000
  #define ADC_TR3_HT3_1         0x00020000
  #define ADC_TR3_HT3_2         0x00040000
  #define ADC_TR3_HT3_3         0x00080000
  #define ADC_TR3_HT3_4         0x00100000
  #define ADC_TR3_HT3_5         0x00200000
  #define ADC_TR3_HT3_6         0x00400000
  #define ADC_TR3_HT3_7         0x00800000
#define TOFF_ADC_SQR1       0x0030	/* (RW) ADC group regular sequencer register 1 */
  #define ADC_SQR1_L            0x0000000F	/* ADC group regular sequencer scan length */
  #define ADC_SQR1_L_0          0x00000001
  #define ADC_SQR1_L_1          0x00000002
  #define ADC_SQR1_L_2          0x00000004
  #define ADC_SQR1_L_3          0x00000008
  #define ADC_SQR1_SQ1          0x000007C0	/* ADC group regular sequencer rank 1 */
  #define ADC_SQR1_SQ1_0        0x00000040
  #define ADC_SQR1_SQ1_1        0x00000080
  #define ADC_SQR1_SQ1_2        0x00000100
  #define ADC_SQR1_SQ1_3        0x00000200
  #define ADC_SQR1_SQ1_4        0x00000400
  #define ADC_SQR1_SQ2          0x0001F000	/* ADC group regular sequencer rank 2 */
  #define ADC_SQR1_SQ2_0        0x00001000
  #define ADC_SQR1_SQ2_1        0x00002000
  #define ADC_SQR1_SQ2_2        0x00004000
  #define ADC_SQR1_SQ2_3        0x00008000
  #define ADC_SQR1_SQ2_4        0x00010000
  #define ADC_SQR1_SQ3          0x007C0000	/* ADC group regular sequencer rank 3 */
  #define ADC_SQR1_SQ3_0        0x00040000
  #define ADC_SQR1_SQ3_1        0x00080000
  #define ADC_SQR1_SQ3_2        0x00100000
  #define ADC_SQR1_SQ3_3        0x00200000
  #define ADC_SQR1_SQ3_4        0x00400000
  #define ADC_SQR1_SQ4          0x1F000000	/* ADC group regular sequencer rank 4 */
  #define ADC_SQR1_SQ4_0        0x01000000
  #define ADC_SQR1_SQ4_1        0x02000000
  #define ADC_SQR1_SQ4_2        0x04000000
  #define ADC_SQR1_SQ4_3        0x08000000
  #define ADC_SQR1_SQ4_4        0x10000000
#define TOFF_ADC_SQR2       0x0034	/* (RW) ADC group regular sequencer register 2 */
  #define ADC_SQR2_SQ5          0x0000001F	/* ADC group regular sequencer rank 5 */
  #define ADC_SQR2_SQ5_0        0x00000001
  #define ADC_SQR2_SQ5_1        0x00000002
  #define ADC_SQR2_SQ5_2        0x00000004
  #define ADC_SQR2_SQ5_3        0x00000008
  #define ADC_SQR2_SQ5_4        0x00000010
  #define ADC_SQR2_SQ6          0x000007C0	/* ADC group regular sequencer rank 6 */
  #define ADC_SQR2_SQ6_0        0x00000040
  #define ADC_SQR2_SQ6_1        0x00000080
  #define ADC_SQR2_SQ6_2        0x00000100
  #define ADC_SQR2_SQ6_3        0x00000200
  #define ADC_SQR2_SQ6_4        0x00000400
  #define ADC_SQR2_SQ7          0x0001F000	/* ADC group regular sequencer rank 7 */
  #define ADC_SQR2_SQ7_0        0x00001000
  #define ADC_SQR2_SQ7_1        0x00002000
  #define ADC_SQR2_SQ7_2        0x00004000
  #define ADC_SQR2_SQ7_3        0x00008000
  #define ADC_SQR2_SQ7_4        0x00010000
  #define ADC_SQR2_SQ8          0x007C0000	/* ADC group regular sequencer rank 8 */
  #define ADC_SQR2_SQ8_0        0x00040000
  #define ADC_SQR2_SQ8_1        0x00080000
  #define ADC_SQR2_SQ8_2        0x00100000
  #define ADC_SQR2_SQ8_3        0x00200000
  #define ADC_SQR2_SQ8_4        0x00400000
  #define ADC_SQR2_SQ9          0x1F000000	/* ADC group regular sequencer rank 9 */
  #define ADC_SQR2_SQ9_0        0x01000000
  #define ADC_SQR2_SQ9_1        0x02000000
  #define ADC_SQR2_SQ9_2        0x04000000
  #define ADC_SQR2_SQ9_3        0x08000000
  #define ADC_SQR2_SQ9_4        0x10000000
#define TOFF_ADC_SQR3       0x0038	/* (RW) ADC group regular sequencer register 3 */
  #define ADC_SQR3_SQ10         0x0000001F	/* ADC group regular sequencer rank 10 */
  #define ADC_SQR3_SQ10_0       0x00000001
  #define ADC_SQR3_SQ10_1       0x00000002
  #define ADC_SQR3_SQ10_2       0x00000004
  #define ADC_SQR3_SQ10_3       0x00000008
  #define ADC_SQR3_SQ10_4       0x00000010
  #define ADC_SQR3_SQ11         0x000007C0	/* ADC group regular sequencer rank 11 */
  #define ADC_SQR3_SQ11_0       0x00000040
  #define ADC_SQR3_SQ11_1       0x00000080
  #define ADC_SQR3_SQ11_2       0x00000100
  #define ADC_SQR3_SQ11_3       0x00000200
  #define ADC_SQR3_SQ11_4       0x00000400
  #define ADC_SQR3_SQ12         0x0001F000	/* ADC group regular sequencer rank 12 */
  #define ADC_SQR3_SQ12_0       0x00001000
  #define ADC_SQR3_SQ12_1       0x00002000
  #define ADC_SQR3_SQ12_2       0x00004000
  #define ADC_SQR3_SQ12_3       0x00008000
  #define ADC_SQR3_SQ12_4       0x00010000
  #define ADC_SQR3_SQ13         0x007C0000	/* ADC group regular sequencer rank 13 */
  #define ADC_SQR3_SQ13_0       0x00040000
  #define ADC_SQR3_SQ13_1       0x00080000
  #define ADC_SQR3_SQ13_2       0x00100000
  #define ADC_SQR3_SQ13_3       0x00200000
  #define ADC_SQR3_SQ13_4       0x00400000
  #define ADC_SQR3_SQ14         0x1F000000	/* ADC group regular sequencer rank 14 */
  #define ADC_SQR3_SQ14_0       0x01000000
  #define ADC_SQR3_SQ14_1       0x02000000
  #define ADC_SQR3_SQ14_2       0x04000000
  #define ADC_SQR3_SQ14_3       0x08000000
  #define ADC_SQR3_SQ14_4       0x10000000
#define TOFF_ADC_SQR4       0x003C	/* (RW) ADC group regular sequencer register 4 */
  #define ADC_SQR4_SQ15         0x0000001F	/* ADC group regular sequencer rank 15 */
  #define ADC_SQR4_SQ15_0       0x00000001
  #define ADC_SQR4_SQ15_1       0x00000002
  #define ADC_SQR4_SQ15_2       0x00000004
  #define ADC_SQR4_SQ15_3       0x00000008
  #define ADC_SQR4_SQ15_4       0x00000010
  #define ADC_SQR4_SQ16         0x000007C0	/* ADC group regular sequencer rank 16 */
  #define ADC_SQR4_SQ16_0       0x00000040
  #define ADC_SQR4_SQ16_1       0x00000080
  #define ADC_SQR4_SQ16_2       0x00000100
  #define ADC_SQR4_SQ16_3       0x00000200
  #define ADC_SQR4_SQ16_4       0x00000400
#define TOFF_ADC_DR         0x0040		/* (RW) ADC group regular data register */
  #define ADC_DR_DATA           0x0000FFFF	/* ADC group regular conversion data */
#define TOFF_ADC_JSQR       0x004C	/* (RW) ADC group injected sequencer register */
  #define ADC_JSQR_JL           0x00000003	/* ADC group injected sequencer scan length */
  #define ADC_JSQR_JL_0         0x00000001
  #define ADC_JSQR_JL_1         0x00000002
  #define ADC_JSQR_JEXTSEL      0x0000007C	/* ADC group injected external trigger source */
  #define ADC_JSQR_JEXTSEL_0    0x00000004
  #define ADC_JSQR_JEXTSEL_1    0x00000008
  #define ADC_JSQR_JEXTSEL_2    0x00000010
  #define ADC_JSQR_JEXTSEL_3    0x00000020
  #define ADC_JSQR_JEXTSEL_4    0x00000040
  #define ADC_JSQR_JEXTEN       0x00000180	/* ADC group injected external trigger polarity */
  #define ADC_JSQR_JEXTEN_0     0x00000080
  #define ADC_JSQR_JEXTEN_1     0x00000100
  #define ADC_JSQR_JSQ1         0x00003F00	/* ADC group injected sequencer rank 1 */
  #define ADC_JSQR_JSQ1_0       0x00000100
  #define ADC_JSQR_JSQ1_1       0x00000200
  #define ADC_JSQR_JSQ1_2       0x00000400
  #define ADC_JSQR_JSQ1_3       0x00000800
  #define ADC_JSQR_JSQ1_4       0x00001000
  #define ADC_JSQR_JSQ2         0x0007C000	/* ADC group injected sequencer rank 2 */
  #define ADC_JSQR_JSQ2_0       0x00004000
  #define ADC_JSQR_JSQ2_1       0x00008000
  #define ADC_JSQR_JSQ2_2       0x00010000
  #define ADC_JSQR_JSQ2_3       0x00020000
  #define ADC_JSQR_JSQ2_4       0x00040000
  #define ADC_JSQR_JSQ3         0x03E00000	/* ADC group injected sequencer rank 3 */
  #define ADC_JSQR_JSQ3_0       0x00200000
  #define ADC_JSQR_JSQ3_1       0x00400000
  #define ADC_JSQR_JSQ3_2       0x00800000
  #define ADC_JSQR_JSQ3_3       0x01000000
  #define ADC_JSQR_JSQ3_4       0x02000000
  #define ADC_JSQR_JSQ4         0xF8000000	/* ADC group injected sequencer rank 4 */
  #define ADC_JSQR_JSQ4_0       0x08000000
  #define ADC_JSQR_JSQ4_1       0x10000000
  #define ADC_JSQR_JSQ4_2       0x20000000
  #define ADC_JSQR_JSQ4_3       0x40000000
  #define ADC_JSQR_JSQ4_4       0x80000000
#define TOFF_ADC_OFR1       0x0060	/* (RW) ADC offset register 1 */
  #define ADC_OFR1_OFFSET1      0x00000FFF	/* ADC offset number 1 offset level */
  #define ADC_OFR1_OFFSETPOS    0x01000000	/* ADC offset number 1 positive */
  #define ADC_OFR1_SATEN        0x02000000	/* ADC offset number 1 saturation enable */
  #define ADC_OFR1_OFFSET1_CH   0x7C000000	/* ADC offset number 1 channel selection */
  #define ADC_OFR1_OFFSET1_CH_0 0x04000000
  #define ADC_OFR1_OFFSET1_CH_1 0x08000000
  #define ADC_OFR1_OFFSET1_CH_2 0x10000000
  #define ADC_OFR1_OFFSET1_CH_3 0x20000000
  #define ADC_OFR1_OFFSET1_CH_4 0x40000000
  #define ADC_OFR1_OFFSET1_EN   0x80000000	/* ADC offset number 1 enable */
#define TOFF_ADC_OFR2       0x0064	/* (RW) ADC offset register 2 */
  #define ADC_OFR2_OFFSET2      0x00000FFF	/* ADC offset number 2 offset level */
  #define ADC_OFR2_OFFSETPOS    0x01000000	/* ADC offset number 2 positive */
  #define ADC_OFR2_SATEN        0x02000000	/* ADC offset number 2 saturation enable */
  #define ADC_OFR2_OFFSET2_CH   0x7C000000	/* ADC offset number 2 channel selection */
  #define ADC_OFR2_OFFSET2_CH_0 0x04000000
  #define ADC_OFR2_OFFSET2_CH_1 0x08000000
  #define ADC_OFR2_OFFSET2_CH_2 0x10000000
  #define ADC_OFR2_OFFSET2_CH_3 0x20000000
  #define ADC_OFR2_OFFSET2_CH_4 0x40000000
  #define ADC_OFR2_OFFSET2_EN   0x80000000	/* ADC offset number 2 enable */
#define TOFF_ADC_OFR3       0x0068	/* (RW) ADC offset register 3 */
  #define ADC_OFR3_OFFSET3      0x00000FFF	/* ADC offset number 3 offset level */
  #define ADC_OFR3_OFFSETPOS    0x01000000	/* ADC offset number 3 positive */
  #define ADC_OFR3_SATEN        0x02000000	/* ADC offset number 3 saturation enable */
  #define ADC_OFR3_OFFSET3_CH   0x7C000000	/* ADC offset number 3 channel selection */
  #define ADC_OFR3_OFFSET3_CH_0 0x04000000
  #define ADC_OFR3_OFFSET3_CH_1 0x08000000
  #define ADC_OFR3_OFFSET3_CH_2 0x10000000
  #define ADC_OFR3_OFFSET3_CH_3 0x20000000
  #define ADC_OFR3_OFFSET3_CH_4 0x40000000
  #define ADC_OFR3_OFFSET3_EN   0x80000000	/* ADC offset number 3 enable */
#define TOFF_ADC_OFR4       0x006C	/* (RW) ADC offset register 4 */
  #define ADC_OFR4_OFFSET4      0x00000FFF	/* ADC offset number 4 offset level */
  #define ADC_OFR4_OFFSETPOS    0x01000000	/* ADC offset number 4 positive */
  #define ADC_OFR4_SATEN        0x02000000	/* ADC offset number 4 saturation enable */
  #define ADC_OFR4_OFFSET4_CH   0x7C000000	/* ADC offset number 4 channel selection */
  #define ADC_OFR4_OFFSET4_CH_0 0x04000000
  #define ADC_OFR4_OFFSET4_CH_1 0x08000000
  #define ADC_OFR4_OFFSET4_CH_2 0x10000000
  #define ADC_OFR4_OFFSET4_CH_3 0x20000000
  #define ADC_OFR4_OFFSET4_CH_4 0x40000000
  #define ADC_OFR4_OFFSET4_EN   0x80000000	/* ADC offset number 4 enable */
#define TOFF_ADC_JDR1       0x0080	/* (RW) ADC group injected rank 1 data register */
  #define ADC_JDR1_JDATA        0x0000FFFF	/* ADC group injected sequencer rank 1 conversion data */
#define TOFF_ADC_JDR2       0x0084	/* (RW) ADC group injected rank 2 data register */
  #define ADC_JDR2_JDATA        0x0000FFFF	/* ADC group injected sequencer rank 2 conversion data */
#define TOFF_ADC_JDR3       0x0088	/* (RW) ADC group injected rank 3 data register */
  #define ADC_JDR3_JDATA        0x0000FFFF	/* ADC group injected sequencer rank 3 conversion data */
#define TOFF_ADC_JDR4       0x008C	/* (RW) ADC group injected rank 4 data register */
  #define ADC_JDR4_JDATA        0x0000FFFF	/* ADC group injected sequencer rank 4 conversion data */
#define TOFF_ADC_AWD2CR     0x00A0	/* (RW) ADC analog watchdog 1 configuration register */
  #define ADC_AWD2CR_AWD2CH     0x0007FFFF	/* ADC analog watchdog 2 monitored channel selection */
  #define ADC_AWD2CR_AWD2CH_0   0x00000001
  #define ADC_AWD2CR_AWD2CH_1   0x00000002
  #define ADC_AWD2CR_AWD2CH_2   0x00000004
  #define ADC_AWD2CR_AWD2CH_3   0x00000008
  #define ADC_AWD2CR_AWD2CH_4   0x00000010
  #define ADC_AWD2CR_AWD2CH_5   0x00000020
  #define ADC_AWD2CR_AWD2CH_6   0x00000040
  #define ADC_AWD2CR_AWD2CH_7   0x00000080
  #define ADC_AWD2CR_AWD2CH_8   0x00000100
  #define ADC_AWD2CR_AWD2CH_9   0x00000200
  #define ADC_AWD2CR_AWD2CH_10  0x00000400
  #define ADC_AWD2CR_AWD2CH_11  0x00000800
  #define ADC_AWD2CR_AWD2CH_12  0x00001000
  #define ADC_AWD2CR_AWD2CH_13  0x00002000
  #define ADC_AWD2CR_AWD2CH_14  0x00004000
  #define ADC_AWD2CR_AWD2CH_15  0x00008000
  #define ADC_AWD2CR_AWD2CH_16  0x00010000
  #define ADC_AWD2CR_AWD2CH_17  0x00020000
  #define ADC_AWD2CR_AWD2CH_18  0x00040000
#define TOFF_ADC_AWD3CR     0x00A4	/* (RW) ADC analog watchdog 3 Configuration Register */
  #define ADC_AWD3CR_AWD3CH     0x0007FFFF	/* ADC analog watchdog 3 monitored channel selection */
  #define ADC_AWD3CR_AWD3CH_0   0x00000001
  #define ADC_AWD3CR_AWD3CH_1   0x00000002
  #define ADC_AWD3CR_AWD3CH_2   0x00000004
  #define ADC_AWD3CR_AWD3CH_3   0x00000008
  #define ADC_AWD3CR_AWD3CH_4   0x00000010
  #define ADC_AWD3CR_AWD3CH_5   0x00000020
  #define ADC_AWD3CR_AWD3CH_6   0x00000040
  #define ADC_AWD3CR_AWD3CH_7   0x00000080
  #define ADC_AWD3CR_AWD3CH_8   0x00000100
  #define ADC_AWD3CR_AWD3CH_9   0x00000200
  #define ADC_AWD3CR_AWD3CH_10  0x00000400
  #define ADC_AWD3CR_AWD3CH_11  0x00000800
  #define ADC_AWD3CR_AWD3CH_12  0x00001000
  #define ADC_AWD3CR_AWD3CH_13  0x00002000
  #define ADC_AWD3CR_AWD3CH_14  0x00004000
  #define ADC_AWD3CR_AWD3CH_15  0x00008000
  #define ADC_AWD3CR_AWD3CH_16  0x00010000
  #define ADC_AWD3CR_AWD3CH_17  0x00020000
  #define ADC_AWD3CR_AWD3CH_18  0x00040000
#define TOFF_ADC_DIFSEL     0x00B0	/* (RW) ADC differential mode selection register */
  #define ADC_DIFSEL_DIFSEL     0x0007FFFF	/* ADC channel differential or single-ended mode */
  #define ADC_DIFSEL_DIFSEL_0   0x00000001
  #define ADC_DIFSEL_DIFSEL_1   0x00000002
  #define ADC_DIFSEL_DIFSEL_2   0x00000004
  #define ADC_DIFSEL_DIFSEL_3   0x00000008
  #define ADC_DIFSEL_DIFSEL_4   0x00000010
  #define ADC_DIFSEL_DIFSEL_5   0x00000020
  #define ADC_DIFSEL_DIFSEL_6   0x00000040
  #define ADC_DIFSEL_DIFSEL_7   0x00000080
  #define ADC_DIFSEL_DIFSEL_8   0x00000100
  #define ADC_DIFSEL_DIFSEL_9   0x00000200
  #define ADC_DIFSEL_DIFSEL_10  0x00000400
  #define ADC_DIFSEL_DIFSEL_11  0x00000800
  #define ADC_DIFSEL_DIFSEL_12  0x00001000
  #define ADC_DIFSEL_DIFSEL_13  0x00002000
  #define ADC_DIFSEL_DIFSEL_14  0x00004000
  #define ADC_DIFSEL_DIFSEL_15  0x00008000
  #define ADC_DIFSEL_DIFSEL_16  0x00010000
  #define ADC_DIFSEL_DIFSEL_17  0x00020000
  #define ADC_DIFSEL_DIFSEL_18  0x00040000
#define TOFF_ADC_CALFACT    0x00B4	/* (RW) ADC data register */
  #define ADC_CALFACT_CALFACT_S 0x0000007F	/* Calibration factor */
  #define ADC_CALFACT_CALFACT_S_0 0x00000001
  #define ADC_CALFACT_CALFACT_S_1 0x00000002
  #define ADC_CALFACT_CALFACT_S_2 0x00000004
  #define ADC_CALFACT_CALFACT_S_3 0x00000008
  #define ADC_CALFACT_CALFACT_S_4 0x00000010
  #define ADC_CALFACT_CALFACT_S_5 0x00000020
  #define ADC_CALFACT_CALFACT_S_6 0x00000030
  #define ADC_CALFACT_CALFACT_D 0x007F0000	/* Calibration factor */
  #define ADC_CALFACT_CALFACT_D_0 0x00010000
  #define ADC_CALFACT_CALFACT_D_1 0x00020000
  #define ADC_CALFACT_CALFACT_D_2 0x00040000
  #define ADC_CALFACT_CALFACT_D_3 0x00080000
  #define ADC_CALFACT_CALFACT_D_4 0x00100000
  #define ADC_CALFACT_CALFACT_D_5 0x00200000
  #define ADC_CALFACT_CALFACT_D_6 0x00300000
#define TOFF_ADC_GCOMP      0x00C0	/* (RW) ADC calibration factors */
  #define ADC_GCOMP_GCOMPCOEFF    0x00003FFF	/* ADC Gain Compensation Coefficient */

#define TADR_ADC12_BASE     (AHB2PERIPH_BASE + 0x08000300)
#define TADR_ADC345_BASE    (AHB2PERIPH_BASE + 0x08000700)
#define TOFF_ADC_CSR        0x0000		/* (RW) ADC common status register */
  #define ADC_CSR_ADRDY_MST     0x00000001	/* ADC multimode master ready flag */
  #define ADC_CSR_EOSMP_MST     0x00000002	/* ADC multimode master group regular end of sampling flag */
  #define ADC_CSR_EOC_MST       0x00000004	/* ADC multimode master group regular end of unitary conversion flag */
  #define ADC_CSR_EOS_MST       0x00000008	/* ADC multimode master group regular end of sequence conversions flag */
  #define ADC_CSR_OVR_MST       0x00000010	/* ADC multimode master group regular overrun flag */
  #define ADC_CSR_JEOC_MST      0x00000020	/* ADC multimode master group injected end of unitary conversion flag */
  #define ADC_CSR_JEOS_MST      0x00000040	/* ADC multimode master group injected end of sequence conversions flag */
  #define ADC_CSR_AWD1_MST      0x00000080	/* ADC multimode master analog watchdog 1 flag */
  #define ADC_CSR_AWD2_MST      0x00000100	/* ADC multimode master analog watchdog 2 flag */
  #define ADC_CSR_AWD3_MST      0x00000200	/* ADC multimode master analog watchdog 3 flag */
  #define ADC_CSR_JQOVF_MST     0x00000400	/* ADC multimode master group injected contexts queue overflow flag */
  #define ADC_CSR_ADRDY_SLV     0x00010000	/* ADC multimode slave ready flag */
  #define ADC_CSR_EOSMP_SLV     0x00020000	/* ADC multimode slave group regular end of sampling flag */
  #define ADC_CSR_EOC_SLV       0x00040000	/* ADC multimode slave group regular end of unitary conversion flag */
  #define ADC_CSR_EOS_SLV       0x00080000	/* ADC multimode slave group regular end of sequence conversions flag */
  #define ADC_CSR_OVR_SLV       0x00100000	/* ADC multimode slave group regular overrun flag */
  #define ADC_CSR_JEOC_SLV      0x00200000	/* ADC multimode slave group injected end of unitary conversion flag */
  #define ADC_CSR_JEOS_SLV      0x00400000	/* ADC multimode slave group injected end of sequence conversions flag */
  #define ADC_CSR_AWD1_SLV      0x00800000	/* ADC multimode slave analog watchdog 1 flag */
  #define ADC_CSR_AWD2_SLV      0x01000000	/* ADC multimode slave analog watchdog 2 flag */
  #define ADC_CSR_AWD3_SLV      0x02000000	/* ADC multimode slave analog watchdog 3 flag */
  #define ADC_CSR_JQOVF_SLV     0x04000000	/* ADC multimode slave group injected contexts queue overflow flag */
#define TOFF_ADC_CCR        0x0008		/* (RW) ADC common configuration register */
  #define ADC_CCR_DUAL          0x0000001F	/* ADC multimode mode selection */
  #define ADC_CCR_DUAL_0        0x00000001
  #define ADC_CCR_DUAL_1        0x00000002
  #define ADC_CCR_DUAL_2        0x00000004
  #define ADC_CCR_DUAL_3        0x00000008
  #define ADC_CCR_DUAL_4        0x00000010
  #define ADC_CCR_DELAY         0x00000F00	/* ADC multimode delay between 2 sampling phases */
  #define ADC_CCR_DELAY_0       0x00000100
  #define ADC_CCR_DELAY_1       0x00000200
  #define ADC_CCR_DELAY_2       0x00000400
  #define ADC_CCR_DELAY_3       0x00000800
  #define ADC_CCR_DMACFG        0x00002000	/* ADC multimode DMA transfer configuration */
  #define ADC_CCR_MDMA          0x0000C000	/* ADC multimode DMA transfer enable */
  #define ADC_CCR_MDMA_0        0x00004000
  #define ADC_CCR_MDMA_1        0x00008000
  #define ADC_CCR_CKMODE        0x00030000	/* ADC common clock source and prescaler (prescaler only for clock source synchronous) */
  #define ADC_CCR_CKMODE_0      0x00010000
  #define ADC_CCR_CKMODE_1      0x00020000
  #define ADC_CCR_PRESC         0x003C0000	/* ADC common clock prescaler, only for clock source asynchronous */
  #define ADC_CCR_PRESC_0       0x00040000
  #define ADC_CCR_PRESC_1       0x00080000
  #define ADC_CCR_PRESC_2       0x00100000
  #define ADC_CCR_PRESC_3       0x00200000
  #define ADC_CCR_VREFEN        0x00400000	/* ADC internal path to VrefInt enable */
  #define ADC_CCR_VSENSESEL     0x00800000	/* ADC internal path to temperature sensor enable */
  #define ADC_CCR_VBATSEL       0x01000000	/* ADC internal path to battery voltage enable */
#define TOFF_ADC_CDR        0x000C		/* (RW) ADC common group regular data register */
  #define ADC_CDR_RDATA_MST     0x0000FFFF	/* ADC multimode master group regular conversion data */
  #define ADC_CDR_RDATA_SLV     0xFFFF0000	/* ADC multimode slave group regular conversion data */


/*
 *  DIGITAL TO ANALOG CONVTER
 */
#define TADR_DAC_BASE       (AHB2PERIPH_BASE + 0x08000800)
#define TADR_DAC1_BASE      (AHB2PERIPH_BASE + 0x08000800)
#define TADR_DAC2_BASE      (AHB2PERIPH_BASE + 0x08000C00)
#define TADR_DAC3_BASE      (AHB2PERIPH_BASE + 0x08001000)
#define TADR_DAC4_BASE      (AHB2PERIPH_BASE + 0x08001400)
#define TOFF_DAC_CR         0x0000		/* (RW) DAC control register */
  #define DAC_CR_EN1            0x00000001	/* DAC channel1 enable */
  #define DAC_CR_TEN1           0x00000002	/* DAC channel1 Trigger enable */
  #define DAC_CR_TSEL1          0x0000003C	/* TSEL1[3:0] (DAC channel1 Trigger selection) */
  #define DAC_CR_TSEL1_0        0x00000004
  #define DAC_CR_TSEL1_1        0x00000008
  #define DAC_CR_TSEL1_2        0x00000010
  #define DAC_CR_TSEL1_3        0x00000020
  #define DAC_CR_WAVE1          0x000000C0	/* WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable) */
  #define DAC_CR_WAVE1_0        0x00000040
  #define DAC_CR_WAVE1_1        0x00000080
  #define DAC_CR_MAMP1          0x00000F00	/* MAMP1[3:0] (DAC channel1 Mask/Amplitude selector) */
  #define DAC_CR_MAMP1_0        0x00000100
  #define DAC_CR_MAMP1_1        0x00000200
  #define DAC_CR_MAMP1_2        0x00000400
  #define DAC_CR_MAMP1_3        0x00000800
  #define DAC_CR_DMAEN1         0x00001000	/* DAC channel1 DMA enable */
  #define DAC_CR_DMAUDRIE1      0x00002000	/* DAC channel 1 DMA underrun interrupt enable  >*/
  #define DAC_CR_CEN1           0x00004000	/* DAC channel 1 calibration enable >*/
  #define DAC_CR_HFSEL          0x00008000	/* DAC channel 1 and 2 high frequency mode enable >*/
  #define DAC_CR_EN2            0x00010000	/* DAC channel2 enable */
  #define DAC_CR_TEN2           0x00020000	/* DAC channel2 Trigger enable */
  #define DAC_CR_TSEL2          0x003C0000	/* TSEL2[3:0] (DAC channel2 Trigger selection) */
  #define DAC_CR_TSEL2_0        0x00040000
  #define DAC_CR_TSEL2_1        0x00080000
  #define DAC_CR_TSEL2_2        0x00100000
  #define DAC_CR_TSEL2_3        0x00200000
  #define DAC_CR_WAVE2          0x00C00000	/* WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
  #define DAC_CR_WAVE2_0        0x00400000
  #define DAC_CR_WAVE2_1        0x00800000
  #define DAC_CR_MAMP2          0x0F000000	/* MAMP2[3:0] (DAC channel2 Mask/Amplitude selector) */
  #define DAC_CR_MAMP2_0        0x01000000
  #define DAC_CR_MAMP2_1        0x02000000
  #define DAC_CR_MAMP2_2        0x04000000
  #define DAC_CR_MAMP2_3        0x08000000
  #define DAC_CR_DMAEN2         0x10000000	/* DAC channel2 DMA enabled */
  #define DAC_CR_DMAUDRIE2      0x20000000	/* DAC channel2 DMA underrun interrupt enable  >*/
  #define DAC_CR_CEN2           0x40000000	/* DAC channel2 calibration enable >*/
#define TOFF_DAC_SWTRIGR	0x0004		/* (RW) DAC software trigger register */
  #define DAC_SWTRIGR_SWTRIG1   0x00000001	/* DAC channel1 software trigger */
  #define DAC_SWTRIGR_SWTRIG2   0x00000002	/* DAC channel2 software trigger */
  #define DAC_SWTRIGR_SWTRIGB1  0x00010000	/* DAC channel1 software trigger B */
  #define DAC_SWTRIGR_SWTRIGB2  0x00020000	/* DAC channel2 software trigger B */
#define TOFF_DAC_DHR12R1    0x0008		/* (RW) DAC channel1 12-bit right-aligned data holding register */
  #define DAC_DHR12R1_DACC1DHR  0x00000FFF	/* DAC channel1 12-bit Right aligned data */
  #define DAC_DHR12R1_DACC1DHRB 0x0FFF0000	/* DAC channel1 12-bit Right-aligned data B */
#define TOFF_DAC_DHR12L1    0x000C		/* (RW) DAC channel1 12-bit left aligned data holding register */
  #define DAC_DHR12L1_DACC1DHR  0x0000FFF0	/* DAC channel1 12-bit Left aligned data */
  #define DAC_DHR12L1_DACC1DHRB 0xFFF00000	/* DAC channel1 12-bit Left aligned data B */
#define TOFF_DAC_DHR8R1     0x0010		/* (RW) DAC channel1 8-bit right aligned data holding register */
  #define DAC_DHR8R1_DACC1DHR   0x000000FF	/* DAC channel1 8-bit Right aligned data */
  #define DAC_DHR8R1_DACC1DHRB  0x0000FF00	/* DAC channel1 8-bit Right aligned data B */
#define TOFF_DAC_DHR12R2    0x0014		/* (RW) DAC channel2 12-bit right aligned data holding register */
  #define DAC_DHR12R2_DACC2DHR  0x00000FFF	/* DAC channel2 12-bit Right aligned data */
  #define DAC_DHR12R2_DACC2DHRB 0x0FFF0000	/* DAC channel2 12-bit Right-aligned data B */
#define TOFF_DAC_DHR12L2    0x0018		/* (RW) DAC channel2 12-bit left aligned data holding register */
  #define DAC_DHR12L2_DACC2DHR  0x0000FFF0	/* DAC channel2 12-bit Left aligned data */
  #define DAC_DHR12L2_DACC2DHRB 0xFFF00000	/* DAC channel2 12-bit Left aligned data B */
#define TOFF_DAC_DHR8R2     0x001C		/* (RW) DAC channel2 8-bit right-aligned data holding register */
  #define DAC_DHR8R2_DACC2DHR   0x000000FF	/* DAC channel2 8-bit Right aligned data */
  #define DAC_DHR8R2_DACC2DHRB  0x0000FF00	/* DAC channel2 8-bit Right aligned data B */
#define TOFF_DAC_DHR12RD    0x0020		/* (RW) Dual DAC 12-bit right-aligned data holding register */
  #define DAC_DHR12RD_DACC1DHR  0x00000FFF	/* DAC channel1 12-bit Right aligned data */
  #define DAC_DHR12RD_DACC2DHR  0x0FFF0000	/* DAC channel2 12-bit Right aligned data */
#define TOFF_DAC_DHR12LD    0x0024		/* (RW) DUAL DAC 12-bit left aligned data holding register */
  #define DAC_DHR12LD_DACC1DHR  0x0000FFF0	/* DAC channel1 12-bit Left aligned data */
  #define DAC_DHR12LD_DACC2DHR  0xFFF00000	/* DAC channel2 12-bit Left aligned data */
#define TOFF_DAC_DHR8RD     0x0028		/* (RW) DUAL DAC 8-bit right aligned data holding register */
  #define DAC_DHR8RD_DACC1DHR   0x000000FF	/* DAC channel1 8-bit Right aligned data */
  #define DAC_DHR8RD_DACC2DHR   0x0000FF00	/* DAC channel2 8-bit Right aligned data */
#define TOFF_DAC_DOR1       0x002C		/* (RW) DAC channel1 data output register */
  #define DAC_DOR1_DACC1DOR     0x00000FFF	/* DAC channel1 data output */
  #define DAC_DOR1_DACC1DORB    0x0FFF0000	/* DAC channel1 data output B */
#define TOFF_DAC_DOR2       0x0030		/* (RW) DAC channel2 data output register */
  #define DAC_DOR2_DACC2DOR     0x00000FFF	/* DAC channel2 data output */
  #define DAC_DOR2_DACC2DORB    0x0FFF0000	/* DAC channel2 data output B */
#define TOFF_DAC_SR         0x0034		/* (RW) DAC status register */
  #define DAC_SR_DAC1RDY        0x00000800	/* DAC channel 1 ready status bit */
  #define DAC_SR_DORSTAT1       0x00001000	/* DAC channel 1 output register status bit */
  #define DAC_SR_DMAUDR1        0x00002000	/* DAC channel1 DMA underrun flag */
  #define DAC_SR_CAL_FLAG1      0x00004000	/* DAC channel1 calibration offset status */
  #define DAC_SR_BWST1          0x00008000	/* DAC channel1 busy writing sample time flag */
  #define DAC_SR_DAC2RDY        0x08000000	/* DAC channel 2 ready status bit */
  #define DAC_SR_DORSTAT2       0x10000000	/* DAC channel 2 output register status bit */
  #define DAC_SR_DMAUDR2        0x20000000	/* DAC channel2 DMA underrun flag */
  #define DAC_SR_CAL_FLAG2      0x40000000	/* DAC channel2 calibration offset status */
  #define DAC_SR_BWST2          0x80000000	/* DAC channel2 busy writing sample time flag */
#define TOFF_DAC_CCR        0x0038		/* (RW) DAC calibration control register */
  #define DAC_CCR_OTRIM1        0x0000001F	/* DAC channel1 offset trimming value */
  #define DAC_CCR_OTRIM2        0x001F0000	/* DAC channel2 offset trimming value */
#define TOFF_DAC_MCR        0x003C		/* (RW) DAC mode control register */
  #define DAC_MCR_MODE1         0x00000007	/* MODE1[2:0] (DAC channel1 mode) */
  #define DAC_MCR_MODE1_0       0x00000001
  #define DAC_MCR_MODE1_1       0x00000002
  #define DAC_MCR_MODE1_2       0x00000004
  #define DAC_MCR_DMADOUBLE1    0x00000100	/* DAC Channel 1 DMA double data mode */
  #define DAC_MCR_SINFORMAT1    0x00000200	/* DAC Channel 1 enable signed format */
  #define DAC_MCR_HFSEL         0x0000C000	/* HFSEL[1:0] (High Frequency interface mode selection) */
  #define DAC_MCR_HFSEL_0       0x00004000
  #define DAC_MCR_HFSEL_1       0x00008000
  #define DAC_MCR_MODE2         0x00070000	/* MODE2[2:0] (DAC channel2 mode) */
  #define DAC_MCR_MODE2_0       0x00010000
  #define DAC_MCR_MODE2_1       0x00020000
  #define DAC_MCR_MODE2_2       0x00040000
  #define DAC_MCR_DMADOUBLE2    0x01000000	/* DAC Channel 2 DMA double data mode */
  #define DAC_MCR_SINFORMAT2    0x02000000	/* DAC Channel 2 enable signed format */
#define TOFF_DAC_SHSR1      0x0040		/* (RW) DAC Sample and Hold sample time register 1 */
  #define DAC_SHSR1_TSAMPLE1    0x000003FF	/* DAC channel1 sample time */
#define TOFF_DAC_SHSR2      0x0044		/* (RW) DAC Sample and Hold sample time register 2 */
  #define DAC_SHSR2_TSAMPLE2    0x000003FF	/* DAC channel2 sample time */
#define TOFF_DAC_SHHR       0x0048		/* (RW) DAC Sample and Hold hold time register */
  #define DAC_SHHR_THOLD1       0x000003FF	/* DAC channel1 hold time */
  #define DAC_SHHR_THOLD2       0x03FF0000	/* DAC channel2 hold time */
#define TOFF_DAC_SHRR       0x004C		/* (RW) DAC Sample and Hold refresh time register */
  #define DAC_SHRR_TREFRESH1    0x000000FF	/* DAC channel1 refresh time */
  #define DAC_SHRR_TREFRESH2    0x00FF0000	/* DAC channel2 refresh time */
#define TOFF_DAC_STR1       0x0058		/* (RW) DAC Sawtooth register */
  #define DAC_STR1_STRSTDATA1   0x00000FFF	/* DAC Channel 1 Sawtooth starting value */
  #define DAC_STR1_STDIR1       0x00001000	/* DAC Channel 1 Sawtooth direction setting */
  #define DAC_STR1_STINCDATA1   0xFFFF0000	/* DAC Channel 1 Sawtooth increment value (12.4 bit format) */
#define TOFF_DAC_STR2       0x005C		/* (RW) DAC Sawtooth register */
  #define DAC_STR2_STRSTDATA2   0x00000FFF	/* DAC Channel 2 Sawtooth starting value */
  #define DAC_STR2_STDIR2       0x00001000	/* DAC Channel 2 Sawtooth direction setting */
  #define DAC_STR2_STINCDATA2   0xFFFF0000	/* DAC Channel 2 Sawtooth increment value (12.4 bit format) */
#define TOFF_DAC_STMODR     0x0060		/* (RW) DAC Sawtooth Mode register */
  #define DAC_STMODR_STRSTTRIGSEL1    0x0000000F	/* STRSTTRIGSEL1[3:0] (DAC Channel 1 Sawtooth Increment trigger selection) */
  #define DAC_STMODR_STRSTTRIGSEL1_0  0x00000001
  #define DAC_STMODR_STRSTTRIGSEL1_1  0x00000002
  #define DAC_STMODR_STRSTTRIGSEL1_2  0x00000004
  #define DAC_STMODR_STRSTTRIGSEL1_3  0x00000008
  #define DAC_STMODR_STINCTRIGSEL1    0x00000F00	/* STINCTRIGSEL1[3:0] (DAC Channel 1 Sawtooth Increment trigger selection) */
  #define DAC_STMODR_STINCTRIGSEL1_0  0x00000100
  #define DAC_STMODR_STINCTRIGSEL1_1  0x00000200
  #define DAC_STMODR_STINCTRIGSEL1_2  0x00000400
  #define DAC_STMODR_STINCTRIGSEL1_3  0x00000800
  #define DAC_STMODR_STRSTTRIGSEL2    0x000F0000	/* STRSTTRIGSEL2[3:0] (DAC Channel 2 Sawtooth Increment trigger selection) */
  #define DAC_STMODR_STRSTTRIGSEL2_0  0x00010000
  #define DAC_STMODR_STRSTTRIGSEL2_1  0x00020000
  #define DAC_STMODR_STRSTTRIGSEL2_2  0x00040000
  #define DAC_STMODR_STRSTTRIGSEL2_3  0x00080000
  #define DAC_STMODR_STINCTRIGSEL2    0x0F000000	/* STINCTRIGSEL2[3:0] (DAC Channel 2 Sawtooth Increment trigger selection) */
  #define DAC_STMODR_STINCTRIGSEL2_0  0x01000000
  #define DAC_STMODR_STINCTRIGSEL2_1  0x02000000
  #define DAC_STMODR_STINCTRIGSEL2_2  0x04000000
  #define DAC_STMODR_STINCTRIGSEL2_3  0x08000000


/*
 *  RANDOM NUMBER GENERATOR
 */
#define TADR_RNG_BASE       (AHB2PERIPH_BASE + 0x08060800)
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
 *  FLEXIBLE STATIC MEMORY
 */
#define TADR_FMC_R_BASE    (FMC_R_BASE + 0x0000)

/*
 *  FLEXIBLE MEMORY CONTROLLER
 */
#define TOFF_FMC_R_BTCR0    0x0000		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 0 */
#define TOFF_FMC_R_BTCR1    0x0004		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 1 */
#define TOFF_FMC_R_BTCR2    0x0008		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 2 */
#define TOFF_FMC_R_BTCR3    0x000C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 3 */
#define TOFF_FMC_R_BTCR4    0x0010		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 4 */
#define TOFF_FMC_R_BTCR5    0x0014		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 5 */
#define TOFF_FMC_R_BTCR6    0x0018		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 6 */
#define TOFF_FMC_R_BTCR7    0x001C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 7 */
#define TOFF_FMC_PCSCNTR    0x0020		/* (RW) PSRAM chip-select counter register */
  #define FMC_PCSCNTR_CSCOUNT   0x0000FFFF	/* CSCOUNT[15:0] bits (Chip select counter) */
  #define FMC_PCSCNTR_CNTB1EN   0x00010000	/* Counter PSRAM/NOR Bank1_1 enable */
  #define FMC_PCSCNTR_CNTB2EN   0x00020000	/* Counter PSRAM/NOR Bank1_2 enable */
  #define FMC_PCSCNTR_CNTB3EN   0x00040000	/* Counter PSRAM/NOR Bank1_3 enable */
  #define FMC_PCSCNTR_CNTB4EN   0x00080000	/* Counter PSRAM/NOR Bank1_4 enable */

/*
 *  FLEXIBLE MEMORY CONTROLLER BANK1E
 */
#define TOFF_FMC_R_BWTR0    0x0104		/* (RW) NOR/PSRAM write timing registers 0 */
#define TOFF_FMC_R_BWTR1    0x0108		/* (RW) NOR/PSRAM write timing registers 1 */
#define TOFF_FMC_R_BWTR2    0x010C		/* (RW) NOR/PSRAM write timing registers 2 */
#define TOFF_FMC_R_BWTR3    0x0110		/* (RW) NOR/PSRAM write timing registers 3 */
#define TOFF_FMC_R_BWTR4    0x0114		/* (RW) NOR/PSRAM write timing registers 4 */
#define TOFF_FMC_R_BWTR5    0x0118		/* (RW) NOR/PSRAM write timing registers 5 */
#define TOFF_FMC_R_BWTR6    0x011C		/* (RW) NOR/PSRAM write timing registers 6 */

/*
 *  FLEXIBLE MEMORY CONTROLLER BANK3
 */
#define TOFF_FMC_R_PCR      0x0080		/* (RW) NAND Flash control register */
  #define FMC_PCR_PWAITEN       0x00000002	/* Wait feature enable bit */
  #define FMC_PCR_PBKEN         0x00000004	/* NAND Flash memory bank enable bit */
  #define FMC_PCR_PTYP          0x00000008	/* Memory type */
  #define FMC_PCR_PWID          0x00000030	/* PWID[1:0] bits (NAND Flash databus width) */
  #define FMC_PCR_PWID_0        0x00000010
  #define FMC_PCR_PWID_1        0x00000020
  #define FMC_PCR_ECCEN         0x00000040	/* ECC computation logic enable bit */
  #define FMC_PCR_TCLR          0x00001E00	/* TCLR[3:0] bits (CLE to RE delay) */
  #define FMC_PCR_TCLR_0        0x00000200
  #define FMC_PCR_TCLR_1        0x00000400
  #define FMC_PCR_TCLR_2        0x00000800
  #define FMC_PCR_TCLR_3        0x00001000
  #define FMC_PCR_TAR           0x0001E000	/* TAR[3:0] bits (ALE to RE delay) */
  #define FMC_PCR_TAR_0         0x00002000
  #define FMC_PCR_TAR_1         0x00004000
  #define FMC_PCR_TAR_2         0x00008000
  #define FMC_PCR_TAR_3         0x00010000
  #define FMC_PCR_ECCPS         0x000E0000	/* ECCPS[1:0] bits (ECC page size)           */
  #define FMC_PCR_ECCPS_0       0x00020000
  #define FMC_PCR_ECCPS_1       0x00040000
  #define FMC_PCR_ECCPS_2       0x00080000
#define TOFF_FMC_R_SR       0x0084		/* (RW) NAND Flash FIFO status and interrupt register */
  #define FMC_SR_IRS            0x00000001	/* Interrupt Rising Edge status */
  #define FMC_SR_ILS            0x00000002	/* Interrupt Level status */
  #define FMC_SR_IFS            0x00000004	/* Interrupt Falling Edge status */
  #define FMC_SR_IREN           0x00000008	/* Interrupt Rising Edge detection Enable bit  */
  #define FMC_SR_ILEN           0x00000010	/* Interrupt Level detection Enable bit */
  #define FMC_SR_IFEN           0x00000020	/* Interrupt Falling Edge detection Enable bit */
  #define FMC_SR_FEMPT          0x00000040	/* FIFO empty */
#define TOFF_FMC_R_PMEM     0x0088		/* (RW) NAND Flash Common memory space timing register */
  #define FMC_PMEM_MEMSET       0x000000FF	/* MEMSET[7:0] bits (Common memory setup time) */
  #define FMC_PMEM_MEMSET_0     0x00000001
  #define FMC_PMEM_MEMSET_1     0x00000002
  #define FMC_PMEM_MEMSET_2     0x00000004
  #define FMC_PMEM_MEMSET_3     0x00000008
  #define FMC_PMEM_MEMSET_4     0x00000010
  #define FMC_PMEM_MEMSET_5     0x00000020
  #define FMC_PMEM_MEMSET_6     0x00000040
  #define FMC_PMEM_MEMSET_7     0x00000080
  #define FMC_PMEM_MEMWAIT      0x0000FF00	/* MEMWAIT[7:0] bits (Common memory wait time) */
  #define FMC_PMEM_MEMWAIT_0    0x00000100
  #define FMC_PMEM_MEMWAIT_1    0x00000200
  #define FMC_PMEM_MEMWAIT_2    0x00000400
  #define FMC_PMEM_MEMWAIT_3    0x00000800
  #define FMC_PMEM_MEMWAIT_4    0x00001000
  #define FMC_PMEM_MEMWAIT_5    0x00002000
  #define FMC_PMEM_MEMWAIT_6    0x00004000
  #define FMC_PMEM_MEMWAIT_7    0x00008000
  #define FMC_PMEM_MEMHOLD      0x00FF0000	/* MEMHOLD[7:0] bits (Common memory hold time) */
  #define FMC_PMEM_MEMHOLD_0    0x00010000
  #define FMC_PMEM_MEMHOLD_1    0x00020000
  #define FMC_PMEM_MEMHOLD_2    0x00040000
  #define FMC_PMEM_MEMHOLD_3    0x00080000
  #define FMC_PMEM_MEMHOLD_4    0x00100000
  #define FMC_PMEM_MEMHOLD_5    0x00200000
  #define FMC_PMEM_MEMHOLD_6    0x00400000
  #define FMC_PMEM_MEMHOLD_7    0x00800000
  #define FMC_PMEM_MEMHIZ       0xFF000000	/* MEMHIZ[7:0] bits (Common memory databus HiZ time) */
  #define FMC_PMEM_MEMHIZ_0     0x01000000
  #define FMC_PMEM_MEMHIZ_1     0x02000000
  #define FMC_PMEM_MEMHIZ_2     0x04000000
  #define FMC_PMEM_MEMHIZ_3     0x08000000
  #define FMC_PMEM_MEMHIZ_4     0x10000000
  #define FMC_PMEM_MEMHIZ_5     0x20000000
  #define FMC_PMEM_MEMHIZ_6     0x40000000
  #define FMC_PMEM_MEMHIZ_7     0x80000000
#define TOFF_FMC_R_PATT     0x008C		/* (RW) NAND Flash Attribute memory space timing register */
  #define FMC_PATT_ATTSET       0x000000FF	/* ATTSET[7:0] bits (Attribute memory setup time) */
  #define FMC_PATT_ATTSET_0     0x00000001
  #define FMC_PATT_ATTSET_1     0x00000002
  #define FMC_PATT_ATTSET_2     0x00000004
  #define FMC_PATT_ATTSET_3     0x00000008
  #define FMC_PATT_ATTSET_4     0x00000010
  #define FMC_PATT_ATTSET_5     0x00000020
  #define FMC_PATT_ATTSET_6     0x00000040
  #define FMC_PATT_ATTSET_7     0x00000080
  #define FMC_PATT_ATTWAIT      0x0000FF00	/* ATTWAIT[7:0] bits (Attribute memory wait time) */
  #define FMC_PATT_ATTWAIT_0    0x00000100
  #define FMC_PATT_ATTWAIT_1    0x00000200
  #define FMC_PATT_ATTWAIT_2    0x00000400
  #define FMC_PATT_ATTWAIT_3    0x00000800
  #define FMC_PATT_ATTWAIT_4    0x00001000
  #define FMC_PATT_ATTWAIT_5    0x00002000
  #define FMC_PATT_ATTWAIT_6    0x00004000
  #define FMC_PATT_ATTWAIT_7    0x00008000
  #define FMC_PATT_ATTHOLD      0x00FF0000	/* ATTHOLD[7:0] bits (Attribute memory hold time) */
  #define FMC_PATT_ATTHOLD_0    0x00010000
  #define FMC_PATT_ATTHOLD_1    0x00020000
  #define FMC_PATT_ATTHOLD_2    0x00040000
  #define FMC_PATT_ATTHOLD_3    0x00080000
  #define FMC_PATT_ATTHOLD_4    0x00100000
  #define FMC_PATT_ATTHOLD_5    0x00200000
  #define FMC_PATT_ATTHOLD_6    0x00400000
  #define FMC_PATT_ATTHOLD_7    0x00800000
  #define FMC_PATT_ATTHIZ       0xFF000000	/* ATTHIZ[7:0] bits (Attribute memory databus HiZ time) */
  #define FMC_PATT_ATTHIZ_0     0x01000000
  #define FMC_PATT_ATTHIZ_1     0x02000000
  #define FMC_PATT_ATTHIZ_2     0x04000000
  #define FMC_PATT_ATTHIZ_3     0x08000000
  #define FMC_PATT_ATTHIZ_4     0x10000000
  #define FMC_PATT_ATTHIZ_5     0x20000000
  #define FMC_PATT_ATTHIZ_6     0x40000000
  #define FMC_PATT_ATTHIZ_7     0x80000000
#define TOFF_FMC_R_ECCR     0x0090		/* (RW) NAND Flash ECC result registers */


/*
 * QUAD SERIAL PERIPHERAL INTERFACE
 */
#define TADR_QSPI_R_BASE    (QSPI_R_BASE)
#define TOFF_QUADSPI_CR     0x0000		/* (RW) QUADSPI Control register */
  #define QUADSPI_CR_EN         0x00000001	/* Enable */
  #define QUADSPI_CR_ABORT      0x00000002	/* Abort request */
  #define QUADSPI_CR_DMAEN      0x00000004	/* DMA Enable */
  #define QUADSPI_CR_TCEN       0x00000008	/* Timeout Counter Enable */
  #define QUADSPI_CR_SSHIFT     0x00000010	/* Sample Shift */
  #define QUADSPI_CR_DFM        0x00000040	/* Dual-flash mode */
  #define QUADSPI_CR_FSEL       0x00000080	/* Flash memory selection */
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
  #define QUADSPI_CCR_DHHC      0x40000000	/* DHHC: DDR hold */
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
#define TOFF_DBGMCU_APB1FZR1 0x0008		/* (RW) Debug MCU APB1 freeze register */
#define TOFF_DBGMCU_APB1FZR2 0x000C		/* (RW) Debug MCU APB1 freeze register 2 */
#define TOFF_DBGMCU_APB2FZ  0x0010		/* (RW) Debug MCU APB2 freeze register */


#endif  /* _STM32G4XX_H_ */

