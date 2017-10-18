/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       IRQ.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */

#ifndef __IRQ_H__
#define __IRQ_H__
 
#include "Common.h" /* include peripheral declarations */ 

/*
**IRQ�ⲿ�ж϶˿�
*/
typedef enum
{
	IRQ_PTA5,//PTA5
	IRQ_PTI0,//PTI0
	IRQ_PTI1,//PTI1
	IRQ_PTI2,//PTI2
	IRQ_PTI3,//PTI3
	IRQ_PTI4,//PTI4
	IRQ_PTI5,//PTI5
	IRQ_PTI6,//PTI6
}IRQ_PTXn;

/*
**IRQ������ʽѡ��
*/
typedef enum
{
	IRQ_Fall_Edge,//�½��ش���
	IRQ_Rise_Edge,//�����ش���
	IRQ_Fall_Edge_And_Low_Level,//�½��غ͵͵�ƽ����
	IRQ_Rise_Edge_And_High_Level//�����غ͸ߵ�ƽ����
}IRQ_Trigger_Mode;

//IRQ�ⲿ�ж����жϺ�
#define IRQ_Flag_Clear IRQ_SC_REG(IRQ_BASE_PTR) |= IRQ_SC_IRQACK_MASK

/*
**function declaration
*/
extern void IRQ_External_Interrupt_Init(IRQ_PTXn IRQ_PTXx,IRQ_Trigger_Mode IRQ_Trigger_Mode_x);

#endif 
