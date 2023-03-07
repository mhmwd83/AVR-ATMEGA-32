/*
 * USART.c
 *
 * Created: 2023-03-06 10:15:45 PM
 *  Author: MGAMAL15
 */ 
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "USART_Interface.h"


void USART_Init()
{
	u8 temp = 0;
	
	//Select Asynchronous Operation
	CLR_BIT(temp,6);
	
	//Disable the parity
	CLR_BIT(temp,5);
	CLR_BIT(temp,4);
	
	//Select 1 bit stop
	CLR_BIT(temp,3);
	
	//using 8 bit mode
	SET_BIT(temp,2);
	SET_BIT(temp,1);
	CLR_BIT(UCSRB,2);
	
	//Set the selection bit
	SET_BIT(temp,7);
	
	UCSRC = temp;
	
	//for Baud Rate 9600 with 8 bit mode
	UBRRL = 51;
	
	//Set flag bits
	SET_BIT(UCSRB,4);    //Receiver Enable
	SET_BIT(UCSRB,3);   //Transmitter Enable
	
}


void USART_Send(u8 data)
{
	while(!GET_BIT(UCSRA,5));
		UDR = data;
}


u8 USART_Receive()
{
		while(!GET_BIT(UCSRA,7));
			return UDR;
	
}