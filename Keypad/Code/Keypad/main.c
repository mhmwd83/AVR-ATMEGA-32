/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */



#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"Keypad_Interface.h"

int main()
{
	SET_Direction_4LSB(PORT_A,OUTPUT);   //Set Columns
	SET_Direction_4LSB(PORT_B,INPUT);   //Set Rows
    SET_Value_4LSB(PORT_B,0x0F);       //Set pull up resistors
	SET_Direction_4LSB(PORT_A,0x0F);  //Set 1 to all four columns
	
	SET_Direction(PORT_C,PIN_0,OUTPUT);
	SET_Direction(PORT_C,PIN_1,OUTPUT);
	SET_Direction(PORT_C,PIN_2,OUTPUT);
	SET_Direction_4MSB(PORT_C,OUTPUT);
    LCD_Init();
	u8 key;
	
	while(1)
	{
		key=Keypad_Getkey();
		if(key!='u')
		{
			LCD_SendData_4BitMode(key);
		}
		else
		{

		}

	}
	return 0;
}

