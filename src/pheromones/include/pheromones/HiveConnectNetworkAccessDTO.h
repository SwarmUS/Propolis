#ifndef PROPOLIS_HIVECONNECTNETWORKACCESSDTO_H
#define PROPOLIS_HIVECONNECTNETWORKACCESSDTO_H

#include "pheromones/PheromonesSettings.h"
#include <message.pb.h>

class HiveConnectNetworkAccessDTO {
  public:
    HiveConnectNetworkAccessDTO(const char* ssid, const char* password);
    HiveConnectNetworkAccessDTO(const HiveConnectNetworkAccess& hiveConnectNetworkAccessDto);

    /**
     * @brief gets the ssid
     * @return a char pointer to the ssid
     */
    const char* getSSID() const;
    /**
     * @brief gets the password
     * @return a char pointer to the password
     */
    const char* getPassword() const;

    /**
     * @brief set the stored ssid
     * @param [in] ssid a char pointer the ssid string
     */
    void setSSID(const char* ssid);
    /**
     * @brief set the stored password
     * @param [in] password a char pointer the password string
     */
    void setPassword(const char* password);

    bool serialize(HiveConnectNetworkAccess& networkAccess);

  private:
    char m_ssid[NETWORK_SSID_MAX_LENGTH];
    char m_password[NETWORK_PASSWORD_MAX_LENGTH];
};
#endif // PROPOLIS_HIVECONNECTNETWORKACCESSDTO_H
