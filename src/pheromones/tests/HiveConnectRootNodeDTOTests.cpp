#include "pheromones/HiveConnectRootNodeDTO.h"
#include <gtest/gtest.h>

class HiveConnectRootNodeDTOTests : public testing::Test {};

TEST_F(HiveConnectRootNodeDTOTests, test_constructor_valid) {
    HiveConnectRootNodeDTO rootNodeDto(true);

    ASSERT_TRUE(rootNodeDto.isRootNode());
}

TEST_F(HiveConnectRootNodeDTOTests, test_constructor_valid_struct) {
    HiveConnectRootNode rootNode;
    rootNode.is_root = true;
    HiveConnectRootNodeDTO rootNodeDto(rootNode);

    ASSERT_TRUE(rootNodeDto.isRootNode());
}

TEST_F(HiveConnectRootNodeDTOTests, test_change_root_noode) {
    HiveConnectRootNodeDTO rootNodeDto(true);

    ASSERT_TRUE(rootNodeDto.isRootNode());

    rootNodeDto.setRootNode(false);

    ASSERT_FALSE(rootNodeDto.isRootNode());
}

TEST_F(HiveConnectRootNodeDTOTests, test_serialize) {
    HiveConnectRootNodeDTO rootNodeDto(true);

    ASSERT_TRUE(rootNodeDto.isRootNode());
    HiveConnectRootNode rootNode;
    ASSERT_TRUE(rootNodeDto.serialize(rootNode));
    ASSERT_EQ(rootNodeDto.isRootNode(), rootNode.is_root);
}
