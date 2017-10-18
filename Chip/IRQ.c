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
 *  @brief      IRQ	�ⲿ�жϳ�ʼ��
 *  @note 			ѡ��IRQ������ʽ
 *  @since      v1.0
 *  Sample usage:		IRQ_External_Interrupt_Init(IRQ_PTI3,IRQ_Rise_Edge);//PTI3�жϿ�,�������ж�
 */ 
 void IRQ_External_Interrupt_Init(IRQ_PTXn IRQ_PTXx,IRQ_Trigger_Mode IRQ_Trigger_Mode_x)
 {
	 //�ⲿ�ж϶˿�,�ж�ģʽ����
	 ASSERT((IRQ_PTXx <= IRQ_PTI6) && (IRQ_Trigger_Mode_x <= IRQ_Rise_Edge_And_High_Level));
	 
	 SIM_SCGC |= SIM_SCGC_IRQ_MASK;//IRQ�ж�ʱ��ʹ��
	 
	 switch(IRQ_PTXx)//ѡ���ж϶˿�,�˿ڸ���ѡ��
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
	 
	 switch(IRQ_Trigger_Mode_x)//IRQ�ⲿ�жϴ���ģʽѡ��
	 {
		 case IRQ_Fall_Edge:								//�½��ش���
																				IRQ_SC_REG(IRQ_BASE_PTR) &= ~IRQ_SC_IRQEDG_MASK;
																				IRQ_SC_REG(IRQ_BASE_PTR) &= ~IRQ_SC_IRQMOD_MASK;
																				break;
		 case IRQ_Rise_Edge:								//�����ش���
																				IRQ_SC_REG(IRQ_BASE_PTR) |= IRQ_SC_IRQEDG_MASK;
																				IRQ_SC_REG(IRQ_BASE_PTR) &= ~IRQ_SC_IRQMOD_MASK;
																				break;
		 case IRQ_Fall_Edge_And_Low_Level:	//�½��غ͵͵�ƽ����
																				IRQ_SC_REG(IRQ_BASE_PTR) &= ~IRQ_SC_IRQEDG_MASK;
																				IRQ_SC_REG(IRQ_BASE_PTR) |= IRQ_SC_IRQMOD_MASK;
																				break;
		 case IRQ_Rise_Edge_And_High_Level: //�����غ͸ߵ�ƽ����
			 																	IRQ_SC_REG(IRQ_BASE_PTR) |= IRQ_SC_IRQEDG_MASK;
																				IRQ_SC_REG(IRQ_BASE_PTR) |= IRQ_SC_IRQMOD_MASK;
																				break;
		 default:
																				break;
	 }
	 
	 IRQ_SC_REG(IRQ_BASE_PTR) |= (IRQ_SC_IRQPE_MASK | IRQ_SC_IRQIE_MASK);//| IRQ_SC_IRQPDD_MASK
	 IRQ_Flag_Clear;//IRQ���жϱ�־
	 
 }
 