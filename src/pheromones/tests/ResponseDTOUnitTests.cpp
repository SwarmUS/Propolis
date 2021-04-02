#include <gtest/gtest.h>
#include <pheromones/ResponseDTO.h>

class ResponseDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t gc_id = 42;
    ResponseDTO* m_response;

    void SetUp() override {
        m_response = new ResponseDTO(gc_id, GenericResponseDTO(GenericResponseStatusDTO::Ok, ""));
    }

    void TearDown() override { delete m_response; }
};

TEST_F(ResponseDTOFixture, ResponseDTO_serialize_Generic_valid) {
    // Given
    Response resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.id, gc_id);
    EXPECT_EQ(resp.which_message, Response_generic_tag);
}

TEST_F(ResponseDTOFixture, ResponseDTO_serialize_UserCall_valid) {
    // Given
    Response resp;
    m_response->setResponse(
        UserCallResponseDTO(UserCallTargetDTO::BUZZ, UserCallTargetDTO::BUZZ,
                            FunctionCallResponseDTO(GenericResponseStatusDTO::Ok, "")));

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.id, gc_id);
    EXPECT_EQ(resp.which_message, Response_user_call_tag);
}

TEST_F(ResponseDTOFixture, ResponseDTO_serialize_HiveMindAPI_valid) {
    // Given
    Response resp;
    m_response->setResponse(
        HiveMindHostApiResponseDTO(GenericResponseDTO(GenericResponseStatusDTO::Ok, "")));

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.id, gc_id);
    EXPECT_EQ(resp.which_message, Response_hive_api_tag);
}

TEST_F(ResponseDTOFixture, ResponseDTO_serialize_invalid) {
    // Given
    Response resp;
    m_response->setResponse(std::monostate());

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_FALSE(ret);
}
