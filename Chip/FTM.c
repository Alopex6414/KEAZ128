/*
 *     COPYRIGHT NOTICE
 *     Copyright(c) 2016, Alopex
 *     All rights reserved.
 *
 * @file       FTM.c
 * @brief      KEAZ128
 * @author     Alopex
 * @version    v1.0
 * @date       2016-09-12
 */	

#include "Common.h" /* include peripheral declarations */
#include "Include.h"

/*
**FTM基址指针数组
*/
FTM_MemMapPtr FTMN[FTM_FTM_MAX]=
{
	FTM0_BASE_PTR,//FTM0基址
	FTM1_BASE_PTR,//FTM1基址
	FTM2_BASE_PTR //FTM2基址
};

/*
 *  @brief      FTM 端口初始化
 *  @param      FTM_FTM_n    模块(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_CHn      通道(CH0~CH5)
 *  @since      v1.0
 *  Sample usage:		FTM_Port_Mux(FTM_FTM0,FTM_CH0);
 */
static void FTM_Port_Mux(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx)
{
	switch(FTM_FTMx)//FTM模块选择
	{
		case FTM_FTM0:  //FTM0模块
										SIM_SCGC |= SIM_SCGC_FTM0_MASK;//Enable FTM0(打开FTM0时钟)
										switch(FTM_CHx)//选择FTM通道
										{
											case FTM_CH0: //FTM通道0
																		if(FTM0_CH0_PIN == PTA0)//PTA0
																		{
																			SIM_PINSEL0 &= ~SIM_PINSEL_FTM0PS0_MASK;
																		}
																		else if(FTM0_CH0_PIN == PTB2)//PTB2
																		{
																			SIM_PINSEL0 |= SIM_PINSEL_FTM0PS0_MASK;
																		}
																		else//default
																		{
																			ASSERT(0);
																		}
																		break;
										  case FTM_CH1: //FTM通道1
																		if(FTM0_CH1_PIN == PTA1)//PTA1
																		{
																			SIM_PINSEL0 &= ~SIM_PINSEL_FTM0PS1_MASK;
																		}
																		else if(FTM0_CH1_PIN == PTB3)//PTB3
																		{
																			SIM_PINSEL0 |= SIM_PINSEL_FTM0PS1_MASK;
																		}
																		else//default
																		{
																			ASSERT(0);
																		}
																		break;
											default:
																		break;
										}
										break;
	  case FTM_FTM1:  //FTM1模块
										SIM_SCGC |= SIM_SCGC_FTM1_MASK;//Enable FTM1(打开FTM1时钟)
										switch(FTM_CHx)//选择FTM通道
										{
											case FTM_CH0: //FTM通道0
																		if(FTM1_CH0_PIN == PTC4)//PTC4
																		{
																			SIM_PINSEL0 &= ~SIM_PINSEL_FTM1PS0_MASK;
																		}
																		else if(FTM1_CH0_PIN == PTH2)//PTH2
																		{
																			SIM_PINSEL0 |= SIM_PINSEL_FTM1PS0_MASK;
																		}
																		else//default
																		{
																			ASSERT(0);
																		}
																		break;
										  case FTM_CH1: //FTM通道1
																		if(FTM1_CH1_PIN == PTC5)//PTC5
																		{
																			SIM_PINSEL0 &= ~SIM_PINSEL_FTM1PS1_MASK;
																		}
																		else if(FTM1_CH1_PIN == PTE7)//PTE7
																		{
																			SIM_PINSEL0 |= SIM_PINSEL_FTM1PS1_MASK;
																		}
																		else//default
																		{
																			ASSERT(0);
																		}
																		break;
											default:
																		break;
										}
										break;
		case FTM_FTM2:  //FTM2模块
										SIM_SCGC |= SIM_SCGC_FTM2_MASK;//Enable FTM2(打开FTM2时钟)
										switch(FTM_CHx)//选择FTM通道
										{
											case FTM_CH0: //FTM通道0
																		if(FTM2_CH0_PIN == PTC0)//PTC0
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS0(0);
																		}
																		else if(FTM2_CH0_PIN == PTH0)//PTH0
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS0(1);
																		}
																		else if(FTM2_CH0_PIN == PTF0)//PTF0
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS0(2);
																		}
																		else//default
																		{
																			ASSERT(0);
																		}
																		break;
										  case FTM_CH1: //FTM通道1
																		if(FTM2_CH1_PIN == PTC1)//PTC1
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS1(0);
																		}
																		else if(FTM2_CH1_PIN == PTH1)//PTH1
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS1(1);
																		}
																		else if(FTM2_CH1_PIN == PTF1)//PTF1
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS1(2);
																		}
																		else//default
																		{
																			ASSERT(0);
																		}
																		break;
										  case FTM_CH2: //FTM通道2
																		if(FTM2_CH2_PIN == PTC2)//PTC2
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS2(0);
																		}
																		else if(FTM2_CH2_PIN == PTD0)//PTD0
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS2(1);
																		}
																		else if(FTM2_CH2_PIN == PTG4)//PTG4
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS2(2);
																		}
																		else//default
																		{
																			ASSERT(0);
																		}
																		break;
										  case FTM_CH3: //FTM通道3
																		if(FTM2_CH3_PIN == PTC3)//PTC3
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS3(0);
																		}
																		else if(FTM2_CH3_PIN == PTD1)//PTD1
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS3(1);
																		}
																		else if(FTM2_CH3_PIN == PTG5)//PTG5
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS3(2);
																		}
																		else//default
																		{
																			ASSERT(0);
																		}
																		break;
											case FTM_CH4: //FTM通道4
																		if(FTM2_CH4_PIN == PTB4)//PTB4
																		{
																			SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS4_MASK;
																		}
																		else if(FTM2_CH4_PIN == PTG6)//PTG6
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS4_MASK;
																		}
																		else//default
																		{
																			ASSERT(0);
																		}
																		break;
											case FTM_CH5: //FTM通道5
																		if(FTM2_CH5_PIN == PTB5)//PTB5
																		{
																			SIM_PINSEL1 &= ~SIM_PINSEL1_FTM2PS5_MASK;
																		}
																		else if(FTM2_CH5_PIN == PTG7)//PTG7
																		{
																			SIM_PINSEL1 |= SIM_PINSEL1_FTM2PS5_MASK;
																		}
																		else//default
																		{
																			ASSERT(0);
																		}
																		break;
											default:
																		break;
										}
										break;
		default:
										break;
	}
}

