#ifndef __FUNCTIONCALLREQUEST_H_
#define __FUNCTIONCALLREQUEST_H_

#include "FunctionCallArgument.h"
#include <array>
#include <optional>

static const uint16_t s_functionCallArgumentsMaxLenght = 16;

class FunctionCallRequest2 {

  public:
    FunctionCallRequest2() = default;

    ~FunctionCallRequest2() = default;

    std::array<FunctionCallArgument, s_functionCallArgumentsMaxLenght> m_arguments = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    uint16_t m_argumentsLength = 0;
};

#endif // __FUNCTIONCALLREQUEST_H_
