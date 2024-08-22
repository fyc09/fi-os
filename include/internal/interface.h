#include <stdbool.h>
#include <stdint.h>

#ifndef FI_Interface_H
#define FI_Interface_H

#define KEYDWON true
#define KEYUP false

/**
 *  ====================
 * || System Interface ||
 *  ====================
 */

uint8_t fi_inter_System_init(void);

/**
 *  ==================
 * || OLED Interface ||
 *  ==================
 */

void fi_inter_OLED_write(uint8_t data);

void fi_inter_OLED_set_DC(bool dc);

void fi_inter_OLED_reset(void);

void fi_inter_OLED_cleanup(void);

/**
 *  =====================
 * || SD card Interface ||
 *  =====================
 */

void fi_inter_SD_write(uint8_t data);

uint8_t fi_inter_SD_read(void);

void fi_inter_SD_cleanup(void);

void fi_inter_SD_sendDummy(void);

/**
 *  ======================
 * || Keyboard Interface ||
 *  ======================
 */

void fi_inter_Keyboard_setRow(uint8_t row, bool state);

bool fi_inter_Keyboard_getCol(uint8_t col);

#endif