/*
 *  @brief      FTM PWM      初始化
 *  @param      FTM_FTM_n    模块(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_CHn      通道(CH0~CH5)
 *  @param      FTM_Freq     FTM频率(Hz)
 *  @param      FTM_Duty     FTM占空比(高电平脉宽,占空比分子),占空比P = (FTM_Duty / FTMn_PRECISON) * 100%
 *  @since      v1.0
 *  @note 			相同FTM模块频率相同,占空比可以不同
 *  Sample usage:		FTM_PWM_Init(FTM_FTM0,FTM_CH0,15000,1000);
 */
void FTM_PWM_Init(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx,uint32 FTM_Freq,uint32 FTM_Duty)
{
	uint32 FTM_Clk_Hz;
	uint16 FTM_Mod;
	uint16 FTM_Cv;
	uint8  FTM_Ps;
	
	//FTM通道模块断言,FTM0和FTM1只有CH0和CH1,FTM2有CH0-CH5
	ASSERT(((FTM_FTMx == FTM_FTM0 || FTM_FTMx == FTM_FTM1) && (FTM_CHx <= FTM_CH1)) || ((FTM_FTMx == FTM_FTM2) && (FTM_CHx <= FTM_CH5)));
	
	FTM_Port_Mux(FTM_FTMx,FTM_CHx);//初始化FTM端口
	
	FTM_Clk_Hz = KEA_Tim_CLK_KHz * 1000;//频率计算
	FTM_Mod = (FTM_Clk_Hz >> 16) / FTM_Freq;
	
	FTM_Ps = 0;
	while((FTM_Mod >> FTM_Ps) >= 1)
	{
		FTM_Ps++;
	}
	
	ASSERT(FTM_Ps <= 0x07);//断言分频因子FTM_Ps<=7
	
	FTM_Mod = (FTM_Clk_Hz >> FTM_Ps) / FTM_Freq;
	
	switch(FTM_FTMx)//选择FTM模块
	{
		case FTM_FTM0:
										FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM0_PRECISON;//FTM0精度占空比计算
										break;
		case FTM_FTM1:
										FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM1_PRECISON;//FTM1精度占空比计算
										break;
		case FTM_FTM2:
										FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM2_PRECISON;//FTM2精度占空比计算
										break;
		default:
										break;
	}
	
	//FTM控制状态和模式选择
	FTM_CnSC_REG(FTMN[FTM_FTMx],FTM_CHx) &= ~FTM_CnSC_ELSA_MASK;
	FTM_CnSC_REG(FTMN[FTM_FTMx],FTM_CHx) |= FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	
	//时钟分频设置
	FTM_SC_REG(FTMN[FTM_FTMx]) = (0 | FTM_SC_CLKS(1) | FTM_SC_PS(FTM_Ps));
	FTM_MOD_REG(FTMN[FTM_FTMx]) = FTM_Mod;
	
	//FTM2有FTM_CNTIN寄存器
	if(FTM_FTMx ==FTM_FTM2)
	{
			FTM_CNTIN_REG(FTMN[FTM_FTMx]) = 0;
	}
	FTM_CnV_REG(FTMN[FTM_FTMx],FTM_CHx) = FTM_Cv;
	FTM_CNT_REG(FTMN[FTM_FTMx]) = 0;
	
}

