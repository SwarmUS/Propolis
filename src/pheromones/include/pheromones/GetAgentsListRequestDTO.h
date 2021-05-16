#ifndef __GETAGENTSLISTREQUESTDTO_H_
#define __GETAGENTSLISTREQUESTDTO_H_

#include <message.pb.h>

class GetAgentsListRequestDTO {
  public:
    GetAgentsListRequestDTO(const GetAgentsListRequest& req);
    GetAgentsListRequestDTO() = default;

    /**
     *@brief serialize a GetAgentsListRequest for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] req the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(GetAgentsListRequest& req) const;
};

#endif // __GETAGENTSLISTREQUESTDTO_H_
