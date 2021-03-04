#include <gtest/gtest.h>
#include <hivemind-host/HiveMindApiRequestDTO.h>

class HiveMindApiRequestDTOFixture : public testing::Test {
  public:
    HiveMindApiRequestDTO* m_request;

    void SetUp() override { m_request = new HiveMindApiRequestDTO(IdRequestDTO()); }

    void TearDown() override { delete m_request; }
};

TEST_F(HiveMindApiRequestDTOFixture, HiveMindApiRequestDTO_serialize_id_valid) {
    // Given
    HiveMindApiRequest req;

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.which_request, HiveMindApiRequest_id_tag);
}

TEST_F(HiveMindApiRequestDTOFixture, HiveMindApiRequestDTO_serialize_invalid) {
    // Given
    HiveMindApiRequest req;

    // Then
    m_request->setRequest(std::monostate());
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_FALSE(ret);
}
