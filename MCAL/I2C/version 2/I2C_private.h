#ifndef _I2C_PRIVATE_H
#define _I2C_PRIVATE_H


/* TWI Control register */
#define TWCR			*((volatile uint8*)(0x56))

/* TWI Data register */
#define TWDR			*((volatile uint8*)(0x23))

/* TWI Address register */
#define TWAR			*((volatile uint8*)(0x22))

/* TWI Status register */
#define TWSR			*((volatile uint8*)(0x21))

/* TWI Bit rate register */
#define TWBR			*((volatile uint8*)(0x20))

#endif