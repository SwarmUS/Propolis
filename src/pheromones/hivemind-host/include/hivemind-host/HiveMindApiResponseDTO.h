#ifndef __HIVEMINDAPIRESPONSEDTO_H_
#define __HIVEMINDAPIRESPONSEDTO_H_

#include "GenericResponseDTO.h"
#include "IdResponseDTO.h"
#include <message.pb.h>
#include <variant>

class HiveMindApiResponseDTO {
  public:
    HiveMindApiResponseDTO(const HiveMindApiResponse& response);

    HiveMindApiResponseDTO(const IdResponseDTO& response);

    HiveMindApiResponseDTO(const GenericResponseDTO& response);

    /**
     *@brief get the stored response
     *@return the stored response */
    const std::variant<std::monostate, GenericResponseDTO, IdResponseDTO>& getResponse() const;

    /**
     *@brief set the response
     *@param [in] response to set */
    void setResponse(
        const std::variant<std::monostate, GenericResponseDTO, IdResponseDTO>& response);

    /**
     *@brief serialize a HiveMindApiResponse for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] response the response to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(HiveMindApiResponse& response) const;

  private:
    std::variant<std::monostate, GenericResponseDTO, IdResponseDTO> m_response;
};

#endif // __HIVEMINDAPIRESPONSEDTO_H_
