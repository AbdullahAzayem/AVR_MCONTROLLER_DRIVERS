/***************************************************************/
/***********   AUTHOR: ABDULLAH AZAYEM               ***********/
/***********   DATE  : 08-05-2021                    ***********/
/***********   COMP  : KEYPAD CONFIG FILE            ***********/
/***************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


#define KEYPAD_u8_PORT		DIO_u8_PORTD
#define KEYPAD_u8_COL0		DIO_u8_PIN0
#define KEYPAD_u8_COL1		DIO_u8_PIN1
#define KEYPAD_u8_COL2		DIO_u8_PIN2
#define KEYPAD_u8_COL3		DIO_u8_PIN3
#define KEYPAD_u8_ROW0		DIO_u8_PIN4
#define KEYPAD_u8_ROW1		DIO_u8_PIN5
#define KEYPAD_u8_ROW2		DIO_u8_PIN6
#define KEYPAD_u8_ROW3		DIO_u8_PIN7

#define KEYPAD_KEYS_ARRAY4x4		{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#define NO_KEY_PRESSED_VAL 			0xff


#endif
