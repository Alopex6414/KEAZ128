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
**ACMP基址指针
*/
ACMP_MemMapPtr ACMP[ACMP_ACMP_MAX]=
{
	ACMP0_BASE_PTR,	//ACMP0基址指针
	ACMP1_BASE_PTR 	//ACMP1基址指针
};

/*
 *  @brief      DAC 初始化
 *  @param 			ACMP_ACMPn ACMP 端口号
 *  @param 			ACMP_DAC_DATA   转换输出电压(6bit 0-63)
 *  @note 			DAC 输出模拟电压
 *  @since      v1.0
 *  Sample usage:		ACMP_DAC_Init(ACMP_ACMP1,32);
 */
 void ACMP_DAC_Init(ACMP_ACMPn ACMP_ACMPx,uint8 ACMP_DAC_DATA)
 {
	 ASSERT((ACMP_ACMPx <= ACMP_ACMP1) && (ACMP_DAC_DATA < 64));//断言ACMP模块和DAC转换数据(0-63)
	 
	 switch(ACMP_ACMPx)//选择ACMP模块号
	 {
		 case ACMP_ACMP0:
											SIM_SCGC |= SIM_SCGC_ACMP0_MASK;//ACMP0时钟使能
											break;
		 case ACMP_ACMP1:
											SIM_SCGC |= SIM_SCGC_ACMP1_MASK;//ACMP1时钟使能
											break;
		 default:
											break;
	 }
	 
	 ACMP_C1_REG(ACMP[ACMP_ACMPx]) = (0 | ACMP_C1_DACREF_MASK | ACMP_C1_DACVAL(ACMP_DAC_DATA & 0x3f));//VDDA作为DAC基准参考电压,设置DAC输出参考电压
	 ACMP_C1_REG(ACMP[ACMP_ACMPx]) |= ACMP_C1_DACEN_MASK;//DAC使能
	 ACMP_CS_REG(ACMP[ACMP_ACMPx]) = (0 | ACMP_CS_ACE_MASK);//ACMP模块使能
 }


























