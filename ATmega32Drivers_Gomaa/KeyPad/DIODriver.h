/*
 * DIODriver.h
 *
 * Created: 9/26/2017 9:54:28 AM
 *  Author: IbrahimGomaa
 */ 


#ifndef DIODRIVER_H_
#define DIODRIVER_H_

#define ALL 8

#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW	 0

void DIO_vSetPinDirection ( char portName , char pinNum,char dir ); //Configure either the port is INPUT or OUPUT

void DIO_vWriteDataPin (char portName , char pinNum , char State);		      //Configure either the port is HIGH or LOW in case of OUTPUT
																		

char DIO_cReadPin (char portName , char pinNum)	;							                //Read input from the port

#endif /* DIODRIVER_H_ */