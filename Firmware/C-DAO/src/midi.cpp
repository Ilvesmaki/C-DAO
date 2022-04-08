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
    for (uint8_t i = MIDI_CMD_SIZE; i > 1; i--)
    {
        m_buffer[i-1] = m_buffer[i-2];
    }

    m_buffer[0] = byte;
}

MIDI_data_t MidiReceiver::TryDecodeCommand()
{
    MIDI_data_t data = {MIDI_NO_COMMAND, 0, 0, 0};

    if ((BT2 & 0xF0) == 0x90)
    {
        // Note on message consists of 3 bytes that are received in order:
        // status byte: 1001 CCCC, CCCC is channel from 0 to 15
        // Data byte 1: 0PPP PPPP, 7 bit note pitch 0 to 127
        // Data byte 2: 0VVV VVVV, 7 bit velocity 0 to 127

        data.cmd = MIDI_NOTE_ON;
        data.channel = BT2 & 0x0F;
        data.pitch = BT1;
        data.velocity = BT0;
    }
    else if ((BT2 & 0xF0) == 0x80)
    {
        // Note off message is similar to note on but satus byte is as follows:
        // status byte: 1000 CCCC, CCCC is channel from 0 to 15

        data.cmd = MIDI_NOTE_OFF;
        data.channel = BT2 & 0x0F;
        data.pitch = BT1;
        data.velocity = BT0;
    }

    return data;
}
