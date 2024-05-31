/*
 * TMR1_PROGRAM.c
 *
 * Created: 10/29/2023 10:40:08 AM
 *  Author: MERNA
 */ 

#include "TMR1_INTERFACE.h"
#include "TMR1_REGISTER.h"
#include "TMR1_PRIVATE.h"
#include "TMR1_CONFIG.h"

void (*Priv_SetCallBack_CAPT) (void) = NULL;
void (*Priv_SetCallBack_COMPA)(void) = NULL;
void (*Priv_SetCallBack_COMPB)(void) = NULL;
void (*Priv_SetCallBack_OVF)  (void) = NULL;

volatile static u16 Priv_u16Ton;
volatile static u16 Priv_u16Toff;

volatile static u8 priv_flag = 0;

/***************************************************************************************************************************/
void TMR1_vInit(void)
{
	/***************************** Mode 00 *******************************/
	#if TMR1_MODE == TMR1_NORMAL_MODE
	
	//set normal mode WGM13:0 = 0000
	CLR_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	//set the noise canceler of ICU
	SET_BIT(TCCR1B,ICNC1);
	
	/***************************** Mode 01 *******************************/
	#elif TMR1_MODE == TMR1_PWM_PHASE_CORRECT_8_BIT
	//set PWM, Phase Correct, 8-bit, WGM13:0 = 0001
	CLR_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1A,WGM10);
	
	/***************************** Mode 02 *******************************/
	#elif TMR1_MODE == TMR1_PWM_PHASE_CORRECT_9_BIT
	//set PWM, Phase Correct, 9-bit WGM13:0 = 0010
	CLR_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	
	/***************************** Mode 03 *******************************/
	#elif TMR1_MODE == TMR1_PWM_PHASE_CORRECT_10_BIT
	//set PWM, Phase Correct, 10-bit WGM13:0 = 0011
	CLR_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	
	/***************************** Mode 04 *******************************/
	#elif TMR1_MODE == TMR1_CTC_OCR1A
	//set CTC mode (top = OCR1A) WGM13:0 = 0100
	CLR_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	
	/***************************** Mode 05 *******************************/
	#elif TMR1_MODE == TMR1_PWM_FAST_8_BIT
	//set Fast PWM, 8-bit, WGM13:0 = 0101
	CLR_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1A,WGM10);
	
	/***************************** Mode 06 *******************************/
	#elif TMR1_MODE == TMR1_PWM_FAST_9_BIT
	//set Fast PWM, 9-bit WGM13:0 = 0110
	CLR_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	
	/***************************** Mode 07 *******************************/
	#elif TMR1_MODE == TMR1_PWM_FAST_10_BIT
	//set Fast PWM, 10-bit WGM13:0 = 0111
	CLR_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1A,WGM10);
	
	/***************************** Mode 08 *******************************/
	#elif TMR1_MODE == TMR1_PWM_PHASE_FREQ_ICR1
	//set PWM, Phase and Frequency Correct (top = ICR1) WGM13:0 = 1000
	SET_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	
	/***************************** Mode 09 *******************************/
	#elif TMR1_MODE == TMR1_PWM_PHASE_FREQ_OCR1A
	//set PWM, Phase and Frequency Correct (top = OCR1A) WGM13:0 = 1001
	SET_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1A,WGM10);
	
	/***************************** Mode 10 *******************************/
	#elif TMR1_MODE == TMR1_PWM_PHASE_ICR1
	//set PWM, Phase Correct (top=ICR1) WGM13:0 = 1010
	SET_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	
	/***************************** Mode 11 *******************************/
	#elif TMR1_MODE == TMR1_PWM_PHASE_OCR1A
	//set PWM, Phase Correct (top=OCR1A)  WGM13:0 = 1011
	SET_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1A,WGM10);
	
	/***************************** Mode 12 *******************************/
	#elif TMR1_MODE == TMR1_CTC_ICR1
	//set CTC mode (top = ICR1) WGM13:0 = 1100
	SET_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	
	/***************************** Mode 14 *******************************/
	#elif TMR1_MODE == TMR1_FAST_PWM_ICR1
	//set Fast PWM (top = ICR1) WGM13:0 = 1110
	SET_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	
	#if TMR1_PWM_MODE == TMR1_PWM_INVERTING
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	
	#elif TMR1_PWM_MODE == TMR1_PWM_NONINVERTING
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#endif
	
	// Set OC1A Pin as output
	Port_ConfigType LOC_conf = {Dio_PORTD,DIO_Pin5,PORT_PIN_OUT};
	PORT_InsertConf(&LOC_conf,1);
	/***************************** Mode 15 *******************************/
	#elif TMR1_MODE == TMR1_FASR_PWM_OCR1A
	//set Fast PWM (top = OCR1A) WGM13:0 = 1111
	SET_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1A,WGM10);

	
	#endif
}

