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
 *  @brief      IRQ_IRQHandler �ⲿ�жϷ�����
 *  @since      v1.0
 *  Sample usage:       IRQ_IRQHandler();
 */
void IRQ_IRQHandler(void)
{
	IRQ_Flag_Clear;
	Disable_IRQ(IRQ_IRQn);
	
	/*
	**IRQ�ⲿ�жϷ������û�����
	*/
	GPIO_Turn(PTB3);
	
	IRQ_Flag_Clear;
	Enable_IRQ(IRQ_IRQn);
}

/*
 *  @brief      PIT_CH0_IRQHandler ��ʱ�ж�0������
 *  @since      v1.0
 *  Sample usage:       PIT_CH0_IRQHandler();
 */
void PIT_CH0_IRQHandler(void)
{
	PIT_Flag_Clear(PIT0);
	Disable_IRQ(PIT_CH0_IRQn);
	
	/*
	**PIT0��ʱ�жϷ������û�����
	*/
	GPIO_Turn(PTB2);
	
	PIT_Flag_Clear(PIT0);
	Enable_IRQ(PIT_CH0_IRQn);
}
 
/*
 *  @brief      PIT_CH1_IRQHandler ��ʱ�ж�1������
 *  @since      v1.0
 *  Sample usage:       PIT_CH1_IRQHandler();
 */
void PIT_CH1_IRQHandler(void)
{
	PIT_Flag_Clear(PIT1);
	Disable_IRQ(PIT_CH1_IRQn);
	
	/*
	**PIT1��ʱ�жϷ������û�����
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

