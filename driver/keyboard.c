#include "keyboard.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "interface.h"

uint8_t keys[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
void fi_Keyboard_scan(void) {
    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t i = 0; i < 4; i++) {
            if (i == row) {
                fi_inter_Keyboard_setRow(i, false);
            } else {
                fi_inter_Keyboard_setRow(i, true);
            }
        }
        for (uint8_t i = 0; i < 4; i++) {
            bool pressed = fi_inter_Keyboard_getCol(i);
            if (pressed && keys[row * 4 + i] < 255) {
                keys[row * 4 + i] += 1;
            }
            if (!pressed && keys[row * 4 + i] > 0) {
                keys[row * 4 + i] -= 1;
            }
        }
    }
}

uint16_t fi_Keyboard_getMap(void) {
    uint16_t keymap = 0;
    for (uint8_t i = 0; i < 16; i++) {
        keymap <<= 1;
        keymap |= keys[15 - i] < 128 ? 0 : 1;
    }
    return keymap;
}
