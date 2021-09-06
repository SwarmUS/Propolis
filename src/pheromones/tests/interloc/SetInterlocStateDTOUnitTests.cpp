#include <gtest/gtest.h>
#include <pheromones/interloc/SetInterlocStateDTO.h>

class SetInterlocStateDTOTestFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(SetInterlocStateDTOTestFixture, SetInterlocStateDTO_deserialize_valid) {
    // Given
    SetInterlocState msg;
    msg.state = InterlocState_STANDBY;
    SetInterlocStateDTO dto = SetInterlocStateDTO(msg);

    // Then
    auto ret = dto.getState();

    // Expect
    EXPECT_EQ(ret, interlocStateToDTO(msg.state));
}

TEST_F(SetInterlocStateDTOTestFixture, SetInterlocStateDTO_fromStateDTO) {
    // Given
    auto state = InterlocStateDTO::STANDBY;
    SetInterlocStateDTO dto = SetInterlocStateDTO(state);

    // Then
    auto ret = dto.getState();

    // Expect
    EXPECT_EQ(ret, state);
}

TEST_F(SetInterlocStateDTOTestFixture, SetInterlocStateDTO_setState) {
    // Given
    auto state1 = InterlocStateDTO::STANDBY;
    auto state2 = InterlocStateDTO::OPERATING;
    SetInterlocStateDTO dto = SetInterlocStateDTO(state1);

    // Then
    dto.setState(state2);
    auto ret = dto.getState();

    // Expect
    EXPECT_EQ(ret, state2);
}

TEST_F(SetInterlocStateDTOTestFixture, SetInterlocStateDTO_serialize_valid) {
    // Given
    SetInterlocState msg;
    auto state = InterlocStateDTO::STANDBY;
    SetInterlocStateDTO dto = SetInterlocStateDTO(state);

    // Then
    auto ret = dto.serialize(msg);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.state, dtoToInterlocState(state));
}
