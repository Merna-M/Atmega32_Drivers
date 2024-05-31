#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_interface.h"

void SEVSEG_BCD_vInit(uint8 Copy_u8Port , uint8 Copy_u8StartPin)
{
	DIO_vSetPinDir(Copy_u8Port , Copy_u8StartPin   , 1); //set the direction of the first pin as an output
	DIO_vSetPinDir(Copy_u8Port , Copy_u8StartPin+1 , 1); //set the direction of the second pin as an output
	DIO_vSetPinDir(Copy_u8Port , Copy_u8StartPin+2 , 1); //set the direction of the third pin as an output
	DIO_vSetPinDir(Copy_u8Port , Copy_u8StartPin+3 , 1); //set the direction of the forth pin as an output
}

void SEVSEG_BCD_vWrite(uint8 Copy_u8Port , uint8 Copy_u8StartPin , uint8 Copy_u8Value)
{
	DIO_vWritePin(Copy_u8Port , Copy_u8StartPin   , READ_BIT(Copy_u8Value , 0)); //put the first bit from the value to the pin
	DIO_vWritePin(Copy_u8Port , Copy_u8StartPin+1 , READ_BIT(Copy_u8Value , 1)); //put the second bit from the value to the pin
	DIO_vWritePin(Copy_u8Port , Copy_u8StartPin+2 , READ_BIT(Copy_u8Value , 2)); //put the third bit from the value to the pin
	DIO_vWritePin(Copy_u8Port , Copy_u8StartPin+3 , READ_BIT(Copy_u8Value , 3)); //put the forth bit from the value to the pin
}

