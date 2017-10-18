/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       PIT.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-15
 */
 
#ifndef __PIT_H__
#define __PIT_H__

#include "Common.h" /* include peripheral declarations */

/*
**PIT模块
*/
typedef enum
{
	PIT0,
	PIT1,
	PIT_MAX
}PITn;

//PIT定时中断清中断标志宏
#define PIT_Flag_Clear(PITn) PIT_TFLG(PITn) |= PIT_TFLG_TIF_MASK

/*
**function declaration
*/
extern void PIT_Init(PITn PITx,uint32 MSec);


#endif
