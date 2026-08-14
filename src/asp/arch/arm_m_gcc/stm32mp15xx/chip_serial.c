/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *  @(#) $Id: chip_serial.c 698 2020-08-08 16:42:31Z roi $
 */

/*
 *  シリアルI/Oデバイス（SIO）ドライバ（stm32mp15xx用）
 */

#include <kernel.h>
#include <t_syslog.h>
#include "target_stddef.h"
#include "target_serial.h"
#include "target_syssvc.h"

/*
 *  SIL関数のマクロ定義
 */
#define sil_orw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) | (b))
#define sil_andw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) & ~(b))
#define sil_modw_mem(a, b, c)	sil_wrw_mem((a), (sil_rew_mem(a) & (~b)) | (c))

/*
 * レジスタ設定値
 */
#define PORT2SIOPID(x)	((x) + 1)
#define INDEX_PORT(x)	((x) - 1)
#define GET_SIOPCB(x)	(&siopcb_table[INDEX_PORT(x)])


/*
 *  UARTクロックソース定義
 */
#define UART_CLOCKSOURCE_PCLK1  0x00	/* PCLK1 clock source */
#define UART_CLOCKSOURCE_PCLK2  0x01	/* PCLK2 clock source */
#define UART_CLOCKSOURCE_PCLK5  0x02	/* PCLK5 clock source (only used by UART1) */
#define UART_CLOCKSOURCE_PLL3Q  0x04	/* PLL3Q clock source (only used by UART1) */
#define UART_CLOCKSOURCE_PLL4Q  0x08	/* PLL4Q clock source  */
#define UART_CLOCKSOURCE_HSI    0x10	/* HSI clock source */
#define UART_CLOCKSOURCE_CSI    0x20	/* CSI clock source */
#define UART_CLOCKSOURCE_HSE    0x40	/* HSE clock source */
#define UART_CLOCKSOURCE_UNDEF  0x80	/* Undefined clock source */

/*
 *  GPIO Configuration Mode enumeration
 */
#define GPIO_Mode_IN            0x0					/* GPIO Input Mode */
#define GPIO_Mode_OUT           GPIO_MODER_MODER0	/* GPIO Output Mode */
#define GPIO_Mode_AF            GPIO_MODER_MODER1	/* GPIO Alternate function Mode */
#define GPIO_Mode_AN            GPIO_MODER_MODER2	/* GPIO Analog Mode */

/*
 *  GPIO Output Maximum frequency enumeration
 */
#define GPIO_Speed_2MHz         0x0						/* Low speed */
#define GPIO_Speed_25MHz        GPIO_OSPEEDER_OSPEEDR0	/* Medium speed */
#define GPIO_Speed_50MHz        GPIO_OSPEEDER_OSPEEDR1	/* Fast speed */
#define GPIO_Speed_100MHz       GPIO_OSPEEDER_OSPEEDR2	/* High speed on 30 pF (80 MHz Output max speed on 15 pF) */

/*
 *  GPIO Output type enumeration
 */
#define GPIO_OType_PP           0x0
#define GPIO_OType_OD           0x1

/*
 *  GPIO Configuration PullUp PullDown enumeration
 */
#define GPIO_PuPd_NOPULL        0x0
#define GPIO_PuPd_UP            GPIO_PUPDR_PUPDR0
#define GPIO_PuPd_DOWN          GPIO_PUPDR_PUPDR1

/*
 *  USART Word Length
 */
#define UART_WORDLENGTH_7B      USART_CR1_M1	/* 7-bit long UART frame */
#define UART_WORDLENGTH_8B      0x00000000		/* 8-bit long UART frame */
#define UART_WORDLENGTH_9B      USART_CR1_M0	/* 9-bit long UART frame */

/*
 *  USART Stop Bits
 */
#define UART_STOPBITS_0_5       USART_CR2_STOP_0	/* UART frame with 0.5 stop bit  */
#define UART_STOPBITS_1         0x00000000			/* UART frame with 1 stop bit    */
#define UART_STOPBITS_1_5       (USART_CR2_STOP_0 | USART_CR2_STOP_1)	/* UART frame with 1.5 stop bits */
#define UART_STOPBITS_2         USART_CR2_STOP_1	/* UART frame with 2 stop bits   */

/*
 *  USART Parity
 */
#define UART_PARITY_NONE        0x00000000		/* No parity   */
#define UART_PARITY_EVEN        USART_CR1_PCE	/* Even parity */
#define UART_PARITY_ODD         (USART_CR1_PCE | USART_CR1_PS)	/* Odd parity  */

/*
 *  USART MODE
 */
#define UART_MODE_RX            USART_CR1_RE	/* RX mode */
#define UART_MODE_TX            USART_CR1_TE	/* TX mode */
#define UART_MODE_TX_RX         (USART_CR1_TE |USART_CR1_RE)	/* RX and TX mode */

/*
 * USART HARDWARE FLOW制御
 */
#define UART_HWCONTROL_NONE     0x00000000		/* No hardware control */
#define UART_HWCONTROL_RTS      USART_CR3_RTSE	/* Request To Send */
#define UART_HWCONTROL_CTS      USART_CR3_CTSE	/* Clear To Send */
#define UART_HWCONTROL_RTS_CTS  (USART_CR3_RTSE | USART_CR3_CTSE)	/* Request and Clear To Send */

/*
 *  UART OVER SAMPLING
 */
#define UART_OVERSAMPLING_16    0x00000000		/* Oversampling by 16 */
#define UART_OVERSAMPLING_8     USART_CR1_OVER8	/* Oversampling by 8 */

/*
 *  UART ONEBIT SAMPLING
 */
#define UART_ONE_BIT_SAMPLE_DISABLE 0x00000000	/* One-bit sampling disable */
#define UART_ONE_BIT_SAMPLE_ENABLE  USART_CR3_ONEBIT	/* One-bit sampling enable  */

/*
 *  USARTクロックプレスケール設定値
 */
#define UART_PRESCALER_DIV1     0x00000000		/* fclk_pres = fclk */
#define UART_PRESCALER_DIV2     0x00000001		/* fclk_pres = fclk/2 */
#define UART_PRESCALER_DIV4     0x00000002		/* fclk_pres = fclk/4 */
#define UART_PRESCALER_DIV6     0x00000003		/* fclk_pres = fclk/6 */
#define UART_PRESCALER_DIV8     0x00000004		/* fclk_pres = fclk/8 */
#define UART_PRESCALER_DIV10    0x00000005		/* fclk_pres = fclk/10 */
#define UART_PRESCALER_DIV12    0x00000006		/* fclk_pres = fclk/12 */
#define UART_PRESCALER_DIV16    0x00000007		/* fclk_pres = fclk/16 */
#define UART_PRESCALER_DIV32    0x00000008		/* fclk_pres = fclk/32 */
#define UART_PRESCALER_DIV64    0x00000009		/* fclk_pres = fclk/64 */
#define UART_PRESCALER_DIV128   0x0000000A		/* fclk_pres = fclk/128 */
#define UART_PRESCALER_DIV256   0x0000000B		/* fclk_pres = fclk/256 */

/*
 *  UART FIFO DEPTH定義
 */
#define RX_FIFO_DEPTH           8U
#define TX_FIFO_DEPTH           8U

#if USE_UAST_FIFOMODE == 0
#define UART_TXFIFO_THRESHOLD   UART_TXFIFO_THRESHOLD_1_8
#else
#define UART_TXFIFO_THRESHOLD   UART_TXFIFO_THRESHOLD_8_8
#endif
#define UART_RXFIFO_THRESHOLD   UART_RXFIFO_THRESHOLD_1_8

/*
 *  UART TXFIFO THRESHOLD定義
 */
#define UART_TXFIFO_THRESHOLD_1_8 0x00000000			/* TXFIFO reaches 1/8 of its depth */
#define UART_TXFIFO_THRESHOLD_1_4 USART_CR3_TXFTCFG_0	/* TXFIFO reaches 1/4 of its depth */
#define UART_TXFIFO_THRESHOLD_1_2 USART_CR3_TXFTCFG_1	/* TXFIFO reaches 1/2 of its depth */
#define UART_TXFIFO_THRESHOLD_3_4 (USART_CR3_TXFTCFG_0|USART_CR3_TXFTCFG_1)	/* TXFIFO reaches 3/4 of its depth */
#define UART_TXFIFO_THRESHOLD_7_8 USART_CR3_TXFTCFG_2	/* TXFIFO reaches 7/8 of its depth */
#define UART_TXFIFO_THRESHOLD_8_8 (USART_CR3_TXFTCFG_2|USART_CR3_TXFTCFG_0)	/* TXFIFO becomes empty */

/*
 *  UART RXFIFO THRESHOLD定義
 */
#define UART_RXFIFO_THRESHOLD_1_8 0x00000000			/* RXFIFO FIFO reaches 1/8 of its depth */
#define UART_RXFIFO_THRESHOLD_1_4 USART_CR3_RXFTCFG_0	/* RXFIFO FIFO reaches 1/4 of its depth */
#define UART_RXFIFO_THRESHOLD_1_2 USART_CR3_RXFTCFG_1	/* RXFIFO FIFO reaches 1/2 of its depth */
#define UART_RXFIFO_THRESHOLD_3_4 (USART_CR3_RXFTCFG_0|USART_CR3_RXFTCFG_1)	/* RXFIFO FIFO reaches 3/4 of its depth */
#define UART_RXFIFO_THRESHOLD_7_8 USART_CR3_RXFTCFG_2	/* RXFIFO FIFO reaches 7/8 of its depth */
#define UART_RXFIFO_THRESHOLD_8_8 (USART_CR3_RXFTCFG_2|USART_CR3_RXFTCFG_0)	/* RXFIFO FIFO becomes full */

#define USART_CR3_TXFTCFG_SHIFT (29U)

#define CR1_CLEAR_MASK          (USART_CR1_M | USART_CR1_PCE | USART_CR1_PS | \
                                 USART_CR1_TE | USART_CR1_RE | USART_CR1_OVER8| \
                                 USART_CR1_FIFOEN )
