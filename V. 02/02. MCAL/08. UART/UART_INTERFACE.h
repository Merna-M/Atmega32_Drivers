/*
 * UART_INTERFACE.h
 *
 * Created: 10/28/2023 1:14:39 PM
 *  Author: MERNA
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/*************************************** Includes ************************************/
#include "../../UTIL/BIT_MATH.h"
#include "../../UTIL/STD_TYPES.h"
#include "../DIO/DIO_INTERFACE.h"
#include "../PORT/PORT_INTERFACE.h"


#define UART_ENABLE				1
#define UART_DISABLE			2

#define UART_CHAR_SIZE_5				1
#define UART_CHAR_SIZE_6				2
#define UART_CHAR_SIZE_7				3
#define UART_CHAR_SIZE_8				4
#define UART_CHAR_SIZE_9				5

#define F_CPU							8000000UL
/*************************************** Prototypes *************************************/
void UART_vInit(void);

void UART_vSendData(u8 Copy_u8Data);

u8 UART_u8ReceiveData(void);

void UART_vSendString(u8* ptr_u8String);

void UART_vSetCallBack(void(*ptr)(u8 Copy_u8RxData));

#endif /* UART_INTERFACE_H_ */