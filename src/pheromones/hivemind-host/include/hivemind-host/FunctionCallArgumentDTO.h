#ifndef __FUNCTIONCALLARGUMENTDTO_H_
#define __FUNCTIONCALLARGUMENTDTO_H_

#include <cstdint>
#include <function-call.pb.h>
#include <variant>

/**
 *@brief Class to manage function call arguments
 **/
class FunctionCallArgumentDTO {
  public:
    FunctionCallArgumentDTO(const FunctionArgument& argument);

    std::variant<int32_t> m_argument;

    static FunctionCallArgumentDTO encode(const FunctionArgument& argument);
};

#endif // __FUNCTIONCALLARGUMENTDTO_H_
