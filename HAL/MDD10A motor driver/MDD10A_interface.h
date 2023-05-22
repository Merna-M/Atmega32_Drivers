#ifndef _MDD10A_INTERFACE_H
#define _MDD10A_INTERFACE_H

/********************************************** Macros ************************************************/


/********************************************** Includes ************************************************/
#include "STD_types.h"
#include "DIO_interface.h"


/********************************************** Prototypes ************************************************/

void MDD10A_vInit(uint8 Copy_u8Port , uint8 Copy_u8PWMPin , uint8 Copy_u8DirPin);

void MDD10A_vMotorMoveForward(uint8 Copy_u8Port , uint8 Copy_u8PWMPin , uint8 Copy_u8DirPin);

void MDD10A_vMotorMoveBack(uint8 Copy_u8Port , uint8 Copy_u8PWMPin , uint8 Copy_u8DirPin);

void MDD10A_vMotorStop(uint8 Copy_u8Port , uint8 Copy_u8PWMPin);

#endif