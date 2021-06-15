/*****************************************************************************************************************************************************/
/*********************************** Author: Abdullah Azayem Ali 											 *****************************************/
/*********************************** Type: MCAL(Microcontroller Abstraction Layer)							 *****************************************/
/*********************************** Date: 26/8/2020														 *****************************************/
/*********************************** Type: register file													 *****************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*Ports id*/
#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

/*Pins id*/
#define DIO_u8_PIN0 0
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2
#define DIO_u8_PIN3 3
#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7

/*Direction*/
#define INPUT  0x00
#define OUTPUT 0xff

/*Values*/
#define HIGH 0xff
#define LOW  0x00

#define IN_HIGH 	1
#define IN_LOW 		0
#define IN_UNDEF 	0xff

/*Pin Services*/
void DIO_VidSetPinDir(u8 u8PortId,u8 u8PinId,u8 u8Dir);
u8 DIO_u8SetPinVal(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinVal);
u8 DIO_u8GetPinVal(u8 u8PortId,u8 u8PinId);


void DIO_VidPullupRes(u8 u8PortId,u8 u8PinId);
void DIO_VidTogglePin(u8 u8PortId,u8 u8PinId);

/*Port services*/
void DIO_VidSetPortDir(u8 u8PortId,u8 u8Dir);
void DIO_VidSetPortVal(u8 u8PortId,u8 u8Val);
u8 DIO_u8GetPortVal(u8 u8PortId);

#endif /* DIO_INTERFACE_H_ */
