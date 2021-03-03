#include "ResponseDTO.h"

ResponseDTO::ResponseDTO(const Response& response) : m_id(response.id) {
    switch (response.which_message) {
    case Response_generic_tag:
        m_response = GenericResponseDTO(response.message.generic);
        break;
    case Response_user_call_tag:
        m_response = UserCallResponseDTO(response.message.user_call);
        break;
    case Response_hive_api_tag:
        m_response = HiveMindApiResponse(response.message.hive_api);
        break;
    case Response_swarm_api_tag:
        m_response = SwarmApiResponse(response.message.swarm_api);
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

const std::variant<std::monostate,
                   GenericResponseDTO,
                   UserCallResponseDTO,
                   HiveMindApiResponseDTO,
                   SwarmApiResponseDTO>&
ResponseDTO::getResponse() const {
    return m_response;
}

void ResponseDTO::setId(uint32_t id) { m_id = id; }

void ResponseDTO::setResponse(const std::variant<std::monostate,
                                                 GenericResponseDTO,
                                                 UserCallResponseDTO,
                                                 HiveMindApiResponseDTO,
                                                 SwarmApiResponseDTO>& response) {
    m_response = response;
}

bool ResponseDTO::serialize(Response& response) const {

    response.id = m_id;

    if (const auto* genericResponse = std::get_if<GenericResponseDTO>(&m_response)) {
        response.which_message = Response_generic_tag;
        return genericResponse->serialize(response.message.generic);
    }
    if (const auto* userResponse = std::get_if<UserCallResponseDTO>(&m_response)) {
        response.which_message = Response_user_call_tag;
        return userResponse->serialize(response.message.user_call);
    }
    if (const auto* hiveResponse = std::get_if<HiveMindApiResponseDTO>(&m_response)) {
        response.which_message = Response_hive_api_tag;
        return hiveResponse->serialize(response.message.hive_api);
    }
    if (const auto* swarmResponse = std::get_if<SwarmApiResponseDTO>(&m_response)) {
        response.which_message = Response_swarm_api_tag;
        return swarmResponse->serialize(response.message.swarm_api);
    }

    return false;
}
