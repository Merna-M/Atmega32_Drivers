/*
 * ADC_PROGRAM.c
 *
 * Created: 10/27/2023 2:41:22 PM
 *  Author: MERNA
 */ 

#include "ADC_INTERFACE.h"
#include "ADC_REGISTER.h"
#include "ADC_PRIVATE.h"
#include "ADC_CONFIG.h"


/**************************************************************************************************************************/
void ADC_vInit(void)
{
	#if ADC_PRESCALAR_MODE == ADC_PRESCALAR_2
	CLR_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);
	
	#elif ADC_PRESCALAR_MODE == ADC_PRESCALAR_4
	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);
	
	#elif ADC_PRESCALAR_MODE == ADC_PRESCALAR_8
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);
	
	#elif ADC_PRESCALAR_MODE == ADC_PRESCALAR_16
	CLR_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	#elif ADC_PRESCALAR_MODE == ADC_PRESCALAR_32
	SET_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	#elif ADC_PRESCALAR_MODE == ADC_PRESCALAR_64
	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	#elif ADC_PRESCALAR_MODE == ADC_PRESCALAR_128
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	#endif
	
	#if ADC_INTERRUPT_STATUS == ADC_ENABLE
	SET_BIT(ADCSRA,ADIE);
	#endif
	
	#if ADC_SOURCE_MODE == ADC_SOURCE_AREF
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	
	#elif ADC_SOURCE_MODE == ADC_SOURCE_AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	
	#elif ADC_SOURCE_MODE == ADC_SOURCE_INTERNAL
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	
	#endif
	
	// enable
	SET_BIT(ADCSRA,ADEN);
}

/**************************************************************************************************************************/

u16 ADC_u16ReadChannel(u8 Copy_u8Channel)
{
	u16 Read_val;
	
	//Choose ADC channel
	ADMUX &= ~(0b111 << MUX0);
	ADMUX |= ((Copy_u8Channel & 0b111) << MUX0);
	
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	
	//wait till the conversion is completed
	while(GET_BIT(ADCSRA,ADIF)==0);
	
	//logic 1 at the flag to clear it
	SET_BIT(ADCSRA,ADIF);
	
	//get the digital value from ADC register
	Read_val = ADCL;
	Read_val |= (ADCH<<8);
	
	return Read_val;
}

/**************************************************************************************************************************/