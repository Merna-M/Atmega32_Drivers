#ifndef _I2C_INTERFACE_H
#define _I2C_INTERFACE_H


/********************************************************* Macros ********************************************************************/
/* Prescalar Values */
#define PRESCALAR_1			1
#define PRESCALAR_4			4
#define PRESCALAR_16		16
#define PRESCALAR_64		64

/* TWCR Register */
#define TWIE				0
#define TWEN				2
#define TWWC				3
#define TWSTO				4
#define TWSTA				5
#define TWEA				6
#define TWINT				7


/* Status */
#define START_STATUS		0x08
#define REPEATED_START		0x10
#define TW_MT_SLA_ACK		0x18
#define TW_MR_SLA_ACK		0x40
#define DATA_ACK_MASTER		0x28
#define SLA_ACK_SLAVE		0x60
#define DATA_ACK_SLAVE		0x80



#define I2C_WRITE			0
#define I2C_READ			1



/****************************************************** Prototypes ********************************************************************/
/*
FUNCTION NAME       : I2C_vInitMaster
FUNCTION DESCRITION : Initializes master by setting clock and setting prescalar
FUNCTION INPUT      : Copy_u32SCLclock: Frequency of clock to be used in SCL line
FUNCTION RETURN     : void
*/
void I2C_vInitMaster(uint32 Copy_u32SCLclock);

/*
FUNCTION NAME       : I2C_vStartCond
FUNCTION DESCRITION : Send the start bit
FUNCTION INPUT      : void
FUNCTION RETURN     : void
*/
uint8 I2C_vStartCond(void);

/*
FUNCTION NAME       : I2C_vWriteAddress
FUNCTION DESCRITION : send slaves's address at SDA line
FUNCTION INPUT      : Copy_u8Address: slaves's address
FUNCTION RETURN     : void
*/
uint8 I2C_vWriteAddress(uint8 Copy_u8Address);

/*
FUNCTION NAME       : I2C_vWriteData
FUNCTION DESCRITION : send data at the SDA line to slave
FUNCTION INPUT      : Copy_u8Data: data to be sent to slave
FUNCTION RETURN     : void
*/
uint8 I2C_vWriteData(uint8 Copy_u8Data);

/*
FUNCTION NAME       : I2C_vStopCond
FUNCTION DESCRITION : sends stop condition
FUNCTION INPUT      : void
FUNCTION RETURN     : void
*/
void I2C_vStopCond(void);

/*
FUNCTION NAME       : I2C_vSetAddress
FUNCTION DESCRITION : sets an address for slave microcontroller
FUNCTION INPUT      : Copy_u8Address: address used for that slave
FUNCTION RETURN     : void
*/
void I2C_vSetAddress(uint8 Copy_u8Address);

/*
FUNCTION NAME       : I2C_vSlaveRead
FUNCTION DESCRITION : read data from slave
FUNCTION INPUT      : void
FUNCTION RETURN     : returns data read from slave (0xFF) if no data received
*/
uint8 I2C_vSlaveRead(void);



void I2C_vWriteByte(uint8 Copy_u8DevAddress , uint8 Copy_u8RegAddress , uint8 Copy_u8Data);

#endif