/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       ADC.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */
 
#include "Common.h" /* include peripheral declarations */
#include "Include.h"

ADC_MemMapPtr ADC_ADC0=ADC_BASE_PTR;//ADC基址指针

/*
 *  @brief      ADC	初始化(ADC时钟初始化)
 *  @note 			ADC端口软件触发
 *  @since      v1.0
 *  Sample usage:		ADC_Init();
 */
 void ADC_Init(void)
 {
	 SIM_SCGC |= SIM_SCGC_ADC_MASK;//ADC Enable(开启ADC时钟)
 }
 
 /*
 *  @brief      ADC	启动采样转换
 *  @param 			ADC0_SEn			ADC端口号
 *  @param 			ADC0_nBIT			ADC采样转换精度
 *  @note 			ADC端口软件触发
 *  @since      v1.0
 *  Sample usage:		ADC_Start(ADC0_SE0,ADC0_12BIT);
 */
 void ADC_Start(ADC0_SEn ADC0_SEx,ADC0_nBIT ADC0_xBIT)
 {
	 //设置ADC转换通道,选中I/O端口ADC模拟量输入打开
	 ADC_APCTL1_REG(ADC_ADC0) = (0 | ADC_APCTL1_ADPC(1<<ADC0_SEx));
	 //设置ADC转换精度,长采样时间,输入时钟为总线时钟(Bus_Clock),ADC输入时钟为总线时钟四分频(ADC_Clock=Bus_Clock/4)
	 ADC_SC3_REG(ADC_ADC0) = (0 | ADC_SC3_MODE(ADC0_xBIT) | ADC_SC3_ADLSMP_MASK | ADC_SC3_ADIV(2) | ADC_SC3_ADICLK(0));
	 //设置转换完成中断使能,相应输入通道选择
	 ADC_SC1_REG(ADC_ADC0) = (0 | ADC_SC1_AIEN_MASK | ADC_SC1_ADCH(ADC0_SEx));//ADC_SC1_AIEN_MASK //ADC_SC1_ADCO_MASK
	 
 }
 
 /*
 *  @brief      ADC	停止采样转换
 *  @param 			ADC0_SEn			ADC端口号
 *  @note 			ADC端口软件触发
 *  @since      v1.0
 *  Sample usage:		ADC_Stop(ADC0_SE0);
 */
 void ADC_Stop(ADC0_SEn ADC0_SEx)
 {
	 ADC_SC1_REG(ADC_ADC0) = (0 | ADC_SC1_AIEN_MASK | ADC_SC1_ADCH(MODULE_DIS));//停止ADC转换
 }
 
 /*
 *  @brief      ADC	获取一次采样转换
 *  @param 			ADC0_SEn			ADC端口号
 *  @param 			ADC0_nBIT			ADC采样转换精度
 *  @note 			ADC端口软件触发
 *  @since      v1.0
 *  Sample usage:		ADC_Once(ADC0_SE0,ADC0_12BIT);
 */
 uint16 ADC_Once(ADC0_SEn ADC0_SEx,ADC0_nBIT ADC0_xBIT)
 {
	 uint16 ADC_Result;
	 
	 //断言参数ADC精度是否满足ADC0_8BIT,ADC0_10BIT,ADC0_12BIT三种精度
	 ASSERT((ADC0_xBIT == ADC0_8BIT) || (ADC0_xBIT == ADC0_10BIT) || (ADC0_xBIT == ADC0_12BIT));
	 
	 //引用ADC_Start函数完成ADC端口初始化配置
	 ADC_Start(ADC0_SEx,ADC0_xBIT);
	 
	 //ADC转换完成标志位ADC_SC1_COCO置位时标志ADC转换完成,可以读取转换结果,否则等待转换完成
	 while((ADC_SC1_REG(ADC_ADC0) & ADC_SC1_COCO_MASK) != ADC_SC1_COCO_MASK);
	 //读取ADC转换结果
	 ADC_Result = ADC_R_REG(ADC_ADC0);
	 //清除ADC转换完成标志位ADC_SC1_COCO
	 ADC_SC1_REG(ADC_ADC0) &= ~ADC_SC1_COCO_MASK;
	 
	 return ADC_Result;
 }

  /*
 *  @brief      ADC	获取多次采样转换均值
 *  @param 			ADC0_SEn			ADC端口号
 *  @param 			ADC0_nBIT			ADC采样转换精度
 *  @param 			ADC0_Samp_Num	ADC采样转换次数
 *  @note 			ADC端口软件触发
 *  @since      v1.0
 *  Sample usage:		ADC_Average(ADC0_SE0,ADC0_12BIT,20);
 */
 uint16 ADC_Average(ADC0_SEn ADC0_SEx,ADC0_nBIT ADC0_xBIT,uint8 ADC_Samp_Num)
 {
	 uint8 i=0;
	 uint16 ADC_Samp_Average=0;
	 uint32 ADC_Samp_Sum=0;
	 
	 //断言参数ADC精度是否满足ADC0_8BIT,ADC0_10BIT,ADC0_12BIT三种精度
	 ASSERT((ADC0_xBIT == ADC0_8BIT) || (ADC0_xBIT == ADC0_10BIT) || (ADC0_xBIT == ADC0_12BIT));
	 
	 for(i=0;i<ADC_Samp_Num;i++)
	 {
		 //引用ADC_Start函数完成ADC端口初始化配置
		 ADC_Start(ADC0_SEx,ADC0_xBIT);
		 
		 //ADC转换完成标志位ADC_SC1_COCO置位时标志ADC转换完成,可以读取转换结果,否则等待转换完成
		 while((ADC_SC1_REG(ADC_ADC0) & ADC_SC1_COCO_MASK) != ADC_SC1_COCO_MASK);
		 
		 //ADC转换结果累加
		 ADC_Samp_Sum += ADC_R_REG(ADC_ADC0);
		 
		 //清除ADC转换完成标志位ADC_SC1_COCO
	   ADC_SC1_REG(ADC_ADC0) &= ~ADC_SC1_COCO_MASK;
	 }
	 
	 //ADC采样均值
	 ADC_Samp_Average = ADC_Samp_Sum / ADC_Samp_Num;
	 
	 return ADC_Samp_Average;
	 
 }
 
 
 
 
 