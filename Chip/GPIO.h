/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       GPIO.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */	 
 
#ifndef __GPIO_H__
#define __GPIO_H__

#include "Common.h" /* include peripheral declarations */

/*
**GPIOA
*/
#define PTA  GPIOA
#define PTB  GPIOA
#define PTC  GPIOA
#define PTD  GPIOA

/*
**GPIOB
*/
#define PTE	GPIOB
#define PTF	GPIOB
#define PTG	GPIOB
#define PTH	GPIOB

/*
**GPIOC
*/
#define PTI	GPIOC

/*
**GPIO状态和输出电平
*/
#define OUTPUT  1
#define INPUT	0

#define HIGH 1U
#define LOW 0U

/*
**端口设置宏
*/
#define GPIO_SET(PTX,DATA)					(PTX->PSOR |= 1<<((DATA)&0x1f))

#define GPIO_CLEAR(PTX,DATA)				(PTX->PCOR |= 1<<((DATA)&0x1f))

#define GPIO_TURN(PTX,DATA)					(PTX->PTOR |= 1<<((DATA)&0x1f))

//端口地址转换
#define GPIO_X(PTxn)           ((PTxn)>>5)						//PTx = PTxn / 32
#define PTn(PTxn)              ((PTxn)&0x1f)					//PTn = PTxn & 31

#define GPIOX_BASE(PTxn)    GPIOX[GPIO_X(PTxn)]       //GPIO模块的地址

/*
**端口枚举
*/
typedef enum
{
	/*GPIOA_Register*/
	PTA0,PTA1,PTA2,PTA3,PTA4,PTA5,PTA6,PTA7,//PTA
	PTB0,PTB1,PTB2,PTB3,PTB4,PTB5,PTB6,PTB7,//PTB
	PTC0,PTC1,PTC2,PTC3,PTC4,PTC5,PTC6,PTC7,//PTC
	PTD0,PTD1,PTD2,PTD3,PTD4,PTD5,PTD6,PTD7,//PTD
	/*GPIOB_Register*/
	PTE0,PTE1,PTE2,PTE3,PTE4,PTE5,PTE6,PTE7,//PTE
	PTF0,PTF1,PTF2,PTF3,PTF4,PTF5,PTF6,PTF7,//PTF
	PTG0,PTG1,PTG2,PTG3,PTG4,PTG5,PTG6,PTG7,//PTG
	PTH0,PTH1,PTH2,PTH3,PTH4,PTH5,PTH6,PTH7,//PTH
	/*GPIOC_Register*/
	PTI0,PTI1,PTI2,PTI3,PTI4,PTI5,PTI6,PTI7,//PTI
}GPIO_PTXn;

/*
**寄存器枚举
*/
typedef enum
{
	GPIO_A,//GPIOA
	GPIO_B,//GPIOB
	GPIO_C,//GPIOC
	GPIO_MAX,
}GPIO_X;

typedef enum
{
	GPI=0,//Input
	GPO=1,//Output
}GPIO_CFG;

/*
**variate declaration
*/
extern  GPIO_MemMapPtr      GPIOX[GPIO_MAX];

/*
**function declaration
*/
extern void GPIO_Init (GPIO_PTXn PTXn, GPIO_CFG CFG, UINT8 DATA);
extern void GPIO_DDR(GPIO_PTXn PTXn, GPIO_CFG CFG);
extern void GPIO_Set(GPIO_PTXn PTXn, UINT8 DATA);
extern void GPIO_Turn(GPIO_PTXn PTXn);
extern UINT8 GPIO_Get(GPIO_PTXn PTXn);

#endif /* GPIO_H_ */
