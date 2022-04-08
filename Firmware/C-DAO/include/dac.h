/**
 * @file dac.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DAC_H
#define DAC_H

#include "stdint.h"

class DAC 
{
public:
    DAC();
    ~DAC();

    void SetLevel(uint8_t level);
};

#endif // DAC_H