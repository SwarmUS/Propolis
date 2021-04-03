#include "FunctionDescriptionRequestDTO.h"

FunctionDescriptionRequestDTO::FunctionDescriptionRequestDTO(
    const FunctionDescriptionRequest& functionDescription) :
    m_functionListIndex(functionDescription.function_list_index) {}

FunctionDescriptionRequestDTO::FunctionDescriptionRequestDTO(uint32_t index) :
    m_functionListIndex(index) {}

uint32_t FunctionDescriptionRequestDTO::getIndex() const { return m_functionListIndex; }

void FunctionDescriptionRequestDTO::setIndex(uint32_t index) { m_functionListIndex = index; }

bool FunctionDescriptionRequestDTO::serialize(FunctionDescriptionRequest& request) const {
    request.function_list_index = m_functionListIndex;
    return true;
}
