#include <gtest/gtest.h>
#include <pheromones/HiveMindHostApiRequestDTO.h>

class HiveMindHostApiRequestDTOFixture : public testing::Test {
  public:
    HiveMindHostApiRequestDTO* m_request;

    void SetUp() override { m_request = new HiveMindHostApiRequestDTO(HiveMindHostApiRequest {}); }

    void TearDown() override { delete m_request; }
};

TEST_F(HiveMindHostApiRequestDTOFixture, HiveMindHostApiRequestDTO_serialize_id_valid) {
    // Given
    HiveMindHostApiRequest req;

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.which_request, 0); // TODO: fix
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
