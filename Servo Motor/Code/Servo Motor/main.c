/*
 * Servo Motor.c
 *
 * Created: 2023-01-31 05:22:12 PM
 * Author : MGAMAL15
 */ 
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Servo_Interface.h"

#define F_CPU 8000000UL //8MHz Clock frequency
#include <util/delay.h>  // For delay function

int main()
{
    SET_Direction(PORT_D,PIN_5,OUTPUT); //OCR1 to be output
    SET_TOP_Value(20000); //Time for overflow
	SET_OCR_Value(1499); //Zero Degree
	Timer1_Init();
	_delay_ms(2000); 
	SET_OCR_Value(999); //-90 degree
	_delay_ms(2000);
	SET_OCR_Value(2000); //+90 degree
	_delay_ms(2000);
	SET_OCR_Value(1499);
	
  while (1) 
  {
	  
  }

	return 0;	
}


