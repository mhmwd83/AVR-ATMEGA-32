/*
 * SPI_Program.c
 *
 *  Created on: Jul 18, 2022
 *      Author: hazemahmed
 */

#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"SPI_Interface.h"

void SPI_Init_Master(){
	SET_BIT(SPCR,5);
	CLR_BIT(SPCR,3);
	CLR_BIT(SPCR,2);
	CLR_BIT(SPSR,0);
	CLR_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	SET_BIT(SPCR,4);
	SET_BIT(SPCR,6);
}
void SPI_Init_Slave(){
	SET_BIT(SPCR,5);
	CLR_BIT(SPCR,3);
	CLR_BIT(SPCR,2);
	CLR_BIT(SPCR,4);
	SET_BIT(SPCR,6);
}
u8 SPI_SendData(u8 data){
	SPDR=data;
	while(!GET_BIT(SPSR, 7));
	return SPDR;

}
