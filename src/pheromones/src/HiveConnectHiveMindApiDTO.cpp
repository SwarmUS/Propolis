#include "HiveConnectHiveMindApiDTO.h"

HiveConnectHiveMindApiDTO::HiveConnectHiveMindApiDTO(const HiveConnectHiveMindApi& apiMsg) {
    switch (apiMsg.which_message) {
    case HiveConnectHiveMindApi_agents_req_tag:
        m_message = GetAgentsListRequestDTO(apiMsg.message.agents_req);
        break;
    case HiveConnectHiveMindApi_agents_resp_tag:
        m_message = GetAgentsListResponseDTO(apiMsg.message.agents_resp);
        break;
    default:
        m_message = std::monostate();
        break;
    }
}

const std::variant<std::monostate, GetAgentsListRequestDTO, GetAgentsListResponseDTO>&
HiveConnectHiveMindApiDTO::getMessage() const {
    return m_message;
}

void HiveConnectHiveMindApiDTO::setMessage(
    const std::variant<std::monostate, GetAgentsListRequestDTO, GetAgentsListResponseDTO>&
        message) {
    m_message = message;
}

bool HiveConnectHiveMindApiDTO::serialize(HiveConnectHiveMindApi& apiMsg) const {

    if (const auto* agentsReq = std::get_if<GetAgentsListRequestDTO>(&m_message)) {
        apiMsg.which_message = HiveConnectHiveMindApi_agents_req_tag;
        agentsReq->serialize(apiMsg.message.agents_req);
        return true;
    }

    if (const auto* agentsResp = std::get_if<GetAgentsListResponseDTO>(&m_message)) {
        apiMsg.which_message = HiveConnectHiveMindApi_agents_resp_tag;
        agentsResp->serialize(apiMsg.message.agents_resp);
        return true;
    }

    return false;
}
