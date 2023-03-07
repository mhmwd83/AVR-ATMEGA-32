/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "USART_Interface.h"
#include "DIO_Interface.h"

int main()
{
	SET_Direction(PORT_B,PIN_0,INPUT);
	SET_Value(PORT_B, PIN_0, HIGH); //Enable internal pull up resistor for port B
	  
	SET_Direction(PORT_D,PIN_0,INPUT);   //Rx pin
	SET_Direction(PORT_D,PIN_1,OUTPUT); //Tx pin
	USART_Init();
	
	while(1)
	{
		if(!GET_Value(PORT_B,PIN_0))
		{
			USART_Send('1');
		}

		else if(GET_Value(PORT_B,PIN_0))
		{
			USART_Send('0');
		}

	}
	return 0;
}

