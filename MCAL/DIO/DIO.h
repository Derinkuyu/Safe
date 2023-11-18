

#include "../../LIB/STD_TYPES/STD_TYPES.h"

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1

#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3

void  DIO_init(void);
void DIO_voidSetPinDirection(u8 port ,u8 pin , u8 direction);
void DIO_voidSetPinValue(u8 port ,u8 pin , u8 value);
u8 DIO_u8GetPinValue(u8 port ,u8 pin);
void DIO_voidSetPortDirection( u8 port ,u8 direction);
void DIO_voidSetPortValue( u8 port ,u8 data);

#endif /* MCAL_DIO_DIO_H_ */
