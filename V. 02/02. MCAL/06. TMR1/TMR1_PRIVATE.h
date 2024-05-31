/*
 * TMR1_PRIVATE.h
 *
 * Created: 10/29/2023 10:41:36 AM
 *  Author: MERNA
 */ 


#ifndef TMR1_PRIVATE_H_
#define TMR1_PRIVATE_H_

/* Timer1 Modes */
#define TMR1_NORMAL_MODE							0
#define TMR1_PWM_PHASE_CORRECT_8_BIT				1 
#define TMR1_PWM_PHASE_CORRECT_9_BIT				2
#define TMR1_PWM_PHASE_CORRECT_10_BIT				3
#define TMR1_CTC_OCR1A								4
#define TMR1_PWM_FAST_8_BIT							5
#define TMR1_PWM_FAST_9_BIT							6
#define TMR1_PWM_FAST_10_BIT						7
#define TMR1_PWM_PHASE_FREQ_ICR1					8
#define TMR1_PWM_PHASE_FREQ_OCR1A					9
#define TMR1_PWM_PHASE_ICR1							10
#define TMR1_PWM_PHASE_OCR1A						11
#define TMR1_CTC_ICR1								12

#define TMR1_FAST_PWM_ICR1							14
#define TMR1_FASR_PWM_OCR1A							15		


/* PWM Modes */
#define TMR1_PWM_INVERTING							1
#define TMR1_PWM_NONINVERTING						2

/* Prescalar Values */
#define TMR1_PRESCALAR_1							1
#define TMR1_PRESCALAR_8							2
#define TMR1_PRESCALAR_64							3
#define TMR1_PRESCALAR_256							4
#define TMR1_PRESCALAR_1024							5



#endif /* TMR1_PRIVATE_H_ */