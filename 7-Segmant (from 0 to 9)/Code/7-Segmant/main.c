/*
 * main.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */
#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"
#define F_CPU 8000000UL //1MHz Clock frequency
#include <util/delay.h>  // For delay function

int main()
{
	SET_Direction(PORT_A,PIN_2,INPUT);  
	SET_Direction_4LSB(PORT_C,OUTPUT);  
 
	SET_Value(PORT_A, PIN_2, HIGH); 
	
	u8 Current_number =0;
	
	while(1)
	{
		
		if(GET_Value(PORT_A,PIN_2) == LOW)
		   {
			   if(Current_number == 9) //to reset numbers to zero after reach 9
			      {
				    Current_number = 0;
			      }
			   else
			      {
			 	    Current_number++;
			      }
		   }
      
	  SET_Value_4LSB(PORT_C, Current_number);
	  _delay_ms(200);   // we use delay function to solve denouncing problem
	}
	return 0;
}

