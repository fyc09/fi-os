#include <stdbool.h>
#include <stdint.h>

#ifndef FI_DRIVER_KEYBOARD_H
#define FI_DRIVER_KEYBOARD_H

/**
 * Scan the keyboard and update the data. The real data should be gotten by @see fiInterface_Keyboard_getMap later.
 */
void fiDriver_Keyboard_scan(void);

/**
 * Get the keys' status.
 * \return The keys in bit map format.
 */
uint16_t fiDriver_Keyboard_getMap(void);

#endif
