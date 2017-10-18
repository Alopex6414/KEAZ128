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

int  PORT_Statu=0;//�˿ڵ�ƽ״̬

int  FTM_Count=0;//FTM����
char FTM_Flag=0;//FTM��־

uint16 ADC_Result_Value=0;//ADCת�����

/*
*
* @brief    main() - Program entry function
* @param    none
* @return   none
*
*/ 
int main(void)
{
	
	InitAll();//��ʼ��
	
	for(;;) 
	{
		/*
		**User Code(�û�����)
		*/
		
		PORT_Statu = GPIO_Get(PTA0);//��ȡ�˿ڵ�ƽ״̬
		
		ADC_Result_Value = ADC_Once(ADC0_SE12,ADC0_12BIT);//PTF4�˿ڳ�ʼ��ΪADC,12Bit����,ADCת��
		
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





