#include "RequestDTO.h"

RequestDTO::RequestDTO(const Request& request) : m_id((uint32_t)request.id) {

    switch (request.which_message) {

    case Request_function_call_tag:
        m_request = FunctionCallRequestDTO(request.message.function_call);
        break;
    default:
        m_request = std::monostate();
    }
}

RequestDTO::RequestDTO(uint32_t id, const FunctionCallRequestDTO& request) :
    m_id(id), m_request(request) {}

const std::variant<std::monostate, FunctionCallRequestDTO>& RequestDTO::getRequest() const {
    return m_request;
}

uint32_t RequestDTO::getId() const { return m_id; }
