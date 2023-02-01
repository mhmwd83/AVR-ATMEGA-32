/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */
#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"
#define F_CPU 8000000UL //8MHz Clock frequency
#include <util/delay.h>  // For delay function

int main(){
	SET_Direction_4LSB(PORT_C, OUTPUT);
	//Enable for the first 7-segment
	SET_Direction(PORT_C, PIN_4, OUTPUT);
	//Enable for the second 7-segment
	SET_Direction(PORT_C, PIN_5, OUTPUT);
	u8 current_number1=0;
	u8 current_number2=0;
	while(1){
		if(current_number1==9){
			current_number1=0;
			current_number2++;
		}
		else{
			current_number1++;
		}
		// A loop so that the same number keeps repeating before going to the next number
		for(u8 i=0;i<15;i++){
			//Since we are using common cathode displays, LOW will turn them on
			SET_Value(PORT_C, PIN_4, LOW);
			SET_Value_4LSB(PORT_C,current_number1);
			_delay_ms(100);
			SET_Value(PORT_C, PIN_4, HIGH);
			SET_Value(PORT_C, PIN_5, LOW);
			SET_Value_4LSB(PORT_C,current_number2);
			_delay_ms(100);
			SET_Value(PORT_C, PIN_5, HIGH);


		}

	}
	return 0;
}


