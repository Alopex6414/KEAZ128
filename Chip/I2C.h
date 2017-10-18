/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       I2C.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-17
 */
 
#ifndef __I2C_H__
#define __I2C_H__

#include "Common.h" /* include peripheral declarations */

/*
**I2C模块
*/
typedef enum
{
	I2C_I2C0,	//I2C0
	I2C_I2C1,	//I2C1
	I2C_I2C_MAX
}I2C_I2Cn;

/*
**I2C主机读写模式
*/
typedef enum
{
	I2C_MWSR,
	I2C_MRSW
}I2C_Mode;

/*
**I2C宏
*/
#define I2C_Start(I2C_I2Cx) 					I2C_C1_REG(I2CN[I2C_I2Cx]) |= (I2C_C1_TX_MASK | I2C_C1_MST_MASK)
#define I2C_Stop(I2C_I2Cx)						I2C_C1_REG(I2CN[I2C_I2Cx]) &= ~(I2C_C1_TX_MASK | I2C_C1_MST_MASK)
#define I2C_RepeatedStart(I2C_I2Cx) 	I2C_C1_REG(I2CN[I2C_I2Cx]) |= I2C_C1_RSTA_MASK
#define I2C_EnterRxMode(I2C_I2Cx)			I2C_C1_REG(I2CN[I2C_I2Cx]) &= ~(I2C_C1_TX_MASK | I2C_C1_TXAK_MASK)
#define I2C_PutinRxMode(I2C_I2Cx)			I2C_C1_REG(I2CN[I2C_I2Cx]) &= ~I2C_C1_TX_MASK; I2C_C1_REG(I2CN[I2C_I2Cx]) |= I2C_C1_TXAK_MASK
#define I2C_DisableAck(I2C_I2Cx)			I2C_C1_REG(I2CN[I2C_I2Cx]) |= I2C_C1_TXAK_MASK
#define I2C_Wait(I2C_I2Cx)						while(( I2C_S_REG(I2CN[I2C_I2Cx]) & I2C_S_IICIF_MASK)==0){};I2C_S_REG(I2CN[I2C_I2Cx]) |= I2C_S_IICIF_MASK
#define I2C_Write_Byte(I2C_I2Cx,DATA)	(I2C_D_REG(I2CN[I2C_I2Cx]) = (DATA));I2C_Wait(I2C_I2Cx)

/*
**variate declaration
*/
extern I2C_MemMapPtr I2CN[I2C_I2C_MAX];

/*
**function declaration
*/
extern void I2C_Init(I2C_I2Cn I2C_I2Cx,uint32 I2C_Baud);
extern void I2C_Delay(uint16 I2C_Delay_us);
extern void I2C_Write_Reg(I2C_I2Cn I2C_I2Cx,uint8 I2C_Slave_Adress,uint8 I2C_Reg_Adress,uint8 DATA);
extern uint8 I2C_Read_Reg(I2C_I2Cn I2C_I2Cx,uint8 I2C_Slave_Adress,uint8 I2C_Reg_Adress);

#endif
