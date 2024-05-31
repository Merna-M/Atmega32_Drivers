/*
 * PORT_config.h
 *
 * Created: 10/20/2023 3:10:04 PM
 *  Author: MERNA
 */ 


#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

#define MAX_NUMBER_OF_PINS		32

/********************************************************************************/
typedef struct{
	Dio_PortType Port;
	Port_PinType Pin;
	Port_PinDirectionType Dir;
}Port_ConfigType;

/********************************************************************************/

void PORT_InsertConf(Port_ConfigType *Copy_u8Config,u8 Copy_u8Size);
#endif /* PORT_CONFIG_H_ */