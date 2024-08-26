#include <stdbool.h>
#include <stdint.h>
#include "system.h"

#ifndef _FONT_H
#define _FONT_H

#define GET_GETTER(name) _fi_font_##name##_getter
#define GETTER(name) \
    uint8_t GET_GETTER(name)(uint64_t unicode, uint8_t * matrix)
#define DEFINE(name, width, height)     \
    (fi_matrix_t) {                     \
        GET_GETTER(name), width, height \
    }

#define FI_FONT_GUANZHI DEFINE(guanzhi, 8, 8)
#define FI_FONT_SIMSUN DEFINE(simsun, 16, 16)
#define FI_FONT_ASCII8x16 DEFINE(ascii8x16, 8, 16)
#define FI_FONT_ASCII6x16 DEFINE(ascii6x16, 6, 16)

GETTER(guanzhi);
GETTER(simsun);
GETTER(ascii8x16);
GETTER(ascii6x16);

uint8_t fi_font_write(const char* str,
                      uint8_t x,
                      uint8_t y,
                      fi_matrix_t font,
                      bool reversed);

#endif