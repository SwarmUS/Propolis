#include "pheromones/HiveConnectMeshEnableDTO.h"
#include <gtest/gtest.h>

class HiveConnectMeshEnableDTOTests : public testing::Test {};

TEST_F(HiveConnectMeshEnableDTOTests, test_constructor_valid) {
    HiveConnectMeshEnableDTO meshEnableDTO(true);

    ASSERT_TRUE(meshEnableDTO.isMeshEnabled());
}

TEST_F(HiveConnectMeshEnableDTOTests, test_constructor_valid_struct) {
    HiveConnectMeshEnable meshEnable;
    meshEnable.use_mesh = true;
    HiveConnectMeshEnableDTO meshEnableDto(meshEnable);

    ASSERT_TRUE(meshEnableDto.isMeshEnabled());
}

TEST_F(HiveConnectMeshEnableDTOTests, test_change_flag) {
    HiveConnectMeshEnableDTO meshEnableDTO(true);

    ASSERT_TRUE(meshEnableDTO.isMeshEnabled());

    meshEnableDTO.setMeshEnable(false);

    ASSERT_FALSE(meshEnableDTO.isMeshEnabled());
}

TEST_F(HiveConnectMeshEnableDTOTests, test_serialize) {
    HiveConnectMeshEnableDTO meshEnableDTO(true);

    ASSERT_TRUE(meshEnableDTO.isMeshEnabled());
    HiveConnectMeshEnable meshEnable;
    ASSERT_TRUE(meshEnableDTO.serialize(meshEnable));
    ASSERT_EQ(meshEnableDTO.isMeshEnabled(), meshEnable.use_mesh);
}
