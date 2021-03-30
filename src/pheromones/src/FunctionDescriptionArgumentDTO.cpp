#include "FunctionDescriptionArgumentDTO.h"
#include <cstdio>

FunctionDescriptionArgumentDTO::FunctionDescriptionArgumentDTO() :
    m_argumentType(FunctionDescriptionArgumentTypeDTO::Unknown) {
    setArgumentName("");
}

FunctionDescriptionArgumentDTO::FunctionDescriptionArgumentDTO(
    const FunctionDescriptionArgument& arg) :
    m_argumentType(typeToDTO(arg.type)) {
    setArgumentName(arg.argument_name);
}

FunctionDescriptionArgumentDTO::FunctionDescriptionArgumentDTO(
    const char* argName, FunctionDescriptionArgumentTypeDTO type) :
    m_argumentType(type) {
    setArgumentName(argName);
}

const char* FunctionDescriptionArgumentDTO::getArgumentName() const { return m_argumentName; }

void FunctionDescriptionArgumentDTO::setArgumentName(const char* argName) {

    snprintf(m_argumentName, FUNCTION_ARGUMENT_NAME_MAX_SIZE, "%s", argName);
}

FunctionDescriptionArgumentTypeDTO FunctionDescriptionArgumentDTO::getArgumentType() const {
    return m_argumentType;
}

void FunctionDescriptionArgumentDTO::setArgumentType(FunctionDescriptionArgumentTypeDTO type) {
    m_argumentType = type;
}

bool FunctionDescriptionArgumentDTO::serialize(FunctionDescriptionArgument& arg) const {
    arg.type = dtoToType(m_argumentType);
    snprintf(arg.argument_name, FUNCTION_ARGUMENT_NAME_MAX_SIZE, "%s", m_argumentName);
    return true;
}
