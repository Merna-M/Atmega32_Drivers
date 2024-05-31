/*
 * TMR2_INTERFACE.h
 *
 * Created: 10/29/2023 8:15:14 PM
 *  Author: MERNA
 */ 


#ifndef TMR2_INTERFACE_H_
#define TMR2_INTERFACE_H_


/************************************* Includes *********************************************/
#include "../../UTIL/BIT_MATH.h"
#include "../../UTIL/STD_TYPES.h"

#include "../DIO/DIO_INTERFACE.h"
#include "../PORT/PORT_INTERFACE.h"

/************************************ Prototypes **********************************************/
void TMR2_vInit(void);

void TMR2_vStart(void);

void TMR2_vStop(void);

void TMR2_vSetDelay_ms_UsingCTC(u16 Copy_u16Delay_ms);

void TMR2_vSetDutyCycle_PWM(u8 Copy_u8DutyCycle);

void TMR2_vSetCallBack_OVF(void (*ptr)(void));

void TMR2_vSetCallBack_COMP(void (*ptr)(void));

#endif /* TMR2_INTERFACE_H_ */