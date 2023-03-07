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
	SET_Direction(PORT_B, PIN_0, INPUT);
	SET_Value(PORT_B, PIN_0, HIGH);
	TWI_MASTER_INIT(0);
	TWI_SEND_START_CONDITION();
	TWI_SEND_SLAVE_ADDRESS_WITH_WRITE(0x20);
	while(1){
		if((GET_Value(PORT_B, PIN_0))==LOW){
			TWI_MASTER_SEND_DATA(1);
		}
		else if((GET_Value(PORT_B, PIN_0))==HIGH){
			TWI_MASTER_SEND_DATA(0);
		}
		_delay_ms(200);
		TWI_SEND_REPEATED_START_CONDITION();
		TWI_SEND_SLAVE_ADDRESS_WITH_WRITE(0x20);
	}
	return 0;
}

