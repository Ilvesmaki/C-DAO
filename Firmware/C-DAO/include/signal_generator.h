/**
 * @file signal_generator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SIGNAL_GENERATOR_H
#define SIGNAL_GENERATOR_H

#include "mode_select.h"
#include "dac.h"

class SignalGenerator
{
public:
    SignalGenerator();
    ~SignalGenerator();

    void SetDac(DAC* dac);
    void SetMode(MODESELECT_mode_e mode);

    // One cycle is 255 values
    void Execute();
private:
    DAC* m_dac;
    MODESELECT_mode_e m_mode;
    uint8_t m_lutIndex;
};

#endif // SIGNAL_GENERATOR_H