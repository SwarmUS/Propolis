#ifndef __GREETINGDTO_H_
#define __GREETINGDTO_H_

#include <message.pb.h>

/**
 *@brief The first message sent on the conneciton of a host on the hivemind*/
class GreetingDTO {
  public:
    GreetingDTO(const Greeting& greeting);

    GreetingDTO(uint32_t agentId);

    /**
     *@brief gets the agentId
     *@return the agentId */
    uint16_t getId() const;

    /**
     *@brief set the agentId
     *@param [in] agentId the agentId to set */
    void setId(uint32_t agentId);

    /**
     *@brief serialize a Greeting for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] greeting the greeting to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(Greeting& greeting) const;

  private:
    uint32_t m_agentId;
};

#endif // __GREETINGDTO_H_
