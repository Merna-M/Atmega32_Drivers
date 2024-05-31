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
#define SLA_ACK_MASTER		0x18
#define DATA_ACK_MASTER		0x28
#define SLA_ACK_SLAVE		0x60
#define DATA_ACK_SLAVE		0x80
/****************************************************** Prototypes ********************************************************************/
/*
FUNCTION NAME       :
FUNCTION DESCRITION :
FUNCTION INPUT      :
FUNCTION RETURN     :
*/
void I2C_vInitMaster(uint32 Copy_u32SCLclock);

/*
FUNCTION NAME       :
FUNCTION DESCRITION :
FUNCTION INPUT      :
FUNCTION RETURN     :
*/
void I2C_vStartCond(void);

/*
FUNCTION NAME       :
FUNCTION DESCRITION :
FUNCTION INPUT      :
FUNCTION RETURN     :
*/
void I2C_vWriteAddress(uint8 Copy_u8Address);

/*
FUNCTION NAME       :
FUNCTION DESCRITION :
FUNCTION INPUT      :
FUNCTION RETURN     :
*/
void I2C_vWriteData(uint8 Copy_u8Data);

/*
FUNCTION NAME       :
FUNCTION DESCRITION :
FUNCTION INPUT      :
FUNCTION RETURN     :
*/
void I2C_vStopCond(void);

/*
FUNCTION NAME       :
FUNCTION DESCRITION :
FUNCTION INPUT      :
FUNCTION RETURN     :
*/
void I2C_vSetAddress(uint8 Copy_u8Address);

/*
FUNCTION NAME       :
FUNCTION DESCRITION :
FUNCTION INPUT      :
FUNCTION RETURN     :
*/
uint8 I2C_vSlaveRead(void);

#endif