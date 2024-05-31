#include "UART_interface.h"

void UART_vInit(void)
{
	uint16 LOC_UBRRvalue=0,LOC_UCSRCvalue=0;
	LOC_UBRRvalue = (F_CPU/(16ul*UART_BAUD_RATE))-1;
	UBRRH = (uint8)LOC_UBRRvalue>>8;
	UBRRL = (uint8)LOC_UBRRvalue;
	
	//enable transmitter and receiver
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	/*options for ucsrc register:*/
	
	//select the UCSRC register
	SET_BIT(LOC_UCSRCvalue,URSEL);
	//8-bit data
	SET_BIT(LOC_UCSRCvalue,UCSZ0);
	SET_BIT(LOC_UCSRCvalue,UCSZ1);
	
	UCSRC = LOC_UCSRCvalue;
}

void UART_vSendData(uint8 Copy_u8Data)
{
	//wait till the UDR register is ready to transmit
	while(READ_BIT(UCSRA,UDRE)==0);
	//put the data in the UDR register
	UDR=Copy_u8Data;
}

uint8 UART_u8ReceiveData(void)
{
	//wait for the receive to be completed
	while(READ_BIT(UCSRA,RXC)==0);
	//return the received value
	return UDR;
}

void UART_vSendString(uint8* Copy_u8StringPointer)
{
	while(*Copy_u8StringPointer != '\0')
	{
		UART_vSendData(*Copy_u8StringPointer);
		Copy_u8StringPointer++;
	}
}