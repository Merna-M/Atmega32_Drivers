#include "EXT_interface.h"

void EXT_vInit(uint8 Copy_u8ExtInt , uint8 Copy_u8Control)
{
	switch(Copy_u8ExtInt)
	{
		case EXT0: //external interrupt 0
		//set the INT0 pin as input
		DIO_vSetPinDir('D',PIN2,PIN_INPUT);
		if(Copy_u8Control == LOW_LEVEL)
		{
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
		}
		else if(Copy_u8Control == ANY_CHANGE)
		{
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
		}
		else if(Copy_u8Control == FALL_EDGE)
		{
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		}
		else if(Copy_u8Control == RISE_EDGE)
		{
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		}
		SET_BIT(GICR,INT0);
		break;
		
		case EXT1: //external interrupt 1
		//set the INT1 pin as input
		DIO_vSetPinDir('D',PIN3,PIN_INPUT);
		if(Copy_u8Control == LOW_LEVEL)
		{
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
		}
		else if(Copy_u8Control == ANY_CHANGE)
		{
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
		}
		else if(Copy_u8Control == FALL_EDGE)
		{
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}
		else if(Copy_u8Control == RISE_EDGE)
		{
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}
		SET_BIT(GICR,INT1);
		break;
		
		case EXT2: //external interrupt 2
		//set the INT2 pin as input
		DIO_vSetPinDir('B',PIN2,PIN_INPUT);
		if(Copy_u8Control == FALL_EDGE)
		{
			CLR_BIT(MCUCSR,ISC2);
		}
		else if(Copy_u8Control == RISE_EDGE)
		{
			SET_BIT(MCUCSR,ISC2);
		}
		SET_BIT(GICR,INT2);
		break;
	}
}