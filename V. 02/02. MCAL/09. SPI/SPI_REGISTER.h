/*
 * SPI_REGISTER.h
 *
 * Created: 10/30/2023 9:48:40 AM
 *  Author: MERNA
 */ 


#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_



//SPI control register
#define SPCR	*((volatile u8*)(0x2D))
//status register
#define SPSR	*((volatile u8*)(0x2E))
//SPI data register
#define SPDR	*((volatile u8*)(0x2F))

/*
#define SPI_BASE_ADDRESS			(0x2D)

typedef struct{
	u8 SPCR;
	u8 SPSR;
	u8 SPDR; 
}SPI_REG;

#define SPI			((volatile SPI_REG*)SPI_BASE_ADDRESS)

*/
//SPCR register
#define SPR0		0		// SPI Clock Rate Select 1 and 0
#define SPR1		1
#define CPHA		2		// Clock Phase
#define CPOL		3		// Clock Polarity
#define MSTR		4		// Master/Slave Select
#define DORD		5		// Data Order
#define SPE			6		// SPI Enable
#define SPIE		7		// SPI Interrupt Enable

//SPSR register
#define SPI2X		0		// Double SPI Speed Bit
#define WCOL		6		// Write COLlision Flag
#define SPIF		7		// SPI Interrupt Flag


#endif /* SPI_REGISTER_H_ */