#ifndef __HIVECONNECTHIVEMINDAPIDTO_H_
#define __HIVECONNECTHIVEMINDAPIDTO_H_

#include "GetAgentsListRequestDTO.h"
#include "GetAgentsListResponseDTO.h"
#include <message.pb.h>
#include <variant>

class HiveConnectHiveMindApiDTO {
  public:
    HiveConnectHiveMindApiDTO(const HiveConnectHiveMindApi& apiMsg);

    HiveConnectHiveMindApiDTO(uint32_t id, const GetAgentsListRequestDTO& req);

    HiveConnectHiveMindApiDTO(uint32_t id, const GetAgentsListResponseDTO& resp);

    uint32_t getMessageId() const;

    void setMessageId(uint32_t id) const;

    const std::variant<std::monostate, GetAgentsListRequestDTO, GetAgentsListResponseDTO>&
    getMessage() const;

    void setMessage(
        const std::variant<std::monostate, GetAgentsListRequestDTO, GetAgentsListResponseDTO>&
            message);

    bool serialize(HiveConnectHiveMindApi& apiMsg) const;

  private:
    uint32_t m_id;
    std::variant<std::monostate, GetAgentsListRequestDTO, GetAgentsListResponseDTO> m_message;
};

#endif // __HIVECONNECTHIVEMINDAPIDTO_H_
