
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/* ################################### Macros ############################## */
// UCSRA register
#define MPCM		0		// Multi-processor Communication Mode
#define U2X			1		// Double the USART Transmission Speed
#define PE			2		// Parity Error
#define DOR			3		// Data OverRun
#define FE			4		// Frame Error
#define UDRE		5		// USART Data Register Empty
#define TXC			6		// USART Transmit Complete
#define RXC			7		// USART Receive Complete

// UCSRB register
#define TXB8		0		// Transmit Data Bit 8
#define RXB8		1		// Receive Data Bit 8
#define UCSZ2		2		// Character Size (the 3rd bit rest in UCSRC)
#define TXEN		3		// Transmitter Enable
#define RXEN		4		// Receiver Enable
#define UDRIE		5		// USART Data Register Empty Interrupt Enable
#define TXCIE		6		// TX Complete Interrupt Enable
#define RXCIE		7		// RX Complete Interrupt Enable

//UCSRC register
#define UCPOL		0		// Clock Polarity
#define UCSZ0		1		// Character Size
#define UCSZ1		2
#define USBS		3		// Stop Bit Select
#define UPM0		4		// Parity Mode
#define UPM1		5		
#define UMSEL		6		// USART Mode Select
#define URSEL		7		// register select

#define F_CPU		8000000UL

/* ################################## Includes ############################## */
#include "STD_types.h"
#include "BIT_math.h"
#include "UART_private.h"
#include "UART_config.h"


/* ################################# prototypes ############################# */
/*
FUNCTION NAME        : UART_vInit
FUNCTION DESCRIPTION : initializes the UART
FUNCTION INPUT       : void
FUNCTION OUTPUT      : void
*/
void UART_vInit(void);

/*
FUNCTION NAME        : UART_vSendData
FUNCTION DESCRIPTION : sends the data through UART to the receiver
FUNCTION INPUT       : Copy_u8Data: data to be sent
FUNCTION OUTPUT      : void
*/
void UART_vSendData(uint8 Copy_u8Data);

/*
FUNCTION NAME        : UART_u8ReceiveData
FUNCTION DESCRIPTION : receives data from another device
FUNCTION INPUT       : void
FUNCTION OUTPUT      : returns the received data
*/
uint8 UART_u8ReceiveData(void);

/*
FUNCTION NAME        : UART_vSendString
FUNCTION DESCRIPTION : sends a whole string to a device
FUNCTION INPUT       : Copy_u8StringPointer: pointer to the first character of the string
FUNCTION OUTPUT      : void
*/
void UART_vSendString(uint8* Copy_u8StringPointer);


#endif 