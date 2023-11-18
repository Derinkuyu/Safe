/*
 * ALARM.c
 *
 *  Created on: Sep 8, 2023
 *      Author: m
 */


#include "ALARM.h"

void ALARM_Init()
{
	LED_Init(alarmPORT, redLED);
	BUZZER_Init(alarmPORT, BUZZER);
}

void ALARM_ON()
{
	LED_ON(alarmPORT, redLED);
	BUZZER_ON(alarmPORT, BUZZER);
    _delay_ms(500);
    LED_OFF(alarmPORT, redLED);
    BUZZER_OFF(alarmPORT, BUZZER);
    _delay_ms(500);
}
