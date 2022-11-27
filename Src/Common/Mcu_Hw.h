/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 Reg;
    INTCTRL_BF Bit;
}INTCTRL_Tag;*/

typedef struct
{
	uint32 EN[5];
}Enable_Tag;
typedef struct
{
	uint32 PRI[35];
}Priority_Tag;
typedef struct
{
	uint32 DIS[5];
}Disable_Tag;
typedef struct
{
	uint32 ACTIVE[5];
}Active_Tag;
typedef struct
{
	uint32 PEND[5];
}Pend_Tag;
typedef struct
{
	uint32 UNPEND[5];
}UNPend_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define PRIx                                   ((volatile Priority_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define ENx                                    ((volatile Enable_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define DISx                                   (volatile Disable_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x180)
#define PENDx                                  (volatile pend_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x200)
#define UNPENDx                                (volatile UNPend_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x280)
#define ACTIVEx                                (volatile Active_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x300)
#define SWTRIG 													       *((volatile uint32* const)(CORTEXM4_PERI_BASE_ADDRESS+0xF00))
#define VTABLE 																 *((volatile uint32* const)(CORTEXM4_PERI_BASE_ADDRESS+0xD08))
#define SYSPRI1 															 *((volatile uint32* const)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2 															 *((volatile uint32* const)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3 															 *((volatile uint32* const)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
#define APINT                             	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
/*****************************************SystemControl Regesters**************************************************************************/
#define SYSTEM_CONTROL_BASE_ADDRESS            0x400FE000
#define RCC_OFFSET                             0x060
#define RCC                                    *((volatile uint32* const)(SYSTEM_CONTROL_BASE_ADDRESS+0x060))
#define RCC2                                   *((volatile uint32* const)(SYSTEM_CONTROL_BASE_ADDRESS+0x070))
#define RIS                                    *((volatile uint32* const)(SYSTEM_CONTROL_BASE_ADDRESS+0x050))
#define PLLFREQ0                               *((volatile uint32* const)(SYSTEM_CONTROL_BASE_ADDRESS+0x160))
#define PLLFREQ1                               *((volatile uint32* const)(SYSTEM_CONTROL_BASE_ADDRESS+0x164))
#define PLLSTAT                                *((volatile uint32* const)(SYSTEM_CONTROL_BASE_ADDRESS+0x168))
	
#define RCGCGPIO                               *((volatile uint32* const)(SYSTEM_CONTROL_BASE_ADDRESS+0x608))
#define RCGCGPIO_OFFSET                        0x608
/*****************************************PORTA Regesters**************************************************************************/
#define PORTA_BASE_ADDRESS                     0x40004000
#define GPIODATAA                              0x40004000
#define GPIODIRA                               *((volatile uint32* const)(PORTA_BASE_ADDRESS+0x400))
#define GPIODR2RA                              *((volatile uint32* const)(PORTA_BASE_ADDRESS+0x500))
#define GPIOPURA                               *((volatile uint32* const)(PORTA_BASE_ADDRESS+0x510))
#define GPIODENA                               *((volatile uint32* const)(PORTA_BASE_ADDRESS+0x51C))
#define GPIOLOCKA                              *((volatile uint32* const)(PORTA_BASE_ADDRESS+0x520))
#define GPIOCRA                                *((volatile uint32* const)(PORTA_BASE_ADDRESS+0x524))
/*****************************************PORTB Regesters**************************************************************************/
#define PORTB_BASE_ADDRESS                     0x40005000
#define GPIODATAB                              0x40005000
#define GPIODIRB                               *((volatile uint32* const)(PORTB_BASE_ADDRESS+0x400))
#define GPIODR2RB                              *((volatile uint32* const)(PORTB_BASE_ADDRESS+0x500))
#define GPIOPURB                               *((volatile uint32* const)(PORTB_BASE_ADDRESS+0x510))
#define GPIODENB                               *((volatile uint32* const)(PORTB_BASE_ADDRESS+0x51C))
#define GPIOLOCKB                              *((volatile uint32* const)(PORTB_BASE_ADDRESS+0x520))
#define GPIOCRB                                *((volatile uint32* const)(PORTB_BASE_ADDRESS+0x524))
/*****************************************PORTC Regesters**************************************************************************/
#define PORTC_BASE_ADDRESS                     0x40006000
#define GPIODATAC                              0x40006000
#define GPIODIRC                               *((volatile uint32* const)(PORTC_BASE_ADDRESS+0x400))
#define GPIODR2RC                              *((volatile uint32* const)(PORTC_BASE_ADDRESS+0x500))
#define GPIOPURC                               *((volatile uint32* const)(PORTC_BASE_ADDRESS+0x510))
#define GPIODENC                               *((volatile uint32* const)(PORTC_BASE_ADDRESS+0x51C))
#define GPIOLOCKC                              *((volatile uint32* const)(PORTC_BASE_ADDRESS+0x520))
#define GPIOCRC                                *((volatile uint32* const)(PORTC_BASE_ADDRESS+0x524))
/*****************************************PORTD Regesters**************************************************************************/	
#define PORTD_BASE_ADDRESS                     0x40007000
#define GPIODATAD                              0x40007000
#define GPIODIRD                               *((volatile uint32* const)(PORTD_BASE_ADDRESS+0x400))
#define GPIODR2RD                              *((volatile uint32* const)(PORTD_BASE_ADDRESS+0x500))
#define GPIOPURD                               *((volatile uint32* const)(PORTD_BASE_ADDRESS+0x510))
#define GPIODEND                               *((volatile uint32* const)(PORTD_BASE_ADDRESS+0x51C))
#define GPIOLOCKD                              *((volatile uint32* const)(PORTD_BASE_ADDRESS+0x520))
#define GPIOCRD                                *((volatile uint32* const)(PORTD_BASE_ADDRESS+0x524))
/*****************************************PORTE Regesters**************************************************************************/
#define PORTE_BASE_ADDRESS                     0x40024000
#define GPIODATAE                              0x40024000
#define GPIODIRE                               *((volatile uint32* const)(PORTE_BASE_ADDRESS+0x400))
#define GPIODR2RE                              *((volatile uint32* const)(PORTE_BASE_ADDRESS+0x500))
#define GPIOPURE                               *((volatile uint32* const)(PORTE_BASE_ADDRESS+0x510))
#define GPIODENE                               *((volatile uint32* const)(PORTE_BASE_ADDRESS+0x51C))
#define GPIOLOCKE                              *((volatile uint32* const)(PORTE_BASE_ADDRESS+0x520))
#define GPIOCRE                                *((volatile uint32* const)(PORTE_BASE_ADDRESS+0x524))
/*****************************************PORTF Regesters**************************************************************************/
#define PORTF_BASE_ADDRESS                     0x40025000
#define GPIODATAF                              0x40025000
#define GPIODIRF                               *((volatile uint32* const)(PORTF_BASE_ADDRESS+0x400))
#define GPIODR2RF                              *((volatile uint32* const)(PORTF_BASE_ADDRESS+0x500))
#define GPIOPURF                               *((volatile uint32* const)(PORTF_BASE_ADDRESS+0x510))
#define GPIODENF                               *((volatile uint32* const)(PORTF_BASE_ADDRESS+0x51C))
#define GPIOLOCKF                              *((volatile uint32* const)(PORTF_BASE_ADDRESS+0x520))
#define GPIOCRF                                *((volatile uint32* const)(PORTF_BASE_ADDRESS+0x524))
/*****************************************TIMER Regesters**************************************************************************/
#define RCGCTIMER                              *((volatile uint32* const)(SYSTEM_CONTROL_BASE_ADDRESS+0x604))
#define RCGCWTIMER                             *((volatile uint32* const)(SYSTEM_CONTROL_BASE_ADDRESS+0x65))
	
#define TIMER0A_BASE_ADDRESS                   0x40030000
#define GPTMCFG0A                              *((volatile uint32* const)(TIMER0A_BASE_ADDRESS+0x000))
#define GPTMTAMR0                              *((volatile uint32* const)(TIMER0A_BASE_ADDRESS+0x004))
#define GPTMCTL0A                              *((volatile uint32* const)(TIMER0A_BASE_ADDRESS+0x00C))
#define GPTMIMR0A                              *((volatile uint32* const)(TIMER0A_BASE_ADDRESS+0x018))
#define GPTMRIS0A                              *((volatile uint32* const)(TIMER0A_BASE_ADDRESS+0x01C))
#define GPTMMIS0A                              *((volatile uint32* const)(TIMER0A_BASE_ADDRESS+0x020))
#define GPTMICR0A                              *((volatile uint32* const)(TIMER0A_BASE_ADDRESS+0x024))
#define GPTMTAILR0                             *((volatile uint32* const)(TIMER0A_BASE_ADDRESS+0x028))
#define GPTMTAPR0                              *((volatile uint32* const)(TIMER0A_BASE_ADDRESS+0x038))
#define GPTMTAR0                               *((volatile uint32* const)(TIMER0A_BASE_ADDRESS+0x048))

#define TIMER1A_BASE_ADDRESS                   0x40031000
#define GPTMCFG1A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x000))
#define GPTMTAMR1                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x004))
#define GPTMCTL1A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x00C))
#define GPTMIMR1A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x018))
#define GPTMRIS1A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x01C))
#define GPTMMIS1A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x020))
#define GPTMICR1A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x024))
#define GPTMTAILR1                             *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x028))
#define GPTMTAPR1                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x038))
#define GPTMTAR1                               *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x048))
	
#define TIMER2A_BASE_ADDRESS                   0x40032000
#define GPTMCFG2A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x000))
#define GPTMTAMR2                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x004))
#define GPTMCTL2A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x00C))
#define GPTMIMR2A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x018))
#define GPTMRIS2A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x01C))
#define GPTMMIS2A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x020))
#define GPTMICR2A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x024))
#define GPTMTAILR2                             *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x028))
#define GPTMTAPR2                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x038))
#define GPTMTAR2                               *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x048))
	
#define TIMER3A_BASE_ADDRESS                   0x40033000
#define GPTMCFG3A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x000))
#define GPTMTAMR3                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x004))
#define GPTMCTL3A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x00C))
#define GPTMIMR3A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x018))
#define GPTMRIS3A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x01C))
#define GPTMMIS3A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x020))
#define GPTMICR3A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x024))
#define GPTMTAILR3                             *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x028))
#define GPTMTAPR3                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x038))
#define GPTMTAR3                               *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x048))
	
#define TIMER4A_BASE_ADDRESS                   0x40034000
#define GPTMCFG4A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x000))
#define GPTMTAMR4                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x004))
#define GPTMCTL4A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x00C))
#define GPTMIMR4A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x018))
#define GPTMRIS4A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x01C))
#define GPTMMIS4A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x020))
#define GPTMICR4A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x024))
#define GPTMTAILR4                             *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x028))
#define GPTMTAPR4                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x038))
#define GPTMTAR4                               *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x048))
	
#define TIMER5A_BASE_ADDRESS                   0x40035000
#define GPTMCFG5A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x000))
#define GPTMTAMR5                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x004))
#define GPTMCTL5A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x00C))
#define GPTMIMR5A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x018))
#define GPTMRIS5A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x01C))
#define GPTMMIS5A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x020))
#define GPTMICR5A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x024))
#define GPTMTAILR5                             *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x028))
#define GPTMTAPR5                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x038))
#define GPTMTAR5                               *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x048))
	
#define TIMER6A_BASE_ADDRESS                   0x40036000
#define GPTMCFG6A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x000))
#define GPTMTAMR6                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x004))
#define GPTMCTL6A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x00C))
#define GPTMIMR6A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x018))
#define GPTMRIS6A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x01C))
#define GPTMMIS6A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x020))
#define GPTMICR6A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x024))
#define GPTMTAILR6                             *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x028))
#define GPTMTAPR6                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x038))
#define GPTMTAR6                               *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x048))

#define TIMER7A_BASE_ADDRESS                   0x40037000
#define GPTMCFG7A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x000))
#define GPTMTAMR7                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x004))
#define GPTMCTL7A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x00C))
#define GPTMIMR7A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x018))
#define GPTMRIS7A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x01C))
#define GPTMMIS7A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x020))
#define GPTMICR7A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x024))
#define GPTMTAILR7                             *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x028))
#define GPTMTAPR7                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x038))
#define GPTMTAR7                               *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x048))

#define TIMER8A_BASE_ADDRESS                   0x4004C000
#define GPTMCFG8A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x000))
#define GPTMTAMR8                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x004))
#define GPTMCTL8A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x00C))
#define GPTMIMR8A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x018))
#define GPTMRIS8A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x01C))
#define GPTMMIS8A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x020))
#define GPTMICR8A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x024))
#define GPTMTAILR8                             *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x028))
#define GPTMTAPR8                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x038))
#define GPTMTAR8                               *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x048))

#define TIMER9A_BASE_ADDRESS                   0x4004D000
#define GPTMCFG9A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x000))
#define GPTMTAMR9                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x004))
#define GPTMCTL9A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x00C))
#define GPTMIMR9A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x018))
#define GPTMRIS9A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x01C))
#define GPTMMIS9A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x020))
#define GPTMICR9A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x024))
#define GPTMTAILR9                             *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x028))
#define GPTMTAPR9                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x038))
#define GPTMTAR9                               *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x048))

#define TIMER10A_BASE_ADDRESS                   0x4004E000
#define GPTMCFG10A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x000))
#define GPTMTAMR10                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x004))
#define GPTMCTL10A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x00C))
#define GPTMIMR10A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x018))
#define GPTMRIS10A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x01C))
#define GPTMMIS10A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x020))
#define GPTMICR10A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x024))
#define GPTMTAILR10                             *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x028))
#define GPTMTAPR10                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x038))
#define GPTMTAR10                               *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x048))

#define TIMER11A_BASE_ADDRESS                   0x4004F000
#define GPTMCFG11A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x000))
#define GPTMTAMR11                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x004))
#define GPTMCTL11A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x00C))
#define GPTMIMR11A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x018))
#define GPTMRIS11A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x01C))
#define GPTMMIS11A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x020))
#define GPTMICR11A                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x024))
#define GPTMTAILR11                             *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x028))
#define GPTMTAPR11                              *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x038))
#define GPTMTAR11                               *((volatile uint32* const)(TIMER1A_BASE_ADDRESS+0x048))
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/



 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
*********************************************************************************************************************/