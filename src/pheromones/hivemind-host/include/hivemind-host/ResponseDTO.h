#ifndef __RESPONSEDTO_H_
#define __RESPONSEDTO_H_

#include "FunctionCallResponseDTO.h"
#include <message.pb.h>
#include <variant>

class ResponseDTO {
  public:
    ResponseDTO(const Response& response);

    ResponseDTO(uint32_t id, const FunctionCallResponseDTO& response);

    uint32_t getId() const;

    const std::variant<std::monostate, FunctionCallResponseDTO>& getResponse() const;

    void setId(uint32_t id);

    void setResponse(const std::variant<std::monostate, FunctionCallResponseDTO>& response);

    bool serialize(Response& response) const;

  private:
    uint32_t m_id;

    std::variant<std::monostate, FunctionCallResponseDTO> m_response;
};

#endif // __RESPONSEDTO_H_
