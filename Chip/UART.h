/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       UART.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */	
 
#ifndef __UART_H__
#define __UART_H__

#include "Common.h" /* include peripheral declarations */ 

/*
**UARTÄ£¿é
*/
typedef enum
{
	UART_UART0,			//UART0
	UART_UART1,			//UART1
	UART_UART2,			//UART2
	UART_UART_MAX
}UART_UARTn;





/*
**variate declaration
*/
extern UART_MemMapPtr UARTN[UART_UART_MAX];

/*
**function declaration
*/
extern void UART_Init(UART_UARTn UART_UARTx,uint32 UART_Baud);
extern void UART_Get_Char(UART_UARTn UART_UARTx,char *UART_Adress);
extern void UART_Put_Char(UART_UARTn UART_UARTx,char UART_Char);
extern void UART_Put_Str(UART_UARTn UART_UARTx,const uint8 *Str);

#endif
