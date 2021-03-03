#include "RequestDTO.h"

RequestDTO::RequestDTO(const Request& request) : m_id(request.id) {

    switch (request.which_message) {

    case Request_user_call_tag:
        m_request = UserCallRequestDTO(request.message.user_call);
        break;
    case Request_hive_api_tag:
        m_request = HiveMindApiRequest(request.message.hive_api);
        break;
    case Request_swarm_api_tag:
        m_request = SwarmApiRequest(request.message.swarm_api);
        break;
    default:
        m_request = std::monostate();
    }
}

RequestDTO::RequestDTO(uint32_t id, const UserCallRequestDTO& request) :
    m_id(id), m_request(request) {}

RequestDTO::RequestDTO(uint32_t id, const HiveMindApiRequestDTO& request) :
    m_id(id), m_request(request) {}

RequestDTO::RequestDTO(uint32_t id, const SwarmApiRequestDTO& request) :
    m_id(id), m_request(request) {}

const std::variant<std::monostate, UserCallRequestDTO, HiveMindApiRequestDTO, SwarmApiRequestDTO>&
RequestDTO::getRequest() const {
    return m_request;
}

uint32_t RequestDTO::getId() const { return m_id; }

void RequestDTO::setId(uint32_t id) { m_id = id; }

void RequestDTO::setRequest(const std::variant<std::monostate,
                                               UserCallRequestDTO,
                                               HiveMindApiRequestDTO,
                                               SwarmApiRequestDTO>& request) {
    m_request = request;
}

bool RequestDTO::serialize(Request& request) const {
    request.id = m_id;

    if (const auto* userRequest = std::get_if<UserCallRequestDTO>(&m_request)) {
        request.which_message = Request_user_call_tag;
        return userRequest->serialize(request.message.user_call);
    }

    if (const auto* hiveRequest = std::get_if<HiveMindApiRequestDTO>(&m_request)) {
        request.which_message = Request_hive_api_tag;
        return hiveRequest->serialize(request.message.hive_api);
    }

    if (const auto* swarmRequest = std::get_if<SwarmApiRequestDTO>(&m_request)) {
        request.which_message = Request_swarm_api_tag;
        return swarmRequest->serialize(request.message.swarm_api);
    }

    return false;
}
