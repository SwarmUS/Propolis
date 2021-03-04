#include <gtest/gtest.h>
#include <hivemind-host/FunctionDescriptionArgumentTypeDTO.h>

class FunctionDescriptionArgumentTypeDTOFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(FunctionDescriptionArgumentTypeDTOFixture,
       FunctionDescriptionArgumentTypeDTO_typeToDto_int) {
    // Given

    // Then

    FunctionDescriptionArgumentTypeDTO ret = typeToDTO(FunctionDescriptionArgumentType_INT);
    // Expect
    EXPECT_EQ(ret, FunctionDescriptionArgumentTypeDTO::Int);
}

TEST_F(FunctionDescriptionArgumentTypeDTOFixture,
       FunctionDescriptionArgumentTypeDTO_typeToDto_float) {
    // Given

    // Then

    FunctionDescriptionArgumentTypeDTO ret = typeToDTO(FunctionDescriptionArgumentType_FLOAT);
    // Expect
    EXPECT_EQ(ret, FunctionDescriptionArgumentTypeDTO::Float);
}

TEST_F(FunctionDescriptionArgumentTypeDTOFixture,
       FunctionDescriptionArgumentTypeDTO_typeToDto_unknown) {
    // Given

    // Then

    FunctionDescriptionArgumentTypeDTO ret =
        typeToDTO(FunctionDescriptionArgumentType_UNKNOWN_TYPE);
    // Expect
    EXPECT_EQ(ret, FunctionDescriptionArgumentTypeDTO::Unknown);
}

TEST_F(FunctionDescriptionArgumentTypeDTOFixture,
       FunctionDescriptionArgumentTypeDTO_dtoToType_int) {
    // Given

    // Then

    FunctionDescriptionArgumentType ret = dtoToType(FunctionDescriptionArgumentTypeDTO::Int);
    // Expect
    EXPECT_EQ(ret, FunctionDescriptionArgumentType_INT);
}

TEST_F(FunctionDescriptionArgumentTypeDTOFixture,
       FunctionDescriptionArgumentTypeDTO_dtoToType_float) {
    // Given

    // Then

    FunctionDescriptionArgumentType ret = dtoToType(FunctionDescriptionArgumentTypeDTO::Float);
    // Expect
    EXPECT_EQ(ret, FunctionDescriptionArgumentType_FLOAT);
}

TEST_F(FunctionDescriptionArgumentTypeDTOFixture,
       FunctionDescriptionArgumentTypeDTO_dtoToType_Unkown) {
    // Given

    // Then

    FunctionDescriptionArgumentType ret = dtoToType(FunctionDescriptionArgumentTypeDTO::Unknown);
    // Expect
    EXPECT_EQ(ret, FunctionDescriptionArgumentType_UNKNOWN_TYPE);
}
