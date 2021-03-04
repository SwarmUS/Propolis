#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <hivemind-host/FunctionDescriptionDTO.h>

class FunctionDescriptionDTOFixture : public testing::Test {
  public:
    FunctionDescriptionDTO* m_desc;
    const char* m_argName = "arg1";
    const FunctionDescriptionArgumentTypeDTO m_argType = FunctionDescriptionArgumentTypeDTO::Int;

    std::string m_functionName = "hello_world";
    std::array<FunctionDescriptionArgumentDTO, 1> m_array = {{{m_argName, m_argType}}};

    void SetUp() override {
        m_desc = new FunctionDescriptionDTO(m_functionName.c_str(), m_array.data(), m_array.size());
    }

    void TearDown() override { delete m_desc; }
};

TEST_F(FunctionDescriptionDTOFixture, FunctionDescriptionDTO_constructor_arrayTooBig) {
    // Given
    const uint16_t arraySize = 2048;
    std::array<FunctionDescriptionArgumentDTO, arraySize> array;

    // Then
    FunctionDescriptionDTO request(m_functionName.c_str(), array.data(), arraySize);

    // Expect
    EXPECT_STREQ(request.getFunctionName(), m_functionName.c_str());
    EXPECT_EQ(request.getArgumentsLength(), FunctionDescriptionDTO::ARGUMENTS_MAX_SIZE);
}

TEST_F(FunctionDescriptionDTOFixture, FunctionDescriptionDTO_constructor_nameTooBig) {
    // Given
    constexpr uint32_t strLength = 2048;
    std::string functionName = randomString(strLength);

    // Then
    FunctionDescriptionDTO request(functionName.c_str(), m_array.data(), m_array.size());

    // Expect
    EXPECT_EQ(strlen(request.getFunctionName()),
              FunctionDescriptionDTO::FUNCTION_NAME_MAX_SIZE - 1);
    EXPECT_EQ(request.getArgumentsLength(), m_array.size());
}

TEST_F(FunctionDescriptionDTOFixture, FunctionDescriptionDTO_serialize_valid) {
    // Given
    FunctionDescription desc;

    // Then
    bool ret = m_desc->serialize(desc);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(desc.arguments_description_count, m_array.size());
    EXPECT_EQ(desc.arguments_description[0].type, dtoToType(m_argType));
    EXPECT_STREQ(desc.arguments_description[0].argument_name, m_argName);
    EXPECT_STREQ(desc.function_name, m_functionName.c_str());
}

TEST_F(FunctionDescriptionDTOFixture, FunctionDescriptionDTO_serialize_invalid) {
    // Given
    FunctionDescription desc;

    // Then
    bool ret = m_desc->serialize(desc);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(desc.arguments_description_count, m_array.size());
    EXPECT_EQ(desc.arguments_description[0].type, dtoToType(m_argType));
    EXPECT_STREQ(desc.arguments_description[0].argument_name, m_argName);
    EXPECT_STREQ(desc.function_name, m_functionName.c_str());
}
