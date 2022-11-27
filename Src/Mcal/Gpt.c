/***************************************************************************************************
*   FILE DESCRIPTION
*   ------------------------------------------------------------------------------------------------*/
/**      \file Gpt.c
*      \brief
*
*     \details
*
*
****************************************************************************************************/

/****************************************************************************************************
*     INCLUDES
****************************************************************************************************/

#include "std_types.h"
#include "Gpt.h"
#include "Mcu_Hw.h"
/***************************************************************************************************
*   LOCAL MACROS CONSTANT\FUNCTION
***************************************************************************************************/

/*************************************************************************************************
*   LOCAL DATA
***********************************************************************************************/

/**********************************************************************************************
*   GLOBAL DATA
*************************************************************************************************/

/***********************************************************************************************
*   LOCAL FUNNCTION PROTOTYPE
************************************************************************************************/

/***********************************************************************************************
*   LOCAL FUNCTIONS 
*************************************************************************************************/

/************************************************************************************************
*   GLOBAL FUNCTIONS
************************************************************************************************/


/***********************************************************************************************
* \Syntax           : Std_ReturnTypefunctionName(AnyType ParameterName)
* \Description      : Describe this service
*
* \Sync\Async       : Synchorouns
* \Reentrancy       : Non Rentrant
* \Parameters (in)  : ParameterName  ParameterDescription
* \Parameters (out) : None
* \Return Value:    :Std_ReturnType  E_OK
                                     E_NOT_OK
**************************************************************************************************/
GptNotification Call_back[12];

