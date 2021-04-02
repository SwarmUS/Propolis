#ifndef __HIVEMINDHOSTAPIRESPONSEDTO_H_
#define __HIVEMINDHOSTAPIRESPONSEDTO_H_

#include "GenericResponseDTO.h"
#include <message.pb.h>
#include <variant>

class HiveMindHostApiResponseDTO {
  public:
    HiveMindHostApiResponseDTO(const HiveMindHostApiResponse& response);

    HiveMindHostApiResponseDTO(const GenericResponseDTO& response);

    /**
     *@brief get the stored response
     *@return the stored response */
    const std::variant<std::monostate, GenericResponseDTO>& getResponse() const;

    /**
     *@brief set the response
     *@param [in] response to set */
    void setResponse(const std::variant<std::monostate, GenericResponseDTO>& response);

    /**
     *@brief serialize a HiveMindHostApiResponse for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] response the response to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(HiveMindHostApiResponse& response) const;

  private:
    std::variant<std::monostate, GenericResponseDTO> m_response;
};

#endif // __HIVEMINDHOSTAPIRESPONSEDTO_H_
