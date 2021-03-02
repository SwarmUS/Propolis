#include <gtest/gtest.h>
#include <hivemind-host/GreetingDTO.h>

class GreetingDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t gc_id = 42;
    GreetingDTO* m_greeting;

    void SetUp() override { m_greeting = new GreetingDTO(); }

    void TearDown() override { delete m_greeting; }
};

TEST_F(GreetingDTOFixture, ResponseDTO_serialize_Generic_valid) {
    // Given
    Greeting greeting;

    // Then
    bool ret = m_greeting->serialize(greeting);

    // Expect
    EXPECT_TRUE(ret);
}