void Gpt_Init(const Gpt_ConfigType* Timers)
{
	#if (PREDEF_TIMER_EN==1)
			#if(PREDEF_TIMER == GPT_PREDEF_TIMER_1US_16BIT) 
						PREDEF_TIMER_1US_16BIT();
			#elif(PREDEF_TIMER == GPT_PREDEF_TIMER_1US_32BIT)
						PREDEF_TIMER_1US_32BIT();
			#elif(PREDEF_TIMER == GPT_PREDEF_TIMER_100US_32BIT)
						PREDEF_TIMER_100US_32BIT();
			#endif 
	#else 
			uint8 i;
			for(i=0;i<NUM_OF_EN_TIMERS;i++)
			{
				switch (Timers[i].ChannelNum){
					case CH0:
						Gpt_Channel0A_Handler(i,Timers);
						break;
					case CH1:
						Gpt_Channel1A_Handler(i,Timers);
						break;
					case CH2:
						Gpt_Channel2A_Handler(i,Timers);
						break;
					case CH3:
						Gpt_Channel3A_Handler(i,Timers);
						break;
					case CH4:
						Gpt_Channel4A_Handler(i,Timers);
						break;
					case CH5:
						Gpt_Channel5A_Handler(i,Timers);
						break;
					case CH6:
						Gpt_Channel6A_Handler(i,Timers);
						break;
					case CH7:
						Gpt_Channel7A_Handler(i,Timers);
						break;
					case CH8:
						Gpt_Channel8A_Handler(i,Timers);
						break;
					case CH9:
						Gpt_Channel9A_Handler(i,Timers);
						break;
					case CH10:
						Gpt_Channel10A_Handler(i,Timers);
						break;
					case CH11:
						Gpt_Channel11A_Handler(i,Timers);
						break;
				}
			}
		#endif
}
void PREDEF_TIMER_1US_16BIT(void)
{
	SET_BIT(RCGCTIMER,0);
	GPTMCTL0A=0x00;  //Disable timer
	GPTMCFG0A=0x00000004; //16 bit
	GPTMTAMR0=0x2; //priodic 
	GPTMTAPR0=16; 
	GPTMICR0A=0x1;
}
void PREDEF_TIMER_1US_32BIT(void)
{
	SET_BIT(RCGCTIMER,0);
	GPTMCTL6A=0x00;    //Disable timer
	GPTMCFG6A=0x00000004; //32 bit
	GPTMTAMR6=0x2; //priodic 
	GPTMTAPR6=16; //Prescale
	GPTMICR6A=0x1;
}
void PREDEF_TIMER_100US_32BIT(void)
{
	SET_BIT(RCGCTIMER,0);
	GPTMCTL6A=0x00;
	GPTMCFG6A=0x00000004; //16 bit
	GPTMTAMR6=0x2; //priodic 
	GPTMTAPR6=1600; //prescale 
	GPTMICR6A=0x1;
}
void Gpt_StartTimer(Gpt_ChannelType Channel,uint32 Value)
{
	switch(Channel)
	{
		case CH0:
			GPTMTAILR0=Value;  //Start value of timer
			GPTMCTL0A=0x01;   //Enable timer
			break;
		case CH1:
			GPTMTAILR1=Value;  //Start value of timer
			GPTMCTL1A=0x01;   //Enable timer
			break;
		case CH2:
			GPTMTAILR2=Value;  //Start value of timer
			GPTMCTL2A=0x01;   //Enable timer
			break;
		case CH3:
			GPTMTAILR3=Value;  //Start value of timer
			GPTMCTL3A=0x01;   //Enable timer
			break;
		case CH4:
			GPTMTAILR4=Value;  //Start value of timer
			GPTMCTL4A=0x01;   //Enable timer
			break;
		case CH5:
			GPTMTAILR5=Value;  //Start value of timer
			GPTMCTL5A=0x01;   //Enable timer
			break;
		case CH6:
			GPTMTAILR6=Value;  //Start value of timer
			GPTMCTL6A=0x01;   //Enable timer
			break;
		case CH7:
			GPTMTAILR7=Value;  //Start value of timer
			GPTMCTL7A=0x01;   //Enable timer
			break;
		case CH8:
			GPTMTAILR8=Value;  //Start value of timer
			GPTMCTL8A=0x01;   //Enable timer
			break;
		case CH9:
			GPTMTAILR9=Value;  //Start value of timer
			GPTMCTL9A=0x01;   //Enable timer
			break;
		case CH10:
			GPTMTAILR10=Value;  //Start value of timer
			GPTMCTL10A=0x01;   //Enable timer
			break;
		case CH11:
			GPTMTAILR11=Value;  //Start value of timer
			GPTMCTL11A=0x01;   //Enable timer
			break;
	}
}
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
	switch(Channel)
	{
		case CH0:
			GPTMCTL0A=0x00;  //Disable timer
			break;
		case CH1:
			GPTMCTL1A=0x00;  //Disable timer
			break;
		case CH2:
			GPTMCTL2A=0x00;  //Disable timer
			break;
		case CH3:
			GPTMCTL3A=0x00;  //Disable timer
			break;
		case CH4:
			GPTMCTL4A=0x00;  //Disable timer
			break;
		case CH5:
			GPTMCTL5A=0x00;  //Disable timer
			break;
		case CH6:
			GPTMCTL6A=0x00;  //Disable timer
			break;
		case CH7:
			GPTMCTL7A=0x00;  //Disable timer
			break;
		case CH8:
			GPTMCTL8A=0x00;  //Disable timer
			break;
		case CH9:
			GPTMCTL9A=0x00;  //Disable timer
			break;
		case CH10:
			GPTMCTL10A=0x00;  //Disable timer
			break;
		case CH11:
			GPTMCTL11A=0x00;  //Disable timer
			break;
	}
}
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
	switch(Channel)
	{
		case CH0:
			GPTMIMR0A=0x01;
		break;
		case CH1:
			GPTMIMR1A=0x01;
		break;
		case CH2:
			GPTMIMR2A=0x01;
		break;
		case CH3:
			GPTMIMR3A=0x01;
		break;
		case CH4:
			GPTMIMR4A=0x01;
		break;
		case CH5:
			GPTMIMR5A=0x01;
		break;
		case CH6:
			GPTMIMR6A=0x01;
		break;
		case CH7:
			GPTMIMR7A=0x01;
		break;
		case CH8:
			GPTMIMR8A=0x01;
		break;
		case CH9:
			GPTMIMR9A=0x01;
		break;
		case CH10:
			GPTMIMR10A=0x01;
		break;
		case CH11:
			GPTMIMR11A=0x01;
		break;
	}
}
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
	switch(Channel)
	{
		case CH0:
			GPTMIMR0A=0x00;
		break;
		case CH1:
			GPTMIMR1A=0x00;
		break;
		case CH2:
			GPTMIMR2A=0x00;
		break;
		case CH3:
			GPTMIMR3A=0x00;
		break;
		case CH4:
			GPTMIMR4A=0x00;
		break;
		case CH5:
			GPTMIMR5A=0x00;
		break;
		case CH6:
			GPTMIMR6A=0x00;
		break;
		case CH7:
			GPTMIMR7A=0x00;
		break;
		case CH8:
			GPTMIMR8A=0x00;
		break;
		case CH9:
			GPTMIMR9A=0x00;
		break;
		case CH10:
			GPTMIMR10A=0x00;
		break;
		case CH11:
			GPTMIMR11A=0x00;
		break;
	}
}
uint32 Gpt_GetTimeElabsed(Gpt_ChannelType Channel)
{
	uint32 Value;
	switch(Channel)
	{
		case CH0:
			Value=GPTMTAR0*GPTMTAPR0;
			break;
		case CH1:
			Value=GPTMTAR1*GPTMTAPR1;
			break;
		case CH2:
			Value=GPTMTAR2*GPTMTAPR2;
			break;
		case CH3:
			Value=GPTMTAR3*GPTMTAPR3;
			break;
		case CH4:
			Value=GPTMTAR4*GPTMTAPR4;
			break;
		case CH5:
			Value=GPTMTAR5*GPTMTAPR5;
			break;
		case CH6:
			Value=GPTMTAR6*GPTMTAPR6;
			break;
		case CH7:
			Value=GPTMTAR7*GPTMTAPR7;
			break;
		case CH8:
			Value=GPTMTAR8*GPTMTAPR8;
			break;
		case CH9:
			Value=GPTMTAR9*GPTMTAPR9;
			break;
		case CH10:
			Value=GPTMTAR10*GPTMTAPR10;
			break;
		case CH11:
			Value=GPTMTAR11*GPTMTAPR11;
			break;
	}
	return Value;
}
uint32 Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
	uint32 Value;
	switch(Channel)
	{
		case CH0:
			Value=(GPTMTAILR0-GPTMTAR0)*GPTMTAPR0;
			break;
		case CH1:
			Value=(GPTMTAILR1-GPTMTAR1)*GPTMTAPR1;
			break;
		case CH2:
			Value=(GPTMTAILR2-GPTMTAR2)*GPTMTAPR2;
			break;
		case CH3:
			Value=(GPTMTAILR3-GPTMTAR3)*GPTMTAPR3;
			break;
		case CH4:
			Value=(GPTMTAILR4-GPTMTAR4)*GPTMTAPR4;
			break;
		case CH5:
			Value=(GPTMTAILR5-GPTMTAR5)*GPTMTAPR5;
			break;
		case CH6:
			Value=(GPTMTAILR6-GPTMTAR6)*GPTMTAPR6;
			break;
		case CH7:
			Value=(GPTMTAILR7-GPTMTAR7)*GPTMTAPR7;
			break;
		case CH8:
			Value=(GPTMTAILR8-GPTMTAR8)*GPTMTAPR8;
			break;
		case CH9:
			Value=(GPTMTAILR9-GPTMTAR9)*GPTMTAPR9;
			break;
		case CH10:
			Value=(GPTMTAILR10-GPTMTAR10)*GPTMTAPR10;
			break;
		case CH11:
			Value=(GPTMTAILR11-GPTMTAR11)*GPTMTAPR11;
			break;
	}
	return Value;
}
Std_ReturnType Gpt_GetPredefTimeValue(Gpt_PredefTimerType PredefTimer,uint32* TimeValue)
{
	Std_ReturnType Value;
	#if(PREDEF_TIMER_EN==0)
		Value= E_NOT_OK;
	#else
		switch(PredefTimer)
		{
			case GPT_PREDEF_TIMER_1US_16BIT:
				*TimeValue=GPTMTAR0*GPTMTAPR0;
				Value=E_OK;
				break;
			case GPT_PREDEF_TIMER_1US_32BIT:
				*TimeValue=GPTMTAR6*GPTMTAPR6;
				Value=E_OK;
				break;
			case GPT_PREDEF_TIMER_100US_32BIT:
				*TimeValue=GPTMTAR6*GPTMTAPR6;
				Value=E_OK;
				break;
		}
	#endif
	return Value;
}
void Gpt_Channel0A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint8 Prescale;
	SET_BIT(RCGCTIMER,0); //Enable clk
	GPTMCTL0A=0x00;  //Disable timer
	GPTMCFG0A=0x00000000; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR0=0x01;
	else
		GPTMTAMR0=0x02;
	SET_BIT(GPTMICR0A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR0=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[0]=Timer[Num].CallBack;
}
void Gpt_Channel1A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint8 Prescale;
	SET_BIT(RCGCTIMER,0); //Enable clk
	GPTMCTL1A=0x00;  //Disable timer
	GPTMCFG1A=0x00000004; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR1=0x01;
	else
		GPTMTAMR1=0x02;
	SET_BIT(GPTMICR1A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR1=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[1]=Timer[Num].CallBack;
}
void Gpt_Channel2A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint8 Prescale;
	SET_BIT(RCGCTIMER,0); //Enable clk
	GPTMCTL2A=0x00;  //Disable timer
	GPTMCFG2A=0x00000004; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR2=0x01;
	else
		GPTMTAMR2=0x02;
	SET_BIT(GPTMICR2A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR2=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[2]=Timer[Num].CallBack;
}