/*
 *  @brief      FTM PWM      占空比设置
 *  @param      FTM_FTM_n    模块(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_CHn      通道(CH0~CH5)
 *  @param      FTM_Duty     FTM占空比(高电平脉宽,占空比分子),占空比P = (FTM_Duty / FTMn_PRECISON) * 100%
 *  @since      v1.0
 *  @note 			相同FTM模块频率相同,占空比可以不同
 *  Sample usage:		FTM_PWM_Duty(FTM_FTM0,FTM_CH0,1000);
 */
void FTM_PWM_Duty(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx,uint32 FTM_Duty)
{
	uint16 FTM_Mod;
	uint16 FTM_Cv;
	
	//FTM通道模块断言,FTM0和FTM1只有CH0和CH1,FTM2有CH0-CH5
	ASSERT(((FTM_FTMx == FTM_FTM0 || FTM_FTMx == FTM_FTM1) && (FTM_CHx <= FTM_CH1)) || ((FTM_FTMx == FTM_FTM2) && (FTM_CHx <= FTM_CH5)));
	
	switch(FTM_FTMx)//选择FTM模块
	{
		case FTM_FTM0:
									ASSERT(FTM_Duty <= FTM0_PRECISON);//断言FTM0占空比符合精度
									break;
		case FTM_FTM1:
									ASSERT(FTM_Duty <= FTM1_PRECISON);//断言FTM1占空比符合精度
									break;
		case FTM_FTM2:
									ASSERT(FTM_Duty <= FTM2_PRECISON);//断言FTM2占空比符合精度
									break;
		default:
									break;
	}
	
	do
	{
		FTM_Mod = FTM_MOD_REG(FTMN[FTM_FTMx]);
	}
	while(FTM_Mod == 0);
	
	switch(FTM_FTMx)//选择FTM模块
	{
		case FTM_FTM0:
									FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM0_PRECISON;//FTM0精度占空比计算
									break;
		case FTM_FTM1:
									FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM1_PRECISON;//FTM1精度占空比计算
									break;
		case FTM_FTM2:
									FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM2_PRECISON;//FTM2精度占空比计算
									break;
		default:
									break;
	}
	
	FTM_CnV_REG(FTMN[FTM_FTMx],FTM_CHx) = FTM_Cv;
	
}

/*
 *  @brief      FTM PWM		   频率设置
 *  @param      FTM_FTM_n    模块(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_Freq     FTM频率(Hz)
 *  @since      v1.0
 *  @note 			相同FTM模块频率相同,占空比可以不同
 *  Sample usage:		FTM_PWM_Freq(FTM_FTM0,15000);
 */
void FTM_PWM_Freq(FTM_FTMn FTM_FTMx,uint32 FTM_Freq)
{
	uint32 FTM_Clk_Hz;
	uint16 FTM_Mod;
	uint8  FTM_Ps;
	
	FTM_Clk_Hz = KEA_Tim_CLK_KHz * 1000;
	FTM_Mod = (FTM_Clk_Hz >> 16) / FTM_Freq;
	
	FTM_Ps = 0;
	while((FTM_Mod >> FTM_Ps) >= 1)
	{
		FTM_Ps++;
	}
	
	ASSERT(FTM_Ps <= 0x07);
	
	FTM_Mod = (FTM_Clk_Hz >> FTM_Ps) / FTM_Freq;
	
	//时钟分频设置
	FTM_SC_REG(FTMN[FTM_FTMx]) = (0 | FTM_SC_CLKS(1) | FTM_SC_PS(FTM_Ps));
	FTM_MOD_REG(FTMN[FTM_FTMx]) = FTM_Mod;
	
	if(FTM_FTMx ==FTM_FTM2)
	{
			FTM_CNTIN_REG(FTMN[FTM_FTMx]) = 0;
	}
	FTM_CNT_REG(FTMN[FTM_FTMx]) = 0;
	
}

