#ifndef PROPOLIS_HIVECONNECTROOTNODEDTO_H
#define PROPOLIS_HIVECONNECTROOTNODEDTO_H

#include "message.pb.h"
class HiveConnectRootNodeDTO {
  public:
    HiveConnectRootNodeDTO(bool isRootNode);
    HiveConnectRootNodeDTO(const HiveConnectRootNode& hiveConnectRootNodeDto);

    /**
     * @brief get the flag to know if node is the root node
     * @return true if the root node
     */
    bool isRootNode() const;
    /**
     * @brief set the flag to put node in root mode
     * @param [in] isRoot the flag value
     */
    void setRootNode(bool isRoot);

    bool serialize(HiveConnectRootNode& rootNode) const;

  private:
    bool m_isRoot;

};
#endif // PROPOLIS_HIVECONNECTROOTNODEDTO_H
