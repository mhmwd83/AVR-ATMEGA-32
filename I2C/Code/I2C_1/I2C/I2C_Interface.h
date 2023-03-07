/*
 * SPI.h
 *
 * Created: 2023-03-06 10:16:08 PM
 *  Author: MGAMAL15
 */ 
#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#define TWBR *((volatile u8*)0x20)
#define TWCR *((volatile u8*)0x56)
#define TWSR *((volatile u8*)0x21)
#define TWAR *((volatile u8*)0x22)
#define TWDR *((volatile u8*)0x23)

typedef enum{
	NO_ERROR,
	START_ERROR,
	REPEATED_START_ERROR,
	SLAVE_ADDRESSS_WRITE_ERROR,
	SLAVE_ADDRESSS_READ_ERROR,
	MASTER_SEND_ERROR,
	MASTER_RECEIVE_ERROR
}ERRORS;

void TWI_MASTER_INIT(u8 Master_Address);
void TWI_SLAVE_INIT(u8 Slave_Address);
ERRORS TWI_SEND_START_CONDITION();
ERRORS TWI_SEND_REPEATED_START_CONDITION();
ERRORS TWI_SEND_SLAVE_ADDRESS_WITH_WRITE(u8 Slave_Address);
ERRORS TWI_SEND_SLAVE_ADDRESS_WITH_READ(u8 Slave_Address);
ERRORS TWI_MASTER_SEND_DATA(u8 data);
ERRORS TWI_MASTER_RECEIVE_DATA(u8* data);
void TWI_SLAVE_READ_ADDRESS_MATCH();
u8 TWI_SLAVE_READ();
void TWI_SLAVE_WRITE_ADDRESS_MATCH();
void TWI_SLAVE_WRITE(u8 data);
void TWI_SEND_STOP_CONDITION();


#endif /*  I2C_INTERFACE_H_ */