#ifndef __FUNCTIONLISTLENGTHREQUESTDTO_H_
#define __FUNCTIONLISTLENGTHREQUESTDTO_H_

#include <message.pb.h>

/**
 *@brief Get the size of the list of registered function, after it is possible to get the
 *description of those function*/
class FunctionListLengthRequestDTO {
  public:
    FunctionListLengthRequestDTO(const FunctionListLengthRequest& req);

    FunctionListLengthRequestDTO() = default;

    /**
     *@brief serialize a FunctionListLengthRequest for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] req the FunctionListLengthRequest to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(FunctionListLengthRequest& req) const;
};

#endif // __FUNCTIONLISTLENGTHREQUESTDTO_H_
