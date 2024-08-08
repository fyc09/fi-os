#include "sd.h"
#include "interface.h"
#include <stddef.h>

#define SD_CMD_GO_IDLE_STATE 0       /* CMD0 = 0x40 */
#define SD_CMD_SEND_IF_COND 8        /* CMD8 = 0x48 */
#define SD_CMD_SEND_CSD 9            /* CMD9 = 0x49 */
#define SD_CMD_SEND_CID 10           /* CMD10 = 0x4A */
#define SD_CMD_STOP_TRANSMISSION 12  /* CMD12 = 0x4C */
#define SD_CMD_SEND_STATUS 13        /* CMD13 = 0x4D */
#define SD_CMD_SET_BLOCKLEN 16       /* CMD16 = 0x50 */
#define SD_CMD_READ_SINGLE_BLOCK 17  /* CMD17 = 0x51 */
#define SD_CMD_READ_MULT_BLOCK 18    /* CMD18 = 0x52 */
#define SD_CMD_SET_BLOCK_COUNT 23    /* CMD23 = 0x57 */
#define SD_CMD_WRITE_SINGLE_BLOCK 24 /* CMD24 = 0x58 */
#define SD_CMD_WRITE_MULT_BLOCK 25   /* CMD25 = 0x59 */
#define SD_CMD_PROG_CSD 27           /* CMD27 = 0x5B */
#define SD_CMD_SET_WRITE_PROT 28     /* CMD28 = 0x5C */
#define SD_CMD_CLR_WRITE_PROT 29     /* CMD29 = 0x5D */
#define SD_CMD_SEND_WRITE_PROT 30    /* CMD30 = 0x5E */
#define SD_CMD_SD_ERASE_GRP_START 32 /* CMD32 = 0x60 */
#define SD_CMD_SD_ERASE_GRP_END 33   /* CMD33 = 0x61 */
#define SD_CMD_UNTAG_SECTOR 34       /* CMD34 = 0x62 */
#define SD_CMD_ERASE_GRP_START 35    /* CMD35 = 0x63 */
#define SD_CMD_ERASE_GRP_END 36      /* CMD36 = 0x64 */
#define SD_CMD_UNTAG_ERASE_GROUP 37  /* CMD37 = 0x65 */
#define SD_CMD_ERASE 38              /* CMD38 = 0x66 */
#define SD_ACMD_SEND_OP_COND 41      /* CMD41 = 0x69 */
#define SD_CMD_APP_CMD 55            /* CMD55 = 0x77 */

void send(uint8_t byte) {
    fiInterface_SD_write(byte);
}

void sendCmd(uint8_t cmd, uint32_t arg, uint8_t crc) {
    uint32_t i = 0x00;

    uint8_t Frame[6];

    Frame[0] = (cmd | 0x40);
    Frame[1] = (uint8_t)(arg >> 24);
    Frame[2] = (uint8_t)(arg >> 16);
    Frame[3] = (uint8_t)(arg >> 8);
    Frame[4] = (uint8_t)(arg);
    Frame[5] = (crc);

    for (i = 0; i < 6; i++) {
        send(Frame[i]);
    }
}

uint8_t readByte() {
    uint8_t res = 0xff;
    uint8_t count = 0xff;
    while (res == 0xff && count > 0) {
        res = fiInterface_SD_read();
        count--;
    }
    return res;
}

bool readUntil(uint8_t token) {
    uint8_t count = 0xff;
    while (count > 0) {
        uint8_t t = fiInterface_SD_read();
        // printf("Got 0x%02x Expect 0x%02x\n", t, token);
        if (t == token) {
            break;
        }
        count--;
    }

    if (count == 0) {
        return false;
    }

    return true;
}

uint8_t fiDriver_SD_init(void) {
    // Give 80 clocks to SD card.
    for (uint8_t i = 0; i <= 9; i++) {
        fiInterface_SD_write(0xff);
    }

    // Try to send CMD0. Fail after 255 times.
    sendCmd(SD_CMD_GO_IDLE_STATE, 0, 0x95);
    if (!readUntil(0x01)) {
        return -1;
    }

    sendCmd(SD_CMD_SEND_IF_COND, 0x1aa, 0x01);
    if (!readUntil(0xaa)) {
        return -2;
    }

    sendCmd(SD_CMD_APP_CMD, 0, 0x01);
    if (!readUntil(0x01)) {
        return -3;
    }

    do {
        sendCmd(SD_ACMD_SEND_OP_COND, 0x40000000, 0xff);
        readByte();
        sendCmd(SD_CMD_APP_CMD, 0, 0xff);
    } while (!readUntil(0x00));

    return 0;
}

uint8_t buffer[512];

uint8_t *fiDriver_SD_readBlock(uint32_t block) {
    sendCmd(SD_CMD_READ_SINGLE_BLOCK, block, 0xff);
    if (!readUntil(0x00)) {
        return NULL;
    }
    if (!readUntil(0xFE)) {
        return NULL;
    }

    for (int i = 0; i < 512; i++) {
        buffer[i] = readByte();
    }

    // 2 CRC bytes. Ignore.
    readByte();
    readByte();

    fiInterface_SD_sendDummy();

    fiInterface_SD_sendDummy();
    send(0xff);
    readUntil(0x00);
    readUntil(0xff);

    return buffer;
}

bool fiDriver_SD_writeBlock(uint32_t block, uint8_t *data) {
    sendCmd(SD_CMD_WRITE_SINGLE_BLOCK, block, 0xff);
    if (!readUntil(0x00)) {
        return false;
    }

    send(0xFE);
    for (int i = 0; i < 512; i++) {
        send(data[i]);
    }

    // 2 CRC bytes. Ignore.
    readByte();
    readByte();

    fiInterface_SD_sendDummy();
    send(0xff);
    readUntil(0x00);
    readUntil(0xff);

    return true;
}
