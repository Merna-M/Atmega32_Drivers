/*
 * TMR2_PROGRAM.c
 *
 * Created: 10/29/2023 8:14:36 PM
 *  Author: MERNA
 */ 

#include "TMR2_INTERFACE.h"
#include "TMR2_REGISTER.h"
#include "TMR2_PRIVATE.h"
#include "TMR2_CONFIG.h"


static void (*Priv_vSetCallBack_OVF) (void) = NULL;
static void (*Priv_vSetCallBack_COMP)(void) = NULL;

volatile static u16 Priv_CtcCounter;

/******************************************************************************************/
void TMR2_vInit(void)
{
	/******************* Normal Mode *******************/
	#if TMR2_MODE == TMR2_NORMAL_MODE
	// Set Normal Mode: WGM21:0 = 00
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	
	// Enable Overflow Interrupt
	SET_BIT(TIMSK,TOIE2);
	
	
	/******************* CTC Mode *******************/
	#elif TMR2_MODE == TMR2_CTC_MODE
	// Set CTC Mode: WGM21:0 = 10
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	
	// Enable Compare Match Interrupt
	SET_BIT(TIMSK,OCIE2);
	
	
	/******************* Fast PWM Mode *******************/
	
	#elif TMR2_MODE == TMR2_FAST_PWM_MODE
	// Set OC2 Pin as output
	Port_ConfigType LOC_conf = {Dio_PORTD,DIO_Pin7,PORT_PIN_OUT};
	PORT_InsertConf(&LOC_conf,1);
	Port_Init();
	
	// Set Fast PWM Mode: WGM21:0 = 11
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	
	//Set OC2 on compare match, clear OC2 at BOTTOM
	#if TMR2_PWM_MODE == TMR2_PWM_INVERTING
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	
	//Clear OC2 on compare match, set OC0 at BOTTOM
	#elif TMR2_PWM_MODE == TMR2_PWM_NONINVERTING
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	
	#endif
	
	
	/******************* PWM, Phase Correct Mode *******************/
	
	#elif TMR2_MODE == TMR2_PHASE_CORRECT_MODE
	// Set OC2 Pin as output
	Port_ConfigType LOC_conf = {Dio_PORTD,DIO_Pin7,PORT_PIN_OUT};
	PORT_InsertConf(&LOC_conf,1);
	Port_Init();
	
	// Set Phase Correct Mode: WGM21:0 = 01
	SET_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	
	//Set OC2 on compare match when up-counting. Clear OC2 on compare match when down-counting
	#if TMR2_PWM_MODE == TMR2_PWM_INVERTING
	SET_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	
	//Clear OC2 on compare match when up-counting. Set OC2 on compare match when down-counting.
	#elif TMR2_PWM_MODE == TMR2_PWM_NONINVERTING
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	
	#endif
	/*****************************************/
	#endif
}
/*************************************************************************************************/

void TMR2_vStart(void)
{
	#if TMR2_PRESCALAR == TMR2_PRESCALAR_1
	SET_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
	
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_8
	CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
	
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_32
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
	
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_64
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_128
	SET_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_256
	CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_1024
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
	#endif
}
/*************************************************************************************************/

void TMR2_vStop(void)
{
	//CS22:0 = 000, No clock source (Timer/Counter stopped).
	TCCR2 &= ~(0x07);
}
/*************************************************************************************************/

void TMR2_vSetDelay_ms_UsingCTC(u16 Copy_u16Delay_ms)
{
	#if TMR2_PRESCALAR == TMR2_PRESCALAR_1
	//under condition -> tick time = 0.125 uSec.
	OCR2 = 249 ;
	Priv_CtcCounter = Copy_u16Delay_ms*32;
	
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_8
	//under condition -> tick time = 1 uSec.
	OCR2 = 249 ;
	Priv_CtcCounter = Copy_u16Delay_ms*4;
	
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_32
	//under condition -> tick time = 4 uSec.
	OCR2 = 249 ;
	Priv_CtcCounter = Copy_u16Delay_ms;
	
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_64
	//under condition -> tick time = 8 uSec.
	OCR2 = 124 ;
	Priv_CtcCounter = Copy_u16Delay_ms;
	
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_128
	//OCR2 = 62;
	//Priv_CtcCounter = Copy_u16Delay_ms;
	
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_256
							   
	#elif TMR2_PRESCALAR == TMR2_PRESCALAR_1024
	
	#endif
	
	
}
/*************************************************************************************************/

void TMR2_vSetDutyCycle_PWM(u8 Copy_u8DutyCycle)
{
	if(Copy_u8DutyCycle <= 100)
	{
		// Fast PWM Mode
		#if TMR2_MODE == TMR2_FAST_PWM_MODE
		
		//Inverting mode, Set OC2 on compare match, clear OC2 at BOTTOM
		#if TMR2_PWM_MODE == TMR2_PWM_INVERTING
		Copy_u8DutyCycle = 100 - Copy_u8DutyCycle;
		OCR2 = ((u16)(Copy_u8DutyCycle*256)/100)-1;
		
		//Non Inverting mode, Clear OC2 on compare match, set OC2 at BOTTOM
		#elif TMR2_PWM_MODE == TMR2_PWM_NONINVERTING
		OCR2 = ((u16)(Copy_u8DutyCycle*256)/100)-1;
		
		#endif
		
		// Phase Correct Mode
		#elif TMR2_MODE == TMR2_PHASE_CORRECT_MODE
		
		//Inverting Mode, Set OC2 on compare match when up-counting. Clear OC2 on compare match when down-counting.

		#if TMR2_PWM_MODE == TMR2_PWM_INVERTING
		Copy_u8DutyCycle = 100 - Copy_u8DutyCycle;
		OCR2 = ((u16)(Copy_u8DutyCycle*255)/100);
		
		//Non Inverting Mode, Clear OC2 on compare match when up-counting. Set OC2 on compare match when down-counting.
		#elif TMR2_PWM_MODE == TMR2_PWM_NONINVERTING
		OCR2 = ((u16)(Copy_u8DutyCycle*255)/100);
		
		#endif
		
		#endif
	}
}
/*************************************************************************************************/

void TMR2_vSetCallBack_OVF(void (*ptr)(void))
{
	Priv_vSetCallBack_OVF = ptr;
}
/*************************************************************************************************/

void TMR2_vSetCallBack_COMP(void (*ptr)(void))
{
	Priv_vSetCallBack_COMP = ptr;
}
/*************************************************************************************************/

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	static u16 Local_u16OVFCounter = 0;
	Local_u16OVFCounter++;
	if(Local_u16OVFCounter == TMR2_OVF_COUNTER)
	{
		TCNT2 = TMR2_PRELOAD_VALUE;
		Local_u16OVFCounter = 0;
		if(Priv_vSetCallBack_OVF != NULL)
		{
			Priv_vSetCallBack_OVF();	//call the action
		}
	}
}

/*************************************************************************************************/
void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	static u16 Local_u16COMPCounter = 0;
	Local_u16COMPCounter++;
	if(Local_u16COMPCounter == Priv_CtcCounter)
	{
		Local_u16COMPCounter = 0;
		if(Priv_vSetCallBack_COMP != NULL)
		{
			Priv_vSetCallBack_COMP();	//call the action
		}
	}
}

/*************************************************************************************************/
