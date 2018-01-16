/*
 * SevSegD.c
 *
 * Created: 9/28/2017 4:42:10 PM
 *  Author: IbrahimGomaa
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "SevSegD.h"
#include "DIODriver.h"
#include "STDMACROS.h"
void SevSeg_vInit()
{
	int i=0;
	for(i=2;i<=7;i++){
	DIO_vSetPinDirection ( 'C' , i,OUTPUT );
	}	
}
void SevSeg_vDisplay (char Num)/*if seg=2->left ,if seg=1->Right*/
{
	char unit, ten;
	unit=Num%10;
	ten=Num/10;
PORTC=unit<<4;
DIO_vWriteDataPin('C',2,HIGH);
DIO_vWriteDataPin('C',3,LOW);
_delay_ms(1);
PORTC=ten<<4;
DIO_vWriteDataPin('C',2,LOW);
DIO_vWriteDataPin('C',3,HIGH);
_delay_ms(1);
}