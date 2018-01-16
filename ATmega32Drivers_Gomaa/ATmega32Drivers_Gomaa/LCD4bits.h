/*
 * LCD4bits.h
 *
 * Created: 10/3/2017 6:33:03 PM
 *  Author: IbrahimGomaa
 */ 


#ifndef LCD4BITS_H_
#define LCD4BITS_H_

void LCD_vSendFllingEdge_4bit();
void LCD_vInit_4bit();
void LCD_vSendCommand_4bit(char cmd);
void LCD_vSendData_4bit(char data);
void LCD_vDisplayString_4bit(char* S);
void LCD_vClearScreen_4bit();
void LCD_vGoTo_X_Y_4bit(unsigned char row,unsigned char col);
void LCD_vSeconedLine_4bit();


#endif /* LCD4BITS_H_ */