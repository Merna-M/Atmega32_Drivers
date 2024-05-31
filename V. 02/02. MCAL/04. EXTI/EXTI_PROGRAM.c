/*
 * EXTI.c
 *
 * Created: 10/22/2023 1:40:49 PM
 *  Author: MERNA
 */ 

#include "EXTI_INTERFACE.h"
#include "EXTI_REGISTER.h"
/********************************************************************************/

/* Global pointer to function */
static void (*priv_pCallBack_EXT0)(void) = NULL;
static void (*priv_pCallBack_EXT1)(void) = NULL;
static void (*priv_pCallBack_EXT2)(void) = NULL;

void EXTI_vInit(u8 Copy_u8IntSource,u8 Copy_u8SenseControl)
{
	/* Validation (default is Rising edge) */
	if(Copy_u8SenseControl > 3)
	{
		Copy_u8SenseControl = EXTI_RISING_EDGE;
	}
	
	switch(Copy_u8IntSource)
	{
		case EXTI_SOURCE_0:
			MCUCR &= ~(0b11 << ISC00);     // clear ISC00 and ISC01
			MCUCR |= Copy_u8SenseControl;  
			break;
			
		case EXTI_SOURCE_1:
			MCUCR &= ~(0b11 << ISC10);     // clear ISC10 and ISC11
			MCUCR |= Copy_u8SenseControl;
			break;
			
		case EXTI_SOURCE_2:
			if(Copy_u8SenseControl == EXTI_FALLING_EDGE)
			{
				CLR_BIT(MCUCSR,ISC2);
			}
			else // Default
			{
				SET_BIT(MCUCSR,ISC2);
			}
			break;
			
		default:
			break;
	}
}

/********************************************************************************/
void EXTI_vEnable(u8 Copy_u8IntSource)
{
	switch (Copy_u8IntSource)
	{
		case EXTI_SOURCE_0:
			SET_BIT(GICR,INT0);
			break;
			
		case EXTI_SOURCE_1:
			SET_BIT(GICR,INT1);
			break;
		
		case EXTI_SOURCE_2:
			SET_BIT(GICR,INT2);
			break;
		
		default:
			break;
	}
}

/********************************************************************************/
void EXTI_vDisable(u8 Copy_u8IntSource)
{
	switch (Copy_u8IntSource)
	{
		case EXTI_SOURCE_0:
			CLR_BIT(GICR,INT0);
			break;
		
		case EXTI_SOURCE_1:
			CLR_BIT(GICR,INT1);
			break;
		
		case EXTI_SOURCE_2:
			CLR_BIT(GICR,INT2);
			break;
		
		default:
			break;
	}
}
/********************************************************************************/
void EXTI_vSetCallBack_INT0(void (*ptr)(void))
{
	priv_pCallBack_EXT0 = ptr;
}

/********************************************************************************/
void EXTI_vSetCallBack_INT1(void (*ptr)(void))
{
	priv_pCallBack_EXT1 = ptr;
}

/********************************************************************************/
void EXTI_vSetCallBack_INT2(void (*ptr)(void))
{
	priv_pCallBack_EXT2 = ptr;
}

/********************************************************************************/
//EXTI_0
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(priv_pCallBack_EXT0!=NULL)
	{
		priv_pCallBack_EXT0();
	}
}

/********************************************************************************/
//EXTI_1
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(priv_pCallBack_EXT1!=NULL)
	{
		priv_pCallBack_EXT1();
	}
}

/********************************************************************************/
//EXTI_2
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(priv_pCallBack_EXT2!=NULL)
	{
		priv_pCallBack_EXT2();
	}
}

/********************************************************************************/