/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       WDOG.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-19
 */

#include "Common.h" /* include peripheral declarations */
#include "Include.h"

/*
 *  @brief      WDOG Unlock 解锁WDOG
 *  @note 			解锁WDOG
 *  @since      v1.0
 *  Sample usage:		WDOG_Unlock();
 */
 void WDOG_Unlock(void)
 {
	 Disable_Interrupts;
	 WDOG_CNT = WDOG_CNT_CNT(0x20C5);
	 WDOG_CNT = WDOG_CNT_CNT(0x28D9);
	 Enable_Interrupts;
 }

/*
 *  @brief      WDOG Feed WDOG计数清零
 *  @note 			WDOG计数清零
 *  @since      v1.0
 *  Sample usage:		WDOG_Feed();
 */
 void WDOG_Feed(void)
 {
	 Disable_Interrupts;
	 WDOG_CNT = WDOG_CNT_CNT(0x02A6);
	 WDOG_CNT = WDOG_CNT_CNT(0x80B4);
	 Enable_Interrupts;
 }
 
/*
 *  @brief      WDOG Disable 禁止WDOG
 *  @note 			禁止WDOG
 *  @since      v1.0
 *  Sample usage:		WDOG_Disable();
 */
 void WDOG_Disable(void)
 {
	 WDOG_Unlock();
	 WDOG_CS1 &= ~WDOG_CS1_EN_MASK;
 }
 
/*
 *  @brief      WDOG Enable 使能WDOG
 *  @note 			使能WDOG
 *  @since      v1.0
 *  Sample usage:		WDOG_Enable();
 */
 void WDOG_Enable(void)
 {
	 WDOG_Unlock();
	 WDOG_CS1 |= WDOG_CS1_EN_MASK;
 }

/*
 *  @brief      WDOG Init 初始化WDOG
 *  @param 			WDOG_Ms		清WDOG时间
 *  @note 			初始化WDOG
 *  @since      v1.0
 *  Sample usage:		WDOG_Init(1000);
 */
 void WDOG_Init(uint16 WDOG_Ms)
 {
	 WDOG_Unlock();
	 
	 WDOG_TOVAL = WDOG_TOVAL_TOVAL(WDOG_Ms);
	 WDOG_CS2 = (0 | WDOG_CS2_CLK(1));
	 WDOG_CS1 = (0 | WDOG_CS1_EN_MASK | WDOG_CS1_DBG_MASK | WDOG_CS1_WAIT_MASK | WDOG_CS1_STOP_MASK);
 }


 
