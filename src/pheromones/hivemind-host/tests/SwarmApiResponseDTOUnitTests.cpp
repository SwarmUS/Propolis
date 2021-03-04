#include <gtest/gtest.h>
#include <hivemind-host/SwarmApiResponseDTO.h>

class SwarmApiResponseDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t gc_id = 42;
    SwarmApiResponseDTO* m_response;

    void SetUp() override { m_response = new SwarmApiResponseDTO(IdResponseDTO(gc_id)); }

    void TearDown() override { delete m_response; }
};

TEST_F(SwarmApiResponseDTOFixture, SwarmApiResponseDTO_serialize_id_valid) {
    // Given
    SwarmApiResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.which_response, SwarmApiResponse_id_tag);
}

TEST_F(SwarmApiResponseDTOFixture, SwarmApiResponseDTO_serialize_generic_valid) {
    // Given
    m_response->setResponse(GenericResponseDTO(GenericResponseStatusDTO::Ok, ""));
    SwarmApiResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.which_response, HiveMindApiResponse_generic_tag);
}

TEST_F(SwarmApiResponseDTOFixture, SwarmApiResponseDTO_serialize_invalid) {
    // Given
    SwarmApiResponse resp;

    // Then
    m_response->setResponse(std::monostate());
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_FALSE(ret);
}
