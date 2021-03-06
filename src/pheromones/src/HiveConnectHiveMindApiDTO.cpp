#include "HiveConnectHiveMindApiDTO.h"

HiveConnectHiveMindApiDTO::HiveConnectHiveMindApiDTO(const HiveConnectHiveMindApi& apiMsg) :
    m_messageId(apiMsg.message_id) {
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

HiveConnectHiveMindApiDTO::HiveConnectHiveMindApiDTO(uint32_t id,
                                                     const GetAgentsListRequestDTO& req) :
    m_messageId(id), m_message(req) {}

HiveConnectHiveMindApiDTO::HiveConnectHiveMindApiDTO(uint32_t id,
                                                     const GetAgentsListResponseDTO& resp) :
    m_messageId(id), m_message(resp) {}

uint32_t HiveConnectHiveMindApiDTO::getMessageId() const { return m_messageId; }

const std::variant<std::monostate, GetAgentsListRequestDTO, GetAgentsListResponseDTO>&
HiveConnectHiveMindApiDTO::getMessage() const {
    return m_message;
}

void HiveConnectHiveMindApiDTO::setMessageId(uint32_t id) { m_messageId = id; }

void HiveConnectHiveMindApiDTO::setMessage(
    const std::variant<std::monostate, GetAgentsListRequestDTO, GetAgentsListResponseDTO>&
        message) {
    m_message = message;
}

bool HiveConnectHiveMindApiDTO::serialize(HiveConnectHiveMindApi& apiMsg) const {
    apiMsg.message_id = m_messageId;

    if (const auto* agentsReq = std::get_if<GetAgentsListRequestDTO>(&m_message)) {
        apiMsg.which_message = HiveConnectHiveMindApi_agents_req_tag;
        return agentsReq->serialize(apiMsg.message.agents_req);
    }

    if (const auto* agentsResp = std::get_if<GetAgentsListResponseDTO>(&m_message)) {
        apiMsg.which_message = HiveConnectHiveMindApi_agents_resp_tag;
        return agentsResp->serialize(apiMsg.message.agents_resp);
    }

    return false;
}
