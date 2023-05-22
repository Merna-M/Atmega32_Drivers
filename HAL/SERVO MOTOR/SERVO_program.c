#include "SERVO_interface.h"

void SERVO_vInit(void)
{
	GIE_EnableInterrupt();
	TMR1_vInit();
}

void SERVO_vSelectAngle(uint8 Copy_u8Angle)
{
	uint16 LOC_OCR1Value = ZERO_ANGLE + (Copy_u8Angle*1000ul)/180ul;
	TMR1_vSetOCR1Value(LOC_OCR1Value); 
}