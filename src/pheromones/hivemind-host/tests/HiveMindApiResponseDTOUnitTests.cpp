#include <gtest/gtest.h>
#include <hivemind-host/HiveMindApiResponseDTO.h>

class HiveMindApiResponseDTOFixture : public testing::Test {
  public:
    static constexpr UserCallTargetDTO gc_dest = UserCallTargetDTO::BUZZ;
    static constexpr uint32_t gc_id = 42;
    HiveMindApiResponseDTO* m_response;

    void SetUp() override {
        m_response = new HiveMindApiResponseDTO(gc_dest, IdResponseDTO(gc_id));
    }

    void TearDown() override { delete m_response; }
};

TEST_F(HiveMindApiResponseDTOFixture, HiveMindApiResponseDTO_serialize_id_valid) {
    // Given
    HiveMindApiResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.destination, dtoToTarget(gc_dest));
    EXPECT_EQ(resp.which_response, HiveMindApiResponse_id_tag);
}

TEST_F(HiveMindApiResponseDTOFixture, HiveMindApiResponseDTO_serialize_invalid) {
    // Given
    HiveMindApiResponse resp;

    // Then
    m_response->setResponse(std::monostate());
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_FALSE(ret);
}
