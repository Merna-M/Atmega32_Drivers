
#ifndef _ULTRASNK_PRIVATE_H_
#define _ULTRASNK_PRIVATE_H_

#define TCCR1A		*((volatile uint8*)(0x4F))
#define TCCR1B		*((volatile uint8*)(0x4E))
#define TIFR		*((volatile uint8*)(0x58))
#define ICR1		*((volatile uint16*)(0x46))
#define TCNT1		*((volatile uint16*)(0x4C))

#endif 