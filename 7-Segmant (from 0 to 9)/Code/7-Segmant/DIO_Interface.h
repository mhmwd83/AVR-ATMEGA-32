/*
 * DIO_Interface.h
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*    PORT A    */
#define PORTA (*(volatile u8*)(0x3B))    //Register contain output value

#define DDRA (*(volatile u8*)(0x3A))    //Register to set port direction input or output

#define PINA (*(volatile u8*)(0x39))   //Register contain input value


/*    PORT B    */
#define PORTB (*(volatile u8*)(0x38))    //Register contain output value

#define DDRB (*(volatile u8*)(0x37))    //Register to set port direction input or output

#define PINB (*(volatile u8*)(0x36))   //Register contain input value


/*    PORT C    */
#define PORTC (*(volatile u8*)(0x35))    //Register contain output value

#define DDRC (*(volatile u8*)(0x34))    //Register to set port direction input or output

#define PINC (*(volatile u8*)(0x33))   //Register contain input value


/*    PORT D    */
#define PORTD (*(volatile u8*)(0x32))    //Register contain output value

#define DDRD (*(volatile u8*)(0x31))    //Register to set port direction input or output

#define PIND (*(volatile u8*)(0x30))   //Register contain input value



#define INPUT 0   //For input port direction
#define OUTPUT 1 //For output port direction

#define LOW 0   //For set pin value to 0
#define HIGH 1 //For set pin value to 1


/* define PINS as enum    */
typedef enum
{
	PIN_0,         //0
	PIN_1,        //1
	PIN_2,       //2
	PIN_3,      //3
	PIN_4,     //4
	PIN_5,    //5
	PIN_6,   //6
	PIN_7,  //7

}PINS;


/* define PORTS as enum    */
typedef enum
{
	PORT_A,         //0
	PORT_B,        //1
	PORT_C,       //2
	PORT_D,      //3

}PORTS;



/*   Function to set the direction of the pin    */
void SET_Direction(u8 port, u8 pin, u8 direction);

/*   Function to set the value of the pin    */
void SET_Value(u8 port, u8 pin, u8 value);

/*   Function to get the value of the pin    */
u8 GET_Value(u8 port, u8 pin); //not void because I will return the value of the pin

/*   Function to set the direction of the 4LSB pins   */
void SET_Direction_4LSB(u8 port, u8 direction);

/*   Function to set the value of the 4LSB pins    */
void SET_Value_4LSB(u8 port, u8 value);

/*   Function to get the value of the 4LSB pins    */
void GET_Value_4LSB(u8 port, u8 value);

/*   Function to set the direction of the 4MSB pins   */
void SET_Direction_4MSB(u8 port, u8 direction);

/*   Function to set the value of the 4MSB pins    */
void SET_Value_4MSB(u8 port, u8 value);

/*   Function to get the value of the 4MSB pins    */
void GET_Value_4MSB(u8 port, u8 value);


#endif /* DIO_INTERFACE_H_ */
