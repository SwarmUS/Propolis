#include "ResponseDTO.h"

ResponseDTO::ResponseDTO(const Response& response) : m_id(response.id) {
    switch (response.which_message) {
    case Response_generic_tag:
        m_response = GenericResponseDTO(response.message.generic);
        break;
    case Response_user_call_tag:
        m_response = UserCallResponseDTO(response.message.user_call);
        break;
    default:
        m_response = std::monostate();
    }
}

ResponseDTO::ResponseDTO(uint32_t id, const GenericResponseDTO& response) :
    m_id(id), m_response(response) {}

ResponseDTO::ResponseDTO(uint32_t id, const UserCallResponseDTO& response) :
    m_id(id), m_response(response) {}

uint32_t ResponseDTO::getId() const { return m_id; }

const std::variant<std::monostate, GenericResponseDTO, UserCallResponseDTO>& ResponseDTO::
    getResponse() const {
    return m_response;
}

void ResponseDTO::setId(uint32_t id) { m_id = id; }

void ResponseDTO::setResponse(
    const std::variant<std::monostate, GenericResponseDTO, UserCallResponseDTO>& response) {
    m_response = response;
}

bool ResponseDTO::serialize(Response& response) const {

    response.id = m_id;

    if (const GenericResponseDTO* genericResponse = std::get_if<GenericResponseDTO>(&m_response)) {

        response.which_message = Response_generic_tag;
        return genericResponse->serialize(response.message.generic);
    }

    if (const UserCallResponseDTO* functionResponse =
            std::get_if<UserCallResponseDTO>(&m_response)) {

        response.which_message = Response_user_call_tag;
        return functionResponse->serialize(response.message.user_call);
    }

    return false;
}
