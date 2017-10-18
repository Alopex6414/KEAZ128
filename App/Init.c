/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       Init.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */	
#include "Common.h" /* include peripheral declarations */
#include "Include.h"

/*
 *  @brief      Interrupt Init(�жϳ�ʼ��)
 *  @since      v1.0
 *  Sample usage:       void InitInterrupts(void);
 */
 void InitInterrupts(void)
 {
	 Set_Priority_IRQ(IRQ_IRQn,0);//IRQ�ж����ȼ�0
	 IRQ_External_Interrupt_Init(IRQ_PTI3,IRQ_Rise_Edge);//��ʼ��IRQ�ⲿ�ж�,PTI3�˿������ش���
	 Disable_IRQ(IRQ_IRQn);//��ֹIRQ�ж�
	 Set_Priority_IRQ(PIT_CH0_IRQn,1);//PIT0�ж����ȼ�1
	 PIT_Init(PIT0,1000);//PIT0��ʱ�жϳ�ʼ��,��ʱʱ��1s
	 Disable_IRQ(PIT_CH0_IRQn);//��ֹPIT0�ж�
 }

/*
 *  @brief      System Init(ϵͳ��ʼ��)
 *  @since      v1.0
 *  Sample usage:       void InitAll(void);
 */
void InitAll(void)
{
	FLL_Iint(FEI,KEA_Core_CLK,FLL_Div_CFG);//�ڲ��ο�ʱ��,FLL40,ʱ�ӷ�Ƶ(Core:40MHz,Bus:40MHz,Flash:40MHz,FTM/TIM:40MHz)
	
	InitInterrupts();//�жϳ�ʼ�������ȼ�����
	
	FTM_PWM_Init(FTM_FTM1,FTM_CH0,15000,2000);//��ʼ��FTM1,FTM_CH0ͨ��,Ƶ��15KHz,ռ�ձ�20%
	FTM_PWM_Init(FTM_FTM2,FTM_CH0,15000,9000);//��ʼ��FTM2,FTM_CH0ͨ��,Ƶ��15KHz,ռ�ձ�90%
	FTM_PWM_Init(FTM_FTM2,FTM_CH1,15000,9000);//��ʼ��FTM2,FTM_CH1ͨ��,Ƶ��15KHz,ռ�ձ�90%
	
	ADC_Init();//ADCʱ�ӳ�ʼ��
	
	ACMP_DAC_Init(ACMP_ACMP1,32);
	
	GPIO_Init(PTA0,GPI,0);//��ʼ��PTA0,����
	GPIO_Init(PTB2,GPO,1);//��ʼ��PTB2,���,�ߵ�ƽ
	GPIO_Init(PTB3,GPO,0);//��ʼ��PTB3,���,�͵�ƽ
	
	Enable_IRQ(IRQ_IRQn);//IRQ�ⲿ�ж�ʹ��
	Enable_IRQ(PIT_CH0_IRQn);//PIT0��ʱ�ж�ʹ��
	
	Enable_Interrupts;//���ж�ʹ��
}

