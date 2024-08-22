#include "font.h"
#include "oled.h"
#include "sd.h"
#include "system.h"
#include <stdint.h>

uint64_t utf8_2_unicode(const char **str) {
    uint64_t codepoint = 0;
    int shift = 0;
    int length = 0;
    unsigned char c;

    // Check first byte
    c = (unsigned char)**str;
    if ((c & 0x80) == 0) { // 1-byte sequence
        codepoint = c;
        length = 1;
    } else if ((c & 0xE0) == 0xC0) { // 2-byte sequence
        codepoint = c & 0x1F;
        length = 2;
    } else if ((c & 0xF0) == 0xE0) { // 3-byte sequence
        codepoint = c & 0x0F;
        length = 3;
    } else if ((c & 0xF8) == 0xF0) { // 4-byte sequence
        codepoint = c & 0x07;
        length = 4;
    } else { // Invalid
        return 0;
    }

    // Parse remaining bytes
    while (--length > 0) {
        (*str)++;
        c = (unsigned char)**str;
        if ((c & 0xC0) != 0x80) { // Invalid
            return 0;
        }
        codepoint = (codepoint << 6) | (c & 0x3F);
    }

    // Update pointer to point to the next character.
    (*str) += 1;

    return codepoint;
}

GETTER(guanzhi) {
    uint8_t status;
    uint8_t record[11];
    uint32_t max_chr;

    if ((status = fi_file_open("gzcnfont"))) {
        return status;
    }
    while (1) {
        if ((status = fi_SD_Reader_read(8, record))) {
            return status;
        }

        max_chr = record[0] | record[1] << 8 | record[2] << 16;
        if (max_chr == 0) {
            return 1;
        }
        if (unicode <= max_chr) {
            break;
        }
    }
    if ((status = fi_SD_Reader_jump(record + 3))) {
        return status;
    }
    while (1) {
        if ((status = fi_SD_Reader_read(11, record))) {
            return status;
        }
        uint32_t match_chr = record[0] | record[1] << 8 | record[2] << 16;
        if (match_chr > max_chr) {
            break;
        }
        if (match_chr == unicode) {
            for (int i = 0; i < 8; i++) {
                matrix[i] = record[i + 3];
            }
            break;
        }
    }
    if ((status = fi_SD_Reader_close())) {
        return status;
    }
    return status;
}

GETTER(simsun) {
    uint8_t status;
    uint8_t record[35];
    uint32_t max_chr;

    if ((status = fi_file_open("suncnfont"))) {
        return status;
    }
    while (1) {
        if ((status = fi_SD_Reader_read(8, record))) {
            return status;
        }

        max_chr = record[0] | record[1] << 8 | record[2] << 16;
        if (max_chr == 0) {
            return 1;
        }
        if (unicode <= max_chr) {
            break;
        }
    }
    if ((status = fi_SD_Reader_jump(record + 3))) {
        return status;
    }
    while (1) {
        if ((status = fi_SD_Reader_read(35, record))) {
            return status;
        }
        uint32_t match_chr = record[0] | record[1] << 8 | record[2] << 16;
        if (match_chr > max_chr) {
            status = 2;
            break;
        }
        if (match_chr == unicode) {
            for (int i = 0; i < 32; i++) {
                matrix[i] = record[i + 3];
            }
            break;
        }
    }
    if ((status |= fi_SD_Reader_close())) {
        return status;
    }
    return status;
}

uint8_t fi_font_write(const char *str, uint8_t x, uint8_t y, fi_font_t font, bool reversed) {
    uint8_t status;
    uint64_t unicode = 1;
    uint8_t matrix[32];

    while (1) {
        unicode = utf8_2_unicode(&str);
        if (!unicode) {
            break;
        }
        if ((status = font.getter(unicode, matrix))) {
            return status;
        }
        if (reversed) {
            for (int i = 0; i < (font.height * font.width / 8); i++) {
                matrix[i] = ~matrix[i];
            }
        }
        fi_OLED_drawPic(x, y, font.width, font.height, matrix);
        x += font.width;
        if ((x + font.width) > OLED_WIDTH) {
            x = 0;
            y += font.height;
        }
    }

    return 0;
}
