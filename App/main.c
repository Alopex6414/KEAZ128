/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       main.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */	

#include "Common.h" /* include peripheral declarations */
#include "Include.h"

int  PORT_Statu=0;//端口电平状态

int  FTM_Count=0;//FTM计数
char FTM_Flag=0;//FTM标志

uint16 ADC_Result_Value=0;//ADC转换结果

/*
*
* @brief    main() - Program entry function
* @param    none
* @return   none
*
*/ 
int main(void)
{
	
	InitAll();//初始化
	
	for(;;) 
	{
		/*
		**User Code(用户代码)
		*/
		
		PORT_Statu = GPIO_Get(PTA0);//获取端口电平状态
		
		ADC_Result_Value = ADC_Once(ADC0_SE12,ADC0_12BIT);//PTF4端口初始化为ADC,12Bit精度,ADC转换
		
		//GPIO
		/*if(PORT_Statu == 0)
		{
			GPIO_Set(PTB2,1);
			GPIO_Set(PTB3,1);
			Delay(200);
			GPIO_Set(PTB2,0);
			GPIO_Set(PTB3,0);
			Delay(200);
		}
		else
		{
			GPIO_Set(PTB2,1);
			GPIO_Set(PTB3,0);
			Delay(200);
			GPIO_Set(PTB2,0);
			GPIO_Set(PTB3,1);
			Delay(200);
		}*/
		
		//FTM
		if(FTM_Flag == 0)
		{
			FTM_Count++;
		}
		else
		{
			FTM_Count--;
		}
		if(FTM_Count > 10000)
		{
			FTM_Count = 10000;
			FTM_Flag = 1;
		}
		else if(FTM_Count < 0)
		{
			FTM_Count = 0;
			FTM_Flag = 0;
		}
		else
		{
			FTM_Count = FTM_Count;
			FTM_Flag = FTM_Flag;
		}
		FTM_PWM_Duty(FTM_FTM2,FTM_CH0,FTM_Count);
		FTM_PWM_Duty(FTM_FTM2,FTM_CH1,(10000-FTM_Count));
	} 
	
}





