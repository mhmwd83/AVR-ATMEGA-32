/*
 * Timer_Interface.h
 *
 *  Created on: Mar 03, 2023
 *      Author: Mahmoud Gamal
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

//*******  TIMER0 Registers *********//

// Timer0 Control register - TCCR0
#define TCCR0			*((volatile u8*) 0x53)
// Timer0 Control register bits
#define TCCR0_FOC0		7		/* Force output compare*/
#define TCCR0_WGM00		6		/* Wave generation mode bit0*/
#define TCCR0_COM01		5		/* OC0 pin action bit1*/
#define TCCR0_COM00		4		/* OC0 pin action bit0*/
#define TCCR0_WGM01		3		/* Wave generation mode bit1*/
#define TCCR0_CS02		2		/* Pre-scaler value bit2*/
#define TCCR0_CS01		1		/* Pre-scaler value bit1*/
#define TCCR0_CS00		0		/* Pre-scaler value bit0*/

// Timer/Counter0 register
#define TCNT0			*((volatile u8*) 0x52)


// Compare Match register
#define OCR0			*((volatile u8*) 0x5C)


// Timer0 Interrupt Mask
#define TIMSK			*((volatile u8*) 0x59)
// Timer0 Interrupt Mask bits
#define TIMSK_OCIE0		1		/* Output compare 0 interrupt flag*/
#define TIMSK_TOIE0		0		/* Overflow 0 interrupt flag*/


// Timer0 flag
#define TIFR			*((volatile u8*) 0x58)


//*******  TIMER0 Modes and config  *********//


/********** Wave Generation Mode Select **********/
/* Wave Generation Mode Select
 * 1. NORMAL
 * 2. PWM_PHASE_CORRECT
 * 3. CTC
 * 4. FAST_PWM
 */
#define NORMAL				0
#define PWM_PHASE_CORRECT	1
#define CTC					2
#define FAST_PWM			3

//Select Timer config as you need
#define WAVE_FORM_GENERATION_MODE		CTC

// Clear on compare match value (used only with CTC mode)
#define COMP_MATCH_VAL_CTC_MODE			2



/********** Compare Match Output Pin Mode *********/
/* Compare Output Mode, non-PWM Mode (Normal Mode or CTC Mode)
 * 1. NORMAL_PORT_OPERATION_OC0_PINB3_DISCONNECTED
 * 2. TOGGLE_OC0_PINB3_ON_COMPARE_MATCH
 * 3. CLEAR_OC0_PINB3_ON_COMPARE_MATCH
 * 4. SET_OC0_PINB3_ON_COMPARE_MATCH
 */
#define NORMAL_PORT_OPERATION_OC0_PINB3_DISCONNECTED			4
#define TOGGLE_OC0_PINB3_ON_COMPARE_MATCH						5
#define CLEAR_OC0_PINB3_ON_COMPARE_MATCH						6
#define SET_OC0_PINB3_ON_COMPARE_MATCH							7

//Select Timer config as you need
#define COMPARE_OUTPUT_MODE_NON_PWM_MODE			TOGGLE_OC0_PINB3_ON_COMPARE_MATCH



/* Compare Output Mode, Fast PWM Mode
 * 1. NORMAL_PORT_OPERATION_OC0_PINB3_DISCONNECTED
 * 2. RESERVED
 * 3. CLEAR_OC0_PINB3_ON_COMPARE_MATCH_SET_OC0_PINB3_AT_TOP
 * 4. SET_OC0_PINB3_ON_COMPARE_MATCH_CLEAR_OC0_PINB3_AT_TOP
 */
#define RESERVED													8
#define CLEAR_OC0_PINB3_ON_COMPARE_MATCH_SET_OC0_PINB3_AT_TOP		9
#define SET_OC0_PINB3_ON_COMPARE_MATCH_CLEAR_OC0_PINB3_AT_TOP		10

//Select Timer config as you need
#define COMPARE_OUTPUT_MODE_FAST_PWM_MODE			NORMAL_PORT_OPERATION_OC0_PINB3_DISCONNECTED


/* Compare Output Mode, Phase Correct PWM Mode
 * 1. NORMAL_PORT_OPERATION_OC0_PINB3_DISCONNECTED
 * 2. RESERVED
 * 3. Clear_OC0_PINB3_on_compare_match_when_up_counting_Set_OC0_PINB3_on_compare_match_when_downcounting
 * 4. Set_OC0_PINB3_on_compare_match_when_up_counting_Clear_OC0_PINB3_on_compare_match_when_downcounting
 */
#define Clear_OC0_PINB3_on_compare_match_when_up_counting_Set_OC0_PINB3_on_compare_match_when_downcounting		11
#define Set_OC0_PINB3_on_compare_match_when_up_counting_Clear_OC0_PINB3_on_compare_match_when_downcounting		12

//Select Timer config as you need
#define COMPARE_OUTPUT_MODE_PHASE_CORRECT_PWM_MODE	NORMAL_PORT_OPERATION_OC0_PINB3_DISCONNECTED



/************ Pre-scaler Clock Select ************/
/* Pre-scaler Clock Select
 * 1. NO_CLOCK_SOURCE
 * 2. NO_PRE_SCALING
 * 3. PRE_SCALER_8
 * 4. PRE_SCALER_64
 * 5. PRE_SCALER_256
 * 6. PRE_SCALER_1024
 * 7. EXTERNAL_CLOCK_SOURCE_ON_T0_PIN_ON_FALLING_EDGE
 * 8. EXTERNAL_CLOCK_SOURCE_ON_T0_PIN_ON_RISING_EDGE
 */
#define NO_CLOCK_SOURCE										13
#define NO_PRE_SCALING										14
#define PRE_SCALER_8										15
#define PRE_SCALER_64										16
#define PRE_SCALER_256										17
#define PRE_SCALER_1024										18
#define EXTERNAL_CLOCK_SOURCE_ON_T0_PIN_ON_FALLING_EDGE		19
#define EXTERNAL_CLOCK_SOURCE_ON_T0_PIN_ON_RISING_EDGE		20

//Select Timer config as you need
#define PRE_SCALER_SELECT			PRE_SCALER_1024	


//*******  TIMER0 Interface  *********//

// Initialize Timer 0
void TIMER0_voidTimer0Init(void);

// Set compare match value via function when using Fast PWM Mode (Change value -> Change Feeding signal power)
void Timer0_voidSetCompareMatchVal(u8 copy_uoCompMatch);

// Callback function to Timer0 ISR
void TIMER0_voidSetCallBack(void (*copy_pvUserFunc)(void));



#endif /* TIMER_INTERFACE_H_ */
