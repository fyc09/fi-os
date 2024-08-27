#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "font.h"
#include "keyboard.h"
#include "oled.h"
#include "pico/stdlib.h"

uint8_t home_main() {
    const char* items[] = {"Game",
                           "Settings",
                           "Info",
                           "Help",
                           "Some very very very very very long item",
                           "Exit"};
    uint8_t num = 6;
    int8_t current = 0;
    int8_t position = 0;
    uint8_t scroll = 0;
    bool up = false;
    bool down = false;
    bool changed;

    goto render;

    while (1) {
        sleep_us(10);
        uint16_t map = fi_Keyboard_getMap();
        changed = false;

        if (map & KEY_DOWN) {
            if (!down) {
                down = true;
                current++;
                if (current >= num) {
                    current -= num;
                }
                changed = true;
            }
        } else {
            down = false;
        }

        if (map & KEY_UP) {
            if (!up) {
                up = true;
                current--;
                if (current < 0) {
                    current += num;
                }
                changed = true;
            }
        } else {
            up = false;
        }

        if (!changed) {
            continue;
        }

    render:
        if (current > position + 3) {
            position = current - 3;
        }
        if (current < position) {
            position = current;
        }

        fi_OLED_clear();
        char text[24];
        for (uint8_t i = 0; i < 4; i++) {
            strncpy(text, items[position + i], 16);
            if (current == position + i) {
                fi_font_write(text, 0, i * 16, FI_FONT_ASCII8x16, REVERSED);
            } else {
                fi_font_write(text, 0, i * 16, FI_FONT_ASCII8x16, NORMAL);
            }
        }
    }
}
