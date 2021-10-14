#ifndef __GETNEIGHBORRESPONSEDTO_H_
#define __GETNEIGHBORRESPONSEDTO_H_

#include "NeighborPositionDTO.h"
#include <message.pb.h>
#include <optional>

class GetNeighborResponseDTO {
  public:
    GetNeighborResponseDTO();
    GetNeighborResponseDTO(const GetNeighborResponse resp);
    GetNeighborResponseDTO(uint16_t neighborId, const std::optional<NeighborPositionDTO>& pos);

    /**@brief get the id of the neighbor
     *@return the id of the neighbor */
    uint16_t getNeighborId() const;

    /**@brief get the relative position
     *@return the relative position*/
    const std::optional<NeighborPositionDTO>& getNeighborPosition() const;

    /**@brief set the id of the neighbor
     *@param id the id of the neighbor to set*/
    void setNeighborId(uint16_t id);

    /**@brief set the position of the neighbor
     *@param pos the new position of the neighbor*/
    void setNeighborPosition(const std::optional<NeighborPositionDTO>& pos);

    /**
     *@brief serialize a GetNeighborResponse for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] resp the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(GetNeighborResponse& resp) const;

  private:
    uint16_t m_neighborId;
    std::optional<NeighborPositionDTO> m_pos;
};

#endif // __GETNEIGHBORRESPONSEDTO_H_
