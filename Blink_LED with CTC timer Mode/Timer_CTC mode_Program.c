/*
 * Timer_Program.c
 *
 *  Created on: Mar 03, 2023
 *      Author: Mahmoud Gamal
 */

#include"BIT_OP.h"
#include"STD_TYPES.h"
#include"Timer_Interface.h"

// Global pointer to function to be used in callback
void (*TIMER0_pvGlobCallBackFunc)(void) = NULL;


// Initialize Timer 0
void TIMER0_voidTimer0Init(void)
{

	/********** Waveform Generation Mode **********/
#if WAVE_FORM_GENERATION_MODE == NORMAL
	CLR_BIT(TCCR0, TCCR0_WGM00);
	CLR_BIT(TCCR0, TCCR0_WGM01);
	
#elif WAVE_FORM_GENERATION_MODE == CTC
	// Wave Form Generation
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	
#elif WAVE_FORM_GENERATION_MODE == PWM_PHASE_CORRECT
	SET_BIT(TCCR0, TCCR0_WGM00);
	CLR_BIT(TCCR0, TCCR0_WGM01);

#elif WAVE_FORM_GENERATION_MODE == FAST_PWM
	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);

#else
#error "Wrong Wave Form Generation Mode"

#endif


	/********** Compare Match Output Pin Mode *********/

	//===================================================
	// Compare Match Output Mode: Non-PWM (Normal or CTC)
	//===================================================
#if (WAVE_FORM_GENERATION_MODE == NORMAL) || (WAVE_FORM_GENERATION_MODE == CTC)

#if COMPARE_OUTPUT_MODE_NON_PWM_MODE == NORMAL_PORT_OPERATION_OC0_PINB3_DISCONNECTED
	CLR_BIT(TCCR0, TCCR0_COM00);
	CLR_BIT(TCCR0, TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE_NON_PWM_MODE == TOGGLE_OC0_PINB3_ON_COMPARE_MATCH
	SET_BIT(TCCR0, TCCR0_COM00);
	CLR_BIT(TCCR0, TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE_NON_PWM_MODE == CLEAR_OC0_PINB3_ON_COMPARE_MATCH
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE_NON_PWM_MODE == SET_OC0_PINB3_ON_COMPARE_MATCH
	SET_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);
#else
#error "Wrong Wave Compare Output Mode"
#endif

#endif


	//===================================================
	// Compare Match Output Mode: Fast PWM
	//===================================================
#if WAVE_FORM_GENERATION_MODE == FAST_PWM

#if COMPARE_OUTPUT_MODE_FAST_PWM_MODE == NORMAL_PORT_OPERATION_OC0_PINB3_DISCONNECTED
	CLR_BIT(TCCR0, TCCR0_COM00);
	CLR_BIT(TCCR0, TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE_FAST_PWM_MODE == RESERVED
	SET_BIT(TCCR0, TCCR0_COM00);
	CLR_BIT(TCCR0, TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE_FAST_PWM_MODE == CLEAR_OC0_PINB3_ON_COMPARE_MATCH_SET_OC0_PINB3_AT_TOP
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE_FAST_PWM_MODE == SET_OC0_PINB3_ON_COMPARE_MATCH_CLEAR_OC0_PINB3_AT_TOP
	SET_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);
#else
#error "Wrong Wave Compare Output Mode"
#endif

#endif

	//===================================================
	// Compare Match Output Mode: PWM Phase Correct
	//===================================================
#if WAVE_FORM_GENERATION_MODE == PWM_PHASE_CORRECT

#if COMPARE_OUTPUT_MODE_PHASE_CORRECT_PWM_MODE == NORMAL_PORT_OPERATION_OC0_PINB3_DISCONNECTED
	CLR_BIT(TCCR0, TCCR0_COM00);
	CLR_BIT(TCCR0, TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE_PHASE_CORRECT_PWM_MODE == RESERVED
	SET_BIT(TCCR0, TCCR0_COM00);
	CLR_BIT(TCCR0, TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE_PHASE_CORRECT_PWM_MODE == Clear_OC0_PINB3_on_compare_match_when_up_counting_Set_OC0_PINB3_on_compare_match_when_downcounting
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);
#elif COMPARE_OUTPUT_MODE_PHASE_CORRECT_PWM_MODE == Set_OC0_PINB3_on_compare_match_when_up_counting_Clear_OC0_PINB3_on_compare_match_when_downcounting
	SET_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);
#else
#error "Wrong Wave Compare Output Mode"
#endif

#endif


	/************ Pre-scaler Clock Select ************/
#if PRE_SCALER_SELECT == NO_CLOCK_SOURCE
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

#elif PRE_SCALER_SELECT == NO_PRE_SCALING
	SET_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

#elif PRE_SCALER_SELECT == PRE_SCALER_8
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

#elif PRE_SCALER_SELECT == PRE_SCALER_64
	SET_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

#elif PRE_SCALER_SELECT == PRE_SCALER_256
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);

#elif PRE_SCALER_SELECT == PRE_SCALER_1024
	SET_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);

#elif PRE_SCALER_SELECT == EXTERNAL_CLOCK_SOURCE_ON_T0_PIN_ON_FALLING_EDGE
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);

#elif PRE_SCALER_SELECT == EXTERNAL_CLOCK_SOURCE_ON_T0_PIN_ON_RISING_EDGE
	SET_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);

#else
#error	"Wrong Pre-scaler Select"

#endif

	// Output Compare Value: Set to COMP_MATCH_VAL_CTC_MODE
	OCR0 = COMP_MATCH_VAL_CTC_MODE;

	// Enable Compare-Match Interrupt
	SET_BIT(TIMSK, TIMSK_OCIE0);
}


// Set compare match value via function when using Fast PWM Mode (Change value -> Change Feeding signal power)
void Timer0_voidSetCompareMatchVal(u8 copy_uoCompMatch)
{
	OCR0 = copy_uoCompMatch;
}


// Callback function to Timer0 ISR
void TIMER0_voidSetCallBack(void (*copy_pvUserFunc)(void))
{
	if(copy_pvUserFunc != NULL)
	{
		TIMER0_pvGlobCallBackFunc = copy_pvUserFunc;
	}
}


// ISR for Timer0
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvGlobCallBackFunc != NULL)
	{
		TIMER0_pvGlobCallBackFunc();
	}
}