void Gpt_Channel3A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint8 Prescale;
	SET_BIT(RCGCTIMER,0); //Enable clk
	GPTMCTL3A=0x00;  //Disable timer
	GPTMCFG3A=0x00000004; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR3=0x01;
	else
		GPTMTAMR3=0x02;
	SET_BIT(GPTMICR3A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR3=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[3]=Timer[Num].CallBack;
}

void Gpt_Channel4A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint8 Prescale;
	SET_BIT(RCGCTIMER,0); //Enable clk
	GPTMCTL4A=0x00;  //Disable timer
	GPTMCFG4A=0x00000004; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR4=0x01;
	else
		GPTMTAMR4=0x02;
	SET_BIT(GPTMICR4A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR4=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[4]=Timer[Num].CallBack;
}

void Gpt_Channel5A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint8 Prescale;
	SET_BIT(RCGCTIMER,0); //Enable clk
	GPTMCTL5A=0x00;  //Disable timer
	GPTMCFG5A=0x00000004; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR5=0x01;
	else
		GPTMTAMR5=0x02;
	SET_BIT(GPTMICR5A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR5=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[5]=Timer[Num].CallBack;
}

void Gpt_Channel6A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint16 Prescale;
	SET_BIT(RCGCWTIMER,0); //Enable clk
	GPTMCTL6A=0x00;  //Disable timer
	GPTMCFG6A=0x00000004; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR6=0x01;
	else
		GPTMTAMR6=0x02;
	SET_BIT(GPTMICR6A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR6=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[6]=Timer[Num].CallBack;
}

