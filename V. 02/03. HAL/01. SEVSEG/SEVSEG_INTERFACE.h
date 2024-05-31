/*
 * SEVSEG.h
 *
 * Created: 10/21/2023 10:10:53 AM
 *  Author: MERNA
 */ 


#ifndef SEVSEG_H_
#define SEVSEG_H_

/*************************************** Includes ************************************/
#include "../../UTIL/STD_TYPES.h"
#include "../../UTIL/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"

/*************************************************************************************/
	
void SEVSEG_vWrite(u8 Copy_u8Number , Dio_ChannelType* Pins , Dio_PortType* Port);

void SEVSEG_vInit(Dio_ChannelType* Pins , Dio_PortType* Port);

/*************************************************************************************/

#endif /* SEVSEG_H_ */