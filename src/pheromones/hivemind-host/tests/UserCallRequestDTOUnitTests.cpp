#include <gtest/gtest.h>
#include <hivemind-host/UserCallRequestDTO.h>

class UserCallRequestDTOFixture : public testing::Test {
  public:
    static constexpr UserCallDestinationDTO gc_dest = UserCallDestinationDTO::BUZZ;
    UserCallRequestDTO* m_request;

    void SetUp() override {
        m_request = new UserCallRequestDTO(gc_dest, FunctionCallRequestDTO(NULL, NULL, 0));
    }

    void TearDown() override { delete m_request; }
};

TEST_F(UserCallRequestDTOFixture, UserCallRequestDTO_serialize_valid) {
    // Given
    UserCallRequest req;

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.destination, dtoToDestination(gc_dest));
    EXPECT_EQ(req.which_request, UserCallRequest_functionCall_tag);
}

TEST_F(UserCallRequestDTOFixture, UserCallRequestDTO_serialize_invalid) {
    // Given
    UserCallRequest req;

    // Then
    m_request->setRequest(std::monostate());
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_FALSE(ret);
}
