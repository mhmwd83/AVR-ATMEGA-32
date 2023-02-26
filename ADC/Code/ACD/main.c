/*
 * ADC Program.c
 *
 * Created: 2023-01-31 05:22:12 PM
 * Author : MGAMAL15
 */ 
#define F_CPU 8000000UL //8MHz Clock frequency
#include <util/delay.h>  // For delay function

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "ADC_Interface.h"
#include "LCD_Interface.h"
#include "DIO_Interface.h"


int main()
{
    SET_Direction(PORT_C,PIN_0,OUTPUT);
	SET_Direction(PORT_C,PIN_1,OUTPUT);
	SET_Direction(PORT_C,PIN_2,OUTPUT);
	SET_Direction_4MSB(PORT_C,OUTPUT);
	SET_Direction(PORT_A,PIN_0,INPUT);
	
    LCD_Init();
	ADC_Init();
	
	u16 Digital;
	u16 Analog = 0;
	u16 Analog_Previous = 0;
  while (1) 
  {
   //Start Conversion (Convert analog to digital)
   ADC_Start(0); //Choose analog channel 0
   
   //Set Result to digital variable
   Digital = ADC_Result();
   
   //Convert digital to analog voltage
   Analog = Analog_Value(Digital);
   if(Analog != Analog_Previous)
      {
	    LCD_SendCommands(0x01>>4); //erase the LCD 4LSB (>>4 woring with 4bit mode)
		LCD_SendCommands(0x01); //erase the LCD 4MSB
	    LCD_SendNumbers(Analog); //Send analog data to the LCD 
		Analog_Previous = Analog;
      }
   else
      {
	      //Do nothing
       }
   _delay_ms(500);
   }
	return 0;	
}


