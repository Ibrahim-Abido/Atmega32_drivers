/*
 * LCD.h
 *
 * Created: 10/3/2017 4:36:50 PM
 *  Author: IbrahimGomaa
 */ 


#ifndef LCD_H_
#define LCD_H_

void LCD_vSendFllingEdge();
void LCD_vInit();
void LCD_vSendCommand(char cmd);
void LCD_vSendData(char data);
void LCD_vDisplayString(char* S);
void LCD_vClearScreen();
void LCD_vGoTo_X_Y_8bitMode(unsigned char row,unsigned char col);

#endif /* LCD_H_ */