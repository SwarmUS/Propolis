#ifndef __GREETINGDTO_H_
#define __GREETINGDTO_H_

#include <message.pb.h>

/**
 *@brief The first message sent on the conneciton of a host on the hivemind*/
class GreetingDTO {
  public:
    GreetingDTO() = default;

    /**
     *@brief serialize a Greeting for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] greeting the greeting to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(Greeting& greeting) const;

  private:
};

#endif // __GREETINGDTO_H_
