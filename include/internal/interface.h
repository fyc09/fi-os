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

uint8_t fiInterface_System_init(void);

/**
 *  ==================
 * || OLED Interface ||
 *  ==================
 */

void fiInterface_OLED_write(uint8_t data);

void fiInterface_OLED_set_DC(bool dc);

void fiInterface_OLED_reset(void);

void fiInterface_OLED_cleanup(void);

/**
 *  =====================
 * || SD card Interface ||
 *  =====================
 */

void fiInterface_SD_write(uint8_t data);

uint8_t fiInterface_SD_read(void);

void fiInterface_SD_cleanup(void);

void fiInterface_SD_sendDummy(void);

/**
 *  ======================
 * || Keyboard Interface ||
 *  ======================
 */

void fiInterface_Keyboard_setRow(uint8_t row, bool state);

bool fiInterface_Keyboard_getCol(uint8_t col);

#endif
