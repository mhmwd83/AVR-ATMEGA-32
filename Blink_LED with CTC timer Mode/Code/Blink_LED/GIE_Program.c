/*
 * GIE_Program.c
 *
 *  Created on: Jul 5, 2022
 *      Author: hazemahmed
 */

#include"BIT_OP.h"
#include"STD_TYPES.h"]
#include"GIE_Interface.h"
void Interrupt_Enable(){
	SET_BIT(SREG,7);
}
