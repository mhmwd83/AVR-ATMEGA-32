/*
 * Timer_Program.c
 *
 *  Created on: Jul 6, 2022
 *      Author: hazemahmed
 */

#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"Timer_Interface.h"
void Timer_Init(){
#if Timer_Mode==Normal_Mode
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
#elif Timer_Mode==CTC_Mode
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	switch(OC_Operation){
	case Toggle:
		CLR_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
		break;
	case Clear:
		SET_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
		break;
	case Set:
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
		break;
	case Off:
		CLR_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);
		break;


	}
#elif Timer_Mode==Fast_PWM
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);
#elif Timer_Mode==Phase_Correct_PWM
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
#else
#error "Wrong Timer mode"
#endif
	SET_BIT(TCCR0,2);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,0);
#if Timer_Interrupt_Enable==Normal_Mode_Interrupt
	SET_BIT(TIMSK,0);
#elif Timer_Interrupt_Enable==CTC_Mode_Interrupt
	SET_BIT(TIMSK,1);
#endif
}
void Timer_Set_Preload(u8 Preload_value){
	TCNT0=Preload_value;
}
void Timer_Set_CTC(u8 CTC_Value){
	OCR0=CTC_Value;
}
