/*
 * STD_MACRO.h
 *
 * Created: 9/19/2017 6:03:01 PM
 *  Author: IbrahimGomaa
 */ 


#ifndef STD_MACRO_H_
#define STD_MACRO_H_

#define SET_BIT(reg,bit) (reg|=1<<bit)
#define CLR_BIT(reg,bit) (reg&=(~(1<<bit)))
#define READ_BIT(reg,bit) (reg&(1<<bit))
#define TOGGLE_BIT(reg,bit) (reg^=(1<<bit))
#define IS_BIT_SET(reg,bit) ((reg&(1<<bit))>>bit)
#define IS_BIT_CLEARED(reg,bit) (!((reg&(1<<bit))>>bit))
#define ROTATE_BIT_LEFT(reg,bit) (reg=(reg<<bit)|(reg>>(8-bit)))
#define ROTATE_BIT_Right(reg,bit) (reg=(reg<<(8-bit))|(reg>>bit)))



#endif /* STD_MACRO_H_ */