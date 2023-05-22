
#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

/* ######################## Macros ###############################*/
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


/* ######################## Includes ############################*/
#include "STD_types.h"
#include "BIT_math.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "GIE_interface.h"

/* ######################################### prototypes ################################################*/

/*
FUNCTION NAME	     : ADC_vInit
FUNCTION DESCRIPTION : used to initialize enables, setting the prescalar , choosing ref voltage
FUNCTION INPUTS	     : void
FUNCTION RETURN		 : void
*/
void ADC_vInit(void);

/*
FUNCTION NAME	     : ADC_u16Read
FUNCTION DESCRIPTION : reads the digital output value of the ADC
FUNCTION INPUTS	     : void 
FUNCTION RETURN		 : returns the digital values stored in ADC register
*/
uint16 ADC_u16Read(void);

/*
FUNCTION NAME	     : ADC_vSelectChannel
FUNCTION DESCRIPTION : selects a channel from the 8 channels in portA
FUNCTION INPUTS	     : Copy_u8Channel: selected channel
FUNCTION RETURN		 : void
*/
void ADC_vSelectChannel(uint8 Copy_u8Channel);

#endif 