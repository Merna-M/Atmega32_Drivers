/*
 * PORT.c
 *
 * Created: 10/20/2023 2:32:18 PM
 *  Author: MERNA
 */ 
#include "PORT_INTERFACE.h"
#include "PORT_CONFIG.h"
#include "PORT_TYPES.h"

extern Port_ConfigType Port_cngs[MAX_NUMBER_OF_PINS];
extern u8 GL_PortNumberOfPins;
static u8 Priv_i = 0;
/*******************************************************************************************/
void Port_Init(void)
{
	static u8 LOC_i = 0;
	for( ; LOC_i < GL_PortNumberOfPins ; LOC_i ++)
	{
		if(Port_cngs[LOC_i].Port==-1)
		{
			break;
		}
		switch(Port_cngs[LOC_i].Port)
		{
			case Dio_PORTA:
				if(Port_cngs[LOC_i].Dir==PORT_PIN_OUT){
					SET_BIT(DDRA,Port_cngs[LOC_i].Pin);
				}else {
					CLR_BIT(DDRA,Port_cngs[LOC_i].Pin);
				}
				break;
				
			case Dio_PORTB:
				if(Port_cngs[LOC_i].Dir==PORT_PIN_OUT){
					SET_BIT(DDRB,Port_cngs[LOC_i].Pin);
				}else {
					CLR_BIT(DDRB,Port_cngs[LOC_i].Pin);
				}
				break;
				
			case Dio_PORTC:
				if(Port_cngs[LOC_i].Dir==PORT_PIN_OUT){
					SET_BIT(DDRC,Port_cngs[LOC_i].Pin);
				}else {
					CLR_BIT(DDRC,Port_cngs[LOC_i].Pin);
				}
				break;
				
			case Dio_PORTD:
				if(Port_cngs[LOC_i].Dir==PORT_PIN_OUT){
					SET_BIT(DDRD,Port_cngs[LOC_i].Pin);
				}else {
					CLR_BIT(DDRD,Port_cngs[LOC_i].Pin);
				}
				break;
				
			default:
				break;
		}
	}
}
/*******************************************************************************************/