/***************************************************************************************************************************/
void TMR1_vStart(void)
{
	#if TMR1_PRESCALAR_SEL == TMR1_PRESCALAR_1
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	
	#elif TMR1_PRESCALAR_SEL == TMR1_PRESCALAR_8
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	
	#elif TMR1_PRESCALAR_SEL == TMR1_PRESCALAR_64
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	
	#elif TMR1_PRESCALAR_SEL == TMR1_PRESCALAR_256
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
	
	#elif TMR1_PRESCALAR_SEL == TMR1_PRESCALAR_1024
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
	
	#endif
}

/***************************************************************************************************************************/
void TMR1_vStop(void)
{
	TCCR1B &= ~(0x07);
}

/***************************************************************************************************************************/

void TMR1_vSetCompareMatchValue_A(u16 Copy_u16CompValueA)
{
	OCR1A = Copy_u16CompValueA;
}


/***************************************************************************************************************************/
/*************************************************** Servo Functions *******************************************************/
/***************************************************************************************************************************/
/*
FUNCTION   : TMR1_vSetFrequency_Mode14
DESCRIPTION: Sets the top value (ICR1) according to the input frequency
*/
/***************************************************************************************************************************/
void TMR1_vSetFrequency_Mode14(u16 Copy_u16Frequency)
{
	//under condition -> tick time = 1 usec. (F_CPU = 8MHz + Prescalar = 8)
	ICR1 = (1000000ul/(1*Copy_u16Frequency))-1;
}

/***************************************************************************************************************************/
/*
FUNCTION   : TMR1_vSetDutyCycle_Mode14
DESCRIPTION: Sets the Compare value (OCR1A) according to the input Duty cycle
*/
/***************************************************************************************************************************/
void TMR1_vSetDutyCycle_Mode14(f32 Copy_f32Duty)
{
	if(Copy_f32Duty <= 100)
	{
		#if TMR1_PWM_MODE == TMR1_PWM_INVERTING
		Copy_f32Duty = 100 - Copy_f32Duty;
		OCR1A = ((Copy_f32Duty*(ICR1+1))/100)-1;
		
		#elif TMR1_PWM_MODE == TMR1_PWM_NONINVERTING
		OCR1A = ((Copy_f32Duty*(ICR1+1))/100)-1;
		
		#endif
		
	}
}
/***************************************************************************************************************************/
/***************************************************** ICU Functions *******************************************************/
/***************************************************************************************************************************/
/*
FUNCTION   : TMR1_vIcuInit
DESCRIPTION: Initializes ICU
*/
/***************************************************************************************************************************/
void TMR1_vIcuInit(void)
{
	//Select Falling Edge as Initial Condition
	CLR_BIT(TCCR1B,ICES1);
	
	//Enable ICU Interrupt
	SET_BIT(TIMSK,TICIE1);
}
/***************************************************************************************************************************/
/*
FUNCTION   : TMR1_vIcuGetDutyCycle
DESCRIPTION: Returns Duty cycle of captured signal
*/
/***************************************************************************************************************************/
u8 TMR1_vIcuGetDutyCycle(void)
{
	u8 LOC_u8Duty;
	LOC_u8Duty = ((u32)Priv_u16Ton*100)/(Priv_u16Ton+Priv_u16Toff);
	return LOC_u8Duty;
}

