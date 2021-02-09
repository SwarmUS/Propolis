#include <gtest/gtest.h>
#include <hivemind-host/UserCallResponseDTO.h>

class UserCallResponseDTOFixture : public testing::Test {
  public:
    static constexpr UserCallDestinationDTO gc_dest = UserCallDestinationDTO::BUZZ;
    UserCallResponseDTO* m_response;

    void SetUp() override {
        m_response = new UserCallResponseDTO(
            gc_dest, FunctionCallResponseDTO(GenericResponseStatusDTO::Ok, ""));
    }

    void TearDown() override { delete m_response; }
};

TEST_F(UserCallResponseDTOFixture, UserCallResponseDTO_serialize_valid) {
    // Given
    UserCallResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.destination, dtoToDestination(gc_dest));
    EXPECT_EQ(resp.which_response, UserCallResponse_functionCall_tag);
}

TEST_F(UserCallResponseDTOFixture, UserCallResponseDTO_serialize_invalid) {
    // Given
    UserCallResponse resp;

    // Then
    m_response->setResponse(std::monostate());
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_FALSE(ret);
}
