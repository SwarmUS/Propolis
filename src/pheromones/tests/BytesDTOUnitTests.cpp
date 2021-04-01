#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <pheromones/BytesDTO.h>

class BytesDTOFixture : public testing::Test {
  public:
    const uint32_t m_byteReqId = 1;
    const uint32_t m_packetNumber = 1;
    const bool m_lastPacket = true;

    BytesDTO* m_bytes;

    void SetUp() override {
        m_bytes = new BytesDTO(m_byteReqId, m_packetNumber, m_lastPacket, NULL, 0);
    }

    void TearDown() override { delete m_bytes; }
};

TEST_F(BytesDTOFixture, Bytes_constructor_noOverflow) {
    // Given
    std::string rndString = randomString(1024);

    // Then
    BytesDTO bytes(m_byteReqId, m_packetNumber, m_lastPacket, (uint8_t*)rndString.data(),
                   rndString.size());

    // Expect
    EXPECT_EQ(bytes.getPayloadLength(), BytesDTO::PAYLOAD_MAX_SIZE);
}

TEST_F(BytesDTOFixture, Bytes_serialize_valid) {
    // Given
    Bytes bytes;

    // Then
    bool ret = m_bytes->serialize(bytes);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(bytes.packet_id, m_bytes->getPacketId());
    EXPECT_EQ(bytes.packet_no, m_bytes->getPacketNumber());
    EXPECT_EQ(bytes.last_packet, m_bytes->isLastPacket());
}
