#include <stdbool.h>
#include <stdint.h>

#ifndef FI_DRIVER_SD_H
#define FI_DRIVER_SD_H

/**
 * Initialize SD card.
 */
uint8_t fi_SD_init(void);

/**
 * Write a block to SD card.
 * \param block Block number to write.
 * \param data Pointer to data to write.
 * \param length Length of data to write, remaining bytes will be padded with
 * 0x00. \return Status code, 0 if successful.
 */
uint8_t fi_SD_writeBlock(uint32_t block, uint8_t* data, uint8_t length);

/**
 * Read some data from SD card, and store it in buffer.
 * \param block Block number to read.
 * \param offset Offset in byte to start reading from.
 * \param length Length of data to read.
 * \param buffer Pointer to buffer to store data in.
 * \return Status code, 0 if successful.
 */
uint8_t fi_SD_read(uint32_t block,
                   uint16_t offset,
                   uint32_t length,
                   uint8_t* buffer);

uint8_t fi_SD_Reader_init(uint32_t block, uint16_t offset);

uint8_t fi_SD_Reader_read(uint32_t length, uint8_t* buffer);

/**
 * Jump, will jump to the pointer just read. ptr is the pointer from
 * fi_SD_Reader_read, has 5 bytes.
 */
uint8_t fi_SD_Reader_jump(uint8_t* ptr);

uint8_t fi_SD_Reader_close();

#endif
