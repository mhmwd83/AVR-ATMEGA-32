/*
 * ADC_Interface.h
 *
 * Created: 2023-02-25 04:56:08 PM
 *  Author: MGAMAL15
 */ 
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADMUX *((volatile u8*)0x27)
#define ADCSRA *((volatile u8*)0x26)
#define ADCH *((volatile u8*)0x25)
#define ADCL *((volatile u8*)0x24)
#define ADC_Data *((volatile u16*)0x24)
#define SFIOR *((volatile u8*)0x50)

void ADC_Init();
void ADC_Start(u8 Channel);
u16 ADC_Result();
u16 Analog_Value(u16 Digital_Value);

#endif /* ADC_INTERFACE_H_ */
