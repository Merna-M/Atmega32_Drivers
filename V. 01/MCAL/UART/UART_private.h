
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

//USART data register
#define	UDR		*((volatile uint8*)(0x2C))		
#define UCSRA	*((volatile uint8*)(0x2B))
#define UCSRB	*((volatile uint8*)(0x2A))
#define UCSRC	*((volatile uint8*)(0x40))
#define UBRRL	*((volatile uint8*)(0x29))
#define UBRRH	*((volatile uint8*)(0x40))


#endif 