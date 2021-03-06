#ifndef __USERCALLDTO_H_
#define __USERCALLDTO_H_

#include "FunctionCallRequestDTO.h"
#include "FunctionDescriptionRequestDTO.h"
#include "FunctionListLengthRequestDTO.h"
#include "UserCallTargetDTO.h"
#include <message.pb.h>
#include <optional>

class UserCallRequestDTO {
  public:
    UserCallRequestDTO(const UserCallRequest& request);

    UserCallRequestDTO(UserCallTargetDTO source,
                       UserCallTargetDTO destination,
                       const FunctionCallRequestDTO& request);

    UserCallRequestDTO(UserCallTargetDTO source,
                       UserCallTargetDTO destination,
                       const FunctionListLengthRequestDTO& request);

    UserCallRequestDTO(UserCallTargetDTO source,
                       UserCallTargetDTO destination,
                       const FunctionDescriptionRequestDTO& request);

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
     *@brief get the stored request
     *
     *@return the stored request
     **/
    const std::variant<std::monostate,
                       FunctionCallRequestDTO,
                       FunctionListLengthRequestDTO,
                       FunctionDescriptionRequestDTO>&
    getRequest() const;

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
     *@brief set the request
     *
     *@param [in] request to set
     **/
    void setRequest(const std::variant<std::monostate,
                                       FunctionCallRequestDTO,
                                       FunctionListLengthRequestDTO,
                                       FunctionDescriptionRequestDTO>& request);

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
    UserCallTargetDTO m_source = UserCallTargetDTO::UNKNOWN;
    UserCallTargetDTO m_destination = UserCallTargetDTO::UNKNOWN;

    std::variant<std::monostate,
                 FunctionCallRequestDTO,
                 FunctionListLengthRequestDTO,
                 FunctionDescriptionRequestDTO>
        m_request;
};

#endif // __USERCALLDTO_H_
