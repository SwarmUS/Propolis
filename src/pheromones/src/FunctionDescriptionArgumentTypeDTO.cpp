#include "FunctionDescriptionArgumentTypeDTO.h"

FunctionDescriptionArgumentTypeDTO typeToDTO(FunctionDescriptionArgumentType type) {
    switch (type) {
    case FunctionDescriptionArgumentType_INT:
        return FunctionDescriptionArgumentTypeDTO::Int;
    case FunctionDescriptionArgumentType_FLOAT:
        return FunctionDescriptionArgumentTypeDTO::Float;
    default:
    case FunctionDescriptionArgumentType_UNKNOWN_TYPE:
        return FunctionDescriptionArgumentTypeDTO::Unknown;
    }
}

FunctionDescriptionArgumentType dtoToType(FunctionDescriptionArgumentTypeDTO type) {
    switch (type) {
    case FunctionDescriptionArgumentTypeDTO::Int:
        return FunctionDescriptionArgumentType_INT;
    case FunctionDescriptionArgumentTypeDTO::Float:
        return FunctionDescriptionArgumentType_FLOAT;
    default:
    case FunctionDescriptionArgumentTypeDTO::Unknown:
        return FunctionDescriptionArgumentType_UNKNOWN_TYPE;
    }
}
