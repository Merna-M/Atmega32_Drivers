/*
 * UART_REGISTER.h
 *
 * Created: 10/28/2023 1:14:58 PM
 *  Author: MERNA
 */ 


#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_



//USART data register
#define	UDR		*((volatile u8*)(0x2C))
#define UCSRA	*((volatile u8*)(0x2B))
#define UCSRB	*((volatile u8*)(0x2A))
#define UCSRC	*((volatile u8*)(0x40))
#define UBRRL	*((volatile u8*)(0x29))
#define UBRRH	*((volatile u8*)(0x40))


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



#endif /* UART_REGISTER_H_ */