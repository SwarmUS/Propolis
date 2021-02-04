#include <freertos-utils/AbstractTask.h>
#include <freertos-utils/BaseTask.h>
#include <freertos-utils/Mutex.h>
#include <gtest/gtest.h>

class MutexUnitTests : public testing::Test {
  protected:
    Mutex* m_mutex;

    void SetUp() override { m_mutex = new Mutex(0); }

    void TearDown() override { delete m_mutex; };
};

TEST_F(MutexUnitTests, MutexUnitTests_lockAcquisitionSequence) {
    // Given

    // Then
    bool lock = m_mutex->lock();
    bool lockAfterLock = m_mutex->lock();
    bool unlock = m_mutex->unlock();
    bool relock = m_mutex->lock();
    bool finalUnlock = m_mutex->unlock();

    // Expect
    EXPECT_TRUE(lock);
    EXPECT_FALSE(lockAfterLock);
    EXPECT_TRUE(unlock);
    EXPECT_TRUE(relock);
    EXPECT_TRUE(finalUnlock);
}
