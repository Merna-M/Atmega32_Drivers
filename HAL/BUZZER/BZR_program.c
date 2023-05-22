#include "STD_types.h"
#include "DIO_interface.h"

void BZR_vInit(uint8 Copy_u8Port,uint8 Copy_u8Pin)
{
	DIO_vSetPinDir(Copy_u8Port,Copy_u8Pin,1); //set direction to 1 (output)
}

void BZR_vON(uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	DIO_vWritePin(Copy_u8Port,Copy_u8Pin,1); //put value = 1 to let the led ON
}

void BZR_vOFF(uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	DIO_vWritePin(Copy_u8Port,Copy_u8Pin,0); //put value = 0 to let the led OFF
}

void BZR_vToggle(uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	DIO_vTogglePin(Copy_u8Port,Copy_u8Pin); //toggle the current bit of the pin
}

uint8 BZR_vReadStatus (uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	return DIO_u8ReadPin(Copy_u8Port,Copy_u8Pin); //read pin value
}