#define CR3_CLEAR_MASK          (USART_CR3_RTSE | USART_CR3_CTSE | USART_CR3_ONEBIT| \
                                 USART_CR3_TXFTCFG | USART_CR3_RXFTCFG )

#define CR2_CLEAR_BITS          (USART_CR2_LINEN | USART_CR2_CLKEN)
#define CR3_CLEAR_BITS          (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN)

#define CR1_CLEAR_ERROR         (USART_CR1_RXNEIE_RXFNEIE | USART_CR1_PEIE | USART_CR1_TXEIE_TXFNFIE)
/*
 *  UART BRR RENGE
 */
#define UART_BRR_MIN            0x10U			/* UART BRR minimum authorized value */
#define UART_BRR_MAX            0x0000FFFFU		/* UART BRR maximum authorized value */


/*
 *  シリアルI/Oポート初期化ブロックの定義
 */
typedef struct sio_port_initialization_block {
	uint32_t base;
	INTNO    intno_usart;
} SIOPINIB;

/*
 *  兼用GPIOポート初期化ブロックの定義
 */
typedef struct gpio_port_initialization_block {
	uint32_t clockbase/* pfr*/;		/* PFRxレジスタアドレス */
	uint32_t clock_set;
	uint32_t gpio_af;
	uint32_t clksrcbase;

	uint32_t txportbase;
	uint32_t txpinport;
	uint32_t txmode_msk;
	uint32_t txmode_set;
	uint32_t txspeed_msk;
	uint32_t txspeed_set;
	uint32_t txtype_msk;
	uint32_t txtype_set;
	uint32_t txpupd_msk;
	uint32_t txpupd_set;

	uint32_t rxportbase;
	uint32_t rxpinport;
	uint32_t rxmode_msk;
	uint32_t rxmode_set;
	uint32_t rxspeed_msk;
	uint32_t rxspeed_set;
	uint32_t rxtype_msk;
	uint32_t rxtype_set;
	uint32_t rxpupd_msk;
	uint32_t rxpupd_set;
} GPIOINIB;

