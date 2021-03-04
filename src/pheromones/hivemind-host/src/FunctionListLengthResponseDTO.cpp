#include "FunctionListLengthResponseDTO.h"

FunctionListLengthResponseDTO::FunctionListLengthResponseDTO(
    const FunctionListLengthResponse& req) :
    m_length(req.function_arrray_length) {}

FunctionListLengthResponseDTO::FunctionListLengthResponseDTO(uint32_t length) : m_length(length) {}

uint32_t FunctionListLengthResponseDTO::getLength() const { return m_length; }

void FunctionListLengthResponseDTO::setLength(uint32_t length) { m_length = length; }

bool FunctionListLengthResponseDTO::serialize(FunctionListLengthResponse& req) const {
    req.function_arrray_length = m_length;
    return true;
}
