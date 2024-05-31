/*
 * UART_PROGRAM.c
 *
 * Created: 10/28/2023 1:14:12 PM
 *  Author: MERNA
 */ 

#include "UART_INTERFACE.h"
#include "UART_REGISTER.h"
#include "UART_CONFIG.h"

/*************************************************************************************************/
static void (*Priv_vSetCallBack_UARTRx) (u8) = NULL;
/*************************************************************************************************/

void UART_vInit(void)
{
	u8 LOC_UCSRC = 0;
	u16 LOC_UBRR = (F_CPU/(16ul*UART_BAUD_RATE))-1 ;
	UBRRH = (u8)(LOC_UBRR>>8);
	UBRRL = (u8)LOC_UBRR;
	
	
	#if UART_TX_ENABLE == UART_ENABLE
	SET_BIT(UCSRB,TXEN);
	#endif
	
	#if UART_RX_ENABLE == UART_ENABLE
	SET_BIT(UCSRB,RXEN);
	#endif
	
	#if UART_TX_INTERRUPT == UART_ENABLE
	SET_BIT(UCSRB,TXCIE);
	#endif
	
	#if UART_RX_INTERRUPT == UART_ENABLE
	SET_BIT(UCSRB,RXCIE);
	#endif
	
	SET_BIT(LOC_UCSRC,URSEL);
	#if UART_CHAR_SELECT == UART_CHAR_SIZE_5
	
	#elif UART_CHAR_SELECT == UART_CHAR_SIZE_6
	SET_BIT(LOC_UCSRC,UCSZ0);
	
	#elif UART_CHAR_SELECT == UART_CHAR_SIZE_7
	SET_BIT(LOC_UCSRC,UCSZ1);
	
	#elif UART_CHAR_SELECT == UART_CHAR_SIZE_8
	SET_BIT(LOC_UCSRC,UCSZ0);
	SET_BIT(LOC_UCSRC,UCSZ1);
	
	#elif UART_CHAR_SELECT == UART_CHAR_SIZE_9
	SET_BIT(LOC_UCSRC,UCSZ0);
	SET_BIT(LOC_UCSRC,UCSZ1);
	SET_BIT(UCSRB,UCSZ2);
	
	#endif
	UCSRC = LOC_UCSRC;
	
	//Set TX pin as an output and RX pin as an input
	Dio_ChannelType UART_TX_Pin = PD_1;
	Dio_ChannelType UART_RX_Pin = PD_0;
	Dio_Init(&UART_TX_Pin,1,PORT_PIN_OUT);
	Dio_Init(&UART_RX_Pin,1,PORT_PIN_IN);
	Port_Init();
}
/*************************************************************************************************/

void UART_vSendData(u8 Copy_u8Data)
{
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR = Copy_u8Data;
}
/*************************************************************************************************/

u8 UART_u8ReceiveData(void)
{
	while(GET_BIT(UCSRA,RXC)==0);
	return UDR;
}
/*************************************************************************************************/

void UART_vSendString(u8* ptr_u8String)
{
	while(*ptr_u8String != '\0')
	{
		UART_vSendData(*ptr_u8String);
		ptr_u8String++;
	}
}
/*************************************************************************************************/
void UART_vSetCallBack(void(*ptr)(u8 Copy_u8RxData))
{
	Priv_vSetCallBack_UARTRx = ptr;
}
/*************************************************************************************************/

/* ISR for UART Receiver */
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if(Priv_vSetCallBack_UARTRx != NULL)
	{
		Priv_vSetCallBack_UARTRx(UDR);
	}
}

/*************************************************************************************************/