#ifndef __FUNCTIONCALLARGUMENT_H_
#define __FUNCTIONCALLARGUMENT_H_

#include <cstdint>
#include <variant>

/**
 *@brief Class to manage function call arguments
 **/
class FunctionCallArgument {
  public:
    /**
     *@brief Constructor for an int32_t argument */
    FunctionCallArgument(int32_t intArg);

    ~FunctionCallArgument() = default;

    /**
     *@brief get the stored argument
     *
     *@return an std::variant conaining the argument*/
    std::variant<int32_t> getArgument();

  private:
    const std::variant<int32_t> m_argument;
};

#endif // __FUNCTIONCALLARGUMENT_H_
