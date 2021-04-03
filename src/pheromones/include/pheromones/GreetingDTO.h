#ifndef __GREETINGDTO_H_
#define __GREETINGDTO_H_

#include <message.pb.h>

/**
 *@brief The first message sent on the conneciton of a host on the hivemind*/
class GreetingDTO {
  public:
    GreetingDTO(const Greeting& greeting);

    GreetingDTO(uint32_t id);

    /**
     *@brief gets the id
     *@return the id */
    uint16_t getId() const;

    /**
     *@brief set the id
     *@param [in] id the id to set */
    void setId(uint32_t id);

    /**
     *@brief serialize a Greeting for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] greeting the greeting to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(Greeting& greeting) const;

  private:
    uint32_t m_id;
};

#endif // __GREETINGDTO_H_
