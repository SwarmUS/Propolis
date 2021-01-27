#include "FunctionCallRequestDTO.h"
#include <cstring>

FunctionCallRequestDTO FunctionCallRequestDTO::encode(const FunctionCallRequest& request) {

    FunctionCallRequestDTO functionCallRequestDTO;

    strcpy(functionCallRequestDTO.m_functionName, request.function_name);

    functionCallRequestDTO.m_argumentsLength = request.arguments_count;

    for (uint16_t i = 0; i < functionCallRequestDTO.m_argumentsLength; i++) {
        functionCallRequestDTO.m_arguments[i] =
            FunctionCallArgumentDTO::encode(request.arguments[i]);
    }

    return functionCallRequestDTO;
}

FunctionCallRequestDTO::FunctionCallRequestDTO(const FunctionCallRequest& request) {

    strcpy(m_functionName, request.function_name);

    m_argumentsLength = request.arguments_count;

    for (uint16_t i = 0; i < request.arguments_count; i++) {
        m_arguments[i] = FunctionCallArgumentDTO::encode(request.arguments[i]);
    }
}
