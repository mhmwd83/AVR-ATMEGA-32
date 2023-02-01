/*
 * LCD_Interface.h
 *
 * Created: 2023-01-28 03:01:44 PM
 *  Author: MGAMAL15
 */ 
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define Function_SET 0b00101000    /* Return display to its home position */ 
#define Display_ON_OFF 0b00001111 /* ON the Display and Cursor and Blinking */ 
#define Display_Clear 0b00000001 /* Clear display */ 
#define Entry_Mode 0b00000110   /* Auto Increment cursor */ 

void LCD_Init();

void LCD_SendCommands(u8 Command);

void LCD_SendData(u8 Data);

void LCD_SendData_4BitMode(u8 Data);

void LCD_SendNumbers(u16 Number);

void LCD_String(char *String);

#endif /* LCD_INTERFACE_H_ */