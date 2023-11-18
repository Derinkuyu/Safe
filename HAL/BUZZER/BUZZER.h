/*
 * BUZZER.h
 *
 *  Created on: Sep 9, 2023
 *      Author: m
 */

#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_

#include "..\..\MCAL\DIO\DIO.h"
#include "..\..\LIB\STD_TYPES\STD_TYPES.h"

void BUZZER_Init(u8 port , u8 pin );
void BUZZER_ON (u8 port, u8 pin);
void BUZZER_OFF (u8 port , u8 pin);


#endif /* HAL_BUZZER_BUZZER_H_ */
