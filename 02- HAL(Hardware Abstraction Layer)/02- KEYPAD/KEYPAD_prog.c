/***************************************************************/
/***********   AUTHOR: ABDULLAH AZAYEM               ***********/
/***********   DATE  : 08-05-2021                    ***********/
/***********   COMP  : KEYPAD PROG FILE                ***********/
/***************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_priv.h"
#include "KEYPAD_int.h"



u8 KEYPAD_u8GetPressedKey(void)
{
	u8 Local_u8PinStatus  = 1;
	u8 Local_u8PressedKey = NO_KEY_PRESSED_VAL ;
	u8 Local_u8Keypad[ROWS_NUMBER][COLS_NUMBER] = KEYPAD_KEYS_ARRAY4x4;

	u8 Local_u8RowIndex = 0 ;
	u8 Local_u8ColIndex = 0 ;

	u8 Local_u8RowsPinsArr[ROWS_NUMBER] = {KEYPAD_u8_ROW0,KEYPAD_u8_ROW1,KEYPAD_u8_ROW2,KEYPAD_u8_ROW3};
	u8 Local_u8ColsPinsArr[COLS_NUMBER] = {KEYPAD_u8_COL0,KEYPAD_u8_COL1,KEYPAD_u8_COL2,KEYPAD_u8_COL3};

	/*Two for loop to check which button is pressed*/
	for(Local_u8ColIndex=0;Local_u8ColIndex < COLS_NUMBER;Local_u8ColIndex++)
	{
		/*Activate the current column*/
		DIO_u8SetPinVal(KEYPAD_u8_PORT,Local_u8ColsPinsArr[Local_u8ColIndex],LOW);

		for(Local_u8RowIndex=0;Local_u8RowIndex < ROWS_NUMBER;Local_u8RowIndex++)
		{
			/*Read current row*/
			Local_u8PinStatus = DIO_u8GetPinVal(KEYPAD_u8_PORT,Local_u8RowsPinsArr[Local_u8RowIndex]);

			/*Check if the key is pressed*/
			if( KEY_LOW == Local_u8PinStatus )
			{
				Local_u8PressedKey = Local_u8Keypad[Local_u8RowIndex][Local_u8ColIndex];
				/*Pulling on button*/
				while((DIO_u8GetPinVal(KEYPAD_u8_PORT,Local_u8RowsPinsArr[Local_u8RowIndex])) == KEY_LOW);

				return Local_u8PressedKey;			}
			else
			{
			}
		}
		/*DEactivate the current column*/
		DIO_u8SetPinVal(KEYPAD_u8_PORT,Local_u8ColsPinsArr[Local_u8ColIndex],HIGH);
	}
	while((DIO_u8GetPinVal(KEYPAD_u8_PORT,Local_u8RowsPinsArr[Local_u8RowIndex])) == KEY_LOW);
	return Local_u8PressedKey;
}
