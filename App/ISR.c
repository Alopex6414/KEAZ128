/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       ISR.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-15
 */
 
#include "Common.h" /* include peripheral declarations */
#include "Include.h"

/*
 *  @brief      IRQ_IRQHandler 外部中断服务函数
 *  @since      v1.0
 *  Sample usage:       IRQ_IRQHandler();
 */
void IRQ_IRQHandler(void)
{
	IRQ_Flag_Clear;
	Disable_IRQ(IRQ_IRQn);
	
	/*
	**IRQ外部中断服务函数用户代码
	*/
	GPIO_Turn(PTB3);
	
	IRQ_Flag_Clear;
	Enable_IRQ(IRQ_IRQn);
}

/*
 *  @brief      PIT_CH0_IRQHandler 定时中断0服务函数
 *  @since      v1.0
 *  Sample usage:       PIT_CH0_IRQHandler();
 */
void PIT_CH0_IRQHandler(void)
{
	PIT_Flag_Clear(PIT0);
	Disable_IRQ(PIT_CH0_IRQn);
	
	/*
	**PIT0定时中断服务函数用户代码
	*/
	GPIO_Turn(PTB2);
	
	PIT_Flag_Clear(PIT0);
	Enable_IRQ(PIT_CH0_IRQn);
}
 
/*
 *  @brief      PIT_CH1_IRQHandler 定时中断1服务函数
 *  @since      v1.0
 *  Sample usage:       PIT_CH1_IRQHandler();
 */
void PIT_CH1_IRQHandler(void)
{
	PIT_Flag_Clear(PIT1);
	Disable_IRQ(PIT_CH1_IRQn);
	
	/*
	**PIT1定时中断服务函数用户代码
	*/
	
	PIT_Flag_Clear(PIT1);
	Enable_IRQ(PIT_CH1_IRQn);
}

/*
 *  @brief      PWT_IRQHandler
 *  @since      v1.0
 *  Sample usage:       PWT_IRQHandler();
 */
/*void PWT_IRQHandler(void)
{
	
}*/

