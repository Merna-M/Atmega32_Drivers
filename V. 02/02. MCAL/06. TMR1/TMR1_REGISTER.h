/*
 * TMR1_REGISTER.h
 *
 * Created: 10/29/2023 10:41:16 AM
 *  Author: MERNA
 */ 


#ifndef TMR1_REGISTER_H_
#define TMR1_REGISTER_H_


/* flag and enable registers */
#define TIMSK		*((volatile u8*)(0x59))
#define TIFR		*((volatile u8*)(0x58))

/* control registers */
#define TCCR1A		*((volatile u8*)(0x4F))
#define TCCR1B		*((volatile u8*)(0x4E))

/* TCNT1 register */
#define TCNT1H		*((volatile u8*)(0x4D))
#define TCNT1L		*((volatile u8*)(0x4C))
#define TCNT1		*((volatile u16*)(0x4C))

/* OCR1 registers */
#define OCR1AH		*((volatile u8*)(0x4B))
#define OCR1AL		*((volatile u8*)(0x4A))
#define OCR1A		*((volatile u16*)(0x4A))

#define OCR1BH		*((volatile u8*)(0x49))
#define OCR1BL		*((volatile u8*)(0x48))
#define OCR1B		*((volatile u16*)(0x48))

/* ICR register */
#define ICR1H		*((volatile u8*)(0x47))
#define ICR1L		*((volatile u8*)(0x46))
#define ICR1		*((volatile u16*)(0x46))



/* TIMSK Register */
#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5

/* TIFR Register */
#define TOV1	2
#define OCF1B	3
#define OCF1A	4
#define ICF1	5

/* TCCR1A Register */
#define WGM10	0
#define WGM11	1
#define FOC1B	2
#define FOC1A	3
#define COM1B0	4
#define COM1B1	5
#define COM1A0	6
#define COM1A1	7

/* TCCR1B Register */
#define CS10	0
#define CS11	1
#define CS12	2
#define WGM12	3
#define WGM13	4

#define ICES1	6 //input capture edge select(falling or rising)
#define ICNC1	7 //input capture noise canceler

/* Timer 1 Pins */
#define TMR1_OCR1A_PIN		 5
#define TMR1_OCR1B_PIN		 4
#define TMR1_ICP1_PIN		 6

/* ICU Edge select choices */
#define FALL_EDGE			0
#define RISE_EDGE			1



#endif /* TMR1_REGISTER_H_ */