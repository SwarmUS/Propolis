#include <FreeRTOS.h>
#include <chrono>
#include <freertos-utils/AbstractTask.h>
#include <freertos-utils/LockGuard.h>
#include <gtest/gtest.h>
#include <thread>

class MockAbstractTask : public AbstractTask<256> {
  public:
    MockAbstractTask(Mutex& mutex,
                     std::chrono::time_point<std::chrono::high_resolution_clock>& getMutexTime) :
        m_mutex(mutex), m_getMutexTime(getMutexTime) {}

    void start() {
        m_mutex.lock();
        m_getMutexTime = std::chrono::high_resolution_clock::now();
        m_mutex.unlock();
    }

    Mutex& m_mutex;

    std::chrono::time_point<std::chrono::high_resolution_clock>& m_getMutexTime;
};

class AbstractTaskIntegrationTests : public testing::Test {
  protected:
    std::thread m_thread;
    void SetUp() override {
        m_thread = std::thread([]() { vTaskStartScheduler(); });
    }

    void TearDown() override {}
};

TEST_F(AbstractTaskIntegrationTests,
       AbstracTaksIntegrationTest_integration_mainAcquireLockBeforeTask) {
    // Given
    Mutex mutex(UINT32_MAX);
    std::chrono::time_point<std::chrono::high_resolution_clock> mainTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> taskTime;

    // Then
    mutex.lock();
    MockAbstractTask task(mutex, taskTime);
    task.start();

    mainTime = std::chrono::high_resolution_clock::now();
    mutex.unlock();

    // Expect
    EXPECT_GT(taskTime, mainTime)
}

TEST_F(AbstractTaskIntegrationTests,
       AbstracTaksIntegrationTest_integration_mainAcquireLockBeforeTask3) {
    // Given
    Mutex mutex(UINT32_MAX);
    std::chrono::time_point<std::chrono::high_resolution_clock> mainTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> taskTime;

    // Then
    mutex.lock();
    MockAbstractTask task(mutex, taskTime);
    task.start();

    mainTime = std::chrono::high_resolution_clock::now();
    mutex.unlock();

    // Expect
    EXPECT_GT(taskTime, mainTime)
}
