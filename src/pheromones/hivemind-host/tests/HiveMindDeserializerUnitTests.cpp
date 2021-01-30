
#include "mocks/ProtobufStreamInterfaceMock.h"
#include <gtest/gtest.h>
#include <hivemind-host/HiveMindDeserializer.h>

class HiveMindDeserializerFixture : public testing::Test {
  protected:
    ProtobufStreamInterfaceMock m_streamInterfaceMock;
    HiveMindDeserializer* m_deserializer;

    void SetUp() override { m_deserializer = new HiveMindDeserializer(m_streamInterfaceMock); }

    void TearDown() override { delete m_deserializer; }
};

TEST_F(HiveMindDeserializerFixture, HiveMindDeserializer_serialize_validStream) {
    // Given
    // We dont really care about the data so we insert garbage in it
    EXPECT_CALL(m_streamInterfaceMock, send(testing::_, testing::_))
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));

    // Then
    std::variant<std::monostate, MessageDTO> message = m_deserializer->deserialize();

    // Expect
    EXPECT_NE(std::get_if<MessageDTO>(message), NULL);
}

TEST_F(HiveMindDeserializerFixture, HiveMindDeserializer_serialize_invalidStream) {
    // Given

    EXPECT_CALL(m_streamInterfaceMock, send(testing::_, testing ::_))
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(false));

    // Then
    std::variant<std::monostate, MessageDTO> message = m_deserializer->deserialize();

    // Expect
    EXPECT_EQ(std::get_if<MessageDTO>(message), NULL);
}
