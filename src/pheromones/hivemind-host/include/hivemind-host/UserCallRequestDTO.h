#ifndef __USERCALLDTO_H_
#define __USERCALLDTO_H_

#include "FunctionCallRequestDTO.h"
#include "UserCallDestinationDTO.h"
#include <optional>
#include <user-call.pb.h>

class UserCallRequestDTO {
  public:
    UserCallRequestDTO(const UserCallRequest& request);

    UserCallRequestDTO(UserCallDestinationDTO destination, const FunctionCallRequestDTO& request);

    /**
     *@brief get the destination
     *
     *@return the destination of the message
     **/
    UserCallDestinationDTO getDestination() const;

    /**
     *@brief get the stored request
     *
     *@return the stored request
     **/
    const std::variant<std::monostate, FunctionCallRequestDTO>& getRequest() const;

    /**
     *@brief set the destination
     *
     *@param [in] destination the destination to set
     **/
    void setDestination(UserCallDestinationDTO destination);

    /**
     *@brief set the request
     *
     *@param [in] request to set
     **/
    void setRequest(const std::variant<std::monostate, FunctionCallRequestDTO>& request);

    /**
     *@brief serialize a UserCallRequest for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] request the request to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(UserCallRequest& request) const;

  private:
    UserCallDestinationDTO m_destination = UserCallDestinationDTO::UNKNOWN;

    std::variant<std::monostate, FunctionCallRequestDTO> m_request;
};

#endif // __USERCALLDTO_H_
