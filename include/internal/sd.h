#include <stdbool.h>
#include <stdint.h>

#ifndef FI_DRIVER_SD_H
#define FI_DRIVER_SD_H

/**
 * Initialize SD card.
 */
uint8_t fiDriver_SD_init(void);

/**
 * Read a block from SD card.
 * \param block Block number to read.
 * \return Pointer to the block data. Will not change until next read.
 */
uint8_t *fiDriver_SD_readBlock(uint32_t block);

/**
 * Write a block to SD card.
 * \param block Block number to write.
 * \param data Pointer to the data to write, must be 512 bytes long.
 * \return true if write was successful, false otherwise.
 */
bool fiDriver_SD_writeBlock(uint32_t block, uint8_t *data);

#endif
