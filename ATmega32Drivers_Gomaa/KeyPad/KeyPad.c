/*
 * KeyPad.c
 *
 * Created: 10/5/2017 5:40:10 PM
 *  Author: IbrahimGomaa
 */ 
#include "KeyPad.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIODriver.h"

char myArr[4][4]={	{'7','8','9',47},/* A->devide; B->mult.; C->minus; D->on/c; E->equal; F->plus*/
					{'4','5','6','*'},
					{'1','2','3','-'},
					{'c','0','=','+'}};

void KeyPad_vInit()
{
	DDRD=0x0f;
	/*To enable internal pull up resistance*/
	SFIOR &=(~(1<<PUD));
	PORTD |=0xf0;
}
char KeyPad_vPressedKey()
{
	
	int Row,Col;
	for (Row=0;Row<4;Row++)
	{
		DIO_vWriteDataPin ('D' , 0 , HIGH);
		DIO_vWriteDataPin ('D' , 1 , HIGH);
		DIO_vWriteDataPin ('D' , 2 , HIGH);
		DIO_vWriteDataPin ('D' , 3 , HIGH);
		DIO_vWriteDataPin('D',Row,LOW);
		for (Col=4;Col<8;Col++)
		{
		char x=DIO_cReadPin ('D' , Col);
			if (x==0)
			{
			return myArr[Row][Col-4];
			}
		}
	}		
	return 0xff;	
}	
