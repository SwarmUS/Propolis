#ifndef __INTERLOCDUMPDTO_H__
#define __INTERLOCDUMPDTO_H__

#include <GetNeighborResponseDTO.h>
#include <array>
#include <message.pb.h>
#include <pheromones/PheromonesSettings.h>

class InterlocDumpDTO {
  public:
    static constexpr uint8_t MAX_UPDATES_SIZE = INTERLOC_DUMP_MAX_UPDATES_SIZE;

    InterlocDumpDTO(const InterlocDump& message);
    InterlocDumpDTO(const GetNeighborResponseDTO* updates, uint8_t updatesLength);

    /**
     * Gives the length of the Updates array
     * @return Length of the array
     */
    uint8_t getUpdatesLength() const;

    /**
     * Returns the array of updates
     * @return Array of updates
     */
    const std::array<GetNeighborResponseDTO, MAX_UPDATES_SIZE>& getUpdates() const;

    /**
     * Sets the updates array by copying a source array
     * @param frames Source updates array
     * @param framesLength Number of updates to copy
     */
    void setUpdates(const GetNeighborResponseDTO* updates, uint8_t updatesLength);

    /**
     *@brief serialize a Message for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] message the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(InterlocDump& message) const;

  private:
    uint8_t m_updatesLength;
    std::array<GetNeighborResponseDTO, MAX_UPDATES_SIZE> m_updates;
};

#endif //__INTERLOCDUMPDTO_H__
