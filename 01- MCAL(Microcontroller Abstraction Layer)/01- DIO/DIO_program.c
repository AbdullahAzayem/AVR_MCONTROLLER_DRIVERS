/*****************************************************************************************************************************************************/
/*********************************** Author: Abdullah Azayem Ali 											 *****************************************/
/*********************************** Layer: MCAL(Microcontroller Abstraction Layer)							 *****************************************/
/*********************************** Date: 26/8/2020														 *****************************************/
/*********************************** Type: Program file														 *****************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_register.h"

/*1- Pin directions
		1- PIN Choices:
			1- DIO_u8_PIN0
			2- DIO_u8_PIN1
			3- DIO_u8_PIN2
			4- DIO_u8_PIN3
			5- DIO_u8_PIN4
			6- DIO_u8_PIN5
			7- DIO_u8_PIN6
			8- DIO_u8_PIN7

		2- PORT Choices:
			1- DIO_u8_PORTA
			2- DIO_u8_PORTB
			3- DIO_u8_PORTC
			4- DIO_u8_PORTD

		3- Direction Choices:
			1- INPUT
			2- OUTPUT 
 */
void DIO_VidSetPinDir(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Dir)
{
	if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) )
	{
		if(Copy_u8Dir==INPUT)
		{
			switch(Copy_u8PortId)
			{
			case DIO_u8_PORTA:
				CLR_BIT(DDRA,Copy_u8PinId);
				break;
			case DIO_u8_PORTB:
				CLR_BIT(DDRB,Copy_u8PinId);
				break;
			case DIO_u8_PORTC:
				CLR_BIT(DDRC,Copy_u8PinId);
				break;
			case DIO_u8_PORTD:
				CLR_BIT(DDRD,Copy_u8PinId);
				break;
			}
		}
		else if(Copy_u8Dir==OUTPUT)
		{
			switch(Copy_u8PortId)
			{
			case DIO_u8_PORTA:
				SET_BIT(DDRA,Copy_u8PinId);
				break;
			case DIO_u8_PORTB:
				SET_BIT(DDRB,Copy_u8PinId);
				break;
			case DIO_u8_PORTC:
				SET_BIT(DDRC,Copy_u8PinId);
				break;
			case DIO_u8_PORTD:
				SET_BIT(DDRD,Copy_u8PinId);
				break;
			}
		}
		else
		{ /*Wrong direction*/ }
	}
}

/*2- Set Pin Value
		1- PIN Choices:
			1- DIO_u8_PIN0
			2- DIO_u8_PIN1
			3- DIO_u8_PIN2
			4- DIO_u8_PIN3
			5- DIO_u8_PIN4
			6- DIO_u8_PIN5
			7- DIO_u8_PIN6
			8- DIO_u8_PIN7

		2- PORT Choices:
			1- DIO_u8_PORTA
			2- DIO_u8_PORTB
			3- DIO_u8_PORTC
			4- DIO_u8_PORTD

		3- Value Choices:
			1- HIGH
			2- LOW 
 */
u8 DIO_u8SetPinVal(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinVal)
{
	/*Error status*/
	u8 Local_u8ErrorStatus = OK;


	/*Check the range for function inputs*/
	if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) )
	{
		switch(Copy_u8PinVal)
		{
		case HIGH:
			switch(Copy_u8PortId)
			{
			case DIO_u8_PORTA:
				SET_BIT(PORTA,Copy_u8PinId);
				break;
			case DIO_u8_PORTB:
				SET_BIT(PORTB,Copy_u8PinId);
				break;
			case DIO_u8_PORTC:
				SET_BIT(PORTC,Copy_u8PinId);
				break;
			case DIO_u8_PORTD:
				SET_BIT(PORTD,Copy_u8PinId);
				break;
			default:
				break;
			}
			break;
		case LOW:
			switch(Copy_u8PortId)
			{
			case DIO_u8_PORTA:
				CLR_BIT(PORTA,Copy_u8PinId);
				break;
			case DIO_u8_PORTB:
				CLR_BIT(PORTB,Copy_u8PinId);
				break;
			case DIO_u8_PORTC:
				CLR_BIT(PORTC,Copy_u8PinId);
				break;
			case DIO_u8_PORTD:
				CLR_BIT(PORTD,Copy_u8PinId);
				break;
			default:
				break;
			}
			break;
		default:
			/*Set error status*/
			Local_u8ErrorStatus = NOK;
			break;
		}
	}
	else
	{
		/*Set Error status*/
		Local_u8ErrorStatus = NOK;

	}
	return Local_u8ErrorStatus;
}
/*3- Pin directions
		1- PIN Choices:
			1- DIO_u8_PIN0
			2- DIO_u8_PIN1
			3- DIO_u8_PIN2
			4- DIO_u8_PIN3
			5- DIO_u8_PIN4
			6- DIO_u8_PIN5
			7- DIO_u8_PIN6
			8- DIO_u8_PIN7

		2- PORT Choices:
			1- DIO_u8_PORTA
			2- DIO_u8_PORTB
			3- DIO_u8_PORTC
			4- DIO_u8_PORTD
 */
u8 DIO_u8GetPinVal(u8 u8PortId,u8 u8PinId)
{
	u8 u8PinVal=IN_UNDEF;
	/*Check if the entered pin and ports are correct or not*/
	if(u8PortId <= DIO_u8_PORTD && u8PinId <= DIO_u8_PIN7)
	{
		/*Switch between the ports*/
		switch(u8PortId)
		{
		/*Four cases for ports*/
		case DIO_u8_PORTA:
			u8PinVal= GET_BIT(PINA,u8PinId);
			break;
		case DIO_u8_PORTB:
			u8PinVal= GET_BIT(PINB,u8PinId);
			break;
		case DIO_u8_PORTC:
			u8PinVal= GET_BIT(PINC,u8PinId);
			break;
		case DIO_u8_PORTD:
			u8PinVal= GET_BIT(PIND,u8PinId);
			break;
		default:
			break;
		}
	}
	else
	{
		/*Wrong port or pin id*/
	}
	return u8PinVal;
}


