/**
 * @file dac.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "dac.h"
#include "avr/io.h"

#define DAC1 PIND5
#define DAC2 PIND6
#define DAC3 PIND7
#define DAC4 PINB0
#define DAC5 PINB1
#define DAC6 PINB2
#define DAC7 PINC0
#define DAC8 PINC1

DAC::DAC()
{
    DDRD |= ((1<<DAC1)|(1<<DAC2)|(1<<DAC3));
    DDRB |= ((1<<DAC4)|(1<<DAC5)|(1<<DAC6));
    DDRC |= ((1<<DAC7)|(1<<DAC8));
    
    SetLevel(0);
}

DAC::~DAC()
{

}

void DAC::SetLevel(uint8_t level)
{
    PORTD &= (0x1F | ((level & 0x1)<<DAC1) | ((level & 0x2)<<DAC2)| ((level & 0x4)<<DAC3));
    PORTB &= (0xF8 | ((level & 0x8)<<DAC4) | ((level & 0x10)<<DAC5)| ((level & 0x20)<<DAC6));
    PORTC &= (0xFC | ((level & 0x40)<<DAC7) | ((level & 0x80)<<DAC8));
}
