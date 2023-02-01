/*
 * General Interrupt.c
 *
 * Created: 2023-01-31 06:09:27 PM
 * Author : MGAMAL15
 */ 
#include "BIT_OP.h"
#include "STD_TYPES.h"

void Interrupt_Enable()
{
 SET_BIT(SREG,7);
}

