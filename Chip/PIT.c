/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       PIT.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-15
 */
 
#include "Common.h" /* include peripheral declarations */
#include "Include.h"

 /*
 *  @brief      PIT��ʼ��
 *  @param 			PITn					PITģ��
 *  @param 			Msec					PIT��ʱ�ж�ʱ��(Ms)
 *  @since      v1.0
 */
 void PIT_Init(PITn PITx,uint32 MSec)
 {	 
	 ASSERT(PITx <= PIT1);//PIT�ж϶���
	 ASSERT(MSec > 0);//PIT��ʱʱ�����
	 
	 SIM_SCGC |= SIM_SCGC_PIT_MASK;//PIT Clock Enable(PIT��ʱ�ж�ʱ��ʹ��)
	 
	 PIT_MCR = (0);
	 PIT_LDVAL(PITx) = (MSec * 50000) - 1;
	 
	 PIT_Flag_Clear(PITx);//PIT��ʱ�ж����жϱ�־
	 
	 PIT_TCTRL(PITx) &= ~PIT_TCTRL_TEN_MASK;
	 PIT_TCTRL(PITx) = (0 | PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK); 
	 
 }


