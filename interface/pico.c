#include "interface.h"
#include "pico/stdlib.h"

#define NOP() asm volatile("nop")
// #define NOP() sleep_us(1);

#define OLED_DC 6
#define OLED_RST 4
#define OLED_MOSI 3
#define OLED_SCLK 2
#define OLED_CS 5

#define SD_CS 9
#define SD_MOSI 11
#define SD_MISO 12
#define SD_SCLK 10

uint8_t KeyBoard_Rn[] = {22, 26, 27, 28};
uint8_t KeyBoard_Cn[] = {21, 20, 19, 18};

uint8_t fi_inter_System_init(void) {
    stdio_init_all();

    gpio_init(OLED_DC);
    gpio_set_dir(OLED_DC, GPIO_OUT);
    gpio_init(OLED_RST);
    gpio_set_dir(OLED_RST, GPIO_OUT);
    gpio_init(OLED_MOSI);
    gpio_set_dir(OLED_MOSI, GPIO_OUT);
    gpio_init(OLED_SCLK);
    gpio_set_dir(OLED_SCLK, GPIO_OUT);
    gpio_init(OLED_CS);
    gpio_set_dir(OLED_CS, GPIO_OUT);
    gpio_init(SD_CS);
    gpio_set_dir(SD_CS, GPIO_OUT);
    gpio_init(SD_MOSI);
    gpio_set_dir(SD_MOSI, GPIO_OUT);
    gpio_init(SD_SCLK);
    gpio_set_dir(SD_SCLK, GPIO_OUT);

    gpio_init(SD_MISO);
    gpio_set_dir(SD_MISO, GPIO_IN);
    gpio_pull_up(SD_MISO);

    for (uint8_t i = 0; i < 4; i++) {
        gpio_init(KeyBoard_Rn[i]);
        gpio_set_dir(KeyBoard_Rn[i], GPIO_OUT);
        gpio_init(KeyBoard_Cn[i]);
        gpio_set_dir(KeyBoard_Cn[i], GPIO_IN);
        gpio_pull_up(KeyBoard_Cn[i]);
    }

    gpio_put(OLED_CS, true);
    gpio_put(SD_CS, true);

    // SD Card Init.
    for (uint8_t i = 0; i < 100; i++) {
        gpio_put(SD_SCLK, true);
        gpio_put(SD_SCLK, true);
    }

    return 0;
}

void fi_inter_OLED_write(uint8_t data) {
    gpio_put(OLED_CS, false);
    for (int i = 0; i < 8; i++) {
        gpio_put(OLED_SCLK, false);
        if (data & 0x80) {
            gpio_put(OLED_MOSI, true);
        } else {
            gpio_put(OLED_MOSI, false);
        }
        NOP();
        gpio_put(OLED_SCLK, true);
        data <<= 1;
    }
    gpio_put(OLED_CS, true);
}

void fi_inter_OLED_set_DC(bool dc) {
    if (dc) {
        gpio_put(OLED_DC, true);
    } else {
        gpio_put(OLED_DC, false);
    }
}

void fi_inter_OLED_reset(void) {
    gpio_put(OLED_RST, true);
    sleep_ms(100);
    gpio_put(OLED_RST, false);
    sleep_ms(100);
    gpio_put(OLED_RST, true);
}

void fi_inter_OLED_cleanup(void) {
    fi_inter_OLED_reset();
}

void fi_inter_SD_write(uint8_t data) {
    gpio_put(SD_CS, false);
    NOP();
    for (int i = 0; i < 8; i++) {
        gpio_put(SD_SCLK, false);
        NOP();
        if (data & 0x80) {
            gpio_put(SD_MOSI, true);
        } else {
            gpio_put(SD_MOSI, false);
        }
        NOP();
        gpio_put(SD_SCLK, true);
        data <<= 1;
    }
    gpio_put(SD_CS, true);
}

uint8_t fi_inter_SD_read(void) {
    uint8_t data = 0;

    gpio_put(SD_CS, false);
    gpio_put(SD_MOSI, true);
    for (int i = 0; i < 8; i++) {
        gpio_put(SD_SCLK, false);
        data <<= 1;
        NOP();
        NOP();
        if (gpio_get(SD_MISO)) {
            data |= 0x01;
        }
        NOP();
        gpio_put(SD_SCLK, true);
        NOP();
    }
    gpio_put(SD_CS, true);

    return data;
}

void fi_inter_SD_cleanup(void) {}

void fi_inter_SD_sendDummy(void) {
    gpio_put(SD_MOSI, true);
    for (int i = 0; i < 8; i++) {
        gpio_put(SD_SCLK, false);
        NOP();
        gpio_put(SD_SCLK, true);
        NOP();
    }
}

void fi_inter_Keyboard_setRow(uint8_t row, bool state) {
    if (state) {
        gpio_put(KeyBoard_Rn[row], true);
    } else {
        gpio_put(KeyBoard_Rn[row], false);
    }
}

bool fi_inter_Keyboard_getCol(uint8_t col) {
    return !gpio_get(KeyBoard_Cn[col]);
}