/*4- Get port value
		1- PORT Choices:
			1- DIO_u8_PORTA
			2- DIO_u8_PORTB
			3- DIO_u8_PORTC
			4- DIO_u8_PORTD
 */
u8 DIO_u8GetPortVal(u8 u8PortId)
{
	u8 u8PortVal=IN_UNDEF;
	/*Check if the entered pin and ports are correct or not*/
	if(u8PortId <= DIO_u8_PORTD )
	{
		/*Switch between the ports*/
		switch(u8PortId)
		{
		/*Four cases for ports*/
		case DIO_u8_PORTA:
			u8PortVal= GET_REG(PINA);
			break;
		case DIO_u8_PORTB:
			u8PortVal= GET_REG(PINB);
			break;
		case DIO_u8_PORTC:
			u8PortVal= GET_REG(PINC);
			break;
		case DIO_u8_PORTD:
			u8PortVal= GET_REG(PIND);
			break;
		default:
			break;
		}
	}
	else
	{
		/*Wrong port or pin id*/
	}
	return u8PortVal;
}


/*5- Pullup resistance
		1- PIN Choices:
			1- DIO_u8_PIN0
			2- DIO_u8_PIN1
			3- DIO_u8_PIN2
			4- DIO_u8_PIN3
			5- DIO_u8_PIN4
			6- DIO_u8_PIN5
			7- DIO_u8_PIN6
			8- DIO_u8_PIN7

		2- PORT Choices:
			1- DIO_u8_PORTA
			2- DIO_u8_PORTB
			3- DIO_u8_PORTC
			4- DIO_u8_PORTD
 */
void DIO_VidPullupRes(u8 u8PortId,u8 u8PinId)
{
	/*Check the ports and pins*/
	if(u8PortId<= DIO_u8_PORTD && u8PinId <=DIO_u8_PIN7)
	{
		/*Switch between the ports*/
		switch(u8PortId)
		{
		case DIO_u8_PORTA:
			SET_BIT(PORTA,u8PinId);
			break;
		case DIO_u8_PORTB:
			SET_BIT(PORTB,u8PinId);
			break;
		case DIO_u8_PORTC:
			SET_BIT(PORTC,u8PinId);
			break;
		case DIO_u8_PORTD:
			SET_BIT(PORTD,u8PinId);
			break;
		}
	}
	else
	{

	}
}


/*6- Toggle pin
		1- PIN Choices:
			1- DIO_u8_PIN0
			2- DIO_u8_PIN1
			3- DIO_u8_PIN2
			4- DIO_u8_PIN3
			5- DIO_u8_PIN4
			6- DIO_u8_PIN5
			7- DIO_u8_PIN6
			8- DIO_u8_PIN7

		2- PORT Choices:
			1- DIO_u8_PORTA
			2- DIO_u8_PORTB
			3- DIO_u8_PORTC
			4- DIO_u8_PORTD

 */
void DIO_VidTogglePin(u8 u8PortId,u8 u8PinId)
{
	/*Check the ports input is correct or not*/
	if(u8PortId <=DIO_u8_PORTD && u8PinId <=DIO_u8_PIN7)
	{
		/*switch between the ports*/
		switch(u8PortId)
		{
		case DIO_u8_PORTA:
			TOGGLE_BIT(PORTA,u8PinId);
			break;
		case DIO_u8_PORTB:
			TOGGLE_BIT(PORTB,u8PinId);
			break;
		case DIO_u8_PORTC:
			TOGGLE_BIT(PORTC,u8PinId);
			break;
		case DIO_u8_PORTD:
			TOGGLE_BIT(PORTD,u8PinId);
			break;
		}
	}
	else
	{
		/*Wrong id*/
	}
}


/*7- Set Port direction
		1- PORT Choices:
			1- DIO_u8_PORTA
			2- DIO_u8_PORTB
			3- DIO_u8_PORTC
			4- DIO_u8_PORTD

		2- Direction Choices:
			1- INPUT
			2- OUTPUT 
 */
void DIO_VidSetPortDir(u8 u8PortId,u8 u8Dir)
{
	switch(u8PortId)
	{
	case DIO_u8_PORTA:
		DDRA=u8Dir;
		break;
	case DIO_u8_PORTB:
		DDRB=u8Dir;
		break;
	case DIO_u8_PORTC:
		DDRC=u8Dir;
		break;
	case DIO_u8_PORTD:
		DDRD=u8Dir;
		break;
	}
}

/*8- Set PORT Value
		1- PORT Choices:
			1- DIO_u8_PORTA
			2- DIO_u8_PORTB
			3- DIO_u8_PORTC
			4- DIO_u8_PORTD

		2- Value Choices:
			1- HIGH
			2- LOW 
 */
void DIO_VidSetPortVal(u8 u8PortId,u8 u8Val)
{

	/*Switch ports*/
	switch(u8PortId)
	{
	case DIO_u8_PORTA:
		PORTA=u8Val;
		break;
	case DIO_u8_PORTB:
		PORTB=u8Val;
		break;
	case DIO_u8_PORTC:
		PORTC=u8Val;
		break;
	case DIO_u8_PORTD:
		PORTD=u8Val;
		break;
	default:
		/*Wrong port id*/
		break;
	}
}
