#ifndef EXT_PRIVATE_H
#define EXT_PRIVATE_H

/*MCU Control Register*/
#define MCUCR   *((volatile uint8*)(0x55))
/*MCU Control and status Register*/
#define MCUCSR  *((volatile uint8*)(0x54))
/*General Interrupt Control Register*/
#define GICR    *((volatile uint8*)(0x5B))
/*General Interrupt Flag Register*/
#define GIFR    *((volatile uint8*)(0x5A))




#endif