/*
 * GIE_Program.c
 *
 *  Created on: Jul 6, 2023
 *      Author: Mahmoud Gamal
 */

#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"GIE_Interface.h"
void Interrupt_Enable(){
	SET_BIT(SREG,7);
}
