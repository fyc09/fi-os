#include "interface.h"
#include "wiringPi.h"

#define OLED_DC 2
#define OLED_RST 3
#define OLED_MOSI 12
#define OLED_SCLK 14
#define OLED_CS 10

#define SD_CS 8
#define SD_MOSI 7
#define SD_MISO 0
#define SD_SCLK 9

uint8_t KeyBoard_Rn[] = {22, 23, 24, 25};
uint8_t KeyBoard_Cn[] = {21, 29, 28, 27};

uint8_t fi_inter_System_init(void) {
    uint8_t code = wiringPiSetup();
    if (code != 0) {
        return code;
    }

    pinMode(OLED_DC, OUTPUT);
    pinMode(OLED_RST, OUTPUT);
    pinMode(OLED_MOSI, OUTPUT);
    pinMode(OLED_SCLK, OUTPUT);
    pinMode(OLED_CS, OUTPUT);
    pinMode(SD_CS, OUTPUT);
    pinMode(SD_MOSI, OUTPUT);
    pinMode(SD_SCLK, OUTPUT);

    pinMode(SD_MISO, INPUT);

    for (uint8_t i = 0; i < 4; i++) {
        pinMode(KeyBoard_Rn[i], OUTPUT);
        pinMode(KeyBoard_Cn[i], INPUT);
        pullUpDnControl(KeyBoard_Cn[i], PUD_UP);
    }

    pullUpDnControl(SD_MISO, PUD_UP);

    digitalWrite(OLED_CS, HIGH);
    digitalWrite(SD_CS, HIGH);

    // SD Card Init.
    for (uint8_t i = 0; i < 100; i++) {
        digitalWrite(SD_SCLK, LOW);
        digitalWrite(SD_SCLK, HIGH);
    }

    return 0;
}

void fi_inter_OLED_write(uint8_t data) {
    digitalWrite(OLED_CS, LOW);
    for (int i = 0; i < 8; i++) {
        digitalWrite(OLED_SCLK, LOW);
        if (data & 0x80) {
            digitalWrite(OLED_MOSI, HIGH);
        } else {
            digitalWrite(OLED_MOSI, LOW);
        }
        digitalWrite(OLED_SCLK, HIGH);
        data <<= 1;
    }
    digitalWrite(OLED_CS, HIGH);
}

void fi_inter_OLED_set_DC(bool dc) {
    if (dc) {
        digitalWrite(OLED_DC, HIGH);
    } else {
        digitalWrite(OLED_DC, LOW);
    }
}

void fi_inter_OLED_reset(void) {
    digitalWrite(OLED_RST, HIGH);
    delay(100);
    digitalWrite(OLED_RST, LOW);
    delay(100);
    digitalWrite(OLED_RST, HIGH);
}

void fi_inter_OLED_cleanup(void) {
    fi_inter_OLED_reset();
}

void fi_inter_SD_write(uint8_t data) {
    digitalWrite(SD_CS, LOW);
    for (int i = 0; i < 8; i++) {
        digitalWrite(SD_SCLK, LOW);
        if (data & 0x80) {
            digitalWrite(SD_MOSI, HIGH);
        } else {
            digitalWrite(SD_MOSI, LOW);
        }
        digitalWrite(SD_SCLK, HIGH);
        data <<= 1;
    }
    digitalWrite(SD_CS, HIGH);
}

uint8_t fi_inter_SD_read(void) {
    uint8_t data = 0;
    digitalWrite(SD_CS, LOW);
    for (int i = 0; i < 8; i++) {
        digitalWrite(SD_SCLK, LOW);
        digitalWrite(SD_MOSI, HIGH);
        data <<= 1;
        if (digitalRead(SD_MISO)) {
            data |= 0x01;
        }
        digitalWrite(SD_SCLK, HIGH);
    }
    digitalWrite(SD_CS, HIGH);

    return data;
}

void fi_inter_SD_cleanup(void) {}

void fi_inter_SD_sendDummy(void) {
    digitalWrite(SD_MOSI, HIGH);
    for (int i = 0; i < 8; i++) {
        digitalWrite(SD_SCLK, LOW);
        digitalWrite(SD_SCLK, HIGH);
    }
}

void fi_inter_Keyboard_setRow(uint8_t row, bool state) {
    if (state) {
        digitalWrite(KeyBoard_Rn[row], HIGH);
    } else {
        digitalWrite(KeyBoard_Rn[row], LOW);
    }
}

bool fi_inter_Keyboard_getCol(uint8_t col) {
    return (bool *)!digitalRead(KeyBoard_Cn[col]);
}
