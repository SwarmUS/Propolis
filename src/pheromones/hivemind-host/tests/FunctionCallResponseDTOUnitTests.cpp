#include <gtest/gtest.h>
#include <hivemind-host/FunctionCallResponseDTO.h>

class FunctionCallResponseDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t m_id = 42;
    FunctionCallResponseDTO* m_response;

    void SetUp() override {
        m_response = new FunctionCallResponseDTO(GenericResponseStatusDTO::Ok, "");
    }

    void TearDown() override { delete m_response; }
};

TEST_F(FunctionCallResponseDTOFixture, FunctionCallResponseDTO_serialize_valid) {
    // Given
    FunctionCallResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_TRUE(resp.has_response);
}
