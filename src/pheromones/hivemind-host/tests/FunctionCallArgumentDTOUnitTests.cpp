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

    // Then
    m_argument.setArgument(42);
    bool ret = m_argument.serialize(argument);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(argument.which_argument, FunctionArgument_int_arg_tag);
    EXPECT_EQ(argument.argument.int_arg, 42);
}
