#ifndef __CONF_H__
#define __CONF_H__

#include "typedefs.h"

/*
**KEA��Ƶ��FLLʱ��Ƶ������
*/
#define KEA_Core_CLK 						FLL40			//KEA�ں�ʱ��FLLƵ��(Core/System),������Ƶ��FLL5,FLL10,FLL20,FLL40
#define KEA_Core_Div						0					//KEA�ں�ʱ�ӷ�Ƶ(Core/System),��Ƶϵ��0,1,2,3,���㹫ʽCore_CLK/(2^Div),(Ĭ�Ϸ�Ƶϵ��0)
#define KEA_Bus_Div				 			0					//KEA����/Flash��Ƶ(Bus/Flash),��Ƶϵ��0,1,(Ĭ�Ϸ�Ƶϵ��0)
#define KEA_Tim_Div							0					//KEA��ʱ����Ƶ(FTM/PWT),��Ƶϵ��0,1,(Ĭ�Ϸ�Ƶϵ��0)

/*
 *����(ASSERT)
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

