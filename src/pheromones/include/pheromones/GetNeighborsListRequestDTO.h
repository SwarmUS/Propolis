#ifndef __GETNEIGHBORSLISTREQUESTDTO_H_
#define __GETNEIGHBORSLISTREQUESTDTO_H_

#include <message.pb.h>

class GetNeighborsListRequestDTO {
  public:
    GetNeighborsListRequestDTO(const GetNeighborsListRequest& req);
    GetNeighborsListRequestDTO() = default;

    /**
     *@brief serialize a GetNeighborsListRequest for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] req the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(GetNeighborsListRequest& req) const;
};

#endif // __GETNEIGHBORSLISTREQUESTDTO_H_
