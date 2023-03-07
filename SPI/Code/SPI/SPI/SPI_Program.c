/*
 * SPI.c
 *
 * Created: 2023-03-06 10:15:45 PM
 *  Author: MGAMAL15
 */ 
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "SPI_Interface.h"

void SPI_Init_Master()
{
	//Enable SPI
	SET_BIT(SPCR,6);
	
	//Data order
	SET_BIT(SPCR,5);
	
	//Select Master
	SET_BIT(SPCR,4);
	
	//Clock polarity
	CLR_BIT(SPCR,3);   //Raising Edge
	CLR_BIT(SPCR,2);  //Leading Edge
	
	//Prescaler - oscillator Frequency
	SET_BIT(SPCR,1);
	CLR_BIT(SPSR,0);
	CLR_BIT(SPCR,0);
}


void SPI_Init_Slave()
{
		//Enable SPI
		SET_BIT(SPCR,6);
		
		//Data order
		SET_BIT(SPCR,5);
		
		//Select Slave
		CLR_BIT(SPCR,4);
		
		//Clock polarity
		CLR_BIT(SPCR,3);   //Raising Edge
		CLR_BIT(SPCR,2);  //Leading Edge
		
		//Slave has no control on the clock so no Prescaler - oscillator Frequency

	
}


u8 SPI_SendData(u8 data)
{
	SPDR = data;
	while (!GET_BIT(SPSR,7));
	return SPDR;
}