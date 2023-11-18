/*
 * CONFIG_MAP.h
 *
 *  Created on: Sep 8, 2023
 *      Author: m
 */

#ifndef LIB_CONFIG_MAP_CONFIG_MAP_H_
#define LIB_CONFIG_MAP_CONFIG_MAP_H_

#include "../../LIB/STD_TYPES/STD_TYPES.h"

/*********************************************
*                            DIO-PINS        *
**********************************************/
//----PORT A---//
#define PORTA  *((volatile u8 *) (0x3B))   //OUTPUT
#define DDRA *((volatile u8 *) (0x3A))    // CHOOSE    (input , output)
#define PINA  *((volatile u8 *) (0x39))   //INPUT

//----PORT B----//
#define PORTB  *((volatile u8 *)(0x38))
#define DDRB *((volatile u8 *)(0x37))
#define PINB  *((volatile u8 *)(0x36))

//----PORTC----//
#define PORTC  *((volatile u8 *) (0x35))
#define DDRC *((volatile u8 *) (0x34))
#define PINC  *((volatile u8 *) (0x33))

//----PORTD----//
#define PORTD  *((volatile u8 *) (0x32))
#define DDRD   *((volatile u8 *) (0x31))
#define PIND   *((volatile u8 *) (0x30))
//------------------------------------------------------------------------------------//

// ---  PIN --//
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//-------------------------------------------------------------------------------//
/*                 TIMER Registers                       */
#define TCNT0   *((volatile u8 *) (0x52))
#define TCCR0   *((volatile u8 *) (0x53))
#define TIFR   *((volatile u8  *) (0x58))
#define TIMSK  *((volatile u8 *) (0x59))
#define OCR0  *((volatile u8 *) (0x5C))

//----------------------------------------------//
/*                         INTERUPTS Registers                  */
#define SREG   *((volatile u8 *) (0x5F))  //Global interrupt register
#define GICR   *((volatile u8 *)(0x5B))
#define GIFR  *((volatile u8 *)(0x5A))
#define MCUCR  *((volatile u8 *)(0x55))
#define MCUCSR  *((volatile u8 *)(0x54))

//----------------------------------------------//
/*                           ADC Registers                                 */
#define ADMUX  *((volatile u8 *)(0x27))
#define ADCSRA *((volatile u8 *)(0x26))
#define ADCH  *((volatile u8 * )(0x25))
#define ADCL  *((volatile u8 * )(0x24))
#define SFIOR  *((volatile u8 * )(0x50))
//-------------------------------------------------------//

/*                             UART Registers                                */

#define UDR  *((volatile u8 *)(0x2C))  //Data Register
#define UCSRA *((volatile u8 *)(0x2B))
#define UCSRB *((volatile u8 *)(0x2A))
#define UCSRC *((volatile u8 *)(0x40))
#define UBRRL  *((volatile u8 *)(0x29))  //Baud Rate Register
#define UBRRH  *((volatile u8 *)(0x40))  //Baud Rate Register


//--------------------------------------------------------//
/*					EEPROM Registers            */
#define EEAR *((volatile u8 *)(0x3E))
#define EEARL *((volatile u8 *)(0x3E))
#define EEARH *((volatile u8 *)(0x3F))
#define EEDR *((volatile u8 *)(0x3D))
#define EECR *((volatile u8 *)(0x3C))
/* EEPROM Control Register */
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3

#endif /* LIB_CONFIG_MAP_CONFIG_MAP_H_ */
