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
**GPIO基址指针数组
*/
GPIO_MemMapPtr GPIOX[GPIO_MAX]=
{
	GPIOA_BASE_PTR,//GPIOA:PTA0-PTA7,PTB0-PTB7,PTC0-PTC7,PTD0-PTD7
	GPIOB_BASE_PTR,//GPIOB:PTE0-PTE7,PTF0-PTF7,PTG0-PTG7,PTH0-PTH7
	GPIOC_BASE_PTR //GPIOC:PTI0-PTI7
};

/*
 *  @brief      初始化GPIO
 *  @param      PTXn    端口
 *  @param      CFG     GPIO方向,0=输入,1=输出
 *  @param      DATA    输入初始状态,0=低电平,1=高电平 (输入无效)
 *  @since      v1.0
 *  Sample usage:       GPIO_Init(PTA0, GPI,0)//初始化PTA0为输入
 *  Sample usage:       GPIO_Init(PTA0, GPO,1)//初始化PTA0为输出,输出高电平1
 */
 void GPIO_Init (GPIO_PTXn PTXn, GPIO_CFG CFG, UINT8 DATA)
 {
	 if(CFG==GPI)//Input
	 {
		 GPIO_PDDR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PDDR=0,Input(输入)
		 GPIO_PIDR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PIDR=0,Enable GPI(开启GPI)
	 }
	 else//Output
	 {
		 GPIO_PDDR_REG(GPIOX_BASE(PTXn)) |= (1 << PTn(PTXn));//GPIO_PDDR=1,Output(输出)
		 
		 //端口数据输出
		 if(DATA==0)
		 {
			 GPIO_PDOR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PDOR=0,Low(低电平)
		 }
		 else
		 {
			 GPIO_PDOR_REG(GPIOX_BASE(PTXn)) |= (1 << PTn(PTXn));//GPIO_PDOR=1,High(高电平)
		 }
	 }
 }
 
/*
 *  @brief      设置GPIO数据方向
 *  @param      PTXn    端口
 *  @param      CFG     引脚方向,0=输入,1=输出
 *  @since      v1.0
 *  Sample usage:       GPIO_DDR(PTA0, GPI)//设置PTA0的方向为输入
 */
 void GPIO_DDR(GPIO_PTXn PTXn, GPIO_CFG CFG)
 {
	 if(CFG==GPI)//Input
	 {
		 GPIO_PDDR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PDDR=0,Input(输入)
		 GPIO_PIDR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PIDR=0,Enable GPI(开启GPI)
	 }
	 else//Output
	 {
		 GPIO_PDDR_REG(GPIOX_BASE(PTXn)) |= (1 << PTn(PTXn));//GPIO_PDDR=1,Output(输出)
	 }
 }
 
/*
 *  @brief      设置GPIO状态
 *  @param      PTXn    端口
 *  @param      DATA    初始输出状态,0=低电平,1=高电平 (输入无效)
 *  @since      v1.0
 *  @warning    必须保证数据方向是输出
 *  Sample usage:       GPIO_Set (PTA0, 1);//PTA0 输出高电平
 */
 void GPIO_Set(GPIO_PTXn PTXn, UINT8 DATA)
 {
	 ASSERT(BIT_GET(GPIO_PDDR_REG(GPIOX_BASE(PTXn)), PTn(PTXn)) == GPO);//断言监测当前位是否为GPO
	 
	 if(DATA==0)//Low
	 {
		 GPIO_PDOR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PDOR=0,Low(低电平)
	 }
	 else
	 {
		 GPIO_PDOR_REG(GPIOX_BASE(PTXn)) |= (1 << PTn(PTXn));//GPIO_PDOR=1,High(高电平)
	 }
 }
 
/*
 *  @brief      GPIO状态反转
 *  @param      PTXn    端口
 *  @since      v1.0
 *  @warning    必须保证数据方向是输出
 *  Sample usage:       GPIO_Turn (PTA0);//PTA0 端口电平反转
 */
 void GPIO_Turn(GPIO_PTXn PTXn)
 {
	 ASSERT(BIT_GET(GPIO_PDDR_REG(GPIOX_BASE(PTXn)), PTn(PTXn)) == GPO);//断言监测当前位是否为GPO
	 
	 GPIO_PTOR_REG(GPIOX_BASE(PTXn)) |= (1 << PTn(PTXn));//端口电平反转
 }
 
 /*
 *  @brief      GPIO状态获取
 *  @param      PTXn    端口
 *  @return     端口状态,1=高电平,0=低电平
 *  @since      v1.0
 *  @warning    必须保证数据方向是输入
 *  Sample usage:		UINT8 DATA=GPIO_Get(PTA0);//PTA0 端口电平获取
 */
 
 UINT8 GPIO_Get(GPIO_PTXn PTXn)
 {
	 ASSERT(BIT_GET(GPIO_PDDR_REG(GPIOX_BASE(PTXn)), PTn(PTXn)) == GPI );//断言监测当前位是否为GPI
	 
	 GPIO_PIDR_REG(GPIOX_BASE(PTXn)) &= ~(1 << PTn(PTXn));//GPIO_PIDR=0,Enable GPI(开启GPI)
	 return ((GPIO_PDIR_REG(GPIOX_BASE(PTXn)) >> PTn(PTXn)) & 0x01);//获取GPIO引脚电平状态
 }
 





 