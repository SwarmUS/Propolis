#ifndef __FUNCTIONCALLREQUESTDTO_H_
#define __FUNCTIONCALLREQUESTDTO_H_

#include "FunctionCallArgumentDTO.h"
#include <array>
#include <function-call.pb.h>
#include <optional>

static const uint16_t s_functionCallArgumentsMaxLenght = 16;

class FunctionCallRequestDTO {

  public:
    FunctionCallRequestDTO(const FunctionCallRequest& request);

    std::array<FunctionCallArgumentDTO, s_functionCallArgumentsMaxLenght> m_arguments;

    char m_functionName[16];

    uint16_t m_argumentsLength = 0;

    static FunctionCallRequestDTO encode(const FunctionCallRequest& request);
};

#endif // __FUNCTIONCALLREQUESTDTO_H_
