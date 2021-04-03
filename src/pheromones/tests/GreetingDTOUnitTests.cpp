#include <gtest/gtest.h>
#include <pheromones/GreetingDTO.h>

class GreetingDTOFixture : public testing::Test {
  public:
    static constexpr uint32_t gc_id = 42;
    GreetingDTO* m_greeting;

    void SetUp() override { m_greeting = new GreetingDTO(gc_id); }

    void TearDown() override { delete m_greeting; }
};

TEST_F(GreetingDTOFixture, GreetingDTO_serialize_valid) {
    // Given
    Greeting greeting;

    // Then
    bool ret = m_greeting->serialize(greeting);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(greeting.id, gc_id);
}
