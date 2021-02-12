#ifndef __SOFTWARE_CRC_H__
#define __SOFTWARE_CRC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Calculates the CRC32 of a buffer
 * @param data Pointer to the buffer
 * @param length Length of buffer in bytes
 * @return CRC32
 */
uint32_t calculateCRC32(const void* data, uint32_t length);

/**
 * @brief Calculates the CRC8 of a buffer
 * @param data Pointer to the buffer
 * @param length Length of buffer in bytes
 * @return CRC8
 */
uint8_t calculateCRC8(const void* data, uint32_t length);

#ifdef __cplusplus
}
#endif

#endif // __SOFTWARE_CRC_H__
