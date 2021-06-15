/***************************************************************/
/***********   AUTHOR: ABDULLAH AZAYEM               ***********/
/***********   DATE  : 09-05-2021                    ***********/
/***********   COMP  : GIE_INT_H_ FILE               ***********/
/***************************************************************/


/*Standard libraries*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*Driver files*/
#include "GIE_reg.h"
#include "GIE_int.h"

/*Interrupt enable*/
void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

/*Interrupt disable*/
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
