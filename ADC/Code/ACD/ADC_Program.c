/*
 * ADC_Program.c
 *
 * Created: 2023-02-25 04:56:43 PM
 *  Author: MGAMAL15
 */ 
#ifndef ADC_PROGRAM_C_
#define ADC_PROGRAM_C_

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "ADC_Interface.h"

void ADC_Init()
 //Reference Voltage is AVCC 
{
  SET_BIT(ADMUX,6);
  CLR_BIT(ADMUX,7);
  
  //Right Adjustment for ADC
  CLR_BIT(ADMUX,5);
  
  //Prescaler of 127
  SET_BIT(ADCSRA,0);
  SET_BIT(ADCSRA,1);
  SET_BIT(ADCSRA,2);
  
  //ADC Enable
 SET_BIT(ADCSRA,7);
}


void ADC_Start(u8 Channel)
{
	//Clear first 5 bits of ADMUX
	ADMUX &= 0b11100000; 
	//Set first 5 bits of ADMUX with the channel
	ADMUX |= Channel;
	SET_BIT(ADCSRA,6);
	while(!GET_BIT(ADCSRA,4)); // wait until the conversion is complete
	
}


u16 ADC_Result()
{
	return ADC_Data;
}

//Function to convert the digital value That converted from analog 
//to display it as analog voltage on the LCD

u16 Analog_Value(u16 Digital_Value)
{
	u16 Analog;
	Analog = Digital_Value*(5000UL)/1024; //Analog = Digital_Value * voltage max value/ 2^10
	//Analog = Analog/1000; //Convert from mV to Voltage
	return Analog;
}

#endif /* ADC_PROGRAM_C_ */