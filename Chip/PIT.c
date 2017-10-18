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
 *  @brief      PIT初始化
 *  @param 			PITn					PIT模块
 *  @param 			Msec					PIT定时中断时间(Ms)
 *  @since      v1.0
 */
 void PIT_Init(PITn PITx,uint32 MSec)
 {	 
	 ASSERT(PITx <= PIT1);//PIT中断断言
	 ASSERT(MSec > 0);//PIT定时时间断言
	 
	 SIM_SCGC |= SIM_SCGC_PIT_MASK;//PIT Clock Enable(PIT定时中断时钟使能)
	 
	 PIT_MCR = (0);
	 PIT_LDVAL(PITx) = (MSec * 50000) - 1;
	 
	 PIT_Flag_Clear(PITx);//PIT定时中断清中断标志
	 
	 PIT_TCTRL(PITx) &= ~PIT_TCTRL_TEN_MASK;
	 PIT_TCTRL(PITx) = (0 | PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK); 
	 
 }


