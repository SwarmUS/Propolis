#ifndef __FUNCTIONCALLRESPONSEDTO_H_
#define __FUNCTIONCALLRESPONSEDTO_H_

#include "GenericResponseDTO.h"
#include <function-call.pb.h>

class FunctionCallResponseDTO {
  public:
    FunctionCallResponseDTO(const GenericResponseDTO& response);

    FunctionCallResponseDTO(GenericResponseStatusDTO status, const char* message);

    FunctionCallResponseDTO(const FunctionCallResponse& response);

    /**
     *@brief gets the generic response
     *
     *@return a reference to the generic response
     */
    const GenericResponseDTO& getResponse() const;

    /**
     *@brief sets the generic response
     *
     *@param [in] status the status to set of the response
     *
     *@param [in] message the details to set of the response
     */
    void setResponse(GenericResponseStatusDTO status, const char* message);

    /**
     *@brief sets the generic response
     *
     *@param [in] response a referense to the new response
     */
    void setResponse(const FunctionCallResponse& response);

    /**
     *@brief serialize a FunctionCallResponse for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] response the response to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(FunctionCallResponse& response) const;

  private:
    GenericResponseDTO m_response;
};

#endif // __FUNCTIONCALLRESPONSEDTO_H_
