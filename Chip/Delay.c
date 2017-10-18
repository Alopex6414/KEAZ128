/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       Delay.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */	

#include "Common.h" /* include peripheral declarations */
#include "Include.h"


/*
 *
 * @brief    Delay() - for some delay
 * @param    none
 * @return   none
 *
 */
void Delay(UINT16 times)
{
			UINT16 i, j;
			for(i = 0; i < times; i++)
					for(j = 0; j < 10000; j++)
					{
					;
					}

}

/*
 *  @brief      Delay_us			微秒级延时
 *  @param 			Delay_Times		延时时间
 *  @since      v1.0
 *  Sample usage:		Delay_us(500);//延时500us
 */
void Delay_us(uint16 Delay_Times)
{
	uint16 i=0;
	uint16 j=0;
	
	for(i=0;i<Delay_Times;i++)
	{
		for(j=0;j<KEA_Core_FLL_CLK_MHz;j++)
		{
			__ASM("nop");
		}
	}
	
}

/*
 *  @brief      Delay_ms			毫秒级延时
 *  @param 			Delay_Times		延时时间
 *  @since      v1.0
 *  Sample usage:		Delay_ms(500);//延时500ms
 */
void Delay_ms(uint16 Delay_Times)
{
	uint16 i=0;
	uint16 j=0;
	
	for(i=0;i<Delay_Times;i++)
	{
		for(j=0;j<KEA_Core_CLK_KHz;j++)
		{
			__ASM("nop");
		}
	}
	
}
