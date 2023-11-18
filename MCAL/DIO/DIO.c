
#include "DIO.h"
#include "..\..\LIB\STD_TYPES\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH\BIT_MATH.h"
#include "..\..\LIB\CONFIG_MAP\CONFIG_MAP.h"

void  DIO_init(void)
{

}
void DIO_voidSetPinDirection(u8 port ,u8 pin , u8 direction)
{
	if (direction == OUTPUT)
	{
		switch(port)
		{
		case GPIOA : SET_BIT(DDRA, pin);break;
		case GPIOB : SET_BIT(DDRB, pin);break;
		case GPIOC : SET_BIT(DDRC, pin);break;
		case GPIOD : SET_BIT(DDRD, pin);break;
		default :break;
		}
	}
	else
	{
		switch(port)
		{
		case GPIOA : CLR_BIT(DDRA, pin);break;
		case GPIOB : CLR_BIT(DDRB, pin);break;
		case GPIOC : CLR_BIT(DDRC, pin);break;
		case GPIOD : CLR_BIT(DDRD, pin);break;
		default :break;

		}

	}
}
void DIO_voidSetPinValue(u8 port ,u8 pin , u8 value)
{
	if (value == HIGH)
	{
		switch(port)
		{
		case GPIOA : SET_BIT(PORTA, pin);break;
		case GPIOB : SET_BIT(PORTB, pin);break;
		case GPIOC : SET_BIT(PORTC, pin);break;
		case GPIOD : SET_BIT(PORTD, pin);break;
		default :break;
		}
	}
	else
	{
		switch(port)
		{
        case GPIOA : CLR_BIT(PORTA, pin);break;
		case GPIOB : CLR_BIT(PORTB, pin);break;
		case GPIOC : CLR_BIT(PORTC, pin);break;
		case GPIOD : CLR_BIT(PORTD, pin);break;
		default :break;
		}
	}
}
u8 DIO_u8GetPinValue(u8 port ,u8 pin)
{
	u8 result = 0;
	switch(port)
	{
	case GPIOA : result = GET_BIT(PINA, pin);break;
	case GPIOB : result = GET_BIT(PINB, pin);break;
	case GPIOC : result = GET_BIT(PINC, pin);break;
	case GPIOD : result = GET_BIT(PIND, pin);break;
	default :break;
	}
	return result;
}
void DIO_voidSetPortDirection( u8 port ,u8 direction)
{
	switch (port)
	{
	case GPIOA : DDRA = direction;break;
	case GPIOB : DDRB = direction;break;
	case GPIOC : DDRC = direction;break;
	case GPIOD : DDRD = direction;break;
	}
}
void DIO_voidSetPortValue( u8 port ,u8 data)
{
	switch (port)
	{
	case GPIOA : PORTA = data;break;
	case GPIOB : PORTB = data;break;
	case GPIOC : PORTC = data;break;
	case GPIOD : PORTD = data;break;
	}
}
