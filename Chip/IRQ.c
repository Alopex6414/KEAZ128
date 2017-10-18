/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       IRQ.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */
 
#include "Common.h" /* include peripheral declarations */
#include "Include.h" 
 
/*
 *  @brief      IRQ	外部中断初始化
 *  @note 			选择IRQ触发方式
 *  @since      v1.0
 *  Sample usage:		IRQ_External_Interrupt_Init(IRQ_PTI3,IRQ_Rise_Edge);//PTI3中断口,上升沿中断
 */ 
 void IRQ_External_Interrupt_Init(IRQ_PTXn IRQ_PTXx,IRQ_Trigger_Mode IRQ_Trigger_Mode_x)
 {
	 //外部中断端口,中断模式断言
	 ASSERT((IRQ_PTXx <= IRQ_PTI6) && (IRQ_Trigger_Mode_x <= IRQ_Rise_Edge_And_High_Level));
	 
	 SIM_SCGC |= SIM_SCGC_IRQ_MASK;//IRQ中断时钟使能
	 
	 switch(IRQ_PTXx)//选择中断端口,端口复用选择
	 {
		 case IRQ_PTA5: //PTA5
										SIM_PINSEL0 &= ~SIM_PINSEL_IRQPS_MASK;
										SIM_PINSEL0 |= SIM_PINSEL_IRQPS(0);
										break;
		 case IRQ_PTI0: //PTI0
										SIM_PINSEL0 &= ~SIM_PINSEL_IRQPS_MASK;
										SIM_PINSEL0 |= SIM_PINSEL_IRQPS(1);
										break;
		 case IRQ_PTI1: //PTI1
										SIM_PINSEL0 &= ~SIM_PINSEL_IRQPS_MASK;
										SIM_PINSEL0 |= SIM_PINSEL_IRQPS(2);
										break;
		 case IRQ_PTI2: //PTI2
										SIM_PINSEL0 &= ~SIM_PINSEL_IRQPS_MASK;
										SIM_PINSEL0 |= SIM_PINSEL_IRQPS(3);
										break;
		 case IRQ_PTI3: //PTI3
										SIM_PINSEL0 &= ~SIM_PINSEL_IRQPS_MASK;
										SIM_PINSEL0 |= SIM_PINSEL_IRQPS(4);
										break;
		 case IRQ_PTI4: //PTI4
										SIM_PINSEL0 &= ~SIM_PINSEL_IRQPS_MASK;
										SIM_PINSEL0 |= SIM_PINSEL_IRQPS(5);
										break;
		 case IRQ_PTI5: //PTI5
										SIM_PINSEL0 &= ~SIM_PINSEL_IRQPS_MASK;
										SIM_PINSEL0 |= SIM_PINSEL_IRQPS(6);
										break;
		 case IRQ_PTI6: //PTI6
										SIM_PINSEL0 &= ~SIM_PINSEL_IRQPS_MASK;
										SIM_PINSEL0 |= SIM_PINSEL_IRQPS(7);
										break;
		 default:
										break;
	 }
	 
	 switch(IRQ_Trigger_Mode_x)//IRQ外部中断触发模式选择
	 {
		 case IRQ_Fall_Edge:								//下降沿触发
																				IRQ_SC_REG(IRQ_BASE_PTR) &= ~IRQ_SC_IRQEDG_MASK;
																				IRQ_SC_REG(IRQ_BASE_PTR) &= ~IRQ_SC_IRQMOD_MASK;
																				break;
		 case IRQ_Rise_Edge:								//上升沿触发
																				IRQ_SC_REG(IRQ_BASE_PTR) |= IRQ_SC_IRQEDG_MASK;
																				IRQ_SC_REG(IRQ_BASE_PTR) &= ~IRQ_SC_IRQMOD_MASK;
																				break;
		 case IRQ_Fall_Edge_And_Low_Level:	//下降沿和低电平触发
																				IRQ_SC_REG(IRQ_BASE_PTR) &= ~IRQ_SC_IRQEDG_MASK;
																				IRQ_SC_REG(IRQ_BASE_PTR) |= IRQ_SC_IRQMOD_MASK;
																				break;
		 case IRQ_Rise_Edge_And_High_Level: //上升沿和高电平触发
			 																	IRQ_SC_REG(IRQ_BASE_PTR) |= IRQ_SC_IRQEDG_MASK;
																				IRQ_SC_REG(IRQ_BASE_PTR) |= IRQ_SC_IRQMOD_MASK;
																				break;
		 default:
																				break;
	 }
	 
	 IRQ_SC_REG(IRQ_BASE_PTR) |= (IRQ_SC_IRQPE_MASK | IRQ_SC_IRQIE_MASK);//| IRQ_SC_IRQPDD_MASK
	 IRQ_Flag_Clear;//IRQ清中断标志
	 
 }
 