#ifndef __REQUESTDTO_H_
#define __REQUESTDTO_H_

#include "HiveMindApiRequestDTO.h"
#include "SwarmApiRequestDTO.h"
#include "UserCallRequestDTO.h"
#include <message.pb.h>

class RequestDTO {

  public:
    RequestDTO(const Request& request);

    RequestDTO(uint32_t id, const UserCallRequestDTO& request);

    RequestDTO(uint32_t id, const HiveMindApiRequestDTO& request);

    RequestDTO(uint32_t id, const SwarmApiRequestDTO& request);

    /**
     *@brief gets the id of the request
     *
     *@return the id of the request
     */
    uint32_t getId() const;

    /**
     *@brief gets the request currently stored
     *
     *@return a reference to the stored request
     */
    const std::
        variant<std::monostate, UserCallRequestDTO, HiveMindApiRequestDTO, SwarmApiRequestDTO>&
        getRequest() const;

    /**
     *@brief set id of the request

     *@param [in] id new id of the request
     */
    void setId(uint32_t id);

    /**
     *@brief set the request type

     *@param [in] request the type of request to set
     */
    void setRequest(const std::variant<std::monostate,
                                       UserCallRequestDTO,
                                       HiveMindApiRequestDTO,
                                       SwarmApiRequestDTO>& request);

    /**
     *@brief serialize a Request for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] request the request to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(Request& request) const;

  private:
    uint32_t m_id;

    std::variant<std::monostate, UserCallRequestDTO, HiveMindApiRequestDTO, SwarmApiRequestDTO>
        m_request;
};

#endif //__REQUESTDTO_H_
