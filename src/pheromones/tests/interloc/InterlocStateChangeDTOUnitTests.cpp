#include <gtest/gtest.h>
#include <pheromones/interloc/InterlocStateChangeDTO.h>

class InterlocStateChangeTestFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(InterlocStateChangeTestFixture, InterlocStateChange_Construct_FromProto) {
    InterlocStateChange msg;
    msg.previousState = InterlocState_STANDBY;
    msg.newState = InterlocState_OPERATING;

    InterlocStateChangeDTO dto = InterlocStateChangeDTO(msg);

    EXPECT_EQ(dtoToInterlocState(dto.getPreviousState()), msg.previousState);
    EXPECT_EQ(dtoToInterlocState(dto.getNewState()), msg.newState);
}

TEST_F(InterlocStateChangeTestFixture, InterlocStateChange_Construct_FromStates) {
    InterlocStateDTO prevState = InterlocStateDTO::STANDBY;
    InterlocStateDTO newState = InterlocStateDTO::OPERATING;
    InterlocStateChangeDTO dto = InterlocStateChangeDTO(prevState, newState);

    EXPECT_EQ(dto.getPreviousState(), prevState);
    EXPECT_EQ(dto.getNewState(), newState);
}

TEST_F(InterlocStateChangeTestFixture, InterlocStateChange_SetPrevState) {
    InterlocStateDTO prevState = InterlocStateDTO::STANDBY;
    InterlocStateDTO newState = InterlocStateDTO::OPERATING;
    InterlocStateChangeDTO dto = InterlocStateChangeDTO(prevState, newState);

    InterlocStateDTO state = InterlocStateDTO::ANGLE_CALIB_SENDER;
    dto.setPreviousState(state);

    EXPECT_EQ(dto.getPreviousState(), state);
    EXPECT_EQ(dto.getNewState(), newState);
}

TEST_F(InterlocStateChangeTestFixture, InterlocStateChange_SetNewState) {
    InterlocStateDTO prevState = InterlocStateDTO::STANDBY;
    InterlocStateDTO newState = InterlocStateDTO::OPERATING;
    InterlocStateChangeDTO dto = InterlocStateChangeDTO(prevState, newState);

    InterlocStateDTO state = InterlocStateDTO::ANGLE_CALIB_SENDER;
    dto.setNewState(state);

    EXPECT_EQ(dto.getPreviousState(), prevState);
    EXPECT_EQ(dto.getNewState(), state);
}

TEST_F(InterlocStateChangeTestFixture, InterlocStateChange_Serialize) {
    InterlocStateDTO prevState = InterlocStateDTO::STANDBY;
    InterlocStateDTO newState = InterlocStateDTO::OPERATING;
    InterlocStateChange msg{};

    InterlocStateChangeDTO dto = InterlocStateChangeDTO(prevState, newState);
    auto ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(interlocStateToDTO(msg.previousState), prevState);
    EXPECT_EQ(interlocStateToDTO(msg.newState), newState);
}