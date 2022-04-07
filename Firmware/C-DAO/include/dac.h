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

#include "stdint.h"

class DAC 
{
public:
    DAC();
    ~DAC();

    void SetLevel(uint8_t level);
};
