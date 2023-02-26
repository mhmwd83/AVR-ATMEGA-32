/*
 * GIE_Interface.h
 *
 *  Created on: Jul 5, 2022
 *      Author: hazemahmed
 */

#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

#define SREG *((volatile u8 *)0x5F)

void Interrupt_Enable();
#endif /* GIE_INTERFACE_H_ */