/*
 *  シリアルI/Oポート管理ブロックの定義
 */
struct sio_port_control_block {
	const SIOPINIB  *p_siopinib;  /* シリアルI/Oポート初期化ブロック */
	const GPIOINIB  *p_gpioinib;  /* 兼用GPIOポート初期化ブロック */
	intptr_t        exinf;        /* 拡張情報 */
	bool_t          opnflg;       /* オープン済みフラグ */
};

/*******************************/
/*
 * シリアルI/Oポート初期化ブロック
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{(uint32_t)USART1_BASE, (INTNO)INTNO_SIO1}
};

/*
 * 兼用GPIOポート初期化ブロック
 */
const GPIOINIB gpioinib_table[TNUM_SIOP] = {
	{(uint32_t)(TADR_RCC_BASE+TOFF_U1_APBNER), (uint32_t)ENABLE_U1_PORT,
	 (uint32_t)GPIO_U1_AF, (uint32_t)(TADR_RCC_BASE+TOFF_U1_CLKSEL),
     (uint32_t)TADR_U1T_GPIO_BASE, (uint32_t)TX1_PINPOS,
     (uint32_t)(GPIO_MODER_MODER2 << (TX1_PINPOS*2)), (uint32_t)(GPIO_Mode_AF << (TX1_PINPOS*2)),
     (uint32_t)(GPIO_OSPEEDER_OSPEEDR2 << (TX1_PINPOS*2)), (uint32_t)(U1_GPIOSPEED << (TX1_PINPOS*2)),
     (uint32_t)(GPIO_OTYPER_OT << TX1_PINPOS), (uint32_t)(GPIO_OType_PP << TX1_PINPOS),
     (uint32_t)(GPIO_PUPDR_PUPDR2 << (TX1_PINPOS*2)), (uint32_t)(GPIO_PuPd_UP << (TX1_PINPOS*2)),
     (uint32_t)TADR_U1R_GPIO_BASE, (uint32_t)RX1_PINPOS,
     (uint32_t)(GPIO_MODER_MODER2 << (RX1_PINPOS*2)), (uint32_t)(GPIO_Mode_AF << (RX1_PINPOS*2)),
     (uint32_t)(GPIO_OSPEEDER_OSPEEDR2 << (RX1_PINPOS*2)), (uint32_t)(U1_GPIOSPEED << (RX1_PINPOS*2)),
     (uint32_t)(GPIO_OTYPER_OT << RX1_PINPOS), (uint32_t)(GPIO_OType_PP << RX1_PINPOS),
     (uint32_t)(GPIO_PUPDR_PUPDR2 << (RX1_PINPOS*2)), (uint32_t)(GPIO_PuPd_UP << (RX1_PINPOS*2))
    }
};
/*******************************/

static const uint8_t usart1_clock_source[8] = {
	UART_CLOCKSOURCE_PCLK5,
	UART_CLOCKSOURCE_PLL3Q,
	UART_CLOCKSOURCE_HSI,
	UART_CLOCKSOURCE_CSI,
	UART_CLOCKSOURCE_PLL4Q,
	UART_CLOCKSOURCE_HSE,
	UART_CLOCKSOURCE_UNDEF,
	UART_CLOCKSOURCE_UNDEF
};

static const uint8_t usart6_clock_source[8] = {
	UART_CLOCKSOURCE_PCLK2,
	UART_CLOCKSOURCE_PLL4Q,
	UART_CLOCKSOURCE_HSI,
	UART_CLOCKSOURCE_CSI,
	UART_CLOCKSOURCE_HSE,
	UART_CLOCKSOURCE_UNDEF,
	UART_CLOCKSOURCE_UNDEF,
	UART_CLOCKSOURCE_UNDEF
};

