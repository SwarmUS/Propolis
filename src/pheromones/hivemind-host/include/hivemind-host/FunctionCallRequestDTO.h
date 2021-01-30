#ifndef __FUNCTIONCALLREQUESTDTO_H_
#define __FUNCTIONCALLREQUESTDTO_H_

#include "FunctionCallArgumentDTO.h"
#include <array>
#include <function-call.pb.h>
#include <optional>

constexpr uint16_t FUNCTION_CALL_ARGUMENTS_MAX_LENGTH = 16;
constexpr uint16_t FUNCTION_CALL_NAME_MAX_LENGTH = 16;

class FunctionCallRequestDTO {

  public:
    FunctionCallRequestDTO(const FunctionCallRequest& request);

    FunctionCallRequestDTO(const char* functionName,
                           const FunctionCallArgumentDTO* arguments,
                           uint16_t argumentsLength);

    uint16_t getArgumentsLength() const;

    const char* getFunctionName() const;

    const std::array<FunctionCallArgumentDTO, FUNCTION_CALL_ARGUMENTS_MAX_LENGTH>& getArguments()
        const;

    void setFunctionName(const char* functionName);

    uint16_t setArguments(const FunctionCallArgumentDTO* arguments, uint16_t argumentsLength);

    bool serialize(FunctionCallRequest& request) const;

  private:
    std::array<FunctionCallArgumentDTO, FUNCTION_CALL_ARGUMENTS_MAX_LENGTH> m_arguments;

    uint16_t m_argumentsLength = 0;

    char m_functionName[FUNCTION_CALL_NAME_MAX_LENGTH];
};

#endif // __FUNCTIONCALLREQUESTDTO_H_
