#include <stdint.h>

#ifndef FI_SYSTEM_H
#define FI_SYSTEM_H

typedef struct {
    uint8_t (*getter)(uint64_t unicode, uint8_t* matrix);
    uint8_t width;
    uint8_t height;
} fi_matrix_t;

/**
 * Cleanup system resources.
 */
void fi_system_cleanup(void);

/**
 * Initialize system.
 * \return 0 if successful, otherwise non-zero.
 */
uint8_t fi_system_init(void);

/**
 * Set SD driver to the file. SD driver status must be STATUS_READY.
 */
uint8_t fi_file_open(const char* filename);

#endif
