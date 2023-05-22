#include "MOTOR_interface.h"

void MOTOR_vInitOnePin(uint8 Copy_u8Port , uint8 Copy_u8Pin)
{
	DIO_vSetPinDir(Copy_u8Port,Copy_u8Pin,PIN_OUTPUT);
}

void MOTOR_vInitHBridge(uint8 Copy_u8Port , uint8 Copy_u8StartPin)
{
	DIO_vSetPinDir(Copy_u8Port,Copy_u8StartPin,PIN_OUTPUT);
	DIO_vSetPinDir(Copy_u8Port,Copy_u8StartPin+1,PIN_OUTPUT);
}


void MOTOR_vRotate(uint8 Copy_u8MotorSelect , uint8 Copy_u8Direction ,uint8 Copy_u8Port , uint8 Copy_u8StartPin)
{
	if(Copy_u8MotorSelect == MOTOR_ONE_PIN)
	{
		if(Copy_u8Direction == MOTOR_ON)
		{
			DIO_vWritePin(Copy_u8Port , Copy_u8StartPin , HIGH);
		}
		else
		{
			DIO_vWritePin(Copy_u8Port , Copy_u8StartPin , LOW);
		}
	}
	else if(Copy_u8MotorSelect == MOTOR_HBRIDGE || Copy_u8MotorSelect == MOTOR_L293D)
	{
		if(Copy_u8Direction == MOTOR_ROTATE_RIGHT)
		{
			DIO_vWritePin(Copy_u8Port , Copy_u8StartPin   , LOW);
			DIO_vWritePin(Copy_u8Port , Copy_u8StartPin+1 , HIGH);
		}
		else if(Copy_u8Direction == MOTOR_ROTATE_LEFT)
		{
			DIO_vWritePin(Copy_u8Port , Copy_u8StartPin+1 , LOW);
			DIO_vWritePin(Copy_u8Port , Copy_u8StartPin   , HIGH);
		}
		else
		{
			DIO_vWritePin(Copy_u8Port , Copy_u8StartPin   , LOW);
			DIO_vWritePin(Copy_u8Port , Copy_u8StartPin+1 , LOW);
		}
	}
}