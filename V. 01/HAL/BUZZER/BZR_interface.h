#ifndef _BZR_INTERFACE_H
#define _BZR_INTERFACE_H

/*############################### prototypes ################################ */

/*
FUNCTION NAME        : BZR_vInit
FUNCTION DESCRIPTION : Set direction of the pin of the Buzzer to make it output
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
*/
void BZR_vInit(uint8 Copy_u8Port,uint8 Copy_u8Pin);

/*
FUNCTION NAME        : BZR_vON
FUNCTION DESCRIPTION : write 1 to the selected pin to let the buzzrt beep
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
*/
void BZR_vON(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : BZR_vOFF
FUNCTION DESCRIPTION : write 0 to the selected pin to turn off the sound of buzzer
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
*/
void BZR_vOFF(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : BZR_vToggle
FUNCTION DESCRIPTION : change the current status of the buzzer (from ON to OFF and from OFF to ON)
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
*/
void BZR_vToggle(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : BZR_vReadStatus
FUNCTION DESCRIPTION : Read the current status of the buzzer whether it's beeping or not
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
FUNCTION RETURN      : returns 1 if the buzzer is ON and 0 if it's OFF
*/
uint8 BZR_vReadStatus (uint8 Copy_u8Port , uint8 Copy_u8Pin);



#endif 