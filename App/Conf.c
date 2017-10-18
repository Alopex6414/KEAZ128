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
 *  @brief      ����ʧ��ִ�к���
 *  @param      file    �ļ�·����ַ
 *  @param      line    ����
 *  @since      v1.0
 *  Sample usage:       assert_failed(__FILE__, __LINE__);
 */
void assert_failed(char *file, int line)
{	
	while(1)
	{
		//�û��������ö���ʧ�ܵķ�����Ϣ
		//GPIO_Init(PTF1,GPO,0);
	}
}

/*
 *  @brief      Ĭ���жϷ�����
 *  @since      v1.0
 *  @note       Ĭ���жϷ�����д���ж�������,����Ҫ�û�ִ��
 */
void default_isr(void)
{
	#ifdef DEBUG
				while(1)
				{
					//�û����������ж�ָ����������
					//GPIO_Init(PTF1,GPO,0);
				}
	#else
				return;
	#endif
}

