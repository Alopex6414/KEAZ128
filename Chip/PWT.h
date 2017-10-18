/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       PWT.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-16
 */

#ifndef __PWT_H__
#define __PWT_H__

#include "Common.h" /* include peripheral declarations */

/*
**PWT输入端口
*/
typedef enum
{
	PWTIN0,
	PWTIN1
}PWTINn;

/*
**PWT输入边沿触发
*/
typedef enum
{
	PWT_Fall,
	PWT_Rise_Step,
	PWT_Fall_Step,
	PWT_Rise
}PWT_Mode;

/*
**PWT时钟分频
*/
typedef enum
{
	PWT_CLKPRE_1,
	PWT_CLKPRE_2,
	PWT_CLKPRE_4,
	PWT_CLKPRE_8,
	PWT_CLKPRE_16,
	PWT_CLKPRE_32,
	PWT_CLKPRE_64,
	PWT_CLKPRE_128
}PWT_CLKPRE_n;

//PWT中断清标志
#define PWT_Flag_Clean PWT_R1_REG(PWT_BASE_PTR) &= ~PWT_R1_PWTRDY_MASK

/*
**function declaration
*/
extern void PWT_Init(PWTINn PWTINx,PWT_Mode PWT_Mode_x,PWT_CLKPRE_n PWT_CLKPRE_x);


#endif
