#include "c-common/software_crc.h"

#define CRC8_START 0x0D
#define CRC32_START 0xFFFFFFFF
static uint32_t Crc32Fast(uint32_t crc, uint32_t data);

uint32_t calculateCRC32_software(const void* data, uint32_t length) {
    uint32_t crc32 = CRC32_START;
    const uint32_t* ptr = (const uint32_t*)data;
    uint32_t numElements = length / sizeof(uint32_t);
    if (data) {
        while (numElements--) {
            crc32 = Crc32Fast(crc32, *ptr++);
        }
    }

    return crc32;
}

// Source: https://github.com/lammertb/libcrc/blob/master/src/crc8.c
uint8_t calculateCRC8_software(const void* data, uint32_t length) {
    static uint8_t s_crcTable[] = {
        0,   49,  98,  83,  196, 245, 166, 151, 185, 136, 219, 234, 125, 76,  31,  46,  67,  114,
        33,  16,  135, 182, 229, 212, 250, 203, 152, 169, 62,  15,  92,  109, 134, 183, 228, 213,
        66,  115, 32,  17,  63,  14,  93,  108, 251, 202, 153, 168, 197, 244, 167, 150, 1,   48,
        99,  82,  124, 77,  30,  47,  184, 137, 218, 235, 61,  12,  95,  110, 249, 200, 155, 170,
        132, 181, 230, 215, 64,  113, 34,  19,  126, 79,  28,  45,  186, 139, 216, 233, 199, 246,
        165, 148, 3,   50,  97,  80,  187, 138, 217, 232, 127, 78,  29,  44,  2,   51,  96,  81,
        198, 247, 164, 149, 248, 201, 154, 171, 60,  13,  94,  111, 65,  112, 35,  18,  133, 180,
        231, 214, 122, 75,  24,  41,  190, 143, 220, 237, 195, 242, 161, 144, 7,   54,  101, 84,
        57,  8,   91,  106, 253, 204, 159, 174, 128, 177, 226, 211, 68,  117, 38,  23,  252, 205,
        158, 175, 56,  9,   90,  107, 69,  116, 39,  22,  129, 176, 227, 210, 191, 142, 221, 236,
        123, 74,  25,  40,  6,   55,  100, 85,  194, 243, 160, 145, 71,  118, 37,  20,  131, 178,
        225, 208, 254, 207, 156, 173, 58,  11,  88,  105, 4,   53,  102, 87,  192, 241, 162, 147,
        189, 140, 223, 238, 121, 72,  27,  42,  193, 240, 163, 146, 5,   52,  103, 86,  120, 73,
        26,  43,  188, 141, 222, 239, 130, 179, 224, 209, 70,  119, 36,  21,  59,  10,  89,  104,
        255, 206, 157, 172};
    uint8_t crc = CRC8_START;
    const uint8_t* ptr = (const uint8_t*)data;

    if (ptr) {
        for (uint32_t a = 0; a < length; a++) {

            crc = s_crcTable[(*ptr++) ^ crc];
        }
    }

    return crc;
}

// source: https://community.st.com/s/question/0D50X0000AIeYIb/stm32f4-crc32-algorithm-headache
uint32_t Crc32Fast(uint32_t crc, uint32_t data) {
    static const uint32_t s_crcTable[16] = {// Nibble lookup table for 0x04C11DB7 polynomial
                                            0x00000000, 0x04C11DB7, 0x09823B6E, 0x0D4326D9,
                                            0x130476DC, 0x17C56B6B, 0x1A864DB2, 0x1E475005,
                                            0x2608EDB8, 0x22C9F00F, 0x2F8AD6D6, 0x2B4BCB61,
                                            0x350C9B64, 0x31CD86D3, 0x3C8EA00A, 0x384FBDBD};

    crc = crc ^ data; // Apply all 32-bits

    // Process 32-bits, 4 at a time, or 8 rounds

    crc = (crc << 4) ^ s_crcTable[crc >> 28]; // Assumes 32-bit reg, masking index to 4-bits
    crc = (crc << 4) ^ s_crcTable[crc >> 28]; //  0x04C11DB7 Polynomial used in STM32
    crc = (crc << 4) ^ s_crcTable[crc >> 28];
    crc = (crc << 4) ^ s_crcTable[crc >> 28];
    crc = (crc << 4) ^ s_crcTable[crc >> 28];
    crc = (crc << 4) ^ s_crcTable[crc >> 28];
    crc = (crc << 4) ^ s_crcTable[crc >> 28];
    crc = (crc << 4) ^ s_crcTable[crc >> 28];

    return (crc);
}
