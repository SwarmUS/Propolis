#ifndef __HIVEMINDAPIRESPONSEDTO_H_
#define __HIVEMINDAPIRESPONSEDTO_H_

#include "IdResponseDTO.h"
#include "UserCallTargetDTO.h"
#include <message.pb.h>
#include <variant>

class HiveMindApiResponseDTO {
  public:
    HiveMindApiResponseDTO(const HiveMindApiResponse& response);

    HiveMindApiResponseDTO(UserCallTargetDTO destination, const IdResponseDTO& response);

    /**
     *@brief get the destination
     *@return the destination of the message */
    UserCallTargetDTO getDestination() const;

    /**
     *@brief get the stored response
     *@return the stored response */
    const std::variant<std::monostate, IdResponseDTO>& getResponse() const;

    /**
     *@brief set the destination
     *@param [in] destination the destination to set */
    void setDestination(UserCallTargetDTO destination);

    /**
     *@brief set the response
     *@param [in] response to set */
    void setResponse(const std::variant<std::monostate, IdResponseDTO>& response);

    /**
     *@brief serialize a HiveMindApiResponse for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] response the response to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(HiveMindApiResponse& response) const;

  private:
    UserCallTargetDTO m_destination = UserCallTargetDTO::UNKNOWN;

    std::variant<std::monostate, IdResponseDTO> m_response;
};

#endif // __HIVEMINDAPIRESPONSEDTO_H_
