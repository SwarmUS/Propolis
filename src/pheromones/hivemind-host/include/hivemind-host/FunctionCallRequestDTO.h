#ifndef __FUNCTIONCALLREQUESTDTO_H_
#define __FUNCTIONCALLREQUESTDTO_H_

#include "FunctionCallArgumentDTO.h"
#include <array>
#include <function-call.pb.h>
#include <optional>

constexpr uint16_t s_functionCallArgumentsMaxLenght = 16;
constexpr uint16_t s_functionNameMaxLength = 16;

class FunctionCallRequestDTO {

  public:
    FunctionCallRequestDTO(const FunctionCallRequest& request);

    FunctionCallRequestDTO(const char* functionName,
                           const FunctionCallArgumentDTO* arguments,
                           uint16_t argumentsLength);

    bool serialize(FunctionCallRequest& request) const;

    std::array<FunctionCallArgumentDTO, s_functionCallArgumentsMaxLenght> m_arguments;

    uint16_t m_argumentsLength = 0;

    char m_functionName[s_functionNameMaxLength];
};

#endif // __FUNCTIONCALLREQUESTDTO_H_
