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
    IPDiscoveryDTO(const IPDiscovery& ipDiscovery);

    IPDiscoveryDTO(uint32_t ipAddress);

    /**
     *@brief get the current stored ip address
     *
     *@return the ip address*/
    uint32_t getIP() const;

    /**
     *@brief set the stored ip address
     *
     *@param [in] ip the value to set
     */
    void setIP(uint32_t ip);

    /**
     *@brief serialize a IpRequest for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] ipDiscovery the Ip request to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(IPDiscovery& ipDiscovery) const;

  private:
    uint32_t m_ip;
};

#endif // PROPOLIS_IPDISCOVERYDTO_H
