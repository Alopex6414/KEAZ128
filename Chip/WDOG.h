/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       WDOG.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-19
 */
 
#ifndef __WDOG_H__
#define __WDOG_H__

#include "Common.h" /* include peripheral declarations */

/*
**function declaration
*/
extern void WDOG_Unlock(void);
extern void WDOG_Feed(void);
extern void WDOG_Disable(void);
extern void WDOG_Enable(void);
extern void WDOG_Init(uint16 WDOG_Ms);


#endif


















