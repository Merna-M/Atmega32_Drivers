#include "MDD10A_interface.h"

/****************************************************************************************************/
void MDD10A_vInit(uint8 Copy_u8Port , uint8 Copy_u8PWMPin , uint8 Copy_u8DirPin)
{
	DIO_vSetPinDir(Copy_u8Port,Copy_u8PWMPin,PIN_OUTPUT);
	DIO_vSetPinDir(Copy_u8Port,Copy_u8DirPin,PIN_OUTPUT);
}


/****************************************************************************************************/
void MDD10A_vMotorMoveForward(uint8 Copy_u8Port , uint8 Copy_u8PWMPin , uint8 Copy_u8DirPin)
{
	DIO_vWritePin(Copy_u8Port,Copy_u8PWMPin,HIGH);
	DIO_vWritePin(Copy_u8Port,Copy_u8DirPin,LOW);
}


/****************************************************************************************************/

void MDD10A_vMotorMoveBack(uint8 Copy_u8Port , uint8 Copy_u8PWMPin , uint8 Copy_u8DirPin)
{
	DIO_vWritePin(Copy_u8Port,Copy_u8PWMPin,HIGH);
	DIO_vWritePin(Copy_u8Port,Copy_u8DirPin,HIGH);
}

/****************************************************************************************************/


void MDD10A_vMotorStop(uint8 Copy_u8Port , uint8 Copy_u8PWMPin)
{
	DIO_vWritePin(Copy_u8Port,Copy_u8PWMPin,LOW);
}


/****************************************************************************************************/

