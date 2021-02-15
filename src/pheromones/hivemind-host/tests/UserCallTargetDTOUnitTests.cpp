#include <gtest/gtest.h>
#include <hivemind-host/UserCallTargetDTO.h>

class UserCallTargetDTOFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(UserCallTargetDTOFixture, UserCallTargetDTO_dtoToTarget_host) {
    // Given

    // Then
    UserCallTarget ret = dtoToTarget(UserCallTargetDTO::HOST);

    // Expect
    EXPECT_EQ(ret, UserCallTarget_HOST);
}

TEST_F(UserCallTargetDTOFixture, UserCallTargetDTO_dtoToTarget_buzz) {
    // Given

    // Then
    UserCallTarget ret = dtoToTarget(UserCallTargetDTO::BUZZ);

    // Expect
    EXPECT_EQ(ret, UserCallTarget_BUZZ);
}

TEST_F(UserCallTargetDTOFixture, UserCallTargetDTO_dtoToTarget_Unknown) {
    // Given

    // Then
    UserCallTarget ret = dtoToTarget(UserCallTargetDTO::UNKNOWN);

    // Expect
    EXPECT_EQ(ret, UserCallTarget_UNKNOWN);
}

TEST_F(UserCallTargetDTOFixture, UserCallTargetDTO_targetToDTO_host) {
    // Given

    // Then
    UserCallTargetDTO ret = targetToDTO(UserCallTarget_HOST);

    // Expect
    EXPECT_EQ(ret, UserCallTargetDTO::HOST);
}

TEST_F(UserCallTargetDTOFixture, UserCallTargetDTO_targetToDTO_buzz) {
    // Given

    // Then
    UserCallTargetDTO ret = targetToDTO(UserCallTarget_BUZZ);

    // Expect
    EXPECT_EQ(ret, UserCallTargetDTO::BUZZ);
}

TEST_F(UserCallTargetDTOFixture, UserCallTargetDTO_targetToDTO_unknown) {
    // Given

    // Then
    UserCallTargetDTO ret = targetToDTO(UserCallTarget_UNKNOWN);

    // Expect
    EXPECT_EQ(ret, UserCallTargetDTO::UNKNOWN);
}
