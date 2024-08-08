#include "keyboard.h"
#include "interface.h"
#include <stdbool.h>
#include <stdint.h>

uint16_t keymap = 0;
void fiDriver_Keyboard_scan(void) {
    keymap = 0;
    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t i = 0; i < 4; i++) {
            if (i == row) {
                fiInterface_Keyboard_setRow(i, false);
            } else {
                fiInterface_Keyboard_setRow(i, true);
            }
        }
        for (uint8_t i = 0; i < 4; i++) {
            keymap |= (uint16_t)fiInterface_Keyboard_getCol(i) << (4 * row) << i;
        }
    }
}

uint16_t fiDriver_Keyboard_getMap(void) {
    return keymap;
}
