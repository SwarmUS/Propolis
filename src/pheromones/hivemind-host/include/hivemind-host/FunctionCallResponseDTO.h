#ifndef __FUNCTIONCALLRESPONSEDTO_H_
#define __FUNCTIONCALLRESPONSEDTO_H_

#include "GenericResponseDTO.h"
#include <function-call.pb.h>

class FunctionCallResponseDTO {
  public:
    FunctionCallResponseDTO(const GenericResponseDTO& response);

    FunctionCallResponseDTO(GenericResponseStatusDTO status, const char* message);

    FunctionCallResponseDTO(const GenericResponse& response);

    const GenericResponseDTO& getResponse() const;

    void setResponse(GenericResponseStatusDTO status, const char* message);

    void setResponse(const FunctionCallResponse& response);

    bool serialize(FunctionCallResponse& response) const;

  private:
    GenericResponseDTO m_response;
};

#endif // __FUNCTIONCALLRESPONSEDTO_H_
