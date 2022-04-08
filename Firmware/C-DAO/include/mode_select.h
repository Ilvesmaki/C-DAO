/**
 * @file mode_select.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MODE_SELECT_H
#define MODE_SELECT_H

#include "avr/io.h"

#define MODE_SINE_PIN       PINC2
#define MODE_SQUARE_PIN     PINC3
#define MODE_TRIANGLE_PIN    PINC4

typedef enum {
    MODESELECT_DISABLED = 0,
    MODESELECT_SINE,
    MODESELECT_SQUARE,
    MODESELECT_TRIANGLE
} MODESELECT_mode_e;

class ModeSelect 
{
public:
    ModeSelect();
    ~ModeSelect();

    void ReadPinState();
    MODESELECT_mode_e GetMode();

private:
    MODESELECT_mode_e m_mode;
};

#endif // MODE_SELECT_H