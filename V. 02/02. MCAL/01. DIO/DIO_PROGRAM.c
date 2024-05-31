/*
 * DIO.c
 *
 * Created: 10/20/2023 10:16:06 AM
 *  Author: MERNA
 */ 
#include "DIO_INTERFACE.h"
/**********************************************************************************************************************/
/*
NAME       : Dio_WriteChannel
DESCRIPTION: Write pin
INPUTS     : ChannelId: Channel number(PA_0 : PD_7) ,, Level: STD_HIGH or STD_LOW
RETURN     : void
*/
/**********************************************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level){	switch(ChannelId/8)	{		/* PortA */		case Dio_PORTA:		if(Level == STD_HIGH){			SET_BIT(PORTA,ChannelId);		}else {			CLR_BIT(PORTA,ChannelId);		}		break;				/* PortB */		case Dio_PORTB:		if(Level == STD_HIGH){			SET_BIT(PORTB,ChannelId%8);		}else {			CLR_BIT(PORTB,ChannelId%8);		}		break;				/* PortC */		case Dio_PORTC:		if(Level == STD_HIGH){			SET_BIT(PORTC,ChannelId%8);		}else {			CLR_BIT(PORTC,ChannelId%8);		}		break;				/* PortD */		case Dio_PORTD:		if(Level == STD_HIGH){			SET_BIT(PORTD,ChannelId%8);		}else {			CLR_BIT(PORTD,ChannelId%8);		}		break;				default:		break;	}}/**********************************************************************************************************************/
/*
NAME       : Dio_ReadChannel
DESCRIPTION: Read pin
INPUTS     : ChannelId: Channel number(PA_0 : PD_7) 
RETURN     : Pin input (STD_HIGH or STD_LOW)
*/
/**********************************************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){	/*volatile u8* PINs[4]={0x39,0x36,0x33,0x30};	Dio_LevelType Ret = GET_BIT(*(volatile u8*)PINs[ChannelId/8],ChannelId%8);	return Ret;*/	Dio_LevelType LOC_Ret=0;	switch(ChannelId/8)	{		case Dio_PORTA:		LOC_Ret = GET_BIT(PINA,ChannelId);		break;				case Dio_PORTB:		LOC_Ret = GET_BIT(PINB,ChannelId%8);		break;				case Dio_PORTC:		LOC_Ret = GET_BIT(PINC,ChannelId%8);		break;				case Dio_PORTD:		LOC_Ret = GET_BIT(PIND,ChannelId%8);		break;				default:		break;	}	return LOC_Ret;}/**********************************************************************************************************************/
/*
NAME       : Dio_ReadPort
DESCRIPTION: Read Port
INPUTS     : PortId: Port number (Dio_PORTA : Dio_PORTD)
RETURN     : Port input 
*/
/**********************************************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){	Dio_PortLevelType LOC_Ret;	switch(PortId)	{		case Dio_PORTA:			LOC_Ret = PINA;			break;				case Dio_PORTB:			LOC_Ret = PINB;			break;					case Dio_PORTC:			LOC_Ret = PINC;			break;					case Dio_PORTD:			LOC_Ret = PIND;			break;					default:			break;	}}/**********************************************************************************************************************/
/*
NAME       : Dio_WritePort
DESCRIPTION: Write Port
INPUTS     : PortId: Port number (Dio_PORTA : Dio_PORTD) ,, Level: output port value
RETURN     : void
*/
/**********************************************************************************************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){	switch(PortId)	{		case Dio_PORTA:		PORTA = Level;		break;				case Dio_PORTB:		PORTB = Level;		break;				case Dio_PORTC:		PORTC = Level;		break;				case Dio_PORTD:		PORTD = Level;		break;				default:		break;	}}


/**********************************************************************************************************************/
/*
NAME       : Dio_FlipChannel
DESCRIPTION: Flips pin value
INPUTS     : ChannelId: Channel number(PA_0 : PD_7)
RETURN     : new pin value (STD_HIGH or STD_LOW)
*/
/**********************************************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){	Dio_LevelType LOC_Ret=0;	switch(ChannelId/8)	{		case Dio_PORTA:			TOG_BIT(PORTA,ChannelId);			LOC_Ret = GET_BIT(PORTA,ChannelId);			break;				case Dio_PORTB:			TOG_BIT(PORTB,ChannelId%8);			LOC_Ret = GET_BIT(PORTB,ChannelId%8);			break;				case Dio_PORTC:			TOG_BIT(PORTC,ChannelId%8);			LOC_Ret = GET_BIT(PORTC,ChannelId%8);			break;				case Dio_PORTD:			TOG_BIT(PORTD,ChannelId%8);			LOC_Ret = GET_BIT(PORTD,ChannelId%8);			break;				default:			break;	}	return LOC_Ret;}



/**********************************************************************************************************************/
/*
NAME       : Dio_WriteMask
DESCRIPTION: write pins only if the opposite pin in Copy_u8Mask is 1
INPUTS     : PortId: Port number (Dio_PORTA : Dio_PORTD) ,, Level: output port value ,, Copy_u8Mask: Mask
RETURN     : void
*/
/**********************************************************************************************************************/
void Dio_WriteMask(Dio_PortType PortId, Dio_PortLevelType Level, u8 Copy_u8Mask)
{
	Dio_ChannelType LOC_Channel = PortId*8;
	u8 LOC_i=0;
	for(LOC_i=0 ; LOC_i<8 ; LOC_i++)
	{
		if(GET_BIT(Copy_u8Mask,LOC_i) == STD_HIGH)
		{
			Dio_WriteChannel(LOC_Channel+LOC_i, GET_BIT(Level , LOC_i));
		}
	}
}



/**********************************************************************************************************************/
/*
NAME       : Dio_Init
DESCRIPTION: Initialize pins' directions
INPUTS     : ChannelId: array of Channel numbers(PA_0 : PD_7) ,, Copy_u8Size: size of array ,, Dir: Direction of pins
RETURN     : void
*/
/**********************************************************************************************************************/
void Dio_Init(Dio_ChannelType *ChannelId,u8 Copy_u8Size,Port_PinDirectionType Dir)
{
	Port_ConfigType LOC_Config;
	for(u8 LOC_i=0 ; LOC_i<Copy_u8Size ; LOC_i++)
	{
		LOC_Config.Port = ChannelId[LOC_i]/8;
		LOC_Config.Pin  = ChannelId[LOC_i]%8;
		LOC_Config.Dir  = Dir%2;
		PORT_InsertConf(&LOC_Config , 1);
		if(Dir == PORT_PIN_PP)
		{
			Dio_WriteChannel(ChannelId[LOC_i],STD_HIGH);
		}
	}
}




/**********************************************************************************************************************/