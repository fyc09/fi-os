#include <stdint.h>
#include <string.h>
#include "sd.h"
#include "system.h"

uint8_t fi_file_open(const char* filename) {
    uint8_t status;

    uint8_t length = strlen(filename);
    if (length > 11) {
        return 1;
    }

    uint8_t record[16];
    uint8_t i;

    printf(";;;\n");
    if ((status = fi_SD_Reader_init(0, 0))) {
    printf("%d", status);
        return status;
    }

next:
    if ((status = fi_SD_Reader_read(16, record))) {
        return status;
    }
    i = 0;
    // If reaching the end of the index, return not found.
    if (record[0] == 0x00) {
        return 1;
    }
    // Match until end of filename.
    while (i < 11) {
        if (filename[i] == 0x00) {
            break;
        }
        if (record[i] != filename[i]) {
            goto next;
        }
        i++;
    }
    // Make sure the rest of the filename is 0x00.
    while (i < 11) {
        if (record[i] != 0x00) {
            goto next;
        }
        i++;
    }

    if ((status = fi_SD_Reader_jump(record + 11))) {
        return status;
    }

    return 0;
}
