

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

#include "..\..\MCAL\DIO\DIO.h"
#include "..\..\LIB\STD_TYPES\STD_TYPES.h"


void LED_Init(u8 port , u8 pin );
void LED_ON (u8 port, u8 pin);
void LED_OFF (u8 port , u8 pin);
#endif /* HAL_LED_LED_H_ */
