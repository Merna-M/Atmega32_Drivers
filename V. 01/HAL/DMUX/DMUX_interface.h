
#ifndef DMUX_INTERFACE_H_
#define DMUX_INTERFACE_H_

/* ################################ Macros ############################ */
#define DMUX_OUTPUT_0	0
#define DMUX_OUTPUT_1	1
#define DMUX_OUTPUT_2	2
#define DMUX_OUTPUT_3	3
#define DMUX_OUTPUT_4	4
#define DMUX_OUTPUT_5	5
#define DMUX_OUTPUT_6	6
#define DMUX_OUTPUT_7	7

/* ############################### Includes ########################### */
#include "STD_types.h"
#include "DIO_interface.h"
#include "DMUX_config.h"

/* ############################### Prototypes ########################## */
/*
FUNCTION NAME        : DMUX_vInit
FUNCTION DESCRIPTION : initializes the DMUX by setting the selected pins
FUNCTION INPUTS      : void
FUNCTION RETURN      : void
*/
void DMUX_vInit(void);

/*
FUNCTION NAME        : DMUX_vSelectOutput
FUNCTION DESCRIPTION : chooses an output from the DMUX
FUNCTION INPUTS      : Copy_u8SelectedOutput: selected output pin from the DMUX
FUNCTION RETURN      : void
*/
void DMUX_vSelectOutput(uint8 Copy_u8SelectedOutput);


#endif 