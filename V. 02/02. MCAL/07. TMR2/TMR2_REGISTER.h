/*
 * TMR2_REGISTER.h
 *
 * Created: 10/29/2023 8:15:37 PM
 *  Author: MERNA
 */ 


#ifndef TMR2_REGISTER_H_
#define TMR2_REGISTER_H_


#define TCNT2	*((volatile u8*)(0x44))
#define TCCR2	*((volatile u8*)(0x45))
#define TIMSK	*((volatile u8*)(0x59))
#define TIFR	*((volatile u8*)(0x58))
#define OCR2	*((volatile u8*)(0x43))
#define ASSR	*((volatile u8*)(0x42))


/* TCCR2 Register */
#define CS20	0
#define CS21	1
#define CS22	2
#define WGM21	3
#define COM20	4
#define COM21	5
#define WGM20	6
#define FOC2	7

/* TIMSK Register */
#define TOIE2	6
#define OCIE2	7

/* TIFR Register */
#define TOV2	6
#define OCF2	7

/* ASSR Register */
#define AS2		3


#endif /* TMR2_REGISTER_H_ */