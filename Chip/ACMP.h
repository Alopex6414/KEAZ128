/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       ACMP.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-19
 */
 
#ifndef __ACMP_H__
#define __ACMP_H__

#include "Common.h" /* include peripheral declarations */

/*
**ACMP模块
*/
typedef enum
{
	ACMP_ACMP0,
	ACMP_ACMP1,
	ACMP_ACMP_MAX
}ACMP_ACMPn;

/*
**ACMP_DAC端口宏
*/
#define ACMP0_OUT_PIN PTA4	//建议不用
#define ACMP1_OUT_PIN PTB5 

/*
**variate declaration
*/
extern ACMP_MemMapPtr ACMP[ACMP_ACMP_MAX];

/*
**function declaration
*/
extern void ACMP_DAC_Init(ACMP_ACMPn ACMP_ACMPx,uint8 ACMP_DAC_DATA);


#endif


























