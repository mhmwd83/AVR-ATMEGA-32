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
	SET_Direction(PORT_B, PIN_0, INPUT);
	SET_Value(PORT_B, PIN_0, HIGH);
	SET_Direction(PORT_B, PIN_5, OUTPUT);
	SET_Direction(PORT_B, PIN_6, INPUT);
	SET_Direction(PORT_B, PIN_4, OUTPUT);
	SET_Direction(PORT_B, PIN_7, OUTPUT);
	SET_Value(PORT_B, PIN_4, LOW);
	SPI_Init_Master();
	while(1){
		if(!GET_Value(PORT_B, PIN_0)){
			SPI_SendData('1');
			SPI_SendData('1');
		}
		else if(GET_Value(PORT_B, PIN_0)){
			SPI_SendData('0');
			SPI_SendData('0');
		}
	}
	return 0;
}
