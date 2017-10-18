/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       PWT.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-16
 */

#include "Common.h" /* include peripheral declarations */
#include "Include.h"

/*
 *  @brief      PWT 初始化(PWT脉冲宽度测量初始化)
 *  @note 			PWT脉冲宽度测量
 *  @since      v1.0
 *  Sample usage:		PWT_Init();
 */
 void PWT_Init(PWTINn PWTINx,PWT_Mode PWT_Mode_x,PWT_CLKPRE_n PWT_CLKPRE_x)
 {
	 ASSERT((PWTINx == PWTIN0) || (PWTINx == PWTIN1));
	 ASSERT(PWT_Mode_x <= PWT_Rise);
	 ASSERT(PWT_CLKPRE_x <= PWT_CLKPRE_128);
	 
	 SIM_SCGC |= SIM_SCGC_PWT_MASK;//Enable PWT
	 
	 switch(PWTINx)
	 {
		 case PWTIN0:
									if(PWTIN0_PIN == PTD5)
									{
										SIM_PINSEL1 &= ~SIM_PINSEL1_PWTIN0PS_MASK;
										PWT_R1_REG(PWT_BASE_PTR) &= ~PWT_R1_PINSEL_MASK;
										PWT_R1_REG(PWT_BASE_PTR) |= PWT_R1_PINSEL(PWTIN0);
									}
									else if(PWTIN0_PIN == PTE2)
									{
										SIM_PINSEL1 |= SIM_PINSEL1_PWTIN0PS_MASK;
										PWT_R1_REG(PWT_BASE_PTR) &= ~PWT_R1_PINSEL_MASK;
										PWT_R1_REG(PWT_BASE_PTR) |= PWT_R1_PINSEL(PWTIN0);
									}
									else
									{
										ASSERT(0);
									}
									break;
		 case PWTIN1:
			 						if(PWTIN1_PIN == PTB0)
									{
										SIM_PINSEL1 &= ~SIM_PINSEL1_PWTIN1PS_MASK;
										PWT_R1_REG(PWT_BASE_PTR) &= ~PWT_R1_PINSEL_MASK;
										PWT_R1_REG(PWT_BASE_PTR) |= PWT_R1_PINSEL(PWTIN1);
									}
									else if(PWTIN1_PIN == PTH7)
									{
										SIM_PINSEL1 |= SIM_PINSEL1_PWTIN1PS_MASK;
										PWT_R1_REG(PWT_BASE_PTR) &= ~PWT_R1_PINSEL_MASK;
										PWT_R1_REG(PWT_BASE_PTR) |= PWT_R1_PINSEL(PWTIN1);
									}
									else
									{
										ASSERT(0);
									}
									break;
		 default:
									break;
	 }
	 
	 PWT_R1_REG(PWT_BASE_PTR) |= (PWT_R1_PWTSR_MASK | PWT_R1_PRE(PWT_CLKPRE_x) | PWT_R1_EDGE(PWT_Mode_x) | PWT_R1_PWTEN_MASK);// | PWT_R1_PRDYIE_MASK | PWT_R1_PWTIE_MASK
	 PWT_Flag_Clean;

 }






