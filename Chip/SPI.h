/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       SPI.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-19
 */
 
#ifndef __SPI_H__
#define __SPI_H__

#include "Common.h" /* include peripheral declarations */

/*
**SPI模块
*/
typedef enum
{
	SPI_SPI0,
	SPI_SPI1,
	SPI_SPI_MAX
}SPI_SPIn;

/*
**SPI主机从机模式
*/
typedef enum
{
	MASTER,
	SLAVE
}SPI_CFG;

/*
**variate declaration
*/
extern SPI_MemMapPtr SPIN[SPI_SPI_MAX];
/*
**function declaration
*/
extern void SPI_Init(SPI_SPIn SPI_SPIx,SPI_CFG SPI_CFG_x,uint32 SPI_Baud);

#endif



