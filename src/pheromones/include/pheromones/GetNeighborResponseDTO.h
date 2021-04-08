#ifndef __GETNEIGHBORRESPONSEDTO_H_
#define __GETNEIGHBORRESPONSEDTO_H_

#include "RelativePositionDTO.h"
#include <message.pb.h>

class GetNeighborResponseDTO {
  public:
    GetNeighborResponseDTO(const GetNeighborResponse resp);
    GetNeighborResponseDTO(uint32_t neighborId, const RelativePositionDTO& pos);

    /**@brief get the id of the neighbor
     *@return the id of the neighbor */
    uint32_t getNeighborId() const;

    /**@brief get the relative position
     *@return the relative position*/
    const RelativePositionDTO& getRelativePosition() const;

    /**@brief set the id of the neighbor
     *@param id the id of the neighbor to set*/
    void setNeighborId(uint32_t id);

    /**@brief set the position of the neighbor
     *@param pos the new position of the neighbor*/
    void setRelativePosition(const RelativePositionDTO& pos);

    /**
     *@brief serialize a GetNeighborResponse for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] resp the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(GetNeighborResponse& resp) const;

  private:
    uint32_t m_neighborId;
    RelativePositionDTO m_pos;
};

#endif // __GETNEIGHBORRESPONSEDTO_H_