/*
 *  @brief      FTM Input		 				输入捕捉
 *  @param      FTM_FTM_n    				模块(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_CHn      				通道(CH0~CH5)
 *  @param      FTM_Input_Mode     	FTM输入捕捉模式
 *  @param      FTM_PS_n      			FTM分频因子
 *  @since      v1.0
 *  @note 		  用于输入捕捉的FTM模块不能作为PWM输出
 *  Sample usage:		FTM_Input_Init(FTM_FTM0,FTM_CH0,FTM_Rise,FTM_PS_1);
 */
void FTM_Input_Init(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx,FTM_Input_Mode FTM_Input_Mode_x,FTM_PS_n FTM_PS_x)
{
	ASSERT(((FTM_FTMx == FTM_FTM0 || FTM_FTMx == FTM_FTM1) && (FTM_CHx <= FTM_CH1)) || ((FTM_FTMx == FTM_FTM2) && (FTM_CHx <= FTM_CH5)));
	
	FTM_Port_Mux(FTM_FTMx,FTM_CHx);//初始化FTM端口
	
	switch(FTM_Input_Mode_x)
	{
		case 	FTM_Rise:
														FTM_CnSC_REG(FTMN[FTM_FTMx],FTM_CHx) |= (FTM_CnSC_ELSA_MASK | FTM_CnSC_CHIE_MASK);
														FTM_CnSC_REG(FTMN[FTM_FTMx],FTM_CHx) &= ~(FTM_CnSC_ELSB_MASK  | FTM_CnSC_MSB_MASK | FTM_CnSC_MSA_MASK);
														break;
		case 	FTM_Fall:
														FTM_CnSC_REG(FTMN[FTM_FTMx],FTM_CHx) |= (FTM_CnSC_ELSB_MASK | FTM_CnSC_CHIE_MASK);
														FTM_CnSC_REG(FTMN[FTM_FTMx],FTM_CHx) &= ~(FTM_CnSC_ELSA_MASK  | FTM_CnSC_MSB_MASK | FTM_CnSC_MSA_MASK);
														break;
		case 	FTM_Rise_Or_Fall:
														FTM_CnSC_REG(FTMN[FTM_FTMx],FTM_CHx) |= (FTM_CnSC_ELSA_MASK | FTM_CnSC_ELSB_MASK | FTM_CnSC_CHIE_MASK);
														FTM_CnSC_REG(FTMN[FTM_FTMx],FTM_CHx) &= ~(FTM_CnSC_MSB_MASK | FTM_CnSC_MSA_MASK);
														break;
		default:
														break;
	}
	
	//时钟分频设置
	FTM_SC_REG(FTMN[FTM_FTMx]) = (0 | FTM_SC_CLKS(1) | FTM_SC_PS(FTM_PS_x));
	FTM_CnV_REG(FTMN[FTM_FTMx],FTM_CHx) &= ~FTM_CnV_VAL_MASK;
	FTM_MOD_REG(FTMN[FTM_FTMx]) |= FTM_MODE_WPDIS_MASK;
	FTM_MOD_REG(FTMN[FTM_FTMx]) &= ~FTM_MODE_FTMEN_MASK;
	
	FTM_CNT_REG(FTMN[FTM_FTMx]) &= ~FTM_CNT_COUNT_MASK;
	
}

/*
 *  @brief      FTM Input Count Get	输入捕捉计数脉冲获取
 *  @param      FTM_FTM_n    				模块(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_CHn      				通道(CH0~CH5)
 *  @since      v1.0
 *  @note 		  用于输入捕捉的FTM模块不能作为PWM输出
 *  Sample usage:		FTM_Result = FTM_Input_Count_Get(FTM_FTM0,FTM_CH0);
 */
uint16 FTM_Input_Count_Get(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx)
{
	uint16 FTM_Count=0;
	
	ASSERT(((FTM_FTMx == FTM_FTM0 || FTM_FTMx == FTM_FTM1) && (FTM_CHx <= FTM_CH1)) || ((FTM_FTMx == FTM_FTM2) && (FTM_CHx <= FTM_CH5)));
	
	FTM_Count = (uint16)FTM_CnV_REG(FTMN[FTM_FTMx],FTM_CHx);
	
	return FTM_Count;
}

/*
 *  @brief      FTM Input Clean	    输入捕捉计数清零
 *  @param      FTM_FTM_n    				模块(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @since      v1.0
 *  @note 		  用于输入捕捉的FTM模块不能作为PWM输出
 *  Sample usage:		FTM_Input_Clean(FTM_FTM0);
 */
void FTM_Input_Clean(FTM_FTMn FTM_FTMx)
{
	ASSERT(FTM_FTMx < FTM_FTM_MAX);
	
	FTM_CNT_REG(FTMN[FTM_FTMx]) &= ~FTM_CNT_COUNT_MASK;
}










