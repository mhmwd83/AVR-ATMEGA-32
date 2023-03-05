/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Timer_Interface.h"

#define F_CPU 8000000UL //8MHz Clock frequency
#include <util/delay.h>  // For delay function

int main()
{

	SET_Direction(PORT_D,PIN_5,OUTPUT);
	Timer1_init();
	SET_OCR_Value(15624);

    // loop forever
    while(1)
    {
	    // check whether the flag bit is set
	    // if set, it means that there has been a compare match
	    // and the timer has been cleared
	    // use this opportunity to toggle the led
	    if (TIFR & (1 << 4)) // NOTE: '>=' used instead of '=='
	    {
		   PORTD ^= (1 << 5); // toggles the led
	    }
	    
	    // wait! we are not done yet!
	    // clear the flag bit manually since there is no ISR to execute
	    // clear it by writing '1' to it (as per the datasheet)
		CLR_BIT(TIFR,4); //TIFR |= (1 << OCF1A);
	    
	    
	    // yeah, now we are done!
    }
	return 0;
}

