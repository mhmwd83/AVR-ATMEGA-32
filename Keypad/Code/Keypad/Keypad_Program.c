/*
 * Keypad_Interface.c
 *
 * Created: 2023-01-31 02:51:36 PM
 *  Author: MGAMAL15
 */ 
#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"
#define F_CPU 8000000UL //1MHz Clock frequency
#include <util/delay.h>  // For delay function


u8 Keypad_Getkey()
{   u8 Key='u';
	u8 arr[4][4] = {{'7','8','9','/'},{'4','5','6','x'},{'1','2','3','-'},{'C','0','=','+'}};
	for(u8 i=0;i<4;i++ )
	{
		SET_Value(PORT_A,i,LOW);
		for(u8 j=0;j<4;j++)
		{
			if(GET_Value(PORT_B,j)==LOW)
			{
				while(GET_Value(PORT_B,j)==LOW) //For denouncing Problem
				{
					_delay_ms(25);
				}
				Key=arr[j][i];
				return Key;
			}
		}
		SET_Value(PORT_A,i,HIGH);
	}
	return Key;
}
