
#ifndef _IRENCODER_INTERFACE_H_
#define _IRENCODER_INTERFACE_H_


/* ####################### Macros #########################*/


/* ######################## Includes ##########################*/
#include "STD_types.h"
#include "DIO_interface.h"


/* ####################### Prototypes ###########################*/
/*
FUNCTION NAME        : IRENCODER_vInit
FUNCTION DESCRIPTION : initializes IR encoder by setting the pin direction
FUNCTION INPUT       : Copy_u8IRPort: IR encoder selected port , Copy_u8IROutPin: IR encoder selected pin
FUNCTION RETURN      : void
*/
void IRENCODER_vInit(uint8 Copy_u8IRPort ,uint8 Copy_u8IROutPin);

/*
FUNCTION NAME        : IRENCODER_u8DetectObstacle
FUNCTION DESCRIPTION : detects a value by returning 0 or 1
FUNCTION INPUT       : Copy_u8IRPort: IR encoder selected port , Copy_u8IROutPin: IR encoder selected pin
FUNCTION RETURN      : returns 1 if an obstacle detected and 0 if no obstacle
*/
uint8 IRENCODER_u8DetectObstacle(uint8 Copy_u8IRPort ,uint8 Copy_u8IROutPin);

#endif 