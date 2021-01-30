#include "ResponseDTO.h"

ResponseDTO::ResponseDTO(const Response& response) : m_id((uint32_t)response.id) {
    switch (response.which_message) {
    case Response_function_call_tag:
        if (response.message.function_call.has_response) {
            m_response = FunctionCallResponseDTO(response.message.function_call.response);
        } else {
            m_response = FunctionCallResponseDTO(GenericResponseStatusDTO::Unknown, "No response");
        }

        break;
    default:
        m_response = std::monostate();
    }
}

ResponseDTO::ResponseDTO(uint32_t id, const FunctionCallResponseDTO& response) :
    m_id(id), m_response(response) {}

uint32_t ResponseDTO::getId() const { return m_id; }

const std::variant<std::monostate, FunctionCallResponseDTO>& ResponseDTO::getResponse() const {
    return m_response;
}

void ResponseDTO::setId(uint32_t id) { m_id = id; }

void ResponseDTO::setResponse(
    const std::variant<std::monostate, FunctionCallResponseDTO>& response) {
    m_response = response;
}

bool ResponseDTO::serialize(Response& response) const {

    response.id = (int32_t)m_id;

    if (const FunctionCallResponseDTO* functionResponse =
            std::get_if<FunctionCallResponseDTO>(&m_response)) {

        response.which_message = Response_function_call_tag;
        return functionResponse->serialize(response.message.function_call);
    }

    return false;
}
