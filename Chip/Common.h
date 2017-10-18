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
 * ������������
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
 *  @brief �����ļ�����
 */
#include <Conf.h>

/*
 * �����λ�������������
 */
 
/*
 *  @brief ����λ��0����1
 */
#define BIT_CLEAN(var,n)        (var) &= ~(1<<(n))   //����var�ĵ�nλ(����n+1λ)��0
#define BIT_SET(var,n)          (var) |=  (1<<(n))   //����var�ĵ�nλ(����n+1λ)��1
#define BIT_GET(var,n)          (((var)>>(n))&0x01)  //��ȡ����var�ĵ�nλ(����n+1λ)

/*
**�ж�����IRQ
*/
//ʹ��/��ֹIRQ�ж�����,�����ж�IRQ���ȼ�
#define Enable_IRQ(Vector) 								NVIC_EnableIRQ(Vector)					//�ж�ʹ��
#define Disable_IRQ(Vector)								NVIC_DisableIRQ(Vector)					//�жϽ�ֹ
#define Set_Priority_IRQ(Vector,Pro)			NVIC_SetPriority(Vector,Pro)		//�ж����ȼ�����

#define Enable_Interrupts 								__ASM("cpsie i");								//�����ж�
#define Disable_Interrupts								__ASM("cpsid i");								//�����ж�

/*
**function declaration
*/
extern int main(void);

#endif /*__COMMON_H__*/
