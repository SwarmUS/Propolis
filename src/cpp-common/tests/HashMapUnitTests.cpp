#include "cpp-common/HashMap.h"
#include <gtest/gtest.h>

class HashMapTestFixture : public testing::Test {};

TEST_F(HashMapTestFixture, test_size) {
    HashMap<uint8_t, std::string, 3> hashMap;
    ASSERT_EQ(hashMap.getMaxSize(), 3);
}

TEST_F(HashMapTestFixture, test_insert) {
    HashMap<uint8_t, std::string, 3> hashMap;

    ASSERT_TRUE(hashMap.isEmpty());

    std::pair<uint8_t, std::string> pair(1, "test1");
    ASSERT_TRUE(hashMap.insert(pair));

    ASSERT_FALSE(hashMap.isEmpty());
}

TEST_F(HashMapTestFixture, test_insert_and_get) {
    HashMap<uint8_t, std::string, 3> hashMap;

    std::pair<uint8_t, std::string> pair(1, "test1");
    ASSERT_TRUE(hashMap.insert(pair));

    std::string compare;
    ASSERT_TRUE(hashMap.get(pair.first, compare));
    ASSERT_TRUE(compare == pair.second);
    std::optional<std::string> val = hashMap.at(pair.first);
    ASSERT_TRUE(val.has_value());
    ASSERT_TRUE(val.value() == pair.second);
}

TEST_F(HashMapTestFixture, test_insert_duplicate_key) {
    HashMap<uint8_t, std::string, 3> hashMap;
    std::pair<uint8_t, std::string> pair1(1, "test1");
    ASSERT_TRUE(hashMap.insert(pair1));
    ASSERT_FALSE(hashMap.insert(pair1));
}

TEST_F(HashMapTestFixture, test_insert_and_remove) {
    HashMap<uint8_t, std::string, 3> hashMap;
    std::pair<uint8_t, std::string> pair1(1, "test1");
    ASSERT_TRUE(hashMap.insert(pair1));

    ASSERT_TRUE(hashMap.remove(pair1.first));

    std::optional<std::string> val = hashMap.at(pair1.first);
    ASSERT_FALSE(val.has_value());
}

TEST_F(HashMapTestFixture, test_insert_full) {
    HashMap<uint8_t, std::string, 3> hashMap;

    std::pair<uint8_t, std::string> pair1(1, "test1"); // 1 % 3 = 1
    ASSERT_TRUE(hashMap.insert(pair1));

    std::pair<uint8_t, std::string> pair2(2, "test2"); // 1 % 3 = 2
    ASSERT_TRUE(hashMap.insert(pair2));

    std::pair<uint8_t, std::string> pair3(3, "test3"); // 1 % 3 = 0
    ASSERT_TRUE(hashMap.insert(pair3));

    std::pair<uint8_t, std::string> pair4(4, "test4"); // full
    ASSERT_FALSE(hashMap.insert(pair4));

    ASSERT_TRUE(hashMap.isFull());
}

TEST_F(HashMapTestFixture, test_insert_wrapping_keys) {
    HashMap<uint8_t, std::string, 3> hashMap;

    std::pair<uint8_t, std::string> pair1(4, "test1"); // 4 % 3 = 2
    ASSERT_TRUE(hashMap.insert(pair1));

    std::pair<uint8_t, std::string> pair2(5, "test2"); // 5 % 3 = 1
    ASSERT_TRUE(hashMap.insert(pair2));

    std::pair<uint8_t, std::string> pair3(1, "test3"); // 5 % 3 = 1 -> should go to index 0
    ASSERT_TRUE(hashMap.insert(pair3));

    std::pair<uint8_t, std::string> pair4(UINT16_MAX, "test4"); // full
    ASSERT_FALSE(hashMap.insert(pair4));
}

TEST_F(HashMapTestFixture, test_insert_full_then_clear) {
    HashMap<uint8_t, std::string, 3> hashMap;

    std::pair<uint8_t, std::string> pair1(1, "test1");
    ASSERT_TRUE(hashMap.insert(pair1));

    std::pair<uint8_t, std::string> pair2(2, "test2");
    ASSERT_TRUE(hashMap.insert(pair2));

    std::pair<uint8_t, std::string> pair3(3, "test3");
    ASSERT_TRUE(hashMap.insert(pair3));

    std::pair<uint8_t, std::string> pair4(4, "test4");
    ASSERT_FALSE(hashMap.insert(pair4));

    ASSERT_TRUE(hashMap.isFull());
    hashMap.clear();
    ASSERT_TRUE(hashMap.isEmpty());

    ASSERT_TRUE(hashMap.insert(pair1));
    ASSERT_TRUE(hashMap.insert(pair2));
    ASSERT_TRUE(hashMap.insert(pair3));
    ASSERT_FALSE(hashMap.insert(pair4));
}
