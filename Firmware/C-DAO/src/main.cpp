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

DAC f_dac;
ModeSelect f_modeSelect;
SignalGenerator f_generator;

MODESELECT_mode_e f_mode;

void setup() {
    f_generator.SetDac(&f_dac);
    f_mode = MODESELECT_DISABLED;
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