static const uint8_t default_clock_source[8] = {
	UART_CLOCKSOURCE_PCLK1,
	UART_CLOCKSOURCE_PLL4Q,
	UART_CLOCKSOURCE_HSI,
	UART_CLOCKSOURCE_CSI,
	UART_CLOCKSOURCE_HSE,
	UART_CLOCKSOURCE_UNDEF,
	UART_CLOCKSOURCE_UNDEF,
	UART_CLOCKSOURCE_UNDEF
};

static const uint16_t usart_dev_factor[12] = {
	1, 2, 4, 6, 8, 10, 12, 16, 32, 64, 128, 256
};

static const uint8_t numerator[] = {1U, 1U, 1U, 3U, 7U, 1U, 0U, 0U};
static const uint8_t denominator[] = {8U, 4U, 2U, 4U, 8U, 1U, 1U, 1U};

/*
 *  シリアルI/Oポート管理ブロックのエリア
 */
SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  シリアルI/OポートIDから管理ブロックを取り出すためのマクロ
 */
#define INDEX_SIOP(siopid)	((uint_t)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

static void
setup_gpio_source(uint32_t base, uint8_t source, uint8_t select)
{
	uint32_t tmpreg, regoff;
	regoff = TOFF_GPIO_AFR0+((source>>1) & 0x4);
	tmpreg = (sil_rew_mem((uint32_t *)(base+regoff)) & ~(0xF << ((source & 0x07) * 4)))
			    | (select << ((source & 0x07) * 4));
	sil_wrw_mem((uint32_t *)(base+regoff), tmpreg);
}

void
put_hex(char a, int val)
{
	int i, j;
	target_fput_log(a);
	target_fput_log(' ');
	for(i = 28 ; i >= 0 ; i-= 4){
		j = (val >> i) & 0xf;;
		if(j > 9)
			j += ('A'-10);
		else
			j += '0';
		target_fput_log(j);
	}
	target_fput_log('\n');
}

/*
 *  UART READY待ち関数
 *  input base  uart base address
 *        flag  ISR待ちフラグ
 *  result: 0:OK
 */
static int
UART_ReadyWaitOnFlag(uint32_t base, uint32_t flag)
{
	uint32_t tick = 0;

	/*
	 *  フラグがセットされるまで待つ
	 */
	while((sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR)) & flag) == 0){
		if(++tick > UARTREADY_TIMEOUT_VALUE){
			/*
			 *  エラー設定をリセット
			 */
			sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), CR1_CLEAR_ERROR);
			sil_andw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_EIE);
			return -1;
		}
		if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_RE) != 0){
			if((sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR)) & USART_ISR_RTOF) != 0){
				/*
				 *  受信タイムアウトフラグをリセット
				 */
				sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), USART_ICR_RTOCF);

				/*
				 *  エラー設定をリセット
				 */
				sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), CR1_CLEAR_ERROR);
				sil_andw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_EIE);
				return -1;
			}
		}
		sil_dly_nse(1000);
	}
	return 0;
}


/*
 *  SIOドライバの初期化
 */
void
sio_initialize(intptr_t exinf)
{
	SIOPCB	*p_siopcb;
	uint_t	i;

	/*
	 *  シリアルI/Oポート管理ブロックの初期化
	 */
	for (p_siopcb = siopcb_table, i = 0; i < TNUM_SIOP; p_siopcb++, i++) {
		p_siopcb->p_siopinib = &(siopinib_table[i]);
		p_siopcb->p_gpioinib = &(gpioinib_table[i]);
		p_siopcb->opnflg = false;
	}
}


/*
 *  シリアルI/Oポートのオープン
 */
