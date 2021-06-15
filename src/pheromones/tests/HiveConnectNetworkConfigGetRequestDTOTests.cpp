#include "pheromones/HiveConnectNetworkConfigGetRequestDTO.h"
#include <gtest/gtest.h>

class HiveConnectNetworkConfigGetRequestDTOTests : public testing::Test {};

TEST_F(HiveConnectNetworkConfigGetRequestDTOTests, serialize) {
    // Given
    HiveConnectNetworkConfigGetRequestDTO getRequestDto;

    // Then
    HiveConnectNetworkConfigGetRequest getRequest;
    ASSERT_TRUE(getRequestDto.serialize(getRequest));
}