#include <gtest/gtest.h>
#include <pheromones/interloc/InterlocRxFrameRawAngleDataDTO.h>

class InterlocRxFrameRawAngleDataTestsFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(InterlocRxFrameRawAngleDataTestsFixture, InterlocRxFrameRawAngleData_deserialize) {
    InterlocRxFrameRawAngleData msg;
    msg.frameId = 1;
    msg.frameInfos_count = 2;

    for (unsigned int i = 0; i < msg.frameInfos_count; i++) {
        msg.frameInfos[i].rxTimestamp = i;
    }

    InterlocRxFrameRawAngleDataDTO dto = InterlocRxFrameRawAngleDataDTO(msg);

    EXPECT_EQ(dto.getFrameId(), msg.frameId);
    EXPECT_EQ(dto.getFrameInfosLength(), msg.frameInfos_count);
    for (unsigned int i = 0; i < msg.frameInfos_count; i++) {
        EXPECT_EQ(dto.getFrameInfos()[i].getRxTimestamp(), i);
    }
}

TEST_F(InterlocRxFrameRawAngleDataTestsFixture, InterlocRxFrameRawAngleData_setFrameId) {
    InterlocRxFrameRawAngleData msg;
    msg.frameId = 1;
    msg.frameInfos_count = 2;

    for (unsigned int i = 0; i < msg.frameInfos_count; i++) {
        msg.frameInfos[i].rxTimestamp = i;
    }

    uint32_t newFrameId = 42;

    InterlocRxFrameRawAngleDataDTO dto = InterlocRxFrameRawAngleDataDTO(msg);
    dto.setFrameId(newFrameId);

    EXPECT_EQ(dto.getFrameId(), newFrameId);
    EXPECT_EQ(dto.getFrameInfosLength(), msg.frameInfos_count);
    for (unsigned int i = 0; i < msg.frameInfos_count; i++) {
        EXPECT_EQ(dto.getFrameInfos()[i].getRxTimestamp(), i);
    }
}

TEST_F(InterlocRxFrameRawAngleDataTestsFixture, InterlocRxFrameRawAngleData_setFrameInfos_Empty) {
    InterlocRxFrameRawAngleData msg;
    msg.frameId = 1;
    msg.frameInfos_count = 2;

    for (unsigned int i = 0; i < msg.frameInfos_count; i++) {
        msg.frameInfos[i].rxTimestamp = i;
    }

    InterlocRxFrameRawAngleDataDTO dto = InterlocRxFrameRawAngleDataDTO(msg);
    dto.setFrameInfos(nullptr, 0);

    EXPECT_EQ(dto.getFrameId(), msg.frameId);
    EXPECT_EQ(dto.getFrameInfosLength(), 0);
}

TEST_F(InterlocRxFrameRawAngleDataTestsFixture, InterlocRxFrameRawAngleData_setFrameInfos) {
    InterlocRxFrameRawAngleData msg;
    msg.frameId = 1;
    msg.frameInfos_count = 0;

    constexpr uint8_t frameInfosLength = 3;

    InterlocRxFrameRawAngleDataDTO dto = InterlocRxFrameRawAngleDataDTO(msg);

    InterlocRxFrameInfoDTO frameInfos[frameInfosLength];
    for (unsigned int i = 0; i < frameInfosLength; i++) {
        frameInfos[i].setRxTimestamp(i);
    }
    dto.setFrameInfos(frameInfos, frameInfosLength);

    EXPECT_EQ(dto.getFrameId(), msg.frameId);
    EXPECT_EQ(dto.getFrameInfosLength(), frameInfosLength);
    for (unsigned int i = 0; i < frameInfosLength; i++) {
        EXPECT_EQ(dto.getFrameInfos()[i].getRxTimestamp(), i);
    }
}

TEST_F(InterlocRxFrameRawAngleDataTestsFixture, InterlocRxFrameRawAngleData_serialize) {
    InterlocRxFrameRawAngleData msg;
    uint32_t frameId = 42;
    constexpr uint8_t frameInfosLength = 3;
    InterlocRxFrameRawAngleDataDTO dto = InterlocRxFrameRawAngleDataDTO();

    InterlocRxFrameInfoDTO frameInfos[frameInfosLength];
    for (unsigned int i = 0; i < frameInfosLength; i++) {
        frameInfos[i].setRxTimestamp(i);
    }

    dto.setFrameId(frameId);
    dto.setFrameInfos(frameInfos, frameInfosLength);

    bool ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.frameId, frameId);
    EXPECT_EQ(msg.frameInfos_count, frameInfosLength);
    for (unsigned int i = 0; i < frameInfosLength; i++) {
        EXPECT_EQ(msg.frameInfos[i].rxTimestamp, i);
    }
}
