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
 *  @brief      Interrupt Init(中断初始化)
 *  @since      v1.0
 *  Sample usage:       void InitInterrupts(void);
 */
 void InitInterrupts(void)
 {
	 Set_Priority_IRQ(IRQ_IRQn,0);//IRQ中断优先级0
	 IRQ_External_Interrupt_Init(IRQ_PTI3,IRQ_Rise_Edge);//初始化IRQ外部中断,PTI3端口上升沿触发
	 Disable_IRQ(IRQ_IRQn);//禁止IRQ中断
	 Set_Priority_IRQ(PIT_CH0_IRQn,1);//PIT0中断优先级1
	 PIT_Init(PIT0,1000);//PIT0定时中断初始化,定时时间1s
	 Disable_IRQ(PIT_CH0_IRQn);//禁止PIT0中断
 }

/*
 *  @brief      System Init(系统初始化)
 *  @since      v1.0
 *  Sample usage:       void InitAll(void);
 */
void InitAll(void)
{
	FLL_Iint(FEI,KEA_Core_CLK,FLL_Div_CFG);//内部参考时钟,FLL40,时钟分频(Core:40MHz,Bus:40MHz,Flash:40MHz,FTM/TIM:40MHz)
	
	InitInterrupts();//中断初始化及优先级设置
	
	FTM_PWM_Init(FTM_FTM1,FTM_CH0,15000,2000);//初始化FTM1,FTM_CH0通道,频率15KHz,占空比20%
	FTM_PWM_Init(FTM_FTM2,FTM_CH0,15000,9000);//初始化FTM2,FTM_CH0通道,频率15KHz,占空比90%
	FTM_PWM_Init(FTM_FTM2,FTM_CH1,15000,9000);//初始化FTM2,FTM_CH1通道,频率15KHz,占空比90%
	
	ADC_Init();//ADC时钟初始化
	
	ACMP_DAC_Init(ACMP_ACMP1,32);
	
	GPIO_Init(PTA0,GPI,0);//初始化PTA0,输入
	GPIO_Init(PTB2,GPO,1);//初始化PTB2,输出,高电平
	GPIO_Init(PTB3,GPO,0);//初始化PTB3,输出,低电平
	
	Enable_IRQ(IRQ_IRQn);//IRQ外部中断使能
	Enable_IRQ(PIT_CH0_IRQn);//PIT0定时中断使能
	
	Enable_Interrupts;//总中断使能
}

