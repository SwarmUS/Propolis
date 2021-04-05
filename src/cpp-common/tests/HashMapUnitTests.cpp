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

    ASSERT_TRUE(hashMap.insert(1, "test1"));

    ASSERT_FALSE(hashMap.isEmpty());
    ASSERT_EQ(hashMap.getUsedSpace(), 1);
    ASSERT_EQ(hashMap.getFreeSpace(), 2);
}

TEST_F(HashMapTestFixture, test_insert_and_get) {
    HashMap<uint8_t, std::string, 3> hashMap;

    std::pair<uint8_t, std::string> pair(1, "test1");
    ASSERT_TRUE(hashMap.insert(pair.first, pair.second));

    std::string compare;
    ASSERT_TRUE(hashMap.get(pair.first, compare));
    ASSERT_TRUE(compare == pair.second);

    ASSERT_TRUE(hashMap.at(pair.first).has_value());
    auto val = hashMap.at(pair.first);
    ASSERT_TRUE(val.value().get() == pair.second);
}

TEST_F(HashMapTestFixture, test_insert_and_get_const) {
    HashMap<uint8_t, std::string, 3> hashMap;

    std::pair<uint8_t, std::string> pair(1, "test1");
    ASSERT_TRUE(hashMap.insert(pair.first, pair.second));

    const HashMap<uint8_t, std::string, 3>& constHashMap = hashMap;
    const auto& val = constHashMap.at(pair.first);
    ASSERT_TRUE(val.has_value());
    ASSERT_TRUE(val.value().get() == pair.second);
}

TEST_F(HashMapTestFixture, test_insert_duplicate_key) {
    HashMap<uint8_t, std::string, 3> hashMap;
    std::pair<uint8_t, std::string> pair1(1, "test1");
    ASSERT_TRUE(hashMap.insert(pair1.first, pair1.second));

    ASSERT_FALSE(hashMap.insert(pair1.first, pair1.second));
    ASSERT_EQ(hashMap.getUsedSpace(), 1);

    ASSERT_TRUE(hashMap.upsert(pair1.first, pair1.second));
    ASSERT_EQ(hashMap.getUsedSpace(), 1);
}

TEST_F(HashMapTestFixture, test_insert_duplicate_key_edge_case) {
    HashMap<uint8_t, std::string, 3> hashMap;
    // Fill map
    std::pair<uint8_t, std::string> pair1(1, "test1"); // 1 % 3 = 1
    std::pair<uint8_t, std::string> pair2(2, "test1"); // 2 % 3 = 2
    std::pair<uint8_t, std::string> pair3(4, "test1"); // 4 % 3 = 1 -> collision, will go to index 0

    ASSERT_TRUE(hashMap.insert(pair1.first, pair1.second));
    ASSERT_TRUE(hashMap.insert(pair2.first, pair2.second));
    ASSERT_TRUE(hashMap.insert(pair3.first, pair2.second));

    // Remove entry at index 2
    ASSERT_TRUE(hashMap.remove(pair2.first)); // index 2 now free

    pair1.second = "update value";
    ASSERT_FALSE(
        hashMap.insert(pair1.first, pair1.second)); // Insert should fail since key already present
    ASSERT_TRUE(hashMap.upsert(pair1.first, pair1.second)); // Upsert should succeed
    ASSERT_EQ(hashMap.getUsedSpace(), 2); // Should only be using 2 spaces

    auto val = hashMap.at(pair1.first);
    ASSERT_TRUE(val.has_value());
    ASSERT_EQ(val.value().get(), pair1.second);
}

TEST_F(HashMapTestFixture, test_insert_collision) {
    HashMap<uint8_t, std::string, 3> hashMap;
    std::pair<uint8_t, std::string> pair1(1, "test1"); // 1 % 3 = 1
    ASSERT_TRUE(hashMap.insert(pair1.first, pair1.second));

    std::pair<uint8_t, std::string> pair2(4, "test2"); // 4 % 3 = 1 ->collision
    ASSERT_TRUE(hashMap.insert(pair2.first, pair2.second));

    auto val = hashMap.at(pair2.first);

    ASSERT_TRUE(val.has_value());
    ASSERT_TRUE(val.value().get() == pair2.second);
}

TEST_F(HashMapTestFixture, test_updating_inserted_value) {
    HashMap<uint8_t, std::string, 3> hashMap;
    std::pair<uint8_t, std::string> pair(1, "test1");
    ASSERT_TRUE(hashMap.insert(pair.first, pair.second));

    ASSERT_TRUE(hashMap.at(pair.first).has_value());
    hashMap.at(pair.first).value().get().clear();
    ASSERT_TRUE(hashMap.at(pair.first).value().get().empty());
}

TEST_F(HashMapTestFixture, test_insert_and_remove) {
    HashMap<uint8_t, std::string, 3> hashMap;
    std::pair<uint8_t, std::string> pair1(1, "test1");
    ASSERT_TRUE(hashMap.insert(pair1.first, pair1.second));

    ASSERT_TRUE(hashMap.remove(pair1.first));

    auto val = hashMap.at(pair1.first);
    val.has_value();
}

TEST_F(HashMapTestFixture, test_insert_full) {
    HashMap<uint8_t, std::string, 3> hashMap;

    ASSERT_TRUE(hashMap.insert(1, "test1")); // 1 % 3 = 1

    ASSERT_TRUE(hashMap.insert(2, "test2")); // 1 % 3 = 2

    ASSERT_TRUE(hashMap.insert(3, "test3")); // 1 % 3 = 0

    ASSERT_FALSE(hashMap.insert(4, "test4")); // full

    ASSERT_TRUE(hashMap.isFull());
}

TEST_F(HashMapTestFixture, test_insert_wrapping_keys) {
    HashMap<uint8_t, std::string, 3> hashMap;

    ASSERT_TRUE(hashMap.insert(4, "test1")); // 4 % 3 = 2

    ASSERT_TRUE(hashMap.insert(5, "test2")); // 5 % 3 = 1

    ASSERT_TRUE(hashMap.insert(1, "test3")); // 5 % 3 = 1 -> should go to index 0

    ASSERT_FALSE(hashMap.insert(UINT8_MAX, "test4")); // full
}

TEST_F(HashMapTestFixture, test_insert_full_then_clear) {
    HashMap<uint8_t, std::string, 3> hashMap;

    std::pair<uint8_t, std::string> pair1(1, "test1");
    std::pair<uint8_t, std::string> pair4(4, "test4");
    std::pair<uint8_t, std::string> pair3(3, "test3");
    std::pair<uint8_t, std::string> pair2(2, "test2");

    ASSERT_TRUE(hashMap.insert(pair1.first, pair1.second));
    ASSERT_TRUE(hashMap.insert(pair2.first, pair2.second));
    ASSERT_TRUE(hashMap.insert(pair3.first, pair3.second));
    ASSERT_FALSE(hashMap.insert(pair4.first, pair4.second));

    ASSERT_TRUE(hashMap.isFull());
    hashMap.clear();
    ASSERT_TRUE(hashMap.isEmpty());

    ASSERT_TRUE(hashMap.insert(pair1.first, pair2.second));
    ASSERT_TRUE(hashMap.insert(pair2.first, pair2.second));
    ASSERT_TRUE(hashMap.insert(pair3.first, pair3.second));
    ASSERT_FALSE(hashMap.insert(pair4.first, pair4.second));
}
