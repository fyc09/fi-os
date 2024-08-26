#include <stdint.h>

#ifndef FONTDATA_H
#define FONTDATA_H

uint8_t FONTDATA_ASCII_8x16[][16] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33,
     0x00, 0x00, 0x00, 0x00},
    {0x00, 0x10, 0x0C, 0x02, 0x10, 0x0C, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00},
    {0x00, 0x40, 0xC0, 0x78, 0x40, 0xC0, 0x78, 0x00, 0x00, 0x04, 0x3F, 0x04,
     0x04, 0x3F, 0x04, 0x00},
    {0x00, 0x70, 0x88, 0x88, 0xFC, 0x08, 0x30, 0x00, 0x00, 0x18, 0x20, 0x20,
     0xFF, 0x21, 0x1E, 0x00},
    {0xF0, 0x08, 0xF0, 0x80, 0x60, 0x18, 0x00, 0x00, 0x00, 0x31, 0x0C, 0x03,
     0x1E, 0x21, 0x1E, 0x00},
    {0x00, 0xF0, 0x08, 0x88, 0x70, 0x00, 0x00, 0x00, 0x1E, 0x21, 0x23, 0x2C,
     0x19, 0x27, 0x21, 0x10},
    {0x00, 0x12, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0xE0, 0x18, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x07,
     0x18, 0x20, 0x40, 0x00},
    {0x00, 0x02, 0x04, 0x18, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0x18,
     0x07, 0x00, 0x00, 0x00},
    {0x40, 0x40, 0x80, 0xF0, 0x80, 0x40, 0x40, 0x00, 0x02, 0x02, 0x01, 0x0F,
     0x01, 0x02, 0x02, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
     0x0F, 0x01, 0x01, 0x01},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x70, 0x00,
     0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
     0x01, 0x01, 0x01, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00,
     0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0xC0, 0x38, 0x04, 0x00, 0x00, 0x60, 0x18, 0x07,
     0x00, 0x00, 0x00, 0x00},
    {0x00, 0xE0, 0x10, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x00, 0x0F, 0x10, 0x20,
     0x20, 0x10, 0x0F, 0x00},
    {0x00, 0x00, 0x10, 0x10, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20,
     0x3F, 0x20, 0x20, 0x00},
    {0x00, 0x70, 0x08, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x00, 0x30, 0x28, 0x24,
     0x22, 0x21, 0x30, 0x00},
    {0x00, 0x30, 0x08, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x18, 0x20, 0x21,
     0x21, 0x22, 0x1C, 0x00},
    {0x00, 0x00, 0x80, 0x40, 0x30, 0xF8, 0x00, 0x00, 0x00, 0x06, 0x05, 0x24,
     0x24, 0x3F, 0x24, 0x24},
    {0x00, 0xF8, 0x88, 0x88, 0x88, 0x08, 0x08, 0x00, 0x00, 0x19, 0x20, 0x20,
     0x20, 0x11, 0x0E, 0x00},
    {0x00, 0xE0, 0x10, 0x88, 0x88, 0x90, 0x00, 0x00, 0x00, 0x0F, 0x11, 0x20,
     0x20, 0x20, 0x1F, 0x00},
    {0x00, 0x18, 0x08, 0x08, 0x88, 0x68, 0x18, 0x00, 0x00, 0x00, 0x00, 0x3E,
     0x01, 0x00, 0x00, 0x00},
    {0x00, 0x70, 0x88, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x1C, 0x22, 0x21,
     0x21, 0x22, 0x1C, 0x00},
    {0x00, 0xF0, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x00, 0x01, 0x12, 0x22,
     0x22, 0x11, 0x0F, 0x00},
    {0x00, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
     0x30, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0,
     0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00, 0x01, 0x02, 0x04,
     0x08, 0x10, 0x20, 0x00},
    {0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x02, 0x02, 0x02,
     0x02, 0x02, 0x02, 0x00},
    {0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x20, 0x10, 0x08,
     0x04, 0x02, 0x01, 0x00},
    {0x00, 0x70, 0x48, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x00, 0x00, 0x30,
     0x37, 0x00, 0x00, 0x00},
    {0xC0, 0x30, 0xC8, 0x28, 0xE8, 0x10, 0xE0, 0x00, 0x07, 0x18, 0x27, 0x28,
     0x2F, 0x28, 0x17, 0x00},
    {0x00, 0x00, 0xC0, 0x38, 0xE0, 0x00, 0x00, 0x00, 0x20, 0x3C, 0x23, 0x02,
     0x02, 0x27, 0x38, 0x20},
    {0x08, 0xF8, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x20,
     0x20, 0x11, 0x0E, 0x00},
    {0xC0, 0x30, 0x08, 0x08, 0x08, 0x08, 0x38, 0x00, 0x07, 0x18, 0x20, 0x20,
     0x20, 0x10, 0x08, 0x00},
    {0x08, 0xF8, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x20, 0x3F, 0x20, 0x20,
     0x20, 0x10, 0x0F, 0x00},
    {0x08, 0xF8, 0x88, 0x88, 0xE8, 0x08, 0x10, 0x00, 0x20, 0x3F, 0x20, 0x20,
     0x23, 0x20, 0x18, 0x00},
    {0x08, 0xF8, 0x88, 0x88, 0xE8, 0x08, 0x10, 0x00, 0x20, 0x3F, 0x20, 0x00,
     0x03, 0x00, 0x00, 0x00},
    {0xC0, 0x30, 0x08, 0x08, 0x08, 0x38, 0x00, 0x00, 0x07, 0x18, 0x20, 0x20,
     0x22, 0x1E, 0x02, 0x00},
    {0x08, 0xF8, 0x08, 0x00, 0x00, 0x08, 0xF8, 0x08, 0x20, 0x3F, 0x21, 0x01,
     0x01, 0x21, 0x3F, 0x20},
    {0x00, 0x08, 0x08, 0xF8, 0x08, 0x08, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F,
     0x20, 0x20, 0x00, 0x00},
    {0x00, 0x00, 0x08, 0x08, 0xF8, 0x08, 0x08, 0x00, 0xC0, 0x80, 0x80, 0x80,
     0x7F, 0x00, 0x00, 0x00},
    {0x08, 0xF8, 0x88, 0xC0, 0x28, 0x18, 0x08, 0x00, 0x20, 0x3F, 0x20, 0x01,
     0x26, 0x38, 0x20, 0x00},
    {0x08, 0xF8, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x20,
     0x20, 0x20, 0x30, 0x00},
    {0x08, 0xF8, 0xF8, 0x00, 0xF8, 0xF8, 0x08, 0x00, 0x20, 0x3F, 0x01, 0x3E,
     0x01, 0x3F, 0x20, 0x00},
    {0x08, 0xF8, 0x30, 0xC0, 0x00, 0x08, 0xF8, 0x08, 0x20, 0x3F, 0x20, 0x00,
     0x07, 0x18, 0x3F, 0x00},
    {0xE0, 0x10, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x0F, 0x10, 0x20, 0x20,
     0x20, 0x10, 0x0F, 0x00},
    {0x08, 0xF8, 0x08, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x20, 0x3F, 0x21, 0x01,
     0x01, 0x01, 0x00, 0x00},
    {0xE0, 0x10, 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x0F, 0x10, 0x28, 0x28,
     0x30, 0x50, 0x4F, 0x00},
    {0x08, 0xF8, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x20, 0x3F, 0x20, 0x00,
     0x03, 0x0C, 0x30, 0x20},
    {0x00, 0x70, 0x88, 0x08, 0x08, 0x08, 0x38, 0x00, 0x00, 0x38, 0x20, 0x21,
     0x21, 0x22, 0x1C, 0x00},
    {0x18, 0x08, 0x08, 0xF8, 0x08, 0x08, 0x18, 0x00, 0x00, 0x00, 0x20, 0x3F,
     0x20, 0x00, 0x00, 0x00},
    {0x08, 0xF8, 0x08, 0x00, 0x00, 0x08, 0xF8, 0x08, 0x00, 0x1F, 0x20, 0x20,
     0x20, 0x20, 0x1F, 0x00},
    {0x08, 0x78, 0x88, 0x00, 0x00, 0xC8, 0x38, 0x08, 0x00, 0x00, 0x07, 0x38,
     0x0E, 0x01, 0x00, 0x00},
    {0x08, 0xF8, 0x00, 0xF8, 0x00, 0xF8, 0x08, 0x00, 0x00, 0x03, 0x3E, 0x01,
     0x3E, 0x03, 0x00, 0x00},
    {0x08, 0x18, 0x68, 0x80, 0x80, 0x68, 0x18, 0x08, 0x20, 0x30, 0x2C, 0x03,
     0x03, 0x2C, 0x30, 0x20},
    {0x08, 0x38, 0xC8, 0x00, 0xC8, 0x38, 0x08, 0x00, 0x00, 0x00, 0x20, 0x3F,
     0x20, 0x00, 0x00, 0x00},
    {0x10, 0x08, 0x08, 0x08, 0xC8, 0x38, 0x08, 0x00, 0x20, 0x38, 0x26, 0x21,
     0x20, 0x20, 0x18, 0x00},
    {0x00, 0x00, 0x00, 0xFE, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x7F,
     0x40, 0x40, 0x40, 0x00},
    {0x00, 0x04, 0x38, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
     0x06, 0x38, 0xC0, 0x00},
    {0x00, 0x02, 0x02, 0x02, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40,
     0x7F, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x04, 0x02, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80,
     0x80, 0x80, 0x80, 0x80},
    {0x00, 0x02, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x19, 0x24, 0x24,
     0x12, 0x3F, 0x20, 0x00},
    {0x10, 0xF0, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x11, 0x20,
     0x20, 0x11, 0x0E, 0x00},
    {0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x20,
     0x20, 0x20, 0x11, 0x00},
    {0x00, 0x00, 0x80, 0x80, 0x80, 0x90, 0xF0, 0x00, 0x00, 0x1F, 0x20, 0x20,
     0x20, 0x10, 0x3F, 0x20},
    {0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x1F, 0x24, 0x24,
     0x24, 0x24, 0x17, 0x00},
    {0x00, 0x80, 0x80, 0xE0, 0x90, 0x90, 0x20, 0x00, 0x00, 0x20, 0x20, 0x3F,
     0x20, 0x20, 0x00, 0x00},
    {0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x6B, 0x94, 0x94,
     0x94, 0x93, 0x60, 0x00},
    {0x10, 0xF0, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x20, 0x3F, 0x21, 0x00,
     0x00, 0x20, 0x3F, 0x20},
    {0x00, 0x80, 0x98, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F,
     0x20, 0x20, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x80, 0x98, 0x98, 0x00, 0x00, 0x00, 0xC0, 0x80, 0x80,
     0x80, 0x7F, 0x00, 0x00},
    {0x10, 0xF0, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x20, 0x3F, 0x24, 0x06,
     0x29, 0x30, 0x20, 0x00},
    {0x00, 0x10, 0x10, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F,
     0x20, 0x20, 0x00, 0x00},
    {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x20, 0x3F, 0x20, 0x00,
     0x3F, 0x20, 0x00, 0x3F},
    {0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x20, 0x3F, 0x21, 0x00,
     0x00, 0x20, 0x3F, 0x20},
    {0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x1F, 0x20, 0x20,
     0x20, 0x20, 0x1F, 0x00},
    {0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x91, 0x20,
     0x20, 0x11, 0x0E, 0x00},
    {0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x0E, 0x11, 0x20,
     0x20, 0x91, 0xFF, 0x80},
    {0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x20, 0x20, 0x3F, 0x21,
     0x20, 0x00, 0x01, 0x00},
    {0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x33, 0x24, 0x24,
     0x24, 0x24, 0x19, 0x00},
    {0x00, 0x80, 0x80, 0xE0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F,
     0x20, 0x20, 0x10, 0x00},
    {0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x1F, 0x20, 0x20,
     0x20, 0x10, 0x3F, 0x20},
    {0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x03, 0x0C, 0x30,
     0x0C, 0x03, 0x00, 0x00},
    {0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x80, 0x80, 0x01, 0x0E, 0x30, 0x0C,
     0x07, 0x38, 0x06, 0x01},
    {0x00, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x20, 0x31, 0x0E,
     0x2E, 0x31, 0x20, 0x00},
    {0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x81, 0x86, 0x78,
     0x18, 0x06, 0x01, 0x00},
    {0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x21, 0x30, 0x2C,
     0x22, 0x21, 0x30, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00,
     0x01, 0x3E, 0x40, 0x40},
    {0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0xFF, 0x00, 0x00, 0x00},
    {0x02, 0x02, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x3E, 0x01,
     0x00, 0x00, 0x00, 0x00},
    {0x00, 0x02, 0x01, 0x02, 0x02, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00},
};

