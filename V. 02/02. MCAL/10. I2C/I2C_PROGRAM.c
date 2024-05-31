/*
 * I2C_PROGRAM.c
 *
 * Created: 10/31/2023 10:52:29 AM
 *  Author: MERNA
 */ 

#include "I2C_INTERFACE.h"
#include "I2C_REGISTER.h"
#include "I2C_PRIVATE.h"
#include "I2C_CONFIG.h"


/**************************************************************************************************************************/
/*
FUNCTION   : TWI_vInitMaster
DESCRIPTION: Initializes TWI for Master MCU by enabling Pins and setting an address
INPUTS     : Copy_u8Address: Address of the master
RETURN     : void
*/
/**************************************************************************************************************************/
void TWI_vInitMaster(u8 Copy_u8Address)
{
	if((Copy_u8Address < 128) && (Copy_u8Address > 0)) // address for master is optional (7 bits for the address)
	{
		TWAR = Copy_u8Address<<1 ;
	}
	//Set clock as configured in Config
	TWBR = (u8)(((F_CPU/TWI_FREQUENCY)-16)/(2*TWI_PRESCALAR_SELECT));
	#if TWI_PRESCALAR_SELECT == TWI_PRESCALAR_1
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
	
	#elif TWI_PRESCALAR_SELECT == TWI_PRESCALAR_4
	SET_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
	
	#elif TWI_PRESCALAR_SELECT == TWI_PRESCALAR_16
	CLR_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);
	
	#elif TWI_PRESCALAR_SELECT == TWI_PRESCALAR_64
	SET_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);
	
	#endif
	
	//Enable ACK
	SET_BIT(TWCR,TWEA);
	
	//Enable TWI Peripheral
	SET_BIT(TWCR,TWEN);
}
/**************************************************************************************************************************/
/*
FUNCTION   : TWI_vSendStartCondition
DESCRIPTION: Sends a Start Condition
INPUTS     : void
RETURN     : STD_OK: if start condition is successfully sent, STD_NOK: if not
*/
/**************************************************************************************************************************/

STD_Status TWI_vSendStartCondition(void)
{
	STD_Status LOC_status = STD_OK;
	//Request a Start condition
	SET_BIT(TWCR,TWSTA);
	
	//Clear flag for start condition
	SET_BIT(TWCR,TWINT);
	
	//Busy Wait for the flag 
	while(GET_BIT(TWCR,TWINT) == 0);
	
	//Check Status Code == Start Cond. ACK
	if(TWI_STATUS_VALUE != TWI_START_COND_ACK)
	{
		LOC_status = STD_NOK;
	}
	return LOC_status;
}

/**************************************************************************************************************************/
/*
FUNCTION   : TWI_vSendRepStartCondition
DESCRIPTION: sends a repeated start
INPUTS     : void
RETURN     : STD_OK: if start condition is successfully sent, STD_NOK: if not
*/
/**************************************************************************************************************************/
STD_Status TWI_vSendRepStartCondition(void)
{
	STD_Status LOC_Status = STD_OK;
	//Request a Start condition
	SET_BIT(TWCR,TWSTA);
	
	//Clear flag for start condition
	SET_BIT(TWCR,TWINT);
	
	//Busy Wait for the flag
	while(GET_BIT(TWCR,TWINT) == 0);
	
	//Check Status Code == Repeated Start Cond. ACK
	if(TWI_STATUS_VALUE != TWI_REP_START_COND_ACK)
	{
		LOC_Status = STD_NOK;
	}
	return LOC_Status;
}

/**************************************************************************************************************************/
/*
FUNCTION   : TWI_vSendStopCondition
DESCRIPTION: Sends a stop condition
INPUTS     : void
RETURN     : void
*/
/**************************************************************************************************************************/
void TWI_vSendStopCondition(void)
{
	//Request a Stop Condition
	SET_BIT(TWCR,TWSTO);
	
	//Clear flag for Stop Condition
	SET_BIT(TWCR,TWINT);
}

