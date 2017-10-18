/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       Conf.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */	
 
#include "Common.h" /* include peripheral declarations */
#include "Include.h"

/*
 *  @brief      断言失败执行函数
 *  @param      file    文件路径地址
 *  @param      line    行数
 *  @since      v1.0
 *  Sample usage:       assert_failed(__FILE__, __LINE__);
 */
void assert_failed(char *file, int line)
{	
	while(1)
	{
		//用户可以设置断言失败的反馈信息
		//GPIO_Init(PTF1,GPO,0);
	}
}

/*
 *  @brief      默认中断服务函数
 *  @since      v1.0
 *  @note       默认中断服务函数写入中断向量表,不需要用户执行
 */
void default_isr(void)
{
	#ifdef DEBUG
				while(1)
				{
					//用户可以设置中断指向向量函数
					//GPIO_Init(PTF1,GPO,0);
				}
	#else
				return;
	#endif
}