/***************************************************************************************************************************/
/*
FUNCTION   : TMR1_vIcuGetFrequency
DESCRIPTION: Returns frequency of captured signal
*/
/***************************************************************************************************************************/
u32 TMR1_vIcuGetFrequency(void)
{
	u32 LOC_u32Frequency;
	LOC_u32Frequency = 1000000UL/(Priv_u16Toff+Priv_u16Ton);
	return LOC_u32Frequency;
}

/***************************************************************************************************************************/
/*
FUNCTION   : TMR1_u16IcuGetTon
DESCRIPTION: Returns Ton in Micro seconds (Time when the signal is HIGH)
*/
/***************************************************************************************************************************/
u16 TMR1_u16IcuGetTon(void)
{
	while(priv_flag != 2);  // Wait to get the reading of Ton
	priv_flag = 0;
	return Priv_u16Ton;
}


/***************************************************************************************************************************/
/*********************************************** Call Back Functions *******************************************************/
/***************************************************************************************************************************/
/*
FUNCTION   : TMR1_vSetCallBack_CAPT
DESCRIPTION: ptr to Function that occurs when a capture event occurs (Rising or Falling)
*/
/***************************************************************************************************************************/
void TMR1_vSetCallBack_CAPT(void (*ptr)(void))
{
	Priv_SetCallBack_CAPT = ptr;
}

/***************************************************************************************************************************/
/*
FUNCTION   : TMR1_vSetCallBack_COMPA
DESCRIPTION: ptr to Function that occurs when the counter reaches the value of OCR1A
*/
/***************************************************************************************************************************/
void TMR1_vSetCallBack_COMPA(void (*ptr)(void))
{
	Priv_SetCallBack_COMPA = ptr;
}

/***************************************************************************************************************************/
/*
FUNCTION   : TMR1_vSetCallBack_COMPB
DESCRIPTION: ptr to Function that occurs when the counter reaches the value of OCR1B
*/
/***************************************************************************************************************************/
void TMR1_vSetCallBack_COMPB(void (*ptr)(void))
{
	Priv_SetCallBack_COMPB = ptr;
}

/***************************************************************************************************************************/
/*
FUNCTION   : TMR1_vSetCallBack_OVF
DESCRIPTION: ptr to Function that occurs when the counter reaches zero (Overflow)
*/
/***************************************************************************************************************************/
void TMR1_vSetCallBack_OVF(void (*ptr)(void))
{
	Priv_SetCallBack_OVF = ptr;
}

/***************************************************************************************************************************/
/******************************************** Interrupt Service Routine  ***************************************************/
/***************************************************************************************************************************/
void __vector_6()__attribute__((signal));
void __vector_6()
{
	static u8 Local_u16EdgeCounter = 0;
	Local_u16EdgeCounter++;
	static u16 Local_u16ldValue = 0;
	switch(Local_u16EdgeCounter)
	{
		case 1: //Dummy
		// Select Rising Edge
		SET_BIT(TCCR1B,ICES1);
		Local_u16ldValue = ICR1;
		break;
		
		case 2:
		Priv_u16Toff = (ICR1 - Local_u16ldValue); //tick time 1 usec.
		priv_flag = 1;
		Local_u16ldValue = ICR1;
		// Select Falling Edge
		CLR_BIT(TCCR1B,ICES1);
		
		break;
		
		case 3:
		Priv_u16Ton = (ICR1 - Local_u16ldValue); //tick time 1 usec.
		priv_flag = 2;
		// Select Rising Edge
		SET_BIT(TCCR1B,ICES1);
		Local_u16ldValue = ICR1;
		Local_u16EdgeCounter = 1;
		break;
	}		
}
/***********************************************************************************************************************/
void __vector_7()__attribute__((signal));
void __vector_7()
{
	if(Priv_SetCallBack_COMPA != NULL)
	{
		Priv_SetCallBack_COMPA();
	}
}
/***********************************************************************************************************************/
void __vector_8()__attribute__((signal));
void __vector_8()
{
	if(Priv_SetCallBack_COMPB != NULL)
	{
		Priv_SetCallBack_COMPB();
	}
}
/***********************************************************************************************************************/
void __vector_9()__attribute__((signal));
void __vector_9()
{
	if(Priv_SetCallBack_OVF != NULL)
	{
		Priv_SetCallBack_OVF();
	}
}
/***********************************************************************************************************************/