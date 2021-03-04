#ifndef __FUNCTIONDESCRIPTIONREQUESTDTO_H_
#define __FUNCTIONDESCRIPTIONREQUESTDTO_H_

#include <message.pb.h>

class FunctionDescriptionRequestDTO {
  public:
    FunctionDescriptionRequestDTO(const FunctionDescriptionRequest& functionDescription);

    FunctionDescriptionRequestDTO(uint32_t index);

    /**
     *@brief get the index of the funtion to get of the request
     *@return the index */
    uint32_t getIndex() const;

    /**
     *@brief set the index of the funtion of the request
     *@param [in] index the index to set*/
    void setIndex(uint32_t index);

    /**
     *@brief serialize a FunctionDescriptionRequest for nanopb, sets the fields properly before
     *using pb_encode
     *@param [out] request the request to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(FunctionDescriptionRequest& request) const;

  private:
    uint32_t m_functionListIndex = 0;
};

#endif // __FUNCTIONDESCRIPTIONREQUESTDTO_H_
