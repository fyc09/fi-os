#include <stdint.h>

#ifndef FI_SYSTEM_H
#define FI_SYSTEM_H

/**
 * Cleanup system resources.
 */
void fiSystem_cleanup(void);

/**
 * Initialize system.
 * \return 0 if successful, otherwise non-zero.
 */
uint8_t fiSystem_init(void);

#endif
