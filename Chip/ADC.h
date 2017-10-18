/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       ADC.h
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */	
 
#ifndef __ADC_H__
#define __ADC_H__

#include "Common.h" /* include peripheral declarations */

/*
**ADC端口
*/
typedef enum
{
	ADC0_SE0, //PTA0
	ADC0_SE1, //PTA1
	ADC0_SE2, //PTA6
	ADC0_SE3, //PTA7
	ADC0_SE4, //PTB0
	ADC0_SE5, //PTB1
	ADC0_SE6, //PTB2
	ADC0_SE7, //PTB3
	ADC0_SE8, //PTC0
	ADC0_SE9, //PTC1
	ADC0_SE10,//PTC2
	ADC0_SE11,//PTC3
	ADC0_SE12,//PTF4
	ADC0_SE13,//PTF5
	ADC0_SE14,//PTF6
	ADC0_SE15,//PTF7
	VSS0,			//VSS
	VSS1,			//VSS
	VSS2,			//VSS
	VSS3,			//VSS
	RES0,			//Reserved
	RES1,			//Reserved
	TEMP,			//Temperature Sensor
	BANDGAP,	//Bandgap
	RES2,			//Reserved
	RES3,			//Reserved
	RES4,			//Reserved
	RES5,			//Reserved
	RES6,			//Reserved
	VREFH,		//VREFH
	VREFL,		//VREFL
	MODULE_DIS//Module Disable
}ADC0_SEn;

/*
**ADC转换精度
*/
typedef enum
{
	ADC0_8BIT,
	ADC0_10BIT,
	ADC0_12BIT
}ADC0_nBIT;

/*
**variate declaration
*/
extern ADC_MemMapPtr ADC_ADC0;

/*
**function declaration
*/
extern void ADC_Init(void);
extern void ADC_Start(ADC0_SEn ADC0_SEx,ADC0_nBIT ADC0_xBIT);
extern void ADC_Stop(ADC0_SEn ADC0_SEx);
extern uint16 ADC_Once(ADC0_SEn ADC0_SEx,ADC0_nBIT ADC0_xBIT);
extern uint16 ADC_Average(ADC0_SEn ADC0_SEx,ADC0_nBIT ADC0_xBIT,uint8 ADC_Samp_Num);

#endif
