/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       Delay.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */	
 
#ifndef __DELAY_H__
#define __DELAY_H__

#include "Common.h" /* include peripheral declarations */

/*
**function declaration
*/
extern void Delay(UINT16 times);
extern void Delay_us(uint16 Delay_Times);
extern void Delay_ms(uint16 Delay_Times);
  
#endif /* TYPEDEFS_H_ */