SIOPCB *
sio_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB          *p_siopcb;
	const SIOPINIB  *p_siopinib;
	const GPIOINIB  *p_gpioinib;
	RCC_PLLClocksTypeDef RCC_Clocks;
	bool_t   opnflg;
	ER       ercd;
	uint32_t base, txbase, rxbase;
	uint32_t csource, pclk, usartdiv, tmp;

	p_siopcb = get_siopcb(siopid);
	p_siopinib = p_siopcb->p_siopinib;
	p_gpioinib = p_siopcb->p_gpioinib;

	/*
	 *  オープンしたポートがあるかをopnflgに読んでおく．
	 */
	opnflg = p_siopcb->opnflg;

	p_siopcb->exinf = exinf;
	txbase = p_gpioinib->txportbase;
	rxbase = p_gpioinib->rxportbase;

	if(txbase == 0 || rxbase == 0)	/* no usart port */
		goto sio_opn_exit;

	/*
	 *  ハードウェアの初期化
	 */
	sil_orw_mem((uint32_t *)p_gpioinib->clockbase, p_gpioinib->clock_set);

	target_periph_lock(TADR_GPIOE_BASE, LOCK_RESOURCE_TIMEOUT);

	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_MODER), p_gpioinib->txmode_msk, p_gpioinib->txmode_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OSPEEDR), p_gpioinib->txspeed_msk, p_gpioinib->txspeed_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OTYPER), p_gpioinib->txtype_msk, p_gpioinib->txtype_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR), p_gpioinib->txpupd_msk, p_gpioinib->txpupd_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_MODER), p_gpioinib->rxmode_msk, p_gpioinib->rxmode_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OSPEEDR), p_gpioinib->rxspeed_msk, p_gpioinib->rxspeed_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OTYPER), p_gpioinib->rxtype_msk, p_gpioinib->rxtype_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_PUPDR), p_gpioinib->rxpupd_msk, p_gpioinib->rxpupd_set);
	setup_gpio_source(txbase, p_gpioinib->txpinport, p_gpioinib->gpio_af);
	setup_gpio_source(rxbase, p_gpioinib->rxpinport, p_gpioinib->gpio_af);

	target_periph_unlock(TADR_GPIOE_BASE);

	base = p_siopinib->base;

	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);

	/*
	 *  UART CR1,2,3設定
	 */
	tmp = (uint32_t)(UART_WORDLENGTH_8B | UART_PARITY_NONE | UART_MODE_TX_RX | UART_OVERSAMPLING);
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR1), CR1_CLEAR_MASK, tmp);
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR2), USART_CR2_STOP, UART_STOPBITS_1);
	tmp = UART_HWCONTROL_NONE | UART_ONE_BIT_SAMPLE_DISABLE;
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), CR3_CLEAR_MASK, tmp);

	/*
	 *  UART PRESC設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_PRESC), USART_PRESC_PRESCALER, UART_PRESCALER_DIV);

	/*
	 *  USART BAUD設定
	 */
	tmp = sil_rew_mem((uint32_t *)(p_gpioinib->clksrcbase)) & 7;
	if(base == TADR_USART1_BASE)
		csource = usart1_clock_source[tmp];
	else if(base == TADR_USART6_BASE)
		csource = usart6_clock_source[tmp];
	else
		csource = default_clock_source[tmp];

	switch (csource){
	case UART_CLOCKSOURCE_PCLK2:
		pclk = SysFrePCLK2;
		break;
	case UART_CLOCKSOURCE_PCLK5:
		pclk = SysFrePCLK5;
		break;
	case UART_CLOCKSOURCE_PLL3Q:
		GetPLL3ClockFreq(&RCC_Clocks);
		pclk = RCC_Clocks.PLL_Q_Frequency;
		break;
	case UART_CLOCKSOURCE_PLL4Q:
		GetPLL4ClockFreq(&RCC_Clocks);
		pclk = RCC_Clocks.PLL_Q_Frequency;
		break;
	case UART_CLOCKSOURCE_HSI:
		pclk = HSI_VALUE;
		break;
	case UART_CLOCKSOURCE_CSI:
		pclk = CSI_VALUE;
		break;
	case UART_CLOCKSOURCE_HSE:
		pclk = HSE_VALUE;
		break;
	case UART_CLOCKSOURCE_PCLK1:
	default:
		pclk = SysFrePCLK1;
		break;
	}

	/*
	 *  UART ボーレート設定
	 */
	if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & UART_OVERSAMPLING_8) == UART_OVERSAMPLING_8){
		uint16_t brrtemp;
		usartdiv = (((pclk/usart_dev_factor[UART_PRESCALER_DIV])*2U) + (BPS_SETTING/2U)) / BPS_SETTING;

		/*
		 *  ボーレート上限、下限範囲補正
		 */
		if(usartdiv < UART_BRR_MIN)
			usartdiv = UART_BRR_MIN;
		else if(usartdiv > UART_BRR_MAX)
			usartdiv = UART_BRR_MAX;

		brrtemp = (uint16_t)(usartdiv & 0xFFF0U);
		brrtemp |= (uint16_t)((usartdiv & (uint16_t)0x000FU) >> 1U);
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_BRR), brrtemp);
	}
	else{
		usartdiv = ((pclk/usart_dev_factor[UART_PRESCALER_DIV]) + (BPS_SETTING/2U)) / BPS_SETTING;

		/*
		 *  ボーレート上限、下限範囲補正
		 */
		if(usartdiv < UART_BRR_MIN)
			usartdiv = UART_BRR_MIN;
		else if(usartdiv > UART_BRR_MAX)
			usartdiv = UART_BRR_MAX;
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_BRR), usartdiv);
	}

	/*
	 *  UARTアシンクロ・モードで不要な設定をクリア
	 */
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR2), CR2_CLEAR_BITS);
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR3), CR3_CLEAR_BITS);

	/*
	 *  TX FIFOスレッシュ設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_TXFTCFG, UART_TXFIFO_THRESHOLD);

	/*
	 *  RX FIFOスレッシュ設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_RXFTCFG, UART_RXFIFO_THRESHOLD);

	/*
	 *  UART FIFOモード設定
	 */
