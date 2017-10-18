/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       Common.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */
#ifndef __COMMON_H__
#define __COMMON_H__

#include "SKEAZ1284.h"
#include "typedefs.h"

#define DEBUG

/*
 * 数据类型声明
 */
typedef unsigned char       uint8;  /*  8 bits */
typedef unsigned short int  uint16; /* 16 bits */
typedef unsigned long int   uint32; /* 32 bits */
typedef unsigned long long  uint64; /* 64 bits */

typedef char                int8;   /*  8 bits */
typedef short int           int16;  /* 16 bits */
typedef long  int           int32;  /* 32 bits */
typedef long  long          int64;  /* 64 bits */

typedef volatile int8       vint8;  /*  8 bits */
typedef volatile int16      vint16; /* 16 bits */
typedef volatile int32      vint32; /* 32 bits */
typedef volatile int64      vint64; /* 64 bits */

typedef volatile uint8      vuint8;  /*  8 bits */
typedef volatile uint16     vuint16; /* 16 bits */
typedef volatile uint32     vuint32; /* 32 bits */
typedef volatile uint64     vuint64; /* 64 bits */

/*
 *  @brief 配置文件包含
 */
#include <Conf.h>

/*
 * 定义带位域的联合体类型
 */
 
/*
 *  @brief 变量位清0和置1
 */
#define BIT_CLEAN(var,n)        (var) &= ~(1<<(n))   //变量var的第n位(即第n+1位)清0
#define BIT_SET(var,n)          (var) |=  (1<<(n))   //变量var的第n位(即第n+1位)置1
#define BIT_GET(var,n)          (((var)>>(n))&0x01)  //读取变量var的第n位(即第n+1位)

/*
**中断请求IRQ
*/
//使能/禁止IRQ中断请求,设置中断IRQ优先级
#define Enable_IRQ(Vector) 								NVIC_EnableIRQ(Vector)					//中断使能
#define Disable_IRQ(Vector)								NVIC_DisableIRQ(Vector)					//中断禁止
#define Set_Priority_IRQ(Vector,Pro)			NVIC_SetPriority(Vector,Pro)		//中断优先级设置

#define Enable_Interrupts 								__ASM("cpsie i");								//开总中断
#define Disable_Interrupts								__ASM("cpsid i");								//关总中断

/*
**function declaration
*/
extern int main(void);

#endif /*__COMMON_H__*/
