/**
 * @file midi.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "midi.h"
#include "Arduino.h"

#define BT0 (m_buffer[0])
#define BT1 (m_buffer[1])
#define BT2 (m_buffer[2])

MidiReceiver::MidiReceiver()
{
    for (uint8_t i = 0; i < MIDI_CMD_SIZE; i++)
    {
        m_buffer[i] = 0;
    }

    Serial.begin(31250);
}

MidiReceiver::~MidiReceiver()
{
    Serial.end();
}

MIDI_data_t MidiReceiver::TryGetCommand()
{
    MIDI_data_t data = {MIDI_NO_COMMAND, 0, 0, 0};

    if(Serial.available() > 0)
    {
        uint8_t byte;
        Serial.readBytes(&byte, sizeof(byte));
        AddByteToBuffer(byte);
        data = TryDecodeCommand();
    }

    return data;
}

void MidiReceiver::AddByteToBuffer(uint8_t byte)
{
    m_buffer[2] = m_buffer[1];
    m_buffer[1] = m_buffer[0];
    m_buffer[0] = byte;
}

MIDI_data_t MidiReceiver::TryDecodeCommand()
{
    MIDI_data_t data = {MIDI_NO_COMMAND, 0, 0, 0};

    if ((BT2 & 0xF0) == 0x90)
    {
        data.cmd = MIDI_NOTE_ON;
        data.channel = BT2 & 0x0F;
        data.pitch = BT1;
        data.velocity = BT0;
    }
    else if ((BT2 & 0xF0) == 0x80)
    {
        data.cmd = MIDI_NOTE_OFF;
        data.channel = BT2 & 0x0F;
        data.pitch = BT1;
        data.velocity = BT0;
    }

    return data;
}
