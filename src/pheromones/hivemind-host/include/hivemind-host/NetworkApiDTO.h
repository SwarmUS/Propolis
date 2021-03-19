#ifndef PROPOLIS_NETWORKAPIDTO_H
#define PROPOLIS_NETWORKAPIDTO_H

#include "IpDiscoveryDTO.h"
#include <message.pb.h>
#include <variant>

/**
 * @brief Typedef to reuse for each possible type of the DTO
 */
using NetworkApiDTOType = std::variant<std::monostate, IPDiscoveryDTO>;

class NetworkApiDTO {
  public:
    NetworkApiDTO(const NetworkAPI& networkApi);

    NetworkApiDTO(const IPDiscoveryDTO& ipDiscovery);

    /**
    *@brief default constructor, the network api call will be initialized as a monostate (ie, no ip)
    */
    NetworkApiDTO();

    /**
     *@brief get the API call stored
     *@return the stored API call
     */
    const NetworkApiDTOType& getApiCall() const;

    /**
     *@brief set the API call
     */
     void setAPICall(const NetworkApiDTOType& apiCall);

    /**
    *@brief serialize a NetworkAPI for nanopb, sets the fields properly before using
    *pb_encode
    *@param [out] request the NetworkAPI call to serialize
    *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(NetworkAPI& networkApiCall) const;

  private:
    NetworkApiDTOType m_apiCall;
};


#endif // PROPOLIS_NETWORKAPIDTO_H
