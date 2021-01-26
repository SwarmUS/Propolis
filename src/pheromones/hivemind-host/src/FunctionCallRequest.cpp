#include "FunctionCallRequest.h"

std::optional<FunctionCallArgument> FunctionCallRequest::get(uint16_t index) {
    if (index >= m_argumentsLength)
        return {};

    return m_arguments[m_argumentsLength];
}