uint8_t FONTDATA_ASCII_6x16[][12] = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00},
    {0x00, 0x40, 0x30, 0x40, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0xC0, 0x00, 0xC0, 0x00, 0x00, 0x09, 0x3F, 0x09, 0x3F, 0x09, 0x00},
    {0x80, 0x40, 0xE0, 0x40, 0x80, 0x00, 0x11, 0x22, 0x7F, 0x24, 0x18, 0x00},
    {0x80, 0x40, 0x80, 0x00, 0xC0, 0x00, 0x03, 0x34, 0x0F, 0x1D, 0x22, 0x1C},
    {0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x1C, 0x23, 0x2E, 0x11, 0x2E, 0x12},
    {0x40, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x80, 0x60, 0x10, 0x00, 0x00, 0x00, 0x0F, 0x30, 0x40, 0x00},
    {0x00, 0x10, 0x60, 0x80, 0x00, 0x00, 0x00, 0x40, 0x30, 0x0F, 0x00, 0x00},
    {0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x09, 0x06, 0x1F, 0x06, 0x09, 0x00},
    {0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x02, 0x02, 0x0F, 0x02, 0x02},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x30, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0xC0, 0x20, 0x40, 0x30, 0x0C, 0x03, 0x00, 0x00},
    {0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x1F, 0x00},
    {0x00, 0x80, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x00},
    {0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x31, 0x28, 0x24, 0x22, 0x21, 0x00},
    {0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x10, 0x20, 0x22, 0x22, 0x1D, 0x00},
    {0x00, 0x00, 0x80, 0xC0, 0x00, 0x00, 0x0C, 0x0A, 0x29, 0x3F, 0x28, 0x00},
    {0xC0, 0x40, 0x40, 0x40, 0x40, 0x00, 0x17, 0x22, 0x22, 0x22, 0x1C, 0x00},
    {0x00, 0x80, 0x40, 0x40, 0x80, 0x00, 0x1F, 0x24, 0x22, 0x22, 0x1C, 0x00},
    {0x00, 0x40, 0x40, 0x40, 0xC0, 0x00, 0x00, 0x00, 0x3C, 0x03, 0x00, 0x00},
    {0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x1D, 0x22, 0x22, 0x22, 0x1D, 0x00},
    {0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x13, 0x24, 0x24, 0x12, 0x0F, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x06, 0x09, 0x10, 0x20, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05},
    {0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x20, 0x10, 0x09, 0x06, 0x00},
    {0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x01, 0x00, 0x2C, 0x02, 0x01, 0x00},
    {0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x0F, 0x10, 0x2E, 0x2F, 0x28, 0x17},
    {0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x20, 0x3E, 0x09, 0x0F, 0x38, 0x20},
    {0x40, 0xC0, 0x40, 0x40, 0x80, 0x00, 0x20, 0x3F, 0x22, 0x22, 0x1D, 0x00},
    {0x80, 0x40, 0x40, 0x40, 0xC0, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x10, 0x00},
    {0x40, 0xC0, 0x40, 0x40, 0x80, 0x00, 0x20, 0x3F, 0x20, 0x20, 0x1F, 0x00},
    {0x40, 0xC0, 0x40, 0x40, 0xC0, 0x00, 0x20, 0x3F, 0x22, 0x27, 0x30, 0x00},
    {0x40, 0xC0, 0x40, 0x40, 0xC0, 0x00, 0x20, 0x3F, 0x22, 0x07, 0x00, 0x00},
    {0x00, 0x80, 0x40, 0x40, 0xC0, 0x00, 0x0F, 0x10, 0x20, 0x24, 0x1C, 0x04},
    {0x40, 0xC0, 0x00, 0x00, 0xC0, 0x40, 0x20, 0x3F, 0x02, 0x02, 0x3F, 0x20},
    {0x40, 0x40, 0xC0, 0x40, 0x40, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00},
    {0x00, 0x40, 0x40, 0xC0, 0x40, 0x40, 0xC0, 0x80, 0x80, 0x7F, 0x00, 0x00},
    {0x40, 0xC0, 0x40, 0x00, 0xC0, 0x40, 0x20, 0x3F, 0x22, 0x05, 0x38, 0x20},
    {0x40, 0xC0, 0x40, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x20, 0x20, 0x30},
    {0xC0, 0xC0, 0x00, 0xC0, 0xC0, 0x40, 0x3F, 0x03, 0x3C, 0x03, 0x3F, 0x20},
    {0x40, 0xC0, 0x00, 0x40, 0xC0, 0x40, 0x20, 0x3F, 0x23, 0x0C, 0x3F, 0x00},
    {0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x1F, 0x20, 0x20, 0x20, 0x1F, 0x00},
    {0x40, 0xC0, 0x40, 0x40, 0x80, 0x00, 0x20, 0x3F, 0x22, 0x02, 0x01, 0x00},
    {0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x1F, 0x28, 0x28, 0x70, 0x5F, 0x00},
    {0x40, 0xC0, 0x40, 0x40, 0x80, 0x00, 0x20, 0x3F, 0x22, 0x06, 0x39, 0x20},
    {0x80, 0x40, 0x40, 0x40, 0xC0, 0x00, 0x31, 0x22, 0x22, 0x24, 0x18, 0x00},
    {0xC0, 0x40, 0xC0, 0x40, 0xC0, 0x00, 0x00, 0x20, 0x3F, 0x20, 0x00, 0x00},
    {0x40, 0xC0, 0x00, 0x00, 0xC0, 0x40, 0x00, 0x1F, 0x20, 0x20, 0x1F, 0x00},
    {0x40, 0xC0, 0x00, 0x00, 0xC0, 0x40, 0x00, 0x07, 0x38, 0x0E, 0x01, 0x00},
    {0xC0, 0x00, 0xC0, 0x00, 0xC0, 0x00, 0x03, 0x3C, 0x07, 0x3C, 0x03, 0x00},
    {0x40, 0xC0, 0x00, 0xC0, 0x40, 0x00, 0x20, 0x39, 0x06, 0x39, 0x20, 0x00},
    {0x40, 0xC0, 0x00, 0xC0, 0x40, 0x00, 0x00, 0x23, 0x3C, 0x23, 0x00, 0x00},
    {0xC0, 0x40, 0x40, 0xC0, 0x40, 0x00, 0x20, 0x38, 0x26, 0x21, 0x30, 0x00},
    {0x00, 0x00, 0xF0, 0x10, 0x10, 0x00, 0x00, 0x00, 0x7F, 0x40, 0x40, 0x00},
    {0x00, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1C, 0x60, 0x00},
    {0x00, 0x10, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x40, 0x40, 0x7F, 0x00, 0x00},
    {0x00, 0x20, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80},
    {0x00, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x2A, 0x2A, 0x3C, 0x20},
    {0x20, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x22, 0x22, 0x1C, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x22, 0x22, 0x16, 0x00},
    {0x00, 0x00, 0x00, 0x20, 0xE0, 0x00, 0x00, 0x1C, 0x22, 0x22, 0x3F, 0x20},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x2A, 0x2A, 0x2C, 0x00},
    {0x00, 0x00, 0xC0, 0x20, 0x20, 0x40, 0x00, 0x22, 0x3F, 0x22, 0x22, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x54, 0xAA, 0xAA, 0xA6, 0x42},
    {0x20, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x22, 0x02, 0x3C, 0x20},
    {0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x22, 0x3E, 0x20, 0x00, 0x00},
    {0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x80, 0x80, 0x82, 0x7E, 0x00, 0x00},
    {0x20, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3F, 0x08, 0x16, 0x22, 0x00},
    {0x20, 0x20, 0xE0, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x02, 0x3E, 0x02, 0x3C, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x3E, 0x22, 0x02, 0x3C, 0x20},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x22, 0x22, 0x1C, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0xFE, 0xA2, 0x22, 0x1C, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x22, 0xA2, 0xFE, 0x80},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x3E, 0x24, 0x02, 0x02, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x2A, 0x2A, 0x32, 0x00},
    {0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x02, 0x3F, 0x22, 0x22, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x1E, 0x20, 0x22, 0x3E, 0x20},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0E, 0x30, 0x0E, 0x02, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x38, 0x0E, 0x38, 0x06, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x36, 0x08, 0x36, 0x22, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x8E, 0x50, 0x30, 0x0E, 0x02},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x3A, 0x26, 0x22, 0x00},
    {0x00, 0x00, 0x00, 0xF0, 0x10, 0x00, 0x00, 0x00, 0x02, 0x7F, 0x40, 0x00},
    {0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00},
    {0x00, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x40, 0x7D, 0x02, 0x00, 0x00},
    {0x20, 0x10, 0x10, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
};

#endif
