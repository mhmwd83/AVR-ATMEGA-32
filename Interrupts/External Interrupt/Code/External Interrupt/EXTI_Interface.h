/*
 * EXT_Interface.h
 *
 * Created: 2023-01-31 05:23:35 PM
 *  Author: MGAMAL15
 */ 
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_Level 0
#define Any_Logical_Change 1
#define FALLING_EDGE 2
#define RISING_EDGE 3
#define Sense_Control Any_Logical_Change

#define MCUCR (*(volatile u8*)(0x55));
#define GICR (*(volatile u8*)(0x5B));

EXTI_Enable(u8 INT_NUM);



#endif /* EXTI_INTERFACE_H_ */