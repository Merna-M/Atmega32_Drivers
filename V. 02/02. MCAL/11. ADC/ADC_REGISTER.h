/*
 * ADC_REGISTER.h
 *
 * Created: 10/27/2023 2:52:41 PM
 *  Author: MERNA
 */ 


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_



#define ADMUX	*((volatile u8*) (0x27))
#define ADCSRA	*((volatile u8*) (0x26))
#define ADCH	*((volatile u8*) (0x25))
#define ADCL	*((volatile u8*) (0x24))
#define ADC		*((volatile u16*) (0x24))	


/* ADMUX Register */
#define MUX0	0
#define MUX1	1
#define MUX2	2
#define MUX3	3
#define MUX4	4
#define ADLAR	5
#define REFS0	6
#define REFS1	7

/* ADCSRA Register */
#define ADPS0	0
#define ADPS1	1
#define ADPS2	2
#define ADIE	3
#define ADIF	4
#define ADATE	5
#define ADSC	6
#define ADEN	7

/* Channel IDs */
#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7



#endif /* ADC_REGISTER_H_ */