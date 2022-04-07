/**
 * @file MIDI.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "stdint.h"

#define MIDI_CMD_SIZE 3

typedef enum {
    MIDI_NOTE_ON,
    MIDI_NOTE_OFF,
    MIDI_NO_COMMAND
} MIDI_command_e;

typedef struct
{
    MIDI_command_e cmd;
    uint8_t channel;
    uint8_t pitch;
    uint8_t velocity;
} MIDI_data_t;

class MidiReceiver
{
public:
    MidiReceiver();
    ~MidiReceiver();

    // Periodical function, reads 1 byte from serial
    MIDI_data_t TryGetCommand();

private:
    void AddByteToBuffer(uint8_t byte);
    MIDI_data_t TryDecodeCommand();
    uint8_t m_buffer[MIDI_CMD_SIZE];
};