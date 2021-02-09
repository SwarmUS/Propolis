
#include <cpp-common/CircularQueue.h>
#include <gtest/gtest.h>

static const uint8_t gc_size = 8;

class CircularQueueFixture : public testing::Test {

  public:
    uint8_t m_data[gc_size + 1];

    CircularQueue<uint8_t>* m_circularQueue;

    void SetUp() override {
        memset(m_data, 0, gc_size + 1);
        m_circularQueue = new CircularQueue<uint8_t>(m_data, gc_size);
    }

    void TearDown() override { delete m_circularQueue; }
};

TEST_F(CircularQueueFixture, CircularQueue_push_success) {
    // Given

    // Then
    bool ret = m_circularQueue->push(1);

    // Expect
    EXPECT_TRUE(ret);
}

TEST_F(CircularQueueFixture, CircularQueue_push_fail) {
    // Given

    // Then
    for (uint8_t i = 0; i < gc_size; i++) {
        m_circularQueue->push(1);
    }

    // Expect
    EXPECT_FALSE(m_circularQueue->push(1));
}

TEST_F(CircularQueueFixture, CircularQueue_push_moreThanPossible) {
    // Given

    // Then
    for (uint8_t i = 0; i < 2 * gc_size; i++) {
        m_circularQueue->push(i);
    }

    // Expect
    EXPECT_EQ(m_data[gc_size], 0);
    EXPECT_EQ(m_circularQueue->getLength(), 8);
}

TEST_F(CircularQueueFixture, CircularQueue_pop_noData) {
    // Given

    // Then

    m_circularQueue->pop();

    // Expect
    EXPECT_EQ(m_circularQueue->getLength(), 0);
}

TEST_F(CircularQueueFixture, CircularQueue_pop_withData) {
    // Given

    // Then

    for (uint8_t i = 0; i < gc_size; i++) {
        m_circularQueue->push(i);
    }
    m_circularQueue->pop();

    // Expect
    EXPECT_EQ(m_circularQueue->getLength(), gc_size - 1);
}

TEST_F(CircularQueueFixture, CircularQueue_get_empty) {
    // Given

    // Then
    std::optional<uint8_t> ret = m_circularQueue->get();

    // Expect
    EXPECT_FALSE(ret.operator bool());
    EXPECT_EQ(m_circularQueue->getLength(), 0);
}

TEST_F(CircularQueueFixture, CircularQueue_get_withData) {
    // Given

    // Then

    for (uint8_t i = 0; i < gc_size; i++) {
        m_circularQueue->push(i + 42);
    }

    std::optional<uint8_t> ret = m_circularQueue->get();

    // Expect
    EXPECT_EQ(m_circularQueue->getLength(), 7);
    EXPECT_TRUE(ret.operator bool());
    EXPECT_EQ(ret.value(), 42);

    m_circularQueue->get();
    EXPECT_EQ(m_circularQueue->getLength(), 6);
}

TEST_F(CircularQueueFixture, CircularQueue_clear_noData) {
    // Given

    // Then
    m_circularQueue->clear();

    // Expect
    EXPECT_EQ(m_circularQueue->getLength(), 0);
}

TEST_F(CircularQueueFixture, CircularQueue_clear_data) {
    // Given

    // Then
    for (uint8_t i = 0; i < gc_size; i++) {
        m_circularQueue->push(i);
    }

    m_circularQueue->clear();

    // Expect
    EXPECT_EQ(m_circularQueue->getLength(), 0);
}

TEST_F(CircularQueueFixture, CircularQueue_peek_noData) {
    // Given

    // Then

    auto ret = m_circularQueue->peek();

    // Expect
    EXPECT_FALSE(ret.operator bool());
}

