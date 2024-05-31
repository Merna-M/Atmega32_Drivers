/*
 * I2C_INTERFACE.h
 *
 * Created: 10/31/2023 10:53:04 AM
 *  Author: MERNA
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

/********************************************* Includes **************************************/
#include "../../UTIL/BIT_MATH.h"
#include "../../UTIL/STD_TYPES.h"



#define TWI_DATA_RX_ACK					0
#define TWI_DATA_RX_NACK				1


#define TWI_WRITE						0
#define TWI_READ						1

/******************************************* Prototypes ************************************/
void TWI_vInitMaster(u8 Copy_u8Address);

STD_Status TWI_vSendStartCondition(void);

STD_Status TWI_vSendRepStartCondition(void);

void TWI_vSendStopCondition(void);

STD_Status TWI_vSendSlaveAddressWithWriteOrRead(u8 Copy_u8SlaveAddress,u8 Copy_u8ReadWrite);

STD_Status TWI_vWriteMasterDataByte(u8 Copy_u8TxData);

STD_Status TWI_vReadMasterDataByte(u8* Copy_pu8RxData,u8 Copy_u8AckNack);


#endif /* I2C_INTERFACE_H_ */