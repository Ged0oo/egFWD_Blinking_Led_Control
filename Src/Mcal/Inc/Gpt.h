/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Gpt_Init(const Gpt_ConfigType* Timers);
void Gpt_EnableNotification(Gpt_ChannelType Channel);
void Gpt_DisableNotification(Gpt_ChannelType Channel);
uint32 Gpt_GetTimeElabsed(Gpt_ChannelType Channel);
uint32 Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
void Gpt_StartTimer(Gpt_ChannelType Channel,uint32 Value);
void Gpt_StopTimer(Gpt_ChannelType Channel);
void Gpt_Channel0A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void Gpt_Channel1A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void Gpt_Channel2A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void Gpt_Channel3A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void Gpt_Channel4A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void Gpt_Channel5A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void Gpt_Channel6A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void Gpt_Channel7A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void Gpt_Channel8A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void Gpt_Channel9A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void Gpt_Channel10A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void Gpt_Channel11A_Handler(uint8 Num,const Gpt_ConfigType* Timer);
void PREDEF_TIMER_1US_16BIT(void);
void PREDEF_TIMER_1US_32BIT(void);
void PREDEF_TIMER_100US_32BIT(void);
Std_ReturnType Gpt_GetPredefTimeValue(Gpt_PredefTimerType PredefTimer,uint32* TimeValue);
#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt.h
 *********************************************************************************************************************/