#include <stdint.h>

#ifndef FI_SYSTEM_H
#define FI_SYSTEM_H

typedef struct {
    uint8_t (*getter)(uint64_t unicode, uint8_t *matrix);
    uint8_t width;
    uint8_t height;
} fi_font_t;

#define GET_GETTER(name) _fi_font_##name##_getter
#define GETTER(name) uint8_t GET_GETTER(name)(uint64_t unicode, uint8_t * matrix)
#define DEFINE(name, width, height)                                                                \
    (fi_font_t) {                                                                                  \
        GET_GETTER(name), width, height                                                            \
    }

#define FI_FONT_GUANZHI DEFINE(guanzhi, 8, 8)
#define FI_FONT_SIMSUN DEFINE(simsun, 16, 16)

GETTER(guanzhi);
GETTER(simsun);

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
uint8_t fi_file_open(const char *filename);

// uint8_t fi_font_write(const char *str);
uint8_t fi_font_write(const char *str, uint8_t x, uint8_t y, fi_font_t font, bool reversed);

#endif
