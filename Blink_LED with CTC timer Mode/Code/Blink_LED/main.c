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
	SET_Direction(PORT_C,PIN_7,OUTPUT);  //SET pin7 in port C as an output
	while(1)
	{
			SET_Value(PORT_C,PIN_7,HIGH);
			SET_Value(PORT_C,PIN_7,LOW);

	}
	return 0;
}

