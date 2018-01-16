/*
 * TimerLED.c
 *
 * Created: 10/1/2017 7:11:14 PM
 *  Author: IbrahimGomaa
 */ 


#include <avr/io.h>
#include "STDMACROS.h"
#include "Timers.h"
#include <avr/interrupt.h>

volatile char count1 = 0;
volatile char count2 = 0;
volatile short count3 = 0;

int main(void)
{
	
	sei();
	/*Timer0_vInitComp();*/
	Timer1_vInitComp();
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
    while(1)
	
    {
		if (count1>=10)
		{
			TOGGLE_BIT(PORTD,5);
			count1=0;
		}
		else
		{
			
		}
		if (count2>=20)
		{
			TOGGLE_BIT(PORTD,6);
			count2=0;
		}
		else
		{
			
		}
		
		if (count3>=30)
		{
			TOGGLE_BIT(PORTD,7);
			count3=0;
		}
		else
		{
			
		}			
        //TODO:: Please write your application code 
    }
}
/*ISR(TIMER0_COMP_vect)
{
	count1++;
	count2++;
	count3++;
}*/
ISR(TIMER1_COMPA_vect)
{
	count1++;
	count2++;
	count3++;
}