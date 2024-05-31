/*
 * I2C_REGISTER.h
 *
 * Created: 10/31/2023 10:53:43 AM
 *  Author: MERNA
 */ 


#ifndef I2C_REGISTER_H_
#define I2C_REGISTER_H_



/* TWI Control register */
#define TWCR			*((volatile u8*)(0x56))

/* TWI Data register */
#define TWDR			*((volatile u8*)(0x23))

/* TWI Address register */
#define TWAR			*((volatile u8*)(0x22))

/* TWI Status register */
#define TWSR			*((volatile u8*)(0x21))

/* TWI Bit rate register */
#define TWBR			*((volatile u8*)(0x20))



/* TWCR Register */
#define TWIE				0
#define TWEN				2
#define TWWC				3
#define TWSTO				4
#define TWSTA				5
#define TWEA				6
#define TWINT				7

/* TWSR Register */
#define TWPS0				0
#define TWPS1				1



#endif /* I2C_REGISTER_H_ */