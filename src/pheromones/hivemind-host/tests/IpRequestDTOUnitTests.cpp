#include <gtest/gtest.h>
#include <hivemind-host/IpRequestDTO.h>

class IpRequestDTOFixture : public testing::Test {
  public:
    IPRequestDTO* m_ipRequest;

    void SetUp() override {m_ipRequest = new IPRequestDTO(1); }

    void TearDown() override { delete m_ipRequest; }
};

TEST_F(IpRequestDTOFixture, IpRequest_serialize_valid) {
    // Given
    IPRequest ipRequest;

    // Then
    bool ret = m_ipRequest->serialize(ipRequest);

    // Expect
    EXPECT_TRUE(ret);
}


TEST_F(IpRequestDTOFixture, IpRequest_serialize_failure) {
    // Given
    IPRequest ipRequest;

    // Then
    m_ipRequest->setIP(std::monostate());
    bool ret = m_ipRequest->serialize(ipRequest);

    // Expect
    EXPECT_FALSE(ret);
}