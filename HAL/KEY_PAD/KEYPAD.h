

#ifndef HAL_KEY_PAD_KEYPAD_H_
#define HAL_KEY_PAD_KEYPAD_H_

#include <util\delay.h>
#include "..\..\LIB\STD_TYPES\STD_TYPES.h"
#include "..\..\LIB\CONFIG_MAP\CONFIG_MAP.h"
#include "..\..\LIB\BIT_MATH\BIT_MATH.h"
#include "..\..\MCAL\DIO\DIO.h"

#define KEYPAD_PORT GPIOC
#define NOT_PRESSED 0xff

void KEYPAD_Init(void);
u8 GET_PRESSED_KEY();

#endif /* HAL_KEY_PAD_KEYPAD_H_ */
