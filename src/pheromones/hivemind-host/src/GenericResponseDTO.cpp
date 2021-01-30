#include "GenericResponseDTO.h"
#include <cstdio>

GenericResponseDTO::GenericResponseDTO(GenericResponseStatusDTO status, const char* message) {
    setDetails(message);
    setStatus(status);
}

GenericResponseDTO::GenericResponseDTO(const GenericResponse& response) :
    GenericResponseDTO(statusToDTO(response.status), response.details) {}

GenericResponseStatusDTO GenericResponseDTO::getStatus() const { return m_status; }

const char* GenericResponseDTO::getDetails() const { return m_details; }

void GenericResponseDTO::setDetails(const char* message) {
    snprintf(m_details, DETAILS_MAX_LENGTH, "%s", message);
}

void GenericResponseDTO::setStatus(GenericResponseStatusDTO status) { m_status = status; }

bool GenericResponseDTO::serialize(GenericResponse& response) const {
    if (m_status == GenericResponseStatusDTO::Unknown) {
        return false;
    }

    snprintf(response.details, DETAILS_MAX_LENGTH, "%s", m_details);
    response.status = DTOToStatus(m_status);
    return true;
}

GenericResponseStatusDTO GenericResponseDTO::statusToDTO(GenericResponseStatus status) {
    switch (status) {
    case GenericResponseStatus_OK:
        return GenericResponseStatusDTO::Ok;
    case GenericResponseStatus_ERROR:
        return GenericResponseStatusDTO::Error;
    case GenericResponseStatus_BAD_REQUEST:
        return GenericResponseStatusDTO::BadRequest;
    default:
        return GenericResponseStatusDTO::Unknown;
    }
}

GenericResponseStatus GenericResponseDTO::DTOToStatus(GenericResponseStatusDTO status) {
    switch (status) {

    case GenericResponseStatusDTO::Ok:
        return GenericResponseStatus_OK;

    case GenericResponseStatusDTO::Error:
        return GenericResponseStatus_ERROR;

    case GenericResponseStatusDTO::Unknown:
    case GenericResponseStatusDTO::BadRequest:
    default:
        return GenericResponseStatus_BAD_REQUEST;
    }
}
