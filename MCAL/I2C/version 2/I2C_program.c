#include "STD_types.h"
#include "BIT_math.h"
#include "I2C_private.h"
#include "I2C_interface.h"
#include "I2C_config.h"
#define F_CPU  8000000UL


/***********************************************************************************************************************************************************/

void I2C_vInitMaster(uint32 Copy_u32SCLclock)
{
	TWBR = (uint8)(((F_CPU/Copy_u32SCLclock)-16)/(2*I2C_PRESCALAR));
	#if I2C_PRESCALAR == PRESCALAR_1
	TWSR = 0;
	#elif I2C_PRESCALAR == PRESCALAR_4
	TWSR = 1;
	#elif I2C_PRESCALAR == PRESCALAR_16
	TWSR = 2;
	#elif I2C_PRESCALAR == PRESCALAR_64
	TWSR = 3;
	#endif

}

/***********************************************************************************************************************************************************/

uint8 I2C_vStartCond(void)
{
	uint8 Return_value=0;
	/* clear TWI flag bit and generate start bit */
	TWCR =(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	/* wait for the flag to set */
	while(READ_BIT(TWCR,TWINT)==0);
	if(TWSR & 0xF8 != START_STATUS && TWSR & 0xF8 != REPEATED_START)
	{
		//error
		Return_value = 1;
	}
	return Return_value;
}

/***********************************************************************************************************************************************************/

uint8 I2C_vWriteAddress(uint8 Copy_u8Address)
{
	uint8 Return_value = 0;
	/* Load address in the data register */
	TWDR = Copy_u8Address;
	/* clear TWI flag bit */
	TWCR = (1<<TWINT)|(1<<TWEN);
	/* wait for the flag to set */
	while(READ_BIT(TWCR,TWINT)==0);
	if(TWSR & 0xF8 != TW_MT_SLA_ACK && TWSR & 0xF8 !=TW_MR_SLA_ACK)
	{
		//error
		Return_value = 1;
	}
	return Return_value;
}

/***********************************************************************************************************************************************************/

uint8 I2C_vWriteData(uint8 Copy_u8Data)
{
	uint8 Return_value = 0;
	/* load data in the data register */
	TWDR = Copy_u8Data;
	/* clear TWI flag bit */
	TWCR = (1<<TWINT)|(1<<TWEN);
	/* wait for the flag to set */
	while(READ_BIT(TWCR,TWINT)==0);
	if(TWSR & 0xF8 != DATA_ACK_MASTER)
	{
		//error
		Return_value = 1;
	}
	return Return_value;
}

/***********************************************************************************************************************************************************/

void I2C_vStopCond(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

/***********************************************************************************************************************************************************/

void I2C_vSetAddress(uint8 Copy_u8Address)
{
	TWAR = Copy_u8Address;
}

/***********************************************************************************************************************************************************/

uint8 I2C_vSlaveRead(void)
{
	uint8 Return_value = 0xFF;
	/* enable TWI , clear flag bit , send ack */
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	/* wait for the flag to set */
	while(READ_BIT(TWCR,TWINT)==0);
	if(TWSR & 0xF8 != SLA_ACK_SLAVE)
	{
		//error
	}
	else
	{
		/* enable TWI , clear flag bit , send ack */
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		/* wait for the flag to set */
		while(READ_BIT(TWCR,TWINT)==0);
		if(TWSR & 0xF8 != DATA_ACK_SLAVE)
		{
			//error
		}
		else
		{
			Return_value = TWDR;
		}
	}
	return Return_value;
}


/***********************************************************************************************************************************************************/

void I2C_vWriteByte(uint8 Copy_u8DevAddress , uint8 Copy_u8RegAddress , uint8 Copy_u8Data)
{
	I2C_vStartCond();
	I2C_vWriteAddress(Copy_u8DevAddress+I2C_WRITE);
	I2C_vWriteData(Copy_u8RegAddress);
	I2C_vWriteData(Copy_u8Data);
	I2C_vStopCond();
}


/***********************************************************************************************************************************************************/


uint8 I2C_vReadByte(uint8 Copy_u8DevAddress , uint8 Copy_u8RegAddress)
{
	uint8 Return_data;
	I2C_vStartCond();
	I2C_vWriteAddress(Copy_u8DevAddress+I2C_WRITE);
	I2C_vWriteData(Copy_u8RegAddress);
	I2C_vStartCond();
	I2C_vWriteAddress(Copy_u8DevAddress+I2C_READ);
	Return_data = I2C_vSlaveRead();
}


/***********************************************************************************************************************************************************/







