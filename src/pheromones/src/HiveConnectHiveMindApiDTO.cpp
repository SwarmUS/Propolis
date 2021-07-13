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
    case HiveConnectHiveMindApi_network_config_set_request_tag:
        m_message = HiveConnectNetworkConfigSetRequestDTO(apiMsg.message.network_config_set_request);
        break;
    case HiveConnectHiveMindApi_network_config_get_request_tag:
        m_message = HiveConnectNetworkConfigGetRequestDTO(apiMsg.message.network_config_get_request);
        break;
    case HiveConnectHiveMindApi_network_config_set_response_tag:
        m_message = HiveConnectNetworkConfigSetResponseDTO(apiMsg.message.network_config_set_response);
        break;
    case HiveConnectHiveMindApi_network_config_get_response_tag:
        m_message = HiveConnectNetworkConfigGetResponseDTO(apiMsg.message.network_config_get_response);
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

HiveConnectHiveMindApiDTO::HiveConnectHiveMindApiDTO(uint32_t id, const HiveConnectNetworkConfigGetRequestDTO& req) :
    m_messageId(id), m_message(req) {}

HiveConnectHiveMindApiDTO::HiveConnectHiveMindApiDTO(uint32_t id, const HiveConnectNetworkConfigSetRequestDTO& req) :
    m_messageId(id), m_message(req) {}

HiveConnectHiveMindApiDTO::HiveConnectHiveMindApiDTO(uint32_t id, const HiveConnectNetworkConfigGetResponseDTO& res) :
    m_messageId(id), m_message(res) {}

HiveConnectHiveMindApiDTO::HiveConnectHiveMindApiDTO(uint32_t id, const HiveConnectNetworkConfigSetResponseDTO& res) :
    m_messageId(id), m_message(res) {}

uint32_t HiveConnectHiveMindApiDTO::getMessageId() const { return m_messageId; }

const std::variant<std::monostate,
    GetAgentsListRequestDTO,
    GetAgentsListResponseDTO,
    HiveConnectNetworkConfigSetRequestDTO,
    HiveConnectNetworkConfigSetResponseDTO,
    HiveConnectNetworkConfigGetRequestDTO,
    HiveConnectNetworkConfigGetResponseDTO>&
HiveConnectHiveMindApiDTO::getMessage() const {
    return m_message;
}

void HiveConnectHiveMindApiDTO::setMessageId(uint32_t id) { m_messageId = id; }

void HiveConnectHiveMindApiDTO::setMessage(
    const std::variant<std::monostate,
        GetAgentsListRequestDTO,
        GetAgentsListResponseDTO,
        HiveConnectNetworkConfigSetRequestDTO,
        HiveConnectNetworkConfigSetResponseDTO,
        HiveConnectNetworkConfigGetRequestDTO,
        HiveConnectNetworkConfigGetResponseDTO>&
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

    if (const auto* configSetRequest = std::get_if<HiveConnectNetworkConfigSetRequestDTO>(&m_message)) {
        apiMsg.which_message = HiveConnectHiveMindApi_network_config_set_request_tag;
        return configSetRequest->serialize(apiMsg.message.network_config_set_request);
    }

    if (const auto* configGetRequest = std::get_if<HiveConnectNetworkConfigGetRequestDTO>(&m_message)) {
        apiMsg.which_message = HiveConnectHiveMindApi_network_config_get_request_tag;
        return configGetRequest->serialize(apiMsg.message.network_config_get_request);
    }

    if (const auto* configSetResponse = std::get_if<HiveConnectNetworkConfigSetResponseDTO>(&m_message)) {
        apiMsg.which_message = HiveConnectHiveMindApi_network_config_set_response_tag;
        return configSetResponse->serialize(apiMsg.message.network_config_set_response);
    }

    if (const auto* configGetResponse = std::get_if<HiveConnectNetworkConfigGetResponseDTO>(&m_message)) {
        apiMsg.which_message = HiveConnectHiveMindApi_network_config_get_response_tag;
        return configGetResponse->serialize(apiMsg.message.network_config_get_response);
    }

    return false;
}