TEST_F(CircularQueueFixture, CircularQueue_peek_withData) {
    // Given

    // Then

    for (uint8_t i = 0; i < gc_size; i++) {
        m_circularQueue->push(i + 42);
    }
    auto ret = m_circularQueue->peek();

    // Expect
    EXPECT_EQ(m_circularQueue->getLength(), gc_size);
    EXPECT_TRUE(ret.operator bool());
    EXPECT_EQ(ret.value(), 42);
    EXPECT_EQ(m_circularQueue->getLength(), gc_size);
}

TEST_F(CircularQueueFixture, CircularQueue_isFull_noData) {
    // Given

    // Then

    bool ret = m_circularQueue->isFull();

    // Expect
    EXPECT_FALSE(ret);
}

TEST_F(CircularQueueFixture, CircularQueue_isFull_someData) {
    // Given

    // Then

    for (uint8_t i = 0; i < gc_size / 2; i++) {
        m_circularQueue->push(i);
    }
    bool ret = m_circularQueue->isFull();

    // Expect
    EXPECT_FALSE(ret);
}

TEST_F(CircularQueueFixture, CircularQueue_isFull_full) {
    // Given

    // Then

    for (uint8_t i = 0; i < gc_size; i++) {
        m_circularQueue->push(i);
    }
    auto ret = m_circularQueue->isFull();

    // Expect
    EXPECT_TRUE(ret);
}

TEST_F(CircularQueueFixture, CircularQueue_isEmpty_noData) {
    // Given

    // Then

    bool ret = m_circularQueue->isEmpty();

    // Expect
    EXPECT_TRUE(ret);
}

TEST_F(CircularQueueFixture, CircularQueue_isEmpty_someData) {
    // Given

    // Then

    for (uint8_t i = 0; i < gc_size / 2; i++) {
        m_circularQueue->push(i);
    }
    bool ret = m_circularQueue->isEmpty();

    // Expect
    EXPECT_FALSE(ret);
}

TEST_F(CircularQueueFixture, CircularQueue_isEmpty_full) {
    // Given

    // Then

    for (uint8_t i = 0; i < gc_size; i++) {
        m_circularQueue->push(i);
    }
    auto ret = m_circularQueue->isEmpty();

    // Expect
    EXPECT_FALSE(ret);
}

TEST_F(CircularQueueFixture, CircularQueue_getLength_noData) {
    // Given

    // Then

    uint8_t ret = m_circularQueue->getLength();

    // Expect
    EXPECT_EQ(ret, 0);
}

TEST_F(CircularQueueFixture, CircularQueue_getLength_someData) {
    // Given
    uint8_t len = (int)(gc_size / 2);
    // Then

    for (uint8_t i = 0; i < len; i++) {
        m_circularQueue->push(i);
    }
    uint8_t ret = m_circularQueue->getLength();

    // Expect
    EXPECT_EQ(ret, len);
}

TEST_F(CircularQueueFixture, CircularQueue_getLength_full) {
    // Given

    // Then

    for (uint8_t i = 0; i < gc_size; i++) {
        m_circularQueue->push(i);
    }
    uint8_t ret = m_circularQueue->getLength();

    // Expect
    EXPECT_EQ(ret, gc_size);
}

TEST_F(CircularQueueFixture, CircularQueue_getFreeSize_noData) {
    // Given

    // Then

    uint8_t ret = m_circularQueue->getFreeSize();

    // Expect
    EXPECT_EQ(ret, gc_size);
}

TEST_F(CircularQueueFixture, CircularQueue_getFreeSize_someData) {
    // Given
    uint8_t len = (int)(gc_size / 2);
    // Then

    for (uint8_t i = 0; i < len; i++) {
        m_circularQueue->push(i);
    }
    uint8_t ret = m_circularQueue->getFreeSize();

    // Expect
    EXPECT_EQ(ret, gc_size - len);
}

TEST_F(CircularQueueFixture, CircularQueue_getFreeSize_full) {
    // Given

    // Then

    for (uint8_t i = 0; i < gc_size; i++) {
        m_circularQueue->push(i);
    }
    uint8_t ret = m_circularQueue->getFreeSize();

    // Expect
    EXPECT_EQ(ret, 0);
}
