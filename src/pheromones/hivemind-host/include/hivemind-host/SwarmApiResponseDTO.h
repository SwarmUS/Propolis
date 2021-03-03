#ifndef __HIVEMINDAPIRESPONSEDTO_H_
#define __HIVEMINDAPIRESPONSEDTO_H_

#include "IdResponseDTO.h"
#include <message.pb.h>
#include <variant>

class SwarmApiResponseDTO {
  public:
    SwarmApiResponseDTO(const SwarmApiResponse& response);

    SwarmApiResponseDTO(const IdResponseDTO& response);

    /**
     *@brief get the stored response
     *@return the stored response */
    const std::variant<std::monostate, IdResponseDTO>& getResponse() const;

    /**
     *@brief set the response
     *@param [in] response to set */
    void setResponse(const std::variant<std::monostate, IdResponseDTO>& response);

    /**
     *@brief serialize a SwarmApiResponse for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] response the response to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(SwarmApiResponse& response) const;

  private:
    std::variant<std::monostate, IdResponseDTO> m_response;
};

#endif // __HIVEMINDAPIRESPONSEDTO_H_
