#include <gtest/gtest.h>
#include <hivemind-host/FunctionDescriptionResponseDTO.h>

class FunctionDescriptionResponseDTOFixture : public testing::Test {
  public:
    FunctionDescriptionResponseDTO* m_response;

    void SetUp() override {
        m_response = new FunctionDescriptionResponseDTO(
            GenericResponseDTO(GenericResponseStatusDTO::Ok, ""));
    }

    void TearDown() override { delete m_response; }
};

TEST_F(FunctionDescriptionResponseDTOFixture,
       FunctionDescriptionResponseDTO_serialize_generic_valid) {
    // Given
    FunctionDescriptionResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.which_response, FunctionDescriptionResponse_generic_tag);
}

TEST_F(FunctionDescriptionResponseDTOFixture,
       FunctionDescriptionResponseDTO_serialize_description_valid) {
    // Given
    m_response->setResponse(FunctionDescriptionDTO("", NULL, 0));
    FunctionDescriptionResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.which_response, FunctionDescriptionResponse_function_description_tag);
}

TEST_F(FunctionDescriptionResponseDTOFixture, FunctionDescriptionResponseDTO_serialize_invalid) {
    // Given
    FunctionDescriptionResponse resp;
    m_response->setResponse(std::monostate());

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_FALSE(ret);
}