#if USE_UAST_FIFOMODE == 0
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_FIFOEN);
#else
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_FIFOEN);
#endif

	/*
	 *  UART有効化
	 */
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);

	/*
	 *  送信有効化(TEACK)待ち
	 */
	if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_TE) == USART_CR1_TE){
		if(UART_ReadyWaitOnFlag(base, USART_ISR_TEACK) != 0){
			syslog_1(LOG_DEBUG, "sio_opn_por:ID(%d) TEACK TIMEOUT !", siopid);
		}
	}

	/*
	 *  受信有効化(REACK)待ち
	 */
	if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_RE) == USART_CR1_RE){
		if(UART_ReadyWaitOnFlag(base, USART_ISR_REACK) != 0){
			syslog_1(LOG_DEBUG, "sio_opn_por:ID(%d) REACK TIMEOUT !", siopid);
		}
	}

	/*
	 *  UART受信割込み設定
	 */
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_PEIE);
	if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_FIFOEN) != 0)
		sil_orw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_RXFTIE);
	else
		sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_RXNEIE_RXFNEIE);
	p_siopcb->opnflg = true;

	/*
	 *  シリアルI/O割込みのマスクを解除する．
	 */
	if (!opnflg) {
		ercd = ena_int(p_siopinib->intno_usart);
		assert(ercd == E_OK);
	}

sio_opn_exit:;
	return(p_siopcb);
}

/*
 *  シリアルI/Oポートのクローズ
 */
void
sio_cls_por(SIOPCB *p_siopcb)
{
	const SIOPINIB  *p_siopinib;
	const GPIOINIB  *p_gpioinib;

	p_siopinib = p_siopcb->p_siopinib;
	p_gpioinib = p_siopcb->p_gpioinib;

	/*
	 *  シリアルI/O割込みをマスクする．
	 */
	if ((p_siopcb->opnflg)) {
		dis_int(p_siopcb->p_siopinib->intno_usart);
		sil_andw_mem((uint32_t *)(p_siopinib->base+TOFF_USART_CR1), USART_CR1_UE);
		sil_andw_mem((uint32_t *)p_gpioinib->clockbase, p_gpioinib->clock_set);
	}
	p_siopcb->opnflg = false;
}

/*
 *  SIOの割込みサービスルーチン
 */

Inline bool_t
sio_putready(SIOPCB* p_siopcb)
{
	uint32_t base = p_siopcb->p_siopinib->base;
	uint32_t cr1 = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1));
	uint32_t isr = sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR));
	uint32_t cr3 = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR3));

	/*
	 *  UART wakeup from Stop mode
	 */
	if((isr & USART_ISR_WUF) != 0 && (cr3 & USART_CR3_WUFIE) != 0){
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), USART_ICR_WUCF);
		return 0;
	}
	if((isr & USART_ISR_TXE_TXFNF) != 0 && 
			((cr1 & USART_CR1_TXEIE_TXFNFIE) != 0 || (cr3 & USART_CR3_TXFTIE) != 0)){
		if((cr1 & USART_CR1_FIFOEN) != 0){
			uint8_t  th  = (uint8_t)((cr3 & USART_CR3_TXFTCFG) >> USART_CR3_TXFTCFG_SHIFT);
			uint16_t num = ((uint16_t)TX_FIFO_DEPTH * numerator[th]) / (uint16_t)denominator[th];
			return (num > 0);
		}
		else
			return 1;
	}
	return 0;
}

Inline bool_t
sio_getready(SIOPCB* p_siopcb)
{
	uint32_t base = p_siopcb->p_siopinib->base;
	uint32_t cr1 = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1));
	uint32_t isr = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_ISR));
	uint32_t cr3 = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR3));
	uint32_t errflag;

	/*
	 *  UARTエラーチェック
	 */
	errflag = (isr & (USART_ISR_PE | USART_ISR_FE | USART_ISR_ORE | USART_ISR_NE | USART_ISR_RTOF));
	if(errflag == 0){
		if((isr & USART_ISR_RXNE_RXFNE) != 0 && 
				((cr1 & USART_CR1_RXNEIE_RXFNEIE) != 0 || (cr3 & USART_CR3_RXFTIE) != 0)){
			return 1;
		}
	}
	else if((cr3 & (USART_CR3_RXFTIE | USART_CR3_EIE)) != 0
			|| (cr1 & (USART_CR1_RXNEIE_RXFNEIE | USART_CR1_PEIE | USART_CR1_RTOIE)) != 0){
		syslog_2(LOG_DEBUG, "sio_usart_isr intno(%d) error[%08x] !", p_siopcb->p_siopinib->intno_usart, errflag);
		/*
		 *  UART パリティ―エラークリア
		 */
		if((isr & USART_ISR_PE) != 0 && (cr1 & USART_CR1_PEIE) != 0)
			sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), USART_ICR_PECF);

		/*
		 *  UART フレームエラークリア
		 */
		if((isr & USART_ISR_FE) != 0 && (cr3 & USART_CR3_EIE) != 0)
			sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), USART_ICR_FECF);

		/*
		 *  UART ノイズエラークリア
		 */
		if((isr & USART_ISR_NE) != 0 && (cr3 & USART_CR3_EIE) != 0)
			sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), USART_ICR_NECF);

		/*
		 *  UART オーバーランエラークリア
		 */
		if((isr & USART_ISR_ORE) != 0 &&
			((cr1 & USART_CR1_RXNEIE_RXFNEIE) != 0 || (cr3 & (USART_CR3_RXFTIE | USART_CR3_EIE)) != 0))
			sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), USART_ICR_ORECF);

		/*
		 *  UART 受信タイムアウトエラークリア
		 */
		if((isr & USART_ISR_RTOF) != 0 && (cr1 & USART_CR1_RTOIE) != 0)
			sil_wrw_mem((uint32_t *)(base+TOFF_USART_ICR), USART_ICR_RTOCF);
	}
	return 0;
}

