/*
 * KeyPad.c
 *
 * Created: 10/5/2017 5:38:09 PM
 *  Author: IbrahimGomaa
 */ 


#include "KeyPad.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIODriver.h"
#include "LCD8bit.h"

int main(void)
{
	KeyPad_vInit(); 
	/*DDRA=0xff;*/
	LCD_vInit();
	/*LCD_vSendData(KeyPad_vPressedKey());*/
    while(1)
    {
	char x;
	x=KeyPad_vPressedKey();
	_delay_ms(210);
	if (x!=0xff)
	{
		if (x=='c')
		{
			LCD_vClearScreen();
		} 
		else
		{
			LCD_vSendData(x);
		}
		
	}
		
	PORTA=KeyPad_vPressedKey();
    }
}