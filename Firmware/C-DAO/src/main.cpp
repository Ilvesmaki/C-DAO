/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>
#include "signal_generator.h"
#include "frequency.h"

DAC f_dac;
ModeSelect f_modeSelect;
Frequency f_frequency;
SignalGenerator f_generator;

MODESELECT_mode_e f_mode;

void timerCallback()
{
    f_generator.Execute();
}

void setup() {
    f_generator.SetDac(&f_dac);
    f_mode = MODESELECT_DISABLED;

    f_frequency.SetCallback(timerCallback);
    f_frequency.SetEnable(true);
}

void loop() {
    f_modeSelect.ReadPinState();
    MODESELECT_mode_e newMode = f_modeSelect.GetMode();

    if(newMode != f_mode)
    {
        f_mode = newMode;
        f_generator.SetMode(f_mode);
    }
}
