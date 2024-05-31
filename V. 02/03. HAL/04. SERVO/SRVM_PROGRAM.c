/*
 * SRVM_PROGRAM.c
 *
 * Created: 10/30/2023 11:14:53 PM
 *  Author: MERNA
 */ 

/* UTILES_LIB */
#include "../../UTIL/STD_TYPES.h"
#include "../../UTIL/BIT_MATH.h"

/* MCAL */
#include "../../MCAL/TMR1/TMR1_INTERFACE.h"

void SRVM_voidInit(void)
{
	/* Initialize TMR1 at PWM mode 14 */
	TMR1_vInit();
	/* Set PWM frequency = 50 */
	TMR1_vSetFrequency_Mode14(50);
}

void SRVM_voidOn(u8 Copy_u8Angle)
{
	f32 LOC_DutyCycle = ((Copy_u8Angle*5.0)/180)+5;
	/* Set PWM duty cycle between 5 : 10
	 depend on desired angle[0 : 180] */
	TMR1_vSetDutyCycle_Mode14(LOC_DutyCycle);
	/* TMR1 start */
	TMR1_vStart();
}


void SRVM_voidOff(void)
{
	/* TMR1 stop */
	TMR1_vStop();
}