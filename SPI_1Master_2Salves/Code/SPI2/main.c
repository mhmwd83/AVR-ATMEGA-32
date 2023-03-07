/*
 * main.c
 *
 *  Created on: Jul 18, 2022
 *      Author: hazemahmed
 */


#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"SPI_Interface.h"
#include"DIO_Interface.h"
int main(){
	SET_Direction(PORT_C, PIN_7, OUTPUT);
	SET_Direction(PORT_B, PIN_5, INPUT);
		SET_Direction(PORT_B, PIN_6, OUTPUT);
		SET_Direction(PORT_B, PIN_4, INPUT);
		SET_Direction(PORT_B, PIN_7, INPUT);
	SPI_Init_Slave();
	while(1){
		SPI_SendData(SPDR);
	}
	return 0;
}
