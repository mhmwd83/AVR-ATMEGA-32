/*
 * EXTI_Interface.c
 *
 * Created: 2023-01-31 05:24:19 PM
 *  Author: MGAMAL15
 */ 

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "GIE_Interface.h"
#include "EXTI_Interface.h"


EXTI_Enable(u8 INT_NUM)
{
	switch(INT_NUM)
	{
		case 0:
            #if Sense_Control==LOW_Level
		        CLR_BIT(MCUCR,0);
			    CLR_BIT(MCUCR,1);
            #elif Sense_Control==Any_Logical_Change
                  SET_BIT(MCUCR,0);
                  CLR_BIT(MCUCR,1);
            #elif Sense_Control==FALLING_EDGE
                  CLR_BIT(MCUCR,0);
                  SET_BIT(MCUCR,1);
            #elif Sense_Control==RISING_EDGE
                  SET_BIT(MCUCR,0);
                  SET_BIT(MCUCR,1);
           #else
           #error "Wrong Sense_Control"
           #endif
           break;
      
	  	case 1:
            #if Sense_Control==LOW_Level
	  		    CLR_BIT(MCUCR,2);
	  		    CLR_BIT(MCUCR,3);
            #elif Sense_Control==Any_Logical_Change
	  		     SET_BIT(MCUCR,2);
	  		     CLR_BIT(MCUCR,3);
            #elif Sense_Control==FALLING_EDGE
	  		     CLR_BIT(MCUCR,2);
	  		     SET_BIT(MCUCR,3);
            #elif Sense_Control==RISING_EDGE
	  		     SET_BIT(MCUCR,2);
	  		     SET_BIT(MCUCR,3);
            #else
            #error "Wrong Sense_Control"
            #endif
	  		break;
	}
	
}