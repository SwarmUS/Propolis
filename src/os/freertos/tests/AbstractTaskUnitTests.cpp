#include <freertos-utils/AbstractTask.h>
#include <gtest/gtest.h>

class AbstractTaskTest : public AbstractTask<256> {

  public:
    AbstractTaskTest(const char* taskName, UBaseType_t priority) :
        AbstractTask<256>(taskName, priority) {}

    ~AbstractTaskTest() override = default;

    void task() override{};
};

class AbstractTaskUnitTests : public testing::Test {
  protected:
    AbstractTaskTest* m_task;

    void SetUp() override { m_task = new AbstractTaskTest("test_task", 0); }

    void TearDown() override { delete m_task; };
};

TEST_F(AbstractTaskUnitTests, AbstractTaskUnitTests_startTwiceSecondTimeFalse) {
    // Given

    // Then
    bool start = m_task->start();
    bool shouldNotStart = m_task->start();

    // Expect
    EXPECT_TRUE(start);
    EXPECT_FALSE(shouldNotStart);
}
