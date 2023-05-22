
#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_


/*########################## Macros #########################*/
#define ZERO_ANGLE			999

/* ########################## Includes ############################*/
#include "STD_types.h"
#include "GIE_interface.h"
#include "TMR1_interface.h"


/* ######################### Prototypes ###########################*/
/*
FUNCTION NAME        : SERVO_vInit
FUNCTION DESCRIPTION : initializes servo motor by initializing timer1
FUNCTION INPUT       : void
FUNCTION RETURN      : void
*/
void SERVO_vInit(void);

/*
FUNCTION NAME        : SERVO_vSelectAngle
FUNCTION DESCRIPTION : rotates the servo motor according to that angle
FUNCTION INPUT       : Copy_u8Angle: angle of servo motor
FUNCTION RETURN      : void
*/
void SERVO_vSelectAngle(uint8 Copy_u8Angle);


#endif