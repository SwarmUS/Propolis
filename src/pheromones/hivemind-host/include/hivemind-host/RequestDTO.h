#ifndef __REQUESTDTO_H_
#define __REQUESTDTO_H_

#include "FunctionCallRequestDTO.h"
#include <message.pb.h>

class RequestDTO {

  public:
    RequestDTO(const Request& request);

    RequestDTO(uint32_t id, const FunctionCallRequestDTO& request);

    uint32_t getId() const;

    const std::variant<std::monostate, FunctionCallRequestDTO>& getRequest() const;

    bool serialize(Request&) const;

  private:
    uint32_t m_id;

    std::variant<std::monostate, FunctionCallRequestDTO> m_request;
};

#endif //__REQUESTDTO_H_
