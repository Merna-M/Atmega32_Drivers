/*
 * EXEEPROM_PROGRAM.c
 *
 * Created: 10/31/2023 2:22:39 PM
 *  Author: MERNA
 */ 

#include "EXEEPROM_INTERFACE.h"
#include "EXEEPROM_PRIVATE.h"

/*****************************************************************************************************************************/
void EXEEPROM_vWriteByte(u16 Copy_u16WordAddress, u8 Copy_u8Data)
{
	u8 LOC_u8Address = (Copy_u16WordAddress>>8) | EEPROM_ADDRESS;
	
	//Send Start Condition
	TWI_vSendStartCondition();
	
	//Send EEPROM + MS bits of EEPROM address
	TWI_vSendSlaveAddressWithWriteOrRead(LOC_u8Address,TWI_WRITE);
	
	//Send EEPROM Word address
	TWI_vWriteMasterDataByte((u8)Copy_u16WordAddress);
	
	//Send Data
	TWI_vWriteMasterDataByte(Copy_u8Data);
	
	//Stop Condition
	TWI_vSendStopCondition();
	
	//Self-timed Write Cycle
	_delay_ms(5);
}

/*****************************************************************************************************************************/

void EXEEPROM_vReadByte(u16 Copy_u16WordAddress, u8* Copy_pu8RxData)
{
	if(Copy_pu8RxData != NULL)
	{
		u8 LOC_u8Address = (Copy_u16WordAddress>>8) | EEPROM_ADDRESS;
		
		//Send Start Condition
		TWI_vSendStartCondition();
		
		//Send EEPROM + MS bits of EEPROM address with Write Operation
		TWI_vSendSlaveAddressWithWriteOrRead(LOC_u8Address,TWI_WRITE);
		
		//Send EEPROM Word address
		TWI_vWriteMasterDataByte((u8)Copy_u16WordAddress);
		
		//Repeated start to switch operation to Read
		TWI_vSendRepStartCondition();
		
		//Send EEPROM + MS bits of EEPROM address with Read Operation
		TWI_vSendSlaveAddressWithWriteOrRead(LOC_u8Address,TWI_READ);
		
		//Read Data from Slave
		TWI_vReadMasterDataByte(Copy_pu8RxData,TWI_DATA_RX_NACK);
		
		//Send Stop Condition
		TWI_vSendStopCondition();
		
		//Self-timed Write Cycle
		_delay_ms(5);
	}
}

/*****************************************************************************************************************************/

void EXEEPROM_vWritePage(u16 Copy_u16WordAddress, u8* Copy_pu8Data, u8 Copy_u8SizeData)
{
	u8 LOC_u8Address = (Copy_u16WordAddress>>8) | EEPROM_ADDRESS;
	u8 LOC_iter=0;
	
	//Send Start Condition
	TWI_vSendStartCondition();
	
	//Send EEPROM + MS bits of EEPROM address
	TWI_vSendSlaveAddressWithWriteOrRead(LOC_u8Address,TWI_WRITE);
	
	//Send EEPROM Word address
	TWI_vWriteMasterDataByte((u8)Copy_u16WordAddress);
	
	for(LOC_iter=0 ; LOC_iter<Copy_u8SizeData ; LOC_iter++)
	{
		//Send Data
		TWI_vWriteMasterDataByte(Copy_pu8Data[LOC_iter]);
	}
	
	//Stop Condition
	TWI_vSendStopCondition();
	
	//Self-timed Write Cycle
	_delay_ms(5);
}
/*****************************************************************************************************************************/

void EXEEPROM_vReadSequence(u16 Copy_u16WordAddress, u8* Copy_pu8RxData,u8 Copy_u8Size)
{
	if(Copy_pu8RxData != NULL && Copy_u8Size>0)
	{
		u8 LOC_u8Address = (Copy_u16WordAddress>>8) | EEPROM_ADDRESS;
		u8 LOC_iter=0;
		
		//Send Start Condition
		TWI_vSendStartCondition();
		
		//Send EEPROM + MS bits of EEPROM address with Write Operation
		TWI_vSendSlaveAddressWithWriteOrRead(LOC_u8Address,TWI_WRITE);
		
		//Send EEPROM Word address
		TWI_vWriteMasterDataByte((u8)Copy_u16WordAddress);
		
		//Repeated start to switch operation to Read
		TWI_vSendRepStartCondition();
		
		//Send EEPROM + MS bits of EEPROM address with Read Operation
		TWI_vSendSlaveAddressWithWriteOrRead(LOC_u8Address,TWI_READ);
		
		for(LOC_iter=0 ; LOC_iter<Copy_u8Size-1 ; LOC_iter++)
		{
			//Read Data from Slave
			TWI_vReadMasterDataByte(&Copy_pu8RxData[LOC_iter],TWI_DATA_RX_ACK);
		}
		//Read Last Data from Slave
		TWI_vReadMasterDataByte(&Copy_pu8RxData[LOC_iter],TWI_DATA_RX_NACK);
		
		//Send Stop Condition
		TWI_vSendStopCondition();
		
		//Self-timed Write Cycle
		_delay_ms(5);
	}
}
/*****************************************************************************************************************************/