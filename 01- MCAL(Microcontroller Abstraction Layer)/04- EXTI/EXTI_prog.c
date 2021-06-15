/***************************************************************/
/***********   AUTHOR: ABDULLAH AZAYEM               ***********/
/***********   DATE  : 09-05-2021                    ***********/
/***********   COMP  : EXTI_PROGRAM_FILE             ***********/
/***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_config.h"
#include "EXTI_priv.h"
#include "EXTI_int.h"
#include "EXTI_reg.h"


/*initialize interrupt0 at preprocessor configuration*/
void EXTI_voidINT0Init(void)
{
	/*Set sense control of int0 to falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

	/*int0 PIE enable*/
	SET_BIT(GICR,GICRINT0);
}


/*initialize interrupt1 at preprocessor configuration*/
void EXTI_voidINT1Init(void)
{


}


/*initialize interrupt2 at preprocessor configuration*/
void EXTI_voidINT2Init(void)
{



}

/*Initialize in post-build*/
void EXTI_voidSetSenseControl(u8 Copy_u8Int,u8 Copy_u8Sense)
{



}

/*interrupt status enable*/
void EXTI_voidEnableInterrupt(u8 Copy_u8Interrupt)
{


}

/*interrupt status disable*/
void EXTI_voidDisableInterrupt(u8 Copy_u8Interrupt)
{



}




