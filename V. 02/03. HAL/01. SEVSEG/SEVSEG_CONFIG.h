/*
 * SEVSEG_CONFIG.h
 *
 * Created: 5/29/2024 4:19:42 PM
 *  Author: MERNA
 */ 


#ifndef SEVSEG_CONFIG_H_
#define SEVSEG_CONFIG_H_

/* Choose 7Segment Mode
Options:
01. SEVSEG_BCD_TO_7SEG_DECODER
02. SEVSEG_NO_DECODER
*/
#define SEVSEG_MODE		SEVSEG_BCD_TO_7SEG_DECODER

/* Choose 7Segment Type
Options:
01. SEVSEG_COMMON_ANODE
02. SEVSEG_COMMON_CATHODE
*/
#define SEVSEG_TYPE		SEVSEG_COMMON_CATHODE


#endif /* SEVSEG_CONFIG_H_ */