#include <gtest/gtest.h>
#include <hivemind-host/SwarmApiRequestDTO.h>

class SwarmApiRequestDTOFixture : public testing::Test {
  public:
    SwarmApiRequestDTO* m_request;

    void SetUp() override { m_request = new SwarmApiRequestDTO(IdRequestDTO()); }

    void TearDown() override { delete m_request; }
};

TEST_F(SwarmApiRequestDTOFixture, SwarmApiRequestDTO_serialize_id_valid) {
    // Given
    SwarmApiRequest req;

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.which_request, SwarmApiRequest_id_tag);
}

TEST_F(SwarmApiRequestDTOFixture, SwarmApiRequestDTO_serialize_invalid) {
    // Given
    SwarmApiRequest req;

    // Then
    m_request->setRequest(std::monostate());
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_FALSE(ret);
}
