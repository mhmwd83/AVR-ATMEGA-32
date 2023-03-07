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
	SET_Direction(PORT_C,PIN_7,OUTPUT); //LED
	
	SET_Direction(PORT_B,PIN_5,INPUT); //MISO pin
	SET_Direction(PORT_B,PIN_6,OUTPUT); //MOSI pin
	SET_Direction(PORT_B,PIN_4,INPUT); //SS pin
	SET_Direction(PORT_B,PIN_7,INPUT); //SCK pin

	
	SPI_Init_Slave();
	
	while(1)
	{
		if(SPI_SendData('1') == '1')           //The sent data will be returned to the master again
		{
	       SET_Value(PORT_C, PIN_7, HIGH);
		}

		else if(SPI_SendData('0') == '0')           //The sent data will be returned to the master again
		{
          SET_Value(PORT_C, PIN_7, LOW);
		}

	}
	return 0;
}

