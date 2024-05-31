/*
 * TMR1_CONFIG.h
 *
 * Created: 10/29/2023 10:42:11 AM
 *  Author: MERNA
 */ 


#ifndef TMR1_CONFIG_H_
#define TMR1_CONFIG_H_

/* Choose Timer1 Mode */
/*
Options:
01. TMR1_NORMAL_MODE
02. TMR1_PWM_PHASE_CORRECT_8_BIT
03. TMR1_PWM_PHASE_CORRECT_9_BIT
04. TMR1_PWM_PHASE_CORRECT_10_BIT
05. TMR1_CTC_OCR1A
06. TMR1_PWM_FAST_8_BIT
07. TMR1_PWM_FAST_9_BIT
08. TMR1_PWM_FAST_10_BIT
09. TMR1_PWM_PHASE_FREQ_ICR1
10. TMR1_PWM_PHASE_FREQ_OCR1A
11. TMR1_PWM_PHASE_ICR1
12. TMR1_PWM_PHASE_OCR1A
13. TMR1_CTC_ICR1
14. TMR1_FAST_PWM_ICR1
15. TMR1_FASR_PWM_OCR1A
*/
#define TMR1_MODE				TMR1_NORMAL_MODE

/* Choose PWM Mode
Options:
1. TMR1_PWM_INVERTING
2. TMR1_PWM_NONINVERTING
*/
#define TMR1_PWM_MODE			TMR1_PWM_NONINVERTING

/* Prescalar Choose
Options:
1. TMR1_PRESCALAR_1							
2. TMR1_PRESCALAR_8							
3. TMR1_PRESCALAR_64							
4. TMR1_PRESCALAR_256							
5. TMR1_PRESCALAR_1024							
*/
#define TMR1_PRESCALAR_SEL			TMR1_PRESCALAR_8

#endif /* TMR1_CONFIG_H_ */