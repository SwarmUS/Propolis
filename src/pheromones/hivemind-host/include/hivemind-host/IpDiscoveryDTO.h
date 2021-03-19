#ifndef PROPOLIS_IPDISCOVERYDTO_H
#define PROPOLIS_IPDISCOVERYDTO_H

#include <cstdint>
#include <message.pb.h>
#include <variant>

/**
 * @brief Class to represent an IP request
 */
class IPDiscoveryDTO {

  public:
    IPDiscoveryDTO(const IPDiscovery & ipDiscovery);

    IPDiscoveryDTO(uint32_t ipAddress);

    /**
    *@brief default constructor, the ip will be initialized as a monostate (ie, no ip)
    */
    IPDiscoveryDTO();

    /**
     *@brief get the current stored ip address
     *
     *@return the ip address*/
    const std::variant<std::monostate, uint32_t>& getIP() const;

    /**
     *@brief set the stored ip address
     *
     *@param [in] arg the value to set
     */
    void setIP(const std::variant<std::monostate, uint32_t>& ip);

    /**
     *@brief serialize a IpRequest for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] argument the Ip request to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(IPDiscovery& ipDiscovery) const;

  private:
    std::variant<std::monostate, uint32_t> m_ip;
};


#endif // PROPOLIS_IPDISCOVERYDTO_H
