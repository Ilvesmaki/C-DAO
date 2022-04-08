/**
 * @file signal_generator.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "signal_generator.h"
#include "waveforms.h"

SignalGenerator::SignalGenerator()
{
    m_mode = MODESELECT_DISABLED;
    m_dac = nullptr;
}
SignalGenerator::~SignalGenerator()
{

}

void SignalGenerator::SetDac(DAC* dac)
{
    m_dac = dac;
}

void SignalGenerator::SetMode(MODESELECT_mode_e mode)
{
    m_mode = mode;
    m_lutIndex = 0;
}

void SignalGenerator::Execute()
{
    if (m_dac)
    {
        switch (m_mode)
        {
        case MODESELECT_DISABLED:
            m_dac->SetLevel(0);
            break;

        case MODESELECT_SINE:
            m_dac->SetLevel(WAVEFORMS[WAVEFORM_SINE][m_lutIndex]);
            break;

        case MODESELECT_SQUARE:
            m_dac->SetLevel(WAVEFORMS[WAVEFORM_SQUARE][m_lutIndex]);
            break;
        
        case MODESELECT_TRIANGLE:
            m_dac->SetLevel(WAVEFORMS[WAVEFORM_TRIANGLE][m_lutIndex]);
            break;

        default:
            break;
        }
    }

    m_lutIndex++;
}
