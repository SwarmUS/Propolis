#include <gtest/gtest.h>
#include <pheromones/interloc/InterlocRawAngleDataDTO.h>

class InterlocRawAngleDataTestFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(InterlocRawAngleDataTestFixture, InterlocRawAngleData_deserialize) {
    InterlocRawAngleData msg;
    msg.frames_count = 3;

    for (unsigned int i = 0; i < msg.frames_count; i++) {
        msg.frames[i].frameId = i;
    }

    InterlocRawAngleDataDTO dto = InterlocRawAngleDataDTO(msg);

    EXPECT_EQ(dto.getFramesLength(), msg.frames_count);
    for (unsigned int i = 0; i < msg.frames_count; i++) {
        EXPECT_EQ(dto.getFrames()[i].getFrameId(), i);
    }
}

TEST_F(InterlocRawAngleDataTestFixture, InterlocRawAngleData_setFrames) {
    InterlocRawAngleData msg;
    msg.frames_count = 0;

    constexpr uint8_t framesLength = 4;

    InterlocRawAngleDataDTO dto = InterlocRawAngleDataDTO(msg);

    InterlocRxFrameRawAngleDataDTO frames[framesLength];
    for (unsigned int i = 0; i < framesLength; i++) {
        frames[i].setFrameId(i);
    }
    dto.setFrames(frames, framesLength);

    EXPECT_EQ(dto.getFramesLength(), framesLength);
    for (unsigned int i = 0; i < framesLength; i++) {
        EXPECT_EQ(dto.getFrames()[i].getFrameId(), i);
    }
}

TEST_F(InterlocRawAngleDataTestFixture, InterlocRawAngleData_serialize) {
    InterlocRawAngleData msg;
    constexpr uint8_t framesLength = 3;
    InterlocRawAngleDataDTO dto = InterlocRawAngleDataDTO();

    InterlocRxFrameRawAngleDataDTO frames[framesLength];
    for (unsigned int i = 0; i < framesLength; i++) {
        frames[i].setFrameId(i);
    }

    dto.setFrames(frames, framesLength);

    bool ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.frames_count, framesLength);
    for (unsigned int i = 0; i < framesLength; i++) {
        EXPECT_EQ(msg.frames[i].frameId, i);
    }
}
