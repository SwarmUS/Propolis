#include "FunctionCallRequestDTO.h"
#include <cstring>

FunctionCallRequestDTO::FunctionCallRequestDTO(const FunctionCallRequest& request) :
    m_argumentsLength(request.arguments_count) {

    strncpy(m_functionName, request.function_name, s_functionNameMaxLength);

    for (uint16_t i = 0; i < request.arguments_count; i++) {
        m_arguments[i] = FunctionCallArgumentDTO(request.arguments[i]);
    }
}

FunctionCallRequestDTO::FunctionCallRequestDTO(const char* functionName,
                                               const FunctionCallArgumentDTO* arguments,
                                               uint16_t argumentsLength) {

    strncpy(m_functionName, functionName, s_functionNameMaxLength);
    m_argumentsLength = argumentsLength < s_functionCallArgumentsMaxLenght ? argumentsLength 
                                        : s_functionNameMaxLength;

    for (uint16_t i = 0; i < m_argumentsLength; i++) {
        m_arguments[i] = arguments[i];
    }
}

const FunctionCallArgumentDTO& FunctionCallRequestDTO::getArgument(uint16_t index) const {
    return m_arguments[index];
}

uint16_t FunctionCallRequestDTO::getArgumentsLength() const { return m_argumentsLength; }

const char* FunctionCallRequestDTO::getFunctionName() const { return m_functionName; }

bool FunctionCallRequestDTO::serialize(FunctionCallRequest& request) const {
    request.arguments_count = m_argumentsLength;
    strncpy(request.function_name, m_functionName, s_functionNameMaxLength);

    for (uint16_t i = 0; i < m_argumentsLength; i++) {

        if (m_arguments[i].serialize(request.arguments[i]) != true) {
            return false;
        }
    }

    return true;
}
