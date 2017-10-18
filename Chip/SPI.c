/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       SPI.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-19
 */
 
#include "Common.h" /* include peripheral declarations */
#include "Include.h"

/*
**SPI基址指针
*/
SPI_MemMapPtr SPIN[SPI_SPI_MAX]=
{
	SPI0_BASE_PTR,
	SPI1_BASE_PTR
};

/*
 *  @brief      SPI初始化 设置波特率
 *  @param      SPI_SPIn  SPI模块号
 *  @param      SPI_Baud  SPI波特率(KHz)
 *  @since      v1.0
 *  Sample usage 
 */
 void SPI_Init(SPI_SPIn SPI_SPIx,SPI_CFG SPI_CFG_x,uint32 SPI_Baud)
 { 
	 uint8 SPI_Br = 0;
	 uint8 SPI_Pbr = 0;
	 uint8 SPI_Prescaler[8] = {1,2,3,4,5,6,7,8};
	 uint16 SPI_Scaler[9] = {2,4,8,16,32,64,128,256,512};
	 uint32 SPI_Tmp = 0;
	 uint32 SPI_Fit_Clk = 0;
	 uint32 SPI_Fit_Br = 0;
	 uint32 SPI_Fit_Pbr = 0;
	 uint32 SPI_Min_Diff = ~0;
	 uint32 SPI_Diff = 0;
	 uint32 SPI_Clk = (KEA_Bus_CLK_KHz * 1000) / SPI_Baud;
	 
	 ASSERT((SPI_SPIx <= SPI_SPI1) && (SPI_CFG_x <= SLAVE));
	 
	 switch(SPI_SPIx)
	 {
		 case SPI_SPI0:
										SIM_SCGC |= SIM_SCGC_SPI0_MASK;
										if(SPI0_SCK_PIN == PTB2 && SPI0_MOSI_PIN == PTB3 && SPI0_MISO_PIN == PTB4 && SPI0_PCS_PIN == PTB5)
										{
											SIM_PINSEL0 &= ~SIM_PINSEL_SPI0PS_MASK;
										}
										else if(SPI0_SCK_PIN == PTE0 && SPI0_MOSI_PIN == PTE1 && SPI0_MISO_PIN == PTE2 && SPI0_PCS_PIN == PTE3)
										{
											SIM_PINSEL0 |= SIM_PINSEL_SPI0PS_MASK;
										}
										else
										{
											ASSERT(0);
										}
										break;
		 case SPI_SPI1:
										SIM_SCGC |= SIM_SCGC_SPI1_MASK;
										if(SPI1_SCK_PIN == PTD0 && SPI1_MOSI_PIN == PTD1 && SPI1_MISO_PIN == PTD2 && SPI1_PCS_PIN == PTD3)
										{
											SIM_PINSEL1 &= ~SIM_PINSEL1_SPI1PS_MASK;
										}
										else if(SPI1_SCK_PIN == PTG4 && SPI1_MOSI_PIN == PTG5 && SPI1_MISO_PIN == PTG6 && SPI1_PCS_PIN == PTG7)
										{
											SIM_PINSEL1 |= SIM_PINSEL1_SPI1PS_MASK;
										}
										else
										{
											ASSERT(0);
										}
										break;
		 default:
										break;
	 }
	 
	 if(SPI_CFG_x == MASTER)//主机模式
	 {
		 SPI_C1_REG(SPIN[SPI_SPIx]) = (0 | SPI_C1_SPE_MASK | SPI_C1_MSTR_MASK | SPI_C1_CPHA_MASK);
		 
		 for(SPI_Br=0;SPI_Br<9;SPI_Br++)
		 {
			 for(SPI_Pbr=0;SPI_Pbr<8;SPI_Pbr++)
			 {
				 SPI_Tmp = SPI_Scaler[SPI_Br] * SPI_Prescaler[SPI_Pbr];
				 SPI_Diff = abs(SPI_Tmp - SPI_Clk);
				 if(SPI_Min_Diff > SPI_Diff)
				 {
					 SPI_Min_Diff = SPI_Diff;
					 SPI_Fit_Br = SPI_Br;
					 SPI_Fit_Pbr = SPI_Pbr;
				 }
			 }
		 }
		 
		 SPI_Fit_Clk = (KEA_Bus_CLK_KHz * 1000)/(SPI_Scaler[SPI_Fit_Br] * SPI_Prescaler[SPI_Fit_Pbr]);
		 SPI_BR_REG(SPIN[SPI_SPIx]) = (0 | SPI_BR_SPPR(SPI_Fit_Pbr) | SPI_BR_SPR(SPI_Fit_Br));
	 }
	 else//从机模式
	 {
		 SPI_C1_REG(SPIN[SPI_SPIx]) = (0 | SPI_C1_SPE_MASK | SPI_C1_CPHA_MASK);
	 }
	 
	 
 }







 