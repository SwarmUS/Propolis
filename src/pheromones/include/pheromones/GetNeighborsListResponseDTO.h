#ifndef __GETNEIGHBORSLISTRESPONSEDTO_H_
#define __GETNEIGHBORSLISTRESPONSEDTO_H_

#include "pheromones/PheromonesSettings.h"
#include <array>
#include <message.pb.h>

class GetNeighborsListResponseDTO {
  public:
    static constexpr uint16_t NEIGHBORS_MAX_SIZE = NEIGHBORS_LIST_SIZE;

    GetNeighborsListResponseDTO(const GetNeighborsListResponse& resp);
    GetNeighborsListResponseDTO(uint16_t* neighbors, uint16_t neighborsLength);

    /**
     *@brief get the neighbors
     *@return a ref to the neighbors array*/
    const std::array<uint16_t, NEIGHBORS_MAX_SIZE>& getNeighbors() const;

    /**
     *@brief get the raw neighbors, not const. Can be used to write on it, call
     *setRawNeighborsLength
     *@return the raw value of the neighbors */
    std::array<uint16_t, NEIGHBORS_MAX_SIZE>& getRawNeighbors();

    /**
     *@brief get the neighbors array length
     *@return the length of the array */
    uint16_t getNeighborsLength() const;

    /**
     *@brief set the neighbors length after a write with the raw neighbors
     *@return true if the length is smaller than the max length, false otherwise*/
    bool setRawNeighborsLength(uint16_t neighborsLength);

    /**
     *@brief set the neighbors
     *@param [in] neighbors a pointer to the neighbors to set
     *@param [in] neighborsLength the length of the provided array*/
    void setNeighbors(const uint16_t* neighbors, uint16_t neighborsLength);
    void setNeighbors(const uint32_t* neighbors, uint16_t neighborsLength);

    /**
     *@brief serialize a GetNeighborsListResponse for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] resp the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(GetNeighborsListResponse& resp) const;

  private:
    std::array<uint16_t, NEIGHBORS_MAX_SIZE> m_neighbors;
    uint16_t m_neighborsLength;
};

#endif // __GETNEIGHBORSLISTRESPONSEDTO_H_
