/*
 * Servo_Program.c
 *
 * Created: 2023-02-25 08:14:19 PM
 *  Author: MGAMAL15
 */ 
#ifndef SERVO_PROGRAM_C_
#define SERVO_PROGRAM_C_

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "Servo_Interface.h"

void Timer1_Init()
{
	//Set Timer1 to be in PWM fast mode
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	
	//Set non inverting mode for fast PWM
	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);
	
	//Set the prescaler to 8
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	
}

void SET_TOP_Value(u16 Top_Value)
{
	 ICR1 = Top_Value;
}
void SET_OCR_Value(u16 OCR_Value)
{
	OCR1 = OCR_Value;
}

#endif /* SERVO_PROGRAM_C_ */