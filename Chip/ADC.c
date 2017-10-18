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

ADC_MemMapPtr ADC_ADC0=ADC_BASE_PTR;//ADC��ַָ��

/*
 *  @brief      ADC	��ʼ��(ADCʱ�ӳ�ʼ��)
 *  @note 			ADC�˿��������
 *  @since      v1.0
 *  Sample usage:		ADC_Init();
 */
 void ADC_Init(void)
 {
	 SIM_SCGC |= SIM_SCGC_ADC_MASK;//ADC Enable(����ADCʱ��)
 }
 
 /*
 *  @brief      ADC	��������ת��
 *  @param 			ADC0_SEn			ADC�˿ں�
 *  @param 			ADC0_nBIT			ADC����ת������
 *  @note 			ADC�˿��������
 *  @since      v1.0
 *  Sample usage:		ADC_Start(ADC0_SE0,ADC0_12BIT);
 */
 void ADC_Start(ADC0_SEn ADC0_SEx,ADC0_nBIT ADC0_xBIT)
 {
	 //����ADCת��ͨ��,ѡ��I/O�˿�ADCģ���������
	 ADC_APCTL1_REG(ADC_ADC0) = (0 | ADC_APCTL1_ADPC(1<<ADC0_SEx));
	 //����ADCת������,������ʱ��,����ʱ��Ϊ����ʱ��(Bus_Clock),ADC����ʱ��Ϊ����ʱ���ķ�Ƶ(ADC_Clock=Bus_Clock/4)
	 ADC_SC3_REG(ADC_ADC0) = (0 | ADC_SC3_MODE(ADC0_xBIT) | ADC_SC3_ADLSMP_MASK | ADC_SC3_ADIV(2) | ADC_SC3_ADICLK(0));
	 //����ת������ж�ʹ��,��Ӧ����ͨ��ѡ��
	 ADC_SC1_REG(ADC_ADC0) = (0 | ADC_SC1_AIEN_MASK | ADC_SC1_ADCH(ADC0_SEx));//ADC_SC1_AIEN_MASK //ADC_SC1_ADCO_MASK
	 
 }
 
 /*
 *  @brief      ADC	ֹͣ����ת��
 *  @param 			ADC0_SEn			ADC�˿ں�
 *  @note 			ADC�˿��������
 *  @since      v1.0
 *  Sample usage:		ADC_Stop(ADC0_SE0);
 */
 void ADC_Stop(ADC0_SEn ADC0_SEx)
 {
	 ADC_SC1_REG(ADC_ADC0) = (0 | ADC_SC1_AIEN_MASK | ADC_SC1_ADCH(MODULE_DIS));//ֹͣADCת��
 }
 
 /*
 *  @brief      ADC	��ȡһ�β���ת��
 *  @param 			ADC0_SEn			ADC�˿ں�
 *  @param 			ADC0_nBIT			ADC����ת������
 *  @note 			ADC�˿��������
 *  @since      v1.0
 *  Sample usage:		ADC_Once(ADC0_SE0,ADC0_12BIT);
 */
 uint16 ADC_Once(ADC0_SEn ADC0_SEx,ADC0_nBIT ADC0_xBIT)
 {
	 uint16 ADC_Result;
	 
	 //���Բ���ADC�����Ƿ�����ADC0_8BIT,ADC0_10BIT,ADC0_12BIT���־���
	 ASSERT((ADC0_xBIT == ADC0_8BIT) || (ADC0_xBIT == ADC0_10BIT) || (ADC0_xBIT == ADC0_12BIT));
	 
	 //����ADC_Start�������ADC�˿ڳ�ʼ������
	 ADC_Start(ADC0_SEx,ADC0_xBIT);
	 
	 //ADCת����ɱ�־λADC_SC1_COCO��λʱ��־ADCת�����,���Զ�ȡת�����,����ȴ�ת�����
	 while((ADC_SC1_REG(ADC_ADC0) & ADC_SC1_COCO_MASK) != ADC_SC1_COCO_MASK);
	 //��ȡADCת�����
	 ADC_Result = ADC_R_REG(ADC_ADC0);
	 //���ADCת����ɱ�־λADC_SC1_COCO
	 ADC_SC1_REG(ADC_ADC0) &= ~ADC_SC1_COCO_MASK;
	 
	 return ADC_Result;
 }

  /*
 *  @brief      ADC	��ȡ��β���ת����ֵ
 *  @param 			ADC0_SEn			ADC�˿ں�
 *  @param 			ADC0_nBIT			ADC����ת������
 *  @param 			ADC0_Samp_Num	ADC����ת������
 *  @note 			ADC�˿��������
 *  @since      v1.0
 *  Sample usage:		ADC_Average(ADC0_SE0,ADC0_12BIT,20);
 */
 uint16 ADC_Average(ADC0_SEn ADC0_SEx,ADC0_nBIT ADC0_xBIT,uint8 ADC_Samp_Num)
 {
	 uint8 i=0;
	 uint16 ADC_Samp_Average=0;
	 uint32 ADC_Samp_Sum=0;
	 
	 //���Բ���ADC�����Ƿ�����ADC0_8BIT,ADC0_10BIT,ADC0_12BIT���־���
	 ASSERT((ADC0_xBIT == ADC0_8BIT) || (ADC0_xBIT == ADC0_10BIT) || (ADC0_xBIT == ADC0_12BIT));
	 
	 for(i=0;i<ADC_Samp_Num;i++)
	 {
		 //����ADC_Start�������ADC�˿ڳ�ʼ������
		 ADC_Start(ADC0_SEx,ADC0_xBIT);
		 
		 //ADCת����ɱ�־λADC_SC1_COCO��λʱ��־ADCת�����,���Զ�ȡת�����,����ȴ�ת�����
		 while((ADC_SC1_REG(ADC_ADC0) & ADC_SC1_COCO_MASK) != ADC_SC1_COCO_MASK);
		 
		 //ADCת������ۼ�
		 ADC_Samp_Sum += ADC_R_REG(ADC_ADC0);
		 
		 //���ADCת����ɱ�־λADC_SC1_COCO
	   ADC_SC1_REG(ADC_ADC0) &= ~ADC_SC1_COCO_MASK;
	 }
	 
	 //ADC������ֵ
	 ADC_Samp_Average = ADC_Samp_Sum / ADC_Samp_Num;
	 
	 return ADC_Samp_Average;
	 
 }
 
 
 
 
 