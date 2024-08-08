#include <stdbool.h>
#include <stdint.h>

#ifndef FI_DRIVER_OLED_H
#define FI_DRIVER_OLED_H

#define CMD false
#define DATA true

#define ON true
#define OFF false

#define HANZI 16
#define BIG 8
#define SMALL 6

#define NORMAL false
#define REVERSED true

/**
 * Initialize OLED.
 */
void fiDriver_OLED_init(void);

/**
 * Set display on or off.
 * \param on True to turn on, false to turn off.
 */
void fiDriver_OLED_setDisplay(bool on);

/**
 * Show string on OLED.
 * \param x X coordinate, in pixels.
 * \param y Y coordinate, in pixels, must be multiple of 8.
 * \param chr String to show.
 * \param size Font size. Accepts BIG or SMALL.
 * \param mode Normal or reversed mode. Accepts NORMAL or REVERSED.
 */
void fiDriver_OLED_showStr(uint8_t x, uint8_t y, char *chr, uint8_t size, bool mode);

/**
 * Draw picture on OLED.
 * \param x X coordinate, in pixels.
 * \param y Y coordinate, in pixels, must be multiple of 8.
 * \param width Picture width, in pixels.
 * \param height Picture height, in pixels, must be multiple of 8.
 * \param pic Picture to draw.
 */
void fiDriver_OLED_drawPic(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t *pic);

/**
 * Clear OLED display.
 */
void fiDriver_OLED_clear(void);

#endif
