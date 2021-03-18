#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <hivemind-host/BuzzMessageDTO.h>

class BuzMessageDTOFixture : public testing::Test {
  public:
    BuzzMessageDTO* m_msg;

    void SetUp() override { m_msg = new BuzzMessageDTO(NULL, 0); }

    void TearDown() override { delete m_msg; }
};

TEST_F(BuzMessageDTOFixture, BuzzMessage_constructor_noOverflow) {
    // Given
    std::string rndString = randomString(100);

    // Then
    BuzzMessageDTO msg((uint8_t*)rndString.data(), rndString.size());

    // Expect
    EXPECT_EQ(msg.getPayloadLength(), BuzzMessageDTO::PAYLOAD_MAX_SIZE);
}

TEST_F(BuzMessageDTOFixture, BuzzMessage_serialize_valid) {
    // Given
    BuzzMessage msg;

    // Then
    bool ret = m_msg->serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
}
