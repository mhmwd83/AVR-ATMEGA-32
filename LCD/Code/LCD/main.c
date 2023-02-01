/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */

#define F_CPU 8000000UL //1MHz Clock frequency
#include <util/delay.h>  // For delay function

#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"

int main()
{
	SET_Direction(PORT_C,PIN_0,OUTPUT);    //Set RS pin to PIN 0
	SET_Direction(PORT_C,PIN_1,OUTPUT);   //Set RW pin to PIN 1
    SET_Direction(PORT_C,PIN_2,OUTPUT);  //Set EN pin to PIN 2
	SET_Direction_4MSB(PORT_C,OUTPUT);  //Set D4 to D7 pina as data PINs
	LCD_Init();  /* Initialize LCD */ 
	LCD_String("MahmoudGamal"); /* Write a string on 1st line of LCD*/ 
	LCD_SendNumbers(1993); /* Write a string on 1st line of LCD*/ 
	
	while(1)
	{
		

	}
	return 0;
}

