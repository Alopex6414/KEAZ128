/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       PORT_MUX.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */
#ifndef __PORT_MUX_H__
#define __PORT_MUX_H__

#include "Common.h" /* include peripheral declarations */

/*
**PORT_MUX(选择通道 可选端口)
*/
//FTM
//FTMx_CHx_PIN Channal Useable

//FTM0
#define FTM0_CH0_PIN PTA0	//(PTA0 PTB2)
#define FTM0_CH1_PIN PTA1	//(PTA1 PTB3)

//FTM1
#define FTM1_CH0_PIN PTH2	//(PTC4 PTH2)
#define FTM1_CH1_PIN PTE7	//(PTC5 PTE7)

//FTM2
#define FTM2_CH0_PIN PTF0	//(PTC0 PTH0 PTF0)
#define FTM2_CH1_PIN PTF1	//(PTC1 PTH1 PTF1)
#define FTM2_CH2_PIN PTG4	//(PTC2 PTD0 PTG4)
#define FTM2_CH3_PIN PTG5	//(PTC3 PTD1 PTG5)
#define FTM2_CH4_PIN PTG6	//(PTB4 PTG6)
#define FTM2_CH5_PIN PTG7	//(PTB5 PTG7)

//UART
//UARTx_TX/RX_PIN Channal Useable

//UART0
#define UART0_RX_PIN PTB0 //(PTB0 PTA2)
#define UART0_TX_PIN PTB1 //(PTB1 PTA3)

//UART1
#define UART1_RX_PIN PTC6 //(PTC6 PTF2)
#define UART1_TX_PIN PTC7 //(PTC7 PTF3)

//UART2
#define UART2_RX_PIN PTD6 //(PTD6 PTI0)
#define UART2_TX_PIN PTD7 //(PTD7 PTI1)

//SPI
//SPIx_SCK/MISO/MOSI/PCS_PIN Channal Useable

//SPI0
#define SPI0_SCK_PIN	PTB2 //(PTB2 PTE0)
#define SPI0_MOSI_PIN	PTB3 //(PTB3 PTE1)	
#define SPI0_MISO_PIN PTB4 //(PTB4 PTE2)
#define SPI0_PCS_PIN  PTB5 //(PTB5 PTE3)

//SPI1
#define SPI1_SCK_PIN	PTD0 //(PTD0 PTG4)
#define SPI1_MOSI_PIN	PTD1 //(PTD1 PTG5)	
#define SPI1_MISO_PIN PTD2 //(PTD2 PTG6)
#define SPI1_PCS_PIN  PTD3 //(PTD3 PTG7)

//I2C
//I2Cx_SCL/SDA_PIN Channal Useable

//I2C0
#define I2C0_SCL_PIN PTA3 //(PTA3 PTB7)
#define I2C0_SDA_PIN PTA2 //(PTA2 PTB6)

//I2C1
#define I2C1_SCL_PIN PTE1 //(PTE1 PTH4)
#define I2C1_SDA_PIN PTE0 //(PTE0 PTH3)

//PWT
//PWTINx_PIN Channal Useable
#define PWTIN0_PIN PTD5   //(PTD5 PTE2)
#define PWTIN1_PIN PTB0   //(PTB0 PTH7)

#endif
