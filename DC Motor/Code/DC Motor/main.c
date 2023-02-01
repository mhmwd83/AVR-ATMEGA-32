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


int main()
{
	SET_Direction(PORT_C,PIN_0,OUTPUT);    
	SET_Direction(PORT_C,PIN_1,OUTPUT);   
	while(1)
	{
		//CW Direction
		SET_Value(PORT_C,PIN_0,HIGH);
		SET_Value(PORT_C,PIN_1,LOW);
		_delay_ms(2000);
		//STOP
		SET_Value(PORT_C,PIN_0,LOW);
		SET_Value(PORT_C,PIN_1,LOW);
		_delay_ms(500);
		//CCW Direction
		SET_Value(PORT_C,PIN_0,LOW);
		SET_Value(PORT_C,PIN_1,HIGH);
		_delay_ms(2000);	
	}
	return 0;
}

