/*
 * DIO_Program.c
 *
 *  Created on: Jan 26, 2023
 *      Author: MGAMAL15
 */
#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"DIO_Interface.h"

/*   Function to set the direction of the pin    */
void SET_Direction(u8 port, u8 pin, u8 direction)
{
	switch(port)
	{
	case PORT_A:
		if(direction == INPUT)
		{
			CLR_BIT(DDRA,pin);
		}

		else if(direction == OUTPUT)
		{
			SET_BIT(DDRA,pin);
		}
		break;

	case PORT_B:
		if(direction == INPUT)
		{
			CLR_BIT(DDRB,pin);
		}

		else if(direction == OUTPUT)
		{
			SET_BIT(DDRB,pin);
		}
		break;

	case PORT_C:
		if(direction == INPUT)
		{
			CLR_BIT(DDRC,pin);
		}

		else if(direction == OUTPUT)
		{
			SET_BIT(DDRC,pin);
		}
		break;

	case PORT_D:
		if(direction == INPUT)
		{
			CLR_BIT(DDRD,pin);
		}

		else if(direction == OUTPUT)
		{
			SET_BIT(DDRD,pin);
		}
		break;
	}
}


/*   Function to set the value of the pin    */
void SET_Value(u8 port, u8 pin, u8 value)
{
	switch(port)
	{
	case PORT_A:
		if(value == LOW)
		{
			CLR_BIT(PORTA,pin);
		}

		else if(value  == HIGH)
		{
			SET_BIT(PORTA,pin);
		}
		break;

	case PORT_B:
		if(value == LOW)
		{
			CLR_BIT(PORTB,pin);
		}

		else if(value == HIGH)
		{
			SET_BIT(PORTB,pin);
		}
		break;

	case PORT_C:
		if(value == LOW)
		{
			CLR_BIT(PORTC,pin);
		}

		else if(value == HIGH)
		{
			SET_BIT(PORTC,pin);
		}
		break;

	case PORT_D:
		if(value == LOW)
		{
			CLR_BIT(PORTD,pin);
		}

		else if(value == HIGH)
		{
			SET_BIT(PORTD,pin);
		}
		break;
	}

}


/*   Function to get the value of the pin    */
u8 GET_Value(u8 port, u8 pin)
{
	switch(port)
	{
	case PORT_A:
		return GET_BIT(PINA,pin);
	    break;
	case PORT_B:
		return GET_BIT(PINB,pin);
	    break;
	case PORT_C:
		return GET_BIT(PINC,pin);
	    break;
	case PORT_D:
		return GET_BIT(PIND,pin);
	    break;
	}
	return 0;
}


/*   Function to set the direction of the 4LSB pins   */
void SET_Direction_4LSB(u8 port, u8 direction)
{
	switch(port)
	{
	case PORT_A:
		if(direction == INPUT)
		{
			DDRA&=0xF0; //set 4 LSB to zero
		}

		else if(direction == OUTPUT)
		{
			DDRA|=0x0F;  //set 4 LSB to one's
		}
		break;

	case PORT_B:
		if(direction == INPUT)
		{
			DDRB&=0xF0; //set 4 LSB to zero
		}

		else if(direction == OUTPUT)
		{
			DDRB|=0x0F;  //set 4 LSB to one's
		}
		break;

	case PORT_C:
		if(direction == INPUT)
		{
			DDRC&=0xF0; //set 4 LSB to zero
		}

		else if(direction == OUTPUT)
		{
			DDRC|=0x0F;  //set 4 LSB to one's
		}
		break;

	case PORT_D:
		if(direction == INPUT)
		{
			DDRD&=0xF0; //set 4 LSB to zero
		}

		else if(direction == OUTPUT)
		{
			DDRD|=0x0F;  //set 4 LSB to one's
		}
		break;
	}
}

/*   Function to set the direction of the 4MSB pins   */
void SET_Direction_4MSB(u8 port, u8 direction)
{
	switch(port)
	{
	case PORT_A:
		if(direction == INPUT)
		{
			DDRA&=0x0F; //set 4 LSB to zero
		}

		else if(direction == OUTPUT)
		{
			DDRA|=0xF0;  //set 4 LSB to one's
		}
		break;

	case PORT_B:
		if(direction == INPUT)
		{
			DDRB&=0x0F; //set 4 LSB to zero
		}

		else if(direction == OUTPUT)
		{
			DDRB|=0xF0;  //set 4 LSB to one's
		}
		break;

	case PORT_C:
		if(direction == INPUT)
		{
			DDRC&=0x0F; //set 4 LSB to zero
		}

		else if(direction == OUTPUT)
		{
			DDRC|=0xF0;  //set 4 LSB to one's
		}
		break;

	case PORT_D:
		if(direction == INPUT)
		{
			DDRD &= 0x0F; //set 4 LSB to zero
		}

		else if(direction == OUTPUT)
		{
			DDRD|=0xF0;  //set 4 LSB to one's
		}
		break;
	}
}


/*   Function to set the value of the 4LSB pins    */
void SET_Value_4LSB(u8 port, u8 value)
{
	switch(port)
	{
	case PORT_A:
			PORTA &= 0xF0;
			PORTA |= value;
		break;

	case PORT_B:
			PORTB &= 0xF0;
			PORTB |= value;
			break;
			
	case PORT_C:
			PORTC &= 0xF0;
			PORTC |= value;
			break;

	case PORT_D:
			PORTD &= 0xF0;
			PORTD |= value;
			break;
	}

}

/*   Function to set the value of the 4MSB pins    */
void SET_Value_4MSB(u8 port, u8 value)
{
	switch(port)
	{
		case PORT_A:
		PORTA &= 0x0F;
		PORTA |= value<<4;
		break;

		case PORT_B:
		PORTB &= 0x0F;
		PORTB |= value<<4;
		break;
		
		case PORT_C:
		PORTC &= 0x0F;
		PORTC |= value<<4;
		break;

		case PORT_D:
		PORTD &= 0x0F;
		PORTD |= value<<4;
		break;
	}

}



