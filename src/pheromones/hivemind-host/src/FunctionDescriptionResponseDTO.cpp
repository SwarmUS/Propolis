#include "FunctionDescriptionResponseDTO.h"

FunctionDescriptionResponseDTO::FunctionDescriptionResponseDTO(
    const FunctionDescriptionResponse& response) {
    switch (response.which_response) {
    case FunctionDescriptionResponse_generic_tag:
        m_response = GenericResponseDTO(response.response.generic);
        break;
    case FunctionDescriptionResponse_function_description_tag:
        m_response = FunctionDescription(response.response.function_description);
        break;
    default:
        m_response = std::monostate();
    }
}

FunctionDescriptionResponseDTO::FunctionDescriptionResponseDTO(const GenericResponseDTO& response) :
    m_response(response) {}

FunctionDescriptionResponseDTO::FunctionDescriptionResponseDTO(
    const FunctionDescriptionDTO& response) :
    m_response(response) {}

const std::variant<std::monostate, GenericResponseDTO, FunctionDescriptionDTO>&
FunctionDescriptionResponseDTO::getResponse() const {
    return m_response;
}

void FunctionDescriptionResponseDTO::setResponse(
    const std::variant<std::monostate, GenericResponseDTO, FunctionDescriptionDTO>& response) {
    m_response = response;
}

bool FunctionDescriptionResponseDTO::serialize(FunctionDescriptionResponse& response) const {

    if (const auto* genericResp = std::get_if<GenericResponseDTO>(&m_response)) {
        response.which_response = FunctionDescriptionResponse_generic_tag;
        return genericResp->serialize(response.response.generic);
    }
    if (const auto* descResp = std::get_if<FunctionDescriptionDTO>(&m_response)) {
        response.which_response = FunctionDescriptionResponse_function_description_tag;
        return descResp->serialize(response.response.function_description);
    }
    return false;
}
