#include <gtest/gtest.h>
#include <hivemind-host/FunctionCallArgumentDTO.h>
#include <variant>

class FunctionCallArgumentDTOFixture : public testing::Test {
  protected:
    FunctionCallArgumentDTO m_argument;

    void SetUp() override {}

    void TearDown() override {}
};

// Regression test for default behavior
TEST_F(FunctionCallArgumentDTOFixture, FunctionCallArgumentDTO_default_constructor) {
    // Given

    // Then
    // Expect
    EXPECT_TRUE(std::holds_alternative<std::monostate>(m_argument.getArgument()));
}

TEST_F(FunctionCallArgumentDTOFixture, FunctionCallArgumentDTO_serialize_invalidMonostate) {
    // Given
    FunctionArgument argument;

    // Then
    bool ret = m_argument.serialize(argument);

    // Expect
    EXPECT_FALSE(ret);
}

TEST_F(FunctionCallArgumentDTOFixture, FunctionCallArgumentDTO_serialize_validIntArgument) {
    // Given
    FunctionArgument argument;
    constexpr int64_t arg = 42;

    // Then
    m_argument.setArgument(arg);
    bool ret = m_argument.serialize(argument);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(argument.which_argument, FunctionArgument_int_arg_tag);
    EXPECT_EQ(argument.argument.int_arg, arg);
}
