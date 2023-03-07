/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "I2C_Interface.h"
#include "DIO_Interface.h"

#define F_CPU 8000000UL //1MHz Clock frequency
#include <util/delay.h>  // For delay function


int main(){
	SET_Direction(PORT_C, PIN_7, HIGH);
	TWI_SLAVE_INIT(0x20);
	u8 data;
	while(1){
		TWI_SLAVE_READ_ADDRESS_MATCH();
		data=TWI_SLAVE_READ();
		if(data==1){
			SET_Value(PORT_C, PIN_7, HIGH);
		}
		else if(data==0){
			SET_Value(PORT_C, PIN_7, LOW);
		}
	}
	return 0;
}

