#include "ADC_interface.h"

void ADC_vInit(void)
{
	//set initial channel
	#if defined ADC_0
	// MUX4_0 = 00000
	
	#elif defined ADC_1
	// MUX4_0 = 00001
	SET_BIT(ADMUX,MUX0);
	
	#elif defined ADC_2
	// MUX4_0 = 00010
	SET_BIT(ADMUX,MUX1);
	
	#elif defined ADC_3
	// MUX4_0 = 00011
	SET_BIT(ADMUX,MUX0);
	SET_BIT(ADMUX,MUX1);
	
	#elif defined ADC_4
	// MUX4_0 = 00100
	SET_BIT(ADMUX,MUX2);
	
	#elif defined ADC_5
	// MUX4_0 = 00101
	SET_BIT(ADMUX,MUX0);
	SET_BIT(ADMUX,MUX2);
	
	#elif defined ADC_6
	// MUX4_0 = 00110
	SET_BIT(ADMUX,MUX1);
	SET_BIT(ADMUX,MUX2);
	
	#elif defined ADC_7
	// MUX4_0 = 00111
	SET_BIT(ADMUX,MUX0);
	SET_BIT(ADMUX,MUX1);
	SET_BIT(ADMUX,MUX2);
	
	#endif
	
	//configure VREF AVCC with external capacitor at AREF pin
	//REFS1:0 = 01
	SET_BIT(ADMUX,REFS0);
	
	//Set interrupt Enable
	SET_BIT(ADCSRA,ADEN);
	
	//set prescaler = 64 , ADPS2:0 = 110
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
}


uint16 ADC_u16Read(void)
{
	uint16 Read_val;
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	
	//wait till the conversion is completed
	while(READ_BIT(ADCSRA,ADIF)==0);
	//logic 1 at the flag to clear it
	SET_BIT(ADCSRA,ADIF);
	
	//get the digital value from ADC register
	Read_val = ADCL;
	Read_val |= (ADCH<<8);
	
	return Read_val;
}

void ADC_vSelectChannel(uint8 Copy_u8Channel)
{
	switch(Copy_u8Channel)
	{
		case 0: //MUX4:0 = 00000
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		break;
		
		case 1: //MUX4:0 = 00001
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		break;
		
		case 2: //MUX4:0 = 00010
		CLR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		break;
		
		case 3: //MUX4:0 = 00011
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		break;
		
		case 4: //MUX4:0 = 00100
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		break;
		
		case 5: //MUX4:0 = 00101
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		break;
		
		case 6: //MUX4:0 = 00110
		CLR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		break;
		
		case 7: //MUX4:0 = 00111
		SET_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		SET_BIT(ADMUX,MUX2);
		break;
	}
}