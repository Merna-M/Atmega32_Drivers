/*
 * PORT_config.c
 *
 * Created: 10/21/2023 9:52:22 AM
 *  Author: MERNA
 */ 

#include "PORT_INTERFACE.h"
#include "PORT_CONFIG.h"

u8 GL_PortNumberOfPins = 0;

Port_ConfigType Port_cngs[MAX_NUMBER_OF_PINS]={
{-1,-1,-1}
};

void PORT_InsertConf(Port_ConfigType *Copy_u8Config,u8 Copy_u8Size)
{
	for(u8 LOC_i=0 ; LOC_i < Copy_u8Size ; LOC_i ++)
	{
		Port_cngs[GL_PortNumberOfPins] = Copy_u8Config[LOC_i];
		GL_PortNumberOfPins++;
	}
}

