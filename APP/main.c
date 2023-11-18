/*
 *  Program Flow:
 *  1) the user is asked to setup a new password
 *  2) a menu shows to either
 *  	change password
 *  	enter password --> 3 tries
 *  		correct pass: open, green LED
 *  		wrong pass: try again on LCD, tries--
 *  		when tries = 0: red LED, buzzer
 */

#include "APP.h"

int main(void)
{
	APP_Init();
	APP_WelcomeMessage();
	u8 tries = 0;

	while(1)
	{
		if (eeprom_read_byte(STATUS_LOC) == 0xFF)
		{
			APP_SetPassword();
		}
		else
		{
			u8 state = APP_EnterPassword();
			if (state == CORRECT)
			{
				tries = 0;
				APP_CorrectPassword();
				APP_ResetPassword();
			}
			else
			{
				tries++;
				APP_WrongPassword();
				APP_TryAgain(tries);
			}
			_delay_ms(1500);
		}
	}
}
