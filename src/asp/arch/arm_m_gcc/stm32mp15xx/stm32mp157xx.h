/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2015-2016 by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *  Copyright (C) 2017-2020 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: stm32mp157xx.h,v 1.1 2020/08/25 16:46:15 roi Exp $
 */

#ifndef _STM32MP157XX_H_
#define _STM32MP157XX_H_

#include <sil.h>
#include "cmsis_m4.h"

/*
 *  割込み番号の最大値
 */
#define TMAX_INTNO          (16 + 150)

/*
 *  割込み優先度のビット幅
 */
#define TBITW_IPRI          4

/*
 *  INTERRUPT NUMBER
 */
#define IRQ_VECTOR_WWDG          (16 + 0)		/* Window WatchDog Interrupt */
#define IRQ_VECTOR_PVD           (16 + 1)		/* PVD through EXTI Line detection Interrupt */
#define IRQ_VECTOR_TAMP_STAMP    (16 + 2)		/* Tamper and TimeStamp interrupts through the EXTI line */
#define IRQ_VECTOR_RTC_WKUP      (16 + 3)		/* RTC Wakeup interrupt through the EXTI line */
#define IRQ_VECTOR_RCC           (16 + 5)		/* RCC global Interrupt */
#define IRQ_VECTOR_EXTI0         (16 + 6)		/* EXTI Line0 Interrupt */
#define IRQ_VECTOR_EXTI1         (16 + 7)		/* EXTI Line1 Interrupt */
#define IRQ_VECTOR_EXTI2         (16 + 8)		/* EXTI Line2 Interrupt */
#define IRQ_VECTOR_EXTI3         (16 + 9)		/* EXTI Line3 Interrupt */
#define IRQ_VECTOR_EXTI4         (16 + 10)		/* EXTI Line4 Interrupt */
#define IRQ_VECTOR_DMA1_STREAM0  (16 + 11)		/* DMA1 Stream 0 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM1  (16 + 12)		/* DMA1 Stream 1 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM2  (16 + 13)		/* DMA1 Stream 2 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM3  (16 + 14)		/* DMA1 Stream 3 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM4  (16 + 15)		/* DMA1 Stream 4 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM5  (16 + 16)		/* DMA1 Stream 5 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM6  (16 + 17)		/* DMA1 Stream 6 global Interrupt */
#define IRQ_VECTOR_ADC1          (16 + 18)		/* ADC1 global Interrupts */
#define IRQ_VECTOR_FDCAN1_IT0    (16 + 19)		/* FDCAN1 Interrupt line 0 */
#define IRQ_VECTOR_FDCAN2_IT0    (16 + 20)		/* FDCAN2 Interrupt line 0 */
#define IRQ_VECTOR_FDCAN1_IT1    (16 + 21)		/* FDCAN1 Interrupt line 1 */
#define IRQ_VECTOR_FDCAN2_IT1    (16 + 22)		/* FDCAN2 Interrupt line 1 */
#define IRQ_VECTOR_EXTI5         (16 + 23)		/* External Line[9:5] Interrupts */
#define IRQ_VECTOR_TIM1_BRK      (16 + 24)		/* TIM1 Break interrupt global interrupt */
#define IRQ_VECTOR_TIM1_UP       (16 + 25)		/* TIM1 Update Interrupt global interrupt */
#define IRQ_VECTOR_TIM1_TRG      (16 + 26)		/* TIM1 Trigger and Commutation global interrupt */
#define IRQ_VECTOR_TIM1_CC       (16 + 27)		/* TIM1 Capture Compare Interrupt */
#define IRQ_VECTOR_TIM2          (16 + 28)		/* TIM2 global Interrupt */
#define IRQ_VECTOR_TIM3          (16 + 29)		/* TIM3 global Interrupt */
#define IRQ_VECTOR_TIM4          (16 + 30)		/* TIM4 global Interrupt */
#define IRQ_VECTOR_I2C1_EV       (16 + 31)		/* I2C1 Event Interrupt */
#define IRQ_VECTOR_I2C1_ER       (16 + 32)		/* I2C1 Error Interrupt */
#define IRQ_VECTOR_I2C2_EV       (16 + 33)		/* I2C2 Event Interrupt */
#define IRQ_VECTOR_I2C2_ER       (16 + 34)		/* I2C2 Error Interrupt */
#define IRQ_VECTOR_SPI1          (16 + 35)		/* SPI1 global Interrupt */
#define IRQ_VECTOR_SPI2          (16 + 36)		/* SPI2 global Interrupt */
#define IRQ_VECTOR_USART1        (16 + 37)		/* USART1 global Interrupt */
#define IRQ_VECTOR_USART2        (16 + 38)		/* USART2 global Interrupt */
#define IRQ_VECTOR_USART3        (16 + 39)		/* USART3 global Interrupt */
#define IRQ_VECTOR_EXTI10        (16 + 40)		/* EXTI Line 10 Interrupts */
#define IRQ_VECTOR_RTC_TIMESTAMP (16 + 41)		/* RTC TimeStamp through EXTI Line Interrupt */
#define IRQ_VECTOR_EXTI11        (16 + 42)		/* EXTI Line 11 Interrupts */
#define IRQ_VECTOR_TIM8_BRK      (16 + 43)		/* TIM8 Break Interrupt global interrupt */
#define IRQ_VECTOR_TIM8_UP       (16 + 44)		/* TIM8 Update Interrupt global interrupt */
#define IRQ_VECTOR_TIM8_TRG_COM  (16 + 45)		/* TIM8 Trigger and Commutation global interrupt */
#define IRQ_VECTOR_TIM8_CC       (16 + 46)		/* TIM8 Capture Compare Interrupt */
#define IRQ_VECTOR_DMA1_STREAM7  (16 + 47)		/* DMA1 Stream7 Interrupt */
#define IRQ_VECTOR_FSMC          (16 + 48)		/* FSMC global Interrupt */
#define IRQ_VECTOR_SMMC1         (16 + 49)		/* SDMMC1 global Interrupt */
#define IRQ_VECTOR_TIM5          (16 + 50)		/* TIM5 global Interrupt */
#define IRQ_VECTOR_SPI3          (16 + 51)		/* SPI3 global Interrupt */
#define IRQ_VECTOR_UART4         (16 + 52)		/* UART4 global Interrupt */
#define IRQ_VECTOR_UART5         (16 + 53)		/* UART5 global Interrupt */
#define IRQ_VECTOR_TIM6          (16 + 54)		/* TIM6 global interrupt */
#define IRQ_VECTOR_TIM7          (16 + 55)		/* TIM7 global interrupt */
#define IRQ_VECTOR_DMA2_STREAM0  (16 + 56)		/* DMA2 Stream 0 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM1  (16 + 57)		/* DMA2 Stream 1 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM2  (16 + 58)		/* DMA2 Stream 2 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM3  (16 + 59)		/* DMA2 Stream 3 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM4  (16 + 60)		/* DMA2 Stream 4 global Interrupt */
#define IRQ_VECTOR_ETH           (16 + 61)		/* Ethernet global Interrupt */
#define IRQ_VECTOR_ETH_WKUP      (16 + 62)		/* Ethernet Wakeup through EXTI line Interrupt */
#define IRQ_VECTOR_FDCAN_CAL     (16 + 63)		/* CAN calibration unit interrupt */
#define IRQ_VECTOR_EXTI6         (16 + 64)		/* EXTI Line 6 Interrupts */
#define IRQ_VECTOR_EXTI7         (16 + 65)		/* EXTI Line 7 Interrupts */
#define IRQ_VECTOR_EXTI8         (16 + 66)		/* EXTI Line 8 Interrupts */
#define IRQ_VECTOR_EXTI9         (16 + 67)		/* EXTI Line 9 Interrupts */
#define IRQ_VECTOR_DMA2_STREAM5  (16 + 68)		/* DMA2 Stream 5 global interrupt */
#define IRQ_VECTOR_DMA2_STREAM6  (16 + 69)		/* DMA2 Stream 6 global interrupt */
#define IRQ_VECTOR_DMA2_STREAM7  (16 + 70)		/* DMA2 Stream 7 global interrupt */
#define IRQ_VECTOR_USART6        (16 + 71)		/* USART6 global interrupt */
#define IRQ_VECTOR_I2C3_EV       (16 + 72)		/* I2C3 event interrupt */
#define IRQ_VECTOR_I2C3_ER       (16 + 73)		/* I2C3 error interrupt */
#define IRQ_VECTOR_USBH_OHCI     (16 + 74)		/* USB OHCI global interrupt */
#define IRQ_VECTOR_USBH_ECHI     (16 + 75)		/* USB EHCI global interrupt */
#define IRQ_VECTOR_EXTI12        (16 + 76)		/* EXTI Line 12 Interrupts */
#define IRQ_VECTOR_EXTI13        (16 + 77)		/* EXTI Line 13 Interrupts */
#define IRQ_VECTOR_DCMI          (16 + 78)		/* DCMI global interrupt(only C) */
#define IRQ_VECTOR_CRYP1         (16 + 79)		/* CRYP crypto global interrupt */
#define IRQ_VECTOR_HASH1         (16 + 80)		/* Hash global interrupt */
#define IRQ_VECTOR_FPU           (16 + 81)		/* FPU global interrupt */
#define IRQ_VECTOR_UART7         (16 + 82)		/* UART7 global interrupt */
#define IRQ_VECTOR_UART8         (16 + 83)		/* UART8 global interrupt */
#define IRQ_VECTOR_SPI4          (16 + 84)		/* SPI4 global Interrupt */
#define IRQ_VECTOR_SPI5          (16 + 85)		/* SPI5 global Interrupt */
#define IRQ_VECTOR_SPI6          (16 + 86)		/* SPI6 global Interrupt */
#define IRQ_VECTOR_SAI1          (16 + 87)		/* SAI1 global Interrupt */
#define IRQ_VECTOR_LTDC          (16 + 88)		/* LTDC global Interrupt */
#define IRQ_VECTOR_LTDC_ER       (16 + 89)		/* LTDC Error global Interrupt */
#define IRQ_VECTOR_ADC2          (16 + 90)		/* ADC2 global Interrupts */
#define IRQ_VECTOR_SAI2          (16 + 91)		/* SAI2 global Interrupt */
#define IRQ_VECTOR_QUADSPI       (16 + 92)		/* Quad SPI global interrupt */
#define IRQ_VECTOR_LPTIM1        (16 + 93)		/* LP TIM1 interrupt */
#define IRQ_VECTOR_CEC           (16 + 94)		/* HDMI-CEC global Interrupt */
#define IRQ_VECTOR_I2C4_EV       (16 + 95)		/* I2C4 Event Interrupt */
#define IRQ_VECTOR_I2C4_ER       (16 + 96)		/* I2C4 Error Interrupt */
#define IRQ_VECTOR_SPDIF_RX      (16 + 97)		/* SPDIF-RX global Interrupt */
#define IRQ_VECTOR_OTG           (16 + 98)		/* USB On The Go global interrupt */
#define IRQ_VECTOR_IPCC_RX0      (16 + 100)		/* IPCC RX0 Occupied interrupt (interrupt going to AIEC input as well)  */
#define IRQ_VECTOR_IPCC_TX0      (16 + 101)		/* IPCC TX0 Free interrupt (interrupt going to AIEC input as well) */
#define IRQ_VECTOR_DMAMUX1_OVR   (16 + 102)		/* DMAMUX1 Overrun interrupt */
#define IRQ_VECTOR_IPCC_RX1      (16 + 103)		/* IPCC RX1 Occupied interrupt (interrupt going to AIEC input as well)  */
#define IRQ_VECTOR_IPCC_TX1      (16 + 104)		/* IPCC TX1 Free interrupt (interrupt going to AIEC input as well) */
#define IRQ_VECTOR_CRYP2         (16 + 105)		/* CRYP2 crypto global interrupt */
#define IRQ_VECTOR_HASH2         (16 + 106)		/* Crypto Hash2 interrupt */
#define IRQ_VECTOR_I2C5_EV       (16 + 107)		/* I2C5 Event Interrupt */
#define IRQ_VECTOR_I2C5_ER       (16 + 108)		/* I2C5 Error Interrupt */
#define IRQ_VECTOR_GPU           (16 + 109)		/* GPU global Interrupt */
#define IRQ_VECTOR_DFSDM1_FLT0   (16 + 110)		/* DFSDM Filter1 Interrupt */
#define IRQ_VECTOR_DFSDM1_FLT1   (16 + 111)		/* DFSDM Filter2 Interrupt */
#define IRQ_VECTOR_DFSDM1_FLT2   (16 + 112)		/* DFSDM Filter3 Interrupt */
#define IRQ_VECTOR_DFSDM1_FLT3   (16 + 113)		/* DFSDM Filter4 Interrupt */
#define IRQ_VECTOR_SAI3          (16 + 114)		/* SAI3 global Interrupt   */
#define IRQ_VECTOR_DFSDM1_FLT4   (16 + 115)		/* DFSDM Filter5 Interrupt */
#define IRQ_VECTOR_TIM15         (16 + 116)		/* TIM15 global Interrupt */
#define IRQ_VECTOR_TIM16         (16 + 117)		/* TIM16 global Interrupt */
#define IRQ_VECTOR_TIM17         (16 + 118)		/* TIM17 global Interrupt */
#define IRQ_VECTOR_TIM12         (16 + 119)		/* TIM12 global Interrupt */
#define IRQ_VECTOR_MDIOS         (16 + 120)		/* MDIOS global Interrupt */
#define IRQ_VECTOR_EXTI14        (16 + 121)		/* EXTI Line 14 Interrupts  */
#define IRQ_VECTOR_MDMA          (16 + 122)		/* MDMA global Interrupt */
#define IRQ_VECTOR_DSI           (16 + 123)		/* DSI global Interrupt */
#define IRQ_VECTOR_SDMMC2        (16 + 124)		/* SDMMC2 global Interrupt */
#define IRQ_VECTOR_HSEM_IT2      (16 + 125)		/* HSEM Semaphore Interrupt 2 */
#define IRQ_VECTOR_DFSDM1_FLT5   (16 + 126)		/* DFSDM Filter6 Interrupt */
#define IRQ_VECTOR_EXTI15        (16 + 127)		/* EXTI Line 15 Interrupts */
#define IRQ_VECTOR_nCTIIRQ1      (16 + 128)		/* Cortex-M4 CTI interrupt 1 */
#define IRQ_VECTOR_nCTIIRQ2      (16 + 129)		/* Cortex-M4 CTI interrupt 2 */
#define IRQ_VECTOR_TIM13         (16 + 130)		/* TIM13 global interrupt */
#define IRQ_VECTOR_TIM14         (16 + 131)		/* TIM14 global interrupt */
#define IRQ_VECTOR_DAC           (16 + 132)		/* DAC1 and DAC2 underrun error interrupts */
#define IRQ_VECTOR_RNG1          (16 + 133)		/* RNG1 interrupt */
#define IRQ_VECTOR_RNG2          (16 + 134)		/* RNG2 interrupt */
#define IRQ_VECTOR_I2C6_EV       (16 + 135)		/* I2C6 Event Interrupt */
#define IRQ_VECTOR_I2C6_ER       (16 + 136)		/* I2C6 Error Interrupt */
#define IRQ_VECTOR_SDMMC3        (16 + 137)		/* SDMMC3 global Interrupt  */
#define IRQ_VECTOR_LPTIM2        (16 + 138)		/* LP TIM2 global interrupt */
#define IRQ_VECTOR_LPTIM3        (16 + 139)		/* LP TIM3 global interrupt */
#define IRQ_VECTOR_LPTIM4        (16 + 140)		/* LP TIM4 global interrupt */
#define IRQ_VECTOR_LPTIM5        (16 + 141)		/* LP TIM5 global interrupt */
#define IRQ_VECTOR_ETH1_LPI      (16 + 142)		/* ETH1_LPI interrupt (LPI: lpi_intr_o) */
#define IRQ_VECTOR_MPU_SEV       (16 + 144)		/* MPU Send Event  interrupt */
#define IRQ_VECTOR_RCC_WAKEUP    (16 + 145)		/* RCC Wake up interrupt */
#define IRQ_VECTOR_SAI4          (16 + 146)		/* SAI4 global interrupt */
#define IRQ_VECTOR_DTS           (16 + 147)		/* Temperature sensor Global Interrupt */
#define IRQ_VECTOR_WAKEUP_PIN    (16 + 149)		/* Interrupt for all 6 wake-up pins */


/*
 *  PERIPHERAL MEMORY MAP
 */
#define MCU_AHB_SRAM        0x10000000	/* Base address of : (up to 288KB) system data RAM accessible over over AHB */
#define MCU_AHB_RETRAM      0x00000000	/* Base address of : (up to 64KB) Retention RAM accessible over over AHB */
#define SYSRAM_BASE         0x2FFC0000	/* Base address of : (up to 256KB) System RAM accessible over over AXI */
#define RETRAM_BASE         MCU_AHB_RETRAM
#define SRAM_BASE           MCU_AHB_SRAM
#define PERIPH_BASE         0x40000000	/* Base address of : AHB/ABP Peripherals */
#define MPU_AXI_BUS_MEM_BASE 0x60000000	/* Base address of : AXI Bus */

#define FMC_NOR_MEM_BASE    (MPU_AXI_BUS_MEM_BASE)		/* Base address of : FMC NOR memories  accessible over AXI */
#define QSPI_MEM_BASE       (MPU_AXI_BUS_MEM_BASE + 0x10000000)	/* Base address of : QSPI memories  accessible over AXI */
#define FMC_NAND_MEM_BASE   (MPU_AXI_BUS_MEM_BASE + 0x20000000)	/* Base address of : FMC NAND memories  accessible over AXI */
#define STM_DATA_BASE       (MPU_AXI_BUS_MEM_BASE + 0x30000000)	/* Base address of : STM Data accessible over AXI */
#define DRAM_MEM_BASE       (MPU_AXI_BUS_MEM_BASE + 0x60000000)	/* Base address of : DRAM (DDR) over AXI */

/* Device electronic signature memory map */
#define UID_BASE            (0x5C005234L)	/* Unique Device ID register base address */
#define PACKAGE_BASE        (0x5C005240L)	/* Package Data register base address */
#define RPN_BASE            (0x5C005204L)	/* Device Part Number register base address */
#define DV_BASE             (0x50081000L)	/* Device Version register base address */

/* Peripheral memory map */
#define MCU_APB1_PERIPH_BASE    (PERIPH_BASE + 0x00000000)
#define MCU_APB2_PERIPH_BASE    (PERIPH_BASE + 0x04000000)
#define MCU_AHB2_PERIPH_BASE    (PERIPH_BASE + 0x08000000)
#define MCU_AHB3_PERIPH_BASE    (PERIPH_BASE + 0x0C000000)
#define MCU_AHB4_PERIPH_BASE    (PERIPH_BASE + 0x10000000)
#define MCU_APB3_PERIPH_BASE    (PERIPH_BASE + 0x10020000)
#define APB_DEBUG_PERIPH_BASE   (PERIPH_BASE + 0x10080000)
#define MPU_AHB5_PERIPH_BASE    (PERIPH_BASE + 0x14000000)
#define GPV_PERIPH_BASE         (PERIPH_BASE + 0x17000000)
#define MPU_AHB6_PERIPH_BASE    (PERIPH_BASE + 0x18000000)
#define MPU_APB4_PERIPH_BASE    (PERIPH_BASE + 0x1A000000)
#define MPU_APB5_PERIPH_BASE    (PERIPH_BASE + 0x1C000000)

#define BKPSRAM_BASE            (MPU_AHB5_PERIPH_BASE + 0x0000)
#define STGENR_BASE             (MPU_APB4_PERIPH_BASE + 0x5000)

#define USB_OTG_DEVICE_BASE         0x800
#define USB_OTG_IN_ENDPOINT_BASE    0x900
#define USB_OTG_OUT_ENDPOINT_BASE   0xB00
#define USB_OTG_HOST_BASE           0x400
#define USB_OTG_HOST_PORT_BASE      0x440
#define USB_OTG_HOST_CHANNEL_BASE   0x500
#define USB_OTG_PCGCCTL_BASE        0xE00
#define USB_OTG_FIFO_BASE           0x1000
#define USB_OTG_FIFO_SIZE           0x1000


/*
 *  TIM
 */
#define TADR_TIM2_BASE      (MCU_APB1_PERIPH_BASE + 0x0000)
#define TADR_TIM3_BASE      (MCU_APB1_PERIPH_BASE + 0x1000)
#define TADR_TIM4_BASE      (MCU_APB1_PERIPH_BASE + 0x2000)
#define TADR_TIM5_BASE      (MCU_APB1_PERIPH_BASE + 0x3000)
#define TADR_TIM6_BASE      (MCU_APB1_PERIPH_BASE + 0x4000)
#define TADR_TIM7_BASE      (MCU_APB1_PERIPH_BASE + 0x5000)
#define TADR_TIM12_BASE     (MCU_APB1_PERIPH_BASE + 0x6000)
#define TADR_TIM13_BASE     (MCU_APB1_PERIPH_BASE + 0x7000)
#define TADR_TIM14_BASE     (MCU_APB1_PERIPH_BASE + 0x8000)
#define TADR_TIM1_BASE      (MCU_APB2_PERIPH_BASE + 0x0000)
#define TADR_TIM8_BASE      (MCU_APB2_PERIPH_BASE + 0x1000)
#define TADR_TIM15_BASE     (MCU_APB2_PERIPH_BASE + 0x6000)
#define TADR_TIM16_BASE     (MCU_APB2_PERIPH_BASE + 0x7000)
#define TADR_TIM17_BASE     (MCU_APB2_PERIPH_BASE + 0x8000)
#define TOFF_TIM_CR1        0x0000		/* (RW-16) TIM control register 1 */
  #define TIM_CR1_CEN           0x0001	/* Counter enable */
  #define TIM_CR1_UDIS          0x0002	/* Update disable */
  #define TIM_CR1_URS           0x0004	/* Update request source */
  #define TIM_CR1_OPM           0x0008	/* One pulse mode */
  #define TIM_CR1_DIR           0x0010	/* Direction */
  #define TIM_CR1_CMS           0x0060	/* CMS[1:0] bits (Center-aligned mode selection) */
  #define TIM_CR1_CMS_0         0x0020	/* Bit 0 */
  #define TIM_CR1_CMS_1         0x0040	/* Bit 1 */
  #define TIM_CR1_ARPE          0x0080	/* Auto-reload preload enable */
  #define TIM_CR1_CKD           0x0300	/* CKD[1:0] bits (clock division) */
  #define TIM_CR1_CKD_0         0x0100	/* Bit 0 */
  #define TIM_CR1_CKD_1         0x0200	/* Bit 1 */
  #define TIM_CR1_UIFREMAP      0x0800	/* Update interrupt flag remap */
#define TOFF_TIM_CR2        0x0004		/* (RW) TIM control register 2 */
  #define TIM_CR2_CCPC          0x00000001	/* Capture/Compare Preloaded Control */
  #define TIM_CR2_CCUS          0x00000004	/* Capture/Compare Control Update Selection */
  #define TIM_CR2_CCDS          0x00000008	/* Capture/Compare DMA Selection */
  #define TIM_CR2_MMS           0x00000070	/* MMS[2:0] bits (Master Mode Selection) */
  #define TIM_CR2_MMS_0         0x00000010
  #define TIM_CR2_MMS_1         0x00000020
  #define TIM_CR2_MMS_2         0x00000040
  #define TIM_CR2_TI1S          0x00000080	/* TI1 Selection */
  #define TIM_CR2_OIS1          0x00000100	/* Output Idle state 1 (OC1 output) */
  #define TIM_CR2_OIS1N         0x00000200	/* Output Idle state 1 (OC1N output) */
  #define TIM_CR2_OIS2          0x00000400	/* Output Idle state 2 (OC2 output) */
  #define TIM_CR2_OIS2N         0x00000800	/* Output Idle state 2 (OC2N output) */
  #define TIM_CR2_OIS3          0x00001000	/* Output Idle state 3 (OC3 output) */
  #define TIM_CR2_OIS3N         0x00002000	/* Output Idle state 3 (OC3N output) */
  #define TIM_CR2_OIS4          0x00004000	/* Output Idle state 4 (OC4 output) */
  #define TIM_CR2_OIS5          0x00010000	/* Output Idle state 4 (OC4 output) */
  #define TIM_CR2_OIS6          0x00040000	/* Output Idle state 4 (OC4 output) */
  #define TIM_CR2_MMS2          0x00F00000	/* MMS[2:0] bits (Master Mode Selection) */
  #define TIM_CR2_MMS2_0        0x00100000
  #define TIM_CR2_MMS2_1        0x00200000
  #define TIM_CR2_MMS2_2        0x00400000
  #define TIM_CR2_MMS2_3        0x00800000
#define TOFF_TIM_SMCR       0x0008		/* (RW) TIM slave mode control register */
  #define TIM_SMCR_SMS          0x00010007	/* SMS[2:0] bits (Slave mode selection) */
  #define TIM_SMCR_SMS_0        0x00000001
  #define TIM_SMCR_SMS_1        0x00000002
  #define TIM_SMCR_SMS_2        0x00000004
  #define TIM_SMCR_SMS_3        0x00010000
  #define TIM_SMCR_TS           0x00300070	/* TS[4:0] bits (Trigger selection) */
  #define TIM_SMCR_TS_0         0x00000010
  #define TIM_SMCR_TS_1         0x00000020
  #define TIM_SMCR_TS_2         0x00000040
  #define TIM_SMCR_TS_3         0x00100000
  #define TIM_SMCR_TS_4         0x00200000
  #define TIM_SMCR_MSM          0x00000080	/* Master/slave mode */
  #define TIM_SMCR_ETF          0x00000F00	/* ETF[3:0] bits (External trigger filter) */
  #define TIM_SMCR_ETF_0        0x00000100
  #define TIM_SMCR_ETF_1        0x00000200
  #define TIM_SMCR_ETF_2        0x00000400
  #define TIM_SMCR_ETF_3        0x00000800
  #define TIM_SMCR_ETPS         0x00003000	/* ETPS[1:0] bits (External trigger prescaler) */
  #define TIM_SMCR_ETPS_0       0x00001000
  #define TIM_SMCR_ETPS_1       0x00002000
  #define TIM_SMCR_ECE          0x00004000	/* External clock enable */
  #define TIM_SMCR_ETP          0x00008000	/* External trigger polarity */
#define TOFF_TIM_DIER       0x000C		/* (RW-16) TIM DMA/interrupt enable register */
  #define TIM_DIER_UIE          0x0001	/* Update interrupt enable */
  #define TIM_DIER_CC1IE        0x0002	/* Capture/Compare 1 interrupt enable */
  #define TIM_DIER_CC2IE        0x0004	/* Capture/Compare 2 interrupt enable */
  #define TIM_DIER_CC3IE        0x0008	/* Capture/Compare 3 interrupt enable */
  #define TIM_DIER_CC4IE        0x0010	/* Capture/Compare 4 interrupt enable */
  #define TIM_DIER_COMIE        0x0020	/* COM interrupt enable */
  #define TIM_DIER_TIE          0x0040	/* Trigger interrupt enable */
  #define TIM_DIER_BIE          0x0080	/* Break interrupt enable */
  #define TIM_DIER_UDE          0x0100	/* Update DMA request enable */
  #define TIM_DIER_CC1DE        0x0200	/* Capture/Compare 1 DMA request enable */
  #define TIM_DIER_CC2DE        0x0400	/* Capture/Compare 2 DMA request enable */
  #define TIM_DIER_CC3DE        0x0800	/* Capture/Compare 3 DMA request enable */
  #define TIM_DIER_CC4DE        0x1000	/* Capture/Compare 4 DMA request enable */
  #define TIM_DIER_COMDE        0x2000	/* COM DMA request enable */
  #define TIM_DIER_TDE          0x4000	/* Trigger DMA request enable */
#define TOFF_TIM_SR         0x0010		/* (RW) TIM status register */
  #define TIM_SR_UIF            0x00000001	/* Update interrupt Flag */
  #define TIM_SR_CC1IF          0x00000002	/* Capture/Compare 1 interrupt Flag */
  #define TIM_SR_CC2IF          0x00000004	/* Capture/Compare 2 interrupt Flag */
  #define TIM_SR_CC3IF          0x00000008	/* Capture/Compare 3 interrupt Flag */
  #define TIM_SR_CC4I           0x00000010	/* Capture/Compare 4 interrupt Flag */
  #define TIM_SR_COMIF          0x00000020	/* COM interrupt Flag */
  #define TIM_SR_TIF            0x00000040	/* Trigger interrupt Flag */
  #define TIM_SR_BIF            0x00000080	/* Break interrupt Flag */
  #define TIM_SR_B2IF           0x00000100	/* Break2 interrupt Flag */
  #define TIM_SR_CC1OF          0x00000200	/* Capture/Compare 1 Overcapture Flag */
  #define TIM_SR_CC2OF          0x00000400	/* Capture/Compare 2 Overcapture Flag */
  #define TIM_SR_CC3OF          0x00000800	/* Capture/Compare 3 Overcapture Flag */
  #define TIM_SR_CC4OF          0x00001000	/* Capture/Compare 4 Overcapture Flag */
  #define TIM_SR_CC5IF          0x00010000	/* Capture/Compare 5 interrupt Flag */
  #define TIM_SR_CC6IF          0x00020000	/* Capture/Compare 6 interrupt Flag */
  #define TIM_SR_SBIF           0x00002000	/* System Break Flag */
#define TOFF_TIM_EGR        0x0014		/* (RW-16) TIM event generation register */
  #define TIM_EGR_UG            0x0001	/* Update Generation */
  #define TIM_EGR_CC1G          0x0002	/* Capture/Compare 1 Generation */
  #define TIM_EGR_CC2G          0x0004	/* Capture/Compare 2 Generation */
  #define TIM_EGR_CC3G          0x0008	/* Capture/Compare 3 Generation */
  #define TIM_EGR_CC4G          0x0010	/* Capture/Compare 4 Generation */
  #define TIM_EGR_COMG          0x0020	/* Capture/Compare Control Update Generation */
  #define TIM_EGR_TG            0x0040	/* Trigger Generation */
  #define TIM_EGR_BG            0x0080	/* Break Generation */
  #define TIM_EGR_B2G           0x0100	/* Break Generation */
#define TOFF_TIM_CCMR1      0x0018		/* (RW) TIM capture/compare mode register 1 */
  #define TIM_CCMR1_CC1S        0x00000003	/* CC1S[1:0] bits (Capture/Compare 1 Selection) */
  #define TIM_CCMR1_CC1S_0      0x00000001
  #define TIM_CCMR1_CC1S_1      0x00000002
  #define TIM_CCMR1_OC1FE       0x00000004	/* Output Compare 1 Fast enable */
  #define TIM_CCMR1_OC1PE       0x00000008	/* Output Compare 1 Preload enable */
  #define TIM_CCMR1_OC1M        0x00010070	/* OC1M[2:0] bits (Output Compare 1 Mode) */
  #define TIM_CCMR1_OC1M_0      0x00000010
  #define TIM_CCMR1_OC1M_1      0x00000020
  #define TIM_CCMR1_OC1M_2      0x00000040
  #define TIM_CCMR1_OC1M_3      0x00010000
  #define TIM_CCMR1_OC1CE       0x00000080	/* Output Compare 1Clear Enable */
  #define TIM_CCMR1_CC2S        0x00000300	/* CC2S[1:0] bits (Capture/Compare 2 Selection) */
  #define TIM_CCMR1_CC2S_0      0x00000100
  #define TIM_CCMR1_CC2S_1      0x00000200
  #define TIM_CCMR1_OC2FE       0x00000400	/* Output Compare 2 Fast enable */
  #define TIM_CCMR1_OC2PE       0x00000800	/* Output Compare 2 Preload enable */
  #define TIM_CCMR1_OC2M        0x01007000	/* OC2M[2:0] bits (Output Compare 2 Mode) */
  #define TIM_CCMR1_OC2M_0      0x00001000
  #define TIM_CCMR1_OC2M_1      0x00002000
  #define TIM_CCMR1_OC2M_2      0x00004000
  #define TIM_CCMR1_OC2M_3      0x01000000
  #define TIM_CCMR1_OC2CE       0x00008000	/* Output Compare 2 Clear Enable */

  #define TIM_CCMR1_IC1PSC      0x0000000C	/* IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
  #define TIM_CCMR1_IC1PSC_0    0x00000004
  #define TIM_CCMR1_IC1PSC_1    0x00000008
  #define TIM_CCMR1_IC1F        0x000000F0	/* IC1F[3:0] bits (Input Capture 1 Filter) */
  #define TIM_CCMR1_IC1F_0      0x00000010
  #define TIM_CCMR1_IC1F_1      0x00000020
  #define TIM_CCMR1_IC1F_2      0x00000040
  #define TIM_CCMR1_IC1F_3      0x00000080
  #define TIM_CCMR1_IC2PSC      0x00000C00	/* IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
  #define TIM_CCMR1_IC2PSC_0    0x00000400
  #define TIM_CCMR1_IC2PSC_1    0x00000800
  #define TIM_CCMR1_IC2F        0x0000F000	/* IC2F[3:0] bits (Input Capture 2 Filter) */
  #define TIM_CCMR1_IC2F_0      0x00001000
  #define TIM_CCMR1_IC2F_1      0x00002000
  #define TIM_CCMR1_IC2F_2      0x00004000
  #define TIM_CCMR1_IC2F_3      0x00008000
#define TOFF_TIM_CCMR2      0x001C		/* (RW) TIM capture/compare mode register 2 */
  #define TIM_CCMR2_CC3S        0x00000003	/* CC3S[1:0] bits (Capture/Compare 3 Selection) */
  #define TIM_CCMR2_CC3S_0      0x00000001
  #define TIM_CCMR2_CC3S_1      0x00000002
  #define TIM_CCMR2_OC3FE       0x00000004	/* Output Compare 3 Fast enable */
  #define TIM_CCMR2_OC3PE       0x00000008	/* Output Compare 3 Preload enable */
  #define TIM_CCMR2_OC3M        0x00010070	/* OC3M[2:0] bits (Output Compare 3 Mode) */
  #define TIM_CCMR2_OC3M_0      0x00000010
  #define TIM_CCMR2_OC3M_1      0x00000020
  #define TIM_CCMR2_OC3M_2      0x00000040
  #define TIM_CCMR2_OC3M_3      0x00010000
  #define TIM_CCMR2_OC3CE       0x00000080	/* Output Compare 3 Clear Enable */
  #define TIM_CCMR2_CC4S        0x00000300	/* CC4S[1:0] bits (Capture/Compare 4 Selection) */
  #define TIM_CCMR2_CC4S_0      0x00000100
  #define TIM_CCMR2_CC4S_1      0x00000200
  #define TIM_CCMR2_OC4FE       0x00000400	/* Output Compare 4 Fast enable */
  #define TIM_CCMR2_OC4PE       0x00000800	/* Output Compare 4 Preload enable */
  #define TIM_CCMR2_OC4M        0x01007000	/* OC4M[2:0] bits (Output Compare 4 Mode) */
  #define TIM_CCMR2_OC4M_0      0x00001000
  #define TIM_CCMR2_OC4M_1      0x00002000
  #define TIM_CCMR2_OC4M_2      0x00004000
  #define TIM_CCMR2_OC4M_3      0x01000000
  #define TIM_CCMR2_OC4CE       0x00008000	/* Output Compare 4 Clear Enable */

  #define TIM_CCMR2_IC3PSC      0x000C		/* IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
  #define TIM_CCMR2_IC3PSC_0    0x0004		/* Bit 0 */
  #define TIM_CCMR2_IC3PSC_1    0x0008		/* Bit 1 */
  #define TIM_CCMR2_IC3F        0x00F0		/* IC3F[3:0] bits (Input Capture 3 Filter) */
  #define TIM_CCMR2_IC3F_0      0x0010		/* Bit 0 */
  #define TIM_CCMR2_IC3F_1      0x0020		/* Bit 1 */
  #define TIM_CCMR2_IC3F_2      0x0040		/* Bit 2 */
  #define TIM_CCMR2_IC3F_3      0x0080		/* Bit 3 */
  #define TIM_CCMR2_IC4PSC      0x0C00		/* IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
  #define TIM_CCMR2_IC4PSC_0    0x0400		/* Bit 0 */
  #define TIM_CCMR2_IC4PSC_1    0x0800		/* Bit 1 */
  #define TIM_CCMR2_IC4F        0xF000		/* IC4F[3:0] bits (Input Capture 4 Filter) */
  #define TIM_CCMR2_IC4F_0      0x1000		/* Bit 0 */
  #define TIM_CCMR2_IC4F_1      0x2000		/* Bit 1 */
  #define TIM_CCMR2_IC4F_2      0x4000		/* Bit 2 */
  #define TIM_CCMR2_IC4F_3      0x8000		/* Bit 3 */
#define TOFF_TIM_CCER       0x0020		/* (RW) TIM capture/compare enable register */
  #define TIM_CCER_CC1E         0x00000001	/* Capture/Compare 1 output enable */
  #define TIM_CCER_CC1P         0x00000002	/* Capture/Compare 1 output Polarity */
  #define TIM_CCER_CC1NE        0x00000004	/* Capture/Compare 1 Complementary output enable */
  #define TIM_CCER_CC1NP        0x00000008	/* Capture/Compare 1 Complementary output Polarity */
  #define TIM_CCER_CC2E         0x00000010	/* Capture/Compare 2 output enable */
  #define TIM_CCER_CC2P         0x00000020	/* Capture/Compare 2 output Polarity */
  #define TIM_CCER_CC2NE        0x00000040	/* Capture/Compare 2 Complementary output enable */
  #define TIM_CCER_CC2NP        0x00000080	/* Capture/Compare 2 Complementary output Polarity */
  #define TIM_CCER_CC3E         0x00000100	/* Capture/Compare 3 output enable */
  #define TIM_CCER_CC3P         0x00000200	/* Capture/Compare 3 output Polarity */
  #define TIM_CCER_CC3NE        0x00000400	/* Capture/Compare 3 Complementary output enable */
  #define TIM_CCER_CC3NP        0x00000800	/* Capture/Compare 3 Complementary output Polarity */
  #define TIM_CCER_CC4E         0x00001000	/* Capture/Compare 4 output enable */
  #define TIM_CCER_CC4P         0x00002000	/* Capture/Compare 4 output Polarity */
  #define TIM_CCER_CC4NP        0x00008000	/* Capture/Compare 4 Complementary output Polarity */
  #define TIM_CCER_CC5E         0x00010000	/* Capture/Compare 5 output enable */
  #define TIM_CCER_CC5P         0x00020000	/* Capture/Compare 5 output Polarity */
  #define TIM_CCER_CC6E         0x00100000	/* Capture/Compare 6 output enable */
  #define TIM_CCER_CC6P         0x00200000	/* Capture/Compare 6 output Polarity */
#define TOFF_TIM_CNT        0x0024		/* (RW) TIM counter register */
  #define TIM_CNT_CNT           0xFFFFFFFF	/* Counter Value */
  #define TIM_CNT_UIFCPY        0x80000000	/* Update interrupt flag copy */
#define TOFF_TIM_PSC        0x0028		/* (RW-16) TIM prescaler */
#define TOFF_TIM_ARR        0x002C		/* (RW) TIM auto-reload register */
#define TOFF_TIM_RCR        0x0030		/* (RW) TIM repetition counter register */
  #define TIM_RCR_REP           0x00FF		/* Repetition Counter Value */
#define TOFF_TIM_CCR1       0x0034		/* (RW-16) TIM capture/compare register 1 */
#define TOFF_TIM_CCR2       0x0038		/* (RW-16) TIM capture/compare register 2 */
#define TOFF_TIM_CCR3       0x003C		/* (RW-16) TIM capture/compare register 3 */
#define TOFF_TIM_CCR4       0x0040		/* (RW-16) TIM capture/compare register 4 */
#define TOFF_TIM_BDTR       0x0044		/* (RW) TIM break and dead-time register */
  #define TIM_BDTR_DTG          0x000000FF	/* DTG[0:7] bits (Dead-Time Generator set-up) */
  #define TIM_BDTR_DTG_0        0x00000001
  #define TIM_BDTR_DTG_1        0x00000002
  #define TIM_BDTR_DTG_2        0x00000004
  #define TIM_BDTR_DTG_3        0x00000008
  #define TIM_BDTR_DTG_4        0x00000010
  #define TIM_BDTR_DTG_5        0x00000020
  #define TIM_BDTR_DTG_6        0x00000040
  #define TIM_BDTR_DTG_7        0x00000080
  #define TIM_BDTR_LOCK         0x00000300	/* LOCK[1:0] bits (Lock Configuration) */
  #define TIM_BDTR_LOCK_0       0x00000100
  #define TIM_BDTR_LOCK_1       0x00000200
  #define TIM_BDTR_OSSI         0x00000400	/* Off-State Selection for Idle mode */
  #define TIM_BDTR_OSSR         0x00000800	/* Off-State Selection for Run mode */
  #define TIM_BDTR_BKE          0x00001000	/* Break enable for Break1 */
  #define TIM_BDTR_BKP          0x00002000	/* Break Polarity for Break1 */
  #define TIM_BDTR_AOE          0x00004000	/* Automatic Output enable */
  #define TIM_BDTR_MOE          0x00008000	/* Main Output enable */
  #define TIM_BDTR_BKF          0x000F0000	/* Break Filter for Break1 */
  #define TIM_BDTR_BK2F         0x00F00000	/* Break Filter for Break2 */
  #define TIM_BDTR_BK2E         0x01000000	/* Break enable for Break2 */
  #define TIM_BDTR_BK2P         0x02000000	/* Break Polarity for Break2 */
  #define TIM_BDTR_BKDSRM       0x04000000	/* Break Disarmed for Break1 */
  #define TIM_BDTR_BK2DSRM      0x08000000	/* Break Disarmed for Break2 */
  #define TIM_BDTR_BKBID        0x10000000	/* Break Bidirectionnal for Break1 */
  #define TIM_BDTR_BK2BID       0x20000000	/* Break Bidirectionnal for Break2 */
#define TOFF_TIM_DCR        0x0048		/* (RW-16) TIM DMA control register */
  #define TIM_DCR_DBA           0x001F	/* DBA[4:0] bits (DMA Base Address) */
  #define TIM_DCR_DBA_0         0x0001	/* Bit 0 */
  #define TIM_DCR_DBA_1         0x0002	/* Bit 1 */
  #define TIM_DCR_DBA_2         0x0004	/* Bit 2 */
  #define TIM_DCR_DBA_3         0x0008	/* Bit 3 */
  #define TIM_DCR_DBA_4         0x0010	/* Bit 4 */
  #define TIM_DCR_DBL           0x1F00	/* DBL[4:0] bits (DMA Burst Length) */
  #define TIM_DCR_DBL_0         0x0100	/* Bit 0 */
  #define TIM_DCR_DBL_1         0x0200	/* Bit 1 */
  #define TIM_DCR_DBL_2         0x0400	/* Bit 2 */
  #define TIM_DCR_DBL_3         0x0800	/* Bit 3 */
  #define TIM_DCR_DBL_4         0x1000	/* Bit 4 */
#define TOFF_TIM_DMAR       0x004C		/* (RW-16) TIM DMA address for full transfer */
#define TOFF_TIM_CCMR3      0x0054		/* (RW) TIM capture/compare mode register 3 */
  #define TIM_CCMR3_OC5FE       0x00000004	/* Output Compare 5 Fast enable */
  #define TIM_CCMR3_OC5PE       0x00000008	/* Output Compare 5 Preload enable */
  #define TIM_CCMR3_OC5M        0x00010070	/* OC5M[2:0] bits (Output Compare 5 Mode) */
  #define TIM_CCMR3_OC5M_0      0x00000010
  #define TIM_CCMR3_OC5M_1      0x00000020
  #define TIM_CCMR3_OC5M_2      0x00000040
  #define TIM_CCMR3_OC5M_3      0x00010000
  #define TIM_CCMR3_OC5CE       0x00000080	/* Output Compare 5 Clear Enable */
  #define TIM_CCMR3_OC6FE       0x00000400	/* Output Compare 4 Fast enable */
  #define TIM_CCMR3_OC6PE       0x00000800	/* Output Compare 4 Preload enable */
  #define TIM_CCMR3_OC6M        0x01007000	/* OC4M[2:0] bits (Output Compare 4 Mode) */
  #define TIM_CCMR3_OC6M_0      0x00001000
  #define TIM_CCMR3_OC6M_1      0x00002000
  #define TIM_CCMR3_OC6M_2      0x00004000
  #define TIM_CCMR3_OC6M_3      0x01000000
  #define TIM_CCMR3_OC6CE       0x00008000	/* Output Compare 4 Clear Enable */
#define TOFF_TIM_CCR5       0x0058		/* (RW) TIM capture/compare register5 */
  #define TIM_CCR5_CCR5         0xFFFFFFFF	/* Capture/Compare 5 Value */
  #define TIM_CCR5_GC5C1        0x20000000	/* Group Channel 5 and Channel 1 */
  #define TIM_CCR5_GC5C2        0x40000000	/* Group Channel 5 and Channel 2 */
  #define TIM_CCR5_GC5C3        0x80000000	/* Group Channel 5 and Channel 3 */
#define TOFF_TIM_CCR6       0x005C		/* (RW) TIM capture/compare register6 */
#define TOFF_TIM_AF1        0x0060		/* (RW) TIM alternate function option register 1 */
#define TOFF_TIM_AF2        0x0060		/* (RW) TIM alternate function option register 2 */
#define TOFF_TIM_TISEL      0x0064		/* (RW) TIM Input Selection register */
#define TOFF_TIM_VERR       0x03F4		/* (R)  TIM version register */
#define TOFF_TIM_IPIDR      0x03F8		/* (R)  TIM Identification register */
#define TOFF_TIM_SIDR       0x03FC		/* (R)  TIM Size Identification register */


/*
 *  LPTIM
 */
#define TADR_LPTIM1_BASE    (MCU_APB1_PERIPH_BASE + 0x9000)
#define TADR_LPTIM2_BASE    (MCU_APB3_PERIPH_BASE + 0x1000)
#define TADR_LPTIM3_BASE    (MCU_APB3_PERIPH_BASE + 0x2000)
#define TADR_LPTIM4_BASE    (MCU_APB3_PERIPH_BASE + 0x3000)
#define TADR_LPTIM5_BASE    (MCU_APB3_PERIPH_BASE + 0x4000)
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
  #define LPTIM_CFGR_TIMOUT     0x00080000	/* Timout enable */
  #define LPTIM_CFGR_WAVE       0x00100000	/* Waveform shape */
  #define LPTIM_CFGR_WAVPOL     0x00200000	/* Waveform shape polarity */
  #define LPTIM_CFGR_PRELOAD    0x00400000	/* Reg update mode */
  #define LPTIM_CFGR_COUNTMODE  0x00800000	/* Counter mode enable */
  #define LPTIM_CFGR_ENC        0x01000000	/* Encoder mode enable */
#define TOFF_LPTIM_CR       0x0010		/* (RW) LPTIM Control register */
  #define LPTIM_CR_ENABLE       0x00000001	/* LPTIMer enable */
  #define LPTIM_CR_SNGSTRT      0x00000002	/* Timer start in single mode */
  #define LPTIM_CR_CNTSTRT      0x00000004	/* Timer start in continuous mode */
  #define LPTIM_CR_COUNTRST     0x00000008	/* Timer Counter reset in synchronous mode*/
  #define LPTIM_CR_RSTARE       0x00000010	/* Timer Counter reset after read enable (asynchronously)*/
#define TOFF_LPTIM_CMP      0x0014		/* (RW) LPTIM Compare register */
  #define LPTIM_CMP_CMP         0x0000FFFF	/* Compare register */
#define TOFF_LPTIM_ARR      0x0018		/* (RW) LPTIM Autoreload register */
  #define LPTIM_ARR_ARR         0x0000FFFF	/* Auto reload register */
#define TOFF_LPTIM_CNT      0x001C		/* (RW) LPTIM Counter register */
  #define LPTIM_CNT_CNT         0x0000FFFF	/* Counter register */
#define TOFF_LPTIM_CFGR2    0x0024		/* (RW) LPTIM Option register */
  #define LPTIM_CFGR2_IN1SEL    0x0000000F	/* CFGR2[3:0] bits (INPUT1 selection) */
  #define LPTIM_CFGR2_IN1SEL_0  0x00000001	/* Bit 0 */
  #define LPTIM_CFGR2_IN1SEL_1  0x00000002	/* Bit 1 */
  #define LPTIM_CFGR2_IN1SEL_2  0x00000004	/* Bit 2 */
  #define LPTIM_CFGR2_IN1SEL_3  0x00000008	/* Bit 3 */
  #define LPTIM_CFGR2_IN2SEL    0x000000F0	/* CFGR2[7:4] bits (INPUT2 selection) */
  #define LPTIM_CFGR2_IN2SEL_0  0x00000010	/* Bit 4 */
  #define LPTIM_CFGR2_IN2SEL_1  0x00000020	/* Bit 5 */
  #define LPTIM_CFGR2_IN2SEL_2  0x00000040	/* Bit 6 */
  #define LPTIM_CFGR2_IN2SEL_3  0x00000080	/* Bit 7 */
#define TOFF_LPTIM_HWCFGR   0x03F0		/* (R)  LPTIM HW configuration register */
  #define LPTIM_HWCFGR_CFG1     0x000000FF	/* HW CFG1 */
  #define LPTIM_HWCFGR_CFG2     0x0000FF00	/* HW CFG2 */
  #define LPTIM_HWCFGR_CFG3     0x000F0000	/* HW CFG3 */
  #define LPTIM_HWCFGR_CFG4     0xFF000000	/* HW CFG4 */
#define TOFF_LPTIM_VERR     0x03F4		/* (R)  LPTIM version register */
  #define LPTIM_VERR_CFG1       0x000000FF	/* HW CFG1 */
  #define LPTIM_VERR_CFG2       0x0000FF00	/* HW CFG2 */
  #define LPTIM_VERR_CFG3       0x000F0000	/* HW CFG3 */
  #define LPTIM_VERR_CFG4       0xFF000000	/* HW CFG4 */
#define TOFF_LPTIM_PIDR     0x03F8		/* (R)  LPTIM Identification register */
#define TOFF_LPTIM_SIDR     0x03FC		/* (R)  LPTIM Size Identification register */

/*
 *  WINDOW WATCHDOG
 */
#define TADR_WWDG1_BASE     (MCU_APB1_PERIPH_BASE + 0xA000)
#define TOFF_WWDG_CR        0x0000		/* (RW) WWDG Control register */
  #define WWDG_CR_T             0x0000007F	/* T[6:0] bits (7-Bit counter (MSB to LSB)) */
  #define WWDG_CR_T_0           0x00000001
  #define WWDG_CR_T_1           0x00000002
  #define WWDG_CR_T_2           0x00000004
  #define WWDG_CR_T_3           0x00000008
  #define WWDG_CR_T_4           0x00000010
  #define WWDG_CR_T_5           0x00000020
  #define WWDG_CR_T_6           0x00000040
  #define WWDG_CR_WDGA          0x00000080	/* Activation bit */
#define TOFF_WWDG_CFR       0x0004		/* (RW) WWDG Configuration register */
  #define WWDG_CFR_W            0x0000007F	/* W[6:0] bits (7-bit window value) */
  #define WWDG_CFR_W_0          0x00000001
  #define WWDG_CFR_W_1          0x00000002
  #define WWDG_CFR_W_2          0x00000004
  #define WWDG_CFR_W_3          0x00000008
  #define WWDG_CFR_W_4          0x00000010
  #define WWDG_CFR_W_5          0x00000020
  #define WWDG_CFR_W_6          0x00000040
  #define WWDG_CFR_WDGTB        0x00003800	/* WDGTB[2:0] bits (Timer Base) */
  #define WWDG_CFR_WDGTB_0      0x00000800
  #define WWDG_CFR_WDGTB_1      0x00001000
  #define WWDG_CFR_WDGTB_2      0x00002000
  #define WWDG_CFR_EWI          0x00000200	/* Early Wakeup Interrupt */
#define TOFF_WWDG_SR        0x0008		/* (R)  WWDG Status register */
  #define WWDG_SR_EWIF          0x00000001	/* Early Wakeup Interrupt Flag */
#define TOFF_WWDG_HWCFGR    0x03F0		/* (R)  WWDG HW Config register */
  #define WWDG_HWCFGR_PREDIV    0x0000FFFF	/* Watchdog clock prescaler */
#define TOFF_WWDG_VERR      0x03F4		/* (R)  WWDG Version register */
  #define WWDG_VERR_MINREV      0x0000000F	/* Minor Revision number */
  #define WWDG_VERR_MAJREV      0x000000F0	/* Major Revision number */
#define TOFF_WWDG_IPIDR     0x03F8		/* (R)  WWDG Identification register */
#define TOFF_WWDG_SIDR      0x03FC		/* (R)  WWDG Size ID register */


/*
 *  SERIAL PERIPHERAL INTERFACE
 */
#define TADR_SPI2_BASE      (MCU_APB1_PERIPH_BASE + 0xB000)
#define TADR_SPI3_BASE      (MCU_APB1_PERIPH_BASE + 0xC000)
#define TADR_SPI1_BASE      (MCU_APB2_PERIPH_BASE + 0x4000)
#define TADR_SPI4_BASE      (MCU_APB2_PERIPH_BASE + 0x5000)
#define TADR_SPI5_BASE      (MCU_APB2_PERIPH_BASE + 0x9000)
#define TADR_SPI6_BASE      (MPU_APB5_PERIPH_BASE + 0x1000)
#define TOFF_SPI_CR1        0x0000		/* (RW) SPI control register 1 */
  #define SPI_CR1_SPE           0x00000001	/* Serial Peripheral Enable */
  #define SPI_CR1_MASRX         0x00000100	/* Master automatic SUSP in Receive mode */
  #define SPI_CR1_CSTART        0x00000200	/* Master transfer start */
  #define SPI_CR1_CSUSP         0x00000400	/* Master SUSPend request */
  #define SPI_CR1_HDDIR         0x00000800	/* Rx/Tx direction at Half-duplex mode */
  #define SPI_CR1_SSI           0x00001000	/* Internal SS signal input level */
  #define SPI_CR1_CRC33_17      0x00002000	/* 32-bit CRC polynomial configuration */
  #define SPI_CR1_RCRCINI       0x00004000	/* CRC calculation initialization pattern control for receiver */
  #define SPI_CR1_TCRCINI       0x00008000	/* CRC calculation initialization pattern control for transmitter */
  #define SPI_CR1_IOLOCK        0x00010000	/* Locking the AF configuration of associated IOs */
#define TOFF_SPI_CR2        0x0004		/* (RW) SPI control register 2 */
  #define SPI_CR2_TSIZE         0x0000FFFF	/* Number of data at current transfer */
  #define SPI_CR2_TSER          0xFFFF0000	/* Number of data transfer extension */
#define TOFF_SPI_CFG1       0x0008		/* (RW) SPI config1 register */
  #define SPI_CFG1_DSIZE        0x0000001F	/* DSIZE [4:0]: Number of bits in at single SPI data frame */
  #define SPI_CFG1_DSIZE_0      0x00000001
  #define SPI_CFG1_DSIZE_1      0x00000002
  #define SPI_CFG1_DSIZE_2      0x00000004
  #define SPI_CFG1_DSIZE_3      0x00000008
  #define SPI_CFG1_DSIZE_4      0x00000010
  #define SPI_CFG1_FTHLV        0x000001E0	/* <FTHVL [3:0]: FIFO threshold level*/
  #define SPI_CFG1_FTHLV_0      0x00000020
  #define SPI_CFG1_FTHLV_1      0x00000040
  #define SPI_CFG1_FTHLV_2      0x00000080
  #define SPI_CFG1_FTHLV_3      0x00000100
  #define SPI_CFG1_UDRCFG       0x00000600	/* UDRCFG [1:0]: Behavior of slave transmitter at underrun condition*/
  #define SPI_CFG1_UDRCFG_0     0x00000200
  #define SPI_CFG1_UDRCFG_1     0x00000400
  #define SPI_CFG1_UDRDET       0x00001800	/* UDRDET [1:0]: Detection of underrun condition at slave transmitter*/
  #define SPI_CFG1_UDRDET_0     0x00000800
  #define SPI_CFG1_UDRDET_1     0x00001000
  #define SPI_CFG1_RXDMAEN      0x00004000	/* Rx DMA stream enable */
  #define SPI_CFG1_TXDMAEN      0x00008000	/* Tx DMA stream enable */
  #define SPI_CFG1_CRCSIZE      0x001F0000	/* CRCSIZE [4:0]: Length of CRC frame*/
  #define SPI_CFG1_CRCSIZE_0    0x00010000
  #define SPI_CFG1_CRCSIZE_1    0x00020000
  #define SPI_CFG1_CRCSIZE_2    0x00040000
  #define SPI_CFG1_CRCSIZE_3    0x00080000
  #define SPI_CFG1_CRCSIZE_4    0x00100000
  #define SPI_CFG1_CRCEN        0x00400000	/* Hardware CRC computation enable */
  #define SPI_CFG1_MBR          0x70000000	/* Master baud rate */
  #define SPI_CFG1_MBR_0        0x10000000
  #define SPI_CFG1_MBR_1        0x20000000
  #define SPI_CFG1_MBR_2        0x40000000
#define TOFF_SPI_CFG2       0x000C		/* (RW) SPI config2 register */
  #define SPI_CFG2_MSSI         0x0000000F	/* Master SS Idleness */
  #define SPI_CFG2_MSSI_0       0x00000001
  #define SPI_CFG2_MSSI_1       0x00000002
  #define SPI_CFG2_MSSI_2       0x00000004
  #define SPI_CFG2_MSSI_3       0x00000008
  #define SPI_CFG2_MIDI         0x000000F0	/* Master Inter-Data Idleness */
  #define SPI_CFG2_MIDI_0       0x00000010
  #define SPI_CFG2_MIDI_1       0x00000020
  #define SPI_CFG2_MIDI_2       0x00000040
  #define SPI_CFG2_MIDI_3       0x00000080
  #define SPI_CFG2_IOSWP        0x00008000	/* Swap functionality of MISO and MOSI pins */
  #define SPI_CFG2_COMM         0x00060000	/* COMM [1:0]: SPI Communication Mode */
  #define SPI_CFG2_COMM_0       0x00020000
  #define SPI_CFG2_COMM_1       0x00040000
  #define SPI_CFG2_SP           0x00380000	/* SP[2:0]: Serial Protocol */
  #define SPI_CFG2_SP_0         0x00080000
  #define SPI_CFG2_SP_1         0x00100000
  #define SPI_CFG2_SP_2         0x00200000
  #define SPI_CFG2_MASTER       0x00400000	/* SPI Master */
  #define SPI_CFG2_LSBFRST      0x00800000	/* Data frame format */
  #define SPI_CFG2_CPHA         0x01000000	/* Clock Phase */
  #define SPI_CFG2_CPOL         0x02000000	/* Clock Polarity   */
  #define SPI_CFG2_SSM          0x04000000	/* Software slave management */
  #define SPI_CFG2_SSIOP        0x10000000	/* SS input/output polarity */
  #define SPI_CFG2_SSOE         0x20000000	/* SS output enable */
  #define SPI_CFG2_SSOM         0x40000000	/* SS output management in master mode */
  #define SPI_CFG2_AFCNTR       0x80000000	/* Alternate function GPIOs control */
#define TOFF_SPI_IER        0x0010		/* (RW) SPI interrupt enable register */
  #define SPI_IER_RXPIE         0x00000001	/* RXP Interrupt Enable */
  #define SPI_IER_TXPIE         0x00000002	/* TXP interrupt enable */
  #define SPI_IER_DXPIE         0x00000004	/* DXP interrupt enable */
  #define SPI_IER_EOTIE         0x00000008	/* EOT/SUSP/TXC interrupt enable */
  #define SPI_IER_TXTFIE        0x00000010	/* TXTF interrupt enable */
  #define SPI_IER_UDRIE         0x00000020	/* UDR interrupt enable */
  #define SPI_IER_OVRIE         0x00000040	/* OVR interrupt enable */
  #define SPI_IER_CRCEIE        0x00000080	/* CRC interrupt enable */
  #define SPI_IER_TIFREIE       0x00000100	/* TI Frame Error interrupt enable */
  #define SPI_IER_MODFIE        0x00000200	/* MODF interrupt enable */
  #define SPI_IER_TSERFIE       0x00000400	/* TSERF interrupt enable */
#define TOFF_SPI_SR         0x0014		/* (RW) SPI Status register */
  #define SPI_SR_RXP            0x00000001	/* Rx-Packet available */
  #define SPI_SR_TXP            0x00000002	/* Tx-Packet space available */
  #define SPI_SR_DXP            0x00000004	/* Duplex Packet available */
  #define SPI_SR_EOT            0x00000008	/* Duplex Packet available */
  #define SPI_SR_TXTF           0x00000010	/* Transmission Transfer Filled */
  #define SPI_SR_UDR            0x00000020	/* UDR at Slave transmission */
  #define SPI_SR_OVR            0x00000040	/* Rx-Packet available */
  #define SPI_SR_CRCE           0x00000080	/* CRC Error Detected */
  #define SPI_SR_TIFRE          0x00000100	/* TI frame format error Detected */
  #define SPI_SR_MODF           0x00000200	/* Mode Fault Detected */
  #define SPI_SR_TSERF          0x00000400	/* Additional number of SPI data to be transacted was reload */
  #define SPI_SR_SUSP           0x00000800	/* SUSP is set by hardware  */
  #define SPI_SR_TXC            0x00001000	/* TxFIFO transmission complete */
  #define SPI_SR_RXPLVL         0x00006000	/* RxFIFO Packing Level */
  #define SPI_SR_RXPLVL_0       0x00002000
  #define SPI_SR_RXPLVL_1       0x00004000
  #define SPI_SR_RXWNE          0x00008000	/* Rx FIFO Word Not Empty */
  #define SPI_SR_CTSIZE         0xFFFF0000	/* Number of data frames remaining in TSIZE */
#define TOFF_SPI_IFCR       0x0018		/* (RW) SPI data register */
  #define SPI_IFCR_EOTC         0x00000008	/* End Of Transfer flag clear */
  #define SPI_IFCR_TXTFC        0x00000010	/* Transmission Transfer Filled flag clear */
  #define SPI_IFCR_UDRC         0x00000020	/* Underrun flag clear */
  #define SPI_IFCR_OVRC         0x00000040	/* Overrun flag clear */
  #define SPI_IFCR_CRCEC        0x00000080	/* CRC Error flag clear */
  #define SPI_IFCR_TIFREC       0x00000100	/* TI frame format error flag clear */
  #define SPI_IFCR_MODFC        0x00000200	/* Mode Fault flag clear */
  #define SPI_IFCR_TSERFC       0x00000400	/* TSERFC flag clear */
  #define SPI_IFCR_SUSPC        0x00000800	/* SUSPend flag clear */
#define TOFF_SPI_TXDR       0x0020		/* (RW) SPI data register */
#define TOFF_SPI_RXDR       0x0030		/* (RW) SPI data register */
#define TOFF_SPI_CRCPOLY    0x0040		/* (RW) CRC polynomial register */
#define TOFF_SPI_TXCRC      0x0044		/* (RW) SPI TX CRC register */
#define TOFF_SPI_RXCRC      0x0048		/* (RW) SPI RX CRC register */
#define TOFF_SPI_UDRDR      0x004C		/* (RW) SPI data register */
#define TOFF_SPI_I2SCFGR    0x0050		/* (RW) SPI data register */
  #define SPI_I2SCFGR_I2SMOD    0x00000001	/* I2S mode selection */
  #define SPI_I2SCFGR_I2SCFG    0x0000000E	/* I2SCFGR[1:0] bits (I2S configuration mode) */
  #define SPI_I2SCFGR_I2SCFG_0  0x00000002
  #define SPI_I2SCFGR_I2SCFG_1  0x00000004
  #define SPI_I2SCFGR_I2SCFG_2  0x00000008
  #define SPI_I2SCFGR_I2SSTD    0x00000030	/* I2SSTD[1:0] I2S standard selection */
  #define SPI_I2SCFGR_I2SSTD_0  0x00000010
  #define SPI_I2SCFGR_I2SSTD_1  0x00000020
  #define SPI_I2SCFGR_PCMSYNC   0x00000080	/* PCM frame synchronization */
  #define SPI_I2SCFGR_DATLEN    0x00000300	/* DATLEN[1:0] Data length to be transferred */
  #define SPI_I2SCFGR_DATLEN_0  0x00000100
  #define SPI_I2SCFGR_DATLEN_1  0x00000200
  #define SPI_I2SCFGR_CHLEN     0x00000400	/* Channel length (number of bits per audio channel) */
  #define SPI_I2SCFGR_CKPOL     0x00000800	/* Steady state clock polarity */
  #define SPI_I2SCFGR_FIXCH     0x00001000	/* Fixed channel length in SLAVE */
  #define SPI_I2SCFGR_WSINV     0x00002000	/* Word select inversion */
  #define SPI_I2SCFGR_DATFMT    0x00003000	/* Data format */
  #define SPI_I2SCFGR_I2SDIV    0x00FF0000	/* I2S Linear prescaler */
  #define SPI_I2SCFGR_ODD       0x01000000	/* Odd factor for the prescaler */
  #define SPI_I2SCFGR_MCKOE     0x02000000	/* Master Clock Output Enable */
#define TOFF_SPI_HWCFGR     0x03F0		/* (R)  SPI HW Configuration register */
  #define SPI_HWCFGR_TXFCFG     0x0000000F	/* TxFIFO size */
  #define SPI_HWCFGR_RXFCFG     0x000000F0	/* RxFIFO size */
  #define SPI_HWCFGR_CRCCFG     0x00000F00	/* CRC configuration for SPI */
  #define SPI_HWCFGR_I2SCFG     0x0000F000	/* I2S configuration */
  #define SPI_HWCFGR_DSCFG      0x000F0000	/* SPI data size configuration */
#define TOFF_SPI_VERR       0x03F4		/* (R)  SPI Version register */
  #define SPI_VERR_MINREV       0x0000000F	/* Minor Revision number */
  #define SPI_VERR_MAJREV       0x000000F0	/* Major Revision number */
#define TOFF_SPI_IPIDR      0x03F8		/* (R)  SPI identification register */
#define TOFF_SPI_SIDR       0x03FC		/* (R)  SPI Size Identification register */


/*
 *  SPDIF-RX INTERFACE
 */
#define TADR_SPDIFRX_BASE   (MCU_APB1_PERIPH_BASE + 0xD000)
#define TOFF_SPDIF_CR       0x0000	/* (RW) Control register */
  #define SPDIFRX_CR_SPDIFEN    0x00000003	/* Peripheral Block Enable */
  #define SPDIFRX_CR_RXDMAEN    0x00000004	/* Receiver DMA Enable for data flow */
  #define SPDIFRX_CR_RXSTEO     0x00000008	/* Stereo Mode */
  #define SPDIFRX_CR_DRFMT      0x00000030	/* RX Data format */
  #define SPDIFRX_CR_PMSK       0x00000040	/* Mask Parity error bit */
  #define SPDIFRX_CR_VMSK       0x00000080	/* Mask of Validity bit */
  #define SPDIFRX_CR_CUMSK      0x00000100	/* Mask of channel status and user bits */
  #define SPDIFRX_CR_PTMSK      0x00000200	/* Mask of Preamble Type bits */
  #define SPDIFRX_CR_CBDMAEN    0x00000400	/* Control Buffer DMA ENable for control flow */
  #define SPDIFRX_CR_CHSEL      0x00000800	/* Channel Selection */
  #define SPDIFRX_CR_NBTR       0x00003000	/* Maximum allowed re-tries during synchronization phase */
  #define SPDIFRX_CR_WFA        0x00004000	/* Wait For Activity */
  #define SPDIFRX_CR_INSEL      0x00070000	/* SPDIF input selection */
#define TOFF_SPDIF_IMR      0x0004	/* (RW) Interrupt mask register */
  #define SPDIFRX_IMR_RXNEIE    0x00000001	/* RXNE interrupt enable */
  #define SPDIFRX_IMR_CSRNEIE   0x00000002	/* Control Buffer Ready Interrupt Enable */
  #define SPDIFRX_IMR_PERRIE    0x00000004	/* Parity error interrupt enable */
  #define SPDIFRX_IMR_OVRIE     0x00000008	/* Overrun error Interrupt Enable */
  #define SPDIFRX_IMR_SBLKIE    0x00000010	/* Synchronization Block Detected Interrupt Enable */
  #define SPDIFRX_IMR_SYNCDIE   0x00000020	/* Synchronization Done */
  #define SPDIFRX_IMR_IFEIE     0x00000040	/* Serial Interface Error Interrupt Enable */
#define TOFF_SPDIF_SR       0x0008	/* (RW) Status register */
  #define SPDIFRX_SR_RXNE       0x00000001	/* Read data register not empty */
  #define SPDIFRX_SR_CSRNE      0x00000002	/* The Control Buffer register is not empty */
  #define SPDIFRX_SR_PERR       0x00000004	/* Parity error */
  #define SPDIFRX_SR_OVR        0x00000008	/* Overrun error */
  #define SPDIFRX_SR_SBD        0x00000010	/* Synchronization Block Detected */
  #define SPDIFRX_SR_SYNCD      0x00000020	/* Synchronization Done */
  #define SPDIFRX_SR_FERR       0x00000040	/* Framing error */
  #define SPDIFRX_SR_SERR       0x00000080	/* Synchronization error */
  #define SPDIFRX_SR_TERR       0x00000100	/* Time-out error */
  #define SPDIFRX_SR_WIDTH5     0x7FFF0000	/* Duration of 5 symbols counted with spdif_clk */
#define TOFF_SPDIF_IFCR     0x000C	/* (RW) Interrupt Flag Clear register */
  #define SPDIFRX_IFCR_PERRCF   0x00000004	/* Clears the Parity error flag */
  #define SPDIFRX_IFCR_OVRCF    0x00000008	/* Clears the Overrun error flag */
  #define SPDIFRX_IFCR_SBDCF    0x00000010	/* Clears the Synchronization Block Detected flag */
  #define SPDIFRX_IFCR_SYNCDCF  0x00000020	/* Clears the Synchronization Done flag */
#define TOFF_SPDIF_DR       0x0010	/* (RW) Data input register */
  /* (DRFMT = 0b00 case) */
  #define SPDIFRX_DR0_DR        0x00FFFFFF	/* Data value */
  #define SPDIFRX_DR0_PE        0x01000000	/* Parity Error bit */
  #define SPDIFRX_DR0_V         0x02000000	/* Validity bit */
  #define SPDIFRX_DR0_U         0x04000000	/* User bit */
  #define SPDIFRX_DR0_C         0x08000000	/* Channel Status bit */
  #define SPDIFRX_DR0_PT        0x30000000	/* Preamble Type */
  /* (DRFMT = 0b01 case) */
  #define SPDIFRX_DR1_PE        0x00000001	/* Parity Error bit */
  #define SPDIFRX_DR1_V         0x00000002	/* Validity bit */
  #define SPDIFRX_DR1_U         0x00000004	/* User bit */
  #define SPDIFRX_DR1_C         0x00000008	/* Channel Status bit */
  #define SPDIFRX_DR1_PT        0x00000030	/* Preamble Type */
  #define SPDIFRX_DR1_DR        0xFFFFFF00	/* Data value */
  /* (DRFMT = 0b10 case) */
  #define SPDIFRX_DR1_DRNL2     0x0000FFFF	/* Data value Channel A */
  #define SPDIFRX_DR1_DRNL1     0xFFFF0000	/* Data value Channel B */
#define TOFF_SPDIF_CSR      0x0014	/* (RW) Channel Status register */
  #define SPDIFRX_CSR_USR       0x0000FFFF	/* User data information */
  #define SPDIFRX_CSR_CS        0x00FF0000	/* Channel A status information */
  #define SPDIFRX_CSR_SOB       0x01000000	/* Start Of Block */
#define TOFF_SPDIF_DIR      0x0018	/* (RW) Debug Information register */
  #define SPDIFRX_DIR_THI       0x00001FFF	/* Threshold LOW */
  #define SPDIFRX_DIR_TLO       0x1FFF0000	/* Threshold HIGH */
#define TOFF_SPDIF_VERR     0x03F4	/* (R)  SPDIFRX version register */
  #define SPDIFRX_VERR_MINREV   0x0000000F	/* Minor Revision number */
  #define SPDIFRX_VERR_MAJREV   0x000000F0	/* Major Revision number */
#define TOFF_SPDIF_IPIDR    0x03F8	/* (R)  SPDIFRX Identificationn register */
#define TOFF_SPDIF_SIDR     0x03FC	/* (R)  SPDIFRX Size Identification register */


/*
 *  UNIVERSAL SYNCHRONOUS ASYNCHORONOUS RECEIVER TRANSMITTER
 */
#define TADR_USART2_BASE    (MCU_APB1_PERIPH_BASE + 0xE000)
#define TADR_USART3_BASE    (MCU_APB1_PERIPH_BASE + 0xF000)
#define TADR_UART4_BASE     (MCU_APB1_PERIPH_BASE + 0x10000)
#define TADR_UART5_BASE     (MCU_APB1_PERIPH_BASE + 0x11000)
#define TADR_UART7_BASE     (MCU_APB1_PERIPH_BASE + 0x18000)
#define TADR_UART8_BASE     (MCU_APB1_PERIPH_BASE + 0x19000)
#define TADR_USART6_BASE    (MCU_APB2_PERIPH_BASE + 0x3000)
#define TADR_USART1_BASE    (MPU_APB5_PERIPH_BASE + 0x0000)

#define TOFF_USART_CR1      0x0000		/* (RW) USART Control register 1 */
  #define USART_CR1_UE          0x00000001	/* USART Enable */
  #define USART_CR1_UESM        0x00000002	/* USART Enable in STOP Mode */
  #define USART_CR1_RE          0x00000004	/* Receiver Enable */
  #define USART_CR1_TE          0x00000008	/* Transmitter Enable */
  #define USART_CR1_IDLEIE      0x00000010	/* IDLE Interrupt Enable */
  #define USART_CR1_RXNEIE      0x00000020	/* RXNE Interrupt Enable */
  #define USART_CR1_RXNEIE_RXFNEIE  USART_CR1_RXNEIE	/* RXNE and RX FIFO Not Empty Interrupt Enable */
  #define USART_CR1_TCIE        0x00000040	/* Transmission Complete Interrupt Enable */
  #define USART_CR1_TXEIE       0x00000080	/* TXE Interrupt Enable */
  #define USART_CR1_TXEIE_TXFNFIE   USART_CR1_TXEIE		/* TXE and TX FIFO Not Full Interrupt Enable */
  #define USART_CR1_PEIE        0x00000100	/* PE Interrupt Enable */
  #define USART_CR1_PS          0x00000200	/* Parity Selection */
  #define USART_CR1_PCE         0x00000400	/* Parity Control Enable */
  #define USART_CR1_WAKE        0x00000800	/* Receiver Wakeup method */
  #define USART_CR1_M           0x10001000	/* Word length */
  #define USART_CR1_M0          0x00001000	/* Word length - Bit 0 */
  #define USART_CR1_MME         0x00002000	/* Mute Mode Enable */
  #define USART_CR1_CMIE        0x00004000	/* Character match interrupt enable */
  #define USART_CR1_OVER8       0x00008000	/* Oversampling by 8-bit or 16-bit mode */
  #define USART_CR1_DEDT        0x001F0000	/* DEDT[4:0] bits (Driver Enable Deassertion Time) */
  #define USART_CR1_DEDT_0      0x00010000
  #define USART_CR1_DEDT_1      0x00020000
  #define USART_CR1_DEDT_2      0x00040000
  #define USART_CR1_DEDT_3      0x00080000
  #define USART_CR1_DEDT_4      0x00100000
  #define USART_CR1_DEAT        0x03E00000	/* DEAT[4:0] bits (Driver Enable Assertion Time) */
  #define USART_CR1_DEAT_0      0x00200000
  #define USART_CR1_DEAT_1      0x00400000
  #define USART_CR1_DEAT_2      0x00800000
  #define USART_CR1_DEAT_3      0x01000000
  #define USART_CR1_DEAT_4      0x02000000
  #define USART_CR1_RTOIE       0x04000000	/* Receive Time Out interrupt enable */
  #define USART_CR1_EOBIE       0x08000000	/* End of Block interrupt enable */
  #define USART_CR1_M1          0x10000000	/* Word length - Bit 1 */
  #define USART_CR1_FIFOEN      0x20000000	/* FIFO mode enable */
  #define USART_CR1_TXFEIE      0x40000000	/* TXFIFO empty interrupt enable */
  #define USART_CR1_RXFFIE      0x80000000	/* RXFIFO Full interrupt enable */
#define TOFF_USART_CR2      0x0004		/* (RW) USART Control register 2 */
  #define USART_CR2_SLVEN       0x00000001	/* Synchronous Slave mode enable */
  #define USART_CR2_DIS_NSS     0x00000008	/* Slave Select (NSS) pin management */
  #define USART_CR2_ADDM7       0x00000010	/* 7-bit or 4-bit Address Detection */
  #define USART_CR2_LBDL        0x00000020	/* LIN Break Detection Length */
  #define USART_CR2_LBDIE       0x00000040	/* LIN Break Detection Interrupt Enable */
  #define USART_CR2_LBCL        0x00000100	/* Last Bit Clock pulse */
  #define USART_CR2_CPHA        0x00000200	/* Clock Phase */
  #define USART_CR2_CPOL        0x00000400	/* Clock Polarity */
  #define USART_CR2_CLKEN       0x00000800	/* Clock Enable */
  #define USART_CR2_STOP        0x00003000	/* STOP[1:0] bits (STOP bits) */
  #define USART_CR2_STOP_0      0x00001000
  #define USART_CR2_STOP_1      0x00002000
  #define USART_CR2_LINEN       0x00004000	/* LIN mode enable */
  #define USART_CR2_SWAP        0x00008000	/* SWAP TX/RX pins */
  #define USART_CR2_RXINV       0x00010000	/* RX pin active level inversion */
  #define USART_CR2_TXINV       0x00020000	/* TX pin active level inversion */
  #define USART_CR2_DATAINV     0x00040000	/* Binary data inversion */
  #define USART_CR2_MSBFIRST    0x00080000	/* Most Significant Bit First */
  #define USART_CR2_ABREN       0x00100000	/* Auto Baud-Rate Enable*/
  #define USART_CR2_ABRMODE     0x00600000	/* ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
  #define USART_CR2_ABRMODE_0   0x00200000
  #define USART_CR2_ABRMODE_1   0x00400000
  #define USART_CR2_RTOEN       0x00800000	/* Receiver Time-Out enable */
  #define USART_CR2_ADD         0xFF000000	/* Address of the USART node */
#define TOFF_USART_CR3      0x0008		/* (RW) USART Control register 3 */
  #define USART_CR3_EIE         0x00000001	/* Error Interrupt Enable */
  #define USART_CR3_IREN        0x00000002	/* IrDA mode Enable */
  #define USART_CR3_IRLP        0x00000004	/* IrDA Low-Power */
  #define USART_CR3_HDSEL       0x00000008	/* Half-Duplex Selection */
  #define USART_CR3_NACK        0x00000010	/* SmartCard NACK enable */
  #define USART_CR3_SCEN        0x00000020	/* SmartCard mode enable */
  #define USART_CR3_DMAR        0x00000040	/* DMA Enable Receiver */
  #define USART_CR3_DMAT        0x00000080	/* DMA Enable Transmitter */
  #define USART_CR3_RTSE        0x00000100	/* RTS Enable */
  #define USART_CR3_CTSE        0x00000200	/* CTS Enable */
  #define USART_CR3_CTSIE       0x00000400	/* CTS Interrupt Enable */
  #define USART_CR3_ONEBIT      0x00000800	/* One sample bit method enable */
  #define USART_CR3_OVRDIS      0x00001000	/* Overrun Disable */
  #define USART_CR3_DDRE        0x00002000	/* DMA Disable on Reception Error */
  #define USART_CR3_DEM         0x00004000	/* Driver Enable Mode */
  #define USART_CR3_DEP         0x00008000	/* Driver Enable Polarity Selection */
  #define USART_CR3_SCARCNT     0x000E0000	/* SCARCNT[2:0] bits (SmartCard Auto-Retry Count) */
  #define USART_CR3_SCARCNT_0   0x00020000
  #define USART_CR3_SCARCNT_1   0x00040000
  #define USART_CR3_SCARCNT_2   0x00080000
  #define USART_CR3_WUS         0x00300000	/* WUS[1:0] bits (Wake UP Interrupt Flag Selection) */
  #define USART_CR3_WUS_0       0x00100000
  #define USART_CR3_WUS_1       0x00200000
  #define USART_CR3_WUFIE       0x00400000	/* Wake Up Interrupt Enable */
  #define USART_CR3_TXFTIE      0x00800000	/* TXFIFO threshold interrupt enable */
  #define USART_CR3_TCBGTIE     0x01000000	/* Transmission Complete Before Guard Time Interrupt Enable */
  #define USART_CR3_RXFTCFG     0x0E000000	/* RXFIFO FIFO threshold configuration */
  #define USART_CR3_RXFTCFG_0   0x02000000
  #define USART_CR3_RXFTCFG_1   0x04000000
  #define USART_CR3_RXFTCFG_2   0x08000000
  #define USART_CR3_RXFTIE      0x10000000	/* RXFIFO threshold interrupt enable */
  #define USART_CR3_TXFTCFG     0xE0000000	/* TXFIFO threshold configuration */
  #define USART_CR3_TXFTCFG_0   0x20000000
  #define USART_CR3_TXFTCFG_1   0x40000000
  #define USART_CR3_TXFTCFG_2   0x80000000
#define TOFF_USART_BRR      0x000C		/* (RW) USART Baud rate register */
  #define USART_BRR_LPUART      0x000FFFFF	/* LPUART Baud rate register [19:0] */
  #define USART_BRR_BRR         0x0000FFFF	/* USART Baud rate register [15:0] */
#define TOFF_USART_GTPR     0x0010		/* (RW-16) USART Guard time and prescaler register */
  #define USART_GTPR_PSC        0x000000FF	/* PSC[7:0] bits (Prescaler value) */
  #define USART_GTPR_GT         0x0000FF00	/* GT[7:0] bits (Guard time value) */
#define TOFF_USART_RTOR     0x0014		/* (RW) USART Receiver Time Out register */
  #define USART_RTOR_RTO        0x00FFFFFF	/* Receiver Time Out Value */
  #define USART_RTOR_BLEN       0xFF000000	/* Block Length */
#define TOFF_USART_RQR      0x0018		/* (RW-16) USART Request register */
  #define USART_RQR_ABRRQ       0x00000001	/* Auto-Baud Rate Request */
  #define USART_RQR_SBKRQ       0x00000002	/* Send Break Request */
  #define USART_RQR_MMRQ        0x00000004	/* Mute Mode Request */
  #define USART_RQR_RXFRQ       0x00000008	/* Receive Data flush Request */
  #define USART_RQR_TXFRQ       0x00000010	/* Transmit data flush Request */
#define TOFF_USART_ISR      0x001C		/* (RW) USART Interrupt and status register */
  #define USART_ISR_PE          0x00000001	/* Parity Error */
  #define USART_ISR_FE          0x00000002	/* Framing Error */
  #define USART_ISR_NE          0x00000004	/* Noise detected Flag */
  #define USART_ISR_ORE         0x00000008	/* OverRun Error */
  #define USART_ISR_IDLE        0x00000010	/* IDLE line detected */
  #define USART_ISR_RXNE        0x00000020	/* Read Data Register Not Empty */
  #define USART_ISR_RXNE_RXFNE  USART_ISR_RXNE	/* Read Data Register or RX FIFO Not Empty */
  #define USART_ISR_TC          0x00000040	/* Transmission Complete */
  #define USART_ISR_TXE         0x00000080	/* Transmit Data Register Empty */
  #define USART_ISR_TXE_TXFNF   USART_ISR_TXE	/* Transmit Data Register Empty or TX FIFO Not Full Flag */
  #define USART_ISR_LBDF        0x00000100	/* LIN Break Detection Flag */
  #define USART_ISR_CTSIF       0x00000200	/* CTS interrupt flag */
  #define USART_ISR_CTS         0x00000400	/* CTS flag */
  #define USART_ISR_RTOF        0x00000800	/* Receiver Time Out */
  #define USART_ISR_EOBF        0x00001000	/* End Of Block Flag */
  #define USART_ISR_UDR         0x00002000	/* SPI slave underrun error flag */
  #define USART_ISR_ABRE        0x00004000	/* Auto-Baud Rate Error */
  #define USART_ISR_ABRF        0x00008000	/* Auto-Baud Rate Flag */
  #define USART_ISR_BUSY        0x00010000	/* Busy Flag */
  #define USART_ISR_CMF         0x00020000	/* Character Match Flag */
  #define USART_ISR_SBKF        0x00040000	/* Send Break Flag */
  #define USART_ISR_RWU         0x00080000	/* Receive Wake Up from mute mode Flag */
  #define USART_ISR_WUF         0x00100000	/* Wake Up from stop mode Flag */
  #define USART_ISR_TEACK       0x00200000	/* Transmit Enable Acknowledge Flag */
  #define USART_ISR_REACK       0x00400000	/* Receive Enable Acknowledge Flag */
  #define USART_ISR_TXFE        0x00800000	/* TXFIFO Empty */
  #define USART_ISR_RXFF        0x01000000	/* RXFIFO Full */
  #define USART_ISR_TCBGT       0x02000000	/* Transmission Complete Before Guard Time completion */
  #define USART_ISR_RXFT        0x04000000	/* RXFIFO threshold flag */
  #define USART_ISR_TXFT        0x08000000	/* TXFIFO threshold flag */
#define TOFF_USART_ICR      0x0020		/* (RW) USART Interrupt flag Clear register */
  #define USART_ICR_PECF        0x00000001	/* Parity Error Clear Flag */
  #define USART_ICR_FECF        0x00000002	/* Framing Error Clear Flag */
  #define USART_ICR_NECF        0x00000004	/* Noise detected Clear Flag */
  #define USART_ICR_ORECF       0x00000008	/* OverRun Error Clear Flag */
  #define USART_ICR_IDLECF      0x00000010	/* IDLE line detected Clear Flag */
  #define USART_ICR_TXFECF      0x00000020	/* TXFIFO empty Clear flag */
  #define USART_ICR_TCCF        0x00000040	/* Transmission Complete Clear Flag */
  #define USART_ICR_TCBGTCF     0x00000080	/* Transmission Complete Before Guard Time Clear Flag */
  #define USART_ICR_LBDCF       0x00000100	/* LIN Break Detection Clear Flag */
  #define USART_ICR_CTSCF       0x00000200	/* CTS Interrupt Clear Flag */
  #define USART_ICR_RTOCF       0x00000800	/* Receiver Time Out Clear Flag */
  #define USART_ICR_EOBCF       0x00001000	/* End Of Block Clear Flag */
  #define USART_ICR_UDRCF       0x00002000	/* SPI Slave Underrun Clear Flag */
  #define USART_ICR_CMCF        0x00020000	/* Character Match Clear Flag */
  #define USART_ICR_WUCF        0x00100000	/* Wake Up from stop mode Clear Flag */
#define TOFF_USART_RDR      0x0024		/* (RW-16) USART Receive Data register */
  #define USART_RDR_RDR         0x000001FF	/* RDR[8:0] bits (Receive Data value) */
#define TOFF_USART_TDR      0x0028		/* (RW-16) USART Transmit Data register */
  #define USART_TDR_TDR         0x000001FF	/* TDR[8:0] bits (Transmit Data value) */
#define TOFF_USART_PRESC    0x002C		/* (RW) USART clock Prescaler register */
  #define USART_PRESC_PRESCALER 0x0000000F	/* PRESCALER[3:0] bits (Clock prescaler) */
  #define USART_PRESC_PRESCALER_0 0x00000001
  #define USART_PRESC_PRESCALER_1 0x00000002
  #define USART_PRESC_PRESCALER_2 0x00000004
  #define USART_PRESC_PRESCALER_3 0x00000008
#define TOFF_USART_HWCFGR2  0x03EC		/* (R)  USART Configuration2 register */
  #define USART_HWCFGR2_CFG1    0x0000000F	/* HW CFG1 */
  #define USART_HWCFGR2_CFG2    0x000000F0	/* HW CFG2 */
#define TOFF_USART_HWCFGR1  0x03F0		/* (R)  USART Configuration1 register */
  #define USART_HWCFGR1_CFG1    0x0000000F	/* HW CFG1 */
  #define USART_HWCFGR1_CFG2    0x000000F0	/* HW CFG2 */
  #define USART_HWCFGR1_CFG3    0x00000F00	/* HW CFG3 */
  #define USART_HWCFGR1_CFG4    0x0000F000	/* HW CFG4 */
  #define USART_HWCFGR1_CFG5    0x000F0000	/* HW CFG5 */
  #define USART_HWCFGR1_CFG6    0x00F00000	/* HW CFG6 */
  #define USART_HWCFGR1_CFG7    0x0F000000	/* HW CFG7 */
  #define USART_HWCFGR1_CFG8    0xF0000000	/* HW CFG8 */
#define TOFF_USART_VERR     0x03F4		/* (R)  USART Version register */
  #define USART_VERR_MINREV     0x0000000F	/* Minor Revision number */
  #define USART_VERR_MAJREV     0x000000F0	/* Major Revision number */
#define TOFF_USART_IPIDR    0x03F8		/* (R)  USART Identification register */
#define TOFF_USART_SIDR     0x03FC		/* (R)  USART clock Size Identification register */


/*
 *  INTER-INTERATED CIRCUIT IINTERFACE
 */
#define TADR_I2C1_BASE      (MCU_APB1_PERIPH_BASE + 0x12000)
#define TADR_I2C2_BASE      (MCU_APB1_PERIPH_BASE + 0x13000)
#define TADR_I2C3_BASE      (MCU_APB1_PERIPH_BASE + 0x14000)
#define TADR_I2C5_BASE      (MCU_APB1_PERIPH_BASE + 0x15000)
#define TADR_I2C4_BASE      (MPU_APB5_PERIPH_BASE + 0x2000)
#define TADR_I2C6_BASE      (MPU_APB5_PERIPH_BASE + 0x9000)
#define TOFF_I2C_CR1        0x0000		/* (RW) I2C Control register 1 */
  #define I2C_CR1_PE            0x00000001	/* Peripheral enable */
  #define I2C_CR1_TXIE          0x00000002	/* TX interrupt enable */
  #define I2C_CR1_RXIE          0x00000004	/* RX interrupt enable */
  #define I2C_CR1_ADDRIE        0x00000008	/* Address match interrupt enable */
  #define I2C_CR1_NACKIE        0x00000010	/* NACK received interrupt enable */
  #define I2C_CR1_STOPIE        0x00000020	/* STOP detection interrupt enable */
  #define I2C_CR1_TCIE          0x00000040	/* Transfer complete interrupt enable */
  #define I2C_CR1_ERRIE         0x00000080	/* Errors interrupt enable */
  #define I2C_CR1_DNF           0x00000F00	/* Digital noise filter */
  #define I2C_CR1_ANFOFF        0x00001000	/* Analog noise filter OFF */
  #define I2C_CR1_SWRST         0x00002000	/* Software reset */
  #define I2C_CR1_TXDMAEN       0x00004000	/* DMA transmission requests enable */
  #define I2C_CR1_RXDMAEN       0x00008000	/* DMA reception requests enable */
  #define I2C_CR1_SBC           0x00010000	/* Slave byte control */
  #define I2C_CR1_NOSTRETCH     0x00020000	/* Clock stretching disable */
  #define I2C_CR1_WUPEN         0x00040000	/* Wakeup from STOP enable */
  #define I2C_CR1_GCEN          0x00080000	/* General call enable */
  #define I2C_CR1_SMBHEN        0x00100000	/* SMBus host address enable */
  #define I2C_CR1_SMBDEN        0x00200000	/* SMBus device default address enable */
  #define I2C_CR1_ALERTEN       0x00400000	/* SMBus alert enable */
  #define I2C_CR1_PECEN         0x00800000	/* PEC enable */
#define TOFF_I2C_CR2        0x0004		/* (RW) I2C Control register 2 */
  #define I2C_CR2_SADD          0x000003FF	/* Slave address (master mode) */
  #define I2C_CR2_RD_WRN        0x00000400	/* Transfer direction (master mode) */
  #define I2C_CR2_ADD10         0x00000800	/* 10-bit addressing mode (master mode) */
  #define I2C_CR2_HEAD10R       0x00001000	/* 10-bit address header only read direction (master mode) */
  #define I2C_CR2_START         0x00002000	/* START generation */
  #define I2C_CR2_STOP          0x00004000	/* STOP generation (master mode) */
  #define I2C_CR2_NACK          0x00008000	/* NACK generation (slave mode) */
  #define I2C_CR2_NBYTES        0x00FF0000	/* Number of bytes */
  #define I2C_CR2_RELOAD        0x01000000	/* NBYTES reload mode */
  #define I2C_CR2_AUTOEND       0x02000000	/* Automatic end mode (master mode) */
  #define I2C_CR2_PECBYTE       0x04000000	/* Packet error checking byte */
#define TOFF_I2C_OAR1       0x0008		/* (RW) I2C Own address register 1 */
  #define I2C_OAR1_OA1          0x000003FF	/* Interface own address 1 */
  #define I2C_OAR1_OA1MODE      0x00000400	/* Own address 1 10-bit mode */
  #define I2C_OAR1_OA1EN        0x00008000	/* Own address 1 enable */
#define TOFF_I2C_OAR2       0x000C		/* (RW) I2C Own address register 2 */
  #define I2C_OAR2_OA2          0x000000FE	/* Interface own address 2 */
  #define I2C_OAR2_OA2MSK       0x00000700	/* Own address 2 masks */
  #define I2C_OAR2_OA2NOMASK    0x00000000	/* No mask */
  #define I2C_OAR2_OA2MASK01    0x00000100	/* OA2[1] is masked, Only OA2[7:2] are compared */
  #define I2C_OAR2_OA2MASK02    0x00000200	/* OA2[2:1] is masked, Only OA2[7:3] are compared */
  #define I2C_OAR2_OA2MASK03    0x00000300	/* OA2[3:1] is masked, Only OA2[7:4] are compared */
  #define I2C_OAR2_OA2MASK04    0x00000400	/* OA2[4:1] is masked, Only OA2[7:5] are compared */
  #define I2C_OAR2_OA2MASK05    0x00000500	/* OA2[5:1] is masked, Only OA2[7:6] are compared */
  #define I2C_OAR2_OA2MASK06    0x00000600	/* OA2[6:1] is masked, Only OA2[7] are compared */
  #define I2C_OAR2_OA2MASK07    0x00000700	/* OA2[7:1] is masked, No comparison is done */
  #define I2C_OAR2_OA2EN        0x00008000	/* Own address 2 enable */
#define TOFF_I2C_TIMINGR    0x0010		/* (RW) I2C Timing register */
  #define I2C_TIMINGR_SCLL      0x000000FF	/* SCL low period (master mode) */
  #define I2C_TIMINGR_SCLH      0x0000FF00	/* SCL high period (master mode) */
  #define I2C_TIMINGR_SDADEL    0x000F0000	/* Data hold time */
  #define I2C_TIMINGR_SCLDEL    0x00F00000	/* Data setup time */
  #define I2C_TIMINGR_PRESC     0xF0000000	/* Timings prescaler */
#define TOFF_I2C_TIMEOUTR   0x0014		/* (RW) I2C Timeout register */
  #define I2C_TIMEOUTR_TIMEOUTA 0x00000FFF	/* Bus timeout A */
  #define I2C_TIMEOUTR_TIDLE    0x00001000	/* Idle clock timeout detection */
  #define I2C_TIMEOUTR_TIMOUTEN 0x00008000	/* Clock timeout enable */
  #define I2C_TIMEOUTR_TIMEOUTB 0x0FFF0000	/* Bus timeout B*/
  #define I2C_TIMEOUTR_TEXTEN   0x80000000	/* Extended clock timeout enable */
#define TOFF_I2C_ISR        0x0018		/* (RW) I2C Interrupt and status register */
  #define I2C_ISR_TXE           0x00000001	/* Transmit data register empty */
  #define I2C_ISR_TXIS          0x00000002	/* Transmit interrupt status */
  #define I2C_ISR_RXNE          0x00000004	/* Receive data register not empty */
  #define I2C_ISR_ADDR          0x00000008	/* Address matched (slave mode)*/
  #define I2C_ISR_NACKF         0x00000010	/* NACK received flag */
  #define I2C_ISR_STOPF         0x00000020	/* STOP detection flag */
  #define I2C_ISR_TC            0x00000040	/* Transfer complete (master mode) */
  #define I2C_ISR_TCR           0x00000080	/* Transfer complete reload */
  #define I2C_ISR_BERR          0x00000100	/* Bus error */
  #define I2C_ISR_ARLO          0x00000200	/* Arbitration lost */
  #define I2C_ISR_OVR           0x00000400	/* Overrun/Underrun */
  #define I2C_ISR_PECERR        0x00000800	/* PEC error in reception */
  #define I2C_ISR_TIMEOUT       0x00001000	/* Timeout or Tlow detection flag */
  #define I2C_ISR_ALERT         0x00002000	/* SMBus alert */
  #define I2C_ISR_BUSY          0x00008000	/* Bus busy */
  #define I2C_ISR_DIR           0x00010000	/* Transfer direction (slave mode) */
  #define I2C_ISR_ADDCODE       0x00FE0000	/* Address match code (slave mode) */
#define TOFF_I2C_ICR        0x001C		/* (RW) I2C Interrupt clear register */
  #define I2C_ICR_ADDRCF        0x00000008	/* Address matched clear flag */
  #define I2C_ICR_NACKCF        0x00000010	/* NACK clear flag */
  #define I2C_ICR_STOPCF        0x00000020	/* STOP detection clear flag */
  #define I2C_ICR_BERRCF        0x00000100	/* Bus error clear flag */
  #define I2C_ICR_ARLOCF        0x00000200	/* Arbitration lost clear flag */
  #define I2C_ICR_OVRCF         0x00000400	/* Overrun/Underrun clear flag */
  #define I2C_ICR_PECCF         0x00000800	/* PAC error clear flag */
  #define I2C_ICR_TIMOUTCF      0x00001000	/* Timeout clear flag */
  #define I2C_ICR_ALERTCF       0x00002000	/* Alert clear flag */
#define TOFF_I2C_PECR       0x0020		/* (RW) I2C PEC register */
  #define I2C_PECR_PEC          0x000000FF	/* PEC register */
#define TOFF_I2C_RXDR       0x0024		/* (RW) I2C Receive data register */
  #define I2C_RXDR_RXDATA       0x000000FF	/* 8-bit receive data */
#define TOFF_I2C_TXDR       0x0028		/* (RW) I2C Transmit data register */
  #define I2C_TXDR_TXDATA       0x000000FF	/* 8-bit transmit data */
#define TOFF_I2C_HWCFGR     0x03F0		/* (R)  I2C hardware configuration register */
  #define I2C_HWCFGR_SMBUS      0x0000000F	/* SMBus mode */
  #define I2C_HWCFGR_ASYN       0x000000F0	/* Independent kernel clock */
  #define I2C_HWCFGR_WKP        0x00000F00	/* Wakeup from Stop mode */
#define TOFF_I2C_VERR       0x03F4		/* (R)  I2C version register */
  #define I2C_VERR_MINREV       0x0000000F	/* Minor Revision of the IP*/
  #define I2C_VERR_MAJREV       0x000000F0	/* Major Revision of the IP*/
#define TOFF_I2C_IPIDR      0x03F8		/* (R)  I2C identification register */
#define TOFF_I2C_SIDR       0x03FC		/* (R)  I2C size identification register,     Address offset: 0x3FC */


/*
 *  HDMI-CEC
 */
#define TADR_CEC_BASE       (MCU_APB1_PERIPH_BASE + 0x16000)
#define TOFF_CEC_CR         0x0000		/* (RW) CEC control register */
#define TOFF_CEC_CFGR       0x0004		/* (RW) CEC configuration register */
#define TOFF_CEC_TXDR       0x0008		/* (RW) CEC Tx data register */
#define TOFF_CEC_RXDR       0x000C		/* (RW) CEC Rx Data Register */
#define TOFF_CEC_ISR        0x0010		/* (RW) CEC Interrupt and Status Register */
#define TOFF_CEC_IER        0x0014		/* (RW) CEC interrupt enable register */
#define TOFF_CEC_VERR       0x03F4		/* (R)  CEC version register */
#define TOFF_CEC_IPIDR      0x03F8		/* (R)  CEC ID register */
#define TOFF_CEC_SIDR       0x03FC		/* (R)  CEC Size ID register */


/*
 *  DIGITAL TO ANALOG CONVTER
 */
#define TADR_DAC1_BASE      (MCU_APB1_PERIPH_BASE + 0x17000)
#define TOFF_DAC_CR         0x0000		/* (RW) DAC control register */
  #define DAC_CR_EN1            0x00000001	/* DAC channel1 enable */
  #define DAC_CR_TEN1           0x00000002	/* DAC channel1 Trigger enable */
  #define DAC_CR_TSEL1          0x0000003C	/* TSEL1[2:0] (DAC channel1 Trigger selection) */
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
  #define DAC_CR_HFSEL          0x00008000	/* High frequency interface mode enable >*/
  #define DAC_CR_EN2            0x00010000	/* DAC channel2 enable */
  #define DAC_CR_TEN2           0x00020000	/* DAC channel2 Trigger enable */
  #define DAC_CR_TSEL2          0x003C0000	/* TSEL2[2:0] (DAC channel2 Trigger selection) */
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
  #define DAC_SWTRIGR_SWTRIG1   0x01		/* DAC channel1 software trigger */
  #define DAC_SWTRIGR_SWTRIG2   0x02		/* DAC channel2 software trigger */
#define TOFF_DAC_DHR12R1    0x0008		/* (RW) DAC channel1 12-bit right-aligned data holding register */
  #define DAC_DHR12R1_DACC1DHR  0x0FFF		/* DAC channel1 12-bit Right aligned data */
#define TOFF_DAC_DHR12L1    0x000C		/* (RW) DAC channel1 12-bit left aligned data holding register */
  #define DAC_DHR12L1_DACC1DHR  0xFFF0		/* DAC channel1 12-bit Left aligned data */
#define TOFF_DAC_DHR8R1     0x0010		/* (RW) DAC channel1 8-bit right aligned data holding register */
  #define DAC_DHR8R1_DACC1DHR   0xFF		/* DAC channel1 8-bit Right aligned data */
#define TOFF_DAC_DHR12R2    0x0014		/* (RW) DAC channel2 12-bit right aligned data holding register */
  #define DAC_DHR12R2_DACC2DHR  0x0FFF		/* DAC channel2 12-bit Right aligned data */
#define TOFF_DAC_DHR12L2    0x0018		/* (RW) DAC channel2 12-bit left aligned data holding register */
  #define DAC_DHR12L2_DACC2DHR  0xFFF0		/* DAC channel2 12-bit Left aligned data */
#define TOFF_DAC_DHR8R2     0x001C		/* (RW) DAC channel2 8-bit right-aligned data holding register */
  #define DAC_DHR8R2_DACC2DHR   0xFF		/* DAC channel2 8-bit Right aligned data */
#define TOFF_DAC_DHR12RD    0x0020		/* (RW) Dual DAC 12-bit right-aligned data holding register */
  #define DAC_DHR12RD_DACC1DHR  0x00000FFF	/* DAC channel1 12-bit Right aligned data */
  #define DAC_DHR12RD_DACC2DHR  0x0FFF0000	/* DAC channel2 12-bit Right aligned data */
#define TOFF_DAC_DHR12LD    0x0024		/* (RW) DUAL DAC 12-bit left aligned data holding register */
  #define DAC_DHR12LD_DACC1DHR  0x0000FFF0	/* DAC channel1 12-bit Left aligned data */
  #define DAC_DHR12LD_DACC2DHR  0xFFF00000	/* DAC channel2 12-bit Left aligned data */
#define TOFF_DAC_DHR8RD     0x0028		/* (RW) DUAL DAC 8-bit right aligned data holding register */
  #define DAC_DHR8RD_DACC1DHR   0x000000FF	/* DAC channel1 8-bit Right aligned data */
  #define DAC_DHR8RD_DACC2DHR   0x000000FF	/* DAC channel2 8-bit Right aligned data */
#define TOFF_DAC_DOR1       0x002C		/* (RW) DAC channel1 data output register */
  #define DAC_DOR1_DACC1DOR     0x0FFF		/* DAC channel1 data output */
#define TOFF_DAC_DOR2       0x0030		/* (RW) DAC channel2 data output register */
  #define DAC_DOR2_DACC2DOR     0x0FFF		/* DAC channel2 data output */
#define TOFF_DAC_SR         0x0034		/* (RW) DAC status register */
  #define DAC_SR_DMAUDR1        0x00002000	/* DAC channel1 DMA underrun flag */
  #define DAC_SR_CAL_FLAG1      0x00004000	/* DAC channel1 calibration offset status */
  #define DAC_SR_BWST1          0x20008000	/* DAC channel1 busy writing sample time flag */
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
  #define DAC_MCR_MODE2         0x00070000	/* MODE2[2:0] (DAC channel2 mode) */
  #define DAC_MCR_MODE2_0       0x00010000
  #define DAC_MCR_MODE2_1       0x00020000
  #define DAC_MCR_MODE2_2       0x00040000
#define TOFF_DAC_SHSR1      0x0040		/* (RW) DAC Sample and Hold sample time register 1 */
  #define DAC_SHSR1_TSAMPLE1    0x000003FF	/* DAC channel1 sample time */
#define TOFF_DAC_SHSR2      0x0044		/* (RW) DAC Sample and Hold sample time register 2 */
  #define DAC_SHSR1_TSAMPLE2    0x000003FF	/* DAC channel2 sample time */
#define TOFF_DAC_SHHR       0x0048		/* (RW) DAC Sample and Hold hold time register */
  #define DAC_SHHR_THOLD1       0x000003FF	/* DAC channel1 hold time */
  #define DAC_SHHR_THOLD2       0x03FF0000	/* DAC channel2 hold time */
#define TOFF_DAC_SHRR       0x004C		/* (RW) DAC Sample and Hold refresh time register */
  #define DAC_SHRR_TREFRESH1    0x000000FF	/* DAC channel1 refresh time */
  #define DAC_SHRR_TREFRESH2    0x00FF0000	/* DAC channel2 refresh time */
#define TOFF_DAC_HWCFGR0    0x03F0		/* (R)  DAC x IP hardware configuration register */
  #define DAC_HWCFGR0_DUAL      0x0000000F	/* Dual DAC capability */
  #define DAC_HWCFGR0_LFSR      0x000000F0	/* Pseudonoise wave generation capability */
  #define DAC_HWCFGR0_TRIANGLE  0x00000F00	/* Triangle wave generation capability */
  #define DAC_HWCFGR0_SAMPLE    0x0000F000	/* Sample and Hold mode capability */
  #define DAC_HWCFGR0_OR_CFG    0x00FF0000	/* option register bit width */
#define TOFF_DAC_VERR       0x03F4		/* (R)  DAC version register */
  #define DAC_VERR_MINREV       0x0000000F	/* MAJREV[3:0] bits (Minor revision) */
  #define DAC_VERR_MAJREV       0x000000F0	/* MINREV[3:0] bits (Major revision) */
#define TOFF_DAC_IPIDR      0x03F8		/* (R)  DAC ID register */
#define TOFF_DAC_SIDR       0x03FC		/* (R)  DAC magic ID register */


/*
 *  MDIOS
 */
#define TADR_MDIOS_BASE     (MCU_APB1_PERIPH_BASE + 0x1C000)
#define TOFF_MDIOS_CR       0x0000		/* (RW) Control register */
  #define MDIOS_CR_EN           0x00000001	/* MDIOS slave peripheral enable */
  #define MDIOS_CR_WRIE         0x00000002	/* MDIOS slave register write interrupt enable. */
  #define MDIOS_CR_RDIE         0x00000004	/* MDIOS slave register read interrupt enable. */
  #define MDIOS_CR_EIE          0x00000008	/* MDIOS slave register error interrupt enable. */
  #define MDIOS_CR_DPC          0x00000080	/* MDIOS slave disable preamble check. */
  #define MDIOS_CR_PORT_ADDRESS 0x00001F00	/* MDIOS slave port address mask. */
  #define MDIOS_CR_PORT_ADDRESS_0   0x00000100
  #define MDIOS_CR_PORT_ADDRESS_1   0x00000200
  #define MDIOS_CR_PORT_ADDRESS_2   0x00000400
  #define MDIOS_CR_PORT_ADDRESS_3   0x00000800
  #define MDIOS_CR_PORT_ADDRESS_4   0x00001000
#define TOFF_MDIOS_WRFR     0x0004		/* (RW) Write Flag register */
#define TOFF_MDIOS_CWRFR    0x0008		/* (RW) Clear Write Flag register */
#define TOFF_MDIOS_RDFR     0x000C		/* (RW) Read Flag register */
#define TOFF_MDIOS_CRDFR    0x0010		/* (RW) Clear Read Flag register */
#define TOFF_MDIOS_SR       0x0014		/* (RW) Status register */
  #define MDIOS_SR_PERF         0x00000001	/* MDIOS slave turnaround error flag*/
  #define MDIOS_SR_SERF         0x00000002	/* MDIOS slave start error flag */
  #define MDIOS_SR_TERF         0x00000004	/* MDIOS slave preamble error flag */
#define TOFF_MDIOS_CLRFR    0x0018		/* (RW) Clear Flag register */
  #define MDIOS_SR_CPERF        0x00000001	/* MDIOS slave Clear the turnaround error flag */
  #define MDIOS_SR_CSERF        0x00000002	/* MDIOS slave Clear the start error flag */
  #define MDIOS_SR_CTERF        0x00000004	/* MDIOS slave Clear the preamble error flag */
#define TOFF_MDIOS_DINR0    0x0100		/* (RW) Input Data register 0  */
#define TOFF_MDIOS_DINR1    0x0104		/* (RW) Input Data register 1 */
#define TOFF_MDIOS_DINR2    0x0108		/* (RW) Input Data register 2 */
#define TOFF_MDIOS_DINR3    0x010C		/* (RW) Input Data register 3 */
#define TOFF_MDIOS_DINR4    0x0110		/* (RW) Input Data register 4 */
#define TOFF_MDIOS_DINR5    0x0114		/* (RW) Input Data register 5 */
#define TOFF_MDIOS_DINR6    0x0118		/* (RW) Input Data register 6 */
#define TOFF_MDIOS_DINR7    0x011C		/* (RW) Input Data register 7 */
#define TOFF_MDIOS_DINR8    0x0120		/* (RW) Input Data register 8 */
#define TOFF_MDIOS_DINR9    0x0124		/* (RW) Input Data register 9 */
#define TOFF_MDIOS_DINR10   0x0128		/* (RW) Input Data register 10 */
#define TOFF_MDIOS_DINR11   0x012C		/* (RW) Input Data register 11 */
#define TOFF_MDIOS_DINR12   0x0130		/* (RW) Input Data register 12 */
#define TOFF_MDIOS_DINR13   0x0134		/* (RW) Input Data register 13 */
#define TOFF_MDIOS_DINR14   0x0138		/* (RW) Input Data register 14 */
#define TOFF_MDIOS_DINR15   0x013C		/* (RW) Input Data register 15 */
#define TOFF_MDIOS_DINR16   0x0140		/* (RW) Input Data register 16 */
#define TOFF_MDIOS_DINR17   0x0144		/* (RW) Input Data register 17 */
#define TOFF_MDIOS_DINR18   0x0148		/* (RW) Input Data register 18 */
#define TOFF_MDIOS_DINR19   0x014C		/* (RW) Input Data register 19 */
#define TOFF_MDIOS_DINR20   0x0150		/* (RW) Input Data register 20 */
#define TOFF_MDIOS_DINR21   0x0154		/* (RW) Input Data register 21 */
#define TOFF_MDIOS_DINR22   0x0158		/* (RW) Input Data register 22 */
#define TOFF_MDIOS_DINR23   0x015C		/* (RW) Input Data register 23 */
#define TOFF_MDIOS_DINR24   0x0160		/* (RW) Input Data register 24 */
#define TOFF_MDIOS_DINR25   0x0164		/* (RW) Input Data register 25 */
#define TOFF_MDIOS_DINR26   0x0168		/* (RW) Input Data register 26 */
#define TOFF_MDIOS_DINR27   0x016C		/* (RW) Input Data register 27 */
#define TOFF_MDIOS_DINR28   0x0170		/* (RW) Input Data register 28 */
#define TOFF_MDIOS_DINR29   0x0174		/* (RW) Input Data register 29 */
#define TOFF_MDIOS_DINR30   0x0178		/* (RW) Input Data register 30 */
#define TOFF_MDIOS_DINR31   0x017C		/* (RW) Input Data register 31 */
#define TOFF_MDIOS_DOUTR0   0x0180		/* (RW) Output Data register 0 */
#define TOFF_MDIOS_DOUTR1   0x0184		/* (RW) Output Data register 1 */
#define TOFF_MDIOS_DOUTR2   0x0188		/* (RW) Output Data register 2 */
#define TOFF_MDIOS_DOUTR3   0x018C		/* (RW) Output Data register 3 */
#define TOFF_MDIOS_DOUTR4   0x0190		/* (RW) Output Data register 4 */
#define TOFF_MDIOS_DOUTR5   0x0194		/* (RW) Output Data register 5 */
#define TOFF_MDIOS_DOUTR6   0x0198		/* (RW) Output Data register 6 */
#define TOFF_MDIOS_DOUTR7   0x019C		/* (RW) Output Data register 7 */
#define TOFF_MDIOS_DOUTR8   0x01A0		/* (RW) Output Data register 8 */
#define TOFF_MDIOS_DOUTR9   0x01A4		/* (RW) Output Data register 9 */
#define TOFF_MDIOS_DOUTR10  0x01A8		/* (RW) Output Data register 10 */
#define TOFF_MDIOS_DOUTR11  0x01AC		/* (RW) Output Data register 11 */
#define TOFF_MDIOS_DOUTR12  0x01B0		/* (RW) Output Data register 12 */
#define TOFF_MDIOS_DOUTR13  0x01B4		/* (RW) Output Data register 13 */
#define TOFF_MDIOS_DOUTR14  0x01B8		/* (RW) Output Data register 14 */
#define TOFF_MDIOS_DOUTR15  0x01BC		/* (RW) Output Data register 15 */
#define TOFF_MDIOS_DOUTR16  0x01C0		/* (RW) Output Data register 16 */
#define TOFF_MDIOS_DOUTR17  0x01C4		/* (RW) Output Data register 17 */
#define TOFF_MDIOS_DOUTR18  0x01C8		/* (RW) Output Data register 18 */
#define TOFF_MDIOS_DOUTR19  0x01CC		/* (RW) Output Data register 19 */
#define TOFF_MDIOS_DOUTR20  0x01D0		/* (RW) Output Data register 20 */
#define TOFF_MDIOS_DOUTR21  0x01D4		/* (RW) Output Data register 21 */
#define TOFF_MDIOS_DOUTR22  0x01D8		/* (RW) Output Data register 22 */
#define TOFF_MDIOS_DOUTR23  0x01DC		/* (RW) Output Data register 23 */
#define TOFF_MDIOS_DOUTR24  0x01E0		/* (RW) Output Data register 24 */
#define TOFF_MDIOS_DOUTR25  0x01E4		/* (RW) Output Data register 25 */
#define TOFF_MDIOS_DOUTR26  0x01E8		/* (RW) Output Data register 26 */
#define TOFF_MDIOS_DOUTR27  0x01EC		/* (RW) Output Data register 27 */
#define TOFF_MDIOS_DOUTR28  0x01F0		/* (RW) Output Data register 28 */
#define TOFF_MDIOS_DOUTR29  0x01F4		/* (RW) Output Data register 29 */
#define TOFF_MDIOS_DOUTR30  0x01F8		/* (RW) Output Data register 30 */
#define TOFF_MDIOS_DOUTR31  0x01FC		/* (RW) Output Data register 31 */
#define TOFF_MDIOS_HWCFGR   0x03F0		/* (R)  MDIOS HW Configuration register */
  #define MDIOS_HWCFGR_NBREG    0x000000FF	/* IP configuration number of registers */
#define TOFF_MDIOS_VERR     0x03F4		/* (R)  MDIOS Version register */
  #define MDIOS_VERR_MINREV     0x0000000F	/* Minor Revision number */
  #define MDIOS_VERR_MAJREV     0x000000F0	/* Major Revision number */
#define TOFF_MDIOS_IPIDR    0x03F8		/* (R)  MDIOS identification register */
#define TOFF_MDIOS_SIDR     0x03FC		/* (R)  MDIOS Size ID register */


/*
 *  SERIAL AUDIO INTERFACE
 */
#define TADR_SAI1_BASE      (MCU_APB2_PERIPH_BASE + 0xA000)
#define TADR_SAI2_BASE      (MCU_APB2_PERIPH_BASE + 0xB000)
#define TADR_SAI3_BASE      (MCU_APB2_PERIPH_BASE + 0xC000)
#define TADR_SAI4_BASE      (MCU_APB3_PERIPH_BASE + 0x7000)
#define TOFF_SAI_GCR        0x0000		/* (RW) SAI global configuration register */
  #define SAI_GCR_SYNCIN        0x00000003	/* SYNCIN[1:0] bits (Synchronization Inputs)   */
  #define SAI_GCR_SYNCIN_0      0x00000001	/* Bit 0 */
  #define SAI_GCR_SYNCIN_1      0x00000002	/* Bit 1 */
  #define SAI_GCR_SYNCOUT       0x00000030	/* SYNCOUT[1:0] bits (Synchronization Outputs) */
  #define SAI_GCR_SYNCOUT_0     0x00000010	/* Bit 0 */
  #define SAI_GCR_SYNCOUT_1     0x00000020	/* Bit 1 */
#define TOFF_SAI_PDMCR      0x0044		/* (RW) SAI PDM control register */
  #define SAI_PDMCR_PDMEN       0x00000001	/* PDM Enable */
  #define SAI_PDMCR_MICNBR      0x00000030	/* Number of microphones  */
  #define SAI_PDMCR_MICNBR_0    0x00000010
  #define SAI_PDMCR_MICNBR_1    0x00000020
  #define SAI_PDMCR_CKEN1       0x00000100	/* Clock enable of bitstream clock number 1 */
  #define SAI_PDMCR_CKEN2       0x00000200	/* Clock enable of bitstream clock number 2 */
  #define SAI_PDMCR_CKEN3       0x00000400	/* Clock enable of bitstream clock number 3 */
  #define SAI_PDMCR_CKEN4       0x00000800	/* Clock enable of bitstream clock number 4 */
#define TOFF_SAI_PDMDLY     0x0048		/* (RW) SAI PDM delay register */
  #define SAI_PDMDLY_DLYM1L     0x00000007	/* DLYM1L[2:0] (Delay line adjust for left microphone of pair 1) */
  #define SAI_PDMDLY_DLYM1L_0   0x00000001
  #define SAI_PDMDLY_DLYM1L_1   0x00000002
  #define SAI_PDMDLY_DLYM1L_2   0x00000004
  #define SAI_PDMDLY_DLYM1R     0x00000070	/* DLYM1R[2:0] (Delay line adjust for right microphone of pair 1) */
  #define SAI_PDMDLY_DLYM1R_0   0x00000010
  #define SAI_PDMDLY_DLYM1R_1   0x00000020
  #define SAI_PDMDLY_DLYM1R_2   0x00000040
  #define SAI_PDMDLY_DLYM2L     0x00000700	/* DLYM2L[2:0] (Delay line adjust for left microphone of pair 2) */
  #define SAI_PDMDLY_DLYM2L_0   0x00000100
  #define SAI_PDMDLY_DLYM2L_1   0x00000200
  #define SAI_PDMDLY_DLYM2L_2   0x00000400
  #define SAI_PDMDLY_DLYM2R     0x00007000	/* DLYM2R[2:0] (Delay line adjust for right microphone of pair 2)*/
  #define SAI_PDMDLY_DLYM2R_0   0x00001000
  #define SAI_PDMDLY_DLYM2R_1   0x00002000
  #define SAI_PDMDLY_DLYM2R_2   0x00004000
  #define SAI_PDMDLY_DLYM3L     0x00070000	/* DLYM3L[2:0] (Delay line adjust for left microphone of pair 3)*/
  #define SAI_PDMDLY_DLYM3L_0   0x00010000
  #define SAI_PDMDLY_DLYM3L_1   0x00020000
  #define SAI_PDMDLY_DLYM3L_2   0x00040000
  #define SAI_PDMDLY_DLYM3R     0x00700000	/* DLYM3R[2:0] (Delay line adjust for right microphone of pair 3)*/
  #define SAI_PDMDLY_DLYM3R_0   0x00100000
  #define SAI_PDMDLY_DLYM3R_1   0x00200000
  #define SAI_PDMDLY_DLYM3R_2   0x00400000
  #define SAI_PDMDLY_DLYM4L     0x07000000	/* DLYM4L[2:0] (Delay line adjust for left microphone of pair 4)*/
  #define SAI_PDMDLY_DLYM4L_0   0x01000000
  #define SAI_PDMDLY_DLYM4L_1   0x02000000
  #define SAI_PDMDLY_DLYM4L_2   0x04000000
  #define SAI_PDMDLY_DLYM4R     0x70000000	/* DLYM4R[2:0] (Delay line adjust for right microphone of pair 4)*/
  #define SAI_PDMDLY_DLYM4R_0   0x10000000
  #define SAI_PDMDLY_DLYM4R_1   0x20000000
  #define SAI_PDMDLY_DLYM4R_2   0x40000000
#define TOFF_SAI_HWCFGR     0x03F0		/* (R)  SAI HW Configuration register */
  #define SAI_HWCFGR_FIFO_SIZE  0x000000FF	/* FIFO size for SAIA and SAIB */
  #define SAI_HWCFGR_SPDIF_PDM  0x00000F00	/* Support of SPDIF-OUT and PDM interfaces */
  #define SAI_HWCFGR_OPTION_REGOUT  0x000FF000	/* Support of SAI_IOR register */
#define TOFF_SAI_VERR       0x03F4		/* (R)  SAI PVersion register */
  #define SAI_VERR_MINREV       0x0000000F	/* Minor Revision number */
  #define SAI_VERR_MAJREV       0x000000F0	/* Major Revision number */
#define TOFF_SAI_IPIDR      0x03F8		/* (R)  SAI Identification register */
#define TOFF_SAI_SIDR       0x03FC		/* (R)  SAI Size Identification register,  Address offset: 0x3FC */

#define SAI_WINDOW_SIZE     0x0020
#define TOFF_SAI_CR1        0x0000		/* (RW) SAI block x configuration register 1 */
  #define SAI_xCR1_MODE         0x00000003	/* MODE[1:0] bits (Audio Block Mode) */
  #define SAI_xCR1_MODE_0       0x00000001	/* Bit 0 */
  #define SAI_xCR1_MODE_1       0x00000002	/* Bit 1 */
  #define SAI_xCR1_PRTCFG       0x0000000C	/* PRTCFG[1:0] bits (Protocol Configuration)   */
  #define SAI_xCR1_PRTCFG_0     0x00000004	/* Bit 0 */
  #define SAI_xCR1_PRTCFG_1     0x00000008	/* Bit 1 */
  #define SAI_xCR1_DS           0x000000E0	/* DS[1:0] bits (Data Size) */
  #define SAI_xCR1_DS_0         0x00000020	/* Bit 0 */
  #define SAI_xCR1_DS_1         0x00000040	/* Bit 1 */
  #define SAI_xCR1_DS_2         0x00000080	/* Bit 2 */
  #define SAI_xCR1_LSBFIRST     0x00000100	/* LSB First Configuration  */
  #define SAI_xCR1_CKSTR        0x00000200	/* ClocK STRobing edge      */
  #define SAI_xCR1_SYNCEN       0x00000C00	/* SYNCEN[1:0](SYNChronization ENable) */
  #define SAI_xCR1_SYNCEN_0     0x00000400	/* Bit 0 */
  #define SAI_xCR1_SYNCEN_1     0x00000800	/* Bit 1 */
  #define SAI_xCR1_MONO         0x00001000	/* Mono mode */
  #define SAI_xCR1_OUTDRIV      0x00002000	/* Output Drive */
  #define SAI_xCR1_SAIEN        0x00010000	/* Audio Block enable */
  #define SAI_xCR1_DMAEN        0x00020000	/* DMA enable */
  #define SAI_xCR1_NODIV        0x00080000	/* No Divider Configuration */
  #define SAI_xCR1_MCKDIV       0x00F00000	/* MCKDIV[3:0] (Master ClocK Divider)  */
  #define SAI_xCR1_MCKDIV_0     0x00100000	/* Bit 0  */
  #define SAI_xCR1_MCKDIV_1     0x00200000	/* Bit 1  */
  #define SAI_xCR1_MCKDIV_2     0x00400000	/* Bit 2  */
  #define SAI_xCR1_MCKDIV_3     0x00800000	/* Bit 3  */
  #define SAI_xCR1_OSR          0x04000000	/* OverSampling Ratio for master clock  */
  #define SAI_xCR1_MCKEN        0x08000000	/* Master ClocK enable */
  #define SAI_xCR1_NOMCK      SAI_xCR1_NODIV
#define TOFF_SAI_CR2        0x0004		/* (RW) SAI block x configuration register 2 */
  #define SAI_xCR2_FTH          0x00000007	/* FTH[2:0](Fifo THreshold)  */
  #define SAI_xCR2_FTH_0        0x00000001	/* Bit 0 */
  #define SAI_xCR2_FTH_1        0x00000002	/* Bit 1 */
  #define SAI_xCR2_FTH_2        0x00000004	/* Bit 2 */
  #define SAI_xCR2_FFLUSH       0x00000008	/* Fifo FLUSH */
  #define SAI_xCR2_TRIS         0x00000010	/* TRIState Management on data line */
  #define SAI_xCR2_MUTE         0x00000020	/* Mute mode */
  #define SAI_xCR2_MUTEVAL      0x00000040	/* Mute value */
  #define SAI_xCR2_MUTECNT      0x00001F80	/* MUTECNT[5:0] (MUTE counter) */
  #define SAI_xCR2_MUTECNT_0    0x00000080	/* Bit 0 */
  #define SAI_xCR2_MUTECNT_1    0x00000100	/* Bit 1 */
  #define SAI_xCR2_MUTECNT_2    0x00000200	/* Bit 2 */
  #define SAI_xCR2_MUTECNT_3    0x00000400	/* Bit 3 */
  #define SAI_xCR2_MUTECNT_4    0x00000800	/* Bit 4 */
  #define SAI_xCR2_MUTECNT_5    0x00001000	/* Bit 5 */
  #define SAI_xCR2_CPL          0x00080000	/* Complement Bit */
  #define SAI_xCR2_COMP         0x0000C000	/* COMP[1:0] (Companding mode) */
  #define SAI_xCR2_COMP_0       0x00004000	/* Bit 0 */
  #define SAI_xCR2_COMP_1       0x00008000	/* Bit 1 */
#define TOFF_SAI_FRCR       0x0008		/* (RW) SAI block x frame configuration register */
  #define SAI_xFRCR_FRL         0x000000FF	/* FRL[1:0](Frame length)  */
  #define SAI_xFRCR_FRL_0       0x00000001	/* Bit 0 */
  #define SAI_xFRCR_FRL_1       0x00000002	/* Bit 1 */
  #define SAI_xFRCR_FRL_2       0x00000004	/* Bit 2 */
  #define SAI_xFRCR_FRL_3       0x00000008	/* Bit 3 */
  #define SAI_xFRCR_FRL_4       0x00000010	/* Bit 4 */
  #define SAI_xFRCR_FRL_5       0x00000020	/* Bit 5 */
  #define SAI_xFRCR_FRL_6       0x00000040	/* Bit 6 */
  #define SAI_xFRCR_FRL_7       0x00000080	/* Bit 7 */
  #define SAI_xFRCR_FSALL       0x00007F00	/* FRL[1:0] (Frame synchronization active level length)  */
  #define SAI_xFRCR_FSALL_0     0x00000100	/* Bit 0 */
  #define SAI_xFRCR_FSALL_1     0x00000200	/* Bit 1 */
  #define SAI_xFRCR_FSALL_2     0x00000400	/* Bit 2 */
  #define SAI_xFRCR_FSALL_3     0x00000800	/* Bit 3 */
  #define SAI_xFRCR_FSALL_4     0x00001000	/* Bit 4 */
  #define SAI_xFRCR_FSALL_5     0x00002000	/* Bit 5 */
  #define SAI_xFRCR_FSALL_6     0x00004000	/* Bit 6 */
  #define SAI_xFRCR_FSDEF       0x00010000	/* Frame Synchronization Definition */
  #define SAI_xFRCR_FSPOL       0x00020000	/* Frame Synchronization POLarity */
  #define SAI_xFRCR_FSOFF       0x00040000	/* Frame Synchronization OFFset*/
  #define SAI_xFRCR_FSPO      SAI_xFRCR_FSPOL
#define TOFF_SAI_SLOTR      0x000C		/* (RW) SAI block x slot register */
  #define SAI_xSLOTR_FBOFF      0x0000001F	/* FRL[4:0](First Bit Offset)  */
  #define SAI_xSLOTR_FBOFF_0    0x00000001	/* Bit 0 */
  #define SAI_xSLOTR_FBOFF_1    0x00000002	/* Bit 1 */
  #define SAI_xSLOTR_FBOFF_2    0x00000004	/* Bit 2 */
  #define SAI_xSLOTR_FBOFF_3    0x00000008	/* Bit 3 */
  #define SAI_xSLOTR_FBOFF_4    0x00000010	/* Bit 4 */
  #define SAI_xSLOTR_SLOTSZ     0x000000C0	/* SLOTSZ[1:0] (Slot size)  */
  #define SAI_xSLOTR_SLOTSZ_0   0x00000040	/* Bit 0 */
  #define SAI_xSLOTR_SLOTSZ_1   0x00000080	/* Bit 1 */
  #define SAI_xSLOTR_NBSLOT     0x00000F00	/* NBSLOT[3:0] (Number of Slot in audio Frame)  */
  #define SAI_xSLOTR_NBSLOT_0   0x00000100	/* Bit 0 */
  #define SAI_xSLOTR_NBSLOT_1   0x00000200	/* Bit 1 */
  #define SAI_xSLOTR_NBSLOT_2   0x00000400	/* Bit 2 */
  #define SAI_xSLOTR_NBSLOT_3   0x00000800	/* Bit 3 */
  #define SAI_xSLOTR_SLOTEN     0xFFFF0000	/* SLOTEN[15:0] (Slot Enable)  */
#define TOFF_SAI_IMR        0x0010		/* (RW) SAI block x interrupt mask register */
  #define SAI_xIMR_OVRUDRIE     0x00000001	/* Overrun underrun interrupt enable                              */
  #define SAI_xIMR_MUTEDETIE    0x00000002	/* Mute detection interrupt enable                                */
  #define SAI_xIMR_WCKCFGIE     0x00000004	/* Wrong Clock Configuration interrupt enable                     */
  #define SAI_xIMR_FREQIE       0x00000008	/* FIFO request interrupt enable                                  */
  #define SAI_xIMR_CNRDYIE      0x00000010	/* Codec not ready interrupt enable                               */
  #define SAI_xIMR_AFSDETIE     0x00000020	/* Anticipated frame synchronization detection interrupt enable   */
  #define SAI_xIMR_LFSDETIE     0x00000040	/* Late frame synchronization detection interrupt enable          */
#define TOFF_SAI_SR         0x0014		/* (RW) SAI block x status register */
  #define SAI_xSR_OVRUDR        0x00000001	/* Overrun underrun */
  #define SAI_xSR_MUTEDET       0x00000002	/* Mute detection */
  #define SAI_xSR_WCKCFG        0x00000004	/* Wrong Clock Configuration */
  #define SAI_xSR_FREQ          0x00000008	/* FIFO request */
  #define SAI_xSR_CNRDY         0x00000010	/* Codec not ready */
  #define SAI_xSR_AFSDET        0x00000020	/* Anticipated frame synchronization detection */
  #define SAI_xSR_LFSDET        0x00000040	/* Late frame synchronization detection */
  #define SAI_xSR_FLVL          0x00070000	/* FLVL[2:0] (FIFO Level Threshold) */
  #define SAI_xSR_FLVL_0        0x00010000	/* Bit 0 */
  #define SAI_xSR_FLVL_1        0x00020000	/* Bit 1 */
  #define SAI_xSR_FLVL_2        0x00040000	/* Bit 2 */
#define TOFF_SAI_CLRFR      0x0018		/* (RW) SAI block x clear flag register */
  #define SAI_xCLRFR_COVRUDR    0x00000001	/* Clear Overrun underrun */
  #define SAI_xCLRFR_CMUTEDET   0x00000002	/* Clear Mute detection */
  #define SAI_xCLRFR_CWCKCFG    0x00000004	/* Clear Wrong Clock Configuration */
  #define SAI_xCLRFR_CFREQ      0x00000008	/* Clear FIFO request */
  #define SAI_xCLRFR_CCNRDY     0x00000010	/* Clear Codec not ready */
  #define SAI_xCLRFR_CAFSDET    0x00000020	/* Clear Anticipated frame synchronization detection */
  #define SAI_xCLRFR_CLFSDET    0x00000040	/* Clear Late frame synchronization detection */
#define TOFF_SAI_DR         0x001C		/* (RW) SAI block x data register */


/*
 *  DFSDM MODULE REGISTERS
 */
#define TADR_DFSDM1_BASE    (MCU_APB2_PERIPH_BASE + 0xD000)
#define TADR_DFSDM1_CHANNEL0_BASE   (TADR_DFSDM1_BASE + 0x0000)
#define TADR_DFSDM1_CHANNEL1_BASE   (TADR_DFSDM1_BASE + 0x0020)
#define TADR_DFSDM1_CHANNEL2_BASE   (TADR_DFSDM1_BASE + 0x0040)
#define TADR_DFSDM1_CHANNEL3_BASE   (TADR_DFSDM1_BASE + 0x0060)
#define TADR_DFSDM1_CHANNEL4_BASE   (TADR_DFSDM1_BASE + 0x0080)
#define TADR_DFSDM1_CHANNEL5_BASE   (TADR_DFSDM1_BASE + 0x00A0)
#define TADR_DFSDM1_CHANNEL6_BASE   (TADR_DFSDM1_BASE + 0x00C0)
#define TADR_DFSDM1_CHANNEL7_BASE   (TADR_DFSDM1_BASE + 0x00E0)
#define TOFF_DFSDM_CHCFGR1 0x0000	/* (RW) DFSDM channel configuration register1 */
  #define DFSDM_CHCFGR1_SITP       0x00000003	/* SITP[1:0] Serial interface type for channel y */
  #define DFSDM_CHCFGR1_SITP_0     0x00000001	/* Serial interface type for channel y, Bit 0 */
  #define DFSDM_CHCFGR1_SITP_1     0x00000002	/* Serial interface type for channel y, Bit 1 */
  #define DFSDM_CHCFGR1_SPICKSEL   0x0000000C	/* SPICKSEL[1:0] SPI clock select for channel y */
  #define DFSDM_CHCFGR1_SPICKSEL_0 0x00000004	/* SPI clock select for channel y, Bit 0 */
  #define DFSDM_CHCFGR1_SPICKSEL_1 0x00000008	/* SPI clock select for channel y, Bit 1 */
  #define DFSDM_CHCFGR1_SCDEN      0x00000020	/* Short circuit detector enable on channel y */
  #define DFSDM_CHCFGR1_CKABEN     0x00000040	/* Clock absence detector enable on channel y */
  #define DFSDM_CHCFGR1_CHEN       0x00000080	/* Channel y enable */
  #define DFSDM_CHCFGR1_CHINSEL    0x00000100	/* Serial inputs selection for channel y */
  #define DFSDM_CHCFGR1_DATMPX_0   0x00001000	/* Input data multiplexer for channel y, Bit 0 */
  #define DFSDM_CHCFGR1_DATMPX_1   0x00002000	/* Input data multiplexer for channel y, Bit 1 */
  #define DFSDM_CHCFGR1_DATMPX     0x00003000	/* DATMPX[1:0] Input data multiplexer for channel y */
  #define DFSDM_CHCFGR1_DATPACK    0x0000C000	/* DATPACK[1:0] Data packing mode */
  #define DFSDM_CHCFGR1_DATPACK_0  0x00004000	/* Data packing mode, Bit 0 */
  #define DFSDM_CHCFGR1_DATPACK_1  0x00008000	/* Data packing mode, Bit 1 */
  #define DFSDM_CHCFGR1_CKOUTDIV   0x00FF0000	/* CKOUTDIV[7:0] output serial clock divider */
  #define DFSDM_CHCFGR1_CKOUTSRC   0x40000000	/* Output serial clock source selection */
  #define DFSDM_CHCFGR1_DFSDMEN    0x80000000	/* Global enable for DFSDM interface */
#define TOFF_DFSDM_CHCFGR2 0x0004	/* (RW) DFSDM channel configuration register2 */
  #define DFSDM_CHCFGR2_DTRBS      0x000000F8	/* DTRBS[4:0] Data right bit-shift for channel y */
  #define DFSDM_CHCFGR2_OFFSET     0xFFFFFF00	/* OFFSET[23:0] 24-bit calibration offset for channel y */
#define TOFF_DFSDM_CHAWSCDR 0x0008	/* (RW) DFSDM channel analog watchdog and short circuit detector register */
  #define DFSDM_CHAWSCDR_SCDT      0x000000FF	/* SCDT[7:0] Short circuit detector threshold for channel y */
  #define DFSDM_CHAWSCDR_BKSCD     0x0000F000	/* BKSCD[3:0] Break signal assignment for short circuit detector on channel y */
  #define DFSDM_CHAWSCDR_AWFOSR    0x001F0000	/* AWFOSR[4:0] Analog watchdog filter oversampling ratio on channel y */
  #define DFSDM_CHAWSCDR_AWFORD    0x00C00000	/* AWFORD[1:0] Analog watchdog Sinc filter order on channel y */
  #define DFSDM_CHAWSCDR_AWFORD_0  0x00400000	/* Analog watchdog Sinc filter order on channel y, Bit 0 */
  #define DFSDM_CHAWSCDR_AWFORD_1  0x00800000	/* Analog watchdog Sinc filter order on channel y, Bit 1 */
#define TOFF_DFSDM_CHWDATAR 0x000C	/* (RW) DFSDM channel watchdog filter data register */
  #define DFSDM_CHWDATR_WDATA      0x0000FFFF	/* WDATA[15:0] Input channel y watchdog data */
#define TOFF_DFSDM_CHDATINR 0x0010	/* (RW) DFSDM channel data input register */
  #define DFSDM_CHDATINR_INDAT0    0x0000FFFF	/* INDAT0[31:16] Input data for channel y or channel (y+1) */
  #define DFSDM_CHDATINR_INDAT1    0xFFFF0000	/* INDAT0[15:0] Input data for channel y */
#define TOFF_DFSDM_CHDLYR   0x0014	/* (RW) DFSDM channel delay register */
  #define DFSDM_CHDLYR_PLSSKP      0x0000003F	/* PLSSKP[5:0] Number of input serial samples that will be skipped */

#define TADR_DFSDM1_FILTER0_BASE    (TADR_DFSDM1_BASE + 0x0100)
#define TADR_DFSDM1_FILTER1_BASE    (TADR_DFSDM1_BASE + 0x0180)
#define TADR_DFSDM1_FILTER2_BASE    (TADR_DFSDM1_BASE + 0x0200)
#define TADR_DFSDM1_FILTER3_BASE    (TADR_DFSDM1_BASE + 0x0280)
#define TOFF_DFSDM_FLTCR1  0x0000	/* (RW) DFSDM control register1 */
  #define DFSDM_FLTCR1_DFEN      0x00000001	/* DFSDM enable */
  #define DFSDM_FLTCR1_JSWSTART  0x00000002	/* Start the conversion of the injected group of channels */
  #define DFSDM_FLTCR1_JSYNC     0x00000008	/* Launch an injected conversion synchronously with DFSDMx JSWSTART trigger */
  #define DFSDM_FLTCR1_JSCAN     0x00000010	/* Scanning conversion in continuous mode selection for injected conversions */
  #define DFSDM_FLTCR1_JDMAEN    0x00000020	/* DMA channel enabled to read data for the injected channel group */
  #define DFSDM_FLTCR1_JEXTSEL   0x00001F00	/* JEXTSEL[4:0]Trigger signal selection for launching injected conversions */
  #define DFSDM_FLTCR1_JEXTSEL_0 0x00000100	/* Trigger signal selection for launching injected conversions, Bit 0 */
  #define DFSDM_FLTCR1_JEXTSEL_1 0x00000200	/* Trigger signal selection for launching injected conversions, Bit 1 */
  #define DFSDM_FLTCR1_JEXTSEL_2 0x00000400	/* Trigger signal selection for launching injected conversions, Bit 2 */
  #define DFSDM_FLTCR1_JEXTSEL_3 0x00000800	/* Trigger signal selection for launching injected conversions, Bit 3 */
  #define DFSDM_FLTCR1_JEXTSEL_4 0x00001000	/* Trigger signal selection for launching injected conversions, Bit 4 */
  #define DFSDM_FLTCR1_JEXTEN    0x00006000	/* JEXTEN[1:0] Trigger enable and trigger edge selection for injected conversions */
  #define DFSDM_FLTCR1_JEXTEN_1  0x00004000	/* Trigger enable and trigger edge selection for injected conversions, Bit 1 */
  #define DFSDM_FLTCR1_JEXTEN_0  0x00002000	/* Trigger enable and trigger edge selection for injected conversions, Bit 0 */
  #define DFSDM_FLTCR1_RSWSTART  0x00020000	/* Software start of a conversion on the regular channel */
  #define DFSDM_FLTCR1_RCONT     0x00040000	/* Continuous mode selection for regular conversions */
  #define DFSDM_FLTCR1_RSYNC     0x00080000	/* Launch regular conversion synchronously with DFSDMx */
  #define DFSDM_FLTCR1_RDMAEN    0x00200000	/* DMA channel enabled to read data for the regular conversion */
  #define DFSDM_FLTCR1_RCH       0x07000000	/* RCH[2:0] Regular channel selection */
  #define DFSDM_FLTCR1_FAST      0x20000000	/* Fast conversion mode selection */
  #define DFSDM_FLTCR1_AWFSEL    0x40000000	/* Analog watchdog fast mode select */
#define TOFF_DFSDM_FLTCR2  0x0004	/* (RW) DFSDM control register2 */
  #define DFSDM_FLTCR2_JEOCIE    0x00000001	/* Injected end of conversion interrupt enable */
  #define DFSDM_FLTCR2_REOCIE    0x00000002	/* Regular end of conversion interrupt enable */
  #define DFSDM_FLTCR2_JOVRIE    0x00000004	/* Injected data overrun interrupt enable */
  #define DFSDM_FLTCR2_ROVRIE    0x00000008	/* Regular data overrun interrupt enable */
  #define DFSDM_FLTCR2_AWDIE     0x00000010	/* Analog watchdog interrupt enable */
  #define DFSDM_FLTCR2_SCDIE     0x00000020	/* Short circuit detector interrupt enable */
  #define DFSDM_FLTCR2_CKABIE    0x00000040	/* Clock absence interrupt enable */
  #define DFSDM_FLTCR2_EXCH      0x0000FF00	/* EXCH[7:0] Extreme detector channel selection */
  #define DFSDM_FLTCR2_AWDCH     0x00FF0000	/* AWDCH[7:0] Analog watchdog channel selection */
#define TOFF_DFSDM_FLTISR  0x0008	/* (RW) DFSDM interrupt and status register */
  #define DFSDM_FLTISR_JEOCF     0x00000001	/* End of injected conversion flag */
  #define DFSDM_FLTISR_REOCF     0x00000002	/* End of regular conversion flag */
  #define DFSDM_FLTISR_JOVRF     0x00000004	/* Injected conversion overrun flag */
  #define DFSDM_FLTISR_ROVRF     0x00000008	/* Regular conversion overrun flag */
  #define DFSDM_FLTISR_AWDF      0x00000010	/* Analog watchdog */
  #define DFSDM_FLTISR_JCIP      0x00002000	/* Injected conversion in progress status */
  #define DFSDM_FLTISR_RCIP      0x00004000	/* Regular conversion in progress status */
  #define DFSDM_FLTISR_CKABF     0x00FF0000	/* CKABF[7:0] Clock absence flag */
  #define DFSDM_FLTISR_SCDF      0xFF000000	/* SCDF[7:0] Short circuit detector flag */
#define TOFF_DFSDM_FLTICR  0x000C	/* (RW) DFSDM interrupt flag clear register */
  #define DFSDM_FLTICR_CLRJOVRF  0x00000004	/* Clear the injected conversion overrun flag */
  #define DFSDM_FLTICR_CLRROVRF  0x00000008	/* Clear the regular conversion overrun flag */
  #define DFSDM_FLTICR_CLRCKABF  0x00FF0000	/* CLRCKABF[7:0] Clear the clock absence flag */
  #define DFSDM_FLTICR_CLRSCSDF  0xFF000000	/* CLRSCSDF[7:0] Clear the short circuit detector flag */
#define TOFF_DFSDM_FLTJCHGR 0x0010	/* (RW) DFSDM injected channel group selection register */
  #define DFSDM_FLTJCHGR_JCHG    0x000000FF	/* JCHG[7:0] Injected channel group selection */
#define TOFF_DFSDM_FLTFCR  0x0014	/* (RW) DFSDM filter control register */
  #define DFSDM_FLTFCR_IOSR      0x000000FF	/* IOSR[7:0] Integrator oversampling ratio (averaging length) */
  #define DFSDM_FLTFCR_FOSR      0x03FF0000	/* FOSR[9:0] Sinc filter oversampling ratio (decimation rate) */
  #define DFSDM_FLTFCR_FORD      0xE0000000	/* FORD[2:0] Sinc filter order */
  #define DFSDM_FLTFCR_FORD_2    0x80000000	/* Sinc filter order, Bit 2 */
  #define DFSDM_FLTFCR_FORD_1    0x40000000	/* Sinc filter order, Bit 1 */
  #define DFSDM_FLTFCR_FORD_0    0x20000000	/* Sinc filter order, Bit 0 */
#define TOFF_DFSDM_FLTJDATAR 0x0018	/* (RW) DFSDM data register for injected group */
  #define DFSDM_FLTJDATAR_JDATACH 0x00000007	/* JDATACH[2:0] Injected channel most recently converted */
  #define DFSDM_FLTJDATAR_JDATA   0xFFFFFF00	/* JDATA[23:0] Injected group conversion data */
#define TOFF_DFSDM_FLTRDATAR 0x001C	/* (RW) DFSDM data register for regular group */
  #define DFSDM_FLTRDATAR_RDATACH 0x00000007	/* RDATACH[2:0] Regular channel most recently converted */
  #define DFSDM_FLTRDATAR_RPEND   0x00000010	/* RPEND Regular channel pending data */
  #define DFSDM_FLTRDATAR_RDATA   0xFFFFFF00	/* RDATA[23:0] Regular channel conversion data */
#define TOFF_DFSDM_FLTAWHTR 0x0020	/* (RW) DFSDM analog watchdog high threshold register */
  #define DFSDM_FLTAWHTR_BKAWH   0x0000000F	/* BKAWH[3:0] Break signal assignment to analog watchdog high threshold event */
  #define DFSDM_FLTAWHTR_AWHT    0xFFFFFF00	/* AWHT[23:0] Analog watchdog high threshold */
#define TOFF_DFSDM_FLTAWLTR 0x0024	/* (RW) DFSDM analog watchdog low threshold register */
  #define DFSDM_FLTAWLTR_BKAWL   0x0000000F	/* BKAWL[3:0] Break signal assignment to analog watchdog low threshold event */
  #define DFSDM_FLTAWLTR_AWLT    0xFFFFFF00	/* AWLT[23:0] Analog watchdog low threshold */
#define TOFF_DFSDM_FLTAWSR  0x0028	/* (RW) DFSDM analog watchdog status register */
  #define DFSDM_FLTAWSR_AWLTF    0x000000FF	/* AWLTF[7:0] Analog watchdog low threshold error on given channels */
  #define DFSDM_FLTAWSR_AWHTF    0x0000FF00	/* AWHTF[15:8] Analog watchdog high threshold error on given channels */
#define TOFF_DFSDM_FLTAWCFR 0x002C	/* (RW) DFSDM analog watchdog clear flag register */
  #define DFSDM_FLTAWCFR_CLRAWLTF 0x000000FF	/* CLRAWLTF[7:0] Clear the Analog watchdog low threshold flag */
  #define DFSDM_FLTAWCFR_CLRAWHTF 0x0000FF00	/* CLRAWHTF[15:8] Clear the Analog watchdog high threshold flag */
#define TOFF_DFSDM_FLTEXMAX 0x0030	/* (RW) DFSDM extreme detector maximum register */
  #define DFSDM_FLTEXMAX_EXMAXCH 0x00000007	/* EXMAXCH[2:0] Extreme detector maximum data channel */
  #define DFSDM_FLTEXMAX_EXMAX   0xFFFFFF00	/* EXMAX[23:0] Extreme detector maximum value */
#define TOFF_DFSDM_FLTEXMIN 0x0034	/* (RW) DFSDM extreme detector minimum register */
  #define DFSDM_FLTEXMIN_EXMINCH 0x00000007	/* EXMINCH[2:0] Extreme detector minimum data channel */
  #define DFSDM_FLTEXMIN_EXMIN   0xFFFFFF00	/* EXMIN[23:0] Extreme detector minimum value */
#define TOFF_DFSDM_FLTCNVTIMR 0x0038/* (RW) DFSDM conversion timer */
  #define DFSDM_FLTCNVTIMR_CNVCNT 0xFFFFFFF0	/* CNVCNT[27:0]: 28-bit timer counting conversion time */

#define TOFF_DFSDM_HWCFGR   0x07F0	/* (R)  DFSDM HW Configuration register */
  #define DFSDM_HWCFGR_NBT      0x000000FF	/* Number of implemented transceivers */
  #define DFSDM_HWCFGR_NBF      0x0000FF00	/* Number of implemented filters */
#define TOFF_DFSDM_VERR     0x07F4	/* (R)  DFSDM Version register */
  #define DFSDM_VERR_MINREV     0x0000000F	/* Minor Revision number */
  #define DFSDM_VERR_MAJREV     0x000000F0	/* Major Revision number */
#define TOFF_DFSDM_IPDR     0x07F8	/* (R)  DFSDM Identification register */
#define TOFF_DFSDM_SIDR     0x07FC	/* (R)  DFSDM Size Identification register,     Address offset: 0x7FC */


/*
 *  FDCAN
 */
#define TADR_FDCAN1_BASE    (MCU_APB2_PERIPH_BASE + 0xE000)
#define TADR_FDCAN2_BASE    (MCU_APB2_PERIPH_BASE + 0xF000)
#define TOFF_FDCAN_CREL     0x0000		/* (RW) FDCAN Core Release register */
  #define FDCAN_CREL_DAY        0x000000FF	/* Timestamp Day */
  #define FDCAN_CREL_MON        0x0000FF00	/* Timestamp Month */
  #define FDCAN_CREL_YEAR       0x000F0000	/* Timestamp Year */
  #define FDCAN_CREL_SUBSTEP    0x00F00000	/* Sub-step of Core release */
  #define FDCAN_CREL_STEP       0x0F000000	/* Step of Core release */
  #define FDCAN_CREL_REL        0xF0000000	/* Core release */
#define TOFF_FDCAN_ENDN     0x0004		/* (RW) FDCAN Endian register */
#define TOFF_FDCAN_DBTP     0x000C		/* (RW) FDCAN Data Bit Timing & Prescaler register */
  #define FDCAN_DBTP_DSJW       0x0000000F	/* Synchronization Jump Width */
  #define FDCAN_DBTP_DTSEG2     0x000000F0	/* Data time segment after sample point */
  #define FDCAN_DBTP_DTSEG1     0x00001F00	/* Data time segment before sample point */
  #define FDCAN_DBTP_DBRP       0x001F0000	/* Data BIt Rate Prescaler */
  #define FDCAN_DBTP_TDC        0x00800000	/* Transceiver Delay Compensation */
#define TOFF_FDCAN_TEST     0x0010		/* (RW) FDCAN Test register */
  #define FDCAN_TEST_LBCK       0x00000010	/* Loop Back mode */
  #define FDCAN_TEST_TX         0x00000060	/* Control of Transmit Pin */
  #define FDCAN_TEST_RX         0x00000080	/* Receive Pin */
#define TOFF_FDCAN_RWD      0x0014		/* (RW) FDCAN RAM Watchdog register */
  #define FDCAN_RWD_WDC         0x000000FF	/* Watchdog configuration */
  #define FDCAN_RWD_WDV         0x0000FF00	/* Watchdog value */
#define TOFF_FDCAN_CCCR     0x0018		/* (RW) FDCAN CC Control register */
  #define FDCAN_CCCR_INIT       0x00000001	/* Initialization bit */
  #define FDCAN_CCCR_CCCE       0x00000002	/* Configuration Change Enable bit */
  #define FDCAN_CCCR_ASM        0x00000004	/* ASM Restricted Operation Mode */
  #define FDCAN_CCCR_CSA        0x00000008	/* Clock Stop Acknowledge */
  #define FDCAN_CCCR_CSR        0x00000010	/* Clock Stop Request */
  #define FDCAN_CCCR_MON        0x00000020	/* Bus Monitoring Mode */
  #define FDCAN_CCCR_DAR        0x00000040	/* Disable Automatic Retransmission */
  #define FDCAN_CCCR_TEST       0x00000080	/* Test Mode Enable */
  #define FDCAN_CCCR_FDOE       0x00000100	/* FD Operation Enable */
  #define FDCAN_CCCR_BRSE       0x00000200	/* FDCAN Bit Rate Switching */
  #define FDCAN_CCCR_PXHD       0x00001000	/* Protocol Exception Handling Disable */
  #define FDCAN_CCCR_EFBI       0x00002000	/* Edge Filtering during Bus Integration */
  #define FDCAN_CCCR_TXP        0x00004000	/* Two CAN bit times Pause */
  #define FDCAN_CCCR_NISO       0x00008000	/* Non ISO Operation */
#define TOFF_FDCAN_NBTP     0x001C		/* (RW) FDCAN Nominal Bit Timing & Prescaler register */
  #define FDCAN_NBTP_NTSEG2     0x0000007F	/* Nominal Time segment after sample point */
  #define FDCAN_NBTP_NTSEG1     0x0000FF00	/* Nominal Time segment before sample point */
  #define FDCAN_NBTP_NBRP       0x01FF0000	/* Bit Rate Prescaler */
  #define FDCAN_NBTP_NSJW       0xFE000000	/* Nominal (Re)Synchronization Jump Width */
#define TOFF_FDCAN_TSCC     0x0020		/* (RW) FDCAN Timestamp Counter Configuration register */
  #define FDCAN_TSCC_TS         0x00000003	/* Timestamp Select */
  #define FDCAN_TSCC_TCP        0x000F0000	/* Timestamp Counter Prescaler */
#define TOFF_FDCAN_TSCV     0x0024		/* (RW) FDCAN Timestamp Counter Value register */
  #define FDCAN_TSCV_TSC        0x0000FFFF	/* Timestamp Counter */
#define TOFF_FDCAN_TOCC     0x0028		/* (RW) FDCAN Timeout Counter Configuration register */
  #define FDCAN_TOCC_ETOC       0x00000001	/* Enable Timeout Counter */
  #define FDCAN_TOCC_TOS        0x00000006	/* Timeout Select */
  #define FDCAN_TOCC_TOP        0xFFFF0000	/* Timeout Period */
#define TOFF_FDCAN_TOCV     0x002C		/* (RW) FDCAN Timeout Counter Value register */
  #define FDCAN_TOCV_TOC        0x0000FFFF	/* Timeout Counter */
#define TOFF_FDCAN_ECR      0x0040		/* (RW) FDCAN Error Counter register */
  #define FDCAN_ECR_TEC         0x0000000F	/* Transmit Error Counter */
  #define FDCAN_ECR_REC         0x00007F00	/* Receive Error Counter */
  #define FDCAN_ECR_RP          0x00008000	/* Receive Error Passive */
  #define FDCAN_ECR_CEL         0x00FF0000	/* CAN Error Logging */
#define TOFF_FDCAN_PSR      0x0044		/* (RW) FDCAN Protocol Status register */
  #define FDCAN_PSR_LEC         0x00000007	/* Last Error Code */
  #define FDCAN_PSR_ACT         0x00000018	/* Activity */
  #define FDCAN_PSR_EP          0x00000020	/* Error Passive */
  #define FDCAN_PSR_EW          0x00000040	/* Warning Status */
  #define FDCAN_PSR_BO          0x00000080	/* Bus_Off Status */
  #define FDCAN_PSR_DLEC        0x00000700	/* Data Last Error Code */
  #define FDCAN_PSR_RESI        0x00000800	/* ESI flag of last received FDCAN Message */
  #define FDCAN_PSR_RBRS        0x00001000	/* BRS flag of last received FDCAN Message */
  #define FDCAN_PSR_REDL        0x00002000	/* Received FDCAN Message */
  #define FDCAN_PSR_PXE         0x00004000	/* Protocol Exception Event */
  #define FDCAN_PSR_TDCV        0x007F0000	/* Transmitter Delay Compensation Value */
#define TOFF_FDCAN_TDCR     0x0048		/* (RW) FDCAN Transmitter Delay Compensation register */
  #define FDCAN_TDCR_TDCF       0x0000007F	/* Transmitter Delay Compensation Filter */
  #define FDCAN_TDCR_TDCO       0x00007F00	/* Transmitter Delay Compensation Offset */
#define TOFF_FDCAN_IR       0x0050		/* (RW) FDCAN Interrupt register */
  #define FDCAN_IR_RF0N         0x00000001	/* Rx FIFO 0 New Message */
  #define FDCAN_IR_RF0W         0x00000002	/* Rx FIFO 0 Watermark Reached */
  #define FDCAN_IR_RF0F         0x00000004	/* Rx FIFO 0 Full */
  #define FDCAN_IR_RF0L         0x00000008	/* Rx FIFO 0 Message Lost */
  #define FDCAN_IR_RF1N         0x00000010	/* Rx FIFO 1 New Message */
  #define FDCAN_IR_RF1W         0x00000020	/* Rx FIFO 1 Watermark Reached */
  #define FDCAN_IR_RF1F         0x00000040	/* Rx FIFO 1 Full */
  #define FDCAN_IR_RF1L         0x00000080	/* Rx FIFO 1 Message Lost */
  #define FDCAN_IR_HPM          0x00000100	/* High Priority Message */
  #define FDCAN_IR_TC           0x00000200	/* Transmission Completed */
  #define FDCAN_IR_TCF          0x00000400	/* Transmission Cancellation Finished */
  #define FDCAN_IR_TFE          0x00000800	/* Tx FIFO Empty */
  #define FDCAN_IR_TEFN         0x00001000	/* Tx Event FIFO New Entry */
  #define FDCAN_IR_TEFW         0x00002000	/* Tx Event FIFO Watermark Reached */
  #define FDCAN_IR_TEFF         0x00004000	/* Tx Event FIFO Full */
  #define FDCAN_IR_TEFL         0x00008000	/* Tx Event FIFO Element Lost */
  #define FDCAN_IR_TSW          0x00010000	/* Timestamp Wraparound */
  #define FDCAN_IR_MRAF         0x00020000	/* Message RAM Access Failure */
  #define FDCAN_IR_TOO          0x00040000	/* Timeout Occurred */
  #define FDCAN_IR_DRX          0x00080000	/* Message stored to Dedicated Rx Buffer */
  #define FDCAN_IR_ELO          0x00400000	/* Error Logging Overflow */
  #define FDCAN_IR_EP           0x00800000	/* Error Passive */
  #define FDCAN_IR_EW           0x01000000	/* Warning Status */
  #define FDCAN_IR_BO           0x02000000	/* Bus_Off Status */
  #define FDCAN_IR_WDI          0x04000000	/* Watchdog Interrupt */
  #define FDCAN_IR_PEA          0x08000000	/* Protocol Error in Arbitration Phase */
  #define FDCAN_IR_PED          0x10000000	/* Protocol Error in Data Phase */
  #define FDCAN_IR_ARA          0x20000000	/* Access to Reserved Address */
#define TOFF_FDCAN_IE       0x0054		/* (RW) FDCAN Interrupt Enable register */
  #define FDCAN_IE_RF0NE        0x00000001	/* Rx FIFO 0 New Message Enable */
  #define FDCAN_IE_RF0WE        0x00000002	/* Rx FIFO 0 Watermark Reached Enable */
  #define FDCAN_IE_RF0FE        0x00000004	/* Rx FIFO 0 Full Enable */
  #define FDCAN_IE_RF0LE        0x00000008	/* Rx FIFO 0 Message Lost Enable */
  #define FDCAN_IE_RF1NE        0x00000010	/* Rx FIFO 1 New Message Enable */
  #define FDCAN_IE_RF1WE        0x00000020	/* Rx FIFO 1 Watermark Reached Enable */
  #define FDCAN_IE_RF1FE        0x00000040	/* Rx FIFO 1 Full Enable */
  #define FDCAN_IE_RF1LE        0x00000080	/* Rx FIFO 1 Message Lost Enable */
  #define FDCAN_IE_HPME         0x00000100	/* High Priority Message Enable */
  #define FDCAN_IE_TCE          0x00000200	/* Transmission Completed Enable */
  #define FDCAN_IE_TCFE         0x00000400	/* Transmission Cancellation Finished Enable */
  #define FDCAN_IE_TFEE         0x00000800	/* Tx FIFO Empty Enable */
  #define FDCAN_IE_TEFNE        0x00001000	/* Tx Event FIFO New Entry Enable */
  #define FDCAN_IE_TEFWE        0x00002000	/* Tx Event FIFO Watermark Reached Enable */
  #define FDCAN_IE_TEFFE        0x00004000	/* Tx Event FIFO Full Enable */
  #define FDCAN_IE_TEFLE        0x00008000	/* Tx Event FIFO Element Lost Enable */
  #define FDCAN_IE_TSWE         0x00010000	/* Timestamp Wraparound Enable */
  #define FDCAN_IE_MRAFE        0x00020000	/* Message RAM Access Failure Enable */
  #define FDCAN_IE_TOOE         0x00040000	/* Timeout Occurred Enable */
  #define FDCAN_IE_DRXE         0x00080000	/* Message stored to Dedicated Rx Buffer Enable */
  #define FDCAN_IE_ELOE         0x00400000	/* Error Logging Overflow Enable */
  #define FDCAN_IE_EPE          0x00800000	/* Error Passive Enable */
  #define FDCAN_IE_EWE          0x01000000	/* Warning Status Enable */
  #define FDCAN_IE_BOE          0x02000000	/* Bus_Off Status Enable */
  #define FDCAN_IE_WDIE         0x04000000	/* Watchdog Interrupt Enable */
  #define FDCAN_IE_PEAE         0x08000000	/* Protocol Error in Arbitration Phase Enable */
  #define FDCAN_IE_PEDE         0x10000000	/* Protocol Error in Data Phase Enable */
  #define FDCAN_IE_ARAE         0x20000000	/* Access to Reserved Address Enable */
#define TOFF_FDCAN_ILS      0x0058		/* (RW) FDCAN Interrupt Line Select register */
  #define FDCAN_ILS_RF0NL       0x00000001	/* Rx FIFO 0 New Message Line */
  #define FDCAN_ILS_RF0WL       0x00000002	/* Rx FIFO 0 Watermark Reached Line */
  #define FDCAN_ILS_RF0FL       0x00000004	/* Rx FIFO 0 Full Line */
  #define FDCAN_ILS_RF0LL       0x00000008	/* Rx FIFO 0 Message Lost Line */
  #define FDCAN_ILS_RF1NL       0x00000010	/* Rx FIFO 1 New Message Line */
  #define FDCAN_ILS_RF1WL       0x00000020	/* Rx FIFO 1 Watermark Reached Line */
  #define FDCAN_ILS_RF1FL       0x00000040	/* Rx FIFO 1 Full Line */
  #define FDCAN_ILS_RF1LL       0x00000080	/* Rx FIFO 1 Message Lost Line */
  #define FDCAN_ILS_HPML        0x00000100	/* High Priority Message Line */
  #define FDCAN_ILS_TCL         0x00000200	/* Transmission Completed Line */
  #define FDCAN_ILS_TCFL        0x00000400	/* Transmission Cancellation Finished Line */
  #define FDCAN_ILS_TFEL        0x00000800	/* Tx FIFO Empty Line */
  #define FDCAN_ILS_TEFNL       0x00001000	/* Tx Event FIFO New Entry Line */
  #define FDCAN_ILS_TEFW        0x00002000	/* Tx Event FIFO Watermark Reached Line */
  #define FDCAN_ILS_TEFFL       0x00004000	/* Tx Event FIFO Full Line */
  #define FDCAN_ILS_TEFLL       0x00008000	/* Tx Event FIFO Element Lost Line */
  #define FDCAN_ILS_TSWL        0x00010000	/* Timestamp Wraparound Line */
  #define FDCAN_ILS_MRAFL       0x00020000	/* Message RAM Access Failure Line */
  #define FDCAN_ILS_TOOL        0x00040000	/* Timeout Occurred Line  */
  #define FDCAN_ILS_DRXL        0x00080000	/* Message stored to Dedicated Rx Buffer Line */
  #define FDCAN_ILS_ELOL        0x00400000	/* Error Logging Overflow Line */
  #define FDCAN_ILS_EPL         0x00800000	/* Error Passive Line */
  #define FDCAN_ILS_EWL         0x01000000	/* Warning Status Line */
  #define FDCAN_ILS_BOL         0x02000000	/* Bus_Off Status Line */
  #define FDCAN_ILS_WDIL        0x04000000	/* Watchdog Interrupt Line */
  #define FDCAN_ILS_PEAL        0x08000000	/* Protocol Error in Arbitration Phase Line */
  #define FDCAN_ILS_PEDL        0x10000000	/* Protocol Error in Data Phase Line */
  #define FDCAN_ILS_ARAL        0x20000000	/* Access to Reserved Address Line */
#define TOFF_FDCAN_ILE      0x005C		/* (RW) FDCAN Interrupt Line Enable register */
  #define FDCAN_ILE_EINT0       0x00000001	/* Enable Interrupt Line 0 */
  #define FDCAN_ILE_EINT1       0x00000002	/* Enable Interrupt Line 1 */
#define TOFF_FDCAN_GFC      0x0080		/* (RW) FDCAN Global Filter Configuration register */
  #define FDCAN_GFC_RRFE        0x00000001	/* Reject Remote Frames Extended */
  #define FDCAN_GFC_RRFS        0x00000002	/* Reject Remote Frames Standard */
  #define FDCAN_GFC_ANFE        0x0000000C	/* Accept Non-matching Frames Extended */
  #define FDCAN_GFC_ANFS        0x00000030	/* Accept Non-matching Frames Standard */
#define TOFF_FDCAN_SIDFC    0x0084		/* (RW) FDCAN Standard ID Filter Configuration register */
  #define FDCAN_SIDFC_FLSSA     0x0000FFFC	/* Filter List Standard Start Address */
  #define FDCAN_SIDFC_LSS       0x00FF0000	/* List Size Standard */
#define TOFF_FDCAN_XIDFC    0x0088		/* (RW) FDCAN Extended ID Filter Configuration register */
  #define FDCAN_XIDFC_FLESA     0x0000FFFC	/* Filter List Standard Start Address */
  #define FDCAN_XIDFC_LSE       0x00FF0000	/* List Size Extended */
#define TOFF_FDCAN_XIDAM    0x0090		/* (RW) FDCAN Extended ID AND Mask register */
  #define FDCAN_XIDAM_EIDM      0x1FFFFFFF	/* Extended ID Mask */
#define TOFF_FDCAN_HPMS     0x0094		/* (RW) FDCAN High Priority Message Status register */
  #define FDCAN_HPMS_BIDX       0x0000003F	/* Buffer Index */
  #define FDCAN_HPMS_MSI        0x000000C0	/* Message Storage Indicator */
  #define FDCAN_HPMS_FIDX       0x00007F00	/* Filter Index */
  #define FDCAN_HPMS_FLST       0x00008000	/* Filter List */
#define TOFF_FDCAN_NDAT1    0x0098		/* (RW) FDCAN New Data 1 register */
  #define FDCAN_NDAT1_ND0       0x00000001	/* New Data flag of Rx Buffer 0 */
  #define FDCAN_NDAT1_ND1       0x00000002	/* New Data flag of Rx Buffer 1 */
  #define FDCAN_NDAT1_ND2       0x00000004	/* New Data flag of Rx Buffer 2 */
  #define FDCAN_NDAT1_ND3       0x00000008	/* New Data flag of Rx Buffer 3 */
  #define FDCAN_NDAT1_ND4       0x00000010	/* New Data flag of Rx Buffer 4 */
  #define FDCAN_NDAT1_ND5       0x00000020	/* New Data flag of Rx Buffer 5 */
  #define FDCAN_NDAT1_ND6       0x00000040	/* New Data flag of Rx Buffer 6 */
  #define FDCAN_NDAT1_ND7       0x00000080	/* New Data flag of Rx Buffer 7 */
  #define FDCAN_NDAT1_ND8       0x00000100	/* New Data flag of Rx Buffer 8 */
  #define FDCAN_NDAT1_ND9       0x00000200	/* New Data flag of Rx Buffer 9 */
  #define FDCAN_NDAT1_ND10      0x00000400	/* New Data flag of Rx Buffer 10 */
  #define FDCAN_NDAT1_ND11      0x00000800	/* New Data flag of Rx Buffer 11 */
  #define FDCAN_NDAT1_ND12      0x00001000	/* New Data flag of Rx Buffer 12 */
  #define FDCAN_NDAT1_ND13      0x00002000	/* New Data flag of Rx Buffer 13 */
  #define FDCAN_NDAT1_ND14      0x00004000	/* New Data flag of Rx Buffer 14 */
  #define FDCAN_NDAT1_ND15      0x00008000	/* New Data flag of Rx Buffer 15 */
  #define FDCAN_NDAT1_ND16      0x00010000	/* New Data flag of Rx Buffer 16 */
  #define FDCAN_NDAT1_ND17      0x00020000	/* New Data flag of Rx Buffer 17 */
  #define FDCAN_NDAT1_ND18      0x00040000	/* New Data flag of Rx Buffer 18 */
  #define FDCAN_NDAT1_ND19      0x00080000	/* New Data flag of Rx Buffer 19 */
  #define FDCAN_NDAT1_ND20      0x00100000	/* New Data flag of Rx Buffer 20 */
  #define FDCAN_NDAT1_ND21      0x00200000	/* New Data flag of Rx Buffer 21 */
  #define FDCAN_NDAT1_ND22      0x00400000	/* New Data flag of Rx Buffer 22 */
  #define FDCAN_NDAT1_ND23      0x00800000	/* New Data flag of Rx Buffer 23 */
  #define FDCAN_NDAT1_ND24      0x01000000	/* New Data flag of Rx Buffer 24 */
  #define FDCAN_NDAT1_ND25      0x02000000	/* New Data flag of Rx Buffer 25 */
  #define FDCAN_NDAT1_ND26      0x04000000	/* New Data flag of Rx Buffer 26 */
  #define FDCAN_NDAT1_ND27      0x08000000	/* New Data flag of Rx Buffer 27 */
  #define FDCAN_NDAT1_ND28      0x10000000	/* New Data flag of Rx Buffer 28 */
  #define FDCAN_NDAT1_ND29      0x20000000	/* New Data flag of Rx Buffer 29 */
  #define FDCAN_NDAT1_ND30      0x40000000	/* New Data flag of Rx Buffer 30 */
  #define FDCAN_NDAT1_ND31      0x80000000	/* New Data flag of Rx Buffer 31 */
#define TOFF_FDCAN_NDAT2    0x009C		/* (RW) FDCAN New Data 2 register */
  #define FDCAN_NDAT2_ND32      0x00000001	/* New Data flag of Rx Buffer 32 */
  #define FDCAN_NDAT2_ND33      0x00000002	/* New Data flag of Rx Buffer 33 */
  #define FDCAN_NDAT2_ND34      0x00000004	/* New Data flag of Rx Buffer 34 */
  #define FDCAN_NDAT2_ND35      0x00000008	/* New Data flag of Rx Buffer 35 */
  #define FDCAN_NDAT2_ND36      0x00000010	/* New Data flag of Rx Buffer 36 */
  #define FDCAN_NDAT2_ND37      0x00000020	/* New Data flag of Rx Buffer 37 */
  #define FDCAN_NDAT2_ND38      0x00000040	/* New Data flag of Rx Buffer 38 */
  #define FDCAN_NDAT2_ND39      0x00000080	/* New Data flag of Rx Buffer 39 */
  #define FDCAN_NDAT2_ND40      0x00000100	/* New Data flag of Rx Buffer 40 */
  #define FDCAN_NDAT2_ND41      0x00000200	/* New Data flag of Rx Buffer 41 */
  #define FDCAN_NDAT2_ND42      0x00000400	/* New Data flag of Rx Buffer 42 */
  #define FDCAN_NDAT2_ND43      0x00000800	/* New Data flag of Rx Buffer 43 */
  #define FDCAN_NDAT2_ND44      0x00001000	/* New Data flag of Rx Buffer 44 */
  #define FDCAN_NDAT2_ND45      0x00002000	/* New Data flag of Rx Buffer 45 */
  #define FDCAN_NDAT2_ND46      0x00004000	/* New Data flag of Rx Buffer 46 */
  #define FDCAN_NDAT2_ND47      0x00008000	/* New Data flag of Rx Buffer 47 */
  #define FDCAN_NDAT2_ND4       0x00010000	/* New Data flag of Rx Buffer 48 */
  #define FDCAN_NDAT2_ND49      0x00020000	/* New Data flag of Rx Buffer 49 */
  #define FDCAN_NDAT2_ND50      0x00040000	/* New Data flag of Rx Buffer 50 */
  #define FDCAN_NDAT2_ND51      0x00080000	/* New Data flag of Rx Buffer 51 */
  #define FDCAN_NDAT2_ND52      0x00100000	/* New Data flag of Rx Buffer 52 */
  #define FDCAN_NDAT2_ND53      0x00200000	/* New Data flag of Rx Buffer 53 */
  #define FDCAN_NDAT2_ND54      0x00400000	/* New Data flag of Rx Buffer 54 */
  #define FDCAN_NDAT2_ND55      0x00800000	/* New Data flag of Rx Buffer 55 */
  #define FDCAN_NDAT2_ND56      0x01000000	/* New Data flag of Rx Buffer 56 */
  #define FDCAN_NDAT2_ND57      0x02000000	/* New Data flag of Rx Buffer 57 */
  #define FDCAN_NDAT2_ND58      0x04000000	/* New Data flag of Rx Buffer 58 */
  #define FDCAN_NDAT2_ND59      0x08000000	/* New Data flag of Rx Buffer 59 */
  #define FDCAN_NDAT2_ND60      0x10000000	/* New Data flag of Rx Buffer 60 */
  #define FDCAN_NDAT2_ND61      0x20000000	/* New Data flag of Rx Buffer 61 */
  #define FDCAN_NDAT2_ND62      0x40000000	/* New Data flag of Rx Buffer 62 */
  #define FDCAN_NDAT2_ND63      0x80000000	/* New Data flag of Rx Buffer 63 */
#define TOFF_FDCAN_RXF0C    0x00A0		/* (RW) FDCAN Rx FIFO 0 Configuration register */
  #define FDCAN_RXF0C_F0SA      0x0000FFFC	/* Rx FIFO 0 Start Address */
  #define FDCAN_RXF0C_F0S       0x007F0000	/* Number of Rx FIFO 0 elements */
  #define FDCAN_RXF0C_F0WM      0x7F000000	/* FIFO 0 Watermark */
  #define FDCAN_RXF0C_F0OM      0x80000000	/* FIFO 0 Operation Mode */
#define TOFF_FDCAN_RXF0S    0x00A4		/* (RW) FDCAN Rx FIFO 0 Status register */
  #define FDCAN_RXF0S_F0FL      0x0000007F	/* Rx FIFO 0 Fill Level */
  #define FDCAN_RXF0S_F0GI      0x00003F00	/* Rx FIFO 0 Get Index */
  #define FDCAN_RXF0S_F0PI      0x003F0000	/* Rx FIFO 0 Put Index */
  #define FDCAN_RXF0S_F0F       0x01000000	/* Rx FIFO 0 Full */
  #define FDCAN_RXF0S_RF0L      0x02000000	/* Rx FIFO 0 Message Lost */
#define TOFF_FDCAN_RXF0A    0x00A8		/* (RW) FDCAN Rx FIFO 0 Acknowledge register */
  #define FDCAN_RXF0A_F0AI      0x0000003F	/* Rx FIFO 0 Acknowledge Index */
#define TOFF_FDCAN_RXBC     0x00AC		/* (RW) FDCAN Rx Buffer Configuration register */
  #define FDCAN_RXBC_RBSA       0x0000FFFC	/* Rx Buffer Start Address */
#define TOFF_FDCAN_RXF1C    0x00B0		/* (RW) FDCAN Rx FIFO 1 Configuration register */
  #define FDCAN_RXF1C_F1SA      0x0000FFFC	/* Rx FIFO 1 Start Address */
  #define FDCAN_RXF1C_F1S       0x007F0000	/* Number of Rx FIFO 1 elements */
  #define FDCAN_RXF1C_F1WM      0x7F000000	/* Rx FIFO 1 Watermark */
  #define FDCAN_RXF1C_F1OM      0x80000000	/* FIFO 1 Operation Mode */
#define TOFF_FDCAN_RXF1S    0x00B4		/* (RW) FDCAN Rx FIFO 1 Status register */
  #define FDCAN_RXF1S_F1FL      0x0000007F	/* Rx FIFO 1 Fill Level */
  #define FDCAN_RXF1S_F1GI      0x00003F00	/* Rx FIFO 1 Get Index */
  #define FDCAN_RXF1S_F1PI      0x003F0000	/* Rx FIFO 1 Put Index */
  #define FDCAN_RXF1S_F1F       0x01000000	/* Rx FIFO 1 Full */
  #define FDCAN_RXF1S_RF1L      0x02000000	/* Rx FIFO 1 Message Lost */
  #define FDCAN_RXF1S_DMS       0xC0000000	/* Debug Message Status */
#define TOFF_FDCAN_RXF1A    0x00B8		/* (RW) FDCAN Rx FIFO 1 Acknowledge register */
  #define FDCAN_RXF1A_F1AI      0x0000003F	/* Rx FIFO 1 Acknowledge Index */
#define TOFF_FDCAN_RXESC    0x00BC		/* (RW) FDCAN Rx Buffer/FIFO Element Size Configuration register */
  #define FDCAN_RXESC_F0DS      0x00000007	/* Rx FIFO 1 Data Field Size */
  #define FDCAN_RXESC_F1DS      0x00000070	/* Rx FIFO 0 Data Field Size */
  #define FDCAN_RXESC_RBDS      0x00000700	/* Rx Buffer Data Field Size */
#define TOFF_FDCAN_TXBC     0x00C0		/* (RW) FDCAN Tx Buffer Configuration register */
  #define FDCAN_TXBC_TBSA       0x000000FC	/* Tx Buffers Start Address */
  #define FDCAN_TXBC_NDTB       0x003F0000	/* Number of Dedicated Transmit Buffers */
  #define FDCAN_TXBC_TFQS       0x3F000000	/* Transmit FIFO/Queue Size */
  #define FDCAN_TXBC_TFQM       0x40000000	/* Tx FIFO/Queue Mode */
#define TOFF_FDCAN_TXFQS    0x00C4		/* (RW) FDCAN Tx FIFO/Queue Status register */
  #define FDCAN_TXFQS_TFFL      0x0000003F	/* Tx FIFO Free Level */
  #define FDCAN_TXFQS_TFGI      0x00001F00	/* Tx FIFO Get Index */
  #define FDCAN_TXFQS_TFQPI     0x001F0000	/* Tx FIFO/Queue Put Index */
  #define FDCAN_TXFQS_TFQF      0x00200000	/* Tx FIFO/Queue Full */
#define TOFF_FDCAN_TXESC    0x00C8		/* (RW) FDCAN Tx Buffer Element Size Configuration register */
  #define FDCAN_TXESC_TBDS      0x00000007	/* Tx Buffer Data Field Size */
#define TOFF_FDCAN_TXBRP    0x00CC		/* (RW) FDCAN Tx Buffer Request Pending register */
#define TOFF_FDCAN_TXBAR    0x00D0		/* (RW) FDCAN Tx Buffer Add Request register */
#define TOFF_FDCAN_TXBCR    0x00D4		/* (RW) FDCAN Tx Buffer Cancellation Request register */
#define TOFF_FDCAN_TXBTO    0x00D8		/* (RW) FDCAN Tx Buffer Transmission Occurred register */
#define TOFF_FDCAN_TXBCF    0x00DC		/* (RW) FDCAN Tx Buffer Cancellation Finished register */
#define TOFF_FDCAN_TXBTIE   0x00E0		/* (RW) FDCAN Tx Buffer Transmission Interrupt Enable register */
#define TOFF_FDCAN_TXBCIE   0x00E4		/* (RW) FDCAN Tx Buffer Cancellation Finished Interrupt Enable register */
#define TOFF_FDCAN_TXEFC    0x00F0		/* (RW) FDCAN Tx Event FIFO Configuration register */
  #define FDCAN_TXEFC_EFSA      0x0000FFFC	/* Event FIFO Start Address */
  #define FDCAN_TXEFC_EFS       0x003F0000	/* Event FIFO Size */
  #define FDCAN_TXEFC_EFWM      0x3F000000	/* Event FIFO Watermark */
#define TOFF_FDCAN_TXEFS    0x00F4		/* (RW) FDCAN Tx Event FIFO Status register */
  #define FDCAN_TXEFS_EFFL      0x0000003F	/* Event FIFO Fill Level */
  #define FDCAN_TXEFS_EFGI      0x00001F00	/* Event FIFO Get Index */
  #define FDCAN_TXEFS_EFPI      0x001F0000	/* Event FIFO Put Index */
  #define FDCAN_TXEFS_EFF       0x01000000	/* Event FIFO Full */
  #define FDCAN_TXEFS_TEFL      0x02000000	/* Tx Event FIFO Element Lost */
#define TOFF_FDCAN_TXEFA    0x00F8		/* (RW) FDCAN Tx Event FIFO Acknowledge register */
  #define FDCAN_TXEFA_EFAI      0x0000001F	/* Event FIFO Acknowledge Index */
#define TOFF_FDCAN_TTTMC    0x0100		/* (RW) TT Trigger Memory Configuration register */
  #define FDCAN_TTTMC_TMSA      0x0000FFFC	/* Trigger Memory Start Address */
  #define FDCAN_TTTMC_TME       0x007F0000	/* Trigger Memory Elements */
#define TOFF_FDCAN_TTRMC    0x0104		/* (RW) TT Reference Message Configuration register */
  #define FDCAN_TTRMC_RID       0x1FFFFFFF	/* Reference Identifier */
  #define FDCAN_TTRMC_XTD       0x40000000	/* Extended Identifier */
  #define FDCAN_TTRMC_RMPS      0x80000000	/* Reference Message Payload Select */
#define TOFF_FDCAN_TTOCF    0x0108		/* (RW) TT Operation Configuration register */
  #define FDCAN_TTOCF_OM        0x00000003	/* Operation Mode */
  #define FDCAN_TTOCF_GEN       0x00000008	/* Gap Enable */
  #define FDCAN_TTOCF_TM        0x00000010	/* Time Master */
  #define FDCAN_TTOCF_LDSDL     0x000000E0	/* LD of Synchronization Deviation Limit */
  #define FDCAN_TTOCF_IRTO      0x00007F00	/* Initial Reference Trigger Offset */
  #define FDCAN_TTOCF_EECS      0x00008000	/* Enable External Clock Synchronization */
  #define FDCAN_TTOCF_AWL       0x00FF0000	/* Application Watchdog Limit */
  #define FDCAN_TTOCF_EGTF      0x01000000	/* Enable Global Time Filtering */
  #define FDCAN_TTOCF_ECC       0x02000000	/* Enable Clock Calibration */
  #define FDCAN_TTOCF_EVTP      0x04000000	/* Event Trigger Polarity */
#define TOFF_FDCAN_TTMLM    0x010C		/* (RW) TT Matrix Limits register */
  #define FDCAN_TTMLM_CCM       0x0000003F	/* Cycle Count Max */
  #define FDCAN_TTMLM_CSS       0x000000C0	/* Cycle Start Synchronization */
  #define FDCAN_TTMLM_TXEW      0x00000F00	/* Tx Enable Window */
  #define FDCAN_TTMLM_ENTT      0x0FFF0000	/* Expected Number of Tx Triggers */
#define TOFF_FDCAN_TURCF    0x0110		/* (RW) TUR Configuration register */
  #define FDCAN_TURCF_NCL       0x0000FFFF	/* Numerator Configuration Low */
  #define FDCAN_TURCF_DC        0x3FFF0000	/* Denominator Configuration */
  #define FDCAN_TURCF_ELT       0x80000000	/* Enable Local Time */
#define TOFF_FDCAN_TTOCN    0x0114		/* (RW) TT Operation Control register */
  #define FDCAN_TTOCN_SGT       0x00000001	/* Set Global time */
  #define FDCAN_TTOCN_ECS       0x00000002	/* External Clock Synchronization */
  #define FDCAN_TTOCN_SWP       0x00000004	/* Stop Watch Polarity */
  #define FDCAN_TTOCN_SWS       0x00000018	/* Stop Watch Source */
  #define FDCAN_TTOCN_RTIE      0x00000020	/* Register Time Mark Interrupt Pulse Enable */
  #define FDCAN_TTOCN_TMC       0x000000C0	/* Register Time Mark Compare */
  #define FDCAN_TTOCN_TTIE      0x00000100	/* Trigger Time Mark Interrupt Pulse Enable */
  #define FDCAN_TTOCN_GCS       0x00000200	/* Gap Control Select */
  #define FDCAN_TTOCN_FGP       0x00000400	/* Finish Gap */
  #define FDCAN_TTOCN_TMG       0x00000800	/* Time Mark Gap */
  #define FDCAN_TTOCN_NIG       0x00001000	/* Next is Gap */
  #define FDCAN_TTOCN_ESCN      0x00002000	/* External Synchronization Control */
  #define FDCAN_TTOCN_LCKC      0x00008000	/* TT Operation Control Register Locked */
#define TOFF_FDCAN_TTGTP    0x0118		/* (RW) TT Global Time Preset register */
  #define FDCAN_TTGTP_TP        0x0000FFFF	/* Time Preset */
  #define FDCAN_TTGTP_CTP       0xFFFF0000	/* Cycle Time Target Phase */
#define TOFF_FDCAN_TTTMK    0x011C		/* (RW) TT Time Mark register */
  #define FDCAN_TTTMK_TM        0x0000FFFF	/* Time Mark */
  #define FDCAN_TTTMK_TICC      0x007F0000	/* Time Mark Cycle Code */
  #define FDCAN_TTTMK_LCKM      0x80000000	/* TT Time Mark Register Locked */
#define TOFF_FDCAN_TTIR     0x0120		/* (RW) TT Interrupt register */
  #define FDCAN_TTIR_SBC        0x00000001	/* Start of Basic Cycle */
  #define FDCAN_TTIR_SMC        0x00000002	/* Start of Matrix Cycle */
  #define FDCAN_TTIR_CSM        0x00000004	/* Change of Synchronization Mode */
  #define FDCAN_TTIR_SOG        0x00000008	/* Start of Gap */
  #define FDCAN_TTIR_RTMI       0x00000010	/* Register Time Mark Interrupt */
  #define FDCAN_TTIR_TTMI       0x00000020	/* Trigger Time Mark Event Internal */
  #define FDCAN_TTIR_SWE        0x00000040	/* Stop Watch Event */
  #define FDCAN_TTIR_GTW        0x00000080	/* Global Time Wrap */
  #define FDCAN_TTIR_GTD        0x00000100	/* Global Time Discontinuity */
  #define FDCAN_TTIR_GTE        0x00000200	/* Global Time Error */
  #define FDCAN_TTIR_TXU        0x00000400	/* Tx Count Underflow */
  #define FDCAN_TTIR_TXO        0x00000800	/* Tx Count Overflow */
  #define FDCAN_TTIR_SE1        0x00001000	/* Scheduling Error 1 */
  #define FDCAN_TTIR_SE2        0x00002000	/* Scheduling Error 2 */
  #define FDCAN_TTIR_ELC        0x00004000	/* Error Level Changed */
  #define FDCAN_TTIR_IWT        0x00008000	/* Initialization Watch Trigger */
  #define FDCAN_TTIR_WT         0x00010000	/* Watch Trigger */
  #define FDCAN_TTIR_AW         0x00020000	/* Application Watchdog */
  #define FDCAN_TTIR_CER        0x00040000	/* Configuration Error */
#define TOFF_FDCAN_TTIE     0x0124		/* (RW) TT Interrupt Enable register */
  #define FDCAN_TTIE_SBCE       0x00000001	/* Start of Basic Cycle Interrupt Enable */
  #define FDCAN_TTIE_SMCE       0x00000002	/* Start of Matrix Cycle Interrupt Enable */
  #define FDCAN_TTIE_CSME       0x00000004	/* Change of Synchronization Mode Interrupt Enable */
  #define FDCAN_TTIE_SOGE       0x00000008	/* Start of Gap Interrupt Enable */
  #define FDCAN_TTIE_RTMIE      0x00000010	/* Register Time Mark Interrupt Interrupt Enable */
  #define FDCAN_TTIE_TTMIE      0x00000020	/* Trigger Time Mark Event Internal Interrupt Enable */
  #define FDCAN_TTIE_SWEE       0x00000040	/* Stop Watch Event Interrupt Enable */
  #define FDCAN_TTIE_GTWE       0x00000080	/* Global Time Wrap Interrupt Enable */
  #define FDCAN_TTIE_GTDE       0x00000100	/* Global Time Discontinuity Interrupt Enable */
  #define FDCAN_TTIE_GTEE       0x00000200	/* Global Time Error Interrupt Enable */
  #define FDCAN_TTIE_TXUE       0x00000400	/* Tx Count Underflow Interrupt Enable */
  #define FDCAN_TTIE_TXOE       0x00000800	/* Tx Count Overflow Interrupt Enable */
  #define FDCAN_TTIE_SE1E       0x00001000	/* Scheduling Error 1 Interrupt Enable */
  #define FDCAN_TTIE_SE2E       0x00002000	/* Scheduling Error 2 Interrupt Enable */
  #define FDCAN_TTIE_ELCE       0x00004000	/* Error Level Changed Interrupt Enable */
  #define FDCAN_TTIE_IWTE       0x00008000	/* Initialization Watch Trigger Interrupt Enable */
  #define FDCAN_TTIE_WTE        0x00010000	/* Watch Trigger Interrupt Enable */
  #define FDCAN_TTIE_AWE        0x00020000	/* Application Watchdog Interrupt Enable */
  #define FDCAN_TTIE_CERE       0x00040000	/* Configuration Error Interrupt Enable */
#define TOFF_FDCAN_TTILS    0x0128		/* (RW) TT Interrupt Line Select register */
  #define FDCAN_TTILS_SBCS      0x00000001	/* Start of Basic Cycle Interrupt Line */
  #define FDCAN_TTILS_SMCS      0x00000002	/* Start of Matrix Cycle Interrupt Line */
  #define FDCAN_TTILS_CSMS      0x00000004	/* Change of Synchronization Mode Interrupt Line */
  #define FDCAN_TTILS_SOGS      0x00000008	/* Start of Gap Interrupt Line */
  #define FDCAN_TTILS_RTMIS     0x00000010	/* Register Time Mark Interrupt Interrupt Line */
  #define FDCAN_TTILS_TTMIS     0x00000020	/* Trigger Time Mark Event Internal Interrupt Line */
  #define FDCAN_TTILS_SWES      0x00000040	/* Stop Watch Event Interrupt Line */
  #define FDCAN_TTILS_GTWS      0x00000080	/* Global Time Wrap Interrupt Line */
  #define FDCAN_TTILS_GTDS      0x00000100	/* Global Time Discontinuity Interrupt Line */
  #define FDCAN_TTILS_GTES      0x00000200	/* Global Time Error Interrupt Line */
  #define FDCAN_TTILS_TXUS      0x00000400	/* Tx Count Underflow Interrupt Line */
  #define FDCAN_TTILS_TXOS      0x00000800	/* Tx Count Overflow Interrupt Line */
  #define FDCAN_TTILS_SE1S      0x00001000	/* Scheduling Error 1 Interrupt Line */
  #define FDCAN_TTILS_SE2S      0x00002000	/* Scheduling Error 2 Interrupt Line */
  #define FDCAN_TTILS_ELCS      0x00004000	/* Error Level Changed Interrupt Line */
  #define FDCAN_TTILS_IWTS      0x00008000	/* Initialization Watch Trigger Interrupt Line */
  #define FDCAN_TTILS_WTS       0x00010000	/* Watch Trigger Interrupt Line */
  #define FDCAN_TTILS_AWS       0x00020000	/* Application Watchdog Interrupt Line */
  #define FDCAN_TTILS_CERS      0x00040000	/* Configuration Error Interrupt Line */
#define TOFF_FDCAN_TTOST    0x012C		/* (RW) TT Operation Status register */
  #define FDCAN_TTOST_EL        0x00000003	/* Error Level */
  #define FDCAN_TTOST_MS        0x0000000C	/* Master State */
  #define FDCAN_TTOST_SYS       0x00000030	/* Synchronization State */
  #define FDCAN_TTOST_QGTP      0x00000040	/* Quality of Global Time Phase */
  #define FDCAN_TTOST_QCS       0x00000080	/* Quality of Clock Speed */
  #define FDCAN_TTOST_RTO       0x0000FF00	/* Reference Trigger Offset */
  #define FDCAN_TTOST_WGTD      0x00400000	/* Wait for Global Time Discontinuity */
  #define FDCAN_TTOST_GFI       0x00800000	/* Gap Finished Indicator */
  #define FDCAN_TTOST_TMP       0x07000000	/* Time Master Priority */
  #define FDCAN_TTOST_GSI       0x08000000	/* Gap Started Indicator */
  #define FDCAN_TTOST_WFE       0x10000000	/* Wait for Event */
  #define FDCAN_TTOST_AWE       0x20000000	/* Application Watchdog Event */
  #define FDCAN_TTOST_WECS      0x40000000	/* Wait for External Clock Synchronization  */
  #define FDCAN_TTOST_SPL       0x80000000	/* Schedule Phase Lock */
#define TOFF_FDCAN_TURNA    0x0130		/* (RW) TT TUR Numerator Actual register */
  #define FDCAN_TURNA_NAV       0x0003FFFF	/* Numerator Actual Value */
#define TOFF_FDCAN_TTLGT    0x0134		/* (RW) TT Local and Global Time register */
  #define FDCAN_TTLGT_LT        0x0000FFFF	/* Local Time */
  #define FDCAN_TTLGT_GT        0xFFFF0000	/* Global Time */
#define TOFF_FDCAN_TTCTC    0x0138		/* (RW) TT Cycle Time and Count register */
  #define FDCAN_TTCTC_CT        0x0000FFFF	/* Cycle Time */
  #define FDCAN_TTCTC_CC        0x003F0000	/* Cycle Count */
#define TOFF_FDCAN_TTCPT    0x013C		/* (RW) TT Capture Time register */
  #define FDCAN_TTCPT_CCV       0x0000003F	/* Cycle Count Value */
  #define FDCAN_TTCPT_SWV       0xFFFF0000	/* Stop Watch Value */
#define TOFF_FDCAN_TTCSM    0x0140		/* (RW) TT Cycle Sync Mark register */
  #define FDCAN_TTCSM_CSM       0x0000FFFF	/* Cycle Sync Mark */
#define TOFF_FDCAN_TTTS     0x0300		/* (RW) TT Trigger Select register */
  #define FDCAN_TTTS_SWTSEL     0x00000003	/* Stop watch trigger input selection */
  #define FDCAN_TTTS_EVTSEL     0x00000030	/* Event trigger input selection */

#define TADR_FDCAN_CCU_BASE (MCU_APB2_PERIPH_BASE + 0x10000)
#define TOFF_FDCANCCU_CREL  0x0000		/* (RW) Clock Calibration Unit Core Release register */
  #define FDCANCCU_CREL_DAY     0x000000FF	/* Timestamp Day */
  #define FDCANCCU_CREL_MON     0x0000FF00	/* Timestamp Month */
  #define FDCANCCU_CREL_YEAR    0x000F0000	/* Timestamp Year */
  #define FDCANCCU_CREL_SUBSTEP 0x00F00000	/* Sub-step of Core release */
  #define FDCANCCU_CREL_STEP    0x0F000000	/* Step of Core release */
  #define FDCANCCU_CREL_REL     0xF0000000	/* Core release */
#define TOFF_FDCANCCU_CCFG  0x0004		/* (RW) Calibration Configuration register */
  #define FDCANCCU_CCFG_TQBT    0x0000001F	/* Time Quanta per Bit Time */
  #define FDCANCCU_CCFG_BCC     0x00000040	/* Bypass Clock Calibration */
  #define FDCANCCU_CCFG_CFL     0x00000080	/* Calibration Field Length */
  #define FDCANCCU_CCFG_OCPM    0x0000FF00	/* Oscillator Clock Periods Minimum */
  #define FDCANCCU_CCFG_CDIV    0x000F0000	/* Clock Divider */
  #define FDCANCCU_CCFG_SWR     0x80000000	/* Software Reset */
#define TOFF_FDCANCCU_CSTAT 0x0008		/* (RW) Calibration Status register */
  #define FDCANCCU_CSTAT_OCPC   0x0003FFFF	/* Oscillator Clock Period Counter */
  #define FDCANCCU_CSTAT_TQC    0x1FFC0000	/* Time Quanta Counter */
  #define FDCANCCU_CSTAT_CALS   0xC0000000	/* Calibration State */
#define TOFF_FDCANCCU_CWD   0x000C		/* (RW) Calibration Watchdog register */
  #define FDCANCCU_CWD_WDC      0x0000FFFF	/* Watchdog Configuration */
  #define FDCANCCU_CWD_WDV      0xFFFF0000	/* Watchdog Value */
#define TOFF_FDCANCCU_IR    0x0010		/* (RW) CCU Interrupt register */
  #define FDCANCCU_IR_CWE       0x00000001	/* Calibration Watchdog Event */
  #define FDCANCCU_IR_CSC       0x00000002	/* Calibration State Changed */
#define TOFF_FDCANCCU_IE    0x0014		/* (RW) CCU Interrupt Enable register */
  #define FDCANCCU_IE_CWEE      0x00000001	/* Calibration Watchdog Event Enable */
  #define FDCANCCU_IE_CSCE      0x00000002	/* Calibration State Changed Enable */

#define SRAMCAN_BASE        (MCU_APB2_PERIPH_BASE + 0x11000)


/* 
 *  DMA CONTROLLER
 */
#define TADR_DMA1_BASE      (MCU_AHB2_PERIPH_BASE + 0x0000)
#define TADR_DMA2_BASE      (MCU_AHB2_PERIPH_BASE + 0x1000)
#define TOFF_DMAI_LISR      0x0000		/* (RW) DMA low interrupt status register */
  #define DMA_LISR_FEIF0        0x00000001
  #define DMA_LISR_DMEIF0       0x00000004
  #define DMA_LISR_TEIF0        0x00000008
  #define DMA_LISR_HTIF0        0x00000010
  #define DMA_LISR_TCIF0        0x00000020
  #define DMA_LISR_FEIF1        0x00000040
  #define DMA_LISR_DMEIF1       0x00000100
  #define DMA_LISR_TEIF1        0x00000200
  #define DMA_LISR_HTIF1        0x00000400
  #define DMA_LISR_TCIF1        0x00000800
  #define DMA_LISR_FEIF2        0x00010000
  #define DMA_LISR_DMEIF2       0x00040000
  #define DMA_LISR_TEIF2        0x00080000
  #define DMA_LISR_HTIF2        0x00100000
  #define DMA_LISR_TCIF2        0x00200000
  #define DMA_LISR_FEIF3        0x00400000
  #define DMA_LISR_DMEIF3       0x01000000
  #define DMA_LISR_TEIF3        0x02000000
  #define DMA_LISR_HTIF3        0x04000000
  #define DMA_LISR_TCIF3        0x08000000
#define TOFF_DMAI_HISR      0x0004		/* (RW) DMA high interrupt status register */
  #define DMA_HISR_FEIF4        0x00000001
  #define DMA_HISR_DMEIF4       0x00000004
  #define DMA_HISR_TEIF4        0x00000008
  #define DMA_HISR_HTIF4        0x00000010
  #define DMA_HISR_TCIF4        0x00000020
  #define DMA_HISR_FEIF5        0x00000040
  #define DMA_HISR_DMEIF5       0x00000100
  #define DMA_HISR_TEIF5        0x00000200
  #define DMA_HISR_HTIF5        0x00000400
  #define DMA_HISR_TCIF5        0x00000800
  #define DMA_HISR_FEIF6        0x00010000
  #define DMA_HISR_DMEIF6       0x00040000
  #define DMA_HISR_TEIF6        0x00080000
  #define DMA_HISR_HTIF6        0x00100000
  #define DMA_HISR_TCIF6        0x00200000
  #define DMA_HISR_FEIF7        0x00400000
  #define DMA_HISR_DMEIF7       0x01000000
  #define DMA_HISR_TEIF7        0x02000000
  #define DMA_HISR_HTIF7        0x04000000
  #define DMA_HISR_TCIF7        0x08000000
#define TOFF_DMAI_LIFCR     0x0008		/* (RW) DMA low interrupt flag clear register */
  #define DMA_LIFCR_CFEIF0      0x00000001
  #define DMA_LIFCR_CDMEIF0     0x00000004
  #define DMA_LIFCR_CTEIF0      0x00000008
  #define DMA_LIFCR_CHTIF0      0x00000010
  #define DMA_LIFCR_CTCIF0      0x00000020
  #define DMA_LIFCR_CFEIF1      0x00000040
  #define DMA_LIFCR_CDMEIF1     0x00000100
  #define DMA_LIFCR_CTEIF1      0x00000200
  #define DMA_LIFCR_CHTIF1      0x00000400
  #define DMA_LIFCR_CTCIF1      0x00000800
  #define DMA_LIFCR_CFEIF2      0x00010000
  #define DMA_LIFCR_CDMEIF2     0x00040000
  #define DMA_LIFCR_CTEIF2      0x00080000
  #define DMA_LIFCR_CHTIF2      0x00100000
  #define DMA_LIFCR_CTCIF2      0x00200000
  #define DMA_LIFCR_CFEIF3      0x00400000
  #define DMA_LIFCR_CDMEIF3     0x01000000
  #define DMA_LIFCR_CTEIF3      0x02000000
  #define DMA_LIFCR_CHTIF3      0x04000000
  #define DMA_LIFCR_CTCIF3      0x08000000
#define TOFF_DMAI_HIFCR     0x000C		/* (RW) DMA high interrupt flag clear register */
  #define DMA_HIFCR_CFEIF4      0x00000001
  #define DMA_HIFCR_CDMEIF4     0x00000004
  #define DMA_HIFCR_CTEIF4      0x00000008
  #define DMA_HIFCR_CHTIF4      0x00000010
  #define DMA_HIFCR_CTCIF4      0x00000020
  #define DMA_HIFCR_CFEIF5      0x00000040
  #define DMA_HIFCR_CDMEIF5     0x00000100
  #define DMA_HIFCR_CTEIF5      0x00000200
  #define DMA_HIFCR_CHTIF5      0x00000400
  #define DMA_HIFCR_CTCIF5      0x00000800
  #define DMA_HIFCR_CFEIF6      0x00010000
  #define DMA_HIFCR_CDMEIF6     0x00040000
  #define DMA_HIFCR_CTEIF6      0x00080000
  #define DMA_HIFCR_CHTIF6      0x00100000
  #define DMA_HIFCR_CTCIF6      0x00200000
  #define DMA_HIFCR_CFEIF7      0x00400000
  #define DMA_HIFCR_CDMEIF7     0x01000000
  #define DMA_HIFCR_CTEIF7      0x02000000
  #define DMA_HIFCR_CHTIF7      0x04000000
  #define DMA_HIFCR_CTCIF7      0x08000000
#define TOFF_DMAI_HWCFGR2   0x03EC		/* (R)  DMA HW Configuration register 2 */
  #define DMA_HWCFGR2_FIFO_SIZE        0x00000003	/* FIFO size, common to all streams*/
  #define DMA_HWCFGR2_WRITE_BUFFERABLE 0x00000010	/* Write bufferable*/
  #define DMA_HWCFGR2_CHSEL_WIDTH      0x00000700	/* width of the CHSEL field */
#define TOFF_DMAI_HWCFGR1   0x03F0		/* (R)  DMA HW Configuration register 1 */
  #define DMA_HWCFGR1_DMA_DEF0  0x00000003	/* Type of the stream 0 */
  #define DMA_HWCFGR1_DMA_DEF1  0x00000030	/* Type of the stream 1 */
  #define DMA_HWCFGR1_DMA_DEF2  0x00000300	/* Type of the stream 2 */
  #define DMA_HWCFGR1_DMA_DEF3  0x00003000	/* Type of the stream 3 */
  #define DMA_HWCFGR1_DMA_DEF4  0x00030000	/* Type of the stream 4 */
  #define DMA_HWCFGR1_DMA_DEF5  0x00300000	/* Type of the stream 5 */
  #define DMA_HWCFGR1_DMA_DEF6  0x03000000	/* Type of the stream 6 */
  #define DMA_HWCFGR1_DMA_DEF7  0x30000000	/* Type of the stream 7 */
#define TOFF_DMAI_VERR      0x03F4		/* (R)  DMA Version register */
  #define DMA_VERR_MINREV       0x0000000F	/* Minor Revision number */
  #define DMA_VERR_MAJREV       0x000000F0	/* Major Revision number */
#define TOFF_DMAI_IPDR      0x03F8		/* (R)  DMA Identification register */
#define TOFF_DMAI_SIDR      0x03FC		/* (R)  DMA Size Identification register */

#define TADR_DMA1_STM0_BASE (TADR_DMA1_BASE + 0x010)
#define TADR_DMA1_STM1_BASE (TADR_DMA1_BASE + 0x028)
#define TADR_DMA1_STM2_BASE (TADR_DMA1_BASE + 0x040)
#define TADR_DMA1_STM3_BASE (TADR_DMA1_BASE + 0x058)
#define TADR_DMA1_STM4_BASE (TADR_DMA1_BASE + 0x070)
#define TADR_DMA1_STM5_BASE (TADR_DMA1_BASE + 0x088)
#define TADR_DMA1_STM6_BASE (TADR_DMA1_BASE + 0x0A0)
#define TADR_DMA1_STM7_BASE (TADR_DMA1_BASE + 0x0B8)
#define TADR_DMA2_STM0_BASE (TADR_DMA2_BASE + 0x010)
#define TADR_DMA2_STM1_BASE (TADR_DMA2_BASE + 0x028)
#define TADR_DMA2_STM2_BASE (TADR_DMA2_BASE + 0x040)
#define TADR_DMA2_STM3_BASE (TADR_DMA2_BASE + 0x058)
#define TADR_DMA2_STM4_BASE (TADR_DMA2_BASE + 0x070)
#define TADR_DMA2_STM5_BASE (TADR_DMA2_BASE + 0x088)
#define TADR_DMA2_STM6_BASE (TADR_DMA2_BASE + 0x0A0)
#define TADR_DMA2_STM7_BASE (TADR_DMA2_BASE + 0x0B8)
#define TOFF_DMAS_CR        0x0000		/* (RW) DMA stream x configuration register      */
  #define DMA_SxCR_EN           0x00000001
  #define DMA_SxCR_DMEIE        0x00000002
  #define DMA_SxCR_TEIE         0x00000004
  #define DMA_SxCR_HTIE         0x00000008
  #define DMA_SxCR_TCIE         0x00000010
  #define DMA_SxCR_PFCTRL       0x00000020
  #define DMA_SxCR_DIR          0x000000C0
  #define DMA_SxCR_DIR_0        0x00000040
  #define DMA_SxCR_DIR_1        0x00000080
  #define DMA_SxCR_CIRC         0x00000100
  #define DMA_SxCR_PINC         0x00000200
  #define DMA_SxCR_MINC         0x00000400
  #define DMA_SxCR_PSIZE        0x00001800
  #define DMA_SxCR_PSIZE_0      0x00000800
  #define DMA_SxCR_PSIZE_1      0x00001000
  #define DMA_SxCR_MSIZE        0x00006000
  #define DMA_SxCR_MSIZE_0      0x00002000
  #define DMA_SxCR_MSIZE_1      0x00004000
  #define DMA_SxCR_PINCOS       0x00008000
  #define DMA_SxCR_PL           0x00030000
  #define DMA_SxCR_PL_0         0x00010000
  #define DMA_SxCR_PL_1         0x00020000
  #define DMA_SxCR_DBM          0x00040000
  #define DMA_SxCR_CT           0x00080000
  #define DMA_SxCR_ACK          0x00100000
  #define DMA_SxCR_PBURST       0x00600000
  #define DMA_SxCR_PBURST_0     0x00200000
  #define DMA_SxCR_PBURST_1     0x00400000
  #define DMA_SxCR_MBURST       0x01800000
  #define DMA_SxCR_MBURST_0     0x00800000
  #define DMA_SxCR_MBURST_1     0x01000000
#define TOFF_DMAS_NDTR      0x0004		/* (RW) DMA stream x number of data register     */
  #define DMA_SxNDT             0x0000FFFF
  #define DMA_SxNDT_0           0x00000001
  #define DMA_SxNDT_1           0x00000002
  #define DMA_SxNDT_2           0x00000004
  #define DMA_SxNDT_3           0x00000008
  #define DMA_SxNDT_4           0x00000010
  #define DMA_SxNDT_5           0x00000020
  #define DMA_SxNDT_6           0x00000040
  #define DMA_SxNDT_7           0x00000080
  #define DMA_SxNDT_8           0x00000100
  #define DMA_SxNDT_9           0x00000200
  #define DMA_SxNDT_10          0x00000400
  #define DMA_SxNDT_11          0x00000800
  #define DMA_SxNDT_12          0x00001000
  #define DMA_SxNDT_13          0x00002000
  #define DMA_SxNDT_14          0x00004000
  #define DMA_SxNDT_15          0x00008000
#define TOFF_DMAS_PAR       0x0008		/* (RW) DMA stream x peripheral address register */
#define TOFF_DMAS_M0AR      0x000C		/* (RW) DMA stream x memory 0 address register   */
#define TOFF_DMAS_M1AR      0x0010		/* (RW) DMA stream x memory 1 address register   */
#define TOFF_DMAS_FCR       0x0014		/* (RW) DMA stream x FIFO control register       */
  #define DMA_SxFCR_FTH         0x00000003
  #define DMA_SxFCR_FTH_0       0x00000001
  #define DMA_SxFCR_FTH_1       0x00000002
  #define DMA_SxFCR_DMDIS       0x00000004
  #define DMA_SxFCR_FS          0x00000038
  #define DMA_SxFCR_FS_0        0x00000008
  #define DMA_SxFCR_FS_1        0x00000010
  #define DMA_SxFCR_FS_2        0x00000020
  #define DMA_SxFCR_FEIE        0x00000080

/*
 *  DMAMUTEX
 */
#define TADR_DMAMUX1_BASE   (MCU_AHB2_PERIPH_BASE + 0x2000)
#define TOFF_DMAMUX_CHANNEL_CCR     0x0000
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
#define TOFF_DMAMUX_REQUEST_GENSTS_HWCFGR2 0x03EC
#define TOFF_DMAMUX_REQUEST_GENSTS_HWCFGR1 0x03F0
#define TOFF_DMAMUX_REQUEST_GENSTS_VERR    0x03F4
  #define DMAMUX_VERR_MINREV        0x0000000F	/* Minor Revision number */
  #define DMAMUX_VERR_MAJREV        0x000000F0	/* Major Revision number */
#define TOFF_DMAMUX_REQUEST_GENSTS_IPDR    0x03F8
#define TOFF_DMAMUX_REQUEST_GENSTS_SIDR    0x03FC


/*
 *  ANALOG TO DIGITAL CONVERTER
 */
#define TADR_ADC1_BASE      (MCU_AHB2_PERIPH_BASE + 0x3000)
#define TADR_ADC2_BASE      (MCU_AHB2_PERIPH_BASE + 0x3100)

#define TOFF_ADC_ISR        0x0000		/* (RW) ADC Interrupt and Status Register */
  #define ADC_ISR_ADRDY         0x00000001	/* ADC Ready (ADRDY) flag  */
  #define ADC_ISR_EOSMP         0x00000002	/* ADC End of Sampling flag */
  #define ADC_ISR_EOC           0x00000004	/* ADC End of Regular Conversion flag */
  #define ADC_ISR_EOS           0x00000008	/* ADC End of Regular sequence of Conversions flag */
  #define ADC_ISR_OVR           0x00000010	/* ADC overrun flag */
  #define ADC_ISR_JEOC          0x00000020	/* ADC End of Injected Conversion flag */
  #define ADC_ISR_JEOS          0x00000040	/* ADC End of Injected sequence of Conversions flag */
  #define ADC_ISR_AWD1          0x00000080	/* ADC Analog watchdog 1 flag */
  #define ADC_ISR_AWD2          0x00000100	/* ADC Analog watchdog 2 flag */
  #define ADC_ISR_AWD3          0x00000200	/* ADC Analog watchdog 3 flag */
  #define ADC_ISR_JQOVF         0x00000400	/* ADC Injected Context Queue Overflow flag */
#define TOFF_ADC_IER        0x0004		/* (RW) ADC Interrupt Enable Register */
  #define ADC_IER_ADRDYIE       0x00000001	/* ADC Ready (ADRDY) interrupt source */
  #define ADC_IER_EOSMPIE       0x00000002	/* ADC End of Sampling interrupt source */
  #define ADC_IER_EOCIE         0x00000004	/* ADC End of Regular Conversion interrupt source */
  #define ADC_IER_EOSIE         0x00000008	/* ADC End of Regular sequence of Conversions interrupt source */
  #define ADC_IER_OVRIE         0x00000010	/* ADC overrun interrupt source */
  #define ADC_IER_JEOCIE        0x00000020	/* ADC End of Injected Conversion interrupt source */
  #define ADC_IER_JEOSIE        0x00000040	/* ADC End of Injected sequence of Conversions interrupt source */
  #define ADC_IER_AWD1IE        0x00000080	/* ADC Analog watchdog 1 interrupt source */
  #define ADC_IER_AWD2IE        0x00000100	/* ADC Analog watchdog 2 interrupt source */
  #define ADC_IER_AWD3IE        0x00000200	/* ADC Analog watchdog 3 interrupt source */
  #define ADC_IER_JQOVFIE       0x00000400	/* ADC Injected Context Queue Overflow interrupt source */
#define TOFF_ADC_CR         0x0008		/* (RW) ADC control register */
  #define ADC_CR_ADEN           0x00000001	/* ADC Enable control */
  #define ADC_CR_ADDIS          0x00000002	/* ADC Disable command */
  #define ADC_CR_ADSTART        0x00000004	/* ADC Start of Regular conversion */
  #define ADC_CR_JADSTART       0x00000008	/* ADC Start of injected conversion */
  #define ADC_CR_ADSTP          0x00000010	/* ADC Stop of Regular conversion */
  #define ADC_CR_JADSTP         0x00000020	/* ADC Stop of injected conversion */
  #define ADC_CR_BOOST          0x00000100	/* ADC Boost Mode */
  #define ADC_CR_ADCALLIN       0x00010000	/* ADC Linearity calibration */
  #define ADC_CR_LINCALRDYW1    0x00400000	/* ADC Linearity calibration ready Word 1 */
  #define ADC_CR_LINCALRDYW2    0x00800000	/* ADC Linearity calibration ready Word 2 */
  #define ADC_CR_LINCALRDYW3    0x01000000	/* ADC Linearity calibration ready Word 3 */
  #define ADC_CR_LINCALRDYW4    0x02000000	/* ADC Linearity calibration ready Word 4 */
  #define ADC_CR_LINCALRDYW5    0x04000000	/* ADC Linearity calibration ready Word 5 */
  #define ADC_CR_LINCALRDYW6    0x08000000	/* ADC Linearity calibration ready Word 6 */
  #define ADC_CR_ADVREGEN       0x10000000	/* ADC Voltage regulator Enable */
  #define ADC_CR_DEEPPWD        0x20000000	/* ADC Deep power down Enable */
  #define ADC_CR_ADCALDIF       0x40000000	/* ADC Differential Mode for calibration */
  #define ADC_CR_ADCAL          0x80000000	/* ADC Calibration */
#define TOFF_ADC_CFGR       0x000C		/* (RW) ADC Configuration register */
  #define ADC_CFGR_DMNGT        0x00000003	/* ADC Data Management configuration */
  #define ADC_CFGR_DMNGT_0      0x00000001
  #define ADC_CFGR_DMNGT_1      0x00000002
  #define ADC_CFGR_RES          0x0000001C	/* ADC Data resolution */
  #define ADC_CFGR_RES_0        0x00000004
  #define ADC_CFGR_RES_1        0x00000008
  #define ADC_CFGR_RES_2        0x00000010
  #define ADC_CFGR_EXTSEL       0x000003E0	/* ADC External trigger selection for regular group */
  #define ADC_CFGR_EXTSEL_0     0x00000020
  #define ADC_CFGR_EXTSEL_1     0x00000040
  #define ADC_CFGR_EXTSEL_2     0x00000080
  #define ADC_CFGR_EXTSEL_3     0x00000100
  #define ADC_CFGR_EXTSEL_4     0x00000200
  #define ADC_CFGR_EXTEN        0x00000C00	/* ADC External trigger enable and polarity selection for regular channels */
  #define ADC_CFGR_EXTEN_0      0x00000400
  #define ADC_CFGR_EXTEN_1      0x00000800
  #define ADC_CFGR_OVRMOD       0x00001000	/* ADC overrun mode */
  #define ADC_CFGR_CONT         0x00002000	/* ADC Single/continuous conversion mode for regular conversion */
  #define ADC_CFGR_AUTDLY       0x00004000	/* ADC Delayed conversion mode */
  #define ADC_CFGR_DISCEN       0x00010000	/* ADC Discontinuous mode for regular channels */
  #define ADC_CFGR_DISCNUM      0x000E0000	/* ADC Discontinuous mode channel count */
  #define ADC_CFGR_DISCNUM_0    0x00020000
  #define ADC_CFGR_DISCNUM_1    0x00040000
  #define ADC_CFGR_DISCNUM_2    0x00080000
  #define ADC_CFGR_JDISCEN      0x00100000	/* ADC Discontinuous mode on injected channels */
  #define ADC_CFGR_JQM          0x00200000	/* ADC JSQR Queue mode */
  #define ADC_CFGR_AWD1SGL      0x00400000	/* Enable the watchdog 1 on a single channel or on all channels */
  #define ADC_CFGR_AWD1EN       0x00800000	/* ADC Analog watchdog 1 enable on regular Channels */
  #define ADC_CFGR_JAWD1EN      0x01000000	/* ADC Analog watchdog 1 enable on injected Channels */
  #define ADC_CFGR_JAUTO        0x02000000	/* ADC Automatic injected group conversion */
  #define ADC_CFGR_AWD1CH       0x7C000000	/* ADC Analog watchdog 1 Channel selection */
  #define ADC_CFGR_AWD1CH_0     0x04000000
  #define ADC_CFGR_AWD1CH_1     0x08000000
  #define ADC_CFGR_AWD1CH_2     0x10000000
  #define ADC_CFGR_AWD1CH_3     0x20000000
  #define ADC_CFGR_AWD1CH_4     0x40000000
  #define ADC_CFGR_JQDIS        0x80000000	/* ADC Injected queue disable */
#define TOFF_ADC_CFGR2      0x0010		/* (RW) ADC Configuration register 2 */
  #define ADC_CFGR2_ROVSE       0x00000001	/* ADC Regular group oversampler enable */
  #define ADC_CFGR2_JOVSE       0x00000002	/* ADC Injected group oversampler enable */
  #define ADC_CFGR2_OVSR        0x0000001C	/* ADC Regular group oversampler enable TO Be removed after ADC driver update*/
  #define ADC_CFGR2_OVSR_0      0x00000004
  #define ADC_CFGR2_OVSR_1      0x00000008
  #define ADC_CFGR2_OVSR_2      0x00000010
  #define ADC_CFGR2_OVSS        0x000001E0	/* ADC Regular Oversampling shift */
  #define ADC_CFGR2_OVSS_0      0x00000020
  #define ADC_CFGR2_OVSS_1      0x00000040
  #define ADC_CFGR2_OVSS_2      0x00000080
  #define ADC_CFGR2_OVSS_3      0x00000100
  #define ADC_CFGR2_TROVS       0x00000200	/* ADC Triggered regular Oversampling */
  #define ADC_CFGR2_ROVSM       0x00000400	/* ADC Regular oversampling mode */
  #define ADC_CFGR2_RSHIFT1     0x00000800	/* ADC Right-shift data after Offset 1 correction */
  #define ADC_CFGR2_RSHIFT2     0x00001000	/* ADC Right-shift data after Offset 2 correction */
  #define ADC_CFGR2_RSHIFT3     0x00002000	/* ADC Right-shift data after Offset 3 correction */
  #define ADC_CFGR2_RSHIFT4     0x00004000	/* ADC Right-shift data after Offset 4 correction */
  #define ADC_CFGR2_OSR         0x03FF0000	/* ADC oversampling Ratio */
  #define ADC_CFGR2_OSR_0       0x00010000
  #define ADC_CFGR2_OSR_1       0x00020000
  #define ADC_CFGR2_OSR_2       0x00040000
  #define ADC_CFGR2_OSR_3       0x00080000
  #define ADC_CFGR2_OSR_4       0x00100000
  #define ADC_CFGR2_OSR_5       0x00200000
  #define ADC_CFGR2_OSR_6       0x00400000
  #define ADC_CFGR2_OSR_7       0x00800000
  #define ADC_CFGR2_OSR_8       0x01000000
  #define ADC_CFGR2_OSR_9       0x02000000
  #define ADC_CFGR2_LSHIFT      0xF0000000	/* ADC Left shift factor */
  #define ADC_CFGR2_LSHIFT_0    0x10000000
  #define ADC_CFGR2_LSHIFT_1    0x20000000
  #define ADC_CFGR2_LSHIFT_2    0x40000000
  #define ADC_CFGR2_LSHIFT_3    0x80000000
#define TOFF_ADC_SMPR1      0x0014		/* (RW) ADC sample time register 1 */
  #define ADC_SMPR1_SMP0        0x00000007	/* ADC Channel 0 Sampling time selection  */
  #define ADC_SMPR1_SMP0_0      0x00000001
  #define ADC_SMPR1_SMP0_1      0x00000002
  #define ADC_SMPR1_SMP0_2      0x00000004
  #define ADC_SMPR1_SMP1        0x00000038	/* ADC Channel 1 Sampling time selection  */
  #define ADC_SMPR1_SMP1_0      0x00000008
  #define ADC_SMPR1_SMP1_1      0x00000010
  #define ADC_SMPR1_SMP1_2      0x00000020
  #define ADC_SMPR1_SMP2        0x000001C0	/* ADC Channel 2 Sampling time selection  */
  #define ADC_SMPR1_SMP2_0      0x00000040
  #define ADC_SMPR1_SMP2_1      0x00000080
  #define ADC_SMPR1_SMP2_2      0x00000100
  #define ADC_SMPR1_SMP3        0x00000E00	/* ADC Channel 3 Sampling time selection  */
  #define ADC_SMPR1_SMP3_0      0x00000200
  #define ADC_SMPR1_SMP3_1      0x00000400
  #define ADC_SMPR1_SMP3_2      0x00000800
  #define ADC_SMPR1_SMP4        0x00007000	/* ADC Channel 4 Sampling time selection  */
  #define ADC_SMPR1_SMP4_0      0x00001000
  #define ADC_SMPR1_SMP4_1      0x00002000
  #define ADC_SMPR1_SMP4_2      0x00004000
  #define ADC_SMPR1_SMP5        0x00038000	/* ADC Channel 5 Sampling time selection  */
  #define ADC_SMPR1_SMP5_0      0x00008000
  #define ADC_SMPR1_SMP5_1      0x00010000
  #define ADC_SMPR1_SMP5_2      0x00020000
  #define ADC_SMPR1_SMP6        0x001C0000	/* ADC Channel 6 Sampling time selection  */
  #define ADC_SMPR1_SMP6_0      0x00040000
  #define ADC_SMPR1_SMP6_1      0x00080000
  #define ADC_SMPR1_SMP6_2      0x00100000
  #define ADC_SMPR1_SMP7        0x00E00000	/* ADC Channel 7 Sampling time selection  */
  #define ADC_SMPR1_SMP7_0      0x00200000
  #define ADC_SMPR1_SMP7_1      0x00400000
  #define ADC_SMPR1_SMP7_2      0x00800000
  #define ADC_SMPR1_SMP8        0x07000000	/* ADC Channel 8 Sampling time selection  */
  #define ADC_SMPR1_SMP8_0      0x01000000
  #define ADC_SMPR1_SMP8_1      0x02000000
  #define ADC_SMPR1_SMP8_2      0x04000000
  #define ADC_SMPR1_SMP9        0x38000000	/* ADC Channel 9 Sampling time selection  */
  #define ADC_SMPR1_SMP9_0      0x08000000
  #define ADC_SMPR1_SMP9_1      0x10000000
  #define ADC_SMPR1_SMP9_2      0x20000000
#define TOFF_ADC_SMPR2      0x0018		/* (RW) ADC sample time register 2 */
  #define ADC_SMPR2_SMP10_Pos               (0U)
#define ADC_SMPR2_SMP10         0x00000007	/* ADC Channel 10 Sampling time selection  */
  #define ADC_SMPR2_SMP10_0     0x00000001
  #define ADC_SMPR2_SMP10_1     0x00000002
  #define ADC_SMPR2_SMP10_2     0x00000004
  #define ADC_SMPR2_SMP11       0x00000038 	/* ADC Channel 11 Sampling time selection  */
  #define ADC_SMPR2_SMP11_0     0x00000008
  #define ADC_SMPR2_SMP11_1     0x00000010
  #define ADC_SMPR2_SMP11_2     0x00000020
  #define ADC_SMPR2_SMP12       0x000001C0	/* ADC Channel 12 Sampling time selection  */
  #define ADC_SMPR2_SMP12_0     0x00000040
  #define ADC_SMPR2_SMP12_1     0x00000080
  #define ADC_SMPR2_SMP12_2     0x00000100
  #define ADC_SMPR2_SMP13       0x00000E00	/* ADC Channel 13 Sampling time selection  */
  #define ADC_SMPR2_SMP13_0     0x00000200
  #define ADC_SMPR2_SMP13_1     0x00000400
  #define ADC_SMPR2_SMP13_2     0x00000800
  #define ADC_SMPR2_SMP14       0x00007000	/* ADC Channel 14 Sampling time selection  */
  #define ADC_SMPR2_SMP14_0     0x00001000
  #define ADC_SMPR2_SMP14_1     0x00002000
  #define ADC_SMPR2_SMP14_2     0x00004000
  #define ADC_SMPR2_SMP15       0x00038000	/* ADC Channel 15 Sampling time selection  */
  #define ADC_SMPR2_SMP15_0     0x00008000
  #define ADC_SMPR2_SMP15_1     0x00010000
  #define ADC_SMPR2_SMP15_2     0x00020000
  #define ADC_SMPR2_SMP16       0x001C0000	/* ADC Channel 16 Sampling time selection  */
  #define ADC_SMPR2_SMP16_0     0x00040000
  #define ADC_SMPR2_SMP16_1     0x00080000
  #define ADC_SMPR2_SMP16_2     0x00100000
  #define ADC_SMPR2_SMP17       0x00E00000	/* ADC Channel 17 Sampling time selection  */
  #define ADC_SMPR2_SMP17_0     0x00200000
  #define ADC_SMPR2_SMP17_1     0x00400000
  #define ADC_SMPR2_SMP17_2     0x00800000
  #define ADC_SMPR2_SMP18       0x07000000	/* ADC Channel 18 Sampling time selection  */
  #define ADC_SMPR2_SMP18_0     0x01000000
  #define ADC_SMPR2_SMP18_1     0x02000000
  #define ADC_SMPR2_SMP18_2     0x04000000
  #define ADC_SMPR2_SMP19       0x38000000	/* ADC Channel 19 Sampling time selection  */
  #define ADC_SMPR2_SMP19_0     0x08000000
  #define ADC_SMPR2_SMP19_1     0x10000000
  #define ADC_SMPR2_SMP19_2     0x20000000
#define TOFF_ADC_PCSEL      0x001C		/* (RW) ADC pre-channel selection */
  #define ADC_PCSEL_PCSEL       0x000FFFFF	/* ADC pre channel selection */
  #define ADC_PCSEL_PCSEL_0     0x00000001
  #define ADC_PCSEL_PCSEL_1     0x00000002
  #define ADC_PCSEL_PCSEL_2     0x00000004
  #define ADC_PCSEL_PCSEL_3     0x00000008
  #define ADC_PCSEL_PCSEL_4     0x00000010
  #define ADC_PCSEL_PCSEL_5     0x00000020
  #define ADC_PCSEL_PCSEL_6     0x00000040
  #define ADC_PCSEL_PCSEL_7     0x00000080
  #define ADC_PCSEL_PCSEL_8     0x00000100
  #define ADC_PCSEL_PCSEL_9     0x00000200
  #define ADC_PCSEL_PCSEL_10    0x00000400
  #define ADC_PCSEL_PCSEL_11    0x00000800
  #define ADC_PCSEL_PCSEL_12    0x00001000
  #define ADC_PCSEL_PCSEL_13    0x00002000
  #define ADC_PCSEL_PCSEL_14    0x00004000
  #define ADC_PCSEL_PCSEL_15    0x00008000
  #define ADC_PCSEL_PCSEL_16    0x00010000
  #define ADC_PCSEL_PCSEL_17    0x00020000
  #define ADC_PCSEL_PCSEL_18    0x00040000
  #define ADC_PCSEL_PCSEL_19    0x00080000
#define TOFF_ADC_LTR1       0x0020		/* (RW) ADC watchdog Lower threshold register 1 */
  #define ADC_LTR1_LT1          0x03FFFFFF	/* ADC Analog watchdog 1 lower threshold */
  #define ADC_LTR1_LT1_0        0x00000001
  #define ADC_LTR1_LT1_1        0x00000002
  #define ADC_LTR1_LT1_2        0x00000004
  #define ADC_LTR1_LT1_3        0x00000008
  #define ADC_LTR1_LT1_4        0x00000010
  #define ADC_LTR1_LT1_5        0x00000020
  #define ADC_LTR1_LT1_6        0x00000040
  #define ADC_LTR1_LT1_7        0x00000080
  #define ADC_LTR1_LT1_8        0x00000100
  #define ADC_LTR1_LT1_9        0x00000200
  #define ADC_LTR1_LT1_10       0x00000400
  #define ADC_LTR1_LT1_11       0x00000800
  #define ADC_LTR1_LT1_12       0x00001000
  #define ADC_LTR1_LT1_13       0x00002000
  #define ADC_LTR1_LT1_14       0x00004000
  #define ADC_LTR1_LT1_15       0x00008000
  #define ADC_LTR1_LT1_16       0x00010000
  #define ADC_LTR1_LT1_17       0x00020000
  #define ADC_LTR1_LT1_18       0x00040000
  #define ADC_LTR1_LT1_19       0x00080000
  #define ADC_LTR1_LT1_20       0x00100000
  #define ADC_LTR1_LT1_21       0x00200000
  #define ADC_LTR1_LT1_22       0x00400000
  #define ADC_LTR1_LT1_23       0x00800000
  #define ADC_LTR1_LT1_24       0x01000000
  #define ADC_LTR1_LT1_25       0x02000000
#define TOFF_ADC_HTR1       0x0024		/* (RW) ADC watchdog higher threshold register 1 */
  #define ADC_HTR1_HT1          0x03FFFFFF	/* ADC Analog watchdog 1 higher threshold */
  #define ADC_HTR1_HT1_0        0x00000001	/* ADC HT1 bit 0 */
  #define ADC_HTR1_HT1_1        0x00000002	/* ADC HT1 bit 1 */
  #define ADC_HTR1_HT1_2        0x00000004	/* ADC HT1 bit 2 */
  #define ADC_HTR1_HT1_3        0x00000008	/* ADC HT1 bit 3 */
  #define ADC_HTR1_HT1_4        0x00000010	/* ADC HT1 bit 4 */
  #define ADC_HTR1_HT1_5        0x00000020	/* ADC HT1 bit 5 */
  #define ADC_HTR1_HT1_6        0x00000040	/* ADC HT1 bit 6 */
  #define ADC_HTR1_HT1_7        0x00000080	/* ADC HT1 bit 7 */
  #define ADC_HTR1_HT1_8        0x00000100	/* ADC HT1 bit 8 */
  #define ADC_HTR1_HT1_9        0x00000200	/* ADC HT1 bit 9 */
  #define ADC_HTR1_HT1_10       0x00000400	/* ADC HT1 bit 10 */
  #define ADC_HTR1_HT1_11       0x00000800	/* ADC HT1 bit 11 */
  #define ADC_HTR1_HT1_12       0x00001000	/* ADC HT1 bit 12 */
  #define ADC_HTR1_HT1_13       0x00002000	/* ADC HT1 bit 13 */
  #define ADC_HTR1_HT1_14       0x00004000	/* ADC HT1 bit 14 */
  #define ADC_HTR1_HT1_15       0x00008000	/* ADC HT1 bit 15 */
  #define ADC_HTR1_HT1_16       0x00010000	/* ADC HT1 bit 16 */
  #define ADC_HTR1_HT1_17       0x00020000	/* ADC HT1 bit 17 */
  #define ADC_HTR1_HT1_18       0x00040000	/* ADC HT1 bit 18 */
  #define ADC_HTR1_HT1_19       0x00080000	/* ADC HT1 bit 19 */
  #define ADC_HTR1_HT1_20       0x00100000	/* ADC HT1 bit 20 */
  #define ADC_HTR1_HT1_21       0x00200000	/* ADC HT1 bit 21 */
  #define ADC_HTR1_HT1_22       0x00400000	/* ADC HT1 bit 22 */
  #define ADC_HTR1_HT1_23       0x00800000	/* ADC HT1 bit 23 */
  #define ADC_HTR1_HT1_24       0x01000000	/* ADC HT1 bit 24 */
  #define ADC_HTR1_HT1_25       0x02000000	/* ADC HT1 bit 25 */
#define TOFF_ADC_SQR1       0x0030		/* (RW) ADC regular sequence register 1 */
  #define ADC_SQR1_L            0x0000000F	/* ADC regular channel sequence lenght */
  #define ADC_SQR1_L_0          0x00000001
  #define ADC_SQR1_L_1          0x00000002
  #define ADC_SQR1_L_2          0x00000004
  #define ADC_SQR1_L_3          0x00000008
  #define ADC_SQR1_SQ1          0x000007C0	/* ADC 1st conversion in regular sequence */
  #define ADC_SQR1_SQ1_0        0x00000040
  #define ADC_SQR1_SQ1_1        0x00000080
  #define ADC_SQR1_SQ1_2        0x00000100
  #define ADC_SQR1_SQ1_3        0x00000200
  #define ADC_SQR1_SQ1_4        0x00000400
  #define ADC_SQR1_SQ2          0x0001F000	/* ADC 2nd conversion in regular sequence */
  #define ADC_SQR1_SQ2_0        0x00001000
  #define ADC_SQR1_SQ2_1        0x00002000
  #define ADC_SQR1_SQ2_2        0x00004000
  #define ADC_SQR1_SQ2_3        0x00008000
  #define ADC_SQR1_SQ2_4        0x00010000
  #define ADC_SQR1_SQ3          0x007C0000	/* ADC 3rd conversion in regular sequence */
  #define ADC_SQR1_SQ3_0        0x00040000
  #define ADC_SQR1_SQ3_1        0x00080000
  #define ADC_SQR1_SQ3_2        0x00100000
  #define ADC_SQR1_SQ3_3        0x00200000
  #define ADC_SQR1_SQ3_4        0x00400000
  #define ADC_SQR1_SQ4          0x1F000000	/* ADC 4th conversion in regular sequence */
  #define ADC_SQR1_SQ4_0        0x01000000
  #define ADC_SQR1_SQ4_1        0x02000000
  #define ADC_SQR1_SQ4_2        0x04000000
  #define ADC_SQR1_SQ4_3        0x08000000
  #define ADC_SQR1_SQ4_4        0x10000000
#define TOFF_ADC_SQR2       0x0034		/* (RW) ADC regular sequence register 2 */
  #define ADC_SQR2_SQ5          0x0000001F	/* ADC 5th conversion in regular sequence */
  #define ADC_SQR2_SQ5_0        0x00000001
  #define ADC_SQR2_SQ5_1        0x00000002
  #define ADC_SQR2_SQ5_2        0x00000004
  #define ADC_SQR2_SQ5_3        0x00000008
  #define ADC_SQR2_SQ5_4        0x00000010
  #define ADC_SQR2_SQ6          0x000007C0	/* ADC 6th conversion in regular sequence */
  #define ADC_SQR2_SQ6_0        0x00000040
  #define ADC_SQR2_SQ6_1        0x00000080
  #define ADC_SQR2_SQ6_2        0x00000100
  #define ADC_SQR2_SQ6_3        0x00000200
  #define ADC_SQR2_SQ6_4        0x00000400
  #define ADC_SQR2_SQ7          0x0001F000	/* ADC 7th conversion in regular sequence */
  #define ADC_SQR2_SQ7_0        0x00001000
  #define ADC_SQR2_SQ7_1        0x00002000
  #define ADC_SQR2_SQ7_2        0x00004000
  #define ADC_SQR2_SQ7_3        0x00008000
  #define ADC_SQR2_SQ7_4        0x00010000
  #define ADC_SQR2_SQ8          0x007C0000	/* ADC 8th conversion in regular sequence */
  #define ADC_SQR2_SQ8_0        0x00040000
  #define ADC_SQR2_SQ8_1        0x00080000
  #define ADC_SQR2_SQ8_2        0x00100000
  #define ADC_SQR2_SQ8_3        0x00200000
  #define ADC_SQR2_SQ8_4        0x00400000
  #define ADC_SQR2_SQ9          0x1F000000	/* ADC 9th conversion in regular sequence */
  #define ADC_SQR2_SQ9_0        0x01000000
  #define ADC_SQR2_SQ9_1        0x02000000
  #define ADC_SQR2_SQ9_2        0x04000000
  #define ADC_SQR2_SQ9_3        0x08000000
  #define ADC_SQR2_SQ9_4        0x10000000
#define TOFF_ADC_SQR3       0x0038		/* (RW) ADC regular sequence register 3 */
  #define ADC_SQR3_SQ10         0x0000001F	/* ADC 10th conversion in regular sequence */
  #define ADC_SQR3_SQ10_0       0x00000001
  #define ADC_SQR3_SQ10_1       0x00000002
  #define ADC_SQR3_SQ10_2       0x00000004
  #define ADC_SQR3_SQ10_3       0x00000008
  #define ADC_SQR3_SQ10_4       0x00000010
  #define ADC_SQR3_SQ11         0x000007C0	/* ADC 11th conversion in regular sequence */
  #define ADC_SQR3_SQ11_0       0x00000040
  #define ADC_SQR3_SQ11_1       0x00000080
  #define ADC_SQR3_SQ11_2       0x00000100
  #define ADC_SQR3_SQ11_3       0x00000200
  #define ADC_SQR3_SQ11_4       0x00000400
  #define ADC_SQR3_SQ12         0x0001F000	/* ADC 12th conversion in regular sequence */
  #define ADC_SQR3_SQ12_0       0x00001000
  #define ADC_SQR3_SQ12_1       0x00002000
  #define ADC_SQR3_SQ12_2       0x00004000
  #define ADC_SQR3_SQ12_3       0x00008000
  #define ADC_SQR3_SQ12_4       0x00010000
  #define ADC_SQR3_SQ13         0x007C0000	/* ADC 13th conversion in regular sequence */
  #define ADC_SQR3_SQ13_0       0x00040000
  #define ADC_SQR3_SQ13_1       0x00080000
  #define ADC_SQR3_SQ13_2       0x00100000
  #define ADC_SQR3_SQ13_3       0x00200000
  #define ADC_SQR3_SQ13_4       0x00400000
  #define ADC_SQR3_SQ14         0x1F000000	/* ADC 14th conversion in regular sequence */
  #define ADC_SQR3_SQ14_0       0x01000000
  #define ADC_SQR3_SQ14_1       0x02000000
  #define ADC_SQR3_SQ14_2       0x04000000
  #define ADC_SQR3_SQ14_3       0x08000000
  #define ADC_SQR3_SQ14_4       0x10000000
#define TOFF_ADC_SQR4       0x003C		/* (RW) ADC regular sequence register 4 */
  #define ADC_SQR4_SQ15         0x0000001F	/* ADC 15th conversion in regular sequence */
  #define ADC_SQR4_SQ15_0       0x00000001
  #define ADC_SQR4_SQ15_1       0x00000002
  #define ADC_SQR4_SQ15_2       0x00000004
  #define ADC_SQR4_SQ15_3       0x00000008
  #define ADC_SQR4_SQ15_4       0x00000010
  #define ADC_SQR4_SQ16         0x000007C0	/* ADC 16th conversion in regular sequence */
  #define ADC_SQR4_SQ16_0       0x00000040
  #define ADC_SQR4_SQ16_1       0x00000080
  #define ADC_SQR4_SQ16_2       0x00000100
  #define ADC_SQR4_SQ16_3       0x00000200
  #define ADC_SQR4_SQ16_4       0x00000400
#define TOFF_ADC_DR         0x0040		/* (RW) ADC regular data register */
  #define ADC_DR_RDATA          0x0000FFFF	/* ADC regular Data converted */
  #define ADC_DR_RDATA_0        0x00000001
  #define ADC_DR_RDATA_1        0x00000002
  #define ADC_DR_RDATA_2        0x00000004
  #define ADC_DR_RDATA_3        0x00000008
  #define ADC_DR_RDATA_4        0x00000010
  #define ADC_DR_RDATA_5        0x00000020
  #define ADC_DR_RDATA_6        0x00000040
  #define ADC_DR_RDATA_7        0x00000080
  #define ADC_DR_RDATA_8        0x00000100
  #define ADC_DR_RDATA_9        0x00000200
  #define ADC_DR_RDATA_10       0x00000400
  #define ADC_DR_RDATA_11       0x00000800
  #define ADC_DR_RDATA_12       0x00001000
  #define ADC_DR_RDATA_13       0x00002000
  #define ADC_DR_RDATA_14       0x00004000
  #define ADC_DR_RDATA_15       0x00008000
  #define ADC_DR_RDATA_16       0x00010000
  #define ADC_DR_RDATA_17       0x00020000
  #define ADC_DR_RDATA_18       0x00040000
  #define ADC_DR_RDATA_19       0x00080000
  #define ADC_DR_RDATA_20       0x00100000
  #define ADC_DR_RDATA_21       0x00200000
  #define ADC_DR_RDATA_22       0x00400000
  #define ADC_DR_RDATA_23       0x00800000
  #define ADC_DR_RDATA_24       0x01000000
  #define ADC_DR_RDATA_25       0x02000000
  #define ADC_DR_RDATA_26       0x04000000
  #define ADC_DR_RDATA_27       0x08000000
  #define ADC_DR_RDATA_28       0x10000000
  #define ADC_DR_RDATA_29       0x20000000
  #define ADC_DR_RDATA_30       0x40000000
  #define ADC_DR_RDATA_31       0x80000000
#define TOFF_ADC_JSQR       0x004C		/* (RW) ADC injected sequence register */
  #define ADC_JSQR_JL           0x00000003	/* ADC injected channel sequence length */
  #define ADC_JSQR_JL_0         0x00000001
  #define ADC_JSQR_JL_1         0x00000002
  #define ADC_JSQR_JEXTSEL      0x0000007C	/* ADC external trigger selection for injected group */
  #define ADC_JSQR_JEXTSEL_0    0x00000004
  #define ADC_JSQR_JEXTSEL_1    0x00000008
  #define ADC_JSQR_JEXTSEL_2    0x00000010
  #define ADC_JSQR_JEXTSEL_3    0x00000020
  #define ADC_JSQR_JEXTSEL_4    0x00000040
  #define ADC_JSQR_JEXTEN       0x00000180	/* ADC external trigger enable and polarity selection for injected channels */
  #define ADC_JSQR_JEXTEN_0     0x00000080
  #define ADC_JSQR_JEXTEN_1     0x00000100
  #define ADC_JSQR_JSQ1         0x00003E00	/* ADC 1st conversion in injected sequence */
  #define ADC_JSQR_JSQ1_0       0x00000200
  #define ADC_JSQR_JSQ1_1       0x00000400
  #define ADC_JSQR_JSQ1_2       0x00000800
  #define ADC_JSQR_JSQ1_3       0x00001000
  #define ADC_JSQR_JSQ1_4       0x00002000
  #define ADC_JSQR_JSQ2         0x000F8000	/* ADC 2nd conversion in injected sequence */
  #define ADC_JSQR_JSQ2_0       0x00008000
  #define ADC_JSQR_JSQ2_1       0x00010000
  #define ADC_JSQR_JSQ2_2       0x00020000
  #define ADC_JSQR_JSQ2_3       0x00040000
  #define ADC_JSQR_JSQ2_4       0x00080000
  #define ADC_JSQR_JSQ3         0x03E00000	/* ADC 3rd conversion in injected sequence */
  #define ADC_JSQR_JSQ3_0       0x00200000
  #define ADC_JSQR_JSQ3_1       0x00400000
  #define ADC_JSQR_JSQ3_2       0x00800000
  #define ADC_JSQR_JSQ3_3       0x01000000
  #define ADC_JSQR_JSQ3_4       0x02000000
  #define ADC_JSQR_JSQ4         0xF8000000	/* ADC 4th conversion in injected sequence */
  #define ADC_JSQR_JSQ4_0       0x08000000
  #define ADC_JSQR_JSQ4_1       0x10000000
  #define ADC_JSQR_JSQ4_2       0x20000000
  #define ADC_JSQR_JSQ4_3       0x40000000
  #define ADC_JSQR_JSQ4_4       0x80000000
#define TOFF_ADC_OFR1       0x0060		/* (RW) ADC offset register 1 */
  #define ADC_OFR1_OFFSET1      0x03FFFFFF	/* ADC data offset 1 for channel programmed into bits OFFSET1_CH[4:0] */
  #define ADC_OFR1_OFFSET1_0    0x00000001
  #define ADC_OFR1_OFFSET1_1    0x00000002
  #define ADC_OFR1_OFFSET1_2    0x00000004
  #define ADC_OFR1_OFFSET1_3    0x00000008
  #define ADC_OFR1_OFFSET1_4    0x00000010
  #define ADC_OFR1_OFFSET1_5    0x00000020
  #define ADC_OFR1_OFFSET1_6    0x00000040
  #define ADC_OFR1_OFFSET1_7    0x00000080
  #define ADC_OFR1_OFFSET1_8    0x00000100
  #define ADC_OFR1_OFFSET1_9    0x00000200
  #define ADC_OFR1_OFFSET1_10   0x00000400
  #define ADC_OFR1_OFFSET1_11   0x00000800
  #define ADC_OFR1_OFFSET1_12   0x00001000
  #define ADC_OFR1_OFFSET1_13   0x00002000
  #define ADC_OFR1_OFFSET1_14   0x00004000
  #define ADC_OFR1_OFFSET1_15   0x00008000
  #define ADC_OFR1_OFFSET1_16   0x00010000
  #define ADC_OFR1_OFFSET1_17   0x00020000
  #define ADC_OFR1_OFFSET1_18   0x00040000
  #define ADC_OFR1_OFFSET1_19   0x00080000
  #define ADC_OFR1_OFFSET1_20   0x00100000
  #define ADC_OFR1_OFFSET1_21   0x00200000
  #define ADC_OFR1_OFFSET1_22   0x00400000
  #define ADC_OFR1_OFFSET1_23   0x00800000
  #define ADC_OFR1_OFFSET1_24   0x01000000
  #define ADC_OFR1_OFFSET1_25   0x02000000
  #define ADC_OFR1_OFFSET1_CH   0x7C000000	/* ADC Channel selection for the data offset 1 */
  #define ADC_OFR1_OFFSET1_CH_0 0x04000000
  #define ADC_OFR1_OFFSET1_CH_1 0x08000000
  #define ADC_OFR1_OFFSET1_CH_2 0x10000000
  #define ADC_OFR1_OFFSET1_CH_3 0x20000000
  #define ADC_OFR1_OFFSET1_CH_4 0x40000000
  #define ADC_OFR1_SSATE        0x80000000	/* ADC Signed saturation Enable */
#define TOFF_ADC_OFR2       0x0064		/* (RW) ADC offset register 2 */
  #define ADC_OFR2_OFFSET2      0x03FFFFFF	/* ADC data offset 2 for channel programmed into bits OFFSET2_CH[4:0] */
  #define ADC_OFR2_OFFSET2_0    0x00000001
  #define ADC_OFR2_OFFSET2_1    0x00000002
  #define ADC_OFR2_OFFSET2_2    0x00000004
  #define ADC_OFR2_OFFSET2_3    0x00000008
  #define ADC_OFR2_OFFSET2_4    0x00000010
  #define ADC_OFR2_OFFSET2_5    0x00000020
  #define ADC_OFR2_OFFSET2_6    0x00000040
  #define ADC_OFR2_OFFSET2_7    0x00000080
  #define ADC_OFR2_OFFSET2_8    0x00000100
  #define ADC_OFR2_OFFSET2_9    0x00000200
  #define ADC_OFR2_OFFSET2_10   0x00000400
  #define ADC_OFR2_OFFSET2_11   0x00000800
  #define ADC_OFR2_OFFSET2_12   0x00001000
  #define ADC_OFR2_OFFSET2_13   0x00002000
  #define ADC_OFR2_OFFSET2_14   0x00004000
  #define ADC_OFR2_OFFSET2_15   0x00008000
  #define ADC_OFR2_OFFSET2_16   0x00010000
  #define ADC_OFR2_OFFSET2_17   0x00020000
  #define ADC_OFR2_OFFSET2_18   0x00040000
  #define ADC_OFR2_OFFSET2_19   0x00080000
  #define ADC_OFR2_OFFSET2_20   0x00100000
  #define ADC_OFR2_OFFSET2_21   0x00200000
  #define ADC_OFR2_OFFSET2_22   0x00400000
  #define ADC_OFR2_OFFSET2_23   0x00800000
  #define ADC_OFR2_OFFSET2_24   0x01000000
  #define ADC_OFR2_OFFSET2_25   0x02000000
  #define ADC_OFR2_OFFSET2_CH   0x7C000000	/* ADC Channel selection for the data offset 2 */
  #define ADC_OFR2_OFFSET2_CH_0 0x04000000
  #define ADC_OFR2_OFFSET2_CH_1 0x08000000
  #define ADC_OFR2_OFFSET2_CH_2 0x10000000
  #define ADC_OFR2_OFFSET2_CH_3 0x20000000
  #define ADC_OFR2_OFFSET2_CH_4 0x40000000
  #define ADC_OFR2_SSATE        0x80000000	/* ADC Signed saturation Enable */
#define TOFF_ADC_OFR3       0x0068		/* (RW) ADC offset register 3 */
  #define ADC_OFR3_OFFSET3      0x03FFFFFF	/* ADC data offset 3 for channel programmed into bits OFFSET3_CH[4:0] */
  #define ADC_OFR3_OFFSET3_0    0x00000001
  #define ADC_OFR3_OFFSET3_1    0x00000002
  #define ADC_OFR3_OFFSET3_2    0x00000004
  #define ADC_OFR3_OFFSET3_3    0x00000008
  #define ADC_OFR3_OFFSET3_4    0x00000010
  #define ADC_OFR3_OFFSET3_5    0x00000020
  #define ADC_OFR3_OFFSET3_6    0x00000040
  #define ADC_OFR3_OFFSET3_7    0x00000080
  #define ADC_OFR3_OFFSET3_8    0x00000100
  #define ADC_OFR3_OFFSET3_9    0x00000200
  #define ADC_OFR3_OFFSET3_10   0x00000400
  #define ADC_OFR3_OFFSET3_11   0x00000800
  #define ADC_OFR3_OFFSET3_12   0x00001000
  #define ADC_OFR3_OFFSET3_13   0x00002000
  #define ADC_OFR3_OFFSET3_14   0x00004000
  #define ADC_OFR3_OFFSET3_15   0x00008000
  #define ADC_OFR3_OFFSET3_16   0x00010000
  #define ADC_OFR3_OFFSET3_17   0x00020000
  #define ADC_OFR3_OFFSET3_18   0x00040000
  #define ADC_OFR3_OFFSET3_19   0x00080000
  #define ADC_OFR3_OFFSET3_20   0x00100000
  #define ADC_OFR3_OFFSET3_21   0x00200000
  #define ADC_OFR3_OFFSET3_22   0x00400000
  #define ADC_OFR3_OFFSET3_23   0x00800000
  #define ADC_OFR3_OFFSET3_24   0x01000000
  #define ADC_OFR3_OFFSET3_25   0x02000000
  #define ADC_OFR3_OFFSET3_CH   0x7C000000	/* ADC Channel selection for the data offset 3 */
  #define ADC_OFR3_OFFSET3_CH_0 0x04000000
  #define ADC_OFR3_OFFSET3_CH_1 0x08000000
  #define ADC_OFR3_OFFSET3_CH_2 0x10000000
  #define ADC_OFR3_OFFSET3_CH_3 0x20000000
  #define ADC_OFR3_OFFSET3_CH_4 0x40000000
  #define ADC_OFR3_SSATE        0x80000000	/* ADC Signed saturation Enable */
#define TOFF_ADC_OFR4       0x006C		/* (RW) ADC offset register 4 */
  #define ADC_OFR4_OFFSET4      0x03FFFFFF	/* ADC data offset 4 for channel programmed into bits OFFSET4_CH[4:0] */
  #define ADC_OFR4_OFFSET4_0    0x00000001
  #define ADC_OFR4_OFFSET4_1    0x00000002
  #define ADC_OFR4_OFFSET4_2    0x00000004
  #define ADC_OFR4_OFFSET4_3    0x00000008
  #define ADC_OFR4_OFFSET4_4    0x00000010
  #define ADC_OFR4_OFFSET4_5    0x00000020
  #define ADC_OFR4_OFFSET4_6    0x00000040
  #define ADC_OFR4_OFFSET4_7    0x00000080
  #define ADC_OFR4_OFFSET4_8    0x00000100
  #define ADC_OFR4_OFFSET4_9    0x00000200
  #define ADC_OFR4_OFFSET4_10   0x00000400
  #define ADC_OFR4_OFFSET4_11   0x00000800
  #define ADC_OFR4_OFFSET4_12   0x00001000
  #define ADC_OFR4_OFFSET4_13   0x00002000
  #define ADC_OFR4_OFFSET4_14   0x00004000
  #define ADC_OFR4_OFFSET4_15   0x00008000
  #define ADC_OFR4_OFFSET4_16   0x00010000
  #define ADC_OFR4_OFFSET4_17   0x00020000
  #define ADC_OFR4_OFFSET4_18   0x00040000
  #define ADC_OFR4_OFFSET4_19   0x00080000
  #define ADC_OFR4_OFFSET4_20   0x00100000
  #define ADC_OFR4_OFFSET4_21   0x00200000
  #define ADC_OFR4_OFFSET4_22   0x00400000
  #define ADC_OFR4_OFFSET4_23   0x00800000
  #define ADC_OFR4_OFFSET4_24   0x01000000
  #define ADC_OFR4_OFFSET4_25   0x02000000
  #define ADC_OFR4_OFFSET4_CH   0x7C000000	/* ADC Channel selection for the data offset 4 */
  #define ADC_OFR4_OFFSET4_CH_0 0x04000000
  #define ADC_OFR4_OFFSET4_CH_1 0x08000000
  #define ADC_OFR4_OFFSET4_CH_2 0x10000000
  #define ADC_OFR4_OFFSET4_CH_3 0x20000000
  #define ADC_OFR4_OFFSET4_CH_4 0x40000000
  #define ADC_OFR4_SSATE        0x80000000	/* ADC Signed saturation Enable */
#define TOFF_ADC_JDR1       0x0080		/* (RW) ADC injected data register 1 */
  #define ADC_JDR1_JDATA        0x0000FFFF	/* ADC Injected DATA */
  #define ADC_JDR1_JDATA_0      0x00000001
  #define ADC_JDR1_JDATA_1      0x00000002
  #define ADC_JDR1_JDATA_2      0x00000004
  #define ADC_JDR1_JDATA_3      0x00000008
  #define ADC_JDR1_JDATA_4      0x00000010
  #define ADC_JDR1_JDATA_5      0x00000020
  #define ADC_JDR1_JDATA_6      0x00000040
  #define ADC_JDR1_JDATA_7      0x00000080
  #define ADC_JDR1_JDATA_8      0x00000100
  #define ADC_JDR1_JDATA_9      0x00000200
  #define ADC_JDR1_JDATA_10     0x00000400
  #define ADC_JDR1_JDATA_11     0x00000800
  #define ADC_JDR1_JDATA_12     0x00001000
  #define ADC_JDR1_JDATA_13     0x00002000
  #define ADC_JDR1_JDATA_14     0x00004000
  #define ADC_JDR1_JDATA_15     0x00008000
  #define ADC_JDR1_JDATA_16     0x00010000
  #define ADC_JDR1_JDATA_17     0x00020000
  #define ADC_JDR1_JDATA_18     0x00040000
  #define ADC_JDR1_JDATA_19     0x00080000
  #define ADC_JDR1_JDATA_20     0x00100000
  #define ADC_JDR1_JDATA_21     0x00200000
  #define ADC_JDR1_JDATA_22     0x00400000
  #define ADC_JDR1_JDATA_23     0x00800000
  #define ADC_JDR1_JDATA_24     0x01000000
  #define ADC_JDR1_JDATA_25     0x02000000
  #define ADC_JDR1_JDATA_26     0x04000000
  #define ADC_JDR1_JDATA_27     0x08000000
  #define ADC_JDR1_JDATA_28     0x10000000
  #define ADC_JDR1_JDATA_29     0x20000000
  #define ADC_JDR1_JDATA_30     0x40000000
  #define ADC_JDR1_JDATA_31     0x80000000
#define TOFF_ADC_JDR2       0x0084		/* (RW) ADC injected data register 2 */
  #define ADC_JDR2_JDATA        0x0000FFFF	/* ADC Injected DATA */
  #define ADC_JDR2_JDATA_0      0x00000001
  #define ADC_JDR2_JDATA_1      0x00000002
  #define ADC_JDR2_JDATA_2      0x00000004
  #define ADC_JDR2_JDATA_3      0x00000008
  #define ADC_JDR2_JDATA_4      0x00000010
  #define ADC_JDR2_JDATA_5      0x00000020
  #define ADC_JDR2_JDATA_6      0x00000040
  #define ADC_JDR2_JDATA_7      0x00000080
  #define ADC_JDR2_JDATA_8      0x00000100
  #define ADC_JDR2_JDATA_9      0x00000200
  #define ADC_JDR2_JDATA_10     0x00000400
  #define ADC_JDR2_JDATA_11     0x00000800
  #define ADC_JDR2_JDATA_12     0x00001000
  #define ADC_JDR2_JDATA_13     0x00002000
  #define ADC_JDR2_JDATA_14     0x00004000
  #define ADC_JDR2_JDATA_15     0x00008000
  #define ADC_JDR2_JDATA_16     0x00010000
  #define ADC_JDR2_JDATA_17     0x00020000
  #define ADC_JDR2_JDATA_18     0x00040000
  #define ADC_JDR2_JDATA_19     0x00080000
  #define ADC_JDR2_JDATA_20     0x00100000
  #define ADC_JDR2_JDATA_21     0x00200000
  #define ADC_JDR2_JDATA_22     0x00400000
  #define ADC_JDR2_JDATA_23     0x00800000
  #define ADC_JDR2_JDATA_24     0x01000000
  #define ADC_JDR2_JDATA_25     0x02000000
  #define ADC_JDR2_JDATA_26     0x04000000
  #define ADC_JDR2_JDATA_27     0x08000000
  #define ADC_JDR2_JDATA_28     0x10000000
  #define ADC_JDR2_JDATA_29     0x20000000
  #define ADC_JDR2_JDATA_30     0x40000000
  #define ADC_JDR2_JDATA_31     0x80000000
#define TOFF_ADC_JDR3       0x0088		/* (RW) ADC injected data register 3 */
  #define ADC_JDR3_JDATA        0x0000FFFF	/* ADC Injected DATA */
  #define ADC_JDR3_JDATA_0      0x00000001
  #define ADC_JDR3_JDATA_1      0x00000002
  #define ADC_JDR3_JDATA_2      0x00000004
  #define ADC_JDR3_JDATA_3      0x00000008
  #define ADC_JDR3_JDATA_4      0x00000010
  #define ADC_JDR3_JDATA_5      0x00000020
  #define ADC_JDR3_JDATA_6      0x00000040
  #define ADC_JDR3_JDATA_7      0x00000080
  #define ADC_JDR3_JDATA_8      0x00000100
  #define ADC_JDR3_JDATA_9      0x00000200
  #define ADC_JDR3_JDATA_10     0x00000400
  #define ADC_JDR3_JDATA_11     0x00000800
  #define ADC_JDR3_JDATA_12     0x00001000
  #define ADC_JDR3_JDATA_13     0x00002000
  #define ADC_JDR3_JDATA_14     0x00004000
  #define ADC_JDR3_JDATA_15     0x00008000
  #define ADC_JDR3_JDATA_16     0x00010000
  #define ADC_JDR3_JDATA_17     0x00020000
  #define ADC_JDR3_JDATA_18     0x00040000
  #define ADC_JDR3_JDATA_19     0x00080000
  #define ADC_JDR3_JDATA_20     0x00100000
  #define ADC_JDR3_JDATA_21     0x00200000
  #define ADC_JDR3_JDATA_22     0x00400000
  #define ADC_JDR3_JDATA_23     0x00800000
  #define ADC_JDR3_JDATA_24     0x01000000
  #define ADC_JDR3_JDATA_25     0x02000000
  #define ADC_JDR3_JDATA_26     0x04000000
  #define ADC_JDR3_JDATA_27     0x08000000
  #define ADC_JDR3_JDATA_28     0x10000000
  #define ADC_JDR3_JDATA_29     0x20000000
  #define ADC_JDR3_JDATA_30     0x40000000
  #define ADC_JDR3_JDATA_31     0x80000000
#define TOFF_ADC_JDR4       0x008C		/* (RW) ADC injected data register 4 */
  #define ADC_JDR4_JDATA        0x0000FFFF	/* ADC Injected DATA */
  #define ADC_JDR4_JDATA_0      0x00000001
  #define ADC_JDR4_JDATA_1      0x00000002
  #define ADC_JDR4_JDATA_2      0x00000004
  #define ADC_JDR4_JDATA_3      0x00000008
  #define ADC_JDR4_JDATA_4      0x00000010
  #define ADC_JDR4_JDATA_5      0x00000020
  #define ADC_JDR4_JDATA_6      0x00000040
  #define ADC_JDR4_JDATA_7      0x00000080
  #define ADC_JDR4_JDATA_8      0x00000100
  #define ADC_JDR4_JDATA_9      0x00000200
  #define ADC_JDR4_JDATA_10     0x00000400
  #define ADC_JDR4_JDATA_11     0x00000800
  #define ADC_JDR4_JDATA_12     0x00001000
  #define ADC_JDR4_JDATA_13     0x00002000
  #define ADC_JDR4_JDATA_14     0x00004000
  #define ADC_JDR4_JDATA_15     0x00008000
  #define ADC_JDR4_JDATA_16     0x00010000
  #define ADC_JDR4_JDATA_17     0x00020000
  #define ADC_JDR4_JDATA_18     0x00040000
  #define ADC_JDR4_JDATA_19     0x00080000
  #define ADC_JDR4_JDATA_20     0x00100000
  #define ADC_JDR4_JDATA_21     0x00200000
  #define ADC_JDR4_JDATA_22     0x00400000
  #define ADC_JDR4_JDATA_23     0x00800000
  #define ADC_JDR4_JDATA_24     0x01000000
  #define ADC_JDR4_JDATA_25     0x02000000
  #define ADC_JDR4_JDATA_26     0x04000000
  #define ADC_JDR4_JDATA_27     0x08000000
  #define ADC_JDR4_JDATA_28     0x10000000
  #define ADC_JDR4_JDATA_29     0x20000000
  #define ADC_JDR4_JDATA_30     0x40000000
  #define ADC_JDR4_JDATA_31     0x80000000
#define TOFF_ADC_AWD2CR     0x00A0		/* (RW) ADC  Analog Watchdog 2 Configuration Register */
  #define ADC_AWD2CR_AWD2CH     0x000FFFFF	/* ADC Analog watchdog 2 channel selection */
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
  #define ADC_AWD2CR_AWD2CH_19  0x00080000
#define TOFF_ADC_AWD3CR     0x00A4		/* (RW) ADC  Analog Watchdog 3 Configuration Register */
  #define ADC_AWD3CR_AWD3CH     0x000FFFFF	/* ADC Analog watchdog 3 channel selection */
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
  #define ADC_AWD3CR_AWD3CH_19  0x00080000
#define TOFF_ADC_LTR2       0x00B0		/* (RW) ADC watchdog Lower threshold register 2 */
  #define ADC_LTR2_LT2          0x03FFFFFF	/* ADC Analog watchdog 2 lower threshold */
  #define ADC_LTR2_LT2_0        0x00000001	/* ADC LT2 bit 0 */
  #define ADC_LTR2_LT2_1        0x00000002	/* ADC LT2 bit 1 */
  #define ADC_LTR2_LT2_2        0x00000004	/* ADC LT2 bit 2 */
  #define ADC_LTR2_LT2_3        0x00000008	/* ADC LT2 bit 3 */
  #define ADC_LTR2_LT2_4        0x00000010	/* ADC LT2 bit 4 */
  #define ADC_LTR2_LT2_5        0x00000020	/* ADC LT2 bit 5 */
  #define ADC_LTR2_LT2_6        0x00000040	/* ADC LT2 bit 6 */
  #define ADC_LTR2_LT2_7        0x00000080	/* ADC LT2 bit 7 */
  #define ADC_LTR2_LT2_8        0x00000100	/* ADC LT2 bit 8 */
  #define ADC_LTR2_LT2_9        0x00000200	/* ADC LT2 bit 9 */
  #define ADC_LTR2_LT2_10       0x00000400	/* ADC LT2 bit 10 */
  #define ADC_LTR2_LT2_11       0x00000800	/* ADC LT2 bit 11 */
  #define ADC_LTR2_LT2_12       0x00001000	/* ADC LT2 bit 12 */
  #define ADC_LTR2_LT2_13       0x00002000	/* ADC LT2 bit 13 */
  #define ADC_LTR2_LT2_14       0x00004000	/* ADC LT2 bit 14 */
  #define ADC_LTR2_LT2_15       0x00008000	/* ADC LT2 bit 15 */
  #define ADC_LTR2_LT2_16       0x00010000	/* ADC LT2 bit 16 */
  #define ADC_LTR2_LT2_17       0x00020000	/* ADC LT2 bit 17 */
  #define ADC_LTR2_LT2_18       0x00040000	/* ADC LT2 bit 18 */
  #define ADC_LTR2_LT2_19       0x00080000	/* ADC LT2 bit 19 */
  #define ADC_LTR2_LT2_20       0x00100000	/* ADC LT2 bit 20 */
  #define ADC_LTR2_LT2_21       0x00200000	/* ADC LT2 bit 21 */
  #define ADC_LTR2_LT2_22       0x00400000	/* ADC LT2 bit 22 */
  #define ADC_LTR2_LT2_23       0x00800000	/* ADC LT2 bit 23 */
  #define ADC_LTR2_LT2_24       0x01000000	/* ADC LT2 bit 24 */
  #define ADC_LTR2_LT2_25       0x02000000	/* ADC LT2 bit 25 */
#define TOFF_ADC_HTR2       0x00B4		/* (RW) ADC watchdog Higher threshold register 2 */
  #define ADC_HTR2_HT2          0x03FFFFFF	/* ADC Analog watchdog 2 higher threshold */
  #define ADC_HTR2_HT2_0        0x00000001	/* ADC HT2 bit 0 */
  #define ADC_HTR2_HT2_1        0x00000002	/* ADC HT2 bit 1 */
  #define ADC_HTR2_HT2_2        0x00000004	/* ADC HT2 bit 2 */
  #define ADC_HTR2_HT2_3        0x00000008	/* ADC HT2 bit 3 */
  #define ADC_HTR2_HT2_4        0x00000010	/* ADC HT2 bit 4 */
  #define ADC_HTR2_HT2_5        0x00000020	/* ADC HT2 bit 5 */
  #define ADC_HTR2_HT2_6        0x00000040	/* ADC HT2 bit 6 */
  #define ADC_HTR2_HT2_7        0x00000080	/* ADC HT2 bit 7 */
  #define ADC_HTR2_HT2_8        0x00000100	/* ADC HT2 bit 8 */
  #define ADC_HTR2_HT2_9        0x00000200	/* ADC HT2 bit 9 */
  #define ADC_HTR2_HT2_10       0x00000400	/* ADC HT2 bit 10 */
  #define ADC_HTR2_HT2_11       0x00000800	/* ADC HT2 bit 11 */
  #define ADC_HTR2_HT2_12       0x00001000	/* ADC HT2 bit 12 */
  #define ADC_HTR2_HT2_13       0x00002000	/* ADC HT2 bit 13 */
  #define ADC_HTR2_HT2_14       0x00004000	/* ADC HT2 bit 14 */
  #define ADC_HTR2_HT2_15       0x00008000	/* ADC HT2 bit 15 */
  #define ADC_HTR2_HT2_16       0x00010000	/* ADC HT2 bit 16 */
  #define ADC_HTR2_HT2_17       0x00020000	/* ADC HT2 bit 17 */
  #define ADC_HTR2_HT2_18       0x00040000	/* ADC HT2 bit 18 */
  #define ADC_HTR2_HT2_19       0x00080000	/* ADC HT2 bit 19 */
  #define ADC_HTR2_HT2_20       0x00100000	/* ADC HT2 bit 20 */
  #define ADC_HTR2_HT2_21       0x00200000	/* ADC HT2 bit 21 */
  #define ADC_HTR2_HT2_22       0x00400000	/* ADC HT2 bit 22 */
  #define ADC_HTR2_HT2_23       0x00800000	/* ADC HT2 bit 23 */
  #define ADC_HTR2_HT2_24       0x01000000	/* ADC HT2 bit 24 */
  #define ADC_HTR2_HT2_25       0x02000000	/* ADC HT2 bit 25 */
#define TOFF_ADC_LTR3       0x00B8		/* (RW) ADC watchdog Lower threshold register 3 */
  #define ADC_LTR3_LT3          0x03FFFFFF	/* ADC Analog watchdog 3 lower threshold */
  #define ADC_LTR3_LT3_0        0x00000001	/* ADC LT3 bit 0 */
  #define ADC_LTR3_LT3_1        0x00000002	/* ADC LT3 bit 1 */
  #define ADC_LTR3_LT3_2        0x00000004	/* ADC LT3 bit 2 */
  #define ADC_LTR3_LT3_3        0x00000008	/* ADC LT3 bit 3 */
  #define ADC_LTR3_LT3_4        0x00000010	/* ADC LT3 bit 4 */
  #define ADC_LTR3_LT3_5        0x00000020	/* ADC LT3 bit 5 */
  #define ADC_LTR3_LT3_6        0x00000040	/* ADC LT3 bit 6 */
  #define ADC_LTR3_LT3_7        0x00000080	/* ADC LT3 bit 7 */
  #define ADC_LTR3_LT3_8        0x00000100	/* ADC LT3 bit 8 */
  #define ADC_LTR3_LT3_9        0x00000200	/* ADC LT3 bit 9 */
  #define ADC_LTR3_LT3_10       0x00000400	/* ADC LT3 bit 10 */
  #define ADC_LTR3_LT3_11       0x00000800	/* ADC LT3 bit 11 */
  #define ADC_LTR3_LT3_12       0x00001000	/* ADC LT3 bit 12 */
  #define ADC_LTR3_LT3_13       0x00002000	/* ADC LT3 bit 13 */
  #define ADC_LTR3_LT3_14       0x00004000	/* ADC LT3 bit 14 */
  #define ADC_LTR3_LT3_15       0x00008000	/* ADC LT3 bit 15 */
  #define ADC_LTR3_LT3_16       0x00010000	/* ADC LT3 bit 16 */
  #define ADC_LTR3_LT3_17       0x00020000	/* ADC LT3 bit 17 */
  #define ADC_LTR3_LT3_18       0x00040000	/* ADC LT3 bit 18 */
  #define ADC_LTR3_LT3_19       0x00080000	/* ADC LT3 bit 19 */
  #define ADC_LTR3_LT3_20       0x00100000	/* ADC LT3 bit 20 */
  #define ADC_LTR3_LT3_21       0x00200000	/* ADC LT3 bit 21 */
  #define ADC_LTR3_LT3_22       0x00400000	/* ADC LT3 bit 22 */
  #define ADC_LTR3_LT3_23       0x00800000	/* ADC LT3 bit 23 */
  #define ADC_LTR3_LT3_24       0x01000000	/* ADC LT3 bit 24*/
  #define ADC_LTR3_LT3_25       0x02000000	/* ADC LT3 bit 25 */
#define TOFF_ADC_HTR3       0x00BC		/* (RW) ADC watchdog Higher threshold register 3 */
  #define ADC_HTR3_HT3          0x03FFFFFF	/* ADC Analog watchdog 3 higher threshold */
  #define ADC_HTR3_HT3_0        0x00000001	/* ADC HT3 bit 0 */
  #define ADC_HTR3_HT3_1        0x00000002	/* ADC HT3 bit 1 */
  #define ADC_HTR3_HT3_2        0x00000004	/* ADC HT3 bit 2 */
  #define ADC_HTR3_HT3_3        0x00000008	/* ADC HT3 bit 3 */
  #define ADC_HTR3_HT3_4        0x00000010	/* ADC HT3 bit 4 */
  #define ADC_HTR3_HT3_5        0x00000020	/* ADC HT3 bit 5 */
  #define ADC_HTR3_HT3_6        0x00000040	/* ADC HT3 bit 6 */
  #define ADC_HTR3_HT3_7        0x00000080	/* ADC HT3 bit 7 */
  #define ADC_HTR3_HT3_8        0x00000100	/* ADC HT3 bit 8 */
  #define ADC_HTR3_HT3_9        0x00000200	/* ADC HT3 bit 9 */
  #define ADC_HTR3_HT3_10       0x00000400	/* ADC HT3 bit 10 */
  #define ADC_HTR3_HT3_11       0x00000800	/* ADC HT3 bit 11 */
  #define ADC_HTR3_HT3_12       0x00001000	/* ADC HT3 bit 12 */
  #define ADC_HTR3_HT3_13       0x00002000	/* ADC HT3 bit 13 */
  #define ADC_HTR3_HT3_14       0x00004000	/* ADC HT3 bit 14 */
  #define ADC_HTR3_HT3_15       0x00008000	/* ADC HT3 bit 15 */
  #define ADC_HTR3_HT3_16       0x00010000	/* ADC HT3 bit 16 */
  #define ADC_HTR3_HT3_17       0x00020000	/* ADC HT3 bit 17 */
  #define ADC_HTR3_HT3_18       0x00040000	/* ADC HT3 bit 18 */
  #define ADC_HTR3_HT3_19       0x00080000	/* ADC HT3 bit 19 */
  #define ADC_HTR3_HT3_20       0x00100000	/* ADC HT3 bit 20 */
  #define ADC_HTR3_HT3_21       0x00200000	/* ADC HT3 bit 21 */
  #define ADC_HTR3_HT3_22       0x00400000	/* ADC HT3 bit 22 */
  #define ADC_HTR3_HT3_23       0x00800000	/* ADC HT3 bit 23 */
  #define ADC_HTR3_HT3_24       0x01000000	/* ADC HT3 bit 24 */
  #define ADC_HTR3_HT3_25       0x02000000	/* ADC HT3 bit 25 */
#define TOFF_ADC_DIFSEL     0x00C0		/* (RW) ADC  Differential Mode Selection Register */
  #define ADC_DIFSEL_DIFSEL     0x000FFFFF	/* ADC differential modes for channels 1 to 18 */
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
  #define ADC_DIFSEL_DIFSEL_19  0x00080000
#define TOFF_ADC_CALFACT    0x00C4		/* (RW) ADC  Calibration Factors */
  #define ADC_CALFACT_CALFACT_S     0x000007FF	/* ADC calibration factors in single-ended mode */
  #define ADC_CALFACT_CALFACT_S_0   0x00000001
  #define ADC_CALFACT_CALFACT_S_1   0x00000002
  #define ADC_CALFACT_CALFACT_S_2   0x00000004
  #define ADC_CALFACT_CALFACT_S_3   0x00000008
  #define ADC_CALFACT_CALFACT_S_4   0x00000010
  #define ADC_CALFACT_CALFACT_S_5   0x00000020
  #define ADC_CALFACT_CALFACT_S_6   0x00000040
  #define ADC_CALFACT_CALFACT_S_7   0x00000080
  #define ADC_CALFACT_CALFACT_S_8   0x00000100
  #define ADC_CALFACT_CALFACT_S_9   0x00000200
  #define ADC_CALFACT_CALFACT_S_10  0x00000400
  #define ADC_CALFACT_CALFACT_D     0x07FF0000	/* ADC calibration factors in differential mode */
  #define ADC_CALFACT_CALFACT_D_0   0x00010000
  #define ADC_CALFACT_CALFACT_D_1   0x00020000
  #define ADC_CALFACT_CALFACT_D_2   0x00040000
  #define ADC_CALFACT_CALFACT_D_3   0x00080000
  #define ADC_CALFACT_CALFACT_D_4   0x00100000
  #define ADC_CALFACT_CALFACT_D_5   0x00200000
  #define ADC_CALFACT_CALFACT_D_6   0x00400000
  #define ADC_CALFACT_CALFACT_D_7   0x00800000
  #define ADC_CALFACT_CALFACT_D_8   0x01000000
  #define ADC_CALFACT_CALFACT_D_9   0x02000000
  #define ADC_CALFACT_CALFACT_D_10  0x04000000
#define TOFF_ADC_CALFACT2   0x00C8		/* (RW) ADC  Linearity Calibration Factors */
  #define ADC_CALFACT2_LINCALFACT     0x3FFFFFFF	/* ADC Linearity calibration factors */
  #define ADC_CALFACT2_LINCALFACT_0   0x00000001
  #define ADC_CALFACT2_LINCALFACT_1   0x00000002
  #define ADC_CALFACT2_LINCALFACT_2   0x00000004
  #define ADC_CALFACT2_LINCALFACT_3   0x00000008
  #define ADC_CALFACT2_LINCALFACT_4   0x00000010
  #define ADC_CALFACT2_LINCALFACT_5   0x00000020
  #define ADC_CALFACT2_LINCALFACT_6   0x00000040
  #define ADC_CALFACT2_LINCALFACT_7   0x00000080
  #define ADC_CALFACT2_LINCALFACT_8   0x00000100
  #define ADC_CALFACT2_LINCALFACT_9   0x00000200
  #define ADC_CALFACT2_LINCALFACT_10  0x00000400
  #define ADC_CALFACT2_LINCALFACT_11  0x00000800
  #define ADC_CALFACT2_LINCALFACT_12  0x00001000
  #define ADC_CALFACT2_LINCALFACT_13  0x00002000
  #define ADC_CALFACT2_LINCALFACT_14  0x00004000
  #define ADC_CALFACT2_LINCALFACT_15  0x00008000
  #define ADC_CALFACT2_LINCALFACT_16  0x00010000
  #define ADC_CALFACT2_LINCALFACT_17  0x00020000
  #define ADC_CALFACT2_LINCALFACT_18  0x00040000
  #define ADC_CALFACT2_LINCALFACT_19  0x00080000
  #define ADC_CALFACT2_LINCALFACT_20  0x00100000
  #define ADC_CALFACT2_LINCALFACT_21  0x00200000
  #define ADC_CALFACT2_LINCALFACT_22  0x00400000
  #define ADC_CALFACT2_LINCALFACT_23  0x00800000
  #define ADC_CALFACT2_LINCALFACT_24  0x01000000
  #define ADC_CALFACT2_LINCALFACT_25  0x02000000
  #define ADC_CALFACT2_LINCALFACT_26  0x04000000
  #define ADC_CALFACT2_LINCALFACT_27  0x08000001
  #define ADC_CALFACT2_LINCALFACT_28  0x10000000
  #define ADC_CALFACT2_LINCALFACT_29  0x20000000
#define TOFF_ADC_OR         0x00D0		/* (RW) ADC  Calibration Factors */
  #define ADC2_OR_VDDCOREEN     0x00000001	/* ADC2 Option Register  - VDDCORE enable bit */
#define TOFF_ADC_VERR       0x03F4		/* (RW) ADC version register */
#define TOFF_ADC_IPIDR      0x03F8		/* (RW) ADC ID register */
#define TOFF_ADC_SIDR       0x03FC		/* (RW) ADC Size ID register */

#define TADR_ADC_BASE       (MCU_AHB2_PERIPH_BASE + 0x3300)
#define TOFF_ADC_CSR        0x0000		/* (RW) ADC Common status register */
  #define ADC_CSR_ADRDY_MST     0x00000001	/* Master ADC ready */
  #define ADC_CSR_EOSMP_MST     0x00000002	/* End of sampling phase flag of the master ADC */
  #define ADC_CSR_EOC_MST       0x00000004	/* End of regular conversion of the master ADC */
  #define ADC_CSR_EOS_MST       0x00000008	/* End of regular sequence flag of the master ADC */
  #define ADC_CSR_OVR_MST       0x00000010	/* Overrun flag of the master ADC */
  #define ADC_CSR_JEOC_MST      0x00000020	/* End of injected conversion of the master ADC */
  #define ADC_CSR_JEOS_MST      0x00000040	/* End of injected sequence flag of the master ADC */
  #define ADC_CSR_AWD1_MST      0x00000080	/* Analog watchdog 1 flag of the master ADC */
  #define ADC_CSR_AWD2_MST      0x00000100	/* Analog watchdog 2 flag of the master ADC */
  #define ADC_CSR_AWD3_MST      0x00000200	/* Analog watchdog 3 flag of the master ADC */
  #define ADC_CSR_JQOVF_MST     0x00000400	/* Injected context queue overflow flag of the master ADC */
  #define ADC_CSR_ADRDY_SLV     0x00010000	/* Slave ADC ready */
  #define ADC_CSR_EOSMP_SLV     0x00020000	/* End of sampling phase flag of the slave ADC */
  #define ADC_CSR_EOC_SLV       0x00040000	/* End of regular conversion of the slave ADC */
  #define ADC_CSR_EOS_SLV       0x00080000	/* End of regular sequence flag of the slave ADC */
  #define ADC_CSR_OVR_SLV       0x00100000	/* Overrun flag of the slave ADC */
  #define ADC_CSR_JEOC_SLV      0x00200000	/* End of injected conversion of the slave ADC */
  #define ADC_CSR_JEOS_SLV      0x00400000	/* End of injected sequence flag of the slave ADC */
  #define ADC_CSR_AWD1_SLV      0x00800000	/* Analog watchdog 1 flag of the slave ADC */
  #define ADC_CSR_AWD2_SLV      0x01000000	/* Analog watchdog 2 flag of the slave ADC */
  #define ADC_CSR_AWD3_SLV      0x02000000	/* Analog watchdog 3 flag of the slave ADC */
  #define ADC_CSR_JQOVF_SLV     0x04000000	/* Injected context queue overflow flag of the slave ADC */
#define TOFF_ADC_CCR        0x0008		/* (RW) ADC common control register */
  #define ADC_CCR_DUAL          0x0000001F	/* Dual ADC mode selection */
  #define ADC_CCR_DUAL_0        0x00000001
  #define ADC_CCR_DUAL_1        0x00000002
  #define ADC_CCR_DUAL_2        0x00000004
  #define ADC_CCR_DUAL_3        0x00000008
  #define ADC_CCR_DUAL_4        0x00000010
  #define ADC_CCR_DELAY         0x00000F00	/* Delay between 2 sampling phases */
  #define ADC_CCR_DELAY_0       0x00000100
  #define ADC_CCR_DELAY_1       0x00000200
  #define ADC_CCR_DELAY_2       0x00000400
  #define ADC_CCR_DELAY_3       0x00000800
  #define ADC_CCR_DAMDF         0x0000C000	/* Dual ADC mode Data format */
  #define ADC_CCR_DAMDF_0       0x00004000
  #define ADC_CCR_DAMDF_1       0x00008000
  #define ADC_CCR_CKMODE        0x00030000	/* ADC clock mode */
  #define ADC_CCR_CKMODE_0      0x00010000
  #define ADC_CCR_CKMODE_1      0x00020000
  #define ADC_CCR_PRESC         0x003C0000	/* ADC prescaler */
  #define ADC_CCR_PRESC_0       0x00040000
  #define ADC_CCR_PRESC_1       0x00080000
  #define ADC_CCR_PRESC_2       0x00100000
  #define ADC_CCR_PRESC_3       0x00200000
  #define ADC_CCR_VREFEN        0x00400000	/* VREFINT enable */
  #define ADC_CCR_VSENSEEN      0x00800000	/* Temperature sensor enable */
  #define ADC_CCR_VBATEN        0x01000000	/* VBAT enable */
#define TOFF_ADC_CDR        0x000C		/* (RW) ADC common regular data register for dual AND triple modes */
  #define ADC_CDR_RDATA_MST     0x0000FFFF	/* Regular Data of the master ADC */
  #define ADC_CDR_RDATA_MST_0   0x00000001
  #define ADC_CDR_RDATA_MST_1   0x00000002
  #define ADC_CDR_RDATA_MST_2   0x00000004
  #define ADC_CDR_RDATA_MST_3   0x00000008
  #define ADC_CDR_RDATA_MST_4   0x00000010
  #define ADC_CDR_RDATA_MST_5   0x00000020
  #define ADC_CDR_RDATA_MST_6   0x00000040
  #define ADC_CDR_RDATA_MST_7   0x00000080
  #define ADC_CDR_RDATA_MST_8   0x00000100
  #define ADC_CDR_RDATA_MST_9   0x00000200
  #define ADC_CDR_RDATA_MST_10  0x00000400
  #define ADC_CDR_RDATA_MST_11  0x00000800
  #define ADC_CDR_RDATA_MST_12  0x00001000
  #define ADC_CDR_RDATA_MST_13  0x00002000
  #define ADC_CDR_RDATA_MST_14  0x00004000
  #define ADC_CDR_RDATA_MST_15  0x00008000
  #define ADC_CDR_RDATA_SLV     0xFFFF0000	/* Regular Data of the master ADC */
  #define ADC_CDR_RDATA_SLV_0   0x00010000
  #define ADC_CDR_RDATA_SLV_1   0x00020000
  #define ADC_CDR_RDATA_SLV_2   0x00040000
  #define ADC_CDR_RDATA_SLV_3   0x00080000
  #define ADC_CDR_RDATA_SLV_4   0x00100000
  #define ADC_CDR_RDATA_SLV_5   0x00200000
  #define ADC_CDR_RDATA_SLV_6   0x00400000
  #define ADC_CDR_RDATA_SLV_7   0x00800000
  #define ADC_CDR_RDATA_SLV_8   0x01000000
  #define ADC_CDR_RDATA_SLV_9   0x02000000
  #define ADC_CDR_RDATA_SLV_10  0x04000000
  #define ADC_CDR_RDATA_SLV_11  0x08000000
  #define ADC_CDR_RDATA_SLV_12  0x10000000
  #define ADC_CDR_RDATA_SLV_13  0x20000000
  #define ADC_CDR_RDATA_SLV_14  0x40000000
  #define ADC_CDR_RDATA_SLV_15  0x80000000
#define TOFF_ADC_CDR2       0x0010		/* (RW) ADC common regular data register for 32-bit dual mode */
  #define ADC_CDR2_RDATA_ALT    0xFFFFFFFF	/* Regular Data for dual Mode */
  #define ADC_CDR2_RDATA_ALT_0  0x00000001
  #define ADC_CDR2_RDATA_ALT_1  0x00000002
  #define ADC_CDR2_RDATA_ALT_2  0x00000004
  #define ADC_CDR2_RDATA_ALT_3  0x00000008
  #define ADC_CDR2_RDATA_ALT_4  0x00000010
  #define ADC_CDR2_RDATA_ALT_5  0x00000020
  #define ADC_CDR2_RDATA_ALT_6  0x00000040
  #define ADC_CDR2_RDATA_ALT_7  0x00000080
  #define ADC_CDR2_RDATA_ALT_8  0x00000100
  #define ADC_CDR2_RDATA_ALT_9  0x00000200
  #define ADC_CDR2_RDATA_ALT_10 0x00000400
  #define ADC_CDR2_RDATA_ALT_11 0x00000800
  #define ADC_CDR2_RDATA_ALT_12 0x00001000
  #define ADC_CDR2_RDATA_ALT_13 0x00002000
  #define ADC_CDR2_RDATA_ALT_14 0x00004000
  #define ADC_CDR2_RDATA_ALT_15 0x00008000
  #define ADC_CDR2_RDATA_ALT_16 0x00010000
  #define ADC_CDR2_RDATA_ALT_17 0x00020000
  #define ADC_CDR2_RDATA_ALT_18 0x00040000
  #define ADC_CDR2_RDATA_ALT_19 0x00080000
  #define ADC_CDR2_RDATA_ALT_20 0x00100000
  #define ADC_CDR2_RDATA_ALT_21 0x00200000
  #define ADC_CDR2_RDATA_ALT_22 0x00400000
  #define ADC_CDR2_RDATA_ALT_23 0x00800000
  #define ADC_CDR2_RDATA_ALT_24 0x01000000
  #define ADC_CDR2_RDATA_ALT_25 0x02000000
  #define ADC_CDR2_RDATA_ALT_26 0x04000000
  #define ADC_CDR2_RDATA_ALT_27 0x08000000
  #define ADC_CDR2_RDATA_ALT_28 0x10000000
  #define ADC_CDR2_RDATA_ALT_29 0x20000000
  #define ADC_CDR2_RDATA_ALT_30 0x40000000
  #define ADC_CDR2_RDATA_ALT_31 0x80000000


/*
 *  SDMMC
 */
#define TADR_SDMMC3_BASE    (MCU_AHB2_PERIPH_BASE + 0x4000)
#define TADR_SDMMC1_BASE    (MPU_AHB6_PERIPH_BASE + 0x5000)
#define TADR_SDMMC2_BASE    (MPU_AHB6_PERIPH_BASE + 0x7000)
#define TOFF_SDMMC_POWER    0x0000		/* (RW) SDMMC power control register */
  #define SDMMC_POWER_PWRCTRL   0x00000003	/* PWRCTRL[1:0] bits (Power supply control bits) */
  #define SDMMC_POWER_PWRCTRL_0 0x00000001
  #define SDMMC_POWER_PWRCTRL_1 0x00000002
  #define SDMMC_POWER_VSWITCH   0x00000004	/* Voltage switch sequence start */
  #define SDMMC_POWER_VSWITCHEN 0x00000008	/* Voltage switch procedure enable */
  #define SDMMC_POWER_DIRPOL    0x00000010	/* Data and Command direction signals polarity selection */
#define TOFF_SDMMC_CLKCR    0x0004		/* (RW) SDMMC clock control register */
  #define SDMMC_CLKCR_CLKDIV    0x000003FF	/* Clock divide factor */
  #define SDMMC_CLKCR_PWRSAV    0x00001000	/* Power saving configuration bit */
  #define SDMMC_CLKCR_WIDBUS    0x0000C000	/* WIDBUS[1:0] bits (Wide bus mode enable bit) */
  #define SDMMC_CLKCR_WIDBUS_0  0x00004000
  #define SDMMC_CLKCR_WIDBUS_1  0x00008000
  #define SDMMC_CLKCR_NEGEDGE   0x00010000	/* SDMMC_CK dephasing selection bit */
  #define SDMMC_CLKCR_HWFC_EN   0x00020000	/* HW Flow Control enable */
  #define SDMMC_CLKCR_DDR       0x00040000	/* Data rate signaling selection */
  #define SDMMC_CLKCR_BUSSPEED  0x00080000	/* Bus speed mode selection */
  #define SDMMC_CLKCR_SELCLKRX  0x00300000	/* SELCLKRX[1:0] bits (Receive clock selection) */
  #define SDMMC_CLKCR_SELCLKRX_0 0x00100000
  #define SDMMC_CLKCR_SELCLKRX_1 0x00200000
#define TOFF_SDMMC_ARG      0x0008		/* (RW) SDMMC argument register */
#define TOFF_SDMMC_CMD      0x000C		/* (RW) SDMMC command register */
  #define SDMMC_CMD_CMDINDEX    0x0000003F	/* Command Index */
  #define SDMMC_CMD_CMDTRANS    0x00000040	/* CPSM Treats command as a Data Transfer */
  #define SDMMC_CMD_CMDSTOP     0x00000080	/* CPSM Treats command as a Stop */
  #define SDMMC_CMD_WAITRESP    0x00000300	/* WAITRESP[1:0] bits (Wait for response bits) */
  #define SDMMC_CMD_WAITRESP_0  0x00000100
  #define SDMMC_CMD_WAITRESP_1  0x00000200
  #define SDMMC_CMD_WAITINT     0x00000400	/* CPSM Waits for Interrupt Request */
  #define SDMMC_CMD_WAITPEND    0x00000800	/* CPSM Waits for ends of data transfer (CmdPend internal signal) */
  #define SDMMC_CMD_CPSMEN      0x00001000	/* Command path state machine (CPSM) Enable bit */
  #define SDMMC_CMD_DTHOLD      0x00002000	/* Hold new data block transmission and reception in the DPSM */
  #define SDMMC_CMD_BOOTMODE    0x00004000	/* Boot mode */
  #define SDMMC_CMD_BOOTEN      0x00008000	/* Enable Boot mode procedure */
  #define SDMMC_CMD_CMDSUSPEND  0x00010000	/* CPSM Treats command as a Suspend or Resume command */
#define TOFF_SDMMC_RESPCMD  0x0010		/* (R)  SDMMC command response register */
  #define SDMMC_RESPCMD_RESPCMD 0x0000003F	/* Response command index */
#define TOFF_SDMMC_RESP1    0x0014		/* (R)  SDMMC response 1 register */
#define TOFF_SDMMC_RESP2    0x0018		/* (R)  SDMMC response 2 register */
#define TOFF_SDMMC_RESP3    0x001C		/* (R)  SDMMC response 3 register */
#define TOFF_SDMMC_RESP4    0x0020		/* (R)  SDMMC response 4 register */
#define TOFF_SDMMC_DTIMER   0x0024		/* (RW) SDMMC data timer register */
#define TOFF_SDMMC_DLEN     0x0028		/* (RW) SDMMC data length register */
  #define SDMMC_DLEN_DATALENGTH 0x01FFFFFF	/* Data length value */
#define TOFF_SDMMC_DCTRL    0x002C		/* (RW) SDMMC data control register */
  #define SDMMC_DCTRL_DTEN      0x00000001	/* Data transfer enabled bit */
  #define SDMMC_DCTRL_DTDIR     0x00000002	/* Data transfer direction selection */
  #define SDMMC_DCTRL_DTMODE    0x0000000C	/* DTMODE[1:0] Data transfer mode selection */
  #define SDMMC_DCTRL_DTMODE_0  0x00000004
  #define SDMMC_DCTRL_DTMODE_1  0x00000008
  #define SDMMC_DCTRL_DBLOCKSIZE   0x000000F0	/* DBLOCKSIZE[3:0] bits (Data block size) */
  #define SDMMC_DCTRL_DBLOCKSIZE_0 0x00000010
  #define SDMMC_DCTRL_DBLOCKSIZE_1 0x00000020
  #define SDMMC_DCTRL_DBLOCKSIZE_2 0x00000040
  #define SDMMC_DCTRL_DBLOCKSIZE_3 0x00000080
  #define SDMMC_DCTRL_RWSTART   0x00000100	/* Read wait start */
  #define SDMMC_DCTRL_RWSTOP    0x00000200	/* Read wait stop */
  #define SDMMC_DCTRL_RWMOD     0x00000400	/* Read wait mode */
  #define SDMMC_DCTRL_SDIOEN    0x00000800	/* SD I/O enable functions */
  #define SDMMC_DCTRL_BOOTACKEN 0x00001000	/* Enable the reception of the Boot Acknowledgment */
  #define SDMMC_DCTRL_FIFORST   0x00002000	/* FIFO reset */
#define TOFF_SDMMC_DCOUNT   0x0030		/* (R)  SDMMC data counter register */
  #define SDMMC_DCOUNT_DATACOUNT 0x01FFFFFF	/* Data count value */
#define TOFF_SDMMC_STA      0x0034		/* (R)  SDMMC status register */
  #define SDMMC_STA_CCRCFAIL    0x00000001	/* Command response received (CRC check failed)  */
  #define SDMMC_STA_DCRCFAIL    0x00000002	/* Data block sent/received (CRC check failed)   */
  #define SDMMC_STA_CTIMEOUT    0x00000004	/* Command response timeout */
  #define SDMMC_STA_DTIMEOUT    0x00000008	/* Data timeout */
  #define SDMMC_STA_TXUNDERR    0x00000010	/* Transmit FIFO underrun error */
  #define SDMMC_STA_RXOVERR     0x00000020	/* Received FIFO overrun error */
  #define SDMMC_STA_CMDREND     0x00000040	/* Command response received (CRC check passed) */
  #define SDMMC_STA_CMDSENT     0x00000080	/* Command sent (no response required) */
  #define SDMMC_STA_DATAEND     0x00000100	/* Data end (data counter, SDIDCOUNT, is zero) */
  #define SDMMC_STA_DHOLD       0x00000200	/* Data transfer Hold */
  #define SDMMC_STA_DBCKEND     0x00000400	/* Data block sent/received (CRC check passed) */
  #define SDMMC_STA_DABORT      0x00000800	/* Data transfer aborted by CMD12 */
  #define SDMMC_STA_CPSMACT     0x00001000	/* Data path state machine active */
  #define SDMMC_STA_DPSMACT     0x00002000	/* Command path state machine active */
  #define SDMMC_STA_TXFIFOHE    0x00004000	/* Transmit FIFO Half Empty: at least 8 words can be written into the FIFO */
  #define SDMMC_STA_RXFIFOHF    0x00008000	/* Receive FIFO Half Full: there are at least 8 words in the FIFO */
  #define SDMMC_STA_TXFIFOF     0x00010000	/* Transmit FIFO full */
  #define SDMMC_STA_RXFIFOF     0x00020000	/* Receive FIFO full */
  #define SDMMC_STA_TXFIFOE     0x00040000	/* Transmit FIFO empty */
  #define SDMMC_STA_RXFIFOE     0x00080000	/* Receive FIFO empty */
  #define SDMMC_STA_BUSYD0      0x00100000	/* Inverted value of SDMMC_D0 line (Busy) */
  #define SDMMC_STA_BUSYD0END   0x00200000	/* End of SDMMC_D0 Busy following a CMD response detected */
  #define SDMMC_STA_SDIOIT      0x00400000	/* SDIO interrupt received */
  #define SDMMC_STA_ACKFAIL     0x00800000	/* Boot Acknowledgment received (BootAck check fail) */
  #define SDMMC_STA_ACKTIMEOUT  0x01000000	/* Boot Acknowledgment timeout */
  #define SDMMC_STA_VSWEND      0x02000000	/* Voltage switch critical timing section completion */
  #define SDMMC_STA_CKSTOP      0x04000000	/* SDMMC_CK stopped in Voltage switch procedure */
  #define SDMMC_STA_IDMATE      0x08000000	/* IDMA transfer error */
  #define SDMMC_STA_IDMABTC     0x10000000	/* IDMA buffer transfer complete */
#define TOFF_SDMMC_ICR      0x0038		/* (RW) SDMMC interrupt clear register */
  #define SDMMC_ICR_CCRCFAILC   0x00000001	/* CCRCFAIL flag clear bit */
  #define SDMMC_ICR_DCRCFAILC   0x00000002	/* DCRCFAIL flag clear bit */
  #define SDMMC_ICR_CTIMEOUTC   0x00000004	/* CTIMEOUT flag clear bit */
  #define SDMMC_ICR_DTIMEOUTC   0x00000008	/* DTIMEOUT flag clear bit */
  #define SDMMC_ICR_TXUNDERRC   0x00000010	/* TXUNDERR flag clear bit */
  #define SDMMC_ICR_RXOVERRC    0x00000020	/* RXOVERR flag clear bit */
  #define SDMMC_ICR_CMDRENDC    0x00000040	/* CMDREND flag clear bit */
  #define SDMMC_ICR_CMDSENTC    0x00000080	/* CMDSENT flag clear bit */
  #define SDMMC_ICR_DATAENDC    0x00000100	/* DATAEND flag clear bit */
  #define SDMMC_ICR_DHOLDC      0x00000200	/* DHOLD flag clear bit */
  #define SDMMC_ICR_DBCKENDC    0x00000400	/* DBCKEND flag clear bit */
  #define SDMMC_ICR_DABORTC     0x00000800	/* DABORTC flag clear bit */
  #define SDMMC_ICR_BUSYD0ENDC  0x00200000	/* BUSYD0ENDC flag clear bit */
  #define SDMMC_ICR_SDIOITC     0x00400000	/* SDIOIT flag clear bit */
  #define SDMMC_ICR_ACKFAILC    0x00800000	/* ACKFAILC flag clear bit */
  #define SDMMC_ICR_ACKTIMEOUTC 0x01000000	/* ACKTIMEOUTC flag clear bit */
  #define SDMMC_ICR_VSWENDC     0x02000000	/* VSWENDC flag clear bit */
  #define SDMMC_ICR_CKSTOPC     0x04000000	/* CKSTOPC flag clear bit */
  #define SDMMC_ICR_IDMATEC     0x08000000	/* IDMATEC flag clear bit */
  #define SDMMC_ICR_IDMABTCC    0x10000000	/* IDMABTCC flag clear bit */
#define TOFF_SDMMC_MASK     0x003C		/* (RW) SDMMC mask register */
  #define SDMMC_MASK_CCRCFAILIE 0x00000001	/* Command CRC Fail Interrupt Enable */
  #define SDMMC_MASK_DCRCFAILIE 0x00000002	/* Data CRC Fail Interrupt Enable */
  #define SDMMC_MASK_CTIMEOUTIE 0x00000004	/* Command TimeOut Interrupt Enable */
  #define SDMMC_MASK_DTIMEOUTIE 0x00000008	/* Data TimeOut Interrupt Enable */
  #define SDMMC_MASK_TXUNDERRIE 0x00000010	/* Tx FIFO UnderRun Error Interrupt Enable */
  #define SDMMC_MASK_RXOVERRIE  0x00000020	/* Rx FIFO OverRun Error Interrupt Enable */
  #define SDMMC_MASK_CMDRENDIE  0x00000040	/* Command Response Received Interrupt Enable */
  #define SDMMC_MASK_CMDSENTIE  0x00000080	/* Command Sent Interrupt Enable */
  #define SDMMC_MASK_DATAENDIE  0x00000100	/* Data End Interrupt Enable */
  #define SDMMC_MASK_DHOLDIE    0x00000200	/* Data Hold Interrupt Enable */
  #define SDMMC_MASK_DBCKENDIE  0x00000400	/* Data Block End Interrupt Enable */
  #define SDMMC_MASK_DABORTIE   0x00000800	/* Data transfer aborted interrupt enable */
  #define SDMMC_MASK_TXFIFOHEIE 0x00004000	/* Tx FIFO Half Empty interrupt Enable */
  #define SDMMC_MASK_RXFIFOHFIE 0x00008000	/* Rx FIFO Half Full interrupt Enable */
  #define SDMMC_MASK_RXFIFOFIE  0x00020000	/* Rx FIFO Full interrupt Enable */
  #define SDMMC_MASK_TXFIFOEIE  0x00040000	/* Tx FIFO Empty interrupt Enable */
  #define SDMMC_MASK_BUSYD0ENDIE 0x00200000	/* BUSYD0ENDIE interrupt Enable */
  #define SDMMC_MASK_SDIOITIE   0x00400000	/* SDMMC Mode Interrupt Received interrupt Enable */
  #define SDMMC_MASK_ACKFAILIE  0x00800000	/* Acknowledgment Fail Interrupt Enable */
  #define SDMMC_MASK_ACKTIMEOUTIE 0x01000000	/* Acknowledgment timeout Interrupt Enable */
  #define SDMMC_MASK_VSWENDIE   0x02000000	/* Voltage switch critical timing section completion Interrupt Enable */
  #define SDMMC_MASK_CKSTOPIE   0x04000000	/* Voltage Switch clock stopped Interrupt Enable */
  #define SDMMC_MASK_IDMABTCIE  0x10000000	/* IDMA buffer transfer complete Interrupt Enable */
#define TOFF_SDMMC_ACKTIME  0x0040		/* (RW) SDMMC Acknowledgement timer register */
#define TOFF_SDMMC_IDMACTRL 0x0050		/* (RW) SDMMC DMA control register */
  #define SDMMC_IDMA_IDMAEN     0x00000001	/* Enable the internal DMA of the SDMMC peripheral */
  #define SDMMC_IDMA_IDMABMODE  0x00000002	/* Enable double buffer mode for IDMA */
  #define SDMMC_IDMA_IDMABACT   0x00000004	/* Uses buffer 1 when double buffer mode is selected */
#define TOFF_SDMMC_IDMABSIZE 0x0054		/* (RW) SDMMC DMA buffer size register */
#define TOFF_SDMMC_IDMABASE0 0x0058		/* (RW) SDMMC DMA buffer 0 base address register */
#define TOFF_SDMMC_IDMABASE1 0x005C		/* (RW) SDMMC DMA buffer 1 base address register */
#define TOFF_SDMMC_IDMALAR  0x0064		/* (RW) SDMMC DMA linked list address register */
#define TOFF_SDMMC_IDMABAR  0x0068		/* (RW) SDMMC DMA linked list memory base register */
#define TOFF_SDMMC_FIFO     0x0080		/* (RW) SDMMC data FIFO register[0x80 - 0xBC] */
#define TOFF_SDMMC_VERR     0x03F4		/* (R)  SDMMC version register */
  #define SDMMC_VERR_MINREV     0x0000000F	/* Minor Revision number */
  #define SDMMC_VERR_MAJREV     0x000000F0	/*  Major Revision number */
#define TOFF_SDMMC_IPIDR    0x03F8		/* (R)  SDMMC identification register */
#define TOFF_SDMMC_SIDR     0x03FC		/* (R)  SDMMCsize ID register */

#define TADR_DLYB_SDMMC3_BASE   (MCU_AHB2_PERIPH_BASE + 0x5000)
#define TADR_DLYB_SDMMC1_BASE   (MPU_AHB6_PERIPH_BASE + 0x6000)
#define TADR_DLYB_SDMMC2_BASE   (MPU_AHB6_PERIPH_BASE + 0x8000)
#define TADR_DLYB_QSPI_BASE     (MPU_AHB6_PERIPH_BASE + 0x4000)
#define TOFF_DLYB_CR        0x0000		/* (RW) DELAY BLOCK control register */
  #define DLYB_CR_DEN           0x00000001	/* Delay Block enable */
  #define DLYB_CR_SEN           0x00000002	/* Sampler length enable */
#define TOFF_DLYB_CFGR      0x0004		/* (RW) DELAY BLOCK configuration register */
  #define DLYB_CFGR_SEL         0x0000000F	/* Select the phase for the Output clock[3:0] */
  #define DLYB_CFGR_SEL_0       0x00000001
  #define DLYB_CFGR_SEL_1       0x00000002
  #define DLYB_CFGR_SEL_2       0x00000003
  #define DLYB_CFGR_SEL_3       0x00000008
  #define DLYB_CFGR_UNIT        0x00007F00	/* Delay Defines the delay of a Unit delay cell[6:0] */
  #define DLYB_CFGR_UNIT_0      0x00000100
  #define DLYB_CFGR_UNIT_1      0x00000200
  #define DLYB_CFGR_UNIT_2      0x00000400
  #define DLYB_CFGR_UNIT_3      0x00000800
  #define DLYB_CFGR_UNIT_4      0x00001000
  #define DLYB_CFGR_UNIT_5      0x00002000
  #define DLYB_CFGR_UNIT_6      0x00004000
  #define DLYB_CFGR_LNG         0x0FFF0000	/* Delay line length value[11:0] */
  #define DLYB_CFGR_LNG_0       0x00010000
  #define DLYB_CFGR_LNG_1       0x00020000
  #define DLYB_CFGR_LNG_2       0x00040000
  #define DLYB_CFGR_LNG_3       0x00080000
  #define DLYB_CFGR_LNG_4       0x00100000
  #define DLYB_CFGR_LNG_5       0x00200000
  #define DLYB_CFGR_LNG_6       0x00400000
  #define DLYB_CFGR_LNG_7       0x00800000
  #define DLYB_CFGR_LNG_8       0x01000000
  #define DLYB_CFGR_LNG_9       0x02000000
  #define DLYB_CFGR_LNG_10      0x04000000
  #define DLYB_CFGR_LNG_11      0x08000000
  #define DLYB_CFGR_LNGF        0x80000000	/* Length valid flag */
#define TOFF_DLYB_VERR      0x03F4		/* (R)  DELAY BLOCK Version register */
  #define DLYB_VERR_MINREV      0x0000000F	/* Minor Revision number */
  #define DLYB_VERR_MAJREV      0x000000F0	/* Major Revision number */
#define TOFF_DLYB_IPIDR     0x03F8		/* (R)  DELAY BLOCK Identification register */
#define TOFF_DLYB_SIDR      0x03FC		/* (R)  DELAY BLOCK Size ID register */


/*
 *  USB OTG
 */
#define TADR_USB_OTG_BASE   (MCU_AHB2_PERIPH_BASE + 0x1000000)
#define TOFF_USBO_GOTGCTL   0x0000		/* (RW) USB_OTG Control and Status Register */
  #define USB_OTG_GOTGCTL_SRQSCS    0x00000001	/* Session request success */
  #define USB_OTG_GOTGCTL_SRQ       0x00000002	/* Session request */
  #define USB_OTG_GOTGCTL_VBVALOEN  0x00000004	/* VBUS valid override enable */
  #define USB_OTG_GOTGCTL_VBVALOVAL 0x00000008	/* VBUS valid override value */
  #define USB_OTG_GOTGCTL_AVALOEN   0x00000010	/* A-peripheral session valid override enable */
  #define USB_OTG_GOTGCTL_AVALOVAL  0x00000020	/* A-peripheral session valid override value */
  #define USB_OTG_GOTGCTL_BVALOEN   0x00000040	/* B-peripheral session valid override enable */
  #define USB_OTG_GOTGCTL_BVALOVAL  0x00000080	/* B-peripheral session valid override value  */
  #define USB_OTG_GOTGCTL_HNGSCS    0x00000100	/* Host negotiation success */
  #define USB_OTG_GOTGCTL_HNPRQ     0x00000200	/* HNP request */
  #define USB_OTG_GOTGCTL_HSHNPEN   0x00000400	/* Host set HNP enable */
  #define USB_OTG_GOTGCTL_DHNPEN    0x00000800	/* Device HNP enabled */
  #define USB_OTG_GOTGCTL_EHEN      0x00001000	/* Embedded host enable */
  #define USB_OTG_GOTGCTL_CIDSTS    0x00010000	/* Connector ID status */
  #define USB_OTG_GOTGCTL_DBCT      0x00020000	/* Long/short debounce time */
  #define USB_OTG_GOTGCTL_ASVLD     0x00040000	/* A-session valid */
  #define USB_OTG_GOTGCTL_BSVLD     0x00080000	/* B-session valid */
  #define USB_OTG_GOTGCTL_OTGVER    0x00100000	/* OTG version  */
#define TOFF_USBO_GOTGINT   0x0004		/* (RW) USB_OTG Interrupt Register */
  #define USB_OTG_GOTGINT_SEDET     0x00000004	/* Session end detected */
  #define USB_OTG_GOTGINT_SRSSCHG   0x00000100	/* Session request success status change */
  #define USB_OTG_GOTGINT_HNSSCHG   0x00000200	/* Host negotiation success status change */
  #define USB_OTG_GOTGINT_HNGDET    0x00020000	/* Host negotiation detected */
  #define USB_OTG_GOTGINT_ADTOCHG   0x00040000	/* A-device timeout change */
  #define USB_OTG_GOTGINT_DBCDNE    0x00080000	/* Debounce done */
#define TOFF_USBO_GAHBCFG   0x0008		/* (RW) Core AHB Configuration Register */
  #define USB_OTG_GAHBCFG_GINT      0x00000001	/* Global interrupt mask */
  #define USB_OTG_GAHBCFG_HBSTLEN   0x0000001E	/* Burst length/type */
  #define USB_OTG_GAHBCFG_HBSTLEN_0 0x00000002	/* Bit 0 */
  #define USB_OTG_GAHBCFG_HBSTLEN_1 0x00000004	/* Bit 1 */
  #define USB_OTG_GAHBCFG_HBSTLEN_2 0x00000008	/* Bit 2 */
  #define USB_OTG_GAHBCFG_HBSTLEN_3 0x00000010	/* Bit 3 */
  #define USB_OTG_GAHBCFG_DMAEN     0x00000020	/* DMA enable */
  #define USB_OTG_GAHBCFG_TXFELVL   0x00000080	/* TxFIFO empty level */
  #define USB_OTG_GAHBCFG_PTXFELVL  0x00000100	/* Periodic TxFIFO empty level */
#define TOFF_USBO_GUSBCFG   0x000C		/* (RW) Core USB Configuration Register */
  #define USB_OTG_GUSBCFG_TOCAL     0x00000007	/* FS timeout calibration */
  #define USB_OTG_GUSBCFG_TOCAL_0   0x00000001	/* Bit 0 */
  #define USB_OTG_GUSBCFG_TOCAL_1   0x00000002	/* Bit 1 */
  #define USB_OTG_GUSBCFG_TOCAL_2   0x00000004	/* Bit 2 */
  #define USB_OTG_GUSBCFG_ULPI_UTMI_SEL 0x00000010	/* ULPI or UTMI+ Select (ULPI_UTMI_Sel) */
  #define USB_OTG_GUSBCFG_PHYSEL    0x00000040	/* USB 2.0 high-speed ULPI PHY or USB 1.1 full-speed serial transceiver select */
  #define USB_OTG_GUSBCFG_SRPCAP    0x00000100	/* SRP-capable */
  #define USB_OTG_GUSBCFG_HNPCAP    0x00000200	/* HNP-capable */
  #define USB_OTG_GUSBCFG_TRDT      0x00003C00	/* USB turnaround time */
  #define USB_OTG_GUSBCFG_TRDT_0    0x00000400	/* Bit 0 */
  #define USB_OTG_GUSBCFG_TRDT_1    0x00000800	/* Bit 1 */
  #define USB_OTG_GUSBCFG_TRDT_2    0x00001000	/* Bit 2 */
  #define USB_OTG_GUSBCFG_TRDT_3    0x00002000	/* Bit 3 */
  #define USB_OTG_GUSBCFG_PHYLPCS   0x00008000	/* PHY Low-power clock select */
  #define USB_OTG_GUSBCFG_ULPIFSLS  0x00020000	/* ULPI FS/LS select */
  #define USB_OTG_GUSBCFG_ULPIAR    0x00040000	/* ULPI Auto-resume */
  #define USB_OTG_GUSBCFG_ULPICSM   0x00080000	/* ULPI Clock SuspendM */
  #define USB_OTG_GUSBCFG_ULPIEVBUSD 0x00100000	/* ULPI External VBUS Drive */
  #define USB_OTG_GUSBCFG_ULPIEVBUSI 0x00200000	/* ULPI external VBUS indicator */
  #define USB_OTG_GUSBCFG_TSDPS     0x00400000	/* TermSel DLine pulsing selection */
  #define USB_OTG_GUSBCFG_PCCI      0x00800000	/* Indicator complement */
  #define USB_OTG_GUSBCFG_PTCI      0x01000000	/* Indicator pass through */
  #define USB_OTG_GUSBCFG_ULPIIPD   0x02000000	/* ULPI interface protect disable */
  #define USB_OTG_GUSBCFG_FHMOD     0x20000000	/* Forced host mode */
  #define USB_OTG_GUSBCFG_FDMOD     0x40000000	/* Forced peripheral mode */
  #define USB_OTG_GUSBCFG_CTXPKT    0x80000000	/* Corrupt Tx packet */
#define TOFF_USBO_GRSTCTL    0x0010		/* (RW) Core Reset Register */
  #define USB_OTG_GRSTCTL_CSRST     0x00000001	/* Core soft reset */
  #define USB_OTG_GRSTCTL_HSRST     0x00000002	/* HCLK soft reset */
  #define USB_OTG_GRSTCTL_FCRST     0x00000004	/* Host frame counter reset */
  #define USB_OTG_GRSTCTL_RXFFLSH   0x00000010	/* RxFIFO flush */
  #define USB_OTG_GRSTCTL_TXFFLSH   0x00000020	/* TxFIFO flush */
  #define USB_OTG_GRSTCTL_TXFNUM    0x000007C0	/* TxFIFO number */
  #define USB_OTG_GRSTCTL_TXFNUM_0  0x00000040	/* Bit 0 */
  #define USB_OTG_GRSTCTL_TXFNUM_1  0x00000080	/* Bit 1 */
  #define USB_OTG_GRSTCTL_TXFNUM_2  0x00000100	/* Bit 2 */
  #define USB_OTG_GRSTCTL_TXFNUM_3  0x00000200	/* Bit 3 */
  #define USB_OTG_GRSTCTL_TXFNUM_4  0x00000400	/* Bit 4 */
  #define USB_OTG_GRSTCTL_DMAREQ    0x40000000	/* DMA request signal */
  #define USB_OTG_GRSTCTL_AHBIDL    0x80000000	/* AHB master idle */
#define TOFF_USBO_GINTSTS   0x0014		/* (RW)  Core Interrupt Register */
  #define USB_OTG_GINTSTS_CMOD      0x00000001	/* Current mode of operation */
  #define USB_OTG_GINTSTS_MMIS      0x00000002	/* Mode mismatch interrupt */
  #define USB_OTG_GINTSTS_OTGINT    0x00000004	/* OTG interrupt */
  #define USB_OTG_GINTSTS_SOF       0x00000008	/* Start of frame */
  #define USB_OTG_GINTSTS_RXFLVL    0x00000010	/* RxFIFO nonempty */
  #define USB_OTG_GINTSTS_NPTXFE    0x00000020	/* Nonperiodic TxFIFO empty */
  #define USB_OTG_GINTSTS_GINAKEFF  0x00000040	/* Global IN nonperiodic NAK effective */
  #define USB_OTG_GINTSTS_BOUTNAKEFF 0x00000080	/* Global OUT NAK effective */
  #define USB_OTG_GINTSTS_ESUSP     0x00000400	/* Early suspend */
  #define USB_OTG_GINTSTS_USBSUSP   0x00000800	/* USB suspend */
  #define USB_OTG_GINTSTS_USBRST    0x00001000	/* USB reset */
  #define USB_OTG_GINTSTS_ENUMDNE   0x00002000	/* Enumeration done */
  #define USB_OTG_GINTSTS_ISOODRP   0x00004000	/* Isochronous OUT packet dropped interrupt */
  #define USB_OTG_GINTSTS_EOPF      0x00008000	/* End of periodic frame interrupt */
  #define USB_OTG_GINTSTS_IEPINT    0x00040000	/* IN endpoint interrupt */
  #define USB_OTG_GINTSTS_OEPINT    0x00080000	/* OUT endpoint interrupt */
  #define USB_OTG_GINTSTS_IISOIXFR  0x00100000	/* Incomplete isochronous IN transfer */
  #define USB_OTG_GINTSTS_PXFR_INCOMPISOOUT 0x00200000	/* Incomplete periodic transfer */
  #define USB_OTG_GINTSTS_DATAFSUSP 0x00400000	/* Data fetch suspended */
  #define USB_OTG_GINTSTS_RSTDET    0x00800000	/* Reset detected interrupt */
  #define USB_OTG_GINTSTS_HPRTINT   0x01000000	/* Host port interrupt */
  #define USB_OTG_GINTSTS_HCINT     0x02000000	/* Host channels interrupt */
  #define USB_OTG_GINTSTS_PTXFE     0x04000000	/* Periodic TxFIFO empty */
  #define USB_OTG_GINTSTS_LPMINT    0x08000000	/* LPM interrupt                                  */
  #define USB_OTG_GINTSTS_CIDSCHG   0x10000000	/* Connector ID status change */
  #define USB_OTG_GINTSTS_DISCINT   0x20000000	/* Disconnect detected interrupt */
  #define USB_OTG_GINTSTS_SRQINT    0x40000000	/* Session request/new session detected interrupt */
  #define USB_OTG_GINTSTS_WKUINT    0x80000000	/* Resume/remote wakeup detected interrupt */
#define TOFF_USBO_GINTMSK   0x0018		/* (RW)  Core Interrupt Mask Register */
  #define USB_OTG_GINTMSK_MMISM     0x00000002	/* Mode mismatch interrupt mask */
  #define USB_OTG_GINTMSK_OTGINT    0x00000004	/* OTG interrupt mask */
  #define USB_OTG_GINTMSK_SOFM      0x00000008	/* Start of frame mask */
  #define USB_OTG_GINTMSK_RXFLVLM   0x00000010	/* Receive FIFO nonempty mask */
  #define USB_OTG_GINTMSK_NPTXFEM   0x00000020	/* Nonperiodic TxFIFO empty mask */
  #define USB_OTG_GINTMSK_GINAKEFFM 0x00000040	/* Global nonperiodic IN NAK effective mask */
  #define USB_OTG_GINTMSK_GONAKEFFM 0x00000080	/* Global OUT NAK effective mask */
  #define USB_OTG_GINTMSK_ESUSPM    0x00000400	/* Early suspend mask */
  #define USB_OTG_GINTMSK_USBSUSPM  0x00000800	/* USB suspend mask */
  #define USB_OTG_GINTMSK_USBRST    0x00001000	/* USB reset mask */
  #define USB_OTG_GINTMSK_ENUMDNEM  0x00002000	/* Enumeration done mask */
  #define USB_OTG_GINTMSK_ISOODRPM  0x00004000	/* Isochronous OUT packet dropped interrupt mask */
  #define USB_OTG_GINTMSK_EOPFM     0x00008000	/* End of periodic frame interrupt mask */
  #define USB_OTG_GINTMSK_EPMISM    0x00020000	/* Endpoint mismatch interrupt mask */
  #define USB_OTG_GINTMSK_IEPINT    0x00040000	/* IN endpoints interrupt mask */
  #define USB_OTG_GINTMSK_OEPINT    0x00080000	/* OUT endpoints interrupt mask */
  #define USB_OTG_GINTMSK_IISOIXFRM 0x00100000	/* Incomplete isochronous IN transfer mask */
  #define USB_OTG_GINTMSK_PXFRM_IISOOXFRM 0x00200000	/* Incomplete periodic transfer mask */
  #define USB_OTG_GINTMSK_FSUSPM    0x00400000	/* Data fetch suspended mask */
  #define USB_OTG_GINTMSK_RSTDEM    0x00800000	/* Reset detected interrupt mask */
  #define USB_OTG_GINTMSK_PRTIM     0x01000000	/* Host port interrupt mask */
  #define USB_OTG_GINTMSK_HCIM      0x02000000	/* Host channels interrupt mask */
  #define USB_OTG_GINTMSK_PTXFEM    0x04000000	/* Periodic TxFIFO empty mask */
  #define USB_OTG_GINTMSK_LPMINTM   0x08000000	/* LPM interrupt Mask */
  #define USB_OTG_GINTMSK_CIDSCHGM  0x10000000	/* Connector ID status change mask */
  #define USB_OTG_GINTMSK_DISCINT   0x20000000	/* Disconnect detected interrupt mask */
  #define USB_OTG_GINTMSK_SRQIM     0x40000000	/* Session request/new session detected interrupt mask */
  #define USB_OTG_GINTMSK_WUIM      0x80000000	/* Resume/remote wakeup detected interrupt mask */
#define TOFF_USBO_GRXSTSR   0x001C		/* (RW) Receive Sts Q Read Register */
#define TOFF_USBO_GRXSTSP   0x0020		/* (RW) Receive Sts Q Read & POP Register */
  #define USB_OTG_GRXSTSP_EPNUM     0x0000000F	/* IN EP interrupt mask bits */
  #define USB_OTG_GRXSTSP_BCNT      0x00007FF0	/* OUT EP interrupt mask bits */
  #define USB_OTG_GRXSTSP_DPID      0x00018000	/* OUT EP interrupt mask bits */
  #define USB_OTG_GRXSTSP_PKTSTS    0x001E0000	/* OUT EP interrupt mask bits */
#define TOFF_USBO_GRXFSIZ   0x0024		/* (RW) Receive FIFO Size Register */
  #define USB_OTG_GRXFSIZ_RXFD      0x0000FFFF	/* RxFIFO depth */
#define TOFF_USBO_DIEPTXF0_HNPTXFSIZ 0x0028	/* (RW) EP0 / Non Periodic Tx FIFO Size Register */
  #define USB_OTG_NPTXFSA           0x0000FFFF	/* Nonperiodic transmit RAM start address */
  #define USB_OTG_NPTXFD            0xFFFF0000	/* Nonperiodic TxFIFO depth */
  #define USB_OTG_TX0FSA            0x0000FFFF	/* Endpoint 0 transmit RAM start address */
  #define USB_OTG_TX0FD             0xFFFF0000	/* Endpoint 0 TxFIFO depth */
#define TOFF_USBO_HNPTXSTS  0x002C		/* (RW) Non Periodic Tx FIFO/Queue Sts Register */
#define TOFF_USBO_GI2CCTL   0x0030		/* (RW) I2C Access Register */
#define TOFF_USBO_GCCFG     0x0038		/* (RW) General Purpose IO Register */
  #define USB_OTG_GCCFG_DCDET       0x00000001	/* Data contact detection (DCD) status */
  #define USB_OTG_GCCFG_PDET        0x00000002	/* Primary detection (PD) status */
  #define USB_OTG_GCCFG_SDET        0x00000004	/* Secondary detection (SD) status */
  #define USB_OTG_GCCFG_PS2DET      0x00000008	/* DM pull-up detection status */
  #define USB_OTG_GCCFG_PWRDWN      0x00010000	/* Power down */
  #define USB_OTG_GCCFG_BCDEN       0x00020000	/* Battery charging detector (BCD) enable */
  #define USB_OTG_GCCFG_DCDEN       0x00040000	/* Data contact detection (DCD) mode enable*/
  #define USB_OTG_GCCFG_PDEN        0x00080000	/* Primary detection (PD) mode enable*/
  #define USB_OTG_GCCFG_SDEN        0x00100000	/* Secondary detection (SD) mode enable */
  #define USB_OTG_GCCFG_VBDEN       0x00200000	/* Secondary detection (SD) mode enable */
  #define USB_OTG_GCCFG_OTGIDEN     0x00400000	/* OTG Id enable */
  #define USB_OTG_GCCFG_PHYHSEN     0x00800000	/* HS PHY enable */
#define TOFF_USBO_CID       0x003C		/* (RW) User ID Register */
  #define USB_OTG_CID_PRODUCT_ID    0xFFFFFFFF	/* Product ID field */
#define TOFF_USBO_GLPMCFG   0x0054		/* (RW) LPM Register */
  #define USB_OTG_GLPMCFG_LPMEN     0x00000001	/* LPM support enable */
  #define USB_OTG_GLPMCFG_LPMACK    0x00000002	/* LPM Token acknowledge enable */
  #define USB_OTG_GLPMCFG_BESL      0x0000003C	/* BESL value received with last ACKed LPM Token */
  #define USB_OTG_GLPMCFG_REMWAKE   0x00000040	/* bRemoteWake value received with last ACKed LPM Token */
  #define USB_OTG_GLPMCFG_L1SSEN    0x00000080	/* L1 shallow sleep enable */
  #define USB_OTG_GLPMCFG_BESLTHRS  0x00000F00	/* BESL threshold */
  #define USB_OTG_GLPMCFG_L1DSEN    0x00001000	/* L1 deep sleep enable */
  #define USB_OTG_GLPMCFG_LPMRSP    0x00006000	/* LPM response */
  #define USB_OTG_GLPMCFG_SLPSTS    0x00008000	/* Port sleep status */
  #define USB_OTG_GLPMCFG_L1RSMOK   0x00010000	/* Sleep State Resume OK */
  #define USB_OTG_GLPMCFG_LPMCHIDX  0x001E0000	/* LPM Channel Index */
  #define USB_OTG_GLPMCFG_LPMRCNT   0x00E00000	/* LPM retry count */
  #define USB_OTG_GLPMCFG_SNDLPM    0x01000000	/* Send LPM transaction */
  #define USB_OTG_GLPMCFG_LPMRCNTSTS 0x0E000000	/* LPM retry count status */
  #define USB_OTG_GLPMCFG_ENBESL    0x10000000	/* Enable best effort service latency */
#define TOFF_USBO_GDFIFOCFG 0x005C		/* (RW) DFIFO Software Config Register */
#define TOFF_USBO_HPTXFSIZ  0x0100		/* (RW) Host Periodic Tx FIFO Size Reg */
  #define USB_OTG_HPTXFSIZ_PTXSA    0x0000FFFF	/* Host periodic TxFIFO start address */
  #define USB_OTG_HPTXFSIZ_PTXFD    0xFFFF0000	/* Host periodic TxFIFO depth */
#define TOFF_USBO_DIEPTXF   0x0104		/* (RW) dev Periodic Transmit FIFO x 15 */
  #define USB_OTG_DIEPTXF_INEPTXSA  0x0000FFFF	/* IN endpoint FIFOx transmit RAM start address */
  #define USB_OTG_DIEPTXF_INEPTXFD  0xFFFF0000	/* IN endpoint TxFIFO depth */

/*
 *  USB DEVICE(OTG)
 */
#define TADR_USB_DEVICE_BASE (TADR_USB_OTG_BASE+USB_OTG_DEVICE_BASE)
#define TOFF_USBD_DCFG      0x0000		/* (RW) dev Configuration Register */
  #define USB_OTG_DCFG_DSPD         0x00000003	/* Device speed */
  #define USB_OTG_DCFG_DSPD_0       0x00000001	/* Bit 0 */
  #define USB_OTG_DCFG_DSPD_1       0x00000002	/* Bit 1 */
  #define USB_OTG_DCFG_NZLSOHSK     0x00000004	/* Nonzero-length status OUT handshake */
  #define USB_OTG_DCFG_DAD          0x000007F0	/* Device address */
  #define USB_OTG_DCFG_DAD_0        0x00000010	/* Bit 0 */
  #define USB_OTG_DCFG_DAD_1        0x00000020	/* Bit 1 */
  #define USB_OTG_DCFG_DAD_2        0x00000040	/* Bit 2 */
  #define USB_OTG_DCFG_DAD_3        0x00000080	/* Bit 3 */
  #define USB_OTG_DCFG_DAD_4        0x00000100	/* Bit 4 */
  #define USB_OTG_DCFG_DAD_5        0x00000200	/* Bit 5 */
  #define USB_OTG_DCFG_DAD_6        0x00000400	/* Bit 6 */
  #define USB_OTG_DCFG_PFIVL        0x00001800	/* Periodic (micro)frame interval */
  #define USB_OTG_DCFG_PFIVL_0      0x00000800	/* Bit 0 */
  #define USB_OTG_DCFG_PFIVL_1      0x00001000	/* Bit 1 */
  #define USB_OTG_DCFG_PERSCHIVL    0x03000000	/* Periodic scheduling interval */
  #define USB_OTG_DCFG_PERSCHIVL_0  0x01000000	/* Bit 0 */
  #define USB_OTG_DCFG_PERSCHIVL_1  0x02000000	/* Bit 1 */
#define TOFF_USBD_DCTL      0x0004		/* (RW) dev Control Register */
  #define USB_OTG_DCTL_RWUSIG       0x00000001	/* Remote wakeup signaling */
  #define USB_OTG_DCTL_SDIS         0x00000002	/* Soft disconnect */
  #define USB_OTG_DCTL_GINSTS       0x00000004	/* Global IN NAK status */
  #define USB_OTG_DCTL_GONSTS       0x00000008	/* Global OUT NAK status */
  #define USB_OTG_DCTL_TCTL         0x00000070	/* Test control */
  #define USB_OTG_DCTL_TCTL_0       0x00000010	/* Bit 0 */
  #define USB_OTG_DCTL_TCTL_1       0x00000020	/* Bit 1 */
  #define USB_OTG_DCTL_TCTL_2       0x00000040	/* Bit 2 */
  #define USB_OTG_DCTL_SGINAK       0x00000080	/* Set global IN NAK */
  #define USB_OTG_DCTL_CGINAK       0x00000100	/* Clear global IN NAK */
  #define USB_OTG_DCTL_SGONAK       0x00000200	/* Set global OUT NAK */
  #define USB_OTG_DCTL_CGONAK       0x00000400	/* Clear global OUT NAK */
  #define USB_OTG_DCTL_POPRGDNE     0x00000800	/* Power-on programming done */
#define TOFF_USBD_DSTS      0x0008		/* (RO) dev Status Register (RO) */
  #define USB_OTG_DSTS_SUSPSTS      0x00000001	/* Suspend status */
  #define USB_OTG_DSTS_ENUMSPD      0x00000006	/* Enumerated speed */
  #define USB_OTG_DSTS_ENUMSPD_0    0x00000002	/* Bit 0 */
  #define USB_OTG_DSTS_ENUMSPD_1    0x00000004	/* Bit 1 */
  #define USB_OTG_DSTS_EERR         0x00000008	/* Erratic error */
  #define USB_OTG_DSTS_FNSOF        0x003FFF00	/* Frame number of the received SOF */
#define TOFF_USBD_DIEPMSK   0x0010		/* (RW) dev IN Endpoint Mask */
  #define USB_OTG_DIEPMSK_XFRCM     0x00000001	/* Transfer completed interrupt mask */
  #define USB_OTG_DIEPMSK_EPDM      0x00000002	/* Endpoint disabled interrupt mask */
  #define USB_OTG_DIEPMSK_TOM       0x00000008	/* Timeout condition mask (nonisochronous endpoints) */
  #define USB_OTG_DIEPMSK_ITTXFEMSK 0x00000010	/* IN token received when TxFIFO empty mask */
  #define USB_OTG_DIEPMSK_INEPNMM   0x00000020	/* IN token received with EP mismatch mask */
  #define USB_OTG_DIEPMSK_INEPNEM   0x00000040	/* IN endpoint NAK effective mask */
  #define USB_OTG_DIEPMSK_TXFURM    0x00000100	/* FIFO underrun mask */
  #define USB_OTG_DIEPMSK_BIM       0x00000200	/* BNA interrupt mask */
#define TOFF_USBD_DOEPMSK   0x0014		/* (RW) dev OUT Endpoint Mask */
  #define USB_OTG_DOEPMSK_XFRCM     0x00000001	/* Transfer completed interrupt mask */
  #define USB_OTG_DOEPMSK_EPDM      0x00000002	/* Endpoint disabled interrupt mask */
  #define USB_OTG_DOEPMSK_STUPM     0x00000008	/* SETUP phase done mask */
  #define USB_OTG_DOEPMSK_OTEPDM    0x00000010	/* OUT token received when endpoint disabled mask */
  #define USB_OTG_DOEPMSK_B2BSTUP   0x00000040	/* Back-to-back SETUP packets received mask */
  #define USB_OTG_DOEPMSK_OPEM      0x00000100	/* OUT packet error mask */
  #define USB_OTG_DOEPMSK_BOIM      0x00000200	/* BNA interrupt mask */
#define TOFF_USBD_DAINT     0x0018		/* (RW) dev All Endpoints Itr Register */
  #define USB_OTG_DAINT_IEPINT      0x0000FFFF	/* IN endpoint interrupt bits */
  #define USB_OTG_DAINT_OEPINT      0xFFFF0000	/* OUT endpoint interrupt bits */
#define TOFF_USBD_DAINTMSK  0x001C		/* (RW) dev All Endpoints Itr Mask */
  #define USB_OTG_DAINTMSK_IEPM     0x0000FFFF	/* IN EP interrupt mask bits */
  #define USB_OTG_DAINTMSK_OEPM     0xFFFF0000	/* OUT EP interrupt mask bits */
#define TOFF_USBD_DVBUSDIS  0x0028		/* (RW) dev VBUS discharge Register */
  #define USB_OTG_DVBUSDIS_VBUSDT   0x0000FFFF	/* Device VBUS discharge time */
#define TOFF_USBD_DVBUSPULSE 0x002C		/* (RW) dev VBUS Pulse Register */
  #define USB_OTG_DVBUSPULSE_DVBUSP 0x00000FFF	/* Device VBUS pulsing time */
#define TOFF_USBD_DTHRCTL   0x0030		/* (RW) dev thr */
  #define USB_OTG_DTHRCTL_NONISOTHREN 0x00000001	/* Nonisochronous IN endpoints threshold enable */
  #define USB_OTG_DTHRCTL_ISOTHREN    0x00000002	/* ISO IN endpoint threshold enable */
  #define USB_OTG_DTHRCTL_TXTHRLEN    0x000007FC	/* Transmit threshold length */
  #define USB_OTG_DTHRCTL_TXTHRLEN_0  0x00000004	/* Bit 0 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_1  0x00000008	/* Bit 1 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_2  0x00000010	/* Bit 2 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_3  0x00000020	/* Bit 3 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_4  0x00000040	/* Bit 4 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_5  0x00000080	/* Bit 5 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_6  0x00000100	/* Bit 6 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_7  0x00000200	/* Bit 7 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_8  0x00000400	/* Bit 8 */
  #define USB_OTG_DTHRCTL_RXTHREN     0x00010000	/* Receive threshold enable */
  #define USB_OTG_DTHRCTL_RXTHRLEN    0x03FE0000	/* Receive threshold length */
  #define USB_OTG_DTHRCTL_RXTHRLEN_0  0x00020000	/* Bit 0 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_1  0x00040000	/* Bit 1 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_2  0x00080000	/* Bit 2 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_3  0x00100000	/* Bit 3 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_4  0x00200000	/* Bit 4 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_5  0x00400000	/* Bit 5 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_6  0x00800000	/* Bit 6 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_7  0x01000000	/* Bit 7 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_8  0x02000000	/* Bit 8 */
  #define USB_OTG_DTHRCTL_ARPEN       0x08000000	/* Arbiter parking enable */
#define TOFF_USBD_DIEPEMPMSK 0x0034		/* (RW) dev empty msk */
  #define USB_OTG_DIEPEMPMSK_INEPTXFEM 0x0000FFFF	/* IN EP Tx FIFO empty interrupt mask bits */
#define TOFF_USBD_DEACHINT  0x0038		/* (RW) dedicated EP interrupt */
  #define USB_OTG_DEACHINT_IEP1INT  0x00000002	/* IN endpoint 1interrupt bit */
  #define USB_OTG_DEACHINT_OEP1INT  0x00020000	/* OUT endpoint 1 interrupt bit */
#define TOFF_USBD_DEACHMSK  0x003C		/* (RW) dedicated EP msk */
#define TOFF_USBD_DINEP1MSK 0x0044		/* (RW) dedicated EP mask */
#define TOFF_USBD_DOUTEP1MSK 0x0084		/* (RW) dedicated EP msk */

/*
 *  USB OTG IN ENDPOINT
 */
#define TADR_USBO_INEP_BASE     (TADR_USB_OTG_BASE+USB_OTG_IN_ENDPOINT_BASE)
#define USBO_EP_REG_SIZE         0x20
#define TOFF_USBEI_DIEPCTL  0x0000		/* (RW) dev IN Endpoint Control Register */
  #define USB_OTG_DIEPCTL_MPSIZ     0x000007FF	/* Maximum packet size */
  #define USB_OTG_DIEPCTL_USBAEP    0x00008000	/* USB active endpoint */
  #define USB_OTG_DIEPCTL_EONUM_DPID 0x00010000	/* Even/odd frame */
  #define USB_OTG_DIEPCTL_NAKSTS    0x00020000	/* NAK status */
  #define USB_OTG_DIEPCTL_EPTYP     0x000C0000	/* Endpoint type */
  #define USB_OTG_DIEPCTL_EPTYP_0   0x00040000	/* Bit 0 */
  #define USB_OTG_DIEPCTL_EPTYP_1   0x00080000	/* Bit 1 */
  #define USB_OTG_DIEPCTL_STALL     0x00200000	/* STALL handshake */
  #define USB_OTG_DIEPCTL_TXFNUM    0x03C00000	/* TxFIFO number */
  #define USB_OTG_DIEPCTL_TXFNUM_0  0x00400000	/* Bit 0 */
  #define USB_OTG_DIEPCTL_TXFNUM_1  0x00800000	/* Bit 1 */
  #define USB_OTG_DIEPCTL_TXFNUM_2  0x01000000	/* Bit 2 */
  #define USB_OTG_DIEPCTL_TXFNUM_3  0x02000000	/* Bit 3 */
  #define USB_OTG_DIEPCTL_CNAK      0x04000000	/* Clear NAK */
  #define USB_OTG_DIEPCTL_SNAK      0x08000000	/* Set NAK */
  #define USB_OTG_DIEPCTL_SD0PID_SEVNFRM 0x10000000	/* Set DATA0 PID */
  #define USB_OTG_DIEPCTL_SODDFRM   0x20000000	/* Set odd frame */
  #define USB_OTG_DIEPCTL_EPDIS     0x40000000	/* Endpoint disable */
  #define USB_OTG_DIEPCTL_EPENA     0x80000000	/* Endpoint enable */
#define TOFF_USBEI_DIEPINT  0x0008		/* (RW) dev IN Endpoint Itr Register */
  #define USB_OTG_DIEPINT_XFRC      0x00000001	/* Transfer completed interrupt */
  #define USB_OTG_DIEPINT_EPDISD    0x00000002	/* Endpoint disabled interrupt */
  #define USB_OTG_DIEPINT_TOC       0x00000008	/* Timeout condition */
  #define USB_OTG_DIEPINT_ITTXFE    0x00000010	/* IN token received when TxFIFO is empty */
  #define USB_OTG_DIEPINT_INEPNE    0x00000040	/* IN endpoint NAK effective */
  #define USB_OTG_DIEPINT_TXFE      0x00000080	/* Transmit FIFO empty */
  #define USB_OTG_DIEPINT_TXFIFOUDRN 0x00000100	/* Transmit Fifo Underrun */
  #define USB_OTG_DIEPINT_BNA       0x00000200	/* Buffer not available interrupt */
  #define USB_OTG_DIEPINT_PKTDRPSTS 0x00000800	/* Packet dropped status */
  #define USB_OTG_DIEPINT_BERR      0x00001000	/* Babble error interrupt */
  #define USB_OTG_DIEPINT_NAK       0x00002000	/* NAK interrupt */
#define TOFF_USBEI_DIEPTSIZ 0x0010		/* (RW) IN Endpoint Txfer Size */
  #define USB_OTG_DIEPTSIZ_XFRSIZ   0x0007FFFF	/* Transfer size */
  #define USB_OTG_DIEPTSIZ_PKTCNT   0x1FF80000	/* Packet count */
  #define USB_OTG_DIEPTSIZ_MULCNT   0x60000000	/* Packet count */
#define TOFF_USBEI_DIEPDMA  0x0014		/* (RW) IN Endpoint DMA Address Register */
  #define USB_OTG_DIEPDMA_DMAADDR   0xFFFFFFFF	/* DMA address */
#define TOFF_USBEI_DTXFSTS  0x0018		/* (RW) IN Endpoint Tx FIFO Status Register */
  #define USB_OTG_DTXFSTS_INEPTFSAV 0x0000FFFF	/* IN endpoint TxFIFO space avail */

/*
 *  USB OTG OUTPUT ENDPOINT
 */
#define TADR_USBO_OUTEP_BASE    (TADR_USB_OTG_BASE+USB_OTG_OUT_ENDPOINT_BASE)
#define TOFF_USBEO_DOEPCTL  0x0000		/* (RW) dev OUT Endpoint Control Register */
  #define USB_OTG_DOEPCTL_MPSIZ     0x000007FF	/* Maximum packet size */
  #define USB_OTG_DOEPCTL_USBAEP    0x00008000	/* USB active endpoint */
  #define USB_OTG_DOEPCTL_NAKSTS    0x00020000	/* NAK status */
  #define USB_OTG_DOEPCTL_SD0PID_SEVNFRM  0x10000000	/* Set DATA0 PID */
  #define USB_OTG_DOEPCTL_SODDFRM   0x20000000	/* Set odd frame */
  #define USB_OTG_DOEPCTL_EPTYP     0x000C0000	/* Endpoint type */
  #define USB_OTG_DOEPCTL_EPTYP_0   0x00040000	/* Bit 0 */
  #define USB_OTG_DOEPCTL_EPTYP_1   0x00080000	/* Bit 1 */
  #define USB_OTG_DOEPCTL_SNPM      0x00100000	/* Snoop mode */
  #define USB_OTG_DOEPCTL_STALL     0x00200000	/* STALL handshake */
  #define USB_OTG_DOEPCTL_CNAK      0x04000000	/* Clear NAK */
  #define USB_OTG_DOEPCTL_SNAK      0x08000000	/* Set NAK */
  #define USB_OTG_DOEPCTL_EPDIS     0x40000000	/* Endpoint disable */
  #define USB_OTG_DOEPCTL_EPENA     0x80000000	/* Endpoint enable */
#define TOFF_USBEO_DOEPINT  0x0008		/* (RW) dev OUT Endpoint Itr Register */
  #define USB_OTG_DOEPINT_XFRC      0x00000001	/* Transfer completed interrupt */
  #define USB_OTG_DOEPINT_EPDISD    0x00000002	/* Endpoint disabled interrupt */
  #define USB_OTG_DOEPINT_STUP      0x00000008	/* SETUP phase done */
  #define USB_OTG_DOEPINT_OTEPDIS   0x00000010	/* OUT token received when endpoint disabled */
  #define USB_OTG_DOEPINT_B2BSTUP   0x00000040	/* Back-to-back SETUP packets received */
  #define USB_OTG_DOEPINT_NYET      0x00004000	/* NYET interrupt */
#define TOFF_USBEO_DOEPTSIZ 0x0010		/* (RW) dev OUT Endpoint Txfer Size */
  #define USB_OTG_DOEPTSIZ_XFRSIZ   0x0007FFFF	/* Transfer size */
  #define USB_OTG_DOEPTSIZ_PKTCNT   0x1FF80000	/* Packet count */
  #define USB_OTG_DOEPTSIZ_STUPCNT  0x60000000	/* SETUP packet count */
  #define USB_OTG_DOEPTSIZ_STUPCNT_0 0x20000000	/* Bit 0 */
  #define USB_OTG_DOEPTSIZ_STUPCNT_1 0x40000000	/* Bit 1 */
#define TOFF_USBEO_DOEPDMA  0x0014		/* (RW) dev OUT Endpoint DMA Address */

/*
 *  USB OTG HOST
 */
#define TADR_USBO_HOST_BASE     (TADR_USB_OTG_BASE+USB_OTG_HOST_BASE)
#define TOFF_USBH_HCFG      0x0000		/* (RW) Host Configuration Register */
  #define USB_OTG_HCFG_FSLSPCS      0x00000003	/* FS/LS PHY clock select */
  #define USB_OTG_HCFG_FSLSPCS_0    0x00000001	/* Bit 0 */
  #define USB_OTG_HCFG_FSLSPCS_1    0x00000002	/* Bit 1 */
  #define USB_OTG_HCFG_FSLSS        0x00000004	/* FS- and LS-only support */
#define TOFF_USBH_HFIR      0x0004		/* (RW) Host Frame Interval Register */
  #define USB_OTG_HFIR_FRIVL        0x0000FFFF	/* Frame interval */
#define TOFF_USBH_HFNUM     0x0008		/* (RW) Host Frame Nbr/Frame Remaining */
  #define USB_OTG_HFNUM_FRNUM       0x0000FFFF	/* Frame number */
  #define USB_OTG_HFNUM_FTREM       0xFFFF0000	/* Frame time remaining */
#define TOFF_USBH_HPTXSTS   0x0010		/* (RW) Host Periodic Tx FIFO/ Queue Status */
  #define USB_OTG_HPTXSTS_PTXFSAVL  0x0000FFFF	/* Periodic transmit data FIFO space available */
  #define USB_OTG_HPTXSTS_PTXQSAV   0x00FF0000	/* Periodic transmit request queue space available */
  #define USB_OTG_HPTXSTS_PTXQSAV_0 0x00010000	/* Bit 0 */
  #define USB_OTG_HPTXSTS_PTXQSAV_1 0x00020000	/* Bit 1 */
  #define USB_OTG_HPTXSTS_PTXQSAV_2 0x00040000	/* Bit 2 */
  #define USB_OTG_HPTXSTS_PTXQSAV_3 0x00080000	/* Bit 3 */
  #define USB_OTG_HPTXSTS_PTXQSAV_4 0x00100000	/* Bit 4 */
  #define USB_OTG_HPTXSTS_PTXQSAV_5 0x00200000	/* Bit 5 */
  #define USB_OTG_HPTXSTS_PTXQSAV_6 0x00400000	/* Bit 6 */
  #define USB_OTG_HPTXSTS_PTXQSAV_7 0x00800000	/* Bit 7 */
  #define USB_OTG_HPTXSTS_PTXQTOP   0xFF000000	/* Top of the periodic transmit request queue */
  #define USB_OTG_HPTXSTS_PTXQTOP_0 0x01000000	/* Bit 0 */
  #define USB_OTG_HPTXSTS_PTXQTOP_1 0x02000000	/* Bit 1 */
  #define USB_OTG_HPTXSTS_PTXQTOP_2 0x04000000	/* Bit 2 */
  #define USB_OTG_HPTXSTS_PTXQTOP_3 0x08000000	/* Bit 3 */
  #define USB_OTG_HPTXSTS_PTXQTOP_4 0x10000000	/* Bit 4 */
  #define USB_OTG_HPTXSTS_PTXQTOP_5 0x20000000	/* Bit 5 */
  #define USB_OTG_HPTXSTS_PTXQTOP_6 0x40000000	/* Bit 6 */
  #define USB_OTG_HPTXSTS_PTXQTOP_7 0x80000000	/* Bit 7 */
#define TOFF_USBH_HAINT     0x0014		/* (RW) Host All Channels Interrupt Register */
  #define USB_OTG_HAINT_HAINT       0x0000FFFF	/* Channel interrupts */
#define TOFF_USBH_HAINTMSK  0x0018		/* (RW) Host All Channels Interrupt Mask */
  #define USB_OTG_HAINTMSK_HAINTM   0x0000FFFF	/* Channel interrupt mask */
#define TOFF_USBH_HFLBADDR  0x001C		/* (RW) Host frame list base address register */


/*
 *  USB HOST CHANNEL SPECIFIC
 */
#define TADR_USBH_HC_BASE        (TADR_USB_OTG_BASE+USB_OTG_HOST_CHANNEL_BASE)
#define USBO_HOST_CHANNEL_REG_SIZE    0x20
#define TOFF_USBHC_HCCHAR   0x0000		/* (RW) Host Channel Characteristics Register */
  #define USB_OTG_HCCHAR_MPSIZ      0x000007FF	/* Maximum packet size */
  #define USB_OTG_HCCHAR_EPNUM      0x00007800	/* Endpoint number */
  #define USB_OTG_HCCHAR_EPNUM_0    0x00000800	/* Bit 0 */
  #define USB_OTG_HCCHAR_EPNUM_1    0x00001000	/* Bit 1 */
  #define USB_OTG_HCCHAR_EPNUM_2    0x00002000	/* Bit 2 */
  #define USB_OTG_HCCHAR_EPNUM_3    0x00004000	/* Bit 3 */
  #define USB_OTG_HCCHAR_EPDIR      0x00008000	/* Endpoint direction */
  #define USB_OTG_HCCHAR_LSDEV      0x00020000	/* Low-speed device */
  #define USB_OTG_HCCHAR_EPTYP      0x000C0000	/* Endpoint type */
  #define USB_OTG_HCCHAR_EPTYP_0    0x00040000	/* Bit 0 */
  #define USB_OTG_HCCHAR_EPTYP_1    0x00080000	/* Bit 1 */
  #define USB_OTG_HCCHAR_MC         0x00300000	/* Multi Count (MC) / Error Count (EC) */
  #define USB_OTG_HCCHAR_MC_0       0x00100000	/* Bit 0 */
  #define USB_OTG_HCCHAR_MC_1       0x00200000	/* Bit 1 */
  #define USB_OTG_HCCHAR_DAD        0x1FC00000	/* Device address */
  #define USB_OTG_HCCHAR_DAD_0      0x00400000	/* Bit 0 */
  #define USB_OTG_HCCHAR_DAD_1      0x00800000	/* Bit 1 */
  #define USB_OTG_HCCHAR_DAD_2      0x01000000	/* Bit 2 */
  #define USB_OTG_HCCHAR_DAD_3      0x02000000	/* Bit 3 */
  #define USB_OTG_HCCHAR_DAD_4      0x04000000	/* Bit 4 */
  #define USB_OTG_HCCHAR_DAD_5      0x08000000	/* Bit 5 */
  #define USB_OTG_HCCHAR_DAD_6      0x10000000	/* Bit 6 */
  #define USB_OTG_HCCHAR_ODDFRM     0x20000000	/* Odd frame */
  #define USB_OTG_HCCHAR_CHDIS      0x40000000	/* Channel disable */
  #define USB_OTG_HCCHAR_CHENA      0x80000000	/* Channel enable */
#define TOFF_USBHC_HCSPLT   0x0004		/* (RW) Host Channel Split Control Register */
  #define USB_OTG_HCSPLT_PRTADDR    0x0000007F	/* Port address */
  #define USB_OTG_HCSPLT_PRTADDR_0  0x00000001	/* Bit 0 */
  #define USB_OTG_HCSPLT_PRTADDR_1  0x00000002	/* Bit 1 */
  #define USB_OTG_HCSPLT_PRTADDR_2  0x00000004	/* Bit 2 */
  #define USB_OTG_HCSPLT_PRTADDR_3  0x00000008	/* Bit 3 */
  #define USB_OTG_HCSPLT_PRTADDR_4  0x00000010	/* Bit 4 */
  #define USB_OTG_HCSPLT_PRTADDR_5  0x00000020	/* Bit 5 */
  #define USB_OTG_HCSPLT_PRTADDR_6  0x00000040	/* Bit 6 */
  #define USB_OTG_HCSPLT_HUBADDR    0x00003F80	/* Hub address */
  #define USB_OTG_HCSPLT_HUBADDR_0  0x00000080	/* Bit 0 */
  #define USB_OTG_HCSPLT_HUBADDR_1  0x00000100	/* Bit 1 */
  #define USB_OTG_HCSPLT_HUBADDR_2  0x00000200	/* Bit 2 */
  #define USB_OTG_HCSPLT_HUBADDR_3  0x00000400	/* Bit 3 */
  #define USB_OTG_HCSPLT_HUBADDR_4  0x00000800	/* Bit 4 */
  #define USB_OTG_HCSPLT_HUBADDR_5  0x00001000	/* Bit 5 */
  #define USB_OTG_HCSPLT_HUBADDR_6  0x00002000	/* Bit 6 */
  #define USB_OTG_HCSPLT_XACTPOS    0x0000C000	/* XACTPOS */
  #define USB_OTG_HCSPLT_XACTPOS_0  0x00004000	/* Bit 0 */
  #define USB_OTG_HCSPLT_XACTPOS_1  0x00008000	/* Bit 1 */
  #define USB_OTG_HCSPLT_COMPLSPLT  0x00010000	/* Do complete split */
  #define USB_OTG_HCSPLT_SPLITEN    0x80000000	/* Split enable */
#define TOFF_USBHC_HCINT    0x0008		/* (RW) Host Channel Interrupt Register */
  #define USB_OTG_HCINT_XFRC        0x00000001	/* Transfer completed */
  #define USB_OTG_HCINT_CHH         0x00000002	/* Channel halted */
  #define USB_OTG_HCINT_AHBERR      0x00000004	/* AHB error */
  #define USB_OTG_HCINT_STALL       0x00000008	/* STALL response received interrupt */
  #define USB_OTG_HCINT_NAK         0x00000010	/* NAK response received interrupt */
  #define USB_OTG_HCINT_ACK         0x00000020	/* ACK response received/transmitted interrupt */
  #define USB_OTG_HCINT_NYET        0x00000040	/* Response received interrupt */
  #define USB_OTG_HCINT_TXERR       0x00000080	/* Transaction error */
  #define USB_OTG_HCINT_BBERR       0x00000100	/* Babble error */
  #define USB_OTG_HCINT_FRMOR       0x00000200	/* Frame overrun */
  #define USB_OTG_HCINT_DTERR       0x00000400	/* Data toggle error */
#define TOFF_USBHC_HCINTMSK 0x000C		/* (RW) Host Channel Interrupt Mask Register */
  #define USB_OTG_HCINTMSK_XFRCM    0x00000001	/* Transfer completed mask */
  #define USB_OTG_HCINTMSK_CHHM     0x00000002	/* Channel halted mask */
  #define USB_OTG_HCINTMSK_AHBERR   0x00000004	/* AHB error */
  #define USB_OTG_HCINTMSK_STALLM   0x00000008	/* STALL response received interrupt mask */
  #define USB_OTG_HCINTMSK_NAKM     0x00000010	/* NAK response received interrupt mask */
  #define USB_OTG_HCINTMSK_ACKM     0x00000020	/* ACK response received/transmitted interrupt mask */
  #define USB_OTG_HCINTMSK_NYET     0x00000040	/* response received interrupt mask */
  #define USB_OTG_HCINTMSK_TXERRM   0x00000080	/* Transaction error mask */
  #define USB_OTG_HCINTMSK_BBERRM   0x00000100	/* Babble error mask */
  #define USB_OTG_HCINTMSK_FRMORM   0x00000200	/* Frame overrun mask */
  #define USB_OTG_HCINTMSK_DTERRM   0x00000400	/* Data toggle error mask */
#define TOFF_USBHC_HCTSIZ   0x0010		/* (RW) Host Channel Transfer Size Register */
  #define USB_OTG_HCTSIZ_XFRSIZ     0x0007FFFF	/* Transfer size */
  #define USB_OTG_HCTSIZ_PKTCNT     0x1FF80000	/* Packet count */
  #define USB_OTG_HCTSIZ_DOPING     0x80000000	/* Do PING */
  #define USB_OTG_HCTSIZ_DPID       0x60000000	/* Data PID */
  #define USB_OTG_HCTSIZ_DPID_0     0x20000000	/* Bit 0 */
  #define USB_OTG_HCTSIZ_DPID_1     0x40000000	/* Bit 1 */
#define TOFF_USBHC_HCDMA    0x0014		/* (RW) Host Channel DMA Address Register */
  #define USB_OTG_HCDMA_DMAADDR     0xFFFFFFFF	/* DMA address */
#define TOFF_USBHC_HCDMAB   0x0018		/* (RW) Host Channel DMA Address Buffer Register */

/*
 *  USB OTG HPRT
 */
#define TADR_USBO_HPRT0_BASE         (TADR_USB_OTG_BASE+USB_OTG_HOST_PORT_BASE)
  #define USB_OTG_HPRT_PCSTS        0x00000001	/* Port connect status */
  #define USB_OTG_HPRT_PCDET        0x00000002	/* Port connect detected */
  #define USB_OTG_HPRT_PENA         0x00000004	/* Port enable */
  #define USB_OTG_HPRT_PENCHNG      0x00000008	/* Port enable/disable change */
  #define USB_OTG_HPRT_POCA         0x00000010	/* Port overcurrent active */
  #define USB_OTG_HPRT_POCCHNG      0x00000020	/* Port overcurrent change */
  #define USB_OTG_HPRT_PRES         0x00000040	/* Port resume */
  #define USB_OTG_HPRT_PSUSP        0x00000080	/* Port suspend */
  #define USB_OTG_HPRT_PRST         0x00000100	/* Port reset */
  #define USB_OTG_HPRT_PLSTS        0x00000C00	/* Port line status */
  #define USB_OTG_HPRT_PLSTS_0      0x00000400	/* Bit 0 */
  #define USB_OTG_HPRT_PLSTS_1      0x00000800	/* Bit 1 */
  #define USB_OTG_HPRT_PPWR         0x00001000	/* Port power */
  #define USB_OTG_HPRT_PTCTL        0x0001E000	/* Port test control */
  #define USB_OTG_HPRT_PTCTL_0      0x00002000	/* Bit 0 */
  #define USB_OTG_HPRT_PTCTL_1      0x00004000	/* Bit 1 */
  #define USB_OTG_HPRT_PTCTL_2      0x00008000	/* Bit 2 */
  #define USB_OTG_HPRT_PTCTL_3      0x00010000	/* Bit 3 */
  #define USB_OTG_HPRT_PSPD         0x00060000	/* Port speed */
  #define USB_OTG_HPRT_PSPD_0       0x00020000	/* Bit 0 */
  #define USB_OTG_HPRT_PSPD_1       0x00040000	/* Bit 1 */

/*
 *  PCGCCTL BIT DEFINITIONS
 */
#define USB_OTG_PCGCCTL_STOPCLK     0x00000001	/* SETUP packet count */
#define USB_OTG_PCGCCTL_GATECLK     0x00000002	/* Bit 0 */
#define USB_OTG_PCGCCTL_PHYSUSP     0x00000010	/* Bit 1 */


/*
 *  HW SEMAPHORE (HSEM)
 */
#define TADR_HSEM_BASE      (MCU_AHB3_PERIPH_BASE + 0x0000)
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
  #define HSEM_CR_COREID_CPU1    0x00000100
  #define HSEM_CR_COREID_CPU2    0x00000200
  #define HSEM_CR_COREID_CURRENT HSEM_CR_COREID_CPU2
  #define HSEM_CR_KEY        0xFFFF0000	/* semaphores clear key. */
#define TOFF_HSEM_KEYR      0x0144	/* (RW) HSEM Semaphore clear key register */
  #define HSEM_KEYR_KEY      0xFFFF0000	/* semaphores clear key. */
#define TOFF_HSEM_HWCFGR2   0x03EC	/* (R)  HSEM Hardware Configuration Register 2 */
  #define HSEM_HWCFGR2_MASTERID1  0x0000000F	/* HW Config valid bus masters ID1 */
  #define HSEM_HWCFGR2_MASTERID2  0x000000F0	/* HW Config valid bus masters ID2 */
  #define HSEM_HWCFGR2_MASTERID3  0x00000F00	/* HW Config valid bus masters ID3 */
  #define HSEM_HWCFGR2_MASTERID4  0x0000F000	/* HW Config valid bus masters ID4 */
#define TOFF_HSEM_HWCFGR1   0x03F0	/* (R)  HSEM Hardware Configuration Register 1 */
  #define HSEM_HWCFGR1_NBSEM 0x000000FF	/* HW Config number of semaphores */
  #define HSEM_HWCFGR1_NBINT 0x00000F00	/* HW Config number of interrupts/ supported number of master IDs */
#define TOFF_HSEM_VERR      0x03F4	/* (R)  HSEM IP Version Register */
  #define HSEM_VERR_MINREV   0x0000000F	/* Minor Revision number */
  #define HSEM_VERR_MAJREV   0x000000F0	/* Major Revision number */
#define TOFF_HSEM_IPIDR     0x03F8	/* (R)  HSEM IP Identification Register */
#define TOFF_HSEM_SIDR      0x03FC	/* (R)  HSEM Size Identification Register */


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

#define HSEM_SEMID_MIN      (0U)		/* HSEM ID Min*/
#define HSEM_SEMID_MAX      (31U)		/* HSEM ID Max */


/*
 *  INTER-PROCESSOR COMMUNICATION (IPCC)
 */
#define TADR_IPCC_BASE      (MCU_AHB3_PERIPH_BASE + 0x1000)
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
#define TOFF_IPCC_HWCFGR    0x03F0		/* (R)  Inter-Processor Communication hardware configuration register */
  #define IPCC_HWCFGR_CHANNELS 0x000000FF	/* Number of channels per CPU */
#define TOFF_IPCC_VER       0x03F4		/* (R)  Inter-Processor Communication version register */
  #define IPCC_VERR_MINREV   0x0000000F	/* Minor Revision number */
  #define IPCC_VERR_MAJREV   0x000000F0	/* Major Revision number */
#define TOFF_IPCC_ID        0x03F8		/* (R)  Inter-Processor Communication identification register */
#define TOFF_IPCC_SID       0x03FC		/* (R)  Inter-Processor Communication size identification register */

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
 *  HASH
 */
#define TADR_HASH2_BASE     (MCU_AHB3_PERIPH_BASE + 0x2000)
#define TADR_HASH1_BASE     (MPU_AHB5_PERIPH_BASE + 0x2000)
#define TOFF_HASH_CR        0x0000		/* (RW) HASH control register */
  #define HASH_CR_INIT          0x00000004
  #define HASH_CR_DMAE          0x00000008
  #define HASH_CR_DATATYPE      0x00000030
  #define HASH_CR_DATATYPE_0    0x00000010
  #define HASH_CR_DATATYPE_1    0x00000020
  #define HASH_CR_MODE          0x00000040
  #define HASH_CR_ALGO          0x00040080
  #define HASH_CR_ALGO_0        0x00000080
  #define HASH_CR_ALGO_1        0x00040000
  #define HASH_CR_NBW           0x00000F00
  #define HASH_CR_NBW_0         0x00000100
  #define HASH_CR_NBW_1         0x00000200
  #define HASH_CR_NBW_2         0x00000400
  #define HASH_CR_NBW_3         0x00000800
  #define HASH_CR_DINNE         0x00001000
  #define HASH_CR_MDMAT         0x00002000
  #define HASH_CR_DMAA          0x00004000
  #define HASH_CR_LKEY          0x00010000
#define TOFF_HASH_DIN       0x0004		/* (RW) HASH data input register */
#define TOFF_HASH_STR       0x0008		/* (RW) HASH start register */
#define TOFF_HASH_HR        0x000C		/* (RW) HASH digest registers[0-4] */
  #define HASH_STR_NBLW         0x0000001F
  #define HASH_STR_NBLW_0       0x00000001
  #define HASH_STR_NBLW_1       0x00000002
  #define HASH_STR_NBLW_2       0x00000004
  #define HASH_STR_NBLW_3       0x00000008
  #define HASH_STR_NBLW_4       0x00000010
  #define HASH_STR_DCAL         0x00000100
#define TOFF_HASH_IMR       0x0020		/* (RW) HASH interrupt enable register */
  #define HASH_IMR_DINIE        0x00000001
  #define HASH_IMR_DCIE         0x00000002
#define TOFF_HASH_SR        0x0024		/* (R)  HASH status register */
  #define HASH_SR_DINIS         0x00000001
  #define HASH_SR_DCIS          0x00000002
  #define HASH_SR_DMAS          0x00000004
  #define HASH_SR_BUSY          0x00000008
#define TOFF_HASH_CSR       0x00F8		/* (RW) HASH context swap registers[0-53] */
#define TOFF_HASH_HR2       0x0310		/* (RW) HASH digest registers 2[0-7] */
#define TOFF_HASH_HWCFGR    0x03F0		/* (R)  HASH Hardware configuration register */
  #define HASH_HWCFGR_CFG1      0x0000000F	/* use_mdma generic value (0x1) */
#define TOFF_HASH_VERR      0x03F4		/* (RW) HASH HASH Version register */
  #define HASH_VERR_VER         0x000000FF	/*  Revision number */
#define TOFF_HASH_CSR4      0x03F8		/* (RW) HASH identification register */
#define TOFF_HASH_CSR5      0x03FC		/* (RW) HASH Hardware Magic ID register */

#define TADR_HASH2_DIGEST_BASE  (MCU_AHB3_PERIPH_BASE + 0x2310)
#define TADR_HASH1_DIGEST_BASE  (MPU_AHB5_PERIPH_BASE + 0x2310)
#define TOFF_HASH_DIGEST_HR 0x0000		/* (RW) HASH digest registers 2[0-7] */


/*
 *  RNG
 */
#define TADR_RNG2_BASE      (MCU_AHB3_PERIPH_BASE + 0x3000)
#define TADR_RNG1_BASE      (MPU_AHB5_PERIPH_BASE + 0x3000)
#define TOFF_RNG_CR         0x0000		/* (RW) RNG control register */
  #define RNG_CR_RNGEN          0x00000004
  #define RNG_CR_IE             0x00000008
  #define RNG_CR_CED            0x00000020
#define TOFF_RNG_SR         0x0004		/* (RW) RNG status register */
  #define RNG_SR_DRDY           0x00000001
  #define RNG_SR_CECS           0x00000002
  #define RNG_SR_SECS           0x00000004
  #define RNG_SR_CEIS           0x00000020
  #define RNG_SR_SEIS           0x00000040
#define TOFF_RNG_DR         0x0008		/* (RW) RNG data register */
#define TOFF_RNG_HWCFGR     0x03F0		/* (R)  RNG HW Configuration register */
#define TOFF_RNG_VERR       0x03F4		/* (R)  RNG Version register */
  #define RNG_VERR_MINREV       0x0000000F	/* Minor Revision number */
  #define RNG_VERR_MAJREV       0x000000F0	/* Major Revision number */
#define TOFF_RNG_IPIDR      0x03F8		/* (R)  RNG identification register */
#define TOFF_RNG_SIDR       0x03FC		/* (R)  RNG HW magic ID */


/*
 *  CRC CALCULATION UNIT
 */
#define TADR_CRC2_BASE      (MCU_AHB3_PERIPH_BASE + 0x4000)
#define TADR_CRC1_BASE      (MPU_AHB6_PERIPH_BASE + 0x9000)
#define TOFF_CRC_DR         0x0000		/* (RW) CRC Data register */
#define TOFF_CRC_IDR        0x0004		/* (RW-8) CRC Independent data register */
#define TOFF_CRC_CR         0x0008		/* (RW) CRC Control register */
  #define CRC_CR_RESET          0x00000001	/* RESET the CRC computation unit bit */
  #define CRC_CR_POLYSIZE       0x00000018	/* Polynomial size bits */
  #define CRC_CR_POLYSIZE_0     0x00000008
  #define CRC_CR_POLYSIZE_1     0x00000010
  #define CRC_CR_REV            0x00000060	/* REV_IN Reverse Input Data bits */
  #define CRC_CR_REV_IN_0       0x00000020
  #define CRC_CR_REV_IN_1       0x00000040
  #define CRC_CR_REV_OUT        0x00000080	/* REV_OUT Reverse Output Data bits */
#define TOFF_CRC_INIT       0x0010		/* (RW) Initial CRC value register */
#define TOFF_CRC_POL        0x0014		/* (RW) CRC polynomial register */
#define TOFF_CRC_VERR       0x03F4		/* (R)  CRC version register */
#define TOFF_CRC_IPIDR      0x03F8		/* (R)  CRC ID register */
#define TOFF_CRC_SIDR       0x03FC		/* (R)  CRC Size ID register */


/*
 *  CRYPTO PROCESSER
 */
#define TADR_CRYP2_BASE     (MCU_AHB3_PERIPH_BASE + 0x5000)
#define TADR_CRYP1_BASE     (MPU_AHB5_PERIPH_BASE + 0x1000)
#define TOFF_CRYP_CR        0x0000		/* (RW) CRYP control register */
  #define CRYP_CR_ALGODIR       0x00000004
  #define CRYP_CR_ALGOMODE      0x00080038
  #define CRYP_CR_ALGOMODE_0    0x00000008
  #define CRYP_CR_ALGOMODE_1    0x00000010
  #define CRYP_CR_ALGOMODE_2    0x00000020
  #define CRYP_CR_ALGOMODE_TDES_ECB 0x00000000
  #define CRYP_CR_ALGOMODE_TDES_CBC 0x00000008
  #define CRYP_CR_ALGOMODE_DES_ECB  0x00000010
  #define CRYP_CR_ALGOMODE_DES_CBC  0x00000018
  #define CRYP_CR_ALGOMODE_AES_ECB  0x00000020
  #define CRYP_CR_ALGOMODE_AES_CBC  0x00000028
  #define CRYP_CR_ALGOMODE_AES_CTR  0x00000030
  #define CRYP_CR_ALGOMODE_AES_GCM  0x00080000
  #define CRYP_CR_ALGOMODE_AES_CCM  0x00080008
  #define CRYP_CR_ALGOMODE_AES_KEY  0x00000038
  #define CRYP_CR_DATATYPE      0x000000C0
  #define CRYP_CR_DATATYPE_0    0x00000040
  #define CRYP_CR_DATATYPE_1    0x00000080
  #define CRYP_CR_KEYSIZE       0x00000300
  #define CRYP_CR_KEYSIZE_0     0x00000100
  #define CRYP_CR_KEYSIZE_1     0x00000200
  #define CRYP_CR_FFLUSH        0x00004000
  #define CRYP_CR_CRYPEN        0x00008000
  #define CRYP_CR_GCM_CCMPH     0x00030000
  #define CRYP_CR_GCM_CCMPH_0   0x00010000
  #define CRYP_CR_GCM_CCMPH_1   0x00020000
  #define CRYP_CR_ALGOMODE_3    0x00080000
  #define CRYP_CR_NPBLB		    0x00F00000
#define TOFF_CRYP_SR        0x0004		/* (R)  CRYP status register */
  #define CRYP_SR_IFEM          0x00000001
  #define CRYP_SR_IFNF          0x00000002
  #define CRYP_SR_OFNE          0x00000004
  #define CRYP_SR_OFFU          0x00000008
  #define CRYP_SR_BUSY          0x00000010
#define TOFF_CRYP_DR        0x0008		/* (RW) CRYP data input register */
#define TOFF_CRYP_DOUT      0x000C		/* (RW) CRYP data output register */
#define TOFF_CRYP_DMACR     0x0010		/* (RW) CRYP DMA control register */
  #define CRYP_DMACR_DIEN       0x00000001
  #define CRYP_DMACR_DOEN       0x00000002
#define TOFF_CRYP_IMSCR     0x0014		/* (RW) CRYP interrupt mask set/clear register */
  #define CRYP_IMSCR_INIM       0x00000001
  #define CRYP_IMSCR_OUTIM      0x00000002
#define TOFF_CRYP_RISR      0x0018		/* (RW) CRYP raw interrupt status register */
  #define CRYP_RISR_OUTRIS      0x00000001
  #define CRYP_RISR_INRIS       0x00000002
#define TOFF_CRYP_MISR      0x001C		/* (RW) CRYP masked interrupt status register */
  #define CRYP_MISR_INMIS       0x00000001
  #define CRYP_MISR_OUTMIS      0x00000002
#define TOFF_CRYP_K0LR      0x0020		/* (RW) CRYP key left  register 0 */
#define TOFF_CRYP_K0RR      0x0024		/* (RW) CRYP key right register 0 */
#define TOFF_CRYP_K1LR      0x0028		/* (RW) CRYP key left  register 1 */
#define TOFF_CRYP_K1RR      0x002C		/* (RW) CRYP key right register 1 */
#define TOFF_CRYP_K2LR      0x0030		/* (RW) CRYP key left  register 2 */
#define TOFF_CRYP_K2RR      0x0034		/* (RW) CRYP key right register 2 */
#define TOFF_CRYP_K3LR      0x0038		/* (RW) CRYP key left  register 3 */
#define TOFF_CRYP_K3RR      0x003C		/* (RW) CRYP key right register 3 */
#define TOFF_CRYP_IV0LR     0x0040		/* (RW) CRYP initialization vector left-word  register 0 */
#define TOFF_CRYP_IV0RR     0x0044		/* (RW) CRYP initialization vector right-word register 0 */
#define TOFF_CRYP_IV1LR     0x0048		/* (RW) CRYP initialization vector left-word  register 1 */
#define TOFF_CRYP_IV1RR     0x004C		/* (RW) CRYP initialization vector right-word register 1 */
#define TOFF_CRYP_CSGCMCCM0R 0x0050		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 0 */
#define TOFF_CRYP_CSGCMCCM1R 0x0054		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 1 */
#define TOFF_CRYP_CSGCMCCM2R 0x0058		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 2 */
#define TOFF_CRYP_CSGCMCCM3R 0x005C		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 3 */
#define TOFF_CRYP_CSGCMCCM4R 0x0060		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 4 */
#define TOFF_CRYP_CSGCMCCM5R 0x0064		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 5 */
#define TOFF_CRYP_CSGCMCCM6R 0x0068		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 6 */
#define TOFF_CRYP_CSGCMCCM7R 0x006C		/* (RW) CRYP GCM/GMAC or CCM/CMAC context swap register 7 */
#define TOFF_CRYP_CSGCM0R    0x0070		/* (RW) CRYP GCM/GMAC context swap register 0 */
#define TOFF_CRYP_CSGCM1R    0x0074		/* (RW) CRYP GCM/GMAC context swap register 1 */
#define TOFF_CRYP_CSGCM2R    0x0078		/* (RW) CRYP GCM/GMAC context swap register 2 */
#define TOFF_CRYP_CSGCM3R    0x007C		/* (RW) CRYP GCM/GMAC context swap register 3 */
#define TOFF_CRYP_CSGCM4R    0x0080		/* (RW) CRYP GCM/GMAC context swap register 4 */
#define TOFF_CRYP_CSGCM5R    0x0084		/* (RW) CRYP GCM/GMAC context swap register 5 */
#define TOFF_CRYP_CSGCM6R    0x0088		/* (RW) CRYP GCM/GMAC context swap register 6 */
#define TOFF_CRYP_CSGCM7R    0x008C		/* (RW) CRYP GCM/GMAC context swap register 7 */
#define TOFF_CRYP_HWCFGR     0x03F0		/* (R)  CRYP HW Configuration */
  #define CRYP_HWCFGR_CFG1       0x0000000F	/* HW Generic 1 */
  #define CRYP_HWCFGR_CFG2       0x000000F0	/* HW Generic 2 */
  #define CRYP_HWCFGR_CFG3       0x00000F00	/* HW Generic 3 */
  #define CRYP_HWCFGR_CFG4       0x0000F000	/* HW Generic 4 */
#define TOFF_CRYP_VERR       0x03F4		/* (R)  CRYP version register */
  #define CRYP_VERR_VER          0x000000FF	/* Revision number */
#define TOFF_CRYP_IPIDR      0x03F8		/* (R)  CRYP Identification register */
#define TOFF_CRYP_MID        0x03FC		/* (R)  CRYP HW Magic ID register */


/*
 *  DCMI
 */
#define TADR_DCMI_BASE      (MCU_AHB3_PERIPH_BASE + 0x6000)
#define TOFF_DCMI_CR        0x0000		/* (RW) DCMI control register 1 */
  #define DCMI_CR_CAPTURE       0x00000001
  #define DCMI_CR_CM            0x00000002
  #define DCMI_CR_CROP          0x00000004
  #define DCMI_CR_JPEG          0x00000008
  #define DCMI_CR_ESS           0x00000010
  #define DCMI_CR_PCKPOL        0x00000020
  #define DCMI_CR_HSPOL         0x00000040
  #define DCMI_CR_VSPOL         0x00000080
  #define DCMI_CR_FCRC_0        0x00000100
  #define DCMI_CR_FCRC_1        0x00000200
  #define DCMI_CR_EDM_0         0x00000400
  #define DCMI_CR_EDM_1         0x00000800
  #define DCMI_CR_CRE           0x00001000
  #define DCMI_CR_ENABLE        0x00004000
  #define DCMI_CR_BSM           0x00030000
  #define DCMI_CR_BSM_0         0x00010000
  #define DCMI_CR_BSM_1         0x00020000
  #define DCMI_CR_OEBS          0x00040000
  #define DCMI_CR_LSM           0x00080000
  #define DCMI_CR_OELS          0x00100000
#define TOFF_DCMI_SR        0x0004		/* (R)  DCMI status register */
  #define DCMI_SR_HSYNC         0x00000001
  #define DCMI_SR_VSYNC         0x00000002
  #define DCMI_SR_FNE           0x00000004
#define TOFF_DCMI_RISR      0x0008		/* (R)  DCMI raw interrupt status register */
  #define DCMI_RIS_FRAME_RIS    0x00000001
  #define DCMI_RIS_OVR_RIS      0x00000002
  #define DCMI_RIS_ERR_RIS      0x00000004
  #define DCMI_RIS_VSYNC_RIS    0x00000008
  #define DCMI_RIS_LINE_RIS     0x00000010
#define TOFF_DCMI_IER       0x000C		/* (RW) DCMI interrupt enable register */
  #define DCMI_IER_FRAME_IE     0x00000001
  #define DCMI_IER_OVR_IE       0x00000002
  #define DCMI_IER_ERR_IE       0x00000004
  #define DCMI_IER_VSYNC_IE     0x00000008
  #define DCMI_IER_LINE_IE      0x00000010
#define TOFF_DCMI_MISR      0x0010		/* (RW) DCMI masked interrupt status register */
  #define DCMI_MIS_FRAME_MIS    0x00000001
  #define DCMI_MIS_OVR_MIS      0x00000002
  #define DCMI_MIS_ERR_MIS      0x00000004
  #define DCMI_MIS_VSYNC_MIS    0x00000008
  #define DCMI_MIS_LINE_MIS     0x00000010
#define TOFF_DCMI_ICR       0x0014		/* (RW) DCMI interrupt clear register */
  #define DCMI_ICR_FRAME_ISC    0x00000001
  #define DCMI_ICR_OVR_ISC      0x00000002
  #define DCMI_ICR_ERR_ISC      0x00000004
  #define DCMI_ICR_VSYNC_ISC    0x00000008
  #define DCMI_ICR_LINE_ISC     0x00000010
#define TOFF_DCMI_ESCR      0x0018		/* (RW) DCMI embedded synchronization code register */
  #define DCMI_ESCR_FSC         0x000000FF
  #define DCMI_ESCR_LSC         0x0000FF00
  #define DCMI_ESCR_LEC         0x00FF0000
  #define DCMI_ESCR_FEC         0xFF000000
#define TOFF_DCMI_ESUR      0x001C		/* (RW) DCMI embedded synchronization unmask register */
  #define DCMI_ESUR_FSU         0x000000FF
  #define DCMI_ESUR_LSU         0x0000FF00
  #define DCMI_ESUR_LEU         0x00FF0000
  #define DCMI_ESUR_FEU         0xFF000000
#define TOFF_DCMI_CWSTRTR   0x0020		/* (RW) DCMI crop window start */
  #define DCMI_CWSTRT_HOFFCNT   0x00003FFF
  #define DCMI_CWSTRT_VST       0x1FFF0000
#define TOFF_DCMI_CWSIZER   0x0024		/* (RW) DCMI crop window size */
  #define DCMI_CWSIZE_CAPCNT    0x00003FFF
  #define DCMI_CWSIZE_VLINE     0x3FFF0000
#define TOFF_DCMI_DR        0x0028		/* (RW) DCMI data register */
  #define DCMI_DR_BYTE0         0x000000FF
  #define DCMI_DR_BYTE1         0x0000FF00
  #define DCMI_DR_BYTE2         0x00FF0000
  #define DCMI_DR_BYTE3         0xFF000000
#define TOFF_DCMI_VERR      0x03F4		/* (R)  DCMI Version register */
#define TOFF_DCMI_IPDR      0x03F8		/* (R)  DCMI Identification register */
#define TOFF_DCMI_SIDR      0x03FC		/* (R)  DCMI Size Identification register */


/*
 *  RESET AND CLOCK CONTROL
 */
#define TADR_RCC_BASE       (MCU_AHB4_PERIPH_BASE + 0x0000)
#define TOFF_RCC_TZCR             0x0000	/* (RW) RCC TrustZone Control Register */
  #define RCC_TZCR_TZEN               0x00000001	/* TrustZone Enable */
  #define RCC_TZCR_MCKPROT            0x00000002	/* Protection of the generation of ck_mcuss Enable */
#define TOFF_RCC_OCENSETR         0x000C	/* (RW) RCC Oscillator Clock Enable Set Register  */
  #define RCC_OCENSETR_HSION          0x00000001	/* Internal High Speed enable clock */
  #define RCC_OCENSETR_HSIKERON       0x00000002	/* Force HSI to ON,even in stop mode ,in order to be quickly available */
  #define RCC_OCENSETR_CSION          0x00000010	/* CSI enable clock */
  #define RCC_OCENSETR_CSIKERON       0x00000020	/* Force CSI to ON,eve in stop mode ,in order to be quickly available */
  #define RCC_OCENSETR_DIGBYP         0x00000040	/* Digital Bypass */
  #define RCC_OCENSETR_HSEON          0x00000100	/* External High Speed enable clock */
  #define RCC_OCENSETR_HSEKERON       0x00000200	/* Force HSE to ON,evne in stop mode ,in order to be quickly available */
  #define RCC_OCENSETR_HSEBYP         0x00000400	/* HSE Bypass */
  #define RCC_OCENSETR_HSECSSON       0x00000800	/* Clock Security System on HSE enable */
#define TOFF_RCC_OCENCLRR         0x0010	/* (RW) RCC Oscillator Enable Control Clear Register */
  #define RCC_OCENCLRR_HSION          0x00000001	/* clear of HSION bit */
  #define RCC_OCENCLRR_HSIKERON       0x00000002	/* clear of HSIKERON bit */
  #define RCC_OCENCLRR_CSION          0x00000010	/* clear of CSION bit */
  #define RCC_OCENCLRR_CSIKERON       0x00000020	/* clear of CSIKERON bit */
  #define RCC_OCENCLRR_DIGBYP         0x00000040	/* clear of DIGBYP bit */
  #define RCC_OCENCLRR_HSEON          0x00000100	/* clear of HSEON bit */
  #define RCC_OCENCLRR_HSEKERON       0x00000200	/* clear of HSEKERON bit */
  #define RCC_OCENCLRR_HSEBYP         0x00000400	/* clear the HSE Bypass bit */
#define TOFF_RCC_HSICFGR          0x0018	/* (RW) RCC HSI Configuration Register */
  #define RCC_HSICFGR_HSIDIV          0x00000003	/* HSI clock divider*/
  #define RCC_HSICFGR_HSIDIV_0        0x00000000	/* Division by 1 (default after reset)*/
  #define RCC_HSICFGR_HSIDIV_1        0x00000001	/* Division by 2 */
  #define RCC_HSICFGR_HSIDIV_2        0x00000002	/* Division by 4 */
  #define RCC_HSICFGR_HSIDIV_3        0x00000003	/* Division by 8 */
  #define RCC_HSICFGR_HSITRIM         0x00003F00	/* HSI clock trimming */
  #define RCC_HSICFGR_HSICAL          0x0FFF0000	/* HSI clock calibration */
#define TOFF_RCC_CSICFGR          0x001C	/* (RW) RCC CSI Configuration Register */
  #define RCC_CSICFGR_CSITRIM         0x00001F00	/* CSI clock trimming */
  #define RCC_CSICFGR_CSICAL          0x00FF0000	/* CSI clock calibration */
#define TOFF_RCC_MPCKSELR         0x0020	/* (RW) RCC MPU Clock Selection Register */
  #define RCC_MPCKSELR_MPUSRC         0x00000003	/* MPU clock switch */
  #define RCC_MPCKSELR_MPUSRC_0       0x00000000
  #define RCC_MPCKSELR_MPUSRC_1       0x00000001
  #define RCC_MPCKSELR_MPUSRC_2       0x00000002
  #define RCC_MPCKSELR_MPUSRC_3       0x00000003
  #define RCC_MPCKSELR_MPUSRCRDY      0x80000000	/* MPU clock switch status */
#define TOFF_RCC_ASSCKSELR        0x0024	/* (RW) RCC AXI Sub-System Clock Selection Register */
  #define RCC_ASSCKSELR_AXISSRC       0x00000007	/* AXI sub-system clock switch */
  #define RCC_ASSCKSELR_AXISSRC_0     0x00000000
  #define RCC_ASSCKSELR_AXISSRC_1     0x00000001
  #define RCC_ASSCKSELR_AXISSRC_2     0x00000002
  #define RCC_ASSCKSELR_AXISSRC_3     0x00000003
  #define RCC_ASSCKSELR_AXISSRC_4     0x00000004
  #define RCC_ASSCKSELR_AXISSRC_5     0x00000005
  #define RCC_ASSCKSELR_AXISSRC_6     0x00000006
  #define RCC_ASSCKSELR_AXISSRC_7     0x00000007
  #define RCC_ASSCKSELR_AXISSRCRDY    0x80000000	/* AXI sub-system clock switch status */
#define TOFF_RCC_RCK12SELR        0x0028	/* (RW) RCC PLL 1 and 2 Ref. Clock Selection Register */
  #define RCC_RCK12SELR_PLL12SRC      0x00000003	/* Reference clock selection for PLL1 and PLL2 */
  #define RCC_RCK12SELR_PLL12SRC_0    0x00000000
  #define RCC_RCK12SELR_PLL12SRC_1    0x00000001
  #define RCC_RCK12SELR_PLL12SRC_2    0x00000002
  #define RCC_RCK12SELR_PLL12SRC_3    0x00000003
  #define RCC_RCK12SELR_PLL12SRC_4    0x00000004
  #define RCC_RCK12SELR_PLL12SRC_5    0x00000005
  #define RCC_RCK12SELR_PLL12SRC_6    0x00000006
  #define RCC_RCK12SELR_PLL12SRC_7    0x00000007
  #define RCC_RCK12SELR_PLL12SRCRDY   0x80000000	/* PLL12 reference clock switch status */
#define TOFF_RCC_MPCKDIVR         0x002C	/* (RW) RCC MPU Clock Divider Register */
  #define RCC_MPCKDIVR_MPUDIV         0x00000007	/* MPU Core clock divider */
  #define RCC_MPCKDIVR_MPUDIV_0       0x00000000
  #define RCC_MPCKDIVR_MPUDIV_1       0x00000001
  #define RCC_MPCKDIVR_MPUDIV_2       0x00000002
  #define RCC_MPCKDIVR_MPUDIV_3       0x00000003
  #define RCC_MPCKDIVR_MPUDIV_4       0x00000004
  #define RCC_MPCKDIVR_MPUDIV_5       0x00000005
  #define RCC_MPCKDIVR_MPUDIV_6       0x00000006
  #define RCC_MPCKDIVR_MPUDIV_7       0x00000007
  #define RCC_MPCKDIVR_MPUDIVRDY      0x80000000	/* MPU sub-system clock divider status */
#define TOFF_RCC_AXIDIVR          0x0030	/* (RW) RCC AXI Clock Divider Register */
  #define RCC_AXIDIVR_AXIDIV          0x00000007	/* AXI, AHB5 and AHB6 clock divider */
  #define RCC_AXIDIVR_AXIDIV_0        0x00000000
  #define RCC_AXIDIVR_AXIDIV_1        0x00000001
  #define RCC_AXIDIVR_AXIDIV_2        0x00000002
  #define RCC_AXIDIVR_AXIDIV_3        0x00000003
  #define RCC_AXIDIVR_AXIDIV_4        0x00000004
  #define RCC_AXIDIVR_AXIDIV_5        0x00000005
  #define RCC_AXIDIVR_AXIDIV_6        0x00000006
  #define RCC_AXIDIVR_AXIDIV_7        0x00000007
  #define RCC_AXIDIVR_AXIDIVRDY       0x80000000	/* AXI sub-system clock divider status */
#define TOFF_RCC_APB4DIVR         0x003C	/* (RW) RCC APB4 Clock Divider Register */
  #define RCC_APB4DIVR_APB4DIV        0x00000007	/* APB4 clock divider */
  #define RCC_APB4DIVR_APB4DIV_0      0x00000000
  #define RCC_APB4DIVR_APB4DIV_1      0x00000001
  #define RCC_APB4DIVR_APB4DIV_2      0x00000002
  #define RCC_APB4DIVR_APB4DIV_3      0x00000003
  #define RCC_APB4DIVR_APB4DIV_4      0x00000004
  #define RCC_APB4DIVR_APB4DIV_5      0x00000005
  #define RCC_APB4DIVR_APB4DIV_6      0x00000006
  #define RCC_APB4DIVR_APB4DIV_7      0x00000007
  #define RCC_APB4DIVR_APB4DIVRDY     0x80000000	/* APB4 clock divider status */
#define TOFF_RCC_APB5DIVR         0x0040	/* (RW) RCC APB5 Clock Divider Register */
  #define RCC_APB5DIVR_APB5DIV        0x00000007	/* APB5 clock divider */
  #define RCC_APB5DIVR_APB5DIV_0      0x00000000
  #define RCC_APB5DIVR_APB5DIV_1      0x00000001
  #define RCC_APB5DIVR_APB5DIV_2      0x00000002
  #define RCC_APB5DIVR_APB5DIV_3      0x00000003
  #define RCC_APB5DIVR_APB5DIV_4      0x00000004
  #define RCC_APB5DIVR_APB5DIV_5      0x00000005
  #define RCC_APB5DIVR_APB5DIV_6      0x00000006
  #define RCC_APB5DIVR_APB5DIV_7      0x00000007
  #define RCC_APB5DIVR_APB5DIVRDY     0x80000000	/* APB5 clock divider status */
#define TOFF_RCC_RTCDIVR          0x0044	/* (RW) RCC RTC Clock Division Register */
  #define RCC_RTCDIVR_RTCDIV          0x0000003F	/* HSE division factor for RTC clock */
  #define RCC_RTCDIVR_RTCDIV_1        0x00000000
  #define RCC_RTCDIVR_RTCDIV_2        0x00000001
  #define RCC_RTCDIVR_RTCDIV_3        0x00000002
  #define RCC_RTCDIVR_RTCDIV_4        0x00000003
  #define RCC_RTCDIVR_RTCDIV_5        0x00000004
  #define RCC_RTCDIVR_RTCDIV_6        0x00000005
  #define RCC_RTCDIVR_RTCDIV_7        0x00000006
  #define RCC_RTCDIVR_RTCDIV_8        0x00000007
  #define RCC_RTCDIVR_RTCDIV_9        0x00000008
  #define RCC_RTCDIVR_RTCDIV_10       0x00000009
  #define RCC_RTCDIVR_RTCDIV_11       0x0000000A
  #define RCC_RTCDIVR_RTCDIV_12       0x0000000B
  #define RCC_RTCDIVR_RTCDIV_13       0x0000000C
  #define RCC_RTCDIVR_RTCDIV_14       0x0000000D
  #define RCC_RTCDIVR_RTCDIV_15       0x0000000E
  #define RCC_RTCDIVR_RTCDIV_16       0x0000000F
  #define RCC_RTCDIVR_RTCDIV_17       0x00000010
  #define RCC_RTCDIVR_RTCDIV_18       0x00000011
  #define RCC_RTCDIVR_RTCDIV_19       0x00000012
  #define RCC_RTCDIVR_RTCDIV_20       0x00000013
  #define RCC_RTCDIVR_RTCDIV_21       0x00000014
  #define RCC_RTCDIVR_RTCDIV_22       0x00000015
  #define RCC_RTCDIVR_RTCDIV_23       0x00000016
  #define RCC_RTCDIVR_RTCDIV_24       0x00000017
  #define RCC_RTCDIVR_RTCDIV_25       0x00000018
  #define RCC_RTCDIVR_RTCDIV_26       0x00000019
  #define RCC_RTCDIVR_RTCDIV_27       0x0000001A
  #define RCC_RTCDIVR_RTCDIV_28       0x0000001B
  #define RCC_RTCDIVR_RTCDIV_29       0x0000001C
  #define RCC_RTCDIVR_RTCDIV_30       0x0000001D
  #define RCC_RTCDIVR_RTCDIV_31       0x0000001E
  #define RCC_RTCDIVR_RTCDIV_32       0x0000001F
  #define RCC_RTCDIVR_RTCDIV_33       0x00000020
  #define RCC_RTCDIVR_RTCDIV_34       0x00000021
  #define RCC_RTCDIVR_RTCDIV_35       0x00000022
  #define RCC_RTCDIVR_RTCDIV_36       0x00000023
  #define RCC_RTCDIVR_RTCDIV_37       0x00000024
  #define RCC_RTCDIVR_RTCDIV_38       0x00000025
  #define RCC_RTCDIVR_RTCDIV_39       0x00000026
  #define RCC_RTCDIVR_RTCDIV_40       0x00000027
  #define RCC_RTCDIVR_RTCDIV_41       0x00000028
  #define RCC_RTCDIVR_RTCDIV_42       0x00000029
  #define RCC_RTCDIVR_RTCDIV_43       0x0000002A
  #define RCC_RTCDIVR_RTCDIV_44       0x0000002B
  #define RCC_RTCDIVR_RTCDIV_45       0x0000002C
  #define RCC_RTCDIVR_RTCDIV_46       0x0000002D
  #define RCC_RTCDIVR_RTCDIV_47       0x0000002E
  #define RCC_RTCDIVR_RTCDIV_48       0x0000002F
  #define RCC_RTCDIVR_RTCDIV_49       0x00000030
  #define RCC_RTCDIVR_RTCDIV_50       0x00000031
  #define RCC_RTCDIVR_RTCDIV_51       0x00000032
  #define RCC_RTCDIVR_RTCDIV_52       0x00000033
  #define RCC_RTCDIVR_RTCDIV_53       0x00000034
  #define RCC_RTCDIVR_RTCDIV_54       0x00000035
  #define RCC_RTCDIVR_RTCDIV_55       0x00000036
  #define RCC_RTCDIVR_RTCDIV_56       0x00000037
  #define RCC_RTCDIVR_RTCDIV_57       0x00000038
  #define RCC_RTCDIVR_RTCDIV_58       0x00000039
  #define RCC_RTCDIVR_RTCDIV_59       0x0000003A
  #define RCC_RTCDIVR_RTCDIV_60       0x0000003B
  #define RCC_RTCDIVR_RTCDIV_61       0x0000003C
  #define RCC_RTCDIVR_RTCDIV_62       0x0000003D
  #define RCC_RTCDIVR_RTCDIV_63       0x0000003E
  #define RCC_RTCDIVR_RTCDIV_64       0x0000003F
#define TOFF_RCC_MSSCKSELR        0x0048	/* (RW) RCC MCU Sub-System Clock Selection Register */
  #define RCC_MSSCKSELR_MCUSSRC       0x00000003	/* MCU sub-system clock switch */
  #define RCC_MSSCKSELR_MCUSSRC_0     0x00000000
  #define RCC_MSSCKSELR_MCUSSRC_1     0x00000001
  #define RCC_MSSCKSELR_MCUSSRC_2     0x00000002
  #define RCC_MSSCKSELR_MCUSSRC_3     0x00000003
  #define RCC_MSSCKSELR_MCUSSRCRDY    0x80000000	/* MCU sub-system clock switch status */
#define TOFF_RCC_PLL1CR           0x0080	/* (RW) RCC PLL1 Control Register */
  #define RCC_PLL1CR_PLLON            0x00000001	/* PLL1 enable */
  #define RCC_PLL1CR_PLL1RDY          0x00000002	/* PLL1 clock ready flag */
  #define RCC_PLL1CR_SSCG_CTRL        0x00000004	/* Spread Spectrum Clock Generator of PLL1 enable */
  #define RCC_PLL1CR_DIVPEN           0x00000010	/* PLL1 DIVP divider output enable */
  #define RCC_PLL1CR_DIVQEN           0x00000020	/* PLL1 DIVQ divider output enable */
  #define RCC_PLL1CR_DIVREN           0x00000040	/* PLL1 DIVR divider output enable */
#define TOFF_RCC_PLL1CFGR1        0x0084	/* (RW) RCC PLL1 Configuration Register 1 */
  #define RCC_PLL1CFGR1_DIVN          0x000001FF	/* Multiplication factor for PLL1 VCO */
  #define RCC_PLL1CFGR1_DIVN_25       0x00000018	/* Division ratio is 25 */
  #define RCC_PLL1CFGR1_DIVN_26       0x00000019	/* Division ratio is 26 */
  #define RCC_PLL1CFGR1_DIVN_100      0x00000063	/* Division ratio is 100 */
  #define RCC_PLL1CFGR1_DIVM1         0x003F0000	/* Prescaler for PLL1 */
#define TOFF_RCC_PLL1CFGR2        0x0088	/* (RW) RCC PLL1 Configuration Register 2 */
  #define RCC_PLL1CFGR2_DIVP          0x0000007F	/* PLL1 DIVP division factor */
  #define RCC_PLL1CFGR2_DIVP_0        0x00000000
  #define RCC_PLL1CFGR2_DIVP_1        0x00000001
  #define RCC_PLL1CFGR2_DIVP_128      0x0000007F
  #define RCC_PLL1CFGR2_DIVQ          0x00007F00	/* PLL1 DIVQ division factor */
  #define RCC_PLL1CFGR2_DIVQ_0        0x00000000
  #define RCC_PLL1CFGR2_DIVQ_1        0x00000100
  #define RCC_PLL1CFGR2_DIVQ_128      0x00007F00
  #define RCC_PLL1CFGR2_DIVR          0x007F0000	/* PLL1 DIVR division factor */
  #define RCC_PLL1CFGR2_DIVR_0        0x00000000
  #define RCC_PLL1CFGR2_DIVR_1        0x00010000
  #define RCC_PLL1CFGR2_DIVR_128      0x007F0000
#define TOFF_RCC_PLL1FRACR        0x008C	/* (RW) RCC PLL1 Fractional Register */
  #define RCC_PLL1FRACR_FRACV         0x0000FFF8	/* Fractional part of the multiplication factor for PLL1 VCO */
  #define RCC_PLL1FRACR_FRACLE        0x00010000	/* PLL1 fractional latch enable */
#define TOFF_RCC_PLL1CSGR         0x0090	/* (RW) RCC PLL1 Clock Spreading Generator Register */
  #define RCC_PLL1CSGR_MOD_PER        0x00001FFF	/* Modulation Period Adjustment for PLL1 */
  #define RCC_PLL1CSGR_TPDFN_DIS      0x00002000	/* Dithering TPDF noise control */
  #define RCC_PLL1CSGR_RPDFN_DIS      0x00004000	/* Dithering RPDF noise control */
  #define RCC_PLL1CSGR_SSCG_MODE      0x00008000	/* Spread spectrum clock generator mode */
  #define RCC_PLL1CSGR_INC_STEP       0x7FFF0000	/* Modulation Depth Adjustment for PLL1 */
#define TOFF_RCC_PLL2CR           0x0094	/* (RW) RCC PLL2 Control Register */
  #define RCC_PLL2CR_PLLON            0x00000001	/* PLL2 enable */
  #define RCC_PLL2CR_PLL2RDY          0x00000002	/* PLL2 clock ready flag */
  #define RCC_PLL2CR_SSCG_CTRL        0x00000004	/* Spread Spectrum Clock Generator of PLL2 enable */
  #define RCC_PLL2CR_DIVPEN           0x00000010	/* PLL2 DIVP divider output enable */
  #define RCC_PLL2CR_DIVQEN           0x00000020	/* PLL2 DIVQ divider output enable */
  #define RCC_PLL2CR_DIVREN           0x00000040	/* PLL2 DIVR divider output enable */
#define TOFF_RCC_PLL2CFGR1        0x0098	/* (RW) RCC PLL2 Configuration Register 1 */
  #define RCC_PLL2CFGR1_DIVN          0x000001FF	/* Multiplication factor for PLL2 */
  #define RCC_PLL2CFGR1_DIVN_25       0x00000018	/* Division ratio is 25 */
  #define RCC_PLL2CFGR1_DIVN_26       0x00000019	/* Division ratio is 26 */
  #define RCC_PLL2CFGR1_DIVN_100      0x00000063	/* Division ratio is 100 */
  #define  RCC_PLL2CFGR1_DIVM2        0x003F0000	/* Prescaler for PLL2 */
#define TOFF_RCC_PLL2CFGR2        0x009C	/* (RW) RCC PLL2 Configuration Register 2 */
  #define RCC_PLL2CFGR2_DIVP          0x0000007F	/* PLL2 DIVP division factor */
  #define RCC_PLL2CFGR2_DIVP_0        0x00000000
  #define RCC_PLL2CFGR2_DIVP_1        0x00000001
  #define RCC_PLL2CFGR2_DIVP_128      0x0000007F
  #define RCC_PLL2CFGR2_DIVQ          0x00007F00	/* PLL2 DIVQ division factor */
  #define RCC_PLL2CFGR2_DIVQ_0        0x00000000
  #define RCC_PLL2CFGR2_DIVQ_1        0x00000100
  #define RCC_PLL2CFGR2_DIVQ_128      0x00007F00
  #define RCC_PLL2CFGR2_DIVR          0x007F0000	/* PLL2 DIVR division factor */
  #define RCC_PLL2CFGR2_DIVR_0        0x00000000
  #define RCC_PLL2CFGR2_DIVR_1        0x00010000
  #define RCC_PLL2CFGR2_DIVR_128      0x007F0000
#define TOFF_RCC_PLL2FRACR        0x00A0	/* (RW) RCC PLL2 Fractional Register */
  #define RCC_PLL2FRACR_FRACV         0x0000FFF8	/* Fractional part of the multiplication factor for PLL2 VCO */
  #define RCC_PLL2FRACR_FRACLE        0x00010000	/* PLL2 fractional latch enable */
#define TOFF_RCC_PLL2CSGR         0x00A4	/* (RW) RCC PLL2 Clock Spreading Generator Register */
  #define RCC_PLL2CSGR_MOD_PER        0x00001FFF	/* Modulation Period Adjustment for PLL2 */
  #define RCC_PLL2CSGR_TPDFN_DIS      0x00002000	/* Dithering TPDF noise control */
  #define RCC_PLL2CSGR_RPDFN_DIS      0x00004000	/* Dithering RPDF noise control */
  #define RCC_PLL2CSGR_SSCG_MODE      0x00008000	/* Spread spectrum clock generator mode */
  #define RCC_PLL2CSGR_INC_STEP       0x7FFF0000	/* Modulation Depth Adjustment for PLL2 */
#define TOFF_RCC_I2C46CKSELR      0x00C0	/* (RW) RCC I2C46 Kernel Clock Selection Register */
  #define RCC_I2C46CKSELR_I2C46SRC    0x00000007	/* I2C4 kernel clock source selection */
  #define RCC_I2C46CKSELR_I2C46SRC_0  0x00000000
  #define RCC_I2C46CKSELR_I2C46SRC_1  0x00000001
  #define RCC_I2C46CKSELR_I2C46SRC_2  0x00000002
  #define RCC_I2C46CKSELR_I2C46SRC_3  0x00000003
#define TOFF_RCC_SPI6CKSELR       0x00C4	/* (RW) RCC SPI6 Kernel Clock Selection Register */
  #define RCC_SPI6CKSELR_SPI6SRC      0x00000007	/* SPI6 kernel clock source selection */
  #define RCC_SPI6CKSELR_SPI6SRC_0    0x00000000
  #define RCC_SPI6CKSELR_SPI6SRC_1    0x00000001
  #define RCC_SPI6CKSELR_SPI6SRC_2    0x00000002
  #define RCC_SPI6CKSELR_SPI6SRC_3    0x00000003
  #define RCC_SPI6CKSELR_SPI6SRC_4    0x00000004
  #define RCC_SPI6CKSELR_SPI6SRC_5    0x00000005
#define TOFF_RCC_UART1CKSELR      0x00C8	/* (RW) RCC USART1 Kernel Clock Selection Register */
  #define RCC_UART1CKSELR_UART1SRC    0x00000007	/* UART1 kernel clock source selection */
  #define RCC_UART1CKSELR_UART1SRC_0  0x00000000
  #define RCC_UART1CKSELR_UART1SRC_1  0x00000001
  #define RCC_UART1CKSELR_UART1SRC_2  0x00000002
  #define RCC_UART1CKSELR_UART1SRC_3  0x00000003
  #define RCC_UART1CKSELR_UART1SRC_4  0x00000004
  #define RCC_UART1CKSELR_UART1SRC_5  0x00000005
#define TOFF_RCC_RNG1CKSELR       0x00CC	/* (RW) RCC RNG1 Kernel Clock Selection Register */
  #define RCC_RNG1CKSELR_RNG1SRC      0x00000003	/* RNG1 kernel clock source selection */
  #define RCC_RNG1CKSELR_RNG1SRC_0    0x00000000
  #define RCC_RNG1CKSELR_RNG1SRC_1    0x00000001
  #define RCC_RNG1CKSELR_RNG1SRC_2    0x00000002
  #define RCC_RNG1CKSELR_RNG1SRC_3    0x00000003
#define TOFF_RCC_CPERCKSELR       0x00D0	/* (RW) RCC Common Peripheral Clock Selection Register */
  #define RCC_CPERCKSELR_CKPERSRC     0x00000003	/* Oscillator selection for kernel clock */
  #define RCC_CPERCKSELR_CKPERSRC_0   0x00000000
  #define RCC_CPERCKSELR_CKPERSRC_1   0x00000001
  #define RCC_CPERCKSELR_CKPERSRC_2   0x00000002
  #define RCC_CPERCKSELR_CKPERSRC_3   0x00000003
#define TOFF_RCC_STGENCKSELR      0x00D4	/* (RW) RCC STGEN Clock Selection Register */
  #define RCC_STGENCKSELR_STGENSRC    0x00000003	/* Oscillator selection for kernel clock */
  #define RCC_STGENCKSELR_STGENSRC_0  0x00000000
  #define RCC_STGENCKSELR_STGENSRC_1  0x00000001
  #define RCC_STGENCKSELR_STGENSRC_2  0x00000002
#define TOFF_RCC_DDRITFCR         0x00D8	/* (RW) RCC control DDR interface, DDRC and DDRPHYC Register */
  #define  RCC_DDRITFCR_DDRC1EN       0x00000001
  #define  RCC_DDRITFCR_DDRC1LPEN     0x00000002
  #define  RCC_DDRITFCR_DDRC2EN       0x00000004
  #define  RCC_DDRITFCR_DDRC2LPEN     0x00000008
  #define  RCC_DDRITFCR_DDRPHYCEN     0x00000010
  #define  RCC_DDRITFCR_DDRPHYCLPEN   0x00000020
  #define  RCC_DDRITFCR_DDRCAPBEN     0x00000040
  #define  RCC_DDRITFCR_DDRCAPBLPEN   0x00000080
  #define  RCC_DDRITFCR_AXIDCGEN      0x00000100
  #define  RCC_DDRITFCR_DDRPHYCAPBEN  0x00000200
  #define  RCC_DDRITFCR_DDRPHYCAPBLPEN 0x00000400
  #define RCC_DDRITFCR_KERDCG_DLY     0x00003C00	/* AXIDCG delay */
  #define RCC_DDRITFCR_KERDCG_DLY_0   0x00000000
  #define RCC_DDRITFCR_KERDCG_DLY_1   0x00000400
  #define RCC_DDRITFCR_KERDCG_DLY_2   0x00000800
  #define RCC_DDRITFCR_KERDCG_DLY_3   0x00000C00
  #define RCC_DDRITFCR_KERDCG_DLY_4   0x00001000
  #define RCC_DDRITFCR_KERDCG_DLY_5   0x00001400
  #define RCC_DDRITFCR_KERDCG_DLY_6   0x00001800
  #define RCC_DDRITFCR_KERDCG_DLY_7   0x00001C00
  #define RCC_DDRITFCR_KERDCG_DLY_8   0x00002000
  #define RCC_DDRITFCR_KERDCG_DLY_9   0x00002400
  #define RCC_DDRITFCR_KERDCG_DLY_10  0x00002800
  #define RCC_DDRITFCR_KERDCG_DLY_11  0x00002C00
  #define RCC_DDRITFCR_KERDCG_DLY_12  0x00003000
  #define RCC_DDRITFCR_KERDCG_DLY_13  0x00003400
  #define RCC_DDRITFCR_KERDCG_DLY_14  0x00003800
  #define RCC_DDRITFCR_KERDCG_DLY_15  0x00003C00
  #define  RCC_DDRITFCR_DDRCAPBRST    0x00004000
  #define  RCC_DDRITFCR_DDRCAXIRST    0x00008000
  #define  RCC_DDRITFCR_DDRCORERST    0x00010000
  #define  RCC_DDRITFCR_DPHYAPBRST    0x00020000
  #define  RCC_DDRITFCR_DPHYRST       0x00040000
  #define  RCC_DDRITFCR_DPHYCTLRST    0x00080000
  #define RCC_DDRITFCR_DDRCKMOD       0x00700000	/* RCC mode for DDR clock control */
  #define RCC_DDRITFCR_DDRCKMOD_0     0x00000000
  #define RCC_DDRITFCR_DDRCKMOD_1     0x00100000
  #define RCC_DDRITFCR_DDRCKMOD_2     0x00200000
  #define RCC_DDRITFCR_DDRCKMOD_5     0x00500000
  #define RCC_DDRITFCR_DDRCKMOD_6     0x00600000
#define TOFF_RCC_MP_BOOTCR        0x0100	/* (RW) RCC Hold Boot Control Register */
  #define RCC_MP_BOOTCR_MCU_BEN       0x00000001	/* MCU Boot Enable after STANDBY */
  #define RCC_MP_BOOTCR_MPU_BEN       0x00000002	/* MPU Boot Enable after STANDBY */
#define TOFF_RCC_MP_SREQSETR      0x0104	/* (RW) RCC Stop Request Set Register */
  #define RCC_MP_SREQSETR_STPREQ_P0   0x00000001	/* Stop Request for MPU processor number 0 */
  #define RCC_MP_SREQSETR_STPREQ_P1   0x00000002	/* Stop Request for MPU processor number 1 */
#define TOFF_RCC_MP_SREQCLRR      0x0108	/* (RW) RCC Stop Request Clear Register */
  #define RCC_MP_SREQCLRR_STPREQ_P0   0x00000001	/* Stop Request for MPU processor number 0 */
  #define RCC_MP_SREQCLRR_STPREQ_P1   0x00000002	/* Stop Request for MPU processor number 1 */
#define TOFF_RCC_MP_GCR           0x010C	/* (RW) RCC Global Control Register */
  #define RCC_MP_GCR_BOOT_MCU         0x00000001	/* Allows the MCU to boot */
  #define RCC_MP_GCR_BOOT_MCU_0       0x00000000
  #define RCC_MP_GCR_BOOT_MCU_1       0x00000001
#define TOFF_RCC_MP_APRSTCR       0x0110	/* (RW) RCC Application Reset Control Register */
  #define RCC_MP_APRSTCR_RDCTLEN      0x00000001	/* Reset Delay Control Enable */
  #define RCC_MP_APRSTCR_RSTTO        0x00007F00	/* Reset Timeout Delay Adjust */
#define TOFF_RCC_MP_APRSTSR       0x0114	/* (RW) RCC Application Reset Status Register */
  #define RCC_MP_APRSTSR_RSTTOV       0x00007F00	/* Reset Timeout Delay Value */
#define TOFF_RCC_BDCR             0x0140	/* (RW) RCC Backup Domain Control Register */
  #define RCC_BDCR_LSEON              0x00000001	/* LSE oscillator enabled */
  #define RCC_BDCR_LSEBYP             0x00000002	/* LSE oscillator bypass */
  #define RCC_BDCR_LSERDY             0x00000004	/* LSE oscillator ready */
  #define RCC_BDCR_DIGBYP             0x00000008	/* LSE digital bypass */
  #define RCC_BDCR_LSEDRV             0x00000030	/* LSE oscillator driving capability */
  #define RCC_BDCR_LSEDRV_0           0x00000000
  #define RCC_BDCR_LSEDRV_1           0x00000010
  #define RCC_BDCR_LSEDRV_2           0x00000020
  #define RCC_BDCR_LSEDRV_3           0x00000030
  #define RCC_BDCR_LSECSSON           0x00000100	/* LSE clock security system enable */
  #define RCC_BDCR_LSECSSD            0x00000200	/* LSE clock security system failure detection */
  #define RCC_BDCR_RTCSRC             0x00030000	/* RTC clock source selection */
  #define RCC_BDCR_RTCSRC_0           0x00000000
  #define RCC_BDCR_RTCSRC_1           0x00010000
  #define RCC_BDCR_RTCSRC_2           0x00020000
  #define RCC_BDCR_RTCSRC_3           0x00030000
  #define RCC_BDCR_RTCCKEN            0x00100000	/* RTC clock enable */
  #define RCC_BDCR_VSWRST             0x80000000	/* V Switch domain software reset */
#define TOFF_RCC_RDLSICR          0x0144	/* (RW) RCC Reset Duration and LSI Control Register */
  #define RCC_RDLSICR_LSION           0x00000001	/* LSI oscillator enabled */
  #define RCC_RDLSICR_LSIRDY          0x00000002	/* LSI oscillator ready */
  #define RCC_RDLSICR_MRD             0x001F0000	/* Minimum Reset Duration */
  #define RCC_RDLSICR_EADLY           0x07000000	/* External access delays */
  #define RCC_RDLSICR_SPARE           0xF8000000	/* Spare bits */
#define TOFF_RCC_APB4RSTSETR      0x0180	/* (RW) RCC APB4 Peripheral Reset Set Register */
  #define RCC_APB4RSTSETR_LTDCRST     0x00000001
  #define RCC_APB4RSTSETR_DSIRST      0x00000010
  #define RCC_APB4RSTSETR_DDRPERFMRST 0x00000100
  #define RCC_APB4RSTSETR_USBPHYRST   0x00010000
#define TOFF_RCC_APB4RSTCLRR      0x0184	/* (RW) RCC APB4 Peripheral Reset Clear Register */
  #define RCC_APB4RSTCLRR_LTDCRST     0x00000001
  #define RCC_APB4RSTCLRR_DSIRST      0x00000010
  #define RCC_APB4RSTCLRR_DDRPERFMRST 0x00000100
  #define RCC_APB4RSTCLRR_USBPHYRST   0x00010000
#define TOFF_RCC_APB5RSTSETR      0x0188	/* (RW) RCC APB5 Peripheral Reset Set Register */
  #define RCC_APB5RSTSETR_SPI6RST     0x00000001
  #define RCC_APB5RSTSETR_I2C4RST     0x00000004
  #define RCC_APB5RSTSETR_I2C6RST     0x00000008
  #define RCC_APB5RSTSETR_USART1RST   0x00000010
  #define RCC_APB5RSTSETR_STGENRST    0x00100000
#define TOFF_RCC_APB5RSTCLRR      0x018C	/* (RW) RCC APB5 Peripheral Reset Clear Register */
  #define RCC_APB5RSTCLRR_SPI6RST     0x00000001
  #define RCC_APB5RSTCLRR_I2C4RST     0x00000004
  #define RCC_APB5RSTCLRR_I2C6RST     0x00000008
  #define RCC_APB5RSTCLRR_USART1RST   0x00000010
  #define RCC_APB5RSTCLRR_STGENRST    0x00100000
#define TOFF_RCC_AHB5RSTSETR      0x0190	/* (RW) RCC AHB5 Peripheral Reset Set Register */
  #define RCC_AHB5RSTSETR_GPIOZRST    0x00000001
  #define RCC_AHB5RSTSETR_CRYP1RST    0x00000010
  #define RCC_AHB5RSTSETR_HASH1RST    0x00000020
  #define RCC_AHB5RSTSETR_RNG1RST     0x00000040
  #define RCC_AHB5RSTSETR_AXIMCRST    0x00010000
#define TOFF_RCC_AHB5RSTCLRR      0x0194	/* (RW) RCC AHB5 Peripheral Reset Clear Register */
  #define RCC_AHB5RSTCLRR_GPIOZRST    0x00000001
  #define RCC_AHB5RSTCLRR_CRYP1RST    0x00000010
  #define RCC_AHB5RSTCLRR_HASH1RST    0x00000020
  #define RCC_AHB5RSTCLRR_RNG1RST     0x00000040
  #define RCC_AHB5RSTCLRR_AXIMCRST    0x00010000
#define TOFF_RCC_AHB6RSTSETR      0x0198	/* (RW) RCC AHB6 Peripheral Reset Set Register */
  #define RCC_AHB6RSTSETR_GPURST      0x00000020
  #define RCC_AHB6RSTSETR_ETHMACRST   0x00000400
  #define RCC_AHB6RSTSETR_FMCRST      0x00001000
  #define RCC_AHB6RSTSETR_QSPIRST     0x00004000
  #define RCC_AHB6RSTSETR_SDMMC1RST   0x00010000
  #define RCC_AHB6RSTSETR_SDMMC2RST   0x00020000
  #define RCC_AHB6RSTSETR_CRC1RST     0x00100000
  #define RCC_AHB6RSTSETR_USBHRST     0x01000000
#define TOFF_RCC_AHB6RSTCLRR      0x019C	/* (RW) RCC AHB6 Peripheral Reset Clear Register */
  #define RCC_AHB6RSTCLRR_ETHMACRST   0x00000400
  #define RCC_AHB6RSTCLRR_FMCRST      0x00001000
  #define RCC_AHB6RSTCLRR_QSPIRST     0x00004000
  #define RCC_AHB6RSTCLRR_SDMMC1RST   0x00010000
  #define RCC_AHB6RSTCLRR_SDMMC2RST   0x00020000
  #define RCC_AHB6RSTCLRR_CRC1RST     0x00100000
  #define RCC_AHB6RSTCLRR_USBHRST     0x01000000
#define TOFF_RCC_TZAHB6RSTSETR    0x01A0	/* (RW) RCC AHB6 Peripheral Reset Set Register */
  #define RCC_TZAHB6RSTSETR_MDMARST   0x00000001
#define TOFF_RCC_TZAHB6RSTCLRR    0x01A4	/* (RW) RCC AHB6 Peripheral Reset Clear Register */
  #define RCC_TZAHB6RSTCLRR_MDMARST   0x00000001
#define TOFF_RCC_MP_APB4ENSETR    0x0200	/* (RW) RCC APB4 Periph. Enable For MPU Set Register */
  #define RCC_MP_APB4ENSETR_LTDCEN      0x00000001
  #define RCC_MP_APB4ENSETR_DSIEN       0x00000010
  #define RCC_MP_APB4ENSETR_IWDG2APBEN  0x00008000
  #define RCC_MP_APB4ENSETR_USBPHYEN    0x00010000
  #define RCC_MP_APB4ENSETR_STGENROEN   0x00100000
#define TOFF_RCC_MP_APB4ENCLRR    0x0204	/* (RW) RCC APB4 Periph. Enable For MPU Clear Register */
  #define RCC_MP_APB4ENCLRR_LTDCEN      0x00000001
  #define RCC_MP_APB4ENCLRR_DSIEN       0x00000010
  #define RCC_MP_APB4ENCLRR_IWDG2APBEN  0x00008000
  #define RCC_MP_APB4ENCLRR_USBPHYEN    0x00010000
  #define RCC_MP_APB4ENCLRR_STGENROEN   0x00100000
#define TOFF_RCC_MP_APB5ENSETR    0x0208	/* (RW) RCC APB5 Periph. Enable For MPU Set Register */
  #define RCC_MP_APB5ENSETR_IWDG1APBEN  0x00008000
#define TOFF_RCC_MP_APB5ENCLRR    0x020C	/* (RW) RCC APB5 Periph. Enable For MPU Clear Register */
#define TOFF_RCC_MP_AHB5ENSETR    0x0210	/* (RW) RCC AHB5 Periph. Enable For MPU Set Register */
#define TOFF_RCC_MP_AHB5ENCLRR    0x0214	/* (RW) RCC AHB5 Periph. Enable For MPU Clear Register */
#define TOFF_RCC_MP_AHB6ENSETR    0x0218	/* (RW) RCC AHB6 Periph. Enable For MPU Set Register */
#define TOFF_RCC_MP_AHB6ENCLRR    0x021C	/* (RW) RCC AHB6 Periph. Enable For MPU Clear Register */
#define TOFF_RCC_MC_APB4ENSETR    0x0280	/* (RW) RCC APB4 Periph. Enable For MCU Set Register */
  #define RCC_MC_APB4ENSETR_LTDCEN      0x00000001
  #define RCC_MC_APB4ENSETR_DSIEN       0x00000010
  #define RCC_MC_APB4ENSETR_DDRPERFMEN  0x00000100
  #define RCC_MC_APB4ENSETR_USBPHYEN    0x00010000
  #define RCC_MC_APB4ENSETR_STGENROEN   0x00100000
#define TOFF_RCC_MC_APB4ENCLRR    0x0284	/* (RW) RCC APB4 Periph. Enable For MCU Clear Register */
  #define RCC_MC_APB4ENCLRR_LTDCEN    0x00000001
  #define RCC_MC_APB4ENCLRR_DSIEN     0x00000010
  #define RCC_MC_APB4ENCLRR_USBPHYEN  0x00010000
  #define RCC_MC_APB4ENCLRR_STGENROEN 0x00100000
#define TOFF_RCC_MC_APB5ENSETR    0x0288	/* (RW) RCC APB5 Periph. Enable For MCU Set Register */
  #define RCC_MC_APB5ENSETR_SPI6EN    0x00000001
  #define RCC_MC_APB5ENSETR_I2C4EN    0x00000004
  #define RCC_MC_APB5ENSETR_I2C6EN    0x00000008
  #define RCC_MC_APB5ENSETR_USART1EN  0x00000010
  #define RCC_MC_APB5ENSETR_RTCAPBEN  0x00000100
  #define RCC_MC_APB5ENSETR_TZC1EN    0x00000800
  #define RCC_MC_APB5ENSETR_TZC2EN    0x00001000
  #define RCC_MC_APB5ENSETR_TZPCEN    0x00002000
  #define RCC_MC_APB5ENSETR_BSECEN    0x00010000
  #define RCC_MC_APB5ENSETR_STGENEN   0x00100000
#define TOFF_RCC_MC_APB5ENCLRR    0x028C	/* (RW) RCC APB5 Periph. Enable For MCU Clear Register */
  #define RCC_MC_APB5ENCLRR_SPI6EN    0x00000001
  #define RCC_MC_APB5ENCLRR_I2C4EN    0x00000004
  #define RCC_MC_APB5ENCLRR_I2C6EN    0x00000008
  #define RCC_MC_APB5ENCLRR_USART1EN  0x00000010
  #define RCC_MC_APB5ENCLRR_RTCAPBEN  0x00000100
  #define RCC_MC_APB5ENCLRR_TZC1EN    0x00000800
  #define RCC_MC_APB5ENCLRR_TZC2EN    0x00001000
  #define RCC_MC_APB5ENCLRR_TZPCEN    0x00002000
  #define RCC_MC_APB5ENCLRR_BSECEN    0x00010000
  #define RCC_MC_APB5ENCLRR_STGENEN   0x00100000
#define TOFF_RCC_MC_AHB5ENSETR    0x0290	/* (RW) RCC AHB5 Periph. Enable For MCU Set Register */
  #define RCC_MC_AHB5ENSETR_GPIOZEN   0x00000001
  #define RCC_MC_AHB5ENSETR_CRYP1EN   0x00000010
  #define RCC_MC_AHB5ENSETR_HASH1EN   0x00000020
  #define RCC_MC_AHB5ENSETR_RNG1EN    0x00000040
  #define RCC_MC_AHB5ENSETR_BKPSRAMEN 0x00000100
  #define RCC_MC_AHB5ENSETR_AXIMC     0x00010000
#define TOFF_RCC_MC_AHB5ENCLRR    0x0294	/* (RW) RCC AHB5 Periph. Enable For MCU Clear Register */
  #define RCC_MC_AHB5ENCLRR_GPIOZEN   0x00000001
  #define RCC_MC_AHB5ENCLRR_CRYP1EN   0x00000010
  #define RCC_MC_AHB5ENCLRR_HASH1EN   0x00000020
  #define RCC_MC_AHB5ENCLRR_RNG1EN    0x00000040
  #define RCC_MC_AHB5ENCLRR_BKPSRAMEN 0x00000100
#define TOFF_RCC_MC_AHB6ENSETR    0x0298	/* (RW) RCC AHB6 Periph. Enable For MCU Set Register */
  #define RCC_MC_AHB6ENSETR_MDMAEN    0x00000001
  #define RCC_MC_AHB6ENSETR_GPUEN     0x00000020
  #define RCC_MC_AHB6ENSETR_ETHCKEN   0x00000080
  #define RCC_MC_AHB6ENSETR_ETHTXEN   0x00000100
  #define RCC_MC_AHB6ENSETR_ETHRXEN   0x00000200
  #define RCC_MC_AHB6ENSETR_ETHMACEN  0x00000400
  #define RCC_MC_AHB6ENSETR_FMCEN     0x00001000
  #define RCC_MC_AHB6ENSETR_QSPIEN    0x00004000
  #define RCC_MC_AHB6ENSETR_SDMMC1EN  0x00010000
  #define RCC_MC_AHB6ENSETR_SDMMC2EN  0x00020000
  #define RCC_MC_AHB6ENSETR_CRC1EN    0x00100000
  #define RCC_MC_AHB6ENSETR_USBHEN    0x01000000
#define TOFF_RCC_MC_AHB6ENCLRR    0x029C	/* (RW) RCC AHB6 Periph. Enable For MCU Clear Register */
  #define RCC_MC_AHB6ENCLRR_MDMAEN    0x00000001
  #define RCC_MC_AHB6ENCLRR_GPUEN     0x00000020
  #define RCC_MC_AHB6ENCLRR_ETHCKEN   0x00000080
  #define RCC_MC_AHB6ENCLRR_ETHTXEN   0x00000100
  #define RCC_MC_AHB6ENCLRR_ETHRXEN   0x00000200
  #define RCC_MC_AHB6ENCLRR_ETHMACEN  0x00000400
  #define RCC_MC_AHB6ENCLRR_FMCEN     0x00001000
  #define RCC_MC_AHB6ENCLRR_QSPIEN    0x00004000
  #define RCC_MC_AHB6ENCLRR_SDMMC1EN  0x00010000
  #define RCC_MC_AHB6ENCLRR_SDMMC2EN  0x00020000
  #define RCC_MC_AHB6ENCLRR_CRC1EN    0x00100000
  #define RCC_MC_AHB6ENCLRR_USBHEN    0x01000000
#define TOFF_RCC_MP_APB4LPENSETR  0x0300	/* (RW) RCC APB4 Sleep Clock Ena. For MPU Set Register */
  #define RCC_MP_APB4LPENSETR_LTDCLPEN     0x00000001
  #define RCC_MP_APB4LPENSETR_DSILPEN      0x00000010
  #define RCC_MP_APB4LPENSETR_IWDG2APBLPEN 0x00008000
  #define RCC_MP_APB4LPENSETR_USBPHYLPEN   0x00010000
  #define RCC_MP_APB4LPENSETR_STGENROLPEN  0x00100000
  #define RCC_MP_APB4LPENSETR_STGENROSTPEN 0x00200000
#define TOFF_RCC_MP_APB4LPENCLRR  0x0304	/* (RW) RCC APB4 Sleep Clock Ena. For MPU Clear Register */
  #define RCC_MP_APB4LPENCLRR_LTDCLPEN     0x00000001
  #define RCC_MP_APB4LPENCLRR_DSILPEN      0x00000010
  #define RCC_MP_APB4LPENCLRR_IWDG2APBLPEN 0x00008000
  #define RCC_MP_APB4LPENCLRR_USBPHYLPEN   0x00010000
  #define RCC_MP_APB4LPENCLRR_STGENROLPEN  0x00100000
  #define RCC_MP_APB4LPENCLRR_STGENROSTPEN 0x00200000
#define TOFF_RCC_MP_APB5LPENSETR  0x0308	/* (RW) RCC APB5 Sleep Clock Ena. For MPU Set Register */
#define TOFF_RCC_MP_APB5LPENCLRR  0x030C	/* (RW) RCC APB5 Sleep Clock Ena. For MPU Clear Register */
#define TOFF_RCC_MP_AHB5LPENSETR  0x0310	/* (RW) RCC AHB5 Sleep Clock Ena. For MPU Set Register */
#define TOFF_RCC_MP_AHB5LPENCLRR  0x0314	/* (RW) RCC AHB5 Sleep Clock Ena. For MPU Clear Register */
#define TOFF_RCC_MP_AHB6LPENSETR  0x0318	/* (RW) RCC AHB6 Sleep Clock Ena. For MPU Set Register */
#define TOFF_RCC_MP_AHB6LPENCLRR  0x031C	/* (RW) RCC AHB6 Sleep Clock Ena. For MPU Clear Register */
#define TOFF_RCC_MC_APB4LPENSETR  0x0380	/* (RW) RCC APB4 Sleep Clock Ena. For MCU Set Register */
  #define RCC_MC_APB4LPENSETR_LTDCLPEN     0x00000001
  #define RCC_MC_APB4LPENSETR_DSILPEN      0x00000010
  #define RCC_MC_APB4LPENSETR_USBPHYLPEN   0x00010000
  #define RCC_MC_APB4LPENSETR_STGENROLPEN  0x00100000
  #define RCC_MC_APB4LPENSETR_STGENROSTPEN 0x00200000
#define TOFF_RCC_MC_APB4LPENCLRR  0x0384	/* (RW) RCC APB4 Sleep Clock Ena. For MCU Clear Register */
  #define RCC_MC_APB4LPENCLRR_LTDCLPEN     0x00000001
  #define RCC_MC_APB4LPENCLRR_DSILPEN      0x00000010
  #define RCC_MC_APB4LPENCLRR_USBPHYLPEN   0x00010000
  #define RCC_MC_APB4LPENCLRR_STGENROLPEN  0x00100000
  #define RCC_MC_APB4LPENCLRR_STGENROSTPEN 0x00200000
#define TOFF_RCC_MC_APB5LPENSETR  0x0388	/* (RW) RCC APB5 Sleep Clock Ena. For MCU Set Register */
  #define RCC_MC_APB5LPENSETR_SPI6LPEN     0x00000001
  #define RCC_MC_APB5LPENSETR_I2C4LPEN     0x00000004
  #define RCC_MC_APB5LPENSETR_I2C6LPEN     0x00000008
  #define RCC_MC_APB5LPENSETR_USART1LPEN   0x00000010
  #define RCC_MC_APB5LPENSETR_RTCAPBLPEN   0x00000100
  #define RCC_MC_APB5LPENSETR_TZC1LPEN     0x00000800
  #define RCC_MC_APB5LPENSETR_TZC2LPEN     0x00001000
  #define RCC_MC_APB5LPENSETR_TZPCLPEN     0x00002000
  #define RCC_MC_APB5LPENSETR_BSECLPEN     0x00010000
  #define RCC_MC_APB5LPENSETR_STGENLPEN    0x00100000
  #define RCC_MC_APB5LPENSETR_STGENSTPEN   0x00200000
#define TOFF_RCC_MC_APB5LPENCLRR  0x038C	/* (RW) RCC APB5 Sleep Clock Ena. For MCU Clear Register */
  #define RCC_MC_APB5LPENCLRR_SPI6LPEN     0x00000001
  #define RCC_MC_APB5LPENCLRR_I2C4LPEN     0x00000004
  #define RCC_MC_APB5LPENCLRR_I2C6LPEN     0x00000008
  #define RCC_MC_APB5LPENCLRR_USART1LPEN   0x00000010
  #define RCC_MC_APB5LPENCLRR_RTCAPBLPEN   0x00000100
  #define RCC_MC_APB5LPENCLRR_TZC1LPEN     0x00000800
  #define RCC_MC_APB5LPENCLRR_TZC2LPEN     0x00001000
  #define RCC_MC_APB5LPENCLRR_TZPCLPEN     0x00002000
  #define RCC_MC_APB5LPENCLRR_BSECLPEN     0x00010000
  #define RCC_MC_APB5LPENCLRR_STGENLPEN    0x00100000
  #define RCC_MC_APB5LPENCLRR_STGENSTPEN   0x00200000
#define TOFF_RCC_MC_AHB5LPENSETR  0x0390	/* (RW) RCC AHB5 Sleep Clock Ena. For MCU Set Register */
  #define RCC_MC_AHB5LPENSETR_GPIOZLPEN    0x00000001
  #define RCC_MC_AHB5LPENSETR_CRYP1LPEN    0x00000010
  #define RCC_MC_AHB5LPENSETR_HASH1LPEN    0x00000020
  #define RCC_MC_AHB5LPENSETR_RNG1LPEN     0x00000040
  #define RCC_MC_AHB5LPENSETR_BKPSRAMLPEN  0x00000100
#define TOFF_RCC_MC_AHB5LPENCLRR  0x0394	/* (RW) RCC AHB5 Sleep Clock Ena. For MCU Clear Register */
  #define RCC_MC_AHB5LPENCLRR_GPIOZLPEN    0x00000001
  #define RCC_MC_AHB5LPENCLRR_CRYP1LPEN    0x00000010
  #define RCC_MC_AHB5LPENCLRR_HASH1LPEN    0x00000020
  #define RCC_MC_AHB5LPENCLRR_RNG1LPEN     0x00000040
  #define RCC_MC_AHB5LPENCLRR_BKPSRAMLPEN  0x00000100
#define TOFF_RCC_MC_AHB6LPENSETR  0x0398	/* (RW) RCC AHB6 Sleep Clock Ena. For MCU Set Register */
  #define RCC_MC_AHB6LPENSETR_MDMALPEN     0x00000001
  #define RCC_MC_AHB6LPENSETR_GPULPEN      0x00000020
  #define RCC_MC_AHB6LPENSETR_ETHCKLPEN    0x00000080
  #define RCC_MC_AHB6LPENSETR_ETHTXLPEN    0x00000100
  #define RCC_MC_AHB6LPENSETR_ETHRXLPEN    0x00000200
  #define RCC_MC_AHB6LPENSETR_ETHMACLPEN   0x00000400
  #define RCC_MC_AHB6LPENSETR_ETHSTPEN     0x00000800
  #define RCC_MC_AHB6LPENSETR_FMCLPEN      0x00001000
  #define RCC_MC_AHB6LPENSETR_QSPILPEN     0x00004000
  #define RCC_MC_AHB6LPENSETR_SDMMC1LPEN   0x00010000
  #define RCC_MC_AHB6LPENSETR_SDMMC2LPEN   0x00020000
  #define RCC_MC_AHB6LPENSETR_CRC1LPEN     0x00100000
  #define RCC_MC_AHB6LPENSETR_USBHLPEN     0x01000000
#define TOFF_RCC_MC_AHB6LPENCLRR  0x039C	/* (RW) RCC AHB6 Sleep Clock Ena. For MCU Clear Register */
  #define RCC_MC_AHB6LPENCLRR_MDMALPEN     0x00000001
  #define RCC_MC_AHB6LPENCLRR_GPULPEN      0x00000020
  #define RCC_MC_AHB6LPENCLRR_ETHCKLPEN    0x00000080
  #define RCC_MC_AHB6LPENCLRR_ETHTXLPEN    0x00000100
  #define RCC_MC_AHB6LPENCLRR_ETHRXLPEN    0x00000200
  #define RCC_MC_AHB6LPENCLRR_ETHMACLPEN   0x00000400
  #define RCC_MC_AHB6LPENCLRR_ETHSTPEN     0x00000800
  #define RCC_MC_AHB6LPENCLRR_FMCLPEN      0x00001000
  #define RCC_MC_AHB6LPENCLRR_QSPILPEN     0x00004000
  #define RCC_MC_AHB6LPENCLRR_SDMMC1LPEN   0x00010000
  #define RCC_MC_AHB6LPENCLRR_SDMMC2LPEN   0x00020000
  #define RCC_MC_AHB6LPENCLRR_CRC1LPEN     0x00100000
  #define RCC_MC_AHB6LPENCLRR_USBHLPEN     0x01000000
#define TOFF_RCC_BR_RSTSCLRR      0x0400	/* (RW) RCC BootRom Reset Status Clear Register   */
  #define RCC_BR_RSTSCLRR_PORRSTF     0x00000001	/* POR/PDR reset flag */
  #define RCC_BR_RSTSCLRR_BORRSTF     0x00000002	/* BOR reset flag */
  #define RCC_BR_RSTSCLRR_PADRSTF     0x00000004	/* NRST reset flag */
  #define RCC_BR_RSTSCLRR_HCSSRSTF    0x00000008	/* HSE CSS reset flag */
  #define RCC_BR_RSTSCLRR_VCORERSTF   0x00000010	/* VDDCORE reset flag */
  #define RCC_BR_RSTSCLRR_MPSYSRSTF   0x00000040	/* MPU System reset flag */
  #define RCC_BR_RSTSCLRR_MCSYSRSTF   0x00000080	/* MCU System reset flag */
  #define RCC_BR_RSTSCLRR_IWDG1RSTF   0x00000100	/* IWDG1 reset flag */
  #define RCC_BR_RSTSCLRR_IWDG2RSTF   0x00000200	/* IWDG2 reset flag */
  #define RCC_BR_RSTSCLRR_MPUP0RSTF   0x00002000	/* MPU processor 0 reset flag */
  #define RCC_BR_RSTSCLRR_MPUP1RSTF   0x00004000	/* MPU processor 1 reset flag */
#define TOFF_RCC_MP_GRSTCSETR     0x0404	/* (RW) RCC Global Reset Control Set Register */
  #define RCC_MP_GRSTCSETR_MPSYSRST   0x00000001	/* System reset */
  #define RCC_MP_GRSTCSETR_MCURST     0x00000002	/* MCU reset */
  #define RCC_MP_GRSTCSETR_MPUP0RST   0x00000010	/* MPU processor 0 reset */
  #define RCC_MP_GRSTCSETR_MPUP1RST   0x00000020	/* MPU processor 1 reset */
#define TOFF_RCC_MP_RSTSCLRR      0x0408	/* (RW) RCC MPU Reset Status Clear Register */
  #define RCC_MP_RSTSCLRR_PORRSTF     0x00000001	/* POR/PDR reset flag */
  #define RCC_MP_RSTSCLRR_BORRSTF     0x00000002	/* BOR reset flag */
  #define RCC_MP_RSTSCLRR_PADRSTF     0x00000004	/* NRST reset flag */
  #define RCC_MP_RSTSCLRR_HCSSRSTF    0x00000008	/* HSE CSS reset flag */
  #define RCC_MP_RSTSCLRR_VCORERSTF   0x00000010	/* VDDCORE reset flag */
  #define RCC_MP_RSTSCLRR_MPSYSRSTF   0x00000040	/* MPU System reset flag */
  #define RCC_MP_RSTSCLRR_MCSYSRSTF   0x00000080	/* MCU System reset flag */
  #define RCC_MP_RSTSCLRR_IWDG1RSTF   0x00000100	/* IWDG1 reset flag */
  #define RCC_MP_RSTSCLRR_IWDG2RSTF   0x00000200	/* IWDG2 reset flag */
  #define RCC_MP_RSTSCLRR_STDBYRSTF   0x00000800	/* System Standby reset flag */
  #define RCC_MP_RSTSCLRR_CSTDBYRSTF  0x00001000	/* MPU CStandby reset flag */
  #define RCC_MP_RSTSCLRR_MPUP0RSTF   0x00002000	/* MPU processor 0 reset flag */
  #define RCC_MP_RSTSCLRR_MPUP1RSTF   0x00004000	/* MPU processor 1 reset flag */
  #define RCC_MP_RSTSCLRR_SPARE       0x00008000	/* Spare bits */
#define TOFF_RCC_MP_IWDGFZSETR    0x040C	/* (RW) RCC IWDG Clock Freeze Set Register */
  #define RCC_MP_IWDGFZSETR_FZ_IWDG1  0x00000001
  #define RCC_MP_IWDGFZSETR_FZ_IWDG2  0x00000002
#define TOFF_RCC_MP_IWDGFZCLRR    0x0410	/* (RW) RCC IWDG Clock Freeze Clear Register */
  #define RCC_MP_IWDGFZCLRR_FZ_IWDG1  0x00000001
  #define RCC_MP_IWDGFZCLRR_FZ_IWDG2  0x00000002
#define TOFF_RCC_MP_CIER          0x0414	/* (RW) RCC Clock Source Interrupt Enable Register */
  #define RCC_MP_CIER_LSIRDYIE        0x00000001	/* LSI ready Interrupt Enable */
  #define RCC_MP_CIER_LSERDYIE        0x00000002	/* LSE ready Interrupt Enable */
  #define RCC_MP_CIER_HSIRDYIE        0x00000004	/* HSI ready Interrupt Enable */
  #define RCC_MP_CIER_HSERDYIE        0x00000008	/* HSE ready Interrupt Enable */
  #define RCC_MP_CIER_CSIRDYIE        0x00000010	/* CSI ready Interrupt Enable */
  #define RCC_MP_CIER_PLL1DYIE        0x00000100	/* PLL1DYIE ready Interrupt Enable */
  #define RCC_MP_CIER_PLL2DYIE        0x00000200	/* PLL2DYIE ready Interrupt Enable */
  #define RCC_MP_CIER_PLL3DYIE        0x00000400	/* PLL3DYIE ready Interrupt Enable */
  #define RCC_MP_CIER_PLL4DYIE        0x00000800	/* PLL4DYIE ready Interrupt Enable */
  #define RCC_MP_CIER_LSECSSIE        0x00010000	/* LSE clock security system Interrupt Enable */
  #define RCC_MP_CIER_WKUPIE          0x00100000	/* Wake-up from CSTOP Interrupt Enable */
#define TOFF_RCC_MP_CIFR          0x0418	/* (RW) RCC Clock Source Interrupt Flag Register */
  #define RCC_MP_CIFR_LSIRDYF         0x00000001	/* LSI ready Interrupt Flag */
  #define RCC_MP_CIFR_LSERDYF         0x00000002	/* LSE ready Interrupt Flag */
  #define RCC_MP_CIFR_HSIRDYF         0x00000004	/* HSI ready Interrupt Flag */
  #define RCC_MP_CIFR_HSERDYF         0x00000008	/* HSE ready Interrupt Flag */
  #define RCC_MP_CIFR_CSIRDYF         0x00000010	/* CSI ready Interrupt Flag */
  #define RCC_MP_CIFR_PLL1DYF         0x00000100	/* PLL1 ready Interrupt Flag */
  #define RCC_MP_CIFR_PLL2DYF         0x00000200	/* PLL2 ready Interrupt Flag */
  #define RCC_MP_CIFR_PLL3DYF         0x00000400	/* PLL3 ready Interrupt Flag */
  #define RCC_MP_CIFR_PLL4DYF         0x00000800	/* PLL4 ready Interrupt Flag */
  #define RCC_MP_CIFR_LSECSSF         0x00010000	/* LSE clock security system Interrupt Flag */
  #define RCC_MP_CIFR_WKUPF           0x00100000	/* Wake-up from CSTOP Interrupt Flag */
#define TOFF_RCC_PWRLPDLYCR       0x041C	/* (RW) RCC PWR_LP Delay Control Register */
  #define RCC_PWRLPDLYCR_PWRLP_DLY    0x003FFFFF	/* PWR_LP Delay value */
  #define RCC_PWRLPDLYCR_PWRLP_DLY_0  0x00000000
  #define RCC_PWRLPDLYCR_PWRLP_DLY_1  0x00000001
  #define RCC_PWRLPDLYCR_PWRLP_DLY_LAST 0x003FFFFF	/* A PWR_LP delay of about 65.5 milliseconds is observed */
  #define RCC_PWRLPDLYCR_MCTMPSKP     0x01000000	/* Skip the PWR_LP Delay for MCU */
#define TOFF_RCC_MP_RSTSSETR      0x0420	/* (RW) RCC MPU Reset Status Set Register */
  #define RCC_MP_RSTSSETR_PORRSTF     0x00000001	/* POR/PDR reset flag */
  #define RCC_MP_RSTSSETR_BORRSTF     0x00000002	/* BOR reset flag */
  #define RCC_MP_RSTSSETR_PADRSTF     0x00000004	/* NRST reset flag */
  #define RCC_MP_RSTSSETR_HCSSRSTF    0x00000008	/* HSE CSS reset flag */
  #define RCC_MP_RSTSSETR_VCORERSTF   0x00000010	/* VDDCORE reset flag */
  #define RCC_MP_RSTSSETR_MPSYSRSTF   0x00000040	/* MPU System reset flag */
  #define RCC_MP_RSTSSETR_MCSYSRSTF   0x00000080	/* MCU System reset flag */
  #define RCC_MP_RSTSSETR_IWDG1RSTF   0x00000100	/* IWDG1 reset flag */
  #define RCC_MP_RSTSSETR_IWDG2RSTF   0x00000200	/* IWDG2 reset flag */
  #define RCC_MP_RSTSSETR_STDBYRSTF   0x00000800	/* System Standby reset flag */
  #define RCC_MP_RSTSSETR_CSTDBYRSTF  0x00001000	/* MPU CStandby reset flag */
  #define RCC_MP_RSTSSETR_MPUP0RSTF   0x00002000	/* MPU processor 0 reset flag */
  #define RCC_MP_RSTSSETR_MPUP1RSTF   0x00004000	/* MPU processor 1 reset flag */
  #define RCC_MP_RSTSSETR_SPARE       0x00008000	/* Spare bits */
#define TOFF_RCC_MCO1CFGR         0x0800	/* (RW) RCC MCO1 Configuration Register */
  #define RCC_MCO1CFGR_MCO1SEL        0x00000007	/* MCO1 clock output selection */
  #define RCC_MCO1CFGR_MCO1SEL_0      0x00000000
  #define RCC_MCO1CFGR_MCO1SEL_1      0x00000001
  #define RCC_MCO1CFGR_MCO1SEL_2      0x00000002
  #define RCC_MCO1CFGR_MCO1SEL_3      0x00000003
  #define RCC_MCO1CFGR_MCO1SEL_4      0x00000004
  #define RCC_MCO1CFGR_MCO1DIV        0x000000F0	/* MCO1 prescaler */
  #define RCC_MCO1CFGR_MCO1DIV_0      0x00000000
  #define RCC_MCO1CFGR_MCO1DIV_1      0x00000010
  #define RCC_MCO1CFGR_MCO1DIV_2      0x00000020
  #define RCC_MCO1CFGR_MCO1DIV_3      0x00000030
  #define RCC_MCO1CFGR_MCO1DIV_4      0x00000040
  #define RCC_MCO1CFGR_MCO1DIV_5      0x00000050
  #define RCC_MCO1CFGR_MCO1DIV_6      0x00000060
  #define RCC_MCO1CFGR_MCO1DIV_7      0x00000070
  #define RCC_MCO1CFGR_MCO1DIV_8      0x00000080
  #define RCC_MCO1CFGR_MCO1DIV_9      0x00000090
  #define RCC_MCO1CFGR_MCO1DIV_10     0x000000A0
  #define RCC_MCO1CFGR_MCO1DIV_11     0x000000B0
  #define RCC_MCO1CFGR_MCO1DIV_12     0x000000C0
  #define RCC_MCO1CFGR_MCO1DIV_13     0x000000D0
  #define RCC_MCO1CFGR_MCO1DIV_14     0x000000E0
  #define RCC_MCO1CFGR_MCO1DIV_15     0x000000F0
  #define RCC_MCO1CFGR_MCO1ON         0x00001000	/* Control the MCO1 output */
#define TOFF_RCC_MCO2CFGR         0x0804	/* (RW) RCC MCO2 Configuration Register */
  #define RCC_MCO2CFGR_MCO2SEL        0x00000007	/* MCO2 clock output selection */
  #define RCC_MCO2CFGR_MCO2SEL_0      0x00000000
  #define RCC_MCO2CFGR_MCO2SEL_1      0x00000001
  #define RCC_MCO2CFGR_MCO2SEL_2      0x00000002
  #define RCC_MCO2CFGR_MCO2SEL_3      0x00000003
  #define RCC_MCO2CFGR_MCO2SEL_4      0x00000004
  #define RCC_MCO2CFGR_MCO2SEL_5      0x00000005
  #define RCC_MCO2CFGR_MCO2DIV        0x000000F0	/* MCO2 prescaler */
  #define RCC_MCO2CFGR_MCO2DIV_0      0x00000000
  #define RCC_MCO2CFGR_MCO2DIV_1      0x00000010
  #define RCC_MCO2CFGR_MCO2DIV_2      0x00000020
  #define RCC_MCO2CFGR_MCO2DIV_3      0x00000030
  #define RCC_MCO2CFGR_MCO2DIV_4      0x00000040
  #define RCC_MCO2CFGR_MCO2DIV_5      0x00000050
  #define RCC_MCO2CFGR_MCO2DIV_6      0x00000060
  #define RCC_MCO2CFGR_MCO2DIV_7      0x00000070
  #define RCC_MCO2CFGR_MCO2DIV_8      0x00000080
  #define RCC_MCO2CFGR_MCO2DIV_9      0x00000090
  #define RCC_MCO2CFGR_MCO2DIV_10     0x000000A0
  #define RCC_MCO2CFGR_MCO2DIV_11     0x000000B0
  #define RCC_MCO2CFGR_MCO2DIV_12     0x000000C0
  #define RCC_MCO2CFGR_MCO2DIV_13     0x000000D0
  #define RCC_MCO2CFGR_MCO2DIV_14     0x000000E0
  #define RCC_MCO2CFGR_MCO2DIV_15     0x000000F0
  #define RCC_MCO2CFGR_MCO2ON         0x00001000	/* contorl the MCO2 output */
#define TOFF_RCC_OCRDYR           0x0808	/* (RW) RCC Oscillator Clock Ready Register */
  #define RCC_OCRDYR_HSIRDY           0x00000001	/* HSI clock ready flag */
  #define RCC_OCRDYR_HSIDIVRDY        0x00000004	/* HSI divider ready flag */
  #define RCC_OCRDYR_CSIRDY           0x00000010	/* CSI clock ready flag */
  #define RCC_OCRDYR_HSERDY           0x00000100	/* HSE clock ready flag */
  #define RCC_OCRDYR_AXICKRDY         0x01000000	/* AXI sub-system clock ready flag */
  #define RCC_OCRDYR_CKREST           0x02000000	/* Clock Restore State Machine Status */
#define TOFF_RCC_DBGCFGR          0x080C	/* (RW) Debug Configuration Register */
  #define RCC_DBGCFGR_TRACEDIV        0x00000007	/* clock divider for the trace clock */
  #define RCC_DBGCFGR_DBGCKEN         0x00000100	/* clock enable for debug function */
  #define RCC_DBGCFGR_TRACECKEN       0x00000200	/* clock enable for trace function */
  #define RCC_DBGCFGR_DBGRST          0x00001000	/* Reset of the debug function */
#define TOFF_RCC_RCK3SELR         0x0820	/* (RW) RCC PLL 3 Ref. Clock Selection Register */
  #define RCC_RCK3SELR_PLL3SRC        0x00000003	/* Reference clock selection for PLL3 */
  #define RCC_RCK3SELR_PLL3SRC_0      0x00000000
  #define RCC_RCK3SELR_PLL3SRC_1      0x00000001
  #define RCC_RCK3SELR_PLL3SRC_2      0x00000002
  #define RCC_RCK3SELR_PLL3SRC_3      0x00000003
  #define RCC_RCK3SELR_PLL3SRCRDY     0x80000000	/* PLL3 reference clock switch status */
#define TOFF_RCC_RCK4SELR         0x0824	/* (RW) RCC PLL4 Ref. Clock Selection Register */
  #define RCC_RCK4SELR_PLL4SRC        0x00000003	/* Reference clock selection for PLL4 */
  #define RCC_RCK4SELR_PLL4SRC_0      0x00000000
  #define RCC_RCK4SELR_PLL4SRC_1      0x00000001
  #define RCC_RCK4SELR_PLL4SRC_2      0x00000002
  #define RCC_RCK4SELR_PLL4SRC_3      0x00000003
  #define RCC_RCK4SELR_PLL4SRCRDY     0x80000000	/* PLL4 reference clock switch status */
#define TOFF_RCC_TIMG1PRER        0x0828	/* (RW) RCC TIM Group 1 Prescaler Register */
  #define RCC_TIMG1PRER_TIMG1PRE      0x00000001	/* Timers clocks prescaler selection */
  #define RCC_TIMG1PRER_TIMG1PRE_0    0x00000000	/* corresponding to a division by 1 or 2, else it is equal to
													   2 x Fck_pclk1 (default after reset)*/
  #define RCC_TIMG1PRER_TIMG1PRE_1    0x00000001	/* The Timers kernel clock is equal to ck_hclk if APB1DIV is
													   corresponding to division by 1, 2 or 4, else it is equal to 4 x Fck_pclk1 */
  #define RCC_TIMG1PRER_TIMG1PRERDY   0x80000000	/* Timers clocks prescaler status */
#define TOFF_RCC_TIMG2PRER        0x082C	/* (RW) RCC TIM Group 2 Prescaler Register */
  #define RCC_TIMG2PRER_TIMG2PRE      0x00000001	/* Timers clocks prescaler selection */
  #define RCC_TIMG2PRER_TIMG2PRE_0    0x00000000	/* corresponding to a division by 1 or 2, else it is equal
													   to 2 x Fck_pclk2 (default after reset)*/
  #define RCC_TIMG2PRER_TIMG2PRE_1    0x00000001	/* The Timers kernel clock is equal to ck_hclk if APB2DIV is
													   corresponding to division by 1, 2 or 4, else it is equal to 4 x Fck_pclk2 */
  #define RCC_TIMG2PRER_TIMG2PRERDY   0x80000000	/* Timers clocks prescaler status */
#define TOFF_RCC_MCUDIVR          0x0830	/* (RW) RCC MCU Clock Prescaler Register */
  #define RCC_MCUDIVR_MCUDIV          0x0000000F	/* MCU clock divider */
  #define RCC_MCUDIVR_MCUDIV_0        0x00000000
  #define RCC_MCUDIVR_MCUDIV_1        0x00000001
  #define RCC_MCUDIVR_MCUDIV_2        0x00000002
  #define RCC_MCUDIVR_MCUDIV_3        0x00000003
  #define RCC_MCUDIVR_MCUDIV_4        0x00000004
  #define RCC_MCUDIVR_MCUDIV_5        0x00000005
  #define RCC_MCUDIVR_MCUDIV_6        0x00000006
  #define RCC_MCUDIVR_MCUDIV_7        0x00000007
  #define RCC_MCUDIVR_MCUDIV_8        0x00000008
  #define RCC_MCUDIVR_MCUDIV_9        0x00000009
  #define RCC_MCUDIVR_MCUDIVRDY       0x80000000	/* MCU clock prescaler status */
#define TOFF_RCC_APB1DIVR         0x0834	/* (RW) RCC APB1 Clock Prescaler Register */
  #define RCC_APB1DIVR_APB1DIV        0x00000007	/* APB1 clock prescaler */
  #define RCC_APB1DIVR_APB1DIV_0      0x00000000
  #define RCC_APB1DIVR_APB1DIV_1      0x00000001
  #define RCC_APB1DIVR_APB1DIV_2      0x00000002
  #define RCC_APB1DIVR_APB1DIV_3      0x00000003
  #define RCC_APB1DIVR_APB1DIV_4      0x00000004
  #define RCC_APB1DIVR_APB1DIVRDY     0x80000000	/* APB1 clock prescaler status */
#define TOFF_RCC_APB2DIVR         0x0838	/* (RW) RCC APB2 Clock Prescaler Register */
  #define RCC_APB2DIVR_APB2DIV        0x00000007	/* APB2 clock prescaler */
  #define RCC_APB2DIVR_APB2DIV_0      0x00000000
  #define RCC_APB2DIVR_APB2DIV_1      0x00000001
  #define RCC_APB2DIVR_APB2DIV_2      0x00000002
  #define RCC_APB2DIVR_APB2DIV_3      0x00000003
  #define RCC_APB2DIVR_APB2DIV_4      0x00000004
  #define RCC_APB2DIVR_APB2DIVRDY     0x80000000	/* APB2 clock prescaler status */
#define TOFF_RCC_APB3DIVR         0x083C	/* (RW) RCC APB3 Clock Prescaler Register */
  #define RCC_APB3DIVR_APB3DIV        0x00000007	/* APB3 clock prescaler */
  #define RCC_APB3DIVR_APB3DIV_0      0x00000000
  #define RCC_APB3DIVR_APB3DIV_1      0x00000001
  #define RCC_APB3DIVR_APB3DIV_2      0x00000002
  #define RCC_APB3DIVR_APB3DIV_3      0x00000003
  #define RCC_APB3DIVR_APB3DIV_4      0x00000004
  #define RCC_APB3DIVR_APB3DIVRDY     0x80000000	/* APB3 clock prescaler status */
#define TOFF_RCC_PLL3CR           0x0880	/* (RW) RCC PLL3 Control Register */
  #define RCC_PLL3CR_PLLON            0x00000001	/* PLL3 enable */
  #define RCC_PLL3CR_PLL3RDY          0x00000002	/* PLL3 clock ready flag */
  #define RCC_PLL3CR_SSCG_CTRL        0x00000004	/* Spread Spectrum Clock Generator of PLL3 enable */
  #define RCC_PLL3CR_DIVPEN           0x00000010	/* PLL3 DIVP divider output enable */
  #define RCC_PLL3CR_DIVQEN           0x00000020	/* PLL3 DIVQ divider output enable */
  #define RCC_PLL3CR_DIVREN           0x00000040	/* PLL3 DIVR divider output enable */
#define TOFF_RCC_PLL3CFGR1        0x0884	/* (RW) RCC PLL3 Configuration Register 1 */
  #define RCC_PLL3CFGR1_DIVN          0x000001FF	/* Multiplication factor for PLL3 */
  #define RCC_PLL3CFGR1_DIVN_25       0x00000018	/* Division ratio is 25 */
  #define RCC_PLL3CFGR1_DIVN_26       0x00000019	/* Division ratio is 26 */
  #define RCC_PLL3CFGR1_DIVN_200      0x000000C7	/* Division ratio is 200 */
  #define  RCC_PLL3CFGR1_DIVM3        0x003F0000	/* Prescaler for PLL3 */
  #define RCC_PLL3CFGR1_IFRGE         0x03000000	/* PLL3 input frequency range */
  #define RCC_PLL3CFGR1_IFRGE_0       0x00000000	/* between 4 and 8 MHz (default after reset) */
  #define RCC_PLL3CFGR1_IFRGE_1       0x01000000	/* The PLL3 input (ck_ref3) clock range frequency is between 8 and 16 MHz */
#define TOFF_RCC_PLL3CFGR2        0x0888	/* (RW) RCC PLL3 Configuration Register 2 */
  #define RCC_PLL3CFGR2_DIVP          0x0000007F	/* PLL3 DIVP division factor */
  #define RCC_PLL3CFGR2_DIVP_0        0x00000000
  #define RCC_PLL3CFGR2_DIVP_1        0x00000001
  #define RCC_PLL3CFGR2_DIVP_128      0x0000007F
  #define RCC_PLL3CFGR2_DIVQ          0x00007F00	/* PLL3 DIVQ division factor */
  #define RCC_PLL3CFGR2_DIVQ_0        0x00000000
  #define RCC_PLL3CFGR2_DIVQ_1        0x00000100
  #define RCC_PLL3CFGR2_DIVQ_128      0x00007F00
  #define RCC_PLL3CFGR2_DIVR          0x007F0000	/* PLL3 DIVR division factor */
  #define RCC_PLL3CFGR2_DIVR_0        0x00000000
  #define RCC_PLL3CFGR2_DIVR_1        0x00010000
  #define RCC_PLL3CFGR2_DIVR_128      0x007F0000
#define TOFF_RCC_PLL3FRACR        0x088C	/* (RW) RCC PLL3 Fractional Register */
  #define RCC_PLL3FRACR_FRACV         0x0000FFF8	/* Fractional part of the multiplication factor for PLL3 VCO */
  #define RCC_PLL3FRACR_FRACLE        0x00010000	/* PLL3 fractional latch enable */
#define TOFF_RCC_PLL3CSGR         0x0890	/* (RW) RCC PLL3 Clock Spreading Generator Register */
  #define RCC_PLL3CSGR_MOD_PER        0x00001FFF	/* Modulation Period Adjustment for PLL3 */
  #define RCC_PLL3CSGR_TPDFN_DIS      0x00002000	/* Dithering TPDF noise control */
  #define RCC_PLL3CSGR_RPDFN_DIS      0x00004000	/* Dithering RPDF noise control */
  #define RCC_PLL3CSGR_SSCG_MODE      0x00008000	/* Spread spectrum clock generator mode */
  #define RCC_PLL3CSGR_INC_STEP       0x7FFF0000	/* Modulation Depth Adjustment for PLL3 */
#define TOFF_RCC_PLL4CR           0x0894	/* (RW) RCC PLL4 Control Register */
  #define RCC_PLL4CR_PLLON            0x00000001	/* PLL4 enable */
  #define RCC_PLL4CR_PLL4RDY          0x00000002	/* PLL4 clock ready flag */
  #define RCC_PLL4CR_SSCG_CTRL        0x00000004	/* Spread Spectrum Clock Generator of PLL4 enable */
  #define RCC_PLL4CR_DIVPEN           0x00000010	/* PLL4 DIVP divider output enable */
  #define RCC_PLL4CR_DIVQEN           0x00000020	/* PLL4 DIVQ divider output enable */
  #define RCC_PLL4CR_DIVREN           0x00000040	/* PLL4 DIVR divider output enable */
#define TOFF_RCC_PLL4CFGR1        0x0898	/* (RW) RCC PLL4 Configuration Register 1 */
  #define RCC_PLL4CFGR1_DIVN          0x000001FF	/* Multiplication factor for PLL4 */
  #define RCC_PLL4CFGR1_DIVN_25       0x00000018	/* Division ratio is 25 */
  #define RCC_PLL4CFGR1_DIVN_26       0x00000019	/* Division ratio is 26 */
  #define RCC_PLL4CFGR1_DIVN_200      0x000000C7	/* Division ratio is 200 */
  #define RCC_PLL4CFGR1_DIVM4         0x003F0000	/* Prescaler for PLL4 */
  #define RCC_PLL4CFGR1_IFRGE         0x03000000	/* PLL4 input frequency range*/
  #define RCC_PLL4CFGR1_IFRGE_0       0x00000000	/* between 4 and 8 MHz (default after reset) */
  #define RCC_PLL4CFGR1_IFRGE_1       0x01000000	/* The PLL4 input (ck_ref4) clock range frequency is between 8 and 16 MHz */
#define TOFF_RCC_PLL4CFGR2        0x089C	/* (RW) RCC PLL4 Configuration Register 2 */
  #define RCC_PLL4CFGR2_DIVP          0x0000007F	/* PLL4 DIVP division factor */
  #define RCC_PLL4CFGR2_DIVP_0        0x00000000
  #define RCC_PLL4CFGR2_DIVP_1        0x00000001
  #define RCC_PLL4CFGR2_DIVP_128      0x0000007F
  #define RCC_PLL4CFGR2_DIVQ          0x00007F00	/* PLL4 DIVQ division factor */
  #define RCC_PLL4CFGR2_DIVQ_0        0x00000000
  #define RCC_PLL4CFGR2_DIVQ_1        0x00000100
  #define RCC_PLL4CFGR2_DIVQ_128      0x00007F00
  #define RCC_PLL4CFGR2_DIVR          0x007F0000	/* PLL4 DIVR division factor */
  #define RCC_PLL4CFGR2_DIVR_0        0x00000000
  #define RCC_PLL4CFGR2_DIVR_1        0x00010000
  #define RCC_PLL4CFGR2_DIVR_128      0x007F0000
#define TOFF_RCC_PLL4FRACR        0x08A0	/* (RW) RCC PLL4 Fractional Register */
  #define RCC_PLL4FRACR_FRACV         0x0000FFF8	/* Fractional part of the multiplication factor for PLL4 VCO */
  #define RCC_PLL4FRACR_FRACLE        0x00010000	/* PLL4 fractional latch enable */
#define TOFF_RCC_PLL4CSGR         0x08A4	/* (RW) RCC PLL4 Clock Spreading Generator Register */
  #define RCC_PLL4CSGR_MOD_PER        0x00001FFF	/* Modulation Period Adjustment for PLL4 */
  #define RCC_PLL4CSGR_TPDFN_DIS      0x00002000	/* Dithering TPDF noise control */
  #define RCC_PLL4CSGR_RPDFN_DIS      0x00004000	/* Dithering RPDF noise control */
  #define RCC_PLL4CSGR_SSCG_MODE      0x00008000	/* Spread spectrum clock generator mode */
  #define RCC_PLL4CSGR_INC_STEP       0x7FFF0000	/* Modulation Depth Adjustment for PLL4 */
#define TOFF_RCC_I2C12CKSELR      0x08C0	/* (RW) RCC I2C1,2 Kernel Clock Selection Register */
  #define RCC_I2C12CKSELR_I2C12SRC    0x00000007	/* I2C1 and I2C2 kernel clock source selection */
  #define RCC_I2C12CKSELR_I2C12SRC_0  0x00000000
  #define RCC_I2C12CKSELR_I2C12SRC_1  0x00000001
  #define RCC_I2C12CKSELR_I2C12SRC_2  0x00000002
  #define RCC_I2C12CKSELR_I2C12SRC_3  0x00000003
#define TOFF_RCC_I2C35CKSELR      0x08C4	/* (RW) RCC I2C3,5 Kernel Clock Selection Register */
  #define RCC_I2C35CKSELR_I2C35SRC    0x00000007	/* I2C3 and I2C5 kernel clock source selection */
  #define RCC_I2C35CKSELR_I2C35SRC_0  0x00000000
  #define RCC_I2C35CKSELR_I2C35SRC_1  0x00000001
  #define RCC_I2C35CKSELR_I2C35SRC_2  0x00000002
  #define RCC_I2C35CKSELR_I2C35SRC_3  0x00000003
#define TOFF_RCC_SAI1CKSELR       0x08C8	/* (RW) RCC SAI1 Kernel Clock Selection Register */
  #define RCC_SAI1CKSELR_SAI1SRC      0x00000007	/* SAI1 kernel clock source selection */
  #define RCC_SAI1CKSELR_SAI1SRC_0    0x00000000
  #define RCC_SAI1CKSELR_SAI1SRC_1    0x00000001
  #define RCC_SAI1CKSELR_SAI1SRC_2    0x00000002
  #define RCC_SAI1CKSELR_SAI1SRC_3    0x00000003
  #define RCC_SAI1CKSELR_SAI1SRC_4    0x00000004
#define TOFF_RCC_SAI2CKSELR       0x08CC	/* (RW) RCC SAI2 Kernel Clock Selection Register */
  #define RCC_SAI2CKSELR_SAI2SRC      0x00000007	/* SAI2 kernel clock source selection */
  #define RCC_SAI2CKSELR_SAI2SRC_0    0x00000000
  #define RCC_SAI2CKSELR_SAI2SRC_1    0x00000001
  #define RCC_SAI2CKSELR_SAI2SRC_2    0x00000002
  #define RCC_SAI2CKSELR_SAI2SRC_3    0x00000003
  #define RCC_SAI2CKSELR_SAI2SRC_4    0x00000004
  #define RCC_SAI2CKSELR_SAI2SRC_5    0x00000005
#define TOFF_RCC_SAI3CKSELR       0x08D0	/* (RW) RCC SAI3 Kernel Clock Selection Register */
  #define RCC_SAI3CKSELR_SAI3SRC      0x00000007	/* SAI3 kernel clock source selection */
  #define RCC_SAI3CKSELR_SAI3SRC_0    0x00000000
  #define RCC_SAI3CKSELR_SAI3SRC_1    0x00000001
  #define RCC_SAI3CKSELR_SAI3SRC_2    0x00000002
  #define RCC_SAI3CKSELR_SAI3SRC_3    0x00000003
  #define RCC_SAI3CKSELR_SAI3SRC_4    0x00000004
#define TOFF_RCC_SAI4CKSELR       0x08D4	/* (RW) RCC SAI4 Kernel Clock Selection Register */
  #define RCC_SAI4CKSELR_SAI4SRC      0x00000007	/* SAI4 kernel clock source selection */
  #define RCC_SAI4CKSELR_SAI4SRC_0    0x00000000
  #define RCC_SAI4CKSELR_SAI4SRC_1    0x00000001
  #define RCC_SAI4CKSELR_SAI4SRC_2    0x00000002
  #define RCC_SAI4CKSELR_SAI4SRC_3    0x00000003
  #define RCC_SAI4CKSELR_SAI4SRC_4    0x00000004
#define TOFF_RCC_SPI2S1CKSELR     0x08D8	/* (RW) RCC SPI/I2S1 Kernel Clock Selection Register */
  #define RCC_SPI2S1CKSELR_SPI1SRC    0x00000007	/* SPI/I2S1 kernel clock source selection */
  #define RCC_SPI2S1CKSELR_SPI1SRC_0  0x00000000
  #define RCC_SPI2S1CKSELR_SPI1SRC_1  0x00000001
  #define RCC_SPI2S1CKSELR_SPI1SRC_2  0x00000002
  #define RCC_SPI2S1CKSELR_SPI1SRC_3  0x00000003
  #define RCC_SPI2S1CKSELR_SPI1SRC_4  0x00000004
#define TOFF_RCC_SPI2S23CKSELR    0x08DC	/* (RW) RCC SPI/I2S2,3 Kernel Clock Selection Register */
  #define RCC_SPI2S23CKSELR_SPI23SRC  0x00000007	/* SPI/I2S2,3 kernel clock source selection */
  #define RCC_SPI2S23CKSELR_SPI23SRC_0 0x00000000
  #define RCC_SPI2S23CKSELR_SPI23SRC_1 0x00000001
  #define RCC_SPI2S23CKSELR_SPI23SRC_2 0x00000002
  #define RCC_SPI2S23CKSELR_SPI23SRC_3 0x00000003
  #define RCC_SPI2S23CKSELR_SPI23SRC_4 0x00000004
#define TOFF_RCC_SPI45CKSELR      0x08E0	/* (RW) RCC SPI4,5 Kernel Clock Selection Register */
  #define RCC_SPI45CKSELR_SPI45SRC    0x00000007	/* SPI4,5 kernel clock source selection */
  #define RCC_SPI45CKSELR_SPI45SRC_0  0x00000000
  #define RCC_SPI45CKSELR_SPI45SRC_1  0x00000001
  #define RCC_SPI45CKSELR_SPI45SRC_2  0x00000002
  #define RCC_SPI45CKSELR_SPI45SRC_3  0x00000003
  #define RCC_SPI45CKSELR_SPI45SRC_4  0x00000004
#define TOFF_RCC_UART6CKSELR      0x08E4	/* (RW) RCC USART6 Kernel Clock Selection Register */
  #define RCC_UART6CKSELR_UART6SRC    0x00000007	/* UART6 kernel clock source selection */
  #define RCC_UART6CKSELR_UART6SRC_0  0x00000000
  #define RCC_UART6CKSELR_UART6SRC_1  0x00000001
  #define RCC_UART6CKSELR_UART6SRC_2  0x00000002
  #define RCC_UART6CKSELR_UART6SRC_3  0x00000003
  #define RCC_UART6CKSELR_UART6SRC_4  0x00000004
#define TOFF_RCC_UART24CKSELR     0x08E8	/* (RW) RCC UART2,4 Kernel Clock Selection Register */
  #define RCC_UART24CKSELR_UART24SRC   0x00000007	/* UART2,4 kernel clock source selection */
  #define RCC_UART24CKSELR_UART24SRC_0 0x00000000
  #define RCC_UART24CKSELR_UART24SRC_1 0x00000001
  #define RCC_UART24CKSELR_UART24SRC_2 0x00000002
  #define RCC_UART24CKSELR_UART24SRC_3 0x00000003
  #define RCC_UART24CKSELR_UART24SRC_4 0x00000004
#define TOFF_RCC_UART35CKSELR     0x08EC	/* (RW) RCC UART3,5 Kernel Clock Selection Register */
  #define RCC_UART35CKSELR_UART35SRC   0x00000007	/* UART3,5 kernel clock source selection */
  #define RCC_UART35CKSELR_UART35SRC_0 0x00000000
  #define RCC_UART35CKSELR_UART35SRC_1 0x00000001
  #define RCC_UART35CKSELR_UART35SRC_2 0x00000002
  #define RCC_UART35CKSELR_UART35SRC_3 0x00000003
  #define RCC_UART35CKSELR_UART35SRC_4 0x00000004
#define TOFF_RCC_UART78CKSELR     0x08F0	/* (RW) RCC UART7,8 Kernel Clock Selection Register */
  #define RCC_UART78CKSELR_UART78SRC   0x00000007	/* UART7,8 kernel clock source selection */
  #define RCC_UART78CKSELR_UART78SRC_0 0x00000000
  #define RCC_UART78CKSELR_UART78SRC_1 0x00000001
  #define RCC_UART78CKSELR_UART78SRC_2 0x00000002
  #define RCC_UART78CKSELR_UART78SRC_3 0x00000003
  #define RCC_UART78CKSELR_UART78SRC_4 0x00000004
#define TOFF_RCC_SDMMC12CKSELR    0x08F4	/* (RW) RCC SDMMC1&2 Kernel Clock Selection Register */
  #define RCC_SDMMC12CKSELR_SDMMC12SRC   0x00000003	/* SDMMC1 and SDMMC2 kernel clock source selection */
  #define RCC_SDMMC12CKSELR_SDMMC12SRC_0 0x00000000
  #define RCC_SDMMC12CKSELR_SDMMC12SRC_1 0x00000001
  #define RCC_SDMMC12CKSELR_SDMMC12SRC_2 0x00000002
  #define RCC_SDMMC12CKSELR_SDMMC12SRC_3 0x00000003
#define TOFF_RCC_SDMMC3CKSELR     0x08F8	/* (RW) RCC SDMMC3 Kernel Clock Selection Register */
  #define RCC_SDMMC3CKSELR_SDMMC3SRC   0x00000003	/* SDMMC3 kernel clock source selection */
  #define RCC_SDMMC3CKSELR_SDMMC3SRC_0 0x00000000
  #define RCC_SDMMC3CKSELR_SDMMC3SRC_1 0x00000001
  #define RCC_SDMMC3CKSELR_SDMMC3SRC_2 0x00000002
  #define RCC_SDMMC3CKSELR_SDMMC3SRC_3 0x00000003
#define TOFF_RCC_ETHCKSELR        0x08FC	/* (RW) RCC Ethernet Kernel Clock Selection Register */
  #define RCC_ETHCKSELR_ETHSRC        0x00000003	/* ETH kernel clock source selection */
  #define RCC_ETHCKSELR_ETHSRC_0      0x00000000
  #define RCC_ETHCKSELR_ETHSRC_1      0x00000001
  #define RCC_ETHCKSELR_ETHSRC_2      0x00000002
  #define RCC_ETHCKSELR_ETHPTPDIV     0x000000F0	/* Clock divider for Ethernet Precision Time Protocol (PTP) */
  #define RCC_ETHCKSELR_ETHPTPDIV_0   0x00000000
  #define RCC_ETHCKSELR_ETHPTPDIV_1   0x00000010
  #define RCC_ETHCKSELR_ETHPTPDIV_2   0x00000020
  #define RCC_ETHCKSELR_ETHPTPDIV_3   0x00000030
  #define RCC_ETHCKSELR_ETHPTPDIV_4   0x00000040
  #define RCC_ETHCKSELR_ETHPTPDIV_5   0x00000050
  #define RCC_ETHCKSELR_ETHPTPDIV_6   0x00000060
  #define RCC_ETHCKSELR_ETHPTPDIV_7   0x00000070
  #define RCC_ETHCKSELR_ETHPTPDIV_8   0x00000080
  #define RCC_ETHCKSELR_ETHPTPDIV_9   0x00000090
  #define RCC_ETHCKSELR_ETHPTPDIV_10  0x000000A0
  #define RCC_ETHCKSELR_ETHPTPDIV_11  0x000000B0
  #define RCC_ETHCKSELR_ETHPTPDIV_12  0x000000C0
  #define RCC_ETHCKSELR_ETHPTPDIV_13  0x000000D0
  #define RCC_ETHCKSELR_ETHPTPDIV_14  0x000000E0
  #define RCC_ETHCKSELR_ETHPTPDIV_15  0x000000F0
#define TOFF_RCC_QSPICKSELR       0x0900	/* (RW) RCC QUADSPI Kernel Clock Selection Register */
  #define RCC_QSPICKSELR_QSPISRC      0x00000003	/* QUADSPI kernel clock source selection */
  #define RCC_QSPICKSELR_QSPISRC_0    0x00000000
  #define RCC_QSPICKSELR_QSPISRC_1    0x00000001
  #define RCC_QSPICKSELR_QSPISRC_2    0x00000002
  #define RCC_QSPICKSELR_QSPISRC_3    0x00000003
#define TOFF_RCC_FMCCKSELR        0x0904	/* (RW) RCC FMC Kernel Clock Selection Register */
  #define RCC_FMCCKSELR_FMCSRC        0x00000003	/* FMC kernel clock source selection */
  #define RCC_FMCCKSELR_FMCSRC_0      0x00000000
  #define RCC_FMCCKSELR_FMCSRC_1      0x00000001
  #define RCC_FMCCKSELR_FMCSRC_2      0x00000002
  #define RCC_FMCCKSELR_FMCSRC_3      0x00000003
#define TOFF_RCC_FDCANCKSELR      0x090C	/* (RW) RCC FDCAN Kernel Clock Selection Register */
  #define RCC_FDCANCKSELR_FDCANSRC    0x00000003	/* FDCAN kernel clock source selection */
  #define RCC_FDCANCKSELR_FDCANSRC_0  0x00000000
  #define RCC_FDCANCKSELR_FDCANSRC_1  0x00000001
  #define RCC_FDCANCKSELR_FDCANSRC_2  0x00000002
  #define RCC_FDCANCKSELR_FDCANSRC_3  0x00000003
#define TOFF_RCC_SPDIFCKSELR      0x0914	/* (RW) RCC SPDIF Kernel Clock Selection Register */
  #define RCC_SPDIFCKSELR_SPDIFSRC    0x00000003	/* SPDIF-RX kernel clock source selection */
  #define RCC_SPDIFCKSELR_SPDIFSRC_0  0x00000000
  #define RCC_SPDIFCKSELR_SPDIFSRC_1  0x00000001
  #define RCC_SPDIFCKSELR_SPDIFSRC_2  0x00000002
#define TOFF_RCC_CECCKSELR        0x0918	/* (RW) RCC CEC Kernel Clock Selection Register */
  #define RCC_CECCKSELR_CECSRC        0x00000003	/* CEC-HDMI kernel clock source selection */
  #define RCC_CECCKSELR_CECSRC_0      0x00000000
  #define RCC_CECCKSELR_CECSRC_1      0x00000001
  #define RCC_CECCKSELR_CECSRC_2      0x00000002
#define TOFF_RCC_USBCKSELR        0x091C	/* (RW) RCC USB Kernel Clock Selection Register */
  #define RCC_USBCKSELR_USBPHYSRC     0x00000003	/* USB PHY kernel clock source selection */
  #define RCC_USBCKSELR_USBPHYSRC_0   0x00000000
  #define RCC_USBCKSELR_USBPHYSRC_1   0x00000001
  #define RCC_USBCKSELR_USBPHYSRC_2   0x00000002
  #define RCC_USBCKSELR_USBOSRC       0x00000010	/* USB OTG kernel clock source selection */
  #define RCC_USBCKSELR_USBOSRC_0     0x00000000
  #define RCC_USBCKSELR_USBOSRC_1     0x00000010
#define TOFF_RCC_RNG2CKSELR       0x0920	/* (RW) RCC RNG2 Kernel Clock Selection Register */
  #define RCC_RNG2CKSELR_RNG2SRC      0x00000003	/* RNG2 kernel clock source selection */
  #define RCC_RNG2CKSELR_RNG2SRC_0    0x00000000
  #define RCC_RNG2CKSELR_RNG2SRC_1    0x00000001
  #define RCC_RNG2CKSELR_RNG2SRC_2    0x00000002
  #define RCC_RNG2CKSELR_RNG2SRC_3    0x00000003
#define TOFF_RCC_DSICKSELR        0x0924	/* (RW) RCC DSI Kernel Clock Selection Register */
  #define RCC_DSICKSELR_DSISRC        0x00000001	/* DSIHOST kernel clock source selection */
  #define RCC_DSICKSELR_DSISRC_0      0x00000000
  #define RCC_DSICKSELR_DSISRC_1      0x00000001
#define TOFF_RCC_ADCCKSELR        0x0928	/* (RW) RCC ADC Kernel Clock Selection Register */
  #define RCC_ADCCKSELR_ADCSRC        0x00000003	/* ADC1&2 kernel clock source selection */
  #define RCC_ADCCKSELR_ADCSRC_0      0x00000000
  #define RCC_ADCCKSELR_ADCSRC_1      0x00000001
  #define RCC_ADCCKSELR_ADCSRC_2      0x00000002
#define TOFF_RCC_LPTIM45CKSELR    0x092C	/* (RW) RCC LPTIM4&5 Kernel Clock Selection Register */
  #define RCC_LPTIM45CKSELR_LPTIM45SRC   0x00000007	/* LPTIM4 and LPTIM5 kernel clock source selection */
  #define RCC_LPTIM45CKSELR_LPTIM45SRC_0 0x00000000
  #define RCC_LPTIM45CKSELR_LPTIM45SRC_1 0x00000001
  #define RCC_LPTIM45CKSELR_LPTIM45SRC_2 0x00000002
  #define RCC_LPTIM45CKSELR_LPTIM45SRC_3 0x00000003
  #define RCC_LPTIM45CKSELR_LPTIM45SRC_4 0x00000004
  #define RCC_LPTIM45CKSELR_LPTIM45SRC_5 0x00000005
  #define RCC_LPTIM45CKSELR_LPTIM45SRC_6 0x00000006
#define TOFF_RCC_LPTIM23CKSELR    0x0930	/* (RW) RCC LPTIM2&3 Kernel Clock Selection Register */
  #define RCC_LPTIM23CKSELR_LPTIM23SRC   0x00000007	/* LPTIM2 and LPTIM3 kernel clock source selection */
  #define RCC_LPTIM23CKSELR_LPTIM23SRC_0 0x00000000
  #define RCC_LPTIM23CKSELR_LPTIM23SRC_1 0x00000001
  #define RCC_LPTIM23CKSELR_LPTIM23SRC_2 0x00000002
  #define RCC_LPTIM23CKSELR_LPTIM23SRC_3 0x00000003
  #define RCC_LPTIM23CKSELR_LPTIM23SRC_4 0x00000004
  #define RCC_LPTIM23CKSELR_LPTIM23SRC_5 0x00000005
#define TOFF_RCC_LPTIM1CKSELR     0x0934	/* (RW) RCC LPTIM1 Kernel Clock Selection Register */
  #define RCC_LPTIM1CKSELR_LPTIM1SRC   0x00000007	/* LPTIM1 kernel clock source selection */
  #define RCC_LPTIM1CKSELR_LPTIM1SRC_0 0x00000000
  #define RCC_LPTIM1CKSELR_LPTIM1SRC_1 0x00000001
  #define RCC_LPTIM1CKSELR_LPTIM1SRC_2 0x00000002
  #define RCC_LPTIM1CKSELR_LPTIM1SRC_3 0x00000003
  #define RCC_LPTIM1CKSELR_LPTIM1SRC_4 0x00000004
  #define RCC_LPTIM1CKSELR_LPTIM1SRC_5 0x00000005
  #define RCC_LPTIM1CKSELR_LPTIM1SRC_6 0x00000006
#define TOFF_RCC_APB1RSTSETR      0x0980	/* (RW) RCC APB1 Peripheral Reset Set Register */
  #define RCC_APB1RSTSETR_TIM2RST     0x00000001
  #define RCC_APB1RSTSETR_TIM3RST     0x00000002
  #define RCC_APB1RSTSETR_TIM4RST     0x00000004
  #define RCC_APB1RSTSETR_TIM5RST     0x00000008
  #define RCC_APB1RSTSETR_TIM6RST     0x00000010
  #define RCC_APB1RSTSETR_TIM7RST     0x00000020
  #define RCC_APB1RSTSETR_TIM12RST    0x00000040
  #define RCC_APB1RSTSETR_TIM13RST    0x00000080
  #define RCC_APB1RSTSETR_TIM14RST    0x00000100
  #define RCC_APB1RSTSETR_LPTIM1RST   0x00000200
  #define RCC_APB1RSTSETR_SPI2RST     0x00000800
  #define RCC_APB1RSTSETR_SPI3RST     0x00001000
  #define RCC_APB1RSTSETR_USART2RST   0x00004000
  #define RCC_APB1RSTSETR_USART3RST   0x00008000
  #define RCC_APB1RSTSETR_UART4RST    0x00010000
  #define RCC_APB1RSTSETR_UART5RST    0x00020000
  #define RCC_APB1RSTSETR_UART7RST    0x00040000
  #define RCC_APB1RSTSETR_UART8RST    0x00080000
  #define RCC_APB1RSTSETR_I2C1RST     0x00200000
  #define RCC_APB1RSTSETR_I2C2RST     0x00400000
  #define RCC_APB1RSTSETR_I2C3RST     0x00800000
  #define RCC_APB1RSTSETR_I2C5RST     0x01000000
  #define RCC_APB1RSTSETR_SPDIFRST    0x04000000
  #define RCC_APB1RSTSETR_CECRST      0x08000000
  #define RCC_APB1RSTSETR_DAC12RST    0x20000000
  #define RCC_APB1RSTSETR_MDIOSRST    0x80000000
#define TOFF_RCC_APB1RSTCLRR      0x0984	/* (RW) RCC APB1 Peripheral Reset Clear Register */
  #define RCC_APB1RSTCLRR_TIM2RST     0x00000001
  #define RCC_APB1RSTCLRR_TIM3RST     0x00000002
  #define RCC_APB1RSTCLRR_TIM4RST     0x00000004
  #define RCC_APB1RSTCLRR_TIM5RST     0x00000008
  #define RCC_APB1RSTCLRR_TIM6RST     0x00000010
  #define RCC_APB1RSTCLRR_TIM7RST     0x00000020
  #define RCC_APB1RSTCLRR_TIM12RST    0x00000040
  #define RCC_APB1RSTCLRR_TIM13RST    0x00000080
  #define RCC_APB1RSTCLRR_TIM14RST    0x00000100
  #define RCC_APB1RSTCLRR_LPTIM1RST   0x00000200
  #define RCC_APB1RSTCLRR_SPI2RST     0x00000800
  #define RCC_APB1RSTCLRR_SPI3RST     0x00001000
  #define RCC_APB1RSTCLRR_USART2RST   0x00004000
  #define RCC_APB1RSTCLRR_USART3RST   0x00008000
  #define RCC_APB1RSTCLRR_UART4RST    0x00010000
  #define RCC_APB1RSTCLRR_UART5RST    0x00020000
  #define RCC_APB1RSTCLRR_UART7RST    0x00040000
  #define RCC_APB1RSTCLRR_UART8RST    0x00080000
  #define RCC_APB1RSTCLRR_I2C1RST     0x00200000
  #define RCC_APB1RSTCLRR_I2C2RST     0x00400000
  #define RCC_APB1RSTCLRR_I2C3RST     0x00800000
  #define RCC_APB1RSTCLRR_I2C5RST     0x01000000
  #define RCC_APB1RSTCLRR_SPDIFRST    0x04000000
  #define RCC_APB1RSTCLRR_CECRST      0x08000000
  #define RCC_APB1RSTCLRR_DAC12RST    0x20000000
  #define RCC_APB1RSTCLRR_MDIOSRST    0x80000000
#define TOFF_RCC_APB2RSTSETR      0x0988	/* (RW) RCC APB2 Peripheral Reset Set Register */
  #define RCC_APB2RSTSETR_TIM1RST     0x00000001
  #define RCC_APB2RSTSETR_TIM8RST     0x00000002
  #define RCC_APB2RSTSETR_TIM15RST    0x00000004
  #define RCC_APB2RSTSETR_TIM16RST    0x00000008
  #define RCC_APB2RSTSETR_TIM17RST    0x00000010
  #define RCC_APB2RSTSETR_SPI1RST     0x00000100
  #define RCC_APB2RSTSETR_SPI4RST     0x00000200
  #define RCC_APB2RSTSETR_SPI5RST     0x00000400
  #define RCC_APB2RSTSETR_USART6RST   0x00002000
  #define RCC_APB2RSTSETR_SAI1RST     0x00010000
  #define RCC_APB2RSTSETR_SAI2RST     0x00020000
  #define RCC_APB2RSTSETR_SAI3RST     0x00040000
  #define RCC_APB2RSTSETR_DFSDMRST    0x00100000
  #define RCC_APB2RSTSETR_FDCANRST    0x01000000
#define TOFF_RCC_APB2RSTCLRR      0x098C	/* (RW) RCC APB2 Peripheral Reset Clear Register */
  #define RCC_APB2RSTCLRR_TIM1RST     0x00000001
  #define RCC_APB2RSTCLRR_TIM8RST     0x00000002
  #define RCC_APB2RSTCLRR_TIM15RST    0x00000004
  #define RCC_APB2RSTCLRR_TIM16RST    0x00000008
  #define RCC_APB2RSTCLRR_TIM17RST    0x00000010
  #define RCC_APB2RSTCLRR_SPI1RST     0x00000100
  #define RCC_APB2RSTCLRR_SPI4RST     0x00000200
  #define RCC_APB2RSTCLRR_SPI5RST     0x00000400
  #define RCC_APB2RSTCLRR_USART6RST   0x00002000
  #define RCC_APB2RSTCLRR_SAI1RST     0x00010000
  #define RCC_APB2RSTCLRR_SAI2RST     0x00020000
  #define RCC_APB2RSTCLRR_SAI3RST     0x00040000
  #define RCC_APB2RSTCLRR_DFSDMRST    0x00100000
  #define RCC_APB2RSTCLRR_FDCANRST    0x01000000
#define TOFF_RCC_APB3RSTSETR      0x0990	/* (RW) RCC APB3 Peripheral Reset Set Register */
  #define RCC_APB3RSTSETR_LPTIM2RST   0x00000001
  #define RCC_APB3RSTSETR_LPTIM3RST   0x00000002
  #define RCC_APB3RSTSETR_LPTIM4RST   0x00000004
  #define RCC_APB3RSTSETR_LPTIM5RST   0x00000008
  #define RCC_APB3RSTSETR_SAI4RST     0x00000100
  #define RCC_APB3RSTSETR_SYSCFGRST   0x00000800
  #define RCC_APB3RSTSETR_VREFRST     0x00002000
  #define RCC_APB3RSTSETR_DTSRST      0x00010000
  #define RCC_APB3RSTSETR_PMBCTRLRST  0x00020000
#define TOFF_RCC_APB3RSTCLRR      0x0994	/* (RW) RCC APB3 Peripheral Reset Clear Register */
  #define RCC_APB3RSTCLRR_LPTIM2RST   0x00000001
  #define RCC_APB3RSTCLRR_LPTIM3RST   0x00000002
  #define RCC_APB3RSTCLRR_LPTIM4RST   0x00000004
  #define RCC_APB3RSTCLRR_LPTIM5RST   0x00000008
  #define RCC_APB3RSTCLRR_SAI4RST     0x00000100
  #define RCC_APB3RSTCLRR_SYSCFGRST   0x00000800
  #define RCC_APB3RSTCLRR_VREFRST     0x00002000
  #define RCC_APB3RSTCLRR_DTSRST      0x00010000
  #define RCC_APB3RSTCLRR_PMBCTRLRST  0x00020000
#define TOFF_RCC_AHB2RSTSETR      0x0998	/* (RW) RCC AHB2 Peripheral Reset Set Register */
  #define RCC_AHB2RSTSETR_DMA1RST     0x00000001
  #define RCC_AHB2RSTSETR_DMA2RST     0x00000002
  #define RCC_AHB2RSTSETR_DMAMUXRST   0x00000004
  #define RCC_AHB2RSTSETR_ADC12RST    0x00000020
  #define RCC_AHB2RSTSETR_USBORST     0x00000100
  #define RCC_AHB2RSTSETR_SDMMC3RST   0x00010000
#define TOFF_RCC_AHB2RSTCLRR      0x099C	/* (RW) RCC AHB2 Peripheral Reset Clear Register */
  #define RCC_AHB2RSTCLRR_DMA1RST     0x00000001
  #define RCC_AHB2RSTCLRR_DMA2RST     0x00000002
  #define RCC_AHB2RSTCLRR_DMAMUXRST   0x00000004
  #define RCC_AHB2RSTCLRR_ADC12RST    0x00000020
  #define RCC_AHB2RSTCLRR_USBORST     0x00000100
  #define RCC_AHB2RSTCLRR_SDMMC3RST   0x00010000
#define TOFF_RCC_AHB3RSTSETR      0x09A0	/* (RW) RCC AHB3 Peripheral Reset Set Register */
  #define RCC_AHB3RSTSETR_DCMIRST     0x00000001
  #define RCC_AHB3RSTSETR_CRYP2RST    0x00000010
  #define RCC_AHB3RSTSETR_HASH2RST    0x00000020
  #define RCC_AHB3RSTSETR_RNG2RST     0x00000040
  #define RCC_AHB3RSTSETR_CRC2RST     0x00000080
  #define RCC_AHB3RSTSETR_HSEMRST     0x00000800
  #define RCC_AHB3RSTSETR_IPCCRST     0x00001000
#define TOFF_RCC_AHB3RSTCLRR      0x09A4	/* (RW) RCC AHB3 Peripheral Reset Clear Register */
  #define RCC_AHB3RSTCLRR_DCMIRST     0x00000001
  #define RCC_AHB3RSTCLRR_CRYP2RST    0x00000010
  #define RCC_AHB3RSTCLRR_HASH2RST    0x00000020
  #define RCC_AHB3RSTCLRR_RNG2RST     0x00000040
  #define RCC_AHB3RSTCLRR_CRC2RST     0x00000080
  #define RCC_AHB3RSTCLRR_HSEMRST     0x00000800
  #define RCC_AHB3RSTCLRR_IPCCRST     0x00001000
#define TOFF_RCC_AHB4RSTSETR      0x09A8	/* (RW) RCC AHB4 Peripheral Reset Set Register */
  #define RCC_AHB4RSTSETR_GPIOARST    0x00000001
  #define RCC_AHB4RSTSETR_GPIOBRST    0x00000002
  #define RCC_AHB4RSTSETR_GPIOCRST    0x00000004
  #define RCC_AHB4RSTSETR_GPIODRST    0x00000008
  #define RCC_AHB4RSTSETR_GPIOERST    0x00000010
  #define RCC_AHB4RSTSETR_GPIOFRST    0x00000020
  #define RCC_AHB4RSTSETR_GPIOGRST    0x00000040
  #define RCC_AHB4RSTSETR_GPIOHRST    0x00000080
  #define RCC_AHB4RSTSETR_GPIOIRST    0x00000100
  #define RCC_AHB4RSTSETR_GPIOJRST    0x00000200
  #define RCC_AHB4RSTSETR_GPIOKRST    0x00000400
#define TOFF_RCC_AHB4RSTCLRR      0x09AC	/* (RW) RCC AHB4 Peripheral Reset Clear Register */
  #define RCC_AHB4RSTCLRR_GPIOARST    0x00000001
  #define RCC_AHB4RSTCLRR_GPIOBRST    0x00000002
  #define RCC_AHB4RSTCLRR_GPIOCRST    0x00000004
  #define RCC_AHB4RSTCLRR_GPIODRST    0x00000008
  #define RCC_AHB4RSTCLRR_GPIOERST    0x00000010
  #define RCC_AHB4RSTCLRR_GPIOFRST    0x00000020
  #define RCC_AHB4RSTCLRR_GPIOGRST    0x00000040
  #define RCC_AHB4RSTCLRR_GPIOHRST    0x00000080
  #define RCC_AHB4RSTCLRR_GPIOIRST    0x00000100
  #define RCC_AHB4RSTCLRR_GPIOJRST    0x00000200
  #define RCC_AHB4RSTCLRR_GPIOKRST    0x00000400
#define TOFF_RCC_MP_APB1ENSETR    0x0A00	/* (RW) RCC APB1 Peripheral Enable For MPU Set Register */
#define TOFF_RCC_MP_APB1ENCLRR    0x0A04	/* (RW) RCC APB1 Peripheral Enable For MPU Clear Register */
#define TOFF_RCC_MP_APB2ENSETR    0x0A08	/* (RW) RCC APB2 Peripheral Enable For MPU Set Register */
#define TOFF_RCC_MP_APB2ENCLRR    0x0A0C	/* (RW) RCC APB2 Peripheral Enable For MPU Clear Register */
#define TOFF_RCC_MP_APB3ENSETR    0x0A10	/* (RW) RCC APB3 Peripheral Enable For MPU Set Register */
#define TOFF_RCC_MP_APB3ENCLRR    0x0A14	/* (RW) RCC APB3 Peripheral Enable For MPU Clear Register */
#define TOFF_RCC_MP_AHB2ENSETR    0x0A18	/* (RW) RCC AHB2 Peripheral Enable For MPU Set Register */
#define TOFF_RCC_MP_AHB2ENCLRR    0x0A1C	/* (RW) RCC AHB2 Peripheral Enable For MPU Clear Register */
#define TOFF_RCC_MP_AHB3ENSETR    0x0A20	/* (RW) RCC AHB3 Peripheral Enable For MPU Set Register */
#define TOFF_RCC_MP_AHB3ENCLRR    0x0A24	/* (RW) RCC AHB3 Peripheral Enable For MPU Clear Register */
#define TOFF_RCC_MP_AHB4ENSETR    0x0A28	/* (RW) RCC AHB4 Peripheral Enable For MPU Set Register */
#define TOFF_RCC_MP_AHB4ENCLRR    0x0A2C	/* (RW) RCC AHB4 Peripheral Enable For MPU Clear Register */
#define TOFF_RCC_MP_MLAHBENSETR   0x0A38	/* (RW) RCC MLAHB Periph. Enable For MPU Set Register */
#define TOFF_RCC_MP_MLAHBENCLRR   0x0A3C	/* (RW) RCC MLAHB Periph. Enable For MPU Clear Register */
#define TOFF_RCC_MC_APB1ENSETR    0x0A80	/* (RW) RCC APB1 Peripheral Enable For MCU Set Register */
  #define RCC_MC_APB1ENSETR_TIM2EN    0x00000001
  #define RCC_MC_APB1ENSETR_TIM3EN    0x00000002
  #define RCC_MC_APB1ENSETR_TIM4EN    0x00000004
  #define RCC_MC_APB1ENSETR_TIM5EN    0x00000008
  #define RCC_MC_APB1ENSETR_TIM6EN    0x00000010
  #define RCC_MC_APB1ENSETR_TIM7EN    0x00000020
  #define RCC_MC_APB1ENSETR_TIM12EN   0x00000040
  #define RCC_MC_APB1ENSETR_TIM13EN   0x00000080
  #define RCC_MC_APB1ENSETR_TIM14EN   0x00000100
  #define RCC_MC_APB1ENSETR_LPTIM1EN  0x00000200
  #define RCC_MC_APB1ENSETR_SPI2EN    0x00000800
  #define RCC_MC_APB1ENSETR_SPI3EN    0x00001000
  #define RCC_MC_APB1ENSETR_USART2EN  0x00004000
  #define RCC_MC_APB1ENSETR_USART3EN  0x00008000
  #define RCC_MC_APB1ENSETR_UART4EN   0x00010000
  #define RCC_MC_APB1ENSETR_UART5EN   0x00020000
  #define RCC_MC_APB1ENSETR_UART7EN   0x00040000
  #define RCC_MC_APB1ENSETR_UART8EN   0x00080000
  #define RCC_MC_APB1ENSETR_I2C1EN    0x00200000
  #define RCC_MC_APB1ENSETR_I2C2EN    0x00400000
  #define RCC_MC_APB1ENSETR_I2C3EN    0x00800000
  #define RCC_MC_APB1ENSETR_I2C5EN    0x01000000
  #define RCC_MC_APB1ENSETR_SPDIFEN   0x04000000
  #define RCC_MC_APB1ENSETR_CECEN     0x08000000
  #define RCC_MC_APB1ENSETR_WWDG1EN   0x10000000
  #define RCC_MC_APB1ENSETR_DAC12EN   0x20000000
  #define RCC_MC_APB1ENSETR_MDIOSEN   0x80000000
#define TOFF_RCC_MC_APB1ENCLRR    0x0A84	/* (RW) RCC APB1 Peripheral Enable For MCU Clear Register */
  #define RCC_MC_APB1ENCLRR_TIM2EN    0x00000001
  #define RCC_MC_APB1ENCLRR_TIM3EN    0x00000002
  #define RCC_MC_APB1ENCLRR_TIM4EN    0x00000004
  #define RCC_MC_APB1ENCLRR_TIM5EN    0x00000008
  #define RCC_MC_APB1ENCLRR_TIM6EN    0x00000010
  #define RCC_MC_APB1ENCLRR_TIM7EN    0x00000020
  #define RCC_MC_APB1ENCLRR_TIM12EN   0x00000040
  #define RCC_MC_APB1ENCLRR_TIM13EN   0x00000080
  #define RCC_MC_APB1ENCLRR_TIM14EN   0x00000100
  #define RCC_MC_APB1ENCLRR_LPTIM1EN  0x00000200
  #define RCC_MC_APB1ENCLRR_SPI2EN    0x00000800
  #define RCC_MC_APB1ENCLRR_SPI3EN    0x00001000
  #define RCC_MC_APB1ENCLRR_USART2EN  0x00004000
  #define RCC_MC_APB1ENCLRR_USART3EN  0x00008000
  #define RCC_MC_APB1ENCLRR_UART4EN   0x00010000
  #define RCC_MC_APB1ENCLRR_UART5EN   0x00020000
  #define RCC_MC_APB1ENCLRR_UART7EN   0x00040000
  #define RCC_MC_APB1ENCLRR_UART8EN   0x00080000
  #define RCC_MC_APB1ENCLRR_I2C1EN    0x00200000
  #define RCC_MC_APB1ENCLRR_I2C2EN    0x00400000
  #define RCC_MC_APB1ENCLRR_I2C3EN    0x00800000
  #define RCC_MC_APB1ENCLRR_I2C5EN    0x01000000
  #define RCC_MC_APB1ENCLRR_SPDIFEN   0x04000000
  #define RCC_MC_APB1ENCLRR_CECEN     0x08000000
  #define RCC_MC_APB1ENCLRR_WWDG1EN   0x10000000
  #define RCC_MC_APB1ENCLRR_DAC12EN   0x20000000
  #define RCC_MC_APB1ENCLRR_MDIOSEN   0x80000000
#define TOFF_RCC_MC_APB2ENSETR    0x0A88	/* (RW) RCC APB2 Peripheral Enable For MCU Set Register */
  #define RCC_MC_APB2ENSETR_TIM1EN    0x00000001
  #define RCC_MC_APB2ENSETR_TIM8EN    0x00000002
  #define RCC_MC_APB2ENSETR_TIM15EN   0x00000004
  #define RCC_MC_APB2ENSETR_TIM16EN   0x00000008
  #define RCC_MC_APB2ENSETR_TIM17EN   0x00000010
  #define RCC_MC_APB2ENSETR_SPI1EN    0x00000100
  #define RCC_MC_APB2ENSETR_SPI4EN    0x00000200
  #define RCC_MC_APB2ENSETR_SPI5EN    0x00000400
  #define RCC_MC_APB2ENSETR_USART6EN  0x00002000
  #define RCC_MC_APB2ENSETR_SAI1EN    0x00010000
  #define RCC_MC_APB2ENSETR_SAI2EN    0x00020000
  #define RCC_MC_APB2ENSETR_SAI3EN    0x00040000
  #define RCC_MC_APB2ENSETR_DFSDMEN   0x00100000
  #define RCC_MC_APB2ENSETR_ADFSDMEN  0x00200000
  #define RCC_MC_APB2ENSETR_FDCANEN   0x01000000
#define TOFF_RCC_MC_APB2ENCLRR    0x0A8C	/* (RW) RCC APB2 Peripheral Enable For MCU Clear Register */
  #define RCC_MC_APB2ENCLRR_TIM1EN    0x00000001
  #define RCC_MC_APB2ENCLRR_TIM8EN    0x00000002
  #define RCC_MC_APB2ENCLRR_TIM15EN   0x00000004
  #define RCC_MC_APB2ENCLRR_TIM16EN   0x00000008
  #define RCC_MC_APB2ENCLRR_TIM17EN   0x00000010
  #define RCC_MC_APB2ENCLRR_SPI1EN    0x00000100
  #define RCC_MC_APB2ENCLRR_SPI4EN    0x00000200
  #define RCC_MC_APB2ENCLRR_SPI5EN    0x00000400
  #define RCC_MC_APB2ENCLRR_USART6EN  0x00002000
  #define RCC_MC_APB2ENCLRR_SAI1EN    0x00010000
  #define RCC_MC_APB2ENCLRR_SAI2EN    0x00020000
  #define RCC_MC_APB2ENCLRR_SAI3EN    0x00040000
  #define RCC_MC_APB2ENCLRR_DFSDMEN   0x00100000
  #define RCC_MC_APB2ENCLRR_ADFSDMEN  0x00200000
  #define RCC_MC_APB2ENCLRR_FDCANEN   0x01000000
#define TOFF_RCC_MC_APB3ENSETR    0x0A90	/* (RW) RCC APB3 Peripheral Enable For MCU Set Register */
  #define RCC_MC_APB3ENSETR_LPTIM2EN  0x00000001
  #define RCC_MC_APB3ENSETR_LPTIM3EN  0x00000002
  #define RCC_MC_APB3ENSETR_LPTIM4EN  0x00000004
  #define RCC_MC_APB3ENSETR_LPTIM5EN  0x00000008
  #define RCC_MC_APB3ENSETR_SAI4EN    0x00000100
  #define RCC_MC_APB3ENSETR_SYSCFGEN  0x00000800
  #define RCC_MC_APB3ENSETR_VREFEN    0x00002000
  #define RCC_MC_APB3ENSETR_DTSEN     0x00010000
  #define RCC_MC_APB3ENSETR_PMBCTRLEN 0x00020000
  #define RCC_MC_APB3ENSETR_HDPEN     0x00100000
#define TOFF_RCC_MC_APB3ENCLRR    0x0A94	/* (RW) RCC APB3 Peripheral Enable For MCU Clear Register */
  #define RCC_MC_APB3ENCLRR_LPTIM2EN  0x00000001
  #define RCC_MC_APB3ENCLRR_LPTIM3EN  0x00000002
  #define RCC_MC_APB3ENCLRR_LPTIM4EN  0x00000004
  #define RCC_MC_APB3ENCLRR_LPTIM5EN  0x00000008
  #define RCC_MC_APB3ENCLRR_SAI4EN    0x00000100
  #define RCC_MC_APB3ENCLRR_SYSCFGEN  0x00000800
  #define RCC_MC_APB3ENCLRR_VREFEN    0x00002000
  #define RCC_MC_APB3ENCLRR_DTSEN     0x00010000
  #define RCC_MC_APB3ENCLRR_PMBCTRLEN 0x00020000
  #define RCC_MC_APB3ENCLRR_HDPEN     0x00100000
#define TOFF_RCC_MC_AHB2ENSETR    0x0A98	/* (RW) RCC AHB2 Peripheral Enable For MCU Set Register */
  #define RCC_MC_AHB2ENSETR_DMA1EN    0x00000001
  #define RCC_MC_AHB2ENSETR_DMA2EN    0x00000002
  #define RCC_MC_AHB2ENSETR_DMAMUXEN  0x00000004
  #define RCC_MC_AHB2ENSETR_ADC12EN   0x00000020
  #define RCC_MC_AHB2ENSETR_USBOEN    0x00000100
  #define RCC_MC_AHB2ENSETR_SDMMC3EN  0x00010000
#define TOFF_RCC_MC_AHB2ENCLRR    0x0A9C	/* (RW) RCC AHB2 Peripheral Enable For MCU Clear Register */
  #define RCC_MC_AHB2ENCLRR_DMA1EN    0x00000001
  #define RCC_MC_AHB2ENCLRR_DMA2EN    0x00000002
  #define RCC_MC_AHB2ENCLRR_DMAMUXEN  0x00000004
  #define RCC_MC_AHB2ENCLRR_ADC12EN   0x00000020
  #define RCC_MC_AHB2ENCLRR_USBOEN    0x00000100
  #define RCC_MC_AHB2ENCLRR_SDMMC3EN  0x00010000
#define TOFF_RCC_MC_AHB3ENSETR    0x0AA0	/* (RW) RCC AHB3 Peripheral Enable For MCU Set Register */
  #define RCC_MC_AHB3ENSETR_DCMIEN    0x00000001
  #define RCC_MC_AHB3ENSETR_CRYP2EN   0x00000010
  #define RCC_MC_AHB3ENSETR_HASH2EN   0x00000020
  #define RCC_MC_AHB3ENSETR_RNG2EN    0x00000040
  #define RCC_MC_AHB3ENSETR_CRC2EN    0x00000080
  #define RCC_MC_AHB3ENSETR_HSEMEN    0x00000800
  #define RCC_MC_AHB3ENSETR_IPCCEN    0x00001000
#define TOFF_RCC_MC_AHB3ENCLRR    0x0AA4	/* (RW) RCC AHB3 Peripheral Enable For MCU Clear Register */
  #define RCC_MC_AHB3ENCLRR_DCMIEN    0x00000001
  #define RCC_MC_AHB3ENCLRR_CRYP2EN   0x00000010
  #define RCC_MC_AHB3ENCLRR_HASH2EN   0x00000020
  #define RCC_MC_AHB3ENCLRR_RNG2EN    0x00000040
  #define RCC_MC_AHB3ENCLRR_CRC2EN    0x00000080
  #define RCC_MC_AHB3ENCLRR_HSEMEN    0x00000800
  #define RCC_MC_AHB3ENCLRR_IPCCEN    0x00001000
#define TOFF_RCC_MC_AHB4ENSETR    0x0AA8	/* (RW) RCC AHB4 Peripheral Enable For MCU Set Register */
  #define RCC_MC_AHB4ENSETR_GPIOAEN   0x00000001
  #define RCC_MC_AHB4ENSETR_GPIOBEN   0x00000002
  #define RCC_MC_AHB4ENSETR_GPIOCEN   0x00000004
  #define RCC_MC_AHB4ENSETR_GPIODEN   0x00000008
  #define RCC_MC_AHB4ENSETR_GPIOEEN   0x00000010
  #define RCC_MC_AHB4ENSETR_GPIOFEN   0x00000020
  #define RCC_MC_AHB4ENSETR_GPIOGEN   0x00000040
  #define RCC_MC_AHB4ENSETR_GPIOHEN   0x00000080
  #define RCC_MC_AHB4ENSETR_GPIOIEN   0x00000100
  #define RCC_MC_AHB4ENSETR_GPIOJEN   0x00000200
  #define RCC_MC_AHB4ENSETR_GPIOKEN   0x00000400
#define TOFF_RCC_MC_AHB4ENCLRR    0x0AAC	/* (RW) RCC AHB4 Peripheral Enable For MCU Clear Register */
  #define RCC_MC_AHB4ENCLRR_GPIOAEN   0x00000001
  #define RCC_MC_AHB4ENCLRR_GPIOBEN   0x00000002
  #define RCC_MC_AHB4ENCLRR_GPIOCEN   0x00000004
  #define RCC_MC_AHB4ENCLRR_GPIODEN   0x00000008
  #define RCC_MC_AHB4ENCLRR_GPIOEEN   0x00000010
  #define RCC_MC_AHB4ENCLRR_GPIOFEN   0x00000020
  #define RCC_MC_AHB4ENCLRR_GPIOGEN   0x00000040
  #define RCC_MC_AHB4ENCLRR_GPIOHEN   0x00000080
  #define RCC_MC_AHB4ENCLRR_GPIOIEN   0x00000100
  #define RCC_MC_AHB4ENCLRR_GPIOJEN   0x00000200
  #define RCC_MC_AHB4ENCLRR_GPIOKEN   0x00000400
#define TOFF_RCC_MC_AXIMENSETR    0x0AB0	/* (RW) RCC AXI Periph. Enable For MCU Set Register */
  #define RCC_MC_AXIMENSETR_SYSRAMEN  0x00000001
#define TOFF_RCC_MC_AXIMENCLRR    0x0AB4	/* (RW) RCC AXI Periph. Enable For MCU Clear Register */
  #define RCC_MC_AXIMENCLRR_SYSRAMEN  0x00000001
#define TOFF_RCC_MC_MLAHBENSETR   0x0AB8	/* (RW) RCC MLAHB Periph. Enable For MCU Set Register */
  #define RCC_MC_MLAHBENSETR_RETRAMEN 0x00000010
#define TOFF_RCC_MC_MLAHBENCLRR   0x0ABC	/* (RW) RCC MLAHB Periph. Enable For MCU Clear Register */
  #define RCC_MC_MLAHBENCLRR_RETRAMEN 0x00000010
#define TOFF_RCC_MP_APB1LPENSETR  0x0B00	/* (RW) RCC APB1 Sleep Clock Ena. For MPU Set Register */
  #define RCC_MC_APB1LPENSETR_TIM2LPEN    0x00000001
  #define RCC_MC_APB1LPENSETR_TIM3LPEN    0x00000002
  #define RCC_MC_APB1LPENSETR_TIM4LPEN    0x00000004
  #define RCC_MC_APB1LPENSETR_TIM5LPEN    0x00000008
  #define RCC_MC_APB1LPENSETR_TIM6LPEN    0x00000010
  #define RCC_MC_APB1LPENSETR_TIM7LPEN    0x00000020
  #define RCC_MC_APB1LPENSETR_TIM12LPEN   0x00000040
  #define RCC_MC_APB1LPENSETR_TIM13LPEN   0x00000080
  #define RCC_MC_APB1LPENSETR_TIM14LPEN   0x00000100
  #define RCC_MC_APB1LPENSETR_LPTIM1LPEN  0x00000200
  #define RCC_MC_APB1LPENSETR_SPI2LPEN    0x00000800
  #define RCC_MC_APB1LPENSETR_SPI3LPEN    0x00001000
  #define RCC_MC_APB1LPENSETR_USART2LPEN  0x00004000
  #define RCC_MC_APB1LPENSETR_USART3LPEN  0x00008000
  #define RCC_MC_APB1LPENSETR_UART4LPEN   0x00010000
  #define RCC_MC_APB1LPENSETR_UART5LPEN   0x00020000
  #define RCC_MC_APB1LPENSETR_UART7LPEN   0x00040000
  #define RCC_MC_APB1LPENSETR_UART8LPEN   0x00080000
  #define RCC_MC_APB1LPENSETR_I2C1LPEN    0x00200000
  #define RCC_MC_APB1LPENSETR_I2C2LPEN    0x00400000
  #define RCC_MC_APB1LPENSETR_I2C3LPEN    0x00800000
  #define RCC_MC_APB1LPENSETR_I2C5LPEN    0x01000000
  #define RCC_MC_APB1LPENSETR_SPDIFLPEN   0x04000000
  #define RCC_MC_APB1LPENSETR_CECLPEN     0x08000000
  #define RCC_MC_APB1LPENSETR_WWDG1LPEN   0x10000000
  #define RCC_MC_APB1LPENSETR_DAC12LPEN   0x20000000
  #define RCC_MC_APB1LPENSETR_MDIOSLPEN   0x80000000
#define TOFF_RCC_MP_APB1LPENCLRR  0x0B04	/* (RW) RCC APB1 Sleep Clock Ena. For MPU Clear Register */
  #define RCC_MC_APB1LPENCLRR_TIM2LPEN    0x00000001
  #define RCC_MC_APB1LPENCLRR_TIM3LPEN    0x00000002
  #define RCC_MC_APB1LPENCLRR_TIM4LPEN    0x00000004
  #define RCC_MC_APB1LPENCLRR_TIM5LPEN    0x00000008
  #define RCC_MC_APB1LPENCLRR_TIM6LPEN    0x00000010
  #define RCC_MC_APB1LPENCLRR_TIM7LPEN    0x00000020
  #define RCC_MC_APB1LPENCLRR_TIM12LPEN   0x00000040
  #define RCC_MC_APB1LPENCLRR_TIM13LPEN   0x00000080
  #define RCC_MC_APB1LPENCLRR_TIM14LPEN   0x00000100
  #define RCC_MC_APB1LPENCLRR_LPTIM1LPEN  0x00000200
  #define RCC_MC_APB1LPENCLRR_SPI2LPEN    0x00000800
  #define RCC_MC_APB1LPENCLRR_SPI3LPEN    0x00001000
  #define RCC_MC_APB1LPENCLRR_USART2LPEN  0x00004000
  #define RCC_MC_APB1LPENCLRR_USART3LPEN  0x00008000
  #define RCC_MC_APB1LPENCLRR_UART4LPEN   0x00010000
  #define RCC_MC_APB1LPENCLRR_UART5LPEN   0x00020000
  #define RCC_MC_APB1LPENCLRR_UART7LPEN   0x00040000
  #define RCC_MC_APB1LPENCLRR_UART8LPEN   0x00080000
  #define RCC_MC_APB1LPENCLRR_I2C1LPEN    0x00200000
  #define RCC_MC_APB1LPENCLRR_I2C2LPEN    0x00400000
  #define RCC_MC_APB1LPENCLRR_I2C3LPEN    0x00800000
  #define RCC_MC_APB1LPENCLRR_I2C5LPEN    0x01000000
  #define RCC_MC_APB1LPENCLRR_SPDIFLPEN   0x04000000
  #define RCC_MC_APB1LPENCLRR_CECLPEN     0x08000000
  #define RCC_MC_APB1LPENCLRR_WWDG1LPEN   0x10000000
  #define RCC_MC_APB1LPENCLRR_DAC12LPEN   0x20000000
  #define RCC_MC_APB1LPENCLRR_MDIOSLPEN   0x80000000
#define TOFF_RCC_MP_APB2LPENSETR  0x0B08	/* (RW) RCC APB2 Sleep Clock Ena. For MPU Set Register */
  #define RCC_MC_APB2LPENSETR_TIM1LPEN    0x00000001
  #define RCC_MC_APB2LPENSETR_TIM8LPEN    0x00000002
  #define RCC_MC_APB2LPENSETR_TIM15LPEN   0x00000004
  #define RCC_MC_APB2LPENSETR_TIM16LPEN   0x00000008
  #define RCC_MC_APB2LPENSETR_TIM17LPEN   0x00000010
  #define RCC_MC_APB2LPENSETR_SPI1LPEN    0x00000100
  #define RCC_MC_APB2LPENSETR_SPI4LPEN    0x00000200
  #define RCC_MC_APB2LPENSETR_SPI5LPEN    0x00000400
  #define RCC_MC_APB2LPENSETR_USART6LPEN  0x00002000
  #define RCC_MC_APB2LPENSETR_SAI1LPEN    0x00010000
  #define RCC_MC_APB2LPENSETR_SAI2LPEN    0x00020000
  #define RCC_MC_APB2LPENSETR_SAI3LPEN    0x00040000
  #define RCC_MC_APB2LPENSETR_DFSDMLPEN   0x00100000
  #define RCC_MC_APB2LPENSETR_ADFSDMLPEN  0x00200000
  #define RCC_MC_APB2LPENSETR_FDCANLPEN   0x01000000
#define TOFF_RCC_MP_APB2LPENCLRR  0x0B0C	/* (RW) RCC APB2 Sleep Clock Ena. For MPU Clear Register */
  #define RCC_MC_APB2LPENCLRR_TIM1LPEN    0x00000001
  #define RCC_MC_APB2LPENCLRR_TIM8LPEN    0x00000002
  #define RCC_MC_APB2LPENCLRR_TIM15LPEN   0x00000004
  #define RCC_MC_APB2LPENCLRR_TIM16LPEN   0x00000008
  #define RCC_MC_APB2LPENCLRR_TIM17LPEN   0x00000010
  #define RCC_MC_APB2LPENCLRR_SPI1LPEN    0x00000100
  #define RCC_MC_APB2LPENCLRR_SPI4LPEN    0x00000200
  #define RCC_MC_APB2LPENCLRR_SPI5LPEN    0x00000400
  #define RCC_MC_APB2LPENCLRR_USART6LPEN  0x00002000
  #define RCC_MC_APB2LPENCLRR_SAI1LPEN    0x00010000
  #define RCC_MC_APB2LPENCLRR_SAI2LPEN    0x00020000
  #define RCC_MC_APB2LPENCLRR_SAI3LPEN    0x00040000
  #define RCC_MC_APB2LPENCLRR_DFSDMLPEN   0x00100000
  #define RCC_MC_APB2LPENCLRR_ADFSDMLPEN  0x00200000
  #define RCC_MC_APB2LPENCLRR_FDCANLPEN   0x01000000
#define TOFF_RCC_MP_APB3LPENSETR  0x0B10	/* (RW) RCC APB3 Sleep Clock Ena. For MPU Set Register */
  #define RCC_MC_APB3LPENSETR_LPTIM2LPEN  0x00000001
  #define RCC_MC_APB3LPENSETR_LPTIM3LPEN  0x00000002
  #define RCC_MC_APB3LPENSETR_LPTIM4LPEN  0x00000004
  #define RCC_MC_APB3LPENSETR_LPTIM5LPEN  0x00000008
  #define RCC_MC_APB3LPENSETR_SAI4LPEN    0x00000100
  #define RCC_MC_APB3LPENSETR_SYSCFGLPEN  0x00000800
  #define RCC_MC_APB3LPENSETR_VREFLPEN    0x00002000
  #define RCC_MC_APB3LPENSETR_DTSLPEN     0x00010000
  #define RCC_MC_APB3LPENSETR_PMBCTRLLPEN 0x00020000
#define TOFF_RCC_MP_APB3LPENCLRR  0x0B14	/* (RW) RCC APB3 Sleep Clock Ena. For MPU Clear Register */
  #define RCC_MC_APB3LPENCLRR_LPTIM2LPEN  0x00000001
  #define RCC_MC_APB3LPENCLRR_LPTIM3LPEN  0x00000002
  #define RCC_MC_APB3LPENCLRR_LPTIM4LPEN  0x00000004
  #define RCC_MC_APB3LPENCLRR_LPTIM5LPEN  0x00000008
  #define RCC_MC_APB3LPENCLRR_SAI4LPEN    0x00000100
  #define RCC_MC_APB3LPENCLRR_SYSCFGLPEN  0x00000800
  #define RCC_MC_APB3LPENCLRR_VREFLPEN    0x00002000
  #define RCC_MC_APB3LPENCLRR_DTSLPEN     0x00010000
  #define RCC_MC_APB3LPENCLRR_PMBCTRLLPEN 0x00020000
#define TOFF_RCC_MP_AHB2LPENSETR  0x0B18	/* (RW) RCC AHB2 Sleep Clock Ena. For MPU Set Register */
#define TOFF_RCC_MP_AHB2LPENCLRR  0x0B1C	/* (RW) RCC AHB2 Sleep Clock Ena. For MPU Clear Register */
#define TOFF_RCC_MP_AHB3LPENSETR  0x0B20	/* (RW) RCC AHB3 Sleep Clock Ena. For MPU Set Register */
#define TOFF_RCC_MP_AHB3LPENCLRR  0x0B24	/* (RW) RCC AHB3 Sleep Clock Ena. For MPU Clear Register */
#define TOFF_RCC_MP_AHB4LPENSETR  0x0B28	/* (RW) RCC AHB4 Sleep Clock Ena. For MPU Set Register */
#define TOFF_RCC_MP_AHB4LPENCLRR  0x0B2C	/* (RW) RCC AHB4 Sleep Clock Ena. For MPU Clear Register */
#define TOFF_RCC_MP_AXIMLPENSETR  0x0B30	/* (RW) RCC AXI Sleep Clock Ena. For MPU Set Register */
#define TOFF_RCC_MP_AXIMLPENCLRR  0x0B34	/* (RW) RCC AXI Sleep Clock Ena. For MPU Clear Register */
#define TOFF_RCC_MP_MLAHBLPENSETR 0x0B38	/* (RW) RCC MLAHB Sleep Clock Ena. For MPU Set Register */
#define TOFF_RCC_MP_MLAHBLPENCLRR 0x0B3C	/* (RW) RCC MLAHB Sleep Clock Ena. For MPU Clear Register */
#define TOFF_RCC_MC_APB1LPENSETR  0x0B80	/* (RW) RCC APB1 Sleep Clock Ena. For MCU Set Register */
#define TOFF_RCC_MC_APB1LPENCLRR  0x0B84	/* (RW) RCC APB1 Sleep Clock Ena. For MCU Clear Register */
#define TOFF_RCC_MC_APB2LPENSETR  0x0B88	/* (RW) RCC APB2 Sleep Clock Ena. For MCU Set Register */
#define TOFF_RCC_MC_APB2LPENCLRR  0x0B8C	/* (RW) RCC APB2 Sleep Clock Ena. For MCU Clear Register */
#define TOFF_RCC_MC_APB3LPENSETR  0x0B90	/* (RW) RCC APB3 Sleep Clock Ena. For MCU Set Register */
#define TOFF_RCC_MC_APB3LPENCLRR  0x0B94	/* (RW) RCC APB3 Sleep Clock Ena. For MCU Clear Register */
#define TOFF_RCC_MC_AHB2LPENSETR  0x0B98	/* (RW) RCC AHB2 Sleep Clock Ena. For MCU Set Register */
  #define RCC_MC_AHB2LPENSETR_DMA1LPEN    0x00000001
  #define RCC_MC_AHB2LPENSETR_DMA2LPEN    0x00000002
  #define RCC_MC_AHB2LPENSETR_DMAMUXLPEN  0x00000004
  #define RCC_MC_AHB2LPENSETR_ADC12LPEN   0x00000020
  #define RCC_MC_AHB2LPENSETR_USBOLPEN    0x00000100
  #define RCC_MC_AHB2LPENSETR_SDMMC3LPEN  0x00010000
#define TOFF_RCC_MC_AHB2LPENCLRR  0x0B9C	/* (RW) RCC AHB2 Sleep Clock Ena. For MCU Clear Register */
  #define RCC_MC_AHB2LPENCLRR_DMA1LPEN    0x00000001
  #define RCC_MC_AHB2LPENCLRR_DMA2LPEN    0x00000002
  #define RCC_MC_AHB2LPENCLRR_DMAMUXLPEN  0x00000004
  #define RCC_MC_AHB2LPENCLRR_ADC12LPEN   0x00000020
  #define RCC_MC_AHB2LPENCLRR_USBOLPEN    0x00000100
  #define RCC_MC_AHB2LPENCLRR_SDMMC3LPEN  0x00010000
#define TOFF_RCC_MC_AHB3LPENSETR  0x0BA0	/* (RW) RCC AHB3 Sleep Clock Ena. For MCU Set Register */
  #define RCC_MC_AHB3LPENSETR_DCMILPEN    0x00000001
  #define RCC_MC_AHB3LPENSETR_CRYP2LPEN   0x00000010
  #define RCC_MC_AHB3LPENSETR_HASH2LPEN   0x00000020
  #define RCC_MC_AHB3LPENSETR_RNG2LPEN    0x00000040
  #define RCC_MC_AHB3LPENSETR_CRC2LPEN    0x00000080
  #define RCC_MC_AHB3LPENSETR_HSEMLPEN    0x00000800
  #define RCC_MC_AHB3LPENSETR_IPCCLPEN    0x00001000
#define TOFF_RCC_MC_AHB3LPENCLRR  0x0BA4	/* (RW) RCC AHB3 Sleep Clock Ena. For MCU Clear Register */
  #define RCC_MC_AHB3LPENCLRR_DCMILPEN    0x00000001
  #define RCC_MC_AHB3LPENCLRR_CRYP2LPEN   0x00000010
  #define RCC_MC_AHB3LPENCLRR_HASH2LPEN   0x00000020
  #define RCC_MC_AHB3LPENCLRR_RNG2LPEN    0x00000040
  #define RCC_MC_AHB3LPENCLRR_CRC2LPEN    0x00000080
  #define RCC_MC_AHB3LPENCLRR_HSEMLPEN    0x00000800
  #define RCC_MC_AHB3LPENCLRR_IPCCLPEN    0x00001000
#define TOFF_RCC_MC_AHB4LPENSETR  0x0BA8	/* (RW) RCC AHB4 Sleep Clock Ena. For MCU Set Register */
  #define RCC_MC_AHB4LPENSETR_GPIOALPEN   0x00000001
  #define RCC_MC_AHB4LPENSETR_GPIOBLPEN   0x00000002
  #define RCC_MC_AHB4LPENSETR_GPIOCLPEN   0x00000004
  #define RCC_MC_AHB4LPENSETR_GPIODLPEN   0x00000008
  #define RCC_MC_AHB4LPENSETR_GPIOELPEN   0x00000010
  #define RCC_MC_AHB4LPENSETR_GPIOFLPEN   0x00000020
  #define RCC_MC_AHB4LPENSETR_GPIOGLPEN   0x00000040
  #define RCC_MC_AHB4LPENSETR_GPIOHLPEN   0x00000080
  #define RCC_MC_AHB4LPENSETR_GPIOILPEN   0x00000100
  #define RCC_MC_AHB4LPENSETR_GPIOJLPEN   0x00000200
  #define RCC_MC_AHB4LPENSETR_GPIOKLPEN   0x00000400
#define TOFF_RCC_MC_AHB4LPENCLRR  0x0BAC	/* (RW) RCC AHB4 Sleep Clock Ena. For MCU Clear Register */
  #define RCC_MC_AHB4LPENCLRR_GPIOALPEN   0x00000001
  #define RCC_MC_AHB4LPENCLRR_GPIOBLPEN   0x00000002
  #define RCC_MC_AHB4LPENCLRR_GPIOCLPEN   0x00000004
  #define RCC_MC_AHB4LPENCLRR_GPIODLPEN   0x00000008
  #define RCC_MC_AHB4LPENCLRR_GPIOELPEN   0x00000010
  #define RCC_MC_AHB4LPENCLRR_GPIOFLPEN   0x00000020
  #define RCC_MC_AHB4LPENCLRR_GPIOGLPEN   0x00000040
  #define RCC_MC_AHB4LPENCLRR_GPIOHLPEN   0x00000080
  #define RCC_MC_AHB4LPENCLRR_GPIOILPEN   0x00000100
  #define RCC_MC_AHB4LPENCLRR_GPIOJLPEN   0x00000200
  #define RCC_MC_AHB4LPENCLRR_GPIOKLPEN   0x00000400
#define TOFF_RCC_MC_AXIMLPENSETR  0x0BB0	/* (RW) RCC AXI Sleep Clock Ena. For MCU Set Register */
  #define RCC_MC_AXIMLPENSETR_SYSRAMLPEN  0x00000001
#define TOFF_RCC_MC_AXIMLPENCLRR  0x0BB4	/* (RW) RCC AXI Sleep Clock Ena. For MCU Clear Register */
  #define RCC_MC_AXIMLPENCLRR_SYSRAMLPEN  0x00000001
#define TOFF_RCC_MC_MLAHBLPENSETR 0x0BB8	/* (RW) RCC MLAHB Sleep Clock Ena. For MCU Set Register */
  #define RCC_MC_MLAHBLPENSETR_SRAM1LPEN  0x00000001
  #define RCC_MC_MLAHBLPENSETR_SRAM2LPEN  0x00000002
  #define RCC_MC_MLAHBLPENSETR_SRAM3LPEN  0x00000004
  #define RCC_MC_MLAHBLPENSETR_RETRAMLPEN 0x00000010
#define TOFF_RCC_MC_MLAHBLPENCLRR 0x0BBC	/* (RW) RCC MLAHB Sleep Clock Ena. For MCU Clear Register */
  #define RCC_MC_MLAHBLPENCLRR_SRAM1LPEN  0x00000001
  #define RCC_MC_MLAHBLPENCLRR_SRAM2LPEN  0x00000002
  #define RCC_MC_MLAHBLPENCLRR_SRAM3LPEN  0x00000004
  #define RCC_MC_MLAHBLPENCLRR_RETRAMLPEN 0x00000010
#define TOFF_RCC_MC_RSTSCLRR      0x0C00	/* (RW) RCC MCU Reset Status Clear Register */
  #define RCC_MC_RSTSCLRR_PORRSTF     0x00000001	/* POR/PDR reset flag */
  #define RCC_MC_RSTSCLRR_BORRSTF     0x00000002	/* BOR reset flag */
  #define RCC_MC_RSTSCLRR_PADRSTF     0x00000004	/* NRST reset flag */
  #define RCC_MC_RSTSCLRR_HCSSRSTF    0x00000008	/* HSE CSS reset flag */
  #define RCC_MC_RSTSCLRR_VCORERSTF   0x00000010	/* VDDCORE reset flag */
  #define RCC_MC_RSTSCLRR_MCURSTF     0x00000020	/* MCU reset flag */
  #define RCC_MC_RSTSCLRR_MPSYSRSTF   0x00000040	/* MPU System reset flag */
  #define RCC_MC_RSTSCLRR_MCSYSRSTF   0x00000080	/* MCU System reset flag */
  #define RCC_MC_RSTSCLRR_IWDG1RSTF   0x00000100	/* IWDG1 reset flag */
  #define RCC_MC_RSTSCLRR_IWDG2RSTF   0x00000200	/* IWDG2 reset flag */
  #define RCC_MC_RSTSCLRR_WWDG1RSTF   0x00000400	/* WWDG1 reset flag */
#define TOFF_RCC_MC_CIER          0x0C14	/* (RW) RCC Clock Source Interrupt Enable Register */
  #define RCC_MC_CIER_LSIRDYIE        0x00000001	/* LSI ready Interrupt Enable */
  #define RCC_MC_CIER_LSERDYIE        0x00000002	/* LSE ready Interrupt Enable */
  #define RCC_MC_CIER_HSIRDYIE        0x00000004	/* HSI ready Interrupt Enable */
  #define RCC_MC_CIER_HSERDYIE        0x00000008	/* HSE ready Interrupt Enable */
  #define RCC_MC_CIER_CSIRDYIE        0x00000010	/* CSI ready Interrupt Enable */
  #define RCC_MC_CIER_PLL1DYIE        0x00000100	/* PLL1DYIE ready Interrupt Enable */
  #define RCC_MC_CIER_PLL2DYIE        0x00000200	/* PLL2DYIE ready Interrupt Enable */
  #define RCC_MC_CIER_PLL3DYIE        0x00000400	/* PLL3DYIE ready Interrupt Enable */
  #define RCC_MC_CIER_PLL4DYIE        0x00000800	/* PLL4DYIE ready Interrupt Enable */
  #define RCC_MC_CIER_LSECSSIE        0x00010000	/* LSE clock security system Interrupt Enable */
  #define RCC_MC_CIER_WKUPIE          0x00100000	/* Wake-up from CSTOP Interrupt Enable */
#define TOFF_RCC_MC_CIFR          0x0C18	/* (RW) RCC Clock Source Interrupt Flag Register */
  #define RCC_MC_CIFR_LSIRDYF         0x00000001	/* LSI ready Interrupt Flag */
  #define RCC_MC_CIFR_LSERDYF         0x00000002	/* LSE ready Interrupt Flag */
  #define RCC_MC_CIFR_HSIRDYF         0x00000004	/* HSI ready Interrupt Flag */
  #define RCC_MC_CIFR_HSERDYF         0x00000008	/* HSE ready Interrupt Flag */
  #define RCC_MC_CIFR_CSIRDYF         0x00000010	/* CSI ready Interrupt Flag */
  #define RCC_MC_CIFR_PLL1DYF         0x00000100	/* PLL1 ready Interrupt Flag */
  #define RCC_MC_CIFR_PLL2DYF         0x00000200	/* PLL2 ready Interrupt Flag */
  #define RCC_MC_CIFR_PLL3DYF         0x00000400	/* PLL3 ready Interrupt Flag */
  #define RCC_MC_CIFR_PLL4DYF         0x00000800	/* PLL4 ready Interrupt Flag */
  #define RCC_MC_CIFR_LSECSSF         0x00010000	/* LSE clock security system Interrupt Flag */
  #define RCC_MC_CIFR_WKUPF           0x00100000	/* Wake-up from CSTOP Interrupt Flag */
#define TOFF_RCC_VERR             0x0FF4	/* (R)  RCC Version register */
  #define RCC_VERR_MINREV             0x0000000F
  #define RCC_VERR_MAJREV             0x000000F0
#define TOFF_RCC_IPIDR            0x0FF8	/* (R)  RCC ID register */
#define TOFF_RCC_SIDR             0x0FFC	/* (R)  Size ID register */


/*
 *  POWER CONTROL
 */
#define TADR_PWR_BASE       (MCU_AHB4_PERIPH_BASE + 0x1000)
#define TOFF_PWR_CR1        0x0000		/* (RW) PWR power control register */
  #define PWR_CR1_LPDS          0x00000001	/* Low Power Deepsleep STOP mode selection */
  #define PWR_CR1_LPCFG         0x00000002	/* PWR_ON pin configuration */
  #define PWR_CR1_LVDS          0x00000004	/* Low Voltage Deepsleep LP-STOP mode selection */
  #define PWR_CR1_RESERVED0     0x00000008	/* Reserved, must be kept at reset value */
  #define PWR_CR1_PVDEN         0x00000010	/* Programmable Voltage detector enable */
  #define PWR_CR1_PLS           0x000000E0	/* Programmable Voltage Detector level selection */
  #define PWR_CR1_PLS_LEV0      0x00000000	/* PVD level 0 */
  #define PWR_CR1_PLS_LEV1      0x00000020	/* PVD level 1 */
  #define PWR_CR1_PLS_LEV2      0x00000040	/* PVD level 2 */
  #define PWR_CR1_PLS_LEV3      0x00000060	/* PVD level 3 */
  #define PWR_CR1_PLS_LEV4      0x00000080	/* PVD level 4 */
  #define PWR_CR1_PLS_LEV5      0x000000A0	/* PVD level 5 */
  #define PWR_CR1_PLS_LEV6      0x000000C0	/* PVD level 6 */
  #define PWR_CR1_PLS_LEV7      0x000000E0	/* PVD level 7 */
  #define PWR_CR1_DBP           0x00000100	/* Disable Back-up domain Protection */
  #define PWR_CR1_RESERVED1     0x00000200	/* Reserved, must be kept at reset value */
  #define PWR_CR1_RESERVED2     0x0000F800	/* Reserved, must be kept at reset value */
  #define PWR_CR1_AVDEN         0x00010000	/* Peripheral Voltage Monitor on VDDA enable */
  #define PWR_CR1_ALS           0x00060000	/* Analog Voltage Detector level selection */
  #define PWR_CR1_ALS_LEV0      0x00000000	/* AVD level 0 */
  #define PWR_CR1_ALS_LEV1      0x00020000	/* AVD level 1 */
  #define PWR_CR1_ALS_LEV2      0x00040000	/* AVD level 2 */
  #define PWR_CR1_ALS_LEV3      0x00060000	/* AVD level 3 */
  #define PWR_CR1_RESERVED3     0xFFF80000	/* Reserved, must be kept at reset value */
#define TOFF_PWR_CSR1       0x0004		/* (RW) PWR control status register 1 */
  #define PWR_CSR1_PVDO         0x00000010	/* Programmable Voltage Detect Output */
  #define PWR_CSR1_AVDO         0x00010000	/* Analog Voltage detector Output on VDDA */
#define TOFF_PWR_CR2        0x0008		/* (RW) PWR control register 2 */
  #define PWR_CR2_BREN          0x00000001	/* Backup regulator enable */
  #define PWR_CR2_RREN          0x00000002	/* Retention Regulator enable */
  #define PWR_CR2_MONEN         0x00000010	/* VBAT and temperature monitoring enable */
  #define PWR_CR2_BRRDY         0x00010000	/* Backup Regulator ready */
  #define PWR_CR2_RRRDY         0x00020000	/* Retention Regulator ready */
  #define PWR_CR2_VBATL         0x00100000	/* Monitored VBAT level equal or below low threshold */
  #define PWR_CR2_VBATH         0x00200000	/* Monitored VBAT level equal or above high threshold */
  #define PWR_CR2_TEMPL         0x00300000	/* Monitored temperature level equal or below low threshold */
  #define PWR_CR2_TEMPH         0x00400000	/* Monitored temperature level equal or below high threshold */
#define TOFF_PWR_CR3        0x000C		/* (RW) PWR control register 3 */
  #define PWR_CR3_VBE           0x00000100	/* VBAT charging enable */
  #define PWR_CR3_VBRS          0x00000200	/* VBAT charging resistor selection */
  #define PWR_CR3_DDRSREN       0x00000400	/* DDR self-refresh in standby mode enable */
  #define PWR_CR3_DDRSRDIS      0x00000800	/* DDR self-refresh retention after standby disable */
  #define PWR_CR3_DDRRETEN      0x00001000	/* DDR retention enable */
  #define PWR_CR3_POPL          0x003E0000	/* PWR_ON pulse low configuration */
  #define PWR_CR3_USB33DEN      0x01000000	/* USB33DEN: USB 3.3V voltage level detector enable */
  #define PWR_CR3_USB33RDY      0x04000000	/* USB 3.3V supply ready */ 
  #define PWR_CR3_REG18EN       0x10000000	/* 1V8 regulator enable */
  #define PWR_CR3_REG18RDY      0x20000000	/* 1V8 regulator supply ready */
  #define PWR_CR3_REG11EN       0x40000000	/* 1V1 regulator enable  */
  #define PWR_CR3_REG11RDY      0x80000000	/* 1V1 regulator supply ready */
#define TOFF_PWR_MPUCR      0x0010		/* (RW) PWR MPU control register */
  #define PWR_MPUCR_PDDS        0x00000001	/* System Power Down Deepsleep selection */
  #define PWR_MPUCR_CSTBYDIS    0x00000008	/* MPU CStandby mode disable */
  #define PWR_MPUCR_STOPF       0x00000020	/* Stop Flag */
  #define PWR_MPUCR_SBF         0x00000040	/* System Standby Flag */
  #define PWR_MPUCR_SBF_MPU     0x00000080	/* MPU Standby Flag */
  #define PWR_MPUCR_CSSF        0x00000200	/* Clear MCU STANDBY, STOP and HOLD flags.(always read as 0) */
  #define PWR_MPUCR_STANDBYWFIL2 0x00008000	/* MPU system idle indication */
#define TOFF_PWR_MCUCR      0x0014		/* (RW) PWR MCU control register */
  #define PWR_MCUCR_PDDS        0x00000001	/* System Power Down Deepsleep selection */
  #define PWR_MCUCR_STOPF       0x00000020	/* Stop Flag */
  #define PWR_MCUCR_SBF         0x00000040	/* System Standby Flag */
  #define PWR_MCUCR_CSSF        0x00000200	/* Clear MCU Standby, Stop flags */
  #define PWR_MCUCR_DEEPSLEEP   0x00008000	/* MCU system idle indication */
#define TOFF_PWR_WKUPCR     0x0020		/* (RW) PWR wakeup clear register */
  #define PWR_WKUPCR_WKUPC      0x0000003F	/* Wakeup Pin Mask */
  #define PWR_WKUPCR_WKUPC1     0x00000001	/* Clear Wakeup Pin Flag 1 */
  #define PWR_WKUPCR_WKUPC2     0x00000002	/* Clear Wakeup Pin Flag 2 */
  #define PWR_WKUPCR_WKUPC3     0x00000004	/* Clear Wakeup Pin Flag 3 */
  #define PWR_WKUPCR_WKUPC4     0x00000008	/* Clear Wakeup Pin Flag 4 */
  #define PWR_WKUPCR_WKUPC5     0x00000010	/* Clear Wakeup Pin Flag 5 */
  #define PWR_WKUPCR_WKUPC6     0x00000020	/* Clear Wakeup Pin Flag 6 */
  #define PWR_WKUPCR_WKUPP      0x00003F00	/* Wakeup Pin Polarity mask*/
  #define PWR_WKUPCR_WKUPP_1    0x00000100
  #define PWR_WKUPCR_WKUPP_2    0x00000200
  #define PWR_WKUPCR_WKUPP_3    0x00000400
  #define PWR_WKUPCR_WKUPP_4    0x00000800
  #define PWR_WKUPCR_WKUPP_5    0x00001000
  #define PWR_WKUPCR_WKUPP_6    0x00002000
  #define PWR_WKUPCR_WKUPPUPD   0x0FFF0000	/* Wakeup Pin pull configuration mask*/
  #define PWR_WKUPCR_WKUPPUPD1  0x00030000	/* Wakeup Pin pull configuration for WKUP1 */
  #define PWR_WKUPCR_WKUPPUPD1_0  0x00010000
  #define PWR_WKUPCR_WKUPPUPD1_1  0x00020000
  #define PWR_WKUPCR_WKUPPUPD2  0x000C0000	/* Wakeup Pin pull configuration for WKUP2 */
  #define PWR_WKUPCR_WKUPPUPD2_0  0x00040000
  #define PWR_WKUPCR_WKUPPUPD2_1  0x00080000
  #define PWR_WKUPCR_WKUPPUPD3  0x00300000	/* Wakeup Pin pull configuration for WKUP3 */
  #define PWR_WKUPCR_WKUPPUPD3_0  0x00100000
  #define PWR_WKUPCR_WKUPPUPD3_1  0x00200000
  #define PWR_WKUPCR_WKUPPUPD4  0x00C00000	/* Wakeup Pin pull configuration for WKUP4 */
  #define PWR_WKUPCR_WKUPPUPD4_0  0x00400000
  #define PWR_WKUPCR_WKUPPUPD4_1  0x00800000
  #define PWR_WKUPCR_WKUPPUPD5  0x03000000	/* Wakeup Pin pull configuration for WKUP5 */
  #define PWR_WKUPCR_WKUPPUPD5_0  0x01000000
  #define PWR_WKUPCR_WKUPPUPD5_1  0x02000000
  #define PWR_WKUPCR_WKUPPUPD6  0x0C000000	/* Wakeup Pin pull configuration for WKUP6 */
  #define PWR_WKUPCR_WKUPPUPD6_0  0x04000000
  #define PWR_WKUPCR_WKUPPUPD6_1  0x08000000
#define TOFF_PWR_WKUPFR     0x0024		/* (RW) PWR wakeup flag register */
  #define PWR_WKUPFR_WKUPF1     0x00000001	/* Wakeup Pin Flag 1 */
  #define PWR_WKUPFR_WKUPF2     0x00000002	/* Wakeup Pin Flag 2 */
  #define PWR_WKUPFR_WKUPF3     0x00000004	/* Wakeup Pin Flag 3 */
  #define PWR_WKUPFR_WKUPF4     0x00000008	/* Wakeup Pin Flag 4 */
  #define PWR_WKUPFR_WKUPF5     0x00000010	/* Wakeup Pin Flag 5 */
  #define PWR_WKUPFR_WKUPF6     0x00000020	/* Wakeup Pin Flag 6 */
#define TOFF_PWR_MPUWKUPENR 0x0028		/* (RW) PWR wakeup enable and polarity register */
  #define PWR_MPUWKUPENR_WKUPEN 0x0000003F	/* Enable Wakeup and interrupt for CPU1 */
  #define PWR_MPUWKUPENR_WKUPEN_1 0x00000001
  #define PWR_MPUWKUPENR_WKUPEN_2 0x00000002
  #define PWR_MPUWKUPENR_WKUPEN_3 0x00000004
  #define PWR_MPUWKUPENR_WKUPEN_4 0x00000008
  #define PWR_MPUWKUPENR_WKUPEN_5 0x00000010
  #define PWR_MPUWKUPENR_WKUPEN_6 0x00000020
#define TOFF_PWR_MCUWKUPENR 0x002C		/* (RW) PWR wakeup enable and polarity register */
  #define PWR_MCUWKUPENR_WKUPEN 0x0000003F	/* Enable Wakeup and interrupt for CPU2 */
  #define PWR_MCUWKUPENR_WKUPEN1  0x00000001	/* Enable Wakeup WKUP1 pin and interrupt for CPU2 */
  #define PWR_MCUWKUPENR_WKUPEN2  0x00000002	/* Enable Wakeup WKUP2 pin and interrupt for CPU2 */
  #define PWR_MCUWKUPENR_WKUPEN3  0x00000004	/* Enable Wakeup WKUP3 pin and interrupt for CPU2 */
  #define PWR_MCUWKUPENR_WKUPEN4  0x00000008	/* Enable Wakeup WKUP4 pin and interrupt for CPU2 */
  #define PWR_MCUWKUPENR_WKUPEN5  0x00000010	/* Enable Wakeup WKUP5 pin and interrupt for CPU2 */
  #define PWR_MCUWKUPENR_WKUPEN6  0x00000020	/* Enable Wakeup WKUP6 pin and interrupt for CPU2 */
#define TOFF_PWR_VER        0x03F4		/* (R)  PWR IP version register */
  #define PWR_VER_MINREV        0x0000000F	/* Minor Revision number */
  #define PWR_VER_MAJREV        0x000000F0	/* Major Revision number */
#define TOFF_PWR_ID         0x03F8		/* (R)  PWR IP identification register */
#define TOFF_PWR_SID        0x03FC		/* (R)  PWR size ID register */


/*
 *  GENERAL PURPOSE I/O
 */
#define TADR_GPIOA_BASE     (MCU_AHB4_PERIPH_BASE + 0x2000)
#define TADR_GPIOB_BASE     (MCU_AHB4_PERIPH_BASE + 0x3000)
#define TADR_GPIOC_BASE     (MCU_AHB4_PERIPH_BASE + 0x4000)
#define TADR_GPIOD_BASE     (MCU_AHB4_PERIPH_BASE + 0x5000)
#define TADR_GPIOE_BASE     (MCU_AHB4_PERIPH_BASE + 0x6000)
#define TADR_GPIOF_BASE     (MCU_AHB4_PERIPH_BASE + 0x7000)
#define TADR_GPIOG_BASE     (MCU_AHB4_PERIPH_BASE + 0x8000)
#define TADR_GPIOH_BASE     (MCU_AHB4_PERIPH_BASE + 0x9000)
#define TADR_GPIOI_BASE     (MCU_AHB4_PERIPH_BASE + 0xA000)
#define TADR_GPIOJ_BASE     (MCU_AHB4_PERIPH_BASE + 0xB000)
#define TADR_GPIOK_BASE     (MCU_AHB4_PERIPH_BASE + 0xC000)
#define TADR_GPIOZ_BASE     (MPU_AHB5_PERIPH_BASE + 0x4000)
#define TOFF_GPIO_MODER     0x0000		/* (RW) GPIO port mode register */
  #define GPIO_MODER_MODER0       0x1
  #define GPIO_MODER_MODER1       0x2
  #define GPIO_MODER_MODER2       0x3
#define TOFF_GPIO_OTYPER    0x0004		/* (RW) GPIO port output type register */
  #define GPIO_OTYPER_OT          0x1
#define TOFF_GPIO_OSPEEDR   0x0008		/* (RW) GPIO port output speed register */
  #define GPIO_OSPEEDER_OSPEEDR0  0x1
  #define GPIO_OSPEEDER_OSPEEDR1  0x2
  #define GPIO_OSPEEDER_OSPEEDR2  0x3
#define TOFF_GPIO_PUPDR     0x000C		/* (RW) GPIO port pull-up/pull-down register */
  #define GPIO_PUPDR_PUPDR0       0x1
  #define GPIO_PUPDR_PUPDR1       0x2
  #define GPIO_PUPDR_PUPDR2       0x3
#define TOFF_GPIO_IDR       0x0010		/* (R)  GPIO port input data register */
#define TOFF_GPIO_ODR       0x0014		/* (RW) GPIO port output data register */
#define TOFF_GPIO_BSRR      0x0018		/* (RW) GPIO port bit set/reset register */
#define TOFF_GPIO_LCKR      0x001C		/* (RW) GPIO port configuration lock register */
#define TOFF_GPIO_AFR0      0x0020		/* (RW) GPIO alternate function registers */
#define TOFF_GPIO_AFR1      0x0024		/* (RW) GPIO alternate function registers */
#define TOFF_GPIO_BRR       0x0028		/* (RW) GPIO port bit reset register */
  #define GPIO_BRR_BR0            0x00000001
  #define GPIO_BRR_BR1            0x00000002
  #define GPIO_BRR_BR2            0x00000004
  #define GPIO_BRR_BR3            0x00000008
  #define GPIO_BRR_BR4            0x00000010
  #define GPIO_BRR_BR5            0x00000020
  #define GPIO_BRR_BR6            0x00000040
  #define GPIO_BRR_BR7            0x00000080
  #define GPIO_BRR_BR8            0x00000100
  #define GPIO_BRR_BR9            0x00000200
  #define GPIO_BRR_BR10           0x00000400
  #define GPIO_BRR_BR11           0x00000800
  #define GPIO_BRR_BR12           0x00001000
  #define GPIO_BRR_BR13           0x00002000
  #define GPIO_BRR_BR14           0x00004000
  #define GPIO_BRR_BR15           0x00008000
#define TOFF_GPIO_SECCFGR   0x0030		/* GPIO secure configuration register for GPIOZ */
  #define GPIO_SECCFGR_SEC0       0x00000001
  #define GPIO_SECCFGR_SEC1       0x00000002
  #define GPIO_SECCFGR_SEC2       0x00000004
  #define GPIO_SECCFGR_SEC3       0x00000008
  #define GPIO_SECCFGR_SEC4       0x00000010
  #define GPIO_SECCFGR_SEC5       0x00000020
  #define GPIO_SECCFGR_SEC6       0x00000040
  #define GPIO_SECCFGR_SEC7       0x00000080
#define TOFF_GPIO_HWCFGR10  0x03C8		/* (R)  GPIO hardware configuration register 10 */
  #define GPIO_HWCFGR10_AHB_IOP   0x0000000F	/* Bus interface configuration */
  #define GPIO_HWCFGR10_AHB_IOP_0 0x00000001
  #define GPIO_HWCFGR10_AHB_IOP_1 0x00000002
  #define GPIO_HWCFGR10_AHB_IOP_2 0x00000004
  #define GPIO_HWCFGR10_AHB_IOP_3 0x00000008
  #define GPIO_HWCFGR10_AF_SIZE   0x000000F0	/* Number of AF available for each I/O */
  #define GPIO_HWCFGR10_AF_SIZE_0 0x00000010
  #define GPIO_HWCFGR10_AF_SIZE_1 0x00000020
  #define GPIO_HWCFGR10_AF_SIZE_2 0x00000040
  #define GPIO_HWCFGR10_AF_SIZE_3 0x00000080
  #define GPIO_HWCFGR10_SPEED_CFG 0x00000F00	/* Number of speed lines for each I/O */
  #define GPIO_HWCFGR10_SPEED_CFG_0 0x00000100
  #define GPIO_HWCFGR10_SPEED_CFG_1 0x00000200
  #define GPIO_HWCFGR10_SPEED_CFG_2 0x00000400
  #define GPIO_HWCFGR10_SPEED_CFG_3 0x00000800
  #define GPIO_HWCFGR10_LOCK_CFG   0x0000F000	/* Lock mechanism activation */
  #define GPIO_HWCFGR10_LOCK_CFG_0 0x00001000
  #define GPIO_HWCFGR10_LOCK_CFG_1 0x00002000
  #define GPIO_HWCFGR10_LOCK_CFG_2 0x00004000
  #define GPIO_HWCFGR10_LOCK_CFG_3 0x00008000
  #define GPIO_HWCFGR10_SEC_CFG   0x000F0000	/* Security mechanism activation */
  #define GPIO_HWCFGR10_SEC_CFG_0 0x00010000
  #define GPIO_HWCFGR10_SEC_CFG_1 0x00020000
  #define GPIO_HWCFGR10_SEC_CFG_2 0x00040000
  #define GPIO_HWCFGR10_SEC_CFG_3 0x00080000
  #define GPIO_HWCFGR10_OR_CFG    0x00F00000	/* Option register configuration */
  #define GPIO_HWCFGR10_OR_CFG_0  0x00100000
  #define GPIO_HWCFGR10_OR_CFG_1  0x00200000
  #define GPIO_HWCFGR10_OR_CFG_2  0x00400000
  #define GPIO_HWCFGR10_OR_CFG_3  0x00800000
#define TOFF_GPIO_HWCFGR9   0x03CC		/* (R)  GPIO hardware configuration register 9 */
  #define GPIO_HWCFGR9_EN_IO_     0x0000FFFF	/* Presence granularity, each bit indicate the presence of the IO */
#define TOFF_GPIO_HWCFGR8   0x03D0		/* (R)  GPIO hardware configuration register 8 */
  #define GPIO_HWCFGR8_AF_PRIO8   0x0000000F	/* Indicate the priority AF for I/O8 (0 to F) */
  #define GPIO_HWCFGR8_AF_PRIO8_0 0x00000001
  #define GPIO_HWCFGR8_AF_PRIO8_1 0x00000002
  #define GPIO_HWCFGR8_AF_PRIO8_2 0x00000004
  #define GPIO_HWCFGR8_AF_PRIO8_3 0x00000008
  #define GPIO_HWCFGR8_AF_PRIO9   0x000000F0	/* Indicate the priority AF for I/O9 (0 to F) */
  #define GPIO_HWCFGR8_AF_PRIO9_0 0x00000010
  #define GPIO_HWCFGR8_AF_PRIO9_1 0x00000020
  #define GPIO_HWCFGR8_AF_PRIO9_2 0x00000040
  #define GPIO_HWCFGR8_AF_PRIO9_3 0x00000080
  #define GPIO_HWCFGR8_AF_PRIO10  0x00000F00	/* Indicate the priority AF for I/O10 (0 to F) */
  #define GPIO_HWCFGR8_AF_PRIO10_0 0x00000100
  #define GPIO_HWCFGR8_AF_PRIO10_1 0x00000200
  #define GPIO_HWCFGR8_AF_PRIO10_2 0x00000400
  #define GPIO_HWCFGR8_AF_PRIO10_3 0x00000800
  #define GPIO_HWCFGR8_AF_PRIO11  0x0000F000	/* Indicate the priority AF for I/O11 (0 to F) */
  #define GPIO_HWCFGR8_AF_PRIO11_0 0x00001000
  #define GPIO_HWCFGR8_AF_PRIO11_1 0x00002000
  #define GPIO_HWCFGR8_AF_PRIO11_2 0x00004000
  #define GPIO_HWCFGR8_AF_PRIO11_3 0x00008000
  #define GPIO_HWCFGR8_AF_PRIO12  0x000F0000	/* Indicate the priority AF for I/O12 (0 to F) */
  #define GPIO_HWCFGR8_AF_PRIO12_0 0x00010000
  #define GPIO_HWCFGR8_AF_PRIO12_1 0x00020000
  #define GPIO_HWCFGR8_AF_PRIO12_2 0x00040000
  #define GPIO_HWCFGR8_AF_PRIO12_3 0x00080000
  #define GPIO_HWCFGR8_AF_PRIO13  0x00F00000	/* Indicate the priority AF for I/O13 (0 to F) */
  #define GPIO_HWCFGR8_AF_PRIO13_0 0x00100000
  #define GPIO_HWCFGR8_AF_PRIO13_1 0x00200000
  #define GPIO_HWCFGR8_AF_PRIO13_2 0x00400000
  #define GPIO_HWCFGR8_AF_PRIO13_3 0x00800000
  #define GPIO_HWCFGR8_AF_PRIO14  0x0F000000	/* Indicate the priority AF for I/O14 (0 to F) */
  #define GPIO_HWCFGR8_AF_PRIO14_0 0x01000000
  #define GPIO_HWCFGR8_AF_PRIO14_1 0x02000000
  #define GPIO_HWCFGR8_AF_PRIO14_2 0x04000000
  #define GPIO_HWCFGR8_AF_PRIO14_3 0x08000000
  #define GPIO_HWCFGR8_AF_PRIO15  0xF0000000	/* Indicate the priority AF for I/O15 (0 to F) */
  #define GPIO_HWCFGR8_AF_PRIO15_0 0x10000000
  #define GPIO_HWCFGR8_AF_PRIO15_1 0x20000000
  #define GPIO_HWCFGR8_AF_PRIO15_2 0x40000000
  #define GPIO_HWCFGR8_AF_PRIO15_3 0x80000000
#define TOFF_GPIO_HWCFGR7   0x03D4		/* (R)  GPIO hardware configuration register 7 */
  #define GPIO_HWCFGR7_AF_PRIO0   0x0000000F	/* Indicate the priority AF for I/O0 (0 to F) */
  #define GPIO_HWCFGR7_AF_PRIO0_0 0x00000001
  #define GPIO_HWCFGR7_AF_PRIO0_1 0x00000002
  #define GPIO_HWCFGR7_AF_PRIO0_2 0x00000004
  #define GPIO_HWCFGR7_AF_PRIO0_3 0x00000008
  #define GPIO_HWCFGR7_AF_PRIO1   0x000000F0	/* Indicate the priority AF for I/O1 (0 to F) */
  #define GPIO_HWCFGR7_AF_PRIO1_0 0x00000010
  #define GPIO_HWCFGR7_AF_PRIO1_1 0x00000020
  #define GPIO_HWCFGR7_AF_PRIO1_2 0x00000040
  #define GPIO_HWCFGR7_AF_PRIO1_3 0x00000080
  #define GPIO_HWCFGR7_AF_PRIO2   0x00000F00	/* Indicate the priority AF for I/O2 (0 to F) */
  #define GPIO_HWCFGR7_AF_PRIO2_0 0x00000100
  #define GPIO_HWCFGR7_AF_PRIO2_1 0x00000200
  #define GPIO_HWCFGR7_AF_PRIO2_2 0x00000400
  #define GPIO_HWCFGR7_AF_PRIO2_3 0x00000800
  #define GPIO_HWCFGR7_AF_PRIO3   0x0000F000	/* Indicate the priority AF for I/O3 (0 to F) */
  #define GPIO_HWCFGR7_AF_PRIO3_0 0x00001000
  #define GPIO_HWCFGR7_AF_PRIO3_1 0x00002000
  #define GPIO_HWCFGR7_AF_PRIO3_2 0x00004000
  #define GPIO_HWCFGR7_AF_PRIO3_3 0x00008000
  #define GPIO_HWCFGR7_AF_PRIO4   0x000F0000	/* Indicate the priority AF for I/O4 (0 to F) */
  #define GPIO_HWCFGR7_AF_PRIO4_0 0x00010000
  #define GPIO_HWCFGR7_AF_PRIO4_1 0x00020000
  #define GPIO_HWCFGR7_AF_PRIO4_2 0x00040000
  #define GPIO_HWCFGR7_AF_PRIO4_3 0x00080000
  #define GPIO_HWCFGR7_AF_PRIO5   0x00F00000	/* Indicate the priority AF for I/O5 (0 to F) */
  #define GPIO_HWCFGR7_AF_PRIO5_0 0x00100000
  #define GPIO_HWCFGR7_AF_PRIO5_1 0x00200000
  #define GPIO_HWCFGR7_AF_PRIO5_2 0x00400000
  #define GPIO_HWCFGR7_AF_PRIO5_3 0x00800000
  #define GPIO_HWCFGR7_AF_PRIO6   0x0F000000	/* Indicate the priority AF for I/O6 (0 to F) */
  #define GPIO_HWCFGR7_AF_PRIO6_0 0x01000000
  #define GPIO_HWCFGR7_AF_PRIO6_1 0x02000000
  #define GPIO_HWCFGR7_AF_PRIO6_2 0x04000000
  #define GPIO_HWCFGR7_AF_PRIO6_3 0x08000000
  #define GPIO_HWCFGR7_AF_PRIO7   0xF0000000	/* Indicate the priority AF for I/O7 (0 to F) */
  #define GPIO_HWCFGR7_AF_PRIO7_0 0x10000000
  #define GPIO_HWCFGR7_AF_PRIO7_1 0x20000000
  #define GPIO_HWCFGR7_AF_PRIO7_2 0x40000000
  #define GPIO_HWCFGR7_AF_PRIO7_3 0x80000000
#define TOFF_GPIO_HWCFGR6   0x03D8		/* (R)  GPIO hardware configuration register 6 */
  #define GPIO_HWCFGR6_MODER_RES  0xFFFFFFFF	/* MODER register reset value */
#define TOFF_GPIO_HWCFGR5   0x03DC		/* (R)  GPIO hardware configuration register 5 */
  #define GPIO_HWCFGR5_PUPDR_RES  0xFFFFFFFF	/* Pull-up / pull-down register reset value */
#define TOFF_GPIO_HWCFGR4   0x03E0		/* (R)  GPIO hardware configuration register 4 */
  #define GPIO_HWCFGR4_OSPEED_RES 0xFFFFFFFF	/* OSPEED register reset value */
#define TOFF_GPIO_HWCFGR3   0x03E4		/* (R)  GPIO hardware configuration register 3 */
  #define GPIO_HWCFGR3_ODR_RES    0x0000FFFF	/* Output data register reset value */
  #define GPIO_HWCFGR3_OTYPER_RES 0xFFFF0000	/* Output type register reset value */
#define TOFF_GPIO_HWCFGR2   0x03E8		/* (R)  GPIO hardware configuration register 2 */
  #define GPIO_HWCFGR2_AFRL_RES   0xFFFFFFFF	/* AF register low reset value */
#define TOFF_GPIO_HWCFGR1   0x03EC		/* (R)  GPIO hardware configuration register 1 */
  #define GPIO_HWCFGR1_AFRH_RES   0xFFFFFFFF	/* AF register high reset value */
#define TOFF_GPIO_HWCFGR0   0x03F0		/* (R)  GPIO hardware configuration register 0 */
  #define GPIO_HWCFGR0_OR_RES     0x0000FFFF	/* Option register reset value */
#define TOFF_GPIO_VERR      0x03F4		/* (R)  GPIO version register */
  #define GPIO_VERR_MINREV      0x0000000F	/* Minor Revision number */
  #define GPIO_VERR_MAJREV      0x000000F0	/* Major Revision number */
#define TOFF_GPIO_IPIDR     0x03F8		/* (R)  GPIO identification register */
#define TOFF_GPIO_SIDR      0x03FC		/* (R)  GPIO size identification register */


/*
 *  EXTERNAL INTERRUPT/EVENT CONTROLLER
 */
#define TADR_EXTI_BASE      (MCU_AHB4_PERIPH_BASE + 0xD000)

#define TOFF_EXTI_RTSR1     0x0000		/* (RW) EXTI Rising trigger selection register */
  #define EXTI_RTSR1_TR0        0x00000001	/* Rising trigger event configuration bit of line 0 */
  #define EXTI_RTSR1_TR1        0x00000002	/* Rising trigger event configuration bit of line 1 */
  #define EXTI_RTSR1_TR2        0x00000004	/* Rising trigger event configuration bit of line 2 */
  #define EXTI_RTSR1_TR3        0x00000008	/* Rising trigger event configuration bit of line 3 */
  #define EXTI_RTSR1_TR4        0x00000010	/* Rising trigger event configuration bit of line 4 */
  #define EXTI_RTSR1_TR5        0x00000020	/* Rising trigger event configuration bit of line 5 */
  #define EXTI_RTSR1_TR6        0x00000040	/* Rising trigger event configuration bit of line 6 */
  #define EXTI_RTSR1_TR7        0x00000080	/* Rising trigger event configuration bit of line 7 */
  #define EXTI_RTSR1_TR8        0x00000100	/* Rising trigger event configuration bit of line 8 */
  #define EXTI_RTSR1_TR9        0x00000200	/* Rising trigger event configuration bit of line 9 */
  #define EXTI_RTSR1_TR10       0x00000400	/* Rising trigger event configuration bit of line 10 */
  #define EXTI_RTSR1_TR11       0x00000800	/* Rising trigger event configuration bit of line 11 */
  #define EXTI_RTSR1_TR12       0x00001000	/* Rising trigger event configuration bit of line 12 */
  #define EXTI_RTSR1_TR13       0x00002000	/* Rising trigger event configuration bit of line 13 */
  #define EXTI_RTSR1_TR14       0x00004000	/* Rising trigger event configuration bit of line 14 */
  #define EXTI_RTSR1_TR15       0x00008000	/* Rising trigger event configuration bit of line 15 */
  #define EXTI_RTSR1_TR16       0x00010000	/* Rising trigger event configuration bit of line 16 */
  #define EXTI_RTSR1_TR17       0x00020000	/* Rising trigger event configuration bit of line 17 */
  #define EXTI_RTSR1_TR18       0x00040000	/* Rising trigger event configuration bit of line 18 */
  #define EXTI_RTSR1_TR19       0x00080000	/* Rising trigger event configuration bit of line 19 */
  #define EXTI_RTSR1_TR20       0x00100000	/* Rising trigger event configuration bit of line 20 */
  #define EXTI_RTSR1_TR21       0x00200000	/* Rising trigger event configuration bit of line 21 */
#define TOFF_EXTI_FTSR1     0x0004		/* (RW) EXTI Falling trigger selection register */
  #define EXTI_FTSR1_TR0        0x00000001	/* Falling trigger event configuration bit of line 0 */
  #define EXTI_FTSR1_TR1        0x00000002	/* Falling trigger event configuration bit of line 1 */
  #define EXTI_FTSR1_TR2        0x00000004	/* Falling trigger event configuration bit of line 2 */
  #define EXTI_FTSR1_TR3        0x00000008	/* Falling trigger event configuration bit of line 3 */
  #define EXTI_FTSR1_TR4        0x00000010	/* Falling trigger event configuration bit of line 4 */
  #define EXTI_FTSR1_TR5        0x00000020	/* Falling trigger event configuration bit of line 5 */
  #define EXTI_FTSR1_TR6        0x00000040	/* Falling trigger event configuration bit of line 6 */
  #define EXTI_FTSR1_TR7        0x00000080	/* Falling trigger event configuration bit of line 7 */
  #define EXTI_FTSR1_TR8        0x00000100	/* Falling trigger event configuration bit of line 8 */
  #define EXTI_FTSR1_TR9        0x00000200	/* Falling trigger event configuration bit of line 9 */
  #define EXTI_FTSR1_TR10       0x00000400	/* Falling trigger event configuration bit of line 10 */
  #define EXTI_FTSR1_TR11       0x00000800	/* Falling trigger event configuration bit of line 11 */
  #define EXTI_FTSR1_TR12       0x00001000	/* Falling trigger event configuration bit of line 12 */
  #define EXTI_FTSR1_TR13       0x00002000	/* Falling trigger event configuration bit of line 13 */
  #define EXTI_FTSR1_TR14       0x00004000	/* Falling trigger event configuration bit of line 14 */
  #define EXTI_FTSR1_TR15       0x00008000	/* Falling trigger event configuration bit of line 15 */
  #define EXTI_FTSR1_TR16       0x00010000	/* Falling trigger event configuration bit of line 16 */
  #define EXTI_FTSR1_TR17       0x00020000	/* Falling trigger event configuration bit of line 17 */
  #define EXTI_FTSR1_TR18       0x00040000	/* Falling trigger event configuration bit of line 18 */
  #define EXTI_FTSR1_TR19       0x00080000	/* Falling trigger event configuration bit of line 19 */
  #define EXTI_FTSR1_TR20       0x00100000	/* Falling trigger event configuration bit of line 20 */
  #define EXTI_FTSR1_TR21       0x00200000	/* Falling trigger event configuration bit of line 21 */
#define TOFF_EXTI_SWIER1    0x0008		/* (RW) EXTI Software interrupt event register */
  #define EXTI_SWIER1_SWIER0    0x00000001	/* Software Interrupt on line 0 */
  #define EXTI_SWIER1_SWIER1    0x00000002	/* Software Interrupt on line 1 */
  #define EXTI_SWIER1_SWIER2    0x00000004	/* Software Interrupt on line 2 */
  #define EXTI_SWIER1_SWIER3    0x00000008	/* Software Interrupt on line 3 */
  #define EXTI_SWIER1_SWIER4    0x00000010	/* Software Interrupt on line 4 */
  #define EXTI_SWIER1_SWIER5    0x00000020	/* Software Interrupt on line 5 */
  #define EXTI_SWIER1_SWIER6    0x00000040	/* Software Interrupt on line 6 */
  #define EXTI_SWIER1_SWIER7    0x00000080	/* Software Interrupt on line 7 */
  #define EXTI_SWIER1_SWIER8    0x00000100	/* Software Interrupt on line 8 */
  #define EXTI_SWIER1_SWIER9    0x00000200	/* Software Interrupt on line 9 */
  #define EXTI_SWIER1_SWIER10   0x00000400	/* Software Interrupt on line 10 */
  #define EXTI_SWIER1_SWIER11   0x00000800	/* Software Interrupt on line 11 */
  #define EXTI_SWIER1_SWIER12   0x00001000	/* Software Interrupt on line 12 */
  #define EXTI_SWIER1_SWIER13   0x00002000	/* Software Interrupt on line 13 */
  #define EXTI_SWIER1_SWIER14   0x00004000	/* Software Interrupt on line 14 */
  #define EXTI_SWIER1_SWIER15   0x00008000	/* Software Interrupt on line 15 */
  #define EXTI_SWIER1_SWIER16   0x00010000	/* Software Interrupt on line 16 */
  #define EXTI_SWIER1_SWIER17   0x00020000	/* Software Interrupt on line 17 */
  #define EXTI_SWIER1_SWIER18   0x00040000	/* Software Interrupt on line 18 */
  #define EXTI_SWIER1_SWIER19   0x00080000	/* Software Interrupt on line 19 */
  #define EXTI_SWIER1_SWIER20   0x00100000	/* Software Interrupt on line 20 */
  #define EXTI_SWIER1_SWIER21   0x00200000	/* Software Interrupt on line 21 */
#define TOFF_EXTI_RPR1      0x000C		/* (RW) EXTI Rising Edge Pending mask register */
  #define EXTI_PR1_PR0          0x00000001	/* Pending bit for line 0 */
  #define EXTI_PR1_PR1          0x00000002	/* Pending bit for line 1 */
  #define EXTI_PR1_PR2          0x00000004	/* Pending bit for line 2 */
  #define EXTI_PR1_PR3          0x00000008	/* Pending bit for line 3 */
  #define EXTI_PR1_PR4          0x00000010	/* Pending bit for line 4 */
  #define EXTI_PR1_PR5          0x00000020	/* Pending bit for line 5 */
  #define EXTI_PR1_PR6          0x00000040	/* Pending bit for line 6 */
  #define EXTI_PR1_PR7          0x00000080	/* Pending bit for line 7 */
  #define EXTI_PR1_PR8          0x00000100	/* Pending bit for line 8 */
  #define EXTI_PR1_PR9          0x00000200	/* Pending bit for line 9 */
  #define EXTI_PR1_PR10         0x00000400	/* Pending bit for line 10 */
  #define EXTI_PR1_PR11         0x00000800	/* Pending bit for line 11 */
  #define EXTI_PR1_PR12         0x00001000	/* Pending bit for line 12 */
  #define EXTI_PR1_PR13         0x00002000	/* Pending bit for line 13 */
  #define EXTI_PR1_PR14         0x00004000	/* Pending bit for line 14 */
  #define EXTI_PR1_PR15         0x00008000	/* Pending bit for line 15 */
  #define EXTI_PR1_PR16         0x00010000	/* Pending bit for line 16 */
#define TOFF_EXTI_FPR1      0x0010		/* (RW) EXTI Falling Edge Pending mask register */
#define TOFF_EXTI_TZENR1    0x0014		/* (RW) EXTI Trust Zone enable register */
#define TOFF_EXTI_RTSR2     0x0020		/* (RW) EXTI Rising trigger selection register */
  #define EXTI_RTSR2_TR49       0x00020000	/* Rising trigger event configuration bit of line 49 */
  #define EXTI_RTSR2_TR51       0x00080000	/* Rising trigger event configuration bit of line 51 */
#define TOFF_EXTI_FTSR2     0x0024		/* (RW) EXTI Falling trigger selection register */
  #define EXTI_FTSR2_TR49       0x00020000	/* Falling trigger event configuration bit of line 49 */
  #define EXTI_FTSR2_TR51       0x00080000	/* Falling trigger event configuration bit of line 51 */
#define TOFF_EXTI_SWIER2    0x0028		/* (RW) EXTI Software interrupt event register */
  #define EXTI_SWIER2_SWIER49   0x00020000	/* Software Interrupt on line 49 */
  #define EXTI_SWIER2_SWIER51   0x00080000	/* Software Interrupt on line 51 */
#define TOFF_EXTI_RPR2      0x002C		/* (RW) EXTI Rising Edge Pending mask register */
#define TOFF_EXTI_FPR2      0x0030		/* (RW) EXTI Falling Edge Pending mask register */
#define TOFF_EXTI_TZENR2    0x0034		/* (RW) EXTI Trust Zone enable register */
#define TOFF_EXTI_RTSR3     0x0040		/* (RW) EXTI Rising trigger selection register */
  #define EXTI_RTSR3_TR85       0x00200000	/* Rising trigger event configuration bit of line 85 */
  #define EXTI_RTSR3_TR86       0x00400000	/* Rising trigger event configuration bit of line 86 */
#define TOFF_EXTI_FTSR3     0x0044		/* (RW) EXTI Falling trigger selection register */
  #define EXTI_FTSR3_TR85       0x00200000	/* Falling trigger event configuration bit of line 85 */
  #define EXTI_FTSR3_TR86       0x00400000	/* Falling trigger event configuration bit of line 86 */
#define TOFF_EXTI_SWIER3    0x0048		/* (RW) EXTI Software interrupt event register */
  #define EXTI_SWIER3_SWIER85   0x00200000	/* Software Interrupt on line 85 */
  #define EXTI_SWIER3_SWIER86   0x00400000	/* Software Interrupt on line 86 */
#define TOFF_EXTI_RPR3      0x004C		/* (RW) EXTI Rising Edge Pending mask register */
  #define EXTI_PR3_PR65         0x00000002	/* Pending bit for line 65 */
  #define EXTI_PR3_PR66         0x00000004	/* Pending bit for line 66 */
  #define EXTI_PR3_PR68         0x00000010	/* Pending bit for line 68 */
  #define EXTI_PR3_PR73         0x00000200	/* Pending bit for line 73 */
  #define EXTI_PR3_PR74         0x00000400	/* Pending bit for line 74 */
#define TOFF_EXTI_FPR3      0x0050		/* (RW) EXTI Falling Edge Pending mask register */
#define TOFF_EXTI_TZENR3    0x0054		/* (RW) EXTI Trust Zone enable register */
#define TOFF_EXTI_EXTICR    0x0060		/* (RW) EXTI Configuration Register mask register[0-3]           */
#define TOFF_EXTI_C1IMR1    0x0080		/* (RW) EXTI wakeup with interrupt mask register for cpu1 [31:0] */
#define TOFF_EXTI_C1EMR1    0x0084		/* (RW) EXTI wakeup with event mask register for cpu1 [31:0] */
#define TOFF_EXTI_C1IMR2    0x0090		/* (RW) EXTI wakeup with interrupt mask register for cpu1 [31:0] */
#define TOFF_EXTI_C1EMR2    0x0094		/* (RW) EXTI wakeup with event mask register for cpu1 [31:0] */
#define TOFF_EXTI_C1IMR3    0x00A0		/* (RW) EXTI wakeup with interrupt mask register for cpu1 [31:0] */
#define TOFF_EXTI_C1EMR3    0x00A4		/* (RW) EXTI wakeup with event mask register for cpu1 [31:0] */
#define TOFF_EXTI_C2IMR1    0x00C0		/* (RW) EXTI wakeup with interrupt mask register for cpu2 [31:0] */
#define TOFF_EXTI_C2EMR1    0x00C4		/* (RW) EXTI wakeup with event mask register for cpu2 [31:0] */
#define TOFF_EXTI_C2IMR2    0x00D0		/* (RW) EXTI wakeup with interrupt mask register for cpu2 [31:0] */
#define TOFF_EXTI_C2EMR2    0x00D4		/* (RW) EXTI wakeup with event mask register for cpu2 [31:0] */
#define TOFF_EXTI_C2IMR3    0x00E0		/* (RW) EXTI wakeup with interrupt mask register for cpu2 [31:0] */
#define TOFF_EXTI_C2EMR3    0x00E4		/* (RW) EXTI wakeup with event mask register for cpu2 [31:0] */
#define TOFF_EXTI_HWCFGR13  0x03C0		/* (RW) EXTI HW Configuration Register 13 */
#define TOFF_EXTI_HWCFGR12  0x03C4		/* (RW) EXTI HW Configuration Register 12 */
#define TOFF_EXTI_HWCFGR11  0x03C8		/* (RW) EXTI HW Configuration Register 11 */
#define TOFF_EXTI_HWCFGR10  0x03CC		/* (RW) EXTI HW Configuration Register 10 */
#define TOFF_EXTI_HWCFGR9   0x03D0		/* (RW) EXTI HW Configuration Register 9 */
#define TOFF_EXTI_HWCFGR8   0x03D4		/* (RW) EXTI HW Configuration Register 8 */
#define TOFF_EXTI_HWCFGR7   0x03D8		/* (RW) EXTI HW Configuration Register 7 */
#define TOFF_EXTI_HWCFGR6   0x03DC		/* (RW) EXTI HW Configuration Register 6 */
#define TOFF_EXTI_HWCFGR5   0x03E0		/* (RW) EXTI HW Configuration Register 5 */
#define TOFF_EXTI_HWCFGR4   0x03E4		/* (RW) EXTI HW Configuration Register 4 */
#define TOFF_EXTI_HWCFGR3   0x03E8		/* (RW) EXTI HW Configuration Register 3 */
#define TOFF_EXTI_HWCFGR2   0x03EC		/* (RW) EXTI HW Configuration Register 2 */
#define TOFF_EXTI_HWCFGR1   0x03F0		/* (RW) EXTI HW Configuration Register 1 */
  #define EXTI_HWCFGR1_NBEVENTS 0x000000FF	/* Number of EVENT */
  #define EXTI_HWCFGR1_NBCPUS   0x00000F00	/* Number of CPUs */
  #define EXTI_HWCFGR1_CPUEVTEN 0x0000F000	/* CPU(m) event output enable */
  #define EXTI_HWCFGR1_NBIOPORT 0x00FF0000	/* Number of IO ports on EXTI */
#define TOFF_EXTI_VERR      0x03F4		/* (RW) EXTI Version Register */
  #define EXTI_VERR_MINREV      0x0000000F	/* Minor Revision number */
  #define EXTI_VERR_MAJREV      0x000000F0	/* Major Revision number */
#define TOFF_EXTI_IPIDR     0x03F8		/* (RW) EXTI Identification Register */
#define TOFF_EXTI_SIDR      0x03FC		/* (RW) EXTI Size ID Register */

#define TADR_EXTI_C1_BASE   (MCU_AHB4_PERIPH_BASE + 0xD080)
#define TADR_EXTI_C2_BASE   (MCU_AHB4_PERIPH_BASE + 0xD0C0)
#define TOFF_EXTI_C_IMR1    0x0000		/* (RW) EXTI Interrupt mask register */
  #define EXTI_IMR1_IM0         0x00000001	/* Interrupt Mask on line 0 */
  #define EXTI_IMR1_IM1         0x00000002	/* Interrupt Mask on line 1 */
  #define EXTI_IMR1_IM2         0x00000004	/* Interrupt Mask on line 2 */
  #define EXTI_IMR1_IM3         0x00000008	/* Interrupt Mask on line 3 */
  #define EXTI_IMR1_IM4         0x00000010	/* Interrupt Mask on line 4 */
  #define EXTI_IMR1_IM5         0x00000020	/* Interrupt Mask on line 5 */
  #define EXTI_IMR1_IM6         0x00000040	/* Interrupt Mask on line 6 */
  #define EXTI_IMR1_IM7         0x00000080	/* Interrupt Mask on line 7 */
  #define EXTI_IMR1_IM8         0x00000100	/* Interrupt Mask on line 8 */
  #define EXTI_IMR1_IM9         0x00000200	/* Interrupt Mask on line 9 */
  #define EXTI_IMR1_IM10        0x00000400	/* Interrupt Mask on line 10 */
  #define EXTI_IMR1_IM11        0x00000800	/* Interrupt Mask on line 11 */
  #define EXTI_IMR1_IM12        0x00001000	/* Interrupt Mask on line 12 */
  #define EXTI_IMR1_IM13        0x00002000	/* Interrupt Mask on line 13 */
  #define EXTI_IMR1_IM14        0x00004000	/* Interrupt Mask on line 14 */
  #define EXTI_IMR1_IM15        0x00008000	/* Interrupt Mask on line 15 */
  #define EXTI_IMR1_IM16        0x00010000	/* Interrupt Mask on line 16 */
  #define EXTI_IMR1_IM17        0x00020000	/* Interrupt Mask on line 17 */
  #define EXTI_IMR1_IM18        0x00040000	/* Interrupt Mask on line 18 */
  #define EXTI_IMR1_IM19        0x00080000	/* Interrupt Mask on line 19 */
  #define EXTI_IMR1_IM20        0x00100000	/* Interrupt Mask on line 20 */
  #define EXTI_IMR1_IM21        0x00200000	/* Interrupt Mask on line 21 */
  #define EXTI_IMR1_IM22        0x00400000	/* Interrupt Mask on line 22 */
  #define EXTI_IMR1_IM23        0x00800000	/* Interrupt Mask on line 23 */
  #define EXTI_IMR1_IM24        0x01000000	/* Interrupt Mask on line 24 */
  #define EXTI_IMR1_IM25        0x02000000	/* Interrupt Mask on line 25 */
  #define EXTI_IMR1_IM26        0x04000000	/* Interrupt Mask on line 26 */
  #define EXTI_IMR1_IM27        0x08000000	/* Interrupt Mask on line 27 */
  #define EXTI_IMR1_IM28        0x10000000	/* Interrupt Mask on line 28 */
  #define EXTI_IMR1_IM29        0x20000000	/* Interrupt Mask on line 29 */
  #define EXTI_IMR1_IM30        0x40000000	/* Interrupt Mask on line 30 */
  #define EXTI_IMR1_IM31        0x80000000	/* Interrupt Mask on line 31 */
#define TOFF_EXTI_C_EMR1    0x0004		/* (RW) EXTI Event mask register */
  #define EXTI_EMR1_EM0         0x00000001	/* Event Mask on line 0 */
  #define EXTI_EMR1_EM1         0x00000002	/* Event Mask on line 1 */
  #define EXTI_EMR1_EM2         0x00000004	/* Event Mask on line 2 */
  #define EXTI_EMR1_EM3         0x00000008	/* Event Mask on line 3 */
  #define EXTI_EMR1_EM4         0x00000010	/* Event Mask on line 4 */
  #define EXTI_EMR1_EM5         0x00000020	/* Event Mask on line 5 */
  #define EXTI_EMR1_EM6         0x00000040	/* Event Mask on line 6 */
  #define EXTI_EMR1_EM7         0x00000080	/* Event Mask on line 7 */
  #define EXTI_EMR1_EM8         0x00000100	/* Event Mask on line 8 */
  #define EXTI_EMR1_EM9         0x00000200	/* Event Mask on line 9 */
  #define EXTI_EMR1_EM10        0x00000400	/* Event Mask on line 10 */
  #define EXTI_EMR1_EM11        0x00000800	/* Event Mask on line 11 */
  #define EXTI_EMR1_EM12        0x00001000	/* Event Mask on line 12 */
  #define EXTI_EMR1_EM13        0x00002000	/* Event Mask on line 13 */
  #define EXTI_EMR1_EM14        0x00004000	/* Event Mask on line 14 */
  #define EXTI_EMR1_EM15        0x00008000	/* Event Mask on line 15 */
  #define EXTI_EMR1_EM16        0x00010000	/* Event Mask on line 16 */
  #define EXTI_EMR1_EM17        0x00020000	/* Event Mask on line 17 */
  #define EXTI_EMR1_EM18        0x00040000	/* Event Mask on line 18 */
  #define EXTI_EMR1_EM20        0x00100000	/* Event Mask on line 20 */
  #define EXTI_EMR1_EM21        0x00200000	/* Event Mask on line 21 */
  #define EXTI_EMR1_EM22        0x00400000	/* Event Mask on line 22 */
  #define EXTI_EMR1_EM23        0x00800000	/* Event Mask on line 23 */
  #define EXTI_EMR1_EM24        0x01000000	/* Event Mask on line 24 */
  #define EXTI_EMR1_EM25        0x02000000	/* Event Mask on line 25 */
  #define EXTI_EMR1_EM26        0x04000000	/* Event Mask on line 26 */
  #define EXTI_EMR1_EM27        0x08000000	/* Event Mask on line 27 */
  #define EXTI_EMR1_EM28        0x10000000	/* Event Mask on line 28 */
  #define EXTI_EMR1_EM29        0x20000000	/* Event Mask on line 29 */
  #define EXTI_EMR1_EM30        0x40000000	/* Event Mask on line 30 */
  #define EXTI_EMR1_EM31        0x80000000	/* Event Mask on line 31 */
#define TOFF_EXTI_C_IMR2    0x0010		/* (RW) EXTI Interrupt mask register */
  #define EXTI_IMR2_IM32        0x00000001	/* Interrupt Mask on line 32 */
  #define EXTI_IMR2_IM33        0x00000002	/* Interrupt Mask on line 33 */
  #define EXTI_IMR2_IM34        0x00000004	/* Interrupt Mask on line 34 */
  #define EXTI_IMR2_IM35        0x00000008	/* Interrupt Mask on line 35 */
  #define EXTI_IMR2_IM36        0x00000010	/* Interrupt Mask on line 36 */
  #define EXTI_IMR2_IM37        0x00000020	/* Interrupt Mask on line 37 */
  #define EXTI_IMR2_IM38        0x00000040	/* Interrupt Mask on line 38 */
  #define EXTI_IMR2_IM39        0x00000080	/* Interrupt Mask on line 39 */
  #define EXTI_IMR2_IM40        0x00000100	/* Interrupt Mask on line 40 */
  #define EXTI_IMR2_IM41        0x00000200	/* Interrupt Mask on line 41 */
  #define EXTI_IMR2_IM42        0x00000400	/* Interrupt Mask on line 42 */
  #define EXTI_IMR2_IM43        0x00000800	/* Interrupt Mask on line 43 */
  #define EXTI_IMR2_IM44        0x00001000	/* Interrupt Mask on line 44 */
  #define EXTI_IMR2_IM45        0x00002000	/* Interrupt Mask on line 45 */
  #define EXTI_IMR2_IM46        0x00004000	/* Interrupt Mask on line 46 */
  #define EXTI_IMR2_IM47        0x00008000	/* Interrupt Mask on line 47 */
  #define EXTI_IMR2_IM48        0x00010000	/* Interrupt Mask on line 48 */
  #define EXTI_IMR2_IM49        0x00020000	/* Interrupt Mask on line 49 */
  #define EXTI_IMR2_IM50        0x00040000	/* Interrupt Mask on line 50 */
  #define EXTI_IMR2_IM51        0x00080000	/* Interrupt Mask on line 51 */
  #define EXTI_IMR2_IM52        0x00100000	/* Interrupt Mask on line 52 */
  #define EXTI_IMR2_IM53        0x00200000	/* Interrupt Mask on line 53 */
  #define EXTI_IMR2_IM54        0x00400000	/* Interrupt Mask on line 54 */
  #define EXTI_IMR2_IM55        0x00800000	/* Interrupt Mask on line 55 */
  #define EXTI_IMR2_IM56        0x01000000	/* Interrupt Mask on line 56 */
  #define EXTI_IMR2_IM57        0x02000000	/* Interrupt Mask on line 57 */
  #define EXTI_IMR2_IM58        0x04000000	/* Interrupt Mask on line 58 */
  #define EXTI_IMR2_IM59        0x08000000	/* Interrupt Mask on line 59 */
  #define EXTI_IMR2_IM60        0x10000000	/* Interrupt Mask on line 60 */
  #define EXTI_IMR2_IM61        0x20000000	/* Interrupt Mask on line 61 */
  #define EXTI_IMR2_IM62        0x40000000	/* Interrupt Mask on line 62 */
  #define EXTI_IMR2_IM63        0x80000000	/* Interrupt Mask on line 63 */
#define TOFF_EXTI_C_EMR2    0x0014		/* (RW) EXTI Event mask register */
  #define EXTI_EMR2_EM32        0x00000001	/* Event Mask on line 32*/
  #define EXTI_EMR2_EM33        0x00000002	/* Event Mask on line 33*/
  #define EXTI_EMR2_EM34        0x00000004	/* Event Mask on line 34*/
  #define EXTI_EMR2_EM35        0x00000008	/* Event Mask on line 35*/
  #define EXTI_EMR2_EM36        0x00000010	/* Event Mask on line 36*/
  #define EXTI_EMR2_EM37        0x00000020	/* Event Mask on line 37*/
  #define EXTI_EMR2_EM38        0x00000040	/* Event Mask on line 38*/
  #define EXTI_EMR2_EM39        0x00000080	/* Event Mask on line 39*/
  #define EXTI_EMR2_EM40        0x00000100	/* Event Mask on line 40*/
  #define EXTI_EMR2_EM41        0x00000200	/* Event Mask on line 41*/
  #define EXTI_EMR2_EM42        0x00000400	/* Event Mask on line 42 */
  #define EXTI_EMR2_EM43        0x00000800	/* Event Mask on line 43 */
  #define EXTI_EMR2_EM44        0x00001000	/* Event Mask on line 44 */
  #define EXTI_EMR2_EM45        0x00002000	/* Event Mask on line 45 */
  #define EXTI_EMR2_EM46        0x00004000	/* Event Mask on line 46 */
  #define EXTI_EMR2_EM47        0x00008000	/* Event Mask on line 47 */
  #define EXTI_EMR2_EM48        0x00010000	/* Event Mask on line 48 */
  #define EXTI_EMR2_EM49        0x00020000	/* Event Mask on line 49 */
  #define EXTI_EMR2_EM50        0x00040000	/* Event Mask on line 50 */
  #define EXTI_EMR2_EM51        0x00080000	/* Event Mask on line 51 */
  #define EXTI_EMR2_EM52        0x00100000	/* Event Mask on line 52 */
  #define EXTI_EMR2_EM53        0x00200000	/* Event Mask on line 53 */
  #define EXTI_EMR2_EM54        0x00400000	/* Event Mask on line 54 */
  #define EXTI_EMR2_EM55        0x00800000	/* Event Mask on line 55 */
  #define EXTI_EMR2_EM56        0x01000000	/* Event Mask on line 56 */
  #define EXTI_EMR2_EM57        0x02000000	/* Event Mask on line 57 */
  #define EXTI_EMR2_EM58        0x04000000	/* Event Mask on line 58 */
  #define EXTI_EMR2_EM59        0x08000000	/* Event Mask on line 59 */
  #define EXTI_EMR2_EM60        0x10000000	/* Event Mask on line 60 */
  #define EXTI_EMR2_EM61        0x20000000	/* Event Mask on line 61 */
  #define EXTI_EMR2_EM62        0x40000000	/* Event Mask on line 62 */
  #define EXTI_EMR2_EM63        0x80000000	/* Event Mask on line 63 */
#define TOFF_EXTI_C_IMR3    0x0020		/* (RW) EXTI Interrupt mask register */
  #define EXTI_IMR3_IM64        0x00000001	/* Interrupt Mask on line 64 */
  #define EXTI_IMR3_IM65        0x00000002	/* Interrupt Mask on line 65 */
  #define EXTI_IMR3_IM66        0x00000004	/* Interrupt Mask on line 66 */
  #define EXTI_IMR3_IM67        0x00000008	/* Interrupt Mask on line 67 */
  #define EXTI_IMR3_IM68        0x00000010	/* Interrupt Mask on line 68 */
  #define EXTI_IMR3_IM69        0x00000020	/* Interrupt Mask on line 69 */
  #define EXTI_IMR3_IM70        0x00000040	/* Interrupt Mask on line 70 */
  #define EXTI_IMR3_IM71        0x00000080	/* Interrupt Mask on line 71 */
  #define EXTI_IMR3_IM72        0x00000100	/* Interrupt Mask on line 72 */
  #define EXTI_IMR3_IM73        0x00000200	/* Interrupt Mask on line 73 */
  #define EXTI_IMR3_IM74        0x00000400	/* Interrupt Mask on line 74 */
  #define EXTI_IMR3_IM75        0x00000800	/* Interrupt Mask on line 75 */
  #define EXTI_IMR3_IM76        0x00001000	/* Interrupt Mask on line 76 */
  #define EXTI_IMR3_IM77        0x00002000	/* Interrupt Mask on line 77 */
  #define EXTI_IMR3_IM78        0x00004000	/* Interrupt Mask on line 78 */
  #define EXTI_IMR3_IM79        0x00008000	/* Interrupt Mask on line 79 */
  #define EXTI_IMR3_IM80        0x00010000	/* Interrupt Mask on line 80 */
  #define EXTI_IMR3_IM81        0x00020000	/* Interrupt Mask on line 81 */
  #define EXTI_IMR3_IM82        0x00040000	/* Interrupt Mask on line 82 */
  #define EXTI_IMR3_IM84        0x00100000	/* Interrupt Mask on line 84 */
  #define EXTI_IMR3_IM85        0x00200000	/* Interrupt Mask on line 85 */
  #define EXTI_IMR3_IM86        0x00400000	/* Interrupt Mask on line 86 */
  #define EXTI_IMR3_IM87        0x00800000	/* Interrupt Mask on line 87 */
  #define EXTI_IMR3_IM88        0x01000000	/* Interrupt Mask on line 88 */
#define TOFF_EXTI_C_EMR3    0x0024		/* (RW) EXTI Event mask register */
  #define EXTI_EMR3_EM64        0x00000001	/* Event Mask on line 64*/
  #define EXTI_EMR3_EM65        0x00000002	/* Event Mask on line 65*/
  #define EXTI_EMR3_EM66        0x00000004	/* Event Mask on line 66*/
  #define EXTI_EMR3_EM67        0x00000008	/* Event Mask on line 67*/
  #define EXTI_EMR3_EM68        0x00000010	/* Event Mask on line 68*/
  #define EXTI_EMR3_EM69        0x00000020	/* Event Mask on line 69*/
  #define EXTI_EMR3_EM70        0x00000040	/* Event Mask on line 70*/
  #define EXTI_EMR3_EM71        0x00000080	/* Event Mask on line 71*/
  #define EXTI_EMR3_EM72        0x00000100	/* Event Mask on line 72*/
  #define EXTI_EMR3_EM73        0x00000200	/* Event Mask on line 73*/
  #define EXTI_EMR3_EM74        0x00000400	/* Event Mask on line 74 */
  #define EXTI_EMR3_EM75        0x00000800	/* Event Mask on line 75 */
  #define EXTI_EMR3_EM76        0x00001000	/* Event Mask on line 76 */
  #define EXTI_EMR3_EM77        0x00002000	/* Event Mask on line 77 */
  #define EXTI_EMR3_EM78        0x00004000	/* Event Mask on line 78 */
  #define EXTI_EMR3_EM79        0x00008000	/* Event Mask on line 79 */
  #define EXTI_EMR3_EM80        0x00010000	/* Event Mask on line 80 */
  #define EXTI_EMR3_EM81        0x00020000	/* Event Mask on line 81 */
  #define EXTI_EMR3_EM82        0x00040000	/* Event Mask on line 82 */
  #define EXTI_EMR3_EM84        0x00100000	/* Event Mask on line 84 */
  #define EXTI_EMR3_EM85        0x00200000	/* Event Mask on line 85 */
  #define EXTI_EMR3_EM86        0x00400000	/* Event Mask on line 86 */
  #define EXTI_EMR3_EM87        0x00800000	/* Event Mask on line 87 */
  #define EXTI_EMR3_EM88        0x01000000	/* Event Mask on line 88 */


/*
 *  SYSTEM CONFIGURATION CONTROLLER
 */
#define TADR_SYSCFG_BASE    (MCU_APB3_PERIPH_BASE + 0x0000)

#define TOFF_SYSCFG_BOOTR   0x0000		/* (RW) SYSCFG Boot pin control register */
  #define SYSCFG_BOOTR_BOOT0          0x00000001	/* BOOT0 pin value */
  #define SYSCFG_BOOTR_BOOT1          0x00000002	/* BOOT1 pin value */
  #define SYSCFG_BOOTR_BOOT2          0x00000004	/* BOOT2 pin value */
  #define SYSCFG_BOOTR_BOOT0_PD       0x00000010	/* BOOT0 pin pull-down disable */
  #define SYSCFG_BOOTR_BOOT1_PD       0x00000020	/* BOOT1 pin pull-down disable */
  #define SYSCFG_BOOTR_BOOT2_PD       0x00000040	/* BOOT2 pin pull-down disable */
#define TOFF_SYSCFG_PMCSETR 0x0004		/* (RW) SYSCFG Peripheral Mode configuration set register */
  #define SYSCFG_PMCSETR_I2C1_FMP     0x00000001	/* I2C1 Fast mode plus */
  #define SYSCFG_PMCSETR_I2C2_FMP     0x00000002	/* I2C2 Fast mode plus */
  #define SYSCFG_PMCSETR_I2C3_FMP     0x00000004	/* I2C3 Fast mode plus */
  #define SYSCFG_PMCSETR_I2C4_FMP     0x00000008	/* I2C4 Fast mode plus */
  #define SYSCFG_PMCSETR_I2C5_FMP     0x00000010	/* I2C5 Fast mode plus */
  #define SYSCFG_PMCSETR_I2C6_FMP     0x00000020	/* I2C6 Fast mode plus */
  #define SYSCFG_PMCSETR_EN_BOOSTER	  0x00000100	/* I/O analog switch voltage booster enable */
  #define SYSCFG_PMCSETR_ANASWVDD     0x00000200	/* GPIO analog switches control voltage selection */
  #define SYSCFG_PMCSETR_ETH_CLK_SEL  0x00010000	/* Internal clock ETH_CLK1 from RCC is used regardless AFMux */
  #define SYSCFG_PMCSETR_ETH_REF_CLK_SEL 0x00020000	/* Ethernet 50MHz RMII clock selection */
  #define SYSCFG_PMCSETR_ETH_SELMII   0x00100000	/* controls MII or GMII when ETH_SEL[2:0] = 0b000 */
  #define SYSCFG_PMCSETR_ETH_SELMII_SEL  SYSCFG_PMCSETR_ETH_SELMII
  #define SYSCFG_PMCSETR_ETH_SEL      0x00E00000	/* Ethernet PHY Interface Selection */
  #define SYSCFG_PMCSETR_ETH_SEL_0    0x00200000
  #define SYSCFG_PMCSETR_ETH_SEL_1    0x00400000
  #define SYSCFG_PMCSETR_ETH_SEL_2    0x00800000
  #define SYSCFG_PMCSETR_ETH_SEL_CONF 0x00F00000	/* Ethernet PHY Interface Configuration */
  #define SYSCFG_PMCSETR_ANA0_SEL     0x01000000	/* controls analog connection between ANA0 and PA0 pin */
  #define SYSCFG_PMCSETR_ANA1_SEL     0x02000000	/* controls analog connection between ANA1 and PA1 pin */
#define TOFF_SYSCFG_IOCTRLSETR 0x0018	/* (RW) SYSCFG ioctl set register */
  #define SYSCFG_IOCTRLSETR_HSLVEN_TRACE    0x00000001	/* High Speed Low Voltage Pad mode Enable */
  #define SYSCFG_IOCTRLSETR_HSLVEN_QUADSPI  0x00000002	/* High Speed Low Voltage Pad mode Enable */
  #define SYSCFG_IOCTRLSETR_HSLVEN_ETH      0x00000004	/* High Speed Low Voltage Pad mode Enable */
  #define SYSCFG_IOCTRLSETR_HSLVEN_SDMMC    0x00000008	/* High Speed Low Voltage Pad mode Enable */
  #define SYSCFG_IOCTRLSETR_HSLVEN_SPI      0x00000010	/* High Speed Low Voltage Pad mode Enable */
#define TOFF_SYSCFG_ICNR    0x001C		/* (RW) SYSCFG interconnect control register */
  #define SYSCFG_ICNR_AXI_M0          0x00000001	/* controls which slave port is used by the master to access the DDR */
  #define SYSCFG_ICNR_AXI_M1          0x00000002	/* controls which slave port is used by the master to access the DDR */
  #define SYSCFG_ICNR_AXI_M2          0x00000004	/* controls which slave port is used by the master to access the DDR */
  #define SYSCFG_ICNR_AXI_M3          0x00000008	/* controls which slave port is used by the master to access the DDR */
  #define SYSCFG_ICNR_AXI_M5          0x00000020	/* controls which slave port is used by the master to access the DDR */
  #define SYSCFG_ICNR_AXI_M6          0x00000040	/* controls which slave port is used by the master to access the DDR */
  #define SYSCFG_ICNR_AXI_M7          0x00000080	/* controls which slave port is used by the master to access the DDR */
  #define SYSCFG_ICNR_AXI_M8          0x00000100	/* controls which slave port is used by the master to access the DDR */
  #define SYSCFG_ICNR_AXI_M9          0x00000200	/* controls which slave port is used by the master to access the DDR */
  #define SYSCFG_ICNR_AXI_M10         0x00000400	/* controls which slave port is used by the master to access the DDR */
#define TOFF_SYSCFG_CMPCR   0x0020		/* (RW) SYSCFG compensation cell control register */
  #define SYSCFG_CMPCR_SW_CTRL        0x00000002	/* Compensation Software Control */
  #define SYSCFG_CMPCR_READY          0x00000100	/* Compensation cell ready flag */
  #define SYSCFG_CMPCR_RANSRC         0x000F0000	/* NMOS I/O Compensation value sent to IOs when SW_CTRL = 1 */
  #define SYSCFG_CMPCR_RANSRC_0       0x00010000
  #define SYSCFG_CMPCR_RANSRC_1       0x00020000
  #define SYSCFG_CMPCR_RANSRC_2       0x00040000
  #define SYSCFG_CMPCR_RANSRC_3       0x00080000
  #define SYSCFG_CMPCR_RAPSRC         0x00F00000	/* PMOS I/O Compensation value sent to IOs when SW_CTRL = 1 */
  #define SYSCFG_CMPCR_RAPSRC_0       0x00100000
  #define SYSCFG_CMPCR_RAPSRC_1       0x00200000
  #define SYSCFG_CMPCR_RAPSRC_2       0x00400000
  #define SYSCFG_CMPCR_RAPSRC_3       0x00800000
  #define SYSCFG_CMPCR_ANSRC          0x0F000000	/* NMOS I/O Compensation value provided by compensation cell */
  #define SYSCFG_CMPCR_ANSRC_0        0x01000000
  #define SYSCFG_CMPCR_ANSRC_1        0x02000000
  #define SYSCFG_CMPCR_ANSRC_2        0x04000000
  #define SYSCFG_CMPCR_ANSRC_3        0x08000000
  #define SYSCFG_CMPCR_APSRC          0xF0000000	/* PMOS I/O Compensation value provided by compensation cell */
  #define SYSCFG_CMPCR_APSRC_0        0x10000000
  #define SYSCFG_CMPCR_APSRC_1        0x20000000
  #define SYSCFG_CMPCR_APSRC_2        0x40000000
  #define SYSCFG_CMPCR_APSRC_3        0x80000000
#define TOFF_SYSCFG_CMPENSETR  0x0024	/* (RW) SYSCFG compensation cell enable set register */
  #define SYSCFG_CMPENSETR_MPU_EN     0x00000001	/* Compensation cell enable */
  #define SYSCFG_CMPENSETR_MCU_EN     0x00000002	/* Compensation cell enable */
#define TOFF_SYSCFG_CMPENCLRR  0x0028	/* (RW) SYSCFG compensation cell enable clear register */
  #define SYSCFG_CMPENCLRR_MPU_EN     0x00000001	/* Compensation cell disable */
  #define SYSCFG_CMPENCLRR_MCU_EN     0x00000002	/* Compensation cell disable */
#define TOFF_SYSCFG_CBR     0x002C		/* (RW) SYSCFG control timer break register */
  #define SYSCFG_CBR_CLL              0x00000001	/* Cortex-M4 LOCKUP (Hardfault) output enable bit */
  #define SYSCFG_CBR_PVDL             0x00000004	/* PVD lock enable bit */
#define TOFF_SYSCFG_PMCCLRR 0x0044		/* (RW) SYSCFG Peripheral Mode configuration clear register */
  #define SYSCFG_PMCCLRR_I2C1_FMP     0x00000001	/* I2C1 Fast mode plus */
  #define SYSCFG_PMCCLRR_I2C2_FMP     0x00000002	/* I2C2 Fast mode plus */
  #define SYSCFG_PMCCLRR_I2C3_FMP     0x00000004	/* I2C3 Fast mode plus */
  #define SYSCFG_PMCCLRR_I2C4_FMP     0x00000008	/* I2C4 Fast mode plus */
  #define SYSCFG_PMCCLRR_I2C5_FMP     0x00000010	/* I2C5 Fast mode plus */
  #define SYSCFG_PMCCLRR_I2C6_FMP     0x00000020	/* I2C6 Fast mode plus */
  #define SYSCFG_PMCCLRR_EN_BOOSTER   0x00000100	/* I/O analog switch voltage booster enable */
  #define SYSCFG_PMCCLRR_ANASWVDD     0x00000200	/* GPIO analog switches control voltage selection */
  #define SYSCFG_PMCCLRR_ETH_CLK_SEL  0x00010000	/* Internal clock ETH_CLK1 from RCC is used regardless AFMux */
  #define SYSCFG_PMCCLRR_ETH_REF_CLK_SEL 0x00020000	/* Ethernet 50MHz RMII clock selection */
  #define SYSCFG_PMCCLRR_ETH_SELMII   0x00100000	/* controls MII or GMII when ETH_SEL[2:0] = 0b000 */
  #define SYSCFG_PMCCLRR_ETH_SEL      0x00E00000	/* Ethernet PHY Interface Selection */
  #define SYSCFG_PMCCLRR_ETH_SEL_0    0x00200000
  #define SYSCFG_PMCCLRR_ETH_SEL_1    0x00400000
  #define SYSCFG_PMCCLRR_ETH_SEL_2    0x00800000
  #define SYSCFG_PMCCLRR_ETH_SEL_CONF 0x00F00000	/* Ethernet PHY Interface Configuration */
  #define SYSCFG_PMCCLRR_ANA0_SEL     0x01000000	/* controls analog connection between ANA0 and PA0 pin */
  #define SYSCFG_PMCCLRR_ANA1_SEL     0x02000000	/* controls analog connection between ANA1 and PA1 pin */
#define TOFF_SYSCFG_IOCTRLCLRR 0x0058	/* (RW) SYSCFG ioctl clear register */
  #define SYSCFG_IOCTRLCLRR_HSLVEN_TRACE   0x00000001	/* High Speed Low Voltage Pad mode Enable */
  #define SYSCFG_IOCTRLCLRR_HSLVEN_QUADSPI 0x00000002	/* High Speed Low Voltage Pad mode Enable */
  #define SYSCFG_IOCTRLCLRR_HSLVEN_ETH     0x00000004	/* High Speed Low Voltage Pad mode Enable */
  #define SYSCFG_IOCTRLCLRR_HSLVEN_SDMMC   0x00000008	/* High Speed Low Voltage Pad mode Enable */
  #define SYSCFG_IOCTRLCLRR_HSLVEN_SPI     0x00000010	/* High Speed Low Voltage Pad mode Enable */
#define TOFF_SYSCFG_VERR    0x03F4		/* (RW) SYSCFG version register */
  #define SYSCFG_VERR_MINREV          0x0000000F	/* Minor Revision number */
  #define SYSCFG_VERR_MAJREV          0x000000F0	/* Major Revision number */
#define TOFF_SYSCFG_IPIDR   0x03F8		/* (RW) SYSCFG ID register */
#define TOFF_SYSCFG_SIDR    0x03FC		/* (RW) SYSCFG magic ID register */


/*
 *  VOLTAGE REFERENCE BUFFER
 */
#define TADR_VREFBUF_BASE   (MCU_APB3_PERIPH_BASE + 0x5000)
#define TOFF_VREFBUF_CSR    0x0000	/* VREF control and status register */
  #define VREFBUF_CSR_ENVR      0x00000001	/* Voltage reference buffer enable */
  #define VREFBUF_CSR_HIZ       0x00000002	/* High impedance mode */
  #define VREFBUF_CSR_VRR       0x00000008	/* Voltage reference buffer ready */
  #define VREFBUF_CSR_VRS       0x00000070	/* Voltage reference scale */
  #define VREFBUF_CSR_VRS_OUT1  0x00000000	/* Voltage reference VREF_OUT1 */
  #define VREFBUF_CSR_VRS_OUT2  0x00000010	/* Voltage reference VREF_OUT2 */
  #define VREFBUF_CSR_VRS_OUT3  0x00000020	/* Voltage reference VREF_OUT3 */
  #define VREFBUF_CSR_VRS_OUT4  0x00000030	/* Voltage reference VREF_OUT4 */
#define TOFF_VREFBUF_CCR    0x0004	/* VREF control and status register */
  #define VREFBUF_CCR_TRIM      0x0000003F	/* TRIM[5:0] bits (Trimming code) */


/*
 *  TEMPERATURE SENSOR
 */
#define TADR_DTS_BASE       (MCU_APB3_PERIPH_BASE + 0x8000)
#define TOFF_DTS_CFGR1      0x0000		/* (RW) Temperature Sensor Configuration Register 1 */
  #define DTS_CFGR1_TS1_EN          0x00000001	/* DTS1 Enable */
  #define DTS_CFGR1_TS1_START       0x00000010	/* Proceed to a frequency measurement on DTS1 */
  #define DTS_CFGR1_TS1_INTRIG_SEL  0x00000F00	/* Input triggers selection bits [3:0] for DTS1 */
  #define DTS_CFGR1_TS1_INTRIG_SEL_0  0x00000100
  #define DTS_CFGR1_TS1_INTRIG_SEL_1  0x00000200
  #define DTS_CFGR1_TS1_INTRIG_SEL_2  0x00000400
  #define DTS_CFGR1_TS1_INTRIG_SEL_3  0x00000800
  #define DTS_CFGR1_TS1_SMP_TIME    0x000F0000	/* Sample time [3:0] for DTS1 */
  #define DTS_CFGR1_TS1_SMP_TIME_0  0x00010000
  #define DTS_CFGR1_TS1_SMP_TIME_1  0x00020000
  #define DTS_CFGR1_TS1_SMP_TIME_2  0x00040000
  #define DTS_CFGR1_TS1_SMP_TIME_3  0x00080000
  #define DTS_CFGR1_REFCLK_SEL      0x00100000	/* Reference Clock Selection */
  #define DTS_CFGR1_Q_MEAS_OPT      0x00200000	/* Quick measure option bit  */
  #define DTS_CFGR1_HSREF_CLK_DIV   0x7F000000	/* High Speed Clock Divider Ratio [6:0]*/
#define TOFF_DTS_T0VALR1    0x0008		/* (RW) Temperature sensor T0 Value Register 1 */
  #define DTS_T0VALR1_TS1_FMT0      0x0000FFFF	/* Engineering value of the measured frequency at T0 for DTS1 */
  #define DTS_T0VALR1_TS1_T0        0x00030000	/* Engineering value of the DTSerature T0 for DTS1 */
#define TOFF_DTS_RAMPVALR   0x0010		/* (RW) Temperature sensor Ramp Value Register */
  #define DTS_RAMPVALR_TS1_RAMP_COEFF 0x0000FFFF	/* Engineering value of the ramp coefficient for DTS1 */
#define TOFF_DTS_ITR1       0x0014		/* (RW) Temperature sensor Interrupt Threshold Register 1 */
  #define DTS_ITR1_TS1_LITTHD       0x0000FFFF	/* Low interrupt threshold[15:0] for DTS1 */
  #define DTS_ITR1_TS1_HITTHD       0xFFFF0000	/* High interrupt threshold[15:0] for DTS1 */
#define TOFF_DTS_DR         0x001C		/* (RW) Temperature sensor Data Register */
  #define DTS_DR_TS1_MFREQ          0x0000FFFF	/* Measured Frequency[15:0] for DTS1 */
#define TOFF_DTS_SR         0x0020		/* (RW) Temperature sensor Status Register */
  #define DTS_SR_TS1_ITEF           0x00000001	/* Interrupt flag for end of measure for DTS1 */
  #define DTS_SR_TS1_ITLF           0x00000002	/* Interrupt flag for low threshold for DTS1  */
  #define DTS_SR_TS1_ITHF           0x00000004	/* Interrupt flag for high threshold for DTS1 */
  #define DTS_SR_TS1_AITEF          0x00000010	/* Asynchronous interrupt flag for end of measure for DTS1 */
  #define DTS_SR_TS1_AITLF          0x00000020	/* Asynchronous interrupt flag for low threshold for DTS1  */
  #define DTS_SR_TS1_AITHF          0x00000040	/* Asynchronous interrupt flag for high threshold for DTS1 */
  #define DTS_SR_TS1_RDY            0x00008000	/* DTS1 ready flag */
#define TOFF_DTS_ITENR      0x0024		/* (RW) Temperature sensor Interrupt Enable Register */
  #define DTS_ITENR_TS1_ITEEN       0x00000001	/* Enable interrupt flag for end of measure for DTS1 */
  #define DTS_ITENR_TS1_ITLEN       0x00000002	/* Enable interrupt flag for low threshold for DTS1  */
  #define DTS_ITENR_TS1_ITHEN       0x00000004	/* Enable interrupt flag for high threshold for DTS1 */
  #define DTS_ITENR_TS1_AITEEN      0x00000010	/* Enable asynchronous interrupt flag for end of measure for DTS1 */
  #define DTS_ITENR_TS1_AITLEN      0x00000020	/* Enable Asynchronous interrupt flag for low threshold for DTS1  */
  #define DTS_ITENR_TS1_AITHEN      0x00000040	/* Enable asynchronous interrupt flag for high threshold for DTS1 */
#define TOFF_DTS_ICIFR      0x0028		/* (RW) Temperature sensor clear interrupt flag register */
  #define DTS_ICIFR_TS1_CITEF       0x00000001	/* Clear the IT flag for End Of Measure for DTS1 */
  #define DTS_ICIFR_TS1_CITLF       0x00000002	/* Clear the IT flag for low threshold for DTS1  */
  #define DTS_ICIFR_TS1_CITHF       0x00000004	/* Clear the IT flag for high threshold on DTS1  */
  #define DTS_ICIFR_TS1_CAITEF      0x00000010	/* Clear the asynchronous IT flag for End Of Measure for DTS1 */
  #define DTS_ICIFR_TS1_CAITLF      0x00000020	/* Clear the asynchronous IT flag for low threshold for DTS1  */
  #define DTS_ICIFR_TS1_CAITHF      0x00000040	/* Clear the asynchronous IT flag for high threshold on DTS1  */
#define TOFF_DTS_OR         0x002C		/* (RW) Temperature sensor option register */


/*
 *  PROCESS MONTOR BLOCK
  */
#define TADR_PMB_BASE       (MCU_APB3_PERIPH_BASE + 0x9000)
#define TOFF_PMB_SENS_CTRL      0x0004	/* (RW) PMB Sensor control */
#define TOFF_PMB_REF_COUNTER    0x0008	/* (RW) PMB Reference counter */
#define TOFF_PMB_SENSOR_STATUS  0x000C	/* (RW) PMB Sensor Status */


/*
 *  HARDWARE DEBUG PORT
  */
#define TADR_HDP_BASE       (MCU_APB3_PERIPH_BASE + 0xA000)
#define TOFF_HDP_CTRL       0x0000		/* (RW) HDP Control Register */
  #define HDP_CTRL_EN           0x00000001	/* Enable HDP, valid if enabled in BSEC */
#define TOFF_HDP_MUX        0x0004		/* (RW) HDP Multiplexers Control Register */
  #define HDP_MUX_MUX0          0x0000000F	/* Select the HDP0 output among the 16 available signals */
  #define HDP_MUX_MUX0_0        0x00000001
  #define HDP_MUX_MUX0_1        0x00000002
  #define HDP_MUX_MUX0_2        0x00000004
  #define HDP_MUX_MUX0_3        0x00000008
  #define HDP_MUX_MUX1          0x000000F0	/* Select the HDP1 output among the 16 available signals */
  #define HDP_MUX_MUX1_0        0x00000010
  #define HDP_MUX_MUX1_1        0x00000020
  #define HDP_MUX_MUX1_2        0x00000040
  #define HDP_MUX_MUX1_3        0x00000080
  #define HDP_MUX_MUX2          0x00000F00	/* Select the HDP2 output among the 16 available signals */
  #define HDP_MUX_MUX2_0        0x00000100
  #define HDP_MUX_MUX2_1        0x00000200
  #define HDP_MUX_MUX2_2        0x00000400
  #define HDP_MUX_MUX2_3        0x00000800
  #define HDP_MUX_MUX3          0x0000F000	/* Select the HDP3 output among the 16 available signals */
  #define HDP_MUX_MUX3_0        0x00001000
  #define HDP_MUX_MUX3_1        0x00002000
  #define HDP_MUX_MUX3_2        0x00004000
  #define HDP_MUX_MUX3_3        0x00008000
  #define HDP_MUX_MUX4          0x000F0000	/* Select the HDP4 output among the 16 available signals */
  #define HDP_MUX_MUX4_0        0x00010000
  #define HDP_MUX_MUX4_1        0x00020000
  #define HDP_MUX_MUX4_2        0x00040000
  #define HDP_MUX_MUX4_3        0x00080000
  #define HDP_MUX_MUX5          0x00F00000	/* Select the HDP5 output among the 16 available signals */
  #define HDP_MUX_MUX5_0        0x00100000
  #define HDP_MUX_MUX5_1        0x00200000
  #define HDP_MUX_MUX5_2        0x00400000
  #define HDP_MUX_MUX5_3        0x00800000
  #define HDP_MUX_MUX6          0x0F000000	/* Select the HDP6 output among the 16 available signals */
  #define HDP_MUX_MUX6_0        0x01000000
  #define HDP_MUX_MUX6_1        0x02000000
  #define HDP_MUX_MUX6_2        0x04000000
  #define HDP_MUX_MUX6_3        0x08000000
  #define HDP_MUX_MUX7          0xF0000000	/* Select the HDP7 output among the 16 available signals */
  #define HDP_MUX_MUX7_0        0x10000000
  #define HDP_MUX_MUX7_1        0x20000000
  #define HDP_MUX_MUX7_2        0x40000000
  #define HDP_MUX_MUX7_3        0x80000000
#define TOFF_HDP_VAL        0x0010		/* (RW) HDP Read Back Value Register */
  #define HDP_VAL_HDPVAL        0x000000FF	/* Provide the value of the HDP signals */
#define TOFF_HDP_GPOSET     0x0014		/* (RW) HDP General Purpose Output Set Register */
  #define HDP_GPOSET_HDPGPOSET  0x000000FF	/* When a bit is written to 1, the corresponding HDP GPO is seT */
#define TOFF_HDP_GPOCLR     0x0018		/* (RW) HDP General Purpose Output Clear Register */
  #define HDP_GPOCLR_HDPGPOCLR  0x000000FF	/* When a bit is written to 1, the corresponding HDP GPO is cleared */
#define TOFF_HDP_GPOVAL     0x001C		/* (RW) HDP General Purpose Output Value Registe */
  #define HDP_GPOVAL_HDPGPOVAL  0x000000FF	/* When written, define the value of the HDP GPO */
#define TOFF_HDP_VERR       0x03F4		/* (R)  HDP Version Register */
  #define HDP_VERR_MINREV       0x0000000F	/* Minor Revision of the IP */
  #define HDP_VERR_MAJREV       0x000000F0	/* Major Revision of the IP */
#define TOFF_HDP_IPIDR      0x03F8		/* (R)  HDP IP Identification Register */
#define TOFF_HDP_SIDR       0x03FC		/* (R)  HDP Size Identification register */


/*
 *  DEBUG MCU
 */
#define TADR_DBGMCU_BASE    0x50081000
#define TOFF_DBGMCU_IDCODE  0x0000		/* (RW) MCU device ID code */
  #define DBGMCU_IDCODE_DEV_ID           0x00000FFF
  #define DBGMCU_IDCODE_REV_ID           0xFFFF0000
#define TOFF_DBGMCU_CR      0x0004		/* (RW) Debug MCU configuration register */
  #define DBGMCU_CR_DBG_SLEEP            0x00000001
  #define DBGMCU_CR_DBG_STOP             0x00000002
  #define DBGMCU_CR_DBG_STANDBY          0x00000004
  #define DBGMCU_CR_DBG_WDFZCTL          0x01000000
  #define DBGMCU_CR_DBG_TRGOEN           0x10000000
#define TOFF_DBGMCU_APB4FZ1 0x002C		/* (RW) Debug MCU APB4FZ1 freeze register CPU1 */
  #define DBGMCU_APB4_FZ_DBG_IWDG2_STOP  0x00000004
#define TOFF_DBGMCU_APB4FZ2 0x0030		/* (RW) Debug MCU APB4FZ2 freeze register CPU2 */
#define TOFF_DBGMCU_APB1FZ1 0x0034		/* (RW) Debug MCU APB1FZ1 freeze register CPU1 */
  #define DBGMCU_APB1_FZ_DBG_TIM2_STOP   0x00000001
  #define DBGMCU_APB1_FZ_DBG_TIM3_STOP   0x00000002
  #define DBGMCU_APB1_FZ_DBG_TIM4_STOP   0x00000004
  #define DBGMCU_APB1_FZ_DBG_TIM5_STOP   0x00000008
  #define DBGMCU_APB1_FZ_DBG_TIM6_STOP   0x00000010
  #define DBGMCU_APB1_FZ_DBG_TIM7_STOP   0x00000020
  #define DBGMCU_APB1_FZ_DBG_TIM12_STOP  0x00000040
  #define DBGMCU_APB1_FZ_DBG_TIM13_STOP  0x00000080
  #define DBGMCU_APB1_FZ_DBG_TIM14_STOP  0x00000100
  #define DBGMCU_APB1_FZ_DBG_LPTIM1_STOP 0x00000200
  #define DBGMCU_APB1_FZ_DBG_WWDG1_STOP  0x00000400
  #define DBGMCU_APB1_FZ_DBG_I2C1_STOP   0x00040000
  #define DBGMCU_APB1_FZ_DBG_I2C2_STOP   0x00080000
  #define DBGMCU_APB1_FZ_DBG_I2C3_STOP   0x00100000
  #define DBGMCU_APB1_FZ_DBG_I2C5_STOP   0x00200000
#define TOFF_DBGMCU_APB1FZ2 0x0038		/* (RW) Debug MCU APB1FZ2 freeze register CPU2 */
#define TOFF_DBGMCU_APB2FZ1 0x003C		/* (RW) Debug MCU APB2FZ1 freeze register CPU1 */
  #define DBGMCU_APB2_FZ_DBG_TIM1_STOP   0x00000001
  #define DBGMCU_APB2_FZ_DBG_TIM8_STOP   0x00000002
  #define DBGMCU_APB2_FZ_DBG_TIM15_STOP  0x00000040
  #define DBGMCU_APB2_FZ_DBG_TIM16_STOP  0x00000080
  #define DBGMCU_APB2_FZ_DBG_TIM17_STOP  0x00000100
  #define DBGMCU_APB2_FZ_DBG_FDCAN_STOP  0x00008000
#define TOFF_DBGMCU_APB2FZ2 0x0040		/* (RW) Debug MCU APB2FZ2 freeze register CPU2 */
#define TOFF_DBGMCU_APB3FZ1 0x0044		/* (RW) Debug MCU APB3FZ1 freeze register CPU1 */
  #define DBGMCU_APB3_FZ_DBG_LPTIM2_STOP 0x00000002
  #define DBGMCU_APB3_FZ_DBG_LPTIM3_STOP 0x00000004
  #define DBGMCU_APB3_FZ_DBG_LPTIM4_STOP 0x00000008
  #define DBGMCU_APB3_FZ_DBG_LPTIM5_STOP 0x00000010
#define TOFF_DBGMCU_APB3FZ2 0x0048		/* (RW) Debug MCU APB3FZ2 freeze register CPU2 */
#define TOFF_DBGMCU_APB5FZ1 0x004C		/* (RW) Debug MCU APB5FZ1 freeze register CPU1 */
  #define DBGMCU_APB5_FZ_DBG_I2C4_STOP   0x00000004
  #define DBGMCU_APB5_FZ_DBG_IWDG1_STOP  0x00000008
  #define DBGMCU_APB5_FZ_DBG_RTC_STOP    0x00000010
  #define DBGMCU_APB5_FZ_DBG_I2C6_STOP   0x00000200
#define TOFF_DBGMCU_APB5FZ2 0x0050		/* (RW) Debug MCU APB5FZ2 freeze register CPU2 */


/*
 *  MDMA CONTROLLER
 */
#define TADR_MDMA_BASE      (MPU_AHB6_PERIPH_BASE + 0x0000)
#define TOFF_MDMA_GISR0     0x0000		/* MDMA Global Interrupt/Status Register 0 */
  #define MDMA_GISR0_GIF0    0x00000001	/* Channel 0 global interrupt flag */
  #define MDMA_GISR0_GIF1    0x00000002	/* Channel 1 global interrupt flag */
  #define MDMA_GISR0_GIF2    0x00000004	/* Channel 2 global interrupt flag */
  #define MDMA_GISR0_GIF3    0x00000008	/* Channel 3 global interrupt flag */
  #define MDMA_GISR0_GIF4    0x00000010	/* Channel 4 global interrupt flag */
  #define MDMA_GISR0_GIF5    0x00000020	/* Channel 5 global interrupt flag */
  #define MDMA_GISR0_GIF6    0x00000040	/* Channel 6 global interrupt flag */
  #define MDMA_GISR0_GIF7    0x00000080	/* Channel 7 global interrupt flag */
  #define MDMA_GISR0_GIF8    0x00000100	/* Channel 8 global interrupt flag */
  #define MDMA_GISR0_GIF9    0x00000200	/* Channel 9 global interrupt flag */
  #define MDMA_GISR0_GIF10   0x00000400	/* Channel 10 global interrupt flag */
  #define MDMA_GISR0_GIF11   0x00000800	/* Channel 11 global interrupt flag */
  #define MDMA_GISR0_GIF12   0x00001000	/* Channel 12 global interrupt flag */
  #define MDMA_GISR0_GIF13   0x00002000	/* Channel 13 global interrupt flag */
  #define MDMA_GISR0_GIF14   0x00004000	/* Channel 14 global interrupt flag */
  #define MDMA_GISR0_GIF15   0x00008000	/* Channel 15 global interrupt flag */
  #define MDMA_GISR0_GIF16   0x00010000	/* Channel 16 global interrupt flag */
  #define MDMA_GISR0_GIF17   0x00020000	/* Channel 17 global interrupt flag */
  #define MDMA_GISR0_GIF18   0x00040000	/* Channel 18 global interrupt flag */
  #define MDMA_GISR0_GIF19   0x00080000	/* Channel 19 global interrupt flag */
  #define MDMA_GISR0_GIF20   0x00100000	/* Channel 20 global interrupt flag */
  #define MDMA_GISR0_GIF21   0x00200000	/* Channel 21 global interrupt flag */
  #define MDMA_GISR0_GIF22   0x00400000	/* Channel 22 global interrupt flag */
  #define MDMA_GISR0_GIF23   0x00800000	/* Channel 23 global interrupt flag */
  #define MDMA_GISR0_GIF24   0x01000000	/* Channel 24 global interrupt flag */
  #define MDMA_GISR0_GIF25   0x02000000	/* Channel 25 global interrupt flag */
  #define MDMA_GISR0_GIF26   0x04000000	/* Channel 26 global interrupt flag */
  #define MDMA_GISR0_GIF27   0x08000000	/* Channel 27 global interrupt flag */
  #define MDMA_GISR0_GIF28   0x10000000	/* Channel 28 global interrupt flag */
  #define MDMA_GISR0_GIF29   0x20000000	/* Channel 29 global interrupt flag */
  #define MDMA_GISR0_GIF30   0x40000000	/* Channel 30 global interrupt flag */
  #define MDMA_GISR0_GIF31   0x80000000	/* Channel 31 global interrupt flag */
#define TOFF_MDMA_SGISR0    0x0008		/* (RW) MDMA Secure Global Interrupt/Status Register 0 */
#define TOFF_MDMA_VERR      0x03F4		/* (R)  MDMA Verion Register */
#define TOFF_MDMA_IPDR      0x03F8		/* (R)  MDMA Identification register */
#define TOFF_MDMA_SIDR      0x03FC		/* (R)  MDMA Size Identification register */

#define MDMA_NB_CHANNELS    32
#define TADR_MDMA_CH0_BASE  (TADR_MDMA_BASE + 0x0040)
#define TADR_MDMA_CH1_BASE  (TADR_MDMA_BASE + 0x0080)
#define TADR_MDMA_CH2_BASE  (TADR_MDMA_BASE + 0x00C0)
#define TADR_MDMA_CH3_BASE  (TADR_MDMA_BASE + 0x0100)
#define TADR_MDMA_CH4_BASE  (TADR_MDMA_BASE + 0x0140)
#define TADR_MDMA_CH5_BASE  (TADR_MDMA_BASE + 0x0180)
#define TADR_MDMA_CH6_BASE  (TADR_MDMA_BASE + 0x01C0)
#define TADR_MDMA_CH7_BASE  (TADR_MDMA_BASE + 0x0200)
#define TADR_MDMA_CH8_BASE  (TADR_MDMA_BASE + 0x0240)
#define TADR_MDMA_CH9_BASE  (TADR_MDMA_BASE + 0x0280)
#define TADR_MDMA_CH10_BASE (TADR_MDMA_BASE + 0x02C0)
#define TADR_MDMA_CH11_BASE (TADR_MDMA_BASE + 0x0300)
#define TADR_MDMA_CH12_BASE (TADR_MDMA_BASE + 0x0340)
#define TADR_MDMA_CH13_BASE (TADR_MDMA_BASE + 0x0380)
#define TADR_MDMA_CH14_BASE (TADR_MDMA_BASE + 0x03C0)
#define TADR_MDMA_CH15_BASE (TADR_MDMA_BASE + 0x0400)
#define TADR_MDMA_CH16_BASE (TADR_MDMA_BASE + 0x0440)
#define TADR_MDMA_CH17_BASE (TADR_MDMA_BASE + 0x0480)
#define TADR_MDMA_CH18_BASE (TADR_MDMA_BASE + 0x04C0)
#define TADR_MDMA_CH19_BASE (TADR_MDMA_BASE + 0x0500)
#define TADR_MDMA_CH20_BASE (TADR_MDMA_BASE + 0x0540)
#define TADR_MDMA_CH21_BASE (TADR_MDMA_BASE + 0x0580)
#define TADR_MDMA_CH22_BASE (TADR_MDMA_BASE + 0x05C0)
#define TADR_MDMA_CH23_BASE (TADR_MDMA_BASE + 0x0600)
#define TADR_MDMA_CH24_BASE (TADR_MDMA_BASE + 0x0640)
#define TADR_MDMA_CH25_BASE (TADR_MDMA_BASE + 0x0680)
#define TADR_MDMA_CH26_BASE (TADR_MDMA_BASE + 0x06C0)
#define TADR_MDMA_CH27_BASE (TADR_MDMA_BASE + 0x0700)
#define TADR_MDMA_CH28_BASE (TADR_MDMA_BASE + 0x0740)
#define TADR_MDMA_CH29_BASE (TADR_MDMA_BASE + 0x0780)
#define TADR_MDMA_CH30_BASE (TADR_MDMA_BASE + 0x07C0)
#define TADR_MDMA_CH31_BASE (TADR_MDMA_BASE + 0x0800)

#define TADR_MDMA_CISR      0x0000		/* (RW) MDMA channel x interrupt/status register */
  #define MDMA_CISR_TEIF     0x00000001	/* Channel x transfer error interrupt flag */
  #define MDMA_CISR_CTCIF    0x00000002	/* Channel x Channel Transfer Complete interrupt flag */
  #define MDMA_CISR_BRTIF    0x00000004	/* Channel x block repeat transfer complete interrupt flag */
  #define MDMA_CISR_BTIF     0x00000008	/* Channel x block transfer complete interrupt flag */
  #define MDMA_CISR_TCIF     0x00000010	/* Channel x buffer transfer complete interrupt flag */
  #define MDMA_CISR_CRQA     0x00010000	/* Channel x ReQest Active flag */
#define TADR_MDMA_CIFCR     0x0004		/* (RW) MDMA channel x interrupt flag clear register */
  #define MDMA_CIFCR_CTEIF   0x00000001	/* Channel x clear transfer error interrupt flag */
  #define MDMA_CIFCR_CCTCIF  0x00000002	/* Clear Channel transfer complete interrupt flag for channel x */
  #define MDMA_CIFCR_CBRTIF  0x00000004	/* Channel x clear block repeat transfer complete interrupt flag */
  #define MDMA_CIFCR_CBTIF   0x00000008	/* Channel x Clear block transfer complete interrupt flag */
  #define MDMA_CIFCR_CLTCIF  0x00000010	/* CLear Transfer buffer Complete Interrupt Flag for channel */
#define TADR_MDMA_CESR      0x0008		/* (RW) MDMA Channel x error status register */
  #define MDMA_CESR_TEA      0x0000007F	/* Transfer Error Address */
  #define MDMA_CESR_TED      0x00000080	/* Transfer Error Direction */
  #define MDMA_CESR_TELD     0x00000100	/* Transfer Error Link Data */
  #define MDMA_CESR_TEMD     0x00000200	/* Transfer Error Mask Data */
  #define MDMA_CESR_ASE      0x00000400	/* Address/Size Error       */
  #define MDMA_CESR_BSE      0x00000800	/* Block Size Error         */
#define TADR_MDMA_CCR       0x000C		/* (RW) MDMA channel x control register */
  #define MDMA_CCR_EN        0x00000001	/* Channel enable / flag channel ready when read low */
  #define MDMA_CCR_TEIE      0x00000002	/* Transfer error interrupt enable */
  #define MDMA_CCR_CTCIE     0x00000004	/* Channel Transfer Complete interrupt enable */
  #define MDMA_CCR_BRTIE     0x00000008	/* Block Repeat transfer interrupt enable */
  #define MDMA_CCR_BTIE      0x00000010	/* Block Transfer interrupt enable */
  #define MDMA_CCR_TCIE      0x00000020	/* buffer Transfer Complete interrupt enable */
  #define MDMA_CCR_PL        0x000000C0	/* Priority level */
  #define MDMA_CCR_PL_0      0x00000040
  #define MDMA_CCR_PL_1      0x00000080
  #define MDMA_CCR_BEX       0x00001000	/* Byte Endianess eXchange */
  #define MDMA_CCR_HEX       0x00002000	/* Half word Endianess eXchange */
  #define MDMA_CCR_WEX       0x00004000	/* Word Endianess eXchange */
  #define MDMA_CCR_SWRQ      0x00010000	/* SW ReQuest */
#define TADR_MDMA_CTCR      0x0010		/* (RW) MDMA channel x Transfer Configuration register */
  #define MDMA_CTCR_SINC     0x00000003	/* Source increment mode */
  #define MDMA_CTCR_SINC_0   0x00000001
  #define MDMA_CTCR_SINC_1   0x00000002
  #define MDMA_CTCR_DINC     0x0000000C	/* Source increment mode */
  #define MDMA_CTCR_DINC_0   0x00000004
  #define MDMA_CTCR_DINC_1   0x00000008
  #define MDMA_CTCR_SSIZE    0x00000030	/* Source data size */
  #define MDMA_CTCR_SSIZE_0  0x00000010
  #define MDMA_CTCR_SSIZE_1  0x00000020
  #define MDMA_CTCR_DSIZE    0x000000C0	/* Destination data size */
  #define MDMA_CTCR_DSIZE_0  0x00000040
  #define MDMA_CTCR_DSIZE_1  0x00000080
  #define MDMA_CTCR_SINCOS   0x00000300	/* Source increment offset size */
  #define MDMA_CTCR_SINCOS_0 0x00000100
  #define MDMA_CTCR_SINCOS_1 0x00000200
  #define MDMA_CTCR_DINCOS   0x00000C00	/* Destination increment offset size */
  #define MDMA_CTCR_DINCOS_0 0x00000400
  #define MDMA_CTCR_DINCOS_1 0x00000800
  #define MDMA_CTCR_SBURST   0x00007000	/* Source burst transfer configuration */
  #define MDMA_CTCR_SBURST_0 0x00001000
  #define MDMA_CTCR_SBURST_1 0x00002000
  #define MDMA_CTCR_SBURST_2 0x00004000
  #define MDMA_CTCR_DBURST   0x00038000	/* Destination burst transfer configuration */
  #define MDMA_CTCR_DBURST_0 0x00008000
  #define MDMA_CTCR_DBURST_1 0x00010000
  #define MDMA_CTCR_DBURST_2 0x00020000
  #define MDMA_CTCR_TLEN     0x01FC0000	/* buffer Transfer Length (number of bytes - 1) */
  #define MDMA_CTCR_PKE      0x02000000	/* PacK Enable */
  #define MDMA_CTCR_PAM      0x0C000000	/* Padding/Alignement Mode */
  #define MDMA_CTCR_PAM_0    0x04000000
  #define MDMA_CTCR_PAM_1    0x08000000
  #define MDMA_CTCR_TRGM     0x30000000	/* Trigger Mode */
  #define MDMA_CTCR_TRGM_0   0x10000000
  #define MDMA_CTCR_TRGM_1   0x20000000
  #define MDMA_CTCR_SWRM     0x40000000	/* SW Request Mode */
  #define MDMA_CTCR_BWM      0x80000000	/* Bufferable Write Mode */
#define TADR_MDMA_CBNDTR    0x0014		/* (RW) MDMA Channel x block number of data register */
  #define MDMA_CBNDTR_BNDT   0x0001FFFF	/* Block Number of data bytes to transfer */
  #define MDMA_CBNDTR_BRSUM  0x00040000	/* Block Repeat Source address Update Mode */
  #define MDMA_CBNDTR_BRDUM  0x00080000	/* Block Repeat Destination address Update Mode */
  #define MDMA_CBNDTR_BRC    0xFFF00000	/* Block Repeat Count */
#define TADR_MDMA_CSAR      0x0018		/* (RW) MDMA channel x source address register */
#define TADR_MDMA_CDAR      0x001C		/* (RW) MDMA channel x destination address register */
#define TADR_MDMA_CBRUR     0x0020		/* (RW) MDMA channel x Block Repeat address Update register */
  #define MDMA_CBRUR_SUV     0x0000FFFF	/* Source address Update Value */
  #define MDMA_CBRUR_DUV     0xFFFF0000	/* Destination address Update Value */
#define TADR_MDMA_CLAR      0x0024		/* (RW) MDMA channel x Link Address register */
#define TADR_MDMA_CTBR      0x0028		/* (RW) MDMA channel x Trigger and Bus selection Register */
  #define MDMA_CTBR_TSEL     0x000000FF	/* Trigger SELection */
  #define MDMA_CTBR_SBUS     0x00010000	/* Source BUS select */
  #define MDMA_CTBR_DBUS     0x00020000	/* Destination BUS select */
#define TADR_MDMA_CMAR      0x0030		/* (RW) MDMA channel x Mask address register */
#define TADR_MDMA_CMDR      0x0034		/* (RW) MDMA channel x Mask Data register */


/*
 *  FLEXIBLE STATIC MEMORY
 */
#define TADR_FMC_R_BASE     (MPU_AHB6_PERIPH_BASE + 0x2000)

/*
 *  FLEXIBLE MEMORY CONTROLLER
 */
#define TOFF_FMC_R_BTCR0    0x0000		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 0 */
  #define FMC_BCR1_MBKEN        0x00000001	/* Memory bank enable bit */
  #define FMC_BCR1_MUXEN        0x00000002	/* Address/data multiplexing enable bit */
  #define FMC_BCR1_MTYP         0x0000000C	/* MTYP[1:0] bits (Memory type) */
  #define FMC_BCR1_MTYP_0       0x00000004
  #define FMC_BCR1_MTYP_1       0x00000008
  #define FMC_BCR1_MWID         0x00000030	/* MWID[1:0] bits (Memory data bus width) */
  #define FMC_BCR1_MWID_0       0x00000010
  #define FMC_BCR1_MWID_1       0x00000020
  #define FMC_BCR1_FACCEN       0x00000040	/* Flash access enable */
  #define FMC_BCR1_BURSTEN      0x00000100	/* Burst enable bit */
  #define FMC_BCR1_WAITPOL      0x00000200	/* Wait signal polarity bit */
  #define FMC_BCR1_WRAPMOD      0x00000400	/* Wrapped burst mode support */
  #define FMC_BCR1_WAITCFG      0x00000800	/* Wait timing configuration */
  #define FMC_BCR1_WREN         0x00001000	/* Write enable bit */
  #define FMC_BCR1_WAITEN       0x00002000	/* Wait enable bit */
  #define FMC_BCR1_EXTMOD       0x00004000	/* Extended mode enable */
  #define FMC_BCR1_ASYNCWAIT    0x00008000	/* Asynchronous wait */
  #define FMC_BCR1_CPSIZE       0x00070000	/* CRAM page size */
  #define FMC_BCR1_CPSIZE_0     0x00010000
  #define FMC_BCR1_CPSIZE_1     0x00020000
  #define FMC_BCR1_CPSIZE_2     0x00040000
  #define FMC_BCR1_CBURSTRW     0x00080000	/* Write burst enable */
  #define FMC_BCR1_CCLKEN       0x00100000	/* Continous clock enable */
  #define FMC_BCR1_NBLSET       0x00C00000	/* NBLSET[1:0] bits Byte lane (NBL) SETUP */
  #define FMC_BCR1_NBLSET_0     0x00400000
  #define FMC_BCR1_NBLSET_1     0x00800000
  #define FMC_BCR1_FMCEN        0x80000000	/* FMC controller Enable */
#define TOFF_FMC_R_BTCR1    0x0004		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 1 */
  #define FMC_BTR1_ADDSET       0x0000000F	/* ADDSET[3:0] bits (Address setup phase duration) */
  #define FMC_BTR1_ADDSET_0     0x00000001
  #define FMC_BTR1_ADDSET_1     0x00000002
  #define FMC_BTR1_ADDSET_2     0x00000004
  #define FMC_BTR1_ADDSET_3     0x00000008
  #define FMC_BTR1_ADDHLD       0x000000F0	/* ADDHLD[3:0] bits (Address-hold phase duration) */
  #define FMC_BTR1_ADDHLD_0     0x00000010
  #define FMC_BTR1_ADDHLD_1     0x00000020
  #define FMC_BTR1_ADDHLD_2     0x00000040
  #define FMC_BTR1_ADDHLD_3     0x00000080
  #define FMC_BTR1_DATAST       0x0000FF00/* DATAST [3:0] bits (Data-phase duration) */
  #define FMC_BTR1_DATAST_0     0x00000100
  #define FMC_BTR1_DATAST_1     0x00000200
  #define FMC_BTR1_DATAST_2     0x00000400
  #define FMC_BTR1_DATAST_3     0x00000800
  #define FMC_BTR1_DATAST_4     0x00001000
  #define FMC_BTR1_DATAST_5     0x00002000
  #define FMC_BTR1_DATAST_6     0x00004000
  #define FMC_BTR1_DATAST_7     0x00008000
  #define FMC_BTR1_BUSTURN      0x000F0000	/* BUSTURN[3:0] bits (Bus turnaround phase duration) */
  #define FMC_BTR1_BUSTURN_0    0x00010000
  #define FMC_BTR1_BUSTURN_1    0x00020000
  #define FMC_BTR1_BUSTURN_2    0x00040000
  #define FMC_BTR1_BUSTURN_3    0x00080000
  #define FMC_BTR1_CLKDIV       0x00F00000	/* CLKDIV[3:0] bits (Clock divide ratio) */
  #define FMC_BTR1_CLKDIV_0     0x00100000
  #define FMC_BTR1_CLKDIV_1     0x00200000
  #define FMC_BTR1_CLKDIV_2     0x00400000
  #define FMC_BTR1_CLKDIV_3     0x00800000
  #define FMC_BTR1_DATLAT       0x0F000000	/* DATLA[3:0] bits (Data latency) */
  #define FMC_BTR1_DATLAT_0     0x01000000
  #define FMC_BTR1_DATLAT_1     0x02000000
  #define FMC_BTR1_DATLAT_2     0x04000000
  #define FMC_BTR1_DATLAT_3     0x08000000
  #define FMC_BTR1_ACCMOD       0x30000000	/* ACCMOD[1:0] bits (Access mode) */
  #define FMC_BTR1_ACCMOD_0     0x10000000
  #define FMC_BTR1_ACCMOD_1     0x20000000
  #define FMC_BTR1_DATAHLD      0xC0000000	/* DATAHLD[1:0] bits (Data Hold phase duration) */
  #define FMC_BTR1_DATAHLD_0    0x40000000
  #define FMC_BTR1_DATAHLD_1    0x80000000
#define TOFF_FMC_R_BTCR2    0x0008		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 2 */
#define TOFF_FMC_R_BTCR3    0x000C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 3 */
#define TOFF_FMC_R_BTCR4    0x0010		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 4 */
#define TOFF_FMC_R_BTCR5    0x0014		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 5 */
#define TOFF_FMC_R_BTCR6    0x0018		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 6 */
#define TOFF_FMC_R_BTCR7    0x001C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 7 */
#define TOFF_FMC_R_PCSCNTR  0x0020		/* (RW) PSRAM chip-select counter register(PCSCNTR) */
  #define FMC_PCSCNTR_CSCOUNT   0x0000FFFF	/* CSCOUNT[15:0] bits Chip Select (CS) counter */
  #define FMC_PCSCNTR_CNTB1EN   0x00010000	/* CNTB1EN bit Counter Bank1 enable */
  #define FMC_PCSCNTR_CNTB2EN   0x00020000	/* CNTB2EN bit Counter Bank2 enable */
  #define FMC_PCSCNTR_CNTB3EN   0x00040000	/* CNTB3EN bit Counter Bank3 enable */
  #define FMC_PCSCNTR_CNTB4EN   0x00080000	/* CNTB4EN bit Counter Bank4 enable */

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
 *  FLEXIBLE MEMORY CONTROLLER BANK2
 */
#define TOFF_FMC_PSR2       0x0060		/* (RW) NAND Flash control register 2 */
#define TOFF_FMC_SR2        0x0064		/* (RW) NAND Flash FIFO status and interrupt register 2 */
#define TOFF_FMC_PMEM2      0x0068		/* (RW) NAND Flash Common memory space timing register 2 */
#define TOFF_FMC_PATT2      0x006C		/* (RW) NAND Flash Attribute memory space timing register 2 */
#define TOFF_FMC_ECCR2      0x0074		/* (RW) NAND Flash ECC result registers 2 */

/*
 *  FLEXIBLE MEMORY CONTROLLER BANK3
 */
#define TOFF_FMC_R_PCR      0x0080		/* (RW) NAND Flash control register */
  #define FMC_PCR_PWAITEN       0x00000002	/* Wait feature enable bit                   */
  #define FMC_PCR_PBKEN         0x00000004	/* NAND Flash memory bank enable bit */
  #define FMC_PCR_PWID          0x00000030	/* PWID[1:0] bits (NAND Flash databus width) */
  #define FMC_PCR_PWID_0        0x00000010
  #define FMC_PCR_PWID_1        0x00000020
  #define FMC_PCR_ECCEN         0x00000040	/* ECC computation logic enable bit */
  #define FMC_PCR_ECCALG        0x00000100	/* ECC algorithm */
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
  #define FMC_PCR_ECCPS         0x000E0000	/* ECCPS[1:0] bits (ECC page size) */
  #define FMC_PCR_ECCPS_0       0x00020000
  #define FMC_PCR_ECCPS_1       0x00040000
  #define FMC_PCR_ECCPS_2       0x00080000
  #define FMC_PCR_TCEH          0x00F00000	/* TCEH[3:0] bits (Chip select high timing)  */
  #define FMC_PCR_BCHECC        0x01000000	/* BCHECC bit (BCH error correction capability) */
  #define FMC_PCR_WEN           0x02000000	/* WEN bit (Write enable) */
#define TOFF_FMC_R_SR       0x0084		/* (RW) NAND Flash FIFO status and interrupt register */
  #define FMC_SR_ISOST          0x00000003	/* ISOST[1:0] bits (FMC isolation state with respect to the AXI interface) */
  #define FMC_SR_PEF            0x00000010	/* Pipe Empty Flag */
  #define FMC_SR_NWRF           0x00000040	/* NAND write request flag  */
#define TOFF_FMC_R_PMEM     0x0088		/* (RW) NAND Flash Common memory space timing register */
  #define FMC_PMEM_MEMSET3      0x000000FF	/* MEMSET[7:0] bits (Common memory setup time) */
  #define FMC_PMEM_MEMSET3_0    0x00000001
  #define FMC_PMEM_MEMSET3_1    0x00000002
  #define FMC_PMEM_MEMSET3_2    0x00000004
  #define FMC_PMEM_MEMSET3_3    0x00000008
  #define FMC_PMEM_MEMSET3_4    0x00000010
  #define FMC_PMEM_MEMSET3_5    0x00000020
  #define FMC_PMEM_MEMSET3_6    0x00000040
  #define FMC_PMEM_MEMSET3_7    0x00000080
  #define FMC_PMEM_MEMWAIT3     0x0000FF00	/* MEMWAIT[7:0] bits (Common memory wait time) */
  #define FMC_PMEM_MEMWAIT3_0   0x00000100
  #define FMC_PMEM_MEMWAIT3_1   0x00000200
  #define FMC_PMEM_MEMWAIT3_2   0x00000400
  #define FMC_PMEM_MEMWAIT3_3   0x00000800
  #define FMC_PMEM_MEMWAIT3_4   0x00001000
  #define FMC_PMEM_MEMWAIT3_5   0x00002000
  #define FMC_PMEM_MEMWAIT3_6   0x00004000
  #define FMC_PMEM_MEMWAIT3_7   0x00008000
  #define FMC_PMEM_MEMHOLD3     0x00FF0000	/* MEMHOLD[7:0] bits (Common memory hold time) */
  #define FMC_PMEM_MEMHOLD3_0   0x00010000
  #define FMC_PMEM_MEMHOLD3_1   0x00020000
  #define FMC_PMEM_MEMHOLD3_2   0x00040000
  #define FMC_PMEM_MEMHOLD3_3   0x00080000
  #define FMC_PMEM_MEMHOLD3_4   0x00100000
  #define FMC_PMEM_MEMHOLD3_5   0x00200000
  #define FMC_PMEM_MEMHOLD3_6   0x00400000
  #define FMC_PMEM_MEMHOLD3_7   0x00800000
  #define FMC_PMEM_MEMHIZ3      0xFF000000	/* MEMHIZ[7:0] bits (Common memory databus HiZ time) */
  #define FMC_PMEM_MEMHIZ3_0    0x01000000
  #define FMC_PMEM_MEMHIZ3_1    0x02000000
  #define FMC_PMEM_MEMHIZ3_2    0x04000000
  #define FMC_PMEM_MEMHIZ3_3    0x08000000
  #define FMC_PMEM_MEMHIZ3_4    0x10000000
  #define FMC_PMEM_MEMHIZ3_5    0x20000000
  #define FMC_PMEM_MEMHIZ3_6    0x40000000
  #define FMC_PMEM_MEMHIZ3_7    0x80000000
#define TOFF_FMC_R_PATT     0x008C		/* (RW) NAND Flash Attribute memory space timing register */
  #define FMC_PATT_ATTSET3      0x000000FF	/* ATTSET[7:0] bits (Attribute memory setup time) */
  #define FMC_PATT_ATTSET3_0    0x00000001
  #define FMC_PATT_ATTSET3_1    0x00000002
  #define FMC_PATT_ATTSET3_2    0x00000004
  #define FMC_PATT_ATTSET3_3    0x00000008
  #define FMC_PATT_ATTSET3_4    0x00000010
  #define FMC_PATT_ATTSET3_5    0x00000020
  #define FMC_PATT_ATTSET3_6    0x00000040
  #define FMC_PATT_ATTSET3_7    0x00000080
  #define FMC_PATT_ATTWAIT3     0x0000FF00	/* ATTWAIT[7:0] bits (Attribute memory wait time) */
  #define FMC_PATT_ATTWAIT3_0   0x00000100
  #define FMC_PATT_ATTWAIT3_1   0x00000200
  #define FMC_PATT_ATTWAIT3_2   0x00000400
  #define FMC_PATT_ATTWAIT3_3   0x00000800
  #define FMC_PATT_ATTWAIT3_4   0x00001000
  #define FMC_PATT_ATTWAIT3_5   0x00002000
  #define FMC_PATT_ATTWAIT3_6   0x00004000
  #define FMC_PATT_ATTWAIT3_7   0x00008000
  #define FMC_PATT_ATTHOLD3     0x00FF0000	/* ATTHOLD[7:0] bits (Attribute memory hold time) */
  #define FMC_PATT_ATTHOLD3_0   0x00010000
  #define FMC_PATT_ATTHOLD3_1   0x00020000
  #define FMC_PATT_ATTHOLD3_2   0x00040000
  #define FMC_PATT_ATTHOLD3_3   0x00080000
  #define FMC_PATT_ATTHOLD3_4   0x00100000
  #define FMC_PATT_ATTHOLD3_5   0x00200000
  #define FMC_PATT_ATTHOLD3_6   0x00400000
  #define FMC_PATT_ATTHOLD3_7   0x00800000
  #define FMC_PATT_ATTHIZ3      0xFF000000	/* ATTHIZ[7:0] bits (Attribute memory databus HiZ time) */
  #define FMC_PATT_ATTHIZ3_0    0x01000000
  #define FMC_PATT_ATTHIZ3_1    0x02000000
  #define FMC_PATT_ATTHIZ3_2    0x04000000
  #define FMC_PATT_ATTHIZ3_3    0x08000000
  #define FMC_PATT_ATTHIZ3_4    0x10000000
  #define FMC_PATT_ATTHIZ3_5    0x20000000
  #define FMC_PATT_ATTHIZ3_6    0x40000000
  #define FMC_PATT_ATTHIZ3_7    0x80000000
#define TOFF_FMC_R_HPR      0x0090		/* (RW) NAND Flash Hamming Parity result registers 3*/
#define TOFF_FMC_R_HECCR    0x0094		/* (RW) NAND Flash Hamming ECC result registers 3 */
#define TOFF_FMC_R_BCHIER   0x0250		/* (RW) BCH Interrupt Enable Register */
#define TOFF_FMC_R_BCHISR   0x0254		/* (RW) BCH Interrupt Status Register */
#define TOFF_FMC_R_BCHICR   0x0258		/* (RW) BCH Interrupt Clear Register */
#define TOFF_FMC_R_BCHPBR1  0x0260		/* (RW) BCH Parity Bits Register 1 */
#define TOFF_FMC_R_BCHPBR2  0x0264		/* (RW) BCH Parity Bits Register 2 */
#define TOFF_FMC_R_BCHPBR3  0x0268		/* (RW) BCH Parity Bits Register 3 */
#define TOFF_FMC_R_BCHPBR4  0x026C		/* (RW) BCH Parity Bits Register 4 */
#define TOFF_FMC_R_BCHDSR0  0x027C		/* (RW) BCH Decoder Status Register 0 */
#define TOFF_FMC_R_BCHDSR1  0x0280		/* (RW) BCH Decoder Status Register 1 */
#define TOFF_FMC_R_BCHDSR2  0x0284		/* (RW) BCH Decoder Status Register 2 */
#define TOFF_FMC_R_BCHDSR3  0x0288		/* (RW) BCH Decoder Status Register 3 */
#define TOFF_FMC_R_BCHDSR4  0x028C		/* (RW) BCH Decoder Status Register 4 */
#define TOFF_FMC_R_HWCFGR2  0x03EC		/* (RW) FMC HW Configuration register */
#define TOFF_FMC_R_HWCFGR1  0x03F0		/* (RW) FMC HW Configuration register */
#define TOFF_FMC_R_VERR     0x03F4		/* (RW) FMC Version register */
#define TOFF_FMC_R_IDR      0x03F8		/* (RW) FMC Identification register */
#define TOFF_FMC_R_SIDR     0x03FC		/* (RW) FMC Size ID register */


/*
 * QUAD SERIAL PERIPHERAL INTERFACE
 */
#define TADR_QSPI_R_BASE    (MPU_AHB6_PERIPH_BASE + 0x3000)
#define TOFF_QUADSPI_CR     0x0000		/* (RW) QUADSPI Control register */
  #define QUADSPI_CR_EN         0x00000001	/* Enable */
  #define QUADSPI_CR_ABORT      0x00000002	/* Abort request */
  #define QUADSPI_CR_DMAEN      0x00000004	/* DMA Enable */
  #define QUADSPI_CR_TCEN       0x00000008	/* Timeout Counter Enable */
  #define QUADSPI_CR_SSHIFT     0x00000010	/* Sample Shift */
  #define QUADSPI_CR_DFM        0x00000040	/* Dual Flash Mode */
  #define QUADSPI_CR_FSEL       0x00000080	/* Flash Select */
  #define QUADSPI_CR_FTHRES     0x00001F00	/* FTHRES[4:0] FIFO Level */
  #define QUADSPI_CR_FTHRES_0   0x00000100
  #define QUADSPI_CR_FTHRES_1   0x00000200
  #define QUADSPI_CR_FTHRES_2   0x00000400
  #define QUADSPI_CR_FTHRES_3   0x00000800
  #define QUADSPI_CR_TEIE       0x00010000	/* Transfer Error Interrupt Enable */
  #define QUADSPI_CR_TCIE       0x00020000	/* Transfer Complete Interrupt Enable */
  #define QUADSPI_CR_FTIE       0x00040000	/* FIFO Threshold Interrupt Enable */
  #define QUADSPI_CR_SMIE       0x00080000	/* Status Match Interrupt Enable */
  #define QUADSPI_CR_TOIE       0x00100000	/* TimeOut Interrupt Enable */
  #define QUADSPI_CR_APMS       0x00400000	/* Automatic Polling Mode Stop */
  #define QUADSPI_CR_PMM        0x00800000	/* Polling Match Mode */
  #define QUADSPI_CR_PRESCALER  0xFF000000	/* PRESCALER[7:0] Clock prescaler */
  #define QUADSPI_CR_PRESCALER_0  0x01000000
  #define QUADSPI_CR_PRESCALER_1  0x02000000
  #define QUADSPI_CR_PRESCALER_2  0x04000000
  #define QUADSPI_CR_PRESCALER_3  0x08000000
  #define QUADSPI_CR_PRESCALER_4  0x10000000
  #define QUADSPI_CR_PRESCALER_5  0x20000000
  #define QUADSPI_CR_PRESCALER_6  0x40000000
  #define QUADSPI_CR_PRESCALER_7  0x80000000
#define TOFF_QUADSPI_DCR    0x0004		/* (RW) QUADSPI Device Configuration register */
  #define QUADSPI_DCR_CKMODE    0x00000001	/* Mode 0 / Mode 3 */
  #define QUADSPI_DCR_CSHT      0x00000700	/* CSHT[2:0]: ChipSelect High Time */
  #define QUADSPI_DCR_CSHT_0    0x00000100
  #define QUADSPI_DCR_CSHT_1    0x00000200
  #define QUADSPI_DCR_CSHT_2    0x00000400
  #define QUADSPI_DCR_FSIZE     0x001F0000	/* FSIZE[4:0]: Flash Size */
  #define QUADSPI_DCR_FSIZE_0   0x00010000
  #define QUADSPI_DCR_FSIZE_1   0x00020000
  #define QUADSPI_DCR_FSIZE_2   0x00040000
  #define QUADSPI_DCR_FSIZE_3   0x00080000
  #define QUADSPI_DCR_FSIZE_4   0x00100000
#define TOFF_QUADSPI_SR     0x0008		/* (RW) QUADSPI Status register */
  #define QUADSPI_SR_TEF        0x00000001	/* Transfer Error Flag */
  #define QUADSPI_SR_TCF        0x00000002	/* Transfer Complete Flag */
  #define QUADSPI_SR_FTF        0x00000004	/* FIFO Threshlod Flag */
  #define QUADSPI_SR_SMF        0x00000008	/* Status Match Flag */
  #define QUADSPI_SR_TOF        0x00000010	/* Timeout Flag */
  #define QUADSPI_SR_BUSY       0x00000020	/* Busy */
  #define QUADSPI_SR_FLEVEL     0x00001F00	/* FIFO Threshlod Flag */
  #define QUADSPI_SR_FLEVEL_0   0x00000100
  #define QUADSPI_SR_FLEVEL_1   0x00000200
  #define QUADSPI_SR_FLEVEL_2   0x00000400
  #define QUADSPI_SR_FLEVEL_3   0x00000800
  #define QUADSPI_SR_FLEVEL_4   0x00001000
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
  #define QUADSPI_CCR_DCYC_0    0x00040000
  #define QUADSPI_CCR_DCYC_1    0x00080000
  #define QUADSPI_CCR_DCYC_2    0x00100000
  #define QUADSPI_CCR_DCYC_3    0x00200000
  #define QUADSPI_CCR_DCYC_4    0x00400000
  #define QUADSPI_CCR_DMODE     0x03000000	/* DMODE[1:0]: Data Mode */
  #define QUADSPI_CCR_DMODE_0   0x01000000
  #define QUADSPI_CCR_DMODE_1   0x02000000
  #define QUADSPI_CCR_FMODE     0x0C000000	/* FMODE[1:0]: Functional Mode */
  #define QUADSPI_CCR_FMODE_0   0x04000000
  #define QUADSPI_CCR_FMODE_1   0x08000000
  #define QUADSPI_CCR_SIOO      0x10000000	/* SIOO: Send Instruction Only Once Mode */
  #define QUADSPI_CCR_DHHC      0x40000000	/* DHHC: Delay Half Hclk Cycle           */
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
#define TOFF_QUADSPI_HWCFGR 0x03F0		/* (RW) QUADSPI HW configuration register */
  #define QUADSPI_HWCFGR_FIFOSIZE  0x0000000F	/* size of FIFO in words */
  #define QUADSPI_HWCFGR_IDLENGTH  0x000000F0	/* size in bit of the FIFO pointer */
  #define QUADSPI_HWCFGR_PRESCVAL  0x00000F00	/* reset value of the prescaler */
#define TOFF_QUADSPI_VERR   0x03F4		/* (R)  QUADSPI version register */
  #define QUADSPI_VERR_MINREV      0x0000000F	/* Minor Revision number */
  #define QUADSPI_VERR_MAJREV      0x000000F0	/* Major Revision number */
#define TOFF_QUADSPI_IPIDR  0x03F8		/* (R)  QUADSPI dentification register */
#define TOFF_QUADSPI_SIDR   0x03FC		/* (R)  QUADSPI size identification register */


/*
 *  ETHERNET MAC
 */
#define TADR_ETH_BASE       (MPU_AHB6_PERIPH_BASE + 0xA000)
#define TOFF_ETH_MACCR        0x0000	/* (RW) Operating mode configuration register */
#define TOFF_ETH_MACECR       0x0004	/* (RW) Extended operating mode configuration register */
#define TOFF_ETH_MACPFR       0x0008	/* (RW) Packet filtering control register */
#define TOFF_ETH_MACWTR       0x000C	/* (RW) Watchdog timeout register */
#define TOFF_ETH_MACHT0R      0x0010	/* (RW) Hash Table 0 register */
#define TOFF_ETH_MACHT1R      0x0014	/* (RW) Hash Table 1 register */
#define TOFF_ETH_MACVTR       0x0050	/* (RW) VLAN tag register */
#define TOFF_ETH_MACVHTR      0x0058	/* (RW) VLAN Hash table register */
#define TOFF_ETH_MACVIR       0x0060	/* (RW) VLAN inclusion register */
#define TOFF_ETH_MACIVIR      0x0064	/* (RW) Inner VLAN inclusion register */
#define TOFF_ETH_MACQ0TXFCR   0x0070	/* (RW) Tx Queue 0 flow control register */
#define TOFF_ETH_MACRXFCR     0x0090	/* (RW) Rx flow control register  */
#define TOFF_ETH_MACTXQPMR    0x0098	/* (RW) Tx queue priority mapping 0 register */
#define TOFF_ETH_MACRXQC0R    0x00A0	/* (RW) Rx queue control 0 register */
#define TOFF_ETH_MACRXQC1R    0x00A4	/* (RW) Rx queue control 1 register */
#define TOFF_ETH_MACRXQC2R    0x00A8	/* (RW) Rx queue control 2 register */
#define TOFF_ETH_MACISR       0x00B0	/* (RW) Interrupt status register */
#define TOFF_ETH_MACIER       0x00B4	/* (RW) Interrupt enable register */
#define TOFF_ETH_MACRXTXSR    0x00B8	/* (RW) Rx Tx status register */
#define TOFF_ETH_MACPCSR      0x00C0	/* (RW) PMT control status register */
#define TOFF_ETH_MACRWKPFR    0x00C4	/* (RW) Remote wakeup packet filter register */
#define TOFF_ETH_MACLCSR      0x00D0	/* (RW) LPI control status register */
#define TOFF_ETH_MACLTCR      0x00D4	/* (RW) LPI timers control register */
#define TOFF_ETH_MACLETR      0x00D8	/* (RW) LPI entry timer register */
#define TOFF_ETH_MAC1USTCR    0x00DC	/* (RW) microsecond-tick counter register */
#define TOFF_ETH_MACPHYCSR    0x00F8	/* (RW) PHYIF control status register */
#define TOFF_ETH_MACVR        0x0110	/* (RW) Version register */
#define TOFF_ETH_MACDR        0x0114	/* (RW) Debug register */
#define TOFF_ETH_MACHWF1R     0x0120	/* (RW) HW feature 1 register */
#define TOFF_ETH_MACHWF2R     0x0124	/* (RW) HW feature 2 register */
#define TOFF_ETH_MACMDIOAR    0x0200	/* (RW) MDIO address register */
#define TOFF_ETH_MACMDIODR    0x0204	/* (RW) MDIO data register */
#define TOFF_ETH_MACA0HR      0x0300	/* (RW) Address 0 high register */
#define TOFF_ETH_MACA0LR      0x0304	/* (RW) Address 0 low register */
#define TOFF_ETH_MACA1HR      0x0308	/* (RW) Address 1 high register */
#define TOFF_ETH_MACA1LR      0x030C	/* (RW) Address 1 low register */
#define TOFF_ETH_MACA2HR      0x0310	/* (RW) Address 2 high register */
#define TOFF_ETH_MACA2LR      0x0314	/* (RW) Address 2 low register */
#define TOFF_ETH_MACA3HR      0x0318	/* (RW) Address 3 high register */
#define TOFF_ETH_MACA3LR      0x031C	/* (RW) Address 3 low register */
#define TOFF_ETH_MMCCR        0x0700	/* (RW) MMC control register */
#define TOFF_ETH_MMCRXIR      0x0704	/* (RW) MMC Rx interrupt register */
#define TOFF_ETH_MMCTXIR      0x0708	/* (RW) MMC Tx interrupt register */
#define TOFF_ETH_MMCRXIMR     0x070C	/* (RW) MMC Rx interrupt mask register */
#define TOFF_ETH_MMCTXIMR     0x0710	/* (RW) MMC Tx interrupt mask register */
#define TOFF_ETH_MMCTXSCGPR   0x074C	/* (RW) Tx single collision good packets register */
#define TOFF_ETH_MMCTXMCGPR   0x0750	/* (RW) Tx multiple collision good packets register */
#define TOFF_ETH_MMCTXPCGR    0x0768	/* (RW) Tx packet count good register */
#define TOFF_ETH_MMCRXCRCEPR  0x0794	/* (RW) Rx CRC error packets register */
#define TOFF_ETH_MMCRXAEPR    0x0798	/* (RW) Rx alignment error packets register */
#define TOFF_ETH_MMCRXUPGR    0x07C4	/* (RW) Rx unicast packets good register */
#define TOFF_ETH_MMCTXLPIMSTR 0x07EC	/* (RW) Tx LPI microsecond timer register */
#define TOFF_ETH_MMCTXLPITCR  0x07F0	/* (RW) Tx LPI transition counter register */
#define TOFF_ETH_MMCRXLPIMSTR 0x07F4	/* (RW) Rx LPI microsecond counter register */
#define TOFF_ETH_MMCRXLPITCR  0x07F8	/* (RW) Rx LPI transition counter register */
#define TOFF_ETH_MACL3L4C0R   0x0900	/* (RW) L3 and L4 control 0 register */
#define TOFF_ETH_MACL4A0R     0x0904	/* (RW) Layer4 address filter 0 register */
#define TOFF_ETH_MACL3A00R    0x0910	/* (RW) Layer 3 Address 0 filter 0 register */
#define TOFF_ETH_MACL3A10R    0x0914	/* (RW) Layer3 address 1 filter 0 register */
#define TOFF_ETH_MACL3A20     0x0918	/* (RW) Layer3 Address 2 filter 0 register */
#define TOFF_ETH_MACL3A30     0x091C	/* (RW) Layer3 Address 3 filter 0 register */
#define TOFF_ETH_MACL3L4C1R   0x0930	/* (RW) L3 and L4 control 1 register */
#define TOFF_ETH_MACL4A1R     0x0934	/* (RW) Layer 4 address filter 1 register */
#define TOFF_ETH_MACL3A01R    0x0940	/* (RW) Layer3 address 0 filter 1 Register */
#define TOFF_ETH_MACL3A11R    0x0944	/* (RW) Layer3 address 1 filter 1 register */
#define TOFF_ETH_MACL3A21R    0x0948	/* (RW) Layer3 address 2 filter 1 Register */
#define TOFF_ETH_MACL3A31R    0x094C	/* (RW) Layer3 address 3 filter 1 register */
#define TOFF_ETH_MACARPAR     0x0AE0	/* (RW) ARP address register */
#define TOFF_ETH_MACTSCR      0x0B00	/* (RW) Timestamp control Register */
#define TOFF_ETH_MACSSIR      0x0B04	/* (RW) Sub-second increment register */
#define TOFF_ETH_MACSTSR      0x0B08	/* (RW) System time seconds register */
#define TOFF_ETH_MACSTNR      0x0B0C	/* (RW) System time nanoseconds register */
#define TOFF_ETH_MACSTSUR     0x0B10	/* (RW) System time seconds update register */
#define TOFF_ETH_MACSTNUR     0x0B14	/* (RW) System time nanoseconds update register */
#define TOFF_ETH_MACTSAR      0x0B18	/* (RW) Timestamp addend register */
#define TOFF_ETH_MACTSSR      0x0B20	/* (RW) Timestamp status register */
#define TOFF_ETH_MACTXTSSNR   0x0B30	/* (RW) Tx timestamp status nanoseconds register */
#define TOFF_ETH_MACTXTSSSR   0x0B34	/* (RW) Tx timestamp status seconds register */
#define TOFF_ETH_MACACR       0x0B40	/* (RW) Auxiliary control register */
#define TOFF_ETH_MACATSNR     0x0B48	/* (RW) Auxiliary timestamp nanoseconds register */
#define TOFF_ETH_MACATSSR     0x0B4C	/* (RW) Auxiliary timestamp seconds register */
#define TOFF_ETH_MACTSIACR    0x0B50	/* (RW) Timestamp Ingress asymmetric correction register */
#define TOFF_ETH_MACTSEACR    0x0B54	/* (RW) Timestamp Egress asymmetric correction register */
#define TOFF_ETH_MACTSICNR    0x0B58	/* (RW) Timestamp Ingress correction nanosecond register */
#define TOFF_ETH_MACTSECNR    0x0B5C	/* (RW) Timestamp Egress correction nanosecond register */
#define TOFF_ETH_MACPPSCR     0x0B70	/* (RW) PPS control register [alternate] */
#define TOFF_ETH_MACPPSTTSR   0x0B80	/* (RW) PPS target time seconds register */
#define TOFF_ETH_MACPPSTTNR   0x0B84	/* (RW) PPS target time nanoseconds register */
#define TOFF_ETH_MACPPSIR     0x0B88	/* (RW) PPS interval register */
#define TOFF_ETH_MACPPSWR     0x0B8C	/* (RW) PPS width register */
#define TOFF_ETH_MACPOCR      0x0BC0	/* (RW) PTP Offload control register  */
#define TOFF_ETH_MACSPI0R     0x0BC4	/* (RW) PTP Source Port Identity 0 Register */
#define TOFF_ETH_MACSPI1R     0x0BC8	/* (RW) PTP Source port identity 1 register */
#define TOFF_ETH_MACSPI2R     0x0BCC	/* (RW) PTP Source port identity 2 register */
#define TOFF_ETH_MACLMIR      0x0BD0	/* (RW) Log message interval register */
#define TOFF_ETH_MTLOMR       0x0C00	/* (RW) Operating mode Register */
#define TOFF_ETH_MTLISR       0x0C20	/* (RW) Interrupt status Register */
#define TOFF_ETH_MTLTXQ0OMR   0x0D00	/* (RW) Tx queue 0 operating mode Register */
#define TOFF_ETH_MTLTXQ0UR    0x0D04	/* (RW) Tx queue 0 underflow register */
#define TOFF_ETH_MTLTXQ0DR    0x0D08	/* (RW) Tx queue 0 debug Register */
#define TOFF_ETH_MTLTXQ0ESR   0x0D14	/* (RW) Tx queue x ETS status Register */
#define TOFF_ETH_MTLQ0ICSR    0x0D2C	/* (RW) Queue 0 interrupt control status Register */
#define TOFF_ETH_MTLRXQ0OMR   0x0030	/* (RW) Rx queue 0 operating mode register */
#define TOFF_ETH_MTLRXQ0MPOCR 0x0D34	/* (RW) Rx queue 0 missed packet and overflow counter register */
#define TOFF_ETH_MTLRXQ0DR    0x0D38	/* (RW) Rx queue 0 debug register */
#define TOFF_ETH_MTLRXQ0CR    0x0D3C	/* (RW) Rx queue 0 control register */
#define TOFF_ETH_MTLTXQ1OMR   0x0D40	/* (RW) Tx queue 1 operating mode Register */
#define TOFF_ETH_MTLTXQ1UR    0x0D44	/* (RW) Tx queue 1 underflow register */
#define TOFF_ETH_MTLTXQ1DR    0x0D48	/* (RW) Tx queue 1 debug Register */
#define TOFF_ETH_MTLTXQ1ECR   0x0D50	/* (RW) Tx queue 1 ETS control Register */
#define TOFF_ETH_MTLTXQ1ESR   0x0D54	/* (RW) Tx queue x ETS status Register */
#define TOFF_ETH_MTLTXQ1QWR   0x0D58	/* (RW) Tx queue 1 quantum weight register */
#define TOFF_ETH_MTLTXQ1SSCR  0x0D5C	/* (RW) Tx queue 1 send slope credit Register */
#define TOFF_ETH_MTLTXQ1HCR   0x0D60	/* (RW) Tx Queue 1 hiCredit register */
#define TOFF_ETH_MTLTXQ1LCR   0x0D64	/* (RW) Tx queue 1 loCredit register */
#define TOFF_ETH_MTLQ1ICSR    0x0D6C	/* (RW) Queue 1 interrupt control status Register */
#define TOFF_ETH_MTLRXQ1OMR   0x0D70	/* (RW) Rx queue 1 operating mode register */
#define TOFF_ETH_MTLRXQ1MPOCR 0x0D74	/* (RW) Rx queue 1 missed packet and overflow counter register */
#define TOFF_ETH_MTLRXQ1DR    0x0D78	/* (RW) Rx queue 1 debug register */
#define TOFF_ETH_MTLRXQ1CR    0x0D7C	/* (RW) Rx queue 1 control register */
#define TOFF_ETH_DMAMR        0x1000	/* (RW) DMA mode register */
#define TOFF_ETH_DMASBMR      0x1000	/* (RW) System bus mode register */
#define TOFF_ETH_DMAISR       0x1000	/* (RW) Interrupt status register */
#define TOFF_ETH_DMADSR       0x1000	/* (RW) Debug status register */
#define TOFF_ETH_DMAA4TXACR   0x1000	/* (RW) AXI4 transmit channel ACE control register */
#define TOFF_ETH_DMAA4RXACR   0x1000	/* (RW) AXI4 receive channel ACE control register */
#define TOFF_ETH_DMAA4DACR    0x1028	/* (RW) AXI4 descriptor ACE control register */
#define TOFF_ETH_DMAC0CR      0x1100	/* (RW) Channel 0 control register */
#define TOFF_ETH_DMAC0TXCR    0x1104	/* (RW) Channel 0 transmit control register */
#define TOFF_ETH_DMAC0RXCR    0x1108	/* (RW) Channel 0 receive control register */
#define TOFF_ETH_DMAC0TXDLAR  0x1114	/* (RW) Channel 0 Tx descriptor list address register */
#define TOFF_ETH_DMAC0RXDLAR  0x111C	/* (RW) Channel 0 Rx descriptor list address register */
#define TOFF_ETH_DMAC0TXDTPR  0x1120	/* (RW) Channel 0 Tx descriptor tail pointer register */
#define TOFF_ETH_DMAC0RXDTPR  0x1128	/* (RW) Channel 0 Rx descriptor tail pointer register */
#define TOFF_ETH_DMAC0TXRLR   0x112C	/* (RW) Channel 0 Tx descriptor ring length register */
#define TOFF_ETH_DMAC0RXRLR   0x1130	/* (RW) Channel 0 Rx descriptor ring length register */
#define TOFF_ETH_DMAC0IER     0x1134	/* (RW) Channel 0 interrupt enable register */
#define TOFF_ETH_DMAC0RXIWTR  0x1138	/* (RW) Channel 0 Rx interrupt watchdog timer register */
#define TOFF_ETH_DMAC0SFCSR   0x113C	/* (RW) Channel 0 slot function control status register */
#define TOFF_ETH_DMAC0CATXDR  0x1144	/* (RW) Channel 0 current application transmit descriptor register */
#define TOFF_ETH_DMAC0CARXDR  0x114C	/* (RW) Channel 0 current application receive descriptor register */
#define TOFF_ETH_DMAC0CATXBR  0x1154	/* (RW) Channel 0 current application transmit buffer register */
#define TOFF_ETH_DMAC0CARXBR  0x115C	/* (RW) Channel 0 current application receive buffer register */
#define TOFF_ETH_DMAC0SR      0x1160	/* (RW) Channel 0 status register */
#define TOFF_ETH_DMAC0MFCR    0x116C	/* (RW) Channel 0 missed frame count register */
#define TOFF_ETH_DMAC1CR      0x1180	/* (RW) Channel 1 control register */
#define TOFF_ETH_DMAC1TXCR    0x1184	/* (RW) Channel 1 transmit control register */
#define TOFF_ETH_DMAC1TXDLAR  0x1194	/* (RW) Channel 1 Tx descriptor list address register */
#define TOFF_ETH_DMAC1TXDTPR  0x11A0	/* (RW) Channel 1 Tx descriptor tail pointer register */
#define TOFF_ETH_DMAC1TXRLR   0x11AC	/* (RW) Channel 1 Tx descriptor ring length register */
#define TOFF_ETH_DMAC1IER     0x11B4	/* (RW) Channel 1 interrupt enable register */
#define TOFF_ETH_DMAC1SFCSR   0x11BC	/* (RW) Channel 1 slot function control status register */
#define TOFF_ETH_DMAC1CATXDR  0x11C4	/* (RW) Channel 1 current application transmit descriptor register */
#define TOFF_ETH_DMAC1CATXBR  0x11D4	/* (RW) Channel 1 current application transmit buffer register */
#define TOFF_ETH_DMAC1SR      0x11E0	/* (RW) Channel 1 status register */
#define TOFF_ETH_DMAC1MFCR    0x11EC	/* (RW) Channel 1 missed frame count register */


/*
 *  USB_EHCI CAPABILITY RREGISTERS
 */
#define TADR_USB1HSFSP2_BASE (MPU_AHB6_PERIPH_BASE + 0xC000)
#define TADR_USB1HSFSP1_BASE (MPU_AHB6_PERIPH_BASE + 0xD000)
#define TOFF_USB_EHCI_HCCAPBASE         0x0000	/* (RW) Capability Register register */
#define TOFF_USB_EHCI_HCSPARAMS         0x0004	/* (RW) Structural Parameter register */
#define TOFF_USB_EHCI_HCCPARAMS         0x0008	/* (RW) Capability Parameter register */
#define TOFF_USB_EHCI_USBCMD            0x0010	/* (RW) USB Command register */
#define TOFF_USB_EHCI_USBSTS            0x0014	/* (RW) USB Status register */
#define TOFF_USB_EHCI_USBINTR           0x0018	/* (RW) USB Interrupt Enable register */
#define TOFF_USB_EHCI_FRINDEX           0x001C	/* (RW) USB Frame Index register */
#define TOFF_USB_EHCI_CTRLDSSEGMENT     0x0020	/* (RW) 4G Segment Selector register */
#define TOFF_USB_EHCI_PERIODICLISTBASE  0x0024	/* (RW) Periodic Frame List Base Address register */
#define TOFF_USB_EHCI_ASYNCLISTADDR     0x0028	/* (RW) Asynchronous List Address register */


/*
 *  GPU HOST INTERFACE REGISTERS
 */
#define TADR_GPU_BASE       (MPU_AHB6_PERIPH_BASE + 0x1000000)
#define TOFF_GPU_CLKCTRLR     0x0000	/* (RW) Clock control register */
#define TOFF_GPU_IDLESR       0x0004	/* (RW) IDLE status register */
#define TOFF_GPU_AXICFGR      0x0008	/* (RW) AXI Configuration register */
#define TOFF_GPU_AXISR        0x000C	/* (RW) AXI Status register */
#define TOFF_GPU_INTRACK      0x0010	/* (RW) Interrupt acknowledge register */
#define TOFF_GPU_INTREN       0x0014	/* (RW) Interrupt enable register */
#define TOFF_GPU_CHIPID       0x0018	/* (RW) Chip ID */
#define TOFF_GPU_CHIPREV      0x001C	/* (RW) Chip revision register */
#define TOFF_GPU_CHIPDATE     0x0020	/* (RW) Release date register */
#define TOFF_GPU_CHIPTIME     0x0024	/* (RW) Release Time register */
#define TOFF_GPU_TOTALCYCLES  0x0028	/* (RW) Total number of Cycles register */
#define TOFF_GPU_PRODUCTID    0x002C	/* (RW) Product ID register */
#define TOFF_GPU_POWERCTRLR   0x0030	/* (RW) Power control register */
#define TOFF_GPU_MMUCTRLR     0x0034	/* (RW) MMU control register */
#define TOFF_GPU_MEMDEBUG     0x0038	/* (RW) Memory debug register */
#define TOFF_GPU_CMDBUFADDR   0x003C	/* (RW) Command buffer base address register */
#define TOFF_GPU_CMDBUFCTRL   0x0040	/* (RW) Command buffer control register */


/*
 *  DSI CONTROLLER
 */
#define TADR_DSI_BASE       (MPU_APB4_PERIPH_BASE + 0x0000)
#define TOFF_DSI_VR         0x0000		/* (RW) DSI Host Version Register */
#define TOFF_DSI_CR         0x0004		/* (RW) DSI Host Control Register */
#define TOFF_DSI_CCR        0x0008		/* (RW) DSI HOST Clock Control Register */
#define TOFF_DSI_LVCIDR     0x000C		/* (RW) DSI Host LTDC VCID Register */
#define TOFF_DSI_LCOLCR     0x0010		/* (RW) DSI Host LTDC Color Coding Register */
#define TOFF_DSI_LPCR       0x0014		/* (RW) DSI Host LTDC Polarity Configuration Register,*/
#define TOFF_DSI_LPMCR      0x0018		/* (RW) DSI Host Low-Power Mode Configuration Register */
#define TOFF_DSI_PCR        0x002C		/* (RW) DSI Host Protocol Configuration Register */
#define TOFF_DSI_GVCIDR     0x0030		/* (RW) DSI Host Generic VCID Register */
#define TOFF_DSI_MCR        0x0034		/* (RW) DSI Host Mode Configuration Register */
#define TOFF_DSI_VMCR       0x0038		/* (RW) DSI Host Video Mode Configuration Register */
#define TOFF_DSI_VPCR       0x003C		/* (RW) DSI Host Video Packet Configuration Register */
#define TOFF_DSI_VCCR       0x0040		/* (RW) DSI Host Video Chunks Configuration Register */
#define TOFF_DSI_VNPCR      0x0044		/* (RW) DSI Host Video Null Packet Configuration Register */
#define TOFF_DSI_VHSACR     0x0048		/* (RW) DSI Host Video HSA Configuration Register */
#define TOFF_DSI_VHBPCR     0x004C		/* (RW) DSI Host Video HBP Configuration Register */
#define TOFF_DSI_VLCR       0x0050		/* (RW) DSI Host Video Line Configuration Register */
#define TOFF_DSI_VVSACR     0x0054		/* (RW) DSI Host Video VSA Configuration Register */
#define TOFF_DSI_VVBPCR     0x0058		/* (RW) DSI Host Video VBP Configuration Register */
#define TOFF_DSI_VVFPCR     0x005C		/* (RW) DSI Host Video VFP Configuration Register */
#define TOFF_DSI_VVACR      0x0060		/* (RW) DSI Host Video VA Configuration Register */
#define TOFF_DSI_LCCR       0x0064		/* (RW) DSI Host LTDC Command Configuration Register */
#define TOFF_DSI_CMCR       0x0068		/* (RW) DSI Host Command Mode Configuration Register */
#define TOFF_DSI_GHCR       0x006C		/* (RW) DSI Host Generic Header Configuration Register */
#define TOFF_DSI_GPDR       0x0070		/* (RW) DSI Host Generic Payload Data Register */
#define TOFF_DSI_GPSR       0x0074		/* (RW) DSI Host Generic Packet Status Register */
#define TOFF_DSI_TCCR       0x0078		/* (RW) DSI Host Timeout Counter Configuration Register[0-5] */
#define TOFF_DSI_TDCR       0x0090		/* (RW) DSI Host 3D Configuration Register */
#define TOFF_DSI_CLCR       0x0094		/* (RW) DSI Host Clock Lane Configuration Register */
#define TOFF_DSI_CLTCR      0x0098		/* (RW) DSI Host Clock Lane Timer Configuration Register */
#define TOFF_DSI_DLTCR      0x009C		/* (RW) DSI Host Data Lane Timer Configuration Register */
#define TOFF_DSI_PCTLR      0x00A0		/* (RW) DSI Host PHY Control Register */
#define TOFF_DSI_PCONFR     0x00A4		/* (RW) DSI Host PHY Configuration Register */
#define TOFF_DSI_PUCR       0x00A8		/* (RW) DSI Host PHY ULPS Control Register */
#define TOFF_DSI_PTTCR      0x00AC		/* (RW) DSI Host PHY TX Triggers Configuration Register */
#define TOFF_DSI_PSR        0x00B0		/* (RW) DSI Host PHY Status Register */
#define TOFF_DSI_ISR        0x00BC		/* (RW) DSI Host Interrupt & Status Register[0,1] */
#define TOFF_DSI_IER        0x00C4		/* (RW) DSI Host Interrupt Enable Register[0,1] */
#define TOFF_DSI_FIR        0x00D8		/* (RW) DSI Host Force Interrupt Register[0,1] */
#define TOFF_DSI_DLTRCR     0x00F4		/* (RW) DSI Host Data Lane Timer Read Configuration Register */
#define TOFF_DSI_VSCR       0x0100		/* (RW) DSI Host Video Shadow Control Register */
#define TOFF_DSI_LCVCIDR    0x010C		/* (RW) DSI Host LTDC Current VCID Register */
#define TOFF_DSI_LCCCR      0x0110		/* (RW) DSI Host LTDC Current Color Coding Register */
#define TOFF_DSI_LPMCCR     0x0118		/* (RW) DSI Host Low-power Mode Current Configuration Register */
#define TOFF_DSI_VMCCR      0x0138		/* (RW) DSI Host Video Mode Current Configuration Register */
#define TOFF_DSI_VPCCR      0x013C		/* (RW) DSI Host Video Packet Current Configuration Register */
#define TOFF_DSI_VCCCR      0x0140		/* (RW) DSI Host Video Chuncks Current Configuration Register */
#define TOFF_DSI_VNPCCR     0x0144		/* (RW) DSI Host Video Null Packet Current Configuration Register */
#define TOFF_DSI_VHSACCR    0x0148		/* (RW) DSI Host Video HSA Current Configuration Register */
#define TOFF_DSI_VHBPCCR    0x014C		/* (RW) DSI Host Video HBP Current Configuration Register */
#define TOFF_DSI_VLCCR      0x0150		/* (RW) DSI Host Video Line Current Configuration Register */
#define TOFF_DSI_VVSACCR    0x0154		/* (RW) DSI Host Video VSA Current Configuration Register */
#define TOFF_DSI_VVBPCCR    0x0158		/* (RW) DSI Host Video VBP Current Configuration Register */
#define TOFF_DSI_VVFPCCR    0x015C		/* (RW) DSI Host Video VFP Current Configuration Register */
#define TOFF_DSI_VVACCR     0x0160		/* (RW) DSI Host Video VA Current Configuration Register */
#define TOFF_DSI_TDCCR      0x0190		/* (RW) DSI Host 3D Current Configuration Register */
#define TOFF_DSI_WCFGR      0x0400		/* (RW) DSI Wrapper Configuration Register */
#define TOFF_DSI_WCR        0x0404		/* (RW) DSI Wrapper Control Register */
#define TOFF_DSI_WIER       0x0408		/* (RW) DSI Wrapper Interrupt Enable Register */
#define TOFF_DSI_WISR       0x040C		/* (RW) DSI Wrapper Interrupt and Status Register */
#define TOFF_DSI_WIFCR      0x0410		/* (RW) DSI Wrapper Interrupt Flag Clear Register */
#define TOFF_DSI_WPCR       0x0418		/* (RW) DSI Wrapper PHY Configuration Register[0,1] */
#define TOFF_DSI_WRPCR      0x0430		/* (RW) DSI Wrapper Regulator and PLL Control Register */
#define TOFF_DSI_HWCFGR     0x07F0		/* (RW) DSI Host hardware configuration register */
#define TOFF_DSI_VERR       0x07F4		/* (RW) DSI Host version register */
#define TOFF_DSI_IPIDR      0x07F8		/* (RW) DSI Host Identification register */
#define TOFF_DSI_SIDR       0x07FC		/* (RW) DSI Host Size ID register */


/*
 *  LCD-TFT DISPLAY CONTROLLER
 */
#define TADR_LTDC_BASE      (MPU_APB4_PERIPH_BASE + 0x1000)
#define TADR_LTDC_LAYER1    (TADR_LTDC_BASE + 0x84)
#define TADR_LTDC_LAYER2    (TADR_LTDC_BASE + 0x104)
#define TOFF_LTDC_SSCR      0x0008		/* (RW) LTDC Synchronization Size Configuration Register */
#define TOFF_LTDC_BPCR      0x000C		/* (RW) LTDC Back Porch Configuration Register */
#define TOFF_LTDC_AWCR      0x0010		/* (RW) LTDC Active Width Configuration Register */
#define TOFF_LTDC_TWCR      0x0014		/* (RW) LTDC Total Width Configuration Register */
#define TOFF_LTDC_GCR       0x0018		/* (RW) LTDC Global Control Register */
#define TOFF_LTDC_SRCR      0x0024		/* (RW) LTDC Shadow Reload Configuration Register */
#define TOFF_LTDC_BCCR      0x002C		/* (RW) LTDC Background Color Configuration Register */
#define TOFF_LTDC_IER       0x0034		/* (RW) LTDC Interrupt Enable Register */
#define TOFF_LTDC_ISR       0x0038		/* (RW) LTDC Interrupt Status Register */
#define TOFF_LTDC_ICR       0x003C		/* (RW) LTDC Interrupt Clear Register */
#define TOFF_LTDC_LIPCR     0x0040		/* (RW) LTDC Line Interrupt Position Configuration Register */
#define TOFF_LTDC_CPSR      0x0044		/* (RW) LTDC Current Position Status Register */
#define TOFF_LTDC_CDSR      0x0048		/* (RW) LTDC Current Display Status Register */

/*
 *  LCD-TFT DISPLAY LAYER X CONTROLLER (WINDOW)
 */
#define LTDC_WINDOW_SIZE    128
#define TOFF_LTDCW_CR       0x0000		/* (RW) LTDC Layerx Control Register :0x84 */
#define TOFF_LTDCW_WHPCR    0x0004		/* (RW) LTDC Layerx Window Horizontal :0x88 */
#define TOFF_LTDCW_WVPCR    0x0008		/* (RW) LTDC Layerx Window Vertical Position Configuration Register :0x8C */
#define TOFF_LTDCW_CKCR     0x000C		/* (RW) LTDC Layerx Color Keying Configuration Register :0x90 */
#define TOFF_LTDCW_PFCR     0x0010		/* (RW) LTDC Layerx Pixel Format Configuration Register :0x94 */
#define TOFF_LTDCW_CACR     0x0014		/* (RW) LTDC Layerx Constant Alpha Configuration Register :0x98 */
#define TOFF_LTDCW_DCCR     0x0018		/* (RW) LTDC Layerx Default Color Configuration Register :0x9C */
#define TOFF_LTDCW_BFCR     0x001C		/* (RW) LTDC Layerx Blending Factors Configuration Register :0xA0 */
#define TOFF_LTDCW_CFBAR    0x0028		/* (RW) LTDC Layerx Color Frame Buffer Address Register :0xAC */
#define TOFF_LTDCW_CFBLR    0x002C		/* (RW) LTDC Layerx Color Frame Buffer Length Register :0xB0 */
#define TOFF_LTDCW_CFBLNR   0x0030		/* (RW) LTDC Layerx ColorFrame Buffer Line Number Register :0xB4 */
#define TOFF_LTDCW_CLUTWR   0x003C		/* (RW) LTDC Layerx CLUT Write Register :0xC0 */


/*
 *  INDEPENDENT WATCHDOG
 */
#define TADR_IWDG2_BASE     (MPU_APB4_PERIPH_BASE + 0x2000)
#define TADR_IWDG1_BASE     (MPU_APB5_PERIPH_BASE + 0x3000)
#define TOFF_IWDG_KR        0x0000		/* (RW) IWDG Key register */
  #define IWDG_KR_KEY           0x0000FFFF	/* Key value (write only, read 0000h)  */
#define TOFF_IWDG_PR        0x0004		/* (RW) IWDG Prescaler register */
  #define IWDG_PR_PR            0x00000007	/* PR[2:0] (Prescaler divider) */
  #define IWDG_PR_PR_0          0x00000001
  #define IWDG_PR_PR_1          0x00000002
  #define IWDG_PR_PR_2          0x00000004
  #define IWDG_PR_PR_3          0x00000008
#define TOFF_IWDG_RLR       0x0008		/* (RW) IWDG Reload register */
  #define IWDG_RLR_RL           0x00000FFF	/* Watchdog counter reload value */
#define TOFF_IWDG_SR        0x000C		/* (RW) IWDG Status register */
  #define IWDG_SR_PVU           0x00000001	/* Watchdog prescaler value update */
  #define IWDG_SR_RVU           0x00000002	/* Watchdog counter reload value update */
  #define IWDG_SR_WVU           0x00000004	/* Watchdog counter window value update */
  #define IWDG_SR_EWU           0x00000008	/* Watchdog interrupt comparator value update */
  #define IWDG_SR_EWIF          0x00004000	/* Watchdog early interrupt flag */
#define TOFF_IWDG_WINR      0x0010		/* (RW) IWDG Window register */
  #define IWDG_WINR_WIN         0x00000FFF	/* Watchdog counter window value */
#define TOFF_IWDG_EWCR      0x0014		/* (RW) IWDG Window register */
  #define IWDG_EWCR_EWIT        0x00000FFF	/* Watchdog early wakeup comparator value */
  #define IWDG_EWCR_EWIC        0x00004000	/* Watchdog early interrupt acknowledge */
  #define IWDG_EWCR_EWIE        0x00008000	/* Watchdog early interrupt enable */
#define TOFF_IWDG_HWCFGR    0x03F0		/* (R)  IWDG hardware configuration register */
  #define IWDG_HWCFGR_WINDOW    0x0000000F	/* Support of Window function */
  #define IWDG_HWCFGR_PR_DEFAULT 0x000000F0	/* Prescaler default value */
#define TOFF_IWDG_VERR      0x03F4		/* (R)  IWDG version register */
  #define IWDG_VERR_MINREV      0x0000000F	/* Minor Revision number */
  #define IWDG_VERR_MAJREV      0x000000F0	/* Major Revision number */
#define TOFF_IWDG_IDR       0x03F8		/* (R)  IWDG identification register */
#define TOFF_IWDG_SIDR      0x03FC		/* (R)  IWDG size identification register */


/*
 *  DDRC DDR3/LPDDR2 CONTROLLER (DDRCTRL)
 */
#define TADR_DDRC_BASE      (MPU_APB4_PERIPH_BASE + 0x3000)
#define TOFF_DDRC_MSTR      0x0000		/* (RW) DDR_PHY: PUBL revision Identification register */

/*
 *  DDRPHYC DDR PHYSICAL INTERFACE CONTROL
 */
#define TADR_DDRPHYC_BASE   (MPU_APB4_PERIPH_BASE + 0x4000)
#define TOFF_DDR_PTY_RIDR       0x0000	/* (RW) DDR_PHY: PUBL revision Identification register */
#define TOFF_DDR_PTY_PIR        0x0004	/* (RW) DDR_PHY: PUBL PHY Initialization register */
#define TOFF_DDR_PTY_PGCR       0x0008	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_PGSR       0x000C	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DLLGCR     0x0010	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_ACDLLCR    0x0014	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_PTR0       0x0018	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_PTR1       0x001C	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_PTR2       0x0020	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_ACIOCR     0x0024	/* (RW) DDR_PHY: PUBL AC I/O Configuration Register */
#define TOFF_DDR_PTY_DXCCR      0x0028	/* (RW) DDR_PHY: PUBL DATX8 Common Configuration Register */
#define TOFF_DDR_PTY_DSGCR      0x002C	/* (RW) DDR_PHY: PUBL DDR System General Configuration Register */
#define TOFF_DDR_PTY_DCR        0x0030	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DTPR0      0x0034	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DTPR1      0x0038	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DTPR2      0x003C	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_MR0        0x0040	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_MR1        0x0044	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_MR2        0x0048	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_MR3        0x004C	/* (RW) DDR_PHY:B */
#define TOFF_DDR_PTY_ODTCR      0x0050	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_DTAR       0x0054	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DTDR0      0x0058	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DTDR1      0x005C	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DCUAR      0x00C0	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_DCUDR      0x00C4	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DCURR      0x00C8	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DCULR      0x00CC	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DCUGCR     0x00D0	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_DCUTPR     0x00D4	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DCUSR0     0x00D8	/* (RW) DDR_PHY:B */
#define TOFF_DDR_PTY_DCUSR1     0x00DC	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTRR     0x0100	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTMSKR0  0x0104	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTMSKR1  0x0108	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTWCR    0x010C	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_BISTLSR    0x0110	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTAR0    0x0114	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTAR1    0x0118	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_BISTAR2    0x011C	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTUDPR   0x0120	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTGSR    0x0124	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTWER    0x0128	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTBER0   0x012C	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTBER1   0x0130	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTBER2   0x0134	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTWCSR   0x0138	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTFWR0   0x013C	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_BISTFWR1   0x0140	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_GPR0       0x0178	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_GPR1       0x017C	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_ZQ0CR0     0x0180	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_ZQ0CR1     0x0184	/* (RW) DDR_PHY:B */
#define TOFF_DDR_PTY_ZQ0SR0     0x0188	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_ZQ0SR1     0x018C	/* (RW) DDR_PHY:B */
#define TOFF_DDR_PTY_DX0GCR     0x01C0	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX0GSR0    0x01C4	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_DX0GSR1    0x01C8	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX0DLLCR   0x01CC	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX0DQTR    0x01D0	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX0DQSTR   0x01D4	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX1GCR     0x0200	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX1GSR0    0x0204	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_DX1GSR1    0x0208	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX1DLLCR   0x020C	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX1DQTR    0x0210	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX1DQSTR   0x0214	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX2GCR     0x0240	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX2GSR0    0x0244	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_DX2GSR1    0x0248	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX2DLLCR   0x024C	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX2DQTR    0x0250	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX2DQSTR   0x0254	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX3GCR     0x0280	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX3GSR0    0x0284	/* (RW) DDR_PHY:H */
#define TOFF_DDR_PTY_DX3GSR1    0x0288	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX3DLLCR   0x028C	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX3DQTR    0x0290	/* (RW) DDR_PHY: */
#define TOFF_DDR_PTY_DX3DQSTR   0x0294	/* (RW) DDR_PHY: */


/*
 *  USBPHYC  USB HS PHY CONTROL
 */
#define TADR_USBPHYC_BASE       (MPU_APB4_PERIPH_BASE + 0x6000)
#define TOFF_USBPHYC_PLL        0x0000		/* (RW) USBPHYC PLL control register */
#define TOFF_USBPHYC_MISC       0x0008		/* (RW) USBPHYC Misc Control register */
#define TOFF_USBPHYC_VERR       0x03F4		/* (RW) USBPHYC Version register */
#define TOFF_USBPHYC_IPIDR      0x03F8		/* (RW) USBPHYC Identification register */
#define TOFF_USBPHYC_SIDR       0x03FC		/* (RW) USBPHYC Size ID register */

/*
 * USBPHYC  USB HS PHY CONTROL PHYx
 */
#define TADR_USBPHYC_PHY1_BASE  (TADR_USBPHYC_BASE + 0x100)
#define TADR_USBPHYC_PHY2_BASE  (TADR_USBPHYC_BASE + 0x200)
#define TOFF_USBPHYC_TUNE       0x0000		/* (RW) USBPHYC x TUNE register  ter */

/*
 *  REAL-TIME CLOCK
 */
#define TADR_RTC_BASE       (MPU_APB5_PERIPH_BASE + 0x4000)
#define TOFF_RTC_TR         0x0000		/* (RW) RTC time register */
  #define RTC_TR_SU             0x0000000F
  #define RTC_TR_SU_0           0x00000001
  #define RTC_TR_SU_1           0x00000002
  #define RTC_TR_SU_2           0x00000004
  #define RTC_TR_SU_3           0x00000008
  #define RTC_TR_ST             0x00000070
  #define RTC_TR_ST_0           0x00000010
  #define RTC_TR_ST_1           0x00000020
  #define RTC_TR_ST_2           0x00000040
  #define RTC_TR_MNU            0x00000F00
  #define RTC_TR_MNU_0          0x00000100
  #define RTC_TR_MNU_1          0x00000200
  #define RTC_TR_MNU_2          0x00000400
  #define RTC_TR_MNU_3          0x00000800
  #define RTC_TR_MNT            0x00007000
  #define RTC_TR_MNT_0          0x00001000
  #define RTC_TR_MNT_1          0x00002000
  #define RTC_TR_MNT_2          0x00004000
  #define RTC_TR_HU             0x000F0000
  #define RTC_TR_HU_0           0x00010000
  #define RTC_TR_HU_1           0x00020000
  #define RTC_TR_HU_2           0x00040000
  #define RTC_TR_HU_3           0x00080000
  #define RTC_TR_HT             0x00300000
  #define RTC_TR_HT_0           0x00100000
  #define RTC_TR_HT_1           0x00200000
  #define RTC_TR_PM             0x00400000
#define TOFF_RTC_DR         0x0004		/* (RW) RTC date register */
  #define RTC_DR_DU             0x0000000F
  #define RTC_DR_DU_0           0x00000001
  #define RTC_DR_DU_1           0x00000002
  #define RTC_DR_DU_2           0x00000004
  #define RTC_DR_DU_3           0x00000008
  #define RTC_DR_DT             0x00000030
  #define RTC_DR_DT_0           0x00000010
  #define RTC_DR_DT_1           0x00000020
  #define RTC_DR_MU             0x00000F00
  #define RTC_DR_MU_0           0x00000100
  #define RTC_DR_MU_1           0x00000200
  #define RTC_DR_MU_2           0x00000400
  #define RTC_DR_MU_3           0x00000800
  #define RTC_DR_WDU            0x0000E000
  #define RTC_DR_WDU_0          0x00002000
  #define RTC_DR_WDU_1          0x00004000
  #define RTC_DR_WDU_2          0x00008000
  #define RTC_DR_MT             0x00001000
  #define RTC_DR_YU             0x000F0000
  #define RTC_DR_YU_0           0x00010000
  #define RTC_DR_YU_1           0x00020000
  #define RTC_DR_YU_2           0x00040000
  #define RTC_DR_YU_3           0x00080000
  #define RTC_DR_YT             0x00F00000
  #define RTC_DR_YT_0           0x00100000
  #define RTC_DR_YT_1           0x00200000
  #define RTC_DR_YT_2           0x00400000
  #define RTC_DR_YT_3           0x00800000
#define TOFF_RTC_SSR        0x0008		/* (RW) RTC sub second register */
#define TOFF_RTC_ICSR       0x000C		/* (RW) RTC initialization control and status register */
  #define RTC_ICSR_ALRAWF       0x00000001
  #define RTC_ICSR_ALRBWF       0x00000002
  #define RTC_ICSR_WUTWF        0x00000004
  #define RTC_ICSR_SHPF         0x00000008
  #define RTC_ICSR_INITS        0x00000010
  #define RTC_ICSR_RSF          0x00000020
  #define RTC_ICSR_INITF        0x00000040
  #define RTC_ICSR_INIT         0x00000080
  #define RTC_ICSR_RECALPF      0x00010000
#define TOFF_RTC_PRER       0x0010		/* (RW) RTC prescaler register */
  #define RTC_PRER_PREDIV_S     0x00007FFF
  #define RTC_PRER_PREDIV_A     0x007F0000
#define TOFF_RTC_WUTR       0x0014		/* (RW) RTC wakeup timer register */
#define TOFF_RTC_CR         0x0018		/* (RW) RTC control register */
  #define RTC_CR_WUCKSEL        0x00000007
  #define RTC_CR_WUCKSEL_0      0x00000001
  #define RTC_CR_WUCKSEL_1      0x00000002
  #define RTC_CR_WUCKSEL_2      0x00000004
  #define RTC_CR_TSEDGE         0x00000008
  #define RTC_CR_REFCKON        0x00000010
  #define RTC_CR_BYPSHAD        0x00000020
  #define RTC_CR_FMT            0x00000040
  #define RTC_CR_ALRAE          0x00000100
  #define RTC_CR_ALRBE          0x00000200
  #define RTC_CR_WUTE           0x00000400
  #define RTC_CR_TSE            0x00000800
  #define RTC_CR_ALRAIE         0x00001000
  #define RTC_CR_ALRBIE         0x00002000
  #define RTC_CR_WUTIE          0x00004000
  #define RTC_CR_TSIE           0x00008000
  #define RTC_CR_ADD1H          0x00010000
  #define RTC_CR_SUB1H          0x00020000
  #define RTC_CR_BKP            0x00040000
  #define RTC_CR_COSEL          0x00080000
  #define RTC_CR_POL            0x00100000
  #define RTC_CR_OSEL           0x00600000
  #define RTC_CR_OSEL_0         0x00200000
  #define RTC_CR_OSEL_1         0x00400000
  #define RTC_CR_COE            0x00800000
  #define RTC_CR_ITSE           0x01000000
  #define RTC_CR_TAMPTS         0x02000000	/* Activate timestamp on tamper detection event  */
  #define RTC_CR_TAMPOE         0x04000000	/* Tamper detection output enable on TAMPALARM  */
  #define RTC_CR_TAMPALRM_PU    0x20000000	/* TAMPALARM output pull-up config */
  #define RTC_CR_TAMPALRM_TYPE  0x40000000	/* TAMPALARM output type  */
  #define RTC_CR_OUT2EN         0x80000000	/* RTC_OUT2 output enable */
#define TOFF_RTC_SMCR       0x0020		/* (RW) RTC secure mode control register */
  #define RTC_SMCR_ALRADPROT    0x00000001
  #define RTC_SMCR_ALRBDPROT    0x00000002
  #define RTC_SMCR_WUTDPROT     0x00000004
  #define RTC_SMCR_TSDPROT      0x00000008
  #define RTC_SMCR_CALDPROT     0x00002000
  #define RTC_SMCR_INITDPROT    0x00004000
  #define RTC_SMCR_DECPROT      0x00008000
#define TOFF_RTC_WPR        0x0024		/* (RW) RTC write protection register */
  #define RTC_WPR_KEY           0x000000FF
#define TOFF_RTC_CALR       0x0028		/* (RW) RTC calibration register */
  #define RTC_CALR_CALM         0x000001FF
  #define RTC_CALR_CALM_0       0x00000001
  #define RTC_CALR_CALM_1       0x00000002
  #define RTC_CALR_CALM_2       0x00000004
  #define RTC_CALR_CALM_3       0x00000008
  #define RTC_CALR_CALM_4       0x00000010
  #define RTC_CALR_CALM_5       0x00000020
  #define RTC_CALR_CALM_6       0x00000040
  #define RTC_CALR_CALM_7       0x00000080
  #define RTC_CALR_CALM_8       0x00000100
  #define RTC_CALR_CALW16       0x00002000
  #define RTC_CALR_CALW8        0x00004000
  #define RTC_CALR_CALP         0x00008000
#define TOFF_RTC_SHIFTR     0x002C		/* (RW) RTC shift control register */
  #define RTC_SHIFTR_SUBFS      0x00007FFF
  #define RTC_SHIFTR_ADD1S      0x80000000
#define TOFF_RTC_TSTR       0x0030		/* (RW) RTC time stamp time register */
  #define RTC_TSTR_SU           0x0000000F
  #define RTC_TSTR_SU_0         0x00000001
  #define RTC_TSTR_SU_1         0x00000002
  #define RTC_TSTR_SU_2         0x00000004
  #define RTC_TSTR_SU_3         0x00000008
  #define RTC_TSTR_ST           0x00000070
  #define RTC_TSTR_ST_0         0x00000010
  #define RTC_TSTR_ST_1         0x00000020
  #define RTC_TSTR_ST_2         0x00000040
  #define RTC_TSTR_MNU          0x00000F00
  #define RTC_TSTR_MNU_0        0x00000100
  #define RTC_TSTR_MNU_1        0x00000200
  #define RTC_TSTR_MNU_2        0x00000400
  #define RTC_TSTR_MNU_3        0x00000800
  #define RTC_TSTR_MNT          0x00007000
  #define RTC_TSTR_MNT_0        0x00001000
  #define RTC_TSTR_MNT_1        0x00002000
  #define RTC_TSTR_MNT_2        0x00004000
  #define RTC_TSTR_HU           0x000F0000
  #define RTC_TSTR_HU_0         0x00010000
  #define RTC_TSTR_HU_1         0x00020000
  #define RTC_TSTR_HU_2         0x00040000
  #define RTC_TSTR_HU_3         0x00080000
  #define RTC_TSTR_HT           0x00300000
  #define RTC_TSTR_HT_0         0x00100000
  #define RTC_TSTR_HT_1         0x00200000
  #define RTC_TSTR_PM           0x00400000
#define TOFF_RTC_TSDR       0x0034		/* (RW) RTC time stamp date register */
  #define RTC_TSDR_DU           0x0000000F
  #define RTC_TSDR_DU_0         0x00000001
  #define RTC_TSDR_DU_1         0x00000002
  #define RTC_TSDR_DU_2         0x00000004
  #define RTC_TSDR_DU_3         0x00000008
  #define RTC_TSDR_DT           0x00000030
  #define RTC_TSDR_DT_0         0x00000010
  #define RTC_TSDR_DT_1         0x00000020
  #define RTC_TSDR_MU           0x00000F00
  #define RTC_TSDR_MU_0         0x00000100
  #define RTC_TSDR_MU_1         0x00000200
  #define RTC_TSDR_MU_2         0x00000400
  #define RTC_TSDR_MU_3         0x00000800
  #define RTC_TSDR_MT           0x00001000
  #define RTC_TSDR_WDU          0x0000E000
  #define RTC_TSDR_WDU_0        0x00002000
  #define RTC_TSDR_WDU_1        0x00004000
  #define RTC_TSDR_WDU_2        0x00008000
#define TOFF_RTC_TSSSR      0x0038		/* (RW) RTC time-stamp sub second register */
#define TOFF_RTC_ALRMAR     0x0040		/* (RW) RTC alarm A register */
  #define RTC_ALRMAR_SU         0x0000000F
  #define RTC_ALRMAR_SU_0       0x00000001
  #define RTC_ALRMAR_SU_1       0x00000002
  #define RTC_ALRMAR_SU_2       0x00000004
  #define RTC_ALRMAR_SU_3       0x00000008
  #define RTC_ALRMAR_ST         0x00000070
  #define RTC_ALRMAR_ST_0       0x00000010
  #define RTC_ALRMAR_ST_1       0x00000020
  #define RTC_ALRMAR_ST_2       0x00000040
  #define RTC_ALRMAR_MSK1       0x00000080
  #define RTC_ALRMAR_MNU        0x00000F00
  #define RTC_ALRMAR_MNU_0      0x00000100
  #define RTC_ALRMAR_MNU_1      0x00000200
  #define RTC_ALRMAR_MNU_2      0x00000400
  #define RTC_ALRMAR_MNU_3      0x00000800
  #define RTC_ALRMAR_MNT        0x00007000
  #define RTC_ALRMAR_MNT_0      0x00001000
  #define RTC_ALRMAR_MNT_1      0x00002000
  #define RTC_ALRMAR_MNT_2      0x00004000
  #define RTC_ALRMAR_MSK2       0x00008000
  #define RTC_ALRMAR_HU         0x000F0000
  #define RTC_ALRMAR_HU_0       0x00010000
  #define RTC_ALRMAR_HU_1       0x00020000
  #define RTC_ALRMAR_HU_2       0x00040000
  #define RTC_ALRMAR_HU_3       0x00080000
  #define RTC_ALRMAR_HT         0x00300000
  #define RTC_ALRMAR_HT_0       0x00100000
  #define RTC_ALRMAR_HT_1       0x00200000
  #define RTC_ALRMAR_PM         0x00400000
  #define RTC_ALRMAR_MSK3       0x00800000
  #define RTC_ALRMAR_DU         0x0F000000
  #define RTC_ALRMAR_DU_0       0x01000000
  #define RTC_ALRMAR_DU_1       0x02000000
  #define RTC_ALRMAR_DU_2       0x04000000
  #define RTC_ALRMAR_DU_3       0x08000000
  #define RTC_ALRMAR_DT         0x30000000
  #define RTC_ALRMAR_DT_0       0x10000000
  #define RTC_ALRMAR_DT_1       0x20000000
  #define RTC_ALRMAR_WDSEL      0x40000000
  #define RTC_ALRMAR_MSK4       0x80000000
#define TOFF_RTC_ALRMASSR   0x0044		/* (RW) RTC alarm A sub second register */
  #define RTC_ALRMASSR_SS       0x00007FFF
  #define RTC_ALRMASSR_MASKSS   0x0F000000
  #define RTC_ALRMASSR_MASKSS_0 0x01000000
  #define RTC_ALRMASSR_MASKSS_1 0x02000000
  #define RTC_ALRMASSR_MASKSS_2 0x04000000
  #define RTC_ALRMASSR_MASKSS_3 0x08000000
#define TOFF_RTC_ALRMBR     0x0048		/* (RW) RTC alarm B register */
  #define RTC_ALRMBR_SU         0x0000000F
  #define RTC_ALRMBR_SU_0       0x00000001
  #define RTC_ALRMBR_SU_1       0x00000002
  #define RTC_ALRMBR_SU_2       0x00000004
  #define RTC_ALRMBR_SU_3       0x00000008
  #define RTC_ALRMBR_ST         0x00000070
  #define RTC_ALRMBR_ST_0       0x00000010
  #define RTC_ALRMBR_ST_1       0x00000020
  #define RTC_ALRMBR_ST_2       0x00000040
  #define RTC_ALRMBR_MSK1       0x00000080
  #define RTC_ALRMBR_MNU        0x00000F00
  #define RTC_ALRMBR_MNU_0      0x00000100
  #define RTC_ALRMBR_MNU_1      0x00000200
  #define RTC_ALRMBR_MNU_2      0x00000400
  #define RTC_ALRMBR_MNU_3      0x00000800
  #define RTC_ALRMBR_MNT        0x00007000
  #define RTC_ALRMBR_MNT_0      0x00001000
  #define RTC_ALRMBR_MNT_1      0x00002000
  #define RTC_ALRMBR_MNT_2      0x00004000
  #define RTC_ALRMBR_MSK2       0x00008000
  #define RTC_ALRMBR_HU         0x000F0000
  #define RTC_ALRMBR_HU_0       0x00010000
  #define RTC_ALRMBR_HU_1       0x00020000
  #define RTC_ALRMBR_HU_2       0x00040000
  #define RTC_ALRMBR_HU_3       0x00080000
  #define RTC_ALRMBR_HT         0x00300000
  #define RTC_ALRMBR_HT_0       0x00100000
  #define RTC_ALRMBR_HT_1       0x00200000
  #define RTC_ALRMBR_PM         0x00400000
  #define RTC_ALRMBR_MSK3       0x00800000
  #define RTC_ALRMBR_DU         0x0F000000
  #define RTC_ALRMBR_DU_0       0x01000000
  #define RTC_ALRMBR_DU_1       0x02000000
  #define RTC_ALRMBR_DU_2       0x04000000
  #define RTC_ALRMBR_DU_3       0x08000000
  #define RTC_ALRMBR_DT         0x30000000
  #define RTC_ALRMBR_DT_0       0x10000000
  #define RTC_ALRMBR_DT_1       0x20000000
  #define RTC_ALRMBR_WDSEL      0x40000000
  #define RTC_ALRMBR_MSK4       0x80000000
#define TOFF_RTC_ALRMBSSR   0x004C		/* (RW) RTC alarm B sub second register */
  #define RTC_ALRMBSSR_SS       0x00007FFF
  #define RTC_ALRMBSSR_MASKSS   0x0F000000
  #define RTC_ALRMBSSR_MASKSS_0 0x01000000
  #define RTC_ALRMBSSR_MASKSS_1 0x02000000
  #define RTC_ALRMBSSR_MASKSS_2 0x04000000
  #define RTC_ALRMBSSR_MASKSS_3 0x08000000
#define TOFF_RTC_SR         0x0050		/* (RW) RTC Status register */
  #define RTC_SR_ALRAF          0x00000001
  #define RTC_SR_ALRBF          0x00000002
  #define RTC_SR_WUTF           0x00000004
  #define RTC_SR_TSF            0x00000008
  #define RTC_SR_TSOVF          0x00000010
  #define RTC_SR_ITSF           0x00000020
#define TOFF_RTC_MISR       0x0054		/* (RW) RTC Masked Interrupt Status register */
  #define RTC_MISR_ALRAMF       0x00000001
  #define RTC_MISR_ALRBMF       0x00000002
  #define RTC_MISR_WUTMF        0x00000004
  #define RTC_MISR_TSMF         0x00000008
  #define RTC_MISR_TSOVMF       0x00000010
  #define RTC_MISR_ITSMF        0x00000020
#define TOFF_RTC_SMISR      0x0058		/* (RW) RTC secure masked interrupt status register */
  #define RTC_SMISR_ALRAMF      0x00000001
  #define RTC_SMISR_ALRBMF      0x00000002
  #define RTC_SMISR_WUTMF       0x00000004
  #define RTC_SMISR_TSMF        0x00000008
  #define RTC_SMISR_TSOVMF      0x00000010
  #define RTC_SMISR_ITSMF       0x00000020
#define TOFF_RTC_SCR        0x005C		/* (RW) RTC Status Clear register */
  #define RTC_SCR_CALRAF        0x00000001
  #define RTC_SCR_CALRBF        0x00000002
  #define RTC_SCR_CWUTF         0x00000004
  #define RTC_SCR_CTSF          0x00000008
  #define RTC_SCR_CTSOVF        0x00000010
  #define RTC_SCR_CITSF         0x00000020
#define TOFF_RTC_CFGR       0x0060		/* (RW) RTC Configuration register */
  #define RTC_CFGR_OUT2_RMP     0x00000001
  #define RTC_CFGR_LSCOEN       0x00000006
  #define RTC_CFGR_LSCOEN_0     0x00000002
  #define RTC_CFGR_LSCOEN_1     0x00000004
#define TOFF_RTC_HWCFGR     0x03F0		/* (R)  RTC hardware configuration register */
  #define RTC_HWCFGR_ALARMB     0x0000000
  #define RTC_HWCFGR_ALARMB_0   0x00000001
  #define RTC_HWCFGR_ALARMB_1   0x00000002
  #define RTC_HWCFGR_ALARMB_2   0x00000004
  #define RTC_HWCFGR_ALARMB_3   0x00000008
  #define RTC_HWCFGR_WAKEUP     0x000000F0
  #define RTC_HWCFGR_WAKEUP_0   0x00000010
  #define RTC_HWCFGR_WAKEUP_1   0x00000020
  #define RTC_HWCFGR_WAKEUP_2   0x00000040
  #define RTC_HWCFGR_WAKEUP_3   0x00000080
  #define RTC_HWCFGR_SMOOTH_CALIB    0x00000F00
  #define RTC_HWCFGR_SMOOTH_CALIB_0  0x00000100
  #define RTC_HWCFGR_SMOOTH_CALIB_1  0x00000200
  #define RTC_HWCFGR_SMOOTH_CALIB_2  0x00000400
  #define RTC_HWCFGR_SMOOTH_CALIB_3  0x00000800
  #define RTC_HWCFGR_TIMESTAMP       0x0000F000
  #define RTC_HWCFGR_TIMESTAMP_0     0x00001000
  #define RTC_HWCFGR_TIMESTAMP_1     0x00002000
  #define RTC_HWCFGR_TIMESTAMP_2     0x00004000
  #define RTC_HWCFGR_TIMESTAMP_3     0x00008000
  #define RTC_HWCFGR_OPTIONREG_OUT   0x00FF0000
  #define RTC_HWCFGR_OPTIONREG_OUT_0 0x00010000
  #define RTC_HWCFGR_OPTIONREG_OUT_1 0x00020000
  #define RTC_HWCFGR_OPTIONREG_OUT_2 0x00040000
  #define RTC_HWCFGR_OPTIONREG_OUT_3 0x00080000
  #define RTC_HWCFGR_OPTIONREG_OUT_4 0x00100000
  #define RTC_HWCFGR_OPTIONREG_OUT_5 0x00200000
  #define RTC_HWCFGR_OPTIONREG_OUT_6 0x00400000
  #define RTC_HWCFGR_OPTIONREG_OUT_7 0x00800000
  #define RTC_HWCFGR_TRUST_ZONE      0x0F000000
  #define RTC_HWCFGR_TRUST_ZONE_0    0x01000000
  #define RTC_HWCFGR_TRUST_ZONE_1    0x02000000
  #define RTC_HWCFGR_TRUST_ZONE_2    0x04000000
  #define RTC_HWCFGR_TRUST_ZONE_3    0x08000000
#define TOFF_RTC_VERR       0x03F4		/* (R)  RTC version register */
  #define RTC_VERR_MINREV       0x0000000F
  #define RTC_VERR_MINREV_0     0x00000001
  #define RTC_VERR_MINREV_1     0x00000002
  #define RTC_VERR_MINREV_2     0x00000004
  #define RTC_VERR_MINREV_3     0x00000008
  #define RTC_VERR_MAJREV       0x000000F0
  #define RTC_VERR_MAJREV_0     0x00000010
  #define RTC_VERR_MAJREV_1     0x00000020
  #define RTC_VERR_MAJREV_2     0x00000040
  #define RTC_VERR_MAJREV_3     0x00000080
#define TOFF_RTC_IPIDR      0x03F8		/* (R)  RTC identification register */
#define TOFF_RTC_SIDR       0x03FC		/* (R)  RTC size identification register */


/*
 *  BOOT and SECURITY and OTP CONTROLl
 */
#define TADR_BSEC_BASE      (MPU_APB5_PERIPH_BASE + 0x5000)
#define TOFF_BSEC_OTP_CONFIG      0x0000	/* (RW) BSEC OTP Configuration */
  #define BSEC_OTP_CONFIG_PWRUP       0x00000001	/* OTP power-up control */
  #define BSEC_OTP_CONFIG_FRC         0x00000006	/* OTP clock frequency range selection */
  #define BSEC_OTP_CONFIG_FRC_0       0x00000002
  #define BSEC_OTP_CONFIG_FRC_1       0x00000004
  #define BSEC_OTP_CONFIG_PRGWIDTH    0x00000078	/* OTP programming pulse width */
  #define BSEC_OTP_CONFIG_PRGWIDTH_0  0x00000008
  #define BSEC_OTP_CONFIG_PRGWIDTH_1  0x00000010
  #define BSEC_OTP_CONFIG_PRGWIDTH_2  0x00000020
  #define BSEC_OTP_CONFIG_PRGWIDTH_3  0x00000040
  #define BSEC_OTP_CONFIG_TREAD       0x00000180	/* set OTP reading current level */
  #define BSEC_OTP_CONFIG_TREAD_0     0x00000080
  #define BSEC_OTP_CONFIG_TREAD_1     0x00000100
#define TOFF_BSEC_OTP_CONTROL     0x0004	/* (RW) BSEC OTP Control */
  #define BSEC_OTP_CONTROL_ADDR       0x0000007F	/* OTP word address */
  #define BSEC_OTP_CONTROL_PROG       0x00000100	/* OTP operation control */
  #define BSEC_OTP_CONTROL_LOCK       0x00000200	/* OTP permanent word lock control */
#define TOFF_BSEC_OTP_WRDATA      0x0008	/* (RW) BSEC OTP Write Data */
#define TOFF_BSEC_OTP_STATUS      0x000C	/* (RW) BSEC OTP Status */
  #define BSEC_OTP_STATUS_SECURE      0x00000001	/* OTP secured mode */
  #define BSEC_OTP_STATUS_FULLDBG     0x00000002	/* OTP mode in full debug */
  #define BSEC_OTP_STATUS_INVALID     0x00000004	/* OTP invalid mode */
  #define BSEC_OTP_STATUS_BUSY        0x00000008	/* OTP operation status */
  #define BSEC_OTP_STATUS_PROGFAIL    0x00000010	/* last programming status */
  #define BSEC_OTP_STATUS_PWRON       0x00000020	/* OTP power status */
  #define BSEC_OTP_STATUS_BIST1LOCK   0x00000040	/* BIST1 locked */
  #define BSEC_OTP_STATUS_BIST2LOCK   0x00000080	/* BIST2 locked */
#define TOFF_BSEC_OTP_LOCK        0x0010	/* (RW) BSEC OTP Configuration */
  #define BSEC_OTP_LOCK_OTP           0x00000001	/* upper OTP read lock */
  #define BSEC_OTP_LOCK_DENREG        0x00000004	/* debug enable register sticky lock */
  #define BSEC_OTP_LOCK_FENREG        0x00000008	/* feature enable register sticky lock */
  #define BSEC_OTP_LOCK_GPLOCK        0x00000010	/* programming sticky lock */
#define TOFF_BSEC_DENABLE         0x0014	/* (RW) BSEC Debug Configuration */
  #define BSEC_DENABLE_DFTEN          0x00000001	/* DFT enable with signal dften */
  #define BSEC_DENABLE_DBGEN          0x00000002	/* debug enable with signal dbgen */
  #define BSEC_DENABLE_NIDEN          0x00000004	/* non-invasive debug enable with signal niden */
  #define BSEC_DENABLE_DEVICEEN       0x00000008	/* controls access to debug component via external debug port by signal deviceen */
  #define BSEC_DENABLE_HDPEN          0x00000010	/* hardware debug port enable with signal hdpen */
  #define BSEC_DENABLE_SPIDEN         0x00000020	/* secure privilege invasive debug enable with signal spniden */
  #define BSEC_DENABLE_SPNIDEN        0x00000040	/* secure privilege non-invasive debug enable with signal spiden */
  #define BSEC_DENABLE_CP15SDISABLE   0x00000180	/* write access to some secure CortexR-A7 CP15 registers disable CPDISABLE[0] applies to CPU0. CPDISABLE[1] applies to CPU1 */
  #define BSEC_DENABLE_CP15SDISABLE_0 0x00000080
  #define BSEC_DENABLE_CP15SDISABLE_1 0x00000100
  #define BSEC_DENABLE_CFGSDISABLE    0x00000200	/* write access to secure GIC registers disable with signal cfgsdisable */
  #define BSEC_DENABLE_DBGSWENABLE    0x00000400	/* control self hosted debug enable with signal dbgswenable */
#define TOFF_BSEC_FENABLE         0x0018	/* (RW) BSEC Feature Configuration */
#define TOFF_BSEC_OTP_DISTURBED0  0x001C	/* (RW) BSEC OTP Disturbed Status */
#define TOFF_BSEC_OTP_DISTURBED1  0x0020	/* (RW) BSEC OTP Disturbed Status */
#define TOFF_BSEC_OTP_DISTURBED2  0x0024	/* (RW) BSEC OTP Disturbed Status */
#define TOFF_BSEC_OTP_ERROR0      0x0034	/* (RW) BSEC OTP Error Status */
#define TOFF_BSEC_OTP_ERROR1      0x0038	/* (RW) BSEC OTP Error Status */
#define TOFF_BSEC_OTP_ERROR2      0x003C	/* (RW) BSEC OTP Error Status */
#define TOFF_BSEC_OTP_WRLOCK0     0x004C	/* (RW) BSEC OTP Lock status */
#define TOFF_BSEC_OTP_WRLOCK1     0x0050	/* (RW) BSEC OTP Lock status */
#define TOFF_BSEC_OTP_WRLOCK2     0x0054	/* (RW) BSEC OTP Lock status */
#define TOFF_BSEC_OTP_SPLOCK0     0x0064	/* (RW) BSEC OTP prg lock under ctrl by stick bits */
#define TOFF_BSEC_OTP_SPLOCK1     0x0068	/* (RW) BSEC OTP prg lock under ctrl by stick bits */
#define TOFF_BSEC_OTP_SPLOCK2     0x006C	/* (RW) BSEC OTP prg lock under ctrl by stick bits */
#define TOFF_BSEC_OTP_SWLOCK0     0x007C	/* (RW) BSEC OTP Shadow Write Lck under ctrl by sticky bits */
#define TOFF_BSEC_OTP_SWLOCK1     0x0080	/* (RW) BSEC OTP Shadow Write Lck under ctrl by sticky bits */
#define TOFF_BSEC_OTP_SWLOCK2     0x0084	/* (RW) BSEC OTP Shadow Write Lck under ctrl by sticky bits */
#define TOFF_BSEC_OTP_SRLOCK0     0x0094	/* (RW) BSEC OTP Shadow read lock under ctrl by sticky bits */
#define TOFF_BSEC_OTP_SRLOCK1     0x0098	/* (RW) BSEC OTP Shadow read lock under ctrl by sticky bits */
#define TOFF_BSEC_OTP_SRLOCK2     0x009C	/* (RW) BSEC OTP Shadow read lock under ctrl by sticky bits */
#define TOFF_BSEC_JTAGIN          0x00AC	/* (RW) BSEC JTAG Input */
#define TOFF_BSEC_JTAGOUT         0x00B0	/* (RW) BSEC JTAG Output */
#define TOFF_BSEC_SCRATCH         0x00B4	/* (RW) BSEC SCRATCH */
#define TOFF_BSEC_OTP_DATA        0x0200	/* (RW) BSEC Shadow Registers[0-95] */
#define TOFF_HWCFGR               0x0FF0	/* (RW) BSEC IP HW Configuration Register */
  #define BSEC_HWCFGR_SIZE            0x0000000F	/* OTP Block Size */
  #define BSEC_HWCFGR_ECC_USE         0x000000F0	/* protection / redundancy scheme used */
#define TOFF_VERR                 0x0FF4	/* (RW) BSEC IP version Register */
  #define BSEC_VERR_MINREV            0x0000000F	/* MAJREV[3:0] bits (Minor revision) */
  #define BSEC_VERR_MAJREV            0x000000F0	/* MINREV[3:0] bits (Major revision) */
#define TOFF_IPIDR                0x0FF8	/* (RW) BSEC ID Register */
#define TOFF_SIDR                 0x0FFC	/* (RW) BSEC SID Register */


/*
 *  TZC TRUSTZONE ADDRESS SPACE CONTROLLER for DDR
 */
#define TADR_TZC_BASE       (MPU_APB5_PERIPH_BASE + 0x6000)
#define TOFF_TZC_BUILD_CONFIG   0x0000	/* (RW) Build config register */
#define TOFF_TZC_ACTION         0x0004	/* (RW) Action register */
#define TOFF_TZC_GATE_KEEPER    0x0008	/* (RW) Gate keeper register */
#define TOFF_TZC_SPECULATION_CTRL 0x0C	/* (RW) Speculation control register */
#define TOFF_TZC_REG_BASE_LOWO  0x0100	/* (RW) Region 0 base address low register */
#define TOFF_TZC_REG_BASE_HIGHO 0x0104	/* (RW) Region 0 base address high register */
#define TOFF_TZC_REG_TOP_LOWO   0x0108	/* (RW) Region 0 top address low register */
#define TOFF_TZC_REG_TOP_HIGHO  0x010C	/* (RW) Region 0 top address high register */
#define TOFF_TZC_REG_ATTRIBUTESO 0x110	/* (RW) Region 0 attribute register */
#define TOFF_TZC_REG_ID_ACCESSO 0x0114	/* (RW) Region 0 ID access register */

/*
 *  TZPC TRUSTZONE PROTECTION CONTROLLER
 */
#define TADR_TZPC_BASE      (MPU_APB5_PERIPH_BASE + 0x7000)
#define TOFF_TZPC_TZMA0_SIZE    0x0000	/* (RW) TZPC ROM Secure Size Definition register */
#define TOFF_TZPC_TZMA1_SIZE    0x0004	/* (RW)TZPC SYSRAM Secure Size Definition register */
#define TOFF_TZPC_DECPROT0      0x0010	/* (RW)TZPC Securable peripheral definition register 0 */
#define TOFF_TZPC_DECPROT1      0x0014	/* (RW)TZPC Securable peripheral definition register 1 */
#define TOFF_TZPC_DECPROT2      0x0018	/* (RW)TZPC Securable peripheral definition register 2 */
#define TOFF_TZPC_DECPROT3      0x001C	/* (RW)TZPC Securable peripheral definition register 3 */
#define TOFF_TZPC_DECPROT4      0x0020	/* (RW)TZPC Securable peripheral definition register 4 */
#define TOFF_TZPC_DECPROT5      0x0024	/* (RW)TZPC Securable peripheral definition register 5 */
#define TOFF_TZPC_DECPROT_LOCK0 0x0030	/* (RW)TZPC Securable lock of security register 0 */
#define TOFF_TZPC_DECPROT_LOCK1 0x0034	/* (RW)TZPC Securable lock of security register 1 */
#define TOFF_TZPC_DECPROT_LOCK2 0x0038	/* (RW)TZPC Securable lock of security register 2 */
#define TOFF_TZPC_HWCFGR        0x03F0	/* (R)  TZPC IP HW configuration register */
#define TOFF_TZPC_IP_VER        0x03F4	/* (R)  TZPC IP version register  */
#define TOFF_TZPC_ID            0x03F8	/* (R)  TZPC IP version register  */
#define TOFF_TZPC_SID           0x03FC	/* (R)  TZPC IP version register  */


/*
 *  STGENC SYSTEM GENERIC COUNTER CONTROL
 */
#define TADR_STGENC_BASE    (MPU_APB5_PERIPH_BASE + 0x8000)
#define TOFF_STGENC_CNTCR   0x0000		/* (RW) STGEN Counter Control Register */


/*
 *  TAMPER and BACKUP REGISTERS
 */
#define TADR_TAMP_BASE      (MPU_APB5_PERIPH_BASE + 0xA000)
#define TOFF_TAMP_CR1       0x0000		/* (RW) TAMP tamper control register 1 */
  #define TAMP_CR1_TAMPE        0x000000FF
  #define TAMP_CR1_TAMP1E       0x00000001
  #define TAMP_CR1_TAMP2E       0x00000002
  #define TAMP_CR1_TAMP3E       0x00000004
  #define TAMP_CR1_ITAMPE       0xFFFF0000
  #define TAMP_CR1_ITAMP1E      0x00010000
  #define TAMP_CR1_ITAMP2E      0x00020000
  #define TAMP_CR1_ITAMP3E      0x00040000
  #define TAMP_CR1_ITAMP4E      0x00080000
  #define TAMP_CR1_ITAMP5E      0x00100000
  #define TAMP_CR1_ITAMP8E      0x00800000
#define TOFF_TAMP_CR2       0x0004		/* (RW) TAMP tamper control register 2 */
  #define TAMP_CR2_TAMPNOERase  0x000000FF
  #define TAMP_CR2_TAMP1NOERASE 0x00000001
  #define TAMP_CR2_TAMP2NOERASE 0x00000002
  #define TAMP_CR2_TAMP3NOERASE 0x00000004
  #define TAMP_CR2_TAMPMSK      0x00FF0000
  #define TAMP_CR2_TAMP1MSK     0x00010000
  #define TAMP_CR2_TAMP2MSK     0x00020000
  #define TAMP_CR2_TAMP3MSK     0x00040000
  #define TAMP_CR2_TAMPTRG      0xFF000000
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
#define TOFF_TAMP_ATCR1     0x0010		/* (RW) TAMP active tamper control register */
  #define TAMP_ATCR1_TAMPAM     0x000000FF
  #define TAMP_ATCR1_TAMP1AM    0x00000001
  #define TAMP_ATCR1_TAMP2AM    0x00000002
  #define TAMP_ATCR1_TAMP3AM    0x00000004
  #define TAMP_ATCR1_TAMP4AM    0x00000008
  #define TAMP_ATCR1_TAMP5AM    0x00000010
  #define TAMP_ATCR1_TAMP6AM    0x00000020
  #define TAMP_ATCR1_TAMP7AM    0x00000040
  #define TAMP_ATCR1_TAMP8AM    0x00000080
  #define TAMP_ATCR1_ATOSEL1    0x00000300
  #define TAMP_ATCR1_ATOSEL1_0  0x00000100
  #define TAMP_ATCR1_ATOSEL1_1  0x00000200
  #define TAMP_ATCR1_ATOSEL2    0x00000C00
  #define TAMP_ATCR1_ATOSEL2_0  0x00000400
  #define TAMP_ATCR1_ATOSEL2_1  0x00000800
  #define TAMP_ATCR1_ATOSEL3    0x00003000
  #define TAMP_ATCR1_ATOSEL3_0  0x00001000
  #define TAMP_ATCR1_ATOSEL3_1  0x00002000
  #define TAMP_ATCR1_ATOSEL4    0x0000C000
  #define TAMP_ATCR1_ATOSEL4_0  0x00004000
  #define TAMP_ATCR1_ATOSEL4_1  0x00008000
  #define TAMP_ATCR1_ATCKSEL    0x00070000
  #define TAMP_ATCR1_ATCKSEL_0  0x00010000
  #define TAMP_ATCR1_ATCKSEL_1  0x00020000
  #define TAMP_ATCR1_ATCKSEL_2  0x00040000
  #define TAMP_ATCR1_ATPER      0x07000000
  #define TAMP_ATCR1_ATPER_0    0x01000000
  #define TAMP_ATCR1_ATPER_1    0x02000000
  #define TAMP_ATCR1_ATPER_2    0x04000000
  #define TAMP_ATCR1_ATOSHARE   0x40000000
  #define TAMP_ATCR1_FLTEN      0x80000000
#define TOFF_TAMP_ATSEEDR   0x0014		/* (RW) TAMP active tamper seed register */
#define TOFF_TAMP_ATOR      0x0018		/* (RW) TAMP active tamper output register */
  #define TAMP_ATOR_PRNG        0x000000FF
  #define TAMP_ATOR_PRNG_0      0x00000001
  #define TAMP_ATOR_PRNG_1      0x00000002
  #define TAMP_ATOR_PRNG_2      0x00000004
  #define TAMP_ATOR_PRNG_3      0x00000008
  #define TAMP_ATOR_PRNG_4      0x00000010
  #define TAMP_ATOR_PRNG_5      0x00000020
  #define TAMP_ATOR_PRNG_6      0x00000040
  #define TAMP_ATOR_PRNG_7      0x00000080
  #define TAMP_ATOR_SEEDF       0x00004000
  #define TAMP_ATOR_INITS       0x00008000
#define TOFF_TAMP_SMCR      0x0020		/* (RW) TAMP secure mode control register */
  #define TAMP_SMCR_BKPRWDPROT   0x000000FF
  #define TAMP_SMCR_BKPRWDPROT_0 0x00000001
  #define TAMP_SMCR_BKPRWDPROT_1 0x00000002
  #define TAMP_SMCR_BKPRWDPROT_2 0x00000004
  #define TAMP_SMCR_BKPRWDPROT_3 0x00000008
  #define TAMP_SMCR_BKPRWDPROT_4 0x00000010
  #define TAMP_SMCR_BKPRWDPROT_5 0x00000020
  #define TAMP_SMCR_BKPRWDPROT_6 0x00000040
  #define TAMP_SMCR_BKPRWDPROT_7 0x00000080
  #define TAMP_SMCR_BKPWDPROT    0x00FF0000
  #define TAMP_SMCR_BKPWDPROT_0  0x00010000
  #define TAMP_SMCR_BKPWDPROT_1  0x00020000
  #define TAMP_SMCR_BKPWDPROT_2  0x00040000
  #define TAMP_SMCR_BKPWDPROT_3  0x00080000
  #define TAMP_SMCR_BKPWDPROT_4  0x00100000
  #define TAMP_SMCR_BKPWDPROT_5  0x00200000
  #define TAMP_SMCR_BKPWDPROT_6  0x00400000
  #define TAMP_SMCR_BKPWDPROT_7  0x00800000
  #define TAMP_SMCR_TAMPDPROT    0x80000000
#define TOFF_TAMP_IER       0x002C		/* (RW) TAMP interrupt enable register */
  #define TAMP_IER_TAMPIE       0x000000FF
  #define TAMP_IER_TAMP1IE      0x00000001
  #define TAMP_IER_TAMP2IE      0x00000002
  #define TAMP_IER_TAMP3IE      0x00000004
  #define TAMP_IER_ITAMPIE      0xFFFF0000
  #define TAMP_IER_ITAMP1IE     0x00010000
  #define TAMP_IER_ITAMP2IE     0x00020000
  #define TAMP_IER_ITAMP3IE     0x00040000
  #define TAMP_IER_ITAMP4IE     0x00080000
  #define TAMP_IER_ITAMP5IE     0x00100000
  #define TAMP_IER_ITAMP8IE     0x00800000
#define TOFF_TAMP_SR        0x0030		/* (RW) TAMP status register */
  #define TAMP_SR_TAMPF         0x000000FF
  #define TAMP_SR_TAMP1F        0x00000001
  #define TAMP_SR_TAMP2F        0x00000002
  #define TAMP_SR_TAMP3F        0x00000004
  #define TAMP_SR_ITAMPF        0xFFFF0000
  #define TAMP_SR_ITAMP1F       0x00010000
  #define TAMP_SR_ITAMP2F       0x00020000
  #define TAMP_SR_ITAMP3F       0x00040000
  #define TAMP_SR_ITAMP4F       0x00080000
  #define TAMP_SR_ITAMP5F       0x00100000
  #define TAMP_SR_ITAMP8F       0x00800000
#define TOFF_TAMP_MISR      0x0034		/* (RW) TAMP masked interrupt status register */
  #define TAMP_MISR_TAMPMF      0x000000FF
  #define TAMP_MISR_TAMP1MF     0x00000001
  #define TAMP_MISR_TAMP2MF     0x00000002
  #define TAMP_MISR_TAMP3MF     0x00000004
  #define TAMP_MISR_ITAMPMF     0xFFFF0000
  #define TAMP_MISR_ITAMP1MF    0x00010000
  #define TAMP_MISR_ITAMP2MF    0x00020000
  #define TAMP_MISR_ITAMP3MF    0x00040000
  #define TAMP_MISR_ITAMP4MF    0x00080000
  #define TAMP_MISR_ITAMP5MF    0x00100000
  #define TAMP_MISR_ITAMP8MF    0x00800000
#define TOFF_TAMP_SMISR     0x0038		/* (RW) TAMP secure masked interrupt status register */
  #define TAMP_SMISR_TAMPMF     0x000000FF
  #define TAMP_SMISR_TAMP1MF    0x00000001
  #define TAMP_SMISR_TAMP2MF    0x00000002
  #define TAMP_SMISR_TAMP3MF    0x00000004
  #define TAMP_SMISR_ITAMPMF    0xFFFF0000
  #define TAMP_SMISR_ITAMP1MF   0x00010000
  #define TAMP_SMISR_ITAMP2MF   0x00020000
  #define TAMP_SMISR_ITAMP3MF   0x00040000
  #define TAMP_SMISR_ITAMP4MF   0x00080000
  #define TAMP_SMISR_ITAMP5MF   0x00100000
  #define TAMP_SMISR_ITAMP8MF   0x00800000
#define TOFF_TAMP_SCR       0x003C		/* (RW) TAMP status clear register */
  #define TAMP_SCR_CTAMPF       0x000000FF
  #define TAMP_SCR_CTAMP1F      0x00000001
  #define TAMP_SCR_CTAMP2F      0x00000002
  #define TAMP_SCR_CTAMP3F      0x00000004
  #define TAMP_SCR_CITAMPF      0xFFFF0000
  #define TAMP_SCR_CITAMP1F     0x00010000
  #define TAMP_SCR_CITAMP2F     0x00020000
  #define TAMP_SCR_CITAMP3F     0x00040000
  #define TAMP_SCR_CITAMP4F     0x00080000
  #define TAMP_SCR_CITAMP5F     0x00100000
  #define TAMP_SCR_CITAMP8F     0x00800000
#define TOFF_TAMP_COUNTR    0x0040		/* (RW) TAMP monotonic counter register */
#define TOFF_TAMP_CFGR      0x0050		/* (RW) TAMP Configuration register */
  #define TAMP_CFGR_OUT3_RMP    0x00000001
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
#define TOFF_TAMP_HWCFGR2   0x03EC		/* (RW) TAMP hardware configuration register */
  #define TAMP_HWCFGR2_TRUST_ZONE       0x00000F00
  #define TAMP_HWCFGR2_TRUST_ZONE_0     0x00000100
  #define TAMP_HWCFGR2_TRUST_ZONE_1     0x00000200
  #define TAMP_HWCFGR2_TRUST_ZONE_2     0x00000400
  #define TAMP_HWCFGR2_TRUST_ZONE_3     0x00000800
  #define TAMP_HWCFGR2_OPTIONREG_OUT    0x000000FF
  #define TAMP_HWCFGR2_OPTIONREG_OUT_0  0x00000001
  #define TAMP_HWCFGR2_OPTIONREG_OUT_1  0x00000002
  #define TAMP_HWCFGR2_OPTIONREG_OUT_2  0x00000004
  #define TAMP_HWCFGR2_OPTIONREG_OUT_3  0x00000008
  #define TAMP_HWCFGR2_OPTIONREG_OUT_4  0x00000010
  #define TAMP_HWCFGR2_OPTIONREG_OUT_5  0x00000020
  #define TAMP_HWCFGR2_OPTIONREG_OUT_6  0x00000040
  #define TAMP_HWCFGR2_OPTIONREG_OUT_7  0x00000080
#define TOFF_TAMP_HWCFGR1   0x03F0		/* (RW) TAMP hardware configuration register */
  #define TAMP_HWCFGR1_BACKUP_REGS      0x000000FF
  #define TAMP_HWCFGR1_BACKUP_REGS_0    0x00000001
  #define TAMP_HWCFGR1_BACKUP_REGS_1    0x00000002
  #define TAMP_HWCFGR1_BACKUP_REGS_2    0x00000004
  #define TAMP_HWCFGR1_BACKUP_REGS_3    0x00000008
  #define TAMP_HWCFGR1_BACKUP_REGS_4    0x00000010
  #define TAMP_HWCFGR1_BACKUP_REGS_5    0x00000020
  #define TAMP_HWCFGR1_BACKUP_REGS_6    0x00000040
  #define TAMP_HWCFGR1_BACKUP_REGS_7    0x00000080
  #define TAMP_HWCFGR1_TAMPER           0x00000F00
  #define TAMP_HWCFGR1_TAMPER_0         0x00000100
  #define TAMP_HWCFGR1_TAMPER_1         0x00000200
  #define TAMP_HWCFGR1_TAMPER_2         0x00000400
  #define TAMP_HWCFGR1_TAMPER_3         0x00000800
  #define TAMP_HWCFGR1_ACTIVE_TAMPER    0x0000F000
  #define TAMP_HWCFGR1_ACTIVE_TAMPER_0  0x00001000
  #define TAMP_HWCFGR1_ACTIVE_TAMPER_1  0x00002000
  #define TAMP_HWCFGR1_ACTIVE_TAMPER_2  0x00004000
  #define TAMP_HWCFGR1_ACTIVE_TAMPER_3  0x00008000
  #define TAMP_HWCFGR1_INT_TAMPER       0xFFFF0000
  #define TAMP_HWCFGR1_INT_TAMPER_0     0x00010000
  #define TAMP_HWCFGR1_INT_TAMPER_1     0x00020000
  #define TAMP_HWCFGR1_INT_TAMPER_2     0x00040000
  #define TAMP_HWCFGR1_INT_TAMPER_3     0x00080000
  #define TAMP_HWCFGR1_INT_TAMPER_4     0x00100000
  #define TAMP_HWCFGR1_INT_TAMPER_5     0x00200000
  #define TAMP_HWCFGR1_INT_TAMPER_6     0x00400000
  #define TAMP_HWCFGR1_INT_TAMPER_7     0x00800000
  #define TAMP_HWCFGR1_INT_TAMPER_8     0x01000000
  #define TAMP_HWCFGR1_INT_TAMPER_9     0x02000000
  #define TAMP_HWCFGR1_INT_TAMPER_10    0x04000000
  #define TAMP_HWCFGR1_INT_TAMPER_11    0x08000000
  #define TAMP_HWCFGR1_INT_TAMPER_12    0x10000000
  #define TAMP_HWCFGR1_INT_TAMPER_13    0x20000000
  #define TAMP_HWCFGR1_INT_TAMPER_14    0x40000000
  #define TAMP_HWCFGR1_INT_TAMPER_15    0x80000000
#define TOFF_TAMP_VERR      0x03F4		/* (RW) TAMP version register */
  #define TAMP_VERR_MINREV      0x0000000F
  #define TAMP_VERR_MINREV_0    0x00000001
  #define TAMP_VERR_MINREV_1    0x00000002
  #define TAMP_VERR_MINREV_2    0x00000004
  #define TAMP_VERR_MINREV_3    0x00000008
  #define TAMP_VERR_MAJREV      0x000000F0
  #define TAMP_VERR_MAJREV_0    0x00000010
  #define TAMP_VERR_MAJREV_1    0x00000020
  #define TAMP_VERR_MAJREV_2    0x00000040
  #define TAMP_VERR_MAJREV_3    0x00000080
#define TOFF_TAMP_IPIDR     0x03F8		/* (RW) TAMP identification register */
#define TOFF_TAMP_SIDR      0x03FC		/* (RW) TAMP size identification register */


#endif  /* _STM32MP157XX_H_ */

