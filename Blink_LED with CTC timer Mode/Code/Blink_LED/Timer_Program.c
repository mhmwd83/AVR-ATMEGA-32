/*
 * Timer_Program.c
 *
 *  Created on: Mar 03, 2023
 *      Author: Mahmoud Gamal
 */

#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"Timer_Interface.h"


#ifndef TIMER_PROGRAM_H_
#define TIMER_PROGRAM_H_

void Timer1_init()
{
	
	// set up timer with CTC mode
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	// set up timer with prescaler = 1024
	SET_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	
	// initialize counter
	TCNT1 = 0;
}


void SET_OCR_Value(u16 OCR_Value)
{
	OCR1 = OCR_Value;
}




#endif /* TIMER_PROGRAM_H_ */
