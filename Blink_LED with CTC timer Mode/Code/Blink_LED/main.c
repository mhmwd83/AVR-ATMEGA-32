/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */
#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"GIE_Interface.h"
#include"Timer_Interface.h"
#include"DIO_Interface.h"

#define F_CPU 8000000UL //8MHz Clock frequency


int main(){
	SET_Direction(PORT_C, PIN_7, OUTPUT);
	Timer_Set_CTC(250);
	Timer_Init();
	Interrupt_Enable();
	while(1){

	}
	return 0;
}

void __vector_10(void)  __attribute__((signal));
void __vector_10(void){
	static u8 flag=0;
	static u8 count =0;
	count++;
	if(count==250){
		if(flag==0){
			SET_Value(PORT_C, PIN_7, HIGH);
			flag=1;

		}
		else if(flag==1){
			SET_Value(PORT_C, PIN_7, LOW);
			flag=0;

			count=0;
		}
	}

}

