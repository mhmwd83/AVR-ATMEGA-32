/*
 * LCD_Program.c
 *
 * Created: 2023-01-28 03:07:37 PM
 *  Author: MGAMAL15
 */ 
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"

#define F_CPU 8000000UL //8MHz Clock frequency
#include <util/delay.h>  // For delay function

//LCD Initialization Function
void LCD_Init()
{
	LCD_SendCommands(Function_SET>>4);   //send 4MSB
	LCD_SendCommands(Function_SET>>4);  //send 4MSB again
	LCD_SendCommands(Function_SET);    //send 4LSB
	LCD_SendCommands(Display_ON_OFF>>4);    //send ON-OFF for 4LSB
	LCD_SendCommands(Display_ON_OFF);      //send ON-OFF for 4LSB
	LCD_SendCommands(Display_Clear>>4);    //send Clear for 4LSB
	LCD_SendCommands(Display_Clear);      //send Clear for 4LSB
	_delay_ms(2);
	LCD_SendCommands(Entry_Mode>>4);   //send Entry Mode for 4MSB
	LCD_SendCommands(Entry_Mode);     //send Entry Mode for 4LSB
}

//Send Commands Function
void LCD_SendCommands(u8 Command)
{   //RS pin connected to PORT C pin 0
	SET_Value(PORT_C,PIN_0,LOW);      //Set RS pin to zero for write operation
	
	//RW pin connected to PORT C pin 1
	SET_Value(PORT_C,PIN_1,LOW);     //Set RW pin to zero for write operation
	
	//Data pins connected to the 4MSB of PORT C
	SET_Value_4MSB(PORT_C,Command); //Send command to the MSB of PORT C
	
	//EN pin connected to PORT C pin 2
	SET_Value(PORT_C,PIN_2,HIGH); //Set EN pin to 1 
	
	//Delay for 5 m sec
	_delay_ms(5);
	
	//EN pin connected to PORT C pin 2
	SET_Value(PORT_C,PIN_2,LOW); //Set EN pin to 0 
	
	//Delay for 1 m sec
	_delay_ms(1);
}

//Send Data Function
void LCD_SendData(u8 Data)
{   //RS pin connected to PORT C pin 0
	SET_Value(PORT_C,PIN_0,HIGH);      //Set RS pin to one for write operation
	
	//RW pin connected to PORT C pin 1
	SET_Value(PORT_C,PIN_1,LOW);     //Set RW pin to zero for write operation
	
	//Data pins connected to the 4MSB of PORT C
	SET_Value_4MSB(PORT_C,Data); //Send command to the MSB of PORT C
    
	//EN pin connected to PORT C pin 2
	SET_Value(PORT_C,PIN_2,HIGH); //Set EN pin to 1
	
	//Delay for 5 msec
	_delay_ms(5);
	
	//EN pin connected to PORT C pin 2
	SET_Value(PORT_C,PIN_2,LOW); //Set EN pin to 0
	
	//Delay for 1 m sec
	_delay_ms(1);
}

//Send Data with 4bits Function
void LCD_SendData_4BitMode(u8 Data)
{
	LCD_SendData(Data>>4); //Send 4MSB first
	LCD_SendData(Data);   //Send 4LSB second
}

//Send Number Function
void LCD_SendNumbers(u16 Number)
{
	u8 arr[5];
	u8 i =0;
	if (Number == 0)
	   {
	     LCD_SendData_4BitMode('0');		
	    }
   else
       {
	      while(Number !=0)
	     {
		   arr[i]= Number %10;
		   Number /= 10;
		   i++;
	      }
        }
		
	//for send array as reversed 
	for(s8 j=i-1;j>=0;j--)
	{
     LCD_SendData_4BitMode(arr[j]+48);	
	}
}


//Send String Function
void LCD_String(char *String)
{   
	for(u8 i=0;String[i] != 0;i++)
	{
		LCD_SendData_4BitMode(String[i]);
	}
}
