/*
 * LCD4bits.c
 *
 * Created: 10/3/2017 6:33:21 PM
 *  Author: IbrahimGomaa
 */ 
#include "LCD4bits.h"
#include <avr/io.h>
#include <avr/io.h>
#include "STDMACROS.h"
#include "LCD8bit.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define EN_4bit 3
#define RW_4bit 2
#define RS_4bit 1
#define FirstRow 1
#define SeconedRow 2
char count;
void LCD_vSendFallingEdge_4bit()
{
SET_BIT(PORTB,EN_4bit);
_delay_ms(2);
CLR_BIT(PORTB,EN_4bit);
_delay_ms(2);
}

void LCD_vInit_4bit()
{
	/*SET AS OUTPUT*/
	SET_BIT(DDRA,4);
	SET_BIT(DDRA,5);
	SET_BIT(DDRA,6);
	SET_BIT(DDRA,7);
	SET_BIT(DDRB,EN_4bit);
	SET_BIT(DDRB,RW_4bit);
	SET_BIT(DDRB,RS_4bit);
	/*SET IT TO WRITE MODE*/
	CLR_BIT(PORTB,RW_4bit);
	LCD_vSendCommand_4bit(0x02);/*4bit mode*/
	LCD_vSendCommand_4bit(0x28);/*2*16 mode*/
	LCD_vSendCommand_4bit(0x01);/*clear screen*/
	LCD_vSendCommand_4bit(0x0E);/*cursor on*/
	LCD_vSendCommand_4bit(0x80);/*cursor on*/
	_delay_ms(20);
}

void LCD_vSendCommand_4bit(char cmd)
{	
	(READ_BIT(cmd,7))?(SET_BIT(PORTA,7)):(CLR_BIT(PORTA,7));
	(READ_BIT(cmd,6))?(SET_BIT(PORTA,6)):(CLR_BIT(PORTA,6));
	(READ_BIT(cmd,5))?(SET_BIT(PORTA,5)):(CLR_BIT(PORTA,5));
	(READ_BIT(cmd,4))?(SET_BIT(PORTA,4)):(CLR_BIT(PORTA,4));
	CLR_BIT(PORTB,RS_4bit);
	LCD_vSendFallingEdge_4bit();
	(READ_BIT(cmd,3))?(SET_BIT(PORTA,7)):(CLR_BIT(PORTA,7));
	(READ_BIT(cmd,2))?(SET_BIT(PORTA,6)):(CLR_BIT(PORTA,6));
	(READ_BIT(cmd,1))?(SET_BIT(PORTA,5)):(CLR_BIT(PORTA,5));
	(READ_BIT(cmd,0))?(SET_BIT(PORTA,4)):(CLR_BIT(PORTA,4));
	CLR_BIT(PORTB,RS_4bit);
	LCD_vSendFallingEdge_4bit();
/*PORTA = ((cmd>>4)<<4);
CLR_BIT(PORTB,RS_4bit);
LCD_vSendFallingEdge_4bit();
PORTA =(cmd<<4);
CLR_BIT(PORTB,RS_4bit);
LCD_vSendFallingEdge_4bit();*/
}
void LCD_vSendData_4bit(char data)
{
	(READ_BIT(data,7))?(SET_BIT(PORTA,7)):(CLR_BIT(PORTA,7));
	(READ_BIT(data,6))?(SET_BIT(PORTA,6)):(CLR_BIT(PORTA,6));
	(READ_BIT(data,5))?(SET_BIT(PORTA,5)):(CLR_BIT(PORTA,5));
	(READ_BIT(data,4))?(SET_BIT(PORTA,4)):(CLR_BIT(PORTA,4));
	SET_BIT(PORTB,RS_4bit);
	LCD_vSendFallingEdge_4bit();
	(READ_BIT(data,3))?(SET_BIT(PORTA,7)):(CLR_BIT(PORTA,7));
	(READ_BIT(data,2))?(SET_BIT(PORTA,6)):(CLR_BIT(PORTA,6));
	(READ_BIT(data,1))?(SET_BIT(PORTA,5)):(CLR_BIT(PORTA,5));
	(READ_BIT(data,0))?(SET_BIT(PORTA,4)):(CLR_BIT(PORTA,4));
	SET_BIT(PORTB,RS_4bit);
	LCD_vSendFallingEdge_4bit();
	/*PORTA = ((data>>4)<<4);
	SET_BIT(PORTB,RS_4bit);
	LCD_vSendFallingEdge_4bit();
	PORTA = (data<<4);
	SET_BIT(PORTB,RS_4bit);
	LCD_vSendFallingEdge_4bit();*/
}
void LCD_vDisplayString_4bit(char* S)
{
	while(*S != 0)
	{
	
	char x = *S;
	LCD_vSendData_4bit(x);
	S++;
	count++;
	if (count==15)
	{
		LCD_vSendData_4bit('_');
		LCD_vSeconedLine_4bit();
	}
	}	
}
void LCD_vClearScreen_4bit()
{
	LCD_vSendCommand_4bit(0x01);/*clear screen*/
	count=0;
}
void LCD_vSeconedLine_4bit()
{
	LCD_vSendCommand_4bit(0xc0);
}
void LCD_vGoTo_X_Y_4bit(unsigned char row,unsigned char col)
{
	char temp;
	if (FirstRow==row)
	{
		temp=0x80+col-1;
		LCD_vSendCommand_4bit(temp);
	}
	else if (SeconedRow==row)
	{
		temp=0xc0+col-1;
		LCD_vSendCommand_4bit(temp);
	}
}	
