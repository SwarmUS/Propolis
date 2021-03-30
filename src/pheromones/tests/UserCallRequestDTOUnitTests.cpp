#include <gtest/gtest.h>
#include <pheromones/UserCallRequestDTO.h>

class UserCallRequestDTOFixture : public testing::Test {
  public:
    static constexpr UserCallTargetDTO gc_src = UserCallTargetDTO::BUZZ;
    static constexpr UserCallTargetDTO gc_dest = UserCallTargetDTO::BUZZ;
    UserCallRequestDTO* m_request;

    void SetUp() override {
        m_request = new UserCallRequestDTO(gc_src, gc_dest, FunctionCallRequestDTO(NULL, NULL, 0));
    }

    void TearDown() override { delete m_request; }
};

TEST_F(UserCallRequestDTOFixture, UserCallRequestDTO_serialize_functionCall_valid) {
    // Given
    UserCallRequest req;

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.source, dtoToTarget(gc_src));
    EXPECT_EQ(req.destination, dtoToTarget(gc_dest));
    EXPECT_EQ(req.which_request, UserCallRequest_function_call_tag);
}

TEST_F(UserCallRequestDTOFixture, UserCallRequestDTO_serialize_functionListLength_valid) {
    // Given
    UserCallRequest req;
    m_request->setRequest(FunctionListLengthRequestDTO());

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.source, dtoToTarget(gc_src));
    EXPECT_EQ(req.destination, dtoToTarget(gc_dest));
    EXPECT_EQ(req.which_request, UserCallRequest_function_list_length_tag);
}

TEST_F(UserCallRequestDTOFixture, UserCallRequestDTO_serialize_functionDescription_valid) {
    // Given
    UserCallRequest req;
    m_request->setRequest(FunctionDescriptionRequestDTO(42));

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.source, dtoToTarget(gc_src));
    EXPECT_EQ(req.destination, dtoToTarget(gc_dest));
    EXPECT_EQ(req.which_request, UserCallRequest_function_description_tag);
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
