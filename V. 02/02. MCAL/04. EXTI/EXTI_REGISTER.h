/*
 * EXTI_REGISTER.h
 *
 * Created: 10/22/2023 1:42:20 PM
 *  Author: MERNA
 */ 


#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_


/*MCU Control Register*/
#define MCUCR   *((volatile u8*)(0x55))
/*MCU Control and status Register*/
#define MCUCSR  *((volatile u8*)(0x54))
/*General Interrupt Control Register*/
#define GICR    *((volatile u8*)(0x5B))
/*General Interrupt Flag Register*/
#define GIFR    *((volatile u8*)(0x5A))


/** MCUCR **/
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




#endif /* EXTI_REGISTER_H_ */