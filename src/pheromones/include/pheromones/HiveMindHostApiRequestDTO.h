#ifndef __HIVEMINDAPIHOSTREQUESTDTO_H_
#define __HIVEMINDAPIHOSTREQUESTDTO_H_

#include <message.pb.h>
#include <variant>

class HiveMindHostApiRequestDTO {
  public:
    HiveMindHostApiRequestDTO(const HiveMindHostApiRequest& request);

    /**
     *@brief get the stored request
     *@return the stored request */
    const std::variant<std::monostate>& getRequest() const;

    /**
     *@brief set the request
     *@param [in] request to set */
    void setRequest(const std::variant<std::monostate>& request);

    /**
     *@brief serialize a HiveMindHostApiRequest for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] request the request to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(HiveMindHostApiRequest& request) const;

  private:
    std::variant<std::monostate> m_request;
};

#endif // __HIVEMINDAPIHOSTREQUESTDTO_H_
