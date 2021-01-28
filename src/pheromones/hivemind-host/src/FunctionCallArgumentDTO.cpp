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

const std::variant<std::monostate, int32_t>& FunctionCallArgumentDTO::getArgument() const {
    return m_argument;
}
