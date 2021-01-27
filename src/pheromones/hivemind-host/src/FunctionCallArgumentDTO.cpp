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
