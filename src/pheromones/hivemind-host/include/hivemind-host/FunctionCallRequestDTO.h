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

    FunctionCallRequestDTO(char* functionName,
                           FunctionCallArgumentDTO* arguments,
                           uint16_t argumentsLength);

    uint16_t getArgumentsLength() const;

    const char* getFunctionName() const;

    const FunctionCallArgumentDTO& getArgument(uint16_t index) const;

    FunctionCallRequest serialize() const;

  private:
    std::array<FunctionCallArgumentDTO, s_functionCallArgumentsMaxLenght> m_arguments;

    uint16_t m_argumentsLength = 0;

    char m_functionName[s_functionNameMaxLength];
};

#endif // __FUNCTIONCALLREQUESTDTO_H_
