#ifndef _EXT_INTERFACE_H
#define _EXT_INTERFACE_H

/*######################### Macros ############################*/
/* MCUCR Register */
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

/* MCUCSR Register */
#define ISC2	6

/* GICR Register */
#define INT2	5
#define INT0	6
#define INT1	7

/* GIFR Register */
#define INTF2	5
#define INTF0	6
#define INTF1	7

#define LOW_LEVEL	0
#define ANY_CHANGE	1
#define FALL_EDGE	2
#define RISE_EDGE	3

#define EXT0	0
#define EXT1	1
#define EXT2	2

/*########################## Includes #############################*/
#include "STD_types.h"
#include "BIT_math.h"
#include "EXT_private.h"
#include "DIO_interface.h"


/*########################### Prototypes ################################*/
/*
FUNCTION NAME        : EXT_vInit
FUNCTION DESCRIPTION : initializes external interrupt and setting the interrupt enable
FUNCTION INPUTS      : Copy_u8ExtInt: selected external interrupt , Copy_u8Control: selected control
FUNCTION RETURN      : void
*/
void EXT_vInit(uint8 Copy_u8ExtInt , uint8 Copy_u8Control);

#endif