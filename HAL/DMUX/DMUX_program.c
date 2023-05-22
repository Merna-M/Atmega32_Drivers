#include "DMUX_interface.h"

void DMUX_vInit(void)
{
	DIO_vSetPinDir(DMUX_PORT,DMUX_A0_PIN,PIN_OUTPUT);
	DIO_vSetPinDir(DMUX_PORT,DMUX_A1_PIN,PIN_OUTPUT);
}

void DMUX_vSelectOutput(uint8 Copy_u8SelectedOutput)
{
	switch(Copy_u8SelectedOutput)
	{
		case DMUX_OUTPUT_0:
		DIO_vWritePin(DMUX_PORT,DMUX_A0_PIN,LOW);
		DIO_vWritePin(DMUX_PORT,DMUX_A1_PIN,LOW);
		break;
		
		case DMUX_OUTPUT_1:
		DIO_vWritePin(DMUX_PORT,DMUX_A0_PIN,HIGH);
		DIO_vWritePin(DMUX_PORT,DMUX_A1_PIN,LOW);
		break;
		
		case DMUX_OUTPUT_2:
		DIO_vWritePin(DMUX_PORT,DMUX_A0_PIN,LOW);
		DIO_vWritePin(DMUX_PORT,DMUX_A1_PIN,HIGH);
		break;
		
		case DMUX_OUTPUT_3:
		DIO_vWritePin(DMUX_PORT,DMUX_A0_PIN,HIGH);
		DIO_vWritePin(DMUX_PORT,DMUX_A1_PIN,HIGH);
		break;
		
	}
}