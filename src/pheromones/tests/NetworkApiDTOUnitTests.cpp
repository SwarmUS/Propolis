#include <gtest/gtest.h>
#include <pheromones/NetworkApiDTO.h>

class NetworkApiDTOFixture : public testing::Test {
  public:
    NetworkApiDTO* m_networkApiCall;

    void SetUp() override { m_networkApiCall = new NetworkApiDTO(IPDiscoveryDTO(1)); }

    void TearDown() override { delete m_networkApiCall; }
};

TEST_F(NetworkApiDTOFixture, NetworkApiDTO_serialize_succes) {
    // Given
    NetworkAPI apiCall;

    // Then
    bool ret = m_networkApiCall->serialize(apiCall);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(apiCall.which_call, NetworkAPI_ipDiscovery_tag);
}

TEST_F(NetworkApiDTOFixture, NetworkApiDTO_serialize_failure) {
    // Given
    NetworkAPI apiCall;

    // Then
    m_networkApiCall->setAPICall(std::monostate());
    bool ret = m_networkApiCall->serialize(apiCall);

    // Expect
    EXPECT_FALSE(ret);
}