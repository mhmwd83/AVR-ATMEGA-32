/*
 * Timer_Interface.h
 *
 *  Created on: Mar 03, 2023
 *      Author: Mahmoud Gamal
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

//*******  TIMER1 Registers *********//

// Timer0 Control register - TCCR0
#define TCCR1A			*((volatile u8*) 0x4F)

// Timer/Counter0 register
#define TCCR1B			*((volatile u8*) 0x4E)


// Compare Match register
#define OCR1			*((volatile u16*) 0x4A)

// Counter 1 register
#define TCNT1			*((volatile u16*) 0x4C)

// Timer 1  interrupt register
#define ICR1 *((volatile u16*)0x46)


// Timer1 flag
#define TIFR			*((volatile u8*) 0x58)


void Timer1_init(void);

void SET_OCR_Value(u16 OCR_Value);



#endif /* TIMER_INTERFACE_H_ */
