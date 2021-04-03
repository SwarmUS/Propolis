#ifndef __FUNCTIONLISTLENGTHRESPONSEDTO_H_
#define __FUNCTIONLISTLENGTHRESPONSEDTO_H_

#include <message.pb.h>

/**
 *@brief Size of the list of registered function*/
class FunctionListLengthResponseDTO {
  public:
    FunctionListLengthResponseDTO(const FunctionListLengthResponse& req);

    FunctionListLengthResponseDTO(uint32_t length);

    /**
     *@brief get the length
     *@return the length*/
    uint32_t getLength() const;

    /**
     *@brief set the length
     *@param [in] length the length to set*/
    void setLength(uint32_t length);

    /**
     *@brief serialize a FunctionListLengthResponse for nanopb, sets the fields properly before
     *using pb_encode
     *@param [out] req the FunctionListLengthResponse to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(FunctionListLengthResponse& req) const;

  private:
    uint32_t m_length = 0;
};

#endif // __FUNCTIONLISTLENGTHRESPONSEDTO_H_
