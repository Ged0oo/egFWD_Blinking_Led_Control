/***************************************************************************************************
*   FILE DESCRIPTION
*   ------------------------------------------------------------------------------------------------*/
/**      \file Dio.c
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
#include "Dio.h"
#include "Mcu_Hw.h"
#include "Dio_types.h"
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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType Channelnum,Dio_PortType Portname)
{
	uint8 Value;
  uint32 Addr=(1<<(Channelnum+2));
	uint32 Offset;
	switch(Portname)
	{
		case A:
			Offset=GPIODATAA+Addr;
			SET_BIT(RCGCGPIO,0);
			SET_BIT(GPIODENA,Channelnum);
			CLR_BIT(GPIODIRA,Channelnum);
			if( *((volatile uint32* const)(Offset)) >> Channelnum==1)
				Value = HIGH;
			else
				Value = LOW;
		  break;
		case B:
			Offset=GPIODATAB+Addr;
			SET_BIT(RCGCGPIO,1);
			SET_BIT(GPIODENB,Channelnum);
			CLR_BIT(GPIODIRB,Channelnum);
			if(*((volatile uint32*const)(Offset))>>Channelnum==1)
				Value = HIGH;
			else
				Value = LOW;
			break;
		case C:
			Offset=GPIODATAC+Addr;
			SET_BIT(RCGCGPIO,2);
			SET_BIT(GPIODENC,Channelnum);
			CLR_BIT(GPIODIRC,Channelnum);
			if( *((volatile uint32* const)(Offset)) >> Channelnum==1)
				Value = HIGH;
			else
				Value = LOW;
		  break;
		case D:
			Offset=GPIODATAD+Addr;
			SET_BIT(RCGCGPIO,3);
			SET_BIT(GPIODEND,Channelnum);
			CLR_BIT(GPIODIRD,Channelnum);
			if( *((volatile uint32* const)(Offset)) >> Channelnum==1)
				Value = HIGH;
			else
				Value = LOW;
		  break;
		case E:
			Offset=GPIODATAE+Addr;
			SET_BIT(RCGCGPIO,4);
			SET_BIT(GPIODENE,Channelnum);
			CLR_BIT(GPIODIRE,Channelnum);
			if( *((volatile uint32* const)(Offset)) >> Channelnum==1)
				Value = HIGH;
			else
				Value = LOW;
		  break;
		case F:
			Offset=GPIODATAF+Addr;
			SET_BIT(RCGCGPIO,5);
			GPIOLOCKF=0x4C4F434B;
			GPIOCRF=0xFF;
			uint8 i;
		  for(i=0;i<10;i++);
			SET_BIT(GPIODENF,Channelnum);
			CLR_BIT(GPIODIRF,Channelnum);
			if( *((volatile uint32* const)(Offset)) >> Channelnum==1)
				Value = HIGH;
			else
				Value = LOW;
		  break;
	}
	return Value;
}
void Dio_WriteChannel(Dio_ChannelType Channelnum,Dio_LevelType Level,Dio_PortType Portname)
{
	uint32 Addr=(1<<(Channelnum+2));
	switch(Portname)
	{
		case A:
			SET_BIT(RCGCGPIO,0);
			SET_BIT(GPIODENA,Channelnum);
			CLR_BIT(GPIODIRA,Channelnum);
			GPIODR2RA=0xFF;
			if(Level==HIGH){
				*((volatile uint32* const)(GPIODATAA+Addr))=(1<<Channelnum);}
			else{ 
				*((volatile uint32* const)(GPIODATAA+Addr))=(0<<Channelnum);}
		  break;
		case B:
			SET_BIT(RCGCGPIO,1);
			SET_BIT(GPIODENB,Channelnum);
			CLR_BIT(GPIODIRB,Channelnum);
			GPIODR2RB=0xFF;
			if(Level==HIGH){
				*((volatile uint32* const)(GPIODATAB+Addr))=(1<<Channelnum);}
			else {
				*((volatile uint32* const)(GPIODATAB+Addr))=(0<<Channelnum);}
		  break;
		case C:
			SET_BIT(RCGCGPIO,2);
			SET_BIT(GPIODENC,Channelnum);
			CLR_BIT(GPIODIRC,Channelnum);
			GPIODR2RC=0xFF;
			if(Level==HIGH){
				*((volatile uint32* const)(GPIODATAC+Addr))=(1<<Channelnum);}
			else {
				*((volatile uint32* const)(GPIODATAC+Addr))=(0<<Channelnum);}
		  break;
		case D:
			SET_BIT(RCGCGPIO,3);
			SET_BIT(GPIODEND,Channelnum);
			CLR_BIT(GPIODIRD,Channelnum);
			GPIODR2RD=0xFF;
			if(Level==HIGH){
				*((volatile uint32* const)(GPIODATAD+Addr))=(1<<Channelnum);}
			else {
				*((volatile uint32* const)(GPIODATAD+Addr))=(0<<Channelnum);}
		  break;
		case E:
			SET_BIT(RCGCGPIO,4);
			SET_BIT(GPIODENE,Channelnum);
			CLR_BIT(GPIODIRE,Channelnum);
			GPIODR2RE=0xFF;
			if(Level==HIGH){
				*((volatile uint32* const)(GPIODATAE+Addr))=(1<<Channelnum);}
			else {
				*((volatile uint32* const)(GPIODATAE+Addr))=(0<<Channelnum);}
		  break;
		case F:
			SET_BIT(RCGCGPIO,5);
			GPIOLOCKF=0x4C4F434B;
			GPIOCRF=0xFF;
			uint8 i;
		  for(i=0;i<10;i++);
			SET_BIT(GPIODENF,Channelnum);
			CLR_BIT(GPIODIRF,Channelnum);
			GPIODR2RF=0xFF;
			if(Level==HIGH)
				*((volatile uint32* const)(GPIODATAF+Addr))=(1<<Channelnum);
			else 
				*((volatile uint32* const)(GPIODATAF+Addr))=(0<<Channelnum);
		  break;
	}
}
void Dio_WritePort(Dio_PortType Portname,uint8 Level)
{
	switch(Portname)
	{
		case A:
			SET_BIT(RCGCGPIO,0);
			GPIODENA=0xFF;
			GPIODIRA=0xFF;
			if(Level==HIGH)
				*((volatile uint32* const)(GPIODATAA+0x3FC))=0xFF;
			else
				*((volatile uint32* const)(GPIODATAA+0x3FC))=0x00;
			break;
		case B:
			SET_BIT(RCGCGPIO,1);
			GPIODENB=0xFF;
			GPIODIRB=0xFF;
			if(Level==HIGH)
				*((volatile uint32* const)(GPIODATAB+0x3FC))=0xFF;
			else
				*((volatile uint32* const)(GPIODATAB+0x3FC))=0x00;
			break;
		case C:
			SET_BIT(RCGCGPIO,2);
			GPIODENC=0xFF;
			GPIODIRC=0xFF;
			if(Level==HIGH)
				*((volatile uint32* const)(GPIODATAC+0x3FC))=0xFF;
			else
				*((volatile uint32* const)(GPIODATAC+0x3FC))=0x00;
			break;
		case D:
			SET_BIT(RCGCGPIO,3);
			GPIODEND=0xFF;
			GPIODIRD=0xFF;
			if(Level==HIGH)
				*((volatile uint32* const)(GPIODATAD+0x3FC))=0xFF;
			else
				*((volatile uint32* const)(GPIODATAD+0x3FC))=0x00;
			break;
		case E:
			SET_BIT(RCGCGPIO,4);
			GPIODENE=0xFF;
			GPIODIRE=0xFF;
			if(Level==HIGH)
				*((volatile uint32* const)(GPIODATAE+0x3FC))=0xFF;
			else
				*((volatile uint32* const)(GPIODATAE+0x3FC))=0x00;
			break;
		case F:
			SET_BIT(RCGCGPIO,5);
			GPIOLOCKF=0x4C4F434B;
			GPIOCRF=0xFF;
			uint8 i;
		  for(i=0;i<10;i++);
			GPIODENF=0xFF;
			//GPIODIRF=0xFF;
			SET_BIT(GPIODIRF,1);
			SET_BIT(GPIODIRF,2);
			SET_BIT(GPIODIRF,3);
			if(Level==HIGH)
				*((volatile uint32* const)(GPIODATAF+0x3FC))=0xFF;
			else
				*((volatile uint32* const)(GPIODATAF+0x3FC))=0x00;
			break;
	}
}
uint8 Dio_ReadPort(Dio_PortType Portname)
{
	uint8 Value;
	switch(Portname)
	{
		case A:
			SET_BIT(RCGCGPIO,0);
			GPIODENA=0xFF;
			GPIODIRA=0x00;
			Value=*((volatile uint32* const)(GPIODATAA+0x3FC));
			break;
		case B:
			SET_BIT(RCGCGPIO,1);
			GPIODENB=0xFF;
			GPIODIRB=0x00;
			Value=*((volatile uint32* const)(GPIODATAB+0x3FC));
			break;
		case C:
			SET_BIT(RCGCGPIO,2);
			GPIODENC=0xFF;
			GPIODIRC=0x00;
			Value=*((volatile uint32* const)(GPIODATAC+0x3FC));
			break;
		case D:
			SET_BIT(RCGCGPIO,3);
			GPIODEND=0xFF;
			GPIODIRD=0x00;
			Value=*((volatile uint32* const)(GPIODATAD+0x3FC));
			break;
		case E:
			SET_BIT(RCGCGPIO,4);
			GPIODENE=0xFF;
			GPIODIRE=0x00;
			Value=*((volatile uint32* const)(GPIODATAE+0x3FC));
			break;
		case F:
			SET_BIT(RCGCGPIO,5);
			while(READ_BIT(RCGCGPIO,5)==0);		
			GPIODENF=0xFF;
			GPIODIRF=0x00;
			Value=*((volatile uint32* const)(GPIODATAF+0x3FC));
			break;
	}
	return Value;
}
void Dio_FlipChannel(Dio_ChannelType Channelnum,Dio_PortType Portname)
{
	
	switch(Portname)
	{
		case A:
			if(Dio_ReadChannel(Channelnum,A)==HIGH)
				Dio_WriteChannel(Channelnum,LOW,A);
			else
				Dio_WriteChannel(Channelnum,HIGH,A);
		  break;
		case B:
			if(Dio_ReadChannel(Channelnum,B)==HIGH)
				Dio_WriteChannel(Channelnum,LOW,B);
			else
				Dio_WriteChannel(Channelnum,HIGH,B);
		  break;
		case C:
			if(Dio_ReadChannel(Channelnum,A)==HIGH)
				Dio_WriteChannel(Channelnum,LOW,A);
			else
				Dio_WriteChannel(Channelnum,HIGH,A);
		  break;
		case D:
			if(Dio_ReadChannel(Channelnum,D)==HIGH)
				Dio_WriteChannel(Channelnum,LOW,D);
			else
				Dio_WriteChannel(Channelnum,HIGH,A);
		  break;
		case E:
			if(Dio_ReadChannel(Channelnum,E)==HIGH)
				Dio_WriteChannel(Channelnum,LOW,E);
			else
				Dio_WriteChannel(Channelnum,HIGH,E);
		  break;
		case F:
			if(Dio_ReadChannel(Channelnum,F)==HIGH)
				Dio_WriteChannel(Channelnum,LOW,F);
			else
				Dio_WriteChannel(Channelnum,HIGH,F);
		  break;
	}
}
void Dio_FlipPort(Dio_PortType Portname)
{
	uint8 Value,Flipvalue;
	switch(Portname)
	{
		case A:
			Value=Dio_ReadPort(A);
			Flipvalue=Value^0xFF;
			Dio_WritePort(A,Flipvalue);
			break;
		case B:
			Value=Dio_ReadPort(B);
			Flipvalue=Value^0xFF;
			Dio_WritePort(B,Flipvalue);
			break;
		case C:
			Value=Dio_ReadPort(C);
			Flipvalue=Value^0xFF;
			Dio_WritePort(C,Flipvalue);
			break;
		case D:
			Value=Dio_ReadPort(D);
			Flipvalue=Value^0xFF;
			Dio_WritePort(D,Flipvalue);
			break;
		case E:
			Value=Dio_ReadPort(E);
			Flipvalue=Value^0xFF;
			Dio_WritePort(E,Flipvalue);
			break;
		case F:
			Value=Dio_ReadPort(F);
			Flipvalue=Value^0xFF;
			Dio_WritePort(F,Flipvalue);
			break;
	}
}

/************************************************************************************************
*  END OF FILE  :    Dio.C
*************************************************************************************************/