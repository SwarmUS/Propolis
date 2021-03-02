#ifndef __HIVEMINDAPIREQUESTDTO_H_
#define __HIVEMINDAPIREQUESTDTO_H_

#include "IdRequestDTO.h"
#include "UserCallTargetDTO.h"
#include <message.pb.h>
#include <variant>

class HiveMindApiRequestDTO {
  public:
    HiveMindApiRequestDTO(const HiveMindApiRequest& request);

    HiveMindApiRequestDTO(UserCallTargetDTO source, const IdRequestDTO& request);

    /**
     *@brief get the source
     *@return the source of the message */
    UserCallTargetDTO getSource() const;

    /**
     *@brief get the stored request
     *@return the stored request */
    const std::variant<std::monostate, IdRequestDTO>& getRequest() const;

    /**
     *@brief set the source
     *@param [in] source the source to set */
    void setSource(UserCallTargetDTO source);

    /**
     *@brief set the request
     *@param [in] request to set */
    void setRequest(const std::variant<std::monostate, IdRequestDTO>& request);

    /**
     *@brief serialize a HiveMindApiRequest for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] request the request to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(HiveMindApiRequest& request) const;

  private:
    UserCallTargetDTO m_source = UserCallTargetDTO::UNKNOWN;

    std::variant<std::monostate, IdRequestDTO> m_request;
};

#endif // __HIVEMINDAPIREQUESTDTO_H_
