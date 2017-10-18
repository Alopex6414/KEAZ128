/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       FTM.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */	

#ifndef __FTM_H__
#define __FTM_H__

#include "Common.h" /* include peripheral declarations */

/*
**FTM模块
*/
typedef enum
{
	FTM_FTM0,
	FTM_FTM1,
	FTM_FTM2,
	FTM_FTM_MAX,
}FTM_FTMn;

/*
**FTM通道
*/
typedef enum
{
	FTM_CH0,
	FTM_CH1,
	FTM_CH2,
	FTM_CH3,
	FTM_CH4,
	FTM_CH5,
}FTM_CHn;

/*
**FTM时钟分频
*/
typedef enum
{
	FTM_PS_1,
	FTM_PS_2,
	FTM_PS_4,
	FTM_PS_8,
	FTM_PS_16,
	FTM_PS_32,
	FTM_PS_64,
	FTM_PS_128,
	FTM_PS_MAX,
}FTM_PS_n;

/*
**FTM输入捕捉
*/
typedef enum
{
	FTM_Rise,
	FTM_Fall,
	FTM_Rise_Or_Fall
}FTM_Input_Mode;

/*
**FTM通道精度设置
**占空比Duty/FTMx_PRECISON
*/
#define FTM0_PRECISON 10000U
#define FTM1_PRECISON 10000U
#define FTM2_PRECISON 10000U

/*
**variate declaration
*/
extern FTM_MemMapPtr FTMN[FTM_FTM_MAX];

/*
**function declaration
*/
extern void FTM_PWM_Init(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx,uint32 FTM_Freq,uint32 FTM_Duty);
extern void FTM_PWM_Duty(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx,uint32 FTM_Duty);
extern void FTM_PWM_Freq(FTM_FTMn FTM_FTMx,uint32 FTM_Freq);
extern void FTM_Input_Init(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx,FTM_Input_Mode FTM_Input_Mode_x,FTM_PS_n FTM_PS_x);
extern uint16 FTM_Input_Count_Get(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx);
extern void FTM_Input_Clean(FTM_FTMn FTM_FTMx);

#endif /* FTM_H_ */
