#ifndef __IDREQUESTDTO_H_
#define __IDREQUESTDTO_H_

#include <message.pb.h>

/**
 *@brief Get the id of a hivemind, can be used when broadcasting and getting all ids*/
class IdRequestDTO {
  public:
    IdRequestDTO(const IdRequest& req);

    IdRequestDTO() = default;

    /**
     *@brief serialize a IdRequest for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] req the IdRequest to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(IdRequest& req) const;
};

#endif // __IDREQUESTDTO_H_