/**************************************************************************************************************************/
/*
FUNCTION   : TWI_vSendSlaveAddressWithWriteOrRead
DESCRIPTION: Sends the address of the Slave and select to read from or write to the slave 
INPUTS     : Copy_u8SlaveAddress: address of the slave,
			 Copy_u8ReadWrite   : option of read or write (0 if write and 1 if read)
RETURN     : STD_OK: if Address is successfully sent (ACK is received) , STD_NOK: if not
*/
/**************************************************************************************************************************/
STD_Status TWI_vSendSlaveAddressWithWriteOrRead(u8 Copy_u8SlaveAddress,u8 Copy_u8ReadWrite)
{
	STD_Status LOC_Status = STD_NOK;
	
	if(Copy_u8SlaveAddress < 128) //validation 
	{
		TWDR = Copy_u8SlaveAddress<<1 ; // Address is in the high 7 bits of the register
		TWDR |= (Copy_u8ReadWrite & 0x01);
		
		//Clear Start Condition Bit
		CLR_BIT(TWCR,TWSTA);
		
		//Clear flag for Sending Address + R/W Bit
		SET_BIT(TWCR,TWINT);
		
		//Busy Wait for the flag
		while(GET_BIT(TWCR,TWINT) == 0);
		
		//Check Status Code == Slave Address+READ bit ACK
		if(Copy_u8ReadWrite == TWI_WRITE && TWI_STATUS_VALUE == TWI_SLA_WRITE_ACK)
		{
			LOC_Status = STD_OK;
		}
		else if(Copy_u8ReadWrite == TWI_READ && TWI_STATUS_VALUE == TWI_SLA_READ_ACK)
		{
			LOC_Status = STD_OK;
		}
	}
	return LOC_Status;
}


/**************************************************************************************************************************/
/*
FUNCTION   : TWI_vWriteMasterDataByte
DESCRIPTION: Sends Data to Slave
INPUTS     : Copy_u8TxData: Data to be sent to the slave
RETURN     : STD_OK: if Data is successfully sent (ACK is received) , STD_NOK: if not
*/
/**************************************************************************************************************************/
STD_Status TWI_vWriteMasterDataByte(u8 Copy_u8TxData)
{
	STD_Status LOC_Status = STD_OK;
	TWDR = Copy_u8TxData;
	
	//Clear flag for Sending Data
	SET_BIT(TWCR,TWINT);
	
	//Busy Wait for the flag
	while(GET_BIT(TWCR,TWINT) == 0);
	
	//Check Status Code == Start Cond. ACK
	if(TWI_STATUS_VALUE != TWI_MASTER_DATA_TX_ACK)
	{
		LOC_Status = STD_NOK;
	}
	return LOC_Status;
}

/**************************************************************************************************************************/
/*
FUNCTION   : TWI_vReadMasterDataByte
DESCRIPTION: requests data from the slave
INPUTS     : Copy_pu8RxData: pointer to the variable that will hold the received data from slave
			 Copy_u8AckNack: Ack or Nack option Select (0 for ACK and 1 for NACK)
			 (choose NACK if the receiving data is the last one)
RETURN     : STD_OK: if Data is successfully received, STD_NOK: if not
*/
/**************************************************************************************************************************/
STD_Status TWI_vReadMasterDataByte(u8* Copy_pu8RxData,u8 Copy_u8AckNack)
{
	STD_Status LOC_Status = STD_NOK;
	if(Copy_pu8RxData != NULL)
	{
		if(Copy_u8AckNack == TWI_DATA_RX_NACK)
		{
			CLR_BIT(TWCR,TWEA);
		}
		else
		{
			SET_BIT(TWCR,TWEA);
		}
		//Clear flag for Sending Data
		SET_BIT(TWCR,TWINT);
		
		//Busy Wait for the flag
		while(GET_BIT(TWCR,TWINT) == 0);
		
		//Check Status Code == Start Cond. NACK
		if(Copy_u8AckNack == TWI_DATA_RX_NACK && TWI_STATUS_VALUE == TWI_MASTER_DATA_RX_NACK)
		{
			LOC_Status = STD_OK;
		}
		//Check Status Code == Start Cond. ACK
		else if(Copy_u8AckNack == TWI_DATA_RX_ACK && TWI_STATUS_VALUE == TWI_MASTER_DATA_RX_ACK)
		{	
			LOC_Status = STD_OK;
		}
		
		*Copy_pu8RxData = TWDR;
	}
}

/**************************************************************************************************************************/
