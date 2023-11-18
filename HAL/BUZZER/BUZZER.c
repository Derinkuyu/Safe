/*
 * BUZZER.c
 *
 *  Created on: Sep 9, 2023
 *      Author: m
 */

#include "BUZZER.h"
void BUZZER_Init(u8 port , u8 pin ){
	DIO_voidSetPinDirection(port, pin, OUTPUT);
}
void BUZZER_ON (u8 port,u8 pin){
	DIO_voidSetPinValue(port, pin, HIGH);
}
void BUZZER_OFF (u8 port , u8 pin){
	DIO_voidSetPinValue(port, pin, LOW);
}

