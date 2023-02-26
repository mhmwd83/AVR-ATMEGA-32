/*
 * Servo_Interface.h
 *
 * Created: 2023-02-25 08:13:58 PM
 *  Author: MGAMAL15
 */ 
#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)
#define ICR1 *((volatile u16*)0x46)
#define OCR1 *((volatile u16*)0x4A)

void Timer1_Init();
void SET_TOP_Value(u16 Top_Value);
void SET_OCR_Value(u16 OCR_Value);


#endif /* SERVO_INTERFACE_H_ */