#ifndef __GETAGENTSLISTRESPONSEDTO_H_
#define __GETAGENTSLISTRESPONSEDTO_H_

#include "pheromones/PheromonesSettings.h"
#include <array>
#include <message.pb.h>

class GetAgentsListResponseDTO {
  public:
    static constexpr uint16_t AGENTS_MAX_SIZE = AGENTS_LIST_SIZE;

    GetAgentsListResponseDTO(const GetAgentsListResponse& resp);
    GetAgentsListResponseDTO(uint16_t* agents, uint16_t agentsLength);

    /**
     *@brief get the agents
     *@return a ref to the agents array*/
    const std::array<uint16_t, AGENTS_MAX_SIZE>& getAgents() const;

    /**
     *@brief get the raw agents, not const. Can be used to write on it, call
     *setRawAgentsLength
     *@return the raw value of the agents */
    std::array<uint16_t, AGENTS_MAX_SIZE>& getRawAgents();

    /**
     *@brief get the agents array length
     *@return the length of the array */
    uint16_t getAgentsLength() const;

    /**
     *@brief set the agents length after a write with the raw agents
     *@return true if the length is smaller than the max length, false otherwise*/
    bool setRawAgentsLength(uint16_t agentsLength);

    /**
     *@brief set the agents
     *@param [in] agents a pointer to the agents to set
     *@param [in] agentsLength the length of the provided array*/
    void setAgents(const uint16_t* agents, uint16_t agentsLength);
    void setAgents(const uint32_t* agents, uint16_t agentsLength);

    /**
     *@brief serialize a GetAgentsListResponse for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] resp the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(GetAgentsListResponse& resp) const;

  private:
    std::array<uint16_t, AGENTS_MAX_SIZE> m_agents;
    uint16_t m_agentsLength;
};

#endif // __GETAGENTSLISTRESPONSEDTO_H_
