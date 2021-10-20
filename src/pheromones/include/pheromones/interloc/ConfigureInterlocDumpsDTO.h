#ifndef __CONFIGUREINTERLOCDUMPSDTO_H__
#define __CONFIGUREINTERLOCDUMPSDTO_H__

#include <message.pb.h>

class ConfigureInterlocDumpsDTO {
  public:
    ConfigureInterlocDumpsDTO(const ConfigureInterlocDumps& message);
    ConfigureInterlocDumpsDTO(bool enabled);

    bool getEnabled() const;
    void setEnabled(bool enabled);

    /**
     * @brief Serializes to a protobuf message
     * @param message [out] message to serialize to
     * @return True if successful, false otherwise
     */
    bool serialize(ConfigureInterlocDumps& message) const;

  private:
    bool m_enabled;
};

#endif //__CONFIGUREINTERLOCDUMPSDTO_H__
