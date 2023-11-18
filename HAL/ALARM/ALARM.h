/*
 * ALARM.h
 *
 *  Created on: Sep 8, 2023
 *      Author: m
 */

#ifndef HAL_ALARM_ALARM_H_
#define HAL_ALARM_ALARM_H_


#include "..\..\MCAL\DIO\DIO.h"
#include "..\BUZZER\BUZZER.h"
#include "..\..\LIB\CONFIG_MAP\CONFIG_MAP.h"
#include "..\LED\LED.h"
#include <util\delay.h>

#define alarmPORT GPIOD
#define redLED PIN3
#define BUZZER PIN2

void ALARM_Init(void);
void ALARM_ON(void);

#endif /* HAL_ALARM_ALARM_H_ */
