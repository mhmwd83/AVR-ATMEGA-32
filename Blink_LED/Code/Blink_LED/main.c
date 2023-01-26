/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */
#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"

int main()
{
	SET_Direction(PORT_A,PIN_2,INPUT);  //SET pin2 in port A as an input
	SET_Direction(PORT_C,PIN_7,OUTPUT);  //SET pin7 in port C as an output
	SET_Value(PORT_A, PIN_2, HIGH); //Enable internal pull up resistor for port A
	while(1)
	{
		if(GET_Value(PORT_A,PIN_2) == LOW)
		{
			SET_Value(PORT_C,PIN_7,HIGH);
		}

		else if(GET_Value(PORT_A,PIN_2) == HIGH)
		{
			SET_Value(PORT_C,PIN_7,LOW);
		}

	}
	return 0;
}

