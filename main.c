#include <stdio.h>
#include "font.h"
#include "interface.h"
#include "keyboard.h"
#include "oled.h"
#include "pico/stdlib.h"
#include "sd.h"
#include "system.h"

int main() {
    uint8_t code;

    if ((code = fi_system_init())) {
        for (;;) {
            printf("%d ", code);
            sleep_ms(1000);
        }

        return code;
    }

    getchar();

    fi_OLED_init();
    fi_OLED_setDisplay(ON);
    fi_OLED_clear();

    fi_font_write("Hello, world!", 0, 0, FI_FONT_ASCII6x16, NORMAL);

    printf("Hello, world!");

    for (;;)
        ;

    return 0;
}