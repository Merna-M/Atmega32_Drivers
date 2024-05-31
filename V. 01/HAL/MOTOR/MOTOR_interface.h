
#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

/* ################################ Macros ################################### */
#define MOTOR_ONE_PIN		0
#define MOTOR_HBRIDGE		1
#define MOTOR_L293D			2

/* one pin motor */
#define MOTOR_ON			1
#define MOTOR_OFF			0

/* H Bridge motor */
#define MOTOR_ROTATE_LEFT		0
#define MOTOR_ROTATE_RIGHT		1

/* L293D */
#define MOTOR_STOPS				2

/* ################################ Includes ################################# */
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_interface.h"



/* ################################ Prototypes ################################### */

/*
FUNCTION NAME        : MOTOR_vInitOnePin
FUNCTION DESCRIPTION : initializes the motor in case of using only one pin from the MCU
FUNCTION INPUT       : Copy_u8Port: port of motor , Copy_u8Pin: pin used for the motor
FUNCTION RETURN      : void
*/
void MOTOR_vInitOnePin(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : MOTOR_vInitHBridge
FUNCTION DESCRIPTION : initializes the motor in case of using H bridge 
FUNCTION INPUT       : Copy_u8Port: port of motor , Copy_u8StartPin: start pin used for the motor
(assuming the  other pin is the next one at the same port)
FUNCTION RETURN      : void
*/
void MOTOR_vInitHBridge(uint8 Copy_u8Port , uint8 Copy_u8StartPin);


/*
FUNCTION NAME        : MOTOR_vRotate
FUNCTION DESCRIPTION : used to rotate the motor according to the selected direction
FUNCTION INPUT       : Copy_u8MotorSelect: selected method for the motor , Copy_u8Direction: selected direction ,Copy_u8Port: port of motor 
, Copy_u8StartPin: start pin used for the motor (assuming the  other pin is the next one at the same port)
FUNCTION RETURN      : void
*/
void MOTOR_vRotate(uint8 Copy_u8MotorSelect , uint8 Copy_u8Direction ,uint8 Copy_u8Port , uint8 Copy_u8StartPin);

#endif 