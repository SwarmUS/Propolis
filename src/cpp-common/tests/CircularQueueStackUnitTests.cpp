
#include <cpp-common/CircularQueueStack.h>
#include <gtest/gtest.h>

static const uint8_t gc_size = 8;

class CircularQueueStackFixture : public testing::Test {

  public:
    CircularQueueStack<int, gc_size> m_circularQueue;

    void SetUp() override {}

    void TearDown() override {}
};

// Mainly verifies that we can instanciate it and don't cause a segfault
TEST_F(CircularQueueStackFixture, CircularQueue_clear_noData) {
    // Given

    // Then

    for (int i = 0; i < gc_size; i++) {
        m_circularQueue.push(i);
    }
    // Write once more than possible
    bool ret = m_circularQueue.push(gc_size);

    // Expect
    EXPECT_FALSE(ret);

    //
    for (int i = 0; i < gc_size; i++) {
        EXPECT_EQ(m_circularQueue.peek(), i);
        m_circularQueue.pop();
    }
}
