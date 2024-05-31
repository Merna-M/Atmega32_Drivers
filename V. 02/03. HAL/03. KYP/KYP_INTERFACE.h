/*
 * KYP_INTERFACE.h
 *
 * Created: 10/27/2023 10:06:20 AM
 *  Author: MERNA
 */ 


#ifndef KYP_INTERFACE_H_
#define KYP_INTERFACE_H_


/****************************************** Includes *********************************************/
#include "../../UTIL/BIT_MATH.h"
#include "../../UTIL/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "../../MCAL/PORT/PORT_INTERFACE.h"


/****************************************** Macros *********************************************/
#define KYP_NOT_PRESSED				(0xFF)

void KYP_vInit(void);

u8 KYP_u8GetPressedKey(void);

#endif /* KYP_INTERFACE_H_ */