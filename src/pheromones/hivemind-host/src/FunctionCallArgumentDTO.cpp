#include "FunctionCallArgumentDTO.h"

FunctionCallArgumentDTO::FunctionCallArgumentDTO() { m_argument = std::monostate(); }

FunctionCallArgumentDTO::FunctionCallArgumentDTO(const FunctionArgument& argument) {
    switch (argument.which_argument) {

    case FunctionArgument_int_arg_tag:
        m_argument = argument.argument.int_arg;
        break;
    default:
        m_argument = std::monostate();
    }
}

bool FunctionCallArgumentDTO::serialize(FunctionArgument& argument) const {
    if (const int32_t* intArg = std::get_if<int32_t>(&m_argument)) {
        argument.which_argument = FunctionArgument_int_arg_tag;
        argument.argument.int_arg = *intArg;
    }

    return false;
}
