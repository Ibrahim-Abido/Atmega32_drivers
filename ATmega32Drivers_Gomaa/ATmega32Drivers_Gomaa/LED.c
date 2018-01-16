/*
 * LED.c
 *
 * Created: 9/12/2017 7:37:40 PM
 *  Author: Ibrahim
 */ 
#include <avr/io.h>
#include"LED.h"
void toggleLED(){
	
	 PORTD^=0xe0;    //TODO:: Please write your application code
}
void setBit(char bit){
	PORTD|=(1<<bit);
}