void
sio_usart_isr(intptr_t exinf)
{
	SIOPCB *p_siopcb = get_siopcb(exinf);

	if (sio_getready(p_siopcb)) {
		sio_irdy_rcv(p_siopcb->exinf);
	}
	if (sio_putready(p_siopcb)) {
		sio_irdy_snd(p_siopcb->exinf);
	}
}

/*
 *  シリアルI/Oポートへの文字送信
 */
bool_t
sio_snd_chr(SIOPCB *p_siopcb, char c)
{
	uint32_t base = p_siopcb->p_siopinib->base;
	uint32_t isr = sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR));
	uint32_t cr1 = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1));
	uint32_t cr3 = sil_rew_mem((uint32_t *)(base+TOFF_USART_CR3));

	if((isr & USART_ISR_TXE_TXFNF) != 0){
		if((cr1 & USART_CR1_FIFOEN) != 0){
			uint8_t  th  = (uint8_t)((cr3 & USART_CR3_TXFTCFG) >> USART_CR3_TXFTCFG_SHIFT);
			uint16_t num = ((uint16_t)TX_FIFO_DEPTH * numerator[th]) / (uint16_t)denominator[th];
			if(num > 0){
				sil_wrw_mem((uint32_t *)(base+TOFF_USART_TDR), (uint32_t)c);
				return true;
			}
		}
		else{
			sil_wrw_mem((uint32_t *)(base+TOFF_USART_TDR), (uint32_t)c);
			return true;
		}
	}
	return false;
}

/*
 *  シリアルI/Oポートからの文字受信
 */
int_t
sio_rcv_chr(SIOPCB *p_siopcb)
{
	return sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_RDR)) & 0xFF;
}

/*
 *  シリアルI/Oポートからのコールバックの許可
 */
void
sio_ena_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	uint32_t base = p_siopcb->p_siopinib->base;

	switch (cbrtn) {
	case SIO_RDY_SND:
		if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_FIFOEN) != 0)
			sil_orw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_TXFTIE);
		else
			sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_TXEIE_TXFNFIE);
		break;
	case SIO_RDY_RCV:
		if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_FIFOEN) != 0)
			sil_orw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_RXFTIE);
		else
			sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_RXNEIE_RXFNEIE);
		break;
	}
}

/*
 *  シリアルI/Oポートからのコールバックの禁止
 */
void
sio_dis_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	uint32_t base = p_siopcb->p_siopinib->base;

	switch (cbrtn) {
	case SIO_RDY_SND:
		if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_FIFOEN) != 0)
			sil_andw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_TXFTIE);
		else
			sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_TXEIE_TXFNFIE);
		break;
	case SIO_RDY_RCV:
		if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_FIFOEN) != 0)
			sil_andw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_RXFTIE);
		else
			sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_RXNEIE_RXFNEIE);
		break;
	}
}

/*
 *  1文字出力（ポーリングでの出力）
 */
void sio_pol_snd_chr(int8_t c, ID siopid)
{
	uint32_t base = siopinib_table[INDEX_PORT(siopid)].base;

	sil_wrw_mem((uint32_t *)(base+TOFF_USART_TDR), (uint32_t)c);
	while((sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR)) & USART_ISR_TC) == 0);

	/*
	 *  出力が完全に終わるまで待つ
	 */
	volatile int n = SystemFrequency/BPS_SETTING;
	while(n--);
}

/*
 *  ターゲットのシリアル初期化
 */
