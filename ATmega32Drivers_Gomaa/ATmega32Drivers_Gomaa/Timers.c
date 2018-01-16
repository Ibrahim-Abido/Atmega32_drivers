/*
 * Timer.c
 *
 * Created: 10/1/2017 7:11:47 PM
 *  Author: IbrahimGomaa
 */ 
#include <avr/io.h>
#include "STDMACROS.h"
#include "Timers.h"

void Timer0_vInitComp()
{
	/*CTC Mode*/
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*0C0 Pin disconnected*/
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
	
	/*Compare match every 10ms*/
	OCR0=78;
	/*Interrupt enable*/
	SET_BIT(TIMSK,OCIE0);
	
	/*CLK/1024*/
	SET_BIT(TCCR0,CS02);
	//SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
}
void Timer1_vInitComp()
{
	// set up timer with prescaler = 8 and CTC mode
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,CS11);
	/*SET_BIT(TCCR1B,CS10);*/
	
	// initialize counter
	TCNT1 = 0;
	
	// initialize compare value
	OCR1A = 9999;
	
	// enable compare interrupt
	SET_BIT(TIMSK,OCIE1A);
}	
void FastPWM_vInit()
{
	// initialize TCCR0 as per requirement, say as follows
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,COM01);
	
	
	// make sure to make OC0 pin (pin PB3 for atmega32) as output pin
	SET_BIT(DDRB,3);
}
void SetDutyCycle(char percent)
{
	OCR0=(percent*255)/100;
}
