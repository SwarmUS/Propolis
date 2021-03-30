#include "FunctionCallRequestDTO.h"
#include <cstdio>

FunctionCallRequestDTO::FunctionCallRequestDTO(const FunctionCallRequest& request) :
    m_argumentsLength(request.arguments_count) {

    setFunctionName(request.function_name);
    for (uint16_t i = 0; i < request.arguments_count; i++) {
        m_arguments[i] = FunctionCallArgumentDTO(request.arguments[i]);
    }
}

FunctionCallRequestDTO::FunctionCallRequestDTO(const char* functionName,
                                               const FunctionCallArgumentDTO* arguments,
                                               uint16_t argumentsLength) {

    setFunctionName(functionName);
    setArguments(arguments, argumentsLength);
}

const std::array<FunctionCallArgumentDTO,
                 FunctionCallRequestDTO::FUNCTION_CALL_ARGUMENTS_MAX_LENGTH>&
FunctionCallRequestDTO::getArguments() const {
    return m_arguments;
}

uint16_t FunctionCallRequestDTO::getArgumentsLength() const { return m_argumentsLength; }

const char* FunctionCallRequestDTO::getFunctionName() const { return m_functionName; }

void FunctionCallRequestDTO::setFunctionName(const char* functionName) {
    snprintf(m_functionName, FUNCTION_CALL_NAME_MAX_LENGTH, "%s", functionName);
}

uint16_t FunctionCallRequestDTO::setArguments(const FunctionCallArgumentDTO* arguments,
                                              uint16_t argumentsLength) {
    m_argumentsLength = argumentsLength < FUNCTION_CALL_ARGUMENTS_MAX_LENGTH
                            ? argumentsLength
                            : FUNCTION_CALL_ARGUMENTS_MAX_LENGTH;

    for (uint16_t i = 0; i < m_argumentsLength; i++) {
        m_arguments[i] = arguments[i];
    }

    return m_argumentsLength;
}

bool FunctionCallRequestDTO::serialize(FunctionCallRequest& request) const {
    request.arguments_count = m_argumentsLength;
    snprintf(request.function_name, FUNCTION_CALL_NAME_MAX_LENGTH, "%s", m_functionName);

    for (uint16_t i = 0; i < m_argumentsLength; i++) {

        if (!m_arguments[i].serialize(request.arguments[i])) {
            return false;
        }
    }

    return true;
}
