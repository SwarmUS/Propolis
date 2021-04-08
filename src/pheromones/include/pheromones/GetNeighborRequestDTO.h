#ifndef __GETNEIGHBORREQUESTDTO_H_
#define __GETNEIGHBORREQUESTDTO_H_

#include <message.pb.h>

class GetNeighborRequestDTO {
  public:
    GetNeighborRequestDTO(const GetNeighborRequest& req);
    GetNeighborRequestDTO(uint32_t neighborId);

    /**@brief get the id of the neighbor
     *@return the id of the neighbor */
    uint32_t getNeighborId() const;

    /**@brief set the id of the neighbor
     *@param id the id of the neighbor to set*/
    void setNeighborId(uint32_t id);

    /**
     *@brief serialize a GetNeighborRequest for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] req the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(GetNeighborRequest& req) const;

  private:
    uint32_t m_neighborId;
};

#endif // __GETNEIGHBORREQUESTDTO_H_
