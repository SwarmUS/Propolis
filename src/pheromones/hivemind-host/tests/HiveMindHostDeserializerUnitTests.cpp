
#include "mocks/ProtobufStreamInterfaceMock.h"
#include <gtest/gtest.h>
#include <hivemind-host/HiveMindHostDeserializer.h>

class HiveMindHostDeserializerFixture : public testing::Test {
  protected:
    ProtobufStreamInterfaceMock m_streamInterfaceMock;
    HiveMindHostDeserializer* m_deserializer;

    void SetUp() override { m_deserializer = new HiveMindHostDeserializer(m_streamInterfaceMock); }

    void TearDown() override { delete m_deserializer; }
};

TEST_F(HiveMindHostDeserializerFixture, HiveMindDeserializer_deserialize_invalidStream) {
    // Given

    EXPECT_CALL(m_streamInterfaceMock, receive(testing::_, testing ::_))
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(false));

    // Then
    MessageDTO message;
    bool ret = m_deserializer->deserializeFromStream(message);

    // Expect
    EXPECT_FALSE(ret);
}
