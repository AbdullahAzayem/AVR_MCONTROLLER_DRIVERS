/***************************************************************/
/***********   AUTHOR: ABDULLAH AZAYEM               ***********/
/***********   DATE  : 07-05-2021                    ***********/
/***********   COMP  : LCD CONFIG FILE               ***********/
/***************************************************************/


/*Preprocessor file guard*/
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


/*LCD_u8_CTRL_PORT
 * 	1- DIO_u8_PORTA
 * 	2- DIO_u8_PORTB
 * 	3- DIO_u8_PORTC
 * 	4- DIO_u8_PORTD
*/
#define LCD_u8_CTRL_PORT 		DIO_u8_PORTB
#define LCD_u8_RS_PIN  			DIO_u8_PIN0
#define LCD_u8_RW_PIN 			DIO_u8_PIN1
#define LCD_u8_E_PIN 			DIO_u8_PIN2


/*LCD_u8_CTRL_PORT
 * 	1- DIO_u8_PORTA
 * 	2- DIO_u8_PORTB
 * 	3- DIO_u8_PORTC
 * 	4- DIO_u8_PORTD
*/
#define LCD_u8_DATA_PORT 		DIO_u8_PORTC


/*LCD_FONT_MODE
 * 1- LCD_MODE_5x7
 * 2- LCD_MODE_5x11
 */
#define LCD_FONT_MODE 			LCD_MODE_5x7

/*LCD_LINE_NO
 * 1- LCD_ONE_LINE
 * 2- LCD_TWO_LINES
 */
#define LCD_LINE_NO		LCD_TWO_LINES

/*LCD_ENTRY_MODE
 * 1- LCD_INCREMENT
 * 2- LCD_DECREMENT
 */
#define LCD_ENTRY_MODE      LCD_INCREMENT

/*LCD_BLINK_MODE
 * 1- LCD_BLINK_ON
 * 2- LCD_BLINK_OFF
 */
#define LCD_BLINK_MODE		LCD_BLINK_ON


/*LCD_CURSOR_MODE
 * 1= LCD_CURSOR_ON
 * 2= LCD_CURSOR_OFF
 */
#define LCD_CURSOR_MODE		LCD_CURSOR_ON

/*LCD_DISP_MODE
 * 1- LCD_DISP_ENABLE
 * 2- LCD_DISP_DISABLE
 */
#define LCD_DISP_MODE 		LCD_DISP_ENABLE

/*LCD_SHIFT_MODE
 * 1- LCD_SHIFT_ON
 * 2- LCD_SHIFT_OFF
 * */
#define LCD_SHIFT_MODE 		LCD_SHIFT_ON

#endif


