#include <gtest/gtest.h>
#include <pheromones/HiveMindHostApiRequestDTO.h>

class HiveMindHostApiRequestDTOFixture : public testing::Test {
  public:
    HiveMindHostApiRequestDTO* m_request;

    void SetUp() override { m_request = new HiveMindHostApiRequestDTO(HiveMindHostApiRequest{}); }

    void TearDown() override { delete m_request; }
};

TEST_F(HiveMindHostApiRequestDTOFixture, HiveMindHostApiRequestDTO_constructor_bytes) {
    // Given
    HiveMindHostApiRequest req;
    req.which_request = HiveMindHostApiRequest_bytes_tag;

    // Then
    HiveMindHostApiRequestDTO request(req);

    // Expect
    EXPECT_TRUE(std::holds_alternative<BytesDTO>(request.getRequest()));
}

TEST_F(HiveMindHostApiRequestDTOFixture, HiveMindHostApiRequestDTO_constructor_getneighbor) {
    // Given
    HiveMindHostApiRequest req;
    req.which_request = HiveMindHostApiRequest_neighbor_tag;

    // Then
    HiveMindHostApiRequestDTO request(req);

    // Expect
    EXPECT_TRUE(std::holds_alternative<GetNeighborRequestDTO>(request.getRequest()));
}

TEST_F(HiveMindHostApiRequestDTOFixture, HiveMindHostApiRequestDTO_constructor_getneighborslist) {
    // Given
    HiveMindHostApiRequest req;
    req.which_request = HiveMindHostApiRequest_neighbors_list_tag;

    // Then
    HiveMindHostApiRequestDTO request(req);

    // Expect
    EXPECT_TRUE(std::holds_alternative<GetNeighborsListRequestDTO>(request.getRequest()));
}

TEST_F(HiveMindHostApiRequestDTOFixture, HiveMindHostApiRequestDTO_constructor_getAgents) {
    // Given
    HiveMindHostApiRequest req;
    req.which_request = HiveMindHostApiRequest_agents_list_tag;

    // Then
    HiveMindHostApiRequestDTO request(req);

    // Expect
    EXPECT_TRUE(std::holds_alternative<GetAgentsListRequestDTO>(request.getRequest()));
}

TEST_F(HiveMindHostApiRequestDTOFixture, HiveMindHostApiRequestDTO_serialize_bytes_valid) {
    // Given
    HiveMindHostApiRequest req;
    m_request->setRequest(BytesDTO(0, 0, false, NULL, 0));

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.which_request, HiveMindHostApiRequest_bytes_tag);
}

TEST_F(HiveMindHostApiRequestDTOFixture, HiveMindHostApiRequestDTO_serialize_getneighbor_valid) {
    // Given
    HiveMindHostApiRequest req;
    m_request->setRequest(GetNeighborRequestDTO(42));

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.which_request, HiveMindHostApiRequest_neighbor_tag);
}

TEST_F(HiveMindHostApiRequestDTOFixture,
       HiveMindHostApiRequestDTO_serialize_getneighborslist_valid) {
    // Given
    HiveMindHostApiRequest req;
    m_request->setRequest(GetNeighborsListRequest());

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.which_request, HiveMindHostApiRequest_neighbors_list_tag);
}

TEST_F(HiveMindHostApiRequestDTOFixture, HiveMindHostApiRequestDTO_serialize_getAgents_valid) {
    // Given
    HiveMindHostApiRequest req;
    m_request->setRequest(GetAgentsListRequestDTO());

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.which_request, HiveMindHostApiRequest_agents_list_tag);
}

TEST_F(HiveMindHostApiRequestDTOFixture, HiveMindHostApiRequestDTO_serialize_invalid) {
    // Given
    HiveMindHostApiRequest req;

    // Then
    m_request->setRequest(std::monostate());
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_FALSE(ret);
}
