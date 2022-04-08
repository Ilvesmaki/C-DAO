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
#include "signal_generator.h"
#include "frequency.h"
#include "midi.h"
#include "midi_notes.h"
#include "waveforms.h"

MidiReceiver f_midiReceiver;
DAC f_dac;
ModeSelect f_modeSelect;
Frequency f_frequency;
SignalGenerator f_generator;

MODESELECT_mode_e f_mode;

static uint32_t PitchToProgramFrequency(uint8_t pitch);

static void timerCallback()
{
    f_generator.Execute();
}

void setup() {
    f_generator.SetDac(&f_dac);
    f_mode = MODESELECT_DISABLED;

    f_frequency.SetCallback(timerCallback);
    f_frequency.SetEnable(false);
}

void loop() {
    f_modeSelect.ReadPinState();
    MIDI_data_t midicommand = f_midiReceiver.TryGetCommand();
    MODESELECT_mode_e newMode = f_modeSelect.GetMode();

    if (newMode != f_mode)
    {
        f_mode = newMode;
        f_generator.SetMode(f_mode);
    }

    if (midicommand.cmd == MIDI_NOTE_ON)
    {
        f_frequency.SetFrequency(PitchToProgramFrequency(midicommand.pitch));
        f_frequency.SetEnable(true);
    }
    else if (midicommand.cmd == MIDI_NOTE_OFF)
    {
        f_frequency.SetEnable(false);
    }
} 

uint32_t PitchToProgramFrequency(uint8_t pitch)
{
    uint32_t noteFreq_Hz = 0;

    if (pitch < MIDI_NOTE_COUNT)
    {
        noteFreq_Hz = (uint32_t)(MIDINOTES[pitch]);
    }

    return noteFreq_Hz * WAVEFORM_LUT_SIZE;
}
