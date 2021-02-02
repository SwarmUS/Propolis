#include <FreeRTOS.h>
#include <chrono>
#include <freertos-utils/AbstractTask.h>
#include <freertos-utils/LockGuard.h>
#include <gtest/gtest.h>
#include <thread>

class MockAbstractTask : public AbstractTask<256> {
  public:
    MockAbstractTask(const char* taskName,
                     UBaseType_t priority,
                     Mutex& mutex,
                     std::chrono::time_point<std::chrono::high_resolution_clock>& getMutexTime) :
        AbstractTask<256>(taskName, priority), m_mutex(mutex), m_getMutexTime(getMutexTime) {}

    ~MockAbstractTask() override = default;

    void task() override {
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

    std::chrono::time_point<std::chrono::high_resolution_clock> m_mainTime;

    std::chrono::time_point<std::chrono::high_resolution_clock> m_taskTime;

    MockAbstractTask* m_task;

    Mutex* m_mutex;

    void SetUp() override {

        m_mutex = new Mutex(UINT32_MAX);

        m_task = new MockAbstractTask("name", 1, *m_mutex, m_taskTime);

        m_thread = std::thread([]() { vTaskStartScheduler(); });
    }

    void TearDown() override {

        vTaskEndScheduler();
        m_thread.join();

        delete m_mutex;

        delete m_task;
    };
};

TEST_F(AbstractTaskIntegrationTests,
       AbstracTaksIntegrationTest_integration_mainAcquireLockBeforeTask) {
    // Given

    // Then
    m_mutex->lock();
    m_task->start();

    m_mainTime = std::chrono::high_resolution_clock::now();
    m_mutex->unlock();

    // Expect
    EXPECT_GT(m_taskTime, m_mainTime);
}
