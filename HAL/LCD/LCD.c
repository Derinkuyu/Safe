
#include "LCD.h"

void LCD_voidInit()
{
	DIO_voidSetPortDirection(GPIOA, 0xFF);
    DIO_voidSetPortDirection(GPIOB , 0xFF);

    _delay_ms(30);
    LCD_voidSendCommand(LCD_8bit_mode_2lines_5x7_font);
	_delay_ms(3);
    LCD_voidSendCommand(LCD_DISP_CURSOR_ON);
	_delay_ms(3);
    LCD_Clear();
}
void LCD_voidSendCommand( u8 cmnd )
{
    DIO_voidSetPortValue(GPIOA , cmnd );
	DIO_voidSetPinValue(GPIOB , RS , COMMAND);
	DIO_voidSetPinValue(GPIOB , RW , WRITE);
	DIO_voidSetPinValue(GPIOB , EN , HIGH);
	_delay_ms(3);
	DIO_voidSetPinValue(GPIOB , EN , LOW);
	_delay_ms(3);
}

void LCD_voidSendChar( u8 char_data)
{
    DIO_voidSetPortValue(GPIOA , char_data );
	DIO_voidSetPinValue(GPIOB , RS , DATA);
	DIO_voidSetPinValue(GPIOB , RW , WRITE);
	DIO_voidSetPinValue(GPIOB , EN , HIGH);
	_delay_ms(3);
	DIO_voidSetPinValue(GPIOB , EN , LOW);
	_delay_ms(3);
}
void LCD_voidSendString( u8 *str )
{
	u8 i ;
	for ( i = 0 ; str[i] != 0 ; i++ )
	{
		LCD_voidSendChar(str[i]);
	}
}
void LCD_voidSendNum(u16 data)
{
	if(data<0)
	{
		LCD_voidSendChar('-');
		data=-data;
	}
	if(data==0)
	{
		LCD_voidSendChar('0');
		return;
	}
	if(data>=10)
	{
		LCD_voidSendNum(data/10);
	}
	LCD_voidSendChar((data%10)+'0');
}
void LCD_Clear()
{
	LCD_voidSendCommand(LCD_CLR);     /* clear LCD*/
	LCD_voidSendCommand(LCD_HOME_ADDRESS);    /*cursor return to the start*/
}

void LCD_voidSetCursor(u8 row, u8 col) {
	u8 data;
	if(row == 1){
		data= LCD_HOME_ADDRESS +col-1 ;
	}
	else if (row==2){
		data=LCD_NEW_LINE+col-1;
	}
    LCD_voidSendCommand(data);
}


