/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */
#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"USART_Interface.h"
#include "DIO_Interface.h"

int main()
{
	SET_Direction(PORT_C,PIN_7,OUTPUT);  //Output for the LED
	SET_Direction(PORT_D,PIN_0,INPUT);  //RX pin
	SET_Direction(PORT_D,PIN_1,OUTPUT); //Tx pin
	USART_Init();
	
	while(1)
	{
		if(USART_Receive()=='1')
		{
			SET_Value(PORT_C,PIN_7,HIGH);
		}

		else if(USART_Receive()=='0')
		{
			SET_Value(PORT_C,PIN_7,LOW);
		}
	}
	return 0;
}

