#include "FunctionCallResponseDTO.h"

FunctionCallResponseDTO::FunctionCallResponseDTO(const GenericResponseDTO& response) :
    m_response(response.getStatus(), response.getDetails()) {}

FunctionCallResponseDTO::FunctionCallResponseDTO(const GenericResponse& response) :
    m_response(response) {}

FunctionCallResponseDTO::FunctionCallResponseDTO(GenericResponseStatusDTO status,
                                                 const char* message) :
    m_response(status, message) {}

const GenericResponseDTO& FunctionCallResponseDTO::getResponse() const { return m_response; }

void FunctionCallResponseDTO::setResponse(GenericResponseStatusDTO status, const char* message) {
    m_response = GenericResponseDTO(status, message);
}

void FunctionCallResponseDTO::setResponse(const FunctionCallResponse& response) {

    if (response.has_response) {
        m_response = GenericResponseDTO(response.response);
    } else {
        m_response = GenericResponseDTO(GenericResponseStatusDTO::Unknown, "No response");
    }
}

bool FunctionCallResponseDTO::serialize(FunctionCallResponse& response) const {
    response.has_response = true;
    return m_response.serialize(response.response);
}
