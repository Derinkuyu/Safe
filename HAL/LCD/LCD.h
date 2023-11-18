

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include "..\..\MCAL\DIO\DIO.h"
#include "..\..\LIB\STD_TYPES\STD_TYPES.h"
#include "..\..\LIB\CONFIG_MAP\CONFIG_MAP.h"
#include <util\delay.h>


#define RS    PIN0
#define RW    PIN1
#define EN    PIN2

#define COMMAND 0
#define DATA 1

#define WRITE 0
#define READ 1

#define LCD_CLR 0x01
#define LCD_CURSOR_HOME 0x03
#define LCD_DISP_CURSOR_ON 0x0C
#define LCD_HOME_ADDRESS 0x80
#define LCD_NEW_LINE 0xC0
#define LCD_8bit_mode_2lines_5x7_font 0x38
#define LCD_Entry_Mode_Set 0x06

void LCD_voidInit();
void LCD_voidSendCommand( u8 cmnd );
void LCD_voidSendChar( u8 char_data );
void LCD_voidSendString( u8 *str );
void LCD_voidSendNum(u16 data);
void LCD_Clear();
void LCD_voidSetCursor(u8 row, u8 col);


#endif /* HAL_LCD_LCD_H_ */
