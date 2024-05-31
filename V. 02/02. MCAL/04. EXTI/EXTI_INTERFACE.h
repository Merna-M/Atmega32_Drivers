/*
 * EXTI.h
 *
 * Created: 10/22/2023 1:41:08 PM
 *  Author: MERNA
 */ 


#ifndef EXTI_H_
#define EXTI_H_



/********************************** Includes *******************************/
#include "../../UTIL/STD_TYPES.h"
#include "../../UTIL/BIT_MATH.h"


/********************************* Macros ***********************************/

/** Define Interrupt Sources **/
#define EXTI_SOURCE_0			0
#define EXTI_SOURCE_1			1
#define EXTI_SOURCE_2			2


/** Define Sense Control Modes **/
#define EXTI_LOW_LEVEL			0
#define EXTI_ANY_CHANGE			1
#define EXTI_FALLING_EDGE		2
#define EXTI_RISING_EDGE		3


/********************************** Prototypes *******************************/

void EXTI_vInit(u8 Copy_u8IntSource,u8 Copy_u8SenseControl);

void EXTI_vEnable(u8 Copy_u8IntSource);

void EXTI_vDisable(u8 Copy_u8IntSource);

void EXTI_vSetCallBack_INT0(void (*ptr)(void));

void EXTI_vSetCallBack_INT1(void (*ptr)(void));

void EXTI_vSetCallBack_INT2(void (*ptr)(void));

#endif /* EXTI_H_ */