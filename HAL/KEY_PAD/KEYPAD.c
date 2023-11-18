
#include "KEYPAD.h"



void KEYPAD_Init()
{
	/* Initialize first four bits in keypad as output pins and last four as input */
	DIO_voidSetPortDirection (KEYPAD_PORT,0x0F);

	/*****************************************************/
	/*connect pull up resistance to the input pins*/
	DIO_voidSetPortValue(KEYPAD_PORT, 0XF0);
	/****************************************************/
}

u8 GET_PRESSED_KEY()
{
	u8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}}; //keypad buttons
	u8 row; //which indicate the given output  pin
	u8 coloumn; //which indicate the given input pin
	u8 key_pressed_indicator; //the variable  which contain the key pressed

	u8 returnval=NOT_PRESSED; //the variable contain the value which will be returned which will be key pressed or not pressed in case of no key pressed
	for(row=0;row<4;row++)
	{
		/*stop the work of keypad firstly*/
		DIO_voidSetPinValue(KEYPAD_PORT,PIN0,1);
		DIO_voidSetPinValue(KEYPAD_PORT,PIN1,1);
		DIO_voidSetPinValue(KEYPAD_PORT,PIN2,1);
		DIO_voidSetPinValue(KEYPAD_PORT,PIN3,1);
		/*************************************/
		_delay_ms(50);
		DIO_voidSetPinValue(KEYPAD_PORT,row,0);//write 0 to the first pin in keypad (output pin from MC)

		for(coloumn=0;coloumn<4;coloumn++)
		{
			DIO_voidSetPinValue(KEYPAD_PORT,(coloumn+4), 1);
			key_pressed_indicator= DIO_u8GetPinValue(KEYPAD_PORT,(coloumn+4)); // read the input pins of MC which connected to keypad
			if(key_pressed_indicator==0)// will be 0 only if any key pressed
			{
				returnval = arr[row][coloumn]; //put the selected pressed key to the retrurnval
				DIO_voidSetPinValue(KEYPAD_PORT,(coloumn+4), 1);
				_delay_ms(1500);
				break; // break from the loop
			}
		}
	}
	return returnval ; //return the pressed key in case of key pressed or return 0xff in case of no key pressed
}
