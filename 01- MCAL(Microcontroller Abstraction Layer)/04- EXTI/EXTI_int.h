/***************************************************************/
/***********   AUTHOR: ABDULLAH AZAYEM               ***********/
/***********   DATE  : 09-05-2021                    ***********/
/***********   COMP  : EXTI_INT FILE                    ***********/
/***************************************************************/

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

/*initialize interrupt at preprocessor configuration*/
void EXTI_voidINT0Init(void);
void EXTI_voidINT1Init(void);
void EXTI_voidINT2Init(void);

/*Initialize in post-build*/
void EXTI_voidSetSenseControl(u8 Copy_u8Int,u8 Copy_u8Sense);

/*interrupt status enable or disable*/
void EXTI_voidEnableInterrupt(u8 Copy_u8Interrupt);
void EXTI_voidDisableInterrupt(u8 Copy_u8Interrupt);

#endif
