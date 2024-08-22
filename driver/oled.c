#include "oled.h"
#include "interface.h"
#include <stdbool.h>
#include <stdint.h>

void write(uint8_t data, bool dc) {
    fi_inter_OLED_set_DC(dc);
    fi_inter_OLED_write(data);
    fi_inter_OLED_set_DC(true);
}

void setPositon(uint8_t x, uint8_t y) {
    write((y & 0x0f) | 0xb0, CMD);
    write(((x & 0xf0) >> 4) | 0x10, CMD);
    write((x & 0x0f) | 0x01, CMD);
}

void fi_OLED_init() {
    fi_inter_OLED_reset();

    write(0xae, CMD);
    write(0x00, CMD);
    write(0x10, CMD);
    write(0x40, CMD);
    write(0x81, CMD);
    write(0xff, CMD);
    write(0xa1, CMD);
    write(0xc8, CMD);
    write(0xa6, CMD);
    write(0xa8, CMD);
    write(0x3f, CMD);
    write(0xd3, CMD);
    write(0x00, CMD);
    write(0xd5, CMD);
    write(0x80, CMD);
    write(0xd9, CMD);
    write(0xf1, CMD);
    write(0xda, CMD);
    write(0x12, CMD);
    write(0xdb, CMD);
    write(0x40, CMD);
    write(0x20, CMD);
    write(0x02, CMD);
    write(0x8d, CMD);
    write(0x14, CMD);
    write(0xa4, CMD);
    write(0xa6, CMD);
    write(0xaf, CMD);
    write(0xaf, CMD);
}

void fi_OLED_setDisplay(bool on) {
    write(0X8D, CMD); // SET DCDC
    if (on) {
        write(0X14, CMD); // DCDC ON
        write(0xaf, CMD); // DISPLAY ON
    } else {
        write(0X10, CMD); // DCDC OFF
        write(0xae, CMD); // DISPLAY OFF
    }
}

void showChar(uint8_t x, uint8_t y, uint8_t *bitmap, fi_OLED_size_t size, bool reversed) {
    y /= 8;
    for (uint8_t offset_y = 0; offset_y < size.height; offset_y += 8) {
        setPositon(x, y + offset_y);
        for (uint8_t offset_x = 0; offset_x < size.width; offset_x++) {
            if (reversed) {
                write(~*bitmap, DATA);
            } else {
                write(*bitmap, DATA);
            }
            bitmap++;
        }
    }

    // if (size != HANZI) {
    //     chr -= ' ';
    // }

    // if (mode == NORMAL) {
    //     if (size == BIG) {
    //         setPositon(x, y);
    //         for (uint8_t i = 0; i < 8; i++) {
    //             write(F8X16[chr][i], DATA);
    //         }
    //         setPositon(x, y + 1);
    //         for (uint8_t i = 0; i < 8; i++) {
    //             write(F8X16[chr][i + 8], DATA);
    //         }
    //     } else {
    //         setPositon(x, y);
    //         for (uint8_t i = 0; i < 6; i++) {
    //             write(F6X16[chr][i], DATA);
    //         }
    //         setPositon(x, y + 1);
    //         for (uint8_t i = 0; i < 6; i++) {
    //             write(F6X16[chr][i + 6], DATA);
    //         }
    //     }
    // } else {
    //     if (size == BIG) {
    //         setPositon(x, y);
    //         for (uint8_t i = 0; i < 8; i++) {
    //             write(~F8X16[chr][i], DATA);
    //         }
    //         setPositon(x, y + 1);
    //         for (uint8_t i = 0; i < 8; i++) {
    //             write(~F8X16[chr][i + 8], DATA);
    //         }
    //     } else {
    //         setPositon(x, y);
    //         for (uint8_t i = 0; i < 6; i++) {
    //             write(~F6X16[chr][i] & 0xf0, DATA);
    //         }
    //         setPositon(x, y + 1);
    //         for (uint8_t i = 0; i < 6; i++) {
    //             write(~F6X16[chr][i + 6], DATA);
    //         }
    //     }
    // }
}

// void showChar(uint8_t x, uint8_t y, uint8_t *bitmap, fi_OLED_size_t size, bool reversed) {
// void fi_OLED_showStr(uint8_t x, uint8_t y, char *chr, uint8_t size, bool mode) {
//     while (*chr != '\0') {
//         showChar(x, y, *chr, size, mode);
//         x += size;
//         if (x > (X_WIDTH - size)) {
//             x = 0;
//             y += 2;
//         }
//         chr++;
//     }
// }

void fi_OLED_drawPic(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t *pic) {
    y /= 8;
    height /= 8;

    for (uint8_t i = 0; i < height; i++) {
        setPositon(x, y + i);
        for (uint8_t j = 0; j < width; j++) {
            write(*pic, DATA);
            pic++;
        }
    }
}

void fi_OLED_clear(void) {
    for (uint8_t i = 0; i < 8; i++) {
        write(0xb0 + i, CMD);
        write(0x00, CMD);
        write(0x10, CMD);
        for (uint8_t j = 0; j < 128; j++) {
            write(0x00, DATA);
        }
    }
}
