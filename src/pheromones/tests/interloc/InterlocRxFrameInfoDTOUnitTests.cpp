#include <gtest/gtest.h>
#include <pheromones/interloc/InterlocRxFrameInfoDTO.h>

class InterlocRxFrameInfoTestFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(InterlocRxFrameInfoTestFixture, InterlocRxFrameInfo_construct_fromProto) {
    InterlocRxFrameInfo msg;
    msg.beeboardPort = 1;
    msg.rxTimestamp = 2;
    msg.sfdAngle = 3.3;
    msg.accumulatorAngle = 4.4;
    msg.messageId = 42;

    auto dto = InterlocRxFrameInfoDTO(msg);

    EXPECT_EQ(dto.getBeeboardPort(), msg.beeboardPort);
    EXPECT_EQ(dto.getRxTimestamp(), msg.rxTimestamp);
    EXPECT_EQ(dto.getSfdAngle(), msg.sfdAngle);
    EXPECT_EQ(dto.getAccumulatorAngle(), msg.accumulatorAngle);
    EXPECT_EQ(dto.getMessageId(), msg.messageId);
}

TEST_F(InterlocRxFrameInfoTestFixture, InterlocRxFrameInfo_setBeeboardPort) {
    InterlocRxFrameInfo msg;
    msg.beeboardPort = 1;
    msg.rxTimestamp = 2;
    msg.sfdAngle = 3.3;
    msg.accumulatorAngle = 4.4;
    msg.messageId = 42;

    uint8_t beeboardPort = 42;

    auto dto = InterlocRxFrameInfoDTO(msg);
    dto.setBeeboardPort(beeboardPort);

    EXPECT_EQ(dto.getBeeboardPort(), beeboardPort);
    EXPECT_EQ(dto.getRxTimestamp(), msg.rxTimestamp);
    EXPECT_EQ(dto.getSfdAngle(), msg.sfdAngle);
    EXPECT_EQ(dto.getAccumulatorAngle(), msg.accumulatorAngle);
    EXPECT_EQ(dto.getMessageId(), msg.messageId);
}

TEST_F(InterlocRxFrameInfoTestFixture, InterlocRxFrameInfo_setRxTimestamp) {
    InterlocRxFrameInfo msg;
    msg.beeboardPort = 1;
    msg.rxTimestamp = 2;
    msg.sfdAngle = 3.3;
    msg.accumulatorAngle = 4.4;
    msg.messageId = 42;

    uint64_t timestamp = 42;

    auto dto = InterlocRxFrameInfoDTO(msg);
    dto.setRxTimestamp(timestamp);

    EXPECT_EQ(dto.getBeeboardPort(), msg.beeboardPort);
    EXPECT_EQ(dto.getRxTimestamp(), timestamp);
    EXPECT_EQ(dto.getSfdAngle(), msg.sfdAngle);
    EXPECT_EQ(dto.getAccumulatorAngle(), msg.accumulatorAngle);
    EXPECT_EQ(dto.getMessageId(), msg.messageId);
}

TEST_F(InterlocRxFrameInfoTestFixture, InterlocRxFrameInfo_setSfdAngle) {
    InterlocRxFrameInfo msg;
    msg.beeboardPort = 1;
    msg.rxTimestamp = 2;
    msg.sfdAngle = 3.3;
    msg.accumulatorAngle = 4.4;
    msg.messageId = 42;

    float angle = 42.42;

    auto dto = InterlocRxFrameInfoDTO(msg);
    dto.setSfdAngle(angle);

    EXPECT_EQ(dto.getBeeboardPort(), msg.beeboardPort);
    EXPECT_EQ(dto.getRxTimestamp(), msg.rxTimestamp);
    EXPECT_EQ(dto.getSfdAngle(), angle);
    EXPECT_EQ(dto.getAccumulatorAngle(), msg.accumulatorAngle);
    EXPECT_EQ(dto.getMessageId(), msg.messageId);
}

TEST_F(InterlocRxFrameInfoTestFixture, InterlocRxFrameInfo_setAccumulatorAngle) {
    InterlocRxFrameInfo msg;
    msg.beeboardPort = 1;
    msg.rxTimestamp = 2;
    msg.sfdAngle = 3.3;
    msg.accumulatorAngle = 4.4;
    msg.messageId = 42;

    float angle = 42.42;

    auto dto = InterlocRxFrameInfoDTO(msg);
    dto.setAccumulatorAngle(angle);

    EXPECT_EQ(dto.getBeeboardPort(), msg.beeboardPort);
    EXPECT_EQ(dto.getRxTimestamp(), msg.rxTimestamp);
    EXPECT_EQ(dto.getSfdAngle(), msg.sfdAngle);
    EXPECT_EQ(dto.getAccumulatorAngle(), angle);
    EXPECT_EQ(dto.getMessageId(), msg.messageId);
}

TEST_F(InterlocRxFrameInfoTestFixture, InterlocRxFrameInfo_setMessageId) {
    InterlocRxFrameInfo msg;
    msg.beeboardPort = 1;
    msg.rxTimestamp = 2;
    msg.sfdAngle = 3.3;
    msg.accumulatorAngle = 4.4;
    msg.messageId = 42;

    uint32_t newMessageId = 69;

    auto dto = InterlocRxFrameInfoDTO(msg);
    dto.setMessageId(newMessageId);

    EXPECT_EQ(dto.getBeeboardPort(), msg.beeboardPort);
    EXPECT_EQ(dto.getRxTimestamp(), msg.rxTimestamp);
    EXPECT_EQ(dto.getSfdAngle(), msg.sfdAngle);
    EXPECT_EQ(dto.getAccumulatorAngle(), msg.accumulatorAngle);
    EXPECT_EQ(dto.getMessageId(), newMessageId);
}

TEST_F(InterlocRxFrameInfoTestFixture, InterlocRxFrameInfo_serialize) {
    InterlocRxFrameInfo msg;

    uint8_t beeboardPort = 1;
    uint64_t rxTimestamp = 2;
    float sfdAngle = 3.4;
    float accumulatorAngle = 5.6;
    uint32_t messageId = 42;

    auto dto = InterlocRxFrameInfoDTO();
    dto.setBeeboardPort(beeboardPort);
    dto.setRxTimestamp(rxTimestamp);
    dto.setSfdAngle(sfdAngle);
    dto.setAccumulatorAngle(accumulatorAngle);
    dto.setMessageId(messageId);

    bool ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.beeboardPort, beeboardPort);
    EXPECT_EQ(msg.rxTimestamp, rxTimestamp);
    EXPECT_EQ(msg.sfdAngle, sfdAngle);
    EXPECT_EQ(msg.accumulatorAngle, accumulatorAngle);
    EXPECT_EQ(msg.messageId, messageId);
}