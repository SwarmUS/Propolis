#include "c-common/software_crc.h"
#include <gtest/gtest.h>

class CRCTestsFixture : public testing::Test {};

TEST_F(CRCTestsFixture, TestCRC8_AllZeros) {
    uint8_t buff[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    EXPECT_NE(calculateCRC8(buff, sizeof(buff)), 0);
}

TEST_F(CRCTestsFixture, TestCRC8_ShortBuffer) {
    uint8_t buff[] = {0, 3, 4};
    EXPECT_EQ(calculateCRC8(buff, sizeof(buff)), 212);
}
TEST_F(CRCTestsFixture, TestCRC8_NullBuffer) { EXPECT_EQ(calculateCRC8(nullptr, 1), 0X0D); }

TEST_F(CRCTestsFixture, TestCRC32_SingleValue) {
    uint32_t val = 0x11223344;
    EXPECT_EQ(calculateCRC32(&val, sizeof(val)), 0xB14257CC);
}

TEST_F(CRCTestsFixture, TestCRC32_ShortBuffer) {
    uint32_t buff[] = {1, 2, 3, 4};
    uint32_t res = calculateCRC32(buff, sizeof(buff));
    EXPECT_EQ(res, 0x955AE3FD);
}

TEST_F(CRCTestsFixture, TestCRC32_NullBuffer) { EXPECT_EQ(calculateCRC32(nullptr, 4), 0XFFFFFFFF); }