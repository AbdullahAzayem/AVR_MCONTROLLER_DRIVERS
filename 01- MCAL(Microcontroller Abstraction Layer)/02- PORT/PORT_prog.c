
#include "STD_TYPES.h"

#include "PORT_config.h"
#include "PORT_priv.h"
#include "PORT_reg.h"
#include "PORT_int.h"

/*PORT initialization*/
void PORT_voidInit()
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;

	PORTA = PORTA_INIT_VAL;
	PORTB = PORTB_INIT_VAL;
	PORTC = PORTC_INIT_VAL;
	PORTD = PORTD_INIT_VAL;
}
