/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       GPIO.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */
 
#include "Common.h" /* include peripheral declarations */
#include "Include.h"

/*
**GPIO��ַָ������
*/
GPIO_MemMapPtr GPIOX[GPIO_MAX]=
{
	GPIOA_BASE_PTR,//GPIOA:PTA0-PTA7,PTB0-PTB7,PTC0-PTC7,PTD0-PTD7
	GPIOB_BASE_PTR,//GPIOB:PTE0-PTE7,PTF0-PTF7,PTG0-PTG7,PTH0-PTH7
	GPIOC_BASE_PTR //GPIOC:PTI0-PTI7
};

/*
 *  @brief      ��ʼ��GPIO
 *  @param      PTXn    �˿�
 *  @param      CFG     GPIO����,0=����,1=���
 *  @param      DATA    �����ʼ״̬,0=�͵�ƽ,1=�ߵ�ƽ (������Ч)
 *  @since      v1.0
 *  Sample usage:       GPIO_Init(PTA0, GPI,0)//��ʼ��PTA0Ϊ����
 *  Sample usage:       GPIO_Init(PTA0, GPO,1)//��ʼ��PTA0Ϊ���,����ߵ�ƽ1
 */
 void GPIO_Init (GPIO_PTXn PTXn, GPIO_CFG CFG, UINT8 DATA)
 {
	 if(CFG==GPI)//Input
	 {
		 GPIO_PDDR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PDDR=0,Input(����)
		 GPIO_PIDR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PIDR=0,Enable GPI(����GPI)
	 }
	 else//Output
	 {
		 GPIO_PDDR_REG(GPIOX_BASE(PTXn)) |= (1 << PTn(PTXn));//GPIO_PDDR=1,Output(���)
		 
		 //�˿��������
		 if(DATA==0)
		 {
			 GPIO_PDOR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PDOR=0,Low(�͵�ƽ)
		 }
		 else
		 {
			 GPIO_PDOR_REG(GPIOX_BASE(PTXn)) |= (1 << PTn(PTXn));//GPIO_PDOR=1,High(�ߵ�ƽ)
		 }
	 }
 }
 
/*
 *  @brief      ����GPIO���ݷ���
 *  @param      PTXn    �˿�
 *  @param      CFG     ���ŷ���,0=����,1=���
 *  @since      v1.0
 *  Sample usage:       GPIO_DDR(PTA0, GPI)//����PTA0�ķ���Ϊ����
 */
 void GPIO_DDR(GPIO_PTXn PTXn, GPIO_CFG CFG)
 {
	 if(CFG==GPI)//Input
	 {
		 GPIO_PDDR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PDDR=0,Input(����)
		 GPIO_PIDR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PIDR=0,Enable GPI(����GPI)
	 }
	 else//Output
	 {
		 GPIO_PDDR_REG(GPIOX_BASE(PTXn)) |= (1 << PTn(PTXn));//GPIO_PDDR=1,Output(���)
	 }
 }
 
/*
 *  @brief      ����GPIO״̬
 *  @param      PTXn    �˿�
 *  @param      DATA    ��ʼ���״̬,0=�͵�ƽ,1=�ߵ�ƽ (������Ч)
 *  @since      v1.0
 *  @warning    ���뱣֤���ݷ��������
 *  Sample usage:       GPIO_Set (PTA0, 1);//PTA0 ����ߵ�ƽ
 */
 void GPIO_Set(GPIO_PTXn PTXn, UINT8 DATA)
 {
	 ASSERT(BIT_GET(GPIO_PDDR_REG(GPIOX_BASE(PTXn)), PTn(PTXn)) == GPO);//���Լ�⵱ǰλ�Ƿ�ΪGPO
	 
	 if(DATA==0)//Low
	 {
		 GPIO_PDOR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PDOR=0,Low(�͵�ƽ)
	 }
	 else
	 {
		 GPIO_PDOR_REG(GPIOX_BASE(PTXn)) |= (1 << PTn(PTXn));//GPIO_PDOR=1,High(�ߵ�ƽ)
	 }
 }
 
/*
 *  @brief      GPIO״̬��ת
 *  @param      PTXn    �˿�
 *  @since      v1.0
 *  @warning    ���뱣֤���ݷ��������
 *  Sample usage:       GPIO_Turn (PTA0);//PTA0 �˿ڵ�ƽ��ת
 */
 void GPIO_Turn(GPIO_PTXn PTXn)
 {
	 ASSERT(BIT_GET(GPIO_PDDR_REG(GPIOX_BASE(PTXn)), PTn(PTXn)) == GPO);//���Լ�⵱ǰλ�Ƿ�ΪGPO
	 
	 GPIO_PTOR_REG(GPIOX_BASE(PTXn)) |= (1 << PTn(PTXn));//�˿ڵ�ƽ��ת
 }
 
 /*
 *  @brief      GPIO״̬��ȡ
 *  @param      PTXn    �˿�
 *  @return     �˿�״̬,1=�ߵ�ƽ,0=�͵�ƽ
 *  @since      v1.0
 *  @warning    ���뱣֤���ݷ���������
 *  Sample usage:		UINT8 DATA=GPIO_Get(PTA0);//PTA0 �˿ڵ�ƽ��ȡ
 */
 
 UINT8 GPIO_Get(GPIO_PTXn PTXn)
 {
	 ASSERT(BIT_GET(GPIO_PDDR_REG(GPIOX_BASE(PTXn)), PTn(PTXn)) == GPI );//���Լ�⵱ǰλ�Ƿ�ΪGPI
	 
	 GPIO_PIDR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PIDR=0,Enable GPI(����GPI)
	 return ((GPIO_PDIR_REG(GPIOX_BASE(PTXn)) >> PTn(PTXn)) & 0x01);//��ȡGPIO���ŵ�ƽ״̬
 }
 





 