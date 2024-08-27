#include <stdio.h>
#include "font.h"
#include "home.h"
#include "interface.h"
#include "keyboard.h"
#include "oled.h"
#include "pico/stdlib.h"
#include "sd.h"
#include "system.h"

bool scanCallback(repeating_timer_t* timer) {
    timer->alarm_id = 0;
    fi_Keyboard_scan();
    return true;
}

int main() {
    uint8_t code;

    if ((code = fi_system_init())) {
        for (;;) {
            printf("%d ", code);
            sleep_ms(1000);
        }

        return code;
    }

    repeating_timer_t timer;

    add_repeating_timer_us(10, scanCallback, NULL, &timer);

    // for (;;) {
    //     printf("%04x ", fi_Keyboard_getMap());
    //     sleep_us(10);
    // }

    home_main();

    return 0;
}