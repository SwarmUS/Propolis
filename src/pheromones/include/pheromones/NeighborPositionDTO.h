#ifndef __NEIGHBORPOSITIONDTO_H_
#define __NEIGHBORPOSITIONDTO_H_

#include <message.pb.h>

class NeighborPositionDTO {
  public:
    NeighborPositionDTO(const NeighborPosition& pos);
    NeighborPositionDTO(float distance, float relativeOrientation, bool inLOS);

    /**@brief get the distance
     *@return the distance in meters*/
    float getDistance() const;

    /**@brief get if the robot is in LOS
     *@return true  if the robot is in LOS*/
    bool inLOS() const;

    /**@brief get the relative orientation
     *@return the orientation in degrees*/
    float getRelativeOrientation() const;

    /**@brief get the distance
     *@param distance the distance in meters*/
    void setDistance(float distance);

    /**@brief set the relative orientation
     *@param orientation the orientation in degrees*/
    void setRelativeOrientation(float orientation);

    /**@brief set if the robot is in LOS
     *@param inLOS  if the robot is in LOS*/
    void setInLOS(bool inLOS);

    /**
     *@brief serialize a NeighborPosition for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] pos the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(NeighborPosition& pos) const;

  private:
    float m_distance;
    float m_relativeOrientation;
    bool m_inLOS;
};

#endif // __NEIGHBORPOSITIONDTO_H_
