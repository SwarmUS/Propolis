#ifndef __USERCALLRESPONSEDTO_H_
#define __USERCALLRESPONSEDTO_H_

#include "FunctionCallResponseDTO.h"
#include "UserCallTargetDTO.h"
#include <user-call.pb.h>
#include <variant>

class UserCallResponseDTO {
  public:
    UserCallResponseDTO(UserCallTargetDTO source,
                        UserCallTargetDTO destination,
                        const FunctionCallResponseDTO& response);

    UserCallResponseDTO(const UserCallResponse& response);

    /**
     *@brief get the destination
     *
     *@return the destination of the message
     **/
    UserCallTargetDTO getDestination() const;

    /**
     *@brief get the source
     *
     *@return the source of the message
     **/
    UserCallTargetDTO getSource() const;

    /**
     *@brief gets the generic response
     *
     *@return a reference to the response response
     */
    const std::variant<std::monostate, FunctionCallResponseDTO>& getResponse() const;

    /**
     *@brief set the source
     *
     *@param [in] source the source to set
     **/
    void setSource(UserCallTargetDTO source);

    /**
     *@brief set the destination
     *
     *@param [in] destination the destination to set
     **/
    void setDestination(UserCallTargetDTO destination);

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
    UserCallTargetDTO m_source = UserCallTargetDTO::UNKNOWN;
    UserCallTargetDTO m_destination = UserCallTargetDTO::UNKNOWN;

    std::variant<std::monostate, FunctionCallResponseDTO> m_response;
};

#endif // __USERCALLRESPONSEDTO_H_
