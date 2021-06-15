/*****************************************************************************************************************************************************/
/*********************************** Author: Abdullah Azayem Ali 											 *****************************************/
/*********************************** Type: MCAL(Microcontroller Abstraction Layer)							 *****************************************/
/*********************************** Date: 26/8/2020														 *****************************************/
/*********************************** Type: register file													 *****************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


/*Preprocessor file guard*/
#ifndef PORT_REG_H_
#define PORT_REG_H_

/*Group_A Registers*/
#define PORTA 	*((volatile u8*) 0x3B) //PORTA Register
#define DDRA  	*((volatile u8*) 0x3A) //DDRA Register

/*Group_B Registers*/
#define PORTB   *((volatile u8*) 0x38) //PORTB Register
#define DDRB    *((volatile u8*) 0x37) //DDRB Register

/*Group_C Registers*/
#define PORTC   *((volatile u8*) 0x35) //PORTC Register
#define DDRC    *((volatile u8*) 0x34) //DDRC Register

/*Group_D Registers*/
#define PORTD   *((volatile u8*) 0x32) //PORTD Register
#define DDRD    *((volatile u8*) 0x31) //DDRD Register

#endif /* DIO_REGISTER_H_ */