void Gpt_Channel7A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint16 Prescale;
	SET_BIT(RCGCWTIMER,0); //Enable clk
	GPTMCTL7A=0x00;  //Disable timer
	GPTMCFG7A=0x00000004; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR7=0x01;
	else
		GPTMTAMR7=0x02;
	SET_BIT(GPTMICR7A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR7=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[7]=Timer[Num].CallBack;
}

void Gpt_Channel8A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint16 Prescale;
	SET_BIT(RCGCWTIMER,0); //Enable clk
	GPTMCTL8A=0x00;  //Disable timer
	GPTMCFG8A=0x00000004; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR8=0x01;
	else
		GPTMTAMR8=0x02;
	SET_BIT(GPTMICR8A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR8=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[8]=Timer[Num].CallBack;
}

void Gpt_Channel9A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint16 Prescale;
	SET_BIT(RCGCWTIMER,0); //Enable clk
	GPTMCTL9A=0x00;  //Disable timer
	GPTMCFG9A=0x00000004; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR9=0x01;
	else
		GPTMTAMR9=0x02;
	SET_BIT(GPTMICR9A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR9=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[9]=Timer[Num].CallBack;
}

void Gpt_Channel10A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint16 Prescale;
	SET_BIT(RCGCWTIMER,0); //Enable clk
	GPTMCTL10A=0x00;  //Disable timer
	GPTMCFG10A=0x00000004; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR10=0x01;
	else
		GPTMTAMR10=0x02;
	SET_BIT(GPTMICR10A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR10=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[10]=Timer[Num].CallBack;
}

void Gpt_Channel11A_Handler(uint8 Num,const Gpt_ConfigType* Timer)
{
	uint16 Prescale;
	SET_BIT(RCGCWTIMER,0); //Enable clk
	GPTMCTL11A=0x00;  //Disable timer
	GPTMCFG11A=0x00000004; //16 bit
	if(Timer[Num].GptChannelMode==GPT_MODE_ONESHOT)
		GPTMTAMR11=0x01;
	else
		GPTMTAMR11=0x02;
	SET_BIT(GPTMICR11A,0);
	Prescale=(16/Timer[Num].GptChannelTickFreq);
	GPTMTAPR8=Prescale;
	if(Timer[Num].CallBack!=NULL)
		Call_back[11]=Timer[Num].CallBack;
}
void TIMER0A_Handler(void)
{
	Call_back[0]();
	GPTMICR0A=0x1;
}
void TIMER1A(void)
{
	Call_back[1]();
	GPTMICR1A=0x1;
}

void TIMER2A(void)
{
	Call_back[2]();
	GPTMICR2A=0x1;
}

void TIMER3A(void)
{
	Call_back[3]();
	GPTMICR3A=0x1;
}

void TIMER4A(void)
{
	Call_back[4]();
	GPTMICR4A=0x1;
}

void TIMER5A(void)
{
	Call_back[5]();
	GPTMICR5A=0x1;
}

void TIMER6A(void)
{
	Call_back[6]();
	GPTMICR6A=0x1;
}

void TIMER7A(void)
{
	Call_back[7]();
	GPTMICR7A=0x1;
}

void TIMER8A(void)
{
	Call_back[8]();
	GPTMICR8A=0x1;
}

void TIMER9A(void)
{
	Call_back[9]();
	GPTMICR9A=0x1;
}

void TIMER10A(void)
{
	Call_back[10]();
	GPTMICR10A=0x1;
}

void TIMER11A(void)
{
	Call_back[11]();
	GPTMICR11A=0x1;
}


/************************************************************************************************
*  END OF FILE  :    Gpt.C
*************************************************************************************************/
