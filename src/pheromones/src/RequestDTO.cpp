#include "RequestDTO.h"

RequestDTO::RequestDTO(const Request& request) : m_id(request.id) {

    switch (request.which_message) {

    case Request_user_call_tag:
        m_request = UserCallRequestDTO(request.message.user_call);
        break;
    case Request_hivemind_host_tag:
        m_request = HiveMindHostApiRequestDTO(request.message.hivemind_host);
        break;
    default:
        m_request = std::monostate();
    }
}

RequestDTO::RequestDTO(uint32_t id, const UserCallRequestDTO& request) :
    m_id(id), m_request(request) {}

RequestDTO::RequestDTO(uint32_t id, const HiveMindHostApiRequestDTO& request) :
    m_id(id), m_request(request) {}

const std::variant<std::monostate, UserCallRequestDTO, HiveMindHostApiRequestDTO>& RequestDTO::
    getRequest() const {
    return m_request;
}

uint32_t RequestDTO::getId() const { return m_id; }

void RequestDTO::setId(uint32_t id) { m_id = id; }

void RequestDTO::setRequest(
    const std::variant<std::monostate, UserCallRequestDTO, HiveMindHostApiRequestDTO>& request) {
    m_request = request;
}

bool RequestDTO::serialize(Request& request) const {
    request.id = m_id;

    if (const auto* userRequest = std::get_if<UserCallRequestDTO>(&m_request)) {
        request.which_message = Request_user_call_tag;
        return userRequest->serialize(request.message.user_call);
    }

    if (const auto* hiveRequest = std::get_if<HiveMindHostApiRequestDTO>(&m_request)) {
        request.which_message = Request_hivemind_host_tag;
        return hiveRequest->serialize(request.message.hivemind_host);
    }

    return false;
}
