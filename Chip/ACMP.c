/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       ACMP.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-19
 */

#include "Common.h" /* include peripheral declarations */
#include "Include.h"

/*
**ACMP��ַָ��
*/
ACMP_MemMapPtr ACMP[ACMP_ACMP_MAX]=
{
	ACMP0_BASE_PTR,	//ACMP0��ַָ��
	ACMP1_BASE_PTR 	//ACMP1��ַָ��
};

/*
 *  @brief      DAC ��ʼ��
 *  @param 			ACMP_ACMPn ACMP �˿ں�
 *  @param 			ACMP_DAC_DATA   ת�������ѹ(6bit 0-63)
 *  @note 			DAC ���ģ���ѹ
 *  @since      v1.0
 *  Sample usage:		ACMP_DAC_Init(ACMP_ACMP1,32);
 */
 void ACMP_DAC_Init(ACMP_ACMPn ACMP_ACMPx,uint8 ACMP_DAC_DATA)
 {
	 ASSERT((ACMP_ACMPx <= ACMP_ACMP1) && (ACMP_DAC_DATA < 64));//����ACMPģ���DACת������(0-63)
	 
	 switch(ACMP_ACMPx)//ѡ��ACMPģ���
	 {
		 case ACMP_ACMP0:
											SIM_SCGC |= SIM_SCGC_ACMP0_MASK;//ACMP0ʱ��ʹ��
											break;
		 case ACMP_ACMP1:
											SIM_SCGC |= SIM_SCGC_ACMP1_MASK;//ACMP1ʱ��ʹ��
											break;
		 default:
											break;
	 }
	 
	 ACMP_C1_REG(ACMP[ACMP_ACMPx]) = (0 | ACMP_C1_DACREF_MASK | ACMP_C1_DACVAL(ACMP_DAC_DATA & 0x3f));//VDDA��ΪDAC��׼�ο���ѹ,����DAC����ο���ѹ
	 ACMP_C1_REG(ACMP[ACMP_ACMPx]) |= ACMP_C1_DACEN_MASK;//DACʹ��
	 ACMP_CS_REG(ACMP[ACMP_ACMPx]) = (0 | ACMP_CS_ACE_MASK);//ACMPģ��ʹ��
 }


























