#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <hivemind-host/FunctionDescriptionArgumentDTO.h>

class FunctionDescriptionArgumentDTOFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(FunctionDescriptionArgumentDTOFixture,
       FunctionDescriptionArgumentDTO_constructor_stringTooBig) {
    // Given
    std::string longString = randomString(2048);

    // Then
    FunctionDescriptionArgumentDTO arg(longString.c_str(), FunctionDescriptionArgumentTypeDTO::Int);

    // Expect
    EXPECT_EQ(strlen(arg.getArgumentName()),
              FunctionDescriptionArgumentDTO::FUNCTION_ARGUMENT_NAME_MAX_SIZE - 1);
}

TEST_F(FunctionDescriptionArgumentDTOFixture, FunctionDescriptionArgumentDTO_serialize_valid) {
    // Given
    std::string argName = "intArg";
    FunctionDescriptionArgument arg;
    FunctionDescriptionArgumentDTO argDTO(argName.c_str(), FunctionDescriptionArgumentTypeDTO::Int);

    // Then
    argDTO.serialize(arg);

    // Expect
    EXPECT_STREQ(argName.c_str(), arg.argument_name);
    EXPECT_EQ(arg.type, FunctionDescriptionArgumentType_INT);
}
