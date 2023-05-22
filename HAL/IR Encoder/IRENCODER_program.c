#include "IRENCODER_interface.h"

void IRENCODER_vInit(uint8 Copy_u8IRPort ,uint8 Copy_u8IROutPin)
{
	DIO_vSetPinDir(Copy_u8IRPort,Copy_u8IROutPin,PIN_INPUT);
}

uint8 IRENCODER_u8DetectObstacle(uint8 Copy_u8IRPort ,uint8 Copy_u8IROutPin)
{
	uint8 Return_Value = 0; // 0 if no obstacle detected and 1 if detected
	Return_Value = DIO_u8ReadPin(Copy_u8IRPort,Copy_u8IROutPin);
	return Return_Value;
}