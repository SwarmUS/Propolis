#include "FunctionDescriptionDTO.h"
#include <cstdio>

FunctionDescriptionDTO::FunctionDescriptionDTO(const FunctionDescription& desc) :
    m_argumentsLength(desc.arguments_description_count) {
    setFunctionName(desc.function_name);
    for (uint16_t i = 0; i < m_argumentsLength; i++) {
        m_arguments[i] = FunctionDescriptionArgumentDTO(desc.arguments_description[i]);
    }
}

FunctionDescriptionDTO::FunctionDescriptionDTO(const char* functionName,
                                               const FunctionDescriptionArgumentDTO* args,
                                               uint16_t argsLength) {
    setFunctionName(functionName);
    setArguments(args, argsLength);
}

uint16_t FunctionDescriptionDTO::getArgumentsLength() const { return m_argumentsLength; }

const char* FunctionDescriptionDTO::getFunctionName() const { return m_functionName; }

const std::array<FunctionDescriptionArgumentDTO, FunctionDescriptionDTO::ARGUMENTS_MAX_SIZE>&
FunctionDescriptionDTO::getArguments() const {
    return m_arguments;
}

void FunctionDescriptionDTO::setFunctionName(const char* functionName) {
    snprintf(m_functionName, FUNCTION_NAME_MAX_SIZE, "%s", functionName);
}

uint16_t FunctionDescriptionDTO::setArguments(const FunctionDescriptionArgumentDTO* arguments,
                                              uint16_t argumentsLength) {
    m_argumentsLength = argumentsLength < ARGUMENTS_MAX_SIZE ? argumentsLength : ARGUMENTS_MAX_SIZE;

    for (uint16_t i = 0; i < m_argumentsLength; i++) {
        m_arguments[i] = arguments[i];
    }
    return m_argumentsLength;
}

bool FunctionDescriptionDTO::serialize(FunctionDescription& desc) const {
    desc.arguments_description_count = m_argumentsLength;
    snprintf(desc.function_name, FUNCTION_NAME_MAX_SIZE, "%s", m_functionName);

    for (uint16_t i = 0; i < m_argumentsLength; i++) {
        if (!m_arguments[i].serialize(desc.arguments_description[i])) {
            return false;
        }
    }

    return true;
}
