#ifndef __SWARMAPIREQUESTDTO_H_
#define __SWARMAPIREQUESTDTO_H_

#include "IdRequestDTO.h"
#include <message.pb.h>
#include <variant>

class SwarmApiRequestDTO {
  public:
    SwarmApiRequestDTO(const SwarmApiRequest& request);

    SwarmApiRequestDTO(const IdRequestDTO& request);

    /**
     *@brief get the stored request
     *@return the stored request */
    const std::variant<std::monostate, IdRequestDTO>& getRequest() const;

    /**
     *@brief set the request
     *@param [in] request to set */
    void setRequest(const std::variant<std::monostate, IdRequestDTO>& request);

    /**
     *@brief serialize a SwarmApiRequest for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] request the request to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(SwarmApiRequest& request) const;

  private:
    std::variant<std::monostate, IdRequestDTO> m_request;
};

#endif // __SWARMAPIREQUESTDTO_H_