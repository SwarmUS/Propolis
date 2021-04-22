#include <gtest/gtest.h>
#include <pheromones/RequestDTO.h>

class RequestDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t gc_id = 42;
    RequestDTO* m_request;

    void SetUp() override {
        m_request = new RequestDTO(
            gc_id, UserCallRequestDTO(UserCallTargetDTO::BUZZ, UserCallTargetDTO::BUZZ,
                                      FunctionCallRequestDTO(NULL, NULL, 0)));
    }

    void TearDown() override { delete m_request; }
};

TEST_F(RequestDTOFixture, RequestDTO_serialize_user_valid) {
    // Given
    Request req;

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.id, gc_id);
    EXPECT_EQ(req.which_message, Request_user_call_tag);
}

TEST_F(RequestDTOFixture, RequestDTO_serialize_hive_valid) {
    // Given
    Request req;
    m_request->setRequest(HiveMindHostApiRequestDTO(BytesDTO(0, 0, false, NULL, 0)));

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.id, gc_id);
    EXPECT_EQ(req.which_message, Request_hivemind_host_tag);
}

TEST_F(RequestDTOFixture, RequestDTO_serialize_invalid) {
    // Given
    Request req;

    // Then
    m_request->setRequest(std::monostate());
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_FALSE(ret);
}
