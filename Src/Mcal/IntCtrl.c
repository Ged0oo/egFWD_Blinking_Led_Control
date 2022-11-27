/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"
#include "IntCtrl_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
		extern struct Int_Prix Interrupt_Prio[NO_OF_INT];
	  extern uint8 EnabledInt[NO_OF_INT];
    uint8 IntNo,Index,InterruptLoc,BitLoc,i,j;
	  uint32 variable;
	  uint32 IntPri;
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    #if (GROUP_MODE == 0)
			 APINT = VECT_KEY|0x00000200;
	 #elif (GROUP_MODE==1) 
			 APINT = VECT_KEY|0x00000500;
	 #elif (GROUP_MODE==2)
			 APINT = VECT_KEY|0x00000600;
	 #elif (GROUP_MODE==3)
			 APINT = VECT_KEY|0x00000700;
	 #endif 
    
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
		for(i=0;i<NO_OF_INT;i++)
			{
				IntNo=Interrupt_Prio[i].Int_No;
				IntPri=(uint32)Interrupt_Prio[i].Int_pri;
				Index=IntNo/4;
				BitLoc=((IntNo%4)*8)+5;
				variable =(IntPri<<BitLoc);
				PRIx->PRI[Index]|=variable;
			}
			
	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
		for(j=0;j<NO_OF_INT;j++)
			{
				IntNo=EnabledInt[j];
				InterruptLoc=IntNo/32;
				BitLoc=IntNo%32;
				ENx->EN[InterruptLoc]|=(1<<BitLoc);
			}

	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/