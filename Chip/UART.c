/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       UART.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */
 
#include "Common.h" /* include peripheral declarations */ 
#include "Include.h"

//UART基址指针
UART_MemMapPtr UARTN[UART_UART_MAX]=
{
	UART0_BASE_PTR,
	UART1_BASE_PTR,
	UART2_BASE_PTR
};

/*
* @brief    UART_Init		初始化UART 波特率设置
* @param    UART_UARTn 	UART模块号(UART0-UART2)
* @param    UART_Baud 	UART波特率(9600,115200,256000)
* @return   none
* Sample usage:       	UART_Init(UART0,115200)
*/
 void UART_Init(UART_UARTn UART_UARTx,uint32 UART_Baud)
 {
	 uint8 UART_Temp;
	 uint32 UART_SystemClk;
	 register uint16 UART_Sbr;
	 register uint16 UART_Brfa;
	 
	 ASSERT(UART_UARTx <= UART_UART2);
	 
	 switch(UART_UARTx)
	 {
		 case UART_UART0:
											SIM_SCGC |= SIM_SCGC_UART0_MASK;
											if(UART0_RX_PIN == PTB0 && UART0_TX_PIN == PTB1)
											{
												SIM_PINSEL0 &= ~SIM_PINSEL_UART0PS_MASK;
											}
											else if(UART0_RX_PIN == PTA2 && UART0_TX_PIN == PTA3)
											{
												SIM_PINSEL0 |= SIM_PINSEL_UART0PS_MASK;
											}
											else
											{
												ASSERT(0);
											}
											break;
		 case UART_UART1:
											SIM_SCGC |= SIM_SCGC_UART1_MASK;
		 									if(UART1_RX_PIN == PTC6 && UART1_TX_PIN == PTC7)
											{
												SIM_PINSEL1 &= ~SIM_PINSEL1_UART1PS_MASK;
											}
											else if(UART1_RX_PIN == PTF2 && UART1_TX_PIN == PTF3)
											{
												SIM_PINSEL1 |= SIM_PINSEL1_UART1PS_MASK;
											}
											else
											{
												ASSERT(0);
											}
											break;
		 case UART_UART2:
											SIM_SCGC |= SIM_SCGC_UART2_MASK;
		 									if(UART2_RX_PIN == PTD6 && UART2_TX_PIN == PTD7)
											{
												SIM_PINSEL1 &= ~SIM_PINSEL1_UART2PS_MASK;
											}
											else if(UART2_RX_PIN == PTI0 && UART2_TX_PIN == PTI1)
											{
												SIM_PINSEL1 |= SIM_PINSEL1_UART2PS_MASK;
											}
											else
											{
												ASSERT(0);
											}
											break;
		 default:
											break;
	 }
	 
	 UART_C2_REG(UARTN[UART_UARTx]) &= ~(0 | UART_C2_TE_MASK | UART_C2_RE_MASK);
	 UART_C1_REG(UARTN[UART_UARTx]) |= (0);
	 
	 UART_SystemClk = KEA_Bus_CLK_KHz * 1000;
	 
	 UART_Sbr = (uint16)(UART_SystemClk / (UART_Baud * 16));
	 if(UART_Sbr > 0x1fff)
	 {
		 UART_Sbr = 0x1fff;
	 }
	 
	 UART_Brfa = (UART_SystemClk / UART_Baud) - (UART_Sbr * 16);
	 ASSERT(UART_Brfa <= 0x1f);
	 
	 UART_Temp = UART_BDH_REG(UARTN[UART_UARTx]) & (~UART_BDH_SBR_MASK);
	 UART_BDH_REG(UARTN[UART_UARTx]) = UART_Temp |  UART_BDH_SBR(UART_Sbr >> 8);
	 UART_BDL_REG(UARTN[UART_UARTx]) = UART_BDL_SBR(UART_Sbr);
	 
	 UART_C2_REG(UARTN[UART_UARTx]) |= (0 | UART_C2_TE_MASK | UART_C2_RE_MASK);
	 
 }

/*
* @brief    UART_Get_Char		UART等待接受一个字节
* @param    UART_UARTn 			UART模块号(UART0-UART2)
* @param    UART_Adress 		UART接受变量地址
* @return   none
* Sample usage:       	UART_Get_Char(UART0,&UART_Adress)
*/
 void UART_Get_Char(UART_UARTn UART_UARTx,char *UART_Adress)
 {
	 while (!(UART_S1_REG(UARTN[UART_UARTx]) & UART_S1_RDRF_MASK));
	 
	 *UART_Adress =  UART_D_REG(UARTN[UART_UARTx]);
	 
 }

/*
* @brief    UART_Put_Char		UART发送一个字节
* @param    UART_UARTn 			UART模块号(UART0-UART2)
* @param    UART_Char 		  UART发送字符
* @return   none
* Sample usage:       	UART_Put_Char(UART0,'A')
*/
 void UART_Put_Char(UART_UARTn UART_UARTx,char UART_Char)
 {
	 while(!(UART_S1_REG(UARTN[UART_UARTx]) & UART_S1_TDRE_MASK));
	 
	 UART_D_REG(UARTN[UART_UARTx]) = (uint8)UART_Char;
	 
 }

/*
* @brief    UART_Put_Str		UART发送字符串
* @param    UART_UARTn 			UART模块号(UART0-UART2)
* @param    UART_Str 		    UART发送字符串
* @return   none
* Sample usage:       	UART_Put_Str(UART0,'ABCDEFG')
*/
 void UART_Put_Str(UART_UARTn UART_UARTx,const uint8 *Str)
 {
	 while(*Str)
	 {
		 UART_Put_Char(UART_UARTx,*Str++);
	 }
 }


 
