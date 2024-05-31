/*
 * I2C_CONFIG.h
 *
 * Created: 5/30/2024 5:25:24 PM
 *  Author: MERNA
 */ 


#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_


/* SCL frequency */
#define TWI_FREQUENCY				400000UL
/* MCU frequency */
#define F_CPU						8000000UL

/* Prescalar Value
Options:
01. TWI_PRESCALAR_1
02. TWI_PRESCALAR_4
03. TWI_PRESCALAR_16
04. TWI_PRESCALAR_64
*/

#define TWI_PRESCALAR_SELECT		TWI_PRESCALAR_1


#endif /* I2C_CONFIG_H_ */