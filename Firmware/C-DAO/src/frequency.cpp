/**
 * @file frequency.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "frequency.h"
#include "Arduino.h"

#define CPU_HZ F_CPU
#define TIMER_PRESCALER 8
#define OCR0A_COEF (CPU_HZ/TIMER_PRESCALER)

callback_f f_callback = nullptr;

ISR(TIMER0_COMPA_vect)
{
    if(f_callback)
    {
        f_callback();
    }
}

static uint8_t CalculateOCR0AValue(uint32_t freq_Hz)
{
    if(freq_Hz == 0)
    {
        return 0;
    }
    // OCR0A must be set according to
    // OCR0A = (cpu_freq/prescaler)*time_seconds

    float period_s = (1.0f / (float)(freq_Hz));
    return (uint8_t)((float)(OCR0A_COEF)* period_s);
}

Frequency::Frequency()
{
    TCCR0A = (1 << WGM01);
    OCR0A = CalculateOCR0AValue(0);
    TIMSK0 |= (1 << OCIE0A);

    // prescaler
    TCCR0B |= (1 << CS01);
}

Frequency::~Frequency()
{

}

void Frequency::SetEnable(bool set)
{
    if (set)
    {
        sei();
    }
    else
    {
        cli();
    }
}

void Frequency::SetFrequency(uint32_t freq)
{
    OCR0A = CalculateOCR0AValue(freq);
}

void Frequency::SetCallback(callback_f callback)
{
    f_callback = callback;
}
