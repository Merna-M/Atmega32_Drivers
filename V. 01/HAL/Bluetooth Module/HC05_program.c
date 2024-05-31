#include "HC05_interface.h"



void HC05_vInit(void)
{
	UART_vInit();
}

void HC05_vSendData(uint8 *Copy_u8Data)
{
	UART_vSendString(Copy_u8Data);
}

uint8 HC05_u8ReceiveData(void)
{
	uint8 return_data;
	return_data = UART_u8ReceiveData();
	return return_data;
}