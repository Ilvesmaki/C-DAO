/**
 * @file mode_select.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "mode_select.h"
#include "stdbool.h"

ModeSelect::ModeSelect()
{
    m_mode = MODESELECT_DISABLED;

    // Set button pins as output and high: all LEDs off
    DDRC |= ((1<<MODE_SINE_PIN) | (1<<MODE_SQUARE_PIN) | (1<<MODE_TRIANGLE_PIN));
    PORTC |= ((1<<MODE_SINE_PIN) | (1<<MODE_SQUARE_PIN) | (1<<MODE_TRIANGLE_PIN));
}

ModeSelect::~ModeSelect()
{

}

void ModeSelect::ReadPinState()
{
    uint8_t sine     =  (uint8_t)(PINC & ~(1 << MODE_SINE_PIN));
    uint8_t square   =  (uint8_t)(PINC & ~(1 << MODE_SQUARE_PIN));
    uint8_t triangle =  (uint8_t)(PINC & ~(1 << MODE_TRIANGLE_PIN));

    if ((sine + square + triangle) > 1)
    {
        m_mode = MODESELECT_DISABLED;
    }
    else switch (m_mode)
    {
    case MODESELECT_DISABLED:
        if (sine && !square && !triangle)
        {
            m_mode = MODESELECT_SINE;
            PORTC &= ~(1 << MODE_SINE_PIN);
        }
        else if (!sine && square && !triangle)
        {
            m_mode = MODESELECT_SQUARE;
            PORTC &= ~(1 << MODE_SQUARE_PIN);
        }
        else if (!sine && !square && triangle)
        {
            m_mode = MODESELECT_TRIANGLE;
            PORTC &= ~(1 << MODE_TRIANGLE_PIN);
        }
        break;

    case MODESELECT_SINE:
        PORTC |= ((1<<MODE_SINE_PIN) | (1<<MODE_SQUARE_PIN) | (1<<MODE_TRIANGLE_PIN));
        if (square && !triangle)
        {
            m_mode = MODESELECT_SQUARE;
            PORTC &= ~(1 << MODE_SQUARE_PIN);
        }
        else if (!square && triangle)
        {
            m_mode = MODESELECT_TRIANGLE;
            PORTC &= ~(1 << MODE_TRIANGLE_PIN);
        }
        break;

    case MODESELECT_SQUARE:
        PORTC |= ((1<<MODE_SINE_PIN) | (1<<MODE_SQUARE_PIN) | (1<<MODE_TRIANGLE_PIN));
        if (sine && !triangle)
        {
            m_mode = MODESELECT_SINE;
            PORTC &= ~(1 << MODE_SINE_PIN);
        }
        else if (!sine && triangle)
        {
            m_mode = MODESELECT_TRIANGLE;
            PORTC &= ~(1 << MODE_TRIANGLE_PIN);
        }
        break;

    case MODESELECT_TRIANGLE:
        PORTC |= ((1<<MODE_SINE_PIN) | (1<<MODE_SQUARE_PIN) | (1<<MODE_TRIANGLE_PIN));
        if (sine && !square)
        {
            m_mode = MODESELECT_SINE;
            PORTC &= ~(1 << MODE_SINE_PIN);
        }
        else if (!sine && square)
        {
            m_mode = MODESELECT_SQUARE;
            PORTC &= ~(1 << MODE_SQUARE_PIN);
        }
        break;

    default:
        break;
    }
}

MODESELECT_mode_e ModeSelect::GetMode()
{
    return m_mode;
}
