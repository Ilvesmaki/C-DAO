/**
 * @file waveforms.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define WAVEFORM_SINE 0
#define WAVEFORM_SQUARE 1
#define WAVEFORM_TRIANGLE 2

#define WAVEFORM_COUNT 3
#define WAVEFORM_LUT_SIZE 256

#include "stdint.h"

const uint8_t WAVEFORMS[WAVEFORM_COUNT][WAVEFORM_LUT_SIZE] = {
    {
    0x80, 0x83, 0x86, 0x89, 0x8C, 0x90, 0x93, 0x96,
    0x99, 0x9C, 0x9F, 0xA2, 0xA5, 0xA8, 0xAB, 0xAE,
    0xB1, 0xB3, 0xB6, 0xB9, 0xBC, 0xBF, 0xC1, 0xC4,
    0xC7, 0xC9, 0xCC, 0xCE, 0xD1, 0xD3, 0xD5, 0xD8,
    0xDA, 0xDC, 0xDE, 0xE0, 0xE2, 0xE4, 0xE6, 0xE8,
    0xEA, 0xEB, 0xED, 0xEF, 0xF0, 0xF1, 0xF3, 0xF4,
    0xF5, 0xF6, 0xF8, 0xF9, 0xFA, 0xFA, 0xFB, 0xFC,
    0xFD, 0xFD, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFD,
    0xFD, 0xFC, 0xFB, 0xFA, 0xFA, 0xF9, 0xF8, 0xF6,
    0xF5, 0xF4, 0xF3, 0xF1, 0xF0, 0xEF, 0xED, 0xEB,
    0xEA, 0xE8, 0xE6, 0xE4, 0xE2, 0xE0, 0xDE, 0xDC,
    0xDA, 0xD8, 0xD5, 0xD3, 0xD1, 0xCE, 0xCC, 0xC9,
    0xC7, 0xC4, 0xC1, 0xBF, 0xBC, 0xB9, 0xB6, 0xB3,
    0xB1, 0xAE, 0xAB, 0xA8, 0xA5, 0xA2, 0x9F, 0x9C,
    0x99, 0x96, 0x93, 0x90, 0x8C, 0x89, 0x86, 0x83,
    0x80, 0x7D, 0x7A, 0x77, 0x74, 0x70, 0x6D, 0x6A,
    0x67, 0x64, 0x61, 0x5E, 0x5B, 0x58, 0x55, 0x52,
    0x4F, 0x4D, 0x4A, 0x47, 0x44, 0x41, 0x3F, 0x3C,
    0x39, 0x37, 0x34, 0x32, 0x2F, 0x2D, 0x2B, 0x28,
    0x26, 0x24, 0x22, 0x20, 0x1E, 0x1C, 0x1A, 0x18,
    0x16, 0x15, 0x13, 0x11, 0x10, 0x0F, 0x0D, 0x0C,
    0x0B, 0x0A, 0x08, 0x07, 0x06, 0x06, 0x05, 0x04,
    0x03, 0x03, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03,
    0x03, 0x04, 0x05, 0x06, 0x06, 0x07, 0x08, 0x0A,
    0x0B, 0x0C, 0x0D, 0x0F, 0x10, 0x11, 0x13, 0x15,
    0x16, 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22, 0x24,
    0x26, 0x28, 0x2B, 0x2D, 0x2F, 0x32, 0x34, 0x37,
    0x39, 0x3C, 0x3F, 0x41, 0x44, 0x47, 0x4A, 0x4D,
    0x4F, 0x52, 0x55, 0x58, 0x5B, 0x5E, 0x61, 0x64,
    0x67, 0x6A, 0x6D, 0x70, 0x74, 0x77, 0x7A, 0x7D
    },
    {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff
    },
    {
    0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e, 0x10,
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20,
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30,
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40,
    0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50,
    0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60,
    0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70,
    0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80,
    0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d, 0x8f,
    0x91, 0x93, 0x95, 0x97, 0x99, 0x9b, 0x9d, 0x9f,
    0xa1, 0xa3, 0xa5, 0xa7, 0xa9, 0xab, 0xad, 0xaf,
    0xb1, 0xb3, 0xb5, 0xb7, 0xb9, 0xbb, 0xbd, 0xbf,
    0xc1, 0xc3, 0xc5, 0xc7, 0xc9, 0xcb, 0xcd, 0xcf,
    0xd1, 0xd3, 0xd5, 0xd7, 0xd9, 0xdb, 0xdd, 0xdf,
    0xe1, 0xe3, 0xe5, 0xe7, 0xe9, 0xeb, 0xed, 0xef,
    0xf1, 0xf3, 0xf5, 0xf7, 0xf9, 0xfb, 0xfd, 0xff,
    0xfd, 0xfb, 0xf9, 0xf7, 0xf5, 0xf3, 0xf1, 0xef,
    0xed, 0xeb, 0xe9, 0xe7, 0xe5, 0xe3, 0xe1, 0xdf,
    0xdd, 0xdb, 0xd9, 0xd7, 0xd5, 0xd3, 0xd1, 0xcf,
    0xcd, 0xcb, 0xc9, 0xc7, 0xc5, 0xc3, 0xc1, 0xbf,
    0xbd, 0xbb, 0xb9, 0xb7, 0xb5, 0xb3, 0xb1, 0xaf,
    0xad, 0xab, 0xa9, 0xa7, 0xa5, 0xa3, 0xa1, 0x9f,
    0x9d, 0x9b, 0x99, 0x97, 0x95, 0x93, 0x91, 0x8f,
    0x8d, 0x8b, 0x89, 0x87, 0x85, 0x83, 0x81, 0x80,
    0x7e, 0x7c, 0x7a, 0x78, 0x76, 0x74, 0x72, 0x70,
    0x6e, 0x6c, 0x6a, 0x68, 0x66, 0x64, 0x62, 0x60,
    0x5e, 0x5c, 0x5a, 0x58, 0x56, 0x54, 0x52, 0x50,
    0x4e, 0x4c, 0x4a, 0x48, 0x46, 0x44, 0x42, 0x40,
    0x3e, 0x3c, 0x3a, 0x38, 0x36, 0x34, 0x32, 0x30,
    0x2e, 0x2c, 0x2a, 0x28, 0x26, 0x24, 0x22, 0x20,
    0x1e, 0x1c, 0x1a, 0x18, 0x16, 0x14, 0x12, 0x10,
    0x0e, 0x0c, 0x0a, 0x08, 0x06, 0x04, 0x02, 0x00,
    }
};
