#include "FunctionCallArgumentDTO.h"

FunctionCallArgumentDTO FunctionCallArgumentDTO::encode(const FunctionArgument& argument) {

    FunctionCallArgumentDTO argumentDTO;
    switch (argument.which_argument) {

    case FunctionArgument_int_arg_tag:
        argumentDTO.m_argument = argument.argument.int_arg;
    }

    return argumentDTO;
}

FunctionCallArgumentDTO::FunctionCallArgumentDTO(const FunctionArgument& argument) {
    switch (argument.which_argument) {

    case FunctionArgument_int_arg_tag:
        m_argument = argument.argument.int_arg;
    }
}
