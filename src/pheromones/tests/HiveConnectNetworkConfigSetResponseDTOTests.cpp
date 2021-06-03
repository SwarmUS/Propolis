#include <gtest/gtest.h>
#include "pheromones/HiveConnectNetworkConfigSetResponseDTO.h"

class HiveConnectNetworkConfigSetResponseDTOTestsFixture : public testing::Test {};

TEST_F(HiveConnectNetworkConfigSetResponseDTOTestsFixture, test_contructor_valid_value) {
    // Given
    GenericResponseDTO responseDto(GenericResponseStatusDTO::Ok, nullptr);
    HiveConnectNetworkConfigSetResponseDTO setResponseDto(GenericResponse);

    // Expect
    ASSERT_EQ(setResponseDto.getResponse(), GenericResponseStatusDTO::Ok);
}