#include <gtest/gtest.h>
#include <hivemind-host/UserCallDestinationDTO.h>

class UserCallDestinationDTOFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(UserCallDestinationDTOFixture, UserCallDestinationDTO_dtoToDestination_host) {
    // Given

    // Then
    UserCallDestination ret = dtoToDestination(UserCallDestinationDTO::HOST);

    // Expect
    EXPECT_EQ(ret, UserCallDestination_HOST);
}

TEST_F(UserCallDestinationDTOFixture, UserCallDestinationDTO_dtoToDestination_buzz) {
    // Given

    // Then
    UserCallDestination ret = dtoToDestination(UserCallDestinationDTO::BUZZ);

    // Expect
    EXPECT_EQ(ret, UserCallDestination_BUZZ);
}

TEST_F(UserCallDestinationDTOFixture, UserCallDestinationDTO_dtoToDestination_Unknown) {
    // Given

    // Then
    UserCallDestination ret = dtoToDestination(UserCallDestinationDTO::UNKNOWN);

    // Expect
    EXPECT_EQ(ret, UserCallDestination_UNKNOWN);
}

TEST_F(UserCallDestinationDTOFixture, UserCallDestinationDTO_destinationToDTO_host) {
    // Given

    // Then
    UserCallDestinationDTO ret = destinationToDTO(UserCallDestination_HOST);

    // Expect
    EXPECT_EQ(ret, UserCallDestinationDTO::HOST);
}

TEST_F(UserCallDestinationDTOFixture, UserCallDestinationDTO_destinationToDTO_buzz) {
    // Given

    // Then
    UserCallDestinationDTO ret = destinationToDTO(UserCallDestination_BUZZ);

    // Expect
    EXPECT_EQ(ret, UserCallDestinationDTO::BUZZ);
}

TEST_F(UserCallDestinationDTOFixture, UserCallDestinationDTO_destinationToDTO_unknown) {
    // Given

    // Then
    UserCallDestinationDTO ret = destinationToDTO(UserCallDestination_UNKNOWN);

    // Expect
    EXPECT_EQ(ret, UserCallDestinationDTO::UNKNOWN);
}
