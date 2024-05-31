/*
 * LCD.c
 *
 * Created: 10/21/2023 2:10:12 PM
 *  Author: MERNA
 */ 
#include "LCD_INTERFACE.h"
#include "LCD_PRIVATE.h"
#include "LCD_CONFIG.h"

/**********************************************************************************************************************/
/*
FUNCTION   : LCD_Init
DESCRIPTION: Initializes LCD by setting the direction of the pins and sending initial commands
INPUT      : void
RETURN     : void
*/
/**********************************************************************************************************************/
void LCD_Init(void)
{
	#if LCD_MODE == LCD_EIGHT_BIT_MODE
	// Define the Eight pins of the port, RS and EN pins as outputs
	Dio_ChannelType LCD_Pins[]={LCD_PORT*8+0 , LCD_PORT*8+1 , LCD_PORT*8+2 , LCD_PORT*8+3
							   ,LCD_PORT*8+4 , LCD_PORT*8+5 , LCD_PORT*8+6 , LCD_PORT*8+7
							   ,LCD_RS , LCD_EN};
	Dio_Init(LCD_Pins , 10 , PORT_PIN_OUT);
	Port_Init();
	
	_delay_ms(150);
	LCD_SendCMD(RETURN_HOME);
	_delay_ms(10);
	LCD_SendCMD(EIGHT_BIT);
	_delay_ms(1);
	
	#elif LCD_MODE == LCD_FOUT_BIT_MODE
	// Define the Four pins of the port, RS and EN pins as outputs
	Dio_ChannelType LCD_Pins[]={LCD_D4,LCD_D5,LCD_D6,LCD_D7,LCD_RS,LCD_EN};
	Dio_Init(LCD_Pins , 6 , PORT_PIN_OUT);
	Port_Init();
	
	_delay_ms(150);
	LCD_SendCMD(RETURN_HOME);
	_delay_ms(10);
	LCD_SendCMD(FOUR_BIT);
	_delay_ms(1);
	#endif
		
	LCD_SendCMD(DISPLAY_ON_CURSOR_OFF);
	_delay_ms(1);
	LCD_SendCMD(CLR_SCREEN);
	_delay_ms(10);
	LCD_SendCMD(ENTRY_MODE);
	_delay_ms(1);
}

/**********************************************************************************************************************/
/*
FUNCTION   : LCD_SendCMD
DESCRIPTION: Sends commands to LCD
INPUT      : Command: the command to be sent to LCD
RETURN     : void
*/
/**********************************************************************************************************************/
void LCD_SendCMD(u8 Command)
{
	#if LCD_MODE == LCD_EIGHT_BIT_MODE
	Dio_WritePort(LCD_PORT , Command);
	Dio_WriteChannel(LCD_RS,STD_LOW);
	LCD_SendTrigger();
	
	#elif LCD_MODE == LCD_FOUT_BIT_MODE
	// Write Mask to write the high nibble of the command
	Dio_WriteMask(LCD_D4/8 , Command>>4 , 0x0F);
	Dio_WriteChannel(LCD_RS,STD_LOW);
	LCD_SendTrigger();
	// Write Mask to write the low nibble of the command
	Dio_WriteMask(LCD_D4/8 , Command , 0x0F);
	Dio_WriteChannel(LCD_RS,STD_LOW);
	LCD_SendTrigger();
	#endif
}

/**********************************************************************************************************************/
/*
FUNCTION   : LCD_SendData
DESCRIPTION: Sends Data to LCD to be displayed
INPUT      : Data: data to be sent to LCD
RETURN     : void
*/
/**********************************************************************************************************************/
void LCD_SendData(u8 Data)
{
	#if LCD_MODE == LCD_EIGHT_BIT_MODE
	Dio_WritePort(LCD_PORT , Data);
	Dio_WriteChannel(LCD_RS,STD_HIGH);
	LCD_SendTrigger();
	
	#elif LCD_MODE == LCD_FOUT_BIT_MODE
	// Write Mask to write the high nibble of the data
	Dio_WriteMask(LCD_D4/8 , Data>>4 , 0x0F);
	Dio_WriteChannel(LCD_RS,STD_HIGH);
	LCD_SendTrigger();
	// Write Mask to write the low nibble of the data
	Dio_WriteMask(LCD_D4/8 , Data , 0x0F);
	Dio_WriteChannel(LCD_RS,STD_HIGH);
	LCD_SendTrigger();
	#endif
}

/**********************************************************************************************************************/
/*
FUNCTION   : LCD_SendTrigger
DESCRIPTION: Sends trigger pulse to the EN pin of the LCD for the new data or command 
			 this function is static, used only in LCD_PROGRAM.c
INPUT      : void
RETURN     : void
*/
/**********************************************************************************************************************/
static void LCD_SendTrigger(void)
{
	Dio_WriteChannel(LCD_EN,STD_HIGH);
	_delay_ms(2);
	Dio_WriteChannel(LCD_EN,STD_LOW);
	_delay_ms(2);
}

/**********************************************************************************************************************/
/*
FUNCTION   : LCD_SendString
DESCRIPTION: Sends a string (array of char) to LCD to be displayed
INPUT      : String: array of chars to be sent
RETURN     : void
*/
/**********************************************************************************************************************/
void LCD_SendString(char* String)
{
	while(*String != '\0')
	{
		LCD_SendData(*String);
		String++;
	}
}

/**********************************************************************************************************************/
/*
FUNCTION   : LCD_Send_XY
DESCRIPTION: Sends a string (array of char) to LCD to be displayed at the position (X,Y) of LCD
INPUT      : String: array of chars to be sent , X: row of LCD (1 -> 4), Y: Column of LCD (1 -> 20)
RETURN     : void
*/
/**********************************************************************************************************************/
void LCD_Send_XY(u8 X,u8 Y,char* String)
{
	u8 LOC;
	if(X==1 || X>4)
	{
		LOC = ROW1_START+Y-1;
	}
	else if(X==2)
	{
		LOC = ROW1_START+(0x40)+Y-1;	
	}
	else if(X==3)
	{
		LOC = ROW1_START+(0x14)+Y-1;
	}
	else
	{
		LOC = ROW1_START+(0x54)+Y-1;
	}
	LCD_SendCMD(LOC);
	LCD_SendString(String);
}

/**********************************************************************************************************************/
/*
FUNCTION   : LCD_vSendNumber
DESCRIPTION: Sends a Number (converts the number to its ascii numbers and send them
INPUT      : Copy_u16Number: Number to be sent
RETURN     : void
*/
/**********************************************************************************************************************/
void LCD_vSendNumber(u16 Copy_u16Number)
{
	u8 LOC_Arr[10];
	u8 LOC_i=0;
	if(Copy_u16Number == 0)
	{
		LCD_SendData('0');
	}
	else
	{
		while(Copy_u16Number != 0)
		{
			LOC_Arr[LOC_i] = Copy_u16Number%10;
			Copy_u16Number /= 10;
			LOC_i++;
		}
		while(LOC_i>0)
		{
			LOC_i--;
			LCD_SendData(LOC_Arr[LOC_i]+48);
		}
	}
}

/**********************************************************************************************************************/