/***************************************************************/
/***********   AUTHOR: ABDULLAH AZAYEM               ***********/
/***********   DATE  : 07-05-2021                    ***********/
/***********   COMP  : LCD PROGRAM FILE              ***********/
/***************************************************************/

/*Delay function*/
#include <util/delay.h>
#define F_CPU 12000000UL

/*Libraries*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*DIO interface file*/
#include "DIO_interface.h"

/*LCD files*/
#include "LCD_config.h"
#include "LCD_int.h"
#include "LCD_priv.h"


/*Initialize*/
void LCD_voidInit(void)
{
	/*Wait for 30ms*/
	_delay_ms(40);

	/*Send command set function*/
	LCD_voidSendCommand(LCD_FUNC_SET);

	/*Wait for 39 microsecond*/
	_delay_ms(1);
	LCD_voidSendCommand(LCD_DISP_ON_OFF);

	/*Wait for 39 microsecond*/
	_delay_ms(1);
	LCD_voidSendCommand(LCD_CLR);

	/*Wait for 1.53ms*/
	_delay_ms(2);
}

/*Send command*/
void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set R/W pin to write*/
	DIO_u8SetPinVal(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,LOW);

	/*Set to write command*/
	DIO_u8SetPinVal(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,LOW);

	/*Set command*/
	DIO_VidSetPortVal(LCD_u8_DATA_PORT,Copy_u8Command);

	/*LCD enable*/
	DIO_u8SetPinVal(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinVal(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,LOW);
}


/*Send character*/
void LCD_voidSendData(u8 Copy_u8Data)
{
	/*Set R/W pin to write*/
	DIO_u8SetPinVal(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,LOW);

	/*Set to write command*/
	DIO_u8SetPinVal(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,HIGH);

	/*Set command*/
	DIO_VidSetPortVal(LCD_u8_DATA_PORT,Copy_u8Data);

	/*LCD enable*/
	DIO_u8SetPinVal(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinVal(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,LOW);
}



/*LCD Function to write string*/
u8 LCD_u8WriteString(char const *Copy_pchString)
{

	/*Define Error Status*/
	u8 Local_u8ErrorStatus = OK;
	/*Define Counter*/
	u8 Local_u8Counter = 0;

	/*Check null pointer*/
	if('\0' != Copy_pchString)
	{

		/*Loop on string and print it character by character*/
		while(NULL != Copy_pchString[Local_u8Counter])
		{
			LCD_voidSendData(Copy_pchString[Local_u8Counter]);

			/*Go through for next character by increment loop*/
			Local_u8Counter++;
		}
	}
	else
	{
		/*Set error status*/
		Local_u8ErrorStatus = NULLPOINTER;
	}

	return Local_u8ErrorStatus;
}



/*LCD function to write number*/
void LCD_voidWriteNumber(u32 Copy_u32Number)
{
	/*Define Counter*/
	u32 Local_u32Counter = 1;
	/*Define Temporarily variable*/
	u32 Local_u32Temp = Copy_u32Number;

	while(1 != Local_u32Temp)
	{
		Local_u32Temp/=10;
		Local_u32Counter*=10;
	}

	while(0 != Local_u32Counter)
	{
		LCD_voidSendData(((Copy_u32Number/Local_u32Counter)%10)+'0');
		Local_u32Counter/=10;
	}
}



/*LCD function to write number*/
void LCD_voidWriteNumber2(u32 Copy_u32Number)
{
	u32 Local_u32Reserved = 0;
	u8 Local_u8Counter =0 ;

	if(0 != Copy_u32Number)
	{
		while(Copy_u32Number != 0)
		{
			Local_u32Reserved*=10;
			Local_u32Reserved += Copy_u32Number%10;
			Copy_u32Number/=10;
			Local_u8Counter++;
		}

		while(Local_u8Counter!=0)
		{
			Local_u8Counter--;

			LCD_voidSendData(Local_u32Reserved%10 +'0');
			Local_u32Reserved/=10;
		}
	}
	else
	{
		LCD_voidSendData(Copy_u32Number+'0');
	}

}



/*Goto xy
 * Copy_u8xPos:
 * 	1- LCD_u8_FIRST_LINE
 * 	2- LCD_u8_SECOND_LINE
 *
 * Copy_*/
void LCD_voidGotoXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8Address = 0;

	if(Copy_u8XPos == LCD_u8_FIRST_LINE)
	{
		// Address in line one
		Local_u8Address = (Copy_u8YPos-1);
	}
	else if(Copy_u8XPos == LCD_u8_SECONT_LINE)
	{
		Local_u8Address = 0x40 + (Copy_u8YPos-1);
	}
	else
	{

	}
	Local_u8Address |=(1<<7);
	LCD_voidSendCommand(Local_u8Address);
}



/*Write special character*/
void LCD_voidWriteSpecialChar(u8* Copy_pu8Pattern,u8 Copy_u8BlockNo,u8 Copy_u8Xpos,u8 Copy_u8Ypos)
{
	u8 Local_u8Addr =0 ;

	u8 Local_u8Counter=0;
	/*Need protection */

	Local_u8Addr = Copy_u8BlockNo * 8;

	LCD_voidSendCommand(Local_u8Addr+64);
	for(Local_u8Counter=0; Local_u8Counter<8 ;Local_u8Counter++)
	{
		LCD_voidSendData((u8)Copy_pu8Pattern[Local_u8Counter]);
	}
	/*Shift the address counter to DDRAM*/
	LCD_voidGotoXY(Copy_u8Xpos,Copy_u8Ypos);
	LCD_voidSendData(Copy_u8BlockNo);
}


