#include "FunctionCallArgumentDTO.h"

FunctionCallArgumentDTO::FunctionCallArgumentDTO() { m_argument = std::monostate(); }

FunctionCallArgumentDTO::FunctionCallArgumentDTO(int64_t argument) { m_argument = argument; }

FunctionCallArgumentDTO::FunctionCallArgumentDTO(float argument) { m_argument = argument; }

FunctionCallArgumentDTO::FunctionCallArgumentDTO(const FunctionArgument& argument) {
    switch (argument.which_argument) {

    case FunctionArgument_int_arg_tag:
        m_argument = argument.argument.int_arg;
        break;
    case FunctionArgument_float_arg_tag:
        m_argument = argument.argument.float_arg;
        break;
    default:
        m_argument = std::monostate();
    }
}

const std::variant<std::monostate, int64_t, float>& FunctionCallArgumentDTO::getArgument() const {
    return m_argument;
}

void FunctionCallArgumentDTO::setArgument(const std::variant<std::monostate, int64_t, float>& arg) {
    m_argument = arg;
}

bool FunctionCallArgumentDTO::serialize(FunctionArgument& argument) const {
    if (const int64_t* intArg = std::get_if<int64_t>(&m_argument)) {
        argument.which_argument = FunctionArgument_int_arg_tag;
        argument.argument.int_arg = *intArg;
        return true;
    }

    if (const float* floatArg = std::get_if<float>(&m_argument)) {
        argument.which_argument = FunctionArgument_float_arg_tag;
        argument.argument.float_arg = *floatArg;
        return true;
    }

    return false;
}
