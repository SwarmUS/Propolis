#ifndef __HIVECONNECTHIVEMINDAPIDTO_H_
#define __HIVECONNECTHIVEMINDAPIDTO_H_

#include "GetAgentsListRequestDTO.h"
#include "GetAgentsListResponseDTO.h"
#include "HiveConnectNetowrkConfigGetResponseDTO.h"
#include "HiveConnectNetworkConfigGetRequestDTO.h"
#include "HiveConnectNetworkConfigSetRequestDTO.h"
#include "HiveConnectNetworkConfigSetResponseDTO.h"
#include <message.pb.h>
#include <variant>

class HiveConnectHiveMindApiDTO {
  public:
    HiveConnectHiveMindApiDTO(const HiveConnectHiveMindApi& apiMsg);

    HiveConnectHiveMindApiDTO(uint32_t id, const GetAgentsListRequestDTO& req);

    HiveConnectHiveMindApiDTO(uint32_t id, const GetAgentsListResponseDTO& resp);

    HiveConnectHiveMindApiDTO(uint32_t id, const HiveConnectNetworkConfigSetRequestDTO& req);

    HiveConnectHiveMindApiDTO(uint32_t id, const HiveConnectNetworkConfigSetResponseDTO& res);

    HiveConnectHiveMindApiDTO(uint32_t id, const HiveConnectNetworkConfigGetRequestDTO& req);

    HiveConnectHiveMindApiDTO(uint32_t id, const HiveConnectNetworkConfigGetResponseDTO& res);

    uint32_t getMessageId() const;

    const std::variant<std::monostate,
                       GetAgentsListRequestDTO,
                       GetAgentsListResponseDTO,
                       HiveConnectNetworkConfigSetRequestDTO,
                       HiveConnectNetworkConfigSetResponseDTO,
                       HiveConnectNetworkConfigGetRequestDTO,
                       HiveConnectNetworkConfigGetResponseDTO>&
    getMessage() const;

    void setMessageId(uint32_t id);

    void setMessage(const std::variant<std::monostate,
                                       GetAgentsListRequestDTO,
                                       GetAgentsListResponseDTO,
                                       HiveConnectNetworkConfigSetRequestDTO,
                                       HiveConnectNetworkConfigSetResponseDTO,
                                       HiveConnectNetworkConfigGetRequestDTO,
                                       HiveConnectNetworkConfigGetResponseDTO>& message);

    bool serialize(HiveConnectHiveMindApi& apiMsg) const;

  private:
    uint32_t m_messageId;
    std::variant<std::monostate,
                 GetAgentsListRequestDTO,
                 GetAgentsListResponseDTO,
                 HiveConnectNetworkConfigSetRequestDTO,
                 HiveConnectNetworkConfigSetResponseDTO,
                 HiveConnectNetworkConfigGetRequestDTO,
                 HiveConnectNetworkConfigGetResponseDTO>
        m_message;
};

#endif // __HIVECONNECTHIVEMINDAPIDTO_H_
