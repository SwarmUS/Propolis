#ifndef __FUNCTIONCALLREQUESTDTO_H_
#define __FUNCTIONCALLREQUESTDTO_H_

#include "FunctionCallArgumentDTO.h"
#include <array>
#include <function-call.pb.h>
#include <optional>

static const uint16_t s_functionCallArgumentsMaxLenght = 16;
static const uint16_t s_functionNameMaxLength = 16;

class FunctionCallRequestDTO {

  public:
    FunctionCallRequestDTO(const FunctionCallRequest& request);

  private:
    std::array<FunctionCallArgumentDTO, s_functionCallArgumentsMaxLenght> m_arguments;

    char m_functionName[s_functionNameMaxLength];

    uint16_t m_argumentsLength = 0;
};

#endif // __FUNCTIONCALLREQUESTDTO_H_
