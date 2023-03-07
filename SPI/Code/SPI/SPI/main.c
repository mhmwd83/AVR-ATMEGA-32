/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "SPI_Interface.h"
#include "DIO_Interface.h"

int main()
{
	SET_Direction(PORT_B,PIN_0,INPUT); //Switch
	SET_Value(PORT_B, PIN_0, HIGH); //Enable internal pull up resistor for port B
	
	SET_Direction(PORT_B,PIN_5,OUTPUT); //MOSI pin
	SET_Direction(PORT_B,PIN_6,INPUT); //MISO pin
	SET_Direction(PORT_B,PIN_4,OUTPUT); //SS pin
	SET_Direction(PORT_B,PIN_7,OUTPUT); //SCK pin
	
	SET_Value(PORT_B,PIN_4,LOW); //Must set SS pin to zero to select the slave  
	  
	SPI_Init_Master();
	
	while(1)
	{
		if(!GET_Value(PORT_B,PIN_0))
		{
			SPI_SendData('1');
		}

		else if(GET_Value(PORT_B,PIN_0))
		{
			SPI_SendData('0');
		}

	}
	return 0;
}

