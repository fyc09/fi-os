#include "interface.h"
#include "oled.h"
#include "sd.h"
#include "stdio.h"
#include "system.h"

uint8_t fi_system_init(void) {
    uint8_t code;

    if ((code = fi_inter_System_init())) {
        return code;
    }

    fi_OLED_init();

    fi_OLED_clear();

    if ((code = fi_SD_init())) {
        return code;
    }

    return 0;
}

void fi_system_cleanup(void) {
    fi_inter_OLED_cleanup();
}
