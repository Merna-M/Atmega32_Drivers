/*
 * LCD_config.h
 *
 * Created: 10/21/2023 2:10:40 PM
 *  Author: MERNA
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* LCD Mode */
/*
Options:
01. LCD_EIGHT_BIT_MODE
02. LCD_FOUT_BIT_MODE
*/

#define LCD_MODE		LCD_FOUT_BIT_MODE


#if LCD_MODE == LCD_EIGHT_BIT_MODE

#define LCD_PORT		Dio_PORTA

#elif LCD_MODE == LCD_FOUT_BIT_MODE

#define LCD_D4			PA_0
#define LCD_D5			PA_1
#define LCD_D6			PA_2
#define LCD_D7			PA_3

#endif


#define LCD_RS			PA_4
#define LCD_EN			PA_5


#endif /* LCD_CONFIG_H_ */