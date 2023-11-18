#ifndef APP_APP_H_
#define APP_APP_H_

#include "..\LIB\STD_TYPES\STD_TYPES.h"
#include "..\LIB\BIT_MATH\BIT_MATH.h"
#include "..\LIB\CONFIG_MAP\CONFIG_MAP.h"
#include "..\MCAL\DIO\DIO.h"
#include "..\MCAL\UART\UART.h"
#include "..\HAL\LCD\LCD.h"
#include "..\HAL\KEY_PAD\KEYPAD.h"
#include "..\HAL\ALARM\ALARM.h"

#include <util/delay.h>
#include <avr/eeprom.h>

#define WRONG 0
#define CORRECT 1

#define  STATUS_LOC 0x20
#define  PASS_LOC1 0x21
#define  PASS_LOC2 0x22
#define  PASS_LOC3 0x23
#define  PASS_LOC4 0x24
#define	 MAX_TRIES 3
#define  NO_PASSWORD 0xFF

void APP_Init(void);
void APP_WelcomeMessage(void);
void APP_SetPassword(void);
u8 APP_EnterPassword(void);
void APP_WrongPassword(void);
void APP_CorrectPassword(void);
void APP_TryAgain(u8 tries);
u8 APP_CheckPassword(void);
void APP_ResetPassword(void);

#endif /* APP_APP_H_ */
