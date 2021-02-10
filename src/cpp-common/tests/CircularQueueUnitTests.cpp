
#include <cpp-common/CircularQueue.h>
#include <gtest/gtest.h>

static const uint8_t gc_size = 8;

class BasicDestructor {
  public:
    BasicDestructor(int value = 0, bool* destructorCalled = NULL) :
        m_destructorCalled(destructorCalled), m_value(value) {}

    ~BasicDestructor() {
        if (m_destructorCalled != NULL) {
            *m_destructorCalled = true;
        }
    }

    bool operator==(const BasicDestructor& rhs) const { return m_value == rhs.m_value; }

    bool* m_destructorCalled;
    int m_value;
};

bool operator==(const BasicDestructor& lhs, const BasicDestructor& rhs) {
    return lhs.m_value == rhs.m_value;
}
bool operator==(const BasicDestructor& lhs, const int rhs) { return lhs.m_value == rhs; }

class CircularQueueFixture : public testing::Test {

  public:
    std::array<BasicDestructor, gc_size + 1> m_data;

    CircularQueue<BasicDestructor>* m_circularQueue;

    void SetUp() override {
        m_circularQueue = new CircularQueue<BasicDestructor>(m_data.data(), gc_size);
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

TEST_F(CircularQueueFixture, CircularQueue_pop_withData_destructorCalled) {
    // Given

    // Then
    bool destructorCalled = false;
    m_circularQueue->push({42, &destructorCalled});
    m_circularQueue->pop();

    // Expect
    EXPECT_EQ(m_circularQueue->getLength(), 0);
    EXPECT_TRUE(destructorCalled);
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

TEST_F(CircularQueueFixture, CircularQueue_clear_data_destructorCalled) {
    // Given

    // Then
    bool destructorCalled1 = false;
    bool destructorCalled2 = false;
    m_circularQueue->push({42, &destructorCalled1});
    m_circularQueue->push({43, &destructorCalled2});

    m_circularQueue->clear();

    // Expect
    EXPECT_EQ(m_circularQueue->getLength(), 0);
    EXPECT_TRUE(destructorCalled1);
    EXPECT_TRUE(destructorCalled2);
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

TEST_F(CircularQueueFixture, CircularQueue_getNextAllocation_empty) {
    // Given

    // Then

    auto ret = m_circularQueue->getNextAllocation();

    // Expect
    EXPECT_TRUE(ret.operator bool());
    EXPECT_EQ(ret.value(), 0);

    // Verify that we get the reference and it changes it in the buffer
    ret.value().get().m_value = 42;
    EXPECT_EQ(m_data[0], 42);
}

TEST_F(CircularQueueFixture, CircularQueue_getNextAllocation_full) {
    // Given

    // Then

    for (uint8_t i = 0; i < gc_size; i++) {
        m_circularQueue->push(i);
    }
    auto ret = m_circularQueue->getNextAllocation();

    // Expect
    EXPECT_FALSE(ret.operator bool());
}

TEST_F(CircularQueueFixture, CircularQueue_advance_empty) {
    // Given

    // Then

    bool ret = m_circularQueue->advance();

    // Expect
    EXPECT_TRUE(ret);
}

TEST_F(CircularQueueFixture, CircularQueue_advance_full) {
    // Given

    // Then
    for (uint8_t i = 0; i < gc_size; i++) {
        m_circularQueue->push(i);
    }
    bool ret = m_circularQueue->advance();

    // Expect
    EXPECT_FALSE(ret);
}
