/*
 * LCD.c
 *
 * Created: 10/3/2017 4:34:24 PM
 *  Author: IbrahimGomaa
 */ 


#include "LCD4bits.h"
#include <avr/io.h>
#include <avr/io.h>
#include "STDMACROS.h"
#include "LCD8bit.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define EN 0
#define RW 1
#define RS 2
#define FirstRow 1
#define SeconedRow 2
char count;
void LCD_vSendFallingEdge()
{
SET_BIT(PORTB,EN);
_delay_ms(2);
CLR_BIT(PORTB,EN);
_delay_ms(2);
}

void LCD_vInit()
{
	/*SET AS OUTPUT*/
	DDRA=0xff;
	SET_BIT(DDRB,EN);
	SET_BIT(DDRB,RW);
	SET_BIT(DDRB,RS);
	/*SET IT TO WRITE MODE*/
	CLR_BIT(PORTB,RW);
	LCD_vSendCommand(0x38);/*8bit mode*/
	LCD_vSendCommand(0x01);/*clear screen*/
	LCD_vSendCommand(0x0E);/*cursor on*/
}
void LCD_vSendCommand(char cmd)
{	
PORTA=cmd;
CLR_BIT(PORTB,RS);
LCD_vSendFallingEdge();
}
void LCD_vSendData(char data)
{
	PORTA=data;
	SET_BIT(PORTB,RS);
	LCD_vSendFallingEdge();
}
void LCD_vDisplayString(char* S)
{
	while(*S != 0)
	{
	
	char x = *S;
	LCD_vSendData(x);
	S++;
	count++;
	if (count==15)
	{
		LCD_vSendData('_');
		LCD_vSeconedLine();
	}
	}	
}
void LCD_vClearScreen()
{
	LCD_vSendCommand(0x01);/*clear screen*/
	count=0;
}
void LCD_vSeconedLine()
{
	LCD_vSendCommand(0xc0);
}
void LCD_vGoTo_X_Y_8bitMode(unsigned char row,unsigned char col)
{
	char temp;
	if (FirstRow==row)
	{
		temp=0x80+col-1;
		LCD_vSendCommand(temp);
	}
	else if (SeconedRow==row)
	{
		temp=0xc0+col-1;
		LCD_vSendCommand(temp);
	}
}	