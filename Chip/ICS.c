/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       ICS.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */
 
#include "Common.h" /* include peripheral declarations */
#include "Include.h"

/*
**KEA芯片时钟频率
*/
 uint32 KEA_Core_FLL_CLK_MHz=0;	//KEA内核时钟FLL频率MHz
 uint32 KEA_Core_CLK_KHz=0;			//KEA内核时钟频率KHz
 uint32 KEA_Bus_CLK_KHz=0;			//KEA总线时钟频率KHz
 uint32 KEA_Tim_CLK_KHz=0;			//KEA定时器参考时钟频率KHz
 
 /*
 **时钟分频系数
 */
 FLL_Div FLL_Div_CFG=
{
	KEA_Core_Div,	//KEA内核分频系数
	KEA_Bus_Div,	//KEA总线分频系数
	KEA_Tim_Div		//KEA定时器分频系数
};
 
 /*
 *  @brief      ICS分频因子计算
 *  @param      FLL       设置频率
 *  @since      v1.0
 *  Sample usage ICS_Div_Count(FLL20,FLL_Div_CFG);
 */
 void ICS_Div_Count(FLL FLLx,FLL_Div FLL_Div_x)
 {
	 ASSERT((FLLx == FLL5) || (FLLx == FLL10) || (FLLx == FLL20) || (FLLx == FLL40));//FLL锁频环时钟断言
	 ASSERT((FLL_Div_x.Core_Div <= 3U));//内核分频系数断言
	 ASSERT((FLL_Div_x.Bus_Div == 0U) || (FLL_Div_x.Bus_Div == 1U));//总线分频系数断言
	 ASSERT((FLL_Div_x.Tim_Div == 0U) || (FLL_Div_x.Tim_Div == 1U));//定时器分频系数断言
	 
	 switch(FLLx)//选择FLL频率
	 {
		 case FLL5:		
									ICS_C2 &= ~ICS_C2_BDIV(1);//默认2分频清标志
									ICS_C2 |= ICS_C2_BDIV(3); //设置8分频
									KEA_Core_FLL_CLK_MHz = 5;	//内核频率5MHz
									break;
		 case FLL10:	
									ICS_C2 &= ~ICS_C2_BDIV(1);//默认2分频清标志
									ICS_C2 |= ICS_C2_BDIV(2); //设置4分频
									KEA_Core_FLL_CLK_MHz = 10;//内核频率10MHz
									break;
		 case FLL20:	
									ICS_C2 &= ~ICS_C2_BDIV(1);//默认2分频清标志
									ICS_C2 |= ICS_C2_BDIV(1); //设置2分频
									KEA_Core_FLL_CLK_MHz = 20;//内核频率20MHz
									break;
		 case FLL40:	
									ICS_C2 &= ~ICS_C2_BDIV(1);//默认2分频清标志
									ICS_C2 |= ICS_C2_BDIV(0); //设置1分频
									KEA_Core_FLL_CLK_MHz = 40;//内核频率40MHz
									break;
		 default:			
									break;
	 }
	 
	 switch(FLL_Div_x.Core_Div)//选择内核分频系数
	 {
		 case 0U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV1_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV1(0);//内核1分频
							KEA_Core_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000);
							break;
		 case 1U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV1_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV1(1);//内核2分频
		 					KEA_Core_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000) >> 1;
							break;
		 case 2U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV1_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV1(2);//内核4分频
		 					KEA_Core_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000) >> 2;
							break;
		 case 3U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV1_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV1(3);//内核8分频
		 					KEA_Core_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000) >> 3;
							break;
		 default:
							break;
	 }
	 
	 switch(FLL_Div_x.Bus_Div)
	 {
		 case 0U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV2_MASK;
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV2_MASK;//总线1分频
							KEA_Bus_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000);
							break;
		 case 1U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV2_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV2_MASK;//总线2分频
		 					KEA_Bus_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000) >> 1;
							break;
		 default:
							break;
	 }
	 
	 switch(FLL_Div_x.Tim_Div)
	 {
		 case 0U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV3_MASK;
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV3_MASK;//定时器1分频
		 				  KEA_Tim_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000);
							break;
		 case 1U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV3_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV3_MASK;//定时器2分频
							KEA_Tim_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000) >> 1;
							break;
		 default:
							break;
	 }
	 
 }
 
/*
 *  @brief      FLL锁频环
 *  @param      FLL       设置频率
 *  @return     超频(MHz)
 *  @since      v1.0
 *  Sample usage 
 */
 void FLL_Iint(FLL_Mode FLL_Mode_x,FLL FLLx,FLL_Div FLL_Div_x)
 {
	 ASSERT((FLL_Mode_x == FEI) || (FLL_Mode_x == FEE));//断言ICS工作模式,目前只设置FEI和FEE工作模式
	 
	 if(FLL_Mode_x == FEE)//FEE模式,外部晶体振荡器提供时钟源;FEI模式,内部参考时钟提供时钟源
	 {
		 OSC_CR |= (OSC_CR_OSCEN_MASK | OSC_CR_OSCOS_MASK | OSC_CR_RANGE_MASK | OSC_CR_HGO_MASK);
		 while(!(OSC_CR & OSC_CR_OSCINIT_MASK));
		 ICS_C1 |= ICS_C1_RDIV(2);
		 while((ICS_S & ICS_S_IREFST_MASK));
	 }
	 
	 ICS_Div_Count(FLLx,FLL_Div_x);
	 ICS_C1 |= (ICS_C1_IREFS_MASK | ICS_C1_IRCLKEN_MASK);
	 while(!(ICS_S & ICS_S_LOCK_MASK));
 }
 





 