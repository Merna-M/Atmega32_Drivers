#ifndef _BTN_INTERFACE_H
#define _BTN_INTERFACE_H

/* ################# prototypes ###################*/

/*
FUNCTION NAME        : BTN_vInit
FUNCTION DESCRIPTION : it sets the direction of the pin as an input
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
FUNCTION RETURN      : void
*/
void BTN_vInit(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : BTN_u8Read
FUNCTION DESCRIPTION : gets the value of the pin (whether the button is pressed or not) and returns it
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin
FUNCTION RETURN      : returns the value of the pin
*/
uint8 BTN_u8Read(uint8 Copy_u8Port , uint8 Copy_u8Pin);

/*
FUNCTION NAME        : BTN_vConnectPullUp
FUNCTION DESCRIPTION : This function is enable or disable the Pull up of a pin for a LED
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8Pin: selected pin , Copy_u8PullUpCheck: condition (1 if pullup enabled , 0 if pullup disabled)
FUNCTION RETURN      : void
*/
void BTN_vConnectPullUp (uint8 Copy_u8Port , uint8 Copy_u8Pin , uint8 Copy_u8PullUppCond);


#endif