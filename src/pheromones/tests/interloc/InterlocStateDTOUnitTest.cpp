#include <gtest/gtest.h>
#include <message.pb.h>
#include <pheromones/interloc/InterlocStateDTO.h>

class InterlocStateDTOTestFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_dtoToTarget_standby) {
    auto ret = dtoToInterlocState(InterlocStateDTO::STANDBY);

    EXPECT_EQ(ret, InterlocState_STANDBY);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_dtoToTarget_operating) {
    auto ret = dtoToInterlocState(InterlocStateDTO::OPERATING);

    EXPECT_EQ(ret, InterlocState_OPERATING);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_dtoToTarget_angleSender) {
    auto ret = dtoToInterlocState(InterlocStateDTO::ANGLE_CALIB_SENDER);

    EXPECT_EQ(ret, InterlocState_ANGLE_CALIB_SENDER);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_dtoToTarget_angleReceiver) {
    auto ret = dtoToInterlocState(InterlocStateDTO::ANGLE_CALIB_RECEIVER);

    EXPECT_EQ(ret, InterlocState_ANGLE_CALIB_RECEIVER);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_dtoToTarget_twrInitiator) {
    auto ret = dtoToInterlocState(InterlocStateDTO::TWR_CALIB_INITIATOR);

    EXPECT_EQ(ret, InterlocState_TWR_CALIB_INITIATOR);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_dtoToTarget_twrResponder) {
    auto ret = dtoToInterlocState(InterlocStateDTO::TWR_CALIB_RESPONDER);

    EXPECT_EQ(ret, InterlocState_TWR_CALIB_RESPONDER);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_dtoToTarget_unsupported) {
    auto ret = dtoToInterlocState(InterlocStateDTO::UNSUPPORTED);

    EXPECT_EQ(ret, InterlocState_UNSUPORTED);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_targetToDTO_standby) {
    auto ret = interlocStateToDTO(InterlocState_STANDBY);

    EXPECT_EQ(ret, InterlocStateDTO::STANDBY);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_targetToDTO_operating) {
    auto ret = interlocStateToDTO(InterlocState_OPERATING);

    EXPECT_EQ(ret, InterlocStateDTO::OPERATING);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_targetToDTO_angleSender) {
    auto ret = interlocStateToDTO(InterlocState_ANGLE_CALIB_SENDER);

    EXPECT_EQ(ret, InterlocStateDTO::ANGLE_CALIB_SENDER);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_targetToDTO_angleReceiver) {
    auto ret = interlocStateToDTO(InterlocState_ANGLE_CALIB_RECEIVER);

    EXPECT_EQ(ret, InterlocStateDTO::ANGLE_CALIB_RECEIVER);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_targetToDTO_twrInitiator) {
    auto ret = interlocStateToDTO(InterlocState_TWR_CALIB_INITIATOR);

    EXPECT_EQ(ret, InterlocStateDTO::TWR_CALIB_INITIATOR);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_targetToDTO_twrResponder) {
    auto ret = interlocStateToDTO(InterlocState_TWR_CALIB_RESPONDER);

    EXPECT_EQ(ret, InterlocStateDTO::TWR_CALIB_RESPONDER);
}

TEST_F(InterlocStateDTOTestFixture, InterlocStateDTO_targetToDTO_unsuported) {
    auto ret = interlocStateToDTO(InterlocState_UNSUPORTED);

    EXPECT_EQ(ret, InterlocStateDTO::UNSUPPORTED);
}
