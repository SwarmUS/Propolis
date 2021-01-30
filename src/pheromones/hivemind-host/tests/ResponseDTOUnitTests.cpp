#include <gtest/gtest.h>
#include <hivemind-host/ResponseDTO.h>

class ResponseDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t m_id = 42;
    ResponseDTO* m_response;

    void SetUp() override {
        m_response =
            new ResponseDTO(m_id, FunctionCallResponseDTO(GenericResponseStatusDTO::Ok, ""));
    }

    void TearDown() override { delete m_response; }
};

TEST_F(ResponseDTOFixture, ResponseDTO_serialize_valid) {
    // Given
    Response resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.id, m_id);
    EXPECT_EQ(resp.which_message, Request_function_call_tag);
}

TEST_F(ResponseDTOFixture, ResponseDTO_serialize_invalid) {
    // Given
    Response resp;

    // Then
    m_response->setResponse(std::monostate());
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_FALSE(ret);
}
