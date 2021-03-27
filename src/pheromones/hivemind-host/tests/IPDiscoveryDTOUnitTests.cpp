#include <gtest/gtest.h>
#include <hivemind-host/IpDiscoveryDTO.h>

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

TEST_F(IPDiscoveryDTOFixture, IpDiscovery_serialize_failure) {
    // Given
    IPDiscovery ipDiscovery;

    // Then
    m_ipRequest->setIP(std::monostate());
    bool ret = m_ipRequest->serialize(ipDiscovery);

    // Expect
    EXPECT_FALSE(ret);
}