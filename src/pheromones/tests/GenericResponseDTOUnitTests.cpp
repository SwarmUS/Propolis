#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <pheromones/GenericResponseDTO.h>

class GenericResponseDTOFixture : public testing::Test {
  public:
    std::string m_details = "hello_world";
    GenericResponseDTO* m_response;

    void SetUp() override {
        m_response = new GenericResponseDTO(GenericResponseStatusDTO::Ok, m_details.c_str());
    }

    void TearDown() override { delete m_response; }
};

TEST_F(GenericResponseDTOFixture, GenericResponseDTO_constructor_stringTooBig) {
    // Given
    std::string longString = randomString(2048);

    // Then
    GenericResponseDTO resp = GenericResponseDTO(GenericResponseStatusDTO::Ok, longString.c_str());

    // Expect
    EXPECT_EQ(strlen(resp.getDetails()), GenericResponseDTO::DETAILS_MAX_LENGTH);
}

TEST_F(GenericResponseDTOFixture, GenericResponseDTO_serialize_ok) {
    // Given
    GenericResponse resp;

    // Then
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.status, GenericResponseStatus_OK);
    EXPECT_STREQ(resp.details, m_details.c_str());
}

TEST_F(GenericResponseDTOFixture, GenericResponseDTO_serialize_err) {
    // Given
    GenericResponse resp;

    // Then
    m_response->setStatus(GenericResponseStatusDTO::Error);
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.status, GenericResponseStatus_Error);
    EXPECT_STREQ(resp.details, m_details.c_str());
}

TEST_F(GenericResponseDTOFixture, GenericResponseDTO_serialize_bad_req) {
    // Given
    GenericResponse resp;

    // Then
    m_response->setStatus(GenericResponseStatusDTO::BadRequest);
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(resp.status, GenericResponseStatus_BAD_REQUEST);
    EXPECT_STREQ(resp.details, m_details.c_str());
}

TEST_F(GenericResponseDTOFixture, GenericResponseDTO_serialize_unknown) {
    // Given
    GenericResponse resp;

    // Then
    m_response->setStatus(GenericResponseStatusDTO::Unknown);
    bool ret = m_response->serialize(resp);

    // Expect
    EXPECT_FALSE(ret);
}
