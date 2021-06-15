/*
 * bit_math.h
 *
 *  Created on: Nov 12, 2018
 *      Author: abdul
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bitno)   			reg=reg | (1<<bitno)
#define CLR_BIT(reg,bitno)   			reg=reg & ~(1<<bitno)
#define TOGGLE_BIT(reg,bitno)		    reg=reg ^ (1<<bitno)
#define GET_BIT(reg,bitno)   			(reg&(1<<bitno))>> bitno
#define SET_REG(reg)         			reg=reg | ~(0)
#define GET_REG(reg)         			reg
#define CLR_REG(reg)         			reg=reg & 0
#define TOGGLE_REG(reg)      			reg=reg ^ ~(0)
#define SET_LOW_NIB(reg)     			reg=reg | (0b1111)
#define CLR_LOW_NIB(reg)     			reg=reg & ~(0b1111)
#define GET_LOW_NIB(reg)     			reg & (0b1111)
#define SET_HIGH_NIB(reg)    			reg=reg | (0b11110000)
#define CLR_HIGH_NIB(reg)    			reg=reg & ~(0b11110000)
#define GET_HIGH_NIB(reg)    			(reg>>4) & (0b1111)
#define ASSIGN_HIGH_NIB(reg,value)      reg=reg+(value<<4)
#define ASSIGN_LOW_NIB(reg,value)       reg=(reg<<4)+value

#endif /* BIT_MATH_H_ */
