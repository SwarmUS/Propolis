#include <cpp-common/HashMapStack.h>
#include <gtest/gtest.h>

static const uint8_t gc_size = 8;

class HashMapStackFixture : public testing::Test {

  public:
    HashMapStack<int, int, gc_size> m_hashMap;

    void SetUp() override {}

    void TearDown() override {}
};

// Mainly verifies that we can instanciate it and don't cause a segfault
TEST_F(HashMapStackFixture, HashMapStack_noSegFault) {
    // Given

    // Then

    for (int i = 0; i < gc_size; i++) {
        EXPECT_TRUE(m_hashMap.insert(i, i));
    }
    // Write once more than possible
    EXPECT_FALSE(m_hashMap.insert(gc_size, gc_size));

    for (int i = 0; i < gc_size; i++) {
        m_hashMap.remove(i);
    }
}
