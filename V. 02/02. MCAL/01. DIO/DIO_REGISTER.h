#ifndef _DIO_REGISTER_H
#define _DIO_REGISTER_H


//macros for IO registers of portA 
#define DDRA		*((volatile u8*)(0x3A))
#define PORTA		*((volatile u8*)(0x3B))
#define PINA		*((volatile u8*)(0x39))

//macros for IO registers of portB 
#define DDRB		*((volatile u8*)(0x37))
#define PORTB		*((volatile u8*)(0x38))
#define PINB		*((volatile u8*)(0x36))

//macros for IO registers of portC
#define DDRC		*((volatile u8*)(0x34))
#define PORTC		*((volatile u8*)(0x35))
#define PINC		*((volatile u8*)(0x33))

//macros for IO registers of portD
#define DDRD		*((volatile u8*)(0x31))
#define PORTD		*((volatile u8*)(0x32))
#define PIND		*((volatile u8*)(0x30))



#endif