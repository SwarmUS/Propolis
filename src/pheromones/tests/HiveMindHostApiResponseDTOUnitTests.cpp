#include <gtest/gtest.h>
#include <pheromones/HiveMindHostApiResponseDTO.h>

class HiveMindHostApiResponseDTOFixture : public testing::Test {
  public:
    HiveMindHostApiResponseDTO* m_response;

    void SetUp() override {
        m_response = new HiveMindHostApiResponseDTO(GetNeighborsListResponseDTO(NULL, 0));
    }

    void TearDown() override { delete m_response; }
};

TEST_F(HiveMindHostApiResponseDTOFixture, HiveMindHostApiResponseDTO_constructor_getNeighbor) {
    // Given
    HiveMindHostApiResponse resp;
    resp.which_response = HiveMindHostApiResponse_neighbor_tag;

    // Then
    HiveMindHostApiResponseDTO response(resp);

    // Expect
    EXPECT_TRUE(std::holds_alternative<GetNeighborResponseDTO>(response.getResponse()));
}

TEST_F(HiveMindHostApiResponseDTOFixture, HiveMindHostApiResponseDTO_constructor_getNeighborsList) {
    // Given
    HiveMindHostApiResponse resp;
    resp.which_response = HiveMindHostApiResponse_neighbors_list_tag;

    // Then
    HiveMindHostApiResponseDTO response(resp);

    // Expect
    EXPECT_TRUE(std::holds_alternative<GetNeighborsListResponseDTO>(response.getResponse()));
}

TEST_F(HiveMindHostApiResponseDTOFixture, HiveMindHostApiResponseDTO_serialize_getNeighbor_valid) {
    // Given
    NeighborPositionDTO pos(42, 24, true);
    m_response->setResponse(GetNeighborResponseDTO(42, pos));
    HiveMindHostApiResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.which_response, HiveMindHostApiResponse_neighbor_tag);
}

TEST_F(HiveMindHostApiResponseDTOFixture,
       HiveMindHostApiResponseDTO_serialize_getNeighborsList_valid) {
    // Given
    m_response->setResponse(GetNeighborsListResponseDTO(NULL, 0));
    HiveMindHostApiResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.which_response, HiveMindHostApiResponse_neighbors_list_tag);
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
