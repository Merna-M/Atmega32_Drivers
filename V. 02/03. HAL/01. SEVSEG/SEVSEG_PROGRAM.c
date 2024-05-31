/*
 * SEVSEG.c
 *
 * Created: 10/21/2023 10:10:40 AM
 *  Author: MERNA
 */ 

#include "SEVSEG_PRIVATE.h"
#include "SEVSEG_CONFIG.h"
#include "SEVSEG_INTERFACE.h"

/*******************************************************************************************************************************/
/*
FUNCTION   : SEVSEG_Write
DESCRIPTION: This function writes a number to the 7Segment according to the chosen inputs and the configuration
INPUTS     : Number: number to be displayed at the 7Segment
			 Pins: array with the pins used if a BCD to 7Segment used or else it will be NULL
			 Port: address of the port used for the 7Segment or else it will be NULL  
RETURN     : void
*/
/*******************************************************************************************************************************/
void SEVSEG_vWrite(u8 Copy_u8Number , Dio_ChannelType* Pins , Dio_PortType* Port)
{
	#if SEVSEG_MODE == SEVSEG_BCD_TO_7SEG_DECODER
	/* Validation to make sure the array is not NULL and the number is less than or equal 9*/
	if(Pins != NULL && Copy_u8Number <= 9)
	{
		Dio_WriteChannel(Pins[0] , GET_BIT(Copy_u8Number,0));
		Dio_WriteChannel(Pins[1] , GET_BIT(Copy_u8Number,1));
		Dio_WriteChannel(Pins[2] , GET_BIT(Copy_u8Number,2));
		Dio_WriteChannel(Pins[3] , GET_BIT(Copy_u8Number,3));
	}
	#elif SEVSEG_MODE == SEVSEG_NO_DECODER
	/* Validation to make sure the Port is not NULL and the number is less than or equal 9*/
	if(Port != NULL && Copy_u8Number <= 9)
	{
		#if SEVSEG_TYPE == SEVSEG_COMMON_ANODE
		 // all the 7 segment numbers in hex in the common anode mode
		u8 SEVSEG_arr[]={~0x3F,~0x06,~0x5B,~0x4F,~0x66,~0x6D,~0x7D,~0x07,~0x7F,~0x6F};
		Dio_WriteMask(*Port,SEVSEG_arr[Copy_u8Number],0x7F);
		
		#elif SEVSEG_TYPE == SEVSEG_COMMON_CATHODE
		// all the 7 segment numbers in hex in the common cathode mode
		u8 SEVSEG_arr[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; 
		Dio_WriteMask(*Port,SEVSEG_arr[Copy_u8Number],0x7F);
		#endif
	}
	#endif
}

/*******************************************************************************************************************************/
/*
FUNCTION   : SEVSEG_vInit
DESCRIPTION: This function initializes the pins used for the 7 segment (4 pins when using a decoder and 7 when not using it) 
INPUTS     : Pins: array with the pins used if a BCD to 7Segment used or else it will be NULL
			 Port: address of the port used for the 7Segment or else it will be NULL  
RETURN     : void
*/
/*******************************************************************************************************************************/
void SEVSEG_vInit(Dio_ChannelType* Pins , Dio_PortType* Port)
{
	#if SEVSEG_MODE == SEVSEG_BCD_TO_7SEG_DECODER
	if(Pins != NULL)
	{
		Dio_Init(Pins , 4 , PORT_PIN_OUT);
		Port_Init();
	}
	#elif SEVSEG_MODE == SEVSEG_NO_DECODER
	if(Port != NULL)
	{
		Dio_ChannelType SEVSEV_Pins[] = {*Port*8+0 , *Port*8+1 , *Port*8+2 ,
										 *Port*8+3 , *Port*8+4 , *Port*8+5 ,
										 *Port*8+6};
		Dio_Init(SEVSEV_Pins , 7 , PORT_PIN_OUT);
		Port_Init();
	}
	#endif
}

/*******************************************************************************************************************************/