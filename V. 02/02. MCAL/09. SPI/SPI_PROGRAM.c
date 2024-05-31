/*
 * SPI_PROGRAM.c
 *
 * Created: 10/30/2023 9:47:36 AM
 *  Author: MERNA
 */ 

#include "SPI_INTERFACE.h"
#include "SPI_REGISTER.h"
#include "SPI_CONFIG.h"

/*******************************************************************************************************************************/
/* Static pointer to a function that takes a u8 and returns void */
static void(*priv_vSetCallBack)(u8) = NULL;

/*******************************************************************************************************************************/
/*
FUNCTION   : SPI_vInit
DESCRIPTION: Initializes SPI by setting the SPI Mode (Master or Slave), prescalar and Enabling SPI Interrupt
INPUTS     : void
RETURN	   : void
*/
/*******************************************************************************************************************************/
void SPI_vInit(void)
{
	#if SPI_MODE == SPI_MASTER
	// Master Select
	SET_BIT(SPCR,MSTR);
	
	#if SPI_PRESCALAR == SPI_PRESCALAR_4
	CLR_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
	
	#elif SPI_PRESCALAR == SPI_PRESCALAR_16
	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
	
	#elif SPI_PRESCALAR == SPI_PRESCALAR_64
	CLR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
	
	#elif SPI_PRESCALAR == SPI_PRESCALAR_128
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
	
	#elif SPI_PRESCALAR == SPI_PRESCALAR_2
	CLR_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
	
	#elif SPI_PRESCALAR == SPI_PRESCALAR_8
	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
	
	#elif SPI_PRESCALAR == SPI_PRESCALAR_32
	CLR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
	
	#elif SPI_PRESCALAR == SPI_PRESCALAR_64
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
	
	#endif
	
	//Define SS, MOSI and SCK pins as output
	Dio_ChannelType Master_out[] = {PB_4,PB_5,PB_7};
	Dio_Init(Master_out,3,PORT_PIN_OUT);
	//Define MISO pin as an input 
	Dio_ChannelType Master_In = PB_6;
	Dio_Init(&Master_In,1,PORT_PIN_IN);
	Port_Init();
	
	#elif SPI_MODE == SPI_SLAVE
	// Slave Select
	CLR_BIT(SPCR,MSTR);
	
	//Define SS, MOSI and SCK pins as inputs
	Dio_ChannelType Slave_In[] = {PB_4,PB_5,PB_7};
	Dio_Init(Slave_In,3,PORT_PIN_IN);
	//Define MISO pin as an output
	Dio_ChannelType Slave_Out = PB_6;
	Dio_Init(&Slave_Out,1,PORT_PIN_OUT);
	Port_Init();
	#endif
	
	
	#if SPI_DATA_ORDER == SPI_LSB_ORDER
	SET_BIT(SPCR,DORD);
	#elif SPI_DATA_ORDER == SPI_MSB_ORDER
	CLR_BIT(SPCR,DORD);
	#endif
	
	//SET_BIT(SPCR,CPOL);
	//SET_BIT(SPCR,CPHA);
	
	//Enable SPI
	SET_BIT(SPCR,SPE);
}

/*******************************************************************************************************************************/
/*
FUNCTION   : SPI_vTransceiver
DESCRIPTION: Transmit and Receive Data of SPI
INPUTS     : Copy_u8TxData: Data transmitted 
RETURN     : Data Received
*/
/*******************************************************************************************************************************/
u8 SPI_vTransceiver(u8 Copy_u8TxData)
{
	u8 LOC_u8RxData;
	//check collision flag
	while(GET_BIT(SPSR,WCOL)==1);
	SPDR = Copy_u8TxData;
	while(GET_BIT(SPSR,SPIF) == 0);
	LOC_u8RxData = SPDR;
	return LOC_u8RxData;
}

/*******************************************************************************************************************************/
/*
FUNCTION   : SPI_vTransmitAsynchronous
DESCRIPTION: Transmit Data, receives Data through an interrupt (Asynchronous)
INPUTS     : Copy_u8TxData: Data transmitted , Copy_u8RxData: Pointer to ISR function that occurs when Serial Transfer Complete
RETURN     : void
*/
/*******************************************************************************************************************************/
void SPI_vTransmitAsynchronous(u8 Copy_u8TxData,void(*ptr)(u8 Copy_u8RxData))
{
	if(ptr != NULL)
	{
		//set interrupt bit
		SET_BIT(SPCR,SPIE);
		priv_vSetCallBack = ptr;
		//check collision flag
		while(GET_BIT(SPSR,WCOL)==1);
		SPDR = Copy_u8TxData;
	}
}

/*******************************************************************************************************************************/


void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	if(priv_vSetCallBack != NULL)
	{
		priv_vSetCallBack(SPDR);
	}
}
/*******************************************************************************************************************************/