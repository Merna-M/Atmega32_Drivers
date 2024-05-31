#include "STD_types.h"
#include "DIO_interface.h"

void BTN_vInit(uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	DIO_vSetPinDir(Copy_u8Port,Copy_u8Pin,0); //set the direction of the pin as an input
}

uint8 BTN_u8Read(uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	return DIO_u8ReadPin(Copy_u8Port,Copy_u8Pin);
}

void BTN_vConnectPullUp (uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8PullUppCond)
{
	DIO_vConnectPullUp(Copy_u8Port,Copy_u8Pin,Copy_u8PullUppCond); //enable or disable internal pull up
}