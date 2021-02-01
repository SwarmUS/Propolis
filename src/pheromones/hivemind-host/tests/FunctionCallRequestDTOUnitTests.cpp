#include "mocks/Utils.h"
#include <gtest/gtest.h>
#include <hivemind-host/FunctionCallRequestDTO.h>

class FunctionCallRequestDTOFixture : public testing::Test {
  public:
    FunctionCallRequestDTO* m_request;

    static constexpr uint16_t gs_ARRAY_SIZE = 1;
    static constexpr uint16_t gs_ARGUMENT_VALUE = 42;
    std::string m_functionName = "hello_world";
    std::array<FunctionCallArgumentDTO, 1> m_array = {{gs_ARGUMENT_VALUE}};

    void SetUp() override {
        m_request =
            new FunctionCallRequestDTO(m_functionName.c_str(), m_array.data(), gs_ARRAY_SIZE);
    }

    void TearDown() override { delete m_request; }
};

TEST_F(FunctionCallRequestDTOFixture, FunctionCallRequestDTO_constructor_arrayTooBig) {
    // Given
    const uint16_t arraySize = 2048;
    std::array<FunctionCallArgumentDTO, arraySize> array;

    // Then
    FunctionCallRequestDTO request(m_functionName.c_str(), array.data(), arraySize);

    // Expect
    EXPECT_STREQ(request.getFunctionName(), m_functionName.c_str());
    EXPECT_EQ(request.getArgumentsLength(),
              FunctionCallRequestDTO::FUNCTION_CALL_ARGUMENTS_MAX_LENGTH);
}

TEST_F(FunctionCallRequestDTOFixture, FunctionCallRequestDTO_constructor_nameTooBig) {
    // Given
    std::string functionName = randomString(2048);

    // Then
    FunctionCallRequestDTO request(functionName.c_str(), m_array.data(), gs_ARRAY_SIZE);

    // Expect
    EXPECT_EQ(strlen(request.getFunctionName()),
              FunctionCallRequestDTO::FUNCTION_CALL_NAME_MAX_LENGTH - 1);
    EXPECT_EQ(request.getArgumentsLength(), gs_ARRAY_SIZE);
}

TEST_F(FunctionCallRequestDTOFixture, FunctionCallRequestDTO_serialize_valid) {
    // Given
    FunctionCallRequest req;

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.arguments_count, gs_ARRAY_SIZE);
    EXPECT_EQ(req.arguments[0].which_argument, FunctionArgument_int_arg_tag);
    EXPECT_EQ(req.arguments[0].argument.int_arg, std::get<int64_t>(m_array[0].getArgument()));
    EXPECT_STREQ(req.function_name, m_functionName.c_str());
}

TEST_F(FunctionCallRequestDTOFixture, FunctionCallRequestDTO_serialize_invalid) {
    // Given
    FunctionCallRequest req;
    const uint16_t arraySize = 1;
    std::array<FunctionCallArgumentDTO, arraySize> array = {{FunctionCallArgumentDTO()}};

    // Then
    m_request->setArguments(array.data(), arraySize);
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_FALSE(ret);
}
