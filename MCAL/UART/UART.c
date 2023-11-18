

#include "UART.h"

void UART_voidInit()
{
	// BUDRATE
	UBRRL = 51 ;
	UBRRH = 0 ;
	// 2- Select Normal Speed OF SAMPLE
	CLR_BIT(UCSRA , 1);
	// Select Asynchronous Mode
	CLR_BIT(UCSRC , 6);
    //Select 8 bits Data
	CLR_BIT(UCSRB , 2);
	SET_BIT(UCSRC , 1);
	SET_BIT(UCSRC , 2);
	// 1 BIT FOR STOP
	CLR_BIT(UCSRC , 3);
	// NO PARITY
	CLR_BIT(UCSRC , 4);
	CLR_BIT(UCSRC , 5);
	//TRANSIMTTER AND RECIEVER ENABLE
	SET_BIT(UCSRB , 3);
	SET_BIT(UCSRB , 4);
}
void UART_voidSendData(u8 data)
{
	while(GET_BIT(UCSRA,5) == 0) {}   // check if transition is complete( bit5 = 1)
	UDR = data;

}

u8 UART_u8RecieveData(void)
{
	while(GET_BIT(UCSRA,7) == 0) {}    //// check if receiving is complete ( bit7 = 1)
	return UDR;

}

void UART_voidSendString( u8 *ptr)
{
	u8 i=0;

	while(ptr[i] != '\0')
	{
		UART_voidSendData(ptr[i]);
		i++;
	}
	UART_voidSendData(ptr[i]);
}

void  UART_voidRecieveString(u8 * ptr)
{
	u8 i=0;
	while(ptr[i] !='\0')
	{
		i++;
		ptr[i]=UART_u8RecieveData();
	}
	ptr[i]='\0';
}


