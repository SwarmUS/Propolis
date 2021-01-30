#ifndef __FUNCTIONCALLARGUMENTDTO_H_
#define __FUNCTIONCALLARGUMENTDTO_H_

#include <cstdint>
#include <function-call.pb.h>
#include <variant>

/**
 *@brief Class to represent a function call arguments
 **/
class FunctionCallArgumentDTO {

  public:
    FunctionCallArgumentDTO(const FunctionArgument& argument);

    FunctionCallArgumentDTO(int32_t argument);

    FunctionCallArgumentDTO();

    /**
     *@brief get the current stored argument
     *
     *@return the argument*/
    const std::variant<std::monostate, int32_t>& getArgument() const;

    /**
     *@brief set the stored argument
     *
     *@param [in] arg the value to set
     */
    void setArgument(const std::variant<std::monostate, int32_t>& arg);

    /**
     *@brief serialize a FunctionArgument for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] argument the argument to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(FunctionArgument& argument) const;

  private:
    std::variant<std::monostate, int32_t> m_argument;
};

#endif // __FUNCTIONCALLARGUMENTDTO_H_
