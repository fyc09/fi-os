#include "sd.h"
#include <stddef.h>
#include "interface.h"

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

struct {
    uint32_t block;
    uint16_t offset;
    enum {
        STATUS_READING,
        STATUS_READY,
    } status;
} state;

void send(uint8_t byte) {
    fi_inter_SD_write(byte);
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
    uint8_t count = 0x0f;
    while (res == 0xff && count > 0) {
        res = fi_inter_SD_read();
        count--;
    }
    return res;
}

uint8_t readRaw() {
    uint8_t res = fi_inter_SD_read();
    return res;
}

bool readUntil(uint8_t token) {
    uint8_t count = 0xff;
    while (count > 0) {
        uint8_t t = fi_inter_SD_read();
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

uint8_t fi_SD_init(void) {
    // Give 80 clocks to SD card.
    for (uint8_t i = 0; i <= 9; i++) {
        fi_inter_SD_sendDummy();
    }
    for (uint8_t i = 0; i <= 9; i++) {
        send(0xFF);
    }

    // Try to send CMD0. Fail after 255 times.
    sendCmd(SD_CMD_GO_IDLE_STATE, 0, 0x95);
    if (!readUntil(0x01)) {
        return 1;
    }

    sendCmd(SD_CMD_SEND_IF_COND, 0x1aa, 0x01);
    if (!readUntil(0xaa)) {
        return 2;
    }

    sendCmd(SD_CMD_APP_CMD, 0, 0x01);
    if (!readUntil(0x01)) {
        return 3;
    }

    do {
        sendCmd(SD_ACMD_SEND_OP_COND, 0x40000000, 0xff);
        readByte();
        sendCmd(SD_CMD_APP_CMD, 0, 0xff);
    } while (!readUntil(0x00));

    fi_inter_SD_sendDummy();

    sendCmd(SD_CMD_SET_BLOCKLEN, 512, 0xff);
    readByte();

    state.status = STATUS_READY;

    return 0;
}

uint8_t fi_SD_writeBlock(uint32_t block, uint8_t* data, uint8_t length) {
    uint8_t status;

    if ((status = fi_SD_init())) {
        return status;
    }

    if (state.status != STATUS_READY) {
        return 1;
    }

    if (length > 512) {
        return 2;
    }

    sendCmd(SD_CMD_WRITE_SINGLE_BLOCK, block, 0xff);
    if (!readUntil(0x00)) {
        return 3;
    }

    send(0xFE);
    for (int i = 0; i < length; i++) {
        send(data[i]);
    }

    for (int i = 0; i < 512 - length; i++) {
        send(0x00);
    }

    // 2 CRC bytes. Ignore.
    readByte();
    readByte();

    fi_inter_SD_sendDummy();
    send(0xff);
    readUntil(0x00);
    readUntil(0xff);

    return 0;
}

uint8_t startReadCmd(uint32_t block) {
    uint8_t status;
    if ((status = fi_SD_init())) {
        return status;
    }

    sendCmd(SD_CMD_READ_SINGLE_BLOCK, block, 0xff);
    if (!readUntil(0x00)) {
        return 1;
    }
    if (!readUntil(0xFE)) {
        return 2;
    }

    return 0;
}

uint8_t endReadCmd() {
    // 2 CRC bytes. Ignore.

    readByte();
    readByte();

    fi_inter_SD_sendDummy();

    fi_inter_SD_sendDummy();
    send(0xff);
    readUntil(0x00);
    readUntil(0xff);

    return 0;
}

uint8_t fi_SD_Reader_init(uint32_t block, uint16_t offset) {
    uint8_t status = 0;

    if (state.status != STATUS_READY) {
        return 1;
    }

    while (offset >= 512) {
        offset -= 512;
        block++;
    }

    state.block = block;
    state.offset = offset;

    if ((status = startReadCmd(block))) {
        return status;
    }

    while (offset > 0) {
        readRaw();
        offset--;
    }

    state.status = STATUS_READING;

    return 0;
}

uint8_t fi_SD_Reader_read(uint32_t length, uint8_t* buffer) {
    uint8_t status = 0;
    bool isEmpty = buffer == NULL;

    if (state.status != STATUS_READING) {
        return 1;
    }

    while (length > 0) {
        state.offset++;
        if (!isEmpty) {
            *buffer = readRaw();
            buffer++;
        } else {
            readRaw();
        }
        length--;

        if (state.offset == 512) {
            state.offset = 0;
            state.block++;

            if ((status = endReadCmd())) {
                return status;
            }

            if ((status = startReadCmd(state.block))) {
                return status;
            }

            state.status = STATUS_READING;
        }
    }

    return 0;
}

uint8_t fi_SD_Reader_jump(uint8_t* ptr) {
    uint8_t status = 0;

    // uint32_t block = *(uint32_t *)(ptr + 1) >> 1;
    // uint16_t offset = *(uint16_t *)ptr & 0x1ff;
    uint32_t block = ((ptr[1] >> 1) && 0x7f) | (ptr[2] << 7) | (ptr[3] << 15) | (ptr[4] << 23);
    uint16_t offset = ptr[0] | ((ptr[1] << 8) & 0x0100);

    if (offset < 5) {
        block -= 1;
        offset += 512 - 5;
    } else {
        offset -= 5;
    }

    uint32_t targetBlock = state.block + block;
    uint16_t targetOffset = state.offset + offset;

    while (targetOffset >= 512) {
        targetOffset -= 512;
        targetBlock++;
    }

    if ((status = fi_SD_Reader_close())) {
        return status;
    }

    if ((status = fi_SD_Reader_init(targetBlock, targetOffset))) {
        return status;
    }

    return 0;
}

uint8_t fi_SD_Reader_close() {
    uint8_t status = 0;

    if (state.status != STATUS_READING) {
        return 0;
    }

    while (state.offset < 512) {
        state.offset++;
        readRaw();
    }

    state.status = STATUS_READY;

    return endReadCmd();
}

uint8_t fi_SD_read(uint32_t block,
                   uint16_t offset,
                   uint32_t length,
                   uint8_t* buffer) {
    uint8_t status = 0;

    if ((status = fi_SD_Reader_init(block, offset))) {
        return status;
    }

    if ((status = fi_SD_Reader_read(length, buffer))) {
        return status;
    }

    return fi_SD_Reader_close();
}
