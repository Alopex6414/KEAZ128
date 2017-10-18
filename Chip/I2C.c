/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       I2C.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-17
 */

#include "Common.h" /* include peripheral declarations */
#include "Include.h"
 
/*
**I2C基址指针
*/
I2C_MemMapPtr I2CN[I2C_I2C_MAX]=
{
	I2C0_BASE_PTR,
	I2C1_BASE_PTR
};
 
/*
 *  @brief      I2C初始化 设置波特率
 *  @param      I2C_I2Cn  I2C模块号
 *  @param      I2C_Baud  I2C波特率(KHz)
 *  @since      v1.0
 *  Sample usage I2C_Init(I2C_I2C0,400);
 */
 void I2C_Init(I2C_I2Cn I2C_I2Cx,uint32 I2C_Baud)
 {
	 uint8 I2C_ICR = 0;
	 uint8 I2C_N = 64;
	 uint16 I2C_MinDvalue = ~0;
	 uint16 I2C_Dvalue = 0;
	 uint16 I2C_SCL_Div = (KEA_Bus_CLK_KHz * 1000) / I2C_Baud;
	 uint16 I2C_SCL_Divider[64]=
	 {
		 20, 22, 24, 26, 28, 30, 34, 40, 28, 32, 36, 40, 44, 48, 56, 68,
     48, 56, 64, 72, 80, 88, 104, 128, 80, 96, 112, 128, 144, 160, 192, 240,
     160, 192, 224, 256, 288, 320, 384, 480, 320, 384, 448, 512, 576, 640, 768, 960,
     640, 768, 896, 1024, 1152, 1280, 1536, 1920, 1280, 1536, 1792, 2048, 2304, 2560, 3072, 3840
	 };
	 
	 ASSERT(I2C_I2Cx <= I2C_I2C1);
	 
	 switch(I2C_I2Cx)
	 {
		 case I2C_I2C0:
										SIM_SCGC |= SIM_SCGC_I2C0_MASK;
										if(I2C0_SCL_PIN == PTA3 && I2C0_SDA_PIN == PTA2)
										{
											SIM_PINSEL0 &= ~SIM_PINSEL_I2C0PS_MASK;
										}
										else if(I2C0_SCL_PIN == PTB7 && I2C0_SDA_PIN == PTB6)
										{
											SIM_PINSEL0 |= SIM_PINSEL_I2C0PS_MASK;
										}
										else
										{
											ASSERT(0);
										}
										break;
		 case I2C_I2C1:
										SIM_SCGC |= SIM_SCGC_I2C1_MASK;
										if(I2C1_SCL_PIN == PTE1 && I2C1_SDA_PIN == PTE0)
										{
											SIM_PINSEL1 &= ~SIM_PINSEL1_I2C1PS_MASK;
										}
										else if(I2C1_SCL_PIN == PTH4 && I2C1_SDA_PIN == PTH3)
										{
											SIM_PINSEL1 |= SIM_PINSEL1_I2C1PS_MASK;
										}
										else
										{
											ASSERT(0);
										}
										break;
		 default:
										break;
	 }
	 
	 while(I2C_N)
	 {
		 I2C_N--;
		 I2C_Dvalue = abs(I2C_SCL_Div - I2C_SCL_Divider[I2C_N]);
		 
		 if(I2C_Dvalue == 0)
		 {
			 I2C_ICR = I2C_N;
		 }
		 
		 if(I2C_Dvalue < I2C_MinDvalue)
		 {
			 I2C_ICR = I2C_N;
			 I2C_MinDvalue = I2C_ICR;
		 }
		 
	 }
	 
	 I2C_F_REG(I2CN[I2C_I2Cx]) = (0 | I2C_F_MULT(0) | I2C_F_ICR(I2C_ICR));
	 I2C_C1_REG(I2CN[I2C_I2Cx]) = (0 | I2C_C1_IICEN_MASK);
	 
 }
 
/*
 *  @brief      I2C通信延时
 *  @param      I2C_Delay_us
 *  @since      v1.0
 *  Sample usage I2C_Delay(5);
 */
 void I2C_Delay(uint16 I2C_Delay_us)
 {
	 uint16 i=0;
	 uint16 j=0;
	 
	 for(i=0;i<I2C_Delay_us;i++)
	 {
		 for(j=0;j<KEA_Core_FLL_CLK_MHz;j++)
		 {
			 __ASM("nop");
		 }
	 }
	 
 }
 
 /*
 *  @brief      I2C写入从机寄存器一个字节
 *  @param      I2C_I2Cn  I2C模块号
 *  @param      I2C_Slave_Adress  I2C波特率(KHz)
 *  @param      I2C_Reg_Adress    I2C从机寄存器地址
 *  @param      DATA							数据
 *  @since      v1.0
 *  Sample usage I2C_Write_Reg(I2C_I2C0,I2C_Slave_Adress,I2C_Reg_Adress,0x07);
 */
 void I2C_Write_Reg(I2C_I2Cn I2C_I2Cx,uint8 I2C_Slave_Adress,uint8 I2C_Reg_Adress,uint8 DATA)
 {
	 I2C_Start(I2C_I2Cx);
	 I2C_Write_Byte(I2C_I2Cx,(I2C_Slave_Adress << 1) | I2C_MWSR);
	 I2C_Write_Byte(I2C_I2Cx,I2C_Reg_Adress);
	 I2C_Write_Byte(I2C_I2Cx,DATA);
	 I2C_Stop(I2C_I2Cx);
	 I2C_Delay(10);
 }
 
/*
 *  @brief      I2C读取从机寄存器一个字节
 *  @param      I2C_I2Cn  I2C模块号
 *  @param      I2C_Slave_Adress  I2C波特率(KHz)
 *  @param      I2C_Reg_Adress    I2C从机寄存器地址
 *  @since      v1.0
 *  Sample usage uint8 I2C_Result = I2C_Read_Reg(I2C_I2C0,I2C_Slave_Adress,I2C_Reg_Adress);
 */
 uint8 I2C_Read_Reg(I2C_I2Cn I2C_I2Cx,uint8 I2C_Slave_Adress,uint8 I2C_Reg_Adress)
 {
	 uint8 I2C_Result=0;
	 
	 ASSERT((I2C_Slave_Adress & 0x80) == 0);
	 
	 I2C_Start(I2C_I2Cx);
	 I2C_Write_Byte(I2C_I2Cx,(I2C_Slave_Adress << 1) | I2C_MWSR);
	 I2C_Write_Byte(I2C_I2Cx,I2C_Reg_Adress);
	 I2C_RepeatedStart(I2C_I2Cx);
	 I2C_Write_Byte(I2C_I2Cx,(I2C_Slave_Adress << 1) | I2C_MRSW);
	 I2C_PutinRxMode(I2C_I2Cx);
	 I2C_Result = I2C_D_REG(I2CN[I2C_I2Cx]);
	 I2C_Wait(I2C_I2Cx);
	 I2C_Result = I2C_D_REG(I2CN[I2C_I2Cx]);
	 I2C_Delay(10);
	 
	 return I2C_Result;
 }
 
 
 
 
 