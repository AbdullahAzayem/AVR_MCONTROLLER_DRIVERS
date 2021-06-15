/*****************************************************************************************************************************************************/
/*********************************** Author: Abdullah Azayem Ali 											 *****************************************/
/*********************************** Type: MCAL(Microcontroller Abstraction Layer)							 *****************************************/
/*********************************** Date: 26/8/2020														 *****************************************/
/*********************************** Type: register file													 *****************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


/*Preprocessor file guard*/
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

/*Group_A Registers*/
#define PORTA 	*((volatile u8*) 0x3B) //PORTA Register
#define DDRA  	*((volatile u8*) 0x3A) //DDRA Register
#define PINA  	*((volatile u8*) 0x39) //PINA Register

/*Group_B Registers*/
#define PORTB   *((volatile u8*) 0x38) //PORTB Register
#define DDRB    *((volatile u8*) 0x37) //DDRB Register
#define PINB 	*((volatile u8*) 0x36) //PINB Register

/*Group_C Registers*/
#define PORTC   *((volatile u8*) 0x35) //PORTC Register
#define DDRC    *((volatile u8*) 0x34) //DDRC Register
#define PINC    *((volatile u8*) 0x33) //PINC Register

/*Group_D Registers*/
#define PORTD   *((volatile u8*) 0x32) //PORTD Register
#define DDRD    *((volatile u8*) 0x31) //DDRD Register
#define PIND    *((volatile u8*) 0x30) //PIND Register

#endif /* DIO_REGISTER_H_ */
