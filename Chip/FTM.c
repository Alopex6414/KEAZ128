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
**FTM��ַָ������
*/
FTM_MemMapPtr FTMN[FTM_FTM_MAX]=
{
	FTM0_BASE_PTR,//FTM0��ַ
	FTM1_BASE_PTR,//FTM1��ַ
	FTM2_BASE_PTR //FTM2��ַ
};

/*
 *  @brief      FTM �˿ڳ�ʼ��
 *  @param      FTM_FTM_n    ģ��(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_CHn      ͨ��(CH0~CH5)
 *  @since      v1.0
 *  Sample usage:		FTM_Port_Mux(FTM_FTM0,FTM_CH0);
 */
static void FTM_Port_Mux(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx)
{
	switch(FTM_FTMx)//FTMģ��ѡ��
	{
		case FTM_FTM0:  //FTM0ģ��
										SIM_SCGC |= SIM_SCGC_FTM0_MASK;//Enable FTM0(��FTM0ʱ��)
										switch(FTM_CHx)//ѡ��FTMͨ��
										{
											case FTM_CH0: //FTMͨ��0
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
										  case FTM_CH1: //FTMͨ��1
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
	  case FTM_FTM1:  //FTM1ģ��
										SIM_SCGC |= SIM_SCGC_FTM1_MASK;//Enable FTM1(��FTM1ʱ��)
										switch(FTM_CHx)//ѡ��FTMͨ��
										{
											case FTM_CH0: //FTMͨ��0
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
										  case FTM_CH1: //FTMͨ��1
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
		case FTM_FTM2:  //FTM2ģ��
										SIM_SCGC |= SIM_SCGC_FTM2_MASK;//Enable FTM2(��FTM2ʱ��)
										switch(FTM_CHx)//ѡ��FTMͨ��
										{
											case FTM_CH0: //FTMͨ��0
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
										  case FTM_CH1: //FTMͨ��1
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
										  case FTM_CH2: //FTMͨ��2
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
										  case FTM_CH3: //FTMͨ��3
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
											case FTM_CH4: //FTMͨ��4
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
											case FTM_CH5: //FTMͨ��5
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
 *  @brief      FTM PWM      ��ʼ��
 *  @param      FTM_FTM_n    ģ��(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_CHn      ͨ��(CH0~CH5)
 *  @param      FTM_Freq     FTMƵ��(Hz)
 *  @param      FTM_Duty     FTMռ�ձ�(�ߵ�ƽ����,ռ�ձȷ���),ռ�ձ�P = (FTM_Duty / FTMn_PRECISON) * 100%
 *  @since      v1.0
 *  @note 			��ͬFTMģ��Ƶ����ͬ,ռ�ձȿ��Բ�ͬ
 *  Sample usage:		FTM_PWM_Init(FTM_FTM0,FTM_CH0,15000,1000);
 */
void FTM_PWM_Init(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx,uint32 FTM_Freq,uint32 FTM_Duty)
{
	uint32 FTM_Clk_Hz;
	uint16 FTM_Mod;
	uint16 FTM_Cv;
	uint8  FTM_Ps;
	
	//FTMͨ��ģ�����,FTM0��FTM1ֻ��CH0��CH1,FTM2��CH0-CH5
	ASSERT(((FTM_FTMx == FTM_FTM0 || FTM_FTMx == FTM_FTM1) && (FTM_CHx <= FTM_CH1)) || ((FTM_FTMx == FTM_FTM2) && (FTM_CHx <= FTM_CH5)));
	
	FTM_Port_Mux(FTM_FTMx,FTM_CHx);//��ʼ��FTM�˿�
	
	FTM_Clk_Hz = KEA_Tim_CLK_KHz * 1000;//Ƶ�ʼ���
	FTM_Mod = (FTM_Clk_Hz >> 16) / FTM_Freq;
	
	FTM_Ps = 0;
	while((FTM_Mod >> FTM_Ps) >= 1)
	{
		FTM_Ps++;
	}
	
	ASSERT(FTM_Ps <= 0x07);//���Է�Ƶ����FTM_Ps<=7
	
	FTM_Mod = (FTM_Clk_Hz >> FTM_Ps) / FTM_Freq;
	
	switch(FTM_FTMx)//ѡ��FTMģ��
	{
		case FTM_FTM0:
										FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM0_PRECISON;//FTM0����ռ�ձȼ���
										break;
		case FTM_FTM1:
										FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM1_PRECISON;//FTM1����ռ�ձȼ���
										break;
		case FTM_FTM2:
										FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM2_PRECISON;//FTM2����ռ�ձȼ���
										break;
		default:
										break;
	}
	
	//FTM����״̬��ģʽѡ��
	FTM_CnSC_REG(FTMN[FTM_FTMx],FTM_CHx) &= ~FTM_CnSC_ELSA_MASK;
	FTM_CnSC_REG(FTMN[FTM_FTMx],FTM_CHx) |= FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	
	//ʱ�ӷ�Ƶ����
	FTM_SC_REG(FTMN[FTM_FTMx]) = (0 | FTM_SC_CLKS(1) | FTM_SC_PS(FTM_Ps));
	FTM_MOD_REG(FTMN[FTM_FTMx]) = FTM_Mod;
	
	//FTM2��FTM_CNTIN�Ĵ���
	if(FTM_FTMx ==FTM_FTM2)
	{
			FTM_CNTIN_REG(FTMN[FTM_FTMx]) = 0;
	}
	FTM_CnV_REG(FTMN[FTM_FTMx],FTM_CHx) = FTM_Cv;
	FTM_CNT_REG(FTMN[FTM_FTMx]) = 0;
	
}

/*
 *  @brief      FTM PWM      ռ�ձ�����
 *  @param      FTM_FTM_n    ģ��(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_CHn      ͨ��(CH0~CH5)
 *  @param      FTM_Duty     FTMռ�ձ�(�ߵ�ƽ����,ռ�ձȷ���),ռ�ձ�P = (FTM_Duty / FTMn_PRECISON) * 100%
 *  @since      v1.0
 *  @note 			��ͬFTMģ��Ƶ����ͬ,ռ�ձȿ��Բ�ͬ
 *  Sample usage:		FTM_PWM_Duty(FTM_FTM0,FTM_CH0,1000);
 */
void FTM_PWM_Duty(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx,uint32 FTM_Duty)
{
	uint16 FTM_Mod;
	uint16 FTM_Cv;
	
	//FTMͨ��ģ�����,FTM0��FTM1ֻ��CH0��CH1,FTM2��CH0-CH5
	ASSERT(((FTM_FTMx == FTM_FTM0 || FTM_FTMx == FTM_FTM1) && (FTM_CHx <= FTM_CH1)) || ((FTM_FTMx == FTM_FTM2) && (FTM_CHx <= FTM_CH5)));
	
	switch(FTM_FTMx)//ѡ��FTMģ��
	{
		case FTM_FTM0:
									ASSERT(FTM_Duty <= FTM0_PRECISON);//����FTM0ռ�ձȷ��Ͼ���
									break;
		case FTM_FTM1:
									ASSERT(FTM_Duty <= FTM1_PRECISON);//����FTM1ռ�ձȷ��Ͼ���
									break;
		case FTM_FTM2:
									ASSERT(FTM_Duty <= FTM2_PRECISON);//����FTM2ռ�ձȷ��Ͼ���
									break;
		default:
									break;
	}
	
	do
	{
		FTM_Mod = FTM_MOD_REG(FTMN[FTM_FTMx]);
	}
	while(FTM_Mod == 0);
	
	switch(FTM_FTMx)//ѡ��FTMģ��
	{
		case FTM_FTM0:
									FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM0_PRECISON;//FTM0����ռ�ձȼ���
									break;
		case FTM_FTM1:
									FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM1_PRECISON;//FTM1����ռ�ձȼ���
									break;
		case FTM_FTM2:
									FTM_Cv = (FTM_Duty * (FTM_Mod + 1)) / FTM2_PRECISON;//FTM2����ռ�ձȼ���
									break;
		default:
									break;
	}
	
	FTM_CnV_REG(FTMN[FTM_FTMx],FTM_CHx) = FTM_Cv;
	
}

/*
 *  @brief      FTM PWM		   Ƶ������
 *  @param      FTM_FTM_n    ģ��(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_Freq     FTMƵ��(Hz)
 *  @since      v1.0
 *  @note 			��ͬFTMģ��Ƶ����ͬ,ռ�ձȿ��Բ�ͬ
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
	
	//ʱ�ӷ�Ƶ����
	FTM_SC_REG(FTMN[FTM_FTMx]) = (0 | FTM_SC_CLKS(1) | FTM_SC_PS(FTM_Ps));
	FTM_MOD_REG(FTMN[FTM_FTMx]) = FTM_Mod;
	
	if(FTM_FTMx ==FTM_FTM2)
	{
			FTM_CNTIN_REG(FTMN[FTM_FTMx]) = 0;
	}
	FTM_CNT_REG(FTMN[FTM_FTMx]) = 0;
	
}

/*
 *  @brief      FTM Input		 				���벶׽
 *  @param      FTM_FTM_n    				ģ��(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_CHn      				ͨ��(CH0~CH5)
 *  @param      FTM_Input_Mode     	FTM���벶׽ģʽ
 *  @param      FTM_PS_n      			FTM��Ƶ����
 *  @since      v1.0
 *  @note 		  �������벶׽��FTMģ�鲻����ΪPWM���
 *  Sample usage:		FTM_Input_Init(FTM_FTM0,FTM_CH0,FTM_Rise,FTM_PS_1);
 */
void FTM_Input_Init(FTM_FTMn FTM_FTMx,FTM_CHn FTM_CHx,FTM_Input_Mode FTM_Input_Mode_x,FTM_PS_n FTM_PS_x)
{
	ASSERT(((FTM_FTMx == FTM_FTM0 || FTM_FTMx == FTM_FTM1) && (FTM_CHx <= FTM_CH1)) || ((FTM_FTMx == FTM_FTM2) && (FTM_CHx <= FTM_CH5)));
	
	FTM_Port_Mux(FTM_FTMx,FTM_CHx);//��ʼ��FTM�˿�
	
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
	
	//ʱ�ӷ�Ƶ����
	FTM_SC_REG(FTMN[FTM_FTMx]) = (0 | FTM_SC_CLKS(1) | FTM_SC_PS(FTM_PS_x));
	FTM_CnV_REG(FTMN[FTM_FTMx],FTM_CHx) &= ~FTM_CnV_VAL_MASK;
	FTM_MOD_REG(FTMN[FTM_FTMx]) |= FTM_MODE_WPDIS_MASK;
	FTM_MOD_REG(FTMN[FTM_FTMx]) &= ~FTM_MODE_FTMEN_MASK;
	
	FTM_CNT_REG(FTMN[FTM_FTMx]) &= ~FTM_CNT_COUNT_MASK;
	
}

/*
 *  @brief      FTM Input Count Get	���벶׽���������ȡ
 *  @param      FTM_FTM_n    				ģ��(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @param      FTM_CHn      				ͨ��(CH0~CH5)
 *  @since      v1.0
 *  @note 		  �������벶׽��FTMģ�鲻����ΪPWM���
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
 *  @brief      FTM Input Clean	    ���벶׽��������
 *  @param      FTM_FTM_n    				ģ��(FTM_FTM0  FTM_FTM1  FTM_FTM2)
 *  @since      v1.0
 *  @note 		  �������벶׽��FTMģ�鲻����ΪPWM���
 *  Sample usage:		FTM_Input_Clean(FTM_FTM0);
 */
void FTM_Input_Clean(FTM_FTMn FTM_FTMx)
{
	ASSERT(FTM_FTMx < FTM_FTM_MAX);
	
	FTM_CNT_REG(FTMN[FTM_FTMx]) &= ~FTM_CNT_COUNT_MASK;
}










