/*
 * GIE_Interface.h
 *
 * Created: 2023-01-31 06:10:22 PM
 *  Author: MGAMAL15
 */ 
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

#define SREG (*(volatile u8*)(0x5F));
void Interrupt_Enable();

#endif /* GIE_INTERFACE_H_ */