/*
 * ADC_INTERFACE.h
 *
 * Created: 10/27/2023 2:41:58 PM
 *  Author: MERNA
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/************************************ Includes ***************************************/
#include "../../UTIL/BIT_MATH.h"
#include "../../UTIL/STD_TYPES.h"


/************************************ Macros *****************************************/

 /* Source Configurations */ 
#define ADC_SOURCE_AREF					1
#define ADC_SOURCE_AVCC					2
#define ADC_SOURCE_INTERNAL				3

/* interrupt/Enable Status */
#define ADC_ENABLE						1
#define ADC_DISABLE						2

/* ADC Channels */
#define ADC_CHANNEL_0					0
#define ADC_CHANNEL_1					1
#define ADC_CHANNEL_2					2
#define ADC_CHANNEL_3					3
#define ADC_CHANNEL_4					4
#define ADC_CHANNEL_5					5
#define ADC_CHANNEL_6					6
#define ADC_CHANNEL_7					7

/*********************************** Prototypes *************************************/
void ADC_vInit(void);

u16 ADC_u16ReadChannel(u8 Copy_u8Channel);


#endif /* ADC_INTERFACE_H_ */