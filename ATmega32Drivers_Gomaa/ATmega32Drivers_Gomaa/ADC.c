/*
 * ADC.c
 *
 * Created: 10/1/2017 5:33:33 PM
 *  Author: IbrahimGomaa
 */ 
#include "STDMACROS.h"
#include <avr/io.h>
#include "ADC.h"
#include "SevSegD.h"
#include "DIODriver.h"
void ADC_vInitialize()
{
	SET_BIT(ADMUX,6);
	SET_BIT(ADCSRA,7);	
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
}
char ADC_u8ReadData()
{
	char x,temp;
	SET_BIT(ADCSRA,6);
	while(READ_BIT(ADCSRA,ADIF)==0)
	{
		
	}
	
	x=ADCL;
	temp=ADCH;
	return x;
}