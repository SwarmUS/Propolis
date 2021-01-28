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

    FunctionCallArgumentDTO(int32_t argument);

    FunctionCallArgumentDTO();

    const std::variant<std::monostate, int32_t>& getArgument() const;

    bool serialize(FunctionArgument& argument) const;

  private:
    std::variant<std::monostate, int32_t> m_argument;
};

#endif // __FUNCTIONCALLARGUMENTDTO_H_
