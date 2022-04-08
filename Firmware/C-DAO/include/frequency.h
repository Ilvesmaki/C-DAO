/**
 * @file frequency.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef FREQUENCY_H
#define FREQUENCY_H

#include "stdint.h"

typedef void (*callback_f)();

class Frequency
{
public:
    Frequency();
    ~Frequency();

    void SetEnable(bool set);
    void SetFrequency(uint32_t freq);
    void SetCallback(callback_f callback);
};

#endif // FREQUENCY_H