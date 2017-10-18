/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       Vector.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-15
 */
 
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "Common.h" /* include peripheral declarations */

#define VECTOR_00 __initial_sp									//__initial_sp
#define VECTOR_01 Reset_Handler									//Reset_Handler
#define VECTOR_02 NMI_Handler										//NMI_Handler
#define VECTOR_03 HardFault_Handler							//HardFault_Handler
#define VECTOR_04 default_isr										//Reserved
#define VECTOR_05 default_isr										//Reserved
#define VECTOR_06 default_isr										//Reserved
#define VECTOR_07 default_isr										//Reserved
#define VECTOR_08 default_isr										//Reserved
#define VECTOR_09 default_isr										//Reserved
#define VECTOR_10 default_isr										//Reserved
#define VECTOR_11 SVC_Handler										//SVC_Handler
#define VECTOR_12 default_isr										//Reserved
#define VECTOR_13 default_isr										//Reserved
#define VECTOR_14 PendSV_Handler								//PendSV_Handler
#define VECTOR_15 SysTick_Handler								//SysTick_Handler

#define VECTOR_16 default_isr										//Reserved16_IRQHandler
#define VECTOR_17 default_isr										//Reserved17_IRQHandler
#define VECTOR_18 default_isr										//Reserved18_IRQHandler
#define VECTOR_19 default_isr										//Reserved19_IRQHandler
#define VECTOR_20 default_isr										//Reserved20_IRQHandler
#define VECTOR_21 FTMRE_IRQHandler							//FTMRE_IRQHandler
#define VECTOR_22 PMC_IRQHandler								//PMC_IRQHandler
#define VECTOR_23 IRQ_IRQHandler								//IRQ_IRQHandler
#define VECTOR_24 I2C0_IRQHandler								//I2C0_IRQHandler
#define VECTOR_25 I2C1_IRQHandler								//I2C1_IRQHandler
#define VECTOR_26 SPI0_IRQHandler								//SPI0_IRQHandler
#define VECTOR_27 SPI1_IRQHandler								//SPI1_IRQHandler
#define VECTOR_28 UART0_IRQHandler							//UART0_IRQHandler
#define VECTOR_29 UART1_IRQHandler							//UART1_IRQHandler
#define VECTOR_30 UART2_IRQHandler							//UART2_IRQHandler
#define VECTOR_31 ADC_IRQHandler								//ADC_IRQHandler
#define VECTOR_32 ACMP0_IRQHandler							//ACMP0_IRQHandler
#define VECTOR_33 FTM0_IRQHandler								//FTM0_IRQHandler
#define VECTOR_34 FTM1_IRQHandler								//FTM1_IRQHandler
#define VECTOR_35 FTM2_IRQHandler								//FTM2_IRQHandler
#define VECTOR_36 RTC_IRQHandler								//RTC_IRQHandler
#define VECTOR_37 ACMP1_IRQHandler							//ACMP1_IRQHandler
#define VECTOR_38 PIT_CH0_IRQHandler						//PIT_CH0_IRQHandler
#define VECTOR_39 PIT_CH1_IRQHandler						//PIT_CH1_IRQHandler
#define VECTOR_40 KBI0_IRQHandler								//KBI0_IRQHandler
#define VECTOR_41 KBI1_IRQHandler								//KBI1_IRQHandler
#define VECTOR_42 default_isr										//Reserved42_IRQHandler
#define VECTOR_43 ICS_IRQHandler								//ICS_IRQHandler
#define VECTOR_44 WDOG_IRQHandler								//WDOG_IRQHandler
#define VECTOR_45 PWT_IRQHandler								//PWT_IRQHandler
#define VECTOR_46 MSCAN_RX_IRQHandler						//MSCAN_RX_IRQHandler
#define VECTOR_47 MSCAN_TX_IRQHandler						//MSCAN_TX_IRQHandler


#endif
