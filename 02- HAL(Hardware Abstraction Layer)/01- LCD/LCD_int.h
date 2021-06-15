/***************************************************************/
/***********   AUTHOR: ABDULLAH AZAYEM               ***********/
/***********   DATE  : 07-05-2021                    ***********/
/***********   COMP  : LCD INTERFACE FILE            ***********/
/***************************************************************/


/*Preprocessor file guard*/
#ifndef LCD_INT_H_
#define LCD_INT_H_


/*Commands*/

#define LCD_u8_FIRST_LINE 	0
#define LCD_u8_SECONT_LINE	1

#define LCD_u8_COL0 0
#define LCD_u8_COL1 1
#define LCD_u8_COL2 2
#define LCD_u8_COL3 3
#define LCD_u8_COL4 4
#define LCD_u8_COL5 5
#define LCD_u8_COL6 6
#define LCD_u8_COL7 7
#define LCD_u8_COL8 8
#define LCD_u8_COL9 9
#define LCD_u8_COL10 10
#define LCD_u8_COL11 11
#define LCD_u8_COL12 12
#define LCD_u8_COL13 13
#define LCD_u8_COL14 14
#define LCD_u8_COL15 15






#define LCD_CLR 			0x01
#define LCD_RET_HOME 		0x02


/*Lines*/
#define LCD_ONE_LINE		0
#define LCD_TWO_LINES		1

/*Mode*/
#define LCD_MODE_5x7		0
#define LCD_MODE_5x11		1

/*Direction*/
#define LCD_INCREMENT 		1
#define LCD_DECREMENT		0

/*Blink*/
#define LCD_BLINK_ON		1
#define LCD_BLINK_OFF		0

/*Cursor*/
#define LCD_CURSOR_ON		1
#define LCD_CURSOR_OFF		0

#define LCD_DISP_ENABLE		1
#define LCD_DISP_DISABLE	0

#define LCD_SHIFT_ON		1
#define LCD_SHIFT_OFF		0


#define LCD_FUNC_SET		(  0x30 | (u8)(LCD_LINE_NO << 3) | (u8)(LCD_FONT_MODE<<2) )
#define LCD_DISP_ON_OFF     (  0x08 | (u8)(LCD_DISP_MODE << 2) | (u8)(LCD_CURSOR_MODE<<1) |  (u8)(LCD_BLINK_MODE<<0) )
#define LCD_ENTRY_MODE_SET		(  0x04 | (u8)(LCD_ENTRY_MODE << 1) | (u8)(LCD_SHIFT_MODE << 0) )

/*Set font mode*/
void LCD_voidFontMode(u8 Copy_u8Mode);



/*Send command*/
void LCD_voidSendCommand(u8 Copy_u8Command);


/*Send character*/
void LCD_voidSendData(u8 Copy_u8Data);

/*Initialize*/
void LCD_voidInit(void);

u8 LCD_u8WriteString(char const *Copy_pchString);

/*LCD function to write number*/
void LCD_voidWriteNumber(u32 Copy_u32Number);


void LCD_voidWriteNumber2(u32 Copy_u32Number);


/*Goto xy*/
void LCD_voidGotoXY(u8 Copy_u8XPos,u8 Copy_u8YPos);

/*Write special character*/
void LCD_voidWriteSpecialChar(u8* Copy_pu8Pattern,u8 Copy_u8BlockNo,u8 Copy_u8Xpos,u8 Copy_u8Ypos);


#endif


