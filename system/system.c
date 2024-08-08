#include "system.h"
#include "oled.h"
#include "sd.h"
#include "interface.h"
#include "stdio.h"

uint8_t fiSystem_init(void) {
    uint8_t code;

    if ((code = fiInterface_System_init())) {
        return code;
    }

    fiDriver_OLED_init();

    fiDriver_OLED_clear();

    if ((code = fiDriver_SD_init())) {
        return code;
    }

    return 0;
}

void fiSystem_cleanup(void) {
    fiInterface_OLED_cleanup();
}