void chip_uart_init(ID siopid)
{
	const GPIOINIB  *p_gpioinib = &gpioinib_table[INDEX_PORT(siopid)];
	const SIOPINIB  *p_siopinib = &siopinib_table[INDEX_PORT(siopid)];
	RCC_PLLClocksTypeDef RCC_Clocks;
	uint32_t base, txbase, rxbase;
	uint32_t csource, pclk, usartdiv, tmp;

	txbase = p_gpioinib->txportbase;
	rxbase = p_gpioinib->rxportbase;

	/*
	 *  ハードウェアの初期化
	 */
	sil_orw_mem((uint32_t *)p_gpioinib->clockbase, p_gpioinib->clock_set);

	target_periph_lock(TADR_GPIOE_BASE, LOCK_RESOURCE_TIMEOUT);

	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_MODER), p_gpioinib->txmode_msk, p_gpioinib->txmode_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OSPEEDR), p_gpioinib->txspeed_msk, p_gpioinib->txspeed_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OTYPER), p_gpioinib->txtype_msk, p_gpioinib->txtype_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR), p_gpioinib->txpupd_msk, p_gpioinib->txpupd_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_MODER), p_gpioinib->rxmode_msk, p_gpioinib->rxmode_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OSPEEDR), p_gpioinib->rxspeed_msk, p_gpioinib->rxspeed_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OTYPER), p_gpioinib->rxtype_msk, p_gpioinib->rxtype_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_PUPDR), p_gpioinib->rxpupd_msk, p_gpioinib->rxpupd_set);
	setup_gpio_source(txbase, p_gpioinib->txpinport, p_gpioinib->gpio_af);
	setup_gpio_source(rxbase, p_gpioinib->rxpinport, p_gpioinib->gpio_af);

	target_periph_unlock(TADR_GPIOE_BASE);

	base = p_siopinib->base;

	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR3), (USART_CR3_TXFTIE & USART_CR3_RXFTIE));
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), \
			(USART_CR1_TXEIE_TXFNFIE | USART_CR1_RXNEIE_RXFNEIE));

	/*
	 *  UART CR1,2,3設定
	 */
	tmp = (uint32_t)(UART_WORDLENGTH_8B | UART_PARITY_NONE | UART_MODE_TX_RX | UART_OVERSAMPLING);
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR1), CR1_CLEAR_MASK, tmp);
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR2), USART_CR2_STOP, UART_STOPBITS_1);
	tmp = UART_HWCONTROL_NONE | UART_ONE_BIT_SAMPLE_DISABLE;
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), CR3_CLEAR_MASK, tmp);

	/*
	 *  UART PRESC設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_PRESC), USART_PRESC_PRESCALER, UART_PRESCALER_DIV);

	/*
	 *  USART BAUD設定
	 */
	tmp = sil_rew_mem((uint32_t *)(p_gpioinib->clksrcbase)) & 7;
	if(base == TADR_USART1_BASE)
		csource = usart1_clock_source[tmp];
	else if(base == TADR_USART6_BASE)
		csource = usart6_clock_source[tmp];
	else
		csource = default_clock_source[tmp];

	switch (csource){
	case UART_CLOCKSOURCE_PCLK2:
		pclk = SysFrePCLK2;
		break;
	case UART_CLOCKSOURCE_PCLK5:
		pclk = SysFrePCLK5;
		break;
	case UART_CLOCKSOURCE_PLL3Q:
		GetPLL3ClockFreq(&RCC_Clocks);
		pclk = RCC_Clocks.PLL_Q_Frequency;
		break;
	case UART_CLOCKSOURCE_PLL4Q:
		GetPLL4ClockFreq(&RCC_Clocks);
		pclk = RCC_Clocks.PLL_Q_Frequency;
		break;
	case UART_CLOCKSOURCE_HSI:
		pclk = HSI_VALUE;
		break;
	case UART_CLOCKSOURCE_CSI:
		pclk = CSI_VALUE;
		break;
	case UART_CLOCKSOURCE_HSE:
		pclk = HSE_VALUE;
		break;
	case UART_CLOCKSOURCE_PCLK1:
	default:
		pclk = SysFrePCLK1;
		break;
	}

	/*
	 *  UART ボーレート設定
	 */
	if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & UART_OVERSAMPLING_8) == UART_OVERSAMPLING_8){
		uint16_t brrtemp;
		usartdiv = (((pclk/usart_dev_factor[UART_PRESCALER_DIV])*2U) + (BPS_SETTING/2U)) / BPS_SETTING;

		/*
		 *  ボーレート上限、下限範囲補正
		 */
		if(usartdiv < UART_BRR_MIN)
			usartdiv = UART_BRR_MIN;
		else if(usartdiv > UART_BRR_MAX)
			usartdiv = UART_BRR_MAX;

		brrtemp = (uint16_t)(usartdiv & 0xFFF0U);
		brrtemp |= (uint16_t)((usartdiv & (uint16_t)0x000FU) >> 1U);
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_BRR), brrtemp);
	}
	else{
		usartdiv = ((pclk/usart_dev_factor[UART_PRESCALER_DIV]) + (BPS_SETTING/2U)) / BPS_SETTING;

		/*
		 *  ボーレート上限、下限範囲補正
		 */
		if(usartdiv < UART_BRR_MIN)
			usartdiv = UART_BRR_MIN;
		else if(usartdiv > UART_BRR_MAX)
			usartdiv = UART_BRR_MAX;
		sil_wrw_mem((uint32_t *)(base+TOFF_USART_BRR), usartdiv);
	}

	/*
	 *  UARTアシンクロ・モードで不要な設定をクリア
	 */
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR2), CR2_CLEAR_BITS);
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR3), CR3_CLEAR_BITS);

	/*
	 *  TX FIFOスレッシュ設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_TXFTCFG, UART_TXFIFO_THRESHOLD);

	/*
	 *  RX FIFOスレッシュ設定
	 */
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_RXFTCFG, UART_RXFIFO_THRESHOLD);

	/*
	 *  UART FIFOモード設定
	 */
#if USE_UAST_FIFOMODE == 0
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_FIFOEN);
#else
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_FIFOEN);
#endif

	/*
	 *  UART有効化
	 */
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);

	/*
	 *  送信有効化(TEACK)待ち
	 */
	if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_TE) == USART_CR1_TE){
		if(UART_ReadyWaitOnFlag(base, USART_ISR_TEACK) != 0){
			syslog_1(LOG_DEBUG, "chip_uart_init:ID(%d) TEACK TIMEOUT !", siopid);
		}
	}

	/*
	 *  受信有効化(REACK)待ち
	 */
	if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_RE) == USART_CR1_RE){
		if(UART_ReadyWaitOnFlag(base, USART_ISR_REACK) != 0){
			syslog_1(LOG_DEBUG, "chip_uart_init:ID(%d) REACK TIMEOUT !", siopid);
		}
	}
}
