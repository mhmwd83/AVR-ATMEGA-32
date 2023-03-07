/*
 * SPI.c
 *
 * Created: 2023-03-06 10:15:45 PM
 *  Author: MGAMAL15
 */ 
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "I2C_Interface.h"

void TWI_MASTER_INIT(u8 Master_Address).
{
	if(Master_Address!=0)
	  {
		TWAR=Master_Address<<1;
	  }
	else
	 {

	 }
	SET_BIT(TWCR,6);
	SET_BIT(TWCR,2);
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	TWBR=3;

}
void TWI_SLAVE_INIT(u8 Slave_Address){
	TWAR=Slave_Address<<1;
	SET_BIT(TWCR,6);
	SET_BIT(TWCR,2);
}
ERRORS TWI_SEND_START_CONDITION(){
	ERRORS err=NO_ERROR;
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,7);
	while(!GET_BIT(TWCR,7));
	if((TWSR&0b11111000)!=0x08)
	err=START_ERROR;
	else
	{

	}
	return err;

}
ERRORS TWI_SEND_REPEATED_START_CONDITION(){
	ERRORS err=NO_ERROR;
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,7);
	while(!GET_BIT(TWCR,7));
	if((TWSR&0b11111000)!=0x10)
	err=REPEATED_START_ERROR;
	else
	{

	}
	return err;
}
ERRORS TWI_SEND_SLAVE_ADDRESS_WITH_WRITE(u8 Slave_Address){
	ERRORS err=NO_ERROR;
	TWDR=Slave_Address<<1;
	CLR_BIT(TWDR,0);
	CLR_BIT(TWCR,5);
	SET_BIT(TWCR,7);
	while(!GET_BIT(TWCR,7));
	if((TWSR&0b11111000)!=0x18)
	err=SLAVE_ADDRESSS_WRITE_ERROR;
	else
	{

	}
	return err;

}
ERRORS TWI_SEND_SLAVE_ADDRESS_WITH_READ(u8 Slave_Address){
	ERRORS err=NO_ERROR;
	TWDR=Slave_Address<<1;
	SET_BIT(TWDR,0);
	CLR_BIT(TWCR,5);
	SET_BIT(TWCR,7);
	while(!GET_BIT(TWCR,7));
	if((TWSR&0b11111000)!=0x40)
	err=SLAVE_ADDRESSS_READ_ERROR;
	else
	{

	}
	return err;
}
ERRORS TWI_MASTER_SEND_DATA(u8 data){
	ERRORS err=NO_ERROR;
	TWDR=data;
	SET_BIT(TWCR,7);
	while(!GET_BIT(TWCR,7));
	if((TWSR&0b11111000)!=0x28)
	err=MASTER_SEND_ERROR;
	else
	{

	}
	return err;
}
ERRORS TWI_MASTER_RECEIVE_DATA(u8* data){
	ERRORS err=NO_ERROR;
	SET_BIT(TWCR,7);
	while(!GET_BIT(TWCR,7));
	if((TWSR&0b11111000)!=0x50)
	err=MASTER_SEND_ERROR;
	else
	{
		*data=TWDR;

	}
	return err;
}
void TWI_SLAVE_READ_ADDRESS_MATCH(){
	while((TWSR&0b11111000)!=0x60){
		SET_BIT(TWCR,7);
		while(!GET_BIT(TWCR,7));
	}
}
u8 TWI_SLAVE_READ(){
	u8 data=0;
	SET_BIT(TWCR,7);
	while(!GET_BIT(TWCR,7));
	if((TWSR&0b11111000)!=0x80){

	}
	else{
		data=TWDR;
	}
	return data;
}
void TWI_SLAVE_WRITE_ADDRESS_MATCH(){

	while((TWSR&0b11111000)!=0xA8){
		SET_BIT(TWCR,7);
		while(!GET_BIT(TWCR,7));
	}
}
void TWI_SLAVE_WRITE(u8 data){
	TWDR=data;
	SET_BIT(TWCR,7);
	while(!GET_BIT(TWCR,7));
	while((TWSR&0b11111000)!=0xC0);
}

void TWI_SEND_STOP_CONDITION(){
	SET_BIT(TWCR,4);
	SET_BIT(TWCR,7);

}