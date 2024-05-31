
#ifndef SEVEN_SEGMENT_BCD_H_
#define SEVEN_SEGMENT_BCD_H_

/* ############################################# prototypes ###########################################################*/

/*
FUNCTION NAME        : SEVSEG_BCD_vInit
FUNCTION DESCRIPTION : used to initialize a seven segment that works with a BCD_to_Seven_Segment decoder
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8StartPin: first pin connected to the decoder
FUNCTION RETURN      : void
*/
void SEVSEG_BCD_vInit(uint8 Copy_u8Port , uint8 Copy_u8StartPin);

/*
FUNCTION NAME        : SEVSEG_BCD_vWrite
FUNCTION DESCRIPTION : write a value to the seven segment that works with a BCD_to_Seven_Segment decoder
FUNCTION INPUTS      : Copy_u8Port: selected port , Copy_u8StartPin: first pin connected to the decoder , Copy_u8Value: displayed value
FUNCTION RETURN      : void
*/
void SEVSEG_BCD_vWrite(uint8 Copy_u8Port , uint8 Copy_u8StartPin , uint8 Copy_u8Value);



#endif 