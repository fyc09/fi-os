#include <stdbool.h>
#include <stdint.h>

#ifndef FI_DRIVER_KEYBOARD_H
#define FI_DRIVER_KEYBOARD_H

#define KEY01 0x0001
#define KEY02 0x0002
#define KEY03 0x0004
#define KEY04 0x0008
#define KEY05 0x0010
#define KEY06 0x0020
#define KEY07 0x0040
#define KEY08 0x0080
#define KEY09 0x0100
#define KEY10 0x0200
#define KEY11 0x0400
#define KEY12 0x0800
#define KEY13 0x1000
#define KEY14 0x2000
#define KEY15 0x4000
#define KEY16 0x8000

#define KEY_UP KEY02
#define KEY_RIGHT KEY07
#define KEY_DOWN KEY10
#define KEY_LEFT KEY05

#define KEY_OK KEY06
#define KEY_BACK KEY01
#define KEY_MENU KEY03

#define KEY_A KEY08
#define KEY_B KEY12
#define KEY_C KEY16

#define KEY_F1 KEY09
#define KEY_F2 KEY11
#define KEY_F3 KEY13
#define KEY_F4 KEY14
#define KEY_F5 KEY15

/**
 * Scan the keyboard and update the data. The real data should be gotten by @see
 * fi_inter_Keyboard_getMap later.
 */
void fi_Keyboard_scan(void);

/**
 * Get the keys' status.
 * \return The keys in bit map format.
 */
uint16_t fi_Keyboard_getMap(void);

#endif
