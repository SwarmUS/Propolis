#include "FunctionCallRequestDTO.h"
#include <cstring>

FunctionCallRequestDTO::FunctionCallRequestDTO(const FunctionCallRequest& request) {

    strncpy(m_functionName, request.function_name, s_functionNameMaxLength);

    m_argumentsLength = request.arguments_count;

    for (uint16_t i = 0; i < request.arguments_count; i++) {
        m_arguments[i] = FunctionCallArgumentDTO(request.arguments[i]);
    }
}
