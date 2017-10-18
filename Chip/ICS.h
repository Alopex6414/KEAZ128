/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       ICS.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */
 
#ifndef __ICS_H__
#define __ICS_H__

#include "Common.h" /* include peripheral declarations */

/*
**FLL锁频环频率
*/
typedef enum
{
	FLL5,	//5MHz
	FLL10,//10MHz
	FLL20,//20MHz
	FLL40,//40MHz
	FLLMAX,
}FLL;

/*
**ICS工作模式
*/
typedef enum
{
	FEI,//FEI模式
	FEE,//FEE模式
}FLL_Mode;

/*
**分频因子
*/
typedef struct
{
	uint8 Core_Div;//内核分频系数
	uint8 Bus_Div;//总线分频系数
	uint8 Tim_Div;//定时器分频系数
}FLL_Div;

/*
**variate declaration
*/
extern FLL_Div FLL_Div_CFG;
extern uint32 KEA_Core_FLL_CLK_MHz;
extern uint32 KEA_Core_CLK_KHz;
extern uint32 KEA_Bus_CLK_KHz;
extern uint32 KEA_Tim_CLK_KHz;

/*
**function declaration
*/
extern void ICS_Div_Count(FLL FLLx,FLL_Div FLL_Div_x);
extern void FLL_Iint(FLL_Mode FLL_Mode_x,FLL FLLx,FLL_Div FLL_Div_x);

#endif
