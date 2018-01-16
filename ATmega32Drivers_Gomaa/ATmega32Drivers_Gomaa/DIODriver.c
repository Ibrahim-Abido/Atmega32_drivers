/*
 * DIODriver.c
 *
 * Created: 9/26/2017 9:53:44 AM
 *  Author: IbrahimGomaa
 */ 


#include <avr/io.h>
# define F_CPU 8000000UL
#include <util/delay.h>
#include "STDMACROS.h"
#include "DIODriver.h"

/*#define DDRName  strcat("DDR",portName)
#define PORTName  strcat("PORT",portName)
#define PINName  strcat("PIN",portName)*/
void DIO_vSetPinDirection ( char portName , char pinNum,char dir ) //Configure either the port is INPUT or OUPUT
{	
	switch (dir) //Check the Operation (OUTPUT or INPUT)
	{		
		case OUTPUT: //in OUTPUT case
		{
			switch (portName)
			{
				case 'A':
				{
					if (pinNum==ALL)
					{
						DDRA|=0xff;
					}
					SET_BIT(DDRA,pinNum);
				}break;
				case 'B':
				{
					if (pinNum==ALL)
					{
						DDRB|=0xff;
					}
					SET_BIT(DDRB,pinNum);
				}break;
				case 'C':
				{
					if (pinNum==ALL)
					{
						DDRC|=0xff;
					}
					SET_BIT(DDRC,pinNum);
				}break;
				case 'D':
				{
					if (pinNum==ALL)
					{
						DDRD|=0xff;
					}
					SET_BIT(DDRD,pinNum);
				}break;
			}	
		}break;					
					
		case INPUT: //at INPUT case
		{
			switch (portName)
			{
				case 'A':
				{
					if (pinNum==ALL)
					{
						DDRA&=~(0xff);
					}
					CLR_BIT(DDRA,pinNum);
				}break;
				case 'B':
				{
					if (pinNum==ALL)
					{
						DDRB&=~(0xff);
					}
					CLR_BIT(DDRB,pinNum);
				}break;
				case 'C':
				{
					if (pinNum==ALL)
					{
						DDRC&=~(0xff);
					}
					CLR_BIT(DDRC,pinNum);
				}break;
				case 'D':
				{
					if (pinNum==ALL)
					{
						DDRD&=~(0xff);
					}
					CLR_BIT(DDRD,pinNum);
				}break;
			}
		}break;			
	}
}									
void DIO_vWriteDataPin (char portName , char pinNum , char State) //Configure either the port is HIGH or LOW in case of OUTPUT
																
	{
		switch (State) //check the state
	{
		
		case 1: //PULL_UP INPUT or HIGH OUTPUT
		{
			switch (portName) //check the chosen port
			{
				case 'A': //if PORTA
				{
					if (pinNum==ALL)
					{
						PORTA|=0xff;
					}
					SET_BIT(PORTA,pinNum);	
				}break;
				
				case 'B': //if PORTA
				{
					if (pinNum==ALL)
					{
						PORTB|=0xff;
					}
					SET_BIT(PORTB,pinNum);
				}break;
				
				case 'C': //if PORTA
				{
					if (pinNum==ALL)
					{
						PORTC|=0xff;
					}
					SET_BIT(PORTC,pinNum);
				}break;
				case 'D': //if PORTA
				{
					if (pinNum==ALL)
					{
						PORTD|=0xff;
					}
					SET_BIT(PORTD,pinNum);
				}break;
				
			}
			
		}break;
		
		
		case 0 : //HIGH_IMPEDANCE INPUT or LOW OUTPUT
		{
			switch (portName) //check the chosen port
			{
				case 'A': //if PORTA
				{
					if (pinNum==ALL)
					{
						PORTA&=~(0xff);
					}
					CLR_BIT(PORTA,pinNum);
				}break;
				
				case 'B': //if PORTA
				{
					if (pinNum==ALL)
					{
						PORTB&=~(0xff);
					}
					CLR_BIT(PORTB,pinNum);
				}break;
				
				case 'C': //if PORTC
				{
					if (pinNum==ALL)
					{
						PORTC&=~(0xff);
					}
					CLR_BIT(PORTC,pinNum);
				}break;
				case 'D': //if PORTD
				{
					if (pinNum==ALL)
					{
						PORTD&=~(0xff);
					}
					CLR_BIT(PORTD,pinNum);
				}break;
				
			}
			
		}break;
	}
}

char DIO_cReadPin (char portName , char pinNum)										//Read input from the port
{
	switch (portName)
	{
		case 'A':
		{
			return READ_BIT(PINA,pinNum)>>pinNum;
		}break;
		case 'B':
		{
			return READ_BIT(PINB,pinNum)>>pinNum;
		}break;
		case 'C':
		{
			return READ_BIT(PINC,pinNum)>>pinNum;
		}break;
		case 'D':
		{
			return READ_BIT(PIND,pinNum)>>pinNum;
		}break;
	}
	
}
