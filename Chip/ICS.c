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
**KEAоƬʱ��Ƶ��
*/
 uint32 KEA_Core_FLL_CLK_MHz=0;	//KEA�ں�ʱ��FLLƵ��MHz
 uint32 KEA_Core_CLK_KHz=0;			//KEA�ں�ʱ��Ƶ��KHz
 uint32 KEA_Bus_CLK_KHz=0;			//KEA����ʱ��Ƶ��KHz
 uint32 KEA_Tim_CLK_KHz=0;			//KEA��ʱ���ο�ʱ��Ƶ��KHz
 
 /*
 **ʱ�ӷ�Ƶϵ��
 */
 FLL_Div FLL_Div_CFG=
{
	KEA_Core_Div,	//KEA�ں˷�Ƶϵ��
	KEA_Bus_Div,	//KEA���߷�Ƶϵ��
	KEA_Tim_Div		//KEA��ʱ����Ƶϵ��
};
 
 /*
 *  @brief      ICS��Ƶ���Ӽ���
 *  @param      FLL       ����Ƶ��
 *  @since      v1.0
 *  Sample usage ICS_Div_Count(FLL20,FLL_Div_CFG);
 */
 void ICS_Div_Count(FLL FLLx,FLL_Div FLL_Div_x)
 {
	 ASSERT((FLLx == FLL5) || (FLLx == FLL10) || (FLLx == FLL20) || (FLLx == FLL40));//FLL��Ƶ��ʱ�Ӷ���
	 ASSERT((FLL_Div_x.Core_Div <= 3U));//�ں˷�Ƶϵ������
	 ASSERT((FLL_Div_x.Bus_Div == 0U) || (FLL_Div_x.Bus_Div == 1U));//���߷�Ƶϵ������
	 ASSERT((FLL_Div_x.Tim_Div == 0U) || (FLL_Div_x.Tim_Div == 1U));//��ʱ����Ƶϵ������
	 
	 switch(FLLx)//ѡ��FLLƵ��
	 {
		 case FLL5:		
									ICS_C2 &= ~ICS_C2_BDIV(1);//Ĭ��2��Ƶ���־
									ICS_C2 |= ICS_C2_BDIV(3); //����8��Ƶ
									KEA_Core_FLL_CLK_MHz = 5;	//�ں�Ƶ��5MHz
									break;
		 case FLL10:	
									ICS_C2 &= ~ICS_C2_BDIV(1);//Ĭ��2��Ƶ���־
									ICS_C2 |= ICS_C2_BDIV(2); //����4��Ƶ
									KEA_Core_FLL_CLK_MHz = 10;//�ں�Ƶ��10MHz
									break;
		 case FLL20:	
									ICS_C2 &= ~ICS_C2_BDIV(1);//Ĭ��2��Ƶ���־
									ICS_C2 |= ICS_C2_BDIV(1); //����2��Ƶ
									KEA_Core_FLL_CLK_MHz = 20;//�ں�Ƶ��20MHz
									break;
		 case FLL40:	
									ICS_C2 &= ~ICS_C2_BDIV(1);//Ĭ��2��Ƶ���־
									ICS_C2 |= ICS_C2_BDIV(0); //����1��Ƶ
									KEA_Core_FLL_CLK_MHz = 40;//�ں�Ƶ��40MHz
									break;
		 default:			
									break;
	 }
	 
	 switch(FLL_Div_x.Core_Div)//ѡ���ں˷�Ƶϵ��
	 {
		 case 0U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV1_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV1(0);//�ں�1��Ƶ
							KEA_Core_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000);
							break;
		 case 1U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV1_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV1(1);//�ں�2��Ƶ
		 					KEA_Core_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000) >> 1;
							break;
		 case 2U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV1_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV1(2);//�ں�4��Ƶ
		 					KEA_Core_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000) >> 2;
							break;
		 case 3U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV1_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV1(3);//�ں�8��Ƶ
		 					KEA_Core_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000) >> 3;
							break;
		 default:
							break;
	 }
	 
	 switch(FLL_Div_x.Bus_Div)
	 {
		 case 0U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV2_MASK;
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV2_MASK;//����1��Ƶ
							KEA_Bus_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000);
							break;
		 case 1U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV2_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV2_MASK;//����2��Ƶ
		 					KEA_Bus_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000) >> 1;
							break;
		 default:
							break;
	 }
	 
	 switch(FLL_Div_x.Tim_Div)
	 {
		 case 0U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV3_MASK;
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV3_MASK;//��ʱ��1��Ƶ
		 				  KEA_Tim_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000);
							break;
		 case 1U: 
							SIM_CLKDIV &= ~SIM_CLKDIV_OUTDIV3_MASK;
							SIM_CLKDIV |= SIM_CLKDIV_OUTDIV3_MASK;//��ʱ��2��Ƶ
							KEA_Tim_CLK_KHz = (KEA_Core_FLL_CLK_MHz * 1000) >> 1;
							break;
		 default:
							break;
	 }
	 
 }
 
/*
 *  @brief      FLL��Ƶ��
 *  @param      FLL       ����Ƶ��
 *  @return     ��Ƶ(MHz)
 *  @since      v1.0
 *  Sample usage 
 */
 void FLL_Iint(FLL_Mode FLL_Mode_x,FLL FLLx,FLL_Div FLL_Div_x)
 {
	 ASSERT((FLL_Mode_x == FEI) || (FLL_Mode_x == FEE));//����ICS����ģʽ,Ŀǰֻ����FEI��FEE����ģʽ
	 
	 if(FLL_Mode_x == FEE)//FEEģʽ,�ⲿ���������ṩʱ��Դ;FEIģʽ,�ڲ��ο�ʱ���ṩʱ��Դ
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
 





 