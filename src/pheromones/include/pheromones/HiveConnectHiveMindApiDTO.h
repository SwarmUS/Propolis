#ifndef __HIVECONNECTHIVEMINDAPIDTO_H_
#define __HIVECONNECTHIVEMINDAPIDTO_H_

#include "GetAgentsListRequestDTO.h"
#include "GetAgentsListResponseDTO.h"
#include <message.pb.h>
#include <variant>

class HiveConnectHiveMindApiDTO {
  public:
    HiveConnectHiveMindApiDTO(const HiveConnectHiveMindApi& apiMsg);

    HiveConnectHiveMindApiDTO(const GetAgentsListRequestDTO& req);

    HiveConnectHiveMindApiDTO(const GetAgentsListResponseDTO& resp);

    const std::variant<std::monostate, GetAgentsListRequestDTO, GetAgentsListResponseDTO>&
    getMessage() const;

    void setMessage(
        const std::variant<std::monostate, GetAgentsListRequestDTO, GetAgentsListResponseDTO>&
            message);

    bool serialize(HiveConnectHiveMindApi& apiMsg) const;

  private:
    std::variant<std::monostate, GetAgentsListRequestDTO, GetAgentsListResponseDTO> m_message;
};

#endif // __HIVECONNECTHIVEMINDAPIDTO_H_
