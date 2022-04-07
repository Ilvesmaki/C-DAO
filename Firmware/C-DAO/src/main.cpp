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
#include "dac.h"
#include "mode_select.h"

ModeSelect f_modeSelect;
DAC f_dac;

void setup() {

}

void loop() {
    f_modeSelect.ReadPinState();
    f_dac.SetLevel(0);
}
