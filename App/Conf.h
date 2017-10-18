#ifndef __CONF_H__
#define __CONF_H__

#include "typedefs.h"

/*
**KEA锁频环FLL时钟频率设置
*/
#define KEA_Core_CLK 						FLL40			//KEA内核时钟FLL频率(Core/System),可设置频率FLL5,FLL10,FLL20,FLL40
#define KEA_Core_Div						0					//KEA内核时钟分频(Core/System),分频系数0,1,2,3,计算公式Core_CLK/(2^Div),(默认分频系数0)
#define KEA_Bus_Div				 			0					//KEA总线/Flash分频(Bus/Flash),分频系数0,1,(默认分频系数0)
#define KEA_Tim_Div							0					//KEA定时器分频(FTM/PWT),分频系数0,1,(默认分频系数0)

/*
 *断言(ASSERT)
 */
#if defined( DEBUG )
#define ASSERT(expr) \
    if (!(expr)) \
        assert_failed(__FILE__, __LINE__)
#else
#define ASSERT(expr)
#endif

/*
**function declaration
*/		
extern void assert_failed(char *, int);
extern void default_isr(void);

#endif

