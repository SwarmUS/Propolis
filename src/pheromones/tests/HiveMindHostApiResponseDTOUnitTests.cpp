#include <gtest/gtest.h>
#include <pheromones/HiveMindHostApiResponseDTO.h>

class HiveMindHostApiResponseDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t gc_id = 42;
    HiveMindHostApiResponseDTO* m_response;

    void SetUp() override { m_response = new HiveMindHostApiResponseDTO(GenericResponseDTO(GenericResponseStatusDTO::Ok, "")); }

    void TearDown() override { delete m_response; }
};

TEST_F(HiveMindHostApiResponseDTOFixture, HiveMindHostApiResponseDTO_serialize_generic_valid) {
    // Given
    m_response->setResponse(GenericResponseDTO(GenericResponseStatusDTO::Ok, ""));
    HiveMindHostApiResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.which_response, HiveMindHostApiResponse_generic_tag);
}

TEST_F(HiveMindHostApiResponseDTOFixture, HiveMindHostApiResponseDTO_serialize_invalid) {
    // Given
    HiveMindHostApiResponse resp;

    // Then
    m_response->setResponse(std::monostate());
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_FALSE(ret);
}
