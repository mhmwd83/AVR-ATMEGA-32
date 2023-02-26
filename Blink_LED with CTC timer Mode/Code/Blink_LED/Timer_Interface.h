/*
 * Timer_Interface.h
 *
 *  Created on: Jul 6, 2022
 *      Author: hazemahmed
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define OCR0 *((volatile u8*)0x5C)
#define TIMSK *((volatile u8*)0x59)
#define TIFR *((volatile u8*)0x58)

/* Timer Modes
 1- Normal_Mode
 2- CTC_Mode
 3-Fast_PWM
 4-Phase_Correct_PWM
 */
#define Timer_Mode CTC_Mode

#define Normal_Mode 0
#define CTC_Mode 1
#define Fast_PWM 2
#define Phase_Correct_PWM 3

/* OC0 Operation
 1- Toggle
 2- Clear
 3- Set
 4-Off
 */
#define OC_Operation Off

#define Toggle 0
#define Clear 1
#define Set 2
#define Off 3

/*Interrupt enable
 * Normal_Mode_Interrupt
 * CTC_Mode_Interrupt
 */
#define Timer_Interrupt_Enable CTC_Mode_Interrupt

#define Normal_Mode_Interrupt 0
#define CTC_Mode_Interrupt 1
void Timer_Init();
void Timer_Set_Preload(u8 Preload_value);
void Timer_Set_CTC(u8 CTC_Value);
#endif /* TIMER_INTERFACE_H_ */
