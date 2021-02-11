#ifndef __USERCALLRESPONSEDTO_H_
#define __USERCALLRESPONSEDTO_H_

#include "FunctionCallResponseDTO.h"
#include "UserCallDestinationDTO.h"
#include <user-call.pb.h>
#include <variant>

class UserCallResponseDTO {
  public:
    UserCallResponseDTO(UserCallDestinationDTO destination,
                        const FunctionCallResponseDTO& response);

    UserCallResponseDTO(const UserCallResponse& response);

    /**
     *@brief get the destination
     *
     *@return the destination of the message
     **/
    UserCallDestinationDTO getDestination() const;

    /**
     *@brief gets the generic response
     *
     *@return a reference to the response response
     */
    const std::variant<std::monostate, FunctionCallResponseDTO>& getResponse() const;

    /**
     *@brief sets the generic response
     *
     *@param [in] response the response to set
     */
    void setResponse(const std::variant<std::monostate, FunctionCallResponseDTO>& response);

    /**
     *@brief serialize a UserCallResponse for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] response the response to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(UserCallResponse& response) const;

  private:
    UserCallDestinationDTO m_destination = UserCallDestinationDTO::UNKNOWN;

    std::variant<std::monostate, FunctionCallResponseDTO> m_response;
};

#endif // __USERCALLRESPONSEDTO_H_
