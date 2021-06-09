#include "pheromones/HiveConnectNetworkConfigSetResponseDTO.h"
#include <gtest/gtest.h>

class HiveConnectNetworkConfigSetResponseDTOTestsFixture : public testing::Test {};

TEST_F(HiveConnectNetworkConfigSetResponseDTOTestsFixture, test_contructor_valid_dto) {
    // Given
    GenericResponseDTO responseDto(GenericResponseStatusDTO::Error, nullptr);
    HiveConnectNetworkConfigSetResponseDTO setResponseDto(responseDto);

    // Expect
    ASSERT_EQ(setResponseDto.getResponse(), GenericResponseStatusDTO::Error);
}

TEST_F(HiveConnectNetworkConfigSetResponseDTOTestsFixture, test_contructor_valid_struct) {
    // Given
    GenericResponse genericResponse;
    genericResponse.status = GenericResponseStatus_BAD_REQUEST;
    HiveConnectNetworkConfigSetResponseDTO setResponseDto(genericResponse);

    // Expect
    ASSERT_EQ(setResponseDto.getResponse(), GenericResponseStatusDTO::BadRequest);
}

TEST_F(HiveConnectNetworkConfigSetResponseDTOTestsFixture, test_serialize_valid) {
    // Given
    GenericResponse genericResponse;
    genericResponse.status = GenericResponseStatus_BAD_REQUEST;
    HiveConnectNetworkConfigSetResponseDTO setResponseDto(genericResponse);

    // Then
    HiveConnectNetworkConfigSetResponse setResponse;
    ASSERT_TRUE(setResponseDto.serialize(setResponse));

    // Expect
    ASSERT_TRUE(setResponse.has_response);
    ASSERT_EQ(setResponse.response.status, genericResponse.status);
    ASSERT_STREQ(setResponse.response.details, genericResponse.details);
}