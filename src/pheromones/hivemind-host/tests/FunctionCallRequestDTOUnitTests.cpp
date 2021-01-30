#include <gtest/gtest.h>
#include <hivemind-host/FunctionCallRequestDTO.h>

// https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
std::string randomString(size_t length) {
    auto randchar = []() -> char {
        const char charset[] = "0123456789"
                               "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                               "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[(unsigned long)rand() % max_index];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}

class FunctionCallRequestDTOFixture : public testing::Test {
  public:
    FunctionCallRequestDTO* m_request;

    static constexpr uint16_t m_arraySize = 1;
    std::string m_functionName = "hello_world";
    std::array<FunctionCallArgumentDTO, 1> m_array = {{42}};

    void SetUp() override {
        m_request = new FunctionCallRequestDTO(m_functionName.c_str(), m_array.data(), m_arraySize);
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
    EXPECT_EQ(request.getArgumentsLength(), FUNCTION_CALL_ARGUMENTS_MAX_LENGTH);
}

TEST_F(FunctionCallRequestDTOFixture, FunctionCallRequestDTO_constructor_nameTooBig) {
    // Given
    std::string functionName = randomString(2048);

    // Then
    FunctionCallRequestDTO request(functionName.c_str(), m_array.data(), m_arraySize);

    // Expect
    EXPECT_EQ(strlen(request.getFunctionName()), FUNCTION_CALL_NAME_MAX_LENGTH-1);
    EXPECT_EQ(request.getArgumentsLength(), m_arraySize);
}

TEST_F(FunctionCallRequestDTOFixture, FunctionCallRequestDTO_serialize_valid) {
    // Given
    FunctionCallRequest req;

    // Then
    bool ret = m_request->serialize(req);

    // Expect
    EXPECT_TRUE(ret);
    EXPECT_EQ(req.arguments_count, m_arraySize);
    EXPECT_EQ(req.arguments[0].which_argument, FunctionArgument_int_arg_tag);
    EXPECT_EQ(req.arguments[0].argument.int_arg, std::get<int32_t>(m_array[0].getArgument()));
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
