#include "mocks/ProtobufStreamInterfaceMock.h"
#include <gtest/gtest.h>
#include <hivemind-host/HiveMindHostSerializer.h>

class HiveMindHostSerializerFixture : public testing::Test {
  protected:
    ProtobufStreamInterfaceMock m_streamInterfaceMock;
    HiveMindHostSerializer* m_serializer;
    Message m_message;

    void SetUp() override {

        std::string functionName = "Hello world";
        FunctionCallRequestDTO funRequestDTO(functionName.c_str(), (FunctionCallArgumentDTO*)NULL,
                                             0);
        RequestDTO requestDTO(1, funRequestDTO);
        MessageDTO messageDTO(1, 2, requestDTO);

        Message message;
        messageDTO.serialize(message);

        m_serializer = new HiveMindHostSerializer(m_streamInterfaceMock);
    }

    void TearDown() override { delete m_serializer; }
};

TEST_F(HiveMindHostSerializerFixture, HiveMindSerializer_serialize_validStream) {
    // Given
    // We dont really care about the data so we insert garbage in it
    Message message;
    MessageDTO messageDTO(message);

    EXPECT_CALL(m_streamInterfaceMock, send(testing::_, testing::_))
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(true));

    // Then
    bool ret = m_serializer->serialize(messageDTO);

    // Expect
    EXPECT_EQ(ret, true);
}

TEST_F(HiveMindHostSerializerFixture, HiveMindSerializer_serialize_invalidStream) {
    // Given

    EXPECT_CALL(m_streamInterfaceMock, send(testing::_, testing ::_))
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(false));

    // Then
    bool ret = m_serializer->serialize(m_message);

    // Expect
    EXPECT_EQ(ret, false);
}
