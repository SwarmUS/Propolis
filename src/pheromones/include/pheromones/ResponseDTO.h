#ifndef __RESPONSEDTO_H_
#define __RESPONSEDTO_H_

#include "HiveMindHostApiResponseDTO.h"
#include "UserCallResponseDTO.h"
#include <message.pb.h>
#include <variant>

class ResponseDTO {
  public:
    ResponseDTO(const Response& response);

    ResponseDTO(uint32_t id, const UserCallResponseDTO& response);

    ResponseDTO(uint32_t id, const GenericResponseDTO& response);

    ResponseDTO(uint32_t id, const HiveMindHostApiResponseDTO& response);

    /**
     *@brief gets the id of the response
     *
     *@return the id of the response
     */
    uint32_t getId() const;

    /**
     *@brief gets the inner response
     *
     *@return a variant of the stored resposne
     */
    const std::variant<std::monostate,
                       GenericResponseDTO,
                       UserCallResponseDTO,
                       HiveMindHostApiResponseDTO>&
    getResponse() const;

    /**
     *@brief sets the id of the response
     *
     *@param [in] id the new id
     */
    void setId(uint32_t id);

    /**
     *@brief sets the new inner response
     *
     *@param [in] response the new  inner response
     */
    void setResponse(const std::variant<std::monostate,
                                        GenericResponseDTO,
                                        UserCallResponseDTO,
                                        HiveMindHostApiResponseDTO>& response);

    /**
     *@brief serialize a Response for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] response the response to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(Response& response) const;

  private:
    uint32_t m_id;

    std::
        variant<std::monostate, GenericResponseDTO, UserCallResponseDTO, HiveMindHostApiResponseDTO>
            m_response;
};

#endif // __RESPONSEDTO_H_
