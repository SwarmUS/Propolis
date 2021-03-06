#include <gtest/gtest.h>
#include <pheromones/UserCallResponseDTO.h>

class UserCallResponseDTOFixture : public testing::Test {
  public:
    static constexpr UserCallTargetDTO gc_src = UserCallTargetDTO::BUZZ;
    static constexpr UserCallTargetDTO gc_dest = UserCallTargetDTO::BUZZ;
    UserCallResponseDTO* m_response;

    void SetUp() override {
        m_response = new UserCallResponseDTO(gc_src, gc_dest,
                                             GenericResponseDTO(GenericResponseStatusDTO::Ok, ""));
    }

    void TearDown() override { delete m_response; }
};

TEST_F(UserCallResponseDTOFixture, UserCallResponseDTO_serialize_Generic_valid) {
    // Given
    UserCallResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.destination, dtoToTarget(gc_dest));
    EXPECT_EQ(resp.which_response, UserCallResponse_generic_tag);
}

TEST_F(UserCallResponseDTOFixture, UserCallResponseDTO_serialize_Funtioncall_valid) {
    // Given
    UserCallResponse resp;
    m_response->setResponse(FunctionCallResponseDTO(GenericResponseStatusDTO::Ok, ""));

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.destination, dtoToTarget(gc_dest));
    EXPECT_EQ(resp.which_response, UserCallResponse_function_call_tag);
}

TEST_F(UserCallResponseDTOFixture, UserCallResponseDTO_serialize_functionList_valid) {
    // Given
    UserCallResponse resp;
    m_response->setResponse(FunctionListLengthResponseDTO(1));

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.destination, dtoToTarget(gc_dest));
    EXPECT_EQ(resp.which_response, UserCallResponse_function_list_length_tag);
}

TEST_F(UserCallResponseDTOFixture, UserCallResponseDTO_serialize_functionDescription_valid) {
    // Given
    UserCallResponse resp;
    m_response->setResponse(
        FunctionDescriptionResponseDTO(GenericResponseDTO(GenericResponseStatusDTO::Ok, "")));

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.destination, dtoToTarget(gc_dest));
    EXPECT_EQ(resp.which_response, UserCallResponse_function_description_tag);
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
