/*
 * External Interrupt.c
 *
 * Created: 2023-01-31 05:22:12 PM
 * Author : MGAMAL15
 */ 
#define F_CPU 8000000UL //8MHz Clock frequency
#include <util/delay.h>  // For delay function

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "GIE_Interface.h"
#include "EXTI_Interface.h"
#include "DIO_Interface.h"


int main()
{
    SET_Direction(PORT_D,PIN_2,INPUT);
	SET_Direction(PORT_C,PIN_7,OUTPUT);
	SET_Value(PORT_D,PIN_2,HIGH);
	EXTI_Enable(0); //to enable external interrupt 0
	Interrupt_Enable(); //for General interrupt enable
	u8 flag=0;
    while (1) 
    {
		if(flag==0)
		{
			SET_Value(PORT_C,PIN_7,HIGH);
			flag=1;
		}
		else if(flag==1)
		{
			SET_Value(PORT_C,PIN_7,LOW);
			flag=0;
		}
		_delay_ms(500);
    }
	return 0;
}

//this  __attribute__((signal)) to tell the processor that is a function called by the hardware
void __vector_1(void)  __attribute__((signal));
void __vector_1(void){
	SET_Value(PORT_C, PIN_7,HIGH);
	_delay_ms(2000);
}

