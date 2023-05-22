#ifndef _HC05_INTERFACE_H
#define _HC05_INTERFACE_H

/******************************************** Macros ******************************************/



/********************************************* Includes *****************************************/
#include "STD_types.h"
#include "UART_interface.h"



/**********************************************Prototypes ****************************************/

void HC05_vInit(void);

void HC05_vSendData(uint8 *Copy_u8Data);

uint8 HC05_u8ReceiveData(void);

#endif