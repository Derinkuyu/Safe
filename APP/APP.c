
#include "APP.h"

u8 pass[4];

void APP_Init(void)
{
	LCD_voidInit();
	KEYPAD_Init();
	ALARM_Init();
	UART_voidInit();
	DIO_voidSetPinDirection(GPIOD, PIN4, OUTPUT);
	DIO_voidSetPinValue(GPIOD, PIN4, LOW);
}

void APP_WelcomeMessage(void)
{
	LCD_voidSendCommand(LCD_HOME_ADDRESS);
	u8 wel[] = "Welcome to Safe";
	for (int i = 0; i < 15; i++)
	{
		LCD_voidSendChar(wel[i]);
		_delay_ms(50);
	}
	_delay_ms(2000);
}

void APP_SetPassword(void)
{
	LCD_Clear();
	LCD_voidSendString("Set new password: ");
	LCD_voidSendCommand(LCD_NEW_LINE);
	u8 count = 0;
	while(count < 4)
	{
		u8 key = NOT_PRESSED;

		do
		{
			key = GET_PRESSED_KEY();
		} while(key == NOT_PRESSED);

		pass[count] = key;
		LCD_voidSendChar(key);
		_delay_ms(300);
		count++;
		LCD_voidSetCursor(2, count);
		LCD_voidSendChar('*');
	}
	eeprom_write_byte(PASS_LOC1, pass[0]);
	eeprom_write_byte(PASS_LOC2, pass[1]);
	eeprom_write_byte(PASS_LOC3, pass[2]);
	eeprom_write_byte(PASS_LOC4, pass[3]);
	eeprom_write_byte(STATUS_LOC, 0x00);
}

u8 APP_EnterPassword(void)
{
	LCD_Clear();
	LCD_voidSendString("Enter password:");
	LCD_voidSendCommand(LCD_NEW_LINE);
	u8 count = 0;
	while(count < 4)
	{
		u8 key = NOT_PRESSED;

		do
		{
			key = GET_PRESSED_KEY();
		} while(key == NOT_PRESSED);

		pass[count] = key;
		LCD_voidSendChar(key);
		_delay_ms(300);
		count++;
		LCD_voidSetCursor(2, count);
		LCD_voidSendChar('*');
	}

	// check if the password is correct or not
	return APP_CheckPassword();
}

void APP_WrongPassword(void)
{
	LCD_Clear();
	LCD_voidSendString("Wrong password");
	_delay_ms(500);
}

void APP_CorrectPassword(void)
{
	LCD_Clear();
	LCD_voidSendString("Correct password");
	DIO_voidSetPinValue(GPIOD, PIN4, HIGH); // green led
	_delay_ms(1500);

	/* UART communication via bluetooth to send notification to the owner*/
	LCD_Clear();
	u8 notification[] = "Safe opened!";
	UART_voidSendString(notification);
}

void APP_TryAgain(u8 tries)
{
	if (tries == MAX_TRIES)
	{
		/* UART communication via bluetooth to send notification to the owner*/
		u8 notification1[] = "WATCHOUT!!!   IT IS THIEF!!!";
		UART_voidSendString(notification1);

		LCD_Clear();
		LCD_voidSendString("THIEF");
		_delay_ms(3000);

		while(1)
		{
			ALARM_ON();
		}
	}
	LCD_voidSendCommand(LCD_NEW_LINE);
	LCD_voidSendNum(MAX_TRIES - tries);
	LCD_voidSendString(" tries left");
	_delay_ms(1500);
}

u8 APP_CheckPassword()
{
	if (eeprom_read_byte(PASS_LOC1) != pass[0])
		return WRONG;
	if (eeprom_read_byte(PASS_LOC2) != pass[1])
		return WRONG;
	if (eeprom_read_byte(PASS_LOC3) != pass[2])
		return WRONG;
	if (eeprom_read_byte(PASS_LOC4) != pass[3])
		return WRONG;

	return CORRECT;
}

void APP_ResetPassword()
{
	LCD_Clear();
	LCD_voidSendString("Press 1 For");
	LCD_voidSendCommand(LCD_NEW_LINE);
	LCD_voidSendString("Change Password");
	u8 key = NOT_PRESSED;
	do
	{
		key = GET_PRESSED_KEY();
	} while(key == NOT_PRESSED);
	DIO_voidSetPinValue(GPIOD, PIN4, LOW); // green led
	if(key != '1'){
		return;
	}
	APP_SetPassword();
}
