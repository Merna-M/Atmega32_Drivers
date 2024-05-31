/*
 * EXEEPROM_INTERFACE.h
 *
 * Created: 10/31/2023 2:23:10 PM
 *  Author: MERNA
 */ 


#ifndef EXEEPROM_INTERFACE_H_
#define EXEEPROM_INTERFACE_H_

/************************************** Includes ****************************************/
#include "../../UTIL/BIT_MATH.h"
#include "../../UTIL/STD_TYPES.h"

#include "../../MCAL/I2C/I2C_INTERFACE.h"

#define F_CPU		16000000UL
#include "util/delay.h"

/************************************** Prototypes **************************************/
void EXEEPROM_vWriteByte(u16 Copy_u16WordAddress,u8 Copy_u8Data);

void EXEEPROM_vReadByte(u16 Copy_u16WordAddress, u8* Copy_pu8RxData);

void EXEEPROM_vWritePage(u16 Copy_u16WordAddress, u8* Copy_pu8Data, u8 Copy_u8SizeData);

void EXEEPROM_vReadSequence(u16 Copy_u16WordAddress, u8* Copy_pu8RxData,u8 Copy_u8Size);

#endif /* EXEEPROM_INTERFACE_H_ */