#include <stdio.h>
#include "interface.h"
#include "keyboard.h"
#include "oled.h"
#include "pico/stdlib.h"
#include "sd.h"
#include "system.h"

int main() {
    uint8_t code;

    stdio_init_all();

    sleep_ms(5000);

    if ((code = fi_system_init())) {
        for (;;) {
            printf("%d ", code);
            sleep_ms(1000);
        }

        return code;
    }

    printf("Hello, world!\n");

    fi_OLED_init();
    fi_OLED_setDisplay(ON);
    fi_OLED_clear();

    // fi_OLED_showStr(0, 0, "Hello, world!", SMALL, NORMAL);
    // fi_OLED_showStr(0, 16, "Hello, world!", SMALL, REVERSED);
    // fi_OLED_showStr(0, 32, "Hello, world!", BIG, NORMAL);
    // fi_OLED_showStr(0, 48, "Hello, world!", BIG, REVERSED);

    // if ((code = fi_file_open("gzcnfont"))) {
    //
    //     return code;
    // }

    // uint8_t buffer[16];
    // if ((code = fi_SD_Reader_read(16, buffer))) {
    //
    //     return code;
    // }

    // for (int i = 0; i < 16; i++) {
    //
    // }

    // if ((code = fi_SD_Reader_close())) {
    //
    //     return code;
    // }

    // if ((code = fi_file_open("gzcnfont"))) {
    //
    //     return code;
    // }

    // if ((code = fi_SD_Reader_read(16, buffer))) {
    //
    //     return code;
    // }

    // for (int i = 0; i < 16; i++) {
    //
    // }
    printf("Hello, world!");

    // code = fi_font_write("西安交通大学是我国最早兴办、享誉海内外的著名高等学府。", 0,
    //               0, FI_FONT_SIMSUN, REVERSED);
    
    // printf("%d", code);
    // // return 0;

    // uint8_t status;
    // uint8_t buffer[512];
    // for (;;) {
    //     if ((status = fi_SD_read(0, 0, 512, buffer))) {
    //         return status;
    //     }
    //     for (int i = 0; i < 512; i++) {
    //         if (buffer[i] != 0xaa) {
    //             printf("%d ", buffer[i]);
    //         }
    //     }
    //     printf("\n");
    // }
    for (;;)
        ;

    return 0;
}