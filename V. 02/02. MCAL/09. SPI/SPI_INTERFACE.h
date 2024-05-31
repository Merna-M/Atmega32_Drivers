/*
 * SPI_INTERFACE.h
 *
 * Created: 10/30/2023 9:48:11 AM
 *  Author: MERNA
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


/************************************** Includes *********************************/
#include "../../UTIL/BIT_MATH.h"
#include "../../UTIL/STD_TYPES.h"
#include "../DIO/DIO_INTERFACE.h"

#define SPI_MASTER					1
#define SPI_SLAVE					2

#define SPI_PRESCALAR_4				1
#define SPI_PRESCALAR_16			2
#define SPI_PRESCALAR_64			3
#define SPI_PRESCALAR_128			4
#define SPI_PRESCALAR_2				5
#define SPI_PRESCALAR_8				6
#define SPI_PRESCALAR_32			7
#define SPI_PRESCALAR_64			8

#define SPI_LSB_ORDER				1
#define SPI_MSB_ORDER				2

#define SPI_ACTIVE_SYNCH			1
#define SPI_ACTIVE_ASYNCH			2
/************************************** Prototypes ********************************/
void SPI_vInit(void);

u8 SPI_vTransceiver(u8 Copy_u8TxData);

void SPI_vTransmitAsynchronous(u8 Copy_u8TxData,void(*ptr)(u8 Copy_u8RxData));


#endif /* SPI_INTERFACE_H_ */