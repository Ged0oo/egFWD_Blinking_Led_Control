#include "Std_Types.h"
#include "IntCtrl.h"
#include "Systick.h"
#include "Dio.h"
#include "Gpt.h"
#include "Led.h"
void LED_Blinking(uint16 Timeon, uint16 Timeoff);
void Togg_Pin(void);
volatile uint8 TimeON=10;
volatile uint8 TimeOFF=15;
volatile uint8 Switch1=0;
volatile uint8 Old_Switch1=1;
volatile uint8 Old_Switch2=1;
volatile uint8 Switch2=0;
volatile uint8 flag =0;
volatile uint8 Old_flag =1;
int main(){
		Systick_Init();
		IntCrtl_Init();
		static Gpt_ConfigType Timers[NUM_OF_EN_TIMERS]={{CH0,16,65535,GPT_MODE_CONTINOUS,Togg_Pin}};
		Gpt_Init(Timers);
		Gpt_EnableNotification(CH0);
	while(1){
		Switch1=Dio_ReadChannel(4,F);
		Switch2=Dio_ReadChannel(0,F);
		if(Old_Switch1!=Switch1)
		{
			TimeON++;
			TimeOFF--;
			Old_Switch1=Switch1;
		}
		else if(Old_Switch2!=Switch2)
		{
			TimeON--;
			TimeOFF++;
			Old_Switch2=Switch2;
		}
		LED_Blinking(TimeON,TimeOFF);
	}
}
volatile uint8 Res1,Res2;
void LED_Blinking(uint16 Timeon, uint16 TimeOff){
	Res1=Timeon;
	Res2=TimeOff;
	if (Old_flag!=flag){
		if (flag==0){
			Gpt_StartTimer(CH0,TimeOff);
			Old_flag=0;
		}
		else if(flag==1){
			Gpt_StartTimer(CH0,Timeon);
			Old_flag=1;
		}
	}
}

void Togg_Pin(void){
	Gpt_StopTimer(CH0);
	if (flag==0){
				Leds_ON(F);
				flag=1;
	}
	else{
		  Leds_OFF(F);
			flag=0;
	}
}