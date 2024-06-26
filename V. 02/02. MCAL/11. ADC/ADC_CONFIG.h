/*
 * ADC_CONFIG.h
 *
 * Created: 10/27/2023 2:42:17 PM
 *  Author: MERNA
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* Choose ADC Prescalar
Options:
01. ADC_PRESCALAR_2
02. ADC_PRESCALAR_4
03. ADC_PRESCALAR_8
04. ADC_PRESCALAR_16
05. ADC_PRESCALAR_32
06. ADC_PRESCALAR_64
07. ADC_PRESCALAR_128
  
*/

#define ADC_PRESCALAR_MODE				ADC_PRESCALAR_64

			
#define ADC_SOURCE_MODE					ADC_SOURCE_AVCC


#define ADC_INTERRUPT_STATUS			ADC_DISABLE



#endif /* ADC_CONFIG_H_ */