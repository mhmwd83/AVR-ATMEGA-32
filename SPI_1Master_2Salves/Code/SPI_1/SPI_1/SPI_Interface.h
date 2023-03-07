/*
 * SPI.h
 *
 * Created: 2023-03-06 10:16:08 PM
 *  Author: MGAMAL15
 */ 
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SPDR *((volatile u8*)0x2F)
#define SPSR *((volatile u8*)0x2E)
#define SPCR *((volatile u8*)0x2D)

void SPI_Init_Master();
void SPI_Init_Slave();
u8 SPI_SendData(u8 data);


#endif /* SPI_INTERFACE_H_ */