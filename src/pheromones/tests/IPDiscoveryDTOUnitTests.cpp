#include <gtest/gtest.h>
#include <pheromones/IpDiscoveryDTO.h>

class IPDiscoveryDTOFixture : public testing::Test {
  public:
    IPDiscoveryDTO* m_ipRequest;

    void SetUp() override { m_ipRequest = new IPDiscoveryDTO(1); }

    void TearDown() override { delete m_ipRequest; }
};

TEST_F(IPDiscoveryDTOFixture, IpDiscovery_serialize_valid) {
    // Given
    IPDiscovery ipDiscovery;

    // Then
    bool ret = m_ipRequest->serialize(ipDiscovery);

    // Expect
    EXPECT_TRUE(ret);
}
