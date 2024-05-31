#include "ULTRASNK_interface.h"

void ULTRASNK_vInit(void)
{
	// set the trigger pin as an output
	DIO_vSetPinDir(ULTRASNK_PORT,TRIGGER,PIN_OUTPUT);
	//
	TCCR1A=0;
}

static void ULTRASNK_vSendTrigger(void)
{
	DIO_vWritePin(ULTRASNK_PORT,TRIGGER,HIGH);
	_delay_us(50);
	DIO_vWritePin(ULTRASNK_PORT,TRIGGER,LOW);
}

uint16 ULTRASNK_u8MeasureDistance(void)
{
	uint16 LOC_FirstChange,LOC_SecondChange;
	uint16 Return_distance=0;
	
	//logic 1 to clear the flag
	SET_BIT(TIFR,ICF1);
	
	ULTRASNK_vSendTrigger();
	//prescaler = 8 , capture a rising edge
	TCCR1B=0xC2;
	while(READ_BIT(TIFR,ICF1)==0);
	
	LOC_FirstChange = ICR1;
	//logic 1 to clear the flag
	SET_BIT(TIFR,ICF1);
	//prescaler = 8 , capture a falling edge
	TCCR1B = 0x82;
	while(READ_BIT(TIFR,ICF1)==0);
	LOC_SecondChange = ICR1; 
	//logic 1 to clear the flag
	SET_BIT(TIFR,ICF1);
	TCCR1B=0;//close timer1
	Return_distance = SOUND_SPEED*(LOC_SecondChange-LOC_FirstChange)/(1000000*2);
	return Return_distance